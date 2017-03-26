#include "io/infi_base_loader.hpp"
#include "engine/infi_controller.hpp"

namespace Infinity {
namespace IO {

	infi_base_loader_t::infi_base_loader_t(const std::string& fname) :
		_fname(fname) { ; }

	void infi_base_loader_t::operator()(infi_controller_t& ctrl) {
		std::ifstream input(_fname, std::ios::binary);
		if ( !input.good() ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::NotFound,
				"Could not find file %s",
				_fname.c_str()
			);
		}
		this -> Load(ctrl, input);
		input.close();
	}

} }