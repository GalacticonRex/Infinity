#ifndef __INFI_CANVAS_H__
#define __INFI_CANVAS_H__

#include "core/infi_vector.h"
#include "core/infi_methods.h"
#include "render/infi_texture.h"
#include "render/infi_object_dump.h"
#include "render/infi_multi_context.h"
#include "render/infi_view_transform.h"
#include "main/infi_window.h"
#include "main/infi_main.h"

namespace INFI {
namespace render {
	
	INFI_FUNCTION( void, InfiLEmptyCanvasCache, () );
	
	struct infi_canvas_attachment_t {
		infi_texture_base_t* tex;
		uint32 data;
	};
	
	typedef infi_multi_context_t<infi_window_t*,
								uint32,
								infi_canvas_attachment_t,
								InfiRenderWindow,
								infi_dump_framebuffer>
			ContextSwitch;
			
	typedef ContextSwitch::local_handle ContextHandle;
	
	struct infi_canvas_t : ContextSwitch, infi_view_transform_t {
		core::vec2ui dimensions;
		
		uint32 CreateNewHandle( infi_window_t* win );
		void SyncObject( const local_handle&, uint32, const infi_canvas_attachment_t& );
		
		infi_texture_t* color( uint32 ) const;
		infi_texture_t* depth() const;
		infi_texture_t* stencil() const;
		
		operator core::mat4() const {
			return core::OrthoMat4( core::vec2(), dimensions );
		}
	};
	
	INFI_FUNCTION( infi_canvas_t*, InfiCreate2DCanvas, ( core::vec2ui, INFI_channels=INFI_RGBA ) );
	INFI_FUNCTION( infi_canvas_t*, InfiCreate3DCanvas, ( core::vec2ui, INFI_channels=INFI_RGBA ) );
	INFI_FUNCTION( infi_canvas_t*, InfiCreateEmptyCanvas, () );
	INFI_FUNCTION( infi_canvas_t*, InfiCopyCanvas, ( const infi_canvas_t* ) );
	INFI_FUNCTION( void, InfiDestroyCanvas, ( infi_canvas_t* ) );
	
	INFI_FUNCTION( bool, InfiCanvasIsTexture, () );
	INFI_FUNCTION( infi_canvas_t*, InfiCurrentCanvas, () );
	INFI_FUNCTION( infi_texture_t*, InfiCurrentTextureCanvas, () );
	INFI_FUNCTION( void, InfiPushCanvas, ( infi_canvas_t* ) );
	INFI_FUNCTION( void, InfiPushCanvas, ( infi_texture_t* ) );
	INFI_FUNCTION( void, InfiPopCanvas, () );
	
	// apply to specified draw buffer
	INFI_FUNCTION( void, InfiClearCanvas, ( infi_canvas_t*, uint32 = GL_COLOR_BUFFER_BIT ) );
	INFI_FUNCTION( void, InfiClearCanvas, ( infi_canvas_t*, const core::vec4& color, uint32 = GL_COLOR_BUFFER_BIT ) );
	INFI_FUNCTION( void, InfiClearCanvas, ( infi_canvas_t*, float32, float32, float32, float32 = 1, uint32 = GL_COLOR_BUFFER_BIT ) );
	
	INFI_FUNCTION( void, InfiBindToCanvas, ( infi_canvas_t*, infi_texture_base_t*, uint32 = 0, uint32 = 0 ) );
	
	INFI_FUNCTION( void, InfiUnbindFromCanvas, ( infi_canvas_t*, uint32 = 0 ) );
	
	INFI_FUNCTION( void, InfiUnbindDepthFromCanvas, ( infi_canvas_t* ) );
	INFI_FUNCTION( void, InfiUnbindStencilFromCanvas, ( infi_canvas_t* ) );
	INFI_FUNCTION( void, InfiUnbindDepthStencilFromCanvas, ( infi_canvas_t* ) ); 
	
} }

#endif//__INFI_CANVAS_H__