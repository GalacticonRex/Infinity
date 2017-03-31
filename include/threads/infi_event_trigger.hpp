#ifndef __INFI_TYPED_TRIGGER_HPP__
#define __INFI_TYPED_TRIGGER_HPP__

#include "threads/infi_trigger.hpp"

namespace Infinity {

	template<typename _T>
	struct infi_event_trigger_t : private infi_trigger_t {
	private:
		std::function<void(bool,_T&)> _functionality;
		void Triggered(infi_trigger_t* source, bool signal, void* data) {
			if (_functionality) 
				_functionality(signal, *((_T*)data));
		}

		infi_event_trigger_t& __combine_and(infi_event_trigger_t& ev) {
			if( ev.__is_and() ) {
				ev.__add_input(this);
				return ev;
			} else {
				infi_event_trigger_t* gen = new infi_event_trigger_t();
				gen->_data.hidden = true;
				gen->__set_and();
				this->add(*gen);
				ev.add(*gen);
				return *gen;
			}
		}
		infi_event_trigger_t& __combine_or(infi_event_trigger_t& ev) {
			if( ev.__is_or() ) {
				ev.__add_input(this);
				return ev;
			} else {
				infi_event_trigger_t* gen = new infi_event_trigger_t();
				gen->_data.hidden = true;
				gen->__set_or();
				this->add(*gen);
				ev.add(*gen);
				return *gen;
			}
		}
		infi_event_trigger_t& __combine_not() {
			infi_event_trigger_t* ev = new infi_event_trigger_t();
			ev->_data.hidden = true;
			ev->_data.direction = _data.direction;
			ev->_data.true_on_zero = !_data.true_on_zero;
			this->add(*ev);
			return *ev;
		}

	public:
		infi_event_trigger_t() { ; }
		infi_event_trigger_t( std::function<void(bool,_T&)> f ) :
			infi_trigger_t(), _functionality(f) { ; }
		infi_event_trigger_t( bool init, std::function<void(bool,_T&)> f ) :
			infi_trigger_t(init), _functionality(f) { ; }

		infi_event_trigger_t& operator& (infi_event_trigger_t& ev) {
			return __combine_and(ev);
		}
		infi_event_trigger_t& operator| (infi_event_trigger_t& ev) {
			return __combine_or(ev);
		}
		infi_event_trigger_t& operator! () {
			return __combine_not();
		}

		void operator() (_T& data, bool signal = true) {
			run(signal, (void*)&data);
		}
		void propagate(_T& data, bool signal = true) {
			run(signal, (void*)&data);
		}
		operator bool () const {
			return isSignalled();
		}

		// receive
		infi_event_trigger_t& when( infi_event_trigger_t& ev) {
			ev.add(*this);
			return *this;
		}
		infi_event_trigger_t& disable( infi_event_trigger_t& ev ) {
			ev.remove(*this);
			return *this;
		}
	};

	template<>
	struct infi_event_trigger_t<void> : private infi_trigger_t {
	private:
		std::function<void(bool)> _functionality;
		void Triggered(infi_trigger_t* source, bool signal, void* data) {
			if (_functionality) 
				_functionality(signal);
		}

		infi_event_trigger_t& __combine_and(infi_event_trigger_t& ev) {
			if( ev.__is_and() ) {
				ev.__add_input(this);
				return ev;
			} else {
				infi_event_trigger_t* gen = new infi_event_trigger_t();
				gen->_data.hidden = true;
				gen->__set_and();
				this->add(*gen);
				ev.add(*gen);
				return *gen;
			}
		}
		infi_event_trigger_t& __combine_or(infi_event_trigger_t& ev) {
			if( ev.__is_or() ) {
				ev.__add_input(this);
				return ev;
			} else {
				infi_event_trigger_t* gen = new infi_event_trigger_t();
				gen->_data.hidden = true;
				gen->__set_or();
				this->add(*gen);
				ev.add(*gen);
				return *gen;
			}
		}
		infi_event_trigger_t& __combine_not() {
			infi_event_trigger_t* ev = new infi_event_trigger_t();
			ev->_data.hidden = true;
			ev->_data.direction = _data.direction;
			ev->_data.true_on_zero = !_data.true_on_zero;
			this->add(*ev);
			return *ev;
		}

	public:
		infi_event_trigger_t() { ; }
		infi_event_trigger_t( std::function<void(bool)> f ) :
			infi_trigger_t(), _functionality(f) { ; }
		infi_event_trigger_t( bool init, std::function<void(bool)> f ) :
			infi_trigger_t(init), _functionality(f) { ; }

		infi_event_trigger_t& operator& (infi_event_trigger_t& ev) {
			return __combine_and(ev);
		}
		infi_event_trigger_t& operator| (infi_event_trigger_t& ev) {
			return __combine_or(ev);
		}
		infi_event_trigger_t& operator! () {
			return __combine_not();
		}

		void operator() (bool signal = true) {
			run(signal, NULL);
		}
		void propagate(bool signal = true) {
			run(signal, NULL);
		}
		operator bool () const {
			return isSignalled();
		}

		// receive
		infi_event_trigger_t& when( infi_event_trigger_t& ev) {
			ev.add(*this);
			return *this;
		}
		infi_event_trigger_t& disable( infi_event_trigger_t& ev ) {
			ev.remove(*this);
			return *this;
		}
	};
}

#endif//__INFI_TYPED_TRIGGER_HPP__