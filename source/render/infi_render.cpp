#include "render/infi_render.h"
#include "render/infi_format.h"
#include "render/infi_view_transform.h"
#include "render/infi_texture.h"
#include "render/infi_renderbuffer.h"
#include "render/infi_canvas.h"
#include "render/infi_program.h"
#include "render/infi_vertices.h"
#include "render/infi_gl_wrapper.h"
#include "render/infi_gl_objects.h"

namespace INFI {
namespace render {
	
	// for canvas use only
	struct texture_framebuffer {
		struct {
			uint32 uptodate : 1;
			uint32 frame	: 31;
		} data;
		infi_texture_t* name;
	};
	typedef core::map_t<infi_window_t*, texture_framebuffer>::iterator frame_iter;
	static core::map_t<infi_window_t*, texture_framebuffer> texture_frames;
	
	struct feedback_mapping {
		infi_buffer_t* buffer;
		const infi_format_t* formatting;
		core::data_t<core::string_t> elements;
	};
	
	typedef core::map_t<uint32, feedback_mapping>::iterator feedback_iter;
	static core::map_t<uint32, feedback_mapping> feedback_map;
	static bool feedback_is_enabled;
	
	static core::stack_t<infi_canvas_t*> canvases;
	static core::stack_t<bool> 			 istexture;
	// for canvas use only
	
	static bool infi_viewport_change = true;
	void InfiLSignalViewportChange() {
		infi_viewport_change = true;
	}
	
	
	static core::stack_t<INFI_render_style> styles;
	static core::vec4 default_color = core::vec4(1,1,1,1);
	static core::stack_t<core::vec4> infi_render_color;
	
	void InfiLInitRender() {
		styles.push( INFI_TRIANGLES );
	}
	void InfiLQuitRender() {
		InfiLEmptyBlendModeCache();
		InfiLEmptyCanvasCache();
		InfiLEmptyRenderbufferCache();
		InfiLEmptyStencilModeCache();
		InfiLEmptyTextureCache();
		InfiLEmptyVertexCache();
		InfiLEmptyGLStateCache();
	}
	
	static core::rectf viewport;
	static core::vec2ui dimensions;
	static core::vec2ui basic_size(2,2);
	float32 InfiGetRatio() {
		core::vec2ui temp = InfiGetDimensions();
		return (float32) temp.x / (float32) temp.y;
	}
	const core::vec2ui& InfiGetDimensions() {
		infi_canvas_t* cv;
		if ( InfiCanvasIsTexture() ) {
			return InfiCurrentTextureCanvas()->dimensions;
		} else if ( ( cv = InfiCurrentCanvas() ) == NULL ) {
			infi_window_t* win = InfiRenderWindow();
			return ( win == NULL ) ? basic_size : win->dimensions;
		} else {
			return cv->dimensions;
		}
	}
	const core::rectf& InfiGetRect() {
		viewport.x = 0;
		viewport.y = 0;
		viewport.dim = (core::vec2) InfiGetDimensions();
		return viewport;
	}
	
	
	void InfiPushColor() {
		infi_render_color.push( default_color );
	}
	void InfiPushColor( const core::vec4& col ) {
		infi_render_color.push( col );
	}
	void InfiPopColor() {
		infi_render_color.pop();
	}
	void InfiSetColor( const core::vec4& col ) {
		infi_render_color[0] = col;
	}
	void InfiSetColor( float32 r, float32 g, float32 b, float32 a ) {
		infi_render_color[0] = core::vec4(r,g,b,a);
	}
	const core::vec4& InfiGetColor() {
		return (infi_render_color.empty()) ? default_color : infi_render_color[0];
	}
	
	void InfiPushPrimitives( INFI_render_style rend ) {
		styles.push( rend );
	}
	void InfiPopPrimitives() {
		InfiPushFunction( "InfiPopPrimitives" ); 
		if ( styles.size() == 1 )
			InfiSendError( INFI_WARNING, "InfiPopPrimitives", "no style on stack to pop") ;
		styles.pop();
		InfiPopFunction();
	}
	void InfiSetPrimitives( INFI_render_style st ) {
		styles[0] = st;
	}
	
