#include "render/infi_canvas.h"
#include "render/infi_render.h"
#include "render/infi_gl_control.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_renderbuffer.h"
#include "render/infi_texture_multisample.h"
#include <set>

namespace INFI {
namespace render {
	
	static const uint32 INFI_LOCAL_ATTACH = 0x80000000;
	static const uint32 INFI_MIPMAP_ATTACH = 0x7FFFFFFF;
	
	static std::set<infi_canvas_t*> cache;

	void InfiLEmptyCanvasCache() {
		auto iter = cache.begin();
		for ( ;iter!=cache.end();++iter )
			InfiDestroyCanvas( *iter );
		cache.clear();
	}
	
	typedef std::map<infi_window_t*,infi_canvas_t::local_handle>::iterator HandleIter;
	typedef std::pair<infi_window_t*,infi_canvas_t::local_handle> HandlePair;
	
	const uint32 DEPTH_STENCIL_SLOT = 0,
				 DEPTH_SLOT = 1,
				 STENCIL_SLOT = 2,
				 COLOR_SLOT = 3;
	
	void infi_canvas_t::SyncObject( const infi_canvas_t::local_handle& temp, 
									uint32 index, 
									const infi_canvas_attachment_t& att ) {
		if ( att.tex == NULL )
			return;
		
		InfiPushFunction( "infi_canvas_t.sync" );
		
		InfiGLPushFramebuffer( temp.handle );
		
		GLenum attenum;
		bool using_together = false;
		
		switch( index ) {
			case DEPTH_STENCIL_SLOT:
				attenum = GL_DEPTH_STENCIL_ATTACHMENT;
				using_together = true;
				break;
			case DEPTH_SLOT:
				if ( using_together )
					InfiSendError( INFI_BINDING_ERROR,
								   "infi_canvas.handle.CreateNewHandle",
								   "Cannot bind a depth attachment with"
								   " a depth stencil attachment present" );
				attenum = GL_DEPTH_ATTACHMENT;
				break;
			case STENCIL_SLOT:
				if ( using_together )
					InfiSendError( INFI_BINDING_ERROR,
								   "infi_canvas.handle.CreateNewHandle",
								   "Cannot bind a stencil attachment with"
								   " a depth stencil attachment present" );
				attenum = GL_STENCIL_ATTACHMENT;
				break;
			default:
				attenum = GL_COLOR_ATTACHMENT0 + index - COLOR_SLOT;
		}
		
		infi_renderbuffer_t const* rbuf =
			dynamic_cast<infi_renderbuffer_t const*>( att.tex );
			
		if ( rbuf != NULL )
			InfiGLFramebufferRenderbuffer( attenum,
										   att.tex->handle );
		else
			InfiGLFramebufferTexture( attenum,
									  att.tex->handle,
									  att.data & INFI_MIPMAP_ATTACH );
		
		InfiGLPopFramebuffer();
		std::cerr << "CANVAS SYNCED TARGET " << index << std::endl;
		
		InfiPopFunction();
		
	}
	
	uint32 infi_canvas_t::CreateNewHandle( infi_window_t* win ) {
		InfiPushFunction( "infi_canvas_t.create_handle" );
		uint32 hnd;
		InfiGLGenFramebuffers( 1, &(hnd) );
		InfiPopFunction();
		return hnd;
	}
	
