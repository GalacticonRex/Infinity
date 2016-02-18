#include "render/infi_texture.h"
#include "text/infi_text_buffer.h"

namespace INFI {
namespace text {
	
	namespace {
		using namespace core;
		using namespace render;
	}
	
	infi_text_buffer_t* InfiCreateTextBuffer( infi_font_t* ft ) {
		infi_text_buffer_t* txt = new infi_text_buffer_t;
		txt->font = ft;
		txt->buffer = NULL;
		return txt;
	}
	void InfiDestroyTextBuffer( infi_text_buffer_t* txt ) {
		InfiDestroyTexture( txt->buffer );
		delete txt;
	}
	
	/*INFI_FUNCTION( void, InfiSetTextBuffer, ( infi_text_buffer_t*, const core::string_t& ) );
	INFI_FUNCTION( void, InfiAddTextBuffer, ( infi_text_buffer_t*, const core::string_t& ) );
	
	INFI_FUNCTION( render::infi_texture_t*, InfiGetImageTextBuffer( infi_text_buffer_t* ) );*/
	
} }