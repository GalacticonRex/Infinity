#ifndef __INFI_WINDOW_MANAGER_RECIEVER_HPP__
#define __INFI_WINDOW_MANAGER_RECIEVER_HPP__

#include "modules/infi_module_defs.hpp"
#include "modules/infi_module.hpp"
#include "modules/infi_termination_dispatch.hpp"
#include "engine/winmngr/infi_win_mngr_module.hpp"

namespace Infinity {

	struct infi_win_mngr_reciever_t {

		infi_win_mngr_module_t::refresh refresh;
		infi_win_mngr_module_t::destroyWindow destroyWindow;
		infi_win_mngr_module_t::bindRenderable bindRenderable;
		infi_dispatch_terminate_t terminate;

		infi_win_mngr_reciever_t(infi_win_mngr_module_t::module&);
		
	};

}

#endif//__INFI_WINDOW_MANAGER_RECIEVER_HPP__