#ifndef __INFI_TYPES_H__
#define __INFI_TYPES_H__

#include "main/infi_export.h"
#include "main/infi_gl.h"

#define MATH_PI 3.1415926535897932384626f
#define MATH_TAU 6.2831853071795864769252f	
#define MATH_E  2.7182818284590452353603f

namespace INFI {
	typedef unsigned char 			uint8;
	typedef unsigned short 			uint16;
	typedef unsigned int 			uint32;
	typedef long long unsigned int 	uint64;
	typedef char 					int8;
	typedef short 					int16;
	typedef int 					int32;
	typedef long long int 			int64;
	typedef float					float32;
	typedef double					float64;
	
	template<typename T>
	using InfiGetter = T (*)();
	
	template<typename T>
	using InfiSetter = void (*)( T );
	
	enum infi_t {
		INFI_NONE	= GL_NONE,			 // 0
		INFI_BOOL	= GL_BOOL,			 // 1
		INFI_BYTE	= GL_BYTE,			 // 2
		INFI_UBYTE	= GL_UNSIGNED_BYTE,	 // 3
		INFI_SHORT	= GL_SHORT,			 // 4
		INFI_USHORT	= GL_UNSIGNED_SHORT, // 5
		INFI_FLOAT	= GL_FLOAT,			 // 6
		INFI_DOUBLE	= GL_DOUBLE,		 // 7
		INFI_INT	= GL_INT,			 // 8
		INFI_UINT	= GL_UNSIGNED_INT,	 // 9
		INFI_MATRIX = 1,
		INFI_SAMPLER2D = 2,
		INFI_POINTER = 3
	};

	INFI_FUNCTION( uint32, infi_sizeof, ( infi_t ) );
	INFI_FUNCTION( const char*, infi_typename, ( infi_t ) );
}

#endif//__INFI_TYPES_H__