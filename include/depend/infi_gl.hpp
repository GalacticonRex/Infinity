#ifndef __INFI_GL_INCLUDE_H__
#define __INFI_GL_INCLUDE_H__

#define GLEW_NO_GLU
#define GLEW_STATIC
#include <gl/glew.h>
#include <gl/gl.h>

namespace Infinity {
	enum class infi_t {
		NONE	= GL_NONE,			 // 0
		BOOL	= GL_BOOL,			 // 1
		BYTE	= GL_BYTE,			 // 2
		UBYTE	= GL_UNSIGNED_BYTE,	 // 3
		SHORT	= GL_SHORT,			 // 4
		USHORT	= GL_UNSIGNED_SHORT, // 5
		FLOAT	= GL_FLOAT,			 // 6
		DOUBLE	= GL_DOUBLE,		 // 7
		INT		= GL_INT,			 // 8
		UINT	= GL_UNSIGNED_INT,	 // 9
		MATRIX = 1,
		SAMPLER2D = 2,
		POINTER = 3
	};
}

#endif//__INFI_GL_INCLUDE_H__
