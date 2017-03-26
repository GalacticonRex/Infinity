#include "components/infi_extension.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

infi_extension_t::~infi_extension_t() {

}

const char* infi_extension_t::getName() const {
	return _name;
}
uint32 infi_extension_t::dependencyCount() const {
	return _dependencies.size();
}
uint32 infi_extension_t::signalCount() const {
	return _signals.size();
}

void infi_extension_t::initialDelay(float64 delay) {
	_nextrun = delay;
}
void infi_extension_t::loops() {
	this -> needs(this);
}
void infi_extension_t::needs(infi_extension_t* ext) {
	std::unordered_map<infi_extension_t*, uint32>::iterator i = _signal_access.find(ext);
	if ( i == _signal_access.end() ) {
		_signal_access[ext] = _signals.size();
		_signals.push_back({ext,1,0});
		ext -> _dependencies.insert(this);
	} else {
		_signals[(*i).second]._need = 0;
	}
}
void infi_extension_t::needs(infi_extension_t& ext) {
	this -> needs( &ext );
}

void infi_extension_t::needs(infi_extension_t* ext, uint32 amount) {
	if ( ext == this && amount > 1 ) {
		//Error::define_scope __scope__("infi_extension_t.needs");
		Error::send<Error::Fatality::Method>(
			Error::Type::Value,
			"Extension cannot have a prerequisite of itself with a multiplicity greater than once, got %d",
			amount
		);
	}
	std::unordered_map<infi_extension_t*, uint32>::iterator i = _signal_access.find(ext);
	if ( i == _signal_access.end() ) {
		_signal_access[ext] = _signals.size();
		_signals.push_back({ext,amount,0});
		ext -> _dependencies.insert(this);
	} else {
		_signals[(*i).second]._need = amount;
		_signals[(*i).second]._have = 0;
	}
}
void infi_extension_t::needs(infi_extension_t& ext, uint32 amount) {
	this -> needs( &ext, amount );
}

void infi_extension_t::run(infi_controller_t& ctrl) {
	float64 now = ctrl.clock.localTime();
	float64 wnext = Update(ctrl, std::max( 0.0, now - _lastrun ));

	_lastrun = now;
	_nextrun = now + wnext;

	_good = 0;
	for ( uint32 i=0;i<_signals.size();i++ )
		_signals[i]._have = 0;

	std::set<infi_extension_t*>::iterator i=_dependencies.begin();
	for (;i!=_dependencies.end();i++)
		(*i)->__signal(this, ctrl);
}
void infi_extension_t::__signal(infi_extension_t* obj, infi_controller_t& ctrl) {
	std::unordered_map<infi_extension_t*, uint32>::iterator i = _signal_access.find(obj);
	if( i == _signal_access.end() ) {
		Error::send<Error::Fatality::Method>(
			Error::Type::Value,
			"Could not signal extension!"
		);
	}
	__counter_item__& item = _signals[(*i).second];
	if ( ++ item._have >= item._need ) {
		++ _good;
		if ( _good >= _signals.size() ) {
			ctrl.doWith(this, _nextrun - ctrl.clock.localTime());
		}
	}
}

}