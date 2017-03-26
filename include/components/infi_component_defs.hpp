#ifndef __INFI_COMPONENT_DEFS_HPP__
#define __INFI_COMPONENT_DEFS_HPP__

#include "base/lib_export.hpp"

namespace Infinity {
	struct DEFINE_EXPORT infi_named_object_t;
	
	struct DEFINE_EXPORT infi_window_t;
	struct DEFINE_EXPORT infi_keyboard_t;
	struct DEFINE_EXPORT infi_mouse_t;
	struct DEFINE_EXPORT infi_renderable_t;

	struct DEFINE_EXPORT infi_key_type_object_t;
	struct DEFINE_EXPORT infi_mouse_type_object_t;
	struct DEFINE_EXPORT infi_controller_type_object_t;
	struct DEFINE_EXPORT infi_input_events_t;

	struct DEFINE_EXPORT infi_extension_t;
	struct DEFINE_EXPORT infi_async_t;

	struct DEFINE_EXPORT infi_operator_thread_t;
	struct DEFINE_EXPORT infi_operator_thread_pool_t;

	struct DEFINE_EXPORT infi_update_manager_t;
}

#endif//__INFI_COMPONENTS_HPP__