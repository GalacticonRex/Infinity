#ifndef __INFI_RENDER_GL_H__
#define __INFI_RENDER_GL_H__

#include <fstream>
#include "base/types.hpp"
#include "depend/infi_gl.hpp"
#include "core/rect.hpp"
#include "core/vector.hpp"
#include "core/matrix.hpp"
#include "components/infi_window.hpp"
#include "modules/infi_module_defs.hpp"
#include "render/gl/infi_gl_defs.hpp"
#include "render/gl/infi_gl_extensions.hpp"

namespace Infinity {
namespace Render {

	struct infi_gl_t {
	private:
		std::ofstream& _output_log;
		bool _trace_on;
		Time::Point _start;

		struct __write_to_log__ {
			__write_to_log__(std::ofstream&);
		} _write_to_log;

		void __log_operation(Time::Point, std::ofstream&, bool, const char*, ...) const;

	public:
		static uint32 sizeOf(ShaderAttribType);
		static bool getComponents(ShaderAttribType, AttribType&, uint32&);

		template<typename _T>
		static bool getComponents(AttribType&, uint32&) {
			return false;
		}

		infi_gl_t( infi_gl_init_t&, std::ofstream& );

		const infi_gl_info_t extensions;
		const infi_gl_version_t version;

		void Debug_ActivateTrace();
		void Debug_DeactivateTrace();
		void Debug_SendMessage( const std::string& ) const;
		void Debug_SendWhitespace( uint32 = 1 ) const;

		// general texture functions
		void ActiveTexture( uint32 tex ) const;
		void DeleteTextures( uint32 count, const uint32* objs ) const;
		void GenTextures( uint32 count, uint32* output ) const;
		void GenerateMipmap() const;

		// GL_TEXTURE_2D functions
		void BindTexture( uint32 tex ) const;
		void GetTexImage( int32 level, GLenum format, GLenum type, void* pixels ) const;
		void TexImage( int32 level, GLenum internalFormat, uint32 width, uint32 height, GLenum format, GLenum type, const void* data ) const;
		void TexParameterf( GLenum pname, float32 param ) const;
		void TexParameterf( GLenum pname, float32* param ) const;
		void TexParameteri( GLenum pname, int32 param ) const;
		void TexParameteri( GLenum pname, int32* param ) const;
		void TexStorage( uint32 levels, GLenum format, uint32 w, uint32 h ) const;
		void TexSubImage( uint32 level, int32 offx, int32 offy, uint32 w, uint32 h, GLenum format, GLenum type, const void* pixels ) const;

		// GL_TEXTURE_2D_MULTISAMPLE functions
		void BindTextureMultisample( uint32 tex ) const;
		void TexImageMultisample( uint32 samples, GLint format, uint32 width, uint32 height, bool fixloc ) const;
		void TexParameterMultisamplef( GLenum pname, float32 param ) const;
		void TexParameterMultisamplef( GLenum pname, float32* param ) const;
		void TexParameterMultisamplei( GLenum pname, int32 param ) const;
		void TexParameterMultisamplei( GLenum pname, int32* param ) const;

		// create bind and link shaders
		uint32 CreateProgram() const;
		uint32 CreateShader( GLenum type ) const;
		int32 GetAttribLocation( uint32 prog, const char* name ) const;
		int32 GetFragDataLocation( uint32 prog, const char* fragname ) const;
		int32 GetUniformLocation( uint32 prog, const char* name ) const;

		void AttachShader( uint32 prog, uint32 comp ) const;
		void BindAttribLocation( uint32 prog, uint32 attrib, const char* str ) const;
		void BindFragDataLocation( uint32 prog, uint32 location, const char* fragname ) const;
		void CompileShader( uint32 shader ) const;
		void DeleteProgram( uint32 prog ) const;
		void DeleteShader( uint32 shader ) const;
		void DetachShader( uint32 prog, uint32 shader ) const;
		void GetActiveAttrib( uint32, uint32, uint32, int32*, int32*, GLenum*, char* ) const;
		void GetActiveUniform( uint32, uint32, uint32, int32*, int32*, GLenum*, char* ) const;
		void GetProgramiv( uint32 prog, GLenum pname, int32* output ) const;
		void GetProgramInfoLog( uint32 prog, uint32 maxlen, int32* len, char* output ) const;
		void GetShaderiv( uint32 shad, GLenum pname, int32* output ) const;
		void GetShaderInfoLog( uint32 shad, uint32 maxlen, int32* len, char* output ) const;
		void LinkProgram( uint32 prog ) const;
		void ShaderSource( uint32 shad, uint32 count, const char** str, const int32* length ) const;
		void UseProgram( uint32 prog ) const;

