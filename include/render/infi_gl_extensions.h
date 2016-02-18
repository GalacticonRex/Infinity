#ifndef __INFI_OPENGL_EXTENSIONS_H__
#define __INFI_OPENGL_EXTENSIONS_H__

#include "main/infi_gl.h"
#include "core/infi_string.h"

namespace INFI {
namespace render {
	
	struct infi_gl_info_t {
		
		struct __version__ {
			uint32 major() const;
			uint32 minor() const;
			uint32 patch() const;
		} version;
		
		struct __glsl__ {
			uint32 major() const;
			uint32 minor() const;
			uint32 patch() const;
		} glsl;
		
		struct __texture__ {
			bool npot() const;
			bool rg() const;
			bool storage() const;
			bool clear() const;
			bool float_store() const;
			bool integer_render() const;
			bool swizzle() const;
			bool depth() const;
			bool stencil() const;
		} texture;
		
		struct __framebuffer__ {
			bool obj() const;
			bool blit() const;
		} framebuffer;
		
		struct __shader__ {
			bool vertex() const;
			bool fragment() const;
			bool geometry() const;
			bool tessellation() const;
			bool compute() const;
			bool subroutine() const;
		} shaders;
		
		bool multisample() const;
		bool pixel_buffers() const;
		bool buffer_copy() const;
		bool transform_feedback() const;
		bool transform_feedback2() const;
		bool transform_feedback3() const;
		bool draw_instanced() const;
		bool draw_elem_basev() const;
		bool timer_query() const;
		bool vertex_buffers() const;
		bool vertex_arrays() const;
		bool program_binary() const;
		bool debug_output() const;
		
		const char* vendor() const;
		const char* renderer() const;
		
		struct __max__ {
			uint32 vertex_attribs() const;
			uint32 texture_units() const;
			uint32 color_attachments() const;
		} maximum;
		
	};
	
	INFI_FUNCTION( const infi_gl_info_t&, InfiGLGetInfo, () );
	
	#define GL INFI::render::InfiGLGetInfo()
	
	// determine if the GL was set up properly
	INFI_FUNCTION( bool, InfiGLReady, () );
	
	// update OpenGL extensions
	INFI_FUNCTION( void, InfiGLUpdateInfo, () );
	
	// read back OpenGL values
	INFI_FUNCTION( void, InfiGLPrint, ( std::ostream&, GLenum ) );
	
	struct INFI_EXPORT infigl_enum {
		GLenum en;
		infigl_enum( GLenum );
	};
	std::ostream& operator<< ( std::ostream& ostr, infigl_enum en );
	
} }

#endif//__INFI_OPENGL_EXTENSIONS_H__