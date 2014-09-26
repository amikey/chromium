// Copyright (c) 2014 The Chromium Embedded Framework Authors.
// Portions copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "libcef/browser/printing/print_dialog_linux.h"

#include <string>
#include <vector>

#include "libcef/browser/print_settings_impl.h"
#include "libcef/browser/thread_util.h"
#include "libcef/common/content_client.h"

#include "base/bind.h"
#include "base/file_util.h"
#include "base/files/file_util_proxy.h"
#include "base/lazy_instance.h"
#include "base/logging.h"
#include "base/message_loop/message_loop_proxy.h"
#include "base/strings/utf_string_conversions.h"
#include "base/values.h"
#include "printing/metafile.h"
#include "printing/print_job_constants.h"
#include "printing/print_settings.h"

using content::BrowserThread;
using printing::PageRanges;
using printing::PrintSettings;

class CefPrintDialogCallbackImpl : public CefPrintDialogCallback {
 public:
  explicit CefPrintDialogCallbackImpl(CefRefPtr<CefPrintDialogLinux> dialog)
      : dialog_(dialog) {
  }

  virtual void Continue(CefRefPtr<CefPrintSettings> settings) OVERRIDE {
    if (CEF_CURRENTLY_ON_UIT()) {
      if (dialog_.get()) {
        dialog_->OnPrintContinue(settings);
        dialog_ = NULL;
      }
    } else {
      CEF_POST_TASK(CEF_UIT,
          base::Bind(&CefPrintDialogCallbackImpl::Continue, this, settings));
    }
  }

  virtual void Cancel() OVERRIDE {
    if (CEF_CURRENTLY_ON_UIT()) {
      if (dialog_.get()) {
        dialog_->OnPrintCancel();
        dialog_ = NULL;
      }
    } else {
      CEF_POST_TASK(CEF_UIT,
          base::Bind(&CefPrintDialogCallbackImpl::Cancel, this));
    }
  }

  void Disconnect() {
    dialog_ = NULL;
  }

 private:
  CefRefPtr<CefPrintDialogLinux> dialog_;

  IMPLEMENT_REFCOUNTING(CefPrintDialogCallbackImpl);
  DISALLOW_COPY_AND_ASSIGN(CefPrintDialogCallbackImpl);
};

class CefPrintJobCallbackImpl : public CefPrintJobCallback {
 public:
  explicit CefPrintJobCallbackImpl(CefRefPtr<CefPrintDialogLinux> dialog)
      : dialog_(dialog) {
  }

  virtual void Continue() OVERRIDE {
    if (CEF_CURRENTLY_ON_UIT()) {
      if (dialog_.get()) {
        dialog_->OnJobCompleted();
        dialog_ = NULL;
      }
    } else {
      CEF_POST_TASK(CEF_UIT,
          base::Bind(&CefPrintJobCallbackImpl::Continue, this));
    }
  }

  void Disconnect() {
    dialog_ = NULL;
  }

 private:
  CefRefPtr<CefPrintDialogLinux> dialog_;

  IMPLEMENT_REFCOUNTING(CefPrintJobCallbackImpl);
  DISALLOW_COPY_AND_ASSIGN(CefPrintJobCallbackImpl);
};


// static
printing::PrintDialogGtkInterface* CefPrintDialogLinux::CreatePrintDialog(
    PrintingContextLinux* context) {
  CEF_REQUIRE_UIT();
  return new CefPrintDialogLinux(context);
}

CefPrintDialogLinux::CefPrintDialogLinux(PrintingContextLinux* context)
    : context_(context) {
}

CefPrintDialogLinux::~CefPrintDialogLinux() {
  CEF_REQUIRE_UIT();
  ReleaseHandler();
}

void CefPrintDialogLinux::UseDefaultSettings() {
  PrintSettings settings;
  UpdateSettings(&settings, true);
}

bool CefPrintDialogLinux::UpdateSettings(printing::PrintSettings* settings) {
  return UpdateSettings(settings, false);
}

