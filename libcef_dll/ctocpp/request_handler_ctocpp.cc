// Copyright (c) 2012 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/auth_callback_cpptoc.h"
#include "libcef_dll/cpptoc/browser_cpptoc.h"
#include "libcef_dll/cpptoc/cookie_manager_cpptoc.h"
#include "libcef_dll/cpptoc/frame_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/ctocpp/request_handler_ctocpp.h"
#include "libcef_dll/ctocpp/resource_handler_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefRequestHandlerCToCpp::OnBeforeResourceLoad(
    CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request) {
  if (CEF_MEMBER_MISSING(struct_, on_before_resource_load))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return false;

  // Execute
  int _retval = struct_->on_before_resource_load(struct_,
      CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request));

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefResourceHandler> CefRequestHandlerCToCpp::GetResourceHandler(
    CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request) {
  if (CEF_MEMBER_MISSING(struct_, get_resource_handler))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return NULL;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return NULL;
  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return NULL;

  // Execute
  cef_resource_handler_t* _retval = struct_->get_resource_handler(struct_,
      CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame),
      CefRequestCppToC::Wrap(request));

  // Return type: refptr_same
  return CefResourceHandlerCToCpp::Wrap(_retval);
}

void CefRequestHandlerCToCpp::OnResourceRedirect(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, const CefString& old_url, CefString& new_url) {
  if (CEF_MEMBER_MISSING(struct_, on_resource_redirect))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return;
  // Verify param: old_url; type: string_byref_const
  DCHECK(!old_url.empty());
  if (old_url.empty())
    return;

  // Execute
  struct_->on_resource_redirect(struct_,
      CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame),
      old_url.GetStruct(),
      new_url.GetWritableStruct());
}

bool CefRequestHandlerCToCpp::GetAuthCredentials(CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame, bool isProxy, const CefString& host, int port,
    const CefString& realm, const CefString& scheme,
    CefRefPtr<CefAuthCallback> callback) {
  if (CEF_MEMBER_MISSING(struct_, get_auth_credentials))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return false;
  // Verify param: frame; type: refptr_diff
  DCHECK(frame.get());
  if (!frame.get())
    return false;
  // Verify param: host; type: string_byref_const
  DCHECK(!host.empty());
  if (host.empty())
    return false;
  // Verify param: scheme; type: string_byref_const
  DCHECK(!scheme.empty());
  if (scheme.empty())
    return false;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return false;
  // Unverified params: realm

  // Execute
  int _retval = struct_->get_auth_credentials(struct_,
      CefBrowserCppToC::Wrap(browser),
      CefFrameCppToC::Wrap(frame),
      isProxy,
      host.GetStruct(),
      port,
      realm.GetStruct(),
      scheme.GetStruct(),
      CefAuthCallbackCppToC::Wrap(callback));

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefCookieManager> CefRequestHandlerCToCpp::GetCookieManager(
    CefRefPtr<CefBrowser> browser, const CefString& main_url) {
  if (CEF_MEMBER_MISSING(struct_, get_cookie_manager))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: browser; type: refptr_diff
  DCHECK(browser.get());
  if (!browser.get())
    return NULL;
  // Verify param: main_url; type: string_byref_const
  DCHECK(!main_url.empty());
  if (main_url.empty())
    return NULL;

  // Execute
  cef_cookie_manager_t* _retval = struct_->get_cookie_manager(struct_,
      CefBrowserCppToC::Wrap(browser),
      main_url.GetStruct());

  // Return type: refptr_diff
  return CefCookieManagerCppToC::Unwrap(_retval);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefRequestHandlerCToCpp, CefRequestHandler,
    cef_request_handler_t>::DebugObjCt = 0;
#endif

