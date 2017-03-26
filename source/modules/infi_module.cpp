#include <iostream>
#include "base/error_log.hpp"
#include "modules/infi_module.hpp"
#include "modules/infi_error_handler.hpp"
#include "modules/infi_interpreter.hpp"

namespace Infinity {
	infi_module_base_t::infi_module_base_t(const std::string& n, infi_error_handler_t& e) :
		infi_named_object_t(n), _error(e) { ; }

	infi_event_queue_t& infi_module_base_t::exposeQueue() {
		return _queue;
	}
}