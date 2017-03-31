#include <iostream>
#include "threads/infi_event_clock.hpp"

namespace Infinity {

	infi_event_clock_t::infi_event_clock_t() :
		infi_clock_t(0), _continue(true) { ; }
	infi_event_clock_t::infi_event_clock_t(float64 sc) :
		infi_clock_t(sc), _continue(true) { ; }

	void infi_event_clock_t::reset() {
		std::lock_guard<std::mutex> lk(_lock);
		_continue = true;
	}
	void infi_event_clock_t::interrupt() {
		std::lock_guard<std::mutex> lk(_lock);
		_continue = false;
		_condition.notify_all();
	}

	float64 infi_event_clock_t::wait(std::condition_variable& cond, float64 f) {
		std::unique_lock<std::mutex> lk(_lock);

		float64 current_scale = this -> scale();
		Time::Point init = Time::Now();
		Time::Point termin = Time::Now() + Time::Frame(f / current_scale);

		if ( current_scale == 0.0 )
			cond.wait(lk);
		else if ( cond.wait_until(lk, termin) == std::cv_status::timeout )
			return 0.0;

		if ( _continue ) {
			Time::Point now = Time::Now();
			Time::Frame waited_for = (now - init) * current_scale;
			return f - waited_for.count();
		} else {
			return -1.0;
		}
	}
	float64 infi_event_clock_t::wait(float64 f) {
		return wait(_condition, f);
	}
	bool infi_event_clock_t::wait_for(float64 f) {
		while ( (f=wait(f)) > 0.0 );
		return (f == 0.0);
	}

}