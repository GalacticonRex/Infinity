#ifndef __INFI_NAMED_OBJECT_HPP__
#define __INFI_NAMED_OBJECT_HPP__

#include <string>
#include "components/infi_component_defs.hpp"

namespace Infinity {

	struct infi_named_object_t {
	private:
		std::string _name;
	public:
		infi_named_object_t(const std::string&);
		const std::string& name() const;
	};

}

#endif//__INFI_NAMED_OBJECT_HPP__