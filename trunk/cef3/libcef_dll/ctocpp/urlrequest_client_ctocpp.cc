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

#include "libcef_dll/cpptoc/urlrequest_cpptoc.h"
#include "libcef_dll/ctocpp/urlrequest_client_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

void CefURLRequestClientCToCpp::OnRequestComplete(
    CefRefPtr<CefURLRequest> request) {
  if (CEF_MEMBER_MISSING(struct_, on_request_complete))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;

  // Execute
  struct_->on_request_complete(struct_,
      CefURLRequestCppToC::Wrap(request));
}

void CefURLRequestClientCToCpp::OnUploadProgress(
    CefRefPtr<CefURLRequest> request, uint64 current, uint64 total) {
  if (CEF_MEMBER_MISSING(struct_, on_upload_progress))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;

  // Execute
  struct_->on_upload_progress(struct_,
      CefURLRequestCppToC::Wrap(request),
      current,
      total);
}

void CefURLRequestClientCToCpp::OnDownloadProgress(
    CefRefPtr<CefURLRequest> request, uint64 current, uint64 total) {
  if (CEF_MEMBER_MISSING(struct_, on_download_progress))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;

  // Execute
  struct_->on_download_progress(struct_,
      CefURLRequestCppToC::Wrap(request),
      current,
      total);
}

void CefURLRequestClientCToCpp::OnDownloadData(CefRefPtr<CefURLRequest> request,
    const void* data, size_t data_length) {
  if (CEF_MEMBER_MISSING(struct_, on_download_data))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: request; type: refptr_diff
  DCHECK(request.get());
  if (!request.get())
    return;
  // Verify param: data; type: simple_byaddr
  DCHECK(data);
  if (!data)
    return;

  // Execute
  struct_->on_download_data(struct_,
      CefURLRequestCppToC::Wrap(request),
      data,
      data_length);
}


#ifndef NDEBUG
template<> long CefCToCpp<CefURLRequestClientCToCpp, CefURLRequestClient,
    cef_urlrequest_client_t>::DebugObjCt = 0;
#endif

