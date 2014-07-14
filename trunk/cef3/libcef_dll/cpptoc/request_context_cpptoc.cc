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

#include "libcef_dll/cpptoc/request_context_cpptoc.h"
#include "libcef_dll/ctocpp/request_context_handler_ctocpp.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_request_context_t* cef_request_context_get_global_context() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefRequestContext> _retval = CefRequestContext::GetGlobalContext();

  // Return type: refptr_same
  return CefRequestContextCppToC::Wrap(_retval);
}

CEF_EXPORT cef_request_context_t* cef_request_context_create_context(
    struct _cef_request_context_handler_t* handler) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: handler

  // Execute
  CefRefPtr<CefRequestContext> _retval = CefRequestContext::CreateContext(
      CefRequestContextHandlerCToCpp::Wrap(handler));

  // Return type: refptr_same
  return CefRequestContextCppToC::Wrap(_retval);
}


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK request_context_is_same(struct _cef_request_context_t* self,
    struct _cef_request_context_t* other) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;
  // Verify param: other; type: refptr_same
  DCHECK(other);
  if (!other)
    return 0;

  // Execute
  bool _retval = CefRequestContextCppToC::Get(self)->IsSame(
      CefRequestContextCppToC::Unwrap(other));

  // Return type: bool
  return _retval;
}

int CEF_CALLBACK request_context_is_global(
    struct _cef_request_context_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefRequestContextCppToC::Get(self)->IsGlobal();

  // Return type: bool
  return _retval;
}

struct _cef_request_context_handler_t* CEF_CALLBACK request_context_get_handler(
    struct _cef_request_context_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefRequestContextHandler> _retval = CefRequestContextCppToC::Get(
      self)->GetHandler();

  // Return type: refptr_diff
  return CefRequestContextHandlerCToCpp::Unwrap(_retval);
}


// CONSTRUCTOR - Do not edit by hand.

CefRequestContextCppToC::CefRequestContextCppToC(CefRequestContext* cls)
    : CefCppToC<CefRequestContextCppToC, CefRequestContext,
        cef_request_context_t>(cls) {
  struct_.struct_.is_same = request_context_is_same;
  struct_.struct_.is_global = request_context_is_global;
  struct_.struct_.get_handler = request_context_get_handler;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefRequestContextCppToC,
    CefRequestContext, cef_request_context_t>::DebugObjCt = 0;
#endif

