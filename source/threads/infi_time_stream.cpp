#include <iostream>
#include "threads/infi_time_stream.hpp"

namespace Infinity {

	infi_time_stream_t::infi_time_stream_t() :
		_continue(true),
		_scale(1.0),
		_current_global(Time::Now()),
		_current_local(0.0) { 
	}
	infi_time_stream_t::infi_time_stream_t(float64 sc) :
		_continue(true),
		_scale(sc),
		_current_global(Time::Now()),
		_current_local(0.0) { ; }

	infi_time_stream_t& infi_time_stream_t::operator= ( float64 sc ) {
		std::lock_guard<std::mutex> lk(_lock);
		
		Time::Point t = Time::Now();
		Time::Frame amt = t - _current_global.load();
		_current_local = (Time::Frame(_current_local.load()) + amt * _scale.load()).count();
		_current_global = t;

		_scale = sc;
		
		(*this)(true, this); // propagate message
		_condition.notify_all();
		
		return *this;
	}
	float64 infi_time_stream_t::scale() const {
		return _scale;
	}
	infi_time_stream_t::operator float64() const {
		return _scale;
	}

	float64 infi_time_stream_t::localTime() const {
		return globalToLocal(Time::Now());
	}
	float64 infi_time_stream_t::globalToLocal( Time::Point glob ) const {
		return (Time::Frame(glob - _current_global.load()) * _scale.load()).count() + _current_local.load();
	}
	Time::Point infi_time_stream_t::localToGlobal( float64 loc ) const {
		return _current_global.load() + (Time::Frame(loc - _current_local.load()) / _scale.load()); 
	}

	float64 infi_time_stream_t::lastTimeLocal() const {
		return _current_local;
	}
	Time::Point infi_time_stream_t::lastTimeGlobal() const {
		return _current_global;
	}

	void infi_time_stream_t::restart() {
		std::lock_guard<std::mutex> lk(_lock);
		_current_global = Time::Now();
		_current_local = 0.0;
	}

	void infi_time_stream_t::reset() {
		std::lock_guard<std::mutex> lk(_lock);
		_continue = true;
	}
	void infi_time_stream_t::interrupt() {
		std::lock_guard<std::mutex> lk(_lock);
		_continue = false;
		_condition.notify_all();
	}

	float64 infi_time_stream_t::wait(std::condition_variable& cond, float64 f) {
		std::unique_lock<std::mutex> lk(_lock);

		float64 current_scale = _scale;
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
	float64 infi_time_stream_t::wait(float64 f) {
		return wait(_condition, f);
	}
	bool infi_time_stream_t::wait_for(float64 f) {
		while ( (f=wait(f)) > 0.0 );
		return (f == 0.0);
	}

}