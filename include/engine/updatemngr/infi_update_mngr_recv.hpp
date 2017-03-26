#ifndef __INFI_UPDATE_MANAGER_RECIEVER_HPP__
#define __INFI_UPDATE_MANAGER_RECIEVER_HPP__

#include "modules/infi_module_defs.hpp"
#include "modules/infi_module.hpp"
#include "modules/infi_termination_dispatch.hpp"
#include "engine/updatemngr/infi_update_mngr_module.hpp"

namespace Infinity {

	struct infi_update_mngr_reciever_t {
		infi_update_mngr_module_t::extension extension;
		infi_update_mngr_module_t::threadComplete threadComplete;
		infi_dispatch_terminate_t terminate;

		infi_update_mngr_reciever_t(infi_update_mngr_module_t::module&);
	};

}

#endif//__INFI_UPDATE_MANAGER_RECIEVER_HPP__