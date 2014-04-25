// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
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

#ifndef CEF_LIBCEF_DLL_CTOCPP_CLIENT_CTOCPP_H_
#define CEF_LIBCEF_DLL_CTOCPP_CLIENT_CTOCPP_H_
#pragma once

#ifndef BUILDING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed DLL-side only")
#else  // BUILDING_CEF_SHARED

#include "include/cef_client.h"
#include "include/capi/cef_client_capi.h"
#include "libcef_dll/ctocpp/ctocpp.h"

// Wrap a C structure with a C++ class.
// This class may be instantiated and accessed DLL-side only.
class CefClientCToCpp
    : public CefCToCpp<CefClientCToCpp, CefClient, cef_client_t> {
 public:
  explicit CefClientCToCpp(cef_client_t* str)
      : CefCToCpp<CefClientCToCpp, CefClient, cef_client_t>(str) {}
  virtual ~CefClientCToCpp() {}

  // CefClient methods
  virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() OVERRIDE;
  virtual CefRefPtr<CefDialogHandler> GetDialogHandler() OVERRIDE;
  virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE;
  virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() OVERRIDE;
  virtual CefRefPtr<CefDragHandler> GetDragHandler() OVERRIDE;
  virtual CefRefPtr<CefFocusHandler> GetFocusHandler() OVERRIDE;
  virtual CefRefPtr<CefGeolocationHandler> GetGeolocationHandler() OVERRIDE;
  virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() OVERRIDE;
  virtual CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() OVERRIDE;
  virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE;
  virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE;
  virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE;
  virtual bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
      CefProcessId source_process,
      CefRefPtr<CefProcessMessage> message) OVERRIDE;
};

#endif  // BUILDING_CEF_SHARED
#endif  // CEF_LIBCEF_DLL_CTOCPP_CLIENT_CTOCPP_H_

