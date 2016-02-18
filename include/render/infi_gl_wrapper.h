#ifndef __INFI_OPENGL_WRAPPER_H__
#define __INFI_OPENGL_WRAPPER_H__

#include "main/infi_error.h"
#include "core/infi_rect.h"
#include "core/infi_matrix.h"
#include "render/infi_gl_extensions.h"

namespace INFI {
namespace render {
	
INFI_FUNCTION( void, InfiGLActivateTrace, () );
INFI_FUNCTION( void, InfiGLDeactivateTrace, () );
INFI_FUNCTION( void, InfiGLSendMessage, ( const core::string_t& ) );
INFI_FUNCTION( void, InfiGLSendWhitespace, ( uint32 = 1 ) );

// general texture functions
INFI_FUNCTION( void, InfiGLActiveTexture, ( uint32 tex ) );
INFI_FUNCTION( void, InfiGLDeleteTextures, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLGenTextures, ( uint32 count, uint32* output ) );
INFI_FUNCTION( void, InfiGLGenerateMipmap, () );

// GL_TEXTURE_2D functions
INFI_FUNCTION( void, InfiGLBindTexture, ( uint32 tex ) );
INFI_FUNCTION( void, InfiGLGetTexImage, ( int32 level, GLenum format, GLenum type, void* pixels ) );
INFI_FUNCTION( void, InfiGLTexImage, ( int32 level, GLenum internalFormat, uint32 width, uint32 height, GLenum format, GLenum type, const void* data ) );
INFI_FUNCTION( void, InfiGLTexParameterf, ( GLenum pname, float32 param ) );
INFI_FUNCTION( void, InfiGLTexParameterf, ( GLenum pname, float32* param ) );
INFI_FUNCTION( void, InfiGLTexParameteri, ( GLenum pname, int32 param ) );
INFI_FUNCTION( void, InfiGLTexParameteri, ( GLenum pname, int32* param ) );
INFI_FUNCTION( void, InfiGLTexStorage, ( uint32 levels, GLenum format, uint32 w, uint32 h ) );
INFI_FUNCTION( void, InfiGLTexSubImage, ( uint32 level, int32 offx, int32 offy, uint32 w, uint32 h, GLenum format, GLenum type, const void* pixels ) );

// GL_TEXTURE_2D_MULTISAMPLE functions
INFI_FUNCTION( void, InfiGLBindTextureMultisample, ( uint32 tex ) );
INFI_FUNCTION( void, InfiGLTexImageMultisample, ( uint32 samples, GLint format, uint32 width, uint32 height, bool fixloc ) );
INFI_FUNCTION( void, InfiGLTexParameterMultisamplef, ( GLenum pname, float32 param ) );
INFI_FUNCTION( void, InfiGLTexParameterMultisamplef, ( GLenum pname, float32* param ) );
INFI_FUNCTION( void, InfiGLTexParameterMultisamplei, ( GLenum pname, int32 param ) );
INFI_FUNCTION( void, InfiGLTexParameterMultisamplei, ( GLenum pname, int32* param ) );

// create bind and link shaders
INFI_FUNCTION( uint32, InfiGLCreateProgram, () );
INFI_FUNCTION( uint32, InfiGLCreateShader, ( GLenum type ) );
INFI_FUNCTION( int32, InfiGLGetAttribLocation, ( uint32 prog, const char* name ) );
INFI_FUNCTION( int32, InfiGLGetFragDataLocation, ( uint32 prog, const char* fragname ) );
INFI_FUNCTION( int32, InfiGLGetUniformLocation, ( uint32 prog, const char* name ) );

INFI_FUNCTION( void, InfiGLAttachShader, ( uint32 prog, uint32 comp ) );
INFI_FUNCTION( void, InfiGLBindAttribLocation, ( uint32 prog, uint32 attrib, const char* str ) );
INFI_FUNCTION( void, InfiGLBindFragDataLocation, ( uint32 prog, uint32 location, const char* fragname ) );
INFI_FUNCTION( void, InfiGLCompileShader, ( uint32 shader ) );
INFI_FUNCTION( void, InfiGLDeleteProgram, ( uint32 prog ) );
INFI_FUNCTION( void, InfiGLDeleteShader, ( uint32 shader ) );
INFI_FUNCTION( void, InfiGLDetachShader, ( uint32 prog, uint32 shader ) );
INFI_FUNCTION( void, InfiGLGetProgramiv, ( uint32 prog, GLenum pname, int32* output ) );
INFI_FUNCTION( void, InfiGLGetProgramInfoLog, ( uint32 prog, uint32 maxlen, int32* len, char* output ) );
INFI_FUNCTION( void, InfiGLGetShaderiv, ( uint32 shad, GLenum pname, int32* output ) );
INFI_FUNCTION( void, InfiGLGetShaderInfoLog, ( uint32 shad, uint32 maxlen, int32* len, char* output ) );
INFI_FUNCTION( void, InfiGLLinkProgram, ( uint32 prog ) );
INFI_FUNCTION( void, InfiGLShaderSource, ( uint32 shad, uint32 count, const char** str, const int32* length ) );
INFI_FUNCTION( void, InfiGLUseProgram, ( uint32 prog ) );

// shader uniforms
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, float32 a ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, float32 a, float32 b ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, float32 a, float32 b, float32 c ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, float32 a, float32 b, float32 c, float32 d ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, const core::vec2& v ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, const core::vec3& v ) );
INFI_FUNCTION( void, InfiGLUniformf, ( uint32 location, const core::vec4& v ) );
INFI_FUNCTION( void, InfiGLUniformfv, ( uint32 location, uint32 c, const float32* a ) );
INFI_FUNCTION( void, InfiGLUniformfv, ( uint32 location, uint32 c, const core::vec2* v ) );
INFI_FUNCTION( void, InfiGLUniformfv, ( uint32 location, uint32 c, const core::vec3* v ) );
INFI_FUNCTION( void, InfiGLUniformfv, ( uint32 location, uint32 c, const core::vec4* v ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, int32 a ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, int32 a, int32 b ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, int32 a, int32 b, int32 c ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, int32 a, int32 b, int32 c, int32 d ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, const core::vec2i& v ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, const core::vec3i& v ) );
INFI_FUNCTION( void, InfiGLUniformi, ( uint32 location, const core::vec4i& v ) );
INFI_FUNCTION( void, InfiGLUniformiv, ( uint32 location, uint32 c, const int32* a ) );
INFI_FUNCTION( void, InfiGLUniformiv, ( uint32 location, uint32 c, const core::vec2i* v ) );
INFI_FUNCTION( void, InfiGLUniformiv, ( uint32 location, uint32 c, const core::vec3i* v ) );
INFI_FUNCTION( void, InfiGLUniformiv, ( uint32 location, uint32 c, const core::vec4i* v ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, uint32 a ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, uint32 a, uint32 b ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, uint32 a, uint32 b, uint32 c ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, uint32 a, uint32 b, uint32 c, uint32 d ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, const core::vec2ui& v ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, const core::vec3ui& v ) );
INFI_FUNCTION( void, InfiGLUniformui, ( uint32 location, const core::vec4ui& v ) );
INFI_FUNCTION( void, InfiGLUniformuiv, ( uint32 location, uint32 c, const uint32* a ) );
INFI_FUNCTION( void, InfiGLUniformuiv, ( uint32 location, uint32 c, const core::vec2ui* v ) );
INFI_FUNCTION( void, InfiGLUniformuiv, ( uint32 location, uint32 c, const core::vec3ui* v ) );
INFI_FUNCTION( void, InfiGLUniformuiv, ( uint32 location, uint32 c, const core::vec4ui* v ) );
INFI_FUNCTION( void, InfiGLUniform, ( uint32 location, const core::mat2& m ) );
INFI_FUNCTION( void, InfiGLUniform, ( uint32 location, const core::mat3& m ) );
INFI_FUNCTION( void, InfiGLUniform, ( uint32 location, const core::mat4& m ) );
INFI_FUNCTION( void, InfiGLUniformv, ( uint32 location, uint32 count, const core::mat2* m ) );
INFI_FUNCTION( void, InfiGLUniformv, ( uint32 location, uint32 count, const core::mat3* m ) );
INFI_FUNCTION( void, InfiGLUniformv, ( uint32 location, uint32 count, const core::mat4* m ) );

