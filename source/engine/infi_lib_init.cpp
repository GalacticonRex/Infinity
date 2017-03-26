#include "base/error_log.hpp"
#include "depend/infi_sdl.hpp"
#include "engine/infi_lib_init.hpp"

namespace Infinity {

	uint32 infi_lib_init_t::_lib_exists = 0;

	infi_lib_init_t::infi_lib_init_t() {
		if ( _lib_exists == 0 ) {
			if ( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) {
				//Error::define_scope __scope__("infi_init_lib_t.ctor()");
				Error::send<Error::Fatality::Fatal>(
					Error::Type::Library,
					"SDL could not initialize!"
				);
			}
		}
		++ _lib_exists;
	}
	infi_lib_init_t::~infi_lib_init_t() {
		if ( -- _lib_exists == 0 )
			SDL_Quit();
	}

}