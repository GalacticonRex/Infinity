#ifndef __CORE_LINEAR_HPP__
#define __CORE_LINEAR_HPP__

#include "core/function/constant.hpp"

namespace core {

	template<typename _T,
			 typename _Rate = constant<_T>,
			 typename _Offset = constant<_T>,
			 typename _Conv = _T>
	struct linear : resolvable<_T> {
	private:
		const _Rate _rate;
		const _Offset _offset;

	public:
		linear(_Rate rate, _Offset offset) :
			_rate(rate),
			_offset(offset) { ; }

		_T operator()(_T input) const {
			return _Conv(_rate(input)) * input + _Conv(_offset(input));
		}
	};

}

#endif//__CORE_LINEAR_HPP__