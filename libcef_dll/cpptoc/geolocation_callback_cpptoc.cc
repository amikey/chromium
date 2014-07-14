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

#include "libcef_dll/cpptoc/geolocation_callback_cpptoc.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

void CEF_CALLBACK geolocation_callback_cont(
    struct _cef_geolocation_callback_t* self, int allow) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefGeolocationCallbackCppToC::Get(self)->Continue(
      allow?true:false);
}


// CONSTRUCTOR - Do not edit by hand.

CefGeolocationCallbackCppToC::CefGeolocationCallbackCppToC(
    CefGeolocationCallback* cls)
    : CefCppToC<CefGeolocationCallbackCppToC, CefGeolocationCallback,
        cef_geolocation_callback_t>(cls) {
  struct_.struct_.cont = geolocation_callback_cont;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefGeolocationCallbackCppToC,
    CefGeolocationCallback, cef_geolocation_callback_t>::DebugObjCt = 0;
#endif

