#include "main/infi_keyboard.h"
#include "main/infi_main.h"

namespace INFI {

	infi_keyboard_t::infi_keyboard_t( uint32 sz ) :
		init_time(0),
		ondown(sz), 
		onup(sz) { ; }
	
	void infi_keyboard_t::reset() {
		isdown.clear();
		isup.clear();
		tdown.resize( 0 );
		tup.resize( 0 );
	}
	void infi_keyboard_t::syncWith( infi_keyboard_t* other ) {
		isset = other->isset;
	}
	
	void infi_keyboard_t::push_down( uint16 kcode, uint16 mods, float64 t ) {
		INFI_code nc;
			nc.flags = ( INFI_KEY_MASK & mods );
			nc.onstack = tdown.size();
			nc.index = 0;
			
		if ( isdown[kcode] ) {
			uint32 ins = ondown.add( nc );
			uint32 id = kcode;
			
			while ( ondown[id].index != 0 )
				id = ondown[id].index;
			ondown[id].index = ins;
		} else {
			ondown[kcode] = nc;
			isdown.set( kcode );
		}
		
		tdown.add( t - init_time );
		isset.set( kcode );
	}
	void infi_keyboard_t::push_up( uint16 kcode, uint16 mods, float64 t ) {
		INFI_code nc;
			nc.flags = ( INFI_KEY_MASK & mods );
			nc.onstack = tdown.size();
			nc.index = 0;
		
		if ( isup[kcode] ) {
			uint32 ins = onup.add( nc );
			uint32 id = kcode;
			
			while ( onup[id].index != 0 )
				id = onup[id].index;
			onup[id].index = ins;
		} else {
			onup[kcode] = nc;
			isup.set(kcode);
		}
		
		tdown.add( t - init_time );
		isset.unset( kcode );
	}
	uint32 InfiLGetPressed( infi_keyboard_t* kb, uint32 code ) {
		uint32 ret = 0;
		if ( !kb->isdown[code] )
			return ret;
		while ( code != 0 ) {
			ret ++ ;
			code = kb->ondown[code].index;
		}
		return ret;
	}
	const INFI_code& InfiLGetPressed( infi_keyboard_t* kb, uint32 code, uint32 instance ) {
		uint32 i = 0;
		for ( ;i<instance&&(kb->ondown[code].index!=0);i++ )
			code = kb->ondown[code].index;
		instance = i;
		return kb->ondown[code];
	}

	uint32 InfiLGetReleased( infi_keyboard_t* kb, uint32 code ) {
		uint32 ret = 0;
		if ( !kb->isdown[code] )
			return ret;
		while ( code != 0 ) {
			ret ++ ;
			code = kb->onup[code].index;
		}
		return ret;
	}
	const INFI_code& InfiLGetReleased( infi_keyboard_t* kb, uint32 code, uint32& instance ) {
		uint32 i = 0;
		for ( ;i<instance&&(kb->onup[code].index!=0);i++ )
			code = kb->onup[code].index;
		instance = i;
		return kb->onup[code];
	}
	
	#define GET_KB( kb, func ) \
			InfiPushFunction( #func ); \
			infi_window_t* win = InfiCurrentWindow(); \
			if ( win == NULL ) \
				InfiSendError( INFI_BINDING_ERROR, "No window for key fetch" ); \
			infi_keyboard_t* kb = win->kfront; \
			if ( kb == NULL ) \
				InfiSendError( INFI_BINDING_ERROR, "No keyboard attached to window" ); \
			InfiPopFunction();
	
	uint32 InfiKey( uint32 code ) {
		GET_KB( kb, InfiKey )
		return kb->isset[code];
	}
	uint32 InfiKeyPressed( uint32 code ) {
		GET_KB( kb, InfiKeyPressed )
		return InfiLGetPressed( kb, code );
	}
	const INFI_code& InfiKeyPressed( uint32 code, uint32 instance ) {
		GET_KB( kb, InfiKeyPressed )
		return InfiLGetPressed( kb, code, instance );
	}
	uint32 InfiKeyReleased( uint32 code ) {
		GET_KB( kb, InfiKeyReleased )
		return InfiLGetReleased( kb, code );
	}
	const INFI_code& InfiKeyReleased( uint32 code, uint32 instance ) {
		GET_KB( kb, InfiKeyReleased )
		return InfiLGetReleased( kb, code, instance );
	}
	
}