void CefPrintDialogLinux::ShowDialog(
    gfx::NativeView parent_view,
    bool has_selection,
    const PrintingContextLinux::PrintSettingsCallback& callback) {
  CEF_REQUIRE_UIT();

  SetHandler();
  if (!handler_.get()) {
    callback.Run(PrintingContextLinux::CANCEL);
    return;
  }

  callback_ = callback;

  CefRefPtr<CefPrintDialogCallbackImpl> callback_impl(
      new CefPrintDialogCallbackImpl(this));

  if (!handler_->OnPrintDialog(has_selection, callback_impl.get())) {
    callback_impl->Disconnect();
    OnPrintCancel();
  }
}

void CefPrintDialogLinux::PrintDocument(
    const printing::MetafilePlayer& metafile,
    const base::string16& document_name) {
  // This runs on the print worker thread, does not block the UI thread.
  DCHECK(!CEF_CURRENTLY_ON_UIT());

  // The document printing tasks can outlive the PrintingContext that created
  // this dialog.
  AddRef();

  bool success = base::CreateTemporaryFile(&path_to_pdf_);

  if (success) {
    base::File file;
    file.Initialize(path_to_pdf_,
                    base::File::FLAG_CREATE_ALWAYS | base::File::FLAG_WRITE);
    success = metafile.SaveTo(&file);
    file.Close();
    if (!success)
      base::DeleteFile(path_to_pdf_, false);
  }

  if (!success) {
    LOG(ERROR) << "Saving metafile failed";
    // Matches AddRef() above.
    Release();
    return;
  }

  // No errors, continue printing.
  CEF_POST_TASK(
      CEF_UIT,
      base::Bind(&CefPrintDialogLinux::SendDocumentToPrinter, this,
                 document_name));
}

void CefPrintDialogLinux::AddRefToDialog() {
  AddRef();
}

void CefPrintDialogLinux::ReleaseDialog() {
  Release();
}

void CefPrintDialogLinux::SetHandler() {
 if (handler_.get())
   return;

 CefRefPtr<CefApp> app = CefContentClient::Get()->application();
  if (app.get()) {
    CefRefPtr<CefBrowserProcessHandler> browser_handler =
        app->GetBrowserProcessHandler();
    if (browser_handler.get())
      handler_ = browser_handler->GetPrintHandler();
  }
}

void CefPrintDialogLinux::ReleaseHandler() {
  if (handler_.get()) {
    handler_->OnPrintReset();
    handler_ = NULL;
  }
}

bool CefPrintDialogLinux::UpdateSettings(printing::PrintSettings* settings,
                                         bool get_defaults) {
  CEF_REQUIRE_UIT();

  SetHandler();
  if (!handler_.get())
    return false;

  CefRefPtr<CefPrintSettingsImpl> settings_impl(
      new CefPrintSettingsImpl(settings, false, false));
  handler_->OnPrintSettings(settings_impl.get(), get_defaults);
  settings_impl->Detach(NULL);

  context_->InitWithSettings(*settings);
  return true;
}

void CefPrintDialogLinux::SendDocumentToPrinter(
    const base::string16& document_name) {
  CEF_REQUIRE_UIT();

  if (!handler_.get()) {
    OnJobCompleted();
    return;
  }

  CefRefPtr<CefPrintJobCallbackImpl> callback_impl(
      new CefPrintJobCallbackImpl(this));

  if (!handler_->OnPrintJob(document_name, path_to_pdf_.value(),
                            callback_impl.get())) {
    callback_impl->Disconnect();
    OnJobCompleted();
  }
}

void CefPrintDialogLinux::OnPrintContinue(
    CefRefPtr<CefPrintSettings> settings) {
  {
    CefPrintSettingsImpl* impl =
        static_cast<CefPrintSettingsImpl*>(settings.get());
    CefValueController::AutoLock lock_scope(impl->controller());
    context_->InitWithSettings(impl->print_settings());
  }
  callback_.Run(PrintingContextLinux::OK);
  callback_.Reset();
}

void CefPrintDialogLinux::OnPrintCancel() {
  callback_.Run(PrintingContextLinux::CANCEL);
  callback_.Reset();
}

void CefPrintDialogLinux::OnJobCompleted() {
  base::FileUtilProxy::DeleteFile(
      content::BrowserThread::GetMessageLoopProxyForThread(
          BrowserThread::FILE).get(),
      path_to_pdf_,
      false,
      base::FileUtilProxy::StatusCallback());

  // Printing finished. Matches AddRef() in PrintDocument();
  Release();
}

