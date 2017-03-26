#include "components/infi_operator_thread.hpp"
#include "components/infi_extension.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {

	void infi_operator_thread_t::__execute() {
		std::unique_lock<std::mutex> lk(_lock);
		while (_alive) {
			while ( _complete ) {
				_cond.wait(lk);
				if ( !_alive )
					return;
			}
			try {
				_operation(_ctrl);
			} catch(Error::message<Error::Fatality::Fatal> e) {
				if ( !_error.handle(*this, e) )
					break;
			} catch(Error::message<Error::Fatality::Thread> e) {
				if ( !_error.handle(*this, e) )
					break;
			} catch(Error::message<Error::Fatality::Method> e) {
				if ( !_error.handle(*this, e) )
					break;
			} catch(Error::message<Error::Fatality::Warning> e) {
				if ( !_error.handle(*this, e) )
					break;
			} catch (...) {
				std::cerr << "something terrible happened..." << std::endl;
			}
			_complete = true;
			_pool(this);
		}
	}

	infi_operator_thread_t::infi_operator_thread_t( const std::string& n,
													infi_controller_t& ctrl,
													infi_update_mngr_module_t::threadComplete& thr,
													infi_error_handler_t& hnd) :
		infi_named_object_t(n),
		_error(hnd),
		_alive(true),
		_complete(true),
		_ctrl(ctrl),
		_pool(thr),
		_thread(__execute, this) {
		_pool(this);
	}
	infi_operator_thread_t::~infi_operator_thread_t() {
		_alive = false;
		_cond.notify_all();
		_thread.join();
	}
	void infi_operator_thread_t::operator()(infi_update_mngr_module_t::Function&& ext) {
		std::lock_guard<std::mutex> lk(_lock);
		if ( _complete ) {
			_operation = ext;
			_complete = false;
			_cond.notify_all();
		}
	}

}