#ifndef __INFI_GL_INITIALIZER_HPP__
#define __INFI_GL_INITIALIZER_HPP__

#include "engine/infi_root_module.hpp"
#include "engine/infi_displays.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_init_t {
	private:
		static uint32 _built;
		static uint32 _init;

		void* _root_window;
		void* _root_context;

	public:
		infi_gl_init_t(infi_root_module_t&, infi_display_list_t&);
	};

} }

#endif//__INFI_GL_INITIALIZER_HPP__