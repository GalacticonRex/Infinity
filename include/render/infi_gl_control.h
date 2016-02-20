#ifndef __INFI_OPENGL_CONTROL_H__
#define __INFI_OPENGL_CONTROL_H__

#include "main/infi_structs.h"
#include "render/infi_render_structs.h"
#include "render/infi_blend_mode.h"
#include "render/infi_stencil_mode.h"
#include "render/infi_gl_extensions.h"
#include "render/infi_gl_state.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiGLPushContext, ( infi_window_t* ) );
	INFI_FUNCTION( void, InfiGLPopContext, () );
	
	INFI_FUNCTION( const infi_gl_state_t&, InfiGLState, () );
	
	// misc GL function wrappers
	INFI_FUNCTION( void, InfiGLSyncState, () );
	
	INFI_FUNCTION( void, InfiGLDrawArray, ( INFI_render_style,
											uint32 start,
											uint32 count,
											bool indexed = false ) );
	
	INFI_FUNCTION( void, InfiGLDrawElements, ( INFI_render_style,
											   infi_t type,
											   uint32 count,
											   uint32 start = 0,
											   uint32 basevertex = 0,
											   bool indexed = false ) );
	
	// change the GL state
	// there is typically one state per window
	INFI_FUNCTION( void, InfiLEmptyGLStateCache, () );
	INFI_FUNCTION( void, InfiGLInitDefaultState, () );
	INFI_FUNCTION( uint32, InfiGLCreateState, () );
	INFI_FUNCTION( bool, InfiGLFreeState, ( uint32 ) );
	INFI_FUNCTION( bool, InfiGLChangeState, ( uint32 ) );
	
	// reset opengl objects to their base values
	INFI_FUNCTION_( void, InfiGLResetViewport );
	INFI_FUNCTION_( void, InfiGLResetTexture );
	INFI_FUNCTION_( void, InfiGLResetFramebuffer );
	INFI_FUNCTION_( void, InfiGLResetArrayBuffer );
	INFI_FUNCTION_( void, InfiGLResetIndexBuffer );
	INFI_FUNCTION_( void, InfiGLResetProgram );
	INFI_FUNCTION_( void, InfiGLResetPackBuffer );
	INFI_FUNCTION_( void, InfiGLResetUnpackBuffer );
	INFI_FUNCTION_( void, InfiGLResetDrawBuffer );
	INFI_FUNCTION_( void, InfiGLResetVertexArray );
	INFI_FUNCTION_( void, InfiGLResetBlendMode );
	INFI_FUNCTION_( void, InfiGLResetBlendColor );
	INFI_FUNCTION_( void, InfiGLResetAttribFrame );
	
	INFI_FUNCTION_( void, InfiGLRequireViewport );
	INFI_FUNCTION_( void, InfiGLRequireTexture );
	INFI_FUNCTION_( void, InfiGLRequireFramebuffer );
	INFI_FUNCTION_( void, InfiGLRequireArrayBuffer );
	INFI_FUNCTION_( void, InfiGLRequireIndexBuffer );
	INFI_FUNCTION_( void, InfiGLRequireProgram );
	INFI_FUNCTION_( void, InfiGLRequirePackBuffer );
	INFI_FUNCTION_( void, InfiGLRequireUnpackBuffer );
	INFI_FUNCTION_( void, InfiGLRequireDrawBuffer );
	INFI_FUNCTION_( void, InfiGLRequireVertexArray );
	INFI_FUNCTION_( void, InfiGLRequireBlendMode );
	INFI_FUNCTION_( void, InfiGLRequireBlendColor );
	INFI_FUNCTION_( void, InfiGLRequireAttribFrame );
	
	INFI_FUNCTION( void, InfiGLSetWriteBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLSetReadBuffer, ( uint32 ) );

	// bind opengl objects
	INFI_FUNCTION( void, InfiGLPushFramebuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushFramebuffer, ( uint32 r, uint32 w ) );
	INFI_FUNCTION( void, InfiGLPushFramebufferDraw, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushFramebufferRead, ( uint32 ) );
	
	INFI_FUNCTION( void, InfiGLPushColorMask, ( bool, bool, bool, bool ) );
	INFI_FUNCTION( void, InfiGLPushDepthMask, ( bool ) );
	INFI_FUNCTION( void, InfiGLPushDepthMode, ( GLenum ) );
	INFI_FUNCTION( void, InfiGLPushStencilFunc, ( const infi_stencil_t* ) );
	
	INFI_FUNCTION( void, InfiGLPushViewport, ( const core::rect& ) );
	INFI_FUNCTION( void, InfiGLPushTextureFrame, () );
	INFI_FUNCTION( void, InfiGLPushTexture, ( uint32, uint32 = 0 ) );
	INFI_FUNCTION( void, InfiGLPushActiveTexture, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushArrayBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushIndexBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushProgram, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushPackBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushUnpackBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLPushDrawBuffer, ( GLenum ) );
	INFI_FUNCTION( void, InfiGLPushVertexArray, ( uint32 ) );
	
	INFI_FUNCTION( void, InfiGLPushBlendMode, ( const infi_blend_t* ) );
	INFI_FUNCTION( void, InfiGLPushBlendColor, ( const core::vec4& ) );
	
	// unbind opengl objects
	INFI_FUNCTION( void, InfiGLPopFramebuffer, () );
	INFI_FUNCTION( void, InfiGLPopFramebufferDraw, () );
	INFI_FUNCTION( void, InfiGLPopFramebufferRead, () );
	
	INFI_FUNCTION( void, InfiGLPopViewport, () );
	INFI_FUNCTION( void, InfiGLPopTexture, () );
	INFI_FUNCTION( void, InfiGLPopTextureFrame, () );
	INFI_FUNCTION( void, InfiGLPopArrayBuffer, () );
	INFI_FUNCTION( void, InfiGLPopIndexBuffer, () );
	INFI_FUNCTION( void, InfiGLPopProgram, () );
	INFI_FUNCTION( void, InfiGLPopPackBuffer, () );
	INFI_FUNCTION( void, InfiGLPopUnpackBuffer, () );
	INFI_FUNCTION( void, InfiGLPopDrawBuffer, () );
	INFI_FUNCTION( void, InfiGLPopVertexArray, () );
	
	INFI_FUNCTION( void, InfiGLPopBlendMode, () );
	INFI_FUNCTION( void, InfiGLPopBlendColor, () );
	
	INFI_FUNCTION( void, InfiGLPopColorMask, () );
	INFI_FUNCTION( void, InfiGLPopDepthMask, () );
	INFI_FUNCTION( void, InfiGLPopDepthMode, () );
	INFI_FUNCTION( void, InfiGLPopStencilFunc, () );
	
	// set unstacked buffers
	INFI_FUNCTION( void, InfiGLSetWriteBuffer, ( uint32 ) );
	INFI_FUNCTION( void, InfiGLSetReadBuffer, ( uint32 ) );
	
	// get GL data current bound
	INFI_FUNCTION( uint32, InfiGLGetTexture, () );
	
	// set base values (set to when stack is empty)
	INFI_FUNCTION( void, InfiGLSetDefaultBlendMode, ( const infi_blend_t* = NULL ) );
	INFI_FUNCTION( void, InfiGLSetDefaultProgram, ( uint32 = 0 ) );
	
	// debugging operations
	INFI_FUNCTION_( void, InfiGLDebugDisplayCurrentState );
	INFI_FUNCTION_( void, InfiGLDebugDisplayStateStack );
	
} }

#endif // __INFI_OPENGL_CONTROL_H__