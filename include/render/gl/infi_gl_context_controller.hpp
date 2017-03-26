#ifndef __INFI_GL_CONTEXT_CONTROLLER_HPP__
#define __INFI_GL_CONTEXT_CONTROLLER_HPP__

#include <unordered_map>
#include "render/gl/infi_gl_context.hpp"
#include "render/gl/infi_gl_shared.hpp"
#include "render/gl/infi_gl_context_access.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_context_controller_t {
	private:
		infi_gl_t& _gl;
		infi_gl_context_t* _current_context;
		std::unordered_map<void*, infi_gl_context_t*> _contexts;

		void __set_current(void*);
		void __destroy_context(void*);

	public:
		infi_gl_shared_t& shared;
		infi_gl_context_access_t& perContext;
		
		infi_gl_context_controller_t(infi_gl_t&, infi_gl_shared_t&, infi_gl_context_access_t&, void*);
		~infi_gl_context_controller_t();

		infi_gl_context_t* getCurrentContext() const;

		void* createContext( void* );
		void destroyContext( void* );
		void setCurrentContext( void*, void* );
		void swapContext( void* );
	};

} }

#endif//__INFI_GL_CONTEXT_CONTROLLER_HPP__