// blending functions
INFI_FUNCTION( void, InfiGLBlendColor, ( float32 r, float32 g, float32 b, float32 a ) );
INFI_FUNCTION( void, InfiGLBlendEquation, ( GLenum mode ) );
INFI_FUNCTION( void, InfiGLBlendEquationSeparate, ( GLenum modea, GLenum modec ) );
INFI_FUNCTION( void, InfiGLBlendFunc, ( GLenum sfactor, GLenum dfactor ) );
INFI_FUNCTION( void, InfiGLBlendFuncSeparate, ( GLenum sc, GLenum dc, GLenum sa, GLenum da ) );

// buffer control functions
INFI_FUNCTION( void, InfiGLBindBuffer, ( uint32 buf, uint32 obj ) );
INFI_FUNCTION( void, InfiGLBindBufferBase, ( uint32 buf, uint32 slot, uint32 obj ) );
INFI_FUNCTION( void, InfiGLBufferData, ( GLenum buf, uint32 sz, const void* data, GLenum readtype ) );
INFI_FUNCTION( void, InfiGLBufferSubData, ( GLenum buf, uint32 offset, uint32 size, const void* data ) );
INFI_FUNCTION( void, InfiGLCopyBufferSubData, ( GLenum r, GLenum w, int32 roff, int32 woff, int32 sz ) );
INFI_FUNCTION( void, InfiGLDeleteBuffers, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLGenBuffers, ( uint32 count, uint32* output ) );
INFI_FUNCTION( void, InfiGLGetBufferSubData, ( GLenum target, int32 offset, int32 size, void* output ) );
INFI_FUNCTION( void*, InfiGLMapBuffer, ( GLenum target, GLenum access ) );
INFI_FUNCTION( void*, InfiGLMapBufferRange, ( GLenum target, int32 offset, uint32 length, GLbitfield access ) );
INFI_FUNCTION( void, InfiGLUnmapBuffer, ( GLenum target ) );

