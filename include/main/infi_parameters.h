#ifndef __INFI_PARAMETERS_H__
#define __INFI_PARAMETERS_H__

#include "core/infi_array.h"
#include "core/infi_string.h"

namespace INFI {
	
	struct INFI_EXPORT infi_parameters_t {
		void* userdata;
		core::array_t<core::string_t> args;
	};
	
}

#endif//__INFI_PARAMETERS_H__
