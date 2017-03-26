#ifndef __INFI_GL_ENUMERATIONS_HPP__
#define __INFI_GL_ENUMERATIONS_HPP__

#include <iostream>
#include "base/types.hpp"
#include "base/lib_export.hpp"

namespace Infinity {
namespace Render {

	DEFINE_EXPORTED_FUNCTION( const char*, glenum, ( uint32 ) );
	DEFINE_EXPORTED_FUNCTION( void, InfiGLPrint, ( std::ostream&, uint32 ) );
	struct DEFINE_EXPORT infigl_enum {
		uint32 en;
		infigl_enum( uint32 );
	};
	std::ostream& operator<< ( std::ostream& ostr, infigl_enum en );

} }

#endif//__INFI_GL_ENUMERATIONS_HPP__