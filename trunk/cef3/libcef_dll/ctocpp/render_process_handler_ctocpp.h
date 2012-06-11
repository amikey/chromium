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

#ifndef CEF_LIBCEF_DLL_CTOCPP_RENDER_PROCESS_HANDLER_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_RENDER_PROCESS_HANDLER_CTOCPP_H_
#pragma once

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else  // BUILDING_CEF_SHARED

#include "include/cef_render_process_handler.h"
#include "include/capi/cef_render_process_handler_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefRenderProcessHandlerCToCpp
    : public CefCToCpp<CefRenderProcessHandlerCToCpp, CefRenderProcessHandler,
        cef_render_process_handler_t> {
 public:
  explicit CefRenderProcessHandlerCToCpp(cef_render_process_handler_t* str)
      : CefCToCpp<CefRenderProcessHandlerCToCpp, CefRenderProcessHandler,
          cef_render_process_handler_t>(str) {}
  virtual ~CefRenderProcessHandlerCToCpp() {}

  // CefRenderProcessHandler methods
  virtual void OnRenderThreadCreated() OVERRIDE;
  virtual void OnWebKitInitialized() OVERRIDE;
  virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
  virtual void OnBrowserDestroyed(CefRefPtr<CefBrowser> browser) OVERRIDE;
  virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) OVERRIDE;
  virtual void OnContextReleased(CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context) OVERRIDE;
  virtual void OnFocusedNodeChanged(CefRefPtr<CefBrowser> browser,
      CefRefPtr<CefFrame> frame, CefRefPtr<CefDOMNode> node) OVERRIDE;
  virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
      CefProcessId source_process,
      CefRefPtr<CefProcessMessage> message) OVERRIDE;
};

#endif  // BUILDING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_RENDER_PROCESS_HANDLER_CTOCPP_H_

