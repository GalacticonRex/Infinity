#include "components/infi_async.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	infi_async_t::call_order_t::call_order_t(const infi_update_mngr_module_t::Function& f) :
		func(f), counterFinished(0), counterAlive(0), next(NULL) { ; }

	void infi_async_t::call_order_t::operator()(infi_controller_t& ctrl) {
		func(ctrl);

		counterFinished ++ ;

		call_order_t* c;
		if ( (c=next.exchange(NULL, std::memory_order_relaxed)) != NULL ) {
			ctrl.extendWith([c](infi_controller_t& ctrl){(*c)(ctrl);});
		}

		if ( counterAlive.fetch_add(1, std::memory_order_relaxed) == 1 ) {
			delete this;
		}
	}

	void infi_async_t::runAsyncOperation(infi_controller_t& ctrl, call_order_t* c) {
		ctrl.extendWith([c](infi_controller_t& ctrl){(*c)(ctrl);});
	}

	infi_async_t::infi_async_t(infi_controller_t& ctrl) :
		_ctrl(ctrl), _self(NULL) { ; }
	infi_async_t::infi_async_t(infi_controller_t& ctrl, const infi_update_mngr_module_t::Function& f, bool delayed) :
		_ctrl(ctrl), _self(new call_order_t(f)) {
		call_order_t* c = _self;
		if ( !delayed )
			_ctrl.extendWith([c](infi_controller_t& ctrl){(*c)(ctrl);});
	}
	infi_async_t::~infi_async_t() {
		if ( _self -> counterAlive.fetch_add(1, std::memory_order_relaxed) == 1 ) {
			delete _self;
		}
	}

	infi_async_t::call_order_t& infi_async_t::asyncOperation() {
		if ( _self == NULL )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"No async operation yet defined!"
			);
		return *_self;
	}

	infi_async_t infi_async_t::then(const infi_update_mngr_module_t::Function& f) {
		infi_async_t a(_ctrl);
		call_order_t* c = new call_order_t(f);
		a._self = c;
		if ( (uint32) _self -> counterFinished == 1 ) {
			_ctrl.extendWith([c](infi_controller_t& ctrl){(*c)(ctrl);});
		} else {
			_self -> next = a._self;
		}
		return a;
	}

}