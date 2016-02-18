#include <fstream>
#include <iomanip>

#include "main/infi_gl.h"
#include "main/infi_error.h"
#include "main/infi_time.h"
#include "render/infi_gl_wrapper.h"

namespace INFI {
namespace render {
	
namespace {
	using namespace std;
	using namespace core;
}

static std::ofstream gloutput( "opengl_trace.log" );
static bool trace_on; // EMIYAAAAAAAAAAA SHIROUUUUUUUUUU
void InfiGLActivateTrace() {
	trace_on = true;
	gloutput << " --- ENABLED GL TRACE @ " << InfiGetProgramTime() << " -----------------" << endl;
	gloutput << "          TIME | OPERATION" << endl;
}
void InfiGLDeactivateTrace() {
	trace_on = false;
	gloutput << " --- DISABLED GL TRACE @ " << InfiGetProgramTime() << " ----------------" << endl;
}
void InfiGLSendMessage( const string_t& msg ) {
	if ( trace_on )
		gloutput << std::fixed << std::setprecision( 8 ) << std::setw(14) << InfiGetProgramTime() << " | " << msg << endl;
}
void InfiGLSendWhitespace( uint32 lines ) {
	if ( trace_on ) {
		for ( uint32 i=0;i<lines;i++ )
			gloutput << endl;
	}
}

#define __INFI_GL_WRAPPER_ERROR_CHECK__

#ifdef __INFI_GL_WRAPPER_ERROR_CHECK__
	#define __GL_switch_clause( ostr, name ) \
	if ( trace_on ) { \
		GLuint st; \
		ostr << std::fixed << std::setprecision( 8 ) << std::setw(14) << InfiGetProgramTime() << " | "; \
		if ( (st=glGetError()) != GL_NO_ERROR ) \
			switch( st ) { \
				case GL_INVALID_ENUM: \
					ostr << name << " : invalid enumerator" << endl; \
					break; \
				case GL_INVALID_VALUE: \
					ostr << name << " : invalid value" << endl; \
					break; \
				case GL_INVALID_OPERATION: \
					ostr << name << " : invalid operation" << endl; \
					break; \
				case GL_INVALID_FRAMEBUFFER_OPERATION: \
					ostr << name << " : invalid framebuffer operation" << endl; \
					break; \
				case GL_OUT_OF_MEMORY: \
					ostr << name << " : out of memory" << endl; \
					break; \
				case GL_STACK_UNDERFLOW: \
					ostr << name << " : stack underflow" << endl; \
					break; \
				case GL_STACK_OVERFLOW: \
					ostr << name << " : stack overflow" << endl; \
					break; \
				default: \
					ostr << name << " : unknown error" << endl; \
					break; \
			} \
		else ostr << name << endl; \
	}
	
