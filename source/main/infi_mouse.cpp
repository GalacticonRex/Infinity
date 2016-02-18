#include "main/infi_mouse.h"
#include "main/infi_main.h"

namespace INFI {
	
	infi_mouse_t::infi_mouse_t(uint32 x) : infi_keyboard_t(x) {
		core::vec2ui v;
		SDL_GetMouseState( (int32*)&(v.x), (int32*)&(v.y) );
		position.push( v );
	}
	void infi_mouse_t::reset() {
		infi_keyboard_t::reset();
		
		postime.clear();
		wheeltime.clear();
		entertime.clear();
		
		position.clear();
		deltapos.clear();
		wheel.clear();
		
		startenter = endenter;
	}
	void infi_mouse_t::syncWith( infi_mouse_t* other ) {
		infi_keyboard_t::syncWith( other );
		position.push( other->position[0] );
	}
	
	void infi_mouse_t::push_enter( float64 t ) {
		if ( endenter )
			return;
		endenter = true;
		entertime.push( t );
	}
	void infi_mouse_t::push_leave( float64 t ) {
		if ( !endenter )
			return;
		endenter = false;
		entertime.push( t );
	}
	void infi_mouse_t::push_move( core::vec2ui pos, core::vec2i rel, float64 t ) {
		position.push( pos );
		deltapos.push( rel );
		postime.push( t - init_time );
	}
	void infi_mouse_t::push_wheel( int32 x, int32 y, float64 t ) {
		wheel.push( core::vec2i(x,y) );
		wheeltime.push( t - init_time );
	}
	
	
	void InfiLPosition( infi_mouse_t* mb, core::vec2i& v ) {
		v = mb->position[0];
	}
	bool InfiLGetDelta( infi_mouse_t* mb, core::vec2i& v ) {
		InfiPushFunction( "InfiLGetDelta" );
		if ( mb->position.size() <= 1 )
			return false;
		v = mb->position.get_base(0) - mb->position[0];
		InfiPopFunction();
		return ( Length(v) != 0 );
	}
	
	#define GET_MB( mb, func ) \
			InfiPushFunction( #func ); \
			infi_window_t* win = InfiCurrentWindow(); \
			if ( win == NULL ) \
				InfiSendError( INFI_BINDING_ERROR, "No window for mouse fetch" ); \
			infi_mouse_t* mb = win->mfront; \
			if ( mb == NULL ) \
				InfiSendError( INFI_BINDING_ERROR, "No mouse attached to window" ); \
			InfiPopFunction();
			
	core::vec2i InfiPosition() {
		GET_MB( mb, InfiPosition );
		core::vec2i ret;
		InfiLPosition( mb, ret );
		return ret;
	}
	core::vec2i InfiDelta() {
		GET_MB( mb, InfiDelta );
		core::vec2i ret;
		InfiLGetDelta( mb, ret );
		return ret;
	}

	uint32 InfiMouseButton( uint32 code ) {
		GET_MB( mb, InfiMouseButton )
		return mb->isset[code];
	}

	uint32 InfiMouseButtonPressed( uint32 code ) {
		GET_MB( mb, InfiMouseButtonPressed )
		return InfiLGetPressed( mb, code );
	}
	const INFI_code& InfiMouseButtonPressed( uint32 code, uint32 instance) {
		GET_MB( mb, InfiMouseButtonPressed )
		return InfiLGetPressed( mb, code, instance );
	}

	uint32 InfiMouseButtonReleased( uint32 code ) {
		GET_MB( mb, InfiMouseButtonReleased )
		return InfiLGetReleased( mb, code );
	}
	const INFI_code& InfiMouseButtonReleased( uint32 code, uint32 instance ) {
		GET_MB( mb, InfiMouseButtonReleased )
		return InfiLGetReleased( mb, code, instance );
	}
	
	#define MB_OPERATOR( scope, name ) \
			infi_mouse_access_t::scope::operator uint32() const { \
				return InfiMouseButton( name ); \
			} \
			uint32 infi_mouse_access_t::scope::pressed() const { \
				return InfiMouseButtonPressed( name ); \
			} \
			const INFI_code& infi_mouse_access_t::scope::pressed( uint32 inst ) const { \
				return InfiMouseButtonPressed( name, inst ); \
			} \
			uint32 infi_mouse_access_t::scope::released() const { \
				return InfiMouseButtonReleased( name ); \
			} \
			const INFI_code& infi_mouse_access_t::scope::released( uint32 inst ) const { \
				return InfiMouseButtonReleased( name, inst ); \
			}
	
	MB_OPERATOR( __left__, MOUSE_LEFT )
	MB_OPERATOR( __middle__, MOUSE_MIDDLE )
	MB_OPERATOR( __right__, MOUSE_RIGHT )
	
	// gets position of the mouse
	infi_mouse_access_t::operator core::vec2i () const {
		return this->position();
	}
	
	core::vec2i infi_mouse_access_t::position() const {
		return InfiPosition();
	}
	core::vec2i infi_mouse_access_t::delta() const {
		return InfiDelta();
	}
	
}