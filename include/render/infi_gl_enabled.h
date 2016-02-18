#ifndef __INFI_GL_ENABLED_H__
#define __INFI_GL_ENABLED_H__

#include "main/infi_types.h"
#include "main/infi_export.h"

namespace INFI {
namespace render {

	const uint32 INFI_BLEND						= 0x00000001,
				 INFI_COLOR_LOGIC_OP			= 0x00000002,
				 INFI_CULL_FACE					= 0x00000004,
				 INFI_DEPTH_CLAMP				= 0x00000008,
				 INFI_DEBUG_OUTPUT 				= 0x00000010,
				 INFI_DEBUG_OUTPUT_SYNCHRONOUS	= 0x00000020,
				 INFI_DEPTH_TEST				= 0x00000040,
				 INFI_DITHER					= 0x00000080,
				 INFI_FRAMEBUFFER_SRGB			= 0x00000100,
				 INFI_LINE_SMOOTH				= 0x00000200,
				 INFI_MULTISAMPLE				= 0x00000400,
				 INFI_POLYGON_SMOOTH			= 0x00000800,
				 INFI_POLYGON_OFFSET_FILL		= 0x00001000,
				 INFI_POLYGON_OFFSET_LINE		= 0x00002000,
				 INFI_POLYGON_OFFSET_POINT		= 0x00004000,
				 INFI_PROGRAM_POINT_SIZE		= 0x00008000,
				 INFI_PRIMITIVE_RESTART			= 0x00010000,
				 INFI_SAMPLE_ALPHA_TO_COVERAGE	= 0x00020000,
				 INFI_SAMPLE_ALPHA_TO_ONE		= 0x00040000,
				 INFI_SAMPLE_COVERAGE 			= 0x00080000,
				 INFI_SAMPLE_MASK				= 0x00100000,
				 INFI_SCISSOR_TEST				= 0x00200000,
				 INFI_STENCIL_TEST				= 0x00400000,
				 INFI_TEXTURE_CUBE_MAP_SEAMLESS	= 0x00800000,
				 INFI_CLIP_DISTANCE0 			= 0x01000000,
				 INFI_CLIP_DISTANCE1 			= 0x02000000,
				 INFI_CLIP_DISTANCE2 			= 0x04000000,
				 INFI_CLIP_DISTANCE3 			= 0x08000000,
				 INFI_CLIP_DISTANCE4 			= 0x10000000,
				 INFI_CLIP_DISTANCE5 			= 0x20000000;
	
	struct infi_gl_enabled_t {
		uint32 data;
		
		bool operator[] ( uint32 elem )
			{ return ( ( data & elem ) != 0 ); }
		void set( uint32 elem )
			{ data |= elem; }
		void unset( uint32 elem )
			{ data &= ~elem; }
	};
	
	INFI_FUNCTION( void, InfiGLSyncEnabled, ( infi_gl_enabled_t* ) );
	
} }

#endif//__INFI_GL_ENABLED_H__