// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef CEF_TESTS_CEFCLIENT_ROOT_WINDOW_H_
#define CEF_TESTS_CEFCLIENT_ROOT_WINDOW_H_

#include <string>

#include "include/base/cef_ref_counted.h"
#include "include/cef_browser.h"
#include "cefclient/client_types.h"
#include "cefclient/main_message_loop.h"

namespace client {

// Represents a top-level native window in the browser process. While references
// to this object are thread-safe the methods must be called on the main thread
// unless otherwise indicated.
class RootWindow :
    public base::RefCountedThreadSafe<RootWindow, DeleteOnMainThread> {
 public:
  // This interface is implemented by the owner of the RootWindow. The methods
  // of this class will be called on the main thread.
  class Delegate {
   public:
    // Called to execute a test. See resource.h for |test_id| values.
    virtual void OnTest(RootWindow* root_window, int test_id) = 0;

    // Called to exit the application.
    virtual void OnExit(RootWindow* root_window) = 0;

    // Called when the RootWindow has been destroyed.
    virtual void OnRootWindowDestroyed(RootWindow* root_window) = 0;

   protected:
    virtual ~Delegate() {}
  };

  // Create a new RootWindow object. This method may be called on any thread.
  // Use RootWindowManager::CreateRootWindow() or CreateRootWindowAsPopup()
  // instead of calling this method directly.
  static scoped_refptr<RootWindow> Create();

  // Returns the RootWindow associated with the specified |browser_id|. Must be
  // called on the main thread.
  static scoped_refptr<RootWindow> GetForBrowser(int browser_id);

#if defined(OS_MACOSX)
  // Returns the RootWindow associated with the specified |window|. Must be
  // called on the main thread.
  static scoped_refptr<RootWindow> GetForNSWindow(NSWindow* window);
#endif

  // Initialize as a normal window. This will create and show a browser window.
  // This method may be called on any thread.
  // |delegate| must be non-NULL and outlive this object.
  // Use RootWindowManager::CreateRootWindow() instead of calling this method
  // directly.
  virtual void Init(RootWindow::Delegate* delegate,
                    bool with_controls,
                    bool with_osr,
                    const CefRect& bounds,
                    const CefBrowserSettings& settings,
                    const std::string& url) = 0;

  // Initialize as a popup window. This is used to attach a browser window that
  // will be created later. The window will be shown once the browser is
  // available. This method may be called on any thread.
  // |delegate| must be non-NULL and outlive this object.
  // Use RootWindowManager::CreateRootWindowAsPopup() instead of calling this
  // method directly.
  virtual void InitAsPopup(RootWindow::Delegate* delegate,
                           bool with_controls,
                           bool with_osr,
                           const CefPopupFeatures& popupFeatures,
                           CefWindowInfo& windowInfo,
                           CefRefPtr<CefClient>& client,
                           CefBrowserSettings& settings) = 0;

  enum ShowMode {
    ShowNormal,
    ShowMinimized,
    ShowMaximized,
  };

  // Show the window.
  virtual void Show(ShowMode mode) = 0;

  // Hide the window.
  virtual void Hide() = 0;

  // Set the window bounds in screen coordinates.
  virtual void SetBounds(int x, int y, size_t width, size_t height) = 0;

  // Close the window. If |force| is true onunload handlers will not be
  // executed.
  virtual void Close(bool force) = 0;

  // Returns the browser that this window contains, if any.
  virtual CefRefPtr<CefBrowser> GetBrowser() const = 0;

  // Returns the handle for this window, if any.
  virtual ClientWindowHandle GetWindowHandle() const = 0;

 protected:
  // Allow deletion via scoped_refptr only.
  friend struct DeleteOnMainThread;
  friend class base::RefCountedThreadSafe<RootWindow, DeleteOnMainThread>;

  virtual ~RootWindow() {}
};

}  // namespace client

#endif  // CEF_TESTS_CEFCLIENT_ROOT_WINDOW_H_
