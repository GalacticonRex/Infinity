#ifndef __CORE_RESOLVABLE_HPP__
#define __CORE_RESOLVABLE_HPP__

namespace core {

	template<typename _T>
	struct resolvable {
		virtual _T operator()(_T) const = 0;
	};

}

#endif//__INFI_RESOLVABLE_HPP__