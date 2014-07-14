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

#include "libcef_dll/cpptoc/post_data_cpptoc.h"
#include "libcef_dll/cpptoc/request_cpptoc.h"
#include "libcef_dll/transfer_util.h"


// GLOBAL FUNCTIONS - Body may be edited by hand.

CEF_EXPORT cef_request_t* cef_request_create() {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  CefRefPtr<CefRequest> _retval = CefRequest::Create();

  // Return type: refptr_same
  return CefRequestCppToC::Wrap(_retval);
}


// MEMBER FUNCTIONS - Body may be edited by hand.

int CEF_CALLBACK request_is_read_only(struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return 0;

  // Execute
  bool _retval = CefRequestCppToC::Get(self)->IsReadOnly();

  // Return type: bool
  return _retval;
}

cef_string_userfree_t CEF_CALLBACK request_get_url(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefRequestCppToC::Get(self)->GetURL();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK request_set_url(struct _cef_request_t* self,
    const cef_string_t* url) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;

  // Execute
  CefRequestCppToC::Get(self)->SetURL(
      CefString(url));
}

cef_string_userfree_t CEF_CALLBACK request_get_method(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefRequestCppToC::Get(self)->GetMethod();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK request_set_method(struct _cef_request_t* self,
    const cef_string_t* method) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: method; type: string_byref_const
  DCHECK(method);
  if (!method)
    return;

  // Execute
  CefRequestCppToC::Get(self)->SetMethod(
      CefString(method));
}

struct _cef_post_data_t* CEF_CALLBACK request_get_post_data(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefRefPtr<CefPostData> _retval = CefRequestCppToC::Get(self)->GetPostData();

  // Return type: refptr_same
  return CefPostDataCppToC::Wrap(_retval);
}

void CEF_CALLBACK request_set_post_data(struct _cef_request_t* self,
    struct _cef_post_data_t* postData) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: postData; type: refptr_same
  DCHECK(postData);
  if (!postData)
    return;

  // Execute
  CefRequestCppToC::Get(self)->SetPostData(
      CefPostDataCppToC::Unwrap(postData));
}

void CEF_CALLBACK request_get_header_map(struct _cef_request_t* self,
    cef_string_multimap_t headerMap) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: headerMap; type: string_map_multi_byref
  DCHECK(headerMap);
  if (!headerMap)
    return;

  // Translate param: headerMap; type: string_map_multi_byref
  std::multimap<CefString, CefString> headerMapMultimap;
  transfer_string_multimap_contents(headerMap, headerMapMultimap);

  // Execute
  CefRequestCppToC::Get(self)->GetHeaderMap(
      headerMapMultimap);

  // Restore param: headerMap; type: string_map_multi_byref
  cef_string_multimap_clear(headerMap);
  transfer_string_multimap_contents(headerMapMultimap, headerMap);
}

void CEF_CALLBACK request_set_header_map(struct _cef_request_t* self,
    cef_string_multimap_t headerMap) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: headerMap; type: string_map_multi_byref_const
  DCHECK(headerMap);
  if (!headerMap)
    return;

  // Translate param: headerMap; type: string_map_multi_byref_const
  std::multimap<CefString, CefString> headerMapMultimap;
  transfer_string_multimap_contents(headerMap, headerMapMultimap);

  // Execute
  CefRequestCppToC::Get(self)->SetHeaderMap(
      headerMapMultimap);
}

void CEF_CALLBACK request_set(struct _cef_request_t* self,
    const cef_string_t* url, const cef_string_t* method,
    struct _cef_post_data_t* postData, cef_string_multimap_t headerMap) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;
  // Verify param: method; type: string_byref_const
  DCHECK(method);
  if (!method)
    return;
  // Verify param: headerMap; type: string_map_multi_byref_const
  DCHECK(headerMap);
  if (!headerMap)
    return;
  // Unverified params: postData

  // Translate param: headerMap; type: string_map_multi_byref_const
  std::multimap<CefString, CefString> headerMapMultimap;
  transfer_string_multimap_contents(headerMap, headerMapMultimap);

  // Execute
  CefRequestCppToC::Get(self)->Set(
      CefString(url),
      CefString(method),
      CefPostDataCppToC::Unwrap(postData),
      headerMapMultimap);
}

int CEF_CALLBACK request_get_flags(struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return UR_FLAG_NONE;

  // Execute
  int _retval = CefRequestCppToC::Get(self)->GetFlags();

  // Return type: simple
  return _retval;
}

void CEF_CALLBACK request_set_flags(struct _cef_request_t* self, int flags) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;

  // Execute
  CefRequestCppToC::Get(self)->SetFlags(
      flags);
}

cef_string_userfree_t CEF_CALLBACK request_get_first_party_for_cookies(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return NULL;

  // Execute
  CefString _retval = CefRequestCppToC::Get(self)->GetFirstPartyForCookies();

  // Return type: string
  return _retval.DetachToUserFree();
}

void CEF_CALLBACK request_set_first_party_for_cookies(
    struct _cef_request_t* self, const cef_string_t* url) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return;
  // Verify param: url; type: string_byref_const
  DCHECK(url);
  if (!url)
    return;

  // Execute
  CefRequestCppToC::Get(self)->SetFirstPartyForCookies(
      CefString(url));
}

cef_resource_type_t CEF_CALLBACK request_get_resource_type(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return RT_SUB_RESOURCE;

  // Execute
  cef_resource_type_t _retval = CefRequestCppToC::Get(self)->GetResourceType();

  // Return type: simple
  return _retval;
}

cef_transition_type_t CEF_CALLBACK request_get_transition_type(
    struct _cef_request_t* self) {
  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  DCHECK(self);
  if (!self)
    return TT_EXPLICIT;

  // Execute
  cef_transition_type_t _retval = CefRequestCppToC::Get(
      self)->GetTransitionType();

  // Return type: simple
  return _retval;
}


// CONSTRUCTOR - Do not edit by hand.

CefRequestCppToC::CefRequestCppToC(CefRequest* cls)
    : CefCppToC<CefRequestCppToC, CefRequest, cef_request_t>(cls) {
  struct_.struct_.is_read_only = request_is_read_only;
  struct_.struct_.get_url = request_get_url;
  struct_.struct_.set_url = request_set_url;
  struct_.struct_.get_method = request_get_method;
  struct_.struct_.set_method = request_set_method;
  struct_.struct_.get_post_data = request_get_post_data;
  struct_.struct_.set_post_data = request_set_post_data;
  struct_.struct_.get_header_map = request_get_header_map;
  struct_.struct_.set_header_map = request_set_header_map;
  struct_.struct_.set = request_set;
  struct_.struct_.get_flags = request_get_flags;
  struct_.struct_.set_flags = request_set_flags;
  struct_.struct_.get_first_party_for_cookies =
      request_get_first_party_for_cookies;
  struct_.struct_.set_first_party_for_cookies =
      request_set_first_party_for_cookies;
  struct_.struct_.get_resource_type = request_get_resource_type;
  struct_.struct_.get_transition_type = request_get_transition_type;
}

#ifndef NDEBUG
template<> base::AtomicRefCount CefCppToC<CefRequestCppToC, CefRequest,
    cef_request_t>::DebugObjCt = 0;
#endif

