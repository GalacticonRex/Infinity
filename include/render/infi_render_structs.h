#ifndef __INFI_RENDER_STRUCTS_H__
#define __INFI_RENDER_STRUCTS_H__

#include "main/infi_export.h"
#include "main/infi_gl.h"

namespace INFI {
namespace render {
	
	enum INFI_array_write {
		INFI_W_STREAM = GL_STREAM_DRAW,
		INFI_W_DYNAMIC = GL_DYNAMIC_DRAW,
		INFI_W_STATIC = GL_STATIC_DRAW,
		
		INFI_R_STREAM = GL_STREAM_READ,
		INFI_R_DYNAMIC = GL_DYNAMIC_READ,
		INFI_R_STATIC = GL_STATIC_READ,
		
		INFI_C_STREAM = GL_STREAM_COPY,
		INFI_C_DYNAMIC = GL_DYNAMIC_COPY,
		INFI_C_STATIC = GL_STATIC_COPY
	};
	
	enum INFI_render_style {
		INFI_POINTS = GL_POINTS,
		INFI_LINES = GL_LINES,
		INFI_LINE_STRIP = GL_LINE_STRIP,
		INFI_LINE_LOOP = GL_LINE_LOOP,
		INFI_TRIANGLES = GL_TRIANGLES,
		INFI_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
		INFI_TRIANGLE_FAN = GL_TRIANGLE_FAN,
		INFI_QUADS = GL_QUADS,
		INFI_QUAD_STRIP = GL_QUAD_STRIP,
		INFI_PATCHES = GL_PATCHES
	};
	
	struct INFI_EXPORT infi_blend_t;
	struct INFI_EXPORT infi_texture_t;
	struct INFI_EXPORT infi_canvas_t;
	struct INFI_EXPORT infi_program_t;
	struct INFI_EXPORT infi_view_transform_t;
	struct INFI_EXPORT infi_projection_t;
	struct INFI_EXPORT infi_camera_t;
	struct INFI_EXPORT infi_format_t;
	struct INFI_EXPORT infi_buffer_t;
	
	struct INFI_EXPORT infi_vertices_t;
	struct INFI_EXPORT infi_formatted_buffer_t;
	struct INFI_EXPORT infi_stencil_t;
	struct INFI_EXPORT infi_renderbuffer_t;
	
	struct INFI_EXPORT infi_renderable_t;
	struct INFI_EXPORT infi_zlist_t;
	struct INFI_EXPORT infi_view_t;
	
	//struct INFI_EXPORT infi_pixel_buffer_t;
	
	
} }

#endif//__INFI_RENDER_STRUCTS_H__