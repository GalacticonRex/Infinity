#include "main/infi_displays.h"
#include "main/infi_error.h"
#include "core/infi_datablock.h"

#include "sdl/sdl.h"

namespace INFI {
	
	static core::data_t<infi_display_t> disp_list;
	
	void InfiLInitDisplays() {
		uint32 sz = SDL_GetNumVideoDisplays();
		disp_list.resize( sz );
		for ( uint32 i=0;i<sz;i++ ) {
			SDL_DisplayMode md;
			SDL_GetCurrentDisplayMode( i, &md );
			disp_list[i].format = md.format;
			disp_list[i].width = md.w;
			disp_list[i].height = md.h;
			disp_list[i].refresh_rate = md.refresh_rate;
			disp_list[i].driver = md.driverdata;
		}
	}
	
	#define SET_GL_ATTRIB( a,b,c ) \
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, a );\
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, b );\
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, c );
	
	void InfiLHighestCommonPixelFormat() {
		for ( uint32 i=0;i<disp_list.size();++i ) {
			uint32 format = SDL_PIXELLAYOUT(disp_list[i].format);
			switch( format ) {
				case SDL_PACKEDLAYOUT_332:
					SET_GL_ATTRIB( 3, 3, 2 );
					break;
				case SDL_PACKEDLAYOUT_4444:
					SET_GL_ATTRIB( 4, 4, 4 );
					break;
				case SDL_PACKEDLAYOUT_1555:
					SET_GL_ATTRIB( 5, 5, 5 );
					break;
				case SDL_PACKEDLAYOUT_5551:
					SET_GL_ATTRIB( 5, 5, 5 );
					break;
				case SDL_PACKEDLAYOUT_565:
					SET_GL_ATTRIB( 5, 6, 5 );
					break;
				case SDL_PACKEDLAYOUT_8888:
					SET_GL_ATTRIB( 8, 8, 8 );
					break;
				case SDL_PACKEDLAYOUT_2101010:
				case SDL_PACKEDLAYOUT_1010102:
					SET_GL_ATTRIB( 10, 10, 10 );
					break;
			}
		}
	}
	
	uint32 InfiNumDisplays() {
		return disp_list.size();
	}
	const infi_display_t& InfiGetDisplay( uint32 i ) {
		InfiPushFunction( "InfiGetDisplay" );
		if ( disp_list.size() <= i )
			InfiSendError( INFI_INDEX_ERROR, "no display %d", i );
		InfiPopFunction();
		return disp_list[i];
	}
	
}