#include "render/infi_gl_state.h"
#include "render/infi_gl_wrapper.h"

namespace INFI {
namespace render {
	
	void InfiGLClearState( infi_gl_state_t* ctrl ) {
		ctrl->enabled.clear();
		ctrl->texframe.clear();
		ctrl->activetex.clear();
		ctrl->textures.clear();
		ctrl->framebuffersread.clear();
		ctrl->framebuffersdraw.clear();
		ctrl->arraybuffers.clear();
		ctrl->indexbuffers.clear();
		ctrl->programs.clear();
		ctrl->packbuffers.clear();
		ctrl->unpackbuffers.clear();
		ctrl->vertexarrays.clear();
		ctrl->drawbuffers.clear();
		ctrl->viewports.clear();
		ctrl->colormask.clear();
		ctrl->depthmode.clear();
		ctrl->depthmask.clear();
		ctrl->stencilusage.clear();
		ctrl->stencilfront.func.clear();
		ctrl->stencilfront.ref.clear();
		ctrl->stencilfront.mask.clear();
		ctrl->stencilfront.sfail.clear();
		ctrl->stencilfront.dpfail.clear();
		ctrl->stencilfront.dppass.clear();
		ctrl->stencilfront.wmask.clear();
		ctrl->stencilback.func.clear();
		ctrl->stencilback.ref.clear();
		ctrl->stencilback.mask.clear();
		ctrl->stencilback.sfail.clear();
		ctrl->stencilback.dpfail.clear();
		ctrl->stencilback.dppass.clear();
		ctrl->stencilback.wmask.clear();
		ctrl->blendusage.clear();
		ctrl->srcalpha.clear();
		ctrl->dstalpha.clear();
		ctrl->srccolor.clear();
		ctrl->dstcolor.clear();
		ctrl->funcalpha.clear();
		ctrl->funccolor.clear();
		ctrl->color.clear();
	}
	
	#define STATE_NAME ctrl
	#define BUFFER_NAME buffer
	#define GL_GET_ENABLED( bit, obj ) \
			InfiGLGetIntegerv( bit, &BUFFER_NAME ); \
			STATE_NAME->obj.push( BUFFER_NAME );
	
	void InfiGLSyncState( infi_gl_state_t* STATE_NAME ) {
		
		InfiGLClearState( STATE_NAME );
		
		int32 BUFFER_NAME;
		
		infi_gl_enabled_t temp;
		InfiGLSyncEnabled( &temp );
		
		STATE_NAME->enabled.push( temp );
		
		InfiGLGetIntegerv( GL_ACTIVE_TEXTURE, &BUFFER_NAME );
		STATE_NAME->texframe.push( 0 );
		STATE_NAME->activetex.push( core::vec2ui( BUFFER_NAME - GL_TEXTURE0, 1 ) );
		STATE_NAME->textures.resize( GL.maximum.texture_units() );
		for ( uint32 i=0;i<GL.maximum.texture_units();++i )
			STATE_NAME->textures[i].push( 0 );
		
		GL_GET_ENABLED( GL_STENCIL_FUNC, stencilfront.func )
		GL_GET_ENABLED( GL_STENCIL_FUNC, stencilfront.func )
		GL_GET_ENABLED( GL_STENCIL_VALUE_MASK, stencilfront.mask )
		GL_GET_ENABLED( GL_STENCIL_FAIL, stencilfront.sfail )
		GL_GET_ENABLED( GL_STENCIL_PASS_DEPTH_FAIL, stencilfront.dpfail )
		GL_GET_ENABLED( GL_STENCIL_PASS_DEPTH_PASS, stencilfront.dppass )
		GL_GET_ENABLED( GL_STENCIL_WRITEMASK, stencilfront.wmask )
		GL_GET_ENABLED( GL_STENCIL_BACK_FUNC, stencilback.func )
		GL_GET_ENABLED( GL_STENCIL_BACK_REF, stencilback.ref )
		GL_GET_ENABLED( GL_STENCIL_BACK_VALUE_MASK, stencilback.mask )
		GL_GET_ENABLED( GL_STENCIL_BACK_FAIL, stencilback.sfail )
		GL_GET_ENABLED( GL_STENCIL_BACK_PASS_DEPTH_FAIL, stencilback.dpfail )
		GL_GET_ENABLED( GL_STENCIL_BACK_PASS_DEPTH_PASS, stencilback.dppass )
		GL_GET_ENABLED( GL_STENCIL_BACK_WRITEMASK, stencilback.wmask )
		GL_GET_ENABLED( GL_DRAW_FRAMEBUFFER_BINDING, framebuffersread )
		GL_GET_ENABLED( GL_READ_FRAMEBUFFER_BINDING, framebuffersdraw )
		GL_GET_ENABLED( GL_DRAW_BUFFER, drawbuffers )
		GL_GET_ENABLED( GL_ARRAY_BUFFER_BINDING, arraybuffers )
		GL_GET_ENABLED( GL_VERTEX_ARRAY_BINDING, vertexarrays )
		GL_GET_ENABLED( GL_ELEMENT_ARRAY_BUFFER_BINDING, indexbuffers )
		GL_GET_ENABLED( GL_CURRENT_PROGRAM, programs )
		GL_GET_ENABLED( GL_PIXEL_UNPACK_BUFFER_BINDING, packbuffers )
		GL_GET_ENABLED( GL_PIXEL_PACK_BUFFER_BINDING, unpackbuffers )
		GL_GET_ENABLED( GL_BLEND_SRC_ALPHA, srcalpha )
		GL_GET_ENABLED( GL_BLEND_SRC_RGB, srccolor )
		GL_GET_ENABLED( GL_BLEND_DST_ALPHA, dstalpha )
		GL_GET_ENABLED( GL_BLEND_DST_RGB, dstcolor )
		GL_GET_ENABLED( GL_BLEND_EQUATION_ALPHA, funcalpha )
		GL_GET_ENABLED( GL_BLEND_EQUATION_RGB, funccolor )
		
		ctrl->blendusage.push( 0 );
		
		core::vec4 fbuffer;
		InfiGLGetFloatv( GL_BLEND_COLOR, (GLfloat*) &(fbuffer) );
		ctrl->color.push( fbuffer );
	}
	
} }