# Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

{
  'includes': [
    # Bring in the autogenerated source file lists.
    'cef_paths.gypi',
   ],
  'variables': {
    'includes_common': [
      'include/cef_base.h',
      'include/cef_pack_resources.h',
      'include/cef_pack_strings.h',
      'include/cef_runnable.h',
      'include/cef_trace_event.h',
      'include/cef_version.h',
      'include/internal/cef_build.h',
      'include/internal/cef_export.h',
      'include/internal/cef_ptr.h',
      'include/internal/cef_string.h',
      'include/internal/cef_string_list.h',
      'include/internal/cef_string_map.h',
      'include/internal/cef_string_multimap.h',
      'include/internal/cef_string_types.h',
      'include/internal/cef_string_wrappers.h',
      'include/internal/cef_time.h',
      'include/internal/cef_tuple.h',
      'include/internal/cef_types.h',
      'include/internal/cef_types_wrappers.h',
      '<@(autogen_cpp_includes)',
    ],
    'includes_capi': [
      'include/capi/cef_base_capi.h',
      '<@(autogen_capi_includes)',
    ],
    'includes_wrapper': [
      'include/wrapper/cef_byte_read_handler.h',
      'include/wrapper/cef_stream_resource_handler.h',
      'include/wrapper/cef_xml_object.h',
      'include/wrapper/cef_zip_archive.h',
    ],
    'includes_win': [
      'include/internal/cef_types_win.h',
      'include/internal/cef_win.h',
    ],
    'includes_mac': [
      'include/cef_application_mac.h',
      'include/internal/cef_mac.h',
      'include/internal/cef_types_mac.h',
    ],
    'includes_linux': [
      'include/internal/cef_linux.h',
      'include/internal/cef_types_linux.h',
    ],
    'libcef_sources_common': [
      'libcef_dll/cef_logging.h',
      'libcef_dll/cpptoc/cpptoc.h',
      'libcef_dll/ctocpp/ctocpp.h',
      'libcef_dll/libcef_dll.cc',
      'libcef_dll/libcef_dll2.cc',
      'libcef_dll/resource.h',
      'libcef_dll/transfer_util.cpp',
      'libcef_dll/transfer_util.h',
      '<@(autogen_library_side)',
    ],
    'libcef_dll_wrapper_sources_common': [
      'libcef_dll/cef_logging.h',
      'libcef_dll/cpptoc/base_cpptoc.h',
      'libcef_dll/cpptoc/cpptoc.h',
      'libcef_dll/ctocpp/base_ctocpp.h',
      'libcef_dll/ctocpp/ctocpp.h',
      'libcef_dll/transfer_util.cpp',
      'libcef_dll/transfer_util.h',
      'libcef_dll/wrapper/cef_byte_read_handler.cc',
      'libcef_dll/wrapper/cef_stream_resource_handler.cc',
      'libcef_dll/wrapper/cef_xml_object.cc',
      'libcef_dll/wrapper/cef_zip_archive.cc',
      'libcef_dll/wrapper/libcef_dll_wrapper.cc',
      'libcef_dll/wrapper/libcef_dll_wrapper2.cc',
      '<@(autogen_client_side)',
    ],
    'cefclient_sources_common': [
      'tests/cefclient/cefclient.cpp',
      'tests/cefclient/cefclient.h',
      'tests/cefclient/binding_test.cpp',
      'tests/cefclient/binding_test.h',
      'tests/cefclient/client_app.cpp',
      'tests/cefclient/client_app.h',
      'tests/cefclient/client_app_delegates.cpp',
      'tests/cefclient/client_handler.cpp',
      'tests/cefclient/client_handler.h',
      'tests/cefclient/client_renderer.cpp',
      'tests/cefclient/client_renderer.h',
      'tests/cefclient/client_switches.cpp',
      'tests/cefclient/client_switches.h',
      'tests/cefclient/dialog_test.cpp',
      'tests/cefclient/dialog_test.h',
      'tests/cefclient/dom_test.cpp',
      'tests/cefclient/dom_test.h',
      'tests/cefclient/res/binding.html',
      'tests/cefclient/res/dialogs.html',
      'tests/cefclient/res/domaccess.html',
      'tests/cefclient/res/localstorage.html',
      'tests/cefclient/res/logo.png',
      'tests/cefclient/res/xmlhttprequest.html',
      'tests/cefclient/resource_util.h',
      'tests/cefclient/scheme_test.cpp',
      'tests/cefclient/scheme_test.h',
      'tests/cefclient/string_util.cpp',
      'tests/cefclient/string_util.h',
      'tests/cefclient/util.h',
    ],
    'cefclient_sources_win': [
      'tests/cefclient/cefclient.rc',
      'tests/cefclient/cefclient_win.cpp',
      'tests/cefclient/client_handler_win.cpp',
      'tests/cefclient/resource.h',
      'tests/cefclient/res/cefclient.ico',
      'tests/cefclient/res/logoball.png',
      'tests/cefclient/res/small.ico',
      'tests/cefclient/resource_util_win.cpp',
    ],
    'cefclient_sources_mac': [
      'tests/cefclient/cefclient_mac.mm',
      'tests/cefclient/client_handler_mac.mm',
      'tests/cefclient/resource_util_mac.mm',
    ],
    'cefclient_sources_mac_helper': [
      'tests/cefclient/binding_test.cpp',
      'tests/cefclient/binding_test.h',
      'tests/cefclient/client_app.cpp',
      'tests/cefclient/client_app.h',
      'tests/cefclient/client_app_delegates.cpp',
      'tests/cefclient/client_handler.cpp',
      'tests/cefclient/client_handler.h',
      'tests/cefclient/client_handler_mac.mm',
      'tests/cefclient/client_renderer.cpp',
      'tests/cefclient/client_renderer.h',
      'tests/cefclient/client_switches.cpp',
      'tests/cefclient/client_switches.h',
      'tests/cefclient/dialog_test.cpp',
      'tests/cefclient/dialog_test.h',
      'tests/cefclient/dom_test.cpp',
      'tests/cefclient/dom_test.h',
      'tests/cefclient/process_helper_mac.cpp',
      'tests/cefclient/resource_util.h',
      'tests/cefclient/resource_util_mac.mm',
      'tests/cefclient/scheme_test.cpp',
      'tests/cefclient/scheme_test.h',
      'tests/cefclient/string_util.cpp',
      'tests/cefclient/string_util.h',
      'tests/cefclient/util.h',
    ],
    'cefclient_bundle_resources_mac': [
      'tests/cefclient/mac/cefclient.icns',
      'tests/cefclient/mac/English.lproj/InfoPlist.strings',
      'tests/cefclient/mac/English.lproj/MainMenu.xib',
      'tests/cefclient/mac/Info.plist',
      'tests/cefclient/res/binding.html',
      'tests/cefclient/res/dialogs.html',
      'tests/cefclient/res/domaccess.html',
      'tests/cefclient/res/localstorage.html',
      'tests/cefclient/res/logo.png',
      'tests/cefclient/res/xmlhttprequest.html',
    ],
    'cefclient_sources_linux': [
      'tests/cefclient/cefclient_gtk.cpp',
      'tests/cefclient/client_handler_gtk.cpp',
      'tests/cefclient/resource_util_linux.cpp',
    ],
    'cefclient_bundle_resources_linux': [
      'tests/cefclient/res/binding.html',
      'tests/cefclient/res/dialogs.html',
      'tests/cefclient/res/domaccess.html',
      'tests/cefclient/res/localstorage.html',
      'tests/cefclient/res/logo.png',
      'tests/cefclient/res/xmlhttprequest.html',
    ],
  },
}
