#ifndef __INFI_TEXT_INPUT_H__
#define __INFI_TEXT_INPUT_H__

#include "text/infi_text.h"

namespace INFI {
namespace text {
	
	struct infi_text_input_t {
		core::string_t data;
		uint32 cursor, hooked;
		
		const core::string_t& text() const;
	};
	
	INFI_FUNCTION( infi_text_input_t*, InfiCreateTextInput, () );
	INFI_FUNCTION( void, InfiDestroyTextInput, ( infi_text_input_t* ) );
	INFI_FUNCTION( void, InfiResetTextInput, ( infi_text_input_t* ) );
	INFI_FUNCTION( void, InfiActivateTextInput, ( infi_text_input_t* ) );
	INFI_FUNCTION( void, InfiDeactivateTextInput, ( infi_text_input_t* ) );
	
} }

#endif//__INFI_TEXT_INPUT_H__