	static void infi_draw_common( uint32 start, int32 count ) {
		InfiPushFunction( "InfiDraw" );
		
		infi_vertices_t* v = InfiCurrentVertices();
		infi_program_t* pr = InfiCurrentProgram();
		if ( v == NULL )
			InfiSendError( INFI_BINDING_ERROR,
						   "no currently bound vertex object to draw" );
		if ( pr == NULL )
			InfiSendError( INFI_BINDING_ERROR,
						   "no currently bound program for draw" );
		
		if ( !(*(v->format) == *(pr->format.input)) )
			InfiSendError( INFI_BINDING_ERROR,
						   "vertex object format does not match program input format" );
					   
		if ( count != -1 && v->vcount < (uint32)count + start )
			InfiSendError( INFI_BINDING_ERROR,
						   "attempting to render vertices %d through %d out of %d",
						   start, start+count, v->vcount );
		
		infi_window_t* win = InfiRenderWindow();
		
		// enable canvas
		core::vec2ui dim;
		infi_canvas_t* cv;
		if ( InfiCanvasIsTexture() ) {
			texture_framebuffer& ref = texture_frames[win];
			InfiGLPushFramebuffer( ref.data.frame );
			if ( !ref.data.uptodate ) {
				InfiGLFramebufferTexture( GL_COLOR_ATTACHMENT0,
										  ref.name->handle,
										  0 );
				ref.data.uptodate = true;
			}
			dim = ref.name->dimensions;
		} else if ( (cv=InfiCurrentCanvas()) != NULL ) {
			InfiGLPushFramebuffer(cv->handle());
			dim = cv->dimensions;
		} else {
			InfiGLPushFramebuffer(0);
			dim = (win==NULL)?core::vec2ui(1,1):win->dimensions;
		}
		if ( infi_viewport_change ) {
			InfiGLViewport( 0, 0, dim.x, dim.y );
			infi_viewport_change = false;
		}
		
		// enable vertices
		InfiGLPushVertexArray( v->handle() );
		
		// enable program
		pr->compile();
		InfiGLPushProgram( pr->handle );
		
		if ( feedback_is_enabled && pr->flags.has_feedback ) {
			feedback_iter f = feedback_map.find( pr->handle );
			infi_buffer_t* buf = f->second.buffer;
			buf->resizeData( ((count==-1)?v->vcount:count) *
							 f->second.formatting->stride() );
			InfiGLBindBufferBase( GL_TRANSFORM_FEEDBACK_BUFFER,
								  0, buf->getHandle() );
			InfiGLBeginTransformFeedback( *styles );
		}
		
		InfiGLPushTextureFrame();
		pr->uniforms.use( pr->handle );
		
		if ( v->indices == NULL ) {
			InfiGLDrawArrays( *styles,
							  start,
							  (count==-1)?v->vcount:count );
		} else {
			InfiGLDrawElements( *styles,
								(count==-1)?v->vcount:count,
								INFI_UINT, 
								(void*)(start*sizeof(uint32)) );
		}
		
		InfiGLPopTextureFrame();
		
		if ( feedback_is_enabled && pr->flags.has_feedback ) {
			InfiGLEndTransformFeedback();
			InfiGLBindBufferBase( GL_TRANSFORM_FEEDBACK_BUFFER, 0,  0 );
		}
		
		InfiGLPopProgram();
		InfiGLPopVertexArray();
		InfiGLPopFramebuffer();
		InfiPopFunction();
	}
	
	void InfiDraw() {
		infi_draw_common( 0, -1 );
	}
	void InfiDraw( uint32 count ) {
		infi_draw_common( 0, count );
	}
	void InfiDraw( uint32 start, uint32 count ) {
		infi_draw_common( start, count );
	}
	
	
	
