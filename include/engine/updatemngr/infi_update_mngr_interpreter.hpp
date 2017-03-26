#ifndef __INFI_UPDATE_MANAGER_INTERPRETER_HPP__
#define __INFI_UPDATE_MANAGER_INTERPRETER_HPP__

#include "engine/updatemngr/infi_update_mngr_module.hpp"
#include "modules/infi_interpreter.hpp"
#include "components/infi_extension.hpp"
#include "components/infi_operator_thread.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {


	struct infi_update_mngr_interpreter_t : public infi_update_mngr_module_t::interpreter {
	private:
		struct __extension_added__ : public infi_process_message_t<infi_update_mngr_module_t::Function> {
		private:
			infi_update_mngr_interpreter_t& _src;
		public:
			__extension_added__(infi_update_mngr_interpreter_t&);
			void interpret(infi_update_mngr_module_t::Function&);
		};
		struct __thread_complete__ : public infi_process_message_t<infi_operator_thread_t*> {
		private:
			infi_update_mngr_interpreter_t& _src;
		public:
			__thread_complete__(infi_update_mngr_interpreter_t&);
			void interpret(infi_operator_thread_t*&);
		};

		std::vector<infi_operator_thread_t*> _threads;
		std::queue<infi_operator_thread_t*> _queue_threads;
		std::queue<infi_update_mngr_module_t::Function> _queue_extensions;

		infi_controller_t& _ctrl;
		infi_update_mngr_module_t::extension& _ext;
		infi_update_mngr_module_t::threadComplete& _pool;

		__extension_added__ _extension_added;
		__thread_complete__ _thread_complete;

	public:
		infi_update_mngr_interpreter_t(	infi_controller_t&,
										infi_error_handler_t&,
										uint32,
										infi_update_mngr_module_t::extension&,
										infi_update_mngr_module_t::threadComplete& );
		~infi_update_mngr_interpreter_t();
	};

}

#endif//__INFI_UPDATE_MANAGER_INTERPRETER_HPP__