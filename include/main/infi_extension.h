#ifndef __INFI_EXTENDER_H__
#define __INFI_EXTENDER_H__

#include "main/infi_types.h"
#include "main/infi_error.h"
#include "main/infi_structs.h"

namespace INFI {

struct infi_extension_t {
	
	const char* GetName() const { return __name; }
	
	virtual void Initialize( infi_window_t* )	{ }
	virtual void Detach( infi_window_t* ) 		{ }
	
	const infi_window_t& Parent() const { return *__parent; }
	infi_window_t& Parent() { return *__parent; }
	
	infi_extension_t() :
		__name( "New Extension" ),
		__parent( NULL ),
		__extnum(0) { ; }
	
	infi_extension_t( const char* n ) :
		__name( n ),
		__parent( NULL ),
		__extnum(0) { ; }
		
	virtual ~infi_extension_t() { 
		InfiPushFunction( "Extension.dtor" );
		if ( __parent != NULL )
			InfiSendError( INFI_BINDING_ERROR, 
						   "Cannot destroy extension %s still attached to Window", __name );
		InfiPopFunction();
	}
	
	const char* __name;
	infi_window_t* __parent;
	uint32 __extnum;
	
};

struct infi_extension_update_t : virtual infi_extension_t {
	virtual void Update( float64 ) = 0;
};
struct infi_extension_prerender_t : virtual infi_extension_t {
	virtual void PreRender( float64 ) = 0;
};
struct infi_extension_postrender_t : virtual infi_extension_t {
	virtual void PostRender( float64 ) = 0;
};

struct infi_extension_update_prerender_t :
	infi_extension_update_t,
	infi_extension_prerender_t { };
	
struct infi_extension_update_postrender_t :
	infi_extension_update_t,
	infi_extension_postrender_t { };
	
struct infi_extension_prerender_postrender_t :
	infi_extension_prerender_t,
	infi_extension_postrender_t { };

struct infi_full_extension_t :
	infi_extension_update_t,
	infi_extension_prerender_t,
	infi_extension_postrender_t { };
	
}

#endif//__INFI_EXTENDER_H__