	typedef core::map_t<uint32,infi_canvas_attachment_t>::const_iterator CanvasIter;
	infi_texture_t* infi_canvas_t::color( uint32 i ) const {
		if ( i >= GL.maximum.color_attachments() ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "cannot access color attachment %d, hardware maximum number of attachments is %d",
						   i, GL.maximum.color_attachments() );
		}
		CanvasIter iter = objects.find( i + COLOR_SLOT );
		if ( iter == objects.end() ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "color attachment %d does not exist in this canvas", i );
		}
		infi_texture_t* ret = dynamic_cast<infi_texture_t*>( iter->second.tex );
		if ( ret == NULL ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "color attachment %d is not a texture (could be renderbuffer or multisampler)", i );
		}
		return ret;
	}
	infi_texture_t* infi_canvas_t::depth() const {
		CanvasIter iter = objects.find( DEPTH_SLOT );
		if ( iter == objects.end() ) {
			iter = objects.find( DEPTH_STENCIL_SLOT );
			if ( iter == objects.end() )
				InfiSendError( INFI_INDEX_ERROR,
							   "canvas has no depth attachment" );
		}
		infi_texture_t* ret = dynamic_cast<infi_texture_t*>( iter->second.tex );
		if ( ret == NULL ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "depth attachment is not a texture (could be renderbuffer or multisampler)" );
		}
		return ret;
	}
	infi_texture_t* infi_canvas_t::stencil() const {
		CanvasIter iter = objects.find( STENCIL_SLOT );
		if ( iter == objects.end() ) {
			iter = objects.find( DEPTH_STENCIL_SLOT );
			if ( iter == objects.end() )
				InfiSendError( INFI_INDEX_ERROR,
							   "canvas has no stencil attachment" );
		}
		infi_texture_t* ret = dynamic_cast<infi_texture_t*>( iter->second.tex );
		if ( ret == NULL ) {
			InfiSendError( INFI_INDEX_ERROR,
						   "stencil attachment is not a texture (could be renderbuffer or multisampler)" );
		}
		return ret;
	}
	
	infi_canvas_t* InfiCreate2DCanvas( core::vec2ui sz, INFI_channels chan ) {
		InfiPushFunction( "InfiCreate2DCanvas" );
		infi_canvas_t* ret = InfiCreateEmptyCanvas();
		infi_texture_t* ntex = InfiCreateTexture( sz, INFI_UBYTE, INFI_FLOAT, chan, false );
		
		infi_canvas_attachment_t temp = { ntex, INFI_LOCAL_ATTACH };
		ret->add( COLOR_SLOT, temp );
		InfiPopFunction();
		return ret;
	}
	infi_canvas_t* InfiCreate3DCanvas( core::vec2ui sz, INFI_channels chan ) {
		InfiPushFunction( "InfiCreate3DCanvas" );
		infi_canvas_t* ret = InfiCreateEmptyCanvas();
		infi_texture_t* ntex = InfiCreateTexture( sz, INFI_UBYTE, INFI_FLOAT, chan, false );
		infi_renderbuffer_t* nrbf = InfiCreateRenderbuffer( sz.x, sz.y, GL_DEPTH_COMPONENT16 );
		
		infi_canvas_attachment_t temp1 = { ntex, INFI_LOCAL_ATTACH };
		ret->add( COLOR_SLOT, temp1 );
		
		infi_canvas_attachment_t temp2 = { nrbf, INFI_LOCAL_ATTACH };
		ret->add( DEPTH_SLOT, temp2 );
		InfiPopFunction();
		return ret;
	}
	infi_canvas_t* InfiCreateEmptyCanvas() {
		infi_canvas_t* ret = new infi_canvas_t;
		cache.insert( ret );
		return ret;
	}
	infi_canvas_t* InfiCopyCanvas( const infi_canvas_t* cv ) {
		InfiPushFunction( "InfiCopyCanvas" );
		infi_canvas_t* ret = new infi_canvas_t( *cv );
		ret->dimensions = cv->dimensions;
		InfiPopFunction();
		return ret;
	}
	void InfiDestroyCanvas( infi_canvas_t* cv ) {
		cache.erase( cv );
		delete cv;
	}
	
	static void infi_clear_canvas_base( infi_window_t* win,
										infi_canvas_t* cv,
										float32 r, 
										float32 g, 
										float32 b, 
										float32 a, 
										uint32 buf ) {
		if ( cv == NULL || cv->handle() == 0 ) {
			if ( win != NULL ) {
				InfiGLClearColor( r, g, b, a );
				InfiGLClear( buf );
			} else
				InfiSendError( INFI_BINDING_ERROR, "no canvas currently bound to clear" );
		}
		InfiGLPushFramebuffer( cv->handle() );
		InfiGLClearColor( r, g, b, a );
		InfiGLClear( buf );
		InfiGLPopFramebuffer();
	}
	void InfiClearCanvas( infi_canvas_t* cv, uint32 buf ) {
		InfiPushFunction( "InfiClearCanvas" );
		infi_window_t* win = InfiRenderWindow();
		core::vec4 cc = win->clearcolor;
		infi_clear_canvas_base( win, cv, cc.r, cc.g, cc.b, cc.a, buf );
		InfiPopFunction();
	}
	void InfiClearCanvas( infi_canvas_t* cv, const core::vec4& color, uint32 buf ) {
		InfiPushFunction( "InfiClearCanvas" );
		infi_clear_canvas_base( InfiRenderWindow(),
								cv,
								color.r,
								color.g,
								color.b,
								color.a,
								buf );
		InfiPopFunction();
	}
	void InfiClearCanvas( infi_canvas_t* cv, float32 r, float32 g, float32 b, float32 a, uint32 buf ) {
		InfiPushFunction( "InfiClearCanvas" );
		infi_clear_canvas_base( InfiRenderWindow(), cv, r, g, b, a, buf );
		InfiPopFunction();
	}
	
	static void infi_find_smallest( infi_canvas_t* cv ) {
		core::vec2ui v( (uint32) -1, (uint32) -1 );
		core::map_t<uint32,infi_canvas_attachment_t>::iterator iter
			= cv->objects.begin();
		for ( ;iter!=cv->objects.end();++iter ) {
			infi_texture_base_t* tex = iter->second.tex;
			if ( tex == NULL )
				continue;
			const core::vec2ui& u = tex->dimensions;
			v.x = std::min( u.x, v.x );
			v.y = std::min( u.y, v.y );
		}
		cv->dimensions = v;
	}
	void InfiBindToCanvas( infi_canvas_t* cv, infi_texture_base_t* tex, uint32 mip, uint32 target ) {
		InfiPushFunction( "InfiBindToCanvas" );
		
		if ( cv == NULL || cv->handle() == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR, 
						   "no canvas to bind to" );
		if ( tex == NULL || tex->handle == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR, 
						   "invalid texture" );
		
		infi_canvas_attachment_t temp = { tex, mip };
		
		if ( tex->pxformat == GL_DEPTH_STENCIL )
			cv->add( DEPTH_STENCIL_SLOT, temp );
		else if ( tex->pxformat == GL_DEPTH_COMPONENT )
			cv->add( DEPTH_SLOT, temp );
		else if ( tex->pxformat == GL_STENCIL_INDEX )
			cv->add( STENCIL_SLOT, temp );
		else
			cv->add( target + COLOR_SLOT, temp );
		
		infi_find_smallest( cv );
		
		InfiPopFunction();
	}
	
	void InfiUnbindFromCanvas( infi_canvas_t* cv, uint32 target ) {
		InfiPushFunction( "InfiUnbindFromCanvas" );
		target += COLOR_SLOT;
		if ( cv == NULL || cv->handle() == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR,
						   "no canvas to unbind from" );
		if ( !cv->exists(target) )
			InfiSendError( INFI_BINDING_ERROR,
						   "no object bound to target %d", target );
		
		if ( cv->objects[target].data & INFI_LOCAL_ATTACH ) {
			infi_texture_base_t* tb = cv->objects[target].tex;
			infi_texture_t* t0 = dynamic_cast<infi_texture_t*>(tb);
			if ( t0 == NULL ) {
				infi_renderbuffer_t* t1 = dynamic_cast<infi_renderbuffer_t*>(tb);
				if ( t1 == NULL ) {
					infi_texture_multisample_t* t2 = dynamic_cast<infi_texture_multisample_t*>(tb);
					if ( t2 == NULL )
						InfiSendError( INFI_BINDING_ERROR,
									   "cannot destroy local unknown object is bound at this point" );
					else
						delete t2;
				} else
					InfiDestroyRenderbuffer( t1 );
			} else
				InfiDestroyTexture( t0 );
		}
		
		infi_canvas_attachment_t temp = { NULL, 0 };
		cv->add( target, temp );
		infi_find_smallest( cv );
		InfiPopFunction();
	}
	
	void InfiUnbindDepthFromCanvas( infi_canvas_t* cv ) {
		InfiPushFunction( "InfiUnbindDepthFromCanvas" );
		if ( cv == NULL || cv->handle() == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR,
						   "no canvas to unbind from" );
		if ( !cv->exists(DEPTH_SLOT) )
			InfiSendError( INFI_BINDING_ERROR,
						   "no object bound to depth" );
		
		infi_canvas_attachment_t temp = { NULL, 0 };
		cv->add( DEPTH_SLOT, temp );
		infi_find_smallest( cv );
		InfiPopFunction();
	}
	void InfiUnbindStencilFromCanvas( infi_canvas_t* cv ) {
		InfiPushFunction( "InfiUnbindStencilFromCanvas" );
		if ( cv == NULL || cv->handle() == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR,
						   "no canvas to unbind from" );
		if ( !cv->exists(STENCIL_SLOT) )
			InfiSendError( INFI_BINDING_ERROR,
						   "no object bound to depth" );
		
		infi_canvas_attachment_t temp = { NULL, 0 };
		cv->add( STENCIL_SLOT, temp );
		infi_find_smallest( cv );
		InfiPopFunction();
	}
	void InfiUnbindDepthStencilFromCanvas( infi_canvas_t* cv ) {
		InfiPushFunction( "InfiUnbindDepthStencilFromCanvas" );
		if ( cv == NULL || cv->handle() == 0 )
			InfiSendError( INFI_NULL_DEREF_ERROR,
						   "no canvas to unbind from" );
		if ( !cv->exists(DEPTH_STENCIL_SLOT) )
			InfiSendError( INFI_BINDING_ERROR,
						   "no object bound to depth" );
		
		infi_canvas_attachment_t temp = { NULL, 0 };
		cv->add( DEPTH_STENCIL_SLOT, temp );
		infi_find_smallest( cv );
		InfiPopFunction();
	}

} }