		// shader uniforms
		void Uniformf( uint32 location, float32 a ) const;
		void Uniformf( uint32 location, float32 a, float32 b ) const;
		void Uniformf( uint32 location, float32 a, float32 b, float32 c ) const;
		void Uniformf( uint32 location, float32 a, float32 b, float32 c, float32 d ) const;
		void Uniformf( uint32 location, const core::vec2& v ) const;
		void Uniformf( uint32 location, const core::vec3& v ) const;
		void Uniformf( uint32 location, const core::vec4& v ) const;
		void Uniformfv( uint32 location, uint32 c, const float32* a ) const;
		void Uniformfv( uint32 location, uint32 c, const core::vec2* v ) const;
		void Uniformfv( uint32 location, uint32 c, const core::vec3* v ) const;
		void Uniformfv( uint32 location, uint32 c, const core::vec4* v ) const;
		void Uniformi( uint32 location, int32 a ) const;
		void Uniformi( uint32 location, int32 a, int32 b ) const;
		void Uniformi( uint32 location, int32 a, int32 b, int32 c ) const;
		void Uniformi( uint32 location, int32 a, int32 b, int32 c, int32 d ) const;
		void Uniformi( uint32 location, const core::vec2i& v ) const;
		void Uniformi( uint32 location, const core::vec3i& v ) const;
		void Uniformi( uint32 location, const core::vec4i& v ) const;
		void Uniformiv( uint32 location, uint32 c, const int32* a ) const;
		void Uniformiv( uint32 location, uint32 c, const core::vec2i* v ) const;
		void Uniformiv( uint32 location, uint32 c, const core::vec3i* v ) const;
		void Uniformiv( uint32 location, uint32 c, const core::vec4i* v ) const;
		void Uniformui( uint32 location, uint32 a ) const;
		void Uniformui( uint32 location, uint32 a, uint32 b ) const;
		void Uniformui( uint32 location, uint32 a, uint32 b, uint32 c ) const;
		void Uniformui( uint32 location, uint32 a, uint32 b, uint32 c, uint32 d ) const;
		void Uniformui( uint32 location, const core::vec2ui& v ) const;
		void Uniformui( uint32 location, const core::vec3ui& v ) const;
		void Uniformui( uint32 location, const core::vec4ui& v ) const;
		void Uniformuiv( uint32 location, uint32 c, const uint32* a ) const;
		void Uniformuiv( uint32 location, uint32 c, const core::vec2ui* v ) const;
		void Uniformuiv( uint32 location, uint32 c, const core::vec3ui* v ) const;
		void Uniformuiv( uint32 location, uint32 c, const core::vec4ui* v ) const;
		void Uniform( uint32 location, const core::mat2& m ) const;
		void Uniform( uint32 location, const core::mat3& m ) const;
		void Uniform( uint32 location, const core::mat4& m ) const;
		void Uniformv( uint32 location, uint32 count, const core::mat2* m ) const;
		void Uniformv( uint32 location, uint32 count, const core::mat3* m ) const;
		void Uniformv( uint32 location, uint32 count, const core::mat4* m ) const;

		// blending functions
		void BlendColor( float32 r, float32 g, float32 b, float32 a ) const;
		void BlendEquation( GLenum mode ) const;
		void BlendEquationSeparate( GLenum modea, GLenum modec ) const;
		void BlendFunc( GLenum sfactor, GLenum dfactor ) const;
		void BlendFuncSeparate( GLenum sc, GLenum dc, GLenum sa, GLenum da ) const;

		// buffer control functions
		void BindBuffer( uint32 buf, uint32 obj ) const;
		void BindBufferBase( uint32 buf, uint32 slot, uint32 obj ) const;
		void BufferData( GLenum buf, uint32 sz, const void* data, GLenum readtype ) const;
		void BufferSubData( GLenum buf, uint32 offset, uint32 size, const void* data ) const;
		void CopyBufferSubData( GLenum r, GLenum w, int32 roff, int32 woff, int32 sz ) const;
		void DeleteBuffers( uint32 count, const uint32* objs ) const;
		void GenBuffers( uint32 count, uint32* output ) const;
		void GetBufferSubData( GLenum target, int32 offset, int32 size, void* output ) const;
		void* MapBuffer( GLenum target, GLenum access ) const;
		void* MapBufferRange( GLenum target, int32 offset, uint32 length, GLbitfield access ) const;
		void UnmapBuffer( GLenum target ) const;

