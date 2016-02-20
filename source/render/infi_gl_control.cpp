#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_control.h"
#include "core/infi_bitfield.h"

namespace INFI {
namespace render {
	
	static int32 current_state = -1;
	
	static core::bitfield_t					inuse;
	static core::stack_t<uint32> 			available;
	static core::array_t<infi_gl_state_t*> 	glstates;
	
	#define CURRENT_STATE glstates[current_state]
	#define CHECK_VALID_STATE( func ) \
			InfiPushFunction( #func ); \
			if ( current_state == -1 ) \
				InfiSendError( INFI_BINDING_ERROR,\
							   "no GL state currently enabled" );
	#define PUSH_STATE_VALUE( stack, value ) \
			glstates[current_state]->stack.push( value );
	#define PUSH_STATE2_VALUE( array, index, value ) \
			glstates[current_state]->array[index].push( value ); 
	
	void InfiLEmptyGLStateCache() {
		for ( uint32 i=0;i<glstates.size();++i )
			delete glstates[i];
		glstates.clear();
		inuse.clear();
	}
	void InfiGLInitDefaultState() {
		infi_gl_state_t* nstate = new infi_gl_state_t;
		InfiGLSyncState( nstate );
		glstates.add( nstate );
		current_state = 0;
	}
	uint32 InfiGLCreateState() {
		uint32 ret;
		if ( available.empty() ) {
			ret = glstates.size();
			glstates.add( new infi_gl_state_t );
			inuse.set(ret);
		} else {
			ret = *available;
			available.pop();
			inuse.set(ret);
		}
		InfiGLSyncState( glstates[ret] );
		return ret;
	}
	bool InfiGLFreeState( uint32 obj ) {
		if ( !inuse[obj] )
			return false;
		inuse.unset( obj );
		available.push( obj );
		return true;
	}
	bool InfiGLChangeState( uint32 nobj ) {
		current_state = nobj;
		return true;
	}
	
	void InfiGLSetWriteBuffer( uint32 buf ) {
		InfiGLBindBuffer( GL_COPY_WRITE_BUFFER, buf );
	}
	void InfiGLSetReadBuffer( uint32 buf ) {
		InfiGLBindBuffer( GL_COPY_READ_BUFFER, buf );
	}
	
	void InfiGLPushFramebuffer( uint32 obj ) {
		CHECK_VALID_STATE( InfiGLPushFramebuffer );
		InfiGLBindFramebuffer( obj );
		PUSH_STATE_VALUE( framebuffersread, obj );
		PUSH_STATE_VALUE( framebuffersdraw, obj );
		InfiPopFunction();
	}
	void InfiGLPushFramebuffer( uint32 r, uint32 w ) {
		CHECK_VALID_STATE( InfiGLPushFramebuffer );
		if ( r == w ) {
			InfiGLPushFramebuffer( r );
		} else {
			InfiGLBindFramebufferRead( r );
			InfiGLBindFramebufferDraw( w );
		}
		PUSH_STATE_VALUE( framebuffersread, r );
		PUSH_STATE_VALUE( framebuffersdraw, w );
		InfiPopFunction();
	}
	void InfiGLPushFramebufferDraw( uint32 read ) {
		CHECK_VALID_STATE( InfiGLPushFramebufferDraw );
		InfiGLBindFramebufferRead( read );
		PUSH_STATE_VALUE( framebuffersread, read );
		InfiPopFunction();
	}
	void InfiGLPushFramebufferRead( uint32 draw ) {
		CHECK_VALID_STATE( InfiGLPushFramebufferRead );
		InfiGLBindFramebufferDraw( draw );
		PUSH_STATE_VALUE( framebuffersdraw, draw );
		InfiPopFunction();
	}
	
	void InfiGLPushColorMask( bool r, bool g, bool b, bool a ) {
		CHECK_VALID_STATE( InfiGLPushColorMask );
		InfiGLColorMask( r, g, b, a );
		PUSH_STATE_VALUE( colormask, core::vec4b( r, g, b, a ) );
		InfiPopFunction();
	}
	void InfiGLPushDepthMask( bool mask ) {
		CHECK_VALID_STATE( InfiGLPushDepthMask );
		InfiGLDepthMask( mask );
		PUSH_STATE_VALUE( depthmask, mask );
		InfiPopFunction();
	}
	void InfiGLPushDepthMode( GLenum mode ) {
		CHECK_VALID_STATE( InfiGLPushDepthMode );
		InfiGLDepthFunc( mode );
		PUSH_STATE_VALUE( depthmode, mode );
		InfiPopFunction();
	}
	static void infi_gl_bind_stencil_separate( uint32 face, const infi_stencil_t* sten ) {
		if ( sten->usage & INFI_STENCIL_FUNC ) {
			InfiGLStencilFuncSeparate( face, sten->func, sten->ref, sten->mask );
			if ( face == GL_FRONT ) {
				PUSH_STATE_VALUE( stencilfront.func, sten->func );
				PUSH_STATE_VALUE( stencilfront.ref, sten->ref );
				PUSH_STATE_VALUE( stencilfront.mask, sten->mask );
			} else {
				PUSH_STATE_VALUE( stencilback.func, sten->func );
				PUSH_STATE_VALUE( stencilback.ref, sten->ref );
				PUSH_STATE_VALUE( stencilback.mask, sten->mask );
			}
		}
		if ( sten->usage & INFI_STENCIL_OP ) {
			InfiGLStencilOpSeparate( face, sten->sfail, sten->dpfail, sten->dppass );
			if ( face == GL_FRONT ) {
				PUSH_STATE_VALUE( stencilfront.sfail, sten->sfail );
				PUSH_STATE_VALUE( stencilfront.dpfail, sten->dpfail );
				PUSH_STATE_VALUE( stencilfront.dppass, sten->dppass );
			} else {
				PUSH_STATE_VALUE( stencilback.sfail, sten->sfail );
				PUSH_STATE_VALUE( stencilback.dpfail, sten->dpfail );
				PUSH_STATE_VALUE( stencilback.dppass, sten->dppass );
			}
		}
		if ( sten->usage & INFI_STENCIL_MASK ) {
			InfiGLStencilMaskSeparate( face, sten->wmask );
			if ( face == GL_FRONT ) {
				PUSH_STATE_VALUE( stencilfront.wmask, sten->wmask );
			} else {
				PUSH_STATE_VALUE( stencilback.wmask, sten->wmask );
			}
		}
	}
	static void infi_gl_bind_stencil( const infi_stencil_t* sten ) {
		if ( sten->usage & INFI_STENCIL_FUNC ) {
			InfiGLStencilFunc( sten->func, sten->ref, sten->mask );
			PUSH_STATE_VALUE( stencilfront.func, sten->func );
			PUSH_STATE_VALUE( stencilfront.ref, sten->ref );
			PUSH_STATE_VALUE( stencilfront.mask, sten->mask );
			PUSH_STATE_VALUE( stencilback.func, sten->func );
			PUSH_STATE_VALUE( stencilback.ref, sten->ref );
			PUSH_STATE_VALUE( stencilback.mask, sten->mask );
		}
		if ( sten->usage & INFI_STENCIL_OP ) {
			InfiGLStencilOp( sten->sfail, sten->dpfail, sten->dppass );
			PUSH_STATE_VALUE( stencilfront.sfail, sten->sfail );
			PUSH_STATE_VALUE( stencilfront.dpfail, sten->dpfail );
			PUSH_STATE_VALUE( stencilfront.dppass, sten->dppass );
			PUSH_STATE_VALUE( stencilback.sfail, sten->sfail );
			PUSH_STATE_VALUE( stencilback.dpfail, sten->dpfail );
			PUSH_STATE_VALUE( stencilback.dppass, sten->dppass );
		}
		if ( sten->usage & INFI_STENCIL_MASK ) {
			InfiGLStencilMask( sten->wmask );
			PUSH_STATE_VALUE( stencilfront.wmask, sten->wmask );
			PUSH_STATE_VALUE( stencilback.wmask, sten->wmask );
		}
	}
	void InfiGLPushStencilFunc( const infi_stencil_t* sten ) {
		CHECK_VALID_STATE( InfiGLPushStencilFunc );
		PUSH_STATE_VALUE( stencilback.wmask, sten->wmask );
		if ( sten->usage & INFI_STENCIL_FRONT ) {
			if ( sten->usage & INFI_STENCIL_BACK )
				infi_gl_bind_stencil( sten );
			else
				infi_gl_bind_stencil_separate( GL_FRONT, sten );
		} else if ( sten->usage & INFI_STENCIL_BACK )
			infi_gl_bind_stencil_separate( GL_BACK, sten );
		else InfiSendError( INFI_BINDING_ERROR,
							"invalid stencil mode being bound" );
		InfiPopFunction();
	}
	
	void InfiGLPushViewport( const core::rect& r ) {
		CHECK_VALID_STATE( InfiGLPushStencilFunc );
		InfiGLViewport( r );
		PUSH_STATE_VALUE( viewports, r );
		InfiPopFunction();
	}
	
	void InfiGLPushTextureFrame() {
		CHECK_VALID_STATE( InfiGLPushTextureFrame );
		PUSH_STATE_VALUE( texframe, 0 );
		InfiPopFunction();
	}
	
	void InfiGLPushTexture( uint32 tex, uint32 active ) {
		CHECK_VALID_STATE( InfiGLPushTexture );
		core::vec2ui& index = CURRENT_STATE->activetex[0];
		
		if ( active != index.x ) {
			InfiGLActiveTexture( active );
			PUSH_STATE_VALUE( activetex, core::vec2ui( active, 1 ) );
		} else
			++ index.y;
		PUSH_STATE2_VALUE( textures, active, tex );
		
		InfiGLBindTexture( tex );
		++ (*(CURRENT_STATE->texframe));
		InfiPopFunction();
	}
	
	#define INFI_GL_PUSH_BUFFER( fname, buffer, stack ) \
			void fname( uint32 buf ) { \
				CHECK_VALID_STATE( fname ); \
				InfiGLBindBuffer( buffer, buf ); \
				PUSH_STATE_VALUE( stack, buf ); \
				InfiPopFunction(); \
			}
			
	INFI_GL_PUSH_BUFFER( InfiGLPushArrayBuffer, GL_ARRAY_BUFFER, arraybuffers );
	INFI_GL_PUSH_BUFFER( InfiGLPushIndexBuffer, GL_ELEMENT_ARRAY_BUFFER, indexbuffers );
	INFI_GL_PUSH_BUFFER( InfiGLPushPackBuffer, GL_PIXEL_PACK_BUFFER, packbuffers );
	INFI_GL_PUSH_BUFFER( InfiGLPushUnpackBuffer, GL_PIXEL_UNPACK_BUFFER, unpackbuffers );
	
	void InfiGLPushProgram( uint32 prog ) {
		CHECK_VALID_STATE( InfiGLPushShader );
		InfiGLUseProgram( prog );
		PUSH_STATE_VALUE( programs, prog );
		InfiPopFunction();
	}
	void InfiGLPushDrawBuffer( GLenum db ) {
		CHECK_VALID_STATE( InfiGLPushDrawBuffer );
		InfiGLDrawBuffer( db );
		PUSH_STATE_VALUE( drawbuffers, db );
		InfiPopFunction();
	}
	void InfiGLPushVertexArray( uint32 va ) {
		CHECK_VALID_STATE( InfiGLPushVertexArray );
		InfiGLBindVertexArray( va );
		PUSH_STATE_VALUE( vertexarrays, va );
		InfiPopFunction();
	}
	
	static void infi_gl_use_blend_mode( const infi_blend_t* bln ) {
		if ( bln->usage & INFI_BLEND_EQUATION ) {
			if ( bln->usage & INFI_BLEND_EQUATION_SEP ) {
				InfiGLBlendEquationSeparate( bln->funcalpha, bln->funccolor );
				PUSH_STATE_VALUE( funcalpha, bln->funcalpha );
				PUSH_STATE_VALUE( funccolor, bln->funccolor );
			} else {
				InfiGLBlendEquation( bln->funcalpha );
				PUSH_STATE_VALUE( funcalpha, bln->funcalpha );
			}
		}
		if ( bln->usage & INFI_BLEND_FUNCTION ) {
			if ( bln->usage & INFI_BLEND_FUNCTION_SEP ) {
				InfiGLBlendFuncSeparate( bln->srcalpha, bln->srccolor, bln->dstalpha, bln->dstcolor );
				PUSH_STATE_VALUE( srcalpha, bln->srcalpha );
				PUSH_STATE_VALUE( srccolor, bln->srccolor );
				PUSH_STATE_VALUE( dstalpha, bln->dstalpha );
				PUSH_STATE_VALUE( dstcolor, bln->dstcolor );
			} else {
				InfiGLBlendFunc( bln->srcalpha, bln->dstalpha );
				PUSH_STATE_VALUE( srcalpha, bln->srcalpha );
				PUSH_STATE_VALUE( dstalpha, bln->dstalpha );
			}
		}
	}
	void InfiGLPushBlendMode( const infi_blend_t* bln ) {
		CHECK_VALID_STATE( InfiGLPushBlendMode );
		infi_gl_use_blend_mode( bln );
		PUSH_STATE_VALUE( blendusage, bln->usage );
		InfiPopFunction();
	}
	void InfiGLPushBlendColor( const core::vec4& col ) {
		CHECK_VALID_STATE( InfiGLPushBlendColor );
		InfiGLBlendColor( col.r, col.g, col.b, col.a );
		PUSH_STATE_VALUE( color, col );
		InfiPopFunction();
	}
	
	
	#define POP_STATE_VALUE( fname, stack ) \
			if ( glstates[current_state]->stack.size() == 1 ) \
				InfiSendError( INFI_UNDERFLOW_ERROR, \
							   "GL attribute is at its base value" ); \
			glstates[current_state]->stack.pop();
			
	void InfiGLPopFramebuffer() {
		CHECK_VALID_STATE( InfiGLPopFramebuffer );
		
		if ( CURRENT_STATE->framebuffersdraw[0] != 
			 CURRENT_STATE->framebuffersread[0] ) {
			InfiSendError( INFI_BINDING_ERROR,
						   "the read and draw framebuffers were not the same" );
		}
		
		POP_STATE_VALUE( InfiGLPopFramebuffer, framebuffersdraw )
		POP_STATE_VALUE( InfiGLPopFramebuffer, framebuffersread )
		
		InfiGLBindFramebuffer( CURRENT_STATE->framebuffersdraw[0] );
		InfiPopFunction();
	}
	void InfiGLPopFramebufferDraw() {
		CHECK_VALID_STATE( InfiGLPopFramebufferDraw );
		POP_STATE_VALUE( InfiGLPopFramebufferDraw, framebuffersdraw )
		InfiGLBindFramebufferDraw( CURRENT_STATE->framebuffersdraw[0] );
		InfiPopFunction();
	}
	void InfiGLPopFramebufferRead() {
		CHECK_VALID_STATE( InfiGLPopFramebufferRead );
		POP_STATE_VALUE( InfiGLPopFramebufferRead, framebuffersread )
		InfiGLBindFramebufferRead( CURRENT_STATE->framebuffersread[0] );
		InfiPopFunction();
	}
	
	void InfiGLPopViewport() {
		CHECK_VALID_STATE( InfiGLPopViewport );
		POP_STATE_VALUE( InfiGLPopViewport, viewports )
		InfiGLViewport( CURRENT_STATE->viewports[0] );
		InfiPopFunction();
	}
	static int32 pop_tex_inner() {
		core::vec2ui& index = CURRENT_STATE->activetex[0];
		
		POP_STATE_VALUE( InfiGLPopTexture, textures[index.x] );
		
		-- index.y;
		if ( index.y == 0 ) {
			POP_STATE_VALUE( InfiGLPopTexture, activetex );
			index = CURRENT_STATE->activetex[0];
			return index.x;
		} else
			return -1;
	}
	void InfiGLPopTextureFrame() {
		CHECK_VALID_STATE( InfiGLPopTextureFrame );
		
		if ( CURRENT_STATE->texframe.size() <= 1 )
			InfiSendError( INFI_UNDERFLOW_ERROR,
						   "there are no texture frames" );
		
		uint32 amt = *(CURRENT_STATE->texframe);
		if ( amt != 0 ) {
			int32 rem = -1;
			for ( uint32 i=0;i<amt;++i ) {
				rem = pop_tex_inner();
				if ( rem != -1 ) {
					InfiGLActiveTexture( rem );
					InfiGLBindTexture( CURRENT_STATE->textures[rem][0] );
				} 
			}
			InfiGLBindTexture( CURRENT_STATE->textures[CURRENT_STATE->activetex[0].x][0] );
		}
		
		POP_STATE_VALUE( InfiGLPopTextureFrame, texframe );
		
		InfiPopFunction();
	}
	void InfiGLPopTexture() {
		CHECK_VALID_STATE( InfiGLPopTexture );
		
		if ( *(CURRENT_STATE->texframe) == 0 )
			InfiSendError( INFI_UNDERFLOW_ERROR,
						   "there are no textures remaining in the current frame" );
		-- (*(CURRENT_STATE->texframe));
		
		int32 temp = pop_tex_inner();
		if ( temp != -1 )
			InfiGLActiveTexture( temp );
			
		InfiGLBindTexture( CURRENT_STATE->textures[CURRENT_STATE->activetex[0].x][0] );
		InfiPopFunction();
	}
	
	#define INFI_GL_POP_BUFFER( fname, buffer, stack ) \
			void fname() { \
				CHECK_VALID_STATE( fname ); \
				POP_STATE_VALUE( fname, stack ); \
				InfiGLBindBuffer( buffer, CURRENT_STATE->stack[0] ); \
				InfiPopFunction(); \
			}
	
	INFI_GL_POP_BUFFER( InfiGLPopArrayBuffer, GL_ARRAY_BUFFER, arraybuffers );
	INFI_GL_POP_BUFFER( InfiGLPopIndexBuffer, GL_ELEMENT_ARRAY_BUFFER, indexbuffers );
	INFI_GL_POP_BUFFER( InfiGLPopPackBuffer, GL_PIXEL_PACK_BUFFER, packbuffers );
	INFI_GL_POP_BUFFER( InfiGLPopUnpackBuffer, GL_PIXEL_UNPACK_BUFFER, unpackbuffers );
	
	void InfiGLPopProgram() {
		CHECK_VALID_STATE( InfiGLPopProgram );
		POP_STATE_VALUE( InfiGLPopProgram, programs );
		InfiGLUseProgram( CURRENT_STATE->programs[0] );
		InfiPopFunction();
	}
	void InfiGLPopDrawBuffer() {
		CHECK_VALID_STATE( InfiGLPopDrawBuffer );
		POP_STATE_VALUE( InfiGLPopDrawBuffer, drawbuffers );
		InfiGLDrawBuffer( CURRENT_STATE->drawbuffers[0] );
		InfiPopFunction();
	}
	void InfiGLPopVertexArray() {
		CHECK_VALID_STATE( InfiGLPopVertexArray );
		POP_STATE_VALUE( InfiGLPopVertexArray, vertexarrays );
		InfiGLBindVertexArray( CURRENT_STATE->vertexarrays[0] );
		InfiPopFunction();
	}
	
	static void infi_gl_unuse_blend_mode() {
		uint32 usage1 = CURRENT_STATE->blendusage[0];
		POP_STATE_VALUE( InfiGLPopBlendMode, blendusage );
		
		if ( usage1 & INFI_BLEND_EQUATION ) {
			if ( usage1 & INFI_BLEND_EQUATION_SEP ) {
				POP_STATE_VALUE( InfiGLPopBlendMode, funcalpha );
				POP_STATE_VALUE( InfiGLPopBlendMode, funccolor );
				InfiGLBlendEquationSeparate( CURRENT_STATE->funcalpha[0],
											 CURRENT_STATE->funccolor[0] );
			} else {
				POP_STATE_VALUE( InfiGLPopBlendMode, funcalpha );
				InfiGLBlendEquation( CURRENT_STATE->funcalpha[0] );
			}
		}
		if ( usage1 & INFI_BLEND_FUNCTION ) {
			if ( usage1 & INFI_BLEND_FUNCTION_SEP ) {
				POP_STATE_VALUE( InfiGLPopBlendMode, srcalpha );
				POP_STATE_VALUE( InfiGLPopBlendMode, srccolor );
				POP_STATE_VALUE( InfiGLPopBlendMode, dstalpha );
				POP_STATE_VALUE( InfiGLPopBlendMode, dstcolor );
				InfiGLBlendFuncSeparate( CURRENT_STATE->srcalpha[0],
										 CURRENT_STATE->srccolor[0],
										 CURRENT_STATE->dstalpha[0],
										 CURRENT_STATE->dstcolor[0] );
			} else {
				POP_STATE_VALUE( InfiGLPopBlendMode, srcalpha );
				POP_STATE_VALUE( InfiGLPopBlendMode, dstalpha );
				InfiGLBlendFunc( CURRENT_STATE->srcalpha[0],
								 CURRENT_STATE->dstalpha[0] );
			}
		}
	}
	void InfiGLPopBlendMode() {
		CHECK_VALID_STATE( InfiGLPopBlendMode );
		infi_gl_unuse_blend_mode();
		InfiPopFunction();
	}
	void InfiGLPopBlendColor() {
		CHECK_VALID_STATE( InfiGLPopBlendMode );
		POP_STATE_VALUE( InfiGLPopBlendMode, color );
		core::vec4& col = CURRENT_STATE->color[0];
		InfiGLBlendColor( col.r, col.g, col.b, col.a );
		InfiPopFunction();
	}
	
	void InfiGLPopColorMask() {
		CHECK_VALID_STATE( InfiGLPushColorMask );
		POP_STATE_VALUE(cmask. InfiGLPushColorMask, colormask );
		core::vec4b& cmask = CURRENT_STATE->colormask[0];
		InfiGLColorMask( cmask.r, cmask.g, cmask.b, cmask.a );
		InfiPopFunction();
	}
	void InfiGLPopDepthMask() {
		CHECK_VALID_STATE( InfiGLPushDepthMask );
		POP_STATE_VALUE( InfiGLPushDepthMask, depthmask );
		InfiGLDepthMask( CURRENT_STATE->depthmask[0] );
		InfiPopFunction();
	}
	void InfiGLPopDepthMode() {
		CHECK_VALID_STATE( InfiGLPushDepthMode );
		POP_STATE_VALUE( InfiGLPopDepthMode, depthmode );
		InfiGLDepthFunc( CURRENT_STATE->depthmode[0] );
		InfiPopFunction();
	}
	
	static void infi_gl_unbind_stencil_separate( uint32 face, uint32 usage ) {
		if ( usage & INFI_STENCIL_FUNC ) {
			if ( face == GL_FRONT ) {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.func );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.ref );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.mask );
				InfiGLStencilFuncSeparate( face, CURRENT_STATE->stencilfront.func[0],
												 CURRENT_STATE->stencilfront.ref[0], 
												 CURRENT_STATE->stencilfront.mask[0] );
			} else {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.func );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.ref );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.mask );
				InfiGLStencilFuncSeparate( face, CURRENT_STATE->stencilback.func[0],
												 CURRENT_STATE->stencilback.ref[0], 
												 CURRENT_STATE->stencilback.mask[0] );
			}
		}
		if ( usage & INFI_STENCIL_OP ) {
			if ( face == GL_FRONT ) {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.sfail );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.dpfail );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.dppass );
				InfiGLStencilOpSeparate( face, CURRENT_STATE->stencilfront.sfail[0],
											   CURRENT_STATE->stencilfront.dpfail[0], 
											   CURRENT_STATE->stencilfront.dppass[0] );
			} else {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.sfail );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.dpfail );
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.dppass );
				InfiGLStencilOpSeparate( face, CURRENT_STATE->stencilback.sfail[0],
											   CURRENT_STATE->stencilback.dpfail[0], 
											   CURRENT_STATE->stencilback.dppass[0] );
			}
		}
		if ( usage & INFI_STENCIL_MASK ) {
			if ( face == GL_FRONT ) {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.wmask );
				InfiGLStencilMaskSeparate( face, CURRENT_STATE->stencilfront.wmask[0] );
			} else {
				POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.wmask );
				InfiGLStencilMaskSeparate( face, CURRENT_STATE->stencilback.wmask[0] );
			}
		}
	}
	static void infi_gl_unbind_stencil( uint32 usage ) {
		if ( usage & INFI_STENCIL_FUNC ) {
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.func );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.ref );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.mask );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.func );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.ref );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.mask );
			InfiGLStencilFunc( CURRENT_STATE->stencilfront.func[0],
							   CURRENT_STATE->stencilfront.ref[0], 
							   CURRENT_STATE->stencilfront.mask[0] );
		}
		if ( usage & INFI_STENCIL_OP ) {
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.sfail );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.dpfail );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.dppass );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.sfail );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.dpfail );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.dppass );
			InfiGLStencilOp( CURRENT_STATE->stencilfront.sfail[0],
							 CURRENT_STATE->stencilfront.dpfail[0], 
							 CURRENT_STATE->stencilfront.dppass[0] );
		}
		if ( usage & INFI_STENCIL_MASK ) {
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilfront.wmask );
			POP_STATE_VALUE( InfiGLPopStencilFunc, stencilback.wmask );
			InfiGLStencilMask( CURRENT_STATE->stencilfront.wmask[0] );
		}
	}
	void InfiGLPopStencilFunc() {
		CHECK_VALID_STATE( InfiGLPopStencilFunc );
		
		uint32 usage = CURRENT_STATE->stencilusage[0];
		if ( usage & INFI_STENCIL_FRONT ) {
			if ( usage & INFI_STENCIL_BACK )
				infi_gl_unbind_stencil( usage );
			else
				infi_gl_unbind_stencil_separate( GL_FRONT, usage );
		} else if ( usage & INFI_STENCIL_BACK )
			infi_gl_unbind_stencil_separate( GL_BACK, usage );
		else InfiSendError( INFI_BINDING_ERROR,
							"invalid stencil mode being bound" );
		
		POP_STATE_VALUE( InfiGLPopStencilFunc, stencilusage );
		InfiPopFunction();
	}
	
} }
