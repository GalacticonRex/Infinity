#ifndef __INFI_OPERATOR_THREAD_HPP__
#define __INFI_OPERATOR_THREAD_HPP__

#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "base/types.hpp"
#include "base/error_log.hpp"

#include "engine/infi_engine_defs.hpp"
#include "engine/updatemngr/infi_update_mngr_module.hpp"
#include "components/infi_component_defs.hpp"

#include "modules/infi_error_handler.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {

	struct infi_operator_thread_t : infi_named_object_t {	
	private:
		infi_error_handler_t& _error;

		std::atomic<bool> _alive;
		std::atomic<bool> _complete;

		infi_controller_t& _ctrl;
		infi_update_mngr_module_t::threadComplete& _pool;
		infi_update_mngr_module_t::Function _operation;

		// synchonization members
		std::mutex _lock;
		std::condition_variable _cond;
		std::thread _thread;

		void __execute();

	public:
		infi_operator_thread_t( const std::string&,
								infi_controller_t&,
								infi_update_mngr_module_t::threadComplete&,
								infi_error_handler_t& );
		~infi_operator_thread_t();
		void operator()(infi_update_mngr_module_t::Function&&);
	};

}

#endif//__INFI_OPERATOR_THREAD_HPP__