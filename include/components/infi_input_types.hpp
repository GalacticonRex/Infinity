#ifndef __INFI_INPUT_TYPES_H__
#define __INFI_INPUT_TYPES_H__

#include "base/types.hpp"
#include "core/vector.hpp"
#include "components/infi_component_defs.hpp"

namespace Infinity {

	struct infi_key_type_object_t {
		virtual ~infi_key_type_object_t() { ; }

		virtual bool operator[] ( uint32 ) const = 0;
		virtual bool pressed( uint32, float64 ) const = 0;
		virtual bool released( uint32, float64 ) const = 0;
	};

	struct infi_mouse_type_object_t {
		virtual ~infi_mouse_type_object_t() { ; }

		virtual core::vec2i position() const = 0;
		virtual core::vec2i deltaPosition( Time::Point ) const = 0;

		virtual core::vec2i wheel() const = 0;

		virtual bool inside() const = 0;
	};

	struct infi_controller_type_object_t {
		virtual ~infi_controller_type_object_t() { ; }

		virtual float32 value( uint32 ) const = 0;
	};

}

#endif//__INFI_INPUT_TYPES_H__
