#include "main/infi_window.h"
#include "main/infi_renderable.h"

namespace INFI {
	
void InfiInitWindowSpec( infi_window_spec_t& spec ) {
	spec.name.clear();
	spec.dimensions = core::vec2ui(640,480);
	spec.position = INFI_WINDOW_CENTERED;
	spec.anchor = core::vec2();
	spec.relposition = core::vec2( INFINITY, INFINITY );
	spec.hlimits = core::vec2i( INT_MAX, 0 );
	spec.vlimits = core::vec2i( INT_MAX, 0 );
	spec.frame_rate = 60;
	spec.fullscreen = false;
	spec.hidden = false;
	spec.borderless = false;
	spec.resizable = false;
	spec.builtin_ui = false;
}

infi_window_t* InfiCreateWindow( const core::vec2ui& dim, uint32 fps ) {
	infi_window_spec_t spec;
	InfiInitWindowSpec( spec );
	
	spec.dimensions = dim;
	spec.frame_rate = fps;
	
	return InfiCreateWindow( spec ); 
}
infi_window_t* InfiCreateWindow( const core::string_t& name, const core::vec2ui& dim, uint32 fps ) {
	infi_window_spec_t spec;
	InfiInitWindowSpec( spec );
	
	spec.name = name;
	spec.dimensions = dim;
	spec.frame_rate = fps;
	
	return InfiCreateWindow( spec );
}

void InfiDestroyWindow( infi_window_t* win ) {
	InfiPushFunction( "InfiDestroyWindow" );
	if ( win == NULL )
		InfiSendError( INFI_NULL_DEREF_ERROR, "referencing null window" );
		
	win->flags |= INFI_WINDOW_TERMINATE;
	InfiPopFunction();
}

infi_extension_t* InfiExtendWindow( infi_window_t* win, infi_extension_t* ext ) {
	InfiPushFunction( "InfiExtendWindow" );
	
	if ( win == NULL )
		InfiSendError( INFI_NULL_DEREF_ERROR, "referencing null window" );
	
	if ( ext == NULL )
		InfiSendError( INFI_NULL_DEREF_ERROR, "referencing null extension" );
	
	infi_extension_update_t* update 	= dynamic_cast<infi_extension_update_t*>( ext );
	infi_extension_prerender_t* pre 	= dynamic_cast<infi_extension_prerender_t*>( ext );
	infi_extension_postrender_t* post 	= dynamic_cast<infi_extension_postrender_t*>( ext );
	infi_renderable_t* rend				= dynamic_cast<infi_renderable_t*>( ext );
	
	ext->__parent = win;
	ext->__extnum = win->extcount;
	
	win->extmain.add( ext );
	
	if ( update ) win->update.add( update );
	if ( pre ) win->prerender.add( pre );
	if ( post ) win->postrender.add( post );
	if ( rend ) win->renderable.add( rend );
	
	ext->Initialize( win );
	
	InfiPopFunction();
	
	return ext;
	
}

}