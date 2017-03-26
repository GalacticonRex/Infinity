#include "depend/infi_sdl.hpp"
#include "depend/infi_gl.hpp"
#include "render/gl/infi_gl_init.hpp"

namespace Infinity {
namespace Render {

	uint32 infi_gl_init_t::_built = 0;
	uint32 infi_gl_init_t::_init = 0;

	infi_gl_init_t::infi_gl_init_t(infi_root_module_t& rt, infi_display_list_t& dspl) {
		////Error::define_scope __scope__("infi_gl_init_t.ctor()");

		if ( !_built ) {
			switch( dspl[0].format ) {
				case SDL_PIXELFORMAT_RGB888:
					SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8 );
					SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8 );
					SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8 );
					break;
				default:
					Error::send<Error::Fatality::Fatal>(
						Error::Type::Library,
						"Could not initialize SDL pixel format!"
					);
					break;
			}
			
			SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
			
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
			if ( SDL_GL_SetSwapInterval(-1) == -1 )
				if ( SDL_GL_SetSwapInterval(0) == -1 )
					SDL_GL_SetSwapInterval(1);

			_built = true;
		}

		_root_window = rt.baseWindow();
		_root_context = SDL_GL_CreateContext( (SDL_Window*)_root_window );

		if ( !_init ) {
			uint32 err;
			if ( (err=glewInit()) != GLEW_OK )
				Error::send<Error::Fatality::Fatal>(
					Error::Type::Graphics,
					"Could not initialize OpenGL!"
				);

			_init = true;
		}
	}

} }