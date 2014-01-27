// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "tests/unittests/test_handler.h"
#include "include/cef_command_line.h"
#include "include/cef_runnable.h"
#include "include/cef_stream.h"
#include "include/wrapper/cef_stream_resource_handler.h"

namespace {

void NotifyEvent(base::WaitableEvent* event) {
  event->Signal();
}

}  // namespace


// TestHandler::CompletionState

TestHandler::CompletionState::CompletionState(int total)
    : total_(total),
      count_(0),
      event_(true, false) {
}

void TestHandler::CompletionState::TestComplete() {
  if (++count_ == total_) {
    // Signal that the test is now complete.
    event_.Signal();
    count_ = 0;
  }
}

void TestHandler::CompletionState::WaitForTests() {
  // Wait for the test to complete
  event_.Wait();

  // Reset the event so the same test can be executed again.
  event_.Reset();
}


// TestHandler::Collection

TestHandler::Collection::Collection(CompletionState* completion_state)
    : completion_state_(completion_state) {
  EXPECT_TRUE(completion_state_);
}

void TestHandler::Collection::AddTestHandler(TestHandler* test_handler) {
  EXPECT_EQ(test_handler->completion_state_, completion_state_);
  handler_list_.push_back(test_handler);
}

void TestHandler::Collection::ExecuteTests() {
  EXPECT_GT(handler_list_.size(), 0UL);

  TestHandlerList::const_iterator it;

  it = handler_list_.begin();
  for (; it != handler_list_.end(); ++it)
    (*it)->SetupTest();

  completion_state_->WaitForTests();

  it = handler_list_.begin();
  for (; it != handler_list_.end(); ++it)
    (*it)->RunTest();

  completion_state_->WaitForTests();
}


// TestHandler

int TestHandler::browser_count_ = 0;

TestHandler::TestHandler(CompletionState* completion_state)
    : first_browser_id_(0),
      signal_completion_when_all_browsers_close_(true) {
  if (completion_state) {
    completion_state_ = completion_state;
    completion_state_owned_ = false;
  } else {
    completion_state_ = new CompletionState(1);
    completion_state_owned_ = true;
  }
}

TestHandler::~TestHandler() {
  EXPECT_TRUE(browser_map_.empty());

  if (completion_state_owned_)
    delete completion_state_;
}

void TestHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser) {
  EXPECT_UI_THREAD();

  browser_count_++;

  if (!browser->IsPopup()) {
    // Keep non-popup browsers.
    const int browser_id = browser->GetIdentifier();
    EXPECT_EQ(browser_map_.find(browser_id), browser_map_.end());
    if (browser_map_.empty()) {
      first_browser_id_ = browser_id;
      first_browser_ = browser;
    }
    browser_map_.insert(std::make_pair(browser_id, browser));
  }
}

void TestHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser) {
  EXPECT_UI_THREAD();

  if (!browser->IsPopup()) {
    // Free the browser pointer so that the browser can be destroyed.
    const int browser_id = browser->GetIdentifier();
    BrowserMap::iterator it = browser_map_.find(browser_id);
    EXPECT_NE(it, browser_map_.end());
    browser_map_.erase(it);

    if (browser_id == first_browser_id_) {
      first_browser_id_ = 0;
      first_browser_ = NULL;
    }

    if (browser_map_.empty() &&
        signal_completion_when_all_browsers_close_) {
      // Signal that the test is now complete.
      TestComplete();
    }
  }

  browser_count_--;
}

CefRefPtr<CefResourceHandler> TestHandler::GetResourceHandler(
      CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame,
      CefRefPtr<CefRequest> request) {
  EXPECT_IO_THREAD();

  if (resource_map_.size() > 0) {
    CefString url = request->GetURL();

    // Ignore the query component, if any.
    std::string urlStr = url;
    size_t idx = urlStr.find('?');
    if (idx > 0)
       urlStr = urlStr.substr(0, idx);

    ResourceMap::const_iterator it = resource_map_.find(urlStr);
    if (it != resource_map_.end()) {
      // Return the previously mapped resource
      CefRefPtr<CefStreamReader> stream =
          CefStreamReader::CreateForData(
              static_cast<void*>(const_cast<char*>(it->second.first.c_str())),
              it->second.first.length());
      return new CefStreamResourceHandler(it->second.second, stream);
    }
  }

  return NULL;
}

