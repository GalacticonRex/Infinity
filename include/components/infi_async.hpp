#ifndef __INFI_ASYNC_HPP__
#define __INFI_ASYNC_HPP__

#include <functional>
#include <atomic>
#include "components/infi_component_defs.hpp"
#include "engine/updatemngr/infi_update_mngr_module.hpp"

namespace Infinity {

	struct infi_async_t {
	struct call_order_t {
		infi_update_mngr_module_t::Function func;
		std::atomic<uint32> counterFinished;
		std::atomic<uint32> counterAlive;
		std::atomic<call_order_t*> next;

		call_order_t(const infi_update_mngr_module_t::Function&);
		void operator()(infi_controller_t&);
	};

	private:
		infi_controller_t& _ctrl;
		call_order_t* _self;

		infi_async_t(infi_controller_t&);

	public:
		static void runAsyncOperation(infi_controller_t&, call_order_t*);

		infi_async_t(infi_controller_t&, const infi_update_mngr_module_t::Function&, bool delayed=false);
		~infi_async_t();

		call_order_t& asyncOperation();

		infi_async_t then(const infi_update_mngr_module_t::Function&);
	};
	
}

#endif//__INFI_ASYNC_HPP__