	bool InfiCanvasIsTexture() {
		return ( !istexture.empty() && istexture[0] );
	}
	infi_canvas_t* InfiCurrentCanvas() {
		if ( InfiCanvasIsTexture() )
			return NULL;
		return (canvases.empty()) ? NULL : canvases[0];
	}
	infi_texture_t* InfiCurrentTextureCanvas() {
		if ( !InfiCanvasIsTexture() )
			return NULL;
		return texture_frames[InfiRenderWindow()].name;
	}
	void InfiPushCanvas( infi_canvas_t* cv ) {
		canvases.push( cv );
		istexture.push( false );
		InfiLSignalViewportChange();
	}
	void InfiPushCanvas( infi_texture_t* tcv ) {
		canvases.push( NULL );
		istexture.push( true );
		
		infi_window_t* win = InfiRenderWindow();
		frame_iter iter = texture_frames.find( win );
		uint32 fbuf;
		if ( iter == texture_frames.end() ) {
			fbuf = InfiGLCreateFramebuffer();
			texture_frames[win].data.uptodate = false;
			texture_frames[win].data.frame = fbuf;
			texture_frames[win].name = tcv;
		} else {
			iter->second.data.uptodate = false;
			iter->second.name = tcv;
		}
		InfiLSignalViewportChange();
	}
	void InfiPopCanvas() {
		InfiPushFunction( "InfiPopCanvas" );
		if ( canvases.empty() )
			InfiSendError( INFI_UNDERFLOW_ERROR,
						   "no canvas currently bound" );
		else {
			canvases.pop();
			istexture.pop();
		}
		InfiPopFunction();
	}
	
	void InfiDestroyProgram( infi_program_t* prog ) {
		if ( prog->flags.has_feedback ) {
			feedback_iter f = feedback_map.find( prog->handle );
			if ( f != feedback_map.end() )
				feedback_map.erase( f );
		}
		for ( uint32 i=0;i<6;i++ )
			if ( prog->components[i] != 0 )
				InfiGLDeleteShader( prog->components[i] );
		InfiGLDeleteProgram( prog->handle );
		delete[] prog->components;
		delete prog;
	}
	
	void InfiEnableFeedback() {
		feedback_is_enabled = true;
	}
	void InfiDisableFeedback() {
		feedback_is_enabled = false;
	}
	
	infi_buffer_t const* InfiAssignFeedback(infi_program_t* prog,
											const infi_format_t* formatting,
											uint32 count,
											const char** names) {
		infi_buffer_t* nbuf = NULL;
		
		core::data_t<core::string_t> namelist( count );
		for ( uint32 i=0;i<count;++i ) {
			for ( uint32 j=0;j<i;++i )
				if ( namelist[j] == names[i] )
					InfiSendError( INFI_BINDING_ERROR,
								   "duplicate element %s",
								   names[i] );
			namelist[i] = names[i];
		}
		
		
		feedback_iter f = feedback_map.find( prog->handle );
		if ( f == feedback_map.end() ) {
			nbuf = new infi_buffer_t;
			feedback_mapping entry;
				entry.buffer = nbuf;
				entry.formatting = formatting;
				entry.elements = namelist;
			feedback_map.insert( std::make_pair( prog->handle, entry ) );
		} else {
			nbuf = f->second.buffer;
			f->second.elements = namelist;
		}
		
		InfiGLTransformFeedbackVaryings( prog->handle, count, names,
									  	 GL_INTERLEAVED_ATTRIBS );
		
		prog->flags.uptodate = false;
		prog->flags.has_feedback = true;
		
		return nbuf;
	}
	
	infi_buffer_t const* InfiAssignFeedback(infi_program_t* prog,
											const infi_format_t* form,
											std::initializer_list<const char*> stdinit) {
		uint32 count = stdinit.end() - stdinit.begin();
		const char** names = (const char**) &(*(stdinit.begin()));
		return InfiAssignFeedback( prog, form, count, names );
	}
	
} }