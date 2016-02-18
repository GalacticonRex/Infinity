#include "text/infi_text_input.h"
#include "main/infi_main.h"
#include "main/infi_keyboard.h"

namespace INFI {
namespace text {
	
	namespace {
		using namespace std;
		using namespace core;
	}
	
	/*static void __input_hook_func( void* data, const SDL_Event& ev ) {
		infi_text_input_t* input = (infi_text_input_t*) data;
		if ( ev.type == SDL_TEXTINPUT ) {
			uint32 sz1 = input->data.size();
			input->data = input->data.front( input->cursor ) + 
							ev.text.text + 
							input->data.back( input->data.size() - input->cursor );
			input->cursor += input->data.size() - sz1;
		} else if ( ev.type == SDL_KEYDOWN ) {
			if ( ev.key.keysym.scancode == INFI_KEYCODE_BACKSPACE ) {
				input->data = input->data.front( input->data.last() );
				input->cursor = ( input->cursor == 0 ) ? 0 : input->cursor - 1;
			}
		}
	}
	
	const string_t& infi_text_input_t::text() const {
		return data;
	}
	
	infi_text_input_t* InfiCreateTextInput() {
		infi_text_input_t* tmp = ALLOC( new infi_text_input_t(), 1, "InfiCreateTextInput" );
		tmp->cursor = 0;
		tmp->hooked = (uint32) -1;
		return tmp;
	}
	void InfiDestroyTextInput( infi_text_input_t* tmp ) {
		DEALLOC( tmp, "InfiDestroyTextInput" );
	}
	
	void InfiResetTextInput( infi_text_input_t* tmp ) {
		tmp->data.clear();
		tmp->cursor = 0;
	}
	void InfiActivateTextInput( infi_text_input_t* tmp ) {
		if ( tmp->hooked != (uint32)-1 ) return;
		tmp->hooked = InfiHookControl( __input_hook_func, (void*) tmp );
	}
	void InfiDeactivateTextInput( infi_text_input_t* tmp ) {
		if ( tmp->hooked == (uint32)-1 ) return;
		InfiUnHookControl( tmp->hooked );
		tmp->hooked = (uint32) -1;
	}*/
	
} }