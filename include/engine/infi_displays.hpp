#ifndef __INFI_DISPLAY_LISTS_HPP__
#define __INFI_DISPLAY_LISTS_HPP__

#include <vector>
#include "base/structure.hpp"
#include "engine/infi_engine_defs.hpp"

namespace Infinity {

	struct infi_display_list_t : does_not_copy {
	public:
		struct display {
			uint32 format;
			int32 width;
			int32 height;
			int32 refresh_rate;
			void* driver;
		};

		infi_display_list_t(infi_lib_init_t&);
		uint32 count() const;
		operator uint32 () const;
		const display& operator[] ( uint32 ) const;

	private:
		std::vector<display> _displays;
	};
}

#endif//__INFI_DISPLAY_LISTS_HPP__