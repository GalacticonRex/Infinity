#ifndef __CORE_SUM_HPP__
#define __CORE_SUM_HPP__

#include "core/function/constant.hpp"

namespace core {

	template<typename _T,
			 typename _First = constant<_T>,
			 typename _Second = constant<_T>,
			 typename _Conv = _T>
	struct sum : resolvable<_T> {
	private:
		const _First _first;
		const _Second _second;
	public:
		sum(_First f, _Second s) :
			_first(f), _second(s) { ; }

		_T operator()(_T input) const {
			return _Conv(_first(input)) + _Conv(_second(input));
		}
	};

}

#endif//__CORE_SUM_HPP__