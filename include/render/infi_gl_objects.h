#ifndef __INFI_GL_OBJECTS_H__
#define __INFI_GL_OBJECTS_H__

#include "render/infi_gl_wrapper.h"

namespace INFI {
namespace render {
	
	void InfiGLDestroyContextObjects( SDL_GLContext );
	
	uint32 InfiGLCreateFramebuffer();
	uint32 InfiGLCreateVertexArray();
	
	void InfiGLDestroyFramebuffer( uint32 );
	void InfiGLDestroyVertexArray( uint32 );
	
} }

#endif//__INFI_GL_OBJECTS_H__