#include "components/infi_named_object.hpp"

namespace Infinity {

	infi_named_object_t::infi_named_object_t(const std::string& name) :
		_name(name) { ; }
	const std::string& infi_named_object_t::name() const {
		return _name;
	}

}