		void BindFramebuffer( uint32 obj ) const;
		void BindFramebufferDraw( uint32 obj ) const;
		void BindFramebufferRead( uint32 obj ) const;
		void BlitFramebuffer( int32 srcx0, int32 srcy0, int32 srcx1, int32 srcy1, int32 dstx0, int32 dsty0, int32 dstx1, int32 dsty1, uint32 mask, GLenum filter ) const;
		GLenum CheckFramebufferStatus() const;
		void Clear( GLenum channels ) const;
		void ClearColor( float32 r, float32 g, float32 b, float32 a ) const;
		void DeleteFramebuffers( uint32 count, const uint32* objs ) const;
		void DrawBuffer( GLenum buf ) const;
		void DrawBuffers( uint32 count, GLenum* buffers ) const;
		void FramebufferTexture( GLenum attachment, uint32 tex, int32 level ) const;
		void GenFramebuffers( uint32 count, uint32* output ) const;

		void BindRenderbuffer( uint32 obj ) const;
		void DeleteRenderbuffers( uint32 count, const uint32* objs ) const;
		void FramebufferRenderbuffer( GLenum attachment, uint32 buffer ) const;
		void GenRenderbuffers( uint32 count, uint32* output ) const;
		void RenderbufferStorage( GLenum format, uint32 width, uint32 height ) const;
		void RenderbufferStorageMultisample( uint32 samples, GLenum format, uint32 width, uint32 height ) const;

		// vertex array functions
		void DisableVertexAttribArray( uint32 chan ) const;
		void DrawArrays( GLenum style, uint32 start, uint32 count ) const;
		void DrawArraysInstanced( GLenum style, uint32 start, uint32 count, uint32 prim ) const;
		void DrawElements( GLenum style, uint32 count, GLenum type, void* offset ) const;
		void DrawElementsBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 base ) const;
		void DrawElementsInstanced( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim ) const;
		void DrawElementsInstancedBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim, uint32 base ) const;
		void EnableVertexAttribArray( uint32 chan ) const;
		void VertexAttribPointer( uint32 index, int32 sz, GLenum type, bool normalized, uint32 stride, void* offset ) const;

		void BindVertexArray( uint32 obj ) const;
		void DeleteVertexArrays( uint32 count, const uint32* objs ) const;
		void GenVertexArrays( uint32 count, uint32* objs ) const;

		// transform feedback functions
		void BeginTransformFeedback( GLenum style ) const;
		void EndTransformFeedback() const;
		void TransformFeedbackVaryings( uint32 prog, uint32 count, const char** str, GLenum mode ) const;

		// query objects
		void BeginQuery( GLenum type, uint32 query ) const;
		void DeleteQueries( uint32 count, const uint32* objs ) const;
		void EndQuery( GLenum type ) const;
		void GenQueries( uint32 count, uint32* objs ) const;
		void GetQueryObjectiv( uint32 query, GLenum type, int32* output ) const;
		void GetQueryObjectuiv( uint32 query, GLenum type, uint32* output ) const;

		// depth stencil functions
		void ColorMask( bool r, bool g, bool b, bool a ) const;
		void ColorMask( bool rgba ) const;
		void DepthFunc( GLenum mode ) const;
		void DepthMask( bool active ) const;
		void StencilFunc( GLenum func, int32 ref, uint32 mask ) const;
		void StencilFuncSeparate( GLenum face, GLenum func, int32 ref, uint32 mask ) const;
		void StencilMask( uint32 mask ) const;
		void StencilMaskSeparate( GLenum face, uint32 mask ) const;
		void StencilOp( GLenum sfail, GLenum dpfail, GLenum dppass ) const;
		void StencilOpSeparate( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass ) const;

		// misc functions
		const uint8* GetString( GLenum name ) const;
		const uint8* GetStringi( GLenum name, uint32 index ) const;
		bool IsEnabled( GLenum cap ) const;

		void CullFace( GLenum ) const;
		void FrontFace( GLenum ) const;

		void Disable( GLenum elem ) const;
		void Enable( GLenum elem ) const;
		void Flush() const;
		void Finish() const;
		void GetFloatv( GLenum pname, float32* output ) const;
		void GetIntegerv( GLenum pname, int32* output ) const;
		void PointSize( float32 size ) const;
		void ShadeModel( GLenum mode ) const;
		void Viewport( const core::rect& ) const;
		void Viewport( int32 x, int32 y, uint32 w, uint32 h ) const;

