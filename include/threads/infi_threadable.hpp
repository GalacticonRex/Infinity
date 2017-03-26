#ifndef __INFI_THREADABLE_HPP__
#define __INFI_THREADABLE_HPP__

#include "threads/infi_thread_defs.hpp"

namespace Infinity {

	struct infi_threadable_t {
		enum Operation {
			Serial,
			Parallel
		};

		template<Operation _Eval>
		struct DEFINE_EXPORT function_return { typedef infi_async_t type; };
	};

	template<>
	struct DEFINE_EXPORT infi_threadable_t::function_return<infi_threadable_t::Serial> { typedef void type; };

}

#endif//__INFI_THREADABLE_HPP__