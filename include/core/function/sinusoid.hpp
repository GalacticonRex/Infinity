#ifndef __CORE_SINUSOID_HPP__
#define __CORE_SINUSOID_HPP__

#include "core/function/constant.hpp"

namespace core {

	template<typename _T,
			 typename _Wavelength = constant<_T>,
			 typename _Amplitude = constant<_T>,
			 typename _VerticalOffset = constant<_T>,
			 typename _HorizontalOffset = constant<_T>,
			 typename _Conv = _T>
	struct sinusoid : resolvable<_T> {
	private:
		const _Wavelength _wavelength;
		const _Amplitude _amplitude;
		const _VerticalOffset _vertical_offset;
		const _HorizontalOffset _horizontal_offset;

	public:
		sinusoid(_Wavelength w, _Amplitude a, _VerticalOffset v, _HorizontalOffset h) :
			_wavelength(w),
			_amplitude(a),
			_vertical_offset(v),
			_horizontal_offset(h) { ; }

		_T operator()(_T input) const {
			return _Conv(_amplitude(input)) * std::sin(input * _Conv(_wavelength(input)) + _Conv(_horizontal_offset(input))) + _Conv(_vertical_offset(input));
		}
	};

}

#endif//__CORE_SINUSOID_HPP__