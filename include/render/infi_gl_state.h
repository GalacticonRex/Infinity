#ifndef __INFI_GL_STATE_H__
#define __INFI_GL_STATE_H__

#include "core/infi_stack.h"
#include "core/infi_vector.h"
#include "core/infi_rect.h"
#include "render/infi_gl_enabled.h"

namespace INFI {
namespace render {
	
	const uint32 INFI_GL_STATE_BLEND_MODE			= 0x00000001,
				 INFI_GL_STATE_DEPTH_MODE			= 0x00000002,
				 INFI_GL_STATE_STENCIL_MODE			= 0x00000004,
				 INFI_GL_STATE_TEXTURE				= 0x00000008,
				 INFI_GL_STATE_ACTIVE_TEXTURE		= 0x00000010,
				 INFI_GL_STATE_VIEWPORT				= 0x00000020,
				 INFI_GL_STATE_DRAW_FRAMEBUFFER		= 0x00000040,
				 INFI_GL_STATE_READ_FRAMEBUFFER		= 0x00000080,
				 INFI_GL_STATE_ARRAY_BUFFER			= 0x00000100,
				 INFI_GL_STATE_ELEMENT_ARRAY_BUFFER	= 0x00000200,
				 INFI_GL_STATE_SHADER_PROGRAM		= 0x00000400,
				 INFI_GL_STATE_PIXEL_PACK			= 0x00000800,
				 INFI_GL_STATE_PIXEL_UNPACK			= 0x00001000,
				 INFI_GL_STATE_VERTEXARRAY			= 0x00002000;
	
	struct infi_gl_state_t {
		core::stack_t<
			infi_gl_enabled_t>		enabled;
		
		core::stack_t<uint32>		texframe;
		core::stack_t<
			core::vec2_t<uint32> >	activetex;
		core::array_t<
			core::stack_t<GLuint> > textures;
		core::stack_t<GLuint> 		framebuffersread;
		core::stack_t<GLuint> 		framebuffersdraw;
		core::stack_t<GLuint> 		arraybuffers;
		core::stack_t<GLuint> 		indexbuffers;
		core::stack_t<GLuint> 		programs;
		core::stack_t<GLuint> 		packbuffers;
		core::stack_t<GLuint> 		unpackbuffers;
		core::stack_t<GLuint> 		vertexarrays;
		
		core::stack_t<GLenum> 		drawbuffers;
		core::stack_t<core::rect> 	viewports;
		
		core::stack_t<core::vec4b> 	colormask;
		core::stack_t<GLenum> 		depthmode;
		core::stack_t<bool> 		depthmask;
		core::stack_t<uint32> 		stencilusage;
		
		struct {
			core::stack_t<GLenum> 	func;
			core::stack_t<GLint> 	ref;
			core::stack_t<GLuint> 	mask;
			core::stack_t<GLenum> 	sfail;
			core::stack_t<GLenum> 	dpfail;
			core::stack_t<GLenum> 	dppass;
			core::stack_t<GLuint> 	wmask;
		} stencilfront, stencilback;
		
		core::stack_t<uint32> 		blendusage;
		core::stack_t<GLenum> 		srcalpha;
		core::stack_t<GLenum> 		dstalpha;
		core::stack_t<GLenum> 		srccolor;
		core::stack_t<GLenum> 		dstcolor;
		core::stack_t<GLenum> 		funcalpha;
		core::stack_t<GLenum> 		funccolor;
		core::stack_t<core::vec4> 	color;
	};
	
	INFI_FUNCTION( void, InfiGLClearState, ( infi_gl_state_t* ) );
	INFI_FUNCTION( void, InfiGLSyncState, ( infi_gl_state_t* ) );
	
} }

#endif//__INFI_GL_STATE_H__