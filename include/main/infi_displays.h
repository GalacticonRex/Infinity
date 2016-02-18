#ifndef __INFI_DISPLAYS_H__
#define __INFI_DISPLAYS_H__

#include "main/infi_types.h"
#include "main/infi_export.h"

namespace INFI {
	
	struct infi_display_t {
		uint32 format;
		int32 width;
		int32 height;
		int32 refresh_rate;
		void* driver;
	};
	
	INFI_FUNCTION( void, InfiLInitDisplays, () );
	INFI_FUNCTION( void, InfiLHighestCommonPixelFormat, () );
	
	INFI_FUNCTION( uint32, InfiNumDisplays, () );
	INFI_FUNCTION( const infi_display_t&, InfiGetDisplay, ( uint32 i=0 ) );
	
}

#endif//__INFI_DISPLAYS_H__