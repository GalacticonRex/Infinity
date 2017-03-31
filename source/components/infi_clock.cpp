#include "components/infi_clock.hpp"

namespace Infinity {

	infi_clock_t::infi_clock_t() :
		_scale(1.0),
		_current_global(Time::Now()),
		_current_local(0.0) { ; }
	infi_clock_t::infi_clock_t(float64 scale) :
		_scale(scale),
		_current_global(Time::Now()),
		_current_local(0.0) { ; }

	infi_clock_t::operator float64() const {
		return localTime();
	}
	float64 infi_clock_t::localTime() const {
		return globalToLocal(Time::Now());
	}

	infi_clock_t& infi_clock_t::operator= ( float64 sc ) {
		this -> setScale(sc);
		return *this;
	}
	void infi_clock_t::setScale( float64 sc ) {
		Time::Point t = Time::Now();
		Time::Frame amt = t - _current_global.load();

		_current_local = (Time::Frame(_current_local.load()) + amt * _scale.load()).count();
		_current_global = t;

		_scale = sc;
	}

	infi_clock_t& infi_clock_t::operator+= ( float64 sc ) {
		addScale(sc);
		return *this;
	}
	infi_clock_t& infi_clock_t::operator-= ( float64 sc ) {
		addScale(-sc);
		return *this;
	}
	void infi_clock_t::addScale( float64 sc ) {
		setScale(_scale + sc);
	}

	float64 infi_clock_t::scale() const {
		return _scale;
	}

	float64 infi_clock_t::globalToLocal(Time::Point glob) const {
		return (Time::Frame(glob - _current_global.load()) * _scale.load()).count() + _current_local.load();
	}
	Time::Point infi_clock_t::localToGlobal(float64 loc) const {
		return _current_global.load() + (Time::Frame(loc - _current_local.load()) / _scale.load()); 
	}

	float64 infi_clock_t::lastTimeLocal() const {
		return _current_local;
	}
	Time::Point infi_clock_t::lastTimeGlobal() const {
		return _current_global;
	}

	void infi_clock_t::restart() {
		_current_global = Time::Now();
		_current_local = 0.0;
	}

}