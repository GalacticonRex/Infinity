#ifndef __INFI_CLOCK_HPP__
#define __INFI_CLOCK_HPP__

#include <atomic>

#include "components/infi_component_defs.hpp"
#include "base/types.hpp"
#include "base/time.hpp"

namespace Infinity {

	struct infi_clock_t {
	private:
		std::atomic<float64> _scale;
		std::atomic<Time::Point> _current_global;
		std::atomic<float64> _current_local;

	public:
		infi_clock_t();
		infi_clock_t(float64 scale);

		operator float64() const;

		float64 localTime() const;
		float64 scale() const;

		infi_clock_t& operator= ( float64 );
		void setScale(float64);

		infi_clock_t& operator+= ( float64 );
		infi_clock_t& operator-= ( float64 );
		void addScale(float64);

		float64 globalToLocal(Time::Point) const;
		Time::Point localToGlobal(float64) const;

		float64 lastTimeLocal() const;
		Time::Point lastTimeGlobal() const;

		void restart();
	};

}

#endif//__INFI_CLOCK_HPP__