#ifndef __INFI_ERROR_HANDLER_HPP__
#define __INFI_ERROR_HANDLER_HPP__

#include "base/error_log.hpp"
#include "components/infi_component_defs.hpp"
#include "modules/infi_module_defs.hpp"

namespace Infinity {

	struct infi_error_handler_t {
		virtual bool handle(infi_named_object_t&, Error::message<Error::Fatality::Fatal>&) = 0;
		virtual bool handle(infi_named_object_t&, Error::message<Error::Fatality::Thread>&) = 0;
		virtual bool handle(infi_named_object_t&, Error::message<Error::Fatality::Method>&) = 0;
		virtual bool handle(infi_named_object_t&, Error::message<Error::Fatality::Warning>&) = 0;
	};

}

#endif//__INFI_ERROR_HANDLER_HPP__