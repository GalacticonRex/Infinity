#ifndef __CORE_DIFFERENCE_HPP__
#define __CORE_DIFFERENCE_HPP__

#include "core/function/constant.hpp"

namespace core {

	template<typename _T,
			 typename _First = constant<_T>,
			 typename _Second = constant<_T>,
			 typename _Conv = _T>
	struct difference : resolvable<_T> {
	private:
		const _First _first;
		const _Second _second;
	public:
		difference(_First f, _Second s) :
			_first(f), _second(s) { ; }

		_T operator()(_T input) const {
			return _Conv(_first(input)) - _Conv(_second(input));
		}
	};

}

#endif//__CORE_DIFFERENCE_HPP__