		static AttribType TYPE_BYTE;
		static AttribType TYPE_UNSIGNED_BYTE;
		static AttribType TYPE_SHORT;
		static AttribType TYPE_UNSIGNED_SHORT;
		static AttribType TYPE_INT;
		static AttribType TYPE_UNSIGNED_INT;
		static AttribType TYPE_HALF_FLOAT;
		static AttribType TYPE_FLOAT;
		static AttribType TYPE_DOUBLE;
		static AttribType TYPE_FIXED;

		static ShaderAttribType FLOAT_VEC1;
		static ShaderAttribType FLOAT_VEC2;
		static ShaderAttribType FLOAT_VEC3;
		static ShaderAttribType FLOAT_VEC4;
		static ShaderAttribType FLOAT_MAT2;
		static ShaderAttribType FLOAT_MAT3;
		static ShaderAttribType FLOAT_MAT4;
		static ShaderAttribType FLOAT_MAT2x3;
		static ShaderAttribType FLOAT_MAT2x4;
		static ShaderAttribType FLOAT_MAT3x2;
		static ShaderAttribType FLOAT_MAT3x4;
		static ShaderAttribType FLOAT_MAT4x2;
		static ShaderAttribType FLOAT_MAT4x3;
		static ShaderAttribType INT_VEC1;
		static ShaderAttribType INT_VEC2;
		static ShaderAttribType INT_VEC3;
		static ShaderAttribType INT_VEC4;
		static ShaderAttribType UNSIGNED_INT_VEC1;
		static ShaderAttribType UNSIGNED_INT_VEC2;
		static ShaderAttribType UNSIGNED_INT_VEC3;
		static ShaderAttribType UNSIGNED_INT_VEC4;
		static ShaderAttribType DOUBLE_VEC1;
		static ShaderAttribType DOUBLE_VEC2;
		static ShaderAttribType DOUBLE_VEC3;
		static ShaderAttribType DOUBLE_VEC4;
		static ShaderAttribType DOUBLE_MAT2;
		static ShaderAttribType DOUBLE_MAT3;
		static ShaderAttribType DOUBLE_MAT4;
		static ShaderAttribType DOUBLE_MAT2x3;
		static ShaderAttribType DOUBLE_MAT2x4;
		static ShaderAttribType DOUBLE_MAT3x2; 
		static ShaderAttribType DOUBLE_MAT3x4;
		static ShaderAttribType DOUBLE_MAT4x2;
		static ShaderAttribType DOUBLE_MAT4x3;

		static DrawMode POINTS;
		static DrawMode LINE_STRIP;
		static DrawMode LINE_LOOP;
		static DrawMode LINES;
		static DrawMode LINE_STRIP_ADJACENCY;
		static DrawMode LINES_ADJACENCY;
		static DrawMode TRIANGLE_STRIP;
		static DrawMode TRIANGLE_FAN;
		static DrawMode TRIANGLES;
		static DrawMode TRIANGLE_STRIP_ADJACENCY;
		static DrawMode TRIANGLES_ADJACENCY;
		static DrawMode PATCHES;

		static BufferBindPoint ARRAY_BUFFER;
		static BufferBindPoint ATOMIC_COUNTER_BUFFER;
		static BufferBindPoint COPY_READ_BUFFER;
		static BufferBindPoint COPY_WRITE_BUFFER;
		static BufferBindPoint DISPATCH_INDIRECT_BUFFER;
		static BufferBindPoint DRAW_INDIRECT_BUFFER;
		static BufferBindPoint ELEMENT_ARRAY_BUFFER;
		static BufferBindPoint PIXEL_PACK_BUFFER;
		static BufferBindPoint PIXEL_UNPACK_BUFFER;
		static BufferBindPoint QUERY_BUFFER;
		static BufferBindPoint SHADER_STORAGE_BUFFER;
		static BufferBindPoint TEXTURE_BUFFER;
		static BufferBindPoint TRANSFORM_FEEDBACK_BUFFER;
		static BufferBindPoint UNIFORM_BUFFER;
	};

	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<float32>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec2>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec3>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec4>(AttribType&, uint32&);

	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<int32>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec2i>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec3i>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec4i>(AttribType&, uint32&);

	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<uint32>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec2ui>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec3ui>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::vec4ui>(AttribType&, uint32&);

	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::mat2>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::mat3>(AttribType&, uint32&);
	template<> bool DEFINE_EXPORT infi_gl_t::getComponents<core::mat4>(AttribType&, uint32&);

} }

#endif//__INFI_RENDER_GL_H__
