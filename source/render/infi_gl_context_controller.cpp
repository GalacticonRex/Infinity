#include "depend/infi_sdl.hpp"
#include "render/gl/infi_gl_context_controller.hpp"

namespace Infinity {
namespace Render {

	infi_gl_context_controller_t::infi_gl_context_controller_t(infi_gl_t& gl, infi_gl_shared_t& shr, infi_gl_context_access_t& ctx, void* root) :
		_gl(gl),
		_current_context(new infi_gl_context_t(gl, ctx)),
		shared(shr),
		perContext(ctx) {
		_contexts[root] = _current_context;
		perContext.setContextController(*this);
	}
	infi_gl_context_controller_t::~infi_gl_context_controller_t() {
		
	}

	infi_gl_context_t* infi_gl_context_controller_t::getCurrentContext() const {
		return _current_context;
	}

	void* infi_gl_context_controller_t::createContext( void* sdl ) {
		SDL_GLContext context = SDL_GL_CreateContext( (SDL_Window*) sdl );
		__set_current((void*)context);
		return (void*) context;
	}
	void infi_gl_context_controller_t::destroyContext( void* cxt ) {
		//Error::define_scope __scope__("GL.Context.Delete");
		if ( !cxt )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"got null context"
			);

		SDL_GL_DeleteContext( (SDL_GLContext) cxt );
		__destroy_context(cxt);
	}
	void infi_gl_context_controller_t::setCurrentContext( void* sdl, void* cxt ) {
		//Error::define_scope __scope__("GL.Context.Current");
		if ( !sdl || !cxt )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"got null window or context" 
			);

		SDL_GL_MakeCurrent( (SDL_Window*) sdl, (SDL_GLContext) cxt );
		__set_current(cxt);
	}
	void infi_gl_context_controller_t::swapContext( void* sdl ) {
		//Error::define_scope __scope__("GL.Context.Swap");
		if ( !sdl )
			Error::send<Error::Fatality::Method>(
				Error::Type::NullDeref,
				"got null window"
			);

		SDL_GL_SwapWindow( (SDL_Window*) sdl );
	}

	void infi_gl_context_controller_t::__set_current(void* ctx) {
		infi_gl_context_t*& glctx = _contexts[ctx];
		if ( glctx == nullptr ) {
			glctx = new infi_gl_context_t(_gl, perContext);
		}
		_current_context = glctx;
	}
	void infi_gl_context_controller_t::__destroy_context(void* ctx) {
		std::unordered_map<void*, infi_gl_context_t*>::iterator iter = _contexts.find(ctx);
		if ( iter == _contexts.end() )
			return;

		delete (*iter).second;
		_contexts.erase(iter);
	}

} }