// framebuffer control functions
INFI_FUNCTION( GLenum, InfiGLCheckFramebufferStatus, () );
INFI_FUNCTION( GLenum, InfiGLCheckFramebufferReadStatus, () );
INFI_FUNCTION( GLenum, InfiGLCheckFramebufferDrawStatus, () );

INFI_FUNCTION( void, InfiGLBindFramebuffer, ( uint32 obj ) );
INFI_FUNCTION( void, InfiGLBindFramebufferDraw, ( uint32 obj ) );
INFI_FUNCTION( void, InfiGLBindFramebufferRead, ( uint32 obj ) );
INFI_FUNCTION( void, InfiGLBlitFramebuffer, ( int32 srcx0, int32 srcy0, int32 srcx1, int32 srcy1, int32 dstx0, int32 dsty0, int32 dstx1, int32 dsty1, uint32 mask, GLenum filter ) );
INFI_FUNCTION( void, InfiGLClear, ( GLenum channels ) );
INFI_FUNCTION( void, InfiGLClearColor, ( float32 r, float32 g, float32 b, float32 a ) );
INFI_FUNCTION( void, InfiGLDeleteFramebuffers, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLDrawBuffer, ( GLenum buf ) );
INFI_FUNCTION( void, InfiGLDrawBuffers, ( uint32 count, GLenum* buffers ) );
INFI_FUNCTION( void, InfiGLFramebufferTexture, ( GLenum attachment, uint32 tex, int32 level ) );
INFI_FUNCTION( void, InfiGLFramebufferTextureDraw, ( GLenum attachment, uint32 tex, int32 level ) );
INFI_FUNCTION( void, InfiGLFramebufferTextureRead, ( GLenum attachment, uint32 tex, int32 level ) );
INFI_FUNCTION( void, InfiGLGenFramebuffers, ( uint32 count, uint32* output ) );

INFI_FUNCTION( void, InfiGLBindRenderbuffer, ( uint32 obj ) );
INFI_FUNCTION( void, InfiGLDeleteRenderbuffers, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLFramebufferRenderbuffer, ( GLenum attachment, uint32 buffer ) );
INFI_FUNCTION( void, InfiGLFramebufferRenderbufferDraw, ( GLenum attachment, uint32 buffer ) );
INFI_FUNCTION( void, InfiGLFramebufferRenderbufferRead, ( GLenum attachment, uint32 buffer ) );
INFI_FUNCTION( void, InfiGLGenRenderbuffers, ( uint32 count, uint32* output ) );
INFI_FUNCTION( void, InfiGLRenderbufferStorage, ( GLenum format, uint32 width, uint32 height ) );
INFI_FUNCTION( void, InfiGLRenderbufferStorageMultisample, ( uint32 samples, GLenum format, uint32 width, uint32 height ) );

