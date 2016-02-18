#ifndef __INFI_ABBREVIATIONS_H__
#define __INFI_ABBREVIATIONS_H__

#include "infinity.h"

typedef INFI::infi_extension_update_t			UsingUpdate;
typedef INFI::infi_extension_prerender_t		UsingPreRender;
typedef INFI::infi_extension_postrender_t		UsingPostRender;
typedef INFI::infi_renderable_t					UsingRender;

typedef const INFI::infi_display_t&				Display;
typedef INFI::infi_window_spec_t				WindowSpec;
typedef INFI::infi_window_t*					Window;

typedef INFI::render::infi_canvas_t*			Canvas;
typedef INFI::render::infi_texture_t*			Texture;
typedef INFI::render::infi_format_t				Format;
typedef INFI::render::infi_buffer_t*			Buffer;
typedef INFI::render::infi_vertices_t*			Vertices;
typedef INFI::render::infi_formatted_buffer_t	FormatBuffer;
typedef INFI::render::infi_program_t*			Program;

#endif//__INFI_ABBREVIATIONS_H__