#ifndef __INFI_GL_OBJECTS_H__
#define __INFI_GL_OBJECTS_H__

#include "base/types.hpp"
#include "base/lib_export.hpp"

namespace Infinity {
namespace Render {

	struct DEFINE_EXPORT infi_gl_init_t;
	struct DEFINE_EXPORT infi_gl_command_t;
	struct DEFINE_EXPORT infi_gl_function_t;
	struct DEFINE_EXPORT infi_gl_selector_t;
	struct DEFINE_EXPORT infi_gl_enabled_t;
	struct DEFINE_EXPORT infi_gl_info_t;
	struct DEFINE_EXPORT infi_gl_version_t;
	struct DEFINE_EXPORT infi_gl_t;
	struct DEFINE_EXPORT infi_framebuffer_bindings_t;
	struct DEFINE_EXPORT infi_vertex_array_bindings_t;
	struct DEFINE_EXPORT infi_transform_feeback_bindings_t;
	struct DEFINE_EXPORT infi_blend_function_bindings_t;
	struct DEFINE_EXPORT infi_gl_context_t;
	struct DEFINE_EXPORT infi_gl_context_access_t;
	struct DEFINE_EXPORT infi_gl_context_controller_t;
	struct DEFINE_EXPORT infi_gl_shared_t;
	struct DEFINE_EXPORT infi_gl_queue_t;

	typedef uint32 BufferBindPoint;
	typedef uint32 DrawMode;
	typedef uint32 AttribType;
	typedef uint32 ShaderAttribType;

} }

#endif//__INFI_GL_OBJECTS_H__