// vertex array functions
INFI_FUNCTION( void, InfiGLDisableVertexAttribArray, ( uint32 chan ) );
INFI_FUNCTION( void, InfiGLDrawArrays, ( GLenum style, uint32 start, uint32 count ) );
INFI_FUNCTION( void, InfiGLDrawArraysInstanced, ( GLenum style, uint32 start, uint32 count, uint32 prim ) );
INFI_FUNCTION( void, InfiGLDrawElements, ( GLenum style, uint32 count, GLenum type, void* offset ) );
INFI_FUNCTION( void, InfiGLDrawElementsBaseVertex, ( GLenum style, uint32 count, GLenum type, void* offset, uint32 base ) );
INFI_FUNCTION( void, InfiGLDrawElementsInstanced, ( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim ) );
INFI_FUNCTION( void, InfiGLDrawElementsInstancedBaseVertex, ( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim, uint32 base ) );
INFI_FUNCTION( void, InfiGLEnableVertexAttribArray, ( uint32 chan ) );
INFI_FUNCTION( void, InfiGLVertexAttribPointer, ( uint32 index, int32 sz, GLenum type, bool normalized, uint32 stride, void* offset ) );

INFI_FUNCTION( void, InfiGLBindVertexArray, ( uint32 obj ) );
INFI_FUNCTION( void, InfiGLDeleteVertexArrays, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLGenVertexArrays, ( uint32 count, uint32* objs ) );

// transform feedback functions
INFI_FUNCTION( void, InfiGLBeginTransformFeedback, ( GLenum style ) );
INFI_FUNCTION( void, InfiGLEndTransformFeedback, () );
INFI_FUNCTION( void, InfiGLTransformFeedbackVaryings, ( uint32 prog, uint32 count, const char** str, GLenum mode ) );

// query objects
INFI_FUNCTION( void, InfiGLBeginQuery, ( GLenum type, uint32 query ) );
INFI_FUNCTION( void, InfiGLDeleteQueries, ( uint32 count, const uint32* objs ) );
INFI_FUNCTION( void, InfiGLEndQuery, ( GLenum type ) );
INFI_FUNCTION( void, InfiGLGenQueries, ( uint32 count, uint32* objs ) );
INFI_FUNCTION( void, InfiGLGetQueryObjectiv, ( uint32 query, GLenum type, int32* output ) );
INFI_FUNCTION( void, InfiGLGetQueryObjectuiv, ( uint32 query, GLenum type, uint32* output ) );

// depth stencil functions
INFI_FUNCTION( void, InfiGLColorMask, ( bool r, bool g, bool b, bool a ) );
INFI_FUNCTION( void, InfiGLColorMask, ( bool rgba ) );
INFI_FUNCTION( void, InfiGLDepthFunc, ( GLenum mode ) );
INFI_FUNCTION( void, InfiGLDepthMask, ( bool active ) );
INFI_FUNCTION( void, InfiGLStencilFunc, ( GLenum func, int32 ref, uint32 mask ) );
INFI_FUNCTION( void, InfiGLStencilFuncSeparate, ( GLenum face, GLenum func, int32 ref, uint32 mask ) );
INFI_FUNCTION( void, InfiGLStencilMask, ( uint32 mask ) );
INFI_FUNCTION( void, InfiGLStencilMaskSeparate, ( GLenum face, uint32 mask ) );
INFI_FUNCTION( void, InfiGLStencilOp, ( GLenum sfail, GLenum dpfail, GLenum dppass ) );
INFI_FUNCTION( void, InfiGLStencilOpSeparate, ( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass ) );

// misc functions
INFI_FUNCTION( const uint8*, InfiGLGetString, ( GLenum name ) );
INFI_FUNCTION( const uint8*, InfiGLGetStringi, ( GLenum name, uint32 index ) );
INFI_FUNCTION( bool, InfiGLIsEnabled, ( GLenum cap ) );

INFI_FUNCTION( void, InfiGLDisable, ( GLenum elem ) );
INFI_FUNCTION( void, InfiGLEnable, ( GLenum elem ) );
INFI_FUNCTION( void, InfiGLFlush, () );
INFI_FUNCTION( void, InfiGLFinish, () );
INFI_FUNCTION( void, InfiGLGetFloatv, ( GLenum pname, float32* output ) );
INFI_FUNCTION( void, InfiGLGetIntegerv, ( GLenum pname, int32* output ) );
INFI_FUNCTION( void, InfiGLPointSize, ( float32 size ) );
INFI_FUNCTION( void, InfiGLShadeModel, ( GLenum mode ) );
INFI_FUNCTION( void, InfiGLViewport, ( const core::rect& ) );
INFI_FUNCTION( void, InfiGLViewport, ( int32 x, int32 y, uint32 w, uint32 h ) );

} }

#endif//__INFI_OPENGL_WRAPPER_H__