	#define __GL_error( ostr, name ) \
		__GL_switch_clause( ostr, #name "()" );
	#define __GL_error1( ostr, name, arg0 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ")" );
	#define __GL_error2( ostr, name, arg0, arg1 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ")" );
	#define __GL_error3( ostr, name, arg0, arg1, arg2 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ")" );
	#define __GL_error4( ostr, name, arg0, arg1, arg2, arg3 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ")" );
	#define __GL_error5( ostr, name, arg0, arg1, arg2, arg3, arg4 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ")" );
	#define __GL_error6( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ", " << arg5 << ")" );
	#define __GL_error7( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ", " << arg5 << ", " << arg6 << ")" );
	#define __GL_error8( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ", " << arg5 << ", " << arg6 << ", " << arg7 << ")" );
	#define __GL_error9( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ", " << arg5 << ", " << arg6 << ", " << arg7 << ", " << arg8 << ")" );
	#define __GL_error10( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 ) \
		__GL_switch_clause( ostr, #name "(" << arg0 << ", " << arg1 << ", " << arg2 << ", " << arg3 << ", " << arg4 << ", " << arg5 << ", " << arg6 << ", " << arg7 << ", " << arg8 << ", " << arg9 << ")" );
#else
	#define __GL_error( ostr, name )
	#define __GL_error1( ostr, name, arg0 )
	#define __GL_error2( ostr, name, arg0, arg1 )
	#define __GL_error3( ostr, name, arg0, arg1, arg2 )
	#define __GL_error4( ostr, name, arg0, arg1, arg2, arg3 )
	#define __GL_error5( ostr, name, arg0, arg1, arg2, arg3, arg4 )
	#define __GL_error6( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5 )
	#define __GL_error7( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6 )
	#define __GL_error8( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7 )
	#define __GL_error9( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8 )
	#define __GL_error10( ostr, name, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9 )
#endif//__INFI_GL_WRAPPER_ERROR_CHECK__

void InfiGLUnmapBuffer( GLenum target ) {
	glUnmapBuffer( target );
	__GL_error1( gloutput, glUnmapBuffer, infigl_enum( target ) );
}
void* InfiGLMapBuffer( GLenum target, GLenum access ) {
	void* tmp = glMapBuffer( target, access );
	__GL_error2( gloutput, glMapBuffer, infigl_enum( target ), access );
	return tmp;
}
void* InfiGLMapBufferRange( GLenum target, int32 offset, uint32 length, GLbitfield access ) {
	void* tmp = glMapBufferRange( target, offset, length, access );
	__GL_error4( gloutput, glMapBufferRange, infigl_enum( target ), offset, length, access );
	return tmp;
}

void InfiGLFlush() {
	glFlush();
	__GL_error( gloutput, glFlush );
}
void InfiGLFinish() {
	glFinish();
	__GL_error( gloutput, glFinish );
}
		
void InfiGLBindVertexArray( uint32 obj ) {
	glBindVertexArray( obj );
	__GL_error1( gloutput, glBindVertexArray, obj );
}
void InfiGLDeleteVertexArrays( uint32 count, uint32* objs ) {
	glDeleteVertexArrays( count, objs );
	__GL_error2( gloutput, glDeleteVertexArrays, count, objs );
}
void InfiGLGenVertexArrays( uint32 count, uint32* objs ) {
	glGenVertexArrays( count, objs );
	__GL_error2( gloutput, glGenVertexArrays, count, objs );
}
void InfiGLBindRenderbuffer( uint32 obj ) {
	glBindRenderbuffer( GL_RENDERBUFFER, obj );
	__GL_error1( gloutput, glBindRenderbuffer, obj );
}
void InfiGLDeleteRenderbuffers( uint32 count, uint32* objs ) {
	glDeleteRenderbuffers( count, objs );
	__GL_error2( gloutput, glDeleteRenderbuffers, count, objs );
}
void InfiGLFramebufferRenderbuffer( GLenum attachment, uint32 buffer ) {
	glFramebufferRenderbuffer( GL_FRAMEBUFFER, attachment, GL_RENDERBUFFER, buffer );
	__GL_error2( gloutput, glFramebufferRenderbuffer, infigl_enum( attachment ), buffer );
}
void InfiGLFramebufferRenderbufferDraw( GLenum attachment, uint32 buffer ) {
	glFramebufferRenderbuffer( GL_DRAW_FRAMEBUFFER, attachment, GL_RENDERBUFFER, buffer );
	__GL_error2( gloutput, glFramebufferRenderbufferDraw, infigl_enum( attachment ), buffer );
}
void InfiGLFramebufferRenderbufferRead( GLenum attachment, uint32 buffer ) {
	glFramebufferRenderbuffer( GL_READ_FRAMEBUFFER, attachment, GL_RENDERBUFFER, buffer );
	__GL_error2( gloutput, glFramebufferRenderbufferRead, infigl_enum( attachment ), buffer );
}
void InfiGLGenRenderbuffers( uint32 count, uint32* output ) {
	glGenRenderbuffers( count, output );
	__GL_error2( gloutput, glGenRenderbuffers, count, output );
}
void InfiGLRenderbufferStorage( GLenum format, uint32 width, uint32 height ) {
	glRenderbufferStorage( GL_RENDERBUFFER, format, width, height );
	__GL_error3( gloutput, glRenderbufferStorage, infigl_enum( format ), width, height );
}
void InfiGLRenderbufferStorageMultisample( uint32 samples, GLenum format, uint32 width, uint32 height ) {
	glRenderbufferStorageMultisample( GL_RENDERBUFFER, samples, format, width, height );
	__GL_error4( gloutput, glRenderbufferStorageMultisample, samples, infigl_enum( format ), width, height );
}

void InfiGLBindTextureMultisample( uint32 tex ) {
	glBindTexture( GL_TEXTURE_2D_MULTISAMPLE, tex );
	__GL_error1( gloutput, glBindTextureMultisample, tex );
}
void InfiGLTexImageMultisample( uint32 samples, GLint format, uint32 width, uint32 height, bool fixloc ) {
	glTexImage2DMultisample( GL_TEXTURE_2D_MULTISAMPLE, samples, format, width, height, fixloc );
	__GL_error5( gloutput, glTexImage2DMultisample, samples, format, width, height, fixloc );
}
void InfiGLTexParameterMultisamplef( GLenum pname, float32 param ) {
	glTexParameterf( GL_TEXTURE_2D_MULTISAMPLE, pname, param );
	__GL_error2( gloutput, glTexParameterMultisamplef, infigl_enum( pname ), param );	
}
void InfiGLTexParameterMultisamplef( GLenum pname, const float32* param ) {
	glTexParameterfv( GL_TEXTURE_2D_MULTISAMPLE, pname, param );
	__GL_error2( gloutput, glTexParameterMultisamplefv, infigl_enum( pname ), param );	
}
void InfiGLTexParameterMultisamplei( GLenum pname, int32 param ) {
	glTexParameteri( GL_TEXTURE_2D_MULTISAMPLE, pname, param );
	__GL_error2( gloutput, glTexParameterMultisamplei, infigl_enum( pname ), param );	
}
void InfiGLTexParameterMultisamplei( GLenum pname, int32* param ) {
	glTexParameteriv( GL_TEXTURE_2D_MULTISAMPLE, pname, param );
	__GL_error2( gloutput, glTexParameterMultisampleiv, infigl_enum( pname ), param );	
}

void InfiGLGenQueries( uint32 count, uint32* objs ) {
	glGenQueries( count, objs );
	__GL_error2( gloutput, glGenQueries, count, objs );
}
void InfiGLDeleteQueries( uint32 count, const uint32* objs ) {
	glDeleteQueries( count, objs );
	__GL_error2( gloutput, glDeleteQueries, count, objs );
}
void InfiGLBeginQuery( GLenum type, uint32 query ) {
	glBeginQuery( type, query );
	__GL_error2( gloutput, glBeginQueries, infigl_enum( type ), query );
}
void InfiGLEndQuery( GLenum type ) {
	glEndQuery( type );
	__GL_error1( gloutput, glEndQuery, infigl_enum( type ) );
}
void InfiGLGetQueryObjectiv( uint32 query, GLenum type, int32* output ) {
	glGetQueryObjectiv( query, type, output );
	__GL_error3( gloutput, glGetQueryObjectiv, query, infigl_enum( type ), output );
}
void InfiGLGetQueryObjectuiv( uint32 query, GLenum type, uint32* output ) {
	glGetQueryObjectuiv( query, type, output );
	__GL_error3( gloutput, glGetQueryObjectuiv, query, infigl_enum( type ), output );
}
		
void InfiGLBindFragDataLocation( uint32 prog, uint32 count, const char* fragname ) {
	glBindFragDataLocation( prog, count, fragname );
	__GL_error3( gloutput, glBindFragDataLocation, prog, count, fragname );
}
int32 InfiGLGetFragDataLocation( uint32 prog, const char* fragname ) {
	int32 tmp = glGetFragDataLocation( prog, fragname );
	__GL_error2( gloutput, glGetFragDataLocation, prog, fragname );
	return tmp;
}
void InfiGLDrawBuffer( GLenum buf ) {
	glDrawBuffer( buf );
	__GL_error1( gloutput, glDrawBuffer, infigl_enum( buf ) );
}
void InfiGLDrawBuffers( uint32 count, GLenum* buffers ) {
	glDrawBuffers( count, buffers );
	__GL_error2( gloutput, glDrawBuffers, count, buffers );
}

void InfiGLActiveTexture( uint32 tex ) {
	glActiveTexture( GL_TEXTURE0 + tex );
	__GL_error1( gloutput, glActiveTexture, tex );
}
void InfiGLAttachShader( uint32 prog, uint32 comp ) { 
	glAttachShader( prog, comp );
	__GL_error2( gloutput, glAttachShader, prog, comp );
}
void InfiGLBeginTransformFeedback( GLenum style ) { 
	glBeginTransformFeedback( style ); 
	__GL_error1( gloutput, glBeginTransformFeedback, infigl_enum( style ) );
}
void InfiGLBlendColor( float32 r, float32 g, float32 b, float32 a ) { 
	glBlendColor( r,g,b,a ); 
	__GL_error4( gloutput, glBlendColor, r, g, b, a );
}
void InfiGLBlendEquation( GLenum mode ) { 
	glBlendEquation( mode ); 
	__GL_error1( gloutput, glBlendEquation, infigl_enum( mode ) );
}
void InfiGLBlendEquationSeparate( GLenum modea, GLenum modec ) { 
	glBlendEquationSeparate( modea, modec );
	__GL_error2( gloutput, glBlendEquationSeparate, infigl_enum( modea ), infigl_enum( modec ) );
}
void InfiGLBlendFunc( GLenum sfactor, GLenum dfactor ) { 
	glBlendFunc( sfactor, dfactor ); 
	__GL_error2( gloutput, glBlendFunc, sfactor, dfactor );
}
void InfiGLBlendFuncSeparate( GLenum sc, GLenum dc, GLenum sa, GLenum da ) { 
	glBlendFuncSeparate( sc, dc, sa, da ); 
	__GL_error4( gloutput, glBlendFuncSeparate, infigl_enum( sc ), infigl_enum( dc ), infigl_enum( sa ), infigl_enum( da ) );
}
void InfiGLBindAttribLocation( uint32 prog, uint32 attrib, const char* str ) { 
	glBindAttribLocation( prog, attrib, str ); 
	__GL_error3( gloutput, glBindAttribLocation, prog, attrib, str );
}
void InfiGLBindBuffer( uint32 buf, uint32 obj ) { 
	glBindBuffer( buf, obj ); 
	__GL_error2( gloutput, glBindBuffer, buf, obj );
}
void InfiGLBindBufferBase( uint32 buf, uint32 slot, uint32 obj ) { 
	glBindBufferBase( buf, slot, obj ); 
	__GL_error3( gloutput, glBindBufferBase, buf, slot, obj );
} 
void InfiGLBindFramebuffer( uint32 obj ) { 
	glBindFramebuffer( GL_FRAMEBUFFER, obj );
	__GL_error1( gloutput, glBindFramebuffer, obj );
}
void InfiGLBindFramebufferDraw( uint32 obj ) { 
	glBindFramebuffer( GL_DRAW_FRAMEBUFFER, obj );
	__GL_error1( gloutput, glBindFramebuffer_DRAW, obj );
}
void InfiGLBindFramebufferRead( uint32 obj ) {
	glBindFramebuffer( GL_READ_FRAMEBUFFER, obj );
	__GL_error1( gloutput, glBindFramebuffer_READ, obj );
}
void InfiGLBlitFramebuffer( int32 srcx0, int32 srcy0, int32 srcx1, int32 srcy1, int32 dstx0, int32 dsty0, int32 dstx1, int32 dsty1, uint32 mask, GLenum filter ) {
	glBlitFramebuffer( srcx0, srcy0, srcx1, srcy1, dstx0, dsty0, dstx1, dsty1, mask, filter );
	__GL_error10( gloutput, glBlitFramebuffer, srcx0, srcy0, srcx1, srcy1, dstx0, dsty0, dstx1, dsty1, mask, filter );
}
void InfiGLBindTexture( uint32 tex ) { 
	glBindTexture( GL_TEXTURE_2D, tex ); 
	__GL_error1( gloutput, glBindTexture, tex );
}
void InfiGLBufferData( GLenum buf, uint32 sz, const void* data, GLenum readtype ) { 
	glBufferData( buf, sz, data, readtype ); 
	__GL_error4( gloutput, glBufferData, infigl_enum( buf ), sz, data, infigl_enum( readtype ) );
}
void InfiGLBufferSubData( GLenum buf, uint32 offset, uint32 size, const void* data ) { 
	glBufferSubData( buf, offset, size, data ); 
	__GL_error4( gloutput, glBufferData, infigl_enum( buf ), offset, size, data );
}
GLenum InfiGLCheckFramebufferStatus() { 
	GLenum tmp = glCheckFramebufferStatus( GL_FRAMEBUFFER );
	__GL_error( gloutput, glCheckFramebufferStatus );
	return tmp;
}
GLenum InfiGLCheckFramebufferReadStatus() {
	GLenum tmp = glCheckFramebufferStatus( GL_DRAW_FRAMEBUFFER );
	__GL_error( gloutput, glCheckFramebufferStatus_READ );
	return tmp;
}
GLenum InfiGLCheckFramebufferDrawStatus() {
	GLenum tmp = glCheckFramebufferStatus( GL_READ_FRAMEBUFFER );
	__GL_error( gloutput, glCheckFramebufferStatus_DRAW );
	return tmp;
}
void InfiGLClear( GLenum channels ) { 
	glClear( channels ); 
	__GL_error1( gloutput, glClear, infigl_enum( channels ) );
}
void InfiGLClearColor( float32 r, float32 g, float32 b, float32 a ) { 
	glClearColor( r,g,b,a ); 
	__GL_error4( gloutput, glClearColor, r, g, b, a );
}
void InfiGLCompileShader( uint32 shader ) { 
	glCompileShader( shader ); 
	__GL_error1( gloutput, glCompileShader, shader );
}
void InfiGLCopyBufferSubData( GLenum r, GLenum w, int32 roff, int32 woff, int32 sz ) { 
	glCopyBufferSubData(r,w,roff,woff,sz); 
	__GL_error5( gloutput, glCopyBufferSubData, infigl_enum( r ), infigl_enum( w ), roff, woff, sz );
}
uint32 InfiGLCreateProgram() { 
	uint32 tmp = glCreateProgram(); 
	__GL_error( gloutput, glCreateProgram );
	return tmp;
}
uint32 InfiGLCreateShader( GLenum type ) {
	uint32 tmp = glCreateShader( type );
	__GL_error1( gloutput, glCreateShader, infigl_enum( type ) );
	return tmp;
}
void InfiGLDeleteBuffers( uint32 count, uint32* objs ) {
	glDeleteBuffers( count, objs );
	__GL_error2( gloutput, glDeleteBuffers, count, objs );
}
void InfiGLDeleteFramebuffers( uint32 count, uint32* objs ) {
	glDeleteFramebuffers( count, objs );
	__GL_error2( gloutput, glDeleteFramebuffers, count, objs );
}
void InfiGLDeleteProgram( uint32 prog ) {
	glDeleteProgram( prog );
	__GL_error1( gloutput, glDeleteProgram, prog );
}
void InfiGLDeleteShader( uint32 shader ) {
	glDeleteShader( shader );
	__GL_error1( gloutput, glDeleteShader, shader );
}
void InfiGLDeleteTextures( uint32 count, uint32* objs ) {
	glDeleteTextures( count, objs );
	__GL_error2( gloutput, glDeleteTextures, count, objs );
}
void InfiGLDetachShader( uint32 prog, uint32 shader ) {
	glDetachShader( prog, shader );
	__GL_error2( gloutput, glDetachShader, prog, shader );
}
void InfiGLDepthFunc( GLenum mode ) {
	glDepthFunc( mode );
	__GL_error1( gloutput, glDepthFunc, infigl_enum( mode ) );
}
void InfiGLColorMask( bool r, bool g, bool b, bool a ) {
	glColorMask( r,g,b,a );
	__GL_error4( gloutput, glColorMask, r, g, b, a );
}
void InfiGLColorMask( bool rgba ) {
	glColorMask( rgba,rgba,rgba,rgba );
	__GL_error4( gloutput, glColorMask, rgba, rgba, rgba, rgba );
}
void InfiGLDepthMask( bool active ) {
	glDepthMask( active );
	__GL_error1( gloutput, glDepthMask, active );
}
void InfiGLStencilFunc( GLenum func, int32 ref, uint32 mask ) {
	glStencilFunc( func, ref, mask );
	__GL_error3( gloutput, glStencilFunc, infigl_enum( func ), ref, mask );
}
void InfiGLStencilFuncSeparate( GLenum face, GLenum func, int32 ref, uint32 mask ) {
	glStencilFuncSeparate( face, func, ref, mask );
	__GL_error4( gloutput, glStencilFuncSeparate, infigl_enum( face ), infigl_enum( func ), ref, mask );
}
void InfiGLStencilMask( uint32 mask ) {
	glStencilMask( mask );
	__GL_error1( gloutput, glStencilMask, mask );
}
void InfiGLStencilMaskSeparate( GLenum face, uint32 mask ) {
	glStencilMaskSeparate( face, mask );
	__GL_error2( gloutput, glStencilMaskSeparate, infigl_enum( face ), mask );
}
void InfiGLStencilOp( GLenum sfail, GLenum dpfail, GLenum dppass ) {
	glStencilOp( sfail, dpfail, dppass );
	__GL_error3( gloutput, glStencilOp, infigl_enum( sfail ), infigl_enum( dpfail ), infigl_enum( dppass ) );
}
void InfiGLStencilOpSeparate( GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass ) {
	glStencilOpSeparate( face, sfail, dpfail, dppass );
	__GL_error4( gloutput, glStencilOpSeparate, infigl_enum( face ), infigl_enum( sfail ), infigl_enum( dpfail ), infigl_enum( dppass ) );
}
void InfiGLDisable( GLenum elem ) {
	glDisable( elem );
	__GL_error1( gloutput, glDisable, infigl_enum( elem ) );
}
void InfiGLDisableVertexAttribArray( uint32 chan ) {
	glDisableVertexAttribArray( chan );
	__GL_error1( gloutput, glDisableVertexAttribArray, chan );
}
void InfiGLDrawArrays( GLenum style, uint32 start, uint32 count ) {
	glDrawArrays( style, start, count );
	__GL_error3( gloutput, glDrawArrays, infigl_enum( style ), start, count );
}
void InfiGLDrawArraysInstanced( GLenum style, uint32 start, uint32 count, uint32 prim ) {
	glDrawArraysInstanced( style, start, count, prim );
	__GL_error4( gloutput, glDrawArraysInstanced, infigl_enum( style ), start, count, prim );
}
void InfiGLDrawElements( GLenum style, uint32 count, GLenum type, void* offset ) {
	glDrawElements( style, count, type, offset );
	__GL_error4( gloutput, glDrawElements, infigl_enum( style ), count, infigl_enum( type ), offset );
}
void InfiGLDrawElementsBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 base ) {
	glDrawElementsBaseVertex( style, count, type, offset, base );
	__GL_error5( gloutput, glDrawElementsBaseVertex, infigl_enum( style ), count, infigl_enum( type ), offset, base );
}
void InfiGLDrawElementsInstanced( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim ) {
	glDrawElementsInstanced( style, count, type, offset, prim );
	__GL_error5( gloutput, glDrawElementsInstanced, infigl_enum( style ), count, infigl_enum( type ), offset, prim );
}
void InfiGLDrawElementsInstancedBaseVertex( GLenum style, uint32 count, GLenum type, void* offset, uint32 prim, uint32 base ) {
	glDrawElementsInstancedBaseVertex( style, count, type, offset, prim, base );
	__GL_error6( gloutput, glDrawElementsInstancedBaseVertex, infigl_enum( style ), count, infigl_enum( type ), offset, prim, base );
}
void InfiGLEnable( GLenum elem ) {
	glEnable( elem );
	__GL_error1( gloutput, glEnable, infigl_enum( elem ) );
}
void InfiGLEnableVertexAttribArray( uint32 chan ) {
	glEnableVertexAttribArray( chan );
	__GL_error1( gloutput, glEnableVertexAttribArray, chan );
}
void InfiGLEndTransformFeedback() {
	glEndTransformFeedback();
	__GL_error( gloutput, glEndTransformFeedback );
}
void InfiGLFramebufferTexture( GLenum attachment, uint32 tex, int32 level ) {
	glFramebufferTexture( GL_FRAMEBUFFER, attachment, tex, level );
	__GL_error3( gloutput, glFramebufferTexture, infigl_enum( attachment ), tex, level );
}
void InfiGLFramebufferTextureDraw( GLenum attachment, uint32 tex, int32 level ) {
	glFramebufferTexture( GL_DRAW_FRAMEBUFFER, attachment, tex, level );
	__GL_error3( gloutput, glFramebufferTextureDraw, infigl_enum( attachment ), tex, level );
}
void InfiGLFramebufferTextureRead( GLenum attachment, uint32 tex, int32 level ) {
	glFramebufferTexture( GL_READ_FRAMEBUFFER, attachment, tex, level );
	__GL_error3( gloutput, glFramebufferTextureRead, infigl_enum( attachment ), tex, level );
}
void InfiGLGetFloatv( GLenum pname, float32* output ) {
	glGetFloatv( pname, output );
	__GL_error2( gloutput, glGetFloatv, infigl_enum( pname ), output );
}
void InfiGLGetIntegerv( GLenum pname, int32* output ) {
	glGetIntegerv( pname, output );
	__GL_error2( gloutput, glGetIntegerv, infigl_enum( pname ), output );
}
void InfiGLGetProgramiv( uint32 prog, GLenum pname, int32* output ) {
	glGetProgramiv( prog, pname, output );
	__GL_error3( gloutput, glGetProgramiv, prog, infigl_enum( pname ), output );
}
void InfiGLGetProgramInfoLog( uint32 prog, uint32 maxlen, int32* len, char* output ) {
	glGetProgramInfoLog( prog, maxlen, len, output );
	__GL_error4( gloutput, glGetProgramInfoLog, prog, maxlen, len, (void*)output );
}
void InfiGLGetShaderiv( uint32 shad, GLenum pname, int32* output ) {
	glGetShaderiv( shad, pname, output );
	__GL_error3( gloutput, glGetShaderiv, shad, infigl_enum( pname ), output );
}
void InfiGLGetShaderInfoLog( uint32 shad, uint32 maxlen, int32* len, char* output ) {
	glGetShaderInfoLog( shad, maxlen, len, output );
	__GL_error4( gloutput, glGetShaderInfoLog, shad, maxlen, len, (void*)output );
}
const uint8* InfiGLGetString( GLenum name ) {
	const uint8* tmp = glGetString( name );
	__GL_error1( gloutput, glGetString, infigl_enum( name ) );
	return tmp;
}
const uint8* InfiGLGetStringi( GLenum name, uint32 index ) {
	const uint8* tmp = glGetStringi( name, index );
	__GL_error2( gloutput, glGetStringi, infigl_enum( name ), index );
	return tmp;
}
void InfiGLGenBuffers( uint32 count, uint32* output ) {
	glGenBuffers( count, output );
	__GL_error2( gloutput, glGenBuffers, count, output );
}
void InfiGLGenerateMipmap() {
	glGenerateMipmap( GL_TEXTURE_2D );
	__GL_error( gloutput, glGenerateMipmap );
}
void InfiGLGenTextures( uint32 count, uint32* output ) {
	glGenTextures( count, output );
	__GL_error2( gloutput, glGenTextures, count, output );
}
void InfiGLGenFramebuffers( uint32 count, uint32* output ) {
	glGenFramebuffers( count, output );
	__GL_error2( gloutput, glGenFramebuffers, count, output );
}
int32 InfiGLGetAttribLocation( uint32 prog, const char* name ) {
	int32 tmp = glGetAttribLocation( prog, name );
	__GL_error2( gloutput, glGetAttribLocation, prog, name );
	return tmp;
}
void InfiGLGetBufferSubData( GLenum target, int32 offset, int32 size, void* output ) {
	glGetBufferSubData( target, offset, size, output );
	__GL_error4( gloutput, glGetBufferSubData, infigl_enum( target ), offset, size, output );
}
void InfiGLGetTexImage( int32 level, GLenum format, GLenum type, void* pixels ) {
	glGetTexImage( GL_TEXTURE_2D, level, format, type, pixels );
	__GL_error4( gloutput, glGetTexImage, level, infigl_enum( format ), infigl_enum( type ), pixels );
}
int32 InfiGLGetUniformLocation( uint32 prog, const char* name ) {
	int32 tmp = glGetUniformLocation( prog, name );
	__GL_error2( gloutput, glGetUniformLocation, prog, name );
	return tmp;
}
bool InfiGLIsEnabled( GLenum cap ) {
	bool tmp = glIsEnabled( cap );
	__GL_error1( gloutput, glIsEnabled, infigl_enum( cap ) );
	return tmp;
}
void InfiGLLinkProgram( uint32 prog ) {
	glLinkProgram( prog );
	__GL_error1( gloutput, glLinkProgram, prog );
}
void InfiGLPointSize( float32 size ) {
	glPointSize( size );
	__GL_error1( gloutput, glPointSize, size );
}
void InfiGLShadeModel( GLenum mode ) {
	glShadeModel( mode );
	__GL_error1( gloutput, glShadeModel, infigl_enum( mode ) );
}
void InfiGLShaderSource( uint32 shad, uint32 count, const char** str, const int32* length ) {
	glShaderSource( shad, count, str, length );
	__GL_error4( gloutput, glShaderSource, shad, count, str, length );
}
void InfiGLTexImage( int32 level, GLenum internalFormat, uint32 width, uint32 height, GLenum format, GLenum type, const void* data ) {
	glTexImage2D( GL_TEXTURE_2D, level, internalFormat, width, height, 0, format, type, data );
	__GL_error7( gloutput, glTexImage2D, level, infigl_enum( internalFormat ), width, height, infigl_enum( format ), infigl_enum( type ), data );
}
void InfiGLTexParameterf( GLenum pname, float32 param ) {
	glTexParameterf( GL_TEXTURE_2D, pname, param );
	__GL_error2( gloutput, glTexParameterf, infigl_enum( pname ), param );
}
void InfiGLTexParameterf( GLenum pname, float32* param ) {
	glTexParameterfv( GL_TEXTURE_2D, pname, param );
	__GL_error2( gloutput, glTexParameterfv, infigl_enum( pname ), param );
}
void InfiGLTexParameteri( GLenum pname, int32 param ) {
	glTexParameteri( GL_TEXTURE_2D, pname, param );
	__GL_error2( gloutput, glTexParameteri, infigl_enum( pname ), param );
}
void InfiGLTexParameteri( GLenum pname, int32* param ) {
	glTexParameteriv( GL_TEXTURE_2D, pname, param );
	__GL_error2( gloutput, glTexParameteriv, infigl_enum( pname ), param );
}
void InfiGLTexStorage( uint32 levels, GLenum format, uint32 w, uint32 h ) {
	glTexStorage2D( GL_TEXTURE_2D, levels, format, w, h );
	__GL_error4( gloutput, glTexStorage2D, levels, infigl_enum( format ), w, h );
}
void InfiGLTexSubImage( uint32 level, int32 offx, int32 offy, uint32 w, uint32 h, GLenum format, GLenum type, const void* pixels ) {
	glTexSubImage2D( GL_TEXTURE_2D, level, offx, offy, w, h, format, type, pixels );
	__GL_error8( gloutput, glTexSubImage2D, level, offx, offy, w, h, infigl_enum( format ), infigl_enum( type ), pixels );
}
void InfiGLTransformFeedbackVaryings( uint32 prog, uint32 count, const char** str, GLenum mode ) {
	glTransformFeedbackVaryings( prog, count, str, mode );
	__GL_error4( gloutput, glTransformFeedbackVaryings, prog, count, str, infigl_enum( mode ) );
}

void InfiGLUniformf( uint32 location, float32 a ) {
	glUniform1f( location, a );
	__GL_error2( gloutput, glUniform1f, location, a );
}
void InfiGLUniformf( uint32 location, float32 a, float32 b ) {
	glUniform2f( location, a, b );
	__GL_error3( gloutput, glUniform2f, location, a, b );
}
void InfiGLUniformf( uint32 location, float32 a, float32 b, float32 c ) {
	glUniform3f( location, a, b, c );
	__GL_error4( gloutput, glUniform3f, location, a, b, c );
}
void InfiGLUniformf( uint32 location, float32 a, float32 b, float32 c, float32 d ) {
	glUniform4f( location, a, b, c, d );
	__GL_error5( gloutput, glUniform4f, location, a, b, c, d );
}
void InfiGLUniformf( uint32 location, const vec2& v ) {
	glUniform2f( location, v.r, v.g );
	__GL_error2( gloutput, glUniform2f, location, v );
}
void InfiGLUniformf( uint32 location, const vec3& v ) {
	glUniform3f( location, v.r, v.g, v.b );
	__GL_error2( gloutput, glUniform3f, location, v );
}
void InfiGLUniformf( uint32 location, const vec4& v ) {
	glUniform4f( location, v.r, v.g, v.b, v.a );
	__GL_error2( gloutput, glUniform4f, location, v );
}
void InfiGLUniformfv( uint32 location, uint32 c, const float32* a ) {
	glUniform1fv( location, c, a );
	__GL_error2( gloutput, glUniform1fv, location, a );
}
void InfiGLUniformfv( uint32 location, uint32 c, const vec2* v ) {
	glUniform2fv( location, c, (float32*)v );
	__GL_error3( gloutput, glUniform2fv, location, c, v );
}
void InfiGLUniformfv( uint32 location, uint32 c, const vec3* v ) {
	glUniform3fv( location, c, (float32*)v );
	__GL_error3( gloutput, glUniform3fv, location, c, v );
}
void InfiGLUniformfv( uint32 location, uint32 c, const vec4* v ) {
	glUniform4fv( location, c, (float32*)v );
	__GL_error3( gloutput, glUniform4fv, location, c, v );
}

void InfiGLUniformi( uint32 location, int32 a ) {
	glUniform1i( location, a );
	__GL_error2( gloutput, glUniform1i, location, a );
}
void InfiGLUniformi( uint32 location, int32 a, int32 b ) {
	glUniform2i( location, a, b );
	__GL_error3( gloutput, glUniform2i, location, a, b );
}
void InfiGLUniformi( uint32 location, int32 a, int32 b, int32 c ) {
	glUniform3i( location, a, b, c );
	__GL_error4( gloutput, glUniform3i, location, a, b, c );
}
void InfiGLUniformi( uint32 location, int32 a, int32 b, int32 c, int32 d ) {
	glUniform4i( location, a, b, c, d );
	__GL_error5( gloutput, glUniform4i, location, a, b, c, d );
}
void InfiGLUniformi( uint32 location, const vec2i& v ) {
	glUniform2i( location, v.r, v.g );
	__GL_error2( gloutput, glUniform2i, location, v );
}
void InfiGLUniformi( uint32 location, const vec3i& v ) {
	glUniform3i( location, v.r, v.g, v.b );
	__GL_error2( gloutput, glUniform3i, location, v );
}
void InfiGLUniformi( uint32 location, const vec4i& v ) {
	glUniform4i( location, v.r, v.g, v.b, v.a );
	__GL_error2( gloutput, glUniform4i, location, v );
}
void InfiGLUniformiv( uint32 location, uint32 c, const int32* a ) {
	glUniform1iv( location, c, a );
	__GL_error3( gloutput, glUniform1iv, location, c, a );
}
void InfiGLUniformiv( uint32 location, uint32 c, const vec2i* v ) {
	glUniform2iv( location, c, (int32*)v );
	__GL_error3( gloutput, glUniform2iv, location, c, v );
}
void InfiGLUniformiv( uint32 location, uint32 c, const vec3i* v ) {
	glUniform3iv( location, c, (int32*)v );
	__GL_error3( gloutput, glUniform3iv, location, c, v );
}
void InfiGLUniformiv( uint32 location, uint32 c, const vec4i* v ) {
	glUniform4iv( location, c, (int32*)v );
	__GL_error3( gloutput, glUniform4iv, location, c, v );
}

void InfiGLUniformui( uint32 location, uint32 a ) {
	glUniform1ui( location, a );
	__GL_error2( gloutput, glUniform1ui, location, a );
}
void InfiGLUniformui( uint32 location, uint32 a, uint32 b ) {
	glUniform2ui( location, a, b );
	__GL_error3( gloutput, glUniform2ui, location, a, b );
}
void InfiGLUniformui( uint32 location, uint32 a, uint32 b, uint32 c ) {
	glUniform3ui( location, a, b, c );
	__GL_error4( gloutput, glUniform3ui, location, a, b, c );
}
void InfiGLUniformui( uint32 location, uint32 a, uint32 b, uint32 c, uint32 d ) {
	glUniform4ui( location, a, b, c, d );
	__GL_error5( gloutput, glUniform4ui, location, a, b, c, d );
}
void InfiGLUniformui( uint32 location, const vec2ui& v ) {
	glUniform2ui( location, v.r, v.g );
	__GL_error2( gloutput, glUniform2ui, location, v );
}
void InfiGLUniformui( uint32 location, const vec3ui& v ) {
	glUniform3ui( location, v.r, v.g, v.b );
	__GL_error2( gloutput, glUniform3ui, location, v );
}
void InfiGLUniformui( uint32 location, const vec4ui& v ) {
	glUniform4ui( location, v.r, v.g, v.b, v.a );
	__GL_error2( gloutput, glUniform4ui, location, v );
}
void InfiGLUniformuiv( uint32 location, uint32 c, const uint32* a ) {
	glUniform1uiv( location, c, a );
	__GL_error3( gloutput, glUniform1uiv, location, c, a );
}
void InfiGLUniformuiv( uint32 location, uint32 c, const vec2ui* v ) {
	glUniform2uiv( location, c, (uint32*)v );
	__GL_error3( gloutput, glUniform2uiv, location, c, v );
}
void InfiGLUniformuiv( uint32 location, uint32 c, const vec3ui* v ) {
	glUniform3uiv( location, c, (uint32*)v );
	__GL_error3( gloutput, glUniform3uiv, location, c, v );
}
void InfiGLUniformuiv( uint32 location, uint32 c, const vec4ui* v ) {
	glUniform4uiv( location, c, (uint32*)v );
	__GL_error3( gloutput, glUniform4uiv, location, c, v );
}

void InfiGLUniform( uint32 location, const mat2& m ) {
	glUniformMatrix2fv( location, 1, GL_FALSE, m.data );
	__GL_error1( gloutput, glUniformMatrix2fv, location );
}
void InfiGLUniform( uint32 location, const mat3& m ) {
	glUniformMatrix3fv( location, 1, GL_FALSE, m.data );
	__GL_error1( gloutput, glUniformMatrix3fv, location );
}
void InfiGLUniform( uint32 location, const mat4& m ) {
	glUniformMatrix4fv( location, 1, GL_FALSE, m.data );
	__GL_error1( gloutput, glUniformMatrix4fv, location );
}
void InfiGLUniformv( uint32 location, uint32 count, const mat2* m ) {
	glUniformMatrix2fv( location, count, GL_FALSE, (float32*)m );
	__GL_error1( gloutput, glUniformMatrix2fv, location );
}
void InfiGLUniformv( uint32 location, uint32 count, const mat3* m ) {
	glUniformMatrix3fv( location, count, GL_FALSE, (float32*)m );
	__GL_error1( gloutput, glUniformMatrix3fv, location );
}
void InfiGLUniformv( uint32 location, uint32 count, const mat4* m ) {
	glUniformMatrix4fv( location, count, GL_FALSE, (float32*)m );
	__GL_error1( gloutput, glUniformMatrix4fv, location );
}

void InfiGLUseProgram( uint32 prog ) {
	glUseProgram( prog );
	__GL_error1( gloutput, glUseProgram, prog );
}
void InfiGLVertexAttribPointer( uint32 index, int32 sz, GLenum type, bool normalized, uint32 stride, void* offset ) {
	glVertexAttribPointer( index, sz, type, normalized, stride, offset );
	__GL_error6( gloutput, glVertexAttribPointer, index, sz, type, normalized, stride, offset );
}
void InfiGLViewport( const rect& rc ) {
	glViewport( rc.x, rc.y, rc.w, rc.h );
	__GL_error1( gloutput, glViewport, rc );
}
void InfiGLViewport( int32 x, int32 y, uint32 w, uint32 h ) {
	glViewport( x, y, w, h );
	__GL_error4( gloutput, glViewport, x, y, w, h );
}

} }