CefRefPtr<CefBrowser> TestHandler::GetBrowser() {
  return first_browser_;
}

int TestHandler::GetBrowserId() {
  return first_browser_id_;
}

void TestHandler::GetAllBrowsers(BrowserMap* map) {
  EXPECT_UI_THREAD();
  EXPECT_TRUE(map);
  *map = browser_map_;
}

void TestHandler::ExecuteTest() {
  EXPECT_EQ(completion_state_->total(), 1);

  // Run the test
  RunTest();

  // Wait for the test to complete
  completion_state_->WaitForTests();
}

void TestHandler::SetupComplete() {
  // Signal that the test setup is complete.
  completion_state_->TestComplete();
}

void TestHandler::DestroyTest() {
  if (!CefCurrentlyOn(TID_UI)) {
    CefPostTask(TID_UI, NewCefRunnableMethod(this, &TestHandler::DestroyTest));
    return;
  }

  if (!browser_map_.empty()) {
    // Use a copy of the map since the original may be modified while we're
    // iterating.
    BrowserMap browser_map = browser_map_;

    // Tell all non-popup browsers to close.
    BrowserMap::const_iterator it = browser_map.begin();
    for (; it != browser_map.end(); ++it)
      it->second->GetHost()->CloseBrowser(false);
  }
}

void TestHandler::CreateBrowser(
    const CefString& url,
    CefRefPtr<CefRequestContext> request_context) {
  CefWindowInfo windowInfo;
  CefBrowserSettings settings;
#if defined(OS_WIN)
  windowInfo.SetAsPopup(NULL, "CefUnitTest");
  windowInfo.style |= WS_VISIBLE;
#endif
  CefBrowserHost::CreateBrowser(windowInfo, this, url, settings,
                                request_context);
}

void TestHandler::AddResource(const std::string& url,
                              const std::string& content,
                              const std::string& mimeType) {
  if (!CefCurrentlyOn(TID_IO)) {
    CefPostTask(TID_IO,
        NewCefRunnableMethod(this, &TestHandler::AddResource, url, content,
                             mimeType));
    return;
  }

  // Ignore the query component, if any.
  std::string urlStr = url;
  size_t idx = urlStr.find('?');
  if (idx > 0)
     urlStr = urlStr.substr(0, idx);

  resource_map_.insert(
      std::make_pair(urlStr, std::make_pair(content, mimeType)));
}

void TestHandler::ClearResources() {
  if (!CefCurrentlyOn(TID_IO)) {
    CefPostTask(TID_IO,
        NewCefRunnableMethod(this, &TestHandler::ClearResources));
    return;
  }

  resource_map_.clear();
}

void TestHandler::TestComplete() {
  if (!CefCurrentlyOn(TID_UI)) {
    CefPostTask(TID_UI, NewCefRunnableMethod(this, &TestHandler::TestComplete));
    return;
  }

  EXPECT_TRUE(browser_map_.empty());
  completion_state_->TestComplete();
}


// global functions

void WaitForThread(CefThreadId thread_id) {
  base::WaitableEvent event(true, false);
  CefPostTask(thread_id, NewCefRunnableFunction(&NotifyEvent, &event));
  event.Wait();
}

void WaitForThread(CefRefPtr<CefTaskRunner> task_runner) {
  base::WaitableEvent event(true, false);
  task_runner->PostTask(NewCefRunnableFunction(&NotifyEvent, &event));
  event.Wait();
}

bool TestFailed() {
  CefRefPtr<CefCommandLine> command_line =
      CefCommandLine::GetGlobalCommandLine();
  if (command_line->HasSwitch("single-process")) {
    // Check for a failure on the current test only.
    return ::testing::UnitTest::GetInstance()->current_test_info()->result()->
        Failed();
  } else {
    // Check for any global failure.
    return ::testing::UnitTest::GetInstance()->Failed();
  }
}
