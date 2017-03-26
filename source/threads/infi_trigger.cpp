#include <iostream>
#include "threads/infi_trigger.hpp"

namespace Infinity {

	bool infi_trigger_t::__invalidated() const {
		return ( _data.hidden && (_output.empty() || _input.empty()));
	}
	void infi_trigger_t::__generate_hash() {
		if ( _input.empty() ) {
			infi_trigger_t* temp = this;
			_hash_value = std::hash<infi_trigger_t*>()(temp);
		} else {
			iterator iter=_input.begin();
			_hash_value = 0;
			for(;iter!=_input.end();iter++)
				_hash_value ^= (*iter)->gethash();
		}
	}

	void infi_trigger_t::__add_input(infi_trigger_t* ev) {
		if ( _data.direction == -1 )
			if( !ev->_data.signalled )
				_data.count ++ ;
		_input.insert(ev);
		__generate_hash();
	}
	void infi_trigger_t::__add_output(infi_trigger_t* ev) {
		_output.insert(ev);
	}
	bool infi_trigger_t::__remove_input(infi_trigger_t* ev) {
		iterator iter = _input.find(ev);
		if ( iter != _input.end() ) {
			_input.erase(iter);
			if ( __invalidated() )
				delete this;
			return true;
		}
		return false;
	}
	bool infi_trigger_t::__remove_output(infi_trigger_t* ev) {
		iterator iter = _output.find(ev);
		if ( iter != _output.end() ) {
			_output.erase(ev);
			if ( __invalidated() )
				delete this;
			return true;
		}
		return false;
	}

	void infi_trigger_t::__handle_input(infi_trigger_t* ev, bool b, void* d) {
		bool sig;
		
		if ( _data.direction == 0 ) {
			sig = b;
		} else {
			_data.count += (b)?(_data.direction):(-_data.direction);
			sig = (_data.true_on_zero)?(_data.count==0):(_data.count!=0);
		}

		if( _data.signalled != sig ) {
			_data.signalled = sig;
			this->Triggered(ev, _data.signalled, d);
			iterator i = _output.begin();
			for (;i!=_output.end();i++)
				(*i)->__handle_input(this, _data.signalled, d);
		}
	}

	void infi_trigger_t::__set_and() {
		_data.true_on_zero = true;
		_data.direction = -1;
	}
	void infi_trigger_t::__set_or() {
		_data.true_on_zero = false;
		_data.direction = 1;
	}
	void infi_trigger_t::__set_nand() {
		_data.true_on_zero = false;
		_data.direction = -1;
	}
	void infi_trigger_t::__set_nor() {
		_data.true_on_zero = true;
		_data.direction = 1;
	}

	bool infi_trigger_t::__is_and() const {
		return (_data.true_on_zero && _data.direction == -1);
	}
	bool infi_trigger_t::__is_or() const {
		return (!_data.true_on_zero && _data.direction == 1);
	}
	bool infi_trigger_t::__is_nand() const {
		return (!_data.true_on_zero && _data.direction == -1);
	}
	bool infi_trigger_t::__is_nor() const {
		return (_data.true_on_zero && _data.direction == 1);
	}

	infi_trigger_t::infi_trigger_t() {
		__generate_hash();
		_data.hidden = false;
		_data.true_on_zero = false;
		_data.direction = 0;
		_data.signalled = 0;
		_data.count = 0;
	}

	infi_trigger_t::~infi_trigger_t() {
		iterator iter;
		for (iter=_input.begin();iter!=_input.end();iter++)
			(*iter)->__remove_output(this);
		for (iter=_output.begin();iter!=_output.end();iter++)
			(*iter)->__remove_input(this);
	}

	std::size_t infi_trigger_t::gethash() const {
		return _hash_value;
	}

	infi_trigger_t& infi_trigger_t::operator& (infi_trigger_t& ev) {
		if( ev.__is_and() ) {
			ev.__add_input(this);
			return ev;
		} else {
			infi_trigger_t* gen = new infi_trigger_t();
			gen->_data.hidden = true;
			gen->__set_and();
			this->add(*gen);
			ev.add(*gen);
			return *gen;
		}
	}
	infi_trigger_t& infi_trigger_t::operator| (infi_trigger_t& ev) {
		if( ev.__is_or() ) {
			ev.__add_input(this);
			return ev;
		} else {
			infi_trigger_t* gen = new infi_trigger_t();
			gen->_data.hidden = true;
			gen->__set_or();
			this->add(*gen);
			ev.add(*gen);
			return *gen;
		}
	}
	infi_trigger_t& infi_trigger_t::operator! () {
		infi_trigger_t* ev = new infi_trigger_t();
		ev->_data.hidden = true;
		ev->_data.direction = _data.direction;
		ev->_data.true_on_zero = !_data.true_on_zero;
		this->add(*ev);
		return *ev;
	}

	// send
	void infi_trigger_t::add(infi_trigger_t& ev) {
		__add_output(&ev);
		ev.__add_input(this);
	}
	bool infi_trigger_t::remove(infi_trigger_t& ev) {
		if ( __remove_output(&ev) ) {
			ev.__remove_input(this);
			return true;
		}
		return false;
	}

	void infi_trigger_t::operator() (bool sig, void* data) {
		if ( _input.empty() )
			_data.signalled = sig;
		this->Triggered(this, sig, data);
		for (iterator iter=_output.begin();iter!=_output.end();iter++)
			(*iter)->__handle_input(this, sig, data);
	}
	infi_trigger_t::operator bool () const {
		return _data.signalled;
	}

	// receive
	infi_trigger_t& infi_trigger_t::when( infi_trigger_t& ev ) {
		__add_input(&ev);
		ev.__add_output(this);
		return ev;
	}
	infi_trigger_t& infi_trigger_t::unwhen( infi_trigger_t& ev ) {
		__remove_input(&ev);
		ev.__remove_output(this);
		return ev;
	}

	void infi_trigger_t::Triggered(infi_trigger_t* sender, bool sig, void* data) { ; }

	void infi_trigger_t::debug() const {
		//__WriteError__("DEBUG " << this << ": " << _data.signalled << ", " << _data.count);
	}

}
