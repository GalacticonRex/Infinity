#ifndef __INFI_GL_ENABLED_H__
#define __INFI_GL_ENABLED_H__

#include "base/types.hpp"
#include "base/lib_export.hpp"
#include "render/gl/infi_gl_defs.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_enabled_t {
		uint32 data;

		infi_gl_enabled_t( const infi_gl_t& );

		bool operator[] ( uint32 elem )
			{ return ( ( data & elem ) != 0 ); }
		void set( uint32 elem )
			{ data |= elem; }
		void unset( uint32 elem )
			{ data &= ~elem; }
	};

} }

#endif//__INFI_GL_ENABLED_H__
