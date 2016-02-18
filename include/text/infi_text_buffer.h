#ifndef __INFI_TEXT_BUFFER_H__
#define __INFI_TEXT_BUFFER_H__

#include "text/infi_font.h"

namespace INFI {
namespace text {
	
	struct infi_text_buffer_t {
		infi_font_t* font;
		core::string_t textdata;
		core::vec2i pen;
		render::infi_texture_t* buffer;
	};
	
	INFI_FUNCTION( infi_text_buffer_t*, InfiCreateTextBuffer, ( infi_font_t* = NULL ) );
	INFI_FUNCTION( void, InfiDestroyTextBuffer, ( infi_text_buffer_t* ) );
	
	INFI_FUNCTION( void, InfiSetTextBuffer, ( infi_text_buffer_t*, const core::string_t& ) );
	INFI_FUNCTION( void, InfiAddTextBuffer, ( infi_text_buffer_t*, const core::string_t& ) );
	
	INFI_FUNCTION( render::infi_texture_t*, InfiGetImageTextBuffer, ( infi_text_buffer_t* ) );
	
} }

#endif//__INFI_TEXT_BUFFER_H__