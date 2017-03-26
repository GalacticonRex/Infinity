#ifndef __INFI_RENDER_RECIEVER_HPP__
#define __INFI_RENDER_RECIEVER_HPP__

#include "modules/infi_module_defs.hpp"
#include "modules/infi_termination_dispatch.hpp"
#include "render/module/infi_render_module.hpp"
#include "render/gl/infi_gl_shared.hpp"
#include "render/gl/infi_gl_context_access.hpp"

namespace Infinity {
namespace Render {

	struct infi_render_reciever_t {
		infi_render_module_t::draw draw;
		infi_render_module_t::createContext createContext;
		infi_render_module_t::destroyContext destroyContext;
		infi_dispatch_terminate_t terminate;

		Render::infi_gl_shared_t shared;
		Render::infi_gl_context_access_t perContext;

		infi_render_reciever_t(infi_render_module_t::module&);
	};

} }

#endif//__INFI_RENDER_RECIEVER_HPP__
