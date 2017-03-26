#ifndef __INFI_LIBRARY_INITIALIZATION_HPP__
#define __INFI_LIBRARY_INITIALIZATION_HPP__

#include "engine/infi_engine_defs.hpp"

namespace Infinity {

	struct infi_lib_init_t {
	private:
		static uint32 _lib_exists;
	public:
		infi_lib_init_t();
		~infi_lib_init_t();
	};

}

#endif//__INFI_LIBRARY_INITIALIZATION_HPP__