// Copyright (c) 2013 The Chromium Embedded Framework Authors. All rights
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

#include "include/cef_version.h"
#include "libcef_dll/ctocpp/command_line_ctocpp.h"
#include "libcef_dll/transfer_util.h"


// STATIC METHODS - Body may be edited by hand.

CefRefPtr<CefCommandLine> CefCommandLine::CreateCommandLine() {
  int build_revision = cef_build_revision();
  if (build_revision != CEF_REVISION) {
    // The libcef build revision does not match the CEF API revision.
    DCHECK(false);
    return NULL;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_command_line_t* _retval = cef_command_line_create();

  // Return type: refptr_same
  return CefCommandLineCToCpp::Wrap(_retval);
}

CefRefPtr<CefCommandLine> CefCommandLine::GetGlobalCommandLine() {
  int build_revision = cef_build_revision();
  if (build_revision != CEF_REVISION) {
    // The libcef build revision does not match the CEF API revision.
    DCHECK(false);
    return NULL;
  }

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_command_line_t* _retval = cef_command_line_get_global();

  // Return type: refptr_same
  return CefCommandLineCToCpp::Wrap(_retval);
}


// VIRTUAL METHODS - Body may be edited by hand.

bool CefCommandLineCToCpp::IsValid() {
  if (CEF_MEMBER_MISSING(struct_, is_valid))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_valid(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefCommandLineCToCpp::IsReadOnly() {
  if (CEF_MEMBER_MISSING(struct_, is_read_only))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_read_only(struct_);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefCommandLine> CefCommandLineCToCpp::Copy() {
  if (CEF_MEMBER_MISSING(struct_, copy))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_command_line_t* _retval = struct_->copy(struct_);

  // Return type: refptr_same
  return CefCommandLineCToCpp::Wrap(_retval);
}

void CefCommandLineCToCpp::InitFromArgv(int argc, const char* const* argv) {
  if (CEF_MEMBER_MISSING(struct_, init_from_argv))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: argv; type: simple_byaddr
  DCHECK(argv);
  if (!argv)
    return;

  // Execute
  struct_->init_from_argv(struct_,
      argc,
      argv);
}

void CefCommandLineCToCpp::InitFromString(const CefString& command_line) {
  if (CEF_MEMBER_MISSING(struct_, init_from_string))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: command_line; type: string_byref_const
  DCHECK(!command_line.empty());
  if (command_line.empty())
    return;

  // Execute
  struct_->init_from_string(struct_,
      command_line.GetStruct());
}

void CefCommandLineCToCpp::Reset() {
  if (CEF_MEMBER_MISSING(struct_, reset))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  struct_->reset(struct_);
}

void CefCommandLineCToCpp::GetArgv(std::vector<CefString>& argv) {
  if (CEF_MEMBER_MISSING(struct_, get_argv))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: argv; type: string_vec_byref
  cef_string_list_t argvList = cef_string_list_alloc();
  DCHECK(argvList);
  if (argvList)
    transfer_string_list_contents(argv, argvList);

  // Execute
  struct_->get_argv(struct_,
      argvList);

  // Restore param:argv; type: string_vec_byref
  if (argvList) {
    argv.clear();
    transfer_string_list_contents(argvList, argv);
    cef_string_list_free(argvList);
  }
}

CefString CefCommandLineCToCpp::GetCommandLineString() {
  if (CEF_MEMBER_MISSING(struct_, get_command_line_string))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_command_line_string(struct_);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

CefString CefCommandLineCToCpp::GetProgram() {
  if (CEF_MEMBER_MISSING(struct_, get_program))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_program(struct_);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

void CefCommandLineCToCpp::SetProgram(const CefString& program) {
  if (CEF_MEMBER_MISSING(struct_, set_program))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: program; type: string_byref_const
  DCHECK(!program.empty());
  if (program.empty())
    return;

  // Execute
  struct_->set_program(struct_,
      program.GetStruct());
}

bool CefCommandLineCToCpp::HasSwitches() {
  if (CEF_MEMBER_MISSING(struct_, has_switches))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->has_switches(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefCommandLineCToCpp::HasSwitch(const CefString& name) {
  if (CEF_MEMBER_MISSING(struct_, has_switch))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return false;

  // Execute
  int _retval = struct_->has_switch(struct_,
      name.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

CefString CefCommandLineCToCpp::GetSwitchValue(const CefString& name) {
  if (CEF_MEMBER_MISSING(struct_, get_switch_value))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return CefString();

  // Execute
  cef_string_userfree_t _retval = struct_->get_switch_value(struct_,
      name.GetStruct());

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

void CefCommandLineCToCpp::GetSwitches(SwitchMap& switches) {
  if (CEF_MEMBER_MISSING(struct_, get_switches))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: switches; type: string_map_single_byref
  cef_string_map_t switchesMap = cef_string_map_alloc();
  DCHECK(switchesMap);
  if (switchesMap)
    transfer_string_map_contents(switches, switchesMap);

  // Execute
  struct_->get_switches(struct_,
      switchesMap);

  // Restore param:switches; type: string_map_single_byref
  if (switchesMap) {
    switches.clear();
    transfer_string_map_contents(switchesMap, switches);
    cef_string_map_free(switchesMap);
  }
}

void CefCommandLineCToCpp::AppendSwitch(const CefString& name) {
  if (CEF_MEMBER_MISSING(struct_, append_switch))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return;

  // Execute
  struct_->append_switch(struct_,
      name.GetStruct());
}

void CefCommandLineCToCpp::AppendSwitchWithValue(const CefString& name,
    const CefString& value) {
  if (CEF_MEMBER_MISSING(struct_, append_switch_with_value))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: name; type: string_byref_const
  DCHECK(!name.empty());
  if (name.empty())
    return;
  // Verify param: value; type: string_byref_const
  DCHECK(!value.empty());
  if (value.empty())
    return;

  // Execute
  struct_->append_switch_with_value(struct_,
      name.GetStruct(),
      value.GetStruct());
}

bool CefCommandLineCToCpp::HasArguments() {
  if (CEF_MEMBER_MISSING(struct_, has_arguments))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->has_arguments(struct_);

  // Return type: bool
  return _retval?true:false;
}

void CefCommandLineCToCpp::GetArguments(ArgumentList& arguments) {
  if (CEF_MEMBER_MISSING(struct_, get_arguments))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: arguments; type: string_vec_byref
  cef_string_list_t argumentsList = cef_string_list_alloc();
  DCHECK(argumentsList);
  if (argumentsList)
    transfer_string_list_contents(arguments, argumentsList);

  // Execute
  struct_->get_arguments(struct_,
      argumentsList);

  // Restore param:arguments; type: string_vec_byref
  if (argumentsList) {
    arguments.clear();
    transfer_string_list_contents(argumentsList, arguments);
    cef_string_list_free(argumentsList);
  }
}

void CefCommandLineCToCpp::AppendArgument(const CefString& argument) {
  if (CEF_MEMBER_MISSING(struct_, append_argument))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: argument; type: string_byref_const
  DCHECK(!argument.empty());
  if (argument.empty())
    return;

  // Execute
  struct_->append_argument(struct_,
      argument.GetStruct());
}

void CefCommandLineCToCpp::PrependWrapper(const CefString& wrapper) {
  if (CEF_MEMBER_MISSING(struct_, prepend_wrapper))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: wrapper; type: string_byref_const
  DCHECK(!wrapper.empty());
  if (wrapper.empty())
    return;

  // Execute
  struct_->prepend_wrapper(struct_,
      wrapper.GetStruct());
}


#ifndef NDEBUG
template<> long CefCToCpp<CefCommandLineCToCpp, CefCommandLine,
    cef_command_line_t>::DebugObjCt = 0;
#endif

