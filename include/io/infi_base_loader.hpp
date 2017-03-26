#ifndef __INFI_BASE_LOADER_HPP__
#define __INFI_BASE_LOADER_HPP__

#include <fstream>

#include "io/infi_io_defs.hpp"
#include "engine/infi_engine_defs.hpp"
#include "components/infi_extension.hpp"

namespace Infinity {
namespace IO {

	struct infi_base_loader_t {
	private:
		std::string _fname;
	protected:
		virtual void Load(infi_controller_t&, std::ifstream&) = 0;
	public:
		infi_base_loader_t(const std::string&);
		void operator()(infi_controller_t&);
	};

} }

#endif//__INFI_BASE_LOADER_HPP__