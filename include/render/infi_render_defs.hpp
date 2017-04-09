#ifndef __INFI_RENDER_OBJECTS_H__
#define __INFI_RENDER_OBJECTS_H__

#include "base/lib_export.hpp"

namespace Infinity {
namespace Render {

	// Renderers
	struct DEFINE_EXPORT infi_renderer_t;
	struct DEFINE_EXPORT infi_synchronized_renderer_t;

	// Asynchronous Operation
	struct DEFINE_EXPORT infi_render_async_t;

	// Basic Render Resource
	struct DEFINE_EXPORT infi_resource_t;

	// Level 1 Objects
	struct DEFINE_EXPORT infi_vertex_array_t;
	struct DEFINE_EXPORT infi_program_t;
	struct DEFINE_EXPORT infi_buffer_object_t;
	struct DEFINE_EXPORT infi_texture_t;
	struct DEFINE_EXPORT infi_framebuffer_t;

	// Level 2 Objects
	struct DEFINE_EXPORT infi_vertices_t;

	// Formatters
	struct DEFINE_EXPORT infi_blend_func_t;
	struct DEFINE_EXPORT infi_vertex_format_t;

	// Level 2 Objects
	struct DEFINE_EXPORT infi_canvas_t;
	struct DEFINE_EXPORT infi_pixel_object_t;	

	// Projection Objects
	struct DEFINE_EXPORT infi_view_matrix_t;
	struct DEFINE_EXPORT infi_projection_t;
	struct DEFINE_EXPORT infi_orthogonal_t;
	struct DEFINE_EXPORT infi_camera_t;

} }

#endif//__INFI_RENDER_OBJECTS_H__
