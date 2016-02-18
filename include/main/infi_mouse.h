#ifndef __INFI_MOUSE_INPUT_H__
#define __INFI_MOUSE_INPUT_H__

#include "main/infi_keyboard.h"
#include "main/infi_structs.h"

#define INFI_MOUSE_BUTTON_CAP 16

#define INFI_MOUSE_LEFT   1
#define INFI_MOUSE_MIDDLE 2
#define INFI_MOUSE_RIGHT  3

namespace INFI {

struct infi_mouse_t : infi_keyboard_t {
	
	core::stack_t<core::vec2i> position;
	core::stack_t<core::vec2i> deltapos;
	core::stack_t<core::vec2i> wheel;
	bool startenter, endenter;
	
	core::stack_t<float64> postime;
	core::stack_t<float64> wheeltime;
	core::stack_t<float64> entertime;
	
	infi_mouse_t(uint32 x);
	
	void reset();
	void syncWith( infi_mouse_t* other );
	
	void push_enter( float64 t );
	void push_leave( float64 t );
	void push_move( core::vec2ui pos, core::vec2i rel, float64 t );
	void push_wheel( int32 x, int32 y, float64 t );
	
};

#define MOUSE_LEFT 		1
#define MOUSE_MIDDLE 	2
#define MOUSE_RIGHT 	3

struct infi_mouse_access_t {
	struct __left__ {
		operator uint32() const;
		uint32 pressed() const;
		const INFI_code& pressed( uint32 ) const;
		uint32 released() const;
		const INFI_code& released( uint32 ) const;
	} left;
	struct __right__ {
		operator uint32() const;
		uint32 pressed() const;
		const INFI_code& pressed( uint32 ) const;
		uint32 released() const;
		const INFI_code& released( uint32 ) const;
	} right;
	struct __middle__ {
		operator uint32() const;
		uint32 pressed() const;
		const INFI_code& pressed( uint32 ) const;
		uint32 released() const;
		const INFI_code& released( uint32 ) const;
	} middle;
	
	// gets position of the mouse
	operator core::vec2i () const;
	
	core::vec2i position() const;
	core::vec2i delta() const;
};

const INFI_EXPORT infi_mouse_access_t Mouse;

// low level 
INFI_FUNCTION( void, InfiLPosition, ( infi_mouse_t*, core::vec2i& v ) );
INFI_FUNCTION( bool, InfiLGetDelta, ( infi_mouse_t*, core::vec2i& v ) );

// use these
INFI_FUNCTION( core::vec2i, InfiPosition, () );
INFI_FUNCTION( core::vec2i, InfiDelta, () );

INFI_FUNCTION( uint32, InfiMouseButton, (uint32) );

INFI_FUNCTION( uint32, InfiMouseButtonPressed, (uint32) );
INFI_FUNCTION( const INFI_code&, InfiMouseButtonPressed, (uint32,uint32) );

INFI_FUNCTION( uint32, InfiMouseButtonReleased, (uint32) );
INFI_FUNCTION( const INFI_code&, InfiMouseButtonReleased, (uint32,uint32) );

}

#endif//__INFI_MOUSE_INPUT_H__

