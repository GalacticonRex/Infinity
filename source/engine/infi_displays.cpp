#include "depend/infi_sdl.hpp"
#include "base/error_log.hpp"
#include "engine/infi_displays.hpp"

namespace Infinity {

	infi_display_list_t::infi_display_list_t(infi_lib_init_t& libs) {
		uint32 sz = SDL_GetNumVideoDisplays();
		for ( uint32 i=0;i<sz;i++ ) {
			SDL_DisplayMode md;
			SDL_GetCurrentDisplayMode( i, &md );
			display disp;
			disp.format = md.format;
			disp.width = md.w;
			disp.height = md.h;
			disp.refresh_rate = md.refresh_rate;
			disp.driver = md.driverdata;
			_displays.push_back(disp);
		}
	}
	uint32 infi_display_list_t::count() const {
		return _displays.size();
	}
	infi_display_list_t::operator uint32 () const {
		return this -> count();
	}
	const infi_display_list_t::display& infi_display_list_t::operator[] ( uint32 i ) const {
		if ( i >= _displays.size() ) {
			//Error::define_scope __scope__("infi_infi_display_list_t.[]");
			Error::send<Error::Fatality::Method>(
				Error::Type::Index,
				"Cannot access display %d", i
			);
		}
		return _displays[i];
	}

}