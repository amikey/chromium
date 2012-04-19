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

#include "libcef_dll/ctocpp/menu_model_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefMenuModelCToCpp::Clear() {
  if (CEF_MEMBER_MISSING(struct_, clear))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->clear(struct_);

  // Return type: bool
  return _retval?true:false;
}

int CefMenuModelCToCpp::GetCount() {
  if (CEF_MEMBER_MISSING(struct_, get_count))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_count(struct_);

  // Return type: simple
  return _retval;
}

bool CefMenuModelCToCpp::AddSeparator() {
  if (CEF_MEMBER_MISSING(struct_, add_separator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->add_separator(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::AddItem(int command_id, const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, add_item))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->add_item(struct_,
      command_id,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::AddCheckItem(int command_id, const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, add_check_item))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->add_check_item(struct_,
      command_id,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::AddRadioItem(int command_id, const CefString& label,
    int group_id) {
  if (CEF_MEMBER_MISSING(struct_, add_radio_item))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->add_radio_item(struct_,
      command_id,
      label.GetStruct(),
      group_id);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefMenuModel> CefMenuModelCToCpp::AddSubMenu(int command_id,
    const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, add_sub_menu))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return NULL;

  // Execute
  cef_menu_model_t* _retval = struct_->add_sub_menu(struct_,
      command_id,
      label.GetStruct());

  // Return type: refptr_same
  return CefMenuModelCToCpp::Wrap(_retval);
}

bool CefMenuModelCToCpp::InsertSeparatorAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, insert_separator_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->insert_separator_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::InsertItemAt(int index, int command_id,
    const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, insert_item_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->insert_item_at(struct_,
      index,
      command_id,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::InsertCheckItemAt(int index, int command_id,
    const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, insert_check_item_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->insert_check_item_at(struct_,
      index,
      command_id,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::InsertRadioItemAt(int index, int command_id,
    const CefString& label, int group_id) {
  if (CEF_MEMBER_MISSING(struct_, insert_radio_item_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->insert_radio_item_at(struct_,
      index,
      command_id,
      label.GetStruct(),
      group_id);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefMenuModel> CefMenuModelCToCpp::InsertSubMenuAt(int index,
    int command_id, const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, insert_sub_menu_at))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return NULL;

  // Execute
  cef_menu_model_t* _retval = struct_->insert_sub_menu_at(struct_,
      index,
      command_id,
      label.GetStruct());

  // Return type: refptr_same
  return CefMenuModelCToCpp::Wrap(_retval);
}

bool CefMenuModelCToCpp::Remove(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, remove))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->remove(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::RemoveAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, remove_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->remove_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

int CefMenuModelCToCpp::GetIndexOf(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, get_index_of))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_index_of(struct_,
      command_id);

  // Return type: simple
  return _retval;
}

int CefMenuModelCToCpp::GetCommandIdAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, get_command_id_at))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_command_id_at(struct_,
      index);

  // Return type: simple
  return _retval;
}

bool CefMenuModelCToCpp::SetCommandIdAt(int index, int command_id) {
  if (CEF_MEMBER_MISSING(struct_, set_command_id_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_command_id_at(struct_,
      index,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

CefString CefMenuModelCToCpp::GetLabel(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, get_label))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_label(struct_,
      command_id);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

CefString CefMenuModelCToCpp::GetLabelAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, get_label_at))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_label_at(struct_,
      index);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

bool CefMenuModelCToCpp::SetLabel(int command_id, const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, set_label))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->set_label(struct_,
      command_id,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetLabelAt(int index, const CefString& label) {
  if (CEF_MEMBER_MISSING(struct_, set_label_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: label; type: string_byref_const
  DCHECK(!label.empty());
  if (label.empty())
    return false;

  // Execute
  int _retval = struct_->set_label_at(struct_,
      index,
      label.GetStruct());

  // Return type: bool
  return _retval?true:false;
}

CefMenuModel::MenuItemType CefMenuModelCToCpp::GetType(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, get_type))
    return MENUITEMTYPE_NONE;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_menu_item_type_t _retval = struct_->get_type(struct_,
      command_id);

  // Return type: simple
  return _retval;
}

CefMenuModel::MenuItemType CefMenuModelCToCpp::GetTypeAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, get_type_at))
    return MENUITEMTYPE_NONE;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_menu_item_type_t _retval = struct_->get_type_at(struct_,
      index);

  // Return type: simple
  return _retval;
}

int CefMenuModelCToCpp::GetGroupId(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, get_group_id))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_group_id(struct_,
      command_id);

  // Return type: simple
  return _retval;
}

int CefMenuModelCToCpp::GetGroupIdAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, get_group_id_at))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_group_id_at(struct_,
      index);

  // Return type: simple
  return _retval;
}

bool CefMenuModelCToCpp::SetGroupId(int command_id, int group_id) {
  if (CEF_MEMBER_MISSING(struct_, set_group_id))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_group_id(struct_,
      command_id,
      group_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetGroupIdAt(int index, int group_id) {
  if (CEF_MEMBER_MISSING(struct_, set_group_id_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_group_id_at(struct_,
      index,
      group_id);

  // Return type: bool
  return _retval?true:false;
}

CefRefPtr<CefMenuModel> CefMenuModelCToCpp::GetSubMenu(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, get_sub_menu))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_menu_model_t* _retval = struct_->get_sub_menu(struct_,
      command_id);

  // Return type: refptr_same
  return CefMenuModelCToCpp::Wrap(_retval);
}

CefRefPtr<CefMenuModel> CefMenuModelCToCpp::GetSubMenuAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, get_sub_menu_at))
    return NULL;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_menu_model_t* _retval = struct_->get_sub_menu_at(struct_,
      index);

  // Return type: refptr_same
  return CefMenuModelCToCpp::Wrap(_retval);
}

bool CefMenuModelCToCpp::IsVisible(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, is_visible))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_visible(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::IsVisibleAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, is_visible_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_visible_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetVisible(int command_id, bool visible) {
  if (CEF_MEMBER_MISSING(struct_, set_visible))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_visible(struct_,
      command_id,
      visible);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetVisibleAt(int index, bool visible) {
  if (CEF_MEMBER_MISSING(struct_, set_visible_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_visible_at(struct_,
      index,
      visible);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::IsEnabled(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, is_enabled))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_enabled(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::IsEnabledAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, is_enabled_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_enabled_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetEnabled(int command_id, bool enabled) {
  if (CEF_MEMBER_MISSING(struct_, set_enabled))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_enabled(struct_,
      command_id,
      enabled);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetEnabledAt(int index, bool enabled) {
  if (CEF_MEMBER_MISSING(struct_, set_enabled_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_enabled_at(struct_,
      index,
      enabled);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::IsChecked(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, is_checked))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_checked(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::IsCheckedAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, is_checked_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_checked_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetChecked(int command_id, bool checked) {
  if (CEF_MEMBER_MISSING(struct_, set_checked))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_checked(struct_,
      command_id,
      checked);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetCheckedAt(int index, bool checked) {
  if (CEF_MEMBER_MISSING(struct_, set_checked_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_checked_at(struct_,
      index,
      checked);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::HasAccelerator(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, has_accelerator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->has_accelerator(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::HasAcceleratorAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, has_accelerator_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->has_accelerator_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetAccelerator(int command_id, int key_code,
    bool shift_pressed, bool ctrl_pressed, bool alt_pressed) {
  if (CEF_MEMBER_MISSING(struct_, set_accelerator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_accelerator(struct_,
      command_id,
      key_code,
      shift_pressed,
      ctrl_pressed,
      alt_pressed);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::SetAcceleratorAt(int index, int key_code,
    bool shift_pressed, bool ctrl_pressed, bool alt_pressed) {
  if (CEF_MEMBER_MISSING(struct_, set_accelerator_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->set_accelerator_at(struct_,
      index,
      key_code,
      shift_pressed,
      ctrl_pressed,
      alt_pressed);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::RemoveAccelerator(int command_id) {
  if (CEF_MEMBER_MISSING(struct_, remove_accelerator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->remove_accelerator(struct_,
      command_id);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::RemoveAcceleratorAt(int index) {
  if (CEF_MEMBER_MISSING(struct_, remove_accelerator_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->remove_accelerator_at(struct_,
      index);

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::GetAccelerator(int command_id, int& key_code,
    bool& shift_pressed, bool& ctrl_pressed, bool& alt_pressed) {
  if (CEF_MEMBER_MISSING(struct_, get_accelerator))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: shift_pressed; type: bool_byref
  int shift_pressedInt = shift_pressed;
  // Translate param: ctrl_pressed; type: bool_byref
  int ctrl_pressedInt = ctrl_pressed;
  // Translate param: alt_pressed; type: bool_byref
  int alt_pressedInt = alt_pressed;

  // Execute
  int _retval = struct_->get_accelerator(struct_,
      command_id,
      &key_code,
      &shift_pressedInt,
      &ctrl_pressedInt,
      &alt_pressedInt);

  // Restore param:shift_pressed; type: bool_byref
  shift_pressed = shift_pressedInt?true:false;
  // Restore param:ctrl_pressed; type: bool_byref
  ctrl_pressed = ctrl_pressedInt?true:false;
  // Restore param:alt_pressed; type: bool_byref
  alt_pressed = alt_pressedInt?true:false;

  // Return type: bool
  return _retval?true:false;
}

bool CefMenuModelCToCpp::GetAcceleratorAt(int index, int& key_code,
    bool& shift_pressed, bool& ctrl_pressed, bool& alt_pressed) {
  if (CEF_MEMBER_MISSING(struct_, get_accelerator_at))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Translate param: shift_pressed; type: bool_byref
  int shift_pressedInt = shift_pressed;
  // Translate param: ctrl_pressed; type: bool_byref
  int ctrl_pressedInt = ctrl_pressed;
  // Translate param: alt_pressed; type: bool_byref
  int alt_pressedInt = alt_pressed;

  // Execute
  int _retval = struct_->get_accelerator_at(struct_,
      index,
      &key_code,
      &shift_pressedInt,
      &ctrl_pressedInt,
      &alt_pressedInt);

  // Restore param:shift_pressed; type: bool_byref
  shift_pressed = shift_pressedInt?true:false;
  // Restore param:ctrl_pressed; type: bool_byref
  ctrl_pressed = ctrl_pressedInt?true:false;
  // Restore param:alt_pressed; type: bool_byref
  alt_pressed = alt_pressedInt?true:false;

  // Return type: bool
  return _retval?true:false;
}


#ifndef NDEBUG
template<> long CefCToCpp<CefMenuModelCToCpp, CefMenuModel,
    cef_menu_model_t>::DebugObjCt = 0;
#endif

