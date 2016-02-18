#include "render/infi_gl_extensions.h"

namespace INFI {
namespace render {

void InfiGLPrint( std::ostream& ostr, GLenum en ) {
	// convert all enumerator values to strings
		if ( en == GL_ZERO ) ostr << "GL_ZERO";
		else if ( en == GL_ONE ) ostr << "GL_ONE";
	#ifdef GL_LOGIC_OP
		else if ( en == GL_LOGIC_OP ) ostr << "GL_LOGIC_OP";
	#endif
	#ifdef GL_TEXTURE_COMPONENTS
		else if ( en == GL_TEXTURE_COMPONENTS ) ostr << "GL_TEXTURE_COMPONENTS";
	#endif
	#ifdef GL_POINTS
		else if ( en == GL_POINTS ) ostr << "GL_POINTS";
	#endif
	#ifdef GL_CURRENT_BIT
		else if ( en == GL_CURRENT_BIT ) ostr << "GL_CURRENT_BIT";
	#endif
	#ifdef GL_CLIENT_PIXEL_STORE_BIT
		else if ( en == GL_CLIENT_PIXEL_STORE_BIT ) ostr << "GL_CLIENT_PIXEL_STORE_BIT";
	#endif
	#ifdef GL_LINES
		else if ( en == GL_LINES ) ostr << "GL_LINES";
	#endif
	#ifdef GL_LINE_LOOP
		else if ( en == GL_LINE_LOOP ) ostr << "GL_LINE_LOOP";
	#endif
	#ifdef GL_CLIENT_VERTEX_ARRAY_BIT
		else if ( en == GL_CLIENT_VERTEX_ARRAY_BIT ) ostr << "GL_CLIENT_VERTEX_ARRAY_BIT";
	#endif
	#ifdef GL_LINE_STRIP
		else if ( en == GL_LINE_STRIP ) ostr << "GL_LINE_STRIP";
	#endif
	#ifdef GL_TRIANGLES
		else if ( en == GL_TRIANGLES ) ostr << "GL_TRIANGLES";
	#endif
	#ifdef GL_TRIANGLE_STRIP
		else if ( en == GL_TRIANGLE_STRIP ) ostr << "GL_TRIANGLE_STRIP";
	#endif
	#ifdef GL_TRIANGLE_FAN
		else if ( en == GL_TRIANGLE_FAN ) ostr << "GL_TRIANGLE_FAN";
	#endif
	#ifdef GL_QUADS
		else if ( en == GL_QUADS ) ostr << "GL_QUADS";
	#endif
	#ifdef GL_QUAD_STRIP
		else if ( en == GL_QUAD_STRIP ) ostr << "GL_QUAD_STRIP";
	#endif
	#ifdef GL_POLYGON_BIT
		else if ( en == GL_POLYGON_BIT ) ostr << "GL_POLYGON_BIT";
	#endif
	#ifdef GL_POLYGON
		else if ( en == GL_POLYGON ) ostr << "GL_POLYGON";
	#endif
	#ifdef GL_POLYGON_STIPPLE_BIT
		else if ( en == GL_POLYGON_STIPPLE_BIT ) ostr << "GL_POLYGON_STIPPLE_BIT";
	#endif
	#ifdef GL_PIXEL_MODE_BIT
		else if ( en == GL_PIXEL_MODE_BIT ) ostr << "GL_PIXEL_MODE_BIT";
	#endif
	#ifdef GL_LIGHTING_BIT
		else if ( en == GL_LIGHTING_BIT ) ostr << "GL_LIGHTING_BIT";
	#endif
	#ifdef GL_FOG_BIT
		else if ( en == GL_FOG_BIT ) ostr << "GL_FOG_BIT";
	#endif
	#ifdef GL_DEPTH_BUFFER_BIT
		else if ( en == GL_DEPTH_BUFFER_BIT ) ostr << "GL_DEPTH_BUFFER_BIT";
	#endif
	#ifdef GL_ACCUM
		else if ( en == GL_ACCUM ) ostr << "GL_ACCUM";
	#endif
	#ifdef GL_LOAD
		else if ( en == GL_LOAD ) ostr << "GL_LOAD";
	#endif
	#ifdef GL_RETURN
		else if ( en == GL_RETURN ) ostr << "GL_RETURN";
	#endif
	#ifdef GL_MULT
		else if ( en == GL_MULT ) ostr << "GL_MULT";
	#endif
	#ifdef GL_ADD
		else if ( en == GL_ADD ) ostr << "GL_ADD";
	#endif
	#ifdef GL_NEVER
		else if ( en == GL_NEVER ) ostr << "GL_NEVER";
	#endif
	#ifdef GL_ACCUM_BUFFER_BIT
		else if ( en == GL_ACCUM_BUFFER_BIT ) ostr << "GL_ACCUM_BUFFER_BIT";
	#endif
	#ifdef GL_LESS
		else if ( en == GL_LESS ) ostr << "GL_LESS";
	#endif
	#ifdef GL_EQUAL
		else if ( en == GL_EQUAL ) ostr << "GL_EQUAL";
	#endif
	#ifdef GL_LEQUAL
		else if ( en == GL_LEQUAL ) ostr << "GL_LEQUAL";
	#endif
	#ifdef GL_GREATER
		else if ( en == GL_GREATER ) ostr << "GL_GREATER";
	#endif
	#ifdef GL_NOTEQUAL
		else if ( en == GL_NOTEQUAL ) ostr << "GL_NOTEQUAL";
	#endif
	#ifdef GL_GEQUAL
		else if ( en == GL_GEQUAL ) ostr << "GL_GEQUAL";
	#endif
	#ifdef GL_ALWAYS
		else if ( en == GL_ALWAYS ) ostr << "GL_ALWAYS";
	#endif
	#ifdef GL_SRC_COLOR
		else if ( en == GL_SRC_COLOR ) ostr << "GL_SRC_COLOR";
	#endif
	#ifdef GL_ONE_MINUS_SRC_COLOR
		else if ( en == GL_ONE_MINUS_SRC_COLOR ) ostr << "GL_ONE_MINUS_SRC_COLOR";
	#endif
	#ifdef GL_SRC_ALPHA
		else if ( en == GL_SRC_ALPHA ) ostr << "GL_SRC_ALPHA";
	#endif
	#ifdef GL_ONE_MINUS_SRC_ALPHA
		else if ( en == GL_ONE_MINUS_SRC_ALPHA ) ostr << "GL_ONE_MINUS_SRC_ALPHA";
	#endif
	#ifdef GL_DST_ALPHA
		else if ( en == GL_DST_ALPHA ) ostr << "GL_DST_ALPHA";
	#endif
	#ifdef GL_ONE_MINUS_DST_ALPHA
		else if ( en == GL_ONE_MINUS_DST_ALPHA ) ostr << "GL_ONE_MINUS_DST_ALPHA";
	#endif
	#ifdef GL_DST_COLOR
		else if ( en == GL_DST_COLOR ) ostr << "GL_DST_COLOR";
	#endif
	#ifdef GL_ONE_MINUS_DST_COLOR
		else if ( en == GL_ONE_MINUS_DST_COLOR ) ostr << "GL_ONE_MINUS_DST_COLOR";
	#endif
	#ifdef GL_SRC_ALPHA_SATURATE
		else if ( en == GL_SRC_ALPHA_SATURATE ) ostr << "GL_SRC_ALPHA_SATURATE";
	#endif
	#ifdef GL_STENCIL_BUFFER_BIT
		else if ( en == GL_STENCIL_BUFFER_BIT ) ostr << "GL_STENCIL_BUFFER_BIT";
	#endif
	#ifdef GL_FRONT_LEFT
		else if ( en == GL_FRONT_LEFT ) ostr << "GL_FRONT_LEFT";
	#endif
	#ifdef GL_FRONT_RIGHT
		else if ( en == GL_FRONT_RIGHT ) ostr << "GL_FRONT_RIGHT";
	#endif
	#ifdef GL_BACK_LEFT
		else if ( en == GL_BACK_LEFT ) ostr << "GL_BACK_LEFT";
	#endif
	#ifdef GL_BACK_RIGHT
		else if ( en == GL_BACK_RIGHT ) ostr << "GL_BACK_RIGHT";
	#endif
	#ifdef GL_FRONT
		else if ( en == GL_FRONT ) ostr << "GL_FRONT";
	#endif
	#ifdef GL_BACK
		else if ( en == GL_BACK ) ostr << "GL_BACK";
	#endif
	#ifdef GL_LEFT
		else if ( en == GL_LEFT ) ostr << "GL_LEFT";
	#endif
	#ifdef GL_RIGHT
		else if ( en == GL_RIGHT ) ostr << "GL_RIGHT";
	#endif
	#ifdef GL_FRONT_AND_BACK
		else if ( en == GL_FRONT_AND_BACK ) ostr << "GL_FRONT_AND_BACK";
	#endif
	#ifdef GL_AUX0
		else if ( en == GL_AUX0 ) ostr << "GL_AUX0";
	#endif
	#ifdef GL_AUX1
		else if ( en == GL_AUX1 ) ostr << "GL_AUX1";
	#endif
	#ifdef GL_AUX2
		else if ( en == GL_AUX2 ) ostr << "GL_AUX2";
	#endif
	#ifdef GL_AUX3
		else if ( en == GL_AUX3 ) ostr << "GL_AUX3";
	#endif
	#ifdef GL_INVALID_ENUM
		else if ( en == GL_INVALID_ENUM ) ostr << "GL_INVALID_ENUM";
	#endif
	#ifdef GL_INVALID_VALUE
		else if ( en == GL_INVALID_VALUE ) ostr << "GL_INVALID_VALUE";
	#endif
	#ifdef GL_INVALID_OPERATION
		else if ( en == GL_INVALID_OPERATION ) ostr << "GL_INVALID_OPERATION";
	#endif
	#ifdef GL_STACK_OVERFLOW
		else if ( en == GL_STACK_OVERFLOW ) ostr << "GL_STACK_OVERFLOW";
	#endif
	#ifdef GL_STACK_UNDERFLOW
		else if ( en == GL_STACK_UNDERFLOW ) ostr << "GL_STACK_UNDERFLOW";
	#endif
	#ifdef GL_OUT_OF_MEMORY
		else if ( en == GL_OUT_OF_MEMORY ) ostr << "GL_OUT_OF_MEMORY";
	#endif
	#ifdef GL_2D
		else if ( en == GL_2D ) ostr << "GL_2D";
	#endif
	#ifdef GL_3D
		else if ( en == GL_3D ) ostr << "GL_3D";
	#endif
	#ifdef GL_3D_COLOR
		else if ( en == GL_3D_COLOR ) ostr << "GL_3D_COLOR";
	#endif
	#ifdef GL_3D_COLOR_TEXTURE
		else if ( en == GL_3D_COLOR_TEXTURE ) ostr << "GL_3D_COLOR_TEXTURE";
	#endif
	#ifdef GL_4D_COLOR_TEXTURE
		else if ( en == GL_4D_COLOR_TEXTURE ) ostr << "GL_4D_COLOR_TEXTURE";
	#endif
	#ifdef GL_PASS_THROUGH_TOKEN
		else if ( en == GL_PASS_THROUGH_TOKEN ) ostr << "GL_PASS_THROUGH_TOKEN";
	#endif
	#ifdef GL_POINT_TOKEN
		else if ( en == GL_POINT_TOKEN ) ostr << "GL_POINT_TOKEN";
	#endif
	#ifdef GL_LINE_TOKEN
		else if ( en == GL_LINE_TOKEN ) ostr << "GL_LINE_TOKEN";
	#endif
	#ifdef GL_POLYGON_TOKEN
		else if ( en == GL_POLYGON_TOKEN ) ostr << "GL_POLYGON_TOKEN";
	#endif
	#ifdef GL_BITMAP_TOKEN
		else if ( en == GL_BITMAP_TOKEN ) ostr << "GL_BITMAP_TOKEN";
	#endif
	#ifdef GL_DRAW_PIXEL_TOKEN
		else if ( en == GL_DRAW_PIXEL_TOKEN ) ostr << "GL_DRAW_PIXEL_TOKEN";
	#endif
	#ifdef GL_COPY_PIXEL_TOKEN
		else if ( en == GL_COPY_PIXEL_TOKEN ) ostr << "GL_COPY_PIXEL_TOKEN";
	#endif
	#ifdef GL_LINE_RESET_TOKEN
		else if ( en == GL_LINE_RESET_TOKEN ) ostr << "GL_LINE_RESET_TOKEN";
	#endif
	#ifdef GL_EXP
		else if ( en == GL_EXP ) ostr << "GL_EXP";
	#endif
	#ifdef GL_VIEWPORT_BIT
		else if ( en == GL_VIEWPORT_BIT ) ostr << "GL_VIEWPORT_BIT";
	#endif
	#ifdef GL_EXP2
		else if ( en == GL_EXP2 ) ostr << "GL_EXP2";
	#endif
	#ifdef GL_CW
		else if ( en == GL_CW ) ostr << "GL_CW";
	#endif
	#ifdef GL_CCW
		else if ( en == GL_CCW ) ostr << "GL_CCW";
	#endif
	#ifdef GL_COEFF
		else if ( en == GL_COEFF ) ostr << "GL_COEFF";
	#endif
	#ifdef GL_ORDER
		else if ( en == GL_ORDER ) ostr << "GL_ORDER";
	#endif
	#ifdef GL_DOMAIN
		else if ( en == GL_DOMAIN ) ostr << "GL_DOMAIN";
	#endif
	#ifdef GL_CURRENT_COLOR
		else if ( en == GL_CURRENT_COLOR ) ostr << "GL_CURRENT_COLOR";
	#endif
	#ifdef GL_CURRENT_INDEX
		else if ( en == GL_CURRENT_INDEX ) ostr << "GL_CURRENT_INDEX";
	#endif
	#ifdef GL_CURRENT_NORMAL
		else if ( en == GL_CURRENT_NORMAL ) ostr << "GL_CURRENT_NORMAL";
	#endif
	#ifdef GL_CURRENT_TEXTURE_COORDS
		else if ( en == GL_CURRENT_TEXTURE_COORDS ) ostr << "GL_CURRENT_TEXTURE_COORDS";
	#endif
	#ifdef GL_CURRENT_RASTER_COLOR
		else if ( en == GL_CURRENT_RASTER_COLOR ) ostr << "GL_CURRENT_RASTER_COLOR";
	#endif
	#ifdef GL_CURRENT_RASTER_INDEX
		else if ( en == GL_CURRENT_RASTER_INDEX ) ostr << "GL_CURRENT_RASTER_INDEX";
	#endif
	#ifdef GL_CURRENT_RASTER_TEXTURE_COORDS
		else if ( en == GL_CURRENT_RASTER_TEXTURE_COORDS ) ostr << "GL_CURRENT_RASTER_TEXTURE_COORDS";
	#endif
	#ifdef GL_CURRENT_RASTER_POSITION
		else if ( en == GL_CURRENT_RASTER_POSITION ) ostr << "GL_CURRENT_RASTER_POSITION";
	#endif
	#ifdef GL_CURRENT_RASTER_POSITION_VALID
		else if ( en == GL_CURRENT_RASTER_POSITION_VALID ) ostr << "GL_CURRENT_RASTER_POSITION_VALID";
	#endif
	#ifdef GL_CURRENT_RASTER_DISTANCE
		else if ( en == GL_CURRENT_RASTER_DISTANCE ) ostr << "GL_CURRENT_RASTER_DISTANCE";
	#endif
	#ifdef GL_POINT_SMOOTH
		else if ( en == GL_POINT_SMOOTH ) ostr << "GL_POINT_SMOOTH";
	#endif
	#ifdef GL_POINT_SIZE
		else if ( en == GL_POINT_SIZE ) ostr << "GL_POINT_SIZE";
	#endif
	#ifdef GL_POINT_SIZE_RANGE
		else if ( en == GL_POINT_SIZE_RANGE ) ostr << "GL_POINT_SIZE_RANGE";
	#endif
	#ifdef GL_POINT_SIZE_GRANULARITY
		else if ( en == GL_POINT_SIZE_GRANULARITY ) ostr << "GL_POINT_SIZE_GRANULARITY";
	#endif
	#ifdef GL_LINE_SMOOTH
		else if ( en == GL_LINE_SMOOTH ) ostr << "GL_LINE_SMOOTH";
	#endif
	#ifdef GL_LINE_WIDTH
		else if ( en == GL_LINE_WIDTH ) ostr << "GL_LINE_WIDTH";
	#endif
	#ifdef GL_LINE_WIDTH_RANGE
		else if ( en == GL_LINE_WIDTH_RANGE ) ostr << "GL_LINE_WIDTH_RANGE";
	#endif
	#ifdef GL_LINE_WIDTH_GRANULARITY
		else if ( en == GL_LINE_WIDTH_GRANULARITY ) ostr << "GL_LINE_WIDTH_GRANULARITY";
	#endif
	#ifdef GL_LINE_STIPPLE
		else if ( en == GL_LINE_STIPPLE ) ostr << "GL_LINE_STIPPLE";
	#endif
	#ifdef GL_LINE_STIPPLE_PATTERN
		else if ( en == GL_LINE_STIPPLE_PATTERN ) ostr << "GL_LINE_STIPPLE_PATTERN";
	#endif
	#ifdef GL_LINE_STIPPLE_REPEAT
		else if ( en == GL_LINE_STIPPLE_REPEAT ) ostr << "GL_LINE_STIPPLE_REPEAT";
	#endif
	#ifdef GL_LIST_MODE
		else if ( en == GL_LIST_MODE ) ostr << "GL_LIST_MODE";
	#endif
	#ifdef GL_MAX_LIST_NESTING
		else if ( en == GL_MAX_LIST_NESTING ) ostr << "GL_MAX_LIST_NESTING";
	#endif
	#ifdef GL_LIST_BASE
		else if ( en == GL_LIST_BASE ) ostr << "GL_LIST_BASE";
	#endif
	#ifdef GL_LIST_INDEX
		else if ( en == GL_LIST_INDEX ) ostr << "GL_LIST_INDEX";
	#endif
	#ifdef GL_POLYGON_MODE
		else if ( en == GL_POLYGON_MODE ) ostr << "GL_POLYGON_MODE";
	#endif
	#ifdef GL_POLYGON_SMOOTH
		else if ( en == GL_POLYGON_SMOOTH ) ostr << "GL_POLYGON_SMOOTH";
	#endif
	#ifdef GL_POLYGON_STIPPLE
		else if ( en == GL_POLYGON_STIPPLE ) ostr << "GL_POLYGON_STIPPLE";
	#endif
	#ifdef GL_EDGE_FLAG
		else if ( en == GL_EDGE_FLAG ) ostr << "GL_EDGE_FLAG";
	#endif
	#ifdef GL_CULL_FACE
		else if ( en == GL_CULL_FACE ) ostr << "GL_CULL_FACE";
	#endif
	#ifdef GL_CULL_FACE_MODE
		else if ( en == GL_CULL_FACE_MODE ) ostr << "GL_CULL_FACE_MODE";
	#endif
	#ifdef GL_FRONT_FACE
		else if ( en == GL_FRONT_FACE ) ostr << "GL_FRONT_FACE";
	#endif
	#ifdef GL_LIGHTING
		else if ( en == GL_LIGHTING ) ostr << "GL_LIGHTING";
	#endif
	#ifdef GL_LIGHT_MODEL_LOCAL_VIEWER
		else if ( en == GL_LIGHT_MODEL_LOCAL_VIEWER ) ostr << "GL_LIGHT_MODEL_LOCAL_VIEWER";
	#endif
	#ifdef GL_LIGHT_MODEL_TWO_SIDE
		else if ( en == GL_LIGHT_MODEL_TWO_SIDE ) ostr << "GL_LIGHT_MODEL_TWO_SIDE";
	#endif
	#ifdef GL_LIGHT_MODEL_AMBIENT
		else if ( en == GL_LIGHT_MODEL_AMBIENT ) ostr << "GL_LIGHT_MODEL_AMBIENT";
	#endif
	#ifdef GL_SHADE_MODEL
		else if ( en == GL_SHADE_MODEL ) ostr << "GL_SHADE_MODEL";
	#endif
	#ifdef GL_COLOR_MATERIAL_FACE
		else if ( en == GL_COLOR_MATERIAL_FACE ) ostr << "GL_COLOR_MATERIAL_FACE";
	#endif
	#ifdef GL_COLOR_MATERIAL_PARAMETER
		else if ( en == GL_COLOR_MATERIAL_PARAMETER ) ostr << "GL_COLOR_MATERIAL_PARAMETER";
	#endif
	#ifdef GL_COLOR_MATERIAL
		else if ( en == GL_COLOR_MATERIAL ) ostr << "GL_COLOR_MATERIAL";
	#endif
	#ifdef GL_FOG
		else if ( en == GL_FOG ) ostr << "GL_FOG";
	#endif
	#ifdef GL_FOG_INDEX
		else if ( en == GL_FOG_INDEX ) ostr << "GL_FOG_INDEX";
	#endif
	#ifdef GL_FOG_DENSITY
		else if ( en == GL_FOG_DENSITY ) ostr << "GL_FOG_DENSITY";
	#endif
	#ifdef GL_FOG_START
		else if ( en == GL_FOG_START ) ostr << "GL_FOG_START";
	#endif
	#ifdef GL_FOG_END
		else if ( en == GL_FOG_END ) ostr << "GL_FOG_END";
	#endif
	#ifdef GL_FOG_MODE
		else if ( en == GL_FOG_MODE ) ostr << "GL_FOG_MODE";
	#endif
	#ifdef GL_FOG_COLOR
		else if ( en == GL_FOG_COLOR ) ostr << "GL_FOG_COLOR";
	#endif
	#ifdef GL_DEPTH_RANGE
		else if ( en == GL_DEPTH_RANGE ) ostr << "GL_DEPTH_RANGE";
	#endif
	#ifdef GL_DEPTH_TEST
		else if ( en == GL_DEPTH_TEST ) ostr << "GL_DEPTH_TEST";
	#endif
	#ifdef GL_DEPTH_WRITEMASK
		else if ( en == GL_DEPTH_WRITEMASK ) ostr << "GL_DEPTH_WRITEMASK";
	#endif
	#ifdef GL_DEPTH_CLEAR_VALUE
		else if ( en == GL_DEPTH_CLEAR_VALUE ) ostr << "GL_DEPTH_CLEAR_VALUE";
	#endif
	#ifdef GL_DEPTH_FUNC
		else if ( en == GL_DEPTH_FUNC ) ostr << "GL_DEPTH_FUNC";
	#endif
	#ifdef GL_ACCUM_CLEAR_VALUE
		else if ( en == GL_ACCUM_CLEAR_VALUE ) ostr << "GL_ACCUM_CLEAR_VALUE";
	#endif
	#ifdef GL_STENCIL_TEST
		else if ( en == GL_STENCIL_TEST ) ostr << "GL_STENCIL_TEST";
	#endif
	#ifdef GL_STENCIL_CLEAR_VALUE
		else if ( en == GL_STENCIL_CLEAR_VALUE ) ostr << "GL_STENCIL_CLEAR_VALUE";
	#endif
	#ifdef GL_STENCIL_FUNC
		else if ( en == GL_STENCIL_FUNC ) ostr << "GL_STENCIL_FUNC";
	#endif
	#ifdef GL_STENCIL_VALUE_MASK
		else if ( en == GL_STENCIL_VALUE_MASK ) ostr << "GL_STENCIL_VALUE_MASK";
	#endif
	#ifdef GL_STENCIL_FAIL
		else if ( en == GL_STENCIL_FAIL ) ostr << "GL_STENCIL_FAIL";
	#endif
	#ifdef GL_STENCIL_PASS_DEPTH_FAIL
		else if ( en == GL_STENCIL_PASS_DEPTH_FAIL ) ostr << "GL_STENCIL_PASS_DEPTH_FAIL";
	#endif
	#ifdef GL_STENCIL_PASS_DEPTH_PASS
		else if ( en == GL_STENCIL_PASS_DEPTH_PASS ) ostr << "GL_STENCIL_PASS_DEPTH_PASS";
	#endif
	#ifdef GL_STENCIL_REF
		else if ( en == GL_STENCIL_REF ) ostr << "GL_STENCIL_REF";
	#endif
	#ifdef GL_STENCIL_WRITEMASK
		else if ( en == GL_STENCIL_WRITEMASK ) ostr << "GL_STENCIL_WRITEMASK";
	#endif
	#ifdef GL_MATRIX_MODE
		else if ( en == GL_MATRIX_MODE ) ostr << "GL_MATRIX_MODE";
	#endif
	#ifdef GL_NORMALIZE
		else if ( en == GL_NORMALIZE ) ostr << "GL_NORMALIZE";
	#endif
	#ifdef GL_VIEWPORT
		else if ( en == GL_VIEWPORT ) ostr << "GL_VIEWPORT";
	#endif
	#ifdef GL_MODELVIEW_STACK_DEPTH
		else if ( en == GL_MODELVIEW_STACK_DEPTH ) ostr << "GL_MODELVIEW_STACK_DEPTH";
	#endif
	#ifdef GL_PROJECTION_STACK_DEPTH
		else if ( en == GL_PROJECTION_STACK_DEPTH ) ostr << "GL_PROJECTION_STACK_DEPTH";
	#endif
	#ifdef GL_TEXTURE_STACK_DEPTH
		else if ( en == GL_TEXTURE_STACK_DEPTH ) ostr << "GL_TEXTURE_STACK_DEPTH";
	#endif
	#ifdef GL_MODELVIEW_MATRIX
		else if ( en == GL_MODELVIEW_MATRIX ) ostr << "GL_MODELVIEW_MATRIX";
	#endif
	#ifdef GL_PROJECTION_MATRIX
		else if ( en == GL_PROJECTION_MATRIX ) ostr << "GL_PROJECTION_MATRIX";
	#endif
	#ifdef GL_TEXTURE_MATRIX
		else if ( en == GL_TEXTURE_MATRIX ) ostr << "GL_TEXTURE_MATRIX";
	#endif
	#ifdef GL_ATTRIB_STACK_DEPTH
		else if ( en == GL_ATTRIB_STACK_DEPTH ) ostr << "GL_ATTRIB_STACK_DEPTH";
	#endif
	#ifdef GL_CLIENT_ATTRIB_STACK_DEPTH
		else if ( en == GL_CLIENT_ATTRIB_STACK_DEPTH ) ostr << "GL_CLIENT_ATTRIB_STACK_DEPTH";
	#endif
	#ifdef GL_ALPHA_TEST
		else if ( en == GL_ALPHA_TEST ) ostr << "GL_ALPHA_TEST";
	#endif
	#ifdef GL_ALPHA_TEST_FUNC
		else if ( en == GL_ALPHA_TEST_FUNC ) ostr << "GL_ALPHA_TEST_FUNC";
	#endif
	#ifdef GL_ALPHA_TEST_REF
		else if ( en == GL_ALPHA_TEST_REF ) ostr << "GL_ALPHA_TEST_REF";
	#endif
	#ifdef GL_DITHER
		else if ( en == GL_DITHER ) ostr << "GL_DITHER";
	#endif
	#ifdef GL_BLEND_DST
		else if ( en == GL_BLEND_DST ) ostr << "GL_BLEND_DST";
	#endif
	#ifdef GL_BLEND_SRC
		else if ( en == GL_BLEND_SRC ) ostr << "GL_BLEND_SRC";
	#endif
	#ifdef GL_BLEND
		else if ( en == GL_BLEND ) ostr << "GL_BLEND";
	#endif
	#ifdef GL_LOGIC_OP_MODE
		else if ( en == GL_LOGIC_OP_MODE ) ostr << "GL_LOGIC_OP_MODE";
	#endif
	#ifdef GL_INDEX_LOGIC_OP
		else if ( en == GL_INDEX_LOGIC_OP ) ostr << "GL_INDEX_LOGIC_OP";
	#endif
	#ifdef GL_COLOR_LOGIC_OP
		else if ( en == GL_COLOR_LOGIC_OP ) ostr << "GL_COLOR_LOGIC_OP";
	#endif
	#ifdef GL_AUX_BUFFERS
		else if ( en == GL_AUX_BUFFERS ) ostr << "GL_AUX_BUFFERS";
	#endif
	#ifdef GL_DRAW_BUFFER
		else if ( en == GL_DRAW_BUFFER ) ostr << "GL_DRAW_BUFFER";
	#endif
	#ifdef GL_READ_BUFFER
		else if ( en == GL_READ_BUFFER ) ostr << "GL_READ_BUFFER";
	#endif
	#ifdef GL_SCISSOR_BOX
		else if ( en == GL_SCISSOR_BOX ) ostr << "GL_SCISSOR_BOX";
	#endif
	#ifdef GL_SCISSOR_TEST
		else if ( en == GL_SCISSOR_TEST ) ostr << "GL_SCISSOR_TEST";
	#endif
	#ifdef GL_INDEX_CLEAR_VALUE
		else if ( en == GL_INDEX_CLEAR_VALUE ) ostr << "GL_INDEX_CLEAR_VALUE";
	#endif
	#ifdef GL_INDEX_WRITEMASK
		else if ( en == GL_INDEX_WRITEMASK ) ostr << "GL_INDEX_WRITEMASK";
	#endif
	#ifdef GL_COLOR_CLEAR_VALUE
		else if ( en == GL_COLOR_CLEAR_VALUE ) ostr << "GL_COLOR_CLEAR_VALUE";
	#endif
	#ifdef GL_COLOR_WRITEMASK
		else if ( en == GL_COLOR_WRITEMASK ) ostr << "GL_COLOR_WRITEMASK";
	#endif
	#ifdef GL_INDEX_MODE
		else if ( en == GL_INDEX_MODE ) ostr << "GL_INDEX_MODE";
	#endif
	#ifdef GL_RGBA_MODE
		else if ( en == GL_RGBA_MODE ) ostr << "GL_RGBA_MODE";
	#endif
	#ifdef GL_DOUBLEBUFFER
		else if ( en == GL_DOUBLEBUFFER ) ostr << "GL_DOUBLEBUFFER";
	#endif
	#ifdef GL_STEREO
		else if ( en == GL_STEREO ) ostr << "GL_STEREO";
	#endif
	#ifdef GL_RENDER_MODE
		else if ( en == GL_RENDER_MODE ) ostr << "GL_RENDER_MODE";
	#endif
	#ifdef GL_PERSPECTIVE_CORRECTION_HINT
		else if ( en == GL_PERSPECTIVE_CORRECTION_HINT ) ostr << "GL_PERSPECTIVE_CORRECTION_HINT";
	#endif
	#ifdef GL_POINT_SMOOTH_HINT
		else if ( en == GL_POINT_SMOOTH_HINT ) ostr << "GL_POINT_SMOOTH_HINT";
	#endif
	#ifdef GL_LINE_SMOOTH_HINT
		else if ( en == GL_LINE_SMOOTH_HINT ) ostr << "GL_LINE_SMOOTH_HINT";
	#endif
	#ifdef GL_POLYGON_SMOOTH_HINT
		else if ( en == GL_POLYGON_SMOOTH_HINT ) ostr << "GL_POLYGON_SMOOTH_HINT";
	#endif
	#ifdef GL_FOG_HINT
		else if ( en == GL_FOG_HINT ) ostr << "GL_FOG_HINT";
	#endif
	#ifdef GL_TEXTURE_GEN_S
		else if ( en == GL_TEXTURE_GEN_S ) ostr << "GL_TEXTURE_GEN_S";
	#endif
	#ifdef GL_TEXTURE_GEN_T
		else if ( en == GL_TEXTURE_GEN_T ) ostr << "GL_TEXTURE_GEN_T";
	#endif
	#ifdef GL_TEXTURE_GEN_R
		else if ( en == GL_TEXTURE_GEN_R ) ostr << "GL_TEXTURE_GEN_R";
	#endif
	#ifdef GL_TEXTURE_GEN_Q
		else if ( en == GL_TEXTURE_GEN_Q ) ostr << "GL_TEXTURE_GEN_Q";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_I
		else if ( en == GL_PIXEL_MAP_I_TO_I ) ostr << "GL_PIXEL_MAP_I_TO_I";
	#endif
	#ifdef GL_PIXEL_MAP_S_TO_S
		else if ( en == GL_PIXEL_MAP_S_TO_S ) ostr << "GL_PIXEL_MAP_S_TO_S";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_R
		else if ( en == GL_PIXEL_MAP_I_TO_R ) ostr << "GL_PIXEL_MAP_I_TO_R";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_G
		else if ( en == GL_PIXEL_MAP_I_TO_G ) ostr << "GL_PIXEL_MAP_I_TO_G";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_B
		else if ( en == GL_PIXEL_MAP_I_TO_B ) ostr << "GL_PIXEL_MAP_I_TO_B";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_A
		else if ( en == GL_PIXEL_MAP_I_TO_A ) ostr << "GL_PIXEL_MAP_I_TO_A";
	#endif
	#ifdef GL_PIXEL_MAP_R_TO_R
		else if ( en == GL_PIXEL_MAP_R_TO_R ) ostr << "GL_PIXEL_MAP_R_TO_R";
	#endif
	#ifdef GL_PIXEL_MAP_G_TO_G
		else if ( en == GL_PIXEL_MAP_G_TO_G ) ostr << "GL_PIXEL_MAP_G_TO_G";
	#endif
	#ifdef GL_PIXEL_MAP_B_TO_B
		else if ( en == GL_PIXEL_MAP_B_TO_B ) ostr << "GL_PIXEL_MAP_B_TO_B";
	#endif
	#ifdef GL_PIXEL_MAP_A_TO_A
		else if ( en == GL_PIXEL_MAP_A_TO_A ) ostr << "GL_PIXEL_MAP_A_TO_A";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_I_SIZE
		else if ( en == GL_PIXEL_MAP_I_TO_I_SIZE ) ostr << "GL_PIXEL_MAP_I_TO_I_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_S_TO_S_SIZE
		else if ( en == GL_PIXEL_MAP_S_TO_S_SIZE ) ostr << "GL_PIXEL_MAP_S_TO_S_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_R_SIZE
		else if ( en == GL_PIXEL_MAP_I_TO_R_SIZE ) ostr << "GL_PIXEL_MAP_I_TO_R_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_G_SIZE
		else if ( en == GL_PIXEL_MAP_I_TO_G_SIZE ) ostr << "GL_PIXEL_MAP_I_TO_G_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_B_SIZE
		else if ( en == GL_PIXEL_MAP_I_TO_B_SIZE ) ostr << "GL_PIXEL_MAP_I_TO_B_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_I_TO_A_SIZE
		else if ( en == GL_PIXEL_MAP_I_TO_A_SIZE ) ostr << "GL_PIXEL_MAP_I_TO_A_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_R_TO_R_SIZE
		else if ( en == GL_PIXEL_MAP_R_TO_R_SIZE ) ostr << "GL_PIXEL_MAP_R_TO_R_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_G_TO_G_SIZE
		else if ( en == GL_PIXEL_MAP_G_TO_G_SIZE ) ostr << "GL_PIXEL_MAP_G_TO_G_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_B_TO_B_SIZE
		else if ( en == GL_PIXEL_MAP_B_TO_B_SIZE ) ostr << "GL_PIXEL_MAP_B_TO_B_SIZE";
	#endif
	#ifdef GL_PIXEL_MAP_A_TO_A_SIZE
		else if ( en == GL_PIXEL_MAP_A_TO_A_SIZE ) ostr << "GL_PIXEL_MAP_A_TO_A_SIZE";
	#endif
	#ifdef GL_UNPACK_SWAP_BYTES
		else if ( en == GL_UNPACK_SWAP_BYTES ) ostr << "GL_UNPACK_SWAP_BYTES";
	#endif
	#ifdef GL_UNPACK_LSB_FIRST
		else if ( en == GL_UNPACK_LSB_FIRST ) ostr << "GL_UNPACK_LSB_FIRST";
	#endif
	#ifdef GL_UNPACK_ROW_LENGTH
		else if ( en == GL_UNPACK_ROW_LENGTH ) ostr << "GL_UNPACK_ROW_LENGTH";
	#endif
	#ifdef GL_UNPACK_SKIP_ROWS
		else if ( en == GL_UNPACK_SKIP_ROWS ) ostr << "GL_UNPACK_SKIP_ROWS";
	#endif
	#ifdef GL_UNPACK_SKIP_PIXELS
		else if ( en == GL_UNPACK_SKIP_PIXELS ) ostr << "GL_UNPACK_SKIP_PIXELS";
	#endif
	#ifdef GL_UNPACK_ALIGNMENT
		else if ( en == GL_UNPACK_ALIGNMENT ) ostr << "GL_UNPACK_ALIGNMENT";
	#endif
	#ifdef GL_PACK_SWAP_BYTES
		else if ( en == GL_PACK_SWAP_BYTES ) ostr << "GL_PACK_SWAP_BYTES";
	#endif
	#ifdef GL_PACK_LSB_FIRST
		else if ( en == GL_PACK_LSB_FIRST ) ostr << "GL_PACK_LSB_FIRST";
	#endif
	#ifdef GL_PACK_ROW_LENGTH
		else if ( en == GL_PACK_ROW_LENGTH ) ostr << "GL_PACK_ROW_LENGTH";
	#endif
	#ifdef GL_PACK_SKIP_ROWS
		else if ( en == GL_PACK_SKIP_ROWS ) ostr << "GL_PACK_SKIP_ROWS";
	#endif
	#ifdef GL_PACK_SKIP_PIXELS
		else if ( en == GL_PACK_SKIP_PIXELS ) ostr << "GL_PACK_SKIP_PIXELS";
	#endif
	#ifdef GL_PACK_ALIGNMENT
		else if ( en == GL_PACK_ALIGNMENT ) ostr << "GL_PACK_ALIGNMENT";
	#endif
	#ifdef GL_MAP_COLOR
		else if ( en == GL_MAP_COLOR ) ostr << "GL_MAP_COLOR";
	#endif
	#ifdef GL_MAP_STENCIL
		else if ( en == GL_MAP_STENCIL ) ostr << "GL_MAP_STENCIL";
	#endif
	#ifdef GL_INDEX_SHIFT
		else if ( en == GL_INDEX_SHIFT ) ostr << "GL_INDEX_SHIFT";
	#endif
	#ifdef GL_INDEX_OFFSET
		else if ( en == GL_INDEX_OFFSET ) ostr << "GL_INDEX_OFFSET";
	#endif
	#ifdef GL_RED_SCALE
		else if ( en == GL_RED_SCALE ) ostr << "GL_RED_SCALE";
	#endif
	#ifdef GL_RED_BIAS
		else if ( en == GL_RED_BIAS ) ostr << "GL_RED_BIAS";
	#endif
	#ifdef GL_ZOOM_X
		else if ( en == GL_ZOOM_X ) ostr << "GL_ZOOM_X";
	#endif
	#ifdef GL_ZOOM_Y
		else if ( en == GL_ZOOM_Y ) ostr << "GL_ZOOM_Y";
	#endif
	#ifdef GL_GREEN_SCALE
		else if ( en == GL_GREEN_SCALE ) ostr << "GL_GREEN_SCALE";
	#endif
	#ifdef GL_GREEN_BIAS
		else if ( en == GL_GREEN_BIAS ) ostr << "GL_GREEN_BIAS";
	#endif
	#ifdef GL_BLUE_SCALE
		else if ( en == GL_BLUE_SCALE ) ostr << "GL_BLUE_SCALE";
	#endif
	#ifdef GL_BLUE_BIAS
		else if ( en == GL_BLUE_BIAS ) ostr << "GL_BLUE_BIAS";
	#endif
	#ifdef GL_ALPHA_SCALE
		else if ( en == GL_ALPHA_SCALE ) ostr << "GL_ALPHA_SCALE";
	#endif
	#ifdef GL_ALPHA_BIAS
		else if ( en == GL_ALPHA_BIAS ) ostr << "GL_ALPHA_BIAS";
	#endif
	#ifdef GL_DEPTH_SCALE
		else if ( en == GL_DEPTH_SCALE ) ostr << "GL_DEPTH_SCALE";
	#endif
	#ifdef GL_DEPTH_BIAS
		else if ( en == GL_DEPTH_BIAS ) ostr << "GL_DEPTH_BIAS";
	#endif
	#ifdef GL_MAX_EVAL_ORDER
		else if ( en == GL_MAX_EVAL_ORDER ) ostr << "GL_MAX_EVAL_ORDER";
	#endif
	#ifdef GL_MAX_LIGHTS
		else if ( en == GL_MAX_LIGHTS ) ostr << "GL_MAX_LIGHTS";
	#endif
	#ifdef GL_MAX_CLIP_PLANES
		else if ( en == GL_MAX_CLIP_PLANES ) ostr << "GL_MAX_CLIP_PLANES";
	#endif
	#ifdef GL_MAX_TEXTURE_SIZE
		else if ( en == GL_MAX_TEXTURE_SIZE ) ostr << "GL_MAX_TEXTURE_SIZE";
	#endif
	#ifdef GL_MAX_PIXEL_MAP_TABLE
		else if ( en == GL_MAX_PIXEL_MAP_TABLE ) ostr << "GL_MAX_PIXEL_MAP_TABLE";
	#endif
	#ifdef GL_MAX_ATTRIB_STACK_DEPTH
		else if ( en == GL_MAX_ATTRIB_STACK_DEPTH ) ostr << "GL_MAX_ATTRIB_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_MODELVIEW_STACK_DEPTH
		else if ( en == GL_MAX_MODELVIEW_STACK_DEPTH ) ostr << "GL_MAX_MODELVIEW_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_NAME_STACK_DEPTH
		else if ( en == GL_MAX_NAME_STACK_DEPTH ) ostr << "GL_MAX_NAME_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_PROJECTION_STACK_DEPTH
		else if ( en == GL_MAX_PROJECTION_STACK_DEPTH ) ostr << "GL_MAX_PROJECTION_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_TEXTURE_STACK_DEPTH
		else if ( en == GL_MAX_TEXTURE_STACK_DEPTH ) ostr << "GL_MAX_TEXTURE_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_VIEWPORT_DIMS
		else if ( en == GL_MAX_VIEWPORT_DIMS ) ostr << "GL_MAX_VIEWPORT_DIMS";
	#endif
	#ifdef GL_MAX_CLIENT_ATTRIB_STACK_DEPTH
		else if ( en == GL_MAX_CLIENT_ATTRIB_STACK_DEPTH ) ostr << "GL_MAX_CLIENT_ATTRIB_STACK_DEPTH";
	#endif
	#ifdef GL_SUBPIXEL_BITS
		else if ( en == GL_SUBPIXEL_BITS ) ostr << "GL_SUBPIXEL_BITS";
	#endif
	#ifdef GL_INDEX_BITS
		else if ( en == GL_INDEX_BITS ) ostr << "GL_INDEX_BITS";
	#endif
	#ifdef GL_RED_BITS
		else if ( en == GL_RED_BITS ) ostr << "GL_RED_BITS";
	#endif
	#ifdef GL_GREEN_BITS
		else if ( en == GL_GREEN_BITS ) ostr << "GL_GREEN_BITS";
	#endif
	#ifdef GL_BLUE_BITS
		else if ( en == GL_BLUE_BITS ) ostr << "GL_BLUE_BITS";
	#endif
	#ifdef GL_ALPHA_BITS
		else if ( en == GL_ALPHA_BITS ) ostr << "GL_ALPHA_BITS";
	#endif
	#ifdef GL_DEPTH_BITS
		else if ( en == GL_DEPTH_BITS ) ostr << "GL_DEPTH_BITS";
	#endif
	#ifdef GL_STENCIL_BITS
		else if ( en == GL_STENCIL_BITS ) ostr << "GL_STENCIL_BITS";
	#endif
	#ifdef GL_ACCUM_RED_BITS
		else if ( en == GL_ACCUM_RED_BITS ) ostr << "GL_ACCUM_RED_BITS";
	#endif
	#ifdef GL_ACCUM_GREEN_BITS
		else if ( en == GL_ACCUM_GREEN_BITS ) ostr << "GL_ACCUM_GREEN_BITS";
	#endif
	#ifdef GL_ACCUM_BLUE_BITS
		else if ( en == GL_ACCUM_BLUE_BITS ) ostr << "GL_ACCUM_BLUE_BITS";
	#endif
	#ifdef GL_ACCUM_ALPHA_BITS
		else if ( en == GL_ACCUM_ALPHA_BITS ) ostr << "GL_ACCUM_ALPHA_BITS";
	#endif
	#ifdef GL_NAME_STACK_DEPTH
		else if ( en == GL_NAME_STACK_DEPTH ) ostr << "GL_NAME_STACK_DEPTH";
	#endif
	#ifdef GL_AUTO_NORMAL
		else if ( en == GL_AUTO_NORMAL ) ostr << "GL_AUTO_NORMAL";
	#endif
	#ifdef GL_MAP1_COLOR_4
		else if ( en == GL_MAP1_COLOR_4 ) ostr << "GL_MAP1_COLOR_4";
	#endif
	#ifdef GL_MAP1_INDEX
		else if ( en == GL_MAP1_INDEX ) ostr << "GL_MAP1_INDEX";
	#endif
	#ifdef GL_MAP1_NORMAL
		else if ( en == GL_MAP1_NORMAL ) ostr << "GL_MAP1_NORMAL";
	#endif
	#ifdef GL_MAP1_TEXTURE_COORD_1
		else if ( en == GL_MAP1_TEXTURE_COORD_1 ) ostr << "GL_MAP1_TEXTURE_COORD_1";
	#endif
	#ifdef GL_MAP1_TEXTURE_COORD_2
		else if ( en == GL_MAP1_TEXTURE_COORD_2 ) ostr << "GL_MAP1_TEXTURE_COORD_2";
	#endif
	#ifdef GL_MAP1_TEXTURE_COORD_3
		else if ( en == GL_MAP1_TEXTURE_COORD_3 ) ostr << "GL_MAP1_TEXTURE_COORD_3";
	#endif
	#ifdef GL_MAP1_TEXTURE_COORD_4
		else if ( en == GL_MAP1_TEXTURE_COORD_4 ) ostr << "GL_MAP1_TEXTURE_COORD_4";
	#endif
	#ifdef GL_MAP1_VERTEX_3
		else if ( en == GL_MAP1_VERTEX_3 ) ostr << "GL_MAP1_VERTEX_3";
	#endif
	#ifdef GL_MAP1_VERTEX_4
		else if ( en == GL_MAP1_VERTEX_4 ) ostr << "GL_MAP1_VERTEX_4";
	#endif
	#ifdef GL_MAP2_COLOR_4
		else if ( en == GL_MAP2_COLOR_4 ) ostr << "GL_MAP2_COLOR_4";
	#endif
	#ifdef GL_MAP2_INDEX
		else if ( en == GL_MAP2_INDEX ) ostr << "GL_MAP2_INDEX";
	#endif
	#ifdef GL_MAP2_NORMAL
		else if ( en == GL_MAP2_NORMAL ) ostr << "GL_MAP2_NORMAL";
	#endif
	#ifdef GL_MAP2_TEXTURE_COORD_1
		else if ( en == GL_MAP2_TEXTURE_COORD_1 ) ostr << "GL_MAP2_TEXTURE_COORD_1";
	#endif
	#ifdef GL_MAP2_TEXTURE_COORD_2
		else if ( en == GL_MAP2_TEXTURE_COORD_2 ) ostr << "GL_MAP2_TEXTURE_COORD_2";
	#endif
	#ifdef GL_MAP2_TEXTURE_COORD_3
		else if ( en == GL_MAP2_TEXTURE_COORD_3 ) ostr << "GL_MAP2_TEXTURE_COORD_3";
	#endif
	#ifdef GL_MAP2_TEXTURE_COORD_4
		else if ( en == GL_MAP2_TEXTURE_COORD_4 ) ostr << "GL_MAP2_TEXTURE_COORD_4";
	#endif
	#ifdef GL_MAP2_VERTEX_3
		else if ( en == GL_MAP2_VERTEX_3 ) ostr << "GL_MAP2_VERTEX_3";
	#endif
	#ifdef GL_MAP2_VERTEX_4
		else if ( en == GL_MAP2_VERTEX_4 ) ostr << "GL_MAP2_VERTEX_4";
	#endif
	#ifdef GL_MAP1_GRID_DOMAIN
		else if ( en == GL_MAP1_GRID_DOMAIN ) ostr << "GL_MAP1_GRID_DOMAIN";
	#endif
	#ifdef GL_MAP1_GRID_SEGMENTS
		else if ( en == GL_MAP1_GRID_SEGMENTS ) ostr << "GL_MAP1_GRID_SEGMENTS";
	#endif
	#ifdef GL_MAP2_GRID_DOMAIN
		else if ( en == GL_MAP2_GRID_DOMAIN ) ostr << "GL_MAP2_GRID_DOMAIN";
	#endif
	#ifdef GL_MAP2_GRID_SEGMENTS
		else if ( en == GL_MAP2_GRID_SEGMENTS ) ostr << "GL_MAP2_GRID_SEGMENTS";
	#endif
	#ifdef GL_TEXTURE_1D
		else if ( en == GL_TEXTURE_1D ) ostr << "GL_TEXTURE_1D";
	#endif
	#ifdef GL_TEXTURE_2D
		else if ( en == GL_TEXTURE_2D ) ostr << "GL_TEXTURE_2D";
	#endif
	#ifdef GL_FEEDBACK_BUFFER_POINTER
		else if ( en == GL_FEEDBACK_BUFFER_POINTER ) ostr << "GL_FEEDBACK_BUFFER_POINTER";
	#endif
	#ifdef GL_FEEDBACK_BUFFER_SIZE
		else if ( en == GL_FEEDBACK_BUFFER_SIZE ) ostr << "GL_FEEDBACK_BUFFER_SIZE";
	#endif
	#ifdef GL_FEEDBACK_BUFFER_TYPE
		else if ( en == GL_FEEDBACK_BUFFER_TYPE ) ostr << "GL_FEEDBACK_BUFFER_TYPE";
	#endif
	#ifdef GL_SELECTION_BUFFER_POINTER
		else if ( en == GL_SELECTION_BUFFER_POINTER ) ostr << "GL_SELECTION_BUFFER_POINTER";
	#endif
	#ifdef GL_SELECTION_BUFFER_SIZE
		else if ( en == GL_SELECTION_BUFFER_SIZE ) ostr << "GL_SELECTION_BUFFER_SIZE";
	#endif
	#ifdef GL_TEXTURE_WIDTH
		else if ( en == GL_TEXTURE_WIDTH ) ostr << "GL_TEXTURE_WIDTH";
	#endif
	#ifdef GL_TRANSFORM_BIT
		else if ( en == GL_TRANSFORM_BIT ) ostr << "GL_TRANSFORM_BIT";
	#endif
	#ifdef GL_TEXTURE_HEIGHT
		else if ( en == GL_TEXTURE_HEIGHT ) ostr << "GL_TEXTURE_HEIGHT";
	#endif
	#ifdef GL_TEXTURE_INTERNAL_FORMAT
		else if ( en == GL_TEXTURE_INTERNAL_FORMAT ) ostr << "GL_TEXTURE_INTERNAL_FORMAT";
	#endif
	#ifdef GL_TEXTURE_BORDER_COLOR
		else if ( en == GL_TEXTURE_BORDER_COLOR ) ostr << "GL_TEXTURE_BORDER_COLOR";
	#endif
	#ifdef GL_TEXTURE_BORDER
		else if ( en == GL_TEXTURE_BORDER ) ostr << "GL_TEXTURE_BORDER";
	#endif
	#ifdef GL_DONT_CARE
		else if ( en == GL_DONT_CARE ) ostr << "GL_DONT_CARE";
	#endif
	#ifdef GL_FASTEST
		else if ( en == GL_FASTEST ) ostr << "GL_FASTEST";
	#endif
	#ifdef GL_NICEST
		else if ( en == GL_NICEST ) ostr << "GL_NICEST";
	#endif
	#ifdef GL_AMBIENT
		else if ( en == GL_AMBIENT ) ostr << "GL_AMBIENT";
	#endif
	#ifdef GL_DIFFUSE
		else if ( en == GL_DIFFUSE ) ostr << "GL_DIFFUSE";
	#endif
	#ifdef GL_SPECULAR
		else if ( en == GL_SPECULAR ) ostr << "GL_SPECULAR";
	#endif
	#ifdef GL_POSITION
		else if ( en == GL_POSITION ) ostr << "GL_POSITION";
	#endif
	#ifdef GL_SPOT_DIRECTION
		else if ( en == GL_SPOT_DIRECTION ) ostr << "GL_SPOT_DIRECTION";
	#endif
	#ifdef GL_SPOT_EXPONENT
		else if ( en == GL_SPOT_EXPONENT ) ostr << "GL_SPOT_EXPONENT";
	#endif
	#ifdef GL_SPOT_CUTOFF
		else if ( en == GL_SPOT_CUTOFF ) ostr << "GL_SPOT_CUTOFF";
	#endif
	#ifdef GL_CONSTANT_ATTENUATION
		else if ( en == GL_CONSTANT_ATTENUATION ) ostr << "GL_CONSTANT_ATTENUATION";
	#endif
	#ifdef GL_LINEAR_ATTENUATION
		else if ( en == GL_LINEAR_ATTENUATION ) ostr << "GL_LINEAR_ATTENUATION";
	#endif
	#ifdef GL_QUADRATIC_ATTENUATION
		else if ( en == GL_QUADRATIC_ATTENUATION ) ostr << "GL_QUADRATIC_ATTENUATION";
	#endif
	#ifdef GL_COMPILE
		else if ( en == GL_COMPILE ) ostr << "GL_COMPILE";
	#endif
	#ifdef GL_COMPILE_AND_EXECUTE
		else if ( en == GL_COMPILE_AND_EXECUTE ) ostr << "GL_COMPILE_AND_EXECUTE";
	#endif
	#ifdef GL_BYTE
		else if ( en == GL_BYTE ) ostr << "GL_BYTE";
	#endif
	#ifdef GL_UNSIGNED_BYTE
		else if ( en == GL_UNSIGNED_BYTE ) ostr << "GL_UNSIGNED_BYTE";
	#endif
	#ifdef GL_SHORT
		else if ( en == GL_SHORT ) ostr << "GL_SHORT";
	#endif
	#ifdef GL_UNSIGNED_SHORT
		else if ( en == GL_UNSIGNED_SHORT ) ostr << "GL_UNSIGNED_SHORT";
	#endif
	#ifdef GL_INT
		else if ( en == GL_INT ) ostr << "GL_INT";
	#endif
	#ifdef GL_UNSIGNED_INT
		else if ( en == GL_UNSIGNED_INT ) ostr << "GL_UNSIGNED_INT";
	#endif
	#ifdef GL_FLOAT
		else if ( en == GL_FLOAT ) ostr << "GL_FLOAT";
	#endif
	#ifdef GL_2_BYTES
		else if ( en == GL_2_BYTES ) ostr << "GL_2_BYTES";
	#endif
	#ifdef GL_3_BYTES
		else if ( en == GL_3_BYTES ) ostr << "GL_3_BYTES";
	#endif
	#ifdef GL_4_BYTES
		else if ( en == GL_4_BYTES ) ostr << "GL_4_BYTES";
	#endif
	#ifdef GL_DOUBLE
		else if ( en == GL_DOUBLE ) ostr << "GL_DOUBLE";
	#endif
	#ifdef GL_CLEAR
		else if ( en == GL_CLEAR ) ostr << "GL_CLEAR";
	#endif
	#ifdef GL_AND
		else if ( en == GL_AND ) ostr << "GL_AND";
	#endif
	#ifdef GL_AND_REVERSE
		else if ( en == GL_AND_REVERSE ) ostr << "GL_AND_REVERSE";
	#endif
	#ifdef GL_COPY
		else if ( en == GL_COPY ) ostr << "GL_COPY";
	#endif
	#ifdef GL_AND_INVERTED
		else if ( en == GL_AND_INVERTED ) ostr << "GL_AND_INVERTED";
	#endif
	#ifdef GL_NOOP
		else if ( en == GL_NOOP ) ostr << "GL_NOOP";
	#endif
	#ifdef GL_XOR
		else if ( en == GL_XOR ) ostr << "GL_XOR";
	#endif
	#ifdef GL_OR
		else if ( en == GL_OR ) ostr << "GL_OR";
	#endif
	#ifdef GL_NOR
		else if ( en == GL_NOR ) ostr << "GL_NOR";
	#endif
	#ifdef GL_EQUIV
		else if ( en == GL_EQUIV ) ostr << "GL_EQUIV";
	#endif
	#ifdef GL_INVERT
		else if ( en == GL_INVERT ) ostr << "GL_INVERT";
	#endif
	#ifdef GL_OR_REVERSE
		else if ( en == GL_OR_REVERSE ) ostr << "GL_OR_REVERSE";
	#endif
	#ifdef GL_COPY_INVERTED
		else if ( en == GL_COPY_INVERTED ) ostr << "GL_COPY_INVERTED";
	#endif
	#ifdef GL_OR_INVERTED
		else if ( en == GL_OR_INVERTED ) ostr << "GL_OR_INVERTED";
	#endif
	#ifdef GL_NAND
		else if ( en == GL_NAND ) ostr << "GL_NAND";
	#endif
	#ifdef GL_SET
		else if ( en == GL_SET ) ostr << "GL_SET";
	#endif
	#ifdef GL_EMISSION
		else if ( en == GL_EMISSION ) ostr << "GL_EMISSION";
	#endif
	#ifdef GL_SHININESS
		else if ( en == GL_SHININESS ) ostr << "GL_SHININESS";
	#endif
	#ifdef GL_AMBIENT_AND_DIFFUSE
		else if ( en == GL_AMBIENT_AND_DIFFUSE ) ostr << "GL_AMBIENT_AND_DIFFUSE";
	#endif
	#ifdef GL_COLOR_INDEXES
		else if ( en == GL_COLOR_INDEXES ) ostr << "GL_COLOR_INDEXES";
	#endif
	#ifdef GL_MODELVIEW
		else if ( en == GL_MODELVIEW ) ostr << "GL_MODELVIEW";
	#endif
	#ifdef GL_PROJECTION
		else if ( en == GL_PROJECTION ) ostr << "GL_PROJECTION";
	#endif
	#ifdef GL_TEXTURE
		else if ( en == GL_TEXTURE ) ostr << "GL_TEXTURE";
	#endif
	#ifdef GL_COLOR
		else if ( en == GL_COLOR ) ostr << "GL_COLOR";
	#endif
	#ifdef GL_DEPTH
		else if ( en == GL_DEPTH ) ostr << "GL_DEPTH";
	#endif
	#ifdef GL_STENCIL
		else if ( en == GL_STENCIL ) ostr << "GL_STENCIL";
	#endif
	#ifdef GL_COLOR_INDEX
		else if ( en == GL_COLOR_INDEX ) ostr << "GL_COLOR_INDEX";
	#endif
	#ifdef GL_STENCIL_INDEX
		else if ( en == GL_STENCIL_INDEX ) ostr << "GL_STENCIL_INDEX";
	#endif
	#ifdef GL_DEPTH_COMPONENT
		else if ( en == GL_DEPTH_COMPONENT ) ostr << "GL_DEPTH_COMPONENT";
	#endif
	#ifdef GL_RED
		else if ( en == GL_RED ) ostr << "GL_RED";
	#endif
	#ifdef GL_GREEN
		else if ( en == GL_GREEN ) ostr << "GL_GREEN";
	#endif
	#ifdef GL_BLUE
		else if ( en == GL_BLUE ) ostr << "GL_BLUE";
	#endif
	#ifdef GL_ALPHA
		else if ( en == GL_ALPHA ) ostr << "GL_ALPHA";
	#endif
	#ifdef GL_RGB
		else if ( en == GL_RGB ) ostr << "GL_RGB";
	#endif
	#ifdef GL_RGBA
		else if ( en == GL_RGBA ) ostr << "GL_RGBA";
	#endif
	#ifdef GL_LUMINANCE
		else if ( en == GL_LUMINANCE ) ostr << "GL_LUMINANCE";
	#endif
	#ifdef GL_LUMINANCE_ALPHA
		else if ( en == GL_LUMINANCE_ALPHA ) ostr << "GL_LUMINANCE_ALPHA";
	#endif
	#ifdef GL_BITMAP
		else if ( en == GL_BITMAP ) ostr << "GL_BITMAP";
	#endif
	#ifdef GL_POINT
		else if ( en == GL_POINT ) ostr << "GL_POINT";
	#endif
	#ifdef GL_LINE
		else if ( en == GL_LINE ) ostr << "GL_LINE";
	#endif
	#ifdef GL_FILL
		else if ( en == GL_FILL ) ostr << "GL_FILL";
	#endif
	#ifdef GL_RENDER
		else if ( en == GL_RENDER ) ostr << "GL_RENDER";
	#endif
	#ifdef GL_FEEDBACK
		else if ( en == GL_FEEDBACK ) ostr << "GL_FEEDBACK";
	#endif
	#ifdef GL_SELECT
		else if ( en == GL_SELECT ) ostr << "GL_SELECT";
	#endif
	#ifdef GL_FLAT
		else if ( en == GL_FLAT ) ostr << "GL_FLAT";
	#endif
	#ifdef GL_SMOOTH
		else if ( en == GL_SMOOTH ) ostr << "GL_SMOOTH";
	#endif
	#ifdef GL_KEEP
		else if ( en == GL_KEEP ) ostr << "GL_KEEP";
	#endif
	#ifdef GL_REPLACE
		else if ( en == GL_REPLACE ) ostr << "GL_REPLACE";
	#endif
	#ifdef GL_INCR
		else if ( en == GL_INCR ) ostr << "GL_INCR";
	#endif
	#ifdef GL_DECR
		else if ( en == GL_DECR ) ostr << "GL_DECR";
	#endif
	#ifdef GL_VENDOR
		else if ( en == GL_VENDOR ) ostr << "GL_VENDOR";
	#endif
	#ifdef GL_RENDERER
		else if ( en == GL_RENDERER ) ostr << "GL_RENDERER";
	#endif
	#ifdef GL_VERSION
		else if ( en == GL_VERSION ) ostr << "GL_VERSION";
	#endif
	#ifdef GL_EXTENSIONS
		else if ( en == GL_EXTENSIONS ) ostr << "GL_EXTENSIONS";
	#endif
	#ifdef GL_S
		else if ( en == GL_S ) ostr << "GL_S";
	#endif
	#ifdef GL_ENABLE_BIT
		else if ( en == GL_ENABLE_BIT ) ostr << "GL_ENABLE_BIT";
	#endif
	#ifdef GL_T
		else if ( en == GL_T ) ostr << "GL_T";
	#endif
	#ifdef GL_R
		else if ( en == GL_R ) ostr << "GL_R";
	#endif
	#ifdef GL_Q
		else if ( en == GL_Q ) ostr << "GL_Q";
	#endif
	#ifdef GL_MODULATE
		else if ( en == GL_MODULATE ) ostr << "GL_MODULATE";
	#endif
	#ifdef GL_DECAL
		else if ( en == GL_DECAL ) ostr << "GL_DECAL";
	#endif
	#ifdef GL_TEXTURE_ENV_MODE
		else if ( en == GL_TEXTURE_ENV_MODE ) ostr << "GL_TEXTURE_ENV_MODE";
	#endif
	#ifdef GL_TEXTURE_ENV_COLOR
		else if ( en == GL_TEXTURE_ENV_COLOR ) ostr << "GL_TEXTURE_ENV_COLOR";
	#endif
	#ifdef GL_TEXTURE_ENV
		else if ( en == GL_TEXTURE_ENV ) ostr << "GL_TEXTURE_ENV";
	#endif
	#ifdef GL_EYE_LINEAR
		else if ( en == GL_EYE_LINEAR ) ostr << "GL_EYE_LINEAR";
	#endif
	#ifdef GL_OBJECT_LINEAR
		else if ( en == GL_OBJECT_LINEAR ) ostr << "GL_OBJECT_LINEAR";
	#endif
	#ifdef GL_SPHERE_MAP
		else if ( en == GL_SPHERE_MAP ) ostr << "GL_SPHERE_MAP";
	#endif
	#ifdef GL_TEXTURE_GEN_MODE
		else if ( en == GL_TEXTURE_GEN_MODE ) ostr << "GL_TEXTURE_GEN_MODE";
	#endif
	#ifdef GL_OBJECT_PLANE
		else if ( en == GL_OBJECT_PLANE ) ostr << "GL_OBJECT_PLANE";
	#endif
	#ifdef GL_EYE_PLANE
		else if ( en == GL_EYE_PLANE ) ostr << "GL_EYE_PLANE";
	#endif
	#ifdef GL_NEAREST
		else if ( en == GL_NEAREST ) ostr << "GL_NEAREST";
	#endif
	#ifdef GL_LINEAR
		else if ( en == GL_LINEAR ) ostr << "GL_LINEAR";
	#endif
	#ifdef GL_NEAREST_MIPMAP_NEAREST
		else if ( en == GL_NEAREST_MIPMAP_NEAREST ) ostr << "GL_NEAREST_MIPMAP_NEAREST";
	#endif
	#ifdef GL_LINEAR_MIPMAP_NEAREST
		else if ( en == GL_LINEAR_MIPMAP_NEAREST ) ostr << "GL_LINEAR_MIPMAP_NEAREST";
	#endif
	#ifdef GL_NEAREST_MIPMAP_LINEAR
		else if ( en == GL_NEAREST_MIPMAP_LINEAR ) ostr << "GL_NEAREST_MIPMAP_LINEAR";
	#endif
	#ifdef GL_LINEAR_MIPMAP_LINEAR
		else if ( en == GL_LINEAR_MIPMAP_LINEAR ) ostr << "GL_LINEAR_MIPMAP_LINEAR";
	#endif
	#ifdef GL_TEXTURE_MAG_FILTER
		else if ( en == GL_TEXTURE_MAG_FILTER ) ostr << "GL_TEXTURE_MAG_FILTER";
	#endif
	#ifdef GL_TEXTURE_MIN_FILTER
		else if ( en == GL_TEXTURE_MIN_FILTER ) ostr << "GL_TEXTURE_MIN_FILTER";
	#endif
	#ifdef GL_TEXTURE_WRAP_S
		else if ( en == GL_TEXTURE_WRAP_S ) ostr << "GL_TEXTURE_WRAP_S";
	#endif
	#ifdef GL_TEXTURE_WRAP_T
		else if ( en == GL_TEXTURE_WRAP_T ) ostr << "GL_TEXTURE_WRAP_T";
	#endif
	#ifdef GL_CLAMP
		else if ( en == GL_CLAMP ) ostr << "GL_CLAMP";
	#endif
	#ifdef GL_REPEAT
		else if ( en == GL_REPEAT ) ostr << "GL_REPEAT";
	#endif
	#ifdef GL_POLYGON_OFFSET_UNITS
		else if ( en == GL_POLYGON_OFFSET_UNITS ) ostr << "GL_POLYGON_OFFSET_UNITS";
	#endif
	#ifdef GL_POLYGON_OFFSET_POINT
		else if ( en == GL_POLYGON_OFFSET_POINT ) ostr << "GL_POLYGON_OFFSET_POINT";
	#endif
	#ifdef GL_POLYGON_OFFSET_LINE
		else if ( en == GL_POLYGON_OFFSET_LINE ) ostr << "GL_POLYGON_OFFSET_LINE";
	#endif
	#ifdef GL_R3_G3_B2
		else if ( en == GL_R3_G3_B2 ) ostr << "GL_R3_G3_B2";
	#endif
	#ifdef GL_V2F
		else if ( en == GL_V2F ) ostr << "GL_V2F";
	#endif
	#ifdef GL_V3F
		else if ( en == GL_V3F ) ostr << "GL_V3F";
	#endif
	#ifdef GL_C4UB_V2F
		else if ( en == GL_C4UB_V2F ) ostr << "GL_C4UB_V2F";
	#endif
	#ifdef GL_C4UB_V3F
		else if ( en == GL_C4UB_V3F ) ostr << "GL_C4UB_V3F";
	#endif
	#ifdef GL_C3F_V3F
		else if ( en == GL_C3F_V3F ) ostr << "GL_C3F_V3F";
	#endif
	#ifdef GL_N3F_V3F
		else if ( en == GL_N3F_V3F ) ostr << "GL_N3F_V3F";
	#endif
	#ifdef GL_C4F_N3F_V3F
		else if ( en == GL_C4F_N3F_V3F ) ostr << "GL_C4F_N3F_V3F";
	#endif
	#ifdef GL_T2F_V3F
		else if ( en == GL_T2F_V3F ) ostr << "GL_T2F_V3F";
	#endif
	#ifdef GL_T4F_V4F
		else if ( en == GL_T4F_V4F ) ostr << "GL_T4F_V4F";
	#endif
	#ifdef GL_T2F_C4UB_V3F
		else if ( en == GL_T2F_C4UB_V3F ) ostr << "GL_T2F_C4UB_V3F";
	#endif
	#ifdef GL_T2F_C3F_V3F
		else if ( en == GL_T2F_C3F_V3F ) ostr << "GL_T2F_C3F_V3F";
	#endif
	#ifdef GL_T2F_N3F_V3F
		else if ( en == GL_T2F_N3F_V3F ) ostr << "GL_T2F_N3F_V3F";
	#endif
	#ifdef GL_T2F_C4F_N3F_V3F
		else if ( en == GL_T2F_C4F_N3F_V3F ) ostr << "GL_T2F_C4F_N3F_V3F";
	#endif
	#ifdef GL_T4F_C4F_N3F_V4F
		else if ( en == GL_T4F_C4F_N3F_V4F ) ostr << "GL_T4F_C4F_N3F_V4F";
	#endif
	#ifdef GL_CLIP_PLANE0
		else if ( en == GL_CLIP_PLANE0 ) ostr << "GL_CLIP_PLANE0";
	#endif
	#ifdef GL_CLIP_PLANE1
		else if ( en == GL_CLIP_PLANE1 ) ostr << "GL_CLIP_PLANE1";
	#endif
	#ifdef GL_CLIP_PLANE2
		else if ( en == GL_CLIP_PLANE2 ) ostr << "GL_CLIP_PLANE2";
	#endif
	#ifdef GL_CLIP_PLANE3
		else if ( en == GL_CLIP_PLANE3 ) ostr << "GL_CLIP_PLANE3";
	#endif
	#ifdef GL_CLIP_PLANE4
		else if ( en == GL_CLIP_PLANE4 ) ostr << "GL_CLIP_PLANE4";
	#endif
	#ifdef GL_CLIP_PLANE5
		else if ( en == GL_CLIP_PLANE5 ) ostr << "GL_CLIP_PLANE5";
	#endif
	#ifdef GL_LIGHT0
		else if ( en == GL_LIGHT0 ) ostr << "GL_LIGHT0";
	#endif
	#ifdef GL_COLOR_BUFFER_BIT
		else if ( en == GL_COLOR_BUFFER_BIT ) ostr << "GL_COLOR_BUFFER_BIT";
	#endif
	#ifdef GL_LIGHT1
		else if ( en == GL_LIGHT1 ) ostr << "GL_LIGHT1";
	#endif
	#ifdef GL_LIGHT2
		else if ( en == GL_LIGHT2 ) ostr << "GL_LIGHT2";
	#endif
	#ifdef GL_LIGHT3
		else if ( en == GL_LIGHT3 ) ostr << "GL_LIGHT3";
	#endif
	#ifdef GL_LIGHT4
		else if ( en == GL_LIGHT4 ) ostr << "GL_LIGHT4";
	#endif
	#ifdef GL_LIGHT5
		else if ( en == GL_LIGHT5 ) ostr << "GL_LIGHT5";
	#endif
	#ifdef GL_LIGHT6
		else if ( en == GL_LIGHT6 ) ostr << "GL_LIGHT6";
	#endif
	#ifdef GL_LIGHT7
		else if ( en == GL_LIGHT7 ) ostr << "GL_LIGHT7";
	#endif
	#ifdef GL_HINT_BIT
		else if ( en == GL_HINT_BIT ) ostr << "GL_HINT_BIT";
	#endif
	#ifdef GL_POLYGON_OFFSET_FILL
		else if ( en == GL_POLYGON_OFFSET_FILL ) ostr << "GL_POLYGON_OFFSET_FILL";
	#endif
	#ifdef GL_POLYGON_OFFSET_FACTOR
		else if ( en == GL_POLYGON_OFFSET_FACTOR ) ostr << "GL_POLYGON_OFFSET_FACTOR";
	#endif
	#ifdef GL_ALPHA4
		else if ( en == GL_ALPHA4 ) ostr << "GL_ALPHA4";
	#endif
	#ifdef GL_ALPHA8
		else if ( en == GL_ALPHA8 ) ostr << "GL_ALPHA8";
	#endif
	#ifdef GL_ALPHA12
		else if ( en == GL_ALPHA12 ) ostr << "GL_ALPHA12";
	#endif
	#ifdef GL_ALPHA16
		else if ( en == GL_ALPHA16 ) ostr << "GL_ALPHA16";
	#endif
	#ifdef GL_LUMINANCE4
		else if ( en == GL_LUMINANCE4 ) ostr << "GL_LUMINANCE4";
	#endif
	#ifdef GL_LUMINANCE8
		else if ( en == GL_LUMINANCE8 ) ostr << "GL_LUMINANCE8";
	#endif
	#ifdef GL_LUMINANCE12
		else if ( en == GL_LUMINANCE12 ) ostr << "GL_LUMINANCE12";
	#endif
	#ifdef GL_LUMINANCE16
		else if ( en == GL_LUMINANCE16 ) ostr << "GL_LUMINANCE16";
	#endif
	#ifdef GL_LUMINANCE4_ALPHA4
		else if ( en == GL_LUMINANCE4_ALPHA4 ) ostr << "GL_LUMINANCE4_ALPHA4";
	#endif
	#ifdef GL_LUMINANCE6_ALPHA2
		else if ( en == GL_LUMINANCE6_ALPHA2 ) ostr << "GL_LUMINANCE6_ALPHA2";
	#endif
	#ifdef GL_LUMINANCE8_ALPHA8
		else if ( en == GL_LUMINANCE8_ALPHA8 ) ostr << "GL_LUMINANCE8_ALPHA8";
	#endif
	#ifdef GL_LUMINANCE12_ALPHA4
		else if ( en == GL_LUMINANCE12_ALPHA4 ) ostr << "GL_LUMINANCE12_ALPHA4";
	#endif
	#ifdef GL_LUMINANCE12_ALPHA12
		else if ( en == GL_LUMINANCE12_ALPHA12 ) ostr << "GL_LUMINANCE12_ALPHA12";
	#endif
	#ifdef GL_LUMINANCE16_ALPHA16
		else if ( en == GL_LUMINANCE16_ALPHA16 ) ostr << "GL_LUMINANCE16_ALPHA16";
	#endif
	#ifdef GL_INTENSITY
		else if ( en == GL_INTENSITY ) ostr << "GL_INTENSITY";
	#endif
	#ifdef GL_INTENSITY4
		else if ( en == GL_INTENSITY4 ) ostr << "GL_INTENSITY4";
	#endif
	#ifdef GL_INTENSITY8
		else if ( en == GL_INTENSITY8 ) ostr << "GL_INTENSITY8";
	#endif
	#ifdef GL_INTENSITY12
		else if ( en == GL_INTENSITY12 ) ostr << "GL_INTENSITY12";
	#endif
	#ifdef GL_INTENSITY16
		else if ( en == GL_INTENSITY16 ) ostr << "GL_INTENSITY16";
	#endif
	#ifdef GL_RGB4
		else if ( en == GL_RGB4 ) ostr << "GL_RGB4";
	#endif
	#ifdef GL_RGB5
		else if ( en == GL_RGB5 ) ostr << "GL_RGB5";
	#endif
	#ifdef GL_RGB8
		else if ( en == GL_RGB8 ) ostr << "GL_RGB8";
	#endif
	#ifdef GL_RGB10
		else if ( en == GL_RGB10 ) ostr << "GL_RGB10";
	#endif
	#ifdef GL_RGB12
		else if ( en == GL_RGB12 ) ostr << "GL_RGB12";
	#endif
	#ifdef GL_RGB16
		else if ( en == GL_RGB16 ) ostr << "GL_RGB16";
	#endif
	#ifdef GL_RGBA2
		else if ( en == GL_RGBA2 ) ostr << "GL_RGBA2";
	#endif
	#ifdef GL_RGBA4
		else if ( en == GL_RGBA4 ) ostr << "GL_RGBA4";
	#endif
	#ifdef GL_RGB5_A1
		else if ( en == GL_RGB5_A1 ) ostr << "GL_RGB5_A1";
	#endif
	#ifdef GL_RGBA8
		else if ( en == GL_RGBA8 ) ostr << "GL_RGBA8";
	#endif
	#ifdef GL_RGB10_A2
		else if ( en == GL_RGB10_A2 ) ostr << "GL_RGB10_A2";
	#endif
	#ifdef GL_RGBA12
		else if ( en == GL_RGBA12 ) ostr << "GL_RGBA12";
	#endif
	#ifdef GL_RGBA16
		else if ( en == GL_RGBA16 ) ostr << "GL_RGBA16";
	#endif
	#ifdef GL_TEXTURE_RED_SIZE
		else if ( en == GL_TEXTURE_RED_SIZE ) ostr << "GL_TEXTURE_RED_SIZE";
	#endif
	#ifdef GL_TEXTURE_GREEN_SIZE
		else if ( en == GL_TEXTURE_GREEN_SIZE ) ostr << "GL_TEXTURE_GREEN_SIZE";
	#endif
	#ifdef GL_TEXTURE_BLUE_SIZE
		else if ( en == GL_TEXTURE_BLUE_SIZE ) ostr << "GL_TEXTURE_BLUE_SIZE";
	#endif
	#ifdef GL_TEXTURE_ALPHA_SIZE
		else if ( en == GL_TEXTURE_ALPHA_SIZE ) ostr << "GL_TEXTURE_ALPHA_SIZE";
	#endif
	#ifdef GL_TEXTURE_LUMINANCE_SIZE
		else if ( en == GL_TEXTURE_LUMINANCE_SIZE ) ostr << "GL_TEXTURE_LUMINANCE_SIZE";
	#endif
	#ifdef GL_TEXTURE_INTENSITY_SIZE
		else if ( en == GL_TEXTURE_INTENSITY_SIZE ) ostr << "GL_TEXTURE_INTENSITY_SIZE";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D
		else if ( en == GL_PROXY_TEXTURE_1D ) ostr << "GL_PROXY_TEXTURE_1D";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D
		else if ( en == GL_PROXY_TEXTURE_2D ) ostr << "GL_PROXY_TEXTURE_2D";
	#endif
	#ifdef GL_TEXTURE_PRIORITY
		else if ( en == GL_TEXTURE_PRIORITY ) ostr << "GL_TEXTURE_PRIORITY";
	#endif
	#ifdef GL_TEXTURE_RESIDENT
		else if ( en == GL_TEXTURE_RESIDENT ) ostr << "GL_TEXTURE_RESIDENT";
	#endif
	#ifdef GL_TEXTURE_BINDING_1D
		else if ( en == GL_TEXTURE_BINDING_1D ) ostr << "GL_TEXTURE_BINDING_1D";
	#endif
	#ifdef GL_TEXTURE_BINDING_2D
		else if ( en == GL_TEXTURE_BINDING_2D ) ostr << "GL_TEXTURE_BINDING_2D";
	#endif
	#ifdef GL_VERTEX_ARRAY
		else if ( en == GL_VERTEX_ARRAY ) ostr << "GL_VERTEX_ARRAY";
	#endif
	#ifdef GL_NORMAL_ARRAY
		else if ( en == GL_NORMAL_ARRAY ) ostr << "GL_NORMAL_ARRAY";
	#endif
	#ifdef GL_COLOR_ARRAY
		else if ( en == GL_COLOR_ARRAY ) ostr << "GL_COLOR_ARRAY";
	#endif
	#ifdef GL_INDEX_ARRAY
		else if ( en == GL_INDEX_ARRAY ) ostr << "GL_INDEX_ARRAY";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY
		else if ( en == GL_TEXTURE_COORD_ARRAY ) ostr << "GL_TEXTURE_COORD_ARRAY";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY
		else if ( en == GL_EDGE_FLAG_ARRAY ) ostr << "GL_EDGE_FLAG_ARRAY";
	#endif
	#ifdef GL_VERTEX_ARRAY_SIZE
		else if ( en == GL_VERTEX_ARRAY_SIZE ) ostr << "GL_VERTEX_ARRAY_SIZE";
	#endif
	#ifdef GL_VERTEX_ARRAY_TYPE
		else if ( en == GL_VERTEX_ARRAY_TYPE ) ostr << "GL_VERTEX_ARRAY_TYPE";
	#endif
	#ifdef GL_VERTEX_ARRAY_STRIDE
		else if ( en == GL_VERTEX_ARRAY_STRIDE ) ostr << "GL_VERTEX_ARRAY_STRIDE";
	#endif
	#ifdef GL_NORMAL_ARRAY_TYPE
		else if ( en == GL_NORMAL_ARRAY_TYPE ) ostr << "GL_NORMAL_ARRAY_TYPE";
	#endif
	#ifdef GL_NORMAL_ARRAY_STRIDE
		else if ( en == GL_NORMAL_ARRAY_STRIDE ) ostr << "GL_NORMAL_ARRAY_STRIDE";
	#endif
	#ifdef GL_COLOR_ARRAY_SIZE
		else if ( en == GL_COLOR_ARRAY_SIZE ) ostr << "GL_COLOR_ARRAY_SIZE";
	#endif
	#ifdef GL_COLOR_ARRAY_TYPE
		else if ( en == GL_COLOR_ARRAY_TYPE ) ostr << "GL_COLOR_ARRAY_TYPE";
	#endif
	#ifdef GL_COLOR_ARRAY_STRIDE
		else if ( en == GL_COLOR_ARRAY_STRIDE ) ostr << "GL_COLOR_ARRAY_STRIDE";
	#endif
	#ifdef GL_INDEX_ARRAY_TYPE
		else if ( en == GL_INDEX_ARRAY_TYPE ) ostr << "GL_INDEX_ARRAY_TYPE";
	#endif
	#ifdef GL_INDEX_ARRAY_STRIDE
		else if ( en == GL_INDEX_ARRAY_STRIDE ) ostr << "GL_INDEX_ARRAY_STRIDE";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_SIZE
		else if ( en == GL_TEXTURE_COORD_ARRAY_SIZE ) ostr << "GL_TEXTURE_COORD_ARRAY_SIZE";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_TYPE
		else if ( en == GL_TEXTURE_COORD_ARRAY_TYPE ) ostr << "GL_TEXTURE_COORD_ARRAY_TYPE";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_STRIDE
		else if ( en == GL_TEXTURE_COORD_ARRAY_STRIDE ) ostr << "GL_TEXTURE_COORD_ARRAY_STRIDE";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_STRIDE
		else if ( en == GL_EDGE_FLAG_ARRAY_STRIDE ) ostr << "GL_EDGE_FLAG_ARRAY_STRIDE";
	#endif
	#ifdef GL_VERTEX_ARRAY_POINTER
		else if ( en == GL_VERTEX_ARRAY_POINTER ) ostr << "GL_VERTEX_ARRAY_POINTER";
	#endif
	#ifdef GL_NORMAL_ARRAY_POINTER
		else if ( en == GL_NORMAL_ARRAY_POINTER ) ostr << "GL_NORMAL_ARRAY_POINTER";
	#endif
	#ifdef GL_COLOR_ARRAY_POINTER
		else if ( en == GL_COLOR_ARRAY_POINTER ) ostr << "GL_COLOR_ARRAY_POINTER";
	#endif
	#ifdef GL_INDEX_ARRAY_POINTER
		else if ( en == GL_INDEX_ARRAY_POINTER ) ostr << "GL_INDEX_ARRAY_POINTER";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_POINTER
		else if ( en == GL_TEXTURE_COORD_ARRAY_POINTER ) ostr << "GL_TEXTURE_COORD_ARRAY_POINTER";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_POINTER
		else if ( en == GL_EDGE_FLAG_ARRAY_POINTER ) ostr << "GL_EDGE_FLAG_ARRAY_POINTER";
	#endif
	#ifdef GL_COLOR_INDEX1_EXT
		else if ( en == GL_COLOR_INDEX1_EXT ) ostr << "GL_COLOR_INDEX1_EXT";
	#endif
	#ifdef GL_COLOR_INDEX2_EXT
		else if ( en == GL_COLOR_INDEX2_EXT ) ostr << "GL_COLOR_INDEX2_EXT";
	#endif
	#ifdef GL_COLOR_INDEX4_EXT
		else if ( en == GL_COLOR_INDEX4_EXT ) ostr << "GL_COLOR_INDEX4_EXT";
	#endif
	#ifdef GL_COLOR_INDEX8_EXT
		else if ( en == GL_COLOR_INDEX8_EXT ) ostr << "GL_COLOR_INDEX8_EXT";
	#endif
	#ifdef GL_COLOR_INDEX12_EXT
		else if ( en == GL_COLOR_INDEX12_EXT ) ostr << "GL_COLOR_INDEX12_EXT";
	#endif
	#ifdef GL_COLOR_INDEX16_EXT
		else if ( en == GL_COLOR_INDEX16_EXT ) ostr << "GL_COLOR_INDEX16_EXT";
	#endif
	#ifdef GL_EVAL_BIT
		else if ( en == GL_EVAL_BIT ) ostr << "GL_EVAL_BIT";
	#endif
	#ifdef GL_LIST_BIT
		else if ( en == GL_LIST_BIT ) ostr << "GL_LIST_BIT";
	#endif
	#ifdef GL_TEXTURE_BIT
		else if ( en == GL_TEXTURE_BIT ) ostr << "GL_TEXTURE_BIT";
	#endif
	#ifdef GL_SCISSOR_BIT
		else if ( en == GL_SCISSOR_BIT ) ostr << "GL_SCISSOR_BIT";
	#endif
	#ifdef GL_ALL_ATTRIB_BITS
		else if ( en == GL_ALL_ATTRIB_BITS ) ostr << "GL_ALL_ATTRIB_BITS";
	#endif
	#ifdef GL_CLIENT_ALL_ATTRIB_BITS
		else if ( en == GL_CLIENT_ALL_ATTRIB_BITS ) ostr << "GL_CLIENT_ALL_ATTRIB_BITS";
	#endif
	#ifdef GL_SMOOTH_POINT_SIZE_RANGE
		else if ( en == GL_SMOOTH_POINT_SIZE_RANGE ) ostr << "GL_SMOOTH_POINT_SIZE_RANGE";
	#endif
	#ifdef GL_SMOOTH_POINT_SIZE_GRANULARITY
		else if ( en == GL_SMOOTH_POINT_SIZE_GRANULARITY ) ostr << "GL_SMOOTH_POINT_SIZE_GRANULARITY";
	#endif
	#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
		else if ( en == GL_SMOOTH_LINE_WIDTH_RANGE ) ostr << "GL_SMOOTH_LINE_WIDTH_RANGE";
	#endif
	#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
		else if ( en == GL_SMOOTH_LINE_WIDTH_GRANULARITY ) ostr << "GL_SMOOTH_LINE_WIDTH_GRANULARITY";
	#endif
	#ifdef GL_UNSIGNED_BYTE_3_3_2
		else if ( en == GL_UNSIGNED_BYTE_3_3_2 ) ostr << "GL_UNSIGNED_BYTE_3_3_2";
	#endif
	#ifdef GL_UNSIGNED_SHORT_4_4_4_4
		else if ( en == GL_UNSIGNED_SHORT_4_4_4_4 ) ostr << "GL_UNSIGNED_SHORT_4_4_4_4";
	#endif
	#ifdef GL_UNSIGNED_SHORT_5_5_5_1
		else if ( en == GL_UNSIGNED_SHORT_5_5_5_1 ) ostr << "GL_UNSIGNED_SHORT_5_5_5_1";
	#endif
	#ifdef GL_UNSIGNED_INT_8_8_8_8
		else if ( en == GL_UNSIGNED_INT_8_8_8_8 ) ostr << "GL_UNSIGNED_INT_8_8_8_8";
	#endif
	#ifdef GL_UNSIGNED_INT_10_10_10_2
		else if ( en == GL_UNSIGNED_INT_10_10_10_2 ) ostr << "GL_UNSIGNED_INT_10_10_10_2";
	#endif
	#ifdef GL_RESCALE_NORMAL
		else if ( en == GL_RESCALE_NORMAL ) ostr << "GL_RESCALE_NORMAL";
	#endif
	#ifdef GL_TEXTURE_BINDING_3D
		else if ( en == GL_TEXTURE_BINDING_3D ) ostr << "GL_TEXTURE_BINDING_3D";
	#endif
	#ifdef GL_PACK_SKIP_IMAGES
		else if ( en == GL_PACK_SKIP_IMAGES ) ostr << "GL_PACK_SKIP_IMAGES";
	#endif
	#ifdef GL_PACK_IMAGE_HEIGHT
		else if ( en == GL_PACK_IMAGE_HEIGHT ) ostr << "GL_PACK_IMAGE_HEIGHT";
	#endif
	#ifdef GL_UNPACK_SKIP_IMAGES
		else if ( en == GL_UNPACK_SKIP_IMAGES ) ostr << "GL_UNPACK_SKIP_IMAGES";
	#endif
	#ifdef GL_UNPACK_IMAGE_HEIGHT
		else if ( en == GL_UNPACK_IMAGE_HEIGHT ) ostr << "GL_UNPACK_IMAGE_HEIGHT";
	#endif
	#ifdef GL_TEXTURE_3D
		else if ( en == GL_TEXTURE_3D ) ostr << "GL_TEXTURE_3D";
	#endif
	#ifdef GL_PROXY_TEXTURE_3D
		else if ( en == GL_PROXY_TEXTURE_3D ) ostr << "GL_PROXY_TEXTURE_3D";
	#endif
	#ifdef GL_TEXTURE_DEPTH
		else if ( en == GL_TEXTURE_DEPTH ) ostr << "GL_TEXTURE_DEPTH";
	#endif
	#ifdef GL_TEXTURE_WRAP_R
		else if ( en == GL_TEXTURE_WRAP_R ) ostr << "GL_TEXTURE_WRAP_R";
	#endif
	#ifdef GL_MAX_3D_TEXTURE_SIZE
		else if ( en == GL_MAX_3D_TEXTURE_SIZE ) ostr << "GL_MAX_3D_TEXTURE_SIZE";
	#endif
	#ifdef GL_BGR
		else if ( en == GL_BGR ) ostr << "GL_BGR";
	#endif
	#ifdef GL_BGRA
		else if ( en == GL_BGRA ) ostr << "GL_BGRA";
	#endif
	#ifdef GL_MAX_ELEMENTS_VERTICES
		else if ( en == GL_MAX_ELEMENTS_VERTICES ) ostr << "GL_MAX_ELEMENTS_VERTICES";
	#endif
	#ifdef GL_MAX_ELEMENTS_INDICES
		else if ( en == GL_MAX_ELEMENTS_INDICES ) ostr << "GL_MAX_ELEMENTS_INDICES";
	#endif
	#ifdef GL_CLAMP_TO_EDGE
		else if ( en == GL_CLAMP_TO_EDGE ) ostr << "GL_CLAMP_TO_EDGE";
	#endif
	#ifdef GL_TEXTURE_MIN_LOD
		else if ( en == GL_TEXTURE_MIN_LOD ) ostr << "GL_TEXTURE_MIN_LOD";
	#endif
	#ifdef GL_TEXTURE_MAX_LOD
		else if ( en == GL_TEXTURE_MAX_LOD ) ostr << "GL_TEXTURE_MAX_LOD";
	#endif
	#ifdef GL_TEXTURE_BASE_LEVEL
		else if ( en == GL_TEXTURE_BASE_LEVEL ) ostr << "GL_TEXTURE_BASE_LEVEL";
	#endif
	#ifdef GL_TEXTURE_MAX_LEVEL
		else if ( en == GL_TEXTURE_MAX_LEVEL ) ostr << "GL_TEXTURE_MAX_LEVEL";
	#endif
	#ifdef GL_LIGHT_MODEL_COLOR_CONTROL
		else if ( en == GL_LIGHT_MODEL_COLOR_CONTROL ) ostr << "GL_LIGHT_MODEL_COLOR_CONTROL";
	#endif
	#ifdef GL_SINGLE_COLOR
		else if ( en == GL_SINGLE_COLOR ) ostr << "GL_SINGLE_COLOR";
	#endif
	#ifdef GL_SEPARATE_SPECULAR_COLOR
		else if ( en == GL_SEPARATE_SPECULAR_COLOR ) ostr << "GL_SEPARATE_SPECULAR_COLOR";
	#endif
	#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
		else if ( en == GL_UNSIGNED_BYTE_2_3_3_REV ) ostr << "GL_UNSIGNED_BYTE_2_3_3_REV";
	#endif
	#ifdef GL_UNSIGNED_SHORT_5_6_5
		else if ( en == GL_UNSIGNED_SHORT_5_6_5 ) ostr << "GL_UNSIGNED_SHORT_5_6_5";
	#endif
	#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
		else if ( en == GL_UNSIGNED_SHORT_5_6_5_REV ) ostr << "GL_UNSIGNED_SHORT_5_6_5_REV";
	#endif
	#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
		else if ( en == GL_UNSIGNED_SHORT_4_4_4_4_REV ) ostr << "GL_UNSIGNED_SHORT_4_4_4_4_REV";
	#endif
	#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
		else if ( en == GL_UNSIGNED_SHORT_1_5_5_5_REV ) ostr << "GL_UNSIGNED_SHORT_1_5_5_5_REV";
	#endif
	#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
		else if ( en == GL_UNSIGNED_INT_8_8_8_8_REV ) ostr << "GL_UNSIGNED_INT_8_8_8_8_REV";
	#endif
	#ifdef GL_ALIASED_POINT_SIZE_RANGE
		else if ( en == GL_ALIASED_POINT_SIZE_RANGE ) ostr << "GL_ALIASED_POINT_SIZE_RANGE";
	#endif
	#ifdef GL_ALIASED_LINE_WIDTH_RANGE
		else if ( en == GL_ALIASED_LINE_WIDTH_RANGE ) ostr << "GL_ALIASED_LINE_WIDTH_RANGE";
	#endif
	#ifdef GL_MULTISAMPLE
		else if ( en == GL_MULTISAMPLE ) ostr << "GL_MULTISAMPLE";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
		else if ( en == GL_SAMPLE_ALPHA_TO_COVERAGE ) ostr << "GL_SAMPLE_ALPHA_TO_COVERAGE";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_ONE
		else if ( en == GL_SAMPLE_ALPHA_TO_ONE ) ostr << "GL_SAMPLE_ALPHA_TO_ONE";
	#endif
	#ifdef GL_SAMPLE_COVERAGE
		else if ( en == GL_SAMPLE_COVERAGE ) ostr << "GL_SAMPLE_COVERAGE";
	#endif
	#ifdef GL_SAMPLE_BUFFERS
		else if ( en == GL_SAMPLE_BUFFERS ) ostr << "GL_SAMPLE_BUFFERS";
	#endif
	#ifdef GL_SAMPLES
		else if ( en == GL_SAMPLES ) ostr << "GL_SAMPLES";
	#endif
	#ifdef GL_SAMPLE_COVERAGE_VALUE
		else if ( en == GL_SAMPLE_COVERAGE_VALUE ) ostr << "GL_SAMPLE_COVERAGE_VALUE";
	#endif
	#ifdef GL_SAMPLE_COVERAGE_INVERT
		else if ( en == GL_SAMPLE_COVERAGE_INVERT ) ostr << "GL_SAMPLE_COVERAGE_INVERT";
	#endif
	#ifdef GL_CLAMP_TO_BORDER
		else if ( en == GL_CLAMP_TO_BORDER ) ostr << "GL_CLAMP_TO_BORDER";
	#endif
	#ifdef GL_TEXTURE0
		else if ( en == GL_TEXTURE0 ) ostr << "GL_TEXTURE0";
	#endif
	#ifdef GL_TEXTURE1
		else if ( en == GL_TEXTURE1 ) ostr << "GL_TEXTURE1";
	#endif
	#ifdef GL_TEXTURE2
		else if ( en == GL_TEXTURE2 ) ostr << "GL_TEXTURE2";
	#endif
	#ifdef GL_TEXTURE3
		else if ( en == GL_TEXTURE3 ) ostr << "GL_TEXTURE3";
	#endif
	#ifdef GL_TEXTURE4
		else if ( en == GL_TEXTURE4 ) ostr << "GL_TEXTURE4";
	#endif
	#ifdef GL_TEXTURE5
		else if ( en == GL_TEXTURE5 ) ostr << "GL_TEXTURE5";
	#endif
	#ifdef GL_TEXTURE6
		else if ( en == GL_TEXTURE6 ) ostr << "GL_TEXTURE6";
	#endif
	#ifdef GL_TEXTURE7
		else if ( en == GL_TEXTURE7 ) ostr << "GL_TEXTURE7";
	#endif
	#ifdef GL_TEXTURE8
		else if ( en == GL_TEXTURE8 ) ostr << "GL_TEXTURE8";
	#endif
	#ifdef GL_TEXTURE9
		else if ( en == GL_TEXTURE9 ) ostr << "GL_TEXTURE9";
	#endif
	#ifdef GL_TEXTURE10
		else if ( en == GL_TEXTURE10 ) ostr << "GL_TEXTURE10";
	#endif
	#ifdef GL_TEXTURE11
		else if ( en == GL_TEXTURE11 ) ostr << "GL_TEXTURE11";
	#endif
	#ifdef GL_TEXTURE12
		else if ( en == GL_TEXTURE12 ) ostr << "GL_TEXTURE12";
	#endif
	#ifdef GL_TEXTURE13
		else if ( en == GL_TEXTURE13 ) ostr << "GL_TEXTURE13";
	#endif
	#ifdef GL_TEXTURE14
		else if ( en == GL_TEXTURE14 ) ostr << "GL_TEXTURE14";
	#endif
	#ifdef GL_TEXTURE15
		else if ( en == GL_TEXTURE15 ) ostr << "GL_TEXTURE15";
	#endif
	#ifdef GL_TEXTURE16
		else if ( en == GL_TEXTURE16 ) ostr << "GL_TEXTURE16";
	#endif
	#ifdef GL_TEXTURE17
		else if ( en == GL_TEXTURE17 ) ostr << "GL_TEXTURE17";
	#endif
	#ifdef GL_TEXTURE18
		else if ( en == GL_TEXTURE18 ) ostr << "GL_TEXTURE18";
	#endif
	#ifdef GL_TEXTURE19
		else if ( en == GL_TEXTURE19 ) ostr << "GL_TEXTURE19";
	#endif
	#ifdef GL_TEXTURE20
		else if ( en == GL_TEXTURE20 ) ostr << "GL_TEXTURE20";
	#endif
	#ifdef GL_TEXTURE21
		else if ( en == GL_TEXTURE21 ) ostr << "GL_TEXTURE21";
	#endif
	#ifdef GL_TEXTURE22
		else if ( en == GL_TEXTURE22 ) ostr << "GL_TEXTURE22";
	#endif
	#ifdef GL_TEXTURE23
		else if ( en == GL_TEXTURE23 ) ostr << "GL_TEXTURE23";
	#endif
	#ifdef GL_TEXTURE24
		else if ( en == GL_TEXTURE24 ) ostr << "GL_TEXTURE24";
	#endif
	#ifdef GL_TEXTURE25
		else if ( en == GL_TEXTURE25 ) ostr << "GL_TEXTURE25";
	#endif
	#ifdef GL_TEXTURE26
		else if ( en == GL_TEXTURE26 ) ostr << "GL_TEXTURE26";
	#endif
	#ifdef GL_TEXTURE27
		else if ( en == GL_TEXTURE27 ) ostr << "GL_TEXTURE27";
	#endif
	#ifdef GL_TEXTURE28
		else if ( en == GL_TEXTURE28 ) ostr << "GL_TEXTURE28";
	#endif
	#ifdef GL_TEXTURE29
		else if ( en == GL_TEXTURE29 ) ostr << "GL_TEXTURE29";
	#endif
	#ifdef GL_TEXTURE30
		else if ( en == GL_TEXTURE30 ) ostr << "GL_TEXTURE30";
	#endif
	#ifdef GL_TEXTURE31
		else if ( en == GL_TEXTURE31 ) ostr << "GL_TEXTURE31";
	#endif
	#ifdef GL_ACTIVE_TEXTURE
		else if ( en == GL_ACTIVE_TEXTURE ) ostr << "GL_ACTIVE_TEXTURE";
	#endif
	#ifdef GL_CLIENT_ACTIVE_TEXTURE
		else if ( en == GL_CLIENT_ACTIVE_TEXTURE ) ostr << "GL_CLIENT_ACTIVE_TEXTURE";
	#endif
	#ifdef GL_MAX_TEXTURE_UNITS
		else if ( en == GL_MAX_TEXTURE_UNITS ) ostr << "GL_MAX_TEXTURE_UNITS";
	#endif
	#ifdef GL_TRANSPOSE_MODELVIEW_MATRIX
		else if ( en == GL_TRANSPOSE_MODELVIEW_MATRIX ) ostr << "GL_TRANSPOSE_MODELVIEW_MATRIX";
	#endif
	#ifdef GL_TRANSPOSE_PROJECTION_MATRIX
		else if ( en == GL_TRANSPOSE_PROJECTION_MATRIX ) ostr << "GL_TRANSPOSE_PROJECTION_MATRIX";
	#endif
	#ifdef GL_TRANSPOSE_TEXTURE_MATRIX
		else if ( en == GL_TRANSPOSE_TEXTURE_MATRIX ) ostr << "GL_TRANSPOSE_TEXTURE_MATRIX";
	#endif
	#ifdef GL_TRANSPOSE_COLOR_MATRIX
		else if ( en == GL_TRANSPOSE_COLOR_MATRIX ) ostr << "GL_TRANSPOSE_COLOR_MATRIX";
	#endif
	#ifdef GL_SUBTRACT
		else if ( en == GL_SUBTRACT ) ostr << "GL_SUBTRACT";
	#endif
	#ifdef GL_COMPRESSED_ALPHA
		else if ( en == GL_COMPRESSED_ALPHA ) ostr << "GL_COMPRESSED_ALPHA";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE
		else if ( en == GL_COMPRESSED_LUMINANCE ) ostr << "GL_COMPRESSED_LUMINANCE";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_ALPHA
		else if ( en == GL_COMPRESSED_LUMINANCE_ALPHA ) ostr << "GL_COMPRESSED_LUMINANCE_ALPHA";
	#endif
	#ifdef GL_COMPRESSED_INTENSITY
		else if ( en == GL_COMPRESSED_INTENSITY ) ostr << "GL_COMPRESSED_INTENSITY";
	#endif
	#ifdef GL_COMPRESSED_RGB
		else if ( en == GL_COMPRESSED_RGB ) ostr << "GL_COMPRESSED_RGB";
	#endif
	#ifdef GL_COMPRESSED_RGBA
		else if ( en == GL_COMPRESSED_RGBA ) ostr << "GL_COMPRESSED_RGBA";
	#endif
	#ifdef GL_TEXTURE_COMPRESSION_HINT
		else if ( en == GL_TEXTURE_COMPRESSION_HINT ) ostr << "GL_TEXTURE_COMPRESSION_HINT";
	#endif
	#ifdef GL_NORMAL_MAP
		else if ( en == GL_NORMAL_MAP ) ostr << "GL_NORMAL_MAP";
	#endif
	#ifdef GL_REFLECTION_MAP
		else if ( en == GL_REFLECTION_MAP ) ostr << "GL_REFLECTION_MAP";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP
		else if ( en == GL_TEXTURE_CUBE_MAP ) ostr << "GL_TEXTURE_CUBE_MAP";
	#endif
	#ifdef GL_TEXTURE_BINDING_CUBE_MAP
		else if ( en == GL_TEXTURE_BINDING_CUBE_MAP ) ostr << "GL_TEXTURE_BINDING_CUBE_MAP";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_X";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_X";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Y";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Z";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP";
	#endif
	#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
		else if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE ) ostr << "GL_MAX_CUBE_MAP_TEXTURE_SIZE";
	#endif
	#ifdef GL_COMBINE
		else if ( en == GL_COMBINE ) ostr << "GL_COMBINE";
	#endif
	#ifdef GL_COMBINE_RGB
		else if ( en == GL_COMBINE_RGB ) ostr << "GL_COMBINE_RGB";
	#endif
	#ifdef GL_COMBINE_ALPHA
		else if ( en == GL_COMBINE_ALPHA ) ostr << "GL_COMBINE_ALPHA";
	#endif
	#ifdef GL_RGB_SCALE
		else if ( en == GL_RGB_SCALE ) ostr << "GL_RGB_SCALE";
	#endif
	#ifdef GL_ADD_SIGNED
		else if ( en == GL_ADD_SIGNED ) ostr << "GL_ADD_SIGNED";
	#endif
	#ifdef GL_INTERPOLATE
		else if ( en == GL_INTERPOLATE ) ostr << "GL_INTERPOLATE";
	#endif
	#ifdef GL_CONSTANT
		else if ( en == GL_CONSTANT ) ostr << "GL_CONSTANT";
	#endif
	#ifdef GL_PRIMARY_COLOR
		else if ( en == GL_PRIMARY_COLOR ) ostr << "GL_PRIMARY_COLOR";
	#endif
	#ifdef GL_PREVIOUS
		else if ( en == GL_PREVIOUS ) ostr << "GL_PREVIOUS";
	#endif
	#ifdef GL_SOURCE0_RGB
		else if ( en == GL_SOURCE0_RGB ) ostr << "GL_SOURCE0_RGB";
	#endif
	#ifdef GL_SOURCE1_RGB
		else if ( en == GL_SOURCE1_RGB ) ostr << "GL_SOURCE1_RGB";
	#endif
	#ifdef GL_SOURCE2_RGB
		else if ( en == GL_SOURCE2_RGB ) ostr << "GL_SOURCE2_RGB";
	#endif
	#ifdef GL_SOURCE0_ALPHA
		else if ( en == GL_SOURCE0_ALPHA ) ostr << "GL_SOURCE0_ALPHA";
	#endif
	#ifdef GL_SOURCE1_ALPHA
		else if ( en == GL_SOURCE1_ALPHA ) ostr << "GL_SOURCE1_ALPHA";
	#endif
	#ifdef GL_SOURCE2_ALPHA
		else if ( en == GL_SOURCE2_ALPHA ) ostr << "GL_SOURCE2_ALPHA";
	#endif
	#ifdef GL_OPERAND0_RGB
		else if ( en == GL_OPERAND0_RGB ) ostr << "GL_OPERAND0_RGB";
	#endif
	#ifdef GL_OPERAND1_RGB
		else if ( en == GL_OPERAND1_RGB ) ostr << "GL_OPERAND1_RGB";
	#endif
	#ifdef GL_OPERAND2_RGB
		else if ( en == GL_OPERAND2_RGB ) ostr << "GL_OPERAND2_RGB";
	#endif
	#ifdef GL_OPERAND0_ALPHA
		else if ( en == GL_OPERAND0_ALPHA ) ostr << "GL_OPERAND0_ALPHA";
	#endif
	#ifdef GL_OPERAND1_ALPHA
		else if ( en == GL_OPERAND1_ALPHA ) ostr << "GL_OPERAND1_ALPHA";
	#endif
	#ifdef GL_OPERAND2_ALPHA
		else if ( en == GL_OPERAND2_ALPHA ) ostr << "GL_OPERAND2_ALPHA";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_IMAGE_SIZE
		else if ( en == GL_TEXTURE_COMPRESSED_IMAGE_SIZE ) ostr << "GL_TEXTURE_COMPRESSED_IMAGE_SIZE";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED
		else if ( en == GL_TEXTURE_COMPRESSED ) ostr << "GL_TEXTURE_COMPRESSED";
	#endif
	#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
		else if ( en == GL_NUM_COMPRESSED_TEXTURE_FORMATS ) ostr << "GL_NUM_COMPRESSED_TEXTURE_FORMATS";
	#endif
	#ifdef GL_COMPRESSED_TEXTURE_FORMATS
		else if ( en == GL_COMPRESSED_TEXTURE_FORMATS ) ostr << "GL_COMPRESSED_TEXTURE_FORMATS";
	#endif
	#ifdef GL_DOT3_RGB
		else if ( en == GL_DOT3_RGB ) ostr << "GL_DOT3_RGB";
	#endif
	#ifdef GL_DOT3_RGBA
		else if ( en == GL_DOT3_RGBA ) ostr << "GL_DOT3_RGBA";
	#endif
	#ifdef GL_MULTISAMPLE_BIT
		else if ( en == GL_MULTISAMPLE_BIT ) ostr << "GL_MULTISAMPLE_BIT";
	#endif
	#ifdef GL_BLEND_DST_RGB
		else if ( en == GL_BLEND_DST_RGB ) ostr << "GL_BLEND_DST_RGB";
	#endif
	#ifdef GL_BLEND_SRC_RGB
		else if ( en == GL_BLEND_SRC_RGB ) ostr << "GL_BLEND_SRC_RGB";
	#endif
	#ifdef GL_BLEND_DST_ALPHA
		else if ( en == GL_BLEND_DST_ALPHA ) ostr << "GL_BLEND_DST_ALPHA";
	#endif
	#ifdef GL_BLEND_SRC_ALPHA
		else if ( en == GL_BLEND_SRC_ALPHA ) ostr << "GL_BLEND_SRC_ALPHA";
	#endif
	#ifdef GL_POINT_SIZE_MIN
		else if ( en == GL_POINT_SIZE_MIN ) ostr << "GL_POINT_SIZE_MIN";
	#endif
	#ifdef GL_POINT_SIZE_MAX
		else if ( en == GL_POINT_SIZE_MAX ) ostr << "GL_POINT_SIZE_MAX";
	#endif
	#ifdef GL_POINT_FADE_THRESHOLD_SIZE
		else if ( en == GL_POINT_FADE_THRESHOLD_SIZE ) ostr << "GL_POINT_FADE_THRESHOLD_SIZE";
	#endif
	#ifdef GL_POINT_DISTANCE_ATTENUATION
		else if ( en == GL_POINT_DISTANCE_ATTENUATION ) ostr << "GL_POINT_DISTANCE_ATTENUATION";
	#endif
	#ifdef GL_GENERATE_MIPMAP
		else if ( en == GL_GENERATE_MIPMAP ) ostr << "GL_GENERATE_MIPMAP";
	#endif
	#ifdef GL_GENERATE_MIPMAP_HINT
		else if ( en == GL_GENERATE_MIPMAP_HINT ) ostr << "GL_GENERATE_MIPMAP_HINT";
	#endif
	#ifdef GL_DEPTH_COMPONENT16
		else if ( en == GL_DEPTH_COMPONENT16 ) ostr << "GL_DEPTH_COMPONENT16";
	#endif
	#ifdef GL_DEPTH_COMPONENT24
		else if ( en == GL_DEPTH_COMPONENT24 ) ostr << "GL_DEPTH_COMPONENT24";
	#endif
	#ifdef GL_DEPTH_COMPONENT32
		else if ( en == GL_DEPTH_COMPONENT32 ) ostr << "GL_DEPTH_COMPONENT32";
	#endif
	#ifdef GL_MIRRORED_REPEAT
		else if ( en == GL_MIRRORED_REPEAT ) ostr << "GL_MIRRORED_REPEAT";
	#endif
	#ifdef GL_FOG_COORDINATE_SOURCE
		else if ( en == GL_FOG_COORDINATE_SOURCE ) ostr << "GL_FOG_COORDINATE_SOURCE";
	#endif
	#ifdef GL_FOG_COORDINATE
		else if ( en == GL_FOG_COORDINATE ) ostr << "GL_FOG_COORDINATE";
	#endif
	#ifdef GL_FRAGMENT_DEPTH
		else if ( en == GL_FRAGMENT_DEPTH ) ostr << "GL_FRAGMENT_DEPTH";
	#endif
	#ifdef GL_CURRENT_FOG_COORDINATE
		else if ( en == GL_CURRENT_FOG_COORDINATE ) ostr << "GL_CURRENT_FOG_COORDINATE";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_TYPE
		else if ( en == GL_FOG_COORDINATE_ARRAY_TYPE ) ostr << "GL_FOG_COORDINATE_ARRAY_TYPE";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_STRIDE
		else if ( en == GL_FOG_COORDINATE_ARRAY_STRIDE ) ostr << "GL_FOG_COORDINATE_ARRAY_STRIDE";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_POINTER
		else if ( en == GL_FOG_COORDINATE_ARRAY_POINTER ) ostr << "GL_FOG_COORDINATE_ARRAY_POINTER";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY
		else if ( en == GL_FOG_COORDINATE_ARRAY ) ostr << "GL_FOG_COORDINATE_ARRAY";
	#endif
	#ifdef GL_COLOR_SUM
		else if ( en == GL_COLOR_SUM ) ostr << "GL_COLOR_SUM";
	#endif
	#ifdef GL_CURRENT_SECONDARY_COLOR
		else if ( en == GL_CURRENT_SECONDARY_COLOR ) ostr << "GL_CURRENT_SECONDARY_COLOR";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_SIZE
		else if ( en == GL_SECONDARY_COLOR_ARRAY_SIZE ) ostr << "GL_SECONDARY_COLOR_ARRAY_SIZE";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_TYPE
		else if ( en == GL_SECONDARY_COLOR_ARRAY_TYPE ) ostr << "GL_SECONDARY_COLOR_ARRAY_TYPE";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_STRIDE
		else if ( en == GL_SECONDARY_COLOR_ARRAY_STRIDE ) ostr << "GL_SECONDARY_COLOR_ARRAY_STRIDE";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_POINTER
		else if ( en == GL_SECONDARY_COLOR_ARRAY_POINTER ) ostr << "GL_SECONDARY_COLOR_ARRAY_POINTER";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY
		else if ( en == GL_SECONDARY_COLOR_ARRAY ) ostr << "GL_SECONDARY_COLOR_ARRAY";
	#endif
	#ifdef GL_MAX_TEXTURE_LOD_BIAS
		else if ( en == GL_MAX_TEXTURE_LOD_BIAS ) ostr << "GL_MAX_TEXTURE_LOD_BIAS";
	#endif
	#ifdef GL_TEXTURE_FILTER_CONTROL
		else if ( en == GL_TEXTURE_FILTER_CONTROL ) ostr << "GL_TEXTURE_FILTER_CONTROL";
	#endif
	#ifdef GL_TEXTURE_LOD_BIAS
		else if ( en == GL_TEXTURE_LOD_BIAS ) ostr << "GL_TEXTURE_LOD_BIAS";
	#endif
	#ifdef GL_INCR_WRAP
		else if ( en == GL_INCR_WRAP ) ostr << "GL_INCR_WRAP";
	#endif
	#ifdef GL_DECR_WRAP
		else if ( en == GL_DECR_WRAP ) ostr << "GL_DECR_WRAP";
	#endif
	#ifdef GL_TEXTURE_DEPTH_SIZE
		else if ( en == GL_TEXTURE_DEPTH_SIZE ) ostr << "GL_TEXTURE_DEPTH_SIZE";
	#endif
	#ifdef GL_DEPTH_TEXTURE_MODE
		else if ( en == GL_DEPTH_TEXTURE_MODE ) ostr << "GL_DEPTH_TEXTURE_MODE";
	#endif
	#ifdef GL_TEXTURE_COMPARE_MODE
		else if ( en == GL_TEXTURE_COMPARE_MODE ) ostr << "GL_TEXTURE_COMPARE_MODE";
	#endif
	#ifdef GL_TEXTURE_COMPARE_FUNC
		else if ( en == GL_TEXTURE_COMPARE_FUNC ) ostr << "GL_TEXTURE_COMPARE_FUNC";
	#endif
	#ifdef GL_COMPARE_R_TO_TEXTURE
		else if ( en == GL_COMPARE_R_TO_TEXTURE ) ostr << "GL_COMPARE_R_TO_TEXTURE";
	#endif
	#ifdef GL_FOG_COORD_SRC
		else if ( en == GL_FOG_COORD_SRC ) ostr << "GL_FOG_COORD_SRC";
	#endif
	#ifdef GL_FOG_COORD
		else if ( en == GL_FOG_COORD ) ostr << "GL_FOG_COORD";
	#endif
	#ifdef GL_FOG_COORD_ARRAY
		else if ( en == GL_FOG_COORD_ARRAY ) ostr << "GL_FOG_COORD_ARRAY";
	#endif
	#ifdef GL_SRC0_RGB
		else if ( en == GL_SRC0_RGB ) ostr << "GL_SRC0_RGB";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_POINTER
		else if ( en == GL_FOG_COORD_ARRAY_POINTER ) ostr << "GL_FOG_COORD_ARRAY_POINTER";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_TYPE
		else if ( en == GL_FOG_COORD_ARRAY_TYPE ) ostr << "GL_FOG_COORD_ARRAY_TYPE";
	#endif
	#ifdef GL_SRC1_ALPHA
		else if ( en == GL_SRC1_ALPHA ) ostr << "GL_SRC1_ALPHA";
	#endif
	#ifdef GL_CURRENT_FOG_COORD
		else if ( en == GL_CURRENT_FOG_COORD ) ostr << "GL_CURRENT_FOG_COORD";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_STRIDE
		else if ( en == GL_FOG_COORD_ARRAY_STRIDE ) ostr << "GL_FOG_COORD_ARRAY_STRIDE";
	#endif
	#ifdef GL_SRC0_ALPHA
		else if ( en == GL_SRC0_ALPHA ) ostr << "GL_SRC0_ALPHA";
	#endif
	#ifdef GL_SRC1_RGB
		else if ( en == GL_SRC1_RGB ) ostr << "GL_SRC1_RGB";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_BUFFER_BINDING
		else if ( en == GL_FOG_COORD_ARRAY_BUFFER_BINDING ) ostr << "GL_FOG_COORD_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_SRC2_ALPHA
		else if ( en == GL_SRC2_ALPHA ) ostr << "GL_SRC2_ALPHA";
	#endif
	#ifdef GL_SRC2_RGB
		else if ( en == GL_SRC2_RGB ) ostr << "GL_SRC2_RGB";
	#endif
	#ifdef GL_BUFFER_SIZE
		else if ( en == GL_BUFFER_SIZE ) ostr << "GL_BUFFER_SIZE";
	#endif
	#ifdef GL_BUFFER_USAGE
		else if ( en == GL_BUFFER_USAGE ) ostr << "GL_BUFFER_USAGE";
	#endif
	#ifdef GL_QUERY_COUNTER_BITS
		else if ( en == GL_QUERY_COUNTER_BITS ) ostr << "GL_QUERY_COUNTER_BITS";
	#endif
	#ifdef GL_CURRENT_QUERY
		else if ( en == GL_CURRENT_QUERY ) ostr << "GL_CURRENT_QUERY";
	#endif
	#ifdef GL_QUERY_RESULT
		else if ( en == GL_QUERY_RESULT ) ostr << "GL_QUERY_RESULT";
	#endif
	#ifdef GL_QUERY_RESULT_AVAILABLE
		else if ( en == GL_QUERY_RESULT_AVAILABLE ) ostr << "GL_QUERY_RESULT_AVAILABLE";
	#endif
	#ifdef GL_ARRAY_BUFFER
		else if ( en == GL_ARRAY_BUFFER ) ostr << "GL_ARRAY_BUFFER";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BUFFER
		else if ( en == GL_ELEMENT_ARRAY_BUFFER ) ostr << "GL_ELEMENT_ARRAY_BUFFER";
	#endif
	#ifdef GL_ARRAY_BUFFER_BINDING
		else if ( en == GL_ARRAY_BUFFER_BINDING ) ostr << "GL_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
		else if ( en == GL_ELEMENT_ARRAY_BUFFER_BINDING ) ostr << "GL_ELEMENT_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_VERTEX_ARRAY_BUFFER_BINDING
		else if ( en == GL_VERTEX_ARRAY_BUFFER_BINDING ) ostr << "GL_VERTEX_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_NORMAL_ARRAY_BUFFER_BINDING
		else if ( en == GL_NORMAL_ARRAY_BUFFER_BINDING ) ostr << "GL_NORMAL_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_COLOR_ARRAY_BUFFER_BINDING
		else if ( en == GL_COLOR_ARRAY_BUFFER_BINDING ) ostr << "GL_COLOR_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_INDEX_ARRAY_BUFFER_BINDING
		else if ( en == GL_INDEX_ARRAY_BUFFER_BINDING ) ostr << "GL_INDEX_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING
		else if ( en == GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING ) ostr << "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_BUFFER_BINDING
		else if ( en == GL_EDGE_FLAG_ARRAY_BUFFER_BINDING ) ostr << "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING
		else if ( en == GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING ) ostr << "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
		else if ( en == GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING ) ostr << "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_WEIGHT_ARRAY_BUFFER_BINDING
		else if ( en == GL_WEIGHT_ARRAY_BUFFER_BINDING ) ostr << "GL_WEIGHT_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING ) ostr << "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING";
	#endif
	#ifdef GL_READ_ONLY
		else if ( en == GL_READ_ONLY ) ostr << "GL_READ_ONLY";
	#endif
	#ifdef GL_WRITE_ONLY
		else if ( en == GL_WRITE_ONLY ) ostr << "GL_WRITE_ONLY";
	#endif
	#ifdef GL_READ_WRITE
		else if ( en == GL_READ_WRITE ) ostr << "GL_READ_WRITE";
	#endif
	#ifdef GL_BUFFER_ACCESS
		else if ( en == GL_BUFFER_ACCESS ) ostr << "GL_BUFFER_ACCESS";
	#endif
	#ifdef GL_BUFFER_MAPPED
		else if ( en == GL_BUFFER_MAPPED ) ostr << "GL_BUFFER_MAPPED";
	#endif
	#ifdef GL_BUFFER_MAP_POINTER
		else if ( en == GL_BUFFER_MAP_POINTER ) ostr << "GL_BUFFER_MAP_POINTER";
	#endif
	#ifdef GL_STREAM_DRAW
		else if ( en == GL_STREAM_DRAW ) ostr << "GL_STREAM_DRAW";
	#endif
	#ifdef GL_STREAM_READ
		else if ( en == GL_STREAM_READ ) ostr << "GL_STREAM_READ";
	#endif
	#ifdef GL_STREAM_COPY
		else if ( en == GL_STREAM_COPY ) ostr << "GL_STREAM_COPY";
	#endif
	#ifdef GL_STATIC_DRAW
		else if ( en == GL_STATIC_DRAW ) ostr << "GL_STATIC_DRAW";
	#endif
	#ifdef GL_STATIC_READ
		else if ( en == GL_STATIC_READ ) ostr << "GL_STATIC_READ";
	#endif
	#ifdef GL_STATIC_COPY
		else if ( en == GL_STATIC_COPY ) ostr << "GL_STATIC_COPY";
	#endif
	#ifdef GL_DYNAMIC_DRAW
		else if ( en == GL_DYNAMIC_DRAW ) ostr << "GL_DYNAMIC_DRAW";
	#endif
	#ifdef GL_DYNAMIC_READ
		else if ( en == GL_DYNAMIC_READ ) ostr << "GL_DYNAMIC_READ";
	#endif
	#ifdef GL_DYNAMIC_COPY
		else if ( en == GL_DYNAMIC_COPY ) ostr << "GL_DYNAMIC_COPY";
	#endif
	#ifdef GL_SAMPLES_PASSED
		else if ( en == GL_SAMPLES_PASSED ) ostr << "GL_SAMPLES_PASSED";
	#endif
	#ifdef GL_BLEND_EQUATION_RGB
		else if ( en == GL_BLEND_EQUATION_RGB ) ostr << "GL_BLEND_EQUATION_RGB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_ENABLED
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_ENABLED ) ostr << "GL_VERTEX_ATTRIB_ARRAY_ENABLED";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_SIZE
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_SIZE ) ostr << "GL_VERTEX_ATTRIB_ARRAY_SIZE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_STRIDE
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_STRIDE ) ostr << "GL_VERTEX_ATTRIB_ARRAY_STRIDE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_TYPE
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_TYPE ) ostr << "GL_VERTEX_ATTRIB_ARRAY_TYPE";
	#endif
	#ifdef GL_CURRENT_VERTEX_ATTRIB
		else if ( en == GL_CURRENT_VERTEX_ATTRIB ) ostr << "GL_CURRENT_VERTEX_ATTRIB";
	#endif
	#ifdef GL_VERTEX_PROGRAM_POINT_SIZE
		else if ( en == GL_VERTEX_PROGRAM_POINT_SIZE ) ostr << "GL_VERTEX_PROGRAM_POINT_SIZE";
	#endif
	#ifdef GL_VERTEX_PROGRAM_TWO_SIDE
		else if ( en == GL_VERTEX_PROGRAM_TWO_SIDE ) ostr << "GL_VERTEX_PROGRAM_TWO_SIDE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_POINTER
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_POINTER ) ostr << "GL_VERTEX_ATTRIB_ARRAY_POINTER";
	#endif
	#ifdef GL_STENCIL_BACK_FUNC
		else if ( en == GL_STENCIL_BACK_FUNC ) ostr << "GL_STENCIL_BACK_FUNC";
	#endif
	#ifdef GL_STENCIL_BACK_FAIL
		else if ( en == GL_STENCIL_BACK_FAIL ) ostr << "GL_STENCIL_BACK_FAIL";
	#endif
	#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
		else if ( en == GL_STENCIL_BACK_PASS_DEPTH_FAIL ) ostr << "GL_STENCIL_BACK_PASS_DEPTH_FAIL";
	#endif
	#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
		else if ( en == GL_STENCIL_BACK_PASS_DEPTH_PASS ) ostr << "GL_STENCIL_BACK_PASS_DEPTH_PASS";
	#endif
	#ifdef GL_MAX_DRAW_BUFFERS
		else if ( en == GL_MAX_DRAW_BUFFERS ) ostr << "GL_MAX_DRAW_BUFFERS";
	#endif
	#ifdef GL_DRAW_BUFFER0
		else if ( en == GL_DRAW_BUFFER0 ) ostr << "GL_DRAW_BUFFER0";
	#endif
	#ifdef GL_DRAW_BUFFER1
		else if ( en == GL_DRAW_BUFFER1 ) ostr << "GL_DRAW_BUFFER1";
	#endif
	#ifdef GL_DRAW_BUFFER2
		else if ( en == GL_DRAW_BUFFER2 ) ostr << "GL_DRAW_BUFFER2";
	#endif
	#ifdef GL_DRAW_BUFFER3
		else if ( en == GL_DRAW_BUFFER3 ) ostr << "GL_DRAW_BUFFER3";
	#endif
	#ifdef GL_DRAW_BUFFER4
		else if ( en == GL_DRAW_BUFFER4 ) ostr << "GL_DRAW_BUFFER4";
	#endif
	#ifdef GL_DRAW_BUFFER5
		else if ( en == GL_DRAW_BUFFER5 ) ostr << "GL_DRAW_BUFFER5";
	#endif
	#ifdef GL_DRAW_BUFFER6
		else if ( en == GL_DRAW_BUFFER6 ) ostr << "GL_DRAW_BUFFER6";
	#endif
	#ifdef GL_DRAW_BUFFER7
		else if ( en == GL_DRAW_BUFFER7 ) ostr << "GL_DRAW_BUFFER7";
	#endif
	#ifdef GL_DRAW_BUFFER8
		else if ( en == GL_DRAW_BUFFER8 ) ostr << "GL_DRAW_BUFFER8";
	#endif
	#ifdef GL_DRAW_BUFFER9
		else if ( en == GL_DRAW_BUFFER9 ) ostr << "GL_DRAW_BUFFER9";
	#endif
	#ifdef GL_DRAW_BUFFER10
		else if ( en == GL_DRAW_BUFFER10 ) ostr << "GL_DRAW_BUFFER10";
	#endif
	#ifdef GL_DRAW_BUFFER11
		else if ( en == GL_DRAW_BUFFER11 ) ostr << "GL_DRAW_BUFFER11";
	#endif
	#ifdef GL_DRAW_BUFFER12
		else if ( en == GL_DRAW_BUFFER12 ) ostr << "GL_DRAW_BUFFER12";
	#endif
	#ifdef GL_DRAW_BUFFER13
		else if ( en == GL_DRAW_BUFFER13 ) ostr << "GL_DRAW_BUFFER13";
	#endif
	#ifdef GL_DRAW_BUFFER14
		else if ( en == GL_DRAW_BUFFER14 ) ostr << "GL_DRAW_BUFFER14";
	#endif
	#ifdef GL_DRAW_BUFFER15
		else if ( en == GL_DRAW_BUFFER15 ) ostr << "GL_DRAW_BUFFER15";
	#endif
	#ifdef GL_BLEND_EQUATION_ALPHA
		else if ( en == GL_BLEND_EQUATION_ALPHA ) ostr << "GL_BLEND_EQUATION_ALPHA";
	#endif
	#ifdef GL_POINT_SPRITE
		else if ( en == GL_POINT_SPRITE ) ostr << "GL_POINT_SPRITE";
	#endif
	#ifdef GL_COORD_REPLACE
		else if ( en == GL_COORD_REPLACE ) ostr << "GL_COORD_REPLACE";
	#endif
	#ifdef GL_MAX_VERTEX_ATTRIBS
		else if ( en == GL_MAX_VERTEX_ATTRIBS ) ostr << "GL_MAX_VERTEX_ATTRIBS";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_NORMALIZED
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED ) ostr << "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED";
	#endif
	#ifdef GL_MAX_TEXTURE_COORDS
		else if ( en == GL_MAX_TEXTURE_COORDS ) ostr << "GL_MAX_TEXTURE_COORDS";
	#endif
	#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_FRAGMENT_SHADER
		else if ( en == GL_FRAGMENT_SHADER ) ostr << "GL_FRAGMENT_SHADER";
	#endif
	#ifdef GL_VERTEX_SHADER
		else if ( en == GL_VERTEX_SHADER ) ostr << "GL_VERTEX_SHADER";
	#endif
	#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_FRAGMENT_UNIFORM_COMPONENTS ) ostr << "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_VERTEX_UNIFORM_COMPONENTS ) ostr << "GL_MAX_VERTEX_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_VARYING_FLOATS
		else if ( en == GL_MAX_VARYING_FLOATS ) ostr << "GL_MAX_VARYING_FLOATS";
	#endif
	#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_SHADER_TYPE
		else if ( en == GL_SHADER_TYPE ) ostr << "GL_SHADER_TYPE";
	#endif
	#ifdef GL_FLOAT_VEC2
		else if ( en == GL_FLOAT_VEC2 ) ostr << "GL_FLOAT_VEC2";
	#endif
	#ifdef GL_FLOAT_VEC3
		else if ( en == GL_FLOAT_VEC3 ) ostr << "GL_FLOAT_VEC3";
	#endif
	#ifdef GL_FLOAT_VEC4
		else if ( en == GL_FLOAT_VEC4 ) ostr << "GL_FLOAT_VEC4";
	#endif
	#ifdef GL_INT_VEC2
		else if ( en == GL_INT_VEC2 ) ostr << "GL_INT_VEC2";
	#endif
	#ifdef GL_INT_VEC3
		else if ( en == GL_INT_VEC3 ) ostr << "GL_INT_VEC3";
	#endif
	#ifdef GL_INT_VEC4
		else if ( en == GL_INT_VEC4 ) ostr << "GL_INT_VEC4";
	#endif
	#ifdef GL_BOOL
		else if ( en == GL_BOOL ) ostr << "GL_BOOL";
	#endif
	#ifdef GL_BOOL_VEC2
		else if ( en == GL_BOOL_VEC2 ) ostr << "GL_BOOL_VEC2";
	#endif
	#ifdef GL_BOOL_VEC3
		else if ( en == GL_BOOL_VEC3 ) ostr << "GL_BOOL_VEC3";
	#endif
	#ifdef GL_BOOL_VEC4
		else if ( en == GL_BOOL_VEC4 ) ostr << "GL_BOOL_VEC4";
	#endif
	#ifdef GL_FLOAT_MAT2
		else if ( en == GL_FLOAT_MAT2 ) ostr << "GL_FLOAT_MAT2";
	#endif
	#ifdef GL_FLOAT_MAT3
		else if ( en == GL_FLOAT_MAT3 ) ostr << "GL_FLOAT_MAT3";
	#endif
	#ifdef GL_FLOAT_MAT4
		else if ( en == GL_FLOAT_MAT4 ) ostr << "GL_FLOAT_MAT4";
	#endif
	#ifdef GL_SAMPLER_1D
		else if ( en == GL_SAMPLER_1D ) ostr << "GL_SAMPLER_1D";
	#endif
	#ifdef GL_SAMPLER_2D
		else if ( en == GL_SAMPLER_2D ) ostr << "GL_SAMPLER_2D";
	#endif
	#ifdef GL_SAMPLER_3D
		else if ( en == GL_SAMPLER_3D ) ostr << "GL_SAMPLER_3D";
	#endif
	#ifdef GL_SAMPLER_CUBE
		else if ( en == GL_SAMPLER_CUBE ) ostr << "GL_SAMPLER_CUBE";
	#endif
	#ifdef GL_SAMPLER_1D_SHADOW
		else if ( en == GL_SAMPLER_1D_SHADOW ) ostr << "GL_SAMPLER_1D_SHADOW";
	#endif
	#ifdef GL_SAMPLER_2D_SHADOW
		else if ( en == GL_SAMPLER_2D_SHADOW ) ostr << "GL_SAMPLER_2D_SHADOW";
	#endif
	#ifdef GL_DELETE_STATUS
		else if ( en == GL_DELETE_STATUS ) ostr << "GL_DELETE_STATUS";
	#endif
	#ifdef GL_COMPILE_STATUS
		else if ( en == GL_COMPILE_STATUS ) ostr << "GL_COMPILE_STATUS";
	#endif
	#ifdef GL_LINK_STATUS
		else if ( en == GL_LINK_STATUS ) ostr << "GL_LINK_STATUS";
	#endif
	#ifdef GL_VALIDATE_STATUS
		else if ( en == GL_VALIDATE_STATUS ) ostr << "GL_VALIDATE_STATUS";
	#endif
	#ifdef GL_INFO_LOG_LENGTH
		else if ( en == GL_INFO_LOG_LENGTH ) ostr << "GL_INFO_LOG_LENGTH";
	#endif
	#ifdef GL_ATTACHED_SHADERS
		else if ( en == GL_ATTACHED_SHADERS ) ostr << "GL_ATTACHED_SHADERS";
	#endif
	#ifdef GL_ACTIVE_UNIFORMS
		else if ( en == GL_ACTIVE_UNIFORMS ) ostr << "GL_ACTIVE_UNIFORMS";
	#endif
	#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
		else if ( en == GL_ACTIVE_UNIFORM_MAX_LENGTH ) ostr << "GL_ACTIVE_UNIFORM_MAX_LENGTH";
	#endif
	#ifdef GL_SHADER_SOURCE_LENGTH
		else if ( en == GL_SHADER_SOURCE_LENGTH ) ostr << "GL_SHADER_SOURCE_LENGTH";
	#endif
	#ifdef GL_ACTIVE_ATTRIBUTES
		else if ( en == GL_ACTIVE_ATTRIBUTES ) ostr << "GL_ACTIVE_ATTRIBUTES";
	#endif
	#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
		else if ( en == GL_ACTIVE_ATTRIBUTE_MAX_LENGTH ) ostr << "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH";
	#endif
	#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
		else if ( en == GL_FRAGMENT_SHADER_DERIVATIVE_HINT ) ostr << "GL_FRAGMENT_SHADER_DERIVATIVE_HINT";
	#endif
	#ifdef GL_SHADING_LANGUAGE_VERSION
		else if ( en == GL_SHADING_LANGUAGE_VERSION ) ostr << "GL_SHADING_LANGUAGE_VERSION";
	#endif
	#ifdef GL_CURRENT_PROGRAM
		else if ( en == GL_CURRENT_PROGRAM ) ostr << "GL_CURRENT_PROGRAM";
	#endif
	#ifdef GL_POINT_SPRITE_COORD_ORIGIN
		else if ( en == GL_POINT_SPRITE_COORD_ORIGIN ) ostr << "GL_POINT_SPRITE_COORD_ORIGIN";
	#endif
	#ifdef GL_LOWER_LEFT
		else if ( en == GL_LOWER_LEFT ) ostr << "GL_LOWER_LEFT";
	#endif
	#ifdef GL_UPPER_LEFT
		else if ( en == GL_UPPER_LEFT ) ostr << "GL_UPPER_LEFT";
	#endif
	#ifdef GL_STENCIL_BACK_REF
		else if ( en == GL_STENCIL_BACK_REF ) ostr << "GL_STENCIL_BACK_REF";
	#endif
	#ifdef GL_STENCIL_BACK_VALUE_MASK
		else if ( en == GL_STENCIL_BACK_VALUE_MASK ) ostr << "GL_STENCIL_BACK_VALUE_MASK";
	#endif
	#ifdef GL_STENCIL_BACK_WRITEMASK
		else if ( en == GL_STENCIL_BACK_WRITEMASK ) ostr << "GL_STENCIL_BACK_WRITEMASK";
	#endif
	#ifdef GL_CURRENT_RASTER_SECONDARY_COLOR
		else if ( en == GL_CURRENT_RASTER_SECONDARY_COLOR ) ostr << "GL_CURRENT_RASTER_SECONDARY_COLOR";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER
		else if ( en == GL_PIXEL_PACK_BUFFER ) ostr << "GL_PIXEL_PACK_BUFFER";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER
		else if ( en == GL_PIXEL_UNPACK_BUFFER ) ostr << "GL_PIXEL_UNPACK_BUFFER";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER_BINDING
		else if ( en == GL_PIXEL_PACK_BUFFER_BINDING ) ostr << "GL_PIXEL_PACK_BUFFER_BINDING";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
		else if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING ) ostr << "GL_PIXEL_UNPACK_BUFFER_BINDING";
	#endif
	#ifdef GL_FLOAT_MAT2x3
		else if ( en == GL_FLOAT_MAT2x3 ) ostr << "GL_FLOAT_MAT2x3";
	#endif
	#ifdef GL_FLOAT_MAT2x4
		else if ( en == GL_FLOAT_MAT2x4 ) ostr << "GL_FLOAT_MAT2x4";
	#endif
	#ifdef GL_FLOAT_MAT3x2
		else if ( en == GL_FLOAT_MAT3x2 ) ostr << "GL_FLOAT_MAT3x2";
	#endif
	#ifdef GL_FLOAT_MAT3x4
		else if ( en == GL_FLOAT_MAT3x4 ) ostr << "GL_FLOAT_MAT3x4";
	#endif
	#ifdef GL_FLOAT_MAT4x2
		else if ( en == GL_FLOAT_MAT4x2 ) ostr << "GL_FLOAT_MAT4x2";
	#endif
	#ifdef GL_FLOAT_MAT4x3
		else if ( en == GL_FLOAT_MAT4x3 ) ostr << "GL_FLOAT_MAT4x3";
	#endif
	#ifdef GL_SRGB
		else if ( en == GL_SRGB ) ostr << "GL_SRGB";
	#endif
	#ifdef GL_SRGB8
		else if ( en == GL_SRGB8 ) ostr << "GL_SRGB8";
	#endif
	#ifdef GL_SRGB_ALPHA
		else if ( en == GL_SRGB_ALPHA ) ostr << "GL_SRGB_ALPHA";
	#endif
	#ifdef GL_SRGB8_ALPHA8
		else if ( en == GL_SRGB8_ALPHA8 ) ostr << "GL_SRGB8_ALPHA8";
	#endif
	#ifdef GL_SLUMINANCE_ALPHA
		else if ( en == GL_SLUMINANCE_ALPHA ) ostr << "GL_SLUMINANCE_ALPHA";
	#endif
	#ifdef GL_SLUMINANCE8_ALPHA8
		else if ( en == GL_SLUMINANCE8_ALPHA8 ) ostr << "GL_SLUMINANCE8_ALPHA8";
	#endif
	#ifdef GL_SLUMINANCE
		else if ( en == GL_SLUMINANCE ) ostr << "GL_SLUMINANCE";
	#endif
	#ifdef GL_SLUMINANCE8
		else if ( en == GL_SLUMINANCE8 ) ostr << "GL_SLUMINANCE8";
	#endif
	#ifdef GL_COMPRESSED_SRGB
		else if ( en == GL_COMPRESSED_SRGB ) ostr << "GL_COMPRESSED_SRGB";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA
		else if ( en == GL_COMPRESSED_SRGB_ALPHA ) ostr << "GL_COMPRESSED_SRGB_ALPHA";
	#endif
	#ifdef GL_COMPRESSED_SLUMINANCE
		else if ( en == GL_COMPRESSED_SLUMINANCE ) ostr << "GL_COMPRESSED_SLUMINANCE";
	#endif
	#ifdef GL_COMPRESSED_SLUMINANCE_ALPHA
		else if ( en == GL_COMPRESSED_SLUMINANCE_ALPHA ) ostr << "GL_COMPRESSED_SLUMINANCE_ALPHA";
	#endif
	#ifdef GL_MAX_CLIP_DISTANCES
		else if ( en == GL_MAX_CLIP_DISTANCES ) ostr << "GL_MAX_CLIP_DISTANCES";
	#endif
	#ifdef GL_CLIP_DISTANCE5
		else if ( en == GL_CLIP_DISTANCE5 ) ostr << "GL_CLIP_DISTANCE5";
	#endif
	#ifdef GL_CLIP_DISTANCE1
		else if ( en == GL_CLIP_DISTANCE1 ) ostr << "GL_CLIP_DISTANCE1";
	#endif
	#ifdef GL_CLIP_DISTANCE3
		else if ( en == GL_CLIP_DISTANCE3 ) ostr << "GL_CLIP_DISTANCE3";
	#endif
	#ifdef GL_COMPARE_REF_TO_TEXTURE
		else if ( en == GL_COMPARE_REF_TO_TEXTURE ) ostr << "GL_COMPARE_REF_TO_TEXTURE";
	#endif
	#ifdef GL_CLIP_DISTANCE0
		else if ( en == GL_CLIP_DISTANCE0 ) ostr << "GL_CLIP_DISTANCE0";
	#endif
	#ifdef GL_CLIP_DISTANCE4
		else if ( en == GL_CLIP_DISTANCE4 ) ostr << "GL_CLIP_DISTANCE4";
	#endif
	#ifdef GL_CLIP_DISTANCE2
		else if ( en == GL_CLIP_DISTANCE2 ) ostr << "GL_CLIP_DISTANCE2";
	#endif
	#ifdef GL_MAX_VARYING_COMPONENTS
		else if ( en == GL_MAX_VARYING_COMPONENTS ) ostr << "GL_MAX_VARYING_COMPONENTS";
	#endif
	#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
		else if ( en == GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT ) ostr << "GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT";
	#endif
	#ifdef GL_MAJOR_VERSION
		else if ( en == GL_MAJOR_VERSION ) ostr << "GL_MAJOR_VERSION";
	#endif
	#ifdef GL_MINOR_VERSION
		else if ( en == GL_MINOR_VERSION ) ostr << "GL_MINOR_VERSION";
	#endif
	#ifdef GL_NUM_EXTENSIONS
		else if ( en == GL_NUM_EXTENSIONS ) ostr << "GL_NUM_EXTENSIONS";
	#endif
	#ifdef GL_CONTEXT_FLAGS
		else if ( en == GL_CONTEXT_FLAGS ) ostr << "GL_CONTEXT_FLAGS";
	#endif
	#ifdef GL_DEPTH_BUFFER
		else if ( en == GL_DEPTH_BUFFER ) ostr << "GL_DEPTH_BUFFER";
	#endif
	#ifdef GL_STENCIL_BUFFER
		else if ( en == GL_STENCIL_BUFFER ) ostr << "GL_STENCIL_BUFFER";
	#endif
	#ifdef GL_RGBA32F
		else if ( en == GL_RGBA32F ) ostr << "GL_RGBA32F";
	#endif
	#ifdef GL_RGB32F
		else if ( en == GL_RGB32F ) ostr << "GL_RGB32F";
	#endif
	#ifdef GL_RGBA16F
		else if ( en == GL_RGBA16F ) ostr << "GL_RGBA16F";
	#endif
	#ifdef GL_RGB16F
		else if ( en == GL_RGB16F ) ostr << "GL_RGB16F";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER ) ostr << "GL_VERTEX_ATTRIB_ARRAY_INTEGER";
	#endif
	#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
		else if ( en == GL_MAX_ARRAY_TEXTURE_LAYERS ) ostr << "GL_MAX_ARRAY_TEXTURE_LAYERS";
	#endif
	#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
		else if ( en == GL_MIN_PROGRAM_TEXEL_OFFSET ) ostr << "GL_MIN_PROGRAM_TEXEL_OFFSET";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
		else if ( en == GL_MAX_PROGRAM_TEXEL_OFFSET ) ostr << "GL_MAX_PROGRAM_TEXEL_OFFSET";
	#endif
	#ifdef GL_CLAMP_VERTEX_COLOR
		else if ( en == GL_CLAMP_VERTEX_COLOR ) ostr << "GL_CLAMP_VERTEX_COLOR";
	#endif
	#ifdef GL_CLAMP_FRAGMENT_COLOR
		else if ( en == GL_CLAMP_FRAGMENT_COLOR ) ostr << "GL_CLAMP_FRAGMENT_COLOR";
	#endif
	#ifdef GL_CLAMP_READ_COLOR
		else if ( en == GL_CLAMP_READ_COLOR ) ostr << "GL_CLAMP_READ_COLOR";
	#endif
	#ifdef GL_FIXED_ONLY
		else if ( en == GL_FIXED_ONLY ) ostr << "GL_FIXED_ONLY";
	#endif
	#ifdef GL_TEXTURE_RED_TYPE
		else if ( en == GL_TEXTURE_RED_TYPE ) ostr << "GL_TEXTURE_RED_TYPE";
	#endif
	#ifdef GL_TEXTURE_GREEN_TYPE
		else if ( en == GL_TEXTURE_GREEN_TYPE ) ostr << "GL_TEXTURE_GREEN_TYPE";
	#endif
	#ifdef GL_TEXTURE_BLUE_TYPE
		else if ( en == GL_TEXTURE_BLUE_TYPE ) ostr << "GL_TEXTURE_BLUE_TYPE";
	#endif
	#ifdef GL_TEXTURE_ALPHA_TYPE
		else if ( en == GL_TEXTURE_ALPHA_TYPE ) ostr << "GL_TEXTURE_ALPHA_TYPE";
	#endif
	#ifdef GL_TEXTURE_LUMINANCE_TYPE
		else if ( en == GL_TEXTURE_LUMINANCE_TYPE ) ostr << "GL_TEXTURE_LUMINANCE_TYPE";
	#endif
	#ifdef GL_TEXTURE_INTENSITY_TYPE
		else if ( en == GL_TEXTURE_INTENSITY_TYPE ) ostr << "GL_TEXTURE_INTENSITY_TYPE";
	#endif
	#ifdef GL_TEXTURE_DEPTH_TYPE
		else if ( en == GL_TEXTURE_DEPTH_TYPE ) ostr << "GL_TEXTURE_DEPTH_TYPE";
	#endif
	#ifdef GL_TEXTURE_1D_ARRAY
		else if ( en == GL_TEXTURE_1D_ARRAY ) ostr << "GL_TEXTURE_1D_ARRAY";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D_ARRAY
		else if ( en == GL_PROXY_TEXTURE_1D_ARRAY ) ostr << "GL_PROXY_TEXTURE_1D_ARRAY";
	#endif
	#ifdef GL_TEXTURE_2D_ARRAY
		else if ( en == GL_TEXTURE_2D_ARRAY ) ostr << "GL_TEXTURE_2D_ARRAY";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_ARRAY
		else if ( en == GL_PROXY_TEXTURE_2D_ARRAY ) ostr << "GL_PROXY_TEXTURE_2D_ARRAY";
	#endif
	#ifdef GL_TEXTURE_BINDING_1D_ARRAY
		else if ( en == GL_TEXTURE_BINDING_1D_ARRAY ) ostr << "GL_TEXTURE_BINDING_1D_ARRAY";
	#endif
	#ifdef GL_TEXTURE_BINDING_2D_ARRAY
		else if ( en == GL_TEXTURE_BINDING_2D_ARRAY ) ostr << "GL_TEXTURE_BINDING_2D_ARRAY";
	#endif
	#ifdef GL_R11F_G11F_B10F
		else if ( en == GL_R11F_G11F_B10F ) ostr << "GL_R11F_G11F_B10F";
	#endif
	#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
		else if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV ) ostr << "GL_UNSIGNED_INT_10F_11F_11F_REV";
	#endif
	#ifdef GL_RGB9_E5
		else if ( en == GL_RGB9_E5 ) ostr << "GL_RGB9_E5";
	#endif
	#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
		else if ( en == GL_UNSIGNED_INT_5_9_9_9_REV ) ostr << "GL_UNSIGNED_INT_5_9_9_9_REV";
	#endif
	#ifdef GL_TEXTURE_SHARED_SIZE
		else if ( en == GL_TEXTURE_SHARED_SIZE ) ostr << "GL_TEXTURE_SHARED_SIZE";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH ) ostr << "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_MODE";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS ) ostr << "GL_TRANSFORM_FEEDBACK_VARYINGS";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_START";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE";
	#endif
	#ifdef GL_PRIMITIVES_GENERATED
		else if ( en == GL_PRIMITIVES_GENERATED ) ostr << "GL_PRIMITIVES_GENERATED";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
		else if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN ) ostr << "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN";
	#endif
	#ifdef GL_RASTERIZER_DISCARD
		else if ( en == GL_RASTERIZER_DISCARD ) ostr << "GL_RASTERIZER_DISCARD";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS";
	#endif
	#ifdef GL_INTERLEAVED_ATTRIBS
		else if ( en == GL_INTERLEAVED_ATTRIBS ) ostr << "GL_INTERLEAVED_ATTRIBS";
	#endif
	#ifdef GL_SEPARATE_ATTRIBS
		else if ( en == GL_SEPARATE_ATTRIBS ) ostr << "GL_SEPARATE_ATTRIBS";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
	#endif
	#ifdef GL_RGBA32UI
		else if ( en == GL_RGBA32UI ) ostr << "GL_RGBA32UI";
	#endif
	#ifdef GL_RGB32UI
		else if ( en == GL_RGB32UI ) ostr << "GL_RGB32UI";
	#endif
	#ifdef GL_RGBA16UI
		else if ( en == GL_RGBA16UI ) ostr << "GL_RGBA16UI";
	#endif
	#ifdef GL_RGB16UI
		else if ( en == GL_RGB16UI ) ostr << "GL_RGB16UI";
	#endif
	#ifdef GL_RGBA8UI
		else if ( en == GL_RGBA8UI ) ostr << "GL_RGBA8UI";
	#endif
	#ifdef GL_RGB8UI
		else if ( en == GL_RGB8UI ) ostr << "GL_RGB8UI";
	#endif
	#ifdef GL_RGBA32I
		else if ( en == GL_RGBA32I ) ostr << "GL_RGBA32I";
	#endif
	#ifdef GL_RGB32I
		else if ( en == GL_RGB32I ) ostr << "GL_RGB32I";
	#endif
	#ifdef GL_RGBA16I
		else if ( en == GL_RGBA16I ) ostr << "GL_RGBA16I";
	#endif
	#ifdef GL_RGB16I
		else if ( en == GL_RGB16I ) ostr << "GL_RGB16I";
	#endif
	#ifdef GL_RGBA8I
		else if ( en == GL_RGBA8I ) ostr << "GL_RGBA8I";
	#endif
	#ifdef GL_RGB8I
		else if ( en == GL_RGB8I ) ostr << "GL_RGB8I";
	#endif
	#ifdef GL_RED_INTEGER
		else if ( en == GL_RED_INTEGER ) ostr << "GL_RED_INTEGER";
	#endif
	#ifdef GL_GREEN_INTEGER
		else if ( en == GL_GREEN_INTEGER ) ostr << "GL_GREEN_INTEGER";
	#endif
	#ifdef GL_BLUE_INTEGER
		else if ( en == GL_BLUE_INTEGER ) ostr << "GL_BLUE_INTEGER";
	#endif
	#ifdef GL_ALPHA_INTEGER
		else if ( en == GL_ALPHA_INTEGER ) ostr << "GL_ALPHA_INTEGER";
	#endif
	#ifdef GL_RGB_INTEGER
		else if ( en == GL_RGB_INTEGER ) ostr << "GL_RGB_INTEGER";
	#endif
	#ifdef GL_RGBA_INTEGER
		else if ( en == GL_RGBA_INTEGER ) ostr << "GL_RGBA_INTEGER";
	#endif
	#ifdef GL_BGR_INTEGER
		else if ( en == GL_BGR_INTEGER ) ostr << "GL_BGR_INTEGER";
	#endif
	#ifdef GL_BGRA_INTEGER
		else if ( en == GL_BGRA_INTEGER ) ostr << "GL_BGRA_INTEGER";
	#endif
	#ifdef GL_SAMPLER_1D_ARRAY
		else if ( en == GL_SAMPLER_1D_ARRAY ) ostr << "GL_SAMPLER_1D_ARRAY";
	#endif
	#ifdef GL_SAMPLER_2D_ARRAY
		else if ( en == GL_SAMPLER_2D_ARRAY ) ostr << "GL_SAMPLER_2D_ARRAY";
	#endif
	#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
		else if ( en == GL_SAMPLER_1D_ARRAY_SHADOW ) ostr << "GL_SAMPLER_1D_ARRAY_SHADOW";
	#endif
	#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
		else if ( en == GL_SAMPLER_2D_ARRAY_SHADOW ) ostr << "GL_SAMPLER_2D_ARRAY_SHADOW";
	#endif
	#ifdef GL_SAMPLER_CUBE_SHADOW
		else if ( en == GL_SAMPLER_CUBE_SHADOW ) ostr << "GL_SAMPLER_CUBE_SHADOW";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC2
		else if ( en == GL_UNSIGNED_INT_VEC2 ) ostr << "GL_UNSIGNED_INT_VEC2";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC3
		else if ( en == GL_UNSIGNED_INT_VEC3 ) ostr << "GL_UNSIGNED_INT_VEC3";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC4
		else if ( en == GL_UNSIGNED_INT_VEC4 ) ostr << "GL_UNSIGNED_INT_VEC4";
	#endif
	#ifdef GL_INT_SAMPLER_1D
		else if ( en == GL_INT_SAMPLER_1D ) ostr << "GL_INT_SAMPLER_1D";
	#endif
	#ifdef GL_INT_SAMPLER_2D
		else if ( en == GL_INT_SAMPLER_2D ) ostr << "GL_INT_SAMPLER_2D";
	#endif
	#ifdef GL_INT_SAMPLER_3D
		else if ( en == GL_INT_SAMPLER_3D ) ostr << "GL_INT_SAMPLER_3D";
	#endif
	#ifdef GL_INT_SAMPLER_CUBE
		else if ( en == GL_INT_SAMPLER_CUBE ) ostr << "GL_INT_SAMPLER_CUBE";
	#endif
	#ifdef GL_INT_SAMPLER_1D_ARRAY
		else if ( en == GL_INT_SAMPLER_1D_ARRAY ) ostr << "GL_INT_SAMPLER_1D_ARRAY";
	#endif
	#ifdef GL_INT_SAMPLER_2D_ARRAY
		else if ( en == GL_INT_SAMPLER_2D_ARRAY ) ostr << "GL_INT_SAMPLER_2D_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_1D
		else if ( en == GL_UNSIGNED_INT_SAMPLER_1D ) ostr << "GL_UNSIGNED_INT_SAMPLER_1D";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_3D
		else if ( en == GL_UNSIGNED_INT_SAMPLER_3D ) ostr << "GL_UNSIGNED_INT_SAMPLER_3D";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
		else if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE ) ostr << "GL_UNSIGNED_INT_SAMPLER_CUBE";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
		else if ( en == GL_UNSIGNED_INT_SAMPLER_1D_ARRAY ) ostr << "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_ARRAY ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY";
	#endif
	#ifdef GL_QUERY_WAIT
		else if ( en == GL_QUERY_WAIT ) ostr << "GL_QUERY_WAIT";
	#endif
	#ifdef GL_QUERY_NO_WAIT
		else if ( en == GL_QUERY_NO_WAIT ) ostr << "GL_QUERY_NO_WAIT";
	#endif
	#ifdef GL_QUERY_BY_REGION_WAIT
		else if ( en == GL_QUERY_BY_REGION_WAIT ) ostr << "GL_QUERY_BY_REGION_WAIT";
	#endif
	#ifdef GL_QUERY_BY_REGION_NO_WAIT
		else if ( en == GL_QUERY_BY_REGION_NO_WAIT ) ostr << "GL_QUERY_BY_REGION_NO_WAIT";
	#endif
	#ifdef GL_TEXTURE_RECTANGLE
		else if ( en == GL_TEXTURE_RECTANGLE ) ostr << "GL_TEXTURE_RECTANGLE";
	#endif
	#ifdef GL_TEXTURE_BINDING_RECTANGLE
		else if ( en == GL_TEXTURE_BINDING_RECTANGLE ) ostr << "GL_TEXTURE_BINDING_RECTANGLE";
	#endif
	#ifdef GL_PROXY_TEXTURE_RECTANGLE
		else if ( en == GL_PROXY_TEXTURE_RECTANGLE ) ostr << "GL_PROXY_TEXTURE_RECTANGLE";
	#endif
	#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
		else if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE ) ostr << "GL_MAX_RECTANGLE_TEXTURE_SIZE";
	#endif
	#ifdef GL_SAMPLER_2D_RECT
		else if ( en == GL_SAMPLER_2D_RECT ) ostr << "GL_SAMPLER_2D_RECT";
	#endif
	#ifdef GL_SAMPLER_2D_RECT_SHADOW
		else if ( en == GL_SAMPLER_2D_RECT_SHADOW ) ostr << "GL_SAMPLER_2D_RECT_SHADOW";
	#endif
	#ifdef GL_TEXTURE_BUFFER
		else if ( en == GL_TEXTURE_BUFFER ) ostr << "GL_TEXTURE_BUFFER";
	#endif
	#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
		else if ( en == GL_MAX_TEXTURE_BUFFER_SIZE ) ostr << "GL_MAX_TEXTURE_BUFFER_SIZE";
	#endif
	#ifdef GL_TEXTURE_BINDING_BUFFER
		else if ( en == GL_TEXTURE_BINDING_BUFFER ) ostr << "GL_TEXTURE_BINDING_BUFFER";
	#endif
	#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
		else if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING ) ostr << "GL_TEXTURE_BUFFER_DATA_STORE_BINDING";
	#endif
	#ifdef GL_TEXTURE_BUFFER_FORMAT
		else if ( en == GL_TEXTURE_BUFFER_FORMAT ) ostr << "GL_TEXTURE_BUFFER_FORMAT";
	#endif
	#ifdef GL_SAMPLER_BUFFER
		else if ( en == GL_SAMPLER_BUFFER ) ostr << "GL_SAMPLER_BUFFER";
	#endif
	#ifdef GL_INT_SAMPLER_2D_RECT
		else if ( en == GL_INT_SAMPLER_2D_RECT ) ostr << "GL_INT_SAMPLER_2D_RECT";
	#endif
	#ifdef GL_INT_SAMPLER_BUFFER
		else if ( en == GL_INT_SAMPLER_BUFFER ) ostr << "GL_INT_SAMPLER_BUFFER";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_RECT ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_RECT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
		else if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER ) ostr << "GL_UNSIGNED_INT_SAMPLER_BUFFER";
	#endif
	#ifdef GL_RED_SNORM
		else if ( en == GL_RED_SNORM ) ostr << "GL_RED_SNORM";
	#endif
	#ifdef GL_RG_SNORM
		else if ( en == GL_RG_SNORM ) ostr << "GL_RG_SNORM";
	#endif
	#ifdef GL_RGB_SNORM
		else if ( en == GL_RGB_SNORM ) ostr << "GL_RGB_SNORM";
	#endif
	#ifdef GL_RGBA_SNORM
		else if ( en == GL_RGBA_SNORM ) ostr << "GL_RGBA_SNORM";
	#endif
	#ifdef GL_R8_SNORM
		else if ( en == GL_R8_SNORM ) ostr << "GL_R8_SNORM";
	#endif
	#ifdef GL_RG8_SNORM
		else if ( en == GL_RG8_SNORM ) ostr << "GL_RG8_SNORM";
	#endif
	#ifdef GL_RGB8_SNORM
		else if ( en == GL_RGB8_SNORM ) ostr << "GL_RGB8_SNORM";
	#endif
	#ifdef GL_RGBA8_SNORM
		else if ( en == GL_RGBA8_SNORM ) ostr << "GL_RGBA8_SNORM";
	#endif
	#ifdef GL_R16_SNORM
		else if ( en == GL_R16_SNORM ) ostr << "GL_R16_SNORM";
	#endif
	#ifdef GL_RG16_SNORM
		else if ( en == GL_RG16_SNORM ) ostr << "GL_RG16_SNORM";
	#endif
	#ifdef GL_RGB16_SNORM
		else if ( en == GL_RGB16_SNORM ) ostr << "GL_RGB16_SNORM";
	#endif
	#ifdef GL_RGBA16_SNORM
		else if ( en == GL_RGBA16_SNORM ) ostr << "GL_RGBA16_SNORM";
	#endif
	#ifdef GL_SIGNED_NORMALIZED
		else if ( en == GL_SIGNED_NORMALIZED ) ostr << "GL_SIGNED_NORMALIZED";
	#endif
	#ifdef GL_PRIMITIVE_RESTART
		else if ( en == GL_PRIMITIVE_RESTART ) ostr << "GL_PRIMITIVE_RESTART";
	#endif
	#ifdef GL_PRIMITIVE_RESTART_INDEX
		else if ( en == GL_PRIMITIVE_RESTART_INDEX ) ostr << "GL_PRIMITIVE_RESTART_INDEX";
	#endif
	#ifdef GL_BUFFER_ACCESS_FLAGS
		else if ( en == GL_BUFFER_ACCESS_FLAGS ) ostr << "GL_BUFFER_ACCESS_FLAGS";
	#endif
	#ifdef GL_BUFFER_MAP_LENGTH
		else if ( en == GL_BUFFER_MAP_LENGTH ) ostr << "GL_BUFFER_MAP_LENGTH";
	#endif
	#ifdef GL_BUFFER_MAP_OFFSET
		else if ( en == GL_BUFFER_MAP_OFFSET ) ostr << "GL_BUFFER_MAP_OFFSET";
	#endif
	#ifdef GL_CONTEXT_CORE_PROFILE_BIT
		else if ( en == GL_CONTEXT_CORE_PROFILE_BIT ) ostr << "GL_CONTEXT_CORE_PROFILE_BIT";
	#endif
	#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
		else if ( en == GL_CONTEXT_COMPATIBILITY_PROFILE_BIT ) ostr << "GL_CONTEXT_COMPATIBILITY_PROFILE_BIT";
	#endif
	#ifdef GL_LINES_ADJACENCY
		else if ( en == GL_LINES_ADJACENCY ) ostr << "GL_LINES_ADJACENCY";
	#endif
	#ifdef GL_LINE_STRIP_ADJACENCY
		else if ( en == GL_LINE_STRIP_ADJACENCY ) ostr << "GL_LINE_STRIP_ADJACENCY";
	#endif
	#ifdef GL_TRIANGLES_ADJACENCY
		else if ( en == GL_TRIANGLES_ADJACENCY ) ostr << "GL_TRIANGLES_ADJACENCY";
	#endif
	#ifdef GL_TRIANGLE_STRIP_ADJACENCY
		else if ( en == GL_TRIANGLE_STRIP_ADJACENCY ) ostr << "GL_TRIANGLE_STRIP_ADJACENCY";
	#endif
	#ifdef GL_PROGRAM_POINT_SIZE
		else if ( en == GL_PROGRAM_POINT_SIZE ) ostr << "GL_PROGRAM_POINT_SIZE";
	#endif
	#ifdef GL_GEOMETRY_VERTICES_OUT
		else if ( en == GL_GEOMETRY_VERTICES_OUT ) ostr << "GL_GEOMETRY_VERTICES_OUT";
	#endif
	#ifdef GL_GEOMETRY_INPUT_TYPE
		else if ( en == GL_GEOMETRY_INPUT_TYPE ) ostr << "GL_GEOMETRY_INPUT_TYPE";
	#endif
	#ifdef GL_GEOMETRY_OUTPUT_TYPE
		else if ( en == GL_GEOMETRY_OUTPUT_TYPE ) ostr << "GL_GEOMETRY_OUTPUT_TYPE";
	#endif
	#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_LAYERED";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS";
	#endif
	#ifdef GL_GEOMETRY_SHADER
		else if ( en == GL_GEOMETRY_SHADER ) ostr << "GL_GEOMETRY_SHADER";
	#endif
	#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS ) ostr << "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
		else if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES ) ostr << "GL_MAX_GEOMETRY_OUTPUT_VERTICES";
	#endif
	#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS ) ostr << "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_VERTEX_OUTPUT_COMPONENTS ) ostr << "GL_MAX_VERTEX_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
		else if ( en == GL_MAX_GEOMETRY_INPUT_COMPONENTS ) ostr << "GL_MAX_GEOMETRY_INPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_GEOMETRY_OUTPUT_COMPONENTS ) ostr << "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
		else if ( en == GL_MAX_FRAGMENT_INPUT_COMPONENTS ) ostr << "GL_MAX_FRAGMENT_INPUT_COMPONENTS";
	#endif
	#ifdef GL_CONTEXT_PROFILE_MASK
		else if ( en == GL_CONTEXT_PROFILE_MASK ) ostr << "GL_CONTEXT_PROFILE_MASK";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR ) ostr << "GL_VERTEX_ATTRIB_ARRAY_DIVISOR";
	#endif
	#ifdef GL_RGB10_A2UI
		else if ( en == GL_RGB10_A2UI ) ostr << "GL_RGB10_A2UI";
	#endif
	#ifdef GL_SAMPLE_SHADING
		else if ( en == GL_SAMPLE_SHADING ) ostr << "GL_SAMPLE_SHADING";
	#endif
	#ifdef GL_MIN_SAMPLE_SHADING_VALUE
		else if ( en == GL_MIN_SAMPLE_SHADING_VALUE ) ostr << "GL_MIN_SAMPLE_SHADING_VALUE";
	#endif
	#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
		else if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET ) ostr << "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
		else if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET ) ostr << "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS
		else if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS ) ostr << "GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
		else if ( en == GL_TEXTURE_CUBE_MAP_ARRAY ) ostr << "GL_TEXTURE_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
		else if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARRAY ) ostr << "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARRAY
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARRAY ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
		else if ( en == GL_SAMPLER_CUBE_MAP_ARRAY ) ostr << "GL_SAMPLER_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
		else if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW ) ostr << "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW";
	#endif
	#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
		else if ( en == GL_INT_SAMPLER_CUBE_MAP_ARRAY ) ostr << "GL_INT_SAMPLER_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
		else if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY ) ostr << "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
		else if ( en == GL_COMPRESSED_RGBA_BPTC_UNORM ) ostr << "GL_COMPRESSED_RGBA_BPTC_UNORM";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM ) ostr << "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM";
	#endif
	#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
		else if ( en == GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT ) ostr << "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT";
	#endif
	#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
		else if ( en == GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT ) ostr << "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT";
	#endif
	#ifdef GL_NUM_SHADING_LANGUAGE_VERSIONS
		else if ( en == GL_NUM_SHADING_LANGUAGE_VERSIONS ) ostr << "GL_NUM_SHADING_LANGUAGE_VERSIONS";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_LONG
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_LONG ) ostr << "GL_VERTEX_ATTRIB_ARRAY_LONG";
	#endif
	#ifdef GL_MAX_VERTEX_ATTRIB_STRIDE
		else if ( en == GL_MAX_VERTEX_ATTRIB_STRIDE ) ostr << "GL_MAX_VERTEX_ATTRIB_STRIDE";
	#endif
	#ifdef GL_MULTISAMPLE_3DFX
		else if ( en == GL_MULTISAMPLE_3DFX ) ostr << "GL_MULTISAMPLE_3DFX";
	#endif
	#ifdef GL_SAMPLE_BUFFERS_3DFX
		else if ( en == GL_SAMPLE_BUFFERS_3DFX ) ostr << "GL_SAMPLE_BUFFERS_3DFX";
	#endif
	#ifdef GL_SAMPLES_3DFX
		else if ( en == GL_SAMPLES_3DFX ) ostr << "GL_SAMPLES_3DFX";
	#endif
	#ifdef GL_MULTISAMPLE_BIT_3DFX
		else if ( en == GL_MULTISAMPLE_BIT_3DFX ) ostr << "GL_MULTISAMPLE_BIT_3DFX";
	#endif
	#ifdef GL_COMPRESSED_RGB_FXT1_3DFX
		else if ( en == GL_COMPRESSED_RGB_FXT1_3DFX ) ostr << "GL_COMPRESSED_RGB_FXT1_3DFX";
	#endif
	#ifdef GL_COMPRESSED_RGBA_FXT1_3DFX
		else if ( en == GL_COMPRESSED_RGBA_FXT1_3DFX ) ostr << "GL_COMPRESSED_RGBA_FXT1_3DFX";
	#endif
	#ifdef GL_FACTOR_MIN_AMD
		else if ( en == GL_FACTOR_MIN_AMD ) ostr << "GL_FACTOR_MIN_AMD";
	#endif
	#ifdef GL_FACTOR_MAX_AMD
		else if ( en == GL_FACTOR_MAX_AMD ) ostr << "GL_FACTOR_MAX_AMD";
	#endif
	#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH_AMD
		else if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH_AMD ) ostr << "GL_MAX_DEBUG_MESSAGE_LENGTH_AMD";
	#endif
	#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES_AMD
		else if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES_AMD ) ostr << "GL_MAX_DEBUG_LOGGED_MESSAGES_AMD";
	#endif
	#ifdef GL_DEBUG_LOGGED_MESSAGES_AMD
		else if ( en == GL_DEBUG_LOGGED_MESSAGES_AMD ) ostr << "GL_DEBUG_LOGGED_MESSAGES_AMD";
	#endif
	#ifdef GL_DEBUG_SEVERITY_HIGH_AMD
		else if ( en == GL_DEBUG_SEVERITY_HIGH_AMD ) ostr << "GL_DEBUG_SEVERITY_HIGH_AMD";
	#endif
	#ifdef GL_DEBUG_SEVERITY_MEDIUM_AMD
		else if ( en == GL_DEBUG_SEVERITY_MEDIUM_AMD ) ostr << "GL_DEBUG_SEVERITY_MEDIUM_AMD";
	#endif
	#ifdef GL_DEBUG_SEVERITY_LOW_AMD
		else if ( en == GL_DEBUG_SEVERITY_LOW_AMD ) ostr << "GL_DEBUG_SEVERITY_LOW_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_API_ERROR_AMD
		else if ( en == GL_DEBUG_CATEGORY_API_ERROR_AMD ) ostr << "GL_DEBUG_CATEGORY_API_ERROR_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD
		else if ( en == GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD ) ostr << "GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_DEPRECATION_AMD
		else if ( en == GL_DEBUG_CATEGORY_DEPRECATION_AMD ) ostr << "GL_DEBUG_CATEGORY_DEPRECATION_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD
		else if ( en == GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD ) ostr << "GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_PERFORMANCE_AMD
		else if ( en == GL_DEBUG_CATEGORY_PERFORMANCE_AMD ) ostr << "GL_DEBUG_CATEGORY_PERFORMANCE_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD
		else if ( en == GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD ) ostr << "GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_APPLICATION_AMD
		else if ( en == GL_DEBUG_CATEGORY_APPLICATION_AMD ) ostr << "GL_DEBUG_CATEGORY_APPLICATION_AMD";
	#endif
	#ifdef GL_DEBUG_CATEGORY_OTHER_AMD
		else if ( en == GL_DEBUG_CATEGORY_OTHER_AMD ) ostr << "GL_DEBUG_CATEGORY_OTHER_AMD";
	#endif
	#ifdef GL_DEPTH_CLAMP_NEAR_AMD
		else if ( en == GL_DEPTH_CLAMP_NEAR_AMD ) ostr << "GL_DEPTH_CLAMP_NEAR_AMD";
	#endif
	#ifdef GL_DEPTH_CLAMP_FAR_AMD
		else if ( en == GL_DEPTH_CLAMP_FAR_AMD ) ostr << "GL_DEPTH_CLAMP_FAR_AMD";
	#endif
	#ifdef GL_RED
		else if ( en == GL_RED ) ostr << "GL_RED";
	#endif
	#ifdef GL_GREEN
		else if ( en == GL_GREEN ) ostr << "GL_GREEN";
	#endif
	#ifdef GL_BLUE
		else if ( en == GL_BLUE ) ostr << "GL_BLUE";
	#endif
	#ifdef GL_ALPHA
		else if ( en == GL_ALPHA ) ostr << "GL_ALPHA";
	#endif
	#ifdef GL_RG8UI
		else if ( en == GL_RG8UI ) ostr << "GL_RG8UI";
	#endif
	#ifdef GL_RG16UI
		else if ( en == GL_RG16UI ) ostr << "GL_RG16UI";
	#endif
	#ifdef GL_RGBA8UI
		else if ( en == GL_RGBA8UI ) ostr << "GL_RGBA8UI";
	#endif
	#ifdef GL_VERTEX_ELEMENT_SWIZZLE_AMD
		else if ( en == GL_VERTEX_ELEMENT_SWIZZLE_AMD ) ostr << "GL_VERTEX_ELEMENT_SWIZZLE_AMD";
	#endif
	#ifdef GL_VERTEX_ID_SWIZZLE_AMD
		else if ( en == GL_VERTEX_ID_SWIZZLE_AMD ) ostr << "GL_VERTEX_ID_SWIZZLE_AMD";
	#endif
	#ifdef GL_DATA_BUFFER_AMD
		else if ( en == GL_DATA_BUFFER_AMD ) ostr << "GL_DATA_BUFFER_AMD";
	#endif
	#ifdef GL_PERFORMANCE_MONITOR_AMD
		else if ( en == GL_PERFORMANCE_MONITOR_AMD ) ostr << "GL_PERFORMANCE_MONITOR_AMD";
	#endif
	#ifdef GL_QUERY_OBJECT_AMD
		else if ( en == GL_QUERY_OBJECT_AMD ) ostr << "GL_QUERY_OBJECT_AMD";
	#endif
	#ifdef GL_VERTEX_ARRAY_OBJECT_AMD
		else if ( en == GL_VERTEX_ARRAY_OBJECT_AMD ) ostr << "GL_VERTEX_ARRAY_OBJECT_AMD";
	#endif
	#ifdef GL_SAMPLER_OBJECT_AMD
		else if ( en == GL_SAMPLER_OBJECT_AMD ) ostr << "GL_SAMPLER_OBJECT_AMD";
	#endif
	#ifdef GL_COUNTER_TYPE_AMD
		else if ( en == GL_COUNTER_TYPE_AMD ) ostr << "GL_COUNTER_TYPE_AMD";
	#endif
	#ifdef GL_COUNTER_RANGE_AMD
		else if ( en == GL_COUNTER_RANGE_AMD ) ostr << "GL_COUNTER_RANGE_AMD";
	#endif
	#ifdef GL_UNSIGNED_INT64_AMD
		else if ( en == GL_UNSIGNED_INT64_AMD ) ostr << "GL_UNSIGNED_INT64_AMD";
	#endif
	#ifdef GL_PERCENTAGE_AMD
		else if ( en == GL_PERCENTAGE_AMD ) ostr << "GL_PERCENTAGE_AMD";
	#endif
	#ifdef GL_PERFMON_RESULT_AVAILABLE_AMD
		else if ( en == GL_PERFMON_RESULT_AVAILABLE_AMD ) ostr << "GL_PERFMON_RESULT_AVAILABLE_AMD";
	#endif
	#ifdef GL_PERFMON_RESULT_SIZE_AMD
		else if ( en == GL_PERFMON_RESULT_SIZE_AMD ) ostr << "GL_PERFMON_RESULT_SIZE_AMD";
	#endif
	#ifdef GL_PERFMON_RESULT_AMD
		else if ( en == GL_PERFMON_RESULT_AMD ) ostr << "GL_PERFMON_RESULT_AMD";
	#endif
	#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
		else if ( en == GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD ) ostr << "GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD";
	#endif
	#ifdef GL_QUERY_BUFFER_AMD
		else if ( en == GL_QUERY_BUFFER_AMD ) ostr << "GL_QUERY_BUFFER_AMD";
	#endif
	#ifdef GL_QUERY_BUFFER_BINDING_AMD
		else if ( en == GL_QUERY_BUFFER_BINDING_AMD ) ostr << "GL_QUERY_BUFFER_BINDING_AMD";
	#endif
	#ifdef GL_QUERY_RESULT_NO_WAIT_AMD
		else if ( en == GL_QUERY_RESULT_NO_WAIT_AMD ) ostr << "GL_QUERY_RESULT_NO_WAIT_AMD";
	#endif
	#ifdef GL_SUBSAMPLE_DISTANCE_AMD
		else if ( en == GL_SUBSAMPLE_DISTANCE_AMD ) ostr << "GL_SUBSAMPLE_DISTANCE_AMD";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB";
	#endif
	#ifdef GL_TEXTURE_STORAGE_SPARSE_BIT_AMD
		else if ( en == GL_TEXTURE_STORAGE_SPARSE_BIT_AMD ) ostr << "GL_TEXTURE_STORAGE_SPARSE_BIT_AMD";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_X_AMD
		else if ( en == GL_VIRTUAL_PAGE_SIZE_X_AMD ) ostr << "GL_VIRTUAL_PAGE_SIZE_X_AMD";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_Y_AMD
		else if ( en == GL_VIRTUAL_PAGE_SIZE_Y_AMD ) ostr << "GL_VIRTUAL_PAGE_SIZE_Y_AMD";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_Z_AMD
		else if ( en == GL_VIRTUAL_PAGE_SIZE_Z_AMD ) ostr << "GL_VIRTUAL_PAGE_SIZE_Z_AMD";
	#endif
	#ifdef GL_MAX_SPARSE_TEXTURE_SIZE_AMD
		else if ( en == GL_MAX_SPARSE_TEXTURE_SIZE_AMD ) ostr << "GL_MAX_SPARSE_TEXTURE_SIZE_AMD";
	#endif
	#ifdef GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD
		else if ( en == GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD ) ostr << "GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD";
	#endif
	#ifdef GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS
		else if ( en == GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS ) ostr << "GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS";
	#endif
	#ifdef GL_MIN_SPARSE_LEVEL_AMD
		else if ( en == GL_MIN_SPARSE_LEVEL_AMD ) ostr << "GL_MIN_SPARSE_LEVEL_AMD";
	#endif
	#ifdef GL_MIN_LOD_WARNING_AMD
		else if ( en == GL_MIN_LOD_WARNING_AMD ) ostr << "GL_MIN_LOD_WARNING_AMD";
	#endif
	#ifdef GL_SET_AMD
		else if ( en == GL_SET_AMD ) ostr << "GL_SET_AMD";
	#endif
	#ifdef GL_REPLACE_VALUE_AMD
		else if ( en == GL_REPLACE_VALUE_AMD ) ostr << "GL_REPLACE_VALUE_AMD";
	#endif
	#ifdef GL_STENCIL_OP_VALUE_AMD
		else if ( en == GL_STENCIL_OP_VALUE_AMD ) ostr << "GL_STENCIL_OP_VALUE_AMD";
	#endif
	#ifdef GL_STENCIL_BACK_OP_VALUE_AMD
		else if ( en == GL_STENCIL_BACK_OP_VALUE_AMD ) ostr << "GL_STENCIL_BACK_OP_VALUE_AMD";
	#endif
	#ifdef GL_SAMPLER_BUFFER_AMD
		else if ( en == GL_SAMPLER_BUFFER_AMD ) ostr << "GL_SAMPLER_BUFFER_AMD";
	#endif
	#ifdef GL_INT_SAMPLER_BUFFER_AMD
		else if ( en == GL_INT_SAMPLER_BUFFER_AMD ) ostr << "GL_INT_SAMPLER_BUFFER_AMD";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD
		else if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD ) ostr << "GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD";
	#endif
	#ifdef GL_TESSELLATION_MODE_AMD
		else if ( en == GL_TESSELLATION_MODE_AMD ) ostr << "GL_TESSELLATION_MODE_AMD";
	#endif
	#ifdef GL_TESSELLATION_FACTOR_AMD
		else if ( en == GL_TESSELLATION_FACTOR_AMD ) ostr << "GL_TESSELLATION_FACTOR_AMD";
	#endif
	#ifdef GL_DISCRETE_AMD
		else if ( en == GL_DISCRETE_AMD ) ostr << "GL_DISCRETE_AMD";
	#endif
	#ifdef GL_CONTINUOUS_AMD
		else if ( en == GL_CONTINUOUS_AMD ) ostr << "GL_CONTINUOUS_AMD";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER_BINDING_ANGLE
		else if ( en == GL_DRAW_FRAMEBUFFER_BINDING_ANGLE ) ostr << "GL_DRAW_FRAMEBUFFER_BINDING_ANGLE";
	#endif
	#ifdef GL_READ_FRAMEBUFFER_ANGLE
		else if ( en == GL_READ_FRAMEBUFFER_ANGLE ) ostr << "GL_READ_FRAMEBUFFER_ANGLE";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER_ANGLE
		else if ( en == GL_DRAW_FRAMEBUFFER_ANGLE ) ostr << "GL_DRAW_FRAMEBUFFER_ANGLE";
	#endif
	#ifdef GL_READ_FRAMEBUFFER_BINDING_ANGLE
		else if ( en == GL_READ_FRAMEBUFFER_BINDING_ANGLE ) ostr << "GL_READ_FRAMEBUFFER_BINDING_ANGLE";
	#endif
	#ifdef GL_RENDERBUFFER_SAMPLES_ANGLE
		else if ( en == GL_RENDERBUFFER_SAMPLES_ANGLE ) ostr << "GL_RENDERBUFFER_SAMPLES_ANGLE";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE";
	#endif
	#ifdef GL_MAX_SAMPLES_ANGLE
		else if ( en == GL_MAX_SAMPLES_ANGLE ) ostr << "GL_MAX_SAMPLES_ANGLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE ) ostr << "GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE";
	#endif
	#ifdef GL_PACK_REVERSE_ROW_ORDER_ANGLE
		else if ( en == GL_PACK_REVERSE_ROW_ORDER_ANGLE ) ostr << "GL_PACK_REVERSE_ROW_ORDER_ANGLE";
	#endif
	#ifdef GL_PROGRAM_BINARY_ANGLE
		else if ( en == GL_PROGRAM_BINARY_ANGLE ) ostr << "GL_PROGRAM_BINARY_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
	#endif
	#ifdef GL_TEXTURE_USAGE_ANGLE
		else if ( en == GL_TEXTURE_USAGE_ANGLE ) ostr << "GL_TEXTURE_USAGE_ANGLE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_ANGLE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_ANGLE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_ANGLE";
	#endif
	#ifdef GL_QUERY_COUNTER_BITS_ANGLE
		else if ( en == GL_QUERY_COUNTER_BITS_ANGLE ) ostr << "GL_QUERY_COUNTER_BITS_ANGLE";
	#endif
	#ifdef GL_CURRENT_QUERY_ANGLE
		else if ( en == GL_CURRENT_QUERY_ANGLE ) ostr << "GL_CURRENT_QUERY_ANGLE";
	#endif
	#ifdef GL_QUERY_RESULT_ANGLE
		else if ( en == GL_QUERY_RESULT_ANGLE ) ostr << "GL_QUERY_RESULT_ANGLE";
	#endif
	#ifdef GL_QUERY_RESULT_AVAILABLE_ANGLE
		else if ( en == GL_QUERY_RESULT_AVAILABLE_ANGLE ) ostr << "GL_QUERY_RESULT_AVAILABLE_ANGLE";
	#endif
	#ifdef GL_TIME_ELAPSED_ANGLE
		else if ( en == GL_TIME_ELAPSED_ANGLE ) ostr << "GL_TIME_ELAPSED_ANGLE";
	#endif
	#ifdef GL_TIMESTAMP_ANGLE
		else if ( en == GL_TIMESTAMP_ANGLE ) ostr << "GL_TIMESTAMP_ANGLE";
	#endif
	#ifdef GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE
		else if ( en == GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE ) ostr << "GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE";
	#endif
	#ifdef GL_AUX_DEPTH_STENCIL_APPLE
		else if ( en == GL_AUX_DEPTH_STENCIL_APPLE ) ostr << "GL_AUX_DEPTH_STENCIL_APPLE";
	#endif
	#ifdef GL_UNPACK_CLIENT_STORAGE_APPLE
		else if ( en == GL_UNPACK_CLIENT_STORAGE_APPLE ) ostr << "GL_UNPACK_CLIENT_STORAGE_APPLE";
	#endif
	#ifdef GL_ELEMENT_ARRAY_APPLE
		else if ( en == GL_ELEMENT_ARRAY_APPLE ) ostr << "GL_ELEMENT_ARRAY_APPLE";
	#endif
	#ifdef GL_ELEMENT_ARRAY_TYPE_APPLE
		else if ( en == GL_ELEMENT_ARRAY_TYPE_APPLE ) ostr << "GL_ELEMENT_ARRAY_TYPE_APPLE";
	#endif
	#ifdef GL_ELEMENT_ARRAY_POINTER_APPLE
		else if ( en == GL_ELEMENT_ARRAY_POINTER_APPLE ) ostr << "GL_ELEMENT_ARRAY_POINTER_APPLE";
	#endif
	#ifdef GL_DRAW_PIXELS_APPLE
		else if ( en == GL_DRAW_PIXELS_APPLE ) ostr << "GL_DRAW_PIXELS_APPLE";
	#endif
	#ifdef GL_FENCE_APPLE
		else if ( en == GL_FENCE_APPLE ) ostr << "GL_FENCE_APPLE";
	#endif
	#ifdef GL_HALF_APPLE
		else if ( en == GL_HALF_APPLE ) ostr << "GL_HALF_APPLE";
	#endif
	#ifdef GL_RGBA_FLOAT32_APPLE
		else if ( en == GL_RGBA_FLOAT32_APPLE ) ostr << "GL_RGBA_FLOAT32_APPLE";
	#endif
	#ifdef GL_RGB_FLOAT32_APPLE
		else if ( en == GL_RGB_FLOAT32_APPLE ) ostr << "GL_RGB_FLOAT32_APPLE";
	#endif
	#ifdef GL_ALPHA_FLOAT32_APPLE
		else if ( en == GL_ALPHA_FLOAT32_APPLE ) ostr << "GL_ALPHA_FLOAT32_APPLE";
	#endif
	#ifdef GL_INTENSITY_FLOAT32_APPLE
		else if ( en == GL_INTENSITY_FLOAT32_APPLE ) ostr << "GL_INTENSITY_FLOAT32_APPLE";
	#endif
	#ifdef GL_LUMINANCE_FLOAT32_APPLE
		else if ( en == GL_LUMINANCE_FLOAT32_APPLE ) ostr << "GL_LUMINANCE_FLOAT32_APPLE";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_FLOAT32_APPLE
		else if ( en == GL_LUMINANCE_ALPHA_FLOAT32_APPLE ) ostr << "GL_LUMINANCE_ALPHA_FLOAT32_APPLE";
	#endif
	#ifdef GL_RGBA_FLOAT16_APPLE
		else if ( en == GL_RGBA_FLOAT16_APPLE ) ostr << "GL_RGBA_FLOAT16_APPLE";
	#endif
	#ifdef GL_RGB_FLOAT16_APPLE
		else if ( en == GL_RGB_FLOAT16_APPLE ) ostr << "GL_RGB_FLOAT16_APPLE";
	#endif
	#ifdef GL_ALPHA_FLOAT16_APPLE
		else if ( en == GL_ALPHA_FLOAT16_APPLE ) ostr << "GL_ALPHA_FLOAT16_APPLE";
	#endif
	#ifdef GL_INTENSITY_FLOAT16_APPLE
		else if ( en == GL_INTENSITY_FLOAT16_APPLE ) ostr << "GL_INTENSITY_FLOAT16_APPLE";
	#endif
	#ifdef GL_LUMINANCE_FLOAT16_APPLE
		else if ( en == GL_LUMINANCE_FLOAT16_APPLE ) ostr << "GL_LUMINANCE_FLOAT16_APPLE";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_FLOAT16_APPLE
		else if ( en == GL_LUMINANCE_ALPHA_FLOAT16_APPLE ) ostr << "GL_LUMINANCE_ALPHA_FLOAT16_APPLE";
	#endif
	#ifdef GL_COLOR_FLOAT_APPLE
		else if ( en == GL_COLOR_FLOAT_APPLE ) ostr << "GL_COLOR_FLOAT_APPLE";
	#endif
	#ifdef GL_BUFFER_SERIALIZED_MODIFY_APPLE
		else if ( en == GL_BUFFER_SERIALIZED_MODIFY_APPLE ) ostr << "GL_BUFFER_SERIALIZED_MODIFY_APPLE";
	#endif
	#ifdef GL_BUFFER_FLUSHING_UNMAP_APPLE
		else if ( en == GL_BUFFER_FLUSHING_UNMAP_APPLE ) ostr << "GL_BUFFER_FLUSHING_UNMAP_APPLE";
	#endif
	#ifdef GL_BUFFER_OBJECT_APPLE
		else if ( en == GL_BUFFER_OBJECT_APPLE ) ostr << "GL_BUFFER_OBJECT_APPLE";
	#endif
	#ifdef GL_RELEASED_APPLE
		else if ( en == GL_RELEASED_APPLE ) ostr << "GL_RELEASED_APPLE";
	#endif
	#ifdef GL_VOLATILE_APPLE
		else if ( en == GL_VOLATILE_APPLE ) ostr << "GL_VOLATILE_APPLE";
	#endif
	#ifdef GL_RETAINED_APPLE
		else if ( en == GL_RETAINED_APPLE ) ostr << "GL_RETAINED_APPLE";
	#endif
	#ifdef GL_UNDEFINED_APPLE
		else if ( en == GL_UNDEFINED_APPLE ) ostr << "GL_UNDEFINED_APPLE";
	#endif
	#ifdef GL_PURGEABLE_APPLE
		else if ( en == GL_PURGEABLE_APPLE ) ostr << "GL_PURGEABLE_APPLE";
	#endif
	#ifdef GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE
		else if ( en == GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE ) ostr << "GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE";
	#endif
	#ifdef GL_UNSIGNED_SHORT_8_8_APPLE
		else if ( en == GL_UNSIGNED_SHORT_8_8_APPLE ) ostr << "GL_UNSIGNED_SHORT_8_8_APPLE";
	#endif
	#ifdef GL_UNSIGNED_SHORT_8_8_REV_APPLE
		else if ( en == GL_UNSIGNED_SHORT_8_8_REV_APPLE ) ostr << "GL_UNSIGNED_SHORT_8_8_REV_APPLE";
	#endif
	#ifdef GL_RGB_422_APPLE
		else if ( en == GL_RGB_422_APPLE ) ostr << "GL_RGB_422_APPLE";
	#endif
	#ifdef GL_PACK_ROW_BYTES_APPLE
		else if ( en == GL_PACK_ROW_BYTES_APPLE ) ostr << "GL_PACK_ROW_BYTES_APPLE";
	#endif
	#ifdef GL_UNPACK_ROW_BYTES_APPLE
		else if ( en == GL_UNPACK_ROW_BYTES_APPLE ) ostr << "GL_UNPACK_ROW_BYTES_APPLE";
	#endif
	#ifdef GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE
		else if ( en == GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE ) ostr << "GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE";
	#endif
	#ifdef GL_TEXTURE_RANGE_LENGTH_APPLE
		else if ( en == GL_TEXTURE_RANGE_LENGTH_APPLE ) ostr << "GL_TEXTURE_RANGE_LENGTH_APPLE";
	#endif
	#ifdef GL_TEXTURE_RANGE_POINTER_APPLE
		else if ( en == GL_TEXTURE_RANGE_POINTER_APPLE ) ostr << "GL_TEXTURE_RANGE_POINTER_APPLE";
	#endif
	#ifdef GL_TEXTURE_STORAGE_HINT_APPLE
		else if ( en == GL_TEXTURE_STORAGE_HINT_APPLE ) ostr << "GL_TEXTURE_STORAGE_HINT_APPLE";
	#endif
	#ifdef GL_STORAGE_PRIVATE_APPLE
		else if ( en == GL_STORAGE_PRIVATE_APPLE ) ostr << "GL_STORAGE_PRIVATE_APPLE";
	#endif
	#ifdef GL_STORAGE_CACHED_APPLE
		else if ( en == GL_STORAGE_CACHED_APPLE ) ostr << "GL_STORAGE_CACHED_APPLE";
	#endif
	#ifdef GL_STORAGE_SHARED_APPLE
		else if ( en == GL_STORAGE_SHARED_APPLE ) ostr << "GL_STORAGE_SHARED_APPLE";
	#endif
	#ifdef GL_TRANSFORM_HINT_APPLE
		else if ( en == GL_TRANSFORM_HINT_APPLE ) ostr << "GL_TRANSFORM_HINT_APPLE";
	#endif
	#ifdef GL_VERTEX_ARRAY_BINDING_APPLE
		else if ( en == GL_VERTEX_ARRAY_BINDING_APPLE ) ostr << "GL_VERTEX_ARRAY_BINDING_APPLE";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_APPLE
		else if ( en == GL_VERTEX_ARRAY_RANGE_APPLE ) ostr << "GL_VERTEX_ARRAY_RANGE_APPLE";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE
		else if ( en == GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE ) ostr << "GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE";
	#endif
	#ifdef GL_VERTEX_ARRAY_STORAGE_HINT_APPLE
		else if ( en == GL_VERTEX_ARRAY_STORAGE_HINT_APPLE ) ostr << "GL_VERTEX_ARRAY_STORAGE_HINT_APPLE";
	#endif
	#ifdef GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE
		else if ( en == GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE ) ostr << "GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_POINTER_APPLE
		else if ( en == GL_VERTEX_ARRAY_RANGE_POINTER_APPLE ) ostr << "GL_VERTEX_ARRAY_RANGE_POINTER_APPLE";
	#endif
	#ifdef GL_STORAGE_CLIENT_APPLE
		else if ( en == GL_STORAGE_CLIENT_APPLE ) ostr << "GL_STORAGE_CLIENT_APPLE";
	#endif
	#ifdef GL_STORAGE_CACHED_APPLE
		else if ( en == GL_STORAGE_CACHED_APPLE ) ostr << "GL_STORAGE_CACHED_APPLE";
	#endif
	#ifdef GL_STORAGE_SHARED_APPLE
		else if ( en == GL_STORAGE_SHARED_APPLE ) ostr << "GL_STORAGE_SHARED_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP1_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP1_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP1_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP2_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP2_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP2_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE";
	#endif
	#ifdef GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE
		else if ( en == GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE ) ostr << "GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE";
	#endif
	#ifdef GL_YCBCR_422_APPLE
		else if ( en == GL_YCBCR_422_APPLE ) ostr << "GL_YCBCR_422_APPLE";
	#endif
	#ifdef GL_FIXED
		else if ( en == GL_FIXED ) ostr << "GL_FIXED";
	#endif
	#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
		else if ( en == GL_IMPLEMENTATION_COLOR_READ_TYPE ) ostr << "GL_IMPLEMENTATION_COLOR_READ_TYPE";
	#endif
	#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
		else if ( en == GL_IMPLEMENTATION_COLOR_READ_FORMAT ) ostr << "GL_IMPLEMENTATION_COLOR_READ_FORMAT";
	#endif
	#ifdef GL_RGB565
		else if ( en == GL_RGB565 ) ostr << "GL_RGB565";
	#endif
	#ifdef GL_LOW_FLOAT
		else if ( en == GL_LOW_FLOAT ) ostr << "GL_LOW_FLOAT";
	#endif
	#ifdef GL_MEDIUM_FLOAT
		else if ( en == GL_MEDIUM_FLOAT ) ostr << "GL_MEDIUM_FLOAT";
	#endif
	#ifdef GL_HIGH_FLOAT
		else if ( en == GL_HIGH_FLOAT ) ostr << "GL_HIGH_FLOAT";
	#endif
	#ifdef GL_LOW_INT
		else if ( en == GL_LOW_INT ) ostr << "GL_LOW_INT";
	#endif
	#ifdef GL_MEDIUM_INT
		else if ( en == GL_MEDIUM_INT ) ostr << "GL_MEDIUM_INT";
	#endif
	#ifdef GL_HIGH_INT
		else if ( en == GL_HIGH_INT ) ostr << "GL_HIGH_INT";
	#endif
	#ifdef GL_SHADER_BINARY_FORMATS
		else if ( en == GL_SHADER_BINARY_FORMATS ) ostr << "GL_SHADER_BINARY_FORMATS";
	#endif
	#ifdef GL_NUM_SHADER_BINARY_FORMATS
		else if ( en == GL_NUM_SHADER_BINARY_FORMATS ) ostr << "GL_NUM_SHADER_BINARY_FORMATS";
	#endif
	#ifdef GL_SHADER_COMPILER
		else if ( en == GL_SHADER_COMPILER ) ostr << "GL_SHADER_COMPILER";
	#endif
	#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
		else if ( en == GL_MAX_VERTEX_UNIFORM_VECTORS ) ostr << "GL_MAX_VERTEX_UNIFORM_VECTORS";
	#endif
	#ifdef GL_MAX_VARYING_VECTORS
		else if ( en == GL_MAX_VARYING_VECTORS ) ostr << "GL_MAX_VARYING_VECTORS";
	#endif
	#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
		else if ( en == GL_MAX_FRAGMENT_UNIFORM_VECTORS ) ostr << "GL_MAX_FRAGMENT_UNIFORM_VECTORS";
	#endif
	#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
		else if ( en == GL_TEXTURE_IMMUTABLE_LEVELS ) ostr << "GL_TEXTURE_IMMUTABLE_LEVELS";
	#endif
	#ifdef GL_PRIMITIVE_RESTART_FIXED_INDEX
		else if ( en == GL_PRIMITIVE_RESTART_FIXED_INDEX ) ostr << "GL_PRIMITIVE_RESTART_FIXED_INDEX";
	#endif
	#ifdef GL_ANY_SAMPLES_PASSED_CONSERVATIVE
		else if ( en == GL_ANY_SAMPLES_PASSED_CONSERVATIVE ) ostr << "GL_ANY_SAMPLES_PASSED_CONSERVATIVE";
	#endif
	#ifdef GL_MAX_ELEMENT_INDEX
		else if ( en == GL_MAX_ELEMENT_INDEX ) ostr << "GL_MAX_ELEMENT_INDEX";
	#endif
	#ifdef GL_COMPRESSED_R11_EAC
		else if ( en == GL_COMPRESSED_R11_EAC ) ostr << "GL_COMPRESSED_R11_EAC";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_R11_EAC
		else if ( en == GL_COMPRESSED_SIGNED_R11_EAC ) ostr << "GL_COMPRESSED_SIGNED_R11_EAC";
	#endif
	#ifdef GL_COMPRESSED_RG11_EAC
		else if ( en == GL_COMPRESSED_RG11_EAC ) ostr << "GL_COMPRESSED_RG11_EAC";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
		else if ( en == GL_COMPRESSED_SIGNED_RG11_EAC ) ostr << "GL_COMPRESSED_SIGNED_RG11_EAC";
	#endif
	#ifdef GL_COMPRESSED_RGB8_ETC2
		else if ( en == GL_COMPRESSED_RGB8_ETC2 ) ostr << "GL_COMPRESSED_RGB8_ETC2";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ETC2
		else if ( en == GL_COMPRESSED_SRGB8_ETC2 ) ostr << "GL_COMPRESSED_SRGB8_ETC2";
	#endif
	#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
		else if ( en == GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 ) ostr << "GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
		else if ( en == GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 ) ostr << "GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2";
	#endif
	#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
		else if ( en == GL_COMPRESSED_RGBA8_ETC2_EAC ) ostr << "GL_COMPRESSED_RGBA8_ETC2_EAC";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC";
	#endif
	#ifdef GL_UNSIGNED_INT64_ARB
		else if ( en == GL_UNSIGNED_INT64_ARB ) ostr << "GL_UNSIGNED_INT64_ARB";
	#endif
	#ifdef GL_SRC1_COLOR
		else if ( en == GL_SRC1_COLOR ) ostr << "GL_SRC1_COLOR";
	#endif
	#ifdef GL_ONE_MINUS_SRC1_COLOR
		else if ( en == GL_ONE_MINUS_SRC1_COLOR ) ostr << "GL_ONE_MINUS_SRC1_COLOR";
	#endif
	#ifdef GL_ONE_MINUS_SRC1_ALPHA
		else if ( en == GL_ONE_MINUS_SRC1_ALPHA ) ostr << "GL_ONE_MINUS_SRC1_ALPHA";
	#endif
	#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
		else if ( en == GL_MAX_DUAL_SOURCE_DRAW_BUFFERS ) ostr << "GL_MAX_DUAL_SOURCE_DRAW_BUFFERS";
	#endif
	#ifdef GL_MAP_READ_BIT
		else if ( en == GL_MAP_READ_BIT ) ostr << "GL_MAP_READ_BIT";
	#endif
	#ifdef GL_MAP_WRITE_BIT
		else if ( en == GL_MAP_WRITE_BIT ) ostr << "GL_MAP_WRITE_BIT";
	#endif
	#ifdef GL_MAP_PERSISTENT_BIT
		else if ( en == GL_MAP_PERSISTENT_BIT ) ostr << "GL_MAP_PERSISTENT_BIT";
	#endif
	#ifdef GL_MAP_COHERENT_BIT
		else if ( en == GL_MAP_COHERENT_BIT ) ostr << "GL_MAP_COHERENT_BIT";
	#endif
	#ifdef GL_DYNAMIC_STORAGE_BIT
		else if ( en == GL_DYNAMIC_STORAGE_BIT ) ostr << "GL_DYNAMIC_STORAGE_BIT";
	#endif
	#ifdef GL_CLIENT_STORAGE_BIT
		else if ( en == GL_CLIENT_STORAGE_BIT ) ostr << "GL_CLIENT_STORAGE_BIT";
	#endif
	#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
		else if ( en == GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT ) ostr << "GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT";
	#endif
	#ifdef GL_BUFFER_IMMUTABLE_STORAGE
		else if ( en == GL_BUFFER_IMMUTABLE_STORAGE ) ostr << "GL_BUFFER_IMMUTABLE_STORAGE";
	#endif
	#ifdef GL_BUFFER_STORAGE_FLAGS
		else if ( en == GL_BUFFER_STORAGE_FLAGS ) ostr << "GL_BUFFER_STORAGE_FLAGS";
	#endif
	#ifdef GL_SYNC_CL_EVENT_ARB
		else if ( en == GL_SYNC_CL_EVENT_ARB ) ostr << "GL_SYNC_CL_EVENT_ARB";
	#endif
	#ifdef GL_SYNC_CL_EVENT_COMPLETE_ARB
		else if ( en == GL_SYNC_CL_EVENT_COMPLETE_ARB ) ostr << "GL_SYNC_CL_EVENT_COMPLETE_ARB";
	#endif
	#ifdef GL_CLEAR_TEXTURE
		else if ( en == GL_CLEAR_TEXTURE ) ostr << "GL_CLEAR_TEXTURE";
	#endif
	#ifdef GL_RGBA_FLOAT_MODE_ARB
		else if ( en == GL_RGBA_FLOAT_MODE_ARB ) ostr << "GL_RGBA_FLOAT_MODE_ARB";
	#endif
	#ifdef GL_CLAMP_VERTEX_COLOR_ARB
		else if ( en == GL_CLAMP_VERTEX_COLOR_ARB ) ostr << "GL_CLAMP_VERTEX_COLOR_ARB";
	#endif
	#ifdef GL_CLAMP_FRAGMENT_COLOR_ARB
		else if ( en == GL_CLAMP_FRAGMENT_COLOR_ARB ) ostr << "GL_CLAMP_FRAGMENT_COLOR_ARB";
	#endif
	#ifdef GL_CLAMP_READ_COLOR_ARB
		else if ( en == GL_CLAMP_READ_COLOR_ARB ) ostr << "GL_CLAMP_READ_COLOR_ARB";
	#endif
	#ifdef GL_FIXED_ONLY_ARB
		else if ( en == GL_FIXED_ONLY_ARB ) ostr << "GL_FIXED_ONLY_ARB";
	#endif
	#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
		else if ( en == GL_UNPACK_COMPRESSED_BLOCK_WIDTH ) ostr << "GL_UNPACK_COMPRESSED_BLOCK_WIDTH";
	#endif
	#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
		else if ( en == GL_UNPACK_COMPRESSED_BLOCK_HEIGHT ) ostr << "GL_UNPACK_COMPRESSED_BLOCK_HEIGHT";
	#endif
	#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
		else if ( en == GL_UNPACK_COMPRESSED_BLOCK_DEPTH ) ostr << "GL_UNPACK_COMPRESSED_BLOCK_DEPTH";
	#endif
	#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
		else if ( en == GL_UNPACK_COMPRESSED_BLOCK_SIZE ) ostr << "GL_UNPACK_COMPRESSED_BLOCK_SIZE";
	#endif
	#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
		else if ( en == GL_PACK_COMPRESSED_BLOCK_WIDTH ) ostr << "GL_PACK_COMPRESSED_BLOCK_WIDTH";
	#endif
	#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
		else if ( en == GL_PACK_COMPRESSED_BLOCK_HEIGHT ) ostr << "GL_PACK_COMPRESSED_BLOCK_HEIGHT";
	#endif
	#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
		else if ( en == GL_PACK_COMPRESSED_BLOCK_DEPTH ) ostr << "GL_PACK_COMPRESSED_BLOCK_DEPTH";
	#endif
	#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
		else if ( en == GL_PACK_COMPRESSED_BLOCK_SIZE ) ostr << "GL_PACK_COMPRESSED_BLOCK_SIZE";
	#endif
	#ifdef GL_COMPUTE_SHADER_BIT
		else if ( en == GL_COMPUTE_SHADER_BIT ) ostr << "GL_COMPUTE_SHADER_BIT";
	#endif
	#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
		else if ( en == GL_MAX_COMPUTE_SHARED_MEMORY_SIZE ) ostr << "GL_MAX_COMPUTE_SHARED_MEMORY_SIZE";
	#endif
	#ifdef GL_MAX_COMPUTE_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMPUTE_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMPUTE_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_COMPUTE_ATOMIC_COUNTERS
		else if ( en == GL_MAX_COMPUTE_ATOMIC_COUNTERS ) ostr << "GL_MAX_COMPUTE_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_COMPUTE_WORK_GROUP_SIZE
		else if ( en == GL_COMPUTE_WORK_GROUP_SIZE ) ostr << "GL_COMPUTE_WORK_GROUP_SIZE";
	#endif
	#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
		else if ( en == GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS ) ostr << "GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER";
	#endif
	#ifdef GL_DISPATCH_INDIRECT_BUFFER
		else if ( en == GL_DISPATCH_INDIRECT_BUFFER ) ostr << "GL_DISPATCH_INDIRECT_BUFFER";
	#endif
	#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
		else if ( en == GL_DISPATCH_INDIRECT_BUFFER_BINDING ) ostr << "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
	#endif
	#ifdef GL_COMPUTE_SHADER
		else if ( en == GL_COMPUTE_SHADER ) ostr << "GL_COMPUTE_SHADER";
	#endif
	#ifdef GL_MAX_COMPUTE_UNIFORM_BLOCKS
		else if ( en == GL_MAX_COMPUTE_UNIFORM_BLOCKS ) ostr << "GL_MAX_COMPUTE_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_MAX_COMPUTE_IMAGE_UNIFORMS
		else if ( en == GL_MAX_COMPUTE_IMAGE_UNIFORMS ) ostr << "GL_MAX_COMPUTE_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
		else if ( en == GL_MAX_COMPUTE_WORK_GROUP_COUNT ) ostr << "GL_MAX_COMPUTE_WORK_GROUP_COUNT";
	#endif
	#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
		else if ( en == GL_MAX_COMPUTE_WORK_GROUP_SIZE ) ostr << "GL_MAX_COMPUTE_WORK_GROUP_SIZE";
	#endif
	#ifdef GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB
		else if ( en == GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB ) ostr << "GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB";
	#endif
	#ifdef GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB
		else if ( en == GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB ) ostr << "GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB";
	#endif
	#ifdef GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB
		else if ( en == GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB ) ostr << "GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB";
	#endif
	#ifdef GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB
		else if ( en == GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB ) ostr << "GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB";
	#endif
	#ifdef GL_COPY_READ_BUFFER
		else if ( en == GL_COPY_READ_BUFFER ) ostr << "GL_COPY_READ_BUFFER";
	#endif
	#ifdef GL_COPY_WRITE_BUFFER
		else if ( en == GL_COPY_WRITE_BUFFER ) ostr << "GL_COPY_WRITE_BUFFER";
	#endif
	#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB
		else if ( en == GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB ) ostr << "GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB";
	#endif
	#ifdef GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB
		else if ( en == GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB ) ostr << "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB";
	#endif
	#ifdef GL_DEBUG_CALLBACK_FUNCTION_ARB
		else if ( en == GL_DEBUG_CALLBACK_FUNCTION_ARB ) ostr << "GL_DEBUG_CALLBACK_FUNCTION_ARB";
	#endif
	#ifdef GL_DEBUG_CALLBACK_USER_PARAM_ARB
		else if ( en == GL_DEBUG_CALLBACK_USER_PARAM_ARB ) ostr << "GL_DEBUG_CALLBACK_USER_PARAM_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_API_ARB
		else if ( en == GL_DEBUG_SOURCE_API_ARB ) ostr << "GL_DEBUG_SOURCE_API_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB
		else if ( en == GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB ) ostr << "GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER_ARB
		else if ( en == GL_DEBUG_SOURCE_SHADER_COMPILER_ARB ) ostr << "GL_DEBUG_SOURCE_SHADER_COMPILER_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_THIRD_PARTY_ARB
		else if ( en == GL_DEBUG_SOURCE_THIRD_PARTY_ARB ) ostr << "GL_DEBUG_SOURCE_THIRD_PARTY_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_APPLICATION_ARB
		else if ( en == GL_DEBUG_SOURCE_APPLICATION_ARB ) ostr << "GL_DEBUG_SOURCE_APPLICATION_ARB";
	#endif
	#ifdef GL_DEBUG_SOURCE_OTHER_ARB
		else if ( en == GL_DEBUG_SOURCE_OTHER_ARB ) ostr << "GL_DEBUG_SOURCE_OTHER_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_ERROR_ARB
		else if ( en == GL_DEBUG_TYPE_ERROR_ARB ) ostr << "GL_DEBUG_TYPE_ERROR_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
		else if ( en == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB ) ostr << "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
		else if ( en == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB ) ostr << "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_PORTABILITY_ARB
		else if ( en == GL_DEBUG_TYPE_PORTABILITY_ARB ) ostr << "GL_DEBUG_TYPE_PORTABILITY_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_PERFORMANCE_ARB
		else if ( en == GL_DEBUG_TYPE_PERFORMANCE_ARB ) ostr << "GL_DEBUG_TYPE_PERFORMANCE_ARB";
	#endif
	#ifdef GL_DEBUG_TYPE_OTHER_ARB
		else if ( en == GL_DEBUG_TYPE_OTHER_ARB ) ostr << "GL_DEBUG_TYPE_OTHER_ARB";
	#endif
	#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH_ARB
		else if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH_ARB ) ostr << "GL_MAX_DEBUG_MESSAGE_LENGTH_ARB";
	#endif
	#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES_ARB
		else if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES_ARB ) ostr << "GL_MAX_DEBUG_LOGGED_MESSAGES_ARB";
	#endif
	#ifdef GL_DEBUG_LOGGED_MESSAGES_ARB
		else if ( en == GL_DEBUG_LOGGED_MESSAGES_ARB ) ostr << "GL_DEBUG_LOGGED_MESSAGES_ARB";
	#endif
	#ifdef GL_DEBUG_SEVERITY_HIGH_ARB
		else if ( en == GL_DEBUG_SEVERITY_HIGH_ARB ) ostr << "GL_DEBUG_SEVERITY_HIGH_ARB";
	#endif
	#ifdef GL_DEBUG_SEVERITY_MEDIUM_ARB
		else if ( en == GL_DEBUG_SEVERITY_MEDIUM_ARB ) ostr << "GL_DEBUG_SEVERITY_MEDIUM_ARB";
	#endif
	#ifdef GL_DEBUG_SEVERITY_LOW_ARB
		else if ( en == GL_DEBUG_SEVERITY_LOW_ARB ) ostr << "GL_DEBUG_SEVERITY_LOW_ARB";
	#endif
	#ifdef GL_DEPTH_COMPONENT32F
		else if ( en == GL_DEPTH_COMPONENT32F ) ostr << "GL_DEPTH_COMPONENT32F";
	#endif
	#ifdef GL_DEPTH32F_STENCIL8
		else if ( en == GL_DEPTH32F_STENCIL8 ) ostr << "GL_DEPTH32F_STENCIL8";
	#endif
	#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
		else if ( en == GL_FLOAT_32_UNSIGNED_INT_24_8_REV ) ostr << "GL_FLOAT_32_UNSIGNED_INT_24_8_REV";
	#endif
	#ifdef GL_DEPTH_CLAMP
		else if ( en == GL_DEPTH_CLAMP ) ostr << "GL_DEPTH_CLAMP";
	#endif
	#ifdef GL_DEPTH_COMPONENT16_ARB
		else if ( en == GL_DEPTH_COMPONENT16_ARB ) ostr << "GL_DEPTH_COMPONENT16_ARB";
	#endif
	#ifdef GL_DEPTH_COMPONENT24_ARB
		else if ( en == GL_DEPTH_COMPONENT24_ARB ) ostr << "GL_DEPTH_COMPONENT24_ARB";
	#endif
	#ifdef GL_DEPTH_COMPONENT32_ARB
		else if ( en == GL_DEPTH_COMPONENT32_ARB ) ostr << "GL_DEPTH_COMPONENT32_ARB";
	#endif
	#ifdef GL_TEXTURE_DEPTH_SIZE_ARB
		else if ( en == GL_TEXTURE_DEPTH_SIZE_ARB ) ostr << "GL_TEXTURE_DEPTH_SIZE_ARB";
	#endif
	#ifdef GL_DEPTH_TEXTURE_MODE_ARB
		else if ( en == GL_DEPTH_TEXTURE_MODE_ARB ) ostr << "GL_DEPTH_TEXTURE_MODE_ARB";
	#endif
	#ifdef GL_MAX_DRAW_BUFFERS_ARB
		else if ( en == GL_MAX_DRAW_BUFFERS_ARB ) ostr << "GL_MAX_DRAW_BUFFERS_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER0_ARB
		else if ( en == GL_DRAW_BUFFER0_ARB ) ostr << "GL_DRAW_BUFFER0_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER1_ARB
		else if ( en == GL_DRAW_BUFFER1_ARB ) ostr << "GL_DRAW_BUFFER1_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER2_ARB
		else if ( en == GL_DRAW_BUFFER2_ARB ) ostr << "GL_DRAW_BUFFER2_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER3_ARB
		else if ( en == GL_DRAW_BUFFER3_ARB ) ostr << "GL_DRAW_BUFFER3_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER4_ARB
		else if ( en == GL_DRAW_BUFFER4_ARB ) ostr << "GL_DRAW_BUFFER4_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER5_ARB
		else if ( en == GL_DRAW_BUFFER5_ARB ) ostr << "GL_DRAW_BUFFER5_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER6_ARB
		else if ( en == GL_DRAW_BUFFER6_ARB ) ostr << "GL_DRAW_BUFFER6_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER7_ARB
		else if ( en == GL_DRAW_BUFFER7_ARB ) ostr << "GL_DRAW_BUFFER7_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER8_ARB
		else if ( en == GL_DRAW_BUFFER8_ARB ) ostr << "GL_DRAW_BUFFER8_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER9_ARB
		else if ( en == GL_DRAW_BUFFER9_ARB ) ostr << "GL_DRAW_BUFFER9_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER10_ARB
		else if ( en == GL_DRAW_BUFFER10_ARB ) ostr << "GL_DRAW_BUFFER10_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER11_ARB
		else if ( en == GL_DRAW_BUFFER11_ARB ) ostr << "GL_DRAW_BUFFER11_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER12_ARB
		else if ( en == GL_DRAW_BUFFER12_ARB ) ostr << "GL_DRAW_BUFFER12_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER13_ARB
		else if ( en == GL_DRAW_BUFFER13_ARB ) ostr << "GL_DRAW_BUFFER13_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER14_ARB
		else if ( en == GL_DRAW_BUFFER14_ARB ) ostr << "GL_DRAW_BUFFER14_ARB";
	#endif
	#ifdef GL_DRAW_BUFFER15_ARB
		else if ( en == GL_DRAW_BUFFER15_ARB ) ostr << "GL_DRAW_BUFFER15_ARB";
	#endif
	#ifdef GL_DRAW_INDIRECT_BUFFER
		else if ( en == GL_DRAW_INDIRECT_BUFFER ) ostr << "GL_DRAW_INDIRECT_BUFFER";
	#endif
	#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
		else if ( en == GL_DRAW_INDIRECT_BUFFER_BINDING ) ostr << "GL_DRAW_INDIRECT_BUFFER_BINDING";
	#endif
	#ifdef GL_LOCATION_COMPONENT
		else if ( en == GL_LOCATION_COMPONENT ) ostr << "GL_LOCATION_COMPONENT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_INDEX ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_INDEX";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE";
	#endif
	#ifdef GL_MAX_UNIFORM_LOCATIONS
		else if ( en == GL_MAX_UNIFORM_LOCATIONS ) ostr << "GL_MAX_UNIFORM_LOCATIONS";
	#endif
	#ifdef GL_FRAGMENT_PROGRAM_ARB
		else if ( en == GL_FRAGMENT_PROGRAM_ARB ) ostr << "GL_FRAGMENT_PROGRAM_ARB";
	#endif
	#ifdef GL_PROGRAM_ALU_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_ALU_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_ALU_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_TEX_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_TEX_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_TEX_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_TEX_INDIRECTIONS_ARB
		else if ( en == GL_PROGRAM_TEX_INDIRECTIONS_ARB ) ostr << "GL_PROGRAM_TEX_INDIRECTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB
		else if ( en == GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB ) ostr << "GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB ) ostr << "GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB";
	#endif
	#ifdef GL_MAX_TEXTURE_COORDS_ARB
		else if ( en == GL_MAX_TEXTURE_COORDS_ARB ) ostr << "GL_MAX_TEXTURE_COORDS_ARB";
	#endif
	#ifdef GL_MAX_TEXTURE_IMAGE_UNITS_ARB
		else if ( en == GL_MAX_TEXTURE_IMAGE_UNITS_ARB ) ostr << "GL_MAX_TEXTURE_IMAGE_UNITS_ARB";
	#endif
	#ifdef GL_FRAGMENT_SHADER_ARB
		else if ( en == GL_FRAGMENT_SHADER_ARB ) ostr << "GL_FRAGMENT_SHADER_ARB";
	#endif
	#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB
		else if ( en == GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB ) ostr << "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB";
	#endif
	#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB
		else if ( en == GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB ) ostr << "GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
		else if ( en == GL_FRAMEBUFFER_DEFAULT_WIDTH ) ostr << "GL_FRAMEBUFFER_DEFAULT_WIDTH";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
		else if ( en == GL_FRAMEBUFFER_DEFAULT_HEIGHT ) ostr << "GL_FRAMEBUFFER_DEFAULT_HEIGHT";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
		else if ( en == GL_FRAMEBUFFER_DEFAULT_LAYERS ) ostr << "GL_FRAMEBUFFER_DEFAULT_LAYERS";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
		else if ( en == GL_FRAMEBUFFER_DEFAULT_SAMPLES ) ostr << "GL_FRAMEBUFFER_DEFAULT_SAMPLES";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
		else if ( en == GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS ) ostr << "GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS";
	#endif
	#ifdef GL_MAX_FRAMEBUFFER_WIDTH
		else if ( en == GL_MAX_FRAMEBUFFER_WIDTH ) ostr << "GL_MAX_FRAMEBUFFER_WIDTH";
	#endif
	#ifdef GL_MAX_FRAMEBUFFER_HEIGHT
		else if ( en == GL_MAX_FRAMEBUFFER_HEIGHT ) ostr << "GL_MAX_FRAMEBUFFER_HEIGHT";
	#endif
	#ifdef GL_MAX_FRAMEBUFFER_LAYERS
		else if ( en == GL_MAX_FRAMEBUFFER_LAYERS ) ostr << "GL_MAX_FRAMEBUFFER_LAYERS";
	#endif
	#ifdef GL_MAX_FRAMEBUFFER_SAMPLES
		else if ( en == GL_MAX_FRAMEBUFFER_SAMPLES ) ostr << "GL_MAX_FRAMEBUFFER_SAMPLES";
	#endif
	#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
		else if ( en == GL_INVALID_FRAMEBUFFER_OPERATION ) ostr << "GL_INVALID_FRAMEBUFFER_OPERATION";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_DEFAULT
		else if ( en == GL_FRAMEBUFFER_DEFAULT ) ostr << "GL_FRAMEBUFFER_DEFAULT";
	#endif
	#ifdef GL_FRAMEBUFFER_UNDEFINED
		else if ( en == GL_FRAMEBUFFER_UNDEFINED ) ostr << "GL_FRAMEBUFFER_UNDEFINED";
	#endif
	#ifdef GL_DEPTH_STENCIL_ATTACHMENT
		else if ( en == GL_DEPTH_STENCIL_ATTACHMENT ) ostr << "GL_DEPTH_STENCIL_ATTACHMENT";
	#endif
	#ifdef GL_INDEX
		else if ( en == GL_INDEX ) ostr << "GL_INDEX";
	#endif
	#ifdef GL_MAX_RENDERBUFFER_SIZE
		else if ( en == GL_MAX_RENDERBUFFER_SIZE ) ostr << "GL_MAX_RENDERBUFFER_SIZE";
	#endif
	#ifdef GL_DEPTH_STENCIL
		else if ( en == GL_DEPTH_STENCIL ) ostr << "GL_DEPTH_STENCIL";
	#endif
	#ifdef GL_UNSIGNED_INT_24_8
		else if ( en == GL_UNSIGNED_INT_24_8 ) ostr << "GL_UNSIGNED_INT_24_8";
	#endif
	#ifdef GL_DEPTH24_STENCIL8
		else if ( en == GL_DEPTH24_STENCIL8 ) ostr << "GL_DEPTH24_STENCIL8";
	#endif
	#ifdef GL_TEXTURE_STENCIL_SIZE
		else if ( en == GL_TEXTURE_STENCIL_SIZE ) ostr << "GL_TEXTURE_STENCIL_SIZE";
	#endif
	#ifdef GL_UNSIGNED_NORMALIZED
		else if ( en == GL_UNSIGNED_NORMALIZED ) ostr << "GL_UNSIGNED_NORMALIZED";
	#endif
	#ifdef GL_SRGB
		else if ( en == GL_SRGB ) ostr << "GL_SRGB";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER_BINDING
		else if ( en == GL_DRAW_FRAMEBUFFER_BINDING ) ostr << "GL_DRAW_FRAMEBUFFER_BINDING";
	#endif
	#ifdef GL_FRAMEBUFFER_BINDING
		else if ( en == GL_FRAMEBUFFER_BINDING ) ostr << "GL_FRAMEBUFFER_BINDING";
	#endif
	#ifdef GL_RENDERBUFFER_BINDING
		else if ( en == GL_RENDERBUFFER_BINDING ) ostr << "GL_RENDERBUFFER_BINDING";
	#endif
	#ifdef GL_READ_FRAMEBUFFER
		else if ( en == GL_READ_FRAMEBUFFER ) ostr << "GL_READ_FRAMEBUFFER";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER
		else if ( en == GL_DRAW_FRAMEBUFFER ) ostr << "GL_DRAW_FRAMEBUFFER";
	#endif
	#ifdef GL_READ_FRAMEBUFFER_BINDING
		else if ( en == GL_READ_FRAMEBUFFER_BINDING ) ostr << "GL_READ_FRAMEBUFFER_BINDING";
	#endif
	#ifdef GL_RENDERBUFFER_SAMPLES
		else if ( en == GL_RENDERBUFFER_SAMPLES ) ostr << "GL_RENDERBUFFER_SAMPLES";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER";
	#endif
	#ifdef GL_FRAMEBUFFER_COMPLETE
		else if ( en == GL_FRAMEBUFFER_COMPLETE ) ostr << "GL_FRAMEBUFFER_COMPLETE";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER";
	#endif
	#ifdef GL_FRAMEBUFFER_UNSUPPORTED
		else if ( en == GL_FRAMEBUFFER_UNSUPPORTED ) ostr << "GL_FRAMEBUFFER_UNSUPPORTED";
	#endif
	#ifdef GL_MAX_COLOR_ATTACHMENTS
		else if ( en == GL_MAX_COLOR_ATTACHMENTS ) ostr << "GL_MAX_COLOR_ATTACHMENTS";
	#endif
	#ifdef GL_COLOR_ATTACHMENT0
		else if ( en == GL_COLOR_ATTACHMENT0 ) ostr << "GL_COLOR_ATTACHMENT0";
	#endif
	#ifdef GL_COLOR_ATTACHMENT1
		else if ( en == GL_COLOR_ATTACHMENT1 ) ostr << "GL_COLOR_ATTACHMENT1";
	#endif
	#ifdef GL_COLOR_ATTACHMENT2
		else if ( en == GL_COLOR_ATTACHMENT2 ) ostr << "GL_COLOR_ATTACHMENT2";
	#endif
	#ifdef GL_COLOR_ATTACHMENT3
		else if ( en == GL_COLOR_ATTACHMENT3 ) ostr << "GL_COLOR_ATTACHMENT3";
	#endif
	#ifdef GL_COLOR_ATTACHMENT4
		else if ( en == GL_COLOR_ATTACHMENT4 ) ostr << "GL_COLOR_ATTACHMENT4";
	#endif
	#ifdef GL_COLOR_ATTACHMENT5
		else if ( en == GL_COLOR_ATTACHMENT5 ) ostr << "GL_COLOR_ATTACHMENT5";
	#endif
	#ifdef GL_COLOR_ATTACHMENT6
		else if ( en == GL_COLOR_ATTACHMENT6 ) ostr << "GL_COLOR_ATTACHMENT6";
	#endif
	#ifdef GL_COLOR_ATTACHMENT7
		else if ( en == GL_COLOR_ATTACHMENT7 ) ostr << "GL_COLOR_ATTACHMENT7";
	#endif
	#ifdef GL_COLOR_ATTACHMENT8
		else if ( en == GL_COLOR_ATTACHMENT8 ) ostr << "GL_COLOR_ATTACHMENT8";
	#endif
	#ifdef GL_COLOR_ATTACHMENT9
		else if ( en == GL_COLOR_ATTACHMENT9 ) ostr << "GL_COLOR_ATTACHMENT9";
	#endif
	#ifdef GL_COLOR_ATTACHMENT10
		else if ( en == GL_COLOR_ATTACHMENT10 ) ostr << "GL_COLOR_ATTACHMENT10";
	#endif
	#ifdef GL_COLOR_ATTACHMENT11
		else if ( en == GL_COLOR_ATTACHMENT11 ) ostr << "GL_COLOR_ATTACHMENT11";
	#endif
	#ifdef GL_COLOR_ATTACHMENT12
		else if ( en == GL_COLOR_ATTACHMENT12 ) ostr << "GL_COLOR_ATTACHMENT12";
	#endif
	#ifdef GL_COLOR_ATTACHMENT13
		else if ( en == GL_COLOR_ATTACHMENT13 ) ostr << "GL_COLOR_ATTACHMENT13";
	#endif
	#ifdef GL_COLOR_ATTACHMENT14
		else if ( en == GL_COLOR_ATTACHMENT14 ) ostr << "GL_COLOR_ATTACHMENT14";
	#endif
	#ifdef GL_COLOR_ATTACHMENT15
		else if ( en == GL_COLOR_ATTACHMENT15 ) ostr << "GL_COLOR_ATTACHMENT15";
	#endif
	#ifdef GL_DEPTH_ATTACHMENT
		else if ( en == GL_DEPTH_ATTACHMENT ) ostr << "GL_DEPTH_ATTACHMENT";
	#endif
	#ifdef GL_STENCIL_ATTACHMENT
		else if ( en == GL_STENCIL_ATTACHMENT ) ostr << "GL_STENCIL_ATTACHMENT";
	#endif
	#ifdef GL_FRAMEBUFFER
		else if ( en == GL_FRAMEBUFFER ) ostr << "GL_FRAMEBUFFER";
	#endif
	#ifdef GL_RENDERBUFFER
		else if ( en == GL_RENDERBUFFER ) ostr << "GL_RENDERBUFFER";
	#endif
	#ifdef GL_RENDERBUFFER_WIDTH
		else if ( en == GL_RENDERBUFFER_WIDTH ) ostr << "GL_RENDERBUFFER_WIDTH";
	#endif
	#ifdef GL_RENDERBUFFER_HEIGHT
		else if ( en == GL_RENDERBUFFER_HEIGHT ) ostr << "GL_RENDERBUFFER_HEIGHT";
	#endif
	#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
		else if ( en == GL_RENDERBUFFER_INTERNAL_FORMAT ) ostr << "GL_RENDERBUFFER_INTERNAL_FORMAT";
	#endif
	#ifdef GL_STENCIL_INDEX1
		else if ( en == GL_STENCIL_INDEX1 ) ostr << "GL_STENCIL_INDEX1";
	#endif
	#ifdef GL_STENCIL_INDEX4
		else if ( en == GL_STENCIL_INDEX4 ) ostr << "GL_STENCIL_INDEX4";
	#endif
	#ifdef GL_STENCIL_INDEX8
		else if ( en == GL_STENCIL_INDEX8 ) ostr << "GL_STENCIL_INDEX8";
	#endif
	#ifdef GL_STENCIL_INDEX16
		else if ( en == GL_STENCIL_INDEX16 ) ostr << "GL_STENCIL_INDEX16";
	#endif
	#ifdef GL_RENDERBUFFER_RED_SIZE
		else if ( en == GL_RENDERBUFFER_RED_SIZE ) ostr << "GL_RENDERBUFFER_RED_SIZE";
	#endif
	#ifdef GL_RENDERBUFFER_GREEN_SIZE
		else if ( en == GL_RENDERBUFFER_GREEN_SIZE ) ostr << "GL_RENDERBUFFER_GREEN_SIZE";
	#endif
	#ifdef GL_RENDERBUFFER_BLUE_SIZE
		else if ( en == GL_RENDERBUFFER_BLUE_SIZE ) ostr << "GL_RENDERBUFFER_BLUE_SIZE";
	#endif
	#ifdef GL_RENDERBUFFER_ALPHA_SIZE
		else if ( en == GL_RENDERBUFFER_ALPHA_SIZE ) ostr << "GL_RENDERBUFFER_ALPHA_SIZE";
	#endif
	#ifdef GL_RENDERBUFFER_DEPTH_SIZE
		else if ( en == GL_RENDERBUFFER_DEPTH_SIZE ) ostr << "GL_RENDERBUFFER_DEPTH_SIZE";
	#endif
	#ifdef GL_RENDERBUFFER_STENCIL_SIZE
		else if ( en == GL_RENDERBUFFER_STENCIL_SIZE ) ostr << "GL_RENDERBUFFER_STENCIL_SIZE";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE";
	#endif
	#ifdef GL_MAX_SAMPLES
		else if ( en == GL_MAX_SAMPLES ) ostr << "GL_MAX_SAMPLES";
	#endif
	#ifdef GL_FRAMEBUFFER_SRGB
		else if ( en == GL_FRAMEBUFFER_SRGB ) ostr << "GL_FRAMEBUFFER_SRGB";
	#endif
	#ifdef GL_LINES_ADJACENCY_ARB
		else if ( en == GL_LINES_ADJACENCY_ARB ) ostr << "GL_LINES_ADJACENCY_ARB";
	#endif
	#ifdef GL_LINE_STRIP_ADJACENCY_ARB
		else if ( en == GL_LINE_STRIP_ADJACENCY_ARB ) ostr << "GL_LINE_STRIP_ADJACENCY_ARB";
	#endif
	#ifdef GL_TRIANGLES_ADJACENCY_ARB
		else if ( en == GL_TRIANGLES_ADJACENCY_ARB ) ostr << "GL_TRIANGLES_ADJACENCY_ARB";
	#endif
	#ifdef GL_TRIANGLE_STRIP_ADJACENCY_ARB
		else if ( en == GL_TRIANGLE_STRIP_ADJACENCY_ARB ) ostr << "GL_TRIANGLE_STRIP_ADJACENCY_ARB";
	#endif
	#ifdef GL_PROGRAM_POINT_SIZE_ARB
		else if ( en == GL_PROGRAM_POINT_SIZE_ARB ) ostr << "GL_PROGRAM_POINT_SIZE_ARB";
	#endif
	#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB
		else if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB ) ostr << "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB";
	#endif
	#ifdef GL_GEOMETRY_SHADER_ARB
		else if ( en == GL_GEOMETRY_SHADER_ARB ) ostr << "GL_GEOMETRY_SHADER_ARB";
	#endif
	#ifdef GL_GEOMETRY_VERTICES_OUT_ARB
		else if ( en == GL_GEOMETRY_VERTICES_OUT_ARB ) ostr << "GL_GEOMETRY_VERTICES_OUT_ARB";
	#endif
	#ifdef GL_GEOMETRY_INPUT_TYPE_ARB
		else if ( en == GL_GEOMETRY_INPUT_TYPE_ARB ) ostr << "GL_GEOMETRY_INPUT_TYPE_ARB";
	#endif
	#ifdef GL_GEOMETRY_OUTPUT_TYPE_ARB
		else if ( en == GL_GEOMETRY_OUTPUT_TYPE_ARB ) ostr << "GL_GEOMETRY_OUTPUT_TYPE_ARB";
	#endif
	#ifdef GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB
		else if ( en == GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB ) ostr << "GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB";
	#endif
	#ifdef GL_MAX_VERTEX_VARYING_COMPONENTS_ARB
		else if ( en == GL_MAX_VERTEX_VARYING_COMPONENTS_ARB ) ostr << "GL_MAX_VERTEX_VARYING_COMPONENTS_ARB";
	#endif
	#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB
		else if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB ) ostr << "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB";
	#endif
	#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB
		else if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB ) ostr << "GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB";
	#endif
	#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB
		else if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB ) ostr << "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB";
	#endif
	#ifdef GL_PROGRAM_BINARY_RETRIEVABLE_HINT
		else if ( en == GL_PROGRAM_BINARY_RETRIEVABLE_HINT ) ostr << "GL_PROGRAM_BINARY_RETRIEVABLE_HINT";
	#endif
	#ifdef GL_PROGRAM_BINARY_LENGTH
		else if ( en == GL_PROGRAM_BINARY_LENGTH ) ostr << "GL_PROGRAM_BINARY_LENGTH";
	#endif
	#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
		else if ( en == GL_NUM_PROGRAM_BINARY_FORMATS ) ostr << "GL_NUM_PROGRAM_BINARY_FORMATS";
	#endif
	#ifdef GL_PROGRAM_BINARY_FORMATS
		else if ( en == GL_PROGRAM_BINARY_FORMATS ) ostr << "GL_PROGRAM_BINARY_FORMATS";
	#endif
	#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
		else if ( en == GL_GEOMETRY_SHADER_INVOCATIONS ) ostr << "GL_GEOMETRY_SHADER_INVOCATIONS";
	#endif
	#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
		else if ( en == GL_MAX_GEOMETRY_SHADER_INVOCATIONS ) ostr << "GL_MAX_GEOMETRY_SHADER_INVOCATIONS";
	#endif
	#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
		else if ( en == GL_MIN_FRAGMENT_INTERPOLATION_OFFSET ) ostr << "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET";
	#endif
	#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
		else if ( en == GL_MAX_FRAGMENT_INTERPOLATION_OFFSET ) ostr << "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET";
	#endif
	#ifdef GL_FRAGMENT_INTERPOLATION_OFFSET_BITS
		else if ( en == GL_FRAGMENT_INTERPOLATION_OFFSET_BITS ) ostr << "GL_FRAGMENT_INTERPOLATION_OFFSET_BITS";
	#endif
	#ifdef GL_MAX_VERTEX_STREAMS
		else if ( en == GL_MAX_VERTEX_STREAMS ) ostr << "GL_MAX_VERTEX_STREAMS";
	#endif
	#ifdef GL_DOUBLE_MAT2
		else if ( en == GL_DOUBLE_MAT2 ) ostr << "GL_DOUBLE_MAT2";
	#endif
	#ifdef GL_DOUBLE_MAT3
		else if ( en == GL_DOUBLE_MAT3 ) ostr << "GL_DOUBLE_MAT3";
	#endif
	#ifdef GL_DOUBLE_MAT4
		else if ( en == GL_DOUBLE_MAT4 ) ostr << "GL_DOUBLE_MAT4";
	#endif
	#ifdef GL_DOUBLE_MAT2x3
		else if ( en == GL_DOUBLE_MAT2x3 ) ostr << "GL_DOUBLE_MAT2x3";
	#endif
	#ifdef GL_DOUBLE_MAT2x4
		else if ( en == GL_DOUBLE_MAT2x4 ) ostr << "GL_DOUBLE_MAT2x4";
	#endif
	#ifdef GL_DOUBLE_MAT3x2
		else if ( en == GL_DOUBLE_MAT3x2 ) ostr << "GL_DOUBLE_MAT3x2";
	#endif
	#ifdef GL_DOUBLE_MAT3x4
		else if ( en == GL_DOUBLE_MAT3x4 ) ostr << "GL_DOUBLE_MAT3x4";
	#endif
	#ifdef GL_DOUBLE_MAT4x2
		else if ( en == GL_DOUBLE_MAT4x2 ) ostr << "GL_DOUBLE_MAT4x2";
	#endif
	#ifdef GL_DOUBLE_MAT4x3
		else if ( en == GL_DOUBLE_MAT4x3 ) ostr << "GL_DOUBLE_MAT4x3";
	#endif
	#ifdef GL_DOUBLE_VEC2
		else if ( en == GL_DOUBLE_VEC2 ) ostr << "GL_DOUBLE_VEC2";
	#endif
	#ifdef GL_DOUBLE_VEC3
		else if ( en == GL_DOUBLE_VEC3 ) ostr << "GL_DOUBLE_VEC3";
	#endif
	#ifdef GL_DOUBLE_VEC4
		else if ( en == GL_DOUBLE_VEC4 ) ostr << "GL_DOUBLE_VEC4";
	#endif
	#ifdef GL_HALF_FLOAT_ARB
		else if ( en == GL_HALF_FLOAT_ARB ) ostr << "GL_HALF_FLOAT_ARB";
	#endif
	#ifdef GL_HALF_FLOAT
		else if ( en == GL_HALF_FLOAT ) ostr << "GL_HALF_FLOAT";
	#endif
	#ifdef GL_CONSTANT_COLOR
		else if ( en == GL_CONSTANT_COLOR ) ostr << "GL_CONSTANT_COLOR";
	#endif
	#ifdef GL_ONE_MINUS_CONSTANT_COLOR
		else if ( en == GL_ONE_MINUS_CONSTANT_COLOR ) ostr << "GL_ONE_MINUS_CONSTANT_COLOR";
	#endif
	#ifdef GL_CONSTANT_ALPHA
		else if ( en == GL_CONSTANT_ALPHA ) ostr << "GL_CONSTANT_ALPHA";
	#endif
	#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
		else if ( en == GL_ONE_MINUS_CONSTANT_ALPHA ) ostr << "GL_ONE_MINUS_CONSTANT_ALPHA";
	#endif
	#ifdef GL_BLEND_COLOR
		else if ( en == GL_BLEND_COLOR ) ostr << "GL_BLEND_COLOR";
	#endif
	#ifdef GL_FUNC_ADD
		else if ( en == GL_FUNC_ADD ) ostr << "GL_FUNC_ADD";
	#endif
	#ifdef GL_MIN
		else if ( en == GL_MIN ) ostr << "GL_MIN";
	#endif
	#ifdef GL_MAX
		else if ( en == GL_MAX ) ostr << "GL_MAX";
	#endif
	#ifdef GL_BLEND_EQUATION
		else if ( en == GL_BLEND_EQUATION ) ostr << "GL_BLEND_EQUATION";
	#endif
	#ifdef GL_FUNC_SUBTRACT
		else if ( en == GL_FUNC_SUBTRACT ) ostr << "GL_FUNC_SUBTRACT";
	#endif
	#ifdef GL_FUNC_REVERSE_SUBTRACT
		else if ( en == GL_FUNC_REVERSE_SUBTRACT ) ostr << "GL_FUNC_REVERSE_SUBTRACT";
	#endif
	#ifdef GL_CONVOLUTION_1D
		else if ( en == GL_CONVOLUTION_1D ) ostr << "GL_CONVOLUTION_1D";
	#endif
	#ifdef GL_CONVOLUTION_2D
		else if ( en == GL_CONVOLUTION_2D ) ostr << "GL_CONVOLUTION_2D";
	#endif
	#ifdef GL_SEPARABLE_2D
		else if ( en == GL_SEPARABLE_2D ) ostr << "GL_SEPARABLE_2D";
	#endif
	#ifdef GL_CONVOLUTION_BORDER_MODE
		else if ( en == GL_CONVOLUTION_BORDER_MODE ) ostr << "GL_CONVOLUTION_BORDER_MODE";
	#endif
	#ifdef GL_CONVOLUTION_FILTER_SCALE
		else if ( en == GL_CONVOLUTION_FILTER_SCALE ) ostr << "GL_CONVOLUTION_FILTER_SCALE";
	#endif
	#ifdef GL_CONVOLUTION_FILTER_BIAS
		else if ( en == GL_CONVOLUTION_FILTER_BIAS ) ostr << "GL_CONVOLUTION_FILTER_BIAS";
	#endif
	#ifdef GL_REDUCE
		else if ( en == GL_REDUCE ) ostr << "GL_REDUCE";
	#endif
	#ifdef GL_CONVOLUTION_FORMAT
		else if ( en == GL_CONVOLUTION_FORMAT ) ostr << "GL_CONVOLUTION_FORMAT";
	#endif
	#ifdef GL_CONVOLUTION_WIDTH
		else if ( en == GL_CONVOLUTION_WIDTH ) ostr << "GL_CONVOLUTION_WIDTH";
	#endif
	#ifdef GL_CONVOLUTION_HEIGHT
		else if ( en == GL_CONVOLUTION_HEIGHT ) ostr << "GL_CONVOLUTION_HEIGHT";
	#endif
	#ifdef GL_MAX_CONVOLUTION_WIDTH
		else if ( en == GL_MAX_CONVOLUTION_WIDTH ) ostr << "GL_MAX_CONVOLUTION_WIDTH";
	#endif
	#ifdef GL_MAX_CONVOLUTION_HEIGHT
		else if ( en == GL_MAX_CONVOLUTION_HEIGHT ) ostr << "GL_MAX_CONVOLUTION_HEIGHT";
	#endif
	#ifdef GL_POST_CONVOLUTION_RED_SCALE
		else if ( en == GL_POST_CONVOLUTION_RED_SCALE ) ostr << "GL_POST_CONVOLUTION_RED_SCALE";
	#endif
	#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
		else if ( en == GL_POST_CONVOLUTION_GREEN_SCALE ) ostr << "GL_POST_CONVOLUTION_GREEN_SCALE";
	#endif
	#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
		else if ( en == GL_POST_CONVOLUTION_BLUE_SCALE ) ostr << "GL_POST_CONVOLUTION_BLUE_SCALE";
	#endif
	#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
		else if ( en == GL_POST_CONVOLUTION_ALPHA_SCALE ) ostr << "GL_POST_CONVOLUTION_ALPHA_SCALE";
	#endif
	#ifdef GL_POST_CONVOLUTION_RED_BIAS
		else if ( en == GL_POST_CONVOLUTION_RED_BIAS ) ostr << "GL_POST_CONVOLUTION_RED_BIAS";
	#endif
	#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
		else if ( en == GL_POST_CONVOLUTION_GREEN_BIAS ) ostr << "GL_POST_CONVOLUTION_GREEN_BIAS";
	#endif
	#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
		else if ( en == GL_POST_CONVOLUTION_BLUE_BIAS ) ostr << "GL_POST_CONVOLUTION_BLUE_BIAS";
	#endif
	#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
		else if ( en == GL_POST_CONVOLUTION_ALPHA_BIAS ) ostr << "GL_POST_CONVOLUTION_ALPHA_BIAS";
	#endif
	#ifdef GL_HISTOGRAM
		else if ( en == GL_HISTOGRAM ) ostr << "GL_HISTOGRAM";
	#endif
	#ifdef GL_PROXY_HISTOGRAM
		else if ( en == GL_PROXY_HISTOGRAM ) ostr << "GL_PROXY_HISTOGRAM";
	#endif
	#ifdef GL_HISTOGRAM_WIDTH
		else if ( en == GL_HISTOGRAM_WIDTH ) ostr << "GL_HISTOGRAM_WIDTH";
	#endif
	#ifdef GL_HISTOGRAM_FORMAT
		else if ( en == GL_HISTOGRAM_FORMAT ) ostr << "GL_HISTOGRAM_FORMAT";
	#endif
	#ifdef GL_HISTOGRAM_RED_SIZE
		else if ( en == GL_HISTOGRAM_RED_SIZE ) ostr << "GL_HISTOGRAM_RED_SIZE";
	#endif
	#ifdef GL_HISTOGRAM_GREEN_SIZE
		else if ( en == GL_HISTOGRAM_GREEN_SIZE ) ostr << "GL_HISTOGRAM_GREEN_SIZE";
	#endif
	#ifdef GL_HISTOGRAM_BLUE_SIZE
		else if ( en == GL_HISTOGRAM_BLUE_SIZE ) ostr << "GL_HISTOGRAM_BLUE_SIZE";
	#endif
	#ifdef GL_HISTOGRAM_ALPHA_SIZE
		else if ( en == GL_HISTOGRAM_ALPHA_SIZE ) ostr << "GL_HISTOGRAM_ALPHA_SIZE";
	#endif
	#ifdef GL_HISTOGRAM_LUMINANCE_SIZE
		else if ( en == GL_HISTOGRAM_LUMINANCE_SIZE ) ostr << "GL_HISTOGRAM_LUMINANCE_SIZE";
	#endif
	#ifdef GL_HISTOGRAM_SINK
		else if ( en == GL_HISTOGRAM_SINK ) ostr << "GL_HISTOGRAM_SINK";
	#endif
	#ifdef GL_MINMAX
		else if ( en == GL_MINMAX ) ostr << "GL_MINMAX";
	#endif
	#ifdef GL_MINMAX_FORMAT
		else if ( en == GL_MINMAX_FORMAT ) ostr << "GL_MINMAX_FORMAT";
	#endif
	#ifdef GL_MINMAX_SINK
		else if ( en == GL_MINMAX_SINK ) ostr << "GL_MINMAX_SINK";
	#endif
	#ifdef GL_TABLE_TOO_LARGE
		else if ( en == GL_TABLE_TOO_LARGE ) ostr << "GL_TABLE_TOO_LARGE";
	#endif
	#ifdef GL_COLOR_MATRIX
		else if ( en == GL_COLOR_MATRIX ) ostr << "GL_COLOR_MATRIX";
	#endif
	#ifdef GL_COLOR_MATRIX_STACK_DEPTH
		else if ( en == GL_COLOR_MATRIX_STACK_DEPTH ) ostr << "GL_COLOR_MATRIX_STACK_DEPTH";
	#endif
	#ifdef GL_MAX_COLOR_MATRIX_STACK_DEPTH
		else if ( en == GL_MAX_COLOR_MATRIX_STACK_DEPTH ) ostr << "GL_MAX_COLOR_MATRIX_STACK_DEPTH";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
		else if ( en == GL_POST_COLOR_MATRIX_RED_SCALE ) ostr << "GL_POST_COLOR_MATRIX_RED_SCALE";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
		else if ( en == GL_POST_COLOR_MATRIX_GREEN_SCALE ) ostr << "GL_POST_COLOR_MATRIX_GREEN_SCALE";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
		else if ( en == GL_POST_COLOR_MATRIX_BLUE_SCALE ) ostr << "GL_POST_COLOR_MATRIX_BLUE_SCALE";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
		else if ( en == GL_POST_COLOR_MATRIX_ALPHA_SCALE ) ostr << "GL_POST_COLOR_MATRIX_ALPHA_SCALE";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
		else if ( en == GL_POST_COLOR_MATRIX_RED_BIAS ) ostr << "GL_POST_COLOR_MATRIX_RED_BIAS";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
		else if ( en == GL_POST_COLOR_MATRIX_GREEN_BIAS ) ostr << "GL_POST_COLOR_MATRIX_GREEN_BIAS";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
		else if ( en == GL_POST_COLOR_MATRIX_BLUE_BIAS ) ostr << "GL_POST_COLOR_MATRIX_BLUE_BIAS";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
		else if ( en == GL_POST_COLOR_MATRIX_ALPHA_BIAS ) ostr << "GL_POST_COLOR_MATRIX_ALPHA_BIAS";
	#endif
	#ifdef GL_COLOR_TABLE
		else if ( en == GL_COLOR_TABLE ) ostr << "GL_COLOR_TABLE";
	#endif
	#ifdef GL_POST_CONVOLUTION_COLOR_TABLE
		else if ( en == GL_POST_CONVOLUTION_COLOR_TABLE ) ostr << "GL_POST_CONVOLUTION_COLOR_TABLE";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_COLOR_TABLE
		else if ( en == GL_POST_COLOR_MATRIX_COLOR_TABLE ) ostr << "GL_POST_COLOR_MATRIX_COLOR_TABLE";
	#endif
	#ifdef GL_PROXY_COLOR_TABLE
		else if ( en == GL_PROXY_COLOR_TABLE ) ostr << "GL_PROXY_COLOR_TABLE";
	#endif
	#ifdef GL_PROXY_POST_CONVOLUTION_COLOR_TABLE
		else if ( en == GL_PROXY_POST_CONVOLUTION_COLOR_TABLE ) ostr << "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE";
	#endif
	#ifdef GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE
		else if ( en == GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE ) ostr << "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE";
	#endif
	#ifdef GL_COLOR_TABLE_SCALE
		else if ( en == GL_COLOR_TABLE_SCALE ) ostr << "GL_COLOR_TABLE_SCALE";
	#endif
	#ifdef GL_COLOR_TABLE_BIAS
		else if ( en == GL_COLOR_TABLE_BIAS ) ostr << "GL_COLOR_TABLE_BIAS";
	#endif
	#ifdef GL_COLOR_TABLE_FORMAT
		else if ( en == GL_COLOR_TABLE_FORMAT ) ostr << "GL_COLOR_TABLE_FORMAT";
	#endif
	#ifdef GL_COLOR_TABLE_WIDTH
		else if ( en == GL_COLOR_TABLE_WIDTH ) ostr << "GL_COLOR_TABLE_WIDTH";
	#endif
	#ifdef GL_COLOR_TABLE_RED_SIZE
		else if ( en == GL_COLOR_TABLE_RED_SIZE ) ostr << "GL_COLOR_TABLE_RED_SIZE";
	#endif
	#ifdef GL_COLOR_TABLE_GREEN_SIZE
		else if ( en == GL_COLOR_TABLE_GREEN_SIZE ) ostr << "GL_COLOR_TABLE_GREEN_SIZE";
	#endif
	#ifdef GL_COLOR_TABLE_BLUE_SIZE
		else if ( en == GL_COLOR_TABLE_BLUE_SIZE ) ostr << "GL_COLOR_TABLE_BLUE_SIZE";
	#endif
	#ifdef GL_COLOR_TABLE_ALPHA_SIZE
		else if ( en == GL_COLOR_TABLE_ALPHA_SIZE ) ostr << "GL_COLOR_TABLE_ALPHA_SIZE";
	#endif
	#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE
		else if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE ) ostr << "GL_COLOR_TABLE_LUMINANCE_SIZE";
	#endif
	#ifdef GL_COLOR_TABLE_INTENSITY_SIZE
		else if ( en == GL_COLOR_TABLE_INTENSITY_SIZE ) ostr << "GL_COLOR_TABLE_INTENSITY_SIZE";
	#endif
	#ifdef GL_IGNORE_BORDER
		else if ( en == GL_IGNORE_BORDER ) ostr << "GL_IGNORE_BORDER";
	#endif
	#ifdef GL_CONSTANT_BORDER
		else if ( en == GL_CONSTANT_BORDER ) ostr << "GL_CONSTANT_BORDER";
	#endif
	#ifdef GL_WRAP_BORDER
		else if ( en == GL_WRAP_BORDER ) ostr << "GL_WRAP_BORDER";
	#endif
	#ifdef GL_REPLICATE_BORDER
		else if ( en == GL_REPLICATE_BORDER ) ostr << "GL_REPLICATE_BORDER";
	#endif
	#ifdef GL_CONVOLUTION_BORDER_COLOR
		else if ( en == GL_CONVOLUTION_BORDER_COLOR ) ostr << "GL_CONVOLUTION_BORDER_COLOR";
	#endif
	#ifdef GL_PARAMETER_BUFFER_ARB
		else if ( en == GL_PARAMETER_BUFFER_ARB ) ostr << "GL_PARAMETER_BUFFER_ARB";
	#endif
	#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
		else if ( en == GL_PARAMETER_BUFFER_BINDING_ARB ) ostr << "GL_PARAMETER_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB";
	#endif
	#ifdef GL_NUM_SAMPLE_COUNTS
		else if ( en == GL_NUM_SAMPLE_COUNTS ) ostr << "GL_NUM_SAMPLE_COUNTS";
	#endif
	#ifdef GL_INTERNALFORMAT_SUPPORTED
		else if ( en == GL_INTERNALFORMAT_SUPPORTED ) ostr << "GL_INTERNALFORMAT_SUPPORTED";
	#endif
	#ifdef GL_INTERNALFORMAT_PREFERRED
		else if ( en == GL_INTERNALFORMAT_PREFERRED ) ostr << "GL_INTERNALFORMAT_PREFERRED";
	#endif
	#ifdef GL_INTERNALFORMAT_RED_SIZE
		else if ( en == GL_INTERNALFORMAT_RED_SIZE ) ostr << "GL_INTERNALFORMAT_RED_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_GREEN_SIZE
		else if ( en == GL_INTERNALFORMAT_GREEN_SIZE ) ostr << "GL_INTERNALFORMAT_GREEN_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_BLUE_SIZE
		else if ( en == GL_INTERNALFORMAT_BLUE_SIZE ) ostr << "GL_INTERNALFORMAT_BLUE_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
		else if ( en == GL_INTERNALFORMAT_ALPHA_SIZE ) ostr << "GL_INTERNALFORMAT_ALPHA_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
		else if ( en == GL_INTERNALFORMAT_DEPTH_SIZE ) ostr << "GL_INTERNALFORMAT_DEPTH_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
		else if ( en == GL_INTERNALFORMAT_STENCIL_SIZE ) ostr << "GL_INTERNALFORMAT_STENCIL_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_SHARED_SIZE
		else if ( en == GL_INTERNALFORMAT_SHARED_SIZE ) ostr << "GL_INTERNALFORMAT_SHARED_SIZE";
	#endif
	#ifdef GL_INTERNALFORMAT_RED_TYPE
		else if ( en == GL_INTERNALFORMAT_RED_TYPE ) ostr << "GL_INTERNALFORMAT_RED_TYPE";
	#endif
	#ifdef GL_INTERNALFORMAT_GREEN_TYPE
		else if ( en == GL_INTERNALFORMAT_GREEN_TYPE ) ostr << "GL_INTERNALFORMAT_GREEN_TYPE";
	#endif
	#ifdef GL_INTERNALFORMAT_BLUE_TYPE
		else if ( en == GL_INTERNALFORMAT_BLUE_TYPE ) ostr << "GL_INTERNALFORMAT_BLUE_TYPE";
	#endif
	#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
		else if ( en == GL_INTERNALFORMAT_ALPHA_TYPE ) ostr << "GL_INTERNALFORMAT_ALPHA_TYPE";
	#endif
	#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
		else if ( en == GL_INTERNALFORMAT_DEPTH_TYPE ) ostr << "GL_INTERNALFORMAT_DEPTH_TYPE";
	#endif
	#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
		else if ( en == GL_INTERNALFORMAT_STENCIL_TYPE ) ostr << "GL_INTERNALFORMAT_STENCIL_TYPE";
	#endif
	#ifdef GL_MAX_WIDTH
		else if ( en == GL_MAX_WIDTH ) ostr << "GL_MAX_WIDTH";
	#endif
	#ifdef GL_MAX_HEIGHT
		else if ( en == GL_MAX_HEIGHT ) ostr << "GL_MAX_HEIGHT";
	#endif
	#ifdef GL_MAX_DEPTH
		else if ( en == GL_MAX_DEPTH ) ostr << "GL_MAX_DEPTH";
	#endif
	#ifdef GL_MAX_LAYERS
		else if ( en == GL_MAX_LAYERS ) ostr << "GL_MAX_LAYERS";
	#endif
	#ifdef GL_MAX_COMBINED_DIMENSIONS
		else if ( en == GL_MAX_COMBINED_DIMENSIONS ) ostr << "GL_MAX_COMBINED_DIMENSIONS";
	#endif
	#ifdef GL_COLOR_COMPONENTS
		else if ( en == GL_COLOR_COMPONENTS ) ostr << "GL_COLOR_COMPONENTS";
	#endif
	#ifdef GL_DEPTH_COMPONENTS
		else if ( en == GL_DEPTH_COMPONENTS ) ostr << "GL_DEPTH_COMPONENTS";
	#endif
	#ifdef GL_STENCIL_COMPONENTS
		else if ( en == GL_STENCIL_COMPONENTS ) ostr << "GL_STENCIL_COMPONENTS";
	#endif
	#ifdef GL_COLOR_RENDERABLE
		else if ( en == GL_COLOR_RENDERABLE ) ostr << "GL_COLOR_RENDERABLE";
	#endif
	#ifdef GL_DEPTH_RENDERABLE
		else if ( en == GL_DEPTH_RENDERABLE ) ostr << "GL_DEPTH_RENDERABLE";
	#endif
	#ifdef GL_STENCIL_RENDERABLE
		else if ( en == GL_STENCIL_RENDERABLE ) ostr << "GL_STENCIL_RENDERABLE";
	#endif
	#ifdef GL_FRAMEBUFFER_RENDERABLE
		else if ( en == GL_FRAMEBUFFER_RENDERABLE ) ostr << "GL_FRAMEBUFFER_RENDERABLE";
	#endif
	#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
		else if ( en == GL_FRAMEBUFFER_RENDERABLE_LAYERED ) ostr << "GL_FRAMEBUFFER_RENDERABLE_LAYERED";
	#endif
	#ifdef GL_FRAMEBUFFER_BLEND
		else if ( en == GL_FRAMEBUFFER_BLEND ) ostr << "GL_FRAMEBUFFER_BLEND";
	#endif
	#ifdef GL_READ_PIXELS
		else if ( en == GL_READ_PIXELS ) ostr << "GL_READ_PIXELS";
	#endif
	#ifdef GL_READ_PIXELS_FORMAT
		else if ( en == GL_READ_PIXELS_FORMAT ) ostr << "GL_READ_PIXELS_FORMAT";
	#endif
	#ifdef GL_READ_PIXELS_TYPE
		else if ( en == GL_READ_PIXELS_TYPE ) ostr << "GL_READ_PIXELS_TYPE";
	#endif
	#ifdef GL_TEXTURE_IMAGE_FORMAT
		else if ( en == GL_TEXTURE_IMAGE_FORMAT ) ostr << "GL_TEXTURE_IMAGE_FORMAT";
	#endif
	#ifdef GL_TEXTURE_IMAGE_TYPE
		else if ( en == GL_TEXTURE_IMAGE_TYPE ) ostr << "GL_TEXTURE_IMAGE_TYPE";
	#endif
	#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
		else if ( en == GL_GET_TEXTURE_IMAGE_FORMAT ) ostr << "GL_GET_TEXTURE_IMAGE_FORMAT";
	#endif
	#ifdef GL_GET_TEXTURE_IMAGE_TYPE
		else if ( en == GL_GET_TEXTURE_IMAGE_TYPE ) ostr << "GL_GET_TEXTURE_IMAGE_TYPE";
	#endif
	#ifdef GL_MIPMAP
		else if ( en == GL_MIPMAP ) ostr << "GL_MIPMAP";
	#endif
	#ifdef GL_MANUAL_GENERATE_MIPMAP
		else if ( en == GL_MANUAL_GENERATE_MIPMAP ) ostr << "GL_MANUAL_GENERATE_MIPMAP";
	#endif
	#ifdef GL_AUTO_GENERATE_MIPMAP
		else if ( en == GL_AUTO_GENERATE_MIPMAP ) ostr << "GL_AUTO_GENERATE_MIPMAP";
	#endif
	#ifdef GL_COLOR_ENCODING
		else if ( en == GL_COLOR_ENCODING ) ostr << "GL_COLOR_ENCODING";
	#endif
	#ifdef GL_SRGB_READ
		else if ( en == GL_SRGB_READ ) ostr << "GL_SRGB_READ";
	#endif
	#ifdef GL_SRGB_WRITE
		else if ( en == GL_SRGB_WRITE ) ostr << "GL_SRGB_WRITE";
	#endif
	#ifdef GL_SRGB_DECODE_ARB
		else if ( en == GL_SRGB_DECODE_ARB ) ostr << "GL_SRGB_DECODE_ARB";
	#endif
	#ifdef GL_FILTER
		else if ( en == GL_FILTER ) ostr << "GL_FILTER";
	#endif
	#ifdef GL_VERTEX_TEXTURE
		else if ( en == GL_VERTEX_TEXTURE ) ostr << "GL_VERTEX_TEXTURE";
	#endif
	#ifdef GL_TESS_CONTROL_TEXTURE
		else if ( en == GL_TESS_CONTROL_TEXTURE ) ostr << "GL_TESS_CONTROL_TEXTURE";
	#endif
	#ifdef GL_TESS_EVALUATION_TEXTURE
		else if ( en == GL_TESS_EVALUATION_TEXTURE ) ostr << "GL_TESS_EVALUATION_TEXTURE";
	#endif
	#ifdef GL_GEOMETRY_TEXTURE
		else if ( en == GL_GEOMETRY_TEXTURE ) ostr << "GL_GEOMETRY_TEXTURE";
	#endif
	#ifdef GL_FRAGMENT_TEXTURE
		else if ( en == GL_FRAGMENT_TEXTURE ) ostr << "GL_FRAGMENT_TEXTURE";
	#endif
	#ifdef GL_COMPUTE_TEXTURE
		else if ( en == GL_COMPUTE_TEXTURE ) ostr << "GL_COMPUTE_TEXTURE";
	#endif
	#ifdef GL_TEXTURE_SHADOW
		else if ( en == GL_TEXTURE_SHADOW ) ostr << "GL_TEXTURE_SHADOW";
	#endif
	#ifdef GL_TEXTURE_GATHER
		else if ( en == GL_TEXTURE_GATHER ) ostr << "GL_TEXTURE_GATHER";
	#endif
	#ifdef GL_TEXTURE_GATHER_SHADOW
		else if ( en == GL_TEXTURE_GATHER_SHADOW ) ostr << "GL_TEXTURE_GATHER_SHADOW";
	#endif
	#ifdef GL_SHADER_IMAGE_LOAD
		else if ( en == GL_SHADER_IMAGE_LOAD ) ostr << "GL_SHADER_IMAGE_LOAD";
	#endif
	#ifdef GL_SHADER_IMAGE_STORE
		else if ( en == GL_SHADER_IMAGE_STORE ) ostr << "GL_SHADER_IMAGE_STORE";
	#endif
	#ifdef GL_SHADER_IMAGE_ATOMIC
		else if ( en == GL_SHADER_IMAGE_ATOMIC ) ostr << "GL_SHADER_IMAGE_ATOMIC";
	#endif
	#ifdef GL_IMAGE_TEXEL_SIZE
		else if ( en == GL_IMAGE_TEXEL_SIZE ) ostr << "GL_IMAGE_TEXEL_SIZE";
	#endif
	#ifdef GL_IMAGE_COMPATIBILITY_CLASS
		else if ( en == GL_IMAGE_COMPATIBILITY_CLASS ) ostr << "GL_IMAGE_COMPATIBILITY_CLASS";
	#endif
	#ifdef GL_IMAGE_PIXEL_FORMAT
		else if ( en == GL_IMAGE_PIXEL_FORMAT ) ostr << "GL_IMAGE_PIXEL_FORMAT";
	#endif
	#ifdef GL_IMAGE_PIXEL_TYPE
		else if ( en == GL_IMAGE_PIXEL_TYPE ) ostr << "GL_IMAGE_PIXEL_TYPE";
	#endif
	#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
		else if ( en == GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST ) ostr << "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST";
	#endif
	#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
		else if ( en == GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST ) ostr << "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST";
	#endif
	#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
		else if ( en == GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE ) ostr << "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE";
	#endif
	#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
		else if ( en == GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE ) ostr << "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
		else if ( en == GL_TEXTURE_COMPRESSED_BLOCK_WIDTH ) ostr << "GL_TEXTURE_COMPRESSED_BLOCK_WIDTH";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
		else if ( en == GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT ) ostr << "GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
		else if ( en == GL_TEXTURE_COMPRESSED_BLOCK_SIZE ) ostr << "GL_TEXTURE_COMPRESSED_BLOCK_SIZE";
	#endif
	#ifdef GL_CLEAR_BUFFER
		else if ( en == GL_CLEAR_BUFFER ) ostr << "GL_CLEAR_BUFFER";
	#endif
	#ifdef GL_TEXTURE_VIEW
		else if ( en == GL_TEXTURE_VIEW ) ostr << "GL_TEXTURE_VIEW";
	#endif
	#ifdef GL_VIEW_COMPATIBILITY_CLASS
		else if ( en == GL_VIEW_COMPATIBILITY_CLASS ) ostr << "GL_VIEW_COMPATIBILITY_CLASS";
	#endif
	#ifdef GL_FULL_SUPPORT
		else if ( en == GL_FULL_SUPPORT ) ostr << "GL_FULL_SUPPORT";
	#endif
	#ifdef GL_CAVEAT_SUPPORT
		else if ( en == GL_CAVEAT_SUPPORT ) ostr << "GL_CAVEAT_SUPPORT";
	#endif
	#ifdef GL_IMAGE_CLASS_4_X_32
		else if ( en == GL_IMAGE_CLASS_4_X_32 ) ostr << "GL_IMAGE_CLASS_4_X_32";
	#endif
	#ifdef GL_IMAGE_CLASS_2_X_32
		else if ( en == GL_IMAGE_CLASS_2_X_32 ) ostr << "GL_IMAGE_CLASS_2_X_32";
	#endif
	#ifdef GL_IMAGE_CLASS_1_X_32
		else if ( en == GL_IMAGE_CLASS_1_X_32 ) ostr << "GL_IMAGE_CLASS_1_X_32";
	#endif
	#ifdef GL_IMAGE_CLASS_4_X_16
		else if ( en == GL_IMAGE_CLASS_4_X_16 ) ostr << "GL_IMAGE_CLASS_4_X_16";
	#endif
	#ifdef GL_IMAGE_CLASS_2_X_16
		else if ( en == GL_IMAGE_CLASS_2_X_16 ) ostr << "GL_IMAGE_CLASS_2_X_16";
	#endif
	#ifdef GL_IMAGE_CLASS_1_X_16
		else if ( en == GL_IMAGE_CLASS_1_X_16 ) ostr << "GL_IMAGE_CLASS_1_X_16";
	#endif
	#ifdef GL_IMAGE_CLASS_4_X_8
		else if ( en == GL_IMAGE_CLASS_4_X_8 ) ostr << "GL_IMAGE_CLASS_4_X_8";
	#endif
	#ifdef GL_IMAGE_CLASS_2_X_8
		else if ( en == GL_IMAGE_CLASS_2_X_8 ) ostr << "GL_IMAGE_CLASS_2_X_8";
	#endif
	#ifdef GL_IMAGE_CLASS_1_X_8
		else if ( en == GL_IMAGE_CLASS_1_X_8 ) ostr << "GL_IMAGE_CLASS_1_X_8";
	#endif
	#ifdef GL_IMAGE_CLASS_11_11_10
		else if ( en == GL_IMAGE_CLASS_11_11_10 ) ostr << "GL_IMAGE_CLASS_11_11_10";
	#endif
	#ifdef GL_IMAGE_CLASS_10_10_10_2
		else if ( en == GL_IMAGE_CLASS_10_10_10_2 ) ostr << "GL_IMAGE_CLASS_10_10_10_2";
	#endif
	#ifdef GL_VIEW_CLASS_128_BITS
		else if ( en == GL_VIEW_CLASS_128_BITS ) ostr << "GL_VIEW_CLASS_128_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_96_BITS
		else if ( en == GL_VIEW_CLASS_96_BITS ) ostr << "GL_VIEW_CLASS_96_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_64_BITS
		else if ( en == GL_VIEW_CLASS_64_BITS ) ostr << "GL_VIEW_CLASS_64_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_48_BITS
		else if ( en == GL_VIEW_CLASS_48_BITS ) ostr << "GL_VIEW_CLASS_48_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_32_BITS
		else if ( en == GL_VIEW_CLASS_32_BITS ) ostr << "GL_VIEW_CLASS_32_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_24_BITS
		else if ( en == GL_VIEW_CLASS_24_BITS ) ostr << "GL_VIEW_CLASS_24_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_16_BITS
		else if ( en == GL_VIEW_CLASS_16_BITS ) ostr << "GL_VIEW_CLASS_16_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_8_BITS
		else if ( en == GL_VIEW_CLASS_8_BITS ) ostr << "GL_VIEW_CLASS_8_BITS";
	#endif
	#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGB
		else if ( en == GL_VIEW_CLASS_S3TC_DXT1_RGB ) ostr << "GL_VIEW_CLASS_S3TC_DXT1_RGB";
	#endif
	#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGBA
		else if ( en == GL_VIEW_CLASS_S3TC_DXT1_RGBA ) ostr << "GL_VIEW_CLASS_S3TC_DXT1_RGBA";
	#endif
	#ifdef GL_VIEW_CLASS_S3TC_DXT3_RGBA
		else if ( en == GL_VIEW_CLASS_S3TC_DXT3_RGBA ) ostr << "GL_VIEW_CLASS_S3TC_DXT3_RGBA";
	#endif
	#ifdef GL_VIEW_CLASS_S3TC_DXT5_RGBA
		else if ( en == GL_VIEW_CLASS_S3TC_DXT5_RGBA ) ostr << "GL_VIEW_CLASS_S3TC_DXT5_RGBA";
	#endif
	#ifdef GL_VIEW_CLASS_RGTC1_RED
		else if ( en == GL_VIEW_CLASS_RGTC1_RED ) ostr << "GL_VIEW_CLASS_RGTC1_RED";
	#endif
	#ifdef GL_VIEW_CLASS_RGTC2_RG
		else if ( en == GL_VIEW_CLASS_RGTC2_RG ) ostr << "GL_VIEW_CLASS_RGTC2_RG";
	#endif
	#ifdef GL_VIEW_CLASS_BPTC_UNORM
		else if ( en == GL_VIEW_CLASS_BPTC_UNORM ) ostr << "GL_VIEW_CLASS_BPTC_UNORM";
	#endif
	#ifdef GL_VIEW_CLASS_BPTC_FLOAT
		else if ( en == GL_VIEW_CLASS_BPTC_FLOAT ) ostr << "GL_VIEW_CLASS_BPTC_FLOAT";
	#endif
	#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
		else if ( en == GL_MIN_MAP_BUFFER_ALIGNMENT ) ostr << "GL_MIN_MAP_BUFFER_ALIGNMENT";
	#endif
	#ifdef GL_MAP_READ_BIT
		else if ( en == GL_MAP_READ_BIT ) ostr << "GL_MAP_READ_BIT";
	#endif
	#ifdef GL_MAP_WRITE_BIT
		else if ( en == GL_MAP_WRITE_BIT ) ostr << "GL_MAP_WRITE_BIT";
	#endif
	#ifdef GL_MAP_INVALIDATE_RANGE_BIT
		else if ( en == GL_MAP_INVALIDATE_RANGE_BIT ) ostr << "GL_MAP_INVALIDATE_RANGE_BIT";
	#endif
	#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
		else if ( en == GL_MAP_INVALIDATE_BUFFER_BIT ) ostr << "GL_MAP_INVALIDATE_BUFFER_BIT";
	#endif
	#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
		else if ( en == GL_MAP_FLUSH_EXPLICIT_BIT ) ostr << "GL_MAP_FLUSH_EXPLICIT_BIT";
	#endif
	#ifdef GL_MAP_UNSYNCHRONIZED_BIT
		else if ( en == GL_MAP_UNSYNCHRONIZED_BIT ) ostr << "GL_MAP_UNSYNCHRONIZED_BIT";
	#endif
	#ifdef GL_MATRIX_PALETTE_ARB
		else if ( en == GL_MATRIX_PALETTE_ARB ) ostr << "GL_MATRIX_PALETTE_ARB";
	#endif
	#ifdef GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB
		else if ( en == GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB ) ostr << "GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB";
	#endif
	#ifdef GL_MAX_PALETTE_MATRICES_ARB
		else if ( en == GL_MAX_PALETTE_MATRICES_ARB ) ostr << "GL_MAX_PALETTE_MATRICES_ARB";
	#endif
	#ifdef GL_CURRENT_PALETTE_MATRIX_ARB
		else if ( en == GL_CURRENT_PALETTE_MATRIX_ARB ) ostr << "GL_CURRENT_PALETTE_MATRIX_ARB";
	#endif
	#ifdef GL_MATRIX_INDEX_ARRAY_ARB
		else if ( en == GL_MATRIX_INDEX_ARRAY_ARB ) ostr << "GL_MATRIX_INDEX_ARRAY_ARB";
	#endif
	#ifdef GL_CURRENT_MATRIX_INDEX_ARB
		else if ( en == GL_CURRENT_MATRIX_INDEX_ARB ) ostr << "GL_CURRENT_MATRIX_INDEX_ARB";
	#endif
	#ifdef GL_MATRIX_INDEX_ARRAY_SIZE_ARB
		else if ( en == GL_MATRIX_INDEX_ARRAY_SIZE_ARB ) ostr << "GL_MATRIX_INDEX_ARRAY_SIZE_ARB";
	#endif
	#ifdef GL_MATRIX_INDEX_ARRAY_TYPE_ARB
		else if ( en == GL_MATRIX_INDEX_ARRAY_TYPE_ARB ) ostr << "GL_MATRIX_INDEX_ARRAY_TYPE_ARB";
	#endif
	#ifdef GL_MATRIX_INDEX_ARRAY_STRIDE_ARB
		else if ( en == GL_MATRIX_INDEX_ARRAY_STRIDE_ARB ) ostr << "GL_MATRIX_INDEX_ARRAY_STRIDE_ARB";
	#endif
	#ifdef GL_MATRIX_INDEX_ARRAY_POINTER_ARB
		else if ( en == GL_MATRIX_INDEX_ARRAY_POINTER_ARB ) ostr << "GL_MATRIX_INDEX_ARRAY_POINTER_ARB";
	#endif
	#ifdef GL_MULTISAMPLE_ARB
		else if ( en == GL_MULTISAMPLE_ARB ) ostr << "GL_MULTISAMPLE_ARB";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE_ARB
		else if ( en == GL_SAMPLE_ALPHA_TO_COVERAGE_ARB ) ostr << "GL_SAMPLE_ALPHA_TO_COVERAGE_ARB";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_ONE_ARB
		else if ( en == GL_SAMPLE_ALPHA_TO_ONE_ARB ) ostr << "GL_SAMPLE_ALPHA_TO_ONE_ARB";
	#endif
	#ifdef GL_SAMPLE_COVERAGE_ARB
		else if ( en == GL_SAMPLE_COVERAGE_ARB ) ostr << "GL_SAMPLE_COVERAGE_ARB";
	#endif
	#ifdef GL_SAMPLE_BUFFERS_ARB
		else if ( en == GL_SAMPLE_BUFFERS_ARB ) ostr << "GL_SAMPLE_BUFFERS_ARB";
	#endif
	#ifdef GL_SAMPLES_ARB
		else if ( en == GL_SAMPLES_ARB ) ostr << "GL_SAMPLES_ARB";
	#endif
	#ifdef GL_SAMPLE_COVERAGE_VALUE_ARB
		else if ( en == GL_SAMPLE_COVERAGE_VALUE_ARB ) ostr << "GL_SAMPLE_COVERAGE_VALUE_ARB";
	#endif
	#ifdef GL_SAMPLE_COVERAGE_INVERT_ARB
		else if ( en == GL_SAMPLE_COVERAGE_INVERT_ARB ) ostr << "GL_SAMPLE_COVERAGE_INVERT_ARB";
	#endif
	#ifdef GL_MULTISAMPLE_BIT_ARB
		else if ( en == GL_MULTISAMPLE_BIT_ARB ) ostr << "GL_MULTISAMPLE_BIT_ARB";
	#endif
	#ifdef GL_TEXTURE0_ARB
		else if ( en == GL_TEXTURE0_ARB ) ostr << "GL_TEXTURE0_ARB";
	#endif
	#ifdef GL_TEXTURE1_ARB
		else if ( en == GL_TEXTURE1_ARB ) ostr << "GL_TEXTURE1_ARB";
	#endif
	#ifdef GL_TEXTURE2_ARB
		else if ( en == GL_TEXTURE2_ARB ) ostr << "GL_TEXTURE2_ARB";
	#endif
	#ifdef GL_TEXTURE3_ARB
		else if ( en == GL_TEXTURE3_ARB ) ostr << "GL_TEXTURE3_ARB";
	#endif
	#ifdef GL_TEXTURE4_ARB
		else if ( en == GL_TEXTURE4_ARB ) ostr << "GL_TEXTURE4_ARB";
	#endif
	#ifdef GL_TEXTURE5_ARB
		else if ( en == GL_TEXTURE5_ARB ) ostr << "GL_TEXTURE5_ARB";
	#endif
	#ifdef GL_TEXTURE6_ARB
		else if ( en == GL_TEXTURE6_ARB ) ostr << "GL_TEXTURE6_ARB";
	#endif
	#ifdef GL_TEXTURE7_ARB
		else if ( en == GL_TEXTURE7_ARB ) ostr << "GL_TEXTURE7_ARB";
	#endif
	#ifdef GL_TEXTURE8_ARB
		else if ( en == GL_TEXTURE8_ARB ) ostr << "GL_TEXTURE8_ARB";
	#endif
	#ifdef GL_TEXTURE9_ARB
		else if ( en == GL_TEXTURE9_ARB ) ostr << "GL_TEXTURE9_ARB";
	#endif
	#ifdef GL_TEXTURE10_ARB
		else if ( en == GL_TEXTURE10_ARB ) ostr << "GL_TEXTURE10_ARB";
	#endif
	#ifdef GL_TEXTURE11_ARB
		else if ( en == GL_TEXTURE11_ARB ) ostr << "GL_TEXTURE11_ARB";
	#endif
	#ifdef GL_TEXTURE12_ARB
		else if ( en == GL_TEXTURE12_ARB ) ostr << "GL_TEXTURE12_ARB";
	#endif
	#ifdef GL_TEXTURE13_ARB
		else if ( en == GL_TEXTURE13_ARB ) ostr << "GL_TEXTURE13_ARB";
	#endif
	#ifdef GL_TEXTURE14_ARB
		else if ( en == GL_TEXTURE14_ARB ) ostr << "GL_TEXTURE14_ARB";
	#endif
	#ifdef GL_TEXTURE15_ARB
		else if ( en == GL_TEXTURE15_ARB ) ostr << "GL_TEXTURE15_ARB";
	#endif
	#ifdef GL_TEXTURE16_ARB
		else if ( en == GL_TEXTURE16_ARB ) ostr << "GL_TEXTURE16_ARB";
	#endif
	#ifdef GL_TEXTURE17_ARB
		else if ( en == GL_TEXTURE17_ARB ) ostr << "GL_TEXTURE17_ARB";
	#endif
	#ifdef GL_TEXTURE18_ARB
		else if ( en == GL_TEXTURE18_ARB ) ostr << "GL_TEXTURE18_ARB";
	#endif
	#ifdef GL_TEXTURE19_ARB
		else if ( en == GL_TEXTURE19_ARB ) ostr << "GL_TEXTURE19_ARB";
	#endif
	#ifdef GL_TEXTURE20_ARB
		else if ( en == GL_TEXTURE20_ARB ) ostr << "GL_TEXTURE20_ARB";
	#endif
	#ifdef GL_TEXTURE21_ARB
		else if ( en == GL_TEXTURE21_ARB ) ostr << "GL_TEXTURE21_ARB";
	#endif
	#ifdef GL_TEXTURE22_ARB
		else if ( en == GL_TEXTURE22_ARB ) ostr << "GL_TEXTURE22_ARB";
	#endif
	#ifdef GL_TEXTURE23_ARB
		else if ( en == GL_TEXTURE23_ARB ) ostr << "GL_TEXTURE23_ARB";
	#endif
	#ifdef GL_TEXTURE24_ARB
		else if ( en == GL_TEXTURE24_ARB ) ostr << "GL_TEXTURE24_ARB";
	#endif
	#ifdef GL_TEXTURE25_ARB
		else if ( en == GL_TEXTURE25_ARB ) ostr << "GL_TEXTURE25_ARB";
	#endif
	#ifdef GL_TEXTURE26_ARB
		else if ( en == GL_TEXTURE26_ARB ) ostr << "GL_TEXTURE26_ARB";
	#endif
	#ifdef GL_TEXTURE27_ARB
		else if ( en == GL_TEXTURE27_ARB ) ostr << "GL_TEXTURE27_ARB";
	#endif
	#ifdef GL_TEXTURE28_ARB
		else if ( en == GL_TEXTURE28_ARB ) ostr << "GL_TEXTURE28_ARB";
	#endif
	#ifdef GL_TEXTURE29_ARB
		else if ( en == GL_TEXTURE29_ARB ) ostr << "GL_TEXTURE29_ARB";
	#endif
	#ifdef GL_TEXTURE30_ARB
		else if ( en == GL_TEXTURE30_ARB ) ostr << "GL_TEXTURE30_ARB";
	#endif
	#ifdef GL_TEXTURE31_ARB
		else if ( en == GL_TEXTURE31_ARB ) ostr << "GL_TEXTURE31_ARB";
	#endif
	#ifdef GL_ACTIVE_TEXTURE_ARB
		else if ( en == GL_ACTIVE_TEXTURE_ARB ) ostr << "GL_ACTIVE_TEXTURE_ARB";
	#endif
	#ifdef GL_CLIENT_ACTIVE_TEXTURE_ARB
		else if ( en == GL_CLIENT_ACTIVE_TEXTURE_ARB ) ostr << "GL_CLIENT_ACTIVE_TEXTURE_ARB";
	#endif
	#ifdef GL_MAX_TEXTURE_UNITS_ARB
		else if ( en == GL_MAX_TEXTURE_UNITS_ARB ) ostr << "GL_MAX_TEXTURE_UNITS_ARB";
	#endif
	#ifdef GL_QUERY_COUNTER_BITS_ARB
		else if ( en == GL_QUERY_COUNTER_BITS_ARB ) ostr << "GL_QUERY_COUNTER_BITS_ARB";
	#endif
	#ifdef GL_CURRENT_QUERY_ARB
		else if ( en == GL_CURRENT_QUERY_ARB ) ostr << "GL_CURRENT_QUERY_ARB";
	#endif
	#ifdef GL_QUERY_RESULT_ARB
		else if ( en == GL_QUERY_RESULT_ARB ) ostr << "GL_QUERY_RESULT_ARB";
	#endif
	#ifdef GL_QUERY_RESULT_AVAILABLE_ARB
		else if ( en == GL_QUERY_RESULT_AVAILABLE_ARB ) ostr << "GL_QUERY_RESULT_AVAILABLE_ARB";
	#endif
	#ifdef GL_SAMPLES_PASSED_ARB
		else if ( en == GL_SAMPLES_PASSED_ARB ) ostr << "GL_SAMPLES_PASSED_ARB";
	#endif
	#ifdef GL_ANY_SAMPLES_PASSED
		else if ( en == GL_ANY_SAMPLES_PASSED ) ostr << "GL_ANY_SAMPLES_PASSED";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER_ARB
		else if ( en == GL_PIXEL_PACK_BUFFER_ARB ) ostr << "GL_PIXEL_PACK_BUFFER_ARB";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER_ARB
		else if ( en == GL_PIXEL_UNPACK_BUFFER_ARB ) ostr << "GL_PIXEL_UNPACK_BUFFER_ARB";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER_BINDING_ARB
		else if ( en == GL_PIXEL_PACK_BUFFER_BINDING_ARB ) ostr << "GL_PIXEL_PACK_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING_ARB
		else if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING_ARB ) ostr << "GL_PIXEL_UNPACK_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_POINT_SIZE_MIN_ARB
		else if ( en == GL_POINT_SIZE_MIN_ARB ) ostr << "GL_POINT_SIZE_MIN_ARB";
	#endif
	#ifdef GL_POINT_SIZE_MAX_ARB
		else if ( en == GL_POINT_SIZE_MAX_ARB ) ostr << "GL_POINT_SIZE_MAX_ARB";
	#endif
	#ifdef GL_POINT_FADE_THRESHOLD_SIZE_ARB
		else if ( en == GL_POINT_FADE_THRESHOLD_SIZE_ARB ) ostr << "GL_POINT_FADE_THRESHOLD_SIZE_ARB";
	#endif
	#ifdef GL_POINT_DISTANCE_ATTENUATION_ARB
		else if ( en == GL_POINT_DISTANCE_ATTENUATION_ARB ) ostr << "GL_POINT_DISTANCE_ATTENUATION_ARB";
	#endif
	#ifdef GL_POINT_SPRITE_ARB
		else if ( en == GL_POINT_SPRITE_ARB ) ostr << "GL_POINT_SPRITE_ARB";
	#endif
	#ifdef GL_COORD_REPLACE_ARB
		else if ( en == GL_COORD_REPLACE_ARB ) ostr << "GL_COORD_REPLACE_ARB";
	#endif
	#ifdef GL_UNIFORM
		else if ( en == GL_UNIFORM ) ostr << "GL_UNIFORM";
	#endif
	#ifdef GL_UNIFORM_BLOCK
		else if ( en == GL_UNIFORM_BLOCK ) ostr << "GL_UNIFORM_BLOCK";
	#endif
	#ifdef GL_PROGRAM_INPUT
		else if ( en == GL_PROGRAM_INPUT ) ostr << "GL_PROGRAM_INPUT";
	#endif
	#ifdef GL_PROGRAM_OUTPUT
		else if ( en == GL_PROGRAM_OUTPUT ) ostr << "GL_PROGRAM_OUTPUT";
	#endif
	#ifdef GL_BUFFER_VARIABLE
		else if ( en == GL_BUFFER_VARIABLE ) ostr << "GL_BUFFER_VARIABLE";
	#endif
	#ifdef GL_SHADER_STORAGE_BLOCK
		else if ( en == GL_SHADER_STORAGE_BLOCK ) ostr << "GL_SHADER_STORAGE_BLOCK";
	#endif
	#ifdef GL_IS_PER_PATCH
		else if ( en == GL_IS_PER_PATCH ) ostr << "GL_IS_PER_PATCH";
	#endif
	#ifdef GL_VERTEX_SUBROUTINE
		else if ( en == GL_VERTEX_SUBROUTINE ) ostr << "GL_VERTEX_SUBROUTINE";
	#endif
	#ifdef GL_TESS_CONTROL_SUBROUTINE
		else if ( en == GL_TESS_CONTROL_SUBROUTINE ) ostr << "GL_TESS_CONTROL_SUBROUTINE";
	#endif
	#ifdef GL_TESS_EVALUATION_SUBROUTINE
		else if ( en == GL_TESS_EVALUATION_SUBROUTINE ) ostr << "GL_TESS_EVALUATION_SUBROUTINE";
	#endif
	#ifdef GL_GEOMETRY_SUBROUTINE
		else if ( en == GL_GEOMETRY_SUBROUTINE ) ostr << "GL_GEOMETRY_SUBROUTINE";
	#endif
	#ifdef GL_FRAGMENT_SUBROUTINE
		else if ( en == GL_FRAGMENT_SUBROUTINE ) ostr << "GL_FRAGMENT_SUBROUTINE";
	#endif
	#ifdef GL_COMPUTE_SUBROUTINE
		else if ( en == GL_COMPUTE_SUBROUTINE ) ostr << "GL_COMPUTE_SUBROUTINE";
	#endif
	#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
		else if ( en == GL_VERTEX_SUBROUTINE_UNIFORM ) ostr << "GL_VERTEX_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
		else if ( en == GL_TESS_CONTROL_SUBROUTINE_UNIFORM ) ostr << "GL_TESS_CONTROL_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
		else if ( en == GL_TESS_EVALUATION_SUBROUTINE_UNIFORM ) ostr << "GL_TESS_EVALUATION_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
		else if ( en == GL_GEOMETRY_SUBROUTINE_UNIFORM ) ostr << "GL_GEOMETRY_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
		else if ( en == GL_FRAGMENT_SUBROUTINE_UNIFORM ) ostr << "GL_FRAGMENT_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
		else if ( en == GL_COMPUTE_SUBROUTINE_UNIFORM ) ostr << "GL_COMPUTE_SUBROUTINE_UNIFORM";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYING
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYING ) ostr << "GL_TRANSFORM_FEEDBACK_VARYING";
	#endif
	#ifdef GL_ACTIVE_RESOURCES
		else if ( en == GL_ACTIVE_RESOURCES ) ostr << "GL_ACTIVE_RESOURCES";
	#endif
	#ifdef GL_MAX_NAME_LENGTH
		else if ( en == GL_MAX_NAME_LENGTH ) ostr << "GL_MAX_NAME_LENGTH";
	#endif
	#ifdef GL_MAX_NUM_ACTIVE_VARIABLES
		else if ( en == GL_MAX_NUM_ACTIVE_VARIABLES ) ostr << "GL_MAX_NUM_ACTIVE_VARIABLES";
	#endif
	#ifdef GL_MAX_NUM_COMPATIBLE_SUBROUTINES
		else if ( en == GL_MAX_NUM_COMPATIBLE_SUBROUTINES ) ostr << "GL_MAX_NUM_COMPATIBLE_SUBROUTINES";
	#endif
	#ifdef GL_NAME_LENGTH
		else if ( en == GL_NAME_LENGTH ) ostr << "GL_NAME_LENGTH";
	#endif
	#ifdef GL_TYPE
		else if ( en == GL_TYPE ) ostr << "GL_TYPE";
	#endif
	#ifdef GL_ARRAY_SIZE
		else if ( en == GL_ARRAY_SIZE ) ostr << "GL_ARRAY_SIZE";
	#endif
	#ifdef GL_OFFSET
		else if ( en == GL_OFFSET ) ostr << "GL_OFFSET";
	#endif
	#ifdef GL_BLOCK_INDEX
		else if ( en == GL_BLOCK_INDEX ) ostr << "GL_BLOCK_INDEX";
	#endif
	#ifdef GL_ARRAY_STRIDE
		else if ( en == GL_ARRAY_STRIDE ) ostr << "GL_ARRAY_STRIDE";
	#endif
	#ifdef GL_MATRIX_STRIDE
		else if ( en == GL_MATRIX_STRIDE ) ostr << "GL_MATRIX_STRIDE";
	#endif
	#ifdef GL_IS_ROW_MAJOR
		else if ( en == GL_IS_ROW_MAJOR ) ostr << "GL_IS_ROW_MAJOR";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_INDEX ) ostr << "GL_ATOMIC_COUNTER_BUFFER_INDEX";
	#endif
	#ifdef GL_BUFFER_BINDING
		else if ( en == GL_BUFFER_BINDING ) ostr << "GL_BUFFER_BINDING";
	#endif
	#ifdef GL_BUFFER_DATA_SIZE
		else if ( en == GL_BUFFER_DATA_SIZE ) ostr << "GL_BUFFER_DATA_SIZE";
	#endif
	#ifdef GL_NUM_ACTIVE_VARIABLES
		else if ( en == GL_NUM_ACTIVE_VARIABLES ) ostr << "GL_NUM_ACTIVE_VARIABLES";
	#endif
	#ifdef GL_ACTIVE_VARIABLES
		else if ( en == GL_ACTIVE_VARIABLES ) ostr << "GL_ACTIVE_VARIABLES";
	#endif
	#ifdef GL_REFERENCED_BY_VERTEX_SHADER
		else if ( en == GL_REFERENCED_BY_VERTEX_SHADER ) ostr << "GL_REFERENCED_BY_VERTEX_SHADER";
	#endif
	#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
		else if ( en == GL_REFERENCED_BY_TESS_CONTROL_SHADER ) ostr << "GL_REFERENCED_BY_TESS_CONTROL_SHADER";
	#endif
	#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
		else if ( en == GL_REFERENCED_BY_TESS_EVALUATION_SHADER ) ostr << "GL_REFERENCED_BY_TESS_EVALUATION_SHADER";
	#endif
	#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
		else if ( en == GL_REFERENCED_BY_GEOMETRY_SHADER ) ostr << "GL_REFERENCED_BY_GEOMETRY_SHADER";
	#endif
	#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
		else if ( en == GL_REFERENCED_BY_FRAGMENT_SHADER ) ostr << "GL_REFERENCED_BY_FRAGMENT_SHADER";
	#endif
	#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
		else if ( en == GL_REFERENCED_BY_COMPUTE_SHADER ) ostr << "GL_REFERENCED_BY_COMPUTE_SHADER";
	#endif
	#ifdef GL_TOP_LEVEL_ARRAY_SIZE
		else if ( en == GL_TOP_LEVEL_ARRAY_SIZE ) ostr << "GL_TOP_LEVEL_ARRAY_SIZE";
	#endif
	#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
		else if ( en == GL_TOP_LEVEL_ARRAY_STRIDE ) ostr << "GL_TOP_LEVEL_ARRAY_STRIDE";
	#endif
	#ifdef GL_LOCATION
		else if ( en == GL_LOCATION ) ostr << "GL_LOCATION";
	#endif
	#ifdef GL_LOCATION_INDEX
		else if ( en == GL_LOCATION_INDEX ) ostr << "GL_LOCATION_INDEX";
	#endif
	#ifdef GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION
		else if ( en == GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION ) ostr << "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION";
	#endif
	#ifdef GL_FIRST_VERTEX_CONVENTION
		else if ( en == GL_FIRST_VERTEX_CONVENTION ) ostr << "GL_FIRST_VERTEX_CONVENTION";
	#endif
	#ifdef GL_LAST_VERTEX_CONVENTION
		else if ( en == GL_LAST_VERTEX_CONVENTION ) ostr << "GL_LAST_VERTEX_CONVENTION";
	#endif
	#ifdef GL_PROVOKING_VERTEX
		else if ( en == GL_PROVOKING_VERTEX ) ostr << "GL_PROVOKING_VERTEX";
	#endif
	#ifdef GL_QUERY_BUFFER_BARRIER_BIT
		else if ( en == GL_QUERY_BUFFER_BARRIER_BIT ) ostr << "GL_QUERY_BUFFER_BARRIER_BIT";
	#endif
	#ifdef GL_QUERY_BUFFER
		else if ( en == GL_QUERY_BUFFER ) ostr << "GL_QUERY_BUFFER";
	#endif
	#ifdef GL_QUERY_BUFFER_BINDING
		else if ( en == GL_QUERY_BUFFER_BINDING ) ostr << "GL_QUERY_BUFFER_BINDING";
	#endif
	#ifdef GL_QUERY_RESULT_NO_WAIT
		else if ( en == GL_QUERY_RESULT_NO_WAIT ) ostr << "GL_QUERY_RESULT_NO_WAIT";
	#endif
	#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
		else if ( en == GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB ) ostr << "GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB";
	#endif
	#ifdef GL_LOSE_CONTEXT_ON_RESET_ARB
		else if ( en == GL_LOSE_CONTEXT_ON_RESET_ARB ) ostr << "GL_LOSE_CONTEXT_ON_RESET_ARB";
	#endif
	#ifdef GL_GUILTY_CONTEXT_RESET_ARB
		else if ( en == GL_GUILTY_CONTEXT_RESET_ARB ) ostr << "GL_GUILTY_CONTEXT_RESET_ARB";
	#endif
	#ifdef GL_INNOCENT_CONTEXT_RESET_ARB
		else if ( en == GL_INNOCENT_CONTEXT_RESET_ARB ) ostr << "GL_INNOCENT_CONTEXT_RESET_ARB";
	#endif
	#ifdef GL_UNKNOWN_CONTEXT_RESET_ARB
		else if ( en == GL_UNKNOWN_CONTEXT_RESET_ARB ) ostr << "GL_UNKNOWN_CONTEXT_RESET_ARB";
	#endif
	#ifdef GL_RESET_NOTIFICATION_STRATEGY_ARB
		else if ( en == GL_RESET_NOTIFICATION_STRATEGY_ARB ) ostr << "GL_RESET_NOTIFICATION_STRATEGY_ARB";
	#endif
	#ifdef GL_NO_RESET_NOTIFICATION_ARB
		else if ( en == GL_NO_RESET_NOTIFICATION_ARB ) ostr << "GL_NO_RESET_NOTIFICATION_ARB";
	#endif
	#ifdef GL_SAMPLE_SHADING_ARB
		else if ( en == GL_SAMPLE_SHADING_ARB ) ostr << "GL_SAMPLE_SHADING_ARB";
	#endif
	#ifdef GL_MIN_SAMPLE_SHADING_VALUE_ARB
		else if ( en == GL_MIN_SAMPLE_SHADING_VALUE_ARB ) ostr << "GL_MIN_SAMPLE_SHADING_VALUE_ARB";
	#endif
	#ifdef GL_SAMPLER_BINDING
		else if ( en == GL_SAMPLER_BINDING ) ostr << "GL_SAMPLER_BINDING";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
		else if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS ) ostr << "GL_TEXTURE_CUBE_MAP_SEAMLESS";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
		else if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS ) ostr << "GL_TEXTURE_CUBE_MAP_SEAMLESS";
	#endif
	#ifdef GL_VERTEX_SHADER_BIT
		else if ( en == GL_VERTEX_SHADER_BIT ) ostr << "GL_VERTEX_SHADER_BIT";
	#endif
	#ifdef GL_FRAGMENT_SHADER_BIT
		else if ( en == GL_FRAGMENT_SHADER_BIT ) ostr << "GL_FRAGMENT_SHADER_BIT";
	#endif
	#ifdef GL_GEOMETRY_SHADER_BIT
		else if ( en == GL_GEOMETRY_SHADER_BIT ) ostr << "GL_GEOMETRY_SHADER_BIT";
	#endif
	#ifdef GL_TESS_CONTROL_SHADER_BIT
		else if ( en == GL_TESS_CONTROL_SHADER_BIT ) ostr << "GL_TESS_CONTROL_SHADER_BIT";
	#endif
	#ifdef GL_TESS_EVALUATION_SHADER_BIT
		else if ( en == GL_TESS_EVALUATION_SHADER_BIT ) ostr << "GL_TESS_EVALUATION_SHADER_BIT";
	#endif
	#ifdef GL_PROGRAM_SEPARABLE
		else if ( en == GL_PROGRAM_SEPARABLE ) ostr << "GL_PROGRAM_SEPARABLE";
	#endif
	#ifdef GL_ACTIVE_PROGRAM
		else if ( en == GL_ACTIVE_PROGRAM ) ostr << "GL_ACTIVE_PROGRAM";
	#endif
	#ifdef GL_PROGRAM_PIPELINE_BINDING
		else if ( en == GL_PROGRAM_PIPELINE_BINDING ) ostr << "GL_PROGRAM_PIPELINE_BINDING";
	#endif
	#ifdef GL_ALL_SHADER_BITS
		else if ( en == GL_ALL_SHADER_BITS ) ostr << "GL_ALL_SHADER_BITS";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER ) ostr << "GL_ATOMIC_COUNTER_BUFFER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_BINDING ) ostr << "GL_ATOMIC_COUNTER_BUFFER_BINDING";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_START
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_START ) ostr << "GL_ATOMIC_COUNTER_BUFFER_START";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_SIZE
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_SIZE ) ostr << "GL_ATOMIC_COUNTER_BUFFER_SIZE";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE ) ostr << "GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS ) ostr << "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES ) ostr << "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER
		else if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER ) ostr << "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER";
	#endif
	#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
		else if ( en == GL_MAX_VERTEX_ATOMIC_COUNTERS ) ostr << "GL_MAX_VERTEX_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
		else if ( en == GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS ) ostr << "GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
		else if ( en == GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS ) ostr << "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
		else if ( en == GL_MAX_GEOMETRY_ATOMIC_COUNTERS ) ostr << "GL_MAX_GEOMETRY_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
		else if ( en == GL_MAX_FRAGMENT_ATOMIC_COUNTERS ) ostr << "GL_MAX_FRAGMENT_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
		else if ( en == GL_MAX_COMBINED_ATOMIC_COUNTERS ) ostr << "GL_MAX_COMBINED_ATOMIC_COUNTERS";
	#endif
	#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
		else if ( en == GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE ) ostr << "GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE";
	#endif
	#ifdef GL_ACTIVE_ATOMIC_COUNTER_BUFFERS
		else if ( en == GL_ACTIVE_ATOMIC_COUNTER_BUFFERS ) ostr << "GL_ACTIVE_ATOMIC_COUNTER_BUFFERS";
	#endif
	#ifdef GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX
		else if ( en == GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX ) ostr << "GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX";
	#endif
	#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
		else if ( en == GL_UNSIGNED_INT_ATOMIC_COUNTER ) ostr << "GL_UNSIGNED_INT_ATOMIC_COUNTER";
	#endif
	#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
		else if ( en == GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS ) ostr << "GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT ) ostr << "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
		else if ( en == GL_ELEMENT_ARRAY_BARRIER_BIT ) ostr << "GL_ELEMENT_ARRAY_BARRIER_BIT";
	#endif
	#ifdef GL_UNIFORM_BARRIER_BIT
		else if ( en == GL_UNIFORM_BARRIER_BIT ) ostr << "GL_UNIFORM_BARRIER_BIT";
	#endif
	#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
		else if ( en == GL_TEXTURE_FETCH_BARRIER_BIT ) ostr << "GL_TEXTURE_FETCH_BARRIER_BIT";
	#endif
	#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
		else if ( en == GL_SHADER_IMAGE_ACCESS_BARRIER_BIT ) ostr << "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT";
	#endif
	#ifdef GL_COMMAND_BARRIER_BIT
		else if ( en == GL_COMMAND_BARRIER_BIT ) ostr << "GL_COMMAND_BARRIER_BIT";
	#endif
	#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
		else if ( en == GL_PIXEL_BUFFER_BARRIER_BIT ) ostr << "GL_PIXEL_BUFFER_BARRIER_BIT";
	#endif
	#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
		else if ( en == GL_TEXTURE_UPDATE_BARRIER_BIT ) ostr << "GL_TEXTURE_UPDATE_BARRIER_BIT";
	#endif
	#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
		else if ( en == GL_BUFFER_UPDATE_BARRIER_BIT ) ostr << "GL_BUFFER_UPDATE_BARRIER_BIT";
	#endif
	#ifdef GL_FRAMEBUFFER_BARRIER_BIT
		else if ( en == GL_FRAMEBUFFER_BARRIER_BIT ) ostr << "GL_FRAMEBUFFER_BARRIER_BIT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
		else if ( en == GL_TRANSFORM_FEEDBACK_BARRIER_BIT ) ostr << "GL_TRANSFORM_FEEDBACK_BARRIER_BIT";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
		else if ( en == GL_ATOMIC_COUNTER_BARRIER_BIT ) ostr << "GL_ATOMIC_COUNTER_BARRIER_BIT";
	#endif
	#ifdef GL_MAX_IMAGE_UNITS
		else if ( en == GL_MAX_IMAGE_UNITS ) ostr << "GL_MAX_IMAGE_UNITS";
	#endif
	#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
		else if ( en == GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS ) ostr << "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS";
	#endif
	#ifdef GL_IMAGE_BINDING_NAME
		else if ( en == GL_IMAGE_BINDING_NAME ) ostr << "GL_IMAGE_BINDING_NAME";
	#endif
	#ifdef GL_IMAGE_BINDING_LEVEL
		else if ( en == GL_IMAGE_BINDING_LEVEL ) ostr << "GL_IMAGE_BINDING_LEVEL";
	#endif
	#ifdef GL_IMAGE_BINDING_LAYERED
		else if ( en == GL_IMAGE_BINDING_LAYERED ) ostr << "GL_IMAGE_BINDING_LAYERED";
	#endif
	#ifdef GL_IMAGE_BINDING_LAYER
		else if ( en == GL_IMAGE_BINDING_LAYER ) ostr << "GL_IMAGE_BINDING_LAYER";
	#endif
	#ifdef GL_IMAGE_BINDING_ACCESS
		else if ( en == GL_IMAGE_BINDING_ACCESS ) ostr << "GL_IMAGE_BINDING_ACCESS";
	#endif
	#ifdef GL_IMAGE_1D
		else if ( en == GL_IMAGE_1D ) ostr << "GL_IMAGE_1D";
	#endif
	#ifdef GL_IMAGE_2D
		else if ( en == GL_IMAGE_2D ) ostr << "GL_IMAGE_2D";
	#endif
	#ifdef GL_IMAGE_3D
		else if ( en == GL_IMAGE_3D ) ostr << "GL_IMAGE_3D";
	#endif
	#ifdef GL_IMAGE_2D_RECT
		else if ( en == GL_IMAGE_2D_RECT ) ostr << "GL_IMAGE_2D_RECT";
	#endif
	#ifdef GL_IMAGE_CUBE
		else if ( en == GL_IMAGE_CUBE ) ostr << "GL_IMAGE_CUBE";
	#endif
	#ifdef GL_IMAGE_BUFFER
		else if ( en == GL_IMAGE_BUFFER ) ostr << "GL_IMAGE_BUFFER";
	#endif
	#ifdef GL_IMAGE_1D_ARRAY
		else if ( en == GL_IMAGE_1D_ARRAY ) ostr << "GL_IMAGE_1D_ARRAY";
	#endif
	#ifdef GL_IMAGE_2D_ARRAY
		else if ( en == GL_IMAGE_2D_ARRAY ) ostr << "GL_IMAGE_2D_ARRAY";
	#endif
	#ifdef GL_IMAGE_CUBE_MAP_ARRAY
		else if ( en == GL_IMAGE_CUBE_MAP_ARRAY ) ostr << "GL_IMAGE_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_IMAGE_2D_MULTISAMPLE
		else if ( en == GL_IMAGE_2D_MULTISAMPLE ) ostr << "GL_IMAGE_2D_MULTISAMPLE";
	#endif
	#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_IMAGE_2D_MULTISAMPLE_ARRAY ) ostr << "GL_IMAGE_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_INT_IMAGE_1D
		else if ( en == GL_INT_IMAGE_1D ) ostr << "GL_INT_IMAGE_1D";
	#endif
	#ifdef GL_INT_IMAGE_2D
		else if ( en == GL_INT_IMAGE_2D ) ostr << "GL_INT_IMAGE_2D";
	#endif
	#ifdef GL_INT_IMAGE_3D
		else if ( en == GL_INT_IMAGE_3D ) ostr << "GL_INT_IMAGE_3D";
	#endif
	#ifdef GL_INT_IMAGE_2D_RECT
		else if ( en == GL_INT_IMAGE_2D_RECT ) ostr << "GL_INT_IMAGE_2D_RECT";
	#endif
	#ifdef GL_INT_IMAGE_CUBE
		else if ( en == GL_INT_IMAGE_CUBE ) ostr << "GL_INT_IMAGE_CUBE";
	#endif
	#ifdef GL_INT_IMAGE_BUFFER
		else if ( en == GL_INT_IMAGE_BUFFER ) ostr << "GL_INT_IMAGE_BUFFER";
	#endif
	#ifdef GL_INT_IMAGE_1D_ARRAY
		else if ( en == GL_INT_IMAGE_1D_ARRAY ) ostr << "GL_INT_IMAGE_1D_ARRAY";
	#endif
	#ifdef GL_INT_IMAGE_2D_ARRAY
		else if ( en == GL_INT_IMAGE_2D_ARRAY ) ostr << "GL_INT_IMAGE_2D_ARRAY";
	#endif
	#ifdef GL_INT_IMAGE_CUBE_MAP_ARRAY
		else if ( en == GL_INT_IMAGE_CUBE_MAP_ARRAY ) ostr << "GL_INT_IMAGE_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
		else if ( en == GL_INT_IMAGE_2D_MULTISAMPLE ) ostr << "GL_INT_IMAGE_2D_MULTISAMPLE";
	#endif
	#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY ) ostr << "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_1D
		else if ( en == GL_UNSIGNED_INT_IMAGE_1D ) ostr << "GL_UNSIGNED_INT_IMAGE_1D";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D ) ostr << "GL_UNSIGNED_INT_IMAGE_2D";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_3D
		else if ( en == GL_UNSIGNED_INT_IMAGE_3D ) ostr << "GL_UNSIGNED_INT_IMAGE_3D";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_RECT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_RECT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
		else if ( en == GL_UNSIGNED_INT_IMAGE_CUBE ) ostr << "GL_UNSIGNED_INT_IMAGE_CUBE";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
		else if ( en == GL_UNSIGNED_INT_IMAGE_BUFFER ) ostr << "GL_UNSIGNED_INT_IMAGE_BUFFER";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
		else if ( en == GL_UNSIGNED_INT_IMAGE_1D_ARRAY ) ostr << "GL_UNSIGNED_INT_IMAGE_1D_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_ARRAY ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY
		else if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY ) ostr << "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_MAX_IMAGE_SAMPLES
		else if ( en == GL_MAX_IMAGE_SAMPLES ) ostr << "GL_MAX_IMAGE_SAMPLES";
	#endif
	#ifdef GL_IMAGE_BINDING_FORMAT
		else if ( en == GL_IMAGE_BINDING_FORMAT ) ostr << "GL_IMAGE_BINDING_FORMAT";
	#endif
	#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
		else if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_TYPE ) ostr << "GL_IMAGE_FORMAT_COMPATIBILITY_TYPE";
	#endif
	#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE
		else if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE ) ostr << "GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE";
	#endif
	#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS
		else if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS ) ostr << "GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS";
	#endif
	#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
		else if ( en == GL_MAX_VERTEX_IMAGE_UNIFORMS ) ostr << "GL_MAX_VERTEX_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
		else if ( en == GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS ) ostr << "GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
		else if ( en == GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS ) ostr << "GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
		else if ( en == GL_MAX_GEOMETRY_IMAGE_UNIFORMS ) ostr << "GL_MAX_GEOMETRY_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
		else if ( en == GL_MAX_FRAGMENT_IMAGE_UNIFORMS ) ostr << "GL_MAX_FRAGMENT_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
		else if ( en == GL_MAX_COMBINED_IMAGE_UNIFORMS ) ostr << "GL_MAX_COMBINED_IMAGE_UNIFORMS";
	#endif
	#ifdef GL_ALL_BARRIER_BITS
		else if ( en == GL_ALL_BARRIER_BITS ) ostr << "GL_ALL_BARRIER_BITS";
	#endif
	#ifdef GL_PROGRAM_OBJECT_ARB
		else if ( en == GL_PROGRAM_OBJECT_ARB ) ostr << "GL_PROGRAM_OBJECT_ARB";
	#endif
	#ifdef GL_SHADER_OBJECT_ARB
		else if ( en == GL_SHADER_OBJECT_ARB ) ostr << "GL_SHADER_OBJECT_ARB";
	#endif
	#ifdef GL_OBJECT_TYPE_ARB
		else if ( en == GL_OBJECT_TYPE_ARB ) ostr << "GL_OBJECT_TYPE_ARB";
	#endif
	#ifdef GL_OBJECT_SUBTYPE_ARB
		else if ( en == GL_OBJECT_SUBTYPE_ARB ) ostr << "GL_OBJECT_SUBTYPE_ARB";
	#endif
	#ifdef GL_FLOAT_VEC2_ARB
		else if ( en == GL_FLOAT_VEC2_ARB ) ostr << "GL_FLOAT_VEC2_ARB";
	#endif
	#ifdef GL_FLOAT_VEC3_ARB
		else if ( en == GL_FLOAT_VEC3_ARB ) ostr << "GL_FLOAT_VEC3_ARB";
	#endif
	#ifdef GL_FLOAT_VEC4_ARB
		else if ( en == GL_FLOAT_VEC4_ARB ) ostr << "GL_FLOAT_VEC4_ARB";
	#endif
	#ifdef GL_INT_VEC2_ARB
		else if ( en == GL_INT_VEC2_ARB ) ostr << "GL_INT_VEC2_ARB";
	#endif
	#ifdef GL_INT_VEC3_ARB
		else if ( en == GL_INT_VEC3_ARB ) ostr << "GL_INT_VEC3_ARB";
	#endif
	#ifdef GL_INT_VEC4_ARB
		else if ( en == GL_INT_VEC4_ARB ) ostr << "GL_INT_VEC4_ARB";
	#endif
	#ifdef GL_BOOL_ARB
		else if ( en == GL_BOOL_ARB ) ostr << "GL_BOOL_ARB";
	#endif
	#ifdef GL_BOOL_VEC2_ARB
		else if ( en == GL_BOOL_VEC2_ARB ) ostr << "GL_BOOL_VEC2_ARB";
	#endif
	#ifdef GL_BOOL_VEC3_ARB
		else if ( en == GL_BOOL_VEC3_ARB ) ostr << "GL_BOOL_VEC3_ARB";
	#endif
	#ifdef GL_BOOL_VEC4_ARB
		else if ( en == GL_BOOL_VEC4_ARB ) ostr << "GL_BOOL_VEC4_ARB";
	#endif
	#ifdef GL_FLOAT_MAT2_ARB
		else if ( en == GL_FLOAT_MAT2_ARB ) ostr << "GL_FLOAT_MAT2_ARB";
	#endif
	#ifdef GL_FLOAT_MAT3_ARB
		else if ( en == GL_FLOAT_MAT3_ARB ) ostr << "GL_FLOAT_MAT3_ARB";
	#endif
	#ifdef GL_FLOAT_MAT4_ARB
		else if ( en == GL_FLOAT_MAT4_ARB ) ostr << "GL_FLOAT_MAT4_ARB";
	#endif
	#ifdef GL_SAMPLER_1D_ARB
		else if ( en == GL_SAMPLER_1D_ARB ) ostr << "GL_SAMPLER_1D_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_ARB
		else if ( en == GL_SAMPLER_2D_ARB ) ostr << "GL_SAMPLER_2D_ARB";
	#endif
	#ifdef GL_SAMPLER_3D_ARB
		else if ( en == GL_SAMPLER_3D_ARB ) ostr << "GL_SAMPLER_3D_ARB";
	#endif
	#ifdef GL_SAMPLER_CUBE_ARB
		else if ( en == GL_SAMPLER_CUBE_ARB ) ostr << "GL_SAMPLER_CUBE_ARB";
	#endif
	#ifdef GL_SAMPLER_1D_SHADOW_ARB
		else if ( en == GL_SAMPLER_1D_SHADOW_ARB ) ostr << "GL_SAMPLER_1D_SHADOW_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_SHADOW_ARB
		else if ( en == GL_SAMPLER_2D_SHADOW_ARB ) ostr << "GL_SAMPLER_2D_SHADOW_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_RECT_ARB
		else if ( en == GL_SAMPLER_2D_RECT_ARB ) ostr << "GL_SAMPLER_2D_RECT_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_RECT_SHADOW_ARB
		else if ( en == GL_SAMPLER_2D_RECT_SHADOW_ARB ) ostr << "GL_SAMPLER_2D_RECT_SHADOW_ARB";
	#endif
	#ifdef GL_OBJECT_DELETE_STATUS_ARB
		else if ( en == GL_OBJECT_DELETE_STATUS_ARB ) ostr << "GL_OBJECT_DELETE_STATUS_ARB";
	#endif
	#ifdef GL_OBJECT_COMPILE_STATUS_ARB
		else if ( en == GL_OBJECT_COMPILE_STATUS_ARB ) ostr << "GL_OBJECT_COMPILE_STATUS_ARB";
	#endif
	#ifdef GL_OBJECT_LINK_STATUS_ARB
		else if ( en == GL_OBJECT_LINK_STATUS_ARB ) ostr << "GL_OBJECT_LINK_STATUS_ARB";
	#endif
	#ifdef GL_OBJECT_VALIDATE_STATUS_ARB
		else if ( en == GL_OBJECT_VALIDATE_STATUS_ARB ) ostr << "GL_OBJECT_VALIDATE_STATUS_ARB";
	#endif
	#ifdef GL_OBJECT_INFO_LOG_LENGTH_ARB
		else if ( en == GL_OBJECT_INFO_LOG_LENGTH_ARB ) ostr << "GL_OBJECT_INFO_LOG_LENGTH_ARB";
	#endif
	#ifdef GL_OBJECT_ATTACHED_OBJECTS_ARB
		else if ( en == GL_OBJECT_ATTACHED_OBJECTS_ARB ) ostr << "GL_OBJECT_ATTACHED_OBJECTS_ARB";
	#endif
	#ifdef GL_OBJECT_ACTIVE_UNIFORMS_ARB
		else if ( en == GL_OBJECT_ACTIVE_UNIFORMS_ARB ) ostr << "GL_OBJECT_ACTIVE_UNIFORMS_ARB";
	#endif
	#ifdef GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB
		else if ( en == GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB ) ostr << "GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB";
	#endif
	#ifdef GL_OBJECT_SHADER_SOURCE_LENGTH_ARB
		else if ( en == GL_OBJECT_SHADER_SOURCE_LENGTH_ARB ) ostr << "GL_OBJECT_SHADER_SOURCE_LENGTH_ARB";
	#endif
	#ifdef GL_SHADER_STORAGE_BARRIER_BIT
		else if ( en == GL_SHADER_STORAGE_BARRIER_BIT ) ostr << "GL_SHADER_STORAGE_BARRIER_BIT";
	#endif
	#ifdef GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES
		else if ( en == GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES ) ostr << "GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES";
	#endif
	#ifdef GL_SHADER_STORAGE_BUFFER
		else if ( en == GL_SHADER_STORAGE_BUFFER ) ostr << "GL_SHADER_STORAGE_BUFFER";
	#endif
	#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
		else if ( en == GL_SHADER_STORAGE_BUFFER_BINDING ) ostr << "GL_SHADER_STORAGE_BUFFER_BINDING";
	#endif
	#ifdef GL_SHADER_STORAGE_BUFFER_START
		else if ( en == GL_SHADER_STORAGE_BUFFER_START ) ostr << "GL_SHADER_STORAGE_BUFFER_START";
	#endif
	#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
		else if ( en == GL_SHADER_STORAGE_BUFFER_SIZE ) ostr << "GL_SHADER_STORAGE_BUFFER_SIZE";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS
		else if ( en == GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS ) ostr << "GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS";
	#endif
	#ifdef GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS
		else if ( en == GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS ) ostr << "GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS";
	#endif
	#ifdef GL_MAX_SHADER_STORAGE_BLOCK_SIZE
		else if ( en == GL_MAX_SHADER_STORAGE_BLOCK_SIZE ) ostr << "GL_MAX_SHADER_STORAGE_BLOCK_SIZE";
	#endif
	#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
		else if ( en == GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT ) ostr << "GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT";
	#endif
	#ifdef GL_ACTIVE_SUBROUTINES
		else if ( en == GL_ACTIVE_SUBROUTINES ) ostr << "GL_ACTIVE_SUBROUTINES";
	#endif
	#ifdef GL_ACTIVE_SUBROUTINE_UNIFORMS
		else if ( en == GL_ACTIVE_SUBROUTINE_UNIFORMS ) ostr << "GL_ACTIVE_SUBROUTINE_UNIFORMS";
	#endif
	#ifdef GL_MAX_SUBROUTINES
		else if ( en == GL_MAX_SUBROUTINES ) ostr << "GL_MAX_SUBROUTINES";
	#endif
	#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
		else if ( en == GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS ) ostr << "GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS";
	#endif
	#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS
		else if ( en == GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS ) ostr << "GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS";
	#endif
	#ifdef GL_ACTIVE_SUBROUTINE_MAX_LENGTH
		else if ( en == GL_ACTIVE_SUBROUTINE_MAX_LENGTH ) ostr << "GL_ACTIVE_SUBROUTINE_MAX_LENGTH";
	#endif
	#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH
		else if ( en == GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH ) ostr << "GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH";
	#endif
	#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
		else if ( en == GL_NUM_COMPATIBLE_SUBROUTINES ) ostr << "GL_NUM_COMPATIBLE_SUBROUTINES";
	#endif
	#ifdef GL_COMPATIBLE_SUBROUTINES
		else if ( en == GL_COMPATIBLE_SUBROUTINES ) ostr << "GL_COMPATIBLE_SUBROUTINES";
	#endif
	#ifdef GL_SHADING_LANGUAGE_VERSION_ARB
		else if ( en == GL_SHADING_LANGUAGE_VERSION_ARB ) ostr << "GL_SHADING_LANGUAGE_VERSION_ARB";
	#endif
	#ifdef GL_SHADER_INCLUDE_ARB
		else if ( en == GL_SHADER_INCLUDE_ARB ) ostr << "GL_SHADER_INCLUDE_ARB";
	#endif
	#ifdef GL_NAMED_STRING_LENGTH_ARB
		else if ( en == GL_NAMED_STRING_LENGTH_ARB ) ostr << "GL_NAMED_STRING_LENGTH_ARB";
	#endif
	#ifdef GL_NAMED_STRING_TYPE_ARB
		else if ( en == GL_NAMED_STRING_TYPE_ARB ) ostr << "GL_NAMED_STRING_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPARE_MODE_ARB
		else if ( en == GL_TEXTURE_COMPARE_MODE_ARB ) ostr << "GL_TEXTURE_COMPARE_MODE_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPARE_FUNC_ARB
		else if ( en == GL_TEXTURE_COMPARE_FUNC_ARB ) ostr << "GL_TEXTURE_COMPARE_FUNC_ARB";
	#endif
	#ifdef GL_COMPARE_R_TO_TEXTURE_ARB
		else if ( en == GL_COMPARE_R_TO_TEXTURE_ARB ) ostr << "GL_COMPARE_R_TO_TEXTURE_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPARE_FAIL_VALUE_ARB
		else if ( en == GL_TEXTURE_COMPARE_FAIL_VALUE_ARB ) ostr << "GL_TEXTURE_COMPARE_FAIL_VALUE_ARB";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_X_ARB
		else if ( en == GL_VIRTUAL_PAGE_SIZE_X_ARB ) ostr << "GL_VIRTUAL_PAGE_SIZE_X_ARB";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_Y_ARB
		else if ( en == GL_VIRTUAL_PAGE_SIZE_Y_ARB ) ostr << "GL_VIRTUAL_PAGE_SIZE_Y_ARB";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_Z_ARB
		else if ( en == GL_VIRTUAL_PAGE_SIZE_Z_ARB ) ostr << "GL_VIRTUAL_PAGE_SIZE_Z_ARB";
	#endif
	#ifdef GL_MAX_SPARSE_TEXTURE_SIZE_ARB
		else if ( en == GL_MAX_SPARSE_TEXTURE_SIZE_ARB ) ostr << "GL_MAX_SPARSE_TEXTURE_SIZE_ARB";
	#endif
	#ifdef GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB
		else if ( en == GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB ) ostr << "GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB";
	#endif
	#ifdef GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB
		else if ( en == GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB ) ostr << "GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB";
	#endif
	#ifdef GL_TEXTURE_SPARSE_ARB
		else if ( en == GL_TEXTURE_SPARSE_ARB ) ostr << "GL_TEXTURE_SPARSE_ARB";
	#endif
	#ifdef GL_VIRTUAL_PAGE_SIZE_INDEX_ARB
		else if ( en == GL_VIRTUAL_PAGE_SIZE_INDEX_ARB ) ostr << "GL_VIRTUAL_PAGE_SIZE_INDEX_ARB";
	#endif
	#ifdef GL_NUM_VIRTUAL_PAGE_SIZES_ARB
		else if ( en == GL_NUM_VIRTUAL_PAGE_SIZES_ARB ) ostr << "GL_NUM_VIRTUAL_PAGE_SIZES_ARB";
	#endif
	#ifdef GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB
		else if ( en == GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB ) ostr << "GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB";
	#endif
	#ifdef GL_NUM_SPARSE_LEVELS_ARB
		else if ( en == GL_NUM_SPARSE_LEVELS_ARB ) ostr << "GL_NUM_SPARSE_LEVELS_ARB";
	#endif
	#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
		else if ( en == GL_DEPTH_STENCIL_TEXTURE_MODE ) ostr << "GL_DEPTH_STENCIL_TEXTURE_MODE";
	#endif
	#ifdef GL_SYNC_FLUSH_COMMANDS_BIT
		else if ( en == GL_SYNC_FLUSH_COMMANDS_BIT ) ostr << "GL_SYNC_FLUSH_COMMANDS_BIT";
	#endif
	#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
		else if ( en == GL_MAX_SERVER_WAIT_TIMEOUT ) ostr << "GL_MAX_SERVER_WAIT_TIMEOUT";
	#endif
	#ifdef GL_OBJECT_TYPE
		else if ( en == GL_OBJECT_TYPE ) ostr << "GL_OBJECT_TYPE";
	#endif
	#ifdef GL_SYNC_CONDITION
		else if ( en == GL_SYNC_CONDITION ) ostr << "GL_SYNC_CONDITION";
	#endif
	#ifdef GL_SYNC_STATUS
		else if ( en == GL_SYNC_STATUS ) ostr << "GL_SYNC_STATUS";
	#endif
	#ifdef GL_SYNC_FLAGS
		else if ( en == GL_SYNC_FLAGS ) ostr << "GL_SYNC_FLAGS";
	#endif
	#ifdef GL_SYNC_FENCE
		else if ( en == GL_SYNC_FENCE ) ostr << "GL_SYNC_FENCE";
	#endif
	#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
		else if ( en == GL_SYNC_GPU_COMMANDS_COMPLETE ) ostr << "GL_SYNC_GPU_COMMANDS_COMPLETE";
	#endif
	#ifdef GL_UNSIGNALED
		else if ( en == GL_UNSIGNALED ) ostr << "GL_UNSIGNALED";
	#endif
	#ifdef GL_SIGNALED
		else if ( en == GL_SIGNALED ) ostr << "GL_SIGNALED";
	#endif
	#ifdef GL_ALREADY_SIGNALED
		else if ( en == GL_ALREADY_SIGNALED ) ostr << "GL_ALREADY_SIGNALED";
	#endif
	#ifdef GL_TIMEOUT_EXPIRED
		else if ( en == GL_TIMEOUT_EXPIRED ) ostr << "GL_TIMEOUT_EXPIRED";
	#endif
	#ifdef GL_CONDITION_SATISFIED
		else if ( en == GL_CONDITION_SATISFIED ) ostr << "GL_CONDITION_SATISFIED";
	#endif
	#ifdef GL_WAIT_FAILED
		else if ( en == GL_WAIT_FAILED ) ostr << "GL_WAIT_FAILED";
	#endif
	#ifdef GL_TIMEOUT_IGNORED
		else if ( en == GL_TIMEOUT_IGNORED ) ostr << "GL_TIMEOUT_IGNORED";
	#endif
	#ifdef GL_PATCHES
		else if ( en == GL_PATCHES ) ostr << "GL_PATCHES";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
		else if ( en == GL_MAX_TESS_CONTROL_INPUT_COMPONENTS ) ostr << "GL_MAX_TESS_CONTROL_INPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
		else if ( en == GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS ) ostr << "GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_PATCH_VERTICES
		else if ( en == GL_PATCH_VERTICES ) ostr << "GL_PATCH_VERTICES";
	#endif
	#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
		else if ( en == GL_PATCH_DEFAULT_INNER_LEVEL ) ostr << "GL_PATCH_DEFAULT_INNER_LEVEL";
	#endif
	#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
		else if ( en == GL_PATCH_DEFAULT_OUTER_LEVEL ) ostr << "GL_PATCH_DEFAULT_OUTER_LEVEL";
	#endif
	#ifdef GL_TESS_CONTROL_OUTPUT_VERTICES
		else if ( en == GL_TESS_CONTROL_OUTPUT_VERTICES ) ostr << "GL_TESS_CONTROL_OUTPUT_VERTICES";
	#endif
	#ifdef GL_TESS_GEN_MODE
		else if ( en == GL_TESS_GEN_MODE ) ostr << "GL_TESS_GEN_MODE";
	#endif
	#ifdef GL_TESS_GEN_SPACING
		else if ( en == GL_TESS_GEN_SPACING ) ostr << "GL_TESS_GEN_SPACING";
	#endif
	#ifdef GL_TESS_GEN_VERTEX_ORDER
		else if ( en == GL_TESS_GEN_VERTEX_ORDER ) ostr << "GL_TESS_GEN_VERTEX_ORDER";
	#endif
	#ifdef GL_TESS_GEN_POINT_MODE
		else if ( en == GL_TESS_GEN_POINT_MODE ) ostr << "GL_TESS_GEN_POINT_MODE";
	#endif
	#ifdef GL_ISOLINES
		else if ( en == GL_ISOLINES ) ostr << "GL_ISOLINES";
	#endif
	#ifdef GL_FRACTIONAL_ODD
		else if ( en == GL_FRACTIONAL_ODD ) ostr << "GL_FRACTIONAL_ODD";
	#endif
	#ifdef GL_FRACTIONAL_EVEN
		else if ( en == GL_FRACTIONAL_EVEN ) ostr << "GL_FRACTIONAL_EVEN";
	#endif
	#ifdef GL_MAX_PATCH_VERTICES
		else if ( en == GL_MAX_PATCH_VERTICES ) ostr << "GL_MAX_PATCH_VERTICES";
	#endif
	#ifdef GL_MAX_TESS_GEN_LEVEL
		else if ( en == GL_MAX_TESS_GEN_LEVEL ) ostr << "GL_MAX_TESS_GEN_LEVEL";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS ) ostr << "GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS ) ostr << "GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
		else if ( en == GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS ) ostr << "GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS ) ostr << "GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_PATCH_COMPONENTS
		else if ( en == GL_MAX_TESS_PATCH_COMPONENTS ) ostr << "GL_MAX_TESS_PATCH_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS ) ostr << "GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
		else if ( en == GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS ) ostr << "GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS";
	#endif
	#ifdef GL_TESS_EVALUATION_SHADER
		else if ( en == GL_TESS_EVALUATION_SHADER ) ostr << "GL_TESS_EVALUATION_SHADER";
	#endif
	#ifdef GL_TESS_CONTROL_SHADER
		else if ( en == GL_TESS_CONTROL_SHADER ) ostr << "GL_TESS_CONTROL_SHADER";
	#endif
	#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
		else if ( en == GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS ) ostr << "GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
		else if ( en == GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS ) ostr << "GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_CLAMP_TO_BORDER_ARB
		else if ( en == GL_CLAMP_TO_BORDER_ARB ) ostr << "GL_CLAMP_TO_BORDER_ARB";
	#endif
	#ifdef GL_TEXTURE_BUFFER_ARB
		else if ( en == GL_TEXTURE_BUFFER_ARB ) ostr << "GL_TEXTURE_BUFFER_ARB";
	#endif
	#ifdef GL_MAX_TEXTURE_BUFFER_SIZE_ARB
		else if ( en == GL_MAX_TEXTURE_BUFFER_SIZE_ARB ) ostr << "GL_MAX_TEXTURE_BUFFER_SIZE_ARB";
	#endif
	#ifdef GL_TEXTURE_BINDING_BUFFER_ARB
		else if ( en == GL_TEXTURE_BINDING_BUFFER_ARB ) ostr << "GL_TEXTURE_BINDING_BUFFER_ARB";
	#endif
	#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB
		else if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB ) ostr << "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB";
	#endif
	#ifdef GL_TEXTURE_BUFFER_FORMAT_ARB
		else if ( en == GL_TEXTURE_BUFFER_FORMAT_ARB ) ostr << "GL_TEXTURE_BUFFER_FORMAT_ARB";
	#endif
	#ifdef GL_TEXTURE_BUFFER_OFFSET
		else if ( en == GL_TEXTURE_BUFFER_OFFSET ) ostr << "GL_TEXTURE_BUFFER_OFFSET";
	#endif
	#ifdef GL_TEXTURE_BUFFER_SIZE
		else if ( en == GL_TEXTURE_BUFFER_SIZE ) ostr << "GL_TEXTURE_BUFFER_SIZE";
	#endif
	#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
		else if ( en == GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT ) ostr << "GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT";
	#endif
	#ifdef GL_COMPRESSED_ALPHA_ARB
		else if ( en == GL_COMPRESSED_ALPHA_ARB ) ostr << "GL_COMPRESSED_ALPHA_ARB";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_ARB
		else if ( en == GL_COMPRESSED_LUMINANCE_ARB ) ostr << "GL_COMPRESSED_LUMINANCE_ARB";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_ARB
		else if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_ARB ) ostr << "GL_COMPRESSED_LUMINANCE_ALPHA_ARB";
	#endif
	#ifdef GL_COMPRESSED_INTENSITY_ARB
		else if ( en == GL_COMPRESSED_INTENSITY_ARB ) ostr << "GL_COMPRESSED_INTENSITY_ARB";
	#endif
	#ifdef GL_COMPRESSED_RGB_ARB
		else if ( en == GL_COMPRESSED_RGB_ARB ) ostr << "GL_COMPRESSED_RGB_ARB";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ARB
		else if ( en == GL_COMPRESSED_RGBA_ARB ) ostr << "GL_COMPRESSED_RGBA_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPRESSION_HINT_ARB
		else if ( en == GL_TEXTURE_COMPRESSION_HINT_ARB ) ostr << "GL_TEXTURE_COMPRESSION_HINT_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB
		else if ( en == GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB ) ostr << "GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB";
	#endif
	#ifdef GL_TEXTURE_COMPRESSED_ARB
		else if ( en == GL_TEXTURE_COMPRESSED_ARB ) ostr << "GL_TEXTURE_COMPRESSED_ARB";
	#endif
	#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB
		else if ( en == GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB ) ostr << "GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB";
	#endif
	#ifdef GL_COMPRESSED_TEXTURE_FORMATS_ARB
		else if ( en == GL_COMPRESSED_TEXTURE_FORMATS_ARB ) ostr << "GL_COMPRESSED_TEXTURE_FORMATS_ARB";
	#endif
	#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM_ARB
		else if ( en == GL_COMPRESSED_RGBA_BPTC_UNORM_ARB ) ostr << "GL_COMPRESSED_RGBA_BPTC_UNORM_ARB";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB ) ostr << "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB";
	#endif
	#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB
		else if ( en == GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB ) ostr << "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB";
	#endif
	#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB
		else if ( en == GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB ) ostr << "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB";
	#endif
	#ifdef GL_COMPRESSED_RED_RGTC1
		else if ( en == GL_COMPRESSED_RED_RGTC1 ) ostr << "GL_COMPRESSED_RED_RGTC1";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
		else if ( en == GL_COMPRESSED_SIGNED_RED_RGTC1 ) ostr << "GL_COMPRESSED_SIGNED_RED_RGTC1";
	#endif
	#ifdef GL_COMPRESSED_RG_RGTC2
		else if ( en == GL_COMPRESSED_RG_RGTC2 ) ostr << "GL_COMPRESSED_RG_RGTC2";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
		else if ( en == GL_COMPRESSED_SIGNED_RG_RGTC2 ) ostr << "GL_COMPRESSED_SIGNED_RG_RGTC2";
	#endif
	#ifdef GL_NORMAL_MAP_ARB
		else if ( en == GL_NORMAL_MAP_ARB ) ostr << "GL_NORMAL_MAP_ARB";
	#endif
	#ifdef GL_REFLECTION_MAP_ARB
		else if ( en == GL_REFLECTION_MAP_ARB ) ostr << "GL_REFLECTION_MAP_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_ARB";
	#endif
	#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARB
		else if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARB ) ostr << "GL_TEXTURE_BINDING_CUBE_MAP_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARB
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARB ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP_ARB";
	#endif
	#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB
		else if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB ) ostr << "GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_ARRAY_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB ) ostr << "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_ARB ) ostr << "GL_SAMPLER_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB
		else if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB ) ostr << "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB";
	#endif
	#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB ) ostr << "GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB
		else if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB ) ostr << "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB";
	#endif
	#ifdef GL_SUBTRACT_ARB
		else if ( en == GL_SUBTRACT_ARB ) ostr << "GL_SUBTRACT_ARB";
	#endif
	#ifdef GL_COMBINE_ARB
		else if ( en == GL_COMBINE_ARB ) ostr << "GL_COMBINE_ARB";
	#endif
	#ifdef GL_COMBINE_RGB_ARB
		else if ( en == GL_COMBINE_RGB_ARB ) ostr << "GL_COMBINE_RGB_ARB";
	#endif
	#ifdef GL_COMBINE_ALPHA_ARB
		else if ( en == GL_COMBINE_ALPHA_ARB ) ostr << "GL_COMBINE_ALPHA_ARB";
	#endif
	#ifdef GL_RGB_SCALE_ARB
		else if ( en == GL_RGB_SCALE_ARB ) ostr << "GL_RGB_SCALE_ARB";
	#endif
	#ifdef GL_ADD_SIGNED_ARB
		else if ( en == GL_ADD_SIGNED_ARB ) ostr << "GL_ADD_SIGNED_ARB";
	#endif
	#ifdef GL_INTERPOLATE_ARB
		else if ( en == GL_INTERPOLATE_ARB ) ostr << "GL_INTERPOLATE_ARB";
	#endif
	#ifdef GL_CONSTANT_ARB
		else if ( en == GL_CONSTANT_ARB ) ostr << "GL_CONSTANT_ARB";
	#endif
	#ifdef GL_PRIMARY_COLOR_ARB
		else if ( en == GL_PRIMARY_COLOR_ARB ) ostr << "GL_PRIMARY_COLOR_ARB";
	#endif
	#ifdef GL_PREVIOUS_ARB
		else if ( en == GL_PREVIOUS_ARB ) ostr << "GL_PREVIOUS_ARB";
	#endif
	#ifdef GL_SOURCE0_RGB_ARB
		else if ( en == GL_SOURCE0_RGB_ARB ) ostr << "GL_SOURCE0_RGB_ARB";
	#endif
	#ifdef GL_SOURCE1_RGB_ARB
		else if ( en == GL_SOURCE1_RGB_ARB ) ostr << "GL_SOURCE1_RGB_ARB";
	#endif
	#ifdef GL_SOURCE2_RGB_ARB
		else if ( en == GL_SOURCE2_RGB_ARB ) ostr << "GL_SOURCE2_RGB_ARB";
	#endif
	#ifdef GL_SOURCE0_ALPHA_ARB
		else if ( en == GL_SOURCE0_ALPHA_ARB ) ostr << "GL_SOURCE0_ALPHA_ARB";
	#endif
	#ifdef GL_SOURCE1_ALPHA_ARB
		else if ( en == GL_SOURCE1_ALPHA_ARB ) ostr << "GL_SOURCE1_ALPHA_ARB";
	#endif
	#ifdef GL_SOURCE2_ALPHA_ARB
		else if ( en == GL_SOURCE2_ALPHA_ARB ) ostr << "GL_SOURCE2_ALPHA_ARB";
	#endif
	#ifdef GL_OPERAND0_RGB_ARB
		else if ( en == GL_OPERAND0_RGB_ARB ) ostr << "GL_OPERAND0_RGB_ARB";
	#endif
	#ifdef GL_OPERAND1_RGB_ARB
		else if ( en == GL_OPERAND1_RGB_ARB ) ostr << "GL_OPERAND1_RGB_ARB";
	#endif
	#ifdef GL_OPERAND2_RGB_ARB
		else if ( en == GL_OPERAND2_RGB_ARB ) ostr << "GL_OPERAND2_RGB_ARB";
	#endif
	#ifdef GL_OPERAND0_ALPHA_ARB
		else if ( en == GL_OPERAND0_ALPHA_ARB ) ostr << "GL_OPERAND0_ALPHA_ARB";
	#endif
	#ifdef GL_OPERAND1_ALPHA_ARB
		else if ( en == GL_OPERAND1_ALPHA_ARB ) ostr << "GL_OPERAND1_ALPHA_ARB";
	#endif
	#ifdef GL_OPERAND2_ALPHA_ARB
		else if ( en == GL_OPERAND2_ALPHA_ARB ) ostr << "GL_OPERAND2_ALPHA_ARB";
	#endif
	#ifdef GL_DOT3_RGB_ARB
		else if ( en == GL_DOT3_RGB_ARB ) ostr << "GL_DOT3_RGB_ARB";
	#endif
	#ifdef GL_DOT3_RGBA_ARB
		else if ( en == GL_DOT3_RGBA_ARB ) ostr << "GL_DOT3_RGBA_ARB";
	#endif
	#ifdef GL_RGBA32F_ARB
		else if ( en == GL_RGBA32F_ARB ) ostr << "GL_RGBA32F_ARB";
	#endif
	#ifdef GL_RGB32F_ARB
		else if ( en == GL_RGB32F_ARB ) ostr << "GL_RGB32F_ARB";
	#endif
	#ifdef GL_ALPHA32F_ARB
		else if ( en == GL_ALPHA32F_ARB ) ostr << "GL_ALPHA32F_ARB";
	#endif
	#ifdef GL_INTENSITY32F_ARB
		else if ( en == GL_INTENSITY32F_ARB ) ostr << "GL_INTENSITY32F_ARB";
	#endif
	#ifdef GL_LUMINANCE32F_ARB
		else if ( en == GL_LUMINANCE32F_ARB ) ostr << "GL_LUMINANCE32F_ARB";
	#endif
	#ifdef GL_LUMINANCE_ALPHA32F_ARB
		else if ( en == GL_LUMINANCE_ALPHA32F_ARB ) ostr << "GL_LUMINANCE_ALPHA32F_ARB";
	#endif
	#ifdef GL_RGBA16F_ARB
		else if ( en == GL_RGBA16F_ARB ) ostr << "GL_RGBA16F_ARB";
	#endif
	#ifdef GL_RGB16F_ARB
		else if ( en == GL_RGB16F_ARB ) ostr << "GL_RGB16F_ARB";
	#endif
	#ifdef GL_ALPHA16F_ARB
		else if ( en == GL_ALPHA16F_ARB ) ostr << "GL_ALPHA16F_ARB";
	#endif
	#ifdef GL_INTENSITY16F_ARB
		else if ( en == GL_INTENSITY16F_ARB ) ostr << "GL_INTENSITY16F_ARB";
	#endif
	#ifdef GL_LUMINANCE16F_ARB
		else if ( en == GL_LUMINANCE16F_ARB ) ostr << "GL_LUMINANCE16F_ARB";
	#endif
	#ifdef GL_LUMINANCE_ALPHA16F_ARB
		else if ( en == GL_LUMINANCE_ALPHA16F_ARB ) ostr << "GL_LUMINANCE_ALPHA16F_ARB";
	#endif
	#ifdef GL_TEXTURE_RED_TYPE_ARB
		else if ( en == GL_TEXTURE_RED_TYPE_ARB ) ostr << "GL_TEXTURE_RED_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_GREEN_TYPE_ARB
		else if ( en == GL_TEXTURE_GREEN_TYPE_ARB ) ostr << "GL_TEXTURE_GREEN_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_BLUE_TYPE_ARB
		else if ( en == GL_TEXTURE_BLUE_TYPE_ARB ) ostr << "GL_TEXTURE_BLUE_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_ALPHA_TYPE_ARB
		else if ( en == GL_TEXTURE_ALPHA_TYPE_ARB ) ostr << "GL_TEXTURE_ALPHA_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_LUMINANCE_TYPE_ARB
		else if ( en == GL_TEXTURE_LUMINANCE_TYPE_ARB ) ostr << "GL_TEXTURE_LUMINANCE_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_INTENSITY_TYPE_ARB
		else if ( en == GL_TEXTURE_INTENSITY_TYPE_ARB ) ostr << "GL_TEXTURE_INTENSITY_TYPE_ARB";
	#endif
	#ifdef GL_TEXTURE_DEPTH_TYPE_ARB
		else if ( en == GL_TEXTURE_DEPTH_TYPE_ARB ) ostr << "GL_TEXTURE_DEPTH_TYPE_ARB";
	#endif
	#ifdef GL_UNSIGNED_NORMALIZED_ARB
		else if ( en == GL_UNSIGNED_NORMALIZED_ARB ) ostr << "GL_UNSIGNED_NORMALIZED_ARB";
	#endif
	#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB
		else if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB ) ostr << "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB
		else if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB ) ostr << "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB
		else if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB ) ostr << "GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB";
	#endif
	#ifdef GL_MIRROR_CLAMP_TO_EDGE
		else if ( en == GL_MIRROR_CLAMP_TO_EDGE ) ostr << "GL_MIRROR_CLAMP_TO_EDGE";
	#endif
	#ifdef GL_MIRRORED_REPEAT_ARB
		else if ( en == GL_MIRRORED_REPEAT_ARB ) ostr << "GL_MIRRORED_REPEAT_ARB";
	#endif
	#ifdef GL_SAMPLE_POSITION
		else if ( en == GL_SAMPLE_POSITION ) ostr << "GL_SAMPLE_POSITION";
	#endif
	#ifdef GL_SAMPLE_MASK
		else if ( en == GL_SAMPLE_MASK ) ostr << "GL_SAMPLE_MASK";
	#endif
	#ifdef GL_SAMPLE_MASK_VALUE
		else if ( en == GL_SAMPLE_MASK_VALUE ) ostr << "GL_SAMPLE_MASK_VALUE";
	#endif
	#ifdef GL_MAX_SAMPLE_MASK_WORDS
		else if ( en == GL_MAX_SAMPLE_MASK_WORDS ) ostr << "GL_MAX_SAMPLE_MASK_WORDS";
	#endif
	#ifdef GL_TEXTURE_2D_MULTISAMPLE
		else if ( en == GL_TEXTURE_2D_MULTISAMPLE ) ostr << "GL_TEXTURE_2D_MULTISAMPLE";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_MULTISAMPLE
		else if ( en == GL_PROXY_TEXTURE_2D_MULTISAMPLE ) ostr << "GL_PROXY_TEXTURE_2D_MULTISAMPLE";
	#endif
	#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_TEXTURE_2D_MULTISAMPLE_ARRAY ) ostr << "GL_TEXTURE_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY ) ostr << "GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
		else if ( en == GL_TEXTURE_BINDING_2D_MULTISAMPLE ) ostr << "GL_TEXTURE_BINDING_2D_MULTISAMPLE";
	#endif
	#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY ) ostr << "GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_TEXTURE_SAMPLES
		else if ( en == GL_TEXTURE_SAMPLES ) ostr << "GL_TEXTURE_SAMPLES";
	#endif
	#ifdef GL_TEXTURE_FIXED_SAMPLE_LOCATIONS
		else if ( en == GL_TEXTURE_FIXED_SAMPLE_LOCATIONS ) ostr << "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS";
	#endif
	#ifdef GL_SAMPLER_2D_MULTISAMPLE
		else if ( en == GL_SAMPLER_2D_MULTISAMPLE ) ostr << "GL_SAMPLER_2D_MULTISAMPLE";
	#endif
	#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
		else if ( en == GL_INT_SAMPLER_2D_MULTISAMPLE ) ostr << "GL_INT_SAMPLER_2D_MULTISAMPLE";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE";
	#endif
	#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_SAMPLER_2D_MULTISAMPLE_ARRAY ) ostr << "GL_SAMPLER_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY ) ostr << "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY";
	#endif
	#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
		else if ( en == GL_MAX_COLOR_TEXTURE_SAMPLES ) ostr << "GL_MAX_COLOR_TEXTURE_SAMPLES";
	#endif
	#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
		else if ( en == GL_MAX_DEPTH_TEXTURE_SAMPLES ) ostr << "GL_MAX_DEPTH_TEXTURE_SAMPLES";
	#endif
	#ifdef GL_MAX_INTEGER_SAMPLES
		else if ( en == GL_MAX_INTEGER_SAMPLES ) ostr << "GL_MAX_INTEGER_SAMPLES";
	#endif
	#ifdef GL_TEXTURE_RECTANGLE_ARB
		else if ( en == GL_TEXTURE_RECTANGLE_ARB ) ostr << "GL_TEXTURE_RECTANGLE_ARB";
	#endif
	#ifdef GL_TEXTURE_BINDING_RECTANGLE_ARB
		else if ( en == GL_TEXTURE_BINDING_RECTANGLE_ARB ) ostr << "GL_TEXTURE_BINDING_RECTANGLE_ARB";
	#endif
	#ifdef GL_PROXY_TEXTURE_RECTANGLE_ARB
		else if ( en == GL_PROXY_TEXTURE_RECTANGLE_ARB ) ostr << "GL_PROXY_TEXTURE_RECTANGLE_ARB";
	#endif
	#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB
		else if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB ) ostr << "GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_RECT_ARB
		else if ( en == GL_SAMPLER_2D_RECT_ARB ) ostr << "GL_SAMPLER_2D_RECT_ARB";
	#endif
	#ifdef GL_SAMPLER_2D_RECT_SHADOW_ARB
		else if ( en == GL_SAMPLER_2D_RECT_SHADOW_ARB ) ostr << "GL_SAMPLER_2D_RECT_SHADOW_ARB";
	#endif
	#ifdef GL_COMPRESSED_RED
		else if ( en == GL_COMPRESSED_RED ) ostr << "GL_COMPRESSED_RED";
	#endif
	#ifdef GL_COMPRESSED_RG
		else if ( en == GL_COMPRESSED_RG ) ostr << "GL_COMPRESSED_RG";
	#endif
	#ifdef GL_RG
		else if ( en == GL_RG ) ostr << "GL_RG";
	#endif
	#ifdef GL_RG_INTEGER
		else if ( en == GL_RG_INTEGER ) ostr << "GL_RG_INTEGER";
	#endif
	#ifdef GL_R8
		else if ( en == GL_R8 ) ostr << "GL_R8";
	#endif
	#ifdef GL_R16
		else if ( en == GL_R16 ) ostr << "GL_R16";
	#endif
	#ifdef GL_RG8
		else if ( en == GL_RG8 ) ostr << "GL_RG8";
	#endif
	#ifdef GL_RG16
		else if ( en == GL_RG16 ) ostr << "GL_RG16";
	#endif
	#ifdef GL_R16F
		else if ( en == GL_R16F ) ostr << "GL_R16F";
	#endif
	#ifdef GL_R32F
		else if ( en == GL_R32F ) ostr << "GL_R32F";
	#endif
	#ifdef GL_RG16F
		else if ( en == GL_RG16F ) ostr << "GL_RG16F";
	#endif
	#ifdef GL_RG32F
		else if ( en == GL_RG32F ) ostr << "GL_RG32F";
	#endif
	#ifdef GL_R8I
		else if ( en == GL_R8I ) ostr << "GL_R8I";
	#endif
	#ifdef GL_R8UI
		else if ( en == GL_R8UI ) ostr << "GL_R8UI";
	#endif
	#ifdef GL_R16I
		else if ( en == GL_R16I ) ostr << "GL_R16I";
	#endif
	#ifdef GL_R16UI
		else if ( en == GL_R16UI ) ostr << "GL_R16UI";
	#endif
	#ifdef GL_R32I
		else if ( en == GL_R32I ) ostr << "GL_R32I";
	#endif
	#ifdef GL_R32UI
		else if ( en == GL_R32UI ) ostr << "GL_R32UI";
	#endif
	#ifdef GL_RG8I
		else if ( en == GL_RG8I ) ostr << "GL_RG8I";
	#endif
	#ifdef GL_RG8UI
		else if ( en == GL_RG8UI ) ostr << "GL_RG8UI";
	#endif
	#ifdef GL_RG16I
		else if ( en == GL_RG16I ) ostr << "GL_RG16I";
	#endif
	#ifdef GL_RG16UI
		else if ( en == GL_RG16UI ) ostr << "GL_RG16UI";
	#endif
	#ifdef GL_RG32I
		else if ( en == GL_RG32I ) ostr << "GL_RG32I";
	#endif
	#ifdef GL_RG32UI
		else if ( en == GL_RG32UI ) ostr << "GL_RG32UI";
	#endif
	#ifdef GL_RGB10_A2UI
		else if ( en == GL_RGB10_A2UI ) ostr << "GL_RGB10_A2UI";
	#endif
	#ifdef GL_STENCIL_INDEX
		else if ( en == GL_STENCIL_INDEX ) ostr << "GL_STENCIL_INDEX";
	#endif
	#ifdef GL_STENCIL_INDEX8
		else if ( en == GL_STENCIL_INDEX8 ) ostr << "GL_STENCIL_INDEX8";
	#endif
	#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
		else if ( en == GL_TEXTURE_IMMUTABLE_FORMAT ) ostr << "GL_TEXTURE_IMMUTABLE_FORMAT";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_R
		else if ( en == GL_TEXTURE_SWIZZLE_R ) ostr << "GL_TEXTURE_SWIZZLE_R";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_G
		else if ( en == GL_TEXTURE_SWIZZLE_G ) ostr << "GL_TEXTURE_SWIZZLE_G";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_B
		else if ( en == GL_TEXTURE_SWIZZLE_B ) ostr << "GL_TEXTURE_SWIZZLE_B";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_A
		else if ( en == GL_TEXTURE_SWIZZLE_A ) ostr << "GL_TEXTURE_SWIZZLE_A";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_RGBA
		else if ( en == GL_TEXTURE_SWIZZLE_RGBA ) ostr << "GL_TEXTURE_SWIZZLE_RGBA";
	#endif
	#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
		else if ( en == GL_TEXTURE_VIEW_MIN_LEVEL ) ostr << "GL_TEXTURE_VIEW_MIN_LEVEL";
	#endif
	#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
		else if ( en == GL_TEXTURE_VIEW_NUM_LEVELS ) ostr << "GL_TEXTURE_VIEW_NUM_LEVELS";
	#endif
	#ifdef GL_TEXTURE_VIEW_MIN_LAYER
		else if ( en == GL_TEXTURE_VIEW_MIN_LAYER ) ostr << "GL_TEXTURE_VIEW_MIN_LAYER";
	#endif
	#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
		else if ( en == GL_TEXTURE_VIEW_NUM_LAYERS ) ostr << "GL_TEXTURE_VIEW_NUM_LAYERS";
	#endif
	#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
		else if ( en == GL_TEXTURE_IMMUTABLE_LEVELS ) ostr << "GL_TEXTURE_IMMUTABLE_LEVELS";
	#endif
	#ifdef GL_TIME_ELAPSED
		else if ( en == GL_TIME_ELAPSED ) ostr << "GL_TIME_ELAPSED";
	#endif
	#ifdef GL_TIMESTAMP
		else if ( en == GL_TIMESTAMP ) ostr << "GL_TIMESTAMP";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK
		else if ( en == GL_TRANSFORM_FEEDBACK ) ostr << "GL_TRANSFORM_FEEDBACK";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BINDING
		else if ( en == GL_TRANSFORM_FEEDBACK_BINDING ) ostr << "GL_TRANSFORM_FEEDBACK_BINDING";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_BUFFERS ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_BUFFERS";
	#endif
	#ifdef GL_MAX_VERTEX_STREAMS
		else if ( en == GL_MAX_VERTEX_STREAMS ) ostr << "GL_MAX_VERTEX_STREAMS";
	#endif
	#ifdef GL_TRANSPOSE_MODELVIEW_MATRIX_ARB
		else if ( en == GL_TRANSPOSE_MODELVIEW_MATRIX_ARB ) ostr << "GL_TRANSPOSE_MODELVIEW_MATRIX_ARB";
	#endif
	#ifdef GL_TRANSPOSE_PROJECTION_MATRIX_ARB
		else if ( en == GL_TRANSPOSE_PROJECTION_MATRIX_ARB ) ostr << "GL_TRANSPOSE_PROJECTION_MATRIX_ARB";
	#endif
	#ifdef GL_TRANSPOSE_TEXTURE_MATRIX_ARB
		else if ( en == GL_TRANSPOSE_TEXTURE_MATRIX_ARB ) ostr << "GL_TRANSPOSE_TEXTURE_MATRIX_ARB";
	#endif
	#ifdef GL_TRANSPOSE_COLOR_MATRIX_ARB
		else if ( en == GL_TRANSPOSE_COLOR_MATRIX_ARB ) ostr << "GL_TRANSPOSE_COLOR_MATRIX_ARB";
	#endif
	#ifdef GL_UNIFORM_BUFFER
		else if ( en == GL_UNIFORM_BUFFER ) ostr << "GL_UNIFORM_BUFFER";
	#endif
	#ifdef GL_UNIFORM_BUFFER_BINDING
		else if ( en == GL_UNIFORM_BUFFER_BINDING ) ostr << "GL_UNIFORM_BUFFER_BINDING";
	#endif
	#ifdef GL_UNIFORM_BUFFER_START
		else if ( en == GL_UNIFORM_BUFFER_START ) ostr << "GL_UNIFORM_BUFFER_START";
	#endif
	#ifdef GL_UNIFORM_BUFFER_SIZE
		else if ( en == GL_UNIFORM_BUFFER_SIZE ) ostr << "GL_UNIFORM_BUFFER_SIZE";
	#endif
	#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
		else if ( en == GL_MAX_VERTEX_UNIFORM_BLOCKS ) ostr << "GL_MAX_VERTEX_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
		else if ( en == GL_MAX_GEOMETRY_UNIFORM_BLOCKS ) ostr << "GL_MAX_GEOMETRY_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
		else if ( en == GL_MAX_FRAGMENT_UNIFORM_BLOCKS ) ostr << "GL_MAX_FRAGMENT_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
		else if ( en == GL_MAX_COMBINED_UNIFORM_BLOCKS ) ostr << "GL_MAX_COMBINED_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
		else if ( en == GL_MAX_UNIFORM_BUFFER_BINDINGS ) ostr << "GL_MAX_UNIFORM_BUFFER_BINDINGS";
	#endif
	#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
		else if ( en == GL_MAX_UNIFORM_BLOCK_SIZE ) ostr << "GL_MAX_UNIFORM_BLOCK_SIZE";
	#endif
	#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
		else if ( en == GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS ) ostr << "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS";
	#endif
	#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
		else if ( en == GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT ) ostr << "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT";
	#endif
	#ifdef GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH
		else if ( en == GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH ) ostr << "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH";
	#endif
	#ifdef GL_ACTIVE_UNIFORM_BLOCKS
		else if ( en == GL_ACTIVE_UNIFORM_BLOCKS ) ostr << "GL_ACTIVE_UNIFORM_BLOCKS";
	#endif
	#ifdef GL_UNIFORM_TYPE
		else if ( en == GL_UNIFORM_TYPE ) ostr << "GL_UNIFORM_TYPE";
	#endif
	#ifdef GL_UNIFORM_SIZE
		else if ( en == GL_UNIFORM_SIZE ) ostr << "GL_UNIFORM_SIZE";
	#endif
	#ifdef GL_UNIFORM_NAME_LENGTH
		else if ( en == GL_UNIFORM_NAME_LENGTH ) ostr << "GL_UNIFORM_NAME_LENGTH";
	#endif
	#ifdef GL_UNIFORM_BLOCK_INDEX
		else if ( en == GL_UNIFORM_BLOCK_INDEX ) ostr << "GL_UNIFORM_BLOCK_INDEX";
	#endif
	#ifdef GL_UNIFORM_OFFSET
		else if ( en == GL_UNIFORM_OFFSET ) ostr << "GL_UNIFORM_OFFSET";
	#endif
	#ifdef GL_UNIFORM_ARRAY_STRIDE
		else if ( en == GL_UNIFORM_ARRAY_STRIDE ) ostr << "GL_UNIFORM_ARRAY_STRIDE";
	#endif
	#ifdef GL_UNIFORM_MATRIX_STRIDE
		else if ( en == GL_UNIFORM_MATRIX_STRIDE ) ostr << "GL_UNIFORM_MATRIX_STRIDE";
	#endif
	#ifdef GL_UNIFORM_IS_ROW_MAJOR
		else if ( en == GL_UNIFORM_IS_ROW_MAJOR ) ostr << "GL_UNIFORM_IS_ROW_MAJOR";
	#endif
	#ifdef GL_UNIFORM_BLOCK_BINDING
		else if ( en == GL_UNIFORM_BLOCK_BINDING ) ostr << "GL_UNIFORM_BLOCK_BINDING";
	#endif
	#ifdef GL_UNIFORM_BLOCK_DATA_SIZE
		else if ( en == GL_UNIFORM_BLOCK_DATA_SIZE ) ostr << "GL_UNIFORM_BLOCK_DATA_SIZE";
	#endif
	#ifdef GL_UNIFORM_BLOCK_NAME_LENGTH
		else if ( en == GL_UNIFORM_BLOCK_NAME_LENGTH ) ostr << "GL_UNIFORM_BLOCK_NAME_LENGTH";
	#endif
	#ifdef GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS
		else if ( en == GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS ) ostr << "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS";
	#endif
	#ifdef GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES
		else if ( en == GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES ) ostr << "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER";
	#endif
	#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER
		else if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER ) ostr << "GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER";
	#endif
	#ifdef GL_INVALID_INDEX
		else if ( en == GL_INVALID_INDEX ) ostr << "GL_INVALID_INDEX";
	#endif
	#ifdef GL_BGRA
		else if ( en == GL_BGRA ) ostr << "GL_BGRA";
	#endif
	#ifdef GL_VERTEX_ARRAY_BINDING
		else if ( en == GL_VERTEX_ARRAY_BINDING ) ostr << "GL_VERTEX_ARRAY_BINDING";
	#endif
	#ifdef GL_VERTEX_ATTRIB_BINDING
		else if ( en == GL_VERTEX_ATTRIB_BINDING ) ostr << "GL_VERTEX_ATTRIB_BINDING";
	#endif
	#ifdef GL_VERTEX_ATTRIB_RELATIVE_OFFSET
		else if ( en == GL_VERTEX_ATTRIB_RELATIVE_OFFSET ) ostr << "GL_VERTEX_ATTRIB_RELATIVE_OFFSET";
	#endif
	#ifdef GL_VERTEX_BINDING_DIVISOR
		else if ( en == GL_VERTEX_BINDING_DIVISOR ) ostr << "GL_VERTEX_BINDING_DIVISOR";
	#endif
	#ifdef GL_VERTEX_BINDING_OFFSET
		else if ( en == GL_VERTEX_BINDING_OFFSET ) ostr << "GL_VERTEX_BINDING_OFFSET";
	#endif
	#ifdef GL_VERTEX_BINDING_STRIDE
		else if ( en == GL_VERTEX_BINDING_STRIDE ) ostr << "GL_VERTEX_BINDING_STRIDE";
	#endif
	#ifdef GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET
		else if ( en == GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET ) ostr << "GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET";
	#endif
	#ifdef GL_MAX_VERTEX_ATTRIB_BINDINGS
		else if ( en == GL_MAX_VERTEX_ATTRIB_BINDINGS ) ostr << "GL_MAX_VERTEX_ATTRIB_BINDINGS";
	#endif
	#ifdef GL_MODELVIEW0_ARB
		else if ( en == GL_MODELVIEW0_ARB ) ostr << "GL_MODELVIEW0_ARB";
	#endif
	#ifdef GL_MODELVIEW1_ARB
		else if ( en == GL_MODELVIEW1_ARB ) ostr << "GL_MODELVIEW1_ARB";
	#endif
	#ifdef GL_MAX_VERTEX_UNITS_ARB
		else if ( en == GL_MAX_VERTEX_UNITS_ARB ) ostr << "GL_MAX_VERTEX_UNITS_ARB";
	#endif
	#ifdef GL_ACTIVE_VERTEX_UNITS_ARB
		else if ( en == GL_ACTIVE_VERTEX_UNITS_ARB ) ostr << "GL_ACTIVE_VERTEX_UNITS_ARB";
	#endif
	#ifdef GL_WEIGHT_SUM_UNITY_ARB
		else if ( en == GL_WEIGHT_SUM_UNITY_ARB ) ostr << "GL_WEIGHT_SUM_UNITY_ARB";
	#endif
	#ifdef GL_VERTEX_BLEND_ARB
		else if ( en == GL_VERTEX_BLEND_ARB ) ostr << "GL_VERTEX_BLEND_ARB";
	#endif
	#ifdef GL_CURRENT_WEIGHT_ARB
		else if ( en == GL_CURRENT_WEIGHT_ARB ) ostr << "GL_CURRENT_WEIGHT_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_TYPE_ARB
		else if ( en == GL_WEIGHT_ARRAY_TYPE_ARB ) ostr << "GL_WEIGHT_ARRAY_TYPE_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_STRIDE_ARB
		else if ( en == GL_WEIGHT_ARRAY_STRIDE_ARB ) ostr << "GL_WEIGHT_ARRAY_STRIDE_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_SIZE_ARB
		else if ( en == GL_WEIGHT_ARRAY_SIZE_ARB ) ostr << "GL_WEIGHT_ARRAY_SIZE_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_POINTER_ARB
		else if ( en == GL_WEIGHT_ARRAY_POINTER_ARB ) ostr << "GL_WEIGHT_ARRAY_POINTER_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_ARB
		else if ( en == GL_WEIGHT_ARRAY_ARB ) ostr << "GL_WEIGHT_ARRAY_ARB";
	#endif
	#ifdef GL_MODELVIEW2_ARB
		else if ( en == GL_MODELVIEW2_ARB ) ostr << "GL_MODELVIEW2_ARB";
	#endif
	#ifdef GL_MODELVIEW3_ARB
		else if ( en == GL_MODELVIEW3_ARB ) ostr << "GL_MODELVIEW3_ARB";
	#endif
	#ifdef GL_MODELVIEW4_ARB
		else if ( en == GL_MODELVIEW4_ARB ) ostr << "GL_MODELVIEW4_ARB";
	#endif
	#ifdef GL_MODELVIEW5_ARB
		else if ( en == GL_MODELVIEW5_ARB ) ostr << "GL_MODELVIEW5_ARB";
	#endif
	#ifdef GL_MODELVIEW6_ARB
		else if ( en == GL_MODELVIEW6_ARB ) ostr << "GL_MODELVIEW6_ARB";
	#endif
	#ifdef GL_MODELVIEW7_ARB
		else if ( en == GL_MODELVIEW7_ARB ) ostr << "GL_MODELVIEW7_ARB";
	#endif
	#ifdef GL_MODELVIEW8_ARB
		else if ( en == GL_MODELVIEW8_ARB ) ostr << "GL_MODELVIEW8_ARB";
	#endif
	#ifdef GL_MODELVIEW9_ARB
		else if ( en == GL_MODELVIEW9_ARB ) ostr << "GL_MODELVIEW9_ARB";
	#endif
	#ifdef GL_MODELVIEW10_ARB
		else if ( en == GL_MODELVIEW10_ARB ) ostr << "GL_MODELVIEW10_ARB";
	#endif
	#ifdef GL_MODELVIEW11_ARB
		else if ( en == GL_MODELVIEW11_ARB ) ostr << "GL_MODELVIEW11_ARB";
	#endif
	#ifdef GL_MODELVIEW12_ARB
		else if ( en == GL_MODELVIEW12_ARB ) ostr << "GL_MODELVIEW12_ARB";
	#endif
	#ifdef GL_MODELVIEW13_ARB
		else if ( en == GL_MODELVIEW13_ARB ) ostr << "GL_MODELVIEW13_ARB";
	#endif
	#ifdef GL_MODELVIEW14_ARB
		else if ( en == GL_MODELVIEW14_ARB ) ostr << "GL_MODELVIEW14_ARB";
	#endif
	#ifdef GL_MODELVIEW15_ARB
		else if ( en == GL_MODELVIEW15_ARB ) ostr << "GL_MODELVIEW15_ARB";
	#endif
	#ifdef GL_MODELVIEW16_ARB
		else if ( en == GL_MODELVIEW16_ARB ) ostr << "GL_MODELVIEW16_ARB";
	#endif
	#ifdef GL_MODELVIEW17_ARB
		else if ( en == GL_MODELVIEW17_ARB ) ostr << "GL_MODELVIEW17_ARB";
	#endif
	#ifdef GL_MODELVIEW18_ARB
		else if ( en == GL_MODELVIEW18_ARB ) ostr << "GL_MODELVIEW18_ARB";
	#endif
	#ifdef GL_MODELVIEW19_ARB
		else if ( en == GL_MODELVIEW19_ARB ) ostr << "GL_MODELVIEW19_ARB";
	#endif
	#ifdef GL_MODELVIEW20_ARB
		else if ( en == GL_MODELVIEW20_ARB ) ostr << "GL_MODELVIEW20_ARB";
	#endif
	#ifdef GL_MODELVIEW21_ARB
		else if ( en == GL_MODELVIEW21_ARB ) ostr << "GL_MODELVIEW21_ARB";
	#endif
	#ifdef GL_MODELVIEW22_ARB
		else if ( en == GL_MODELVIEW22_ARB ) ostr << "GL_MODELVIEW22_ARB";
	#endif
	#ifdef GL_MODELVIEW23_ARB
		else if ( en == GL_MODELVIEW23_ARB ) ostr << "GL_MODELVIEW23_ARB";
	#endif
	#ifdef GL_MODELVIEW24_ARB
		else if ( en == GL_MODELVIEW24_ARB ) ostr << "GL_MODELVIEW24_ARB";
	#endif
	#ifdef GL_MODELVIEW25_ARB
		else if ( en == GL_MODELVIEW25_ARB ) ostr << "GL_MODELVIEW25_ARB";
	#endif
	#ifdef GL_MODELVIEW26_ARB
		else if ( en == GL_MODELVIEW26_ARB ) ostr << "GL_MODELVIEW26_ARB";
	#endif
	#ifdef GL_MODELVIEW27_ARB
		else if ( en == GL_MODELVIEW27_ARB ) ostr << "GL_MODELVIEW27_ARB";
	#endif
	#ifdef GL_MODELVIEW28_ARB
		else if ( en == GL_MODELVIEW28_ARB ) ostr << "GL_MODELVIEW28_ARB";
	#endif
	#ifdef GL_MODELVIEW29_ARB
		else if ( en == GL_MODELVIEW29_ARB ) ostr << "GL_MODELVIEW29_ARB";
	#endif
	#ifdef GL_MODELVIEW30_ARB
		else if ( en == GL_MODELVIEW30_ARB ) ostr << "GL_MODELVIEW30_ARB";
	#endif
	#ifdef GL_MODELVIEW31_ARB
		else if ( en == GL_MODELVIEW31_ARB ) ostr << "GL_MODELVIEW31_ARB";
	#endif
	#ifdef GL_BUFFER_SIZE_ARB
		else if ( en == GL_BUFFER_SIZE_ARB ) ostr << "GL_BUFFER_SIZE_ARB";
	#endif
	#ifdef GL_BUFFER_USAGE_ARB
		else if ( en == GL_BUFFER_USAGE_ARB ) ostr << "GL_BUFFER_USAGE_ARB";
	#endif
	#ifdef GL_ARRAY_BUFFER_ARB
		else if ( en == GL_ARRAY_BUFFER_ARB ) ostr << "GL_ARRAY_BUFFER_ARB";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BUFFER_ARB
		else if ( en == GL_ELEMENT_ARRAY_BUFFER_ARB ) ostr << "GL_ELEMENT_ARRAY_BUFFER_ARB";
	#endif
	#ifdef GL_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_VERTEX_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_VERTEX_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_VERTEX_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_NORMAL_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_NORMAL_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_NORMAL_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_COLOR_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_COLOR_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_COLOR_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_INDEX_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_INDEX_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_INDEX_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB";
	#endif
	#ifdef GL_READ_ONLY_ARB
		else if ( en == GL_READ_ONLY_ARB ) ostr << "GL_READ_ONLY_ARB";
	#endif
	#ifdef GL_WRITE_ONLY_ARB
		else if ( en == GL_WRITE_ONLY_ARB ) ostr << "GL_WRITE_ONLY_ARB";
	#endif
	#ifdef GL_READ_WRITE_ARB
		else if ( en == GL_READ_WRITE_ARB ) ostr << "GL_READ_WRITE_ARB";
	#endif
	#ifdef GL_BUFFER_ACCESS_ARB
		else if ( en == GL_BUFFER_ACCESS_ARB ) ostr << "GL_BUFFER_ACCESS_ARB";
	#endif
	#ifdef GL_BUFFER_MAPPED_ARB
		else if ( en == GL_BUFFER_MAPPED_ARB ) ostr << "GL_BUFFER_MAPPED_ARB";
	#endif
	#ifdef GL_BUFFER_MAP_POINTER_ARB
		else if ( en == GL_BUFFER_MAP_POINTER_ARB ) ostr << "GL_BUFFER_MAP_POINTER_ARB";
	#endif
	#ifdef GL_STREAM_DRAW_ARB
		else if ( en == GL_STREAM_DRAW_ARB ) ostr << "GL_STREAM_DRAW_ARB";
	#endif
	#ifdef GL_STREAM_READ_ARB
		else if ( en == GL_STREAM_READ_ARB ) ostr << "GL_STREAM_READ_ARB";
	#endif
	#ifdef GL_STREAM_COPY_ARB
		else if ( en == GL_STREAM_COPY_ARB ) ostr << "GL_STREAM_COPY_ARB";
	#endif
	#ifdef GL_STATIC_DRAW_ARB
		else if ( en == GL_STATIC_DRAW_ARB ) ostr << "GL_STATIC_DRAW_ARB";
	#endif
	#ifdef GL_STATIC_READ_ARB
		else if ( en == GL_STATIC_READ_ARB ) ostr << "GL_STATIC_READ_ARB";
	#endif
	#ifdef GL_STATIC_COPY_ARB
		else if ( en == GL_STATIC_COPY_ARB ) ostr << "GL_STATIC_COPY_ARB";
	#endif
	#ifdef GL_DYNAMIC_DRAW_ARB
		else if ( en == GL_DYNAMIC_DRAW_ARB ) ostr << "GL_DYNAMIC_DRAW_ARB";
	#endif
	#ifdef GL_DYNAMIC_READ_ARB
		else if ( en == GL_DYNAMIC_READ_ARB ) ostr << "GL_DYNAMIC_READ_ARB";
	#endif
	#ifdef GL_DYNAMIC_COPY_ARB
		else if ( en == GL_DYNAMIC_COPY_ARB ) ostr << "GL_DYNAMIC_COPY_ARB";
	#endif
	#ifdef GL_COLOR_SUM_ARB
		else if ( en == GL_COLOR_SUM_ARB ) ostr << "GL_COLOR_SUM_ARB";
	#endif
	#ifdef GL_VERTEX_PROGRAM_ARB
		else if ( en == GL_VERTEX_PROGRAM_ARB ) ostr << "GL_VERTEX_PROGRAM_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB";
	#endif
	#ifdef GL_CURRENT_VERTEX_ATTRIB_ARB
		else if ( en == GL_CURRENT_VERTEX_ATTRIB_ARB ) ostr << "GL_CURRENT_VERTEX_ATTRIB_ARB";
	#endif
	#ifdef GL_PROGRAM_LENGTH_ARB
		else if ( en == GL_PROGRAM_LENGTH_ARB ) ostr << "GL_PROGRAM_LENGTH_ARB";
	#endif
	#ifdef GL_PROGRAM_STRING_ARB
		else if ( en == GL_PROGRAM_STRING_ARB ) ostr << "GL_PROGRAM_STRING_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB
		else if ( en == GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB ) ostr << "GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_MATRICES_ARB
		else if ( en == GL_MAX_PROGRAM_MATRICES_ARB ) ostr << "GL_MAX_PROGRAM_MATRICES_ARB";
	#endif
	#ifdef GL_CURRENT_MATRIX_STACK_DEPTH_ARB
		else if ( en == GL_CURRENT_MATRIX_STACK_DEPTH_ARB ) ostr << "GL_CURRENT_MATRIX_STACK_DEPTH_ARB";
	#endif
	#ifdef GL_CURRENT_MATRIX_ARB
		else if ( en == GL_CURRENT_MATRIX_ARB ) ostr << "GL_CURRENT_MATRIX_ARB";
	#endif
	#ifdef GL_VERTEX_PROGRAM_POINT_SIZE_ARB
		else if ( en == GL_VERTEX_PROGRAM_POINT_SIZE_ARB ) ostr << "GL_VERTEX_PROGRAM_POINT_SIZE_ARB";
	#endif
	#ifdef GL_VERTEX_PROGRAM_TWO_SIDE_ARB
		else if ( en == GL_VERTEX_PROGRAM_TWO_SIDE_ARB ) ostr << "GL_VERTEX_PROGRAM_TWO_SIDE_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB";
	#endif
	#ifdef GL_PROGRAM_ERROR_POSITION_ARB
		else if ( en == GL_PROGRAM_ERROR_POSITION_ARB ) ostr << "GL_PROGRAM_ERROR_POSITION_ARB";
	#endif
	#ifdef GL_PROGRAM_BINDING_ARB
		else if ( en == GL_PROGRAM_BINDING_ARB ) ostr << "GL_PROGRAM_BINDING_ARB";
	#endif
	#ifdef GL_MAX_VERTEX_ATTRIBS_ARB
		else if ( en == GL_MAX_VERTEX_ATTRIBS_ARB ) ostr << "GL_MAX_VERTEX_ATTRIBS_ARB";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB ) ostr << "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB";
	#endif
	#ifdef GL_PROGRAM_ERROR_STRING_ARB
		else if ( en == GL_PROGRAM_ERROR_STRING_ARB ) ostr << "GL_PROGRAM_ERROR_STRING_ARB";
	#endif
	#ifdef GL_PROGRAM_FORMAT_ASCII_ARB
		else if ( en == GL_PROGRAM_FORMAT_ASCII_ARB ) ostr << "GL_PROGRAM_FORMAT_ASCII_ARB";
	#endif
	#ifdef GL_PROGRAM_FORMAT_ARB
		else if ( en == GL_PROGRAM_FORMAT_ARB ) ostr << "GL_PROGRAM_FORMAT_ARB";
	#endif
	#ifdef GL_PROGRAM_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB
		else if ( en == GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB ) ostr << "GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB";
	#endif
	#ifdef GL_PROGRAM_TEMPORARIES_ARB
		else if ( en == GL_PROGRAM_TEMPORARIES_ARB ) ostr << "GL_PROGRAM_TEMPORARIES_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_TEMPORARIES_ARB
		else if ( en == GL_MAX_PROGRAM_TEMPORARIES_ARB ) ostr << "GL_MAX_PROGRAM_TEMPORARIES_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_TEMPORARIES_ARB
		else if ( en == GL_PROGRAM_NATIVE_TEMPORARIES_ARB ) ostr << "GL_PROGRAM_NATIVE_TEMPORARIES_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB";
	#endif
	#ifdef GL_PROGRAM_PARAMETERS_ARB
		else if ( en == GL_PROGRAM_PARAMETERS_ARB ) ostr << "GL_PROGRAM_PARAMETERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_PARAMETERS_ARB
		else if ( en == GL_MAX_PROGRAM_PARAMETERS_ARB ) ostr << "GL_MAX_PROGRAM_PARAMETERS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_PARAMETERS_ARB
		else if ( en == GL_PROGRAM_NATIVE_PARAMETERS_ARB ) ostr << "GL_PROGRAM_NATIVE_PARAMETERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB";
	#endif
	#ifdef GL_PROGRAM_ATTRIBS_ARB
		else if ( en == GL_PROGRAM_ATTRIBS_ARB ) ostr << "GL_PROGRAM_ATTRIBS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_ATTRIBS_ARB
		else if ( en == GL_MAX_PROGRAM_ATTRIBS_ARB ) ostr << "GL_MAX_PROGRAM_ATTRIBS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_ATTRIBS_ARB
		else if ( en == GL_PROGRAM_NATIVE_ATTRIBS_ARB ) ostr << "GL_PROGRAM_NATIVE_ATTRIBS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB";
	#endif
	#ifdef GL_PROGRAM_ADDRESS_REGISTERS_ARB
		else if ( en == GL_PROGRAM_ADDRESS_REGISTERS_ARB ) ostr << "GL_PROGRAM_ADDRESS_REGISTERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB
		else if ( en == GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB ) ostr << "GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB";
	#endif
	#ifdef GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB
		else if ( en == GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB ) ostr << "GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB
		else if ( en == GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB ) ostr << "GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB
		else if ( en == GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB ) ostr << "GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB";
	#endif
	#ifdef GL_MAX_PROGRAM_ENV_PARAMETERS_ARB
		else if ( en == GL_MAX_PROGRAM_ENV_PARAMETERS_ARB ) ostr << "GL_MAX_PROGRAM_ENV_PARAMETERS_ARB";
	#endif
	#ifdef GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB
		else if ( en == GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB ) ostr << "GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB";
	#endif
	#ifdef GL_TRANSPOSE_CURRENT_MATRIX_ARB
		else if ( en == GL_TRANSPOSE_CURRENT_MATRIX_ARB ) ostr << "GL_TRANSPOSE_CURRENT_MATRIX_ARB";
	#endif
	#ifdef GL_MATRIX0_ARB
		else if ( en == GL_MATRIX0_ARB ) ostr << "GL_MATRIX0_ARB";
	#endif
	#ifdef GL_MATRIX1_ARB
		else if ( en == GL_MATRIX1_ARB ) ostr << "GL_MATRIX1_ARB";
	#endif
	#ifdef GL_MATRIX2_ARB
		else if ( en == GL_MATRIX2_ARB ) ostr << "GL_MATRIX2_ARB";
	#endif
	#ifdef GL_MATRIX3_ARB
		else if ( en == GL_MATRIX3_ARB ) ostr << "GL_MATRIX3_ARB";
	#endif
	#ifdef GL_MATRIX4_ARB
		else if ( en == GL_MATRIX4_ARB ) ostr << "GL_MATRIX4_ARB";
	#endif
	#ifdef GL_MATRIX5_ARB
		else if ( en == GL_MATRIX5_ARB ) ostr << "GL_MATRIX5_ARB";
	#endif
	#ifdef GL_MATRIX6_ARB
		else if ( en == GL_MATRIX6_ARB ) ostr << "GL_MATRIX6_ARB";
	#endif
	#ifdef GL_MATRIX7_ARB
		else if ( en == GL_MATRIX7_ARB ) ostr << "GL_MATRIX7_ARB";
	#endif
	#ifdef GL_MATRIX8_ARB
		else if ( en == GL_MATRIX8_ARB ) ostr << "GL_MATRIX8_ARB";
	#endif
	#ifdef GL_MATRIX9_ARB
		else if ( en == GL_MATRIX9_ARB ) ostr << "GL_MATRIX9_ARB";
	#endif
	#ifdef GL_MATRIX10_ARB
		else if ( en == GL_MATRIX10_ARB ) ostr << "GL_MATRIX10_ARB";
	#endif
	#ifdef GL_MATRIX11_ARB
		else if ( en == GL_MATRIX11_ARB ) ostr << "GL_MATRIX11_ARB";
	#endif
	#ifdef GL_MATRIX12_ARB
		else if ( en == GL_MATRIX12_ARB ) ostr << "GL_MATRIX12_ARB";
	#endif
	#ifdef GL_MATRIX13_ARB
		else if ( en == GL_MATRIX13_ARB ) ostr << "GL_MATRIX13_ARB";
	#endif
	#ifdef GL_MATRIX14_ARB
		else if ( en == GL_MATRIX14_ARB ) ostr << "GL_MATRIX14_ARB";
	#endif
	#ifdef GL_MATRIX15_ARB
		else if ( en == GL_MATRIX15_ARB ) ostr << "GL_MATRIX15_ARB";
	#endif
	#ifdef GL_MATRIX16_ARB
		else if ( en == GL_MATRIX16_ARB ) ostr << "GL_MATRIX16_ARB";
	#endif
	#ifdef GL_MATRIX17_ARB
		else if ( en == GL_MATRIX17_ARB ) ostr << "GL_MATRIX17_ARB";
	#endif
	#ifdef GL_MATRIX18_ARB
		else if ( en == GL_MATRIX18_ARB ) ostr << "GL_MATRIX18_ARB";
	#endif
	#ifdef GL_MATRIX19_ARB
		else if ( en == GL_MATRIX19_ARB ) ostr << "GL_MATRIX19_ARB";
	#endif
	#ifdef GL_MATRIX20_ARB
		else if ( en == GL_MATRIX20_ARB ) ostr << "GL_MATRIX20_ARB";
	#endif
	#ifdef GL_MATRIX21_ARB
		else if ( en == GL_MATRIX21_ARB ) ostr << "GL_MATRIX21_ARB";
	#endif
	#ifdef GL_MATRIX22_ARB
		else if ( en == GL_MATRIX22_ARB ) ostr << "GL_MATRIX22_ARB";
	#endif
	#ifdef GL_MATRIX23_ARB
		else if ( en == GL_MATRIX23_ARB ) ostr << "GL_MATRIX23_ARB";
	#endif
	#ifdef GL_MATRIX24_ARB
		else if ( en == GL_MATRIX24_ARB ) ostr << "GL_MATRIX24_ARB";
	#endif
	#ifdef GL_MATRIX25_ARB
		else if ( en == GL_MATRIX25_ARB ) ostr << "GL_MATRIX25_ARB";
	#endif
	#ifdef GL_MATRIX26_ARB
		else if ( en == GL_MATRIX26_ARB ) ostr << "GL_MATRIX26_ARB";
	#endif
	#ifdef GL_MATRIX27_ARB
		else if ( en == GL_MATRIX27_ARB ) ostr << "GL_MATRIX27_ARB";
	#endif
	#ifdef GL_MATRIX28_ARB
		else if ( en == GL_MATRIX28_ARB ) ostr << "GL_MATRIX28_ARB";
	#endif
	#ifdef GL_MATRIX29_ARB
		else if ( en == GL_MATRIX29_ARB ) ostr << "GL_MATRIX29_ARB";
	#endif
	#ifdef GL_MATRIX30_ARB
		else if ( en == GL_MATRIX30_ARB ) ostr << "GL_MATRIX30_ARB";
	#endif
	#ifdef GL_MATRIX31_ARB
		else if ( en == GL_MATRIX31_ARB ) ostr << "GL_MATRIX31_ARB";
	#endif
	#ifdef GL_VERTEX_SHADER_ARB
		else if ( en == GL_VERTEX_SHADER_ARB ) ostr << "GL_VERTEX_SHADER_ARB";
	#endif
	#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB
		else if ( en == GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB ) ostr << "GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB";
	#endif
	#ifdef GL_MAX_VARYING_FLOATS_ARB
		else if ( en == GL_MAX_VARYING_FLOATS_ARB ) ostr << "GL_MAX_VARYING_FLOATS_ARB";
	#endif
	#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB
		else if ( en == GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB ) ostr << "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB";
	#endif
	#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB
		else if ( en == GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB ) ostr << "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB";
	#endif
	#ifdef GL_OBJECT_ACTIVE_ATTRIBUTES_ARB
		else if ( en == GL_OBJECT_ACTIVE_ATTRIBUTES_ARB ) ostr << "GL_OBJECT_ACTIVE_ATTRIBUTES_ARB";
	#endif
	#ifdef GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB
		else if ( en == GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB ) ostr << "GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB";
	#endif
	#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
		else if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV ) ostr << "GL_UNSIGNED_INT_10F_11F_11F_REV";
	#endif
	#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
		else if ( en == GL_UNSIGNED_INT_2_10_10_10_REV ) ostr << "GL_UNSIGNED_INT_2_10_10_10_REV";
	#endif
	#ifdef GL_INT_2_10_10_10_REV
		else if ( en == GL_INT_2_10_10_10_REV ) ostr << "GL_INT_2_10_10_10_REV";
	#endif
	#ifdef GL_DEPTH_RANGE
		else if ( en == GL_DEPTH_RANGE ) ostr << "GL_DEPTH_RANGE";
	#endif
	#ifdef GL_VIEWPORT
		else if ( en == GL_VIEWPORT ) ostr << "GL_VIEWPORT";
	#endif
	#ifdef GL_SCISSOR_BOX
		else if ( en == GL_SCISSOR_BOX ) ostr << "GL_SCISSOR_BOX";
	#endif
	#ifdef GL_SCISSOR_TEST
		else if ( en == GL_SCISSOR_TEST ) ostr << "GL_SCISSOR_TEST";
	#endif
	#ifdef GL_MAX_VIEWPORTS
		else if ( en == GL_MAX_VIEWPORTS ) ostr << "GL_MAX_VIEWPORTS";
	#endif
	#ifdef GL_VIEWPORT_SUBPIXEL_BITS
		else if ( en == GL_VIEWPORT_SUBPIXEL_BITS ) ostr << "GL_VIEWPORT_SUBPIXEL_BITS";
	#endif
	#ifdef GL_VIEWPORT_BOUNDS_RANGE
		else if ( en == GL_VIEWPORT_BOUNDS_RANGE ) ostr << "GL_VIEWPORT_BOUNDS_RANGE";
	#endif
	#ifdef GL_LAYER_PROVOKING_VERTEX
		else if ( en == GL_LAYER_PROVOKING_VERTEX ) ostr << "GL_LAYER_PROVOKING_VERTEX";
	#endif
	#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
		else if ( en == GL_VIEWPORT_INDEX_PROVOKING_VERTEX ) ostr << "GL_VIEWPORT_INDEX_PROVOKING_VERTEX";
	#endif
	#ifdef GL_UNDEFINED_VERTEX
		else if ( en == GL_UNDEFINED_VERTEX ) ostr << "GL_UNDEFINED_VERTEX";
	#endif
	#ifdef GL_FIRST_VERTEX_CONVENTION
		else if ( en == GL_FIRST_VERTEX_CONVENTION ) ostr << "GL_FIRST_VERTEX_CONVENTION";
	#endif
	#ifdef GL_LAST_VERTEX_CONVENTION
		else if ( en == GL_LAST_VERTEX_CONVENTION ) ostr << "GL_LAST_VERTEX_CONVENTION";
	#endif
	#ifdef GL_PROVOKING_VERTEX
		else if ( en == GL_PROVOKING_VERTEX ) ostr << "GL_PROVOKING_VERTEX";
	#endif
	#ifdef GL_TEXTURE_POINT_MODE_ATIX
		else if ( en == GL_TEXTURE_POINT_MODE_ATIX ) ostr << "GL_TEXTURE_POINT_MODE_ATIX";
	#endif
	#ifdef GL_TEXTURE_POINT_ONE_COORD_ATIX
		else if ( en == GL_TEXTURE_POINT_ONE_COORD_ATIX ) ostr << "GL_TEXTURE_POINT_ONE_COORD_ATIX";
	#endif
	#ifdef GL_TEXTURE_POINT_SPRITE_ATIX
		else if ( en == GL_TEXTURE_POINT_SPRITE_ATIX ) ostr << "GL_TEXTURE_POINT_SPRITE_ATIX";
	#endif
	#ifdef GL_POINT_SPRITE_CULL_MODE_ATIX
		else if ( en == GL_POINT_SPRITE_CULL_MODE_ATIX ) ostr << "GL_POINT_SPRITE_CULL_MODE_ATIX";
	#endif
	#ifdef GL_POINT_SPRITE_CULL_CENTER_ATIX
		else if ( en == GL_POINT_SPRITE_CULL_CENTER_ATIX ) ostr << "GL_POINT_SPRITE_CULL_CENTER_ATIX";
	#endif
	#ifdef GL_POINT_SPRITE_CULL_CLIP_ATIX
		else if ( en == GL_POINT_SPRITE_CULL_CLIP_ATIX ) ostr << "GL_POINT_SPRITE_CULL_CLIP_ATIX";
	#endif
	#ifdef GL_MODULATE_ADD_ATIX
		else if ( en == GL_MODULATE_ADD_ATIX ) ostr << "GL_MODULATE_ADD_ATIX";
	#endif
	#ifdef GL_MODULATE_SIGNED_ADD_ATIX
		else if ( en == GL_MODULATE_SIGNED_ADD_ATIX ) ostr << "GL_MODULATE_SIGNED_ADD_ATIX";
	#endif
	#ifdef GL_MODULATE_SUBTRACT_ATIX
		else if ( en == GL_MODULATE_SUBTRACT_ATIX ) ostr << "GL_MODULATE_SUBTRACT_ATIX";
	#endif
	#ifdef GL_SECONDARY_COLOR_ATIX
		else if ( en == GL_SECONDARY_COLOR_ATIX ) ostr << "GL_SECONDARY_COLOR_ATIX";
	#endif
	#ifdef GL_TEXTURE_OUTPUT_RGB_ATIX
		else if ( en == GL_TEXTURE_OUTPUT_RGB_ATIX ) ostr << "GL_TEXTURE_OUTPUT_RGB_ATIX";
	#endif
	#ifdef GL_TEXTURE_OUTPUT_ALPHA_ATIX
		else if ( en == GL_TEXTURE_OUTPUT_ALPHA_ATIX ) ostr << "GL_TEXTURE_OUTPUT_ALPHA_ATIX";
	#endif
	#ifdef GL_OUTPUT_POINT_SIZE_ATIX
		else if ( en == GL_OUTPUT_POINT_SIZE_ATIX ) ostr << "GL_OUTPUT_POINT_SIZE_ATIX";
	#endif
	#ifdef GL_MAX_DRAW_BUFFERS_ATI
		else if ( en == GL_MAX_DRAW_BUFFERS_ATI ) ostr << "GL_MAX_DRAW_BUFFERS_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER0_ATI
		else if ( en == GL_DRAW_BUFFER0_ATI ) ostr << "GL_DRAW_BUFFER0_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER1_ATI
		else if ( en == GL_DRAW_BUFFER1_ATI ) ostr << "GL_DRAW_BUFFER1_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER2_ATI
		else if ( en == GL_DRAW_BUFFER2_ATI ) ostr << "GL_DRAW_BUFFER2_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER3_ATI
		else if ( en == GL_DRAW_BUFFER3_ATI ) ostr << "GL_DRAW_BUFFER3_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER4_ATI
		else if ( en == GL_DRAW_BUFFER4_ATI ) ostr << "GL_DRAW_BUFFER4_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER5_ATI
		else if ( en == GL_DRAW_BUFFER5_ATI ) ostr << "GL_DRAW_BUFFER5_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER6_ATI
		else if ( en == GL_DRAW_BUFFER6_ATI ) ostr << "GL_DRAW_BUFFER6_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER7_ATI
		else if ( en == GL_DRAW_BUFFER7_ATI ) ostr << "GL_DRAW_BUFFER7_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER8_ATI
		else if ( en == GL_DRAW_BUFFER8_ATI ) ostr << "GL_DRAW_BUFFER8_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER9_ATI
		else if ( en == GL_DRAW_BUFFER9_ATI ) ostr << "GL_DRAW_BUFFER9_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER10_ATI
		else if ( en == GL_DRAW_BUFFER10_ATI ) ostr << "GL_DRAW_BUFFER10_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER11_ATI
		else if ( en == GL_DRAW_BUFFER11_ATI ) ostr << "GL_DRAW_BUFFER11_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER12_ATI
		else if ( en == GL_DRAW_BUFFER12_ATI ) ostr << "GL_DRAW_BUFFER12_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER13_ATI
		else if ( en == GL_DRAW_BUFFER13_ATI ) ostr << "GL_DRAW_BUFFER13_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER14_ATI
		else if ( en == GL_DRAW_BUFFER14_ATI ) ostr << "GL_DRAW_BUFFER14_ATI";
	#endif
	#ifdef GL_DRAW_BUFFER15_ATI
		else if ( en == GL_DRAW_BUFFER15_ATI ) ostr << "GL_DRAW_BUFFER15_ATI";
	#endif
	#ifdef GL_ELEMENT_ARRAY_ATI
		else if ( en == GL_ELEMENT_ARRAY_ATI ) ostr << "GL_ELEMENT_ARRAY_ATI";
	#endif
	#ifdef GL_ELEMENT_ARRAY_TYPE_ATI
		else if ( en == GL_ELEMENT_ARRAY_TYPE_ATI ) ostr << "GL_ELEMENT_ARRAY_TYPE_ATI";
	#endif
	#ifdef GL_ELEMENT_ARRAY_POINTER_ATI
		else if ( en == GL_ELEMENT_ARRAY_POINTER_ATI ) ostr << "GL_ELEMENT_ARRAY_POINTER_ATI";
	#endif
	#ifdef GL_BUMP_ROT_MATRIX_ATI
		else if ( en == GL_BUMP_ROT_MATRIX_ATI ) ostr << "GL_BUMP_ROT_MATRIX_ATI";
	#endif
	#ifdef GL_BUMP_ROT_MATRIX_SIZE_ATI
		else if ( en == GL_BUMP_ROT_MATRIX_SIZE_ATI ) ostr << "GL_BUMP_ROT_MATRIX_SIZE_ATI";
	#endif
	#ifdef GL_BUMP_NUM_TEX_UNITS_ATI
		else if ( en == GL_BUMP_NUM_TEX_UNITS_ATI ) ostr << "GL_BUMP_NUM_TEX_UNITS_ATI";
	#endif
	#ifdef GL_BUMP_TEX_UNITS_ATI
		else if ( en == GL_BUMP_TEX_UNITS_ATI ) ostr << "GL_BUMP_TEX_UNITS_ATI";
	#endif
	#ifdef GL_DUDV_ATI
		else if ( en == GL_DUDV_ATI ) ostr << "GL_DUDV_ATI";
	#endif
	#ifdef GL_DU8DV8_ATI
		else if ( en == GL_DU8DV8_ATI ) ostr << "GL_DU8DV8_ATI";
	#endif
	#ifdef GL_BUMP_ENVMAP_ATI
		else if ( en == GL_BUMP_ENVMAP_ATI ) ostr << "GL_BUMP_ENVMAP_ATI";
	#endif
	#ifdef GL_BUMP_TARGET_ATI
		else if ( en == GL_BUMP_TARGET_ATI ) ostr << "GL_BUMP_TARGET_ATI";
	#endif
	#ifdef GL_RED_BIT_ATI
		else if ( en == GL_RED_BIT_ATI ) ostr << "GL_RED_BIT_ATI";
	#endif
	#ifdef GL_2X_BIT_ATI
		else if ( en == GL_2X_BIT_ATI ) ostr << "GL_2X_BIT_ATI";
	#endif
	#ifdef GL_4X_BIT_ATI
		else if ( en == GL_4X_BIT_ATI ) ostr << "GL_4X_BIT_ATI";
	#endif
	#ifdef GL_GREEN_BIT_ATI
		else if ( en == GL_GREEN_BIT_ATI ) ostr << "GL_GREEN_BIT_ATI";
	#endif
	#ifdef GL_COMP_BIT_ATI
		else if ( en == GL_COMP_BIT_ATI ) ostr << "GL_COMP_BIT_ATI";
	#endif
	#ifdef GL_BLUE_BIT_ATI
		else if ( en == GL_BLUE_BIT_ATI ) ostr << "GL_BLUE_BIT_ATI";
	#endif
	#ifdef GL_8X_BIT_ATI
		else if ( en == GL_8X_BIT_ATI ) ostr << "GL_8X_BIT_ATI";
	#endif
	#ifdef GL_NEGATE_BIT_ATI
		else if ( en == GL_NEGATE_BIT_ATI ) ostr << "GL_NEGATE_BIT_ATI";
	#endif
	#ifdef GL_BIAS_BIT_ATI
		else if ( en == GL_BIAS_BIT_ATI ) ostr << "GL_BIAS_BIT_ATI";
	#endif
	#ifdef GL_HALF_BIT_ATI
		else if ( en == GL_HALF_BIT_ATI ) ostr << "GL_HALF_BIT_ATI";
	#endif
	#ifdef GL_QUARTER_BIT_ATI
		else if ( en == GL_QUARTER_BIT_ATI ) ostr << "GL_QUARTER_BIT_ATI";
	#endif
	#ifdef GL_EIGHTH_BIT_ATI
		else if ( en == GL_EIGHTH_BIT_ATI ) ostr << "GL_EIGHTH_BIT_ATI";
	#endif
	#ifdef GL_SATURATE_BIT_ATI
		else if ( en == GL_SATURATE_BIT_ATI ) ostr << "GL_SATURATE_BIT_ATI";
	#endif
	#ifdef GL_FRAGMENT_SHADER_ATI
		else if ( en == GL_FRAGMENT_SHADER_ATI ) ostr << "GL_FRAGMENT_SHADER_ATI";
	#endif
	#ifdef GL_REG_0_ATI
		else if ( en == GL_REG_0_ATI ) ostr << "GL_REG_0_ATI";
	#endif
	#ifdef GL_REG_1_ATI
		else if ( en == GL_REG_1_ATI ) ostr << "GL_REG_1_ATI";
	#endif
	#ifdef GL_REG_2_ATI
		else if ( en == GL_REG_2_ATI ) ostr << "GL_REG_2_ATI";
	#endif
	#ifdef GL_REG_3_ATI
		else if ( en == GL_REG_3_ATI ) ostr << "GL_REG_3_ATI";
	#endif
	#ifdef GL_REG_4_ATI
		else if ( en == GL_REG_4_ATI ) ostr << "GL_REG_4_ATI";
	#endif
	#ifdef GL_REG_5_ATI
		else if ( en == GL_REG_5_ATI ) ostr << "GL_REG_5_ATI";
	#endif
	#ifdef GL_CON_0_ATI
		else if ( en == GL_CON_0_ATI ) ostr << "GL_CON_0_ATI";
	#endif
	#ifdef GL_CON_1_ATI
		else if ( en == GL_CON_1_ATI ) ostr << "GL_CON_1_ATI";
	#endif
	#ifdef GL_CON_2_ATI
		else if ( en == GL_CON_2_ATI ) ostr << "GL_CON_2_ATI";
	#endif
	#ifdef GL_CON_3_ATI
		else if ( en == GL_CON_3_ATI ) ostr << "GL_CON_3_ATI";
	#endif
	#ifdef GL_CON_4_ATI
		else if ( en == GL_CON_4_ATI ) ostr << "GL_CON_4_ATI";
	#endif
	#ifdef GL_CON_5_ATI
		else if ( en == GL_CON_5_ATI ) ostr << "GL_CON_5_ATI";
	#endif
	#ifdef GL_CON_6_ATI
		else if ( en == GL_CON_6_ATI ) ostr << "GL_CON_6_ATI";
	#endif
	#ifdef GL_CON_7_ATI
		else if ( en == GL_CON_7_ATI ) ostr << "GL_CON_7_ATI";
	#endif
	#ifdef GL_MOV_ATI
		else if ( en == GL_MOV_ATI ) ostr << "GL_MOV_ATI";
	#endif
	#ifdef GL_ADD_ATI
		else if ( en == GL_ADD_ATI ) ostr << "GL_ADD_ATI";
	#endif
	#ifdef GL_MUL_ATI
		else if ( en == GL_MUL_ATI ) ostr << "GL_MUL_ATI";
	#endif
	#ifdef GL_SUB_ATI
		else if ( en == GL_SUB_ATI ) ostr << "GL_SUB_ATI";
	#endif
	#ifdef GL_DOT3_ATI
		else if ( en == GL_DOT3_ATI ) ostr << "GL_DOT3_ATI";
	#endif
	#ifdef GL_DOT4_ATI
		else if ( en == GL_DOT4_ATI ) ostr << "GL_DOT4_ATI";
	#endif
	#ifdef GL_MAD_ATI
		else if ( en == GL_MAD_ATI ) ostr << "GL_MAD_ATI";
	#endif
	#ifdef GL_LERP_ATI
		else if ( en == GL_LERP_ATI ) ostr << "GL_LERP_ATI";
	#endif
	#ifdef GL_CND_ATI
		else if ( en == GL_CND_ATI ) ostr << "GL_CND_ATI";
	#endif
	#ifdef GL_CND0_ATI
		else if ( en == GL_CND0_ATI ) ostr << "GL_CND0_ATI";
	#endif
	#ifdef GL_DOT2_ADD_ATI
		else if ( en == GL_DOT2_ADD_ATI ) ostr << "GL_DOT2_ADD_ATI";
	#endif
	#ifdef GL_SECONDARY_INTERPOLATOR_ATI
		else if ( en == GL_SECONDARY_INTERPOLATOR_ATI ) ostr << "GL_SECONDARY_INTERPOLATOR_ATI";
	#endif
	#ifdef GL_NUM_FRAGMENT_REGISTERS_ATI
		else if ( en == GL_NUM_FRAGMENT_REGISTERS_ATI ) ostr << "GL_NUM_FRAGMENT_REGISTERS_ATI";
	#endif
	#ifdef GL_NUM_FRAGMENT_CONSTANTS_ATI
		else if ( en == GL_NUM_FRAGMENT_CONSTANTS_ATI ) ostr << "GL_NUM_FRAGMENT_CONSTANTS_ATI";
	#endif
	#ifdef GL_NUM_PASSES_ATI
		else if ( en == GL_NUM_PASSES_ATI ) ostr << "GL_NUM_PASSES_ATI";
	#endif
	#ifdef GL_NUM_INSTRUCTIONS_PER_PASS_ATI
		else if ( en == GL_NUM_INSTRUCTIONS_PER_PASS_ATI ) ostr << "GL_NUM_INSTRUCTIONS_PER_PASS_ATI";
	#endif
	#ifdef GL_NUM_INSTRUCTIONS_TOTAL_ATI
		else if ( en == GL_NUM_INSTRUCTIONS_TOTAL_ATI ) ostr << "GL_NUM_INSTRUCTIONS_TOTAL_ATI";
	#endif
	#ifdef GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI
		else if ( en == GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI ) ostr << "GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI";
	#endif
	#ifdef GL_NUM_LOOPBACK_COMPONENTS_ATI
		else if ( en == GL_NUM_LOOPBACK_COMPONENTS_ATI ) ostr << "GL_NUM_LOOPBACK_COMPONENTS_ATI";
	#endif
	#ifdef GL_COLOR_ALPHA_PAIRING_ATI
		else if ( en == GL_COLOR_ALPHA_PAIRING_ATI ) ostr << "GL_COLOR_ALPHA_PAIRING_ATI";
	#endif
	#ifdef GL_SWIZZLE_STR_ATI
		else if ( en == GL_SWIZZLE_STR_ATI ) ostr << "GL_SWIZZLE_STR_ATI";
	#endif
	#ifdef GL_SWIZZLE_STQ_ATI
		else if ( en == GL_SWIZZLE_STQ_ATI ) ostr << "GL_SWIZZLE_STQ_ATI";
	#endif
	#ifdef GL_SWIZZLE_STR_DR_ATI
		else if ( en == GL_SWIZZLE_STR_DR_ATI ) ostr << "GL_SWIZZLE_STR_DR_ATI";
	#endif
	#ifdef GL_SWIZZLE_STQ_DQ_ATI
		else if ( en == GL_SWIZZLE_STQ_DQ_ATI ) ostr << "GL_SWIZZLE_STQ_DQ_ATI";
	#endif
	#ifdef GL_SWIZZLE_STRQ_ATI
		else if ( en == GL_SWIZZLE_STRQ_ATI ) ostr << "GL_SWIZZLE_STRQ_ATI";
	#endif
	#ifdef GL_SWIZZLE_STRQ_DQ_ATI
		else if ( en == GL_SWIZZLE_STRQ_DQ_ATI ) ostr << "GL_SWIZZLE_STRQ_DQ_ATI";
	#endif
	#ifdef GL_VBO_FREE_MEMORY_ATI
		else if ( en == GL_VBO_FREE_MEMORY_ATI ) ostr << "GL_VBO_FREE_MEMORY_ATI";
	#endif
	#ifdef GL_TEXTURE_FREE_MEMORY_ATI
		else if ( en == GL_TEXTURE_FREE_MEMORY_ATI ) ostr << "GL_TEXTURE_FREE_MEMORY_ATI";
	#endif
	#ifdef GL_RENDERBUFFER_FREE_MEMORY_ATI
		else if ( en == GL_RENDERBUFFER_FREE_MEMORY_ATI ) ostr << "GL_RENDERBUFFER_FREE_MEMORY_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_ATI
		else if ( en == GL_PN_TRIANGLES_ATI ) ostr << "GL_PN_TRIANGLES_ATI";
	#endif
	#ifdef GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI
		else if ( en == GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI ) ostr << "GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_POINT_MODE_ATI
		else if ( en == GL_PN_TRIANGLES_POINT_MODE_ATI ) ostr << "GL_PN_TRIANGLES_POINT_MODE_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_NORMAL_MODE_ATI
		else if ( en == GL_PN_TRIANGLES_NORMAL_MODE_ATI ) ostr << "GL_PN_TRIANGLES_NORMAL_MODE_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI
		else if ( en == GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI ) ostr << "GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI
		else if ( en == GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI ) ostr << "GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI
		else if ( en == GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI ) ostr << "GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI
		else if ( en == GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI ) ostr << "GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI";
	#endif
	#ifdef GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI
		else if ( en == GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI ) ostr << "GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI";
	#endif
	#ifdef GL_STENCIL_BACK_FUNC_ATI
		else if ( en == GL_STENCIL_BACK_FUNC_ATI ) ostr << "GL_STENCIL_BACK_FUNC_ATI";
	#endif
	#ifdef GL_STENCIL_BACK_FAIL_ATI
		else if ( en == GL_STENCIL_BACK_FAIL_ATI ) ostr << "GL_STENCIL_BACK_FAIL_ATI";
	#endif
	#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI
		else if ( en == GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI ) ostr << "GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI";
	#endif
	#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI
		else if ( en == GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI ) ostr << "GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI";
	#endif
	#ifdef GL_TEXT_FRAGMENT_SHADER_ATI
		else if ( en == GL_TEXT_FRAGMENT_SHADER_ATI ) ostr << "GL_TEXT_FRAGMENT_SHADER_ATI";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI
		else if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI ) ostr << "GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI";
	#endif
	#ifdef GL_MODULATE_ADD_ATI
		else if ( en == GL_MODULATE_ADD_ATI ) ostr << "GL_MODULATE_ADD_ATI";
	#endif
	#ifdef GL_MODULATE_SIGNED_ADD_ATI
		else if ( en == GL_MODULATE_SIGNED_ADD_ATI ) ostr << "GL_MODULATE_SIGNED_ADD_ATI";
	#endif
	#ifdef GL_MODULATE_SUBTRACT_ATI
		else if ( en == GL_MODULATE_SUBTRACT_ATI ) ostr << "GL_MODULATE_SUBTRACT_ATI";
	#endif
	#ifdef GL_RGBA_FLOAT32_ATI
		else if ( en == GL_RGBA_FLOAT32_ATI ) ostr << "GL_RGBA_FLOAT32_ATI";
	#endif
	#ifdef GL_RGB_FLOAT32_ATI
		else if ( en == GL_RGB_FLOAT32_ATI ) ostr << "GL_RGB_FLOAT32_ATI";
	#endif
	#ifdef GL_ALPHA_FLOAT32_ATI
		else if ( en == GL_ALPHA_FLOAT32_ATI ) ostr << "GL_ALPHA_FLOAT32_ATI";
	#endif
	#ifdef GL_INTENSITY_FLOAT32_ATI
		else if ( en == GL_INTENSITY_FLOAT32_ATI ) ostr << "GL_INTENSITY_FLOAT32_ATI";
	#endif
	#ifdef GL_LUMINANCE_FLOAT32_ATI
		else if ( en == GL_LUMINANCE_FLOAT32_ATI ) ostr << "GL_LUMINANCE_FLOAT32_ATI";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_FLOAT32_ATI
		else if ( en == GL_LUMINANCE_ALPHA_FLOAT32_ATI ) ostr << "GL_LUMINANCE_ALPHA_FLOAT32_ATI";
	#endif
	#ifdef GL_RGBA_FLOAT16_ATI
		else if ( en == GL_RGBA_FLOAT16_ATI ) ostr << "GL_RGBA_FLOAT16_ATI";
	#endif
	#ifdef GL_RGB_FLOAT16_ATI
		else if ( en == GL_RGB_FLOAT16_ATI ) ostr << "GL_RGB_FLOAT16_ATI";
	#endif
	#ifdef GL_ALPHA_FLOAT16_ATI
		else if ( en == GL_ALPHA_FLOAT16_ATI ) ostr << "GL_ALPHA_FLOAT16_ATI";
	#endif
	#ifdef GL_INTENSITY_FLOAT16_ATI
		else if ( en == GL_INTENSITY_FLOAT16_ATI ) ostr << "GL_INTENSITY_FLOAT16_ATI";
	#endif
	#ifdef GL_LUMINANCE_FLOAT16_ATI
		else if ( en == GL_LUMINANCE_FLOAT16_ATI ) ostr << "GL_LUMINANCE_FLOAT16_ATI";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_FLOAT16_ATI
		else if ( en == GL_LUMINANCE_ALPHA_FLOAT16_ATI ) ostr << "GL_LUMINANCE_ALPHA_FLOAT16_ATI";
	#endif
	#ifdef GL_MIRROR_CLAMP_ATI
		else if ( en == GL_MIRROR_CLAMP_ATI ) ostr << "GL_MIRROR_CLAMP_ATI";
	#endif
	#ifdef GL_MIRROR_CLAMP_TO_EDGE_ATI
		else if ( en == GL_MIRROR_CLAMP_TO_EDGE_ATI ) ostr << "GL_MIRROR_CLAMP_TO_EDGE_ATI";
	#endif
	#ifdef GL_STATIC_ATI
		else if ( en == GL_STATIC_ATI ) ostr << "GL_STATIC_ATI";
	#endif
	#ifdef GL_DYNAMIC_ATI
		else if ( en == GL_DYNAMIC_ATI ) ostr << "GL_DYNAMIC_ATI";
	#endif
	#ifdef GL_PRESERVE_ATI
		else if ( en == GL_PRESERVE_ATI ) ostr << "GL_PRESERVE_ATI";
	#endif
	#ifdef GL_DISCARD_ATI
		else if ( en == GL_DISCARD_ATI ) ostr << "GL_DISCARD_ATI";
	#endif
	#ifdef GL_OBJECT_BUFFER_SIZE_ATI
		else if ( en == GL_OBJECT_BUFFER_SIZE_ATI ) ostr << "GL_OBJECT_BUFFER_SIZE_ATI";
	#endif
	#ifdef GL_OBJECT_BUFFER_USAGE_ATI
		else if ( en == GL_OBJECT_BUFFER_USAGE_ATI ) ostr << "GL_OBJECT_BUFFER_USAGE_ATI";
	#endif
	#ifdef GL_ARRAY_OBJECT_BUFFER_ATI
		else if ( en == GL_ARRAY_OBJECT_BUFFER_ATI ) ostr << "GL_ARRAY_OBJECT_BUFFER_ATI";
	#endif
	#ifdef GL_ARRAY_OBJECT_OFFSET_ATI
		else if ( en == GL_ARRAY_OBJECT_OFFSET_ATI ) ostr << "GL_ARRAY_OBJECT_OFFSET_ATI";
	#endif
	#ifdef GL_MAX_VERTEX_STREAMS_ATI
		else if ( en == GL_MAX_VERTEX_STREAMS_ATI ) ostr << "GL_MAX_VERTEX_STREAMS_ATI";
	#endif
	#ifdef GL_VERTEX_SOURCE_ATI
		else if ( en == GL_VERTEX_SOURCE_ATI ) ostr << "GL_VERTEX_SOURCE_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM0_ATI
		else if ( en == GL_VERTEX_STREAM0_ATI ) ostr << "GL_VERTEX_STREAM0_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM1_ATI
		else if ( en == GL_VERTEX_STREAM1_ATI ) ostr << "GL_VERTEX_STREAM1_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM2_ATI
		else if ( en == GL_VERTEX_STREAM2_ATI ) ostr << "GL_VERTEX_STREAM2_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM3_ATI
		else if ( en == GL_VERTEX_STREAM3_ATI ) ostr << "GL_VERTEX_STREAM3_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM4_ATI
		else if ( en == GL_VERTEX_STREAM4_ATI ) ostr << "GL_VERTEX_STREAM4_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM5_ATI
		else if ( en == GL_VERTEX_STREAM5_ATI ) ostr << "GL_VERTEX_STREAM5_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM6_ATI
		else if ( en == GL_VERTEX_STREAM6_ATI ) ostr << "GL_VERTEX_STREAM6_ATI";
	#endif
	#ifdef GL_VERTEX_STREAM7_ATI
		else if ( en == GL_VERTEX_STREAM7_ATI ) ostr << "GL_VERTEX_STREAM7_ATI";
	#endif
	#ifdef GL_422_EXT
		else if ( en == GL_422_EXT ) ostr << "GL_422_EXT";
	#endif
	#ifdef GL_422_REV_EXT
		else if ( en == GL_422_REV_EXT ) ostr << "GL_422_REV_EXT";
	#endif
	#ifdef GL_422_AVERAGE_EXT
		else if ( en == GL_422_AVERAGE_EXT ) ostr << "GL_422_AVERAGE_EXT";
	#endif
	#ifdef GL_422_REV_AVERAGE_EXT
		else if ( en == GL_422_REV_AVERAGE_EXT ) ostr << "GL_422_REV_AVERAGE_EXT";
	#endif
	#ifdef GL_CG_VERTEX_SHADER_EXT
		else if ( en == GL_CG_VERTEX_SHADER_EXT ) ostr << "GL_CG_VERTEX_SHADER_EXT";
	#endif
	#ifdef GL_CG_FRAGMENT_SHADER_EXT
		else if ( en == GL_CG_FRAGMENT_SHADER_EXT ) ostr << "GL_CG_FRAGMENT_SHADER_EXT";
	#endif
	#ifdef GL_ABGR_EXT
		else if ( en == GL_ABGR_EXT ) ostr << "GL_ABGR_EXT";
	#endif
	#ifdef GL_BGR_EXT
		else if ( en == GL_BGR_EXT ) ostr << "GL_BGR_EXT";
	#endif
	#ifdef GL_BGRA_EXT
		else if ( en == GL_BGRA_EXT ) ostr << "GL_BGRA_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT
		else if ( en == GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT ) ostr << "GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT";
	#endif
	#ifdef GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT
		else if ( en == GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT ) ostr << "GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT
		else if ( en == GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT ) ostr << "GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT";
	#endif
	#ifdef GL_MAX_BINDABLE_UNIFORM_SIZE_EXT
		else if ( en == GL_MAX_BINDABLE_UNIFORM_SIZE_EXT ) ostr << "GL_MAX_BINDABLE_UNIFORM_SIZE_EXT";
	#endif
	#ifdef GL_UNIFORM_BUFFER_EXT
		else if ( en == GL_UNIFORM_BUFFER_EXT ) ostr << "GL_UNIFORM_BUFFER_EXT";
	#endif
	#ifdef GL_UNIFORM_BUFFER_BINDING_EXT
		else if ( en == GL_UNIFORM_BUFFER_BINDING_EXT ) ostr << "GL_UNIFORM_BUFFER_BINDING_EXT";
	#endif
	#ifdef GL_CONSTANT_COLOR_EXT
		else if ( en == GL_CONSTANT_COLOR_EXT ) ostr << "GL_CONSTANT_COLOR_EXT";
	#endif
	#ifdef GL_ONE_MINUS_CONSTANT_COLOR_EXT
		else if ( en == GL_ONE_MINUS_CONSTANT_COLOR_EXT ) ostr << "GL_ONE_MINUS_CONSTANT_COLOR_EXT";
	#endif
	#ifdef GL_CONSTANT_ALPHA_EXT
		else if ( en == GL_CONSTANT_ALPHA_EXT ) ostr << "GL_CONSTANT_ALPHA_EXT";
	#endif
	#ifdef GL_ONE_MINUS_CONSTANT_ALPHA_EXT
		else if ( en == GL_ONE_MINUS_CONSTANT_ALPHA_EXT ) ostr << "GL_ONE_MINUS_CONSTANT_ALPHA_EXT";
	#endif
	#ifdef GL_BLEND_COLOR_EXT
		else if ( en == GL_BLEND_COLOR_EXT ) ostr << "GL_BLEND_COLOR_EXT";
	#endif
	#ifdef GL_BLEND_EQUATION_RGB_EXT
		else if ( en == GL_BLEND_EQUATION_RGB_EXT ) ostr << "GL_BLEND_EQUATION_RGB_EXT";
	#endif
	#ifdef GL_BLEND_EQUATION_ALPHA_EXT
		else if ( en == GL_BLEND_EQUATION_ALPHA_EXT ) ostr << "GL_BLEND_EQUATION_ALPHA_EXT";
	#endif
	#ifdef GL_BLEND_DST_RGB_EXT
		else if ( en == GL_BLEND_DST_RGB_EXT ) ostr << "GL_BLEND_DST_RGB_EXT";
	#endif
	#ifdef GL_BLEND_SRC_RGB_EXT
		else if ( en == GL_BLEND_SRC_RGB_EXT ) ostr << "GL_BLEND_SRC_RGB_EXT";
	#endif
	#ifdef GL_BLEND_DST_ALPHA_EXT
		else if ( en == GL_BLEND_DST_ALPHA_EXT ) ostr << "GL_BLEND_DST_ALPHA_EXT";
	#endif
	#ifdef GL_BLEND_SRC_ALPHA_EXT
		else if ( en == GL_BLEND_SRC_ALPHA_EXT ) ostr << "GL_BLEND_SRC_ALPHA_EXT";
	#endif
	#ifdef GL_FUNC_ADD_EXT
		else if ( en == GL_FUNC_ADD_EXT ) ostr << "GL_FUNC_ADD_EXT";
	#endif
	#ifdef GL_MIN_EXT
		else if ( en == GL_MIN_EXT ) ostr << "GL_MIN_EXT";
	#endif
	#ifdef GL_MAX_EXT
		else if ( en == GL_MAX_EXT ) ostr << "GL_MAX_EXT";
	#endif
	#ifdef GL_BLEND_EQUATION_EXT
		else if ( en == GL_BLEND_EQUATION_EXT ) ostr << "GL_BLEND_EQUATION_EXT";
	#endif
	#ifdef GL_FUNC_SUBTRACT_EXT
		else if ( en == GL_FUNC_SUBTRACT_EXT ) ostr << "GL_FUNC_SUBTRACT_EXT";
	#endif
	#ifdef GL_FUNC_REVERSE_SUBTRACT_EXT
		else if ( en == GL_FUNC_REVERSE_SUBTRACT_EXT ) ostr << "GL_FUNC_REVERSE_SUBTRACT_EXT";
	#endif
	#ifdef GL_CLIP_VOLUME_CLIPPING_HINT_EXT
		else if ( en == GL_CLIP_VOLUME_CLIPPING_HINT_EXT ) ostr << "GL_CLIP_VOLUME_CLIPPING_HINT_EXT";
	#endif
	#ifdef GL_CMYK_EXT
		else if ( en == GL_CMYK_EXT ) ostr << "GL_CMYK_EXT";
	#endif
	#ifdef GL_CMYKA_EXT
		else if ( en == GL_CMYKA_EXT ) ostr << "GL_CMYKA_EXT";
	#endif
	#ifdef GL_PACK_CMYK_HINT_EXT
		else if ( en == GL_PACK_CMYK_HINT_EXT ) ostr << "GL_PACK_CMYK_HINT_EXT";
	#endif
	#ifdef GL_UNPACK_CMYK_HINT_EXT
		else if ( en == GL_UNPACK_CMYK_HINT_EXT ) ostr << "GL_UNPACK_CMYK_HINT_EXT";
	#endif
	#ifdef GL_ARRAY_ELEMENT_LOCK_FIRST_EXT
		else if ( en == GL_ARRAY_ELEMENT_LOCK_FIRST_EXT ) ostr << "GL_ARRAY_ELEMENT_LOCK_FIRST_EXT";
	#endif
	#ifdef GL_ARRAY_ELEMENT_LOCK_COUNT_EXT
		else if ( en == GL_ARRAY_ELEMENT_LOCK_COUNT_EXT ) ostr << "GL_ARRAY_ELEMENT_LOCK_COUNT_EXT";
	#endif
	#ifdef GL_CONVOLUTION_1D_EXT
		else if ( en == GL_CONVOLUTION_1D_EXT ) ostr << "GL_CONVOLUTION_1D_EXT";
	#endif
	#ifdef GL_CONVOLUTION_2D_EXT
		else if ( en == GL_CONVOLUTION_2D_EXT ) ostr << "GL_CONVOLUTION_2D_EXT";
	#endif
	#ifdef GL_SEPARABLE_2D_EXT
		else if ( en == GL_SEPARABLE_2D_EXT ) ostr << "GL_SEPARABLE_2D_EXT";
	#endif
	#ifdef GL_CONVOLUTION_BORDER_MODE_EXT
		else if ( en == GL_CONVOLUTION_BORDER_MODE_EXT ) ostr << "GL_CONVOLUTION_BORDER_MODE_EXT";
	#endif
	#ifdef GL_CONVOLUTION_FILTER_SCALE_EXT
		else if ( en == GL_CONVOLUTION_FILTER_SCALE_EXT ) ostr << "GL_CONVOLUTION_FILTER_SCALE_EXT";
	#endif
	#ifdef GL_CONVOLUTION_FILTER_BIAS_EXT
		else if ( en == GL_CONVOLUTION_FILTER_BIAS_EXT ) ostr << "GL_CONVOLUTION_FILTER_BIAS_EXT";
	#endif
	#ifdef GL_REDUCE_EXT
		else if ( en == GL_REDUCE_EXT ) ostr << "GL_REDUCE_EXT";
	#endif
	#ifdef GL_CONVOLUTION_FORMAT_EXT
		else if ( en == GL_CONVOLUTION_FORMAT_EXT ) ostr << "GL_CONVOLUTION_FORMAT_EXT";
	#endif
	#ifdef GL_CONVOLUTION_WIDTH_EXT
		else if ( en == GL_CONVOLUTION_WIDTH_EXT ) ostr << "GL_CONVOLUTION_WIDTH_EXT";
	#endif
	#ifdef GL_CONVOLUTION_HEIGHT_EXT
		else if ( en == GL_CONVOLUTION_HEIGHT_EXT ) ostr << "GL_CONVOLUTION_HEIGHT_EXT";
	#endif
	#ifdef GL_MAX_CONVOLUTION_WIDTH_EXT
		else if ( en == GL_MAX_CONVOLUTION_WIDTH_EXT ) ostr << "GL_MAX_CONVOLUTION_WIDTH_EXT";
	#endif
	#ifdef GL_MAX_CONVOLUTION_HEIGHT_EXT
		else if ( en == GL_MAX_CONVOLUTION_HEIGHT_EXT ) ostr << "GL_MAX_CONVOLUTION_HEIGHT_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_RED_SCALE_EXT
		else if ( en == GL_POST_CONVOLUTION_RED_SCALE_EXT ) ostr << "GL_POST_CONVOLUTION_RED_SCALE_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_GREEN_SCALE_EXT
		else if ( en == GL_POST_CONVOLUTION_GREEN_SCALE_EXT ) ostr << "GL_POST_CONVOLUTION_GREEN_SCALE_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_BLUE_SCALE_EXT
		else if ( en == GL_POST_CONVOLUTION_BLUE_SCALE_EXT ) ostr << "GL_POST_CONVOLUTION_BLUE_SCALE_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE_EXT
		else if ( en == GL_POST_CONVOLUTION_ALPHA_SCALE_EXT ) ostr << "GL_POST_CONVOLUTION_ALPHA_SCALE_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_RED_BIAS_EXT
		else if ( en == GL_POST_CONVOLUTION_RED_BIAS_EXT ) ostr << "GL_POST_CONVOLUTION_RED_BIAS_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_GREEN_BIAS_EXT
		else if ( en == GL_POST_CONVOLUTION_GREEN_BIAS_EXT ) ostr << "GL_POST_CONVOLUTION_GREEN_BIAS_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_BLUE_BIAS_EXT
		else if ( en == GL_POST_CONVOLUTION_BLUE_BIAS_EXT ) ostr << "GL_POST_CONVOLUTION_BLUE_BIAS_EXT";
	#endif
	#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS_EXT
		else if ( en == GL_POST_CONVOLUTION_ALPHA_BIAS_EXT ) ostr << "GL_POST_CONVOLUTION_ALPHA_BIAS_EXT";
	#endif
	#ifdef GL_TANGENT_ARRAY_EXT
		else if ( en == GL_TANGENT_ARRAY_EXT ) ostr << "GL_TANGENT_ARRAY_EXT";
	#endif
	#ifdef GL_BINORMAL_ARRAY_EXT
		else if ( en == GL_BINORMAL_ARRAY_EXT ) ostr << "GL_BINORMAL_ARRAY_EXT";
	#endif
	#ifdef GL_CURRENT_TANGENT_EXT
		else if ( en == GL_CURRENT_TANGENT_EXT ) ostr << "GL_CURRENT_TANGENT_EXT";
	#endif
	#ifdef GL_CURRENT_BINORMAL_EXT
		else if ( en == GL_CURRENT_BINORMAL_EXT ) ostr << "GL_CURRENT_BINORMAL_EXT";
	#endif
	#ifdef GL_TANGENT_ARRAY_TYPE_EXT
		else if ( en == GL_TANGENT_ARRAY_TYPE_EXT ) ostr << "GL_TANGENT_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_TANGENT_ARRAY_STRIDE_EXT
		else if ( en == GL_TANGENT_ARRAY_STRIDE_EXT ) ostr << "GL_TANGENT_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_BINORMAL_ARRAY_TYPE_EXT
		else if ( en == GL_BINORMAL_ARRAY_TYPE_EXT ) ostr << "GL_BINORMAL_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_BINORMAL_ARRAY_STRIDE_EXT
		else if ( en == GL_BINORMAL_ARRAY_STRIDE_EXT ) ostr << "GL_BINORMAL_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_TANGENT_ARRAY_POINTER_EXT
		else if ( en == GL_TANGENT_ARRAY_POINTER_EXT ) ostr << "GL_TANGENT_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_BINORMAL_ARRAY_POINTER_EXT
		else if ( en == GL_BINORMAL_ARRAY_POINTER_EXT ) ostr << "GL_BINORMAL_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_MAP1_TANGENT_EXT
		else if ( en == GL_MAP1_TANGENT_EXT ) ostr << "GL_MAP1_TANGENT_EXT";
	#endif
	#ifdef GL_MAP2_TANGENT_EXT
		else if ( en == GL_MAP2_TANGENT_EXT ) ostr << "GL_MAP2_TANGENT_EXT";
	#endif
	#ifdef GL_MAP1_BINORMAL_EXT
		else if ( en == GL_MAP1_BINORMAL_EXT ) ostr << "GL_MAP1_BINORMAL_EXT";
	#endif
	#ifdef GL_MAP2_BINORMAL_EXT
		else if ( en == GL_MAP2_BINORMAL_EXT ) ostr << "GL_MAP2_BINORMAL_EXT";
	#endif
	#ifdef GL_CULL_VERTEX_EXT
		else if ( en == GL_CULL_VERTEX_EXT ) ostr << "GL_CULL_VERTEX_EXT";
	#endif
	#ifdef GL_CULL_VERTEX_EYE_POSITION_EXT
		else if ( en == GL_CULL_VERTEX_EYE_POSITION_EXT ) ostr << "GL_CULL_VERTEX_EYE_POSITION_EXT";
	#endif
	#ifdef GL_CULL_VERTEX_OBJECT_POSITION_EXT
		else if ( en == GL_CULL_VERTEX_OBJECT_POSITION_EXT ) ostr << "GL_CULL_VERTEX_OBJECT_POSITION_EXT";
	#endif
	#ifdef GL_DEPTH_BOUNDS_TEST_EXT
		else if ( en == GL_DEPTH_BOUNDS_TEST_EXT ) ostr << "GL_DEPTH_BOUNDS_TEST_EXT";
	#endif
	#ifdef GL_DEPTH_BOUNDS_EXT
		else if ( en == GL_DEPTH_BOUNDS_EXT ) ostr << "GL_DEPTH_BOUNDS_EXT";
	#endif
	#ifdef GL_PROGRAM_MATRIX_EXT
		else if ( en == GL_PROGRAM_MATRIX_EXT ) ostr << "GL_PROGRAM_MATRIX_EXT";
	#endif
	#ifdef GL_TRANSPOSE_PROGRAM_MATRIX_EXT
		else if ( en == GL_TRANSPOSE_PROGRAM_MATRIX_EXT ) ostr << "GL_TRANSPOSE_PROGRAM_MATRIX_EXT";
	#endif
	#ifdef GL_PROGRAM_MATRIX_STACK_DEPTH_EXT
		else if ( en == GL_PROGRAM_MATRIX_STACK_DEPTH_EXT ) ostr << "GL_PROGRAM_MATRIX_STACK_DEPTH_EXT";
	#endif
	#ifdef GL_MAX_ELEMENTS_VERTICES_EXT
		else if ( en == GL_MAX_ELEMENTS_VERTICES_EXT ) ostr << "GL_MAX_ELEMENTS_VERTICES_EXT";
	#endif
	#ifdef GL_MAX_ELEMENTS_INDICES_EXT
		else if ( en == GL_MAX_ELEMENTS_INDICES_EXT ) ostr << "GL_MAX_ELEMENTS_INDICES_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_SOURCE_EXT
		else if ( en == GL_FOG_COORDINATE_SOURCE_EXT ) ostr << "GL_FOG_COORDINATE_SOURCE_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_EXT
		else if ( en == GL_FOG_COORDINATE_EXT ) ostr << "GL_FOG_COORDINATE_EXT";
	#endif
	#ifdef GL_FRAGMENT_DEPTH_EXT
		else if ( en == GL_FRAGMENT_DEPTH_EXT ) ostr << "GL_FRAGMENT_DEPTH_EXT";
	#endif
	#ifdef GL_CURRENT_FOG_COORDINATE_EXT
		else if ( en == GL_CURRENT_FOG_COORDINATE_EXT ) ostr << "GL_CURRENT_FOG_COORDINATE_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_TYPE_EXT
		else if ( en == GL_FOG_COORDINATE_ARRAY_TYPE_EXT ) ostr << "GL_FOG_COORDINATE_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_STRIDE_EXT
		else if ( en == GL_FOG_COORDINATE_ARRAY_STRIDE_EXT ) ostr << "GL_FOG_COORDINATE_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_POINTER_EXT
		else if ( en == GL_FOG_COORDINATE_ARRAY_POINTER_EXT ) ostr << "GL_FOG_COORDINATE_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_EXT
		else if ( en == GL_FOG_COORDINATE_ARRAY_EXT ) ostr << "GL_FOG_COORDINATE_ARRAY_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHTING_EXT
		else if ( en == GL_FRAGMENT_LIGHTING_EXT ) ostr << "GL_FRAGMENT_LIGHTING_EXT";
	#endif
	#ifdef GL_FRAGMENT_COLOR_MATERIAL_EXT
		else if ( en == GL_FRAGMENT_COLOR_MATERIAL_EXT ) ostr << "GL_FRAGMENT_COLOR_MATERIAL_EXT";
	#endif
	#ifdef GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT
		else if ( en == GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT ) ostr << "GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT";
	#endif
	#ifdef GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT
		else if ( en == GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT ) ostr << "GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT";
	#endif
	#ifdef GL_MAX_FRAGMENT_LIGHTS_EXT
		else if ( en == GL_MAX_FRAGMENT_LIGHTS_EXT ) ostr << "GL_MAX_FRAGMENT_LIGHTS_EXT";
	#endif
	#ifdef GL_MAX_ACTIVE_LIGHTS_EXT
		else if ( en == GL_MAX_ACTIVE_LIGHTS_EXT ) ostr << "GL_MAX_ACTIVE_LIGHTS_EXT";
	#endif
	#ifdef GL_CURRENT_RASTER_NORMAL_EXT
		else if ( en == GL_CURRENT_RASTER_NORMAL_EXT ) ostr << "GL_CURRENT_RASTER_NORMAL_EXT";
	#endif
	#ifdef GL_LIGHT_ENV_MODE_EXT
		else if ( en == GL_LIGHT_ENV_MODE_EXT ) ostr << "GL_LIGHT_ENV_MODE_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT
		else if ( en == GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT ) ostr << "GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT
		else if ( en == GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT ) ostr << "GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT
		else if ( en == GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT ) ostr << "GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT
		else if ( en == GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT ) ostr << "GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT0_EXT
		else if ( en == GL_FRAGMENT_LIGHT0_EXT ) ostr << "GL_FRAGMENT_LIGHT0_EXT";
	#endif
	#ifdef GL_FRAGMENT_LIGHT7_EXT
		else if ( en == GL_FRAGMENT_LIGHT7_EXT ) ostr << "GL_FRAGMENT_LIGHT7_EXT";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER_BINDING_EXT
		else if ( en == GL_DRAW_FRAMEBUFFER_BINDING_EXT ) ostr << "GL_DRAW_FRAMEBUFFER_BINDING_EXT";
	#endif
	#ifdef GL_READ_FRAMEBUFFER_EXT
		else if ( en == GL_READ_FRAMEBUFFER_EXT ) ostr << "GL_READ_FRAMEBUFFER_EXT";
	#endif
	#ifdef GL_DRAW_FRAMEBUFFER_EXT
		else if ( en == GL_DRAW_FRAMEBUFFER_EXT ) ostr << "GL_DRAW_FRAMEBUFFER_EXT";
	#endif
	#ifdef GL_READ_FRAMEBUFFER_BINDING_EXT
		else if ( en == GL_READ_FRAMEBUFFER_BINDING_EXT ) ostr << "GL_READ_FRAMEBUFFER_BINDING_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_SAMPLES_EXT
		else if ( en == GL_RENDERBUFFER_SAMPLES_EXT ) ostr << "GL_RENDERBUFFER_SAMPLES_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT";
	#endif
	#ifdef GL_MAX_SAMPLES_EXT
		else if ( en == GL_MAX_SAMPLES_EXT ) ostr << "GL_MAX_SAMPLES_EXT";
	#endif
	#ifdef GL_SCALED_RESOLVE_FASTEST_EXT
		else if ( en == GL_SCALED_RESOLVE_FASTEST_EXT ) ostr << "GL_SCALED_RESOLVE_FASTEST_EXT";
	#endif
	#ifdef GL_SCALED_RESOLVE_NICEST_EXT
		else if ( en == GL_SCALED_RESOLVE_NICEST_EXT ) ostr << "GL_SCALED_RESOLVE_NICEST_EXT";
	#endif
	#ifdef GL_INVALID_FRAMEBUFFER_OPERATION_EXT
		else if ( en == GL_INVALID_FRAMEBUFFER_OPERATION_EXT ) ostr << "GL_INVALID_FRAMEBUFFER_OPERATION_EXT";
	#endif
	#ifdef GL_MAX_RENDERBUFFER_SIZE_EXT
		else if ( en == GL_MAX_RENDERBUFFER_SIZE_EXT ) ostr << "GL_MAX_RENDERBUFFER_SIZE_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_BINDING_EXT
		else if ( en == GL_FRAMEBUFFER_BINDING_EXT ) ostr << "GL_FRAMEBUFFER_BINDING_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_BINDING_EXT
		else if ( en == GL_RENDERBUFFER_BINDING_EXT ) ostr << "GL_RENDERBUFFER_BINDING_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_COMPLETE_EXT
		else if ( en == GL_FRAMEBUFFER_COMPLETE_EXT ) ostr << "GL_FRAMEBUFFER_COMPLETE_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_UNSUPPORTED_EXT
		else if ( en == GL_FRAMEBUFFER_UNSUPPORTED_EXT ) ostr << "GL_FRAMEBUFFER_UNSUPPORTED_EXT";
	#endif
	#ifdef GL_MAX_COLOR_ATTACHMENTS_EXT
		else if ( en == GL_MAX_COLOR_ATTACHMENTS_EXT ) ostr << "GL_MAX_COLOR_ATTACHMENTS_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT0_EXT
		else if ( en == GL_COLOR_ATTACHMENT0_EXT ) ostr << "GL_COLOR_ATTACHMENT0_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT1_EXT
		else if ( en == GL_COLOR_ATTACHMENT1_EXT ) ostr << "GL_COLOR_ATTACHMENT1_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT2_EXT
		else if ( en == GL_COLOR_ATTACHMENT2_EXT ) ostr << "GL_COLOR_ATTACHMENT2_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT3_EXT
		else if ( en == GL_COLOR_ATTACHMENT3_EXT ) ostr << "GL_COLOR_ATTACHMENT3_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT4_EXT
		else if ( en == GL_COLOR_ATTACHMENT4_EXT ) ostr << "GL_COLOR_ATTACHMENT4_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT5_EXT
		else if ( en == GL_COLOR_ATTACHMENT5_EXT ) ostr << "GL_COLOR_ATTACHMENT5_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT6_EXT
		else if ( en == GL_COLOR_ATTACHMENT6_EXT ) ostr << "GL_COLOR_ATTACHMENT6_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT7_EXT
		else if ( en == GL_COLOR_ATTACHMENT7_EXT ) ostr << "GL_COLOR_ATTACHMENT7_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT8_EXT
		else if ( en == GL_COLOR_ATTACHMENT8_EXT ) ostr << "GL_COLOR_ATTACHMENT8_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT9_EXT
		else if ( en == GL_COLOR_ATTACHMENT9_EXT ) ostr << "GL_COLOR_ATTACHMENT9_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT10_EXT
		else if ( en == GL_COLOR_ATTACHMENT10_EXT ) ostr << "GL_COLOR_ATTACHMENT10_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT11_EXT
		else if ( en == GL_COLOR_ATTACHMENT11_EXT ) ostr << "GL_COLOR_ATTACHMENT11_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT12_EXT
		else if ( en == GL_COLOR_ATTACHMENT12_EXT ) ostr << "GL_COLOR_ATTACHMENT12_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT13_EXT
		else if ( en == GL_COLOR_ATTACHMENT13_EXT ) ostr << "GL_COLOR_ATTACHMENT13_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT14_EXT
		else if ( en == GL_COLOR_ATTACHMENT14_EXT ) ostr << "GL_COLOR_ATTACHMENT14_EXT";
	#endif
	#ifdef GL_COLOR_ATTACHMENT15_EXT
		else if ( en == GL_COLOR_ATTACHMENT15_EXT ) ostr << "GL_COLOR_ATTACHMENT15_EXT";
	#endif
	#ifdef GL_DEPTH_ATTACHMENT_EXT
		else if ( en == GL_DEPTH_ATTACHMENT_EXT ) ostr << "GL_DEPTH_ATTACHMENT_EXT";
	#endif
	#ifdef GL_STENCIL_ATTACHMENT_EXT
		else if ( en == GL_STENCIL_ATTACHMENT_EXT ) ostr << "GL_STENCIL_ATTACHMENT_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_EXT
		else if ( en == GL_FRAMEBUFFER_EXT ) ostr << "GL_FRAMEBUFFER_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_EXT
		else if ( en == GL_RENDERBUFFER_EXT ) ostr << "GL_RENDERBUFFER_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_WIDTH_EXT
		else if ( en == GL_RENDERBUFFER_WIDTH_EXT ) ostr << "GL_RENDERBUFFER_WIDTH_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_HEIGHT_EXT
		else if ( en == GL_RENDERBUFFER_HEIGHT_EXT ) ostr << "GL_RENDERBUFFER_HEIGHT_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT_EXT
		else if ( en == GL_RENDERBUFFER_INTERNAL_FORMAT_EXT ) ostr << "GL_RENDERBUFFER_INTERNAL_FORMAT_EXT";
	#endif
	#ifdef GL_STENCIL_INDEX1_EXT
		else if ( en == GL_STENCIL_INDEX1_EXT ) ostr << "GL_STENCIL_INDEX1_EXT";
	#endif
	#ifdef GL_STENCIL_INDEX4_EXT
		else if ( en == GL_STENCIL_INDEX4_EXT ) ostr << "GL_STENCIL_INDEX4_EXT";
	#endif
	#ifdef GL_STENCIL_INDEX8_EXT
		else if ( en == GL_STENCIL_INDEX8_EXT ) ostr << "GL_STENCIL_INDEX8_EXT";
	#endif
	#ifdef GL_STENCIL_INDEX16_EXT
		else if ( en == GL_STENCIL_INDEX16_EXT ) ostr << "GL_STENCIL_INDEX16_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_RED_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_RED_SIZE_EXT ) ostr << "GL_RENDERBUFFER_RED_SIZE_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_GREEN_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_GREEN_SIZE_EXT ) ostr << "GL_RENDERBUFFER_GREEN_SIZE_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_BLUE_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_BLUE_SIZE_EXT ) ostr << "GL_RENDERBUFFER_BLUE_SIZE_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_ALPHA_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_ALPHA_SIZE_EXT ) ostr << "GL_RENDERBUFFER_ALPHA_SIZE_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_DEPTH_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_DEPTH_SIZE_EXT ) ostr << "GL_RENDERBUFFER_DEPTH_SIZE_EXT";
	#endif
	#ifdef GL_RENDERBUFFER_STENCIL_SIZE_EXT
		else if ( en == GL_RENDERBUFFER_STENCIL_SIZE_EXT ) ostr << "GL_RENDERBUFFER_STENCIL_SIZE_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_SRGB_EXT
		else if ( en == GL_FRAMEBUFFER_SRGB_EXT ) ostr << "GL_FRAMEBUFFER_SRGB_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
		else if ( en == GL_FRAMEBUFFER_SRGB_CAPABLE_EXT ) ostr << "GL_FRAMEBUFFER_SRGB_CAPABLE_EXT";
	#endif
	#ifdef GL_LINES_ADJACENCY_EXT
		else if ( en == GL_LINES_ADJACENCY_EXT ) ostr << "GL_LINES_ADJACENCY_EXT";
	#endif
	#ifdef GL_LINE_STRIP_ADJACENCY_EXT
		else if ( en == GL_LINE_STRIP_ADJACENCY_EXT ) ostr << "GL_LINE_STRIP_ADJACENCY_EXT";
	#endif
	#ifdef GL_TRIANGLES_ADJACENCY_EXT
		else if ( en == GL_TRIANGLES_ADJACENCY_EXT ) ostr << "GL_TRIANGLES_ADJACENCY_EXT";
	#endif
	#ifdef GL_TRIANGLE_STRIP_ADJACENCY_EXT
		else if ( en == GL_TRIANGLE_STRIP_ADJACENCY_EXT ) ostr << "GL_TRIANGLE_STRIP_ADJACENCY_EXT";
	#endif
	#ifdef GL_PROGRAM_POINT_SIZE_EXT
		else if ( en == GL_PROGRAM_POINT_SIZE_EXT ) ostr << "GL_PROGRAM_POINT_SIZE_EXT";
	#endif
	#ifdef GL_MAX_VARYING_COMPONENTS_EXT
		else if ( en == GL_MAX_VARYING_COMPONENTS_EXT ) ostr << "GL_MAX_VARYING_COMPONENTS_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT
		else if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT ) ostr << "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT
		else if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT ) ostr << "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT
		else if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT ) ostr << "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT";
	#endif
	#ifdef GL_GEOMETRY_SHADER_EXT
		else if ( en == GL_GEOMETRY_SHADER_EXT ) ostr << "GL_GEOMETRY_SHADER_EXT";
	#endif
	#ifdef GL_GEOMETRY_VERTICES_OUT_EXT
		else if ( en == GL_GEOMETRY_VERTICES_OUT_EXT ) ostr << "GL_GEOMETRY_VERTICES_OUT_EXT";
	#endif
	#ifdef GL_GEOMETRY_INPUT_TYPE_EXT
		else if ( en == GL_GEOMETRY_INPUT_TYPE_EXT ) ostr << "GL_GEOMETRY_INPUT_TYPE_EXT";
	#endif
	#ifdef GL_GEOMETRY_OUTPUT_TYPE_EXT
		else if ( en == GL_GEOMETRY_OUTPUT_TYPE_EXT ) ostr << "GL_GEOMETRY_OUTPUT_TYPE_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT
		else if ( en == GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT ) ostr << "GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_VARYING_COMPONENTS_EXT
		else if ( en == GL_MAX_VERTEX_VARYING_COMPONENTS_EXT ) ostr << "GL_MAX_VERTEX_VARYING_COMPONENTS_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT
		else if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT ) ostr << "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT
		else if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT ) ostr << "GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT";
	#endif
	#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT
		else if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT ) ostr << "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT ) ostr << "GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT";
	#endif
	#ifdef GL_SAMPLER_1D_ARRAY_EXT
		else if ( en == GL_SAMPLER_1D_ARRAY_EXT ) ostr << "GL_SAMPLER_1D_ARRAY_EXT";
	#endif
	#ifdef GL_SAMPLER_2D_ARRAY_EXT
		else if ( en == GL_SAMPLER_2D_ARRAY_EXT ) ostr << "GL_SAMPLER_2D_ARRAY_EXT";
	#endif
	#ifdef GL_SAMPLER_BUFFER_EXT
		else if ( en == GL_SAMPLER_BUFFER_EXT ) ostr << "GL_SAMPLER_BUFFER_EXT";
	#endif
	#ifdef GL_SAMPLER_1D_ARRAY_SHADOW_EXT
		else if ( en == GL_SAMPLER_1D_ARRAY_SHADOW_EXT ) ostr << "GL_SAMPLER_1D_ARRAY_SHADOW_EXT";
	#endif
	#ifdef GL_SAMPLER_2D_ARRAY_SHADOW_EXT
		else if ( en == GL_SAMPLER_2D_ARRAY_SHADOW_EXT ) ostr << "GL_SAMPLER_2D_ARRAY_SHADOW_EXT";
	#endif
	#ifdef GL_SAMPLER_CUBE_SHADOW_EXT
		else if ( en == GL_SAMPLER_CUBE_SHADOW_EXT ) ostr << "GL_SAMPLER_CUBE_SHADOW_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC2_EXT
		else if ( en == GL_UNSIGNED_INT_VEC2_EXT ) ostr << "GL_UNSIGNED_INT_VEC2_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC3_EXT
		else if ( en == GL_UNSIGNED_INT_VEC3_EXT ) ostr << "GL_UNSIGNED_INT_VEC3_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_VEC4_EXT
		else if ( en == GL_UNSIGNED_INT_VEC4_EXT ) ostr << "GL_UNSIGNED_INT_VEC4_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_1D_EXT
		else if ( en == GL_INT_SAMPLER_1D_EXT ) ostr << "GL_INT_SAMPLER_1D_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_2D_EXT
		else if ( en == GL_INT_SAMPLER_2D_EXT ) ostr << "GL_INT_SAMPLER_2D_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_3D_EXT
		else if ( en == GL_INT_SAMPLER_3D_EXT ) ostr << "GL_INT_SAMPLER_3D_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_CUBE_EXT
		else if ( en == GL_INT_SAMPLER_CUBE_EXT ) ostr << "GL_INT_SAMPLER_CUBE_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_2D_RECT_EXT
		else if ( en == GL_INT_SAMPLER_2D_RECT_EXT ) ostr << "GL_INT_SAMPLER_2D_RECT_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_1D_ARRAY_EXT
		else if ( en == GL_INT_SAMPLER_1D_ARRAY_EXT ) ostr << "GL_INT_SAMPLER_1D_ARRAY_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_2D_ARRAY_EXT
		else if ( en == GL_INT_SAMPLER_2D_ARRAY_EXT ) ostr << "GL_INT_SAMPLER_2D_ARRAY_EXT";
	#endif
	#ifdef GL_INT_SAMPLER_BUFFER_EXT
		else if ( en == GL_INT_SAMPLER_BUFFER_EXT ) ostr << "GL_INT_SAMPLER_BUFFER_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_1D_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_1D_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_1D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_3D_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_3D_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_3D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_CUBE_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT
		else if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT ) ostr << "GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT";
	#endif
	#ifdef GL_HISTOGRAM_EXT
		else if ( en == GL_HISTOGRAM_EXT ) ostr << "GL_HISTOGRAM_EXT";
	#endif
	#ifdef GL_PROXY_HISTOGRAM_EXT
		else if ( en == GL_PROXY_HISTOGRAM_EXT ) ostr << "GL_PROXY_HISTOGRAM_EXT";
	#endif
	#ifdef GL_HISTOGRAM_WIDTH_EXT
		else if ( en == GL_HISTOGRAM_WIDTH_EXT ) ostr << "GL_HISTOGRAM_WIDTH_EXT";
	#endif
	#ifdef GL_HISTOGRAM_FORMAT_EXT
		else if ( en == GL_HISTOGRAM_FORMAT_EXT ) ostr << "GL_HISTOGRAM_FORMAT_EXT";
	#endif
	#ifdef GL_HISTOGRAM_RED_SIZE_EXT
		else if ( en == GL_HISTOGRAM_RED_SIZE_EXT ) ostr << "GL_HISTOGRAM_RED_SIZE_EXT";
	#endif
	#ifdef GL_HISTOGRAM_GREEN_SIZE_EXT
		else if ( en == GL_HISTOGRAM_GREEN_SIZE_EXT ) ostr << "GL_HISTOGRAM_GREEN_SIZE_EXT";
	#endif
	#ifdef GL_HISTOGRAM_BLUE_SIZE_EXT
		else if ( en == GL_HISTOGRAM_BLUE_SIZE_EXT ) ostr << "GL_HISTOGRAM_BLUE_SIZE_EXT";
	#endif
	#ifdef GL_HISTOGRAM_ALPHA_SIZE_EXT
		else if ( en == GL_HISTOGRAM_ALPHA_SIZE_EXT ) ostr << "GL_HISTOGRAM_ALPHA_SIZE_EXT";
	#endif
	#ifdef GL_HISTOGRAM_LUMINANCE_SIZE_EXT
		else if ( en == GL_HISTOGRAM_LUMINANCE_SIZE_EXT ) ostr << "GL_HISTOGRAM_LUMINANCE_SIZE_EXT";
	#endif
	#ifdef GL_HISTOGRAM_SINK_EXT
		else if ( en == GL_HISTOGRAM_SINK_EXT ) ostr << "GL_HISTOGRAM_SINK_EXT";
	#endif
	#ifdef GL_MINMAX_EXT
		else if ( en == GL_MINMAX_EXT ) ostr << "GL_MINMAX_EXT";
	#endif
	#ifdef GL_MINMAX_FORMAT_EXT
		else if ( en == GL_MINMAX_FORMAT_EXT ) ostr << "GL_MINMAX_FORMAT_EXT";
	#endif
	#ifdef GL_MINMAX_SINK_EXT
		else if ( en == GL_MINMAX_SINK_EXT ) ostr << "GL_MINMAX_SINK_EXT";
	#endif
	#ifdef GL_FRAGMENT_MATERIAL_EXT
		else if ( en == GL_FRAGMENT_MATERIAL_EXT ) ostr << "GL_FRAGMENT_MATERIAL_EXT";
	#endif
	#ifdef GL_FRAGMENT_NORMAL_EXT
		else if ( en == GL_FRAGMENT_NORMAL_EXT ) ostr << "GL_FRAGMENT_NORMAL_EXT";
	#endif
	#ifdef GL_FRAGMENT_COLOR_EXT
		else if ( en == GL_FRAGMENT_COLOR_EXT ) ostr << "GL_FRAGMENT_COLOR_EXT";
	#endif
	#ifdef GL_ATTENUATION_EXT
		else if ( en == GL_ATTENUATION_EXT ) ostr << "GL_ATTENUATION_EXT";
	#endif
	#ifdef GL_SHADOW_ATTENUATION_EXT
		else if ( en == GL_SHADOW_ATTENUATION_EXT ) ostr << "GL_SHADOW_ATTENUATION_EXT";
	#endif
	#ifdef GL_TEXTURE_APPLICATION_MODE_EXT
		else if ( en == GL_TEXTURE_APPLICATION_MODE_EXT ) ostr << "GL_TEXTURE_APPLICATION_MODE_EXT";
	#endif
	#ifdef GL_TEXTURE_LIGHT_EXT
		else if ( en == GL_TEXTURE_LIGHT_EXT ) ostr << "GL_TEXTURE_LIGHT_EXT";
	#endif
	#ifdef GL_TEXTURE_MATERIAL_FACE_EXT
		else if ( en == GL_TEXTURE_MATERIAL_FACE_EXT ) ostr << "GL_TEXTURE_MATERIAL_FACE_EXT";
	#endif
	#ifdef GL_TEXTURE_MATERIAL_PARAMETER_EXT
		else if ( en == GL_TEXTURE_MATERIAL_PARAMETER_EXT ) ostr << "GL_TEXTURE_MATERIAL_PARAMETER_EXT";
	#endif
	#ifdef GL_MULTISAMPLE_EXT
		else if ( en == GL_MULTISAMPLE_EXT ) ostr << "GL_MULTISAMPLE_EXT";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_MASK_EXT
		else if ( en == GL_SAMPLE_ALPHA_TO_MASK_EXT ) ostr << "GL_SAMPLE_ALPHA_TO_MASK_EXT";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_ONE_EXT
		else if ( en == GL_SAMPLE_ALPHA_TO_ONE_EXT ) ostr << "GL_SAMPLE_ALPHA_TO_ONE_EXT";
	#endif
	#ifdef GL_SAMPLE_MASK_EXT
		else if ( en == GL_SAMPLE_MASK_EXT ) ostr << "GL_SAMPLE_MASK_EXT";
	#endif
	#ifdef GL_1PASS_EXT
		else if ( en == GL_1PASS_EXT ) ostr << "GL_1PASS_EXT";
	#endif
	#ifdef GL_2PASS_0_EXT
		else if ( en == GL_2PASS_0_EXT ) ostr << "GL_2PASS_0_EXT";
	#endif
	#ifdef GL_2PASS_1_EXT
		else if ( en == GL_2PASS_1_EXT ) ostr << "GL_2PASS_1_EXT";
	#endif
	#ifdef GL_4PASS_0_EXT
		else if ( en == GL_4PASS_0_EXT ) ostr << "GL_4PASS_0_EXT";
	#endif
	#ifdef GL_4PASS_1_EXT
		else if ( en == GL_4PASS_1_EXT ) ostr << "GL_4PASS_1_EXT";
	#endif
	#ifdef GL_4PASS_2_EXT
		else if ( en == GL_4PASS_2_EXT ) ostr << "GL_4PASS_2_EXT";
	#endif
	#ifdef GL_4PASS_3_EXT
		else if ( en == GL_4PASS_3_EXT ) ostr << "GL_4PASS_3_EXT";
	#endif
	#ifdef GL_SAMPLE_BUFFERS_EXT
		else if ( en == GL_SAMPLE_BUFFERS_EXT ) ostr << "GL_SAMPLE_BUFFERS_EXT";
	#endif
	#ifdef GL_SAMPLES_EXT
		else if ( en == GL_SAMPLES_EXT ) ostr << "GL_SAMPLES_EXT";
	#endif
	#ifdef GL_SAMPLE_MASK_VALUE_EXT
		else if ( en == GL_SAMPLE_MASK_VALUE_EXT ) ostr << "GL_SAMPLE_MASK_VALUE_EXT";
	#endif
	#ifdef GL_SAMPLE_MASK_INVERT_EXT
		else if ( en == GL_SAMPLE_MASK_INVERT_EXT ) ostr << "GL_SAMPLE_MASK_INVERT_EXT";
	#endif
	#ifdef GL_SAMPLE_PATTERN_EXT
		else if ( en == GL_SAMPLE_PATTERN_EXT ) ostr << "GL_SAMPLE_PATTERN_EXT";
	#endif
	#ifdef GL_MULTISAMPLE_BIT_EXT
		else if ( en == GL_MULTISAMPLE_BIT_EXT ) ostr << "GL_MULTISAMPLE_BIT_EXT";
	#endif
	#ifdef GL_DEPTH_STENCIL_EXT
		else if ( en == GL_DEPTH_STENCIL_EXT ) ostr << "GL_DEPTH_STENCIL_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_24_8_EXT
		else if ( en == GL_UNSIGNED_INT_24_8_EXT ) ostr << "GL_UNSIGNED_INT_24_8_EXT";
	#endif
	#ifdef GL_DEPTH24_STENCIL8_EXT
		else if ( en == GL_DEPTH24_STENCIL8_EXT ) ostr << "GL_DEPTH24_STENCIL8_EXT";
	#endif
	#ifdef GL_TEXTURE_STENCIL_SIZE_EXT
		else if ( en == GL_TEXTURE_STENCIL_SIZE_EXT ) ostr << "GL_TEXTURE_STENCIL_SIZE_EXT";
	#endif
	#ifdef GL_R11F_G11F_B10F_EXT
		else if ( en == GL_R11F_G11F_B10F_EXT ) ostr << "GL_R11F_G11F_B10F_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV_EXT
		else if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV_EXT ) ostr << "GL_UNSIGNED_INT_10F_11F_11F_REV_EXT";
	#endif
	#ifdef GL_RGBA_SIGNED_COMPONENTS_EXT
		else if ( en == GL_RGBA_SIGNED_COMPONENTS_EXT ) ostr << "GL_RGBA_SIGNED_COMPONENTS_EXT";
	#endif
	#ifdef GL_UNSIGNED_BYTE_3_3_2_EXT
		else if ( en == GL_UNSIGNED_BYTE_3_3_2_EXT ) ostr << "GL_UNSIGNED_BYTE_3_3_2_EXT";
	#endif
	#ifdef GL_UNSIGNED_SHORT_4_4_4_4_EXT
		else if ( en == GL_UNSIGNED_SHORT_4_4_4_4_EXT ) ostr << "GL_UNSIGNED_SHORT_4_4_4_4_EXT";
	#endif
	#ifdef GL_UNSIGNED_SHORT_5_5_5_1_EXT
		else if ( en == GL_UNSIGNED_SHORT_5_5_5_1_EXT ) ostr << "GL_UNSIGNED_SHORT_5_5_5_1_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_8_8_8_8_EXT
		else if ( en == GL_UNSIGNED_INT_8_8_8_8_EXT ) ostr << "GL_UNSIGNED_INT_8_8_8_8_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_10_10_10_2_EXT
		else if ( en == GL_UNSIGNED_INT_10_10_10_2_EXT ) ostr << "GL_UNSIGNED_INT_10_10_10_2_EXT";
	#endif
	#ifdef GL_TEXTURE_1D
		else if ( en == GL_TEXTURE_1D ) ostr << "GL_TEXTURE_1D";
	#endif
	#ifdef GL_TEXTURE_2D
		else if ( en == GL_TEXTURE_2D ) ostr << "GL_TEXTURE_2D";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D
		else if ( en == GL_PROXY_TEXTURE_1D ) ostr << "GL_PROXY_TEXTURE_1D";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D
		else if ( en == GL_PROXY_TEXTURE_2D ) ostr << "GL_PROXY_TEXTURE_2D";
	#endif
	#ifdef GL_COLOR_TABLE_FORMAT_EXT
		else if ( en == GL_COLOR_TABLE_FORMAT_EXT ) ostr << "GL_COLOR_TABLE_FORMAT_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_WIDTH_EXT
		else if ( en == GL_COLOR_TABLE_WIDTH_EXT ) ostr << "GL_COLOR_TABLE_WIDTH_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_RED_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_RED_SIZE_EXT ) ostr << "GL_COLOR_TABLE_RED_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_GREEN_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_GREEN_SIZE_EXT ) ostr << "GL_COLOR_TABLE_GREEN_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_BLUE_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_BLUE_SIZE_EXT ) ostr << "GL_COLOR_TABLE_BLUE_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_ALPHA_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_ALPHA_SIZE_EXT ) ostr << "GL_COLOR_TABLE_ALPHA_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE_EXT ) ostr << "GL_COLOR_TABLE_LUMINANCE_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_TABLE_INTENSITY_SIZE_EXT
		else if ( en == GL_COLOR_TABLE_INTENSITY_SIZE_EXT ) ostr << "GL_COLOR_TABLE_INTENSITY_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_INDEX1_EXT
		else if ( en == GL_COLOR_INDEX1_EXT ) ostr << "GL_COLOR_INDEX1_EXT";
	#endif
	#ifdef GL_COLOR_INDEX2_EXT
		else if ( en == GL_COLOR_INDEX2_EXT ) ostr << "GL_COLOR_INDEX2_EXT";
	#endif
	#ifdef GL_COLOR_INDEX4_EXT
		else if ( en == GL_COLOR_INDEX4_EXT ) ostr << "GL_COLOR_INDEX4_EXT";
	#endif
	#ifdef GL_COLOR_INDEX8_EXT
		else if ( en == GL_COLOR_INDEX8_EXT ) ostr << "GL_COLOR_INDEX8_EXT";
	#endif
	#ifdef GL_COLOR_INDEX12_EXT
		else if ( en == GL_COLOR_INDEX12_EXT ) ostr << "GL_COLOR_INDEX12_EXT";
	#endif
	#ifdef GL_COLOR_INDEX16_EXT
		else if ( en == GL_COLOR_INDEX16_EXT ) ostr << "GL_COLOR_INDEX16_EXT";
	#endif
	#ifdef GL_TEXTURE_INDEX_SIZE_EXT
		else if ( en == GL_TEXTURE_INDEX_SIZE_EXT ) ostr << "GL_TEXTURE_INDEX_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_ARB
		else if ( en == GL_TEXTURE_CUBE_MAP_ARB ) ostr << "GL_TEXTURE_CUBE_MAP_ARB";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARB
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARB ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP_ARB";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER_EXT
		else if ( en == GL_PIXEL_PACK_BUFFER_EXT ) ostr << "GL_PIXEL_PACK_BUFFER_EXT";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER_EXT
		else if ( en == GL_PIXEL_UNPACK_BUFFER_EXT ) ostr << "GL_PIXEL_UNPACK_BUFFER_EXT";
	#endif
	#ifdef GL_PIXEL_PACK_BUFFER_BINDING_EXT
		else if ( en == GL_PIXEL_PACK_BUFFER_BINDING_EXT ) ostr << "GL_PIXEL_PACK_BUFFER_BINDING_EXT";
	#endif
	#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING_EXT
		else if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING_EXT ) ostr << "GL_PIXEL_UNPACK_BUFFER_BINDING_EXT";
	#endif
	#ifdef GL_PIXEL_TRANSFORM_2D_EXT
		else if ( en == GL_PIXEL_TRANSFORM_2D_EXT ) ostr << "GL_PIXEL_TRANSFORM_2D_EXT";
	#endif
	#ifdef GL_PIXEL_MAG_FILTER_EXT
		else if ( en == GL_PIXEL_MAG_FILTER_EXT ) ostr << "GL_PIXEL_MAG_FILTER_EXT";
	#endif
	#ifdef GL_PIXEL_MIN_FILTER_EXT
		else if ( en == GL_PIXEL_MIN_FILTER_EXT ) ostr << "GL_PIXEL_MIN_FILTER_EXT";
	#endif
	#ifdef GL_PIXEL_CUBIC_WEIGHT_EXT
		else if ( en == GL_PIXEL_CUBIC_WEIGHT_EXT ) ostr << "GL_PIXEL_CUBIC_WEIGHT_EXT";
	#endif
	#ifdef GL_CUBIC_EXT
		else if ( en == GL_CUBIC_EXT ) ostr << "GL_CUBIC_EXT";
	#endif
	#ifdef GL_AVERAGE_EXT
		else if ( en == GL_AVERAGE_EXT ) ostr << "GL_AVERAGE_EXT";
	#endif
	#ifdef GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT
		else if ( en == GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT ) ostr << "GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT";
	#endif
	#ifdef GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT
		else if ( en == GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT ) ostr << "GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT";
	#endif
	#ifdef GL_PIXEL_TRANSFORM_2D_MATRIX_EXT
		else if ( en == GL_PIXEL_TRANSFORM_2D_MATRIX_EXT ) ostr << "GL_PIXEL_TRANSFORM_2D_MATRIX_EXT";
	#endif
	#ifdef GL_POINT_SIZE_MIN_EXT
		else if ( en == GL_POINT_SIZE_MIN_EXT ) ostr << "GL_POINT_SIZE_MIN_EXT";
	#endif
	#ifdef GL_POINT_SIZE_MAX_EXT
		else if ( en == GL_POINT_SIZE_MAX_EXT ) ostr << "GL_POINT_SIZE_MAX_EXT";
	#endif
	#ifdef GL_POINT_FADE_THRESHOLD_SIZE_EXT
		else if ( en == GL_POINT_FADE_THRESHOLD_SIZE_EXT ) ostr << "GL_POINT_FADE_THRESHOLD_SIZE_EXT";
	#endif
	#ifdef GL_DISTANCE_ATTENUATION_EXT
		else if ( en == GL_DISTANCE_ATTENUATION_EXT ) ostr << "GL_DISTANCE_ATTENUATION_EXT";
	#endif
	#ifdef GL_POLYGON_OFFSET_EXT
		else if ( en == GL_POLYGON_OFFSET_EXT ) ostr << "GL_POLYGON_OFFSET_EXT";
	#endif
	#ifdef GL_POLYGON_OFFSET_FACTOR_EXT
		else if ( en == GL_POLYGON_OFFSET_FACTOR_EXT ) ostr << "GL_POLYGON_OFFSET_FACTOR_EXT";
	#endif
	#ifdef GL_POLYGON_OFFSET_BIAS_EXT
		else if ( en == GL_POLYGON_OFFSET_BIAS_EXT ) ostr << "GL_POLYGON_OFFSET_BIAS_EXT";
	#endif
	#ifdef GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT
		else if ( en == GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT ) ostr << "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT";
	#endif
	#ifdef GL_FIRST_VERTEX_CONVENTION_EXT
		else if ( en == GL_FIRST_VERTEX_CONVENTION_EXT ) ostr << "GL_FIRST_VERTEX_CONVENTION_EXT";
	#endif
	#ifdef GL_LAST_VERTEX_CONVENTION_EXT
		else if ( en == GL_LAST_VERTEX_CONVENTION_EXT ) ostr << "GL_LAST_VERTEX_CONVENTION_EXT";
	#endif
	#ifdef GL_PROVOKING_VERTEX_EXT
		else if ( en == GL_PROVOKING_VERTEX_EXT ) ostr << "GL_PROVOKING_VERTEX_EXT";
	#endif
	#ifdef GL_RESCALE_NORMAL_EXT
		else if ( en == GL_RESCALE_NORMAL_EXT ) ostr << "GL_RESCALE_NORMAL_EXT";
	#endif
	#ifdef GL_COLOR_SUM_EXT
		else if ( en == GL_COLOR_SUM_EXT ) ostr << "GL_COLOR_SUM_EXT";
	#endif
	#ifdef GL_CURRENT_SECONDARY_COLOR_EXT
		else if ( en == GL_CURRENT_SECONDARY_COLOR_EXT ) ostr << "GL_CURRENT_SECONDARY_COLOR_EXT";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_SIZE_EXT
		else if ( en == GL_SECONDARY_COLOR_ARRAY_SIZE_EXT ) ostr << "GL_SECONDARY_COLOR_ARRAY_SIZE_EXT";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_TYPE_EXT
		else if ( en == GL_SECONDARY_COLOR_ARRAY_TYPE_EXT ) ostr << "GL_SECONDARY_COLOR_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT
		else if ( en == GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT ) ostr << "GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_POINTER_EXT
		else if ( en == GL_SECONDARY_COLOR_ARRAY_POINTER_EXT ) ostr << "GL_SECONDARY_COLOR_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_EXT
		else if ( en == GL_SECONDARY_COLOR_ARRAY_EXT ) ostr << "GL_SECONDARY_COLOR_ARRAY_EXT";
	#endif
	#ifdef GL_ACTIVE_PROGRAM_EXT
		else if ( en == GL_ACTIVE_PROGRAM_EXT ) ostr << "GL_ACTIVE_PROGRAM_EXT";
	#endif
	#ifdef GL_LIGHT_MODEL_COLOR_CONTROL_EXT
		else if ( en == GL_LIGHT_MODEL_COLOR_CONTROL_EXT ) ostr << "GL_LIGHT_MODEL_COLOR_CONTROL_EXT";
	#endif
	#ifdef GL_SINGLE_COLOR_EXT
		else if ( en == GL_SINGLE_COLOR_EXT ) ostr << "GL_SINGLE_COLOR_EXT";
	#endif
	#ifdef GL_SEPARATE_SPECULAR_COLOR_EXT
		else if ( en == GL_SEPARATE_SPECULAR_COLOR_EXT ) ostr << "GL_SEPARATE_SPECULAR_COLOR_EXT";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT ) ostr << "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT_EXT
		else if ( en == GL_ELEMENT_ARRAY_BARRIER_BIT_EXT ) ostr << "GL_ELEMENT_ARRAY_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_UNIFORM_BARRIER_BIT_EXT
		else if ( en == GL_UNIFORM_BARRIER_BIT_EXT ) ostr << "GL_UNIFORM_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_TEXTURE_FETCH_BARRIER_BIT_EXT
		else if ( en == GL_TEXTURE_FETCH_BARRIER_BIT_EXT ) ostr << "GL_TEXTURE_FETCH_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT
		else if ( en == GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT ) ostr << "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_COMMAND_BARRIER_BIT_EXT
		else if ( en == GL_COMMAND_BARRIER_BIT_EXT ) ostr << "GL_COMMAND_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_PIXEL_BUFFER_BARRIER_BIT_EXT
		else if ( en == GL_PIXEL_BUFFER_BARRIER_BIT_EXT ) ostr << "GL_PIXEL_BUFFER_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT_EXT
		else if ( en == GL_TEXTURE_UPDATE_BARRIER_BIT_EXT ) ostr << "GL_TEXTURE_UPDATE_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_BUFFER_UPDATE_BARRIER_BIT_EXT
		else if ( en == GL_BUFFER_UPDATE_BARRIER_BIT_EXT ) ostr << "GL_BUFFER_UPDATE_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_FRAMEBUFFER_BARRIER_BIT_EXT
		else if ( en == GL_FRAMEBUFFER_BARRIER_BIT_EXT ) ostr << "GL_FRAMEBUFFER_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT_EXT
		else if ( en == GL_ATOMIC_COUNTER_BARRIER_BIT_EXT ) ostr << "GL_ATOMIC_COUNTER_BARRIER_BIT_EXT";
	#endif
	#ifdef GL_MAX_IMAGE_UNITS_EXT
		else if ( en == GL_MAX_IMAGE_UNITS_EXT ) ostr << "GL_MAX_IMAGE_UNITS_EXT";
	#endif
	#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT
		else if ( en == GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT ) ostr << "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_NAME_EXT
		else if ( en == GL_IMAGE_BINDING_NAME_EXT ) ostr << "GL_IMAGE_BINDING_NAME_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_LEVEL_EXT
		else if ( en == GL_IMAGE_BINDING_LEVEL_EXT ) ostr << "GL_IMAGE_BINDING_LEVEL_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_LAYERED_EXT
		else if ( en == GL_IMAGE_BINDING_LAYERED_EXT ) ostr << "GL_IMAGE_BINDING_LAYERED_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_LAYER_EXT
		else if ( en == GL_IMAGE_BINDING_LAYER_EXT ) ostr << "GL_IMAGE_BINDING_LAYER_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_ACCESS_EXT
		else if ( en == GL_IMAGE_BINDING_ACCESS_EXT ) ostr << "GL_IMAGE_BINDING_ACCESS_EXT";
	#endif
	#ifdef GL_IMAGE_1D_EXT
		else if ( en == GL_IMAGE_1D_EXT ) ostr << "GL_IMAGE_1D_EXT";
	#endif
	#ifdef GL_IMAGE_2D_EXT
		else if ( en == GL_IMAGE_2D_EXT ) ostr << "GL_IMAGE_2D_EXT";
	#endif
	#ifdef GL_IMAGE_3D_EXT
		else if ( en == GL_IMAGE_3D_EXT ) ostr << "GL_IMAGE_3D_EXT";
	#endif
	#ifdef GL_IMAGE_2D_RECT_EXT
		else if ( en == GL_IMAGE_2D_RECT_EXT ) ostr << "GL_IMAGE_2D_RECT_EXT";
	#endif
	#ifdef GL_IMAGE_CUBE_EXT
		else if ( en == GL_IMAGE_CUBE_EXT ) ostr << "GL_IMAGE_CUBE_EXT";
	#endif
	#ifdef GL_IMAGE_BUFFER_EXT
		else if ( en == GL_IMAGE_BUFFER_EXT ) ostr << "GL_IMAGE_BUFFER_EXT";
	#endif
	#ifdef GL_IMAGE_1D_ARRAY_EXT
		else if ( en == GL_IMAGE_1D_ARRAY_EXT ) ostr << "GL_IMAGE_1D_ARRAY_EXT";
	#endif
	#ifdef GL_IMAGE_2D_ARRAY_EXT
		else if ( en == GL_IMAGE_2D_ARRAY_EXT ) ostr << "GL_IMAGE_2D_ARRAY_EXT";
	#endif
	#ifdef GL_IMAGE_CUBE_MAP_ARRAY_EXT
		else if ( en == GL_IMAGE_CUBE_MAP_ARRAY_EXT ) ostr << "GL_IMAGE_CUBE_MAP_ARRAY_EXT";
	#endif
	#ifdef GL_IMAGE_2D_MULTISAMPLE_EXT
		else if ( en == GL_IMAGE_2D_MULTISAMPLE_EXT ) ostr << "GL_IMAGE_2D_MULTISAMPLE_EXT";
	#endif
	#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
		else if ( en == GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) ostr << "GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
	#endif
	#ifdef GL_INT_IMAGE_1D_EXT
		else if ( en == GL_INT_IMAGE_1D_EXT ) ostr << "GL_INT_IMAGE_1D_EXT";
	#endif
	#ifdef GL_INT_IMAGE_2D_EXT
		else if ( en == GL_INT_IMAGE_2D_EXT ) ostr << "GL_INT_IMAGE_2D_EXT";
	#endif
	#ifdef GL_INT_IMAGE_3D_EXT
		else if ( en == GL_INT_IMAGE_3D_EXT ) ostr << "GL_INT_IMAGE_3D_EXT";
	#endif
	#ifdef GL_INT_IMAGE_2D_RECT_EXT
		else if ( en == GL_INT_IMAGE_2D_RECT_EXT ) ostr << "GL_INT_IMAGE_2D_RECT_EXT";
	#endif
	#ifdef GL_INT_IMAGE_CUBE_EXT
		else if ( en == GL_INT_IMAGE_CUBE_EXT ) ostr << "GL_INT_IMAGE_CUBE_EXT";
	#endif
	#ifdef GL_INT_IMAGE_BUFFER_EXT
		else if ( en == GL_INT_IMAGE_BUFFER_EXT ) ostr << "GL_INT_IMAGE_BUFFER_EXT";
	#endif
	#ifdef GL_INT_IMAGE_1D_ARRAY_EXT
		else if ( en == GL_INT_IMAGE_1D_ARRAY_EXT ) ostr << "GL_INT_IMAGE_1D_ARRAY_EXT";
	#endif
	#ifdef GL_INT_IMAGE_2D_ARRAY_EXT
		else if ( en == GL_INT_IMAGE_2D_ARRAY_EXT ) ostr << "GL_INT_IMAGE_2D_ARRAY_EXT";
	#endif
	#ifdef GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT
		else if ( en == GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT ) ostr << "GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT";
	#endif
	#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_EXT
		else if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_EXT ) ostr << "GL_INT_IMAGE_2D_MULTISAMPLE_EXT";
	#endif
	#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
		else if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) ostr << "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_1D_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_1D_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_1D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_3D_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_3D_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_3D_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_CUBE_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_BUFFER_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_BUFFER_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
		else if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) ostr << "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
	#endif
	#ifdef GL_MAX_IMAGE_SAMPLES_EXT
		else if ( en == GL_MAX_IMAGE_SAMPLES_EXT ) ostr << "GL_MAX_IMAGE_SAMPLES_EXT";
	#endif
	#ifdef GL_IMAGE_BINDING_FORMAT_EXT
		else if ( en == GL_IMAGE_BINDING_FORMAT_EXT ) ostr << "GL_IMAGE_BINDING_FORMAT_EXT";
	#endif
	#ifdef GL_ALL_BARRIER_BITS_EXT
		else if ( en == GL_ALL_BARRIER_BITS_EXT ) ostr << "GL_ALL_BARRIER_BITS_EXT";
	#endif
	#ifdef GL_SHARED_TEXTURE_PALETTE_EXT
		else if ( en == GL_SHARED_TEXTURE_PALETTE_EXT ) ostr << "GL_SHARED_TEXTURE_PALETTE_EXT";
	#endif
	#ifdef GL_STENCIL_TAG_BITS_EXT
		else if ( en == GL_STENCIL_TAG_BITS_EXT ) ostr << "GL_STENCIL_TAG_BITS_EXT";
	#endif
	#ifdef GL_STENCIL_CLEAR_TAG_VALUE_EXT
		else if ( en == GL_STENCIL_CLEAR_TAG_VALUE_EXT ) ostr << "GL_STENCIL_CLEAR_TAG_VALUE_EXT";
	#endif
	#ifdef GL_STENCIL_TEST_TWO_SIDE_EXT
		else if ( en == GL_STENCIL_TEST_TWO_SIDE_EXT ) ostr << "GL_STENCIL_TEST_TWO_SIDE_EXT";
	#endif
	#ifdef GL_ACTIVE_STENCIL_FACE_EXT
		else if ( en == GL_ACTIVE_STENCIL_FACE_EXT ) ostr << "GL_ACTIVE_STENCIL_FACE_EXT";
	#endif
	#ifdef GL_INCR_WRAP_EXT
		else if ( en == GL_INCR_WRAP_EXT ) ostr << "GL_INCR_WRAP_EXT";
	#endif
	#ifdef GL_DECR_WRAP_EXT
		else if ( en == GL_DECR_WRAP_EXT ) ostr << "GL_DECR_WRAP_EXT";
	#endif
	#ifdef GL_ALPHA4_EXT
		else if ( en == GL_ALPHA4_EXT ) ostr << "GL_ALPHA4_EXT";
	#endif
	#ifdef GL_ALPHA8_EXT
		else if ( en == GL_ALPHA8_EXT ) ostr << "GL_ALPHA8_EXT";
	#endif
	#ifdef GL_ALPHA12_EXT
		else if ( en == GL_ALPHA12_EXT ) ostr << "GL_ALPHA12_EXT";
	#endif
	#ifdef GL_ALPHA16_EXT
		else if ( en == GL_ALPHA16_EXT ) ostr << "GL_ALPHA16_EXT";
	#endif
	#ifdef GL_LUMINANCE4_EXT
		else if ( en == GL_LUMINANCE4_EXT ) ostr << "GL_LUMINANCE4_EXT";
	#endif
	#ifdef GL_LUMINANCE8_EXT
		else if ( en == GL_LUMINANCE8_EXT ) ostr << "GL_LUMINANCE8_EXT";
	#endif
	#ifdef GL_LUMINANCE12_EXT
		else if ( en == GL_LUMINANCE12_EXT ) ostr << "GL_LUMINANCE12_EXT";
	#endif
	#ifdef GL_LUMINANCE16_EXT
		else if ( en == GL_LUMINANCE16_EXT ) ostr << "GL_LUMINANCE16_EXT";
	#endif
	#ifdef GL_LUMINANCE4_ALPHA4_EXT
		else if ( en == GL_LUMINANCE4_ALPHA4_EXT ) ostr << "GL_LUMINANCE4_ALPHA4_EXT";
	#endif
	#ifdef GL_LUMINANCE6_ALPHA2_EXT
		else if ( en == GL_LUMINANCE6_ALPHA2_EXT ) ostr << "GL_LUMINANCE6_ALPHA2_EXT";
	#endif
	#ifdef GL_LUMINANCE8_ALPHA8_EXT
		else if ( en == GL_LUMINANCE8_ALPHA8_EXT ) ostr << "GL_LUMINANCE8_ALPHA8_EXT";
	#endif
	#ifdef GL_LUMINANCE12_ALPHA4_EXT
		else if ( en == GL_LUMINANCE12_ALPHA4_EXT ) ostr << "GL_LUMINANCE12_ALPHA4_EXT";
	#endif
	#ifdef GL_LUMINANCE12_ALPHA12_EXT
		else if ( en == GL_LUMINANCE12_ALPHA12_EXT ) ostr << "GL_LUMINANCE12_ALPHA12_EXT";
	#endif
	#ifdef GL_LUMINANCE16_ALPHA16_EXT
		else if ( en == GL_LUMINANCE16_ALPHA16_EXT ) ostr << "GL_LUMINANCE16_ALPHA16_EXT";
	#endif
	#ifdef GL_INTENSITY_EXT
		else if ( en == GL_INTENSITY_EXT ) ostr << "GL_INTENSITY_EXT";
	#endif
	#ifdef GL_INTENSITY4_EXT
		else if ( en == GL_INTENSITY4_EXT ) ostr << "GL_INTENSITY4_EXT";
	#endif
	#ifdef GL_INTENSITY8_EXT
		else if ( en == GL_INTENSITY8_EXT ) ostr << "GL_INTENSITY8_EXT";
	#endif
	#ifdef GL_INTENSITY12_EXT
		else if ( en == GL_INTENSITY12_EXT ) ostr << "GL_INTENSITY12_EXT";
	#endif
	#ifdef GL_INTENSITY16_EXT
		else if ( en == GL_INTENSITY16_EXT ) ostr << "GL_INTENSITY16_EXT";
	#endif
	#ifdef GL_RGB2_EXT
		else if ( en == GL_RGB2_EXT ) ostr << "GL_RGB2_EXT";
	#endif
	#ifdef GL_RGB4_EXT
		else if ( en == GL_RGB4_EXT ) ostr << "GL_RGB4_EXT";
	#endif
	#ifdef GL_RGB5_EXT
		else if ( en == GL_RGB5_EXT ) ostr << "GL_RGB5_EXT";
	#endif
	#ifdef GL_RGB8_EXT
		else if ( en == GL_RGB8_EXT ) ostr << "GL_RGB8_EXT";
	#endif
	#ifdef GL_RGB10_EXT
		else if ( en == GL_RGB10_EXT ) ostr << "GL_RGB10_EXT";
	#endif
	#ifdef GL_RGB12_EXT
		else if ( en == GL_RGB12_EXT ) ostr << "GL_RGB12_EXT";
	#endif
	#ifdef GL_RGB16_EXT
		else if ( en == GL_RGB16_EXT ) ostr << "GL_RGB16_EXT";
	#endif
	#ifdef GL_RGBA2_EXT
		else if ( en == GL_RGBA2_EXT ) ostr << "GL_RGBA2_EXT";
	#endif
	#ifdef GL_RGBA4_EXT
		else if ( en == GL_RGBA4_EXT ) ostr << "GL_RGBA4_EXT";
	#endif
	#ifdef GL_RGB5_A1_EXT
		else if ( en == GL_RGB5_A1_EXT ) ostr << "GL_RGB5_A1_EXT";
	#endif
	#ifdef GL_RGBA8_EXT
		else if ( en == GL_RGBA8_EXT ) ostr << "GL_RGBA8_EXT";
	#endif
	#ifdef GL_RGB10_A2_EXT
		else if ( en == GL_RGB10_A2_EXT ) ostr << "GL_RGB10_A2_EXT";
	#endif
	#ifdef GL_RGBA12_EXT
		else if ( en == GL_RGBA12_EXT ) ostr << "GL_RGBA12_EXT";
	#endif
	#ifdef GL_RGBA16_EXT
		else if ( en == GL_RGBA16_EXT ) ostr << "GL_RGBA16_EXT";
	#endif
	#ifdef GL_TEXTURE_RED_SIZE_EXT
		else if ( en == GL_TEXTURE_RED_SIZE_EXT ) ostr << "GL_TEXTURE_RED_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_GREEN_SIZE_EXT
		else if ( en == GL_TEXTURE_GREEN_SIZE_EXT ) ostr << "GL_TEXTURE_GREEN_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_BLUE_SIZE_EXT
		else if ( en == GL_TEXTURE_BLUE_SIZE_EXT ) ostr << "GL_TEXTURE_BLUE_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_ALPHA_SIZE_EXT
		else if ( en == GL_TEXTURE_ALPHA_SIZE_EXT ) ostr << "GL_TEXTURE_ALPHA_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_LUMINANCE_SIZE_EXT
		else if ( en == GL_TEXTURE_LUMINANCE_SIZE_EXT ) ostr << "GL_TEXTURE_LUMINANCE_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_INTENSITY_SIZE_EXT
		else if ( en == GL_TEXTURE_INTENSITY_SIZE_EXT ) ostr << "GL_TEXTURE_INTENSITY_SIZE_EXT";
	#endif
	#ifdef GL_REPLACE_EXT
		else if ( en == GL_REPLACE_EXT ) ostr << "GL_REPLACE_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D_EXT
		else if ( en == GL_PROXY_TEXTURE_1D_EXT ) ostr << "GL_PROXY_TEXTURE_1D_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_EXT
		else if ( en == GL_PROXY_TEXTURE_2D_EXT ) ostr << "GL_PROXY_TEXTURE_2D_EXT";
	#endif
	#ifdef GL_PACK_SKIP_IMAGES_EXT
		else if ( en == GL_PACK_SKIP_IMAGES_EXT ) ostr << "GL_PACK_SKIP_IMAGES_EXT";
	#endif
	#ifdef GL_PACK_IMAGE_HEIGHT_EXT
		else if ( en == GL_PACK_IMAGE_HEIGHT_EXT ) ostr << "GL_PACK_IMAGE_HEIGHT_EXT";
	#endif
	#ifdef GL_UNPACK_SKIP_IMAGES_EXT
		else if ( en == GL_UNPACK_SKIP_IMAGES_EXT ) ostr << "GL_UNPACK_SKIP_IMAGES_EXT";
	#endif
	#ifdef GL_UNPACK_IMAGE_HEIGHT_EXT
		else if ( en == GL_UNPACK_IMAGE_HEIGHT_EXT ) ostr << "GL_UNPACK_IMAGE_HEIGHT_EXT";
	#endif
	#ifdef GL_TEXTURE_3D_EXT
		else if ( en == GL_TEXTURE_3D_EXT ) ostr << "GL_TEXTURE_3D_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_3D_EXT
		else if ( en == GL_PROXY_TEXTURE_3D_EXT ) ostr << "GL_PROXY_TEXTURE_3D_EXT";
	#endif
	#ifdef GL_TEXTURE_DEPTH_EXT
		else if ( en == GL_TEXTURE_DEPTH_EXT ) ostr << "GL_TEXTURE_DEPTH_EXT";
	#endif
	#ifdef GL_TEXTURE_WRAP_R_EXT
		else if ( en == GL_TEXTURE_WRAP_R_EXT ) ostr << "GL_TEXTURE_WRAP_R_EXT";
	#endif
	#ifdef GL_MAX_3D_TEXTURE_SIZE_EXT
		else if ( en == GL_MAX_3D_TEXTURE_SIZE_EXT ) ostr << "GL_MAX_3D_TEXTURE_SIZE_EXT";
	#endif
	#ifdef GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT
		else if ( en == GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT ) ostr << "GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT";
	#endif
	#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS_EXT
		else if ( en == GL_MAX_ARRAY_TEXTURE_LAYERS_EXT ) ostr << "GL_MAX_ARRAY_TEXTURE_LAYERS_EXT";
	#endif
	#ifdef GL_TEXTURE_1D_ARRAY_EXT
		else if ( en == GL_TEXTURE_1D_ARRAY_EXT ) ostr << "GL_TEXTURE_1D_ARRAY_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D_ARRAY_EXT
		else if ( en == GL_PROXY_TEXTURE_1D_ARRAY_EXT ) ostr << "GL_PROXY_TEXTURE_1D_ARRAY_EXT";
	#endif
	#ifdef GL_TEXTURE_2D_ARRAY_EXT
		else if ( en == GL_TEXTURE_2D_ARRAY_EXT ) ostr << "GL_TEXTURE_2D_ARRAY_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_ARRAY_EXT
		else if ( en == GL_PROXY_TEXTURE_2D_ARRAY_EXT ) ostr << "GL_PROXY_TEXTURE_2D_ARRAY_EXT";
	#endif
	#ifdef GL_TEXTURE_BINDING_1D_ARRAY_EXT
		else if ( en == GL_TEXTURE_BINDING_1D_ARRAY_EXT ) ostr << "GL_TEXTURE_BINDING_1D_ARRAY_EXT";
	#endif
	#ifdef GL_TEXTURE_BINDING_2D_ARRAY_EXT
		else if ( en == GL_TEXTURE_BINDING_2D_ARRAY_EXT ) ostr << "GL_TEXTURE_BINDING_2D_ARRAY_EXT";
	#endif
	#ifdef GL_TEXTURE_BUFFER_EXT
		else if ( en == GL_TEXTURE_BUFFER_EXT ) ostr << "GL_TEXTURE_BUFFER_EXT";
	#endif
	#ifdef GL_MAX_TEXTURE_BUFFER_SIZE_EXT
		else if ( en == GL_MAX_TEXTURE_BUFFER_SIZE_EXT ) ostr << "GL_MAX_TEXTURE_BUFFER_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_BINDING_BUFFER_EXT
		else if ( en == GL_TEXTURE_BINDING_BUFFER_EXT ) ostr << "GL_TEXTURE_BINDING_BUFFER_EXT";
	#endif
	#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT
		else if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT ) ostr << "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT";
	#endif
	#ifdef GL_TEXTURE_BUFFER_FORMAT_EXT
		else if ( en == GL_TEXTURE_BUFFER_FORMAT_EXT ) ostr << "GL_TEXTURE_BUFFER_FORMAT_EXT";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_LATC1_EXT
		else if ( en == GL_COMPRESSED_LUMINANCE_LATC1_EXT ) ostr << "GL_COMPRESSED_LUMINANCE_LATC1_EXT";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT
		else if ( en == GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT ) ostr << "GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT";
	#endif
	#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT
		else if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT ) ostr << "GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT
		else if ( en == GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT ) ostr << "GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT";
	#endif
	#ifdef GL_COMPRESSED_RED_RGTC1_EXT
		else if ( en == GL_COMPRESSED_RED_RGTC1_EXT ) ostr << "GL_COMPRESSED_RED_RGTC1_EXT";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1_EXT
		else if ( en == GL_COMPRESSED_SIGNED_RED_RGTC1_EXT ) ostr << "GL_COMPRESSED_SIGNED_RED_RGTC1_EXT";
	#endif
	#ifdef GL_COMPRESSED_RED_GREEN_RGTC2_EXT
		else if ( en == GL_COMPRESSED_RED_GREEN_RGTC2_EXT ) ostr << "GL_COMPRESSED_RED_GREEN_RGTC2_EXT";
	#endif
	#ifdef GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT
		else if ( en == GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT ) ostr << "GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT";
	#endif
	#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_EXT
		else if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_EXT ) ostr << "GL_COMPRESSED_RGB_S3TC_DXT1_EXT";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT1_EXT";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_EXT ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT3_EXT";
	#endif
	#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
		else if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_EXT ) ostr << "GL_COMPRESSED_RGBA_S3TC_DXT5_EXT";
	#endif
	#ifdef GL_NORMAL_MAP_EXT
		else if ( en == GL_NORMAL_MAP_EXT ) ostr << "GL_NORMAL_MAP_EXT";
	#endif
	#ifdef GL_REFLECTION_MAP_EXT
		else if ( en == GL_REFLECTION_MAP_EXT ) ostr << "GL_REFLECTION_MAP_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_EXT";
	#endif
	#ifdef GL_TEXTURE_BINDING_CUBE_MAP_EXT
		else if ( en == GL_TEXTURE_BINDING_CUBE_MAP_EXT ) ostr << "GL_TEXTURE_BINDING_CUBE_MAP_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT";
	#endif
	#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT
		else if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT ) ostr << "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_CUBE_MAP_EXT
		else if ( en == GL_PROXY_TEXTURE_CUBE_MAP_EXT ) ostr << "GL_PROXY_TEXTURE_CUBE_MAP_EXT";
	#endif
	#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT
		else if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT ) ostr << "GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT";
	#endif
	#ifdef GL_CLAMP_TO_EDGE_EXT
		else if ( en == GL_CLAMP_TO_EDGE_EXT ) ostr << "GL_CLAMP_TO_EDGE_EXT";
	#endif
	#ifdef GL_COMBINE_EXT
		else if ( en == GL_COMBINE_EXT ) ostr << "GL_COMBINE_EXT";
	#endif
	#ifdef GL_COMBINE_RGB_EXT
		else if ( en == GL_COMBINE_RGB_EXT ) ostr << "GL_COMBINE_RGB_EXT";
	#endif
	#ifdef GL_COMBINE_ALPHA_EXT
		else if ( en == GL_COMBINE_ALPHA_EXT ) ostr << "GL_COMBINE_ALPHA_EXT";
	#endif
	#ifdef GL_RGB_SCALE_EXT
		else if ( en == GL_RGB_SCALE_EXT ) ostr << "GL_RGB_SCALE_EXT";
	#endif
	#ifdef GL_ADD_SIGNED_EXT
		else if ( en == GL_ADD_SIGNED_EXT ) ostr << "GL_ADD_SIGNED_EXT";
	#endif
	#ifdef GL_INTERPOLATE_EXT
		else if ( en == GL_INTERPOLATE_EXT ) ostr << "GL_INTERPOLATE_EXT";
	#endif
	#ifdef GL_CONSTANT_EXT
		else if ( en == GL_CONSTANT_EXT ) ostr << "GL_CONSTANT_EXT";
	#endif
	#ifdef GL_PRIMARY_COLOR_EXT
		else if ( en == GL_PRIMARY_COLOR_EXT ) ostr << "GL_PRIMARY_COLOR_EXT";
	#endif
	#ifdef GL_PREVIOUS_EXT
		else if ( en == GL_PREVIOUS_EXT ) ostr << "GL_PREVIOUS_EXT";
	#endif
	#ifdef GL_SOURCE0_RGB_EXT
		else if ( en == GL_SOURCE0_RGB_EXT ) ostr << "GL_SOURCE0_RGB_EXT";
	#endif
	#ifdef GL_SOURCE1_RGB_EXT
		else if ( en == GL_SOURCE1_RGB_EXT ) ostr << "GL_SOURCE1_RGB_EXT";
	#endif
	#ifdef GL_SOURCE2_RGB_EXT
		else if ( en == GL_SOURCE2_RGB_EXT ) ostr << "GL_SOURCE2_RGB_EXT";
	#endif
	#ifdef GL_SOURCE0_ALPHA_EXT
		else if ( en == GL_SOURCE0_ALPHA_EXT ) ostr << "GL_SOURCE0_ALPHA_EXT";
	#endif
	#ifdef GL_SOURCE1_ALPHA_EXT
		else if ( en == GL_SOURCE1_ALPHA_EXT ) ostr << "GL_SOURCE1_ALPHA_EXT";
	#endif
	#ifdef GL_SOURCE2_ALPHA_EXT
		else if ( en == GL_SOURCE2_ALPHA_EXT ) ostr << "GL_SOURCE2_ALPHA_EXT";
	#endif
	#ifdef GL_OPERAND0_RGB_EXT
		else if ( en == GL_OPERAND0_RGB_EXT ) ostr << "GL_OPERAND0_RGB_EXT";
	#endif
	#ifdef GL_OPERAND1_RGB_EXT
		else if ( en == GL_OPERAND1_RGB_EXT ) ostr << "GL_OPERAND1_RGB_EXT";
	#endif
	#ifdef GL_OPERAND2_RGB_EXT
		else if ( en == GL_OPERAND2_RGB_EXT ) ostr << "GL_OPERAND2_RGB_EXT";
	#endif
	#ifdef GL_OPERAND0_ALPHA_EXT
		else if ( en == GL_OPERAND0_ALPHA_EXT ) ostr << "GL_OPERAND0_ALPHA_EXT";
	#endif
	#ifdef GL_OPERAND1_ALPHA_EXT
		else if ( en == GL_OPERAND1_ALPHA_EXT ) ostr << "GL_OPERAND1_ALPHA_EXT";
	#endif
	#ifdef GL_OPERAND2_ALPHA_EXT
		else if ( en == GL_OPERAND2_ALPHA_EXT ) ostr << "GL_OPERAND2_ALPHA_EXT";
	#endif
	#ifdef GL_DOT3_RGB_EXT
		else if ( en == GL_DOT3_RGB_EXT ) ostr << "GL_DOT3_RGB_EXT";
	#endif
	#ifdef GL_DOT3_RGBA_EXT
		else if ( en == GL_DOT3_RGBA_EXT ) ostr << "GL_DOT3_RGBA_EXT";
	#endif
	#ifdef GL_TEXTURE_MAX_ANISOTROPY_EXT
		else if ( en == GL_TEXTURE_MAX_ANISOTROPY_EXT ) ostr << "GL_TEXTURE_MAX_ANISOTROPY_EXT";
	#endif
	#ifdef GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
		else if ( en == GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT ) ostr << "GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT";
	#endif
	#ifdef GL_RGBA32UI_EXT
		else if ( en == GL_RGBA32UI_EXT ) ostr << "GL_RGBA32UI_EXT";
	#endif
	#ifdef GL_RGB32UI_EXT
		else if ( en == GL_RGB32UI_EXT ) ostr << "GL_RGB32UI_EXT";
	#endif
	#ifdef GL_ALPHA32UI_EXT
		else if ( en == GL_ALPHA32UI_EXT ) ostr << "GL_ALPHA32UI_EXT";
	#endif
	#ifdef GL_INTENSITY32UI_EXT
		else if ( en == GL_INTENSITY32UI_EXT ) ostr << "GL_INTENSITY32UI_EXT";
	#endif
	#ifdef GL_LUMINANCE32UI_EXT
		else if ( en == GL_LUMINANCE32UI_EXT ) ostr << "GL_LUMINANCE32UI_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA32UI_EXT
		else if ( en == GL_LUMINANCE_ALPHA32UI_EXT ) ostr << "GL_LUMINANCE_ALPHA32UI_EXT";
	#endif
	#ifdef GL_RGBA16UI_EXT
		else if ( en == GL_RGBA16UI_EXT ) ostr << "GL_RGBA16UI_EXT";
	#endif
	#ifdef GL_RGB16UI_EXT
		else if ( en == GL_RGB16UI_EXT ) ostr << "GL_RGB16UI_EXT";
	#endif
	#ifdef GL_ALPHA16UI_EXT
		else if ( en == GL_ALPHA16UI_EXT ) ostr << "GL_ALPHA16UI_EXT";
	#endif
	#ifdef GL_INTENSITY16UI_EXT
		else if ( en == GL_INTENSITY16UI_EXT ) ostr << "GL_INTENSITY16UI_EXT";
	#endif
	#ifdef GL_LUMINANCE16UI_EXT
		else if ( en == GL_LUMINANCE16UI_EXT ) ostr << "GL_LUMINANCE16UI_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA16UI_EXT
		else if ( en == GL_LUMINANCE_ALPHA16UI_EXT ) ostr << "GL_LUMINANCE_ALPHA16UI_EXT";
	#endif
	#ifdef GL_RGBA8UI_EXT
		else if ( en == GL_RGBA8UI_EXT ) ostr << "GL_RGBA8UI_EXT";
	#endif
	#ifdef GL_RGB8UI_EXT
		else if ( en == GL_RGB8UI_EXT ) ostr << "GL_RGB8UI_EXT";
	#endif
	#ifdef GL_ALPHA8UI_EXT
		else if ( en == GL_ALPHA8UI_EXT ) ostr << "GL_ALPHA8UI_EXT";
	#endif
	#ifdef GL_INTENSITY8UI_EXT
		else if ( en == GL_INTENSITY8UI_EXT ) ostr << "GL_INTENSITY8UI_EXT";
	#endif
	#ifdef GL_LUMINANCE8UI_EXT
		else if ( en == GL_LUMINANCE8UI_EXT ) ostr << "GL_LUMINANCE8UI_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA8UI_EXT
		else if ( en == GL_LUMINANCE_ALPHA8UI_EXT ) ostr << "GL_LUMINANCE_ALPHA8UI_EXT";
	#endif
	#ifdef GL_RGBA32I_EXT
		else if ( en == GL_RGBA32I_EXT ) ostr << "GL_RGBA32I_EXT";
	#endif
	#ifdef GL_RGB32I_EXT
		else if ( en == GL_RGB32I_EXT ) ostr << "GL_RGB32I_EXT";
	#endif
	#ifdef GL_ALPHA32I_EXT
		else if ( en == GL_ALPHA32I_EXT ) ostr << "GL_ALPHA32I_EXT";
	#endif
	#ifdef GL_INTENSITY32I_EXT
		else if ( en == GL_INTENSITY32I_EXT ) ostr << "GL_INTENSITY32I_EXT";
	#endif
	#ifdef GL_LUMINANCE32I_EXT
		else if ( en == GL_LUMINANCE32I_EXT ) ostr << "GL_LUMINANCE32I_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA32I_EXT
		else if ( en == GL_LUMINANCE_ALPHA32I_EXT ) ostr << "GL_LUMINANCE_ALPHA32I_EXT";
	#endif
	#ifdef GL_RGBA16I_EXT
		else if ( en == GL_RGBA16I_EXT ) ostr << "GL_RGBA16I_EXT";
	#endif
	#ifdef GL_RGB16I_EXT
		else if ( en == GL_RGB16I_EXT ) ostr << "GL_RGB16I_EXT";
	#endif
	#ifdef GL_ALPHA16I_EXT
		else if ( en == GL_ALPHA16I_EXT ) ostr << "GL_ALPHA16I_EXT";
	#endif
	#ifdef GL_INTENSITY16I_EXT
		else if ( en == GL_INTENSITY16I_EXT ) ostr << "GL_INTENSITY16I_EXT";
	#endif
	#ifdef GL_LUMINANCE16I_EXT
		else if ( en == GL_LUMINANCE16I_EXT ) ostr << "GL_LUMINANCE16I_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA16I_EXT
		else if ( en == GL_LUMINANCE_ALPHA16I_EXT ) ostr << "GL_LUMINANCE_ALPHA16I_EXT";
	#endif
	#ifdef GL_RGBA8I_EXT
		else if ( en == GL_RGBA8I_EXT ) ostr << "GL_RGBA8I_EXT";
	#endif
	#ifdef GL_RGB8I_EXT
		else if ( en == GL_RGB8I_EXT ) ostr << "GL_RGB8I_EXT";
	#endif
	#ifdef GL_ALPHA8I_EXT
		else if ( en == GL_ALPHA8I_EXT ) ostr << "GL_ALPHA8I_EXT";
	#endif
	#ifdef GL_INTENSITY8I_EXT
		else if ( en == GL_INTENSITY8I_EXT ) ostr << "GL_INTENSITY8I_EXT";
	#endif
	#ifdef GL_LUMINANCE8I_EXT
		else if ( en == GL_LUMINANCE8I_EXT ) ostr << "GL_LUMINANCE8I_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA8I_EXT
		else if ( en == GL_LUMINANCE_ALPHA8I_EXT ) ostr << "GL_LUMINANCE_ALPHA8I_EXT";
	#endif
	#ifdef GL_RED_INTEGER_EXT
		else if ( en == GL_RED_INTEGER_EXT ) ostr << "GL_RED_INTEGER_EXT";
	#endif
	#ifdef GL_GREEN_INTEGER_EXT
		else if ( en == GL_GREEN_INTEGER_EXT ) ostr << "GL_GREEN_INTEGER_EXT";
	#endif
	#ifdef GL_BLUE_INTEGER_EXT
		else if ( en == GL_BLUE_INTEGER_EXT ) ostr << "GL_BLUE_INTEGER_EXT";
	#endif
	#ifdef GL_ALPHA_INTEGER_EXT
		else if ( en == GL_ALPHA_INTEGER_EXT ) ostr << "GL_ALPHA_INTEGER_EXT";
	#endif
	#ifdef GL_RGB_INTEGER_EXT
		else if ( en == GL_RGB_INTEGER_EXT ) ostr << "GL_RGB_INTEGER_EXT";
	#endif
	#ifdef GL_RGBA_INTEGER_EXT
		else if ( en == GL_RGBA_INTEGER_EXT ) ostr << "GL_RGBA_INTEGER_EXT";
	#endif
	#ifdef GL_BGR_INTEGER_EXT
		else if ( en == GL_BGR_INTEGER_EXT ) ostr << "GL_BGR_INTEGER_EXT";
	#endif
	#ifdef GL_BGRA_INTEGER_EXT
		else if ( en == GL_BGRA_INTEGER_EXT ) ostr << "GL_BGRA_INTEGER_EXT";
	#endif
	#ifdef GL_LUMINANCE_INTEGER_EXT
		else if ( en == GL_LUMINANCE_INTEGER_EXT ) ostr << "GL_LUMINANCE_INTEGER_EXT";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_INTEGER_EXT
		else if ( en == GL_LUMINANCE_ALPHA_INTEGER_EXT ) ostr << "GL_LUMINANCE_ALPHA_INTEGER_EXT";
	#endif
	#ifdef GL_RGBA_INTEGER_MODE_EXT
		else if ( en == GL_RGBA_INTEGER_MODE_EXT ) ostr << "GL_RGBA_INTEGER_MODE_EXT";
	#endif
	#ifdef GL_MAX_TEXTURE_LOD_BIAS_EXT
		else if ( en == GL_MAX_TEXTURE_LOD_BIAS_EXT ) ostr << "GL_MAX_TEXTURE_LOD_BIAS_EXT";
	#endif
	#ifdef GL_TEXTURE_FILTER_CONTROL_EXT
		else if ( en == GL_TEXTURE_FILTER_CONTROL_EXT ) ostr << "GL_TEXTURE_FILTER_CONTROL_EXT";
	#endif
	#ifdef GL_TEXTURE_LOD_BIAS_EXT
		else if ( en == GL_TEXTURE_LOD_BIAS_EXT ) ostr << "GL_TEXTURE_LOD_BIAS_EXT";
	#endif
	#ifdef GL_MIRROR_CLAMP_EXT
		else if ( en == GL_MIRROR_CLAMP_EXT ) ostr << "GL_MIRROR_CLAMP_EXT";
	#endif
	#ifdef GL_MIRROR_CLAMP_TO_EDGE_EXT
		else if ( en == GL_MIRROR_CLAMP_TO_EDGE_EXT ) ostr << "GL_MIRROR_CLAMP_TO_EDGE_EXT";
	#endif
	#ifdef GL_MIRROR_CLAMP_TO_BORDER_EXT
		else if ( en == GL_MIRROR_CLAMP_TO_BORDER_EXT ) ostr << "GL_MIRROR_CLAMP_TO_BORDER_EXT";
	#endif
	#ifdef GL_TEXTURE_PRIORITY_EXT
		else if ( en == GL_TEXTURE_PRIORITY_EXT ) ostr << "GL_TEXTURE_PRIORITY_EXT";
	#endif
	#ifdef GL_TEXTURE_RESIDENT_EXT
		else if ( en == GL_TEXTURE_RESIDENT_EXT ) ostr << "GL_TEXTURE_RESIDENT_EXT";
	#endif
	#ifdef GL_TEXTURE_1D_BINDING_EXT
		else if ( en == GL_TEXTURE_1D_BINDING_EXT ) ostr << "GL_TEXTURE_1D_BINDING_EXT";
	#endif
	#ifdef GL_TEXTURE_2D_BINDING_EXT
		else if ( en == GL_TEXTURE_2D_BINDING_EXT ) ostr << "GL_TEXTURE_2D_BINDING_EXT";
	#endif
	#ifdef GL_TEXTURE_3D_BINDING_EXT
		else if ( en == GL_TEXTURE_3D_BINDING_EXT ) ostr << "GL_TEXTURE_3D_BINDING_EXT";
	#endif
	#ifdef GL_PERTURB_EXT
		else if ( en == GL_PERTURB_EXT ) ostr << "GL_PERTURB_EXT";
	#endif
	#ifdef GL_TEXTURE_NORMAL_EXT
		else if ( en == GL_TEXTURE_NORMAL_EXT ) ostr << "GL_TEXTURE_NORMAL_EXT";
	#endif
	#ifdef GL_TEXTURE_RECTANGLE_EXT
		else if ( en == GL_TEXTURE_RECTANGLE_EXT ) ostr << "GL_TEXTURE_RECTANGLE_EXT";
	#endif
	#ifdef GL_TEXTURE_BINDING_RECTANGLE_EXT
		else if ( en == GL_TEXTURE_BINDING_RECTANGLE_EXT ) ostr << "GL_TEXTURE_BINDING_RECTANGLE_EXT";
	#endif
	#ifdef GL_PROXY_TEXTURE_RECTANGLE_EXT
		else if ( en == GL_PROXY_TEXTURE_RECTANGLE_EXT ) ostr << "GL_PROXY_TEXTURE_RECTANGLE_EXT";
	#endif
	#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT
		else if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT ) ostr << "GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT";
	#endif
	#ifdef GL_SRGB_EXT
		else if ( en == GL_SRGB_EXT ) ostr << "GL_SRGB_EXT";
	#endif
	#ifdef GL_SRGB8_EXT
		else if ( en == GL_SRGB8_EXT ) ostr << "GL_SRGB8_EXT";
	#endif
	#ifdef GL_SRGB_ALPHA_EXT
		else if ( en == GL_SRGB_ALPHA_EXT ) ostr << "GL_SRGB_ALPHA_EXT";
	#endif
	#ifdef GL_SRGB8_ALPHA8_EXT
		else if ( en == GL_SRGB8_ALPHA8_EXT ) ostr << "GL_SRGB8_ALPHA8_EXT";
	#endif
	#ifdef GL_SLUMINANCE_ALPHA_EXT
		else if ( en == GL_SLUMINANCE_ALPHA_EXT ) ostr << "GL_SLUMINANCE_ALPHA_EXT";
	#endif
	#ifdef GL_SLUMINANCE8_ALPHA8_EXT
		else if ( en == GL_SLUMINANCE8_ALPHA8_EXT ) ostr << "GL_SLUMINANCE8_ALPHA8_EXT";
	#endif
	#ifdef GL_SLUMINANCE_EXT
		else if ( en == GL_SLUMINANCE_EXT ) ostr << "GL_SLUMINANCE_EXT";
	#endif
	#ifdef GL_SLUMINANCE8_EXT
		else if ( en == GL_SLUMINANCE8_EXT ) ostr << "GL_SLUMINANCE8_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_EXT
		else if ( en == GL_COMPRESSED_SRGB_EXT ) ostr << "GL_COMPRESSED_SRGB_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_EXT
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_EXT ) ostr << "GL_COMPRESSED_SRGB_ALPHA_EXT";
	#endif
	#ifdef GL_COMPRESSED_SLUMINANCE_EXT
		else if ( en == GL_COMPRESSED_SLUMINANCE_EXT ) ostr << "GL_COMPRESSED_SLUMINANCE_EXT";
	#endif
	#ifdef GL_COMPRESSED_SLUMINANCE_ALPHA_EXT
		else if ( en == GL_COMPRESSED_SLUMINANCE_ALPHA_EXT ) ostr << "GL_COMPRESSED_SLUMINANCE_ALPHA_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_S3TC_DXT1_EXT
		else if ( en == GL_COMPRESSED_SRGB_S3TC_DXT1_EXT ) ostr << "GL_COMPRESSED_SRGB_S3TC_DXT1_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT ) ostr << "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT ) ostr << "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT";
	#endif
	#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT
		else if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT ) ostr << "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT";
	#endif
	#ifdef GL_TEXTURE_SRGB_DECODE_EXT
		else if ( en == GL_TEXTURE_SRGB_DECODE_EXT ) ostr << "GL_TEXTURE_SRGB_DECODE_EXT";
	#endif
	#ifdef GL_DECODE_EXT
		else if ( en == GL_DECODE_EXT ) ostr << "GL_DECODE_EXT";
	#endif
	#ifdef GL_SKIP_DECODE_EXT
		else if ( en == GL_SKIP_DECODE_EXT ) ostr << "GL_SKIP_DECODE_EXT";
	#endif
	#ifdef GL_RGB9_E5_EXT
		else if ( en == GL_RGB9_E5_EXT ) ostr << "GL_RGB9_E5_EXT";
	#endif
	#ifdef GL_UNSIGNED_INT_5_9_9_9_REV_EXT
		else if ( en == GL_UNSIGNED_INT_5_9_9_9_REV_EXT ) ostr << "GL_UNSIGNED_INT_5_9_9_9_REV_EXT";
	#endif
	#ifdef GL_TEXTURE_SHARED_SIZE_EXT
		else if ( en == GL_TEXTURE_SHARED_SIZE_EXT ) ostr << "GL_TEXTURE_SHARED_SIZE_EXT";
	#endif
	#ifdef GL_RED_SNORM
		else if ( en == GL_RED_SNORM ) ostr << "GL_RED_SNORM";
	#endif
	#ifdef GL_RG_SNORM
		else if ( en == GL_RG_SNORM ) ostr << "GL_RG_SNORM";
	#endif
	#ifdef GL_RGB_SNORM
		else if ( en == GL_RGB_SNORM ) ostr << "GL_RGB_SNORM";
	#endif
	#ifdef GL_RGBA_SNORM
		else if ( en == GL_RGBA_SNORM ) ostr << "GL_RGBA_SNORM";
	#endif
	#ifdef GL_R8_SNORM
		else if ( en == GL_R8_SNORM ) ostr << "GL_R8_SNORM";
	#endif
	#ifdef GL_RG8_SNORM
		else if ( en == GL_RG8_SNORM ) ostr << "GL_RG8_SNORM";
	#endif
	#ifdef GL_RGB8_SNORM
		else if ( en == GL_RGB8_SNORM ) ostr << "GL_RGB8_SNORM";
	#endif
	#ifdef GL_RGBA8_SNORM
		else if ( en == GL_RGBA8_SNORM ) ostr << "GL_RGBA8_SNORM";
	#endif
	#ifdef GL_R16_SNORM
		else if ( en == GL_R16_SNORM ) ostr << "GL_R16_SNORM";
	#endif
	#ifdef GL_RG16_SNORM
		else if ( en == GL_RG16_SNORM ) ostr << "GL_RG16_SNORM";
	#endif
	#ifdef GL_RGB16_SNORM
		else if ( en == GL_RGB16_SNORM ) ostr << "GL_RGB16_SNORM";
	#endif
	#ifdef GL_RGBA16_SNORM
		else if ( en == GL_RGBA16_SNORM ) ostr << "GL_RGBA16_SNORM";
	#endif
	#ifdef GL_SIGNED_NORMALIZED
		else if ( en == GL_SIGNED_NORMALIZED ) ostr << "GL_SIGNED_NORMALIZED";
	#endif
	#ifdef GL_ALPHA_SNORM
		else if ( en == GL_ALPHA_SNORM ) ostr << "GL_ALPHA_SNORM";
	#endif
	#ifdef GL_LUMINANCE_SNORM
		else if ( en == GL_LUMINANCE_SNORM ) ostr << "GL_LUMINANCE_SNORM";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_SNORM
		else if ( en == GL_LUMINANCE_ALPHA_SNORM ) ostr << "GL_LUMINANCE_ALPHA_SNORM";
	#endif
	#ifdef GL_INTENSITY_SNORM
		else if ( en == GL_INTENSITY_SNORM ) ostr << "GL_INTENSITY_SNORM";
	#endif
	#ifdef GL_ALPHA8_SNORM
		else if ( en == GL_ALPHA8_SNORM ) ostr << "GL_ALPHA8_SNORM";
	#endif
	#ifdef GL_LUMINANCE8_SNORM
		else if ( en == GL_LUMINANCE8_SNORM ) ostr << "GL_LUMINANCE8_SNORM";
	#endif
	#ifdef GL_LUMINANCE8_ALPHA8_SNORM
		else if ( en == GL_LUMINANCE8_ALPHA8_SNORM ) ostr << "GL_LUMINANCE8_ALPHA8_SNORM";
	#endif
	#ifdef GL_INTENSITY8_SNORM
		else if ( en == GL_INTENSITY8_SNORM ) ostr << "GL_INTENSITY8_SNORM";
	#endif
	#ifdef GL_ALPHA16_SNORM
		else if ( en == GL_ALPHA16_SNORM ) ostr << "GL_ALPHA16_SNORM";
	#endif
	#ifdef GL_LUMINANCE16_SNORM
		else if ( en == GL_LUMINANCE16_SNORM ) ostr << "GL_LUMINANCE16_SNORM";
	#endif
	#ifdef GL_LUMINANCE16_ALPHA16_SNORM
		else if ( en == GL_LUMINANCE16_ALPHA16_SNORM ) ostr << "GL_LUMINANCE16_ALPHA16_SNORM";
	#endif
	#ifdef GL_INTENSITY16_SNORM
		else if ( en == GL_INTENSITY16_SNORM ) ostr << "GL_INTENSITY16_SNORM";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_R_EXT
		else if ( en == GL_TEXTURE_SWIZZLE_R_EXT ) ostr << "GL_TEXTURE_SWIZZLE_R_EXT";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_G_EXT
		else if ( en == GL_TEXTURE_SWIZZLE_G_EXT ) ostr << "GL_TEXTURE_SWIZZLE_G_EXT";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_B_EXT
		else if ( en == GL_TEXTURE_SWIZZLE_B_EXT ) ostr << "GL_TEXTURE_SWIZZLE_B_EXT";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_A_EXT
		else if ( en == GL_TEXTURE_SWIZZLE_A_EXT ) ostr << "GL_TEXTURE_SWIZZLE_A_EXT";
	#endif
	#ifdef GL_TEXTURE_SWIZZLE_RGBA_EXT
		else if ( en == GL_TEXTURE_SWIZZLE_RGBA_EXT ) ostr << "GL_TEXTURE_SWIZZLE_RGBA_EXT";
	#endif
	#ifdef GL_TIME_ELAPSED_EXT
		else if ( en == GL_TIME_ELAPSED_EXT ) ostr << "GL_TIME_ELAPSED_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_VARYINGS_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT";
	#endif
	#ifdef GL_PRIMITIVES_GENERATED_EXT
		else if ( en == GL_PRIMITIVES_GENERATED_EXT ) ostr << "GL_PRIMITIVES_GENERATED_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT";
	#endif
	#ifdef GL_RASTERIZER_DISCARD_EXT
		else if ( en == GL_RASTERIZER_DISCARD_EXT ) ostr << "GL_RASTERIZER_DISCARD_EXT";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT";
	#endif
	#ifdef GL_INTERLEAVED_ATTRIBS_EXT
		else if ( en == GL_INTERLEAVED_ATTRIBS_EXT ) ostr << "GL_INTERLEAVED_ATTRIBS_EXT";
	#endif
	#ifdef GL_SEPARATE_ATTRIBS_EXT
		else if ( en == GL_SEPARATE_ATTRIBS_EXT ) ostr << "GL_SEPARATE_ATTRIBS_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_EXT";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT";
	#endif
	#ifdef GL_DOUBLE_EXT
		else if ( en == GL_DOUBLE_EXT ) ostr << "GL_DOUBLE_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_EXT
		else if ( en == GL_VERTEX_ARRAY_EXT ) ostr << "GL_VERTEX_ARRAY_EXT";
	#endif
	#ifdef GL_NORMAL_ARRAY_EXT
		else if ( en == GL_NORMAL_ARRAY_EXT ) ostr << "GL_NORMAL_ARRAY_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_EXT
		else if ( en == GL_COLOR_ARRAY_EXT ) ostr << "GL_COLOR_ARRAY_EXT";
	#endif
	#ifdef GL_INDEX_ARRAY_EXT
		else if ( en == GL_INDEX_ARRAY_EXT ) ostr << "GL_INDEX_ARRAY_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_EXT";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_EXT
		else if ( en == GL_EDGE_FLAG_ARRAY_EXT ) ostr << "GL_EDGE_FLAG_ARRAY_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_SIZE_EXT
		else if ( en == GL_VERTEX_ARRAY_SIZE_EXT ) ostr << "GL_VERTEX_ARRAY_SIZE_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_TYPE_EXT
		else if ( en == GL_VERTEX_ARRAY_TYPE_EXT ) ostr << "GL_VERTEX_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_STRIDE_EXT
		else if ( en == GL_VERTEX_ARRAY_STRIDE_EXT ) ostr << "GL_VERTEX_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_COUNT_EXT
		else if ( en == GL_VERTEX_ARRAY_COUNT_EXT ) ostr << "GL_VERTEX_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_NORMAL_ARRAY_TYPE_EXT
		else if ( en == GL_NORMAL_ARRAY_TYPE_EXT ) ostr << "GL_NORMAL_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_NORMAL_ARRAY_STRIDE_EXT
		else if ( en == GL_NORMAL_ARRAY_STRIDE_EXT ) ostr << "GL_NORMAL_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_NORMAL_ARRAY_COUNT_EXT
		else if ( en == GL_NORMAL_ARRAY_COUNT_EXT ) ostr << "GL_NORMAL_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_SIZE_EXT
		else if ( en == GL_COLOR_ARRAY_SIZE_EXT ) ostr << "GL_COLOR_ARRAY_SIZE_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_TYPE_EXT
		else if ( en == GL_COLOR_ARRAY_TYPE_EXT ) ostr << "GL_COLOR_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_STRIDE_EXT
		else if ( en == GL_COLOR_ARRAY_STRIDE_EXT ) ostr << "GL_COLOR_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_COUNT_EXT
		else if ( en == GL_COLOR_ARRAY_COUNT_EXT ) ostr << "GL_COLOR_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_INDEX_ARRAY_TYPE_EXT
		else if ( en == GL_INDEX_ARRAY_TYPE_EXT ) ostr << "GL_INDEX_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_INDEX_ARRAY_STRIDE_EXT
		else if ( en == GL_INDEX_ARRAY_STRIDE_EXT ) ostr << "GL_INDEX_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_INDEX_ARRAY_COUNT_EXT
		else if ( en == GL_INDEX_ARRAY_COUNT_EXT ) ostr << "GL_INDEX_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_SIZE_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_SIZE_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_SIZE_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_TYPE_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_TYPE_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_STRIDE_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_STRIDE_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_COUNT_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_COUNT_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_STRIDE_EXT
		else if ( en == GL_EDGE_FLAG_ARRAY_STRIDE_EXT ) ostr << "GL_EDGE_FLAG_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_COUNT_EXT
		else if ( en == GL_EDGE_FLAG_ARRAY_COUNT_EXT ) ostr << "GL_EDGE_FLAG_ARRAY_COUNT_EXT";
	#endif
	#ifdef GL_VERTEX_ARRAY_POINTER_EXT
		else if ( en == GL_VERTEX_ARRAY_POINTER_EXT ) ostr << "GL_VERTEX_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_NORMAL_ARRAY_POINTER_EXT
		else if ( en == GL_NORMAL_ARRAY_POINTER_EXT ) ostr << "GL_NORMAL_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_COLOR_ARRAY_POINTER_EXT
		else if ( en == GL_COLOR_ARRAY_POINTER_EXT ) ostr << "GL_COLOR_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_INDEX_ARRAY_POINTER_EXT
		else if ( en == GL_INDEX_ARRAY_POINTER_EXT ) ostr << "GL_INDEX_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_POINTER_EXT
		else if ( en == GL_TEXTURE_COORD_ARRAY_POINTER_EXT ) ostr << "GL_TEXTURE_COORD_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_POINTER_EXT
		else if ( en == GL_EDGE_FLAG_ARRAY_POINTER_EXT ) ostr << "GL_EDGE_FLAG_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_BGRA
		else if ( en == GL_BGRA ) ostr << "GL_BGRA";
	#endif
	#ifdef GL_DOUBLE_MAT2_EXT
		else if ( en == GL_DOUBLE_MAT2_EXT ) ostr << "GL_DOUBLE_MAT2_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT3_EXT
		else if ( en == GL_DOUBLE_MAT3_EXT ) ostr << "GL_DOUBLE_MAT3_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT4_EXT
		else if ( en == GL_DOUBLE_MAT4_EXT ) ostr << "GL_DOUBLE_MAT4_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT2x3_EXT
		else if ( en == GL_DOUBLE_MAT2x3_EXT ) ostr << "GL_DOUBLE_MAT2x3_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT2x4_EXT
		else if ( en == GL_DOUBLE_MAT2x4_EXT ) ostr << "GL_DOUBLE_MAT2x4_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT3x2_EXT
		else if ( en == GL_DOUBLE_MAT3x2_EXT ) ostr << "GL_DOUBLE_MAT3x2_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT3x4_EXT
		else if ( en == GL_DOUBLE_MAT3x4_EXT ) ostr << "GL_DOUBLE_MAT3x4_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT4x2_EXT
		else if ( en == GL_DOUBLE_MAT4x2_EXT ) ostr << "GL_DOUBLE_MAT4x2_EXT";
	#endif
	#ifdef GL_DOUBLE_MAT4x3_EXT
		else if ( en == GL_DOUBLE_MAT4x3_EXT ) ostr << "GL_DOUBLE_MAT4x3_EXT";
	#endif
	#ifdef GL_DOUBLE_VEC2_EXT
		else if ( en == GL_DOUBLE_VEC2_EXT ) ostr << "GL_DOUBLE_VEC2_EXT";
	#endif
	#ifdef GL_DOUBLE_VEC3_EXT
		else if ( en == GL_DOUBLE_VEC3_EXT ) ostr << "GL_DOUBLE_VEC3_EXT";
	#endif
	#ifdef GL_DOUBLE_VEC4_EXT
		else if ( en == GL_DOUBLE_VEC4_EXT ) ostr << "GL_DOUBLE_VEC4_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_EXT
		else if ( en == GL_VERTEX_SHADER_EXT ) ostr << "GL_VERTEX_SHADER_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_BINDING_EXT
		else if ( en == GL_VERTEX_SHADER_BINDING_EXT ) ostr << "GL_VERTEX_SHADER_BINDING_EXT";
	#endif
	#ifdef GL_OP_INDEX_EXT
		else if ( en == GL_OP_INDEX_EXT ) ostr << "GL_OP_INDEX_EXT";
	#endif
	#ifdef GL_OP_NEGATE_EXT
		else if ( en == GL_OP_NEGATE_EXT ) ostr << "GL_OP_NEGATE_EXT";
	#endif
	#ifdef GL_OP_DOT3_EXT
		else if ( en == GL_OP_DOT3_EXT ) ostr << "GL_OP_DOT3_EXT";
	#endif
	#ifdef GL_OP_DOT4_EXT
		else if ( en == GL_OP_DOT4_EXT ) ostr << "GL_OP_DOT4_EXT";
	#endif
	#ifdef GL_OP_MUL_EXT
		else if ( en == GL_OP_MUL_EXT ) ostr << "GL_OP_MUL_EXT";
	#endif
	#ifdef GL_OP_ADD_EXT
		else if ( en == GL_OP_ADD_EXT ) ostr << "GL_OP_ADD_EXT";
	#endif
	#ifdef GL_OP_MADD_EXT
		else if ( en == GL_OP_MADD_EXT ) ostr << "GL_OP_MADD_EXT";
	#endif
	#ifdef GL_OP_FRAC_EXT
		else if ( en == GL_OP_FRAC_EXT ) ostr << "GL_OP_FRAC_EXT";
	#endif
	#ifdef GL_OP_MAX_EXT
		else if ( en == GL_OP_MAX_EXT ) ostr << "GL_OP_MAX_EXT";
	#endif
	#ifdef GL_OP_MIN_EXT
		else if ( en == GL_OP_MIN_EXT ) ostr << "GL_OP_MIN_EXT";
	#endif
	#ifdef GL_OP_SET_GE_EXT
		else if ( en == GL_OP_SET_GE_EXT ) ostr << "GL_OP_SET_GE_EXT";
	#endif
	#ifdef GL_OP_SET_LT_EXT
		else if ( en == GL_OP_SET_LT_EXT ) ostr << "GL_OP_SET_LT_EXT";
	#endif
	#ifdef GL_OP_CLAMP_EXT
		else if ( en == GL_OP_CLAMP_EXT ) ostr << "GL_OP_CLAMP_EXT";
	#endif
	#ifdef GL_OP_FLOOR_EXT
		else if ( en == GL_OP_FLOOR_EXT ) ostr << "GL_OP_FLOOR_EXT";
	#endif
	#ifdef GL_OP_ROUND_EXT
		else if ( en == GL_OP_ROUND_EXT ) ostr << "GL_OP_ROUND_EXT";
	#endif
	#ifdef GL_OP_EXP_BASE_2_EXT
		else if ( en == GL_OP_EXP_BASE_2_EXT ) ostr << "GL_OP_EXP_BASE_2_EXT";
	#endif
	#ifdef GL_OP_LOG_BASE_2_EXT
		else if ( en == GL_OP_LOG_BASE_2_EXT ) ostr << "GL_OP_LOG_BASE_2_EXT";
	#endif
	#ifdef GL_OP_POWER_EXT
		else if ( en == GL_OP_POWER_EXT ) ostr << "GL_OP_POWER_EXT";
	#endif
	#ifdef GL_OP_RECIP_EXT
		else if ( en == GL_OP_RECIP_EXT ) ostr << "GL_OP_RECIP_EXT";
	#endif
	#ifdef GL_OP_RECIP_SQRT_EXT
		else if ( en == GL_OP_RECIP_SQRT_EXT ) ostr << "GL_OP_RECIP_SQRT_EXT";
	#endif
	#ifdef GL_OP_SUB_EXT
		else if ( en == GL_OP_SUB_EXT ) ostr << "GL_OP_SUB_EXT";
	#endif
	#ifdef GL_OP_CROSS_PRODUCT_EXT
		else if ( en == GL_OP_CROSS_PRODUCT_EXT ) ostr << "GL_OP_CROSS_PRODUCT_EXT";
	#endif
	#ifdef GL_OP_MULTIPLY_MATRIX_EXT
		else if ( en == GL_OP_MULTIPLY_MATRIX_EXT ) ostr << "GL_OP_MULTIPLY_MATRIX_EXT";
	#endif
	#ifdef GL_OP_MOV_EXT
		else if ( en == GL_OP_MOV_EXT ) ostr << "GL_OP_MOV_EXT";
	#endif
	#ifdef GL_OUTPUT_VERTEX_EXT
		else if ( en == GL_OUTPUT_VERTEX_EXT ) ostr << "GL_OUTPUT_VERTEX_EXT";
	#endif
	#ifdef GL_OUTPUT_COLOR0_EXT
		else if ( en == GL_OUTPUT_COLOR0_EXT ) ostr << "GL_OUTPUT_COLOR0_EXT";
	#endif
	#ifdef GL_OUTPUT_COLOR1_EXT
		else if ( en == GL_OUTPUT_COLOR1_EXT ) ostr << "GL_OUTPUT_COLOR1_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD0_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD0_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD0_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD1_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD1_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD1_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD2_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD2_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD2_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD3_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD3_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD3_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD4_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD4_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD4_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD5_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD5_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD5_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD6_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD6_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD6_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD7_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD7_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD7_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD8_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD8_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD8_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD9_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD9_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD9_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD10_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD10_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD10_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD11_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD11_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD11_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD12_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD12_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD12_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD13_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD13_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD13_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD14_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD14_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD14_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD15_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD15_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD15_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD16_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD16_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD16_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD17_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD17_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD17_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD18_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD18_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD18_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD19_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD19_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD19_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD20_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD20_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD20_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD21_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD21_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD21_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD22_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD22_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD22_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD23_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD23_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD23_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD24_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD24_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD24_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD25_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD25_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD25_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD26_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD26_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD26_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD27_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD27_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD27_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD28_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD28_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD28_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD29_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD29_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD29_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD30_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD30_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD30_EXT";
	#endif
	#ifdef GL_OUTPUT_TEXTURE_COORD31_EXT
		else if ( en == GL_OUTPUT_TEXTURE_COORD31_EXT ) ostr << "GL_OUTPUT_TEXTURE_COORD31_EXT";
	#endif
	#ifdef GL_OUTPUT_FOG_EXT
		else if ( en == GL_OUTPUT_FOG_EXT ) ostr << "GL_OUTPUT_FOG_EXT";
	#endif
	#ifdef GL_SCALAR_EXT
		else if ( en == GL_SCALAR_EXT ) ostr << "GL_SCALAR_EXT";
	#endif
	#ifdef GL_VECTOR_EXT
		else if ( en == GL_VECTOR_EXT ) ostr << "GL_VECTOR_EXT";
	#endif
	#ifdef GL_MATRIX_EXT
		else if ( en == GL_MATRIX_EXT ) ostr << "GL_MATRIX_EXT";
	#endif
	#ifdef GL_VARIANT_EXT
		else if ( en == GL_VARIANT_EXT ) ostr << "GL_VARIANT_EXT";
	#endif
	#ifdef GL_INVARIANT_EXT
		else if ( en == GL_INVARIANT_EXT ) ostr << "GL_INVARIANT_EXT";
	#endif
	#ifdef GL_LOCAL_CONSTANT_EXT
		else if ( en == GL_LOCAL_CONSTANT_EXT ) ostr << "GL_LOCAL_CONSTANT_EXT";
	#endif
	#ifdef GL_LOCAL_EXT
		else if ( en == GL_LOCAL_EXT ) ostr << "GL_LOCAL_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT
		else if ( en == GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT ) ostr << "GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_VARIANTS_EXT
		else if ( en == GL_MAX_VERTEX_SHADER_VARIANTS_EXT ) ostr << "GL_MAX_VERTEX_SHADER_VARIANTS_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_INVARIANTS_EXT
		else if ( en == GL_MAX_VERTEX_SHADER_INVARIANTS_EXT ) ostr << "GL_MAX_VERTEX_SHADER_INVARIANTS_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
		else if ( en == GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) ostr << "GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
	#endif
	#ifdef GL_MAX_VERTEX_SHADER_LOCALS_EXT
		else if ( en == GL_MAX_VERTEX_SHADER_LOCALS_EXT ) ostr << "GL_MAX_VERTEX_SHADER_LOCALS_EXT";
	#endif
	#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT
		else if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT ) ostr << "GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT";
	#endif
	#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT
		else if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT ) ostr << "GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT";
	#endif
	#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT
		else if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT ) ostr << "GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT";
	#endif
	#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
		else if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) ostr << "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
	#endif
	#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT
		else if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT ) ostr << "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_INSTRUCTIONS_EXT
		else if ( en == GL_VERTEX_SHADER_INSTRUCTIONS_EXT ) ostr << "GL_VERTEX_SHADER_INSTRUCTIONS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_VARIANTS_EXT
		else if ( en == GL_VERTEX_SHADER_VARIANTS_EXT ) ostr << "GL_VERTEX_SHADER_VARIANTS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_INVARIANTS_EXT
		else if ( en == GL_VERTEX_SHADER_INVARIANTS_EXT ) ostr << "GL_VERTEX_SHADER_INVARIANTS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
		else if ( en == GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) ostr << "GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_LOCALS_EXT
		else if ( en == GL_VERTEX_SHADER_LOCALS_EXT ) ostr << "GL_VERTEX_SHADER_LOCALS_EXT";
	#endif
	#ifdef GL_VERTEX_SHADER_OPTIMIZED_EXT
		else if ( en == GL_VERTEX_SHADER_OPTIMIZED_EXT ) ostr << "GL_VERTEX_SHADER_OPTIMIZED_EXT";
	#endif
	#ifdef GL_X_EXT
		else if ( en == GL_X_EXT ) ostr << "GL_X_EXT";
	#endif
	#ifdef GL_Y_EXT
		else if ( en == GL_Y_EXT ) ostr << "GL_Y_EXT";
	#endif
	#ifdef GL_Z_EXT
		else if ( en == GL_Z_EXT ) ostr << "GL_Z_EXT";
	#endif
	#ifdef GL_W_EXT
		else if ( en == GL_W_EXT ) ostr << "GL_W_EXT";
	#endif
	#ifdef GL_NEGATIVE_X_EXT
		else if ( en == GL_NEGATIVE_X_EXT ) ostr << "GL_NEGATIVE_X_EXT";
	#endif
	#ifdef GL_NEGATIVE_Y_EXT
		else if ( en == GL_NEGATIVE_Y_EXT ) ostr << "GL_NEGATIVE_Y_EXT";
	#endif
	#ifdef GL_NEGATIVE_Z_EXT
		else if ( en == GL_NEGATIVE_Z_EXT ) ostr << "GL_NEGATIVE_Z_EXT";
	#endif
	#ifdef GL_NEGATIVE_W_EXT
		else if ( en == GL_NEGATIVE_W_EXT ) ostr << "GL_NEGATIVE_W_EXT";
	#endif
	#ifdef GL_ZERO_EXT
		else if ( en == GL_ZERO_EXT ) ostr << "GL_ZERO_EXT";
	#endif
	#ifdef GL_ONE_EXT
		else if ( en == GL_ONE_EXT ) ostr << "GL_ONE_EXT";
	#endif
	#ifdef GL_NEGATIVE_ONE_EXT
		else if ( en == GL_NEGATIVE_ONE_EXT ) ostr << "GL_NEGATIVE_ONE_EXT";
	#endif
	#ifdef GL_NORMALIZED_RANGE_EXT
		else if ( en == GL_NORMALIZED_RANGE_EXT ) ostr << "GL_NORMALIZED_RANGE_EXT";
	#endif
	#ifdef GL_FULL_RANGE_EXT
		else if ( en == GL_FULL_RANGE_EXT ) ostr << "GL_FULL_RANGE_EXT";
	#endif
	#ifdef GL_CURRENT_VERTEX_EXT
		else if ( en == GL_CURRENT_VERTEX_EXT ) ostr << "GL_CURRENT_VERTEX_EXT";
	#endif
	#ifdef GL_MVP_MATRIX_EXT
		else if ( en == GL_MVP_MATRIX_EXT ) ostr << "GL_MVP_MATRIX_EXT";
	#endif
	#ifdef GL_VARIANT_VALUE_EXT
		else if ( en == GL_VARIANT_VALUE_EXT ) ostr << "GL_VARIANT_VALUE_EXT";
	#endif
	#ifdef GL_VARIANT_DATATYPE_EXT
		else if ( en == GL_VARIANT_DATATYPE_EXT ) ostr << "GL_VARIANT_DATATYPE_EXT";
	#endif
	#ifdef GL_VARIANT_ARRAY_STRIDE_EXT
		else if ( en == GL_VARIANT_ARRAY_STRIDE_EXT ) ostr << "GL_VARIANT_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_VARIANT_ARRAY_TYPE_EXT
		else if ( en == GL_VARIANT_ARRAY_TYPE_EXT ) ostr << "GL_VARIANT_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_VARIANT_ARRAY_EXT
		else if ( en == GL_VARIANT_ARRAY_EXT ) ostr << "GL_VARIANT_ARRAY_EXT";
	#endif
	#ifdef GL_VARIANT_ARRAY_POINTER_EXT
		else if ( en == GL_VARIANT_ARRAY_POINTER_EXT ) ostr << "GL_VARIANT_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_INVARIANT_VALUE_EXT
		else if ( en == GL_INVARIANT_VALUE_EXT ) ostr << "GL_INVARIANT_VALUE_EXT";
	#endif
	#ifdef GL_INVARIANT_DATATYPE_EXT
		else if ( en == GL_INVARIANT_DATATYPE_EXT ) ostr << "GL_INVARIANT_DATATYPE_EXT";
	#endif
	#ifdef GL_LOCAL_CONSTANT_VALUE_EXT
		else if ( en == GL_LOCAL_CONSTANT_VALUE_EXT ) ostr << "GL_LOCAL_CONSTANT_VALUE_EXT";
	#endif
	#ifdef GL_LOCAL_CONSTANT_DATATYPE_EXT
		else if ( en == GL_LOCAL_CONSTANT_DATATYPE_EXT ) ostr << "GL_LOCAL_CONSTANT_DATATYPE_EXT";
	#endif
	#ifdef GL_MODELVIEW0_STACK_DEPTH_EXT
		else if ( en == GL_MODELVIEW0_STACK_DEPTH_EXT ) ostr << "GL_MODELVIEW0_STACK_DEPTH_EXT";
	#endif
	#ifdef GL_MODELVIEW0_MATRIX_EXT
		else if ( en == GL_MODELVIEW0_MATRIX_EXT ) ostr << "GL_MODELVIEW0_MATRIX_EXT";
	#endif
	#ifdef GL_MODELVIEW0_EXT
		else if ( en == GL_MODELVIEW0_EXT ) ostr << "GL_MODELVIEW0_EXT";
	#endif
	#ifdef GL_MODELVIEW1_STACK_DEPTH_EXT
		else if ( en == GL_MODELVIEW1_STACK_DEPTH_EXT ) ostr << "GL_MODELVIEW1_STACK_DEPTH_EXT";
	#endif
	#ifdef GL_MODELVIEW1_MATRIX_EXT
		else if ( en == GL_MODELVIEW1_MATRIX_EXT ) ostr << "GL_MODELVIEW1_MATRIX_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHTING_EXT
		else if ( en == GL_VERTEX_WEIGHTING_EXT ) ostr << "GL_VERTEX_WEIGHTING_EXT";
	#endif
	#ifdef GL_MODELVIEW1_EXT
		else if ( en == GL_MODELVIEW1_EXT ) ostr << "GL_MODELVIEW1_EXT";
	#endif
	#ifdef GL_CURRENT_VERTEX_WEIGHT_EXT
		else if ( en == GL_CURRENT_VERTEX_WEIGHT_EXT ) ostr << "GL_CURRENT_VERTEX_WEIGHT_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHT_ARRAY_EXT
		else if ( en == GL_VERTEX_WEIGHT_ARRAY_EXT ) ostr << "GL_VERTEX_WEIGHT_ARRAY_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT
		else if ( en == GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT ) ostr << "GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT
		else if ( en == GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT ) ostr << "GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT
		else if ( en == GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT ) ostr << "GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT";
	#endif
	#ifdef GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT
		else if ( en == GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT ) ostr << "GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT";
	#endif
	#ifdef GL_SYNC_X11_FENCE_EXT
		else if ( en == GL_SYNC_X11_FENCE_EXT ) ostr << "GL_SYNC_X11_FENCE_EXT";
	#endif
	#ifdef GL_CULL_VERTEX_IBM
		else if ( en == GL_CULL_VERTEX_IBM ) ostr << "GL_CULL_VERTEX_IBM";
	#endif
	#ifdef GL_RASTER_POSITION_UNCLIPPED_IBM
		else if ( en == GL_RASTER_POSITION_UNCLIPPED_IBM ) ostr << "GL_RASTER_POSITION_UNCLIPPED_IBM";
	#endif
	#ifdef GL_ALL_STATIC_DATA_IBM
		else if ( en == GL_ALL_STATIC_DATA_IBM ) ostr << "GL_ALL_STATIC_DATA_IBM";
	#endif
	#ifdef GL_STATIC_VERTEX_ARRAY_IBM
		else if ( en == GL_STATIC_VERTEX_ARRAY_IBM ) ostr << "GL_STATIC_VERTEX_ARRAY_IBM";
	#endif
	#ifdef GL_MIRRORED_REPEAT_IBM
		else if ( en == GL_MIRRORED_REPEAT_IBM ) ostr << "GL_MIRRORED_REPEAT_IBM";
	#endif
	#ifdef GL_VERTEX_ARRAY_LIST_IBM
		else if ( en == GL_VERTEX_ARRAY_LIST_IBM ) ostr << "GL_VERTEX_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_NORMAL_ARRAY_LIST_IBM
		else if ( en == GL_NORMAL_ARRAY_LIST_IBM ) ostr << "GL_NORMAL_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_COLOR_ARRAY_LIST_IBM
		else if ( en == GL_COLOR_ARRAY_LIST_IBM ) ostr << "GL_COLOR_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_INDEX_ARRAY_LIST_IBM
		else if ( en == GL_INDEX_ARRAY_LIST_IBM ) ostr << "GL_INDEX_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_LIST_IBM
		else if ( en == GL_TEXTURE_COORD_ARRAY_LIST_IBM ) ostr << "GL_TEXTURE_COORD_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_LIST_IBM
		else if ( en == GL_EDGE_FLAG_ARRAY_LIST_IBM ) ostr << "GL_EDGE_FLAG_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_LIST_IBM
		else if ( en == GL_FOG_COORDINATE_ARRAY_LIST_IBM ) ostr << "GL_FOG_COORDINATE_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_LIST_IBM
		else if ( en == GL_SECONDARY_COLOR_ARRAY_LIST_IBM ) ostr << "GL_SECONDARY_COLOR_ARRAY_LIST_IBM";
	#endif
	#ifdef GL_VERTEX_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_VERTEX_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_VERTEX_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_NORMAL_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_NORMAL_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_NORMAL_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_COLOR_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_COLOR_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_COLOR_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_INDEX_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_INDEX_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_INDEX_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM
		else if ( en == GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM ) ostr << "GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM";
	#endif
	#ifdef GL_RED_MIN_CLAMP_INGR
		else if ( en == GL_RED_MIN_CLAMP_INGR ) ostr << "GL_RED_MIN_CLAMP_INGR";
	#endif
	#ifdef GL_GREEN_MIN_CLAMP_INGR
		else if ( en == GL_GREEN_MIN_CLAMP_INGR ) ostr << "GL_GREEN_MIN_CLAMP_INGR";
	#endif
	#ifdef GL_BLUE_MIN_CLAMP_INGR
		else if ( en == GL_BLUE_MIN_CLAMP_INGR ) ostr << "GL_BLUE_MIN_CLAMP_INGR";
	#endif
	#ifdef GL_ALPHA_MIN_CLAMP_INGR
		else if ( en == GL_ALPHA_MIN_CLAMP_INGR ) ostr << "GL_ALPHA_MIN_CLAMP_INGR";
	#endif
	#ifdef GL_RED_MAX_CLAMP_INGR
		else if ( en == GL_RED_MAX_CLAMP_INGR ) ostr << "GL_RED_MAX_CLAMP_INGR";
	#endif
	#ifdef GL_GREEN_MAX_CLAMP_INGR
		else if ( en == GL_GREEN_MAX_CLAMP_INGR ) ostr << "GL_GREEN_MAX_CLAMP_INGR";
	#endif
	#ifdef GL_BLUE_MAX_CLAMP_INGR
		else if ( en == GL_BLUE_MAX_CLAMP_INGR ) ostr << "GL_BLUE_MAX_CLAMP_INGR";
	#endif
	#ifdef GL_ALPHA_MAX_CLAMP_INGR
		else if ( en == GL_ALPHA_MAX_CLAMP_INGR ) ostr << "GL_ALPHA_MAX_CLAMP_INGR";
	#endif
	#ifdef GL_INTERLACE_READ_INGR
		else if ( en == GL_INTERLACE_READ_INGR ) ostr << "GL_INTERLACE_READ_INGR";
	#endif
	#ifdef GL_LAYOUT_LINEAR_CPU_CACHED_INTEL
		else if ( en == GL_LAYOUT_LINEAR_CPU_CACHED_INTEL ) ostr << "GL_LAYOUT_LINEAR_CPU_CACHED_INTEL";
	#endif
	#ifdef GL_TEXTURE_MEMORY_LAYOUT_INTEL
		else if ( en == GL_TEXTURE_MEMORY_LAYOUT_INTEL ) ostr << "GL_TEXTURE_MEMORY_LAYOUT_INTEL";
	#endif
	#ifdef GL_PARALLEL_ARRAYS_INTEL
		else if ( en == GL_PARALLEL_ARRAYS_INTEL ) ostr << "GL_PARALLEL_ARRAYS_INTEL";
	#endif
	#ifdef GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL
		else if ( en == GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL ) ostr << "GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL";
	#endif
	#ifdef GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL
		else if ( en == GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL ) ostr << "GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL";
	#endif
	#ifdef GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL
		else if ( en == GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL ) ostr << "GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL
		else if ( en == GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL ) ostr << "GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL";
	#endif
	#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
		else if ( en == GL_CONTEXT_FLAG_DEBUG_BIT ) ostr << "GL_CONTEXT_FLAG_DEBUG_BIT";
	#endif
	#ifdef GL_STACK_OVERFLOW
		else if ( en == GL_STACK_OVERFLOW ) ostr << "GL_STACK_OVERFLOW";
	#endif
	#ifdef GL_STACK_UNDERFLOW
		else if ( en == GL_STACK_UNDERFLOW ) ostr << "GL_STACK_UNDERFLOW";
	#endif
	#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
		else if ( en == GL_DEBUG_OUTPUT_SYNCHRONOUS ) ostr << "GL_DEBUG_OUTPUT_SYNCHRONOUS";
	#endif
	#ifdef GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH
		else if ( en == GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH ) ostr << "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH";
	#endif
	#ifdef GL_DEBUG_CALLBACK_FUNCTION
		else if ( en == GL_DEBUG_CALLBACK_FUNCTION ) ostr << "GL_DEBUG_CALLBACK_FUNCTION";
	#endif
	#ifdef GL_DEBUG_CALLBACK_USER_PARAM
		else if ( en == GL_DEBUG_CALLBACK_USER_PARAM ) ostr << "GL_DEBUG_CALLBACK_USER_PARAM";
	#endif
	#ifdef GL_DEBUG_SOURCE_API
		else if ( en == GL_DEBUG_SOURCE_API ) ostr << "GL_DEBUG_SOURCE_API";
	#endif
	#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
		else if ( en == GL_DEBUG_SOURCE_WINDOW_SYSTEM ) ostr << "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
	#endif
	#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
		else if ( en == GL_DEBUG_SOURCE_SHADER_COMPILER ) ostr << "GL_DEBUG_SOURCE_SHADER_COMPILER";
	#endif
	#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
		else if ( en == GL_DEBUG_SOURCE_THIRD_PARTY ) ostr << "GL_DEBUG_SOURCE_THIRD_PARTY";
	#endif
	#ifdef GL_DEBUG_SOURCE_APPLICATION
		else if ( en == GL_DEBUG_SOURCE_APPLICATION ) ostr << "GL_DEBUG_SOURCE_APPLICATION";
	#endif
	#ifdef GL_DEBUG_SOURCE_OTHER
		else if ( en == GL_DEBUG_SOURCE_OTHER ) ostr << "GL_DEBUG_SOURCE_OTHER";
	#endif
	#ifdef GL_DEBUG_TYPE_ERROR
		else if ( en == GL_DEBUG_TYPE_ERROR ) ostr << "GL_DEBUG_TYPE_ERROR";
	#endif
	#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
		else if ( en == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR ) ostr << "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR";
	#endif
	#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
		else if ( en == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR ) ostr << "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR";
	#endif
	#ifdef GL_DEBUG_TYPE_PORTABILITY
		else if ( en == GL_DEBUG_TYPE_PORTABILITY ) ostr << "GL_DEBUG_TYPE_PORTABILITY";
	#endif
	#ifdef GL_DEBUG_TYPE_PERFORMANCE
		else if ( en == GL_DEBUG_TYPE_PERFORMANCE ) ostr << "GL_DEBUG_TYPE_PERFORMANCE";
	#endif
	#ifdef GL_DEBUG_TYPE_OTHER
		else if ( en == GL_DEBUG_TYPE_OTHER ) ostr << "GL_DEBUG_TYPE_OTHER";
	#endif
	#ifdef GL_DEBUG_TYPE_MARKER
		else if ( en == GL_DEBUG_TYPE_MARKER ) ostr << "GL_DEBUG_TYPE_MARKER";
	#endif
	#ifdef GL_DEBUG_TYPE_PUSH_GROUP
		else if ( en == GL_DEBUG_TYPE_PUSH_GROUP ) ostr << "GL_DEBUG_TYPE_PUSH_GROUP";
	#endif
	#ifdef GL_DEBUG_TYPE_POP_GROUP
		else if ( en == GL_DEBUG_TYPE_POP_GROUP ) ostr << "GL_DEBUG_TYPE_POP_GROUP";
	#endif
	#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
		else if ( en == GL_DEBUG_SEVERITY_NOTIFICATION ) ostr << "GL_DEBUG_SEVERITY_NOTIFICATION";
	#endif
	#ifdef GL_MAX_DEBUG_GROUP_STACK_DEPTH
		else if ( en == GL_MAX_DEBUG_GROUP_STACK_DEPTH ) ostr << "GL_MAX_DEBUG_GROUP_STACK_DEPTH";
	#endif
	#ifdef GL_DEBUG_GROUP_STACK_DEPTH
		else if ( en == GL_DEBUG_GROUP_STACK_DEPTH ) ostr << "GL_DEBUG_GROUP_STACK_DEPTH";
	#endif
	#ifdef GL_BUFFER
		else if ( en == GL_BUFFER ) ostr << "GL_BUFFER";
	#endif
	#ifdef GL_SHADER
		else if ( en == GL_SHADER ) ostr << "GL_SHADER";
	#endif
	#ifdef GL_PROGRAM
		else if ( en == GL_PROGRAM ) ostr << "GL_PROGRAM";
	#endif
	#ifdef GL_QUERY
		else if ( en == GL_QUERY ) ostr << "GL_QUERY";
	#endif
	#ifdef GL_PROGRAM_PIPELINE
		else if ( en == GL_PROGRAM_PIPELINE ) ostr << "GL_PROGRAM_PIPELINE";
	#endif
	#ifdef GL_SAMPLER
		else if ( en == GL_SAMPLER ) ostr << "GL_SAMPLER";
	#endif
	#ifdef GL_DISPLAY_LIST
		else if ( en == GL_DISPLAY_LIST ) ostr << "GL_DISPLAY_LIST";
	#endif
	#ifdef GL_MAX_LABEL_LENGTH
		else if ( en == GL_MAX_LABEL_LENGTH ) ostr << "GL_MAX_LABEL_LENGTH";
	#endif
	#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH
		else if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH ) ostr << "GL_MAX_DEBUG_MESSAGE_LENGTH";
	#endif
	#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES
		else if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES ) ostr << "GL_MAX_DEBUG_LOGGED_MESSAGES";
	#endif
	#ifdef GL_DEBUG_LOGGED_MESSAGES
		else if ( en == GL_DEBUG_LOGGED_MESSAGES ) ostr << "GL_DEBUG_LOGGED_MESSAGES";
	#endif
	#ifdef GL_DEBUG_SEVERITY_HIGH
		else if ( en == GL_DEBUG_SEVERITY_HIGH ) ostr << "GL_DEBUG_SEVERITY_HIGH";
	#endif
	#ifdef GL_DEBUG_SEVERITY_MEDIUM
		else if ( en == GL_DEBUG_SEVERITY_MEDIUM ) ostr << "GL_DEBUG_SEVERITY_MEDIUM";
	#endif
	#ifdef GL_DEBUG_SEVERITY_LOW
		else if ( en == GL_DEBUG_SEVERITY_LOW ) ostr << "GL_DEBUG_SEVERITY_LOW";
	#endif
	#ifdef GL_DEBUG_OUTPUT
		else if ( en == GL_DEBUG_OUTPUT ) ostr << "GL_DEBUG_OUTPUT";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_4x4_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_4x4_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_4x4_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_5x4_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_5x4_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_5x4_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_5x5_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_5x5_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_5x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_6x5_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_6x5_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_6x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_6x6_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_6x6_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_6x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_8x5_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_8x5_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_8x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_8x6_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_8x6_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_8x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_8x8_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_8x8_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_8x8_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_10x5_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_10x5_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_10x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_10x6_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_10x6_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_10x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_10x8_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_10x8_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_10x8_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_10x10_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_10x10_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_10x10_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_12x10_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_12x10_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_12x10_KHR";
	#endif
	#ifdef GL_COMPRESSED_RGBA_ASTC_12x12_KHR
		else if ( en == GL_COMPRESSED_RGBA_ASTC_12x12_KHR ) ostr << "GL_COMPRESSED_RGBA_ASTC_12x12_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR";
	#endif
	#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR
		else if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR ) ostr << "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR";
	#endif
	#ifdef GL_KTX_FRONT_REGION
		else if ( en == GL_KTX_FRONT_REGION ) ostr << "GL_KTX_FRONT_REGION";
	#endif
	#ifdef GL_KTX_BACK_REGION
		else if ( en == GL_KTX_BACK_REGION ) ostr << "GL_KTX_BACK_REGION";
	#endif
	#ifdef GL_KTX_Z_REGION
		else if ( en == GL_KTX_Z_REGION ) ostr << "GL_KTX_Z_REGION";
	#endif
	#ifdef GL_KTX_STENCIL_REGION
		else if ( en == GL_KTX_STENCIL_REGION ) ostr << "GL_KTX_STENCIL_REGION";
	#endif
	#ifdef GL_TEXTURE_1D_STACK_MESAX
		else if ( en == GL_TEXTURE_1D_STACK_MESAX ) ostr << "GL_TEXTURE_1D_STACK_MESAX";
	#endif
	#ifdef GL_TEXTURE_2D_STACK_MESAX
		else if ( en == GL_TEXTURE_2D_STACK_MESAX ) ostr << "GL_TEXTURE_2D_STACK_MESAX";
	#endif
	#ifdef GL_PROXY_TEXTURE_1D_STACK_MESAX
		else if ( en == GL_PROXY_TEXTURE_1D_STACK_MESAX ) ostr << "GL_PROXY_TEXTURE_1D_STACK_MESAX";
	#endif
	#ifdef GL_PROXY_TEXTURE_2D_STACK_MESAX
		else if ( en == GL_PROXY_TEXTURE_2D_STACK_MESAX ) ostr << "GL_PROXY_TEXTURE_2D_STACK_MESAX";
	#endif
	#ifdef GL_TEXTURE_1D_STACK_BINDING_MESAX
		else if ( en == GL_TEXTURE_1D_STACK_BINDING_MESAX ) ostr << "GL_TEXTURE_1D_STACK_BINDING_MESAX";
	#endif
	#ifdef GL_TEXTURE_2D_STACK_BINDING_MESAX
		else if ( en == GL_TEXTURE_2D_STACK_BINDING_MESAX ) ostr << "GL_TEXTURE_2D_STACK_BINDING_MESAX";
	#endif
	#ifdef GL_PACK_INVERT_MESA
		else if ( en == GL_PACK_INVERT_MESA ) ostr << "GL_PACK_INVERT_MESA";
	#endif
	#ifdef GL_UNSIGNED_SHORT_8_8_MESA
		else if ( en == GL_UNSIGNED_SHORT_8_8_MESA ) ostr << "GL_UNSIGNED_SHORT_8_8_MESA";
	#endif
	#ifdef GL_UNSIGNED_SHORT_8_8_REV_MESA
		else if ( en == GL_UNSIGNED_SHORT_8_8_REV_MESA ) ostr << "GL_UNSIGNED_SHORT_8_8_REV_MESA";
	#endif
	#ifdef GL_YCBCR_MESA
		else if ( en == GL_YCBCR_MESA ) ostr << "GL_YCBCR_MESA";
	#endif
	#ifdef GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX
		else if ( en == GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX ) ostr << "GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX";
	#endif
	#ifdef GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX
		else if ( en == GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX ) ostr << "GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX";
	#endif
	#ifdef GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX
		else if ( en == GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX ) ostr << "GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX";
	#endif
	#ifdef GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX
		else if ( en == GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX ) ostr << "GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX";
	#endif
	#ifdef GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX
		else if ( en == GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX ) ostr << "GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX";
	#endif
	#ifdef GL_BLEND_PREMULTIPLIED_SRC_NV
		else if ( en == GL_BLEND_PREMULTIPLIED_SRC_NV ) ostr << "GL_BLEND_PREMULTIPLIED_SRC_NV";
	#endif
	#ifdef GL_BLEND_OVERLAP_NV
		else if ( en == GL_BLEND_OVERLAP_NV ) ostr << "GL_BLEND_OVERLAP_NV";
	#endif
	#ifdef GL_UNCORRELATED_NV
		else if ( en == GL_UNCORRELATED_NV ) ostr << "GL_UNCORRELATED_NV";
	#endif
	#ifdef GL_DISJOINT_NV
		else if ( en == GL_DISJOINT_NV ) ostr << "GL_DISJOINT_NV";
	#endif
	#ifdef GL_CONJOINT_NV
		else if ( en == GL_CONJOINT_NV ) ostr << "GL_CONJOINT_NV";
	#endif
	#ifdef GL_BLEND_ADVANCED_COHERENT_NV
		else if ( en == GL_BLEND_ADVANCED_COHERENT_NV ) ostr << "GL_BLEND_ADVANCED_COHERENT_NV";
	#endif
	#ifdef GL_SRC_NV
		else if ( en == GL_SRC_NV ) ostr << "GL_SRC_NV";
	#endif
	#ifdef GL_DST_NV
		else if ( en == GL_DST_NV ) ostr << "GL_DST_NV";
	#endif
	#ifdef GL_SRC_OVER_NV
		else if ( en == GL_SRC_OVER_NV ) ostr << "GL_SRC_OVER_NV";
	#endif
	#ifdef GL_DST_OVER_NV
		else if ( en == GL_DST_OVER_NV ) ostr << "GL_DST_OVER_NV";
	#endif
	#ifdef GL_SRC_IN_NV
		else if ( en == GL_SRC_IN_NV ) ostr << "GL_SRC_IN_NV";
	#endif
	#ifdef GL_DST_IN_NV
		else if ( en == GL_DST_IN_NV ) ostr << "GL_DST_IN_NV";
	#endif
	#ifdef GL_SRC_OUT_NV
		else if ( en == GL_SRC_OUT_NV ) ostr << "GL_SRC_OUT_NV";
	#endif
	#ifdef GL_DST_OUT_NV
		else if ( en == GL_DST_OUT_NV ) ostr << "GL_DST_OUT_NV";
	#endif
	#ifdef GL_SRC_ATOP_NV
		else if ( en == GL_SRC_ATOP_NV ) ostr << "GL_SRC_ATOP_NV";
	#endif
	#ifdef GL_DST_ATOP_NV
		else if ( en == GL_DST_ATOP_NV ) ostr << "GL_DST_ATOP_NV";
	#endif
	#ifdef GL_PLUS_NV
		else if ( en == GL_PLUS_NV ) ostr << "GL_PLUS_NV";
	#endif
	#ifdef GL_PLUS_DARKER_NV
		else if ( en == GL_PLUS_DARKER_NV ) ostr << "GL_PLUS_DARKER_NV";
	#endif
	#ifdef GL_MULTIPLY_NV
		else if ( en == GL_MULTIPLY_NV ) ostr << "GL_MULTIPLY_NV";
	#endif
	#ifdef GL_SCREEN_NV
		else if ( en == GL_SCREEN_NV ) ostr << "GL_SCREEN_NV";
	#endif
	#ifdef GL_OVERLAY_NV
		else if ( en == GL_OVERLAY_NV ) ostr << "GL_OVERLAY_NV";
	#endif
	#ifdef GL_DARKEN_NV
		else if ( en == GL_DARKEN_NV ) ostr << "GL_DARKEN_NV";
	#endif
	#ifdef GL_LIGHTEN_NV
		else if ( en == GL_LIGHTEN_NV ) ostr << "GL_LIGHTEN_NV";
	#endif
	#ifdef GL_COLORDODGE_NV
		else if ( en == GL_COLORDODGE_NV ) ostr << "GL_COLORDODGE_NV";
	#endif
	#ifdef GL_COLORBURN_NV
		else if ( en == GL_COLORBURN_NV ) ostr << "GL_COLORBURN_NV";
	#endif
	#ifdef GL_HARDLIGHT_NV
		else if ( en == GL_HARDLIGHT_NV ) ostr << "GL_HARDLIGHT_NV";
	#endif
	#ifdef GL_SOFTLIGHT_NV
		else if ( en == GL_SOFTLIGHT_NV ) ostr << "GL_SOFTLIGHT_NV";
	#endif
	#ifdef GL_DIFFERENCE_NV
		else if ( en == GL_DIFFERENCE_NV ) ostr << "GL_DIFFERENCE_NV";
	#endif
	#ifdef GL_MINUS_NV
		else if ( en == GL_MINUS_NV ) ostr << "GL_MINUS_NV";
	#endif
	#ifdef GL_EXCLUSION_NV
		else if ( en == GL_EXCLUSION_NV ) ostr << "GL_EXCLUSION_NV";
	#endif
	#ifdef GL_CONTRAST_NV
		else if ( en == GL_CONTRAST_NV ) ostr << "GL_CONTRAST_NV";
	#endif
	#ifdef GL_INVERT_RGB_NV
		else if ( en == GL_INVERT_RGB_NV ) ostr << "GL_INVERT_RGB_NV";
	#endif
	#ifdef GL_LINEARDODGE_NV
		else if ( en == GL_LINEARDODGE_NV ) ostr << "GL_LINEARDODGE_NV";
	#endif
	#ifdef GL_LINEARBURN_NV
		else if ( en == GL_LINEARBURN_NV ) ostr << "GL_LINEARBURN_NV";
	#endif
	#ifdef GL_VIVIDLIGHT_NV
		else if ( en == GL_VIVIDLIGHT_NV ) ostr << "GL_VIVIDLIGHT_NV";
	#endif
	#ifdef GL_LINEARLIGHT_NV
		else if ( en == GL_LINEARLIGHT_NV ) ostr << "GL_LINEARLIGHT_NV";
	#endif
	#ifdef GL_PINLIGHT_NV
		else if ( en == GL_PINLIGHT_NV ) ostr << "GL_PINLIGHT_NV";
	#endif
	#ifdef GL_HARDMIX_NV
		else if ( en == GL_HARDMIX_NV ) ostr << "GL_HARDMIX_NV";
	#endif
	#ifdef GL_HSL_HUE_NV
		else if ( en == GL_HSL_HUE_NV ) ostr << "GL_HSL_HUE_NV";
	#endif
	#ifdef GL_HSL_SATURATION_NV
		else if ( en == GL_HSL_SATURATION_NV ) ostr << "GL_HSL_SATURATION_NV";
	#endif
	#ifdef GL_HSL_COLOR_NV
		else if ( en == GL_HSL_COLOR_NV ) ostr << "GL_HSL_COLOR_NV";
	#endif
	#ifdef GL_HSL_LUMINOSITY_NV
		else if ( en == GL_HSL_LUMINOSITY_NV ) ostr << "GL_HSL_LUMINOSITY_NV";
	#endif
	#ifdef GL_PLUS_CLAMPED_NV
		else if ( en == GL_PLUS_CLAMPED_NV ) ostr << "GL_PLUS_CLAMPED_NV";
	#endif
	#ifdef GL_PLUS_CLAMPED_ALPHA_NV
		else if ( en == GL_PLUS_CLAMPED_ALPHA_NV ) ostr << "GL_PLUS_CLAMPED_ALPHA_NV";
	#endif
	#ifdef GL_MINUS_CLAMPED_NV
		else if ( en == GL_MINUS_CLAMPED_NV ) ostr << "GL_MINUS_CLAMPED_NV";
	#endif
	#ifdef GL_INVERT_OVG_NV
		else if ( en == GL_INVERT_OVG_NV ) ostr << "GL_INVERT_OVG_NV";
	#endif
	#ifdef GL_COMPUTE_PROGRAM_NV
		else if ( en == GL_COMPUTE_PROGRAM_NV ) ostr << "GL_COMPUTE_PROGRAM_NV";
	#endif
	#ifdef GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_QUERY_WAIT_NV
		else if ( en == GL_QUERY_WAIT_NV ) ostr << "GL_QUERY_WAIT_NV";
	#endif
	#ifdef GL_QUERY_NO_WAIT_NV
		else if ( en == GL_QUERY_NO_WAIT_NV ) ostr << "GL_QUERY_NO_WAIT_NV";
	#endif
	#ifdef GL_QUERY_BY_REGION_WAIT_NV
		else if ( en == GL_QUERY_BY_REGION_WAIT_NV ) ostr << "GL_QUERY_BY_REGION_WAIT_NV";
	#endif
	#ifdef GL_QUERY_BY_REGION_NO_WAIT_NV
		else if ( en == GL_QUERY_BY_REGION_NO_WAIT_NV ) ostr << "GL_QUERY_BY_REGION_NO_WAIT_NV";
	#endif
	#ifdef GL_DEPTH_STENCIL_TO_RGBA_NV
		else if ( en == GL_DEPTH_STENCIL_TO_RGBA_NV ) ostr << "GL_DEPTH_STENCIL_TO_RGBA_NV";
	#endif
	#ifdef GL_DEPTH_STENCIL_TO_BGRA_NV
		else if ( en == GL_DEPTH_STENCIL_TO_BGRA_NV ) ostr << "GL_DEPTH_STENCIL_TO_BGRA_NV";
	#endif
	#ifdef GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV
		else if ( en == GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV ) ostr << "GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV";
	#endif
	#ifdef GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV
		else if ( en == GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV ) ostr << "GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV";
	#endif
	#ifdef GL_DEPTH_COMPONENT32F_NV
		else if ( en == GL_DEPTH_COMPONENT32F_NV ) ostr << "GL_DEPTH_COMPONENT32F_NV";
	#endif
	#ifdef GL_DEPTH32F_STENCIL8_NV
		else if ( en == GL_DEPTH32F_STENCIL8_NV ) ostr << "GL_DEPTH32F_STENCIL8_NV";
	#endif
	#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV
		else if ( en == GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV ) ostr << "GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV";
	#endif
	#ifdef GL_DEPTH_BUFFER_FLOAT_MODE_NV
		else if ( en == GL_DEPTH_BUFFER_FLOAT_MODE_NV ) ostr << "GL_DEPTH_BUFFER_FLOAT_MODE_NV";
	#endif
	#ifdef GL_DEPTH_CLAMP_NV
		else if ( en == GL_DEPTH_CLAMP_NV ) ostr << "GL_DEPTH_CLAMP_NV";
	#endif
	#ifdef GL_SAMPLE_COUNT_BITS_NV
		else if ( en == GL_SAMPLE_COUNT_BITS_NV ) ostr << "GL_SAMPLE_COUNT_BITS_NV";
	#endif
	#ifdef GL_CURRENT_SAMPLE_COUNT_QUERY_NV
		else if ( en == GL_CURRENT_SAMPLE_COUNT_QUERY_NV ) ostr << "GL_CURRENT_SAMPLE_COUNT_QUERY_NV";
	#endif
	#ifdef GL_QUERY_RESULT_NV
		else if ( en == GL_QUERY_RESULT_NV ) ostr << "GL_QUERY_RESULT_NV";
	#endif
	#ifdef GL_QUERY_RESULT_AVAILABLE_NV
		else if ( en == GL_QUERY_RESULT_AVAILABLE_NV ) ostr << "GL_QUERY_RESULT_AVAILABLE_NV";
	#endif
	#ifdef GL_SAMPLE_COUNT_NV
		else if ( en == GL_SAMPLE_COUNT_NV ) ostr << "GL_SAMPLE_COUNT_NV";
	#endif
	#ifdef GL_EVAL_2D_NV
		else if ( en == GL_EVAL_2D_NV ) ostr << "GL_EVAL_2D_NV";
	#endif
	#ifdef GL_EVAL_TRIANGULAR_2D_NV
		else if ( en == GL_EVAL_TRIANGULAR_2D_NV ) ostr << "GL_EVAL_TRIANGULAR_2D_NV";
	#endif
	#ifdef GL_MAP_TESSELLATION_NV
		else if ( en == GL_MAP_TESSELLATION_NV ) ostr << "GL_MAP_TESSELLATION_NV";
	#endif
	#ifdef GL_MAP_ATTRIB_U_ORDER_NV
		else if ( en == GL_MAP_ATTRIB_U_ORDER_NV ) ostr << "GL_MAP_ATTRIB_U_ORDER_NV";
	#endif
	#ifdef GL_MAP_ATTRIB_V_ORDER_NV
		else if ( en == GL_MAP_ATTRIB_V_ORDER_NV ) ostr << "GL_MAP_ATTRIB_V_ORDER_NV";
	#endif
	#ifdef GL_EVAL_FRACTIONAL_TESSELLATION_NV
		else if ( en == GL_EVAL_FRACTIONAL_TESSELLATION_NV ) ostr << "GL_EVAL_FRACTIONAL_TESSELLATION_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB0_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB0_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB0_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB1_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB1_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB1_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB2_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB2_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB2_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB3_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB3_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB3_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB4_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB4_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB4_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB5_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB5_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB5_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB6_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB6_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB6_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB7_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB7_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB7_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB8_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB8_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB8_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB9_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB9_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB9_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB10_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB10_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB10_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB11_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB11_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB11_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB12_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB12_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB12_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB13_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB13_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB13_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB14_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB14_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB14_NV";
	#endif
	#ifdef GL_EVAL_VERTEX_ATTRIB15_NV
		else if ( en == GL_EVAL_VERTEX_ATTRIB15_NV ) ostr << "GL_EVAL_VERTEX_ATTRIB15_NV";
	#endif
	#ifdef GL_MAX_MAP_TESSELLATION_NV
		else if ( en == GL_MAX_MAP_TESSELLATION_NV ) ostr << "GL_MAX_MAP_TESSELLATION_NV";
	#endif
	#ifdef GL_MAX_RATIONAL_EVAL_ORDER_NV
		else if ( en == GL_MAX_RATIONAL_EVAL_ORDER_NV ) ostr << "GL_MAX_RATIONAL_EVAL_ORDER_NV";
	#endif
	#ifdef GL_SAMPLE_POSITION_NV
		else if ( en == GL_SAMPLE_POSITION_NV ) ostr << "GL_SAMPLE_POSITION_NV";
	#endif
	#ifdef GL_SAMPLE_MASK_NV
		else if ( en == GL_SAMPLE_MASK_NV ) ostr << "GL_SAMPLE_MASK_NV";
	#endif
	#ifdef GL_SAMPLE_MASK_VALUE_NV
		else if ( en == GL_SAMPLE_MASK_VALUE_NV ) ostr << "GL_SAMPLE_MASK_VALUE_NV";
	#endif
	#ifdef GL_TEXTURE_BINDING_RENDERBUFFER_NV
		else if ( en == GL_TEXTURE_BINDING_RENDERBUFFER_NV ) ostr << "GL_TEXTURE_BINDING_RENDERBUFFER_NV";
	#endif
	#ifdef GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV
		else if ( en == GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV ) ostr << "GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV";
	#endif
	#ifdef GL_TEXTURE_RENDERBUFFER_NV
		else if ( en == GL_TEXTURE_RENDERBUFFER_NV ) ostr << "GL_TEXTURE_RENDERBUFFER_NV";
	#endif
	#ifdef GL_SAMPLER_RENDERBUFFER_NV
		else if ( en == GL_SAMPLER_RENDERBUFFER_NV ) ostr << "GL_SAMPLER_RENDERBUFFER_NV";
	#endif
	#ifdef GL_INT_SAMPLER_RENDERBUFFER_NV
		else if ( en == GL_INT_SAMPLER_RENDERBUFFER_NV ) ostr << "GL_INT_SAMPLER_RENDERBUFFER_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV
		else if ( en == GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV ) ostr << "GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV";
	#endif
	#ifdef GL_MAX_SAMPLE_MASK_WORDS_NV
		else if ( en == GL_MAX_SAMPLE_MASK_WORDS_NV ) ostr << "GL_MAX_SAMPLE_MASK_WORDS_NV";
	#endif
	#ifdef GL_ALL_COMPLETED_NV
		else if ( en == GL_ALL_COMPLETED_NV ) ostr << "GL_ALL_COMPLETED_NV";
	#endif
	#ifdef GL_FENCE_STATUS_NV
		else if ( en == GL_FENCE_STATUS_NV ) ostr << "GL_FENCE_STATUS_NV";
	#endif
	#ifdef GL_FENCE_CONDITION_NV
		else if ( en == GL_FENCE_CONDITION_NV ) ostr << "GL_FENCE_CONDITION_NV";
	#endif
	#ifdef GL_FLOAT_R_NV
		else if ( en == GL_FLOAT_R_NV ) ostr << "GL_FLOAT_R_NV";
	#endif
	#ifdef GL_FLOAT_RG_NV
		else if ( en == GL_FLOAT_RG_NV ) ostr << "GL_FLOAT_RG_NV";
	#endif
	#ifdef GL_FLOAT_RGB_NV
		else if ( en == GL_FLOAT_RGB_NV ) ostr << "GL_FLOAT_RGB_NV";
	#endif
	#ifdef GL_FLOAT_RGBA_NV
		else if ( en == GL_FLOAT_RGBA_NV ) ostr << "GL_FLOAT_RGBA_NV";
	#endif
	#ifdef GL_FLOAT_R16_NV
		else if ( en == GL_FLOAT_R16_NV ) ostr << "GL_FLOAT_R16_NV";
	#endif
	#ifdef GL_FLOAT_R32_NV
		else if ( en == GL_FLOAT_R32_NV ) ostr << "GL_FLOAT_R32_NV";
	#endif
	#ifdef GL_FLOAT_RG16_NV
		else if ( en == GL_FLOAT_RG16_NV ) ostr << "GL_FLOAT_RG16_NV";
	#endif
	#ifdef GL_FLOAT_RG32_NV
		else if ( en == GL_FLOAT_RG32_NV ) ostr << "GL_FLOAT_RG32_NV";
	#endif
	#ifdef GL_FLOAT_RGB16_NV
		else if ( en == GL_FLOAT_RGB16_NV ) ostr << "GL_FLOAT_RGB16_NV";
	#endif
	#ifdef GL_FLOAT_RGB32_NV
		else if ( en == GL_FLOAT_RGB32_NV ) ostr << "GL_FLOAT_RGB32_NV";
	#endif
	#ifdef GL_FLOAT_RGBA16_NV
		else if ( en == GL_FLOAT_RGBA16_NV ) ostr << "GL_FLOAT_RGBA16_NV";
	#endif
	#ifdef GL_FLOAT_RGBA32_NV
		else if ( en == GL_FLOAT_RGBA32_NV ) ostr << "GL_FLOAT_RGBA32_NV";
	#endif
	#ifdef GL_TEXTURE_FLOAT_COMPONENTS_NV
		else if ( en == GL_TEXTURE_FLOAT_COMPONENTS_NV ) ostr << "GL_TEXTURE_FLOAT_COMPONENTS_NV";
	#endif
	#ifdef GL_FLOAT_CLEAR_COLOR_VALUE_NV
		else if ( en == GL_FLOAT_CLEAR_COLOR_VALUE_NV ) ostr << "GL_FLOAT_CLEAR_COLOR_VALUE_NV";
	#endif
	#ifdef GL_FLOAT_RGBA_MODE_NV
		else if ( en == GL_FLOAT_RGBA_MODE_NV ) ostr << "GL_FLOAT_RGBA_MODE_NV";
	#endif
	#ifdef GL_FOG_DISTANCE_MODE_NV
		else if ( en == GL_FOG_DISTANCE_MODE_NV ) ostr << "GL_FOG_DISTANCE_MODE_NV";
	#endif
	#ifdef GL_EYE_RADIAL_NV
		else if ( en == GL_EYE_RADIAL_NV ) ostr << "GL_EYE_RADIAL_NV";
	#endif
	#ifdef GL_EYE_PLANE_ABSOLUTE_NV
		else if ( en == GL_EYE_PLANE_ABSOLUTE_NV ) ostr << "GL_EYE_PLANE_ABSOLUTE_NV";
	#endif
	#ifdef GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV
		else if ( en == GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV ) ostr << "GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV";
	#endif
	#ifdef GL_FRAGMENT_PROGRAM_NV
		else if ( en == GL_FRAGMENT_PROGRAM_NV ) ostr << "GL_FRAGMENT_PROGRAM_NV";
	#endif
	#ifdef GL_MAX_TEXTURE_COORDS_NV
		else if ( en == GL_MAX_TEXTURE_COORDS_NV ) ostr << "GL_MAX_TEXTURE_COORDS_NV";
	#endif
	#ifdef GL_MAX_TEXTURE_IMAGE_UNITS_NV
		else if ( en == GL_MAX_TEXTURE_IMAGE_UNITS_NV ) ostr << "GL_MAX_TEXTURE_IMAGE_UNITS_NV";
	#endif
	#ifdef GL_FRAGMENT_PROGRAM_BINDING_NV
		else if ( en == GL_FRAGMENT_PROGRAM_BINDING_NV ) ostr << "GL_FRAGMENT_PROGRAM_BINDING_NV";
	#endif
	#ifdef GL_PROGRAM_ERROR_STRING_NV
		else if ( en == GL_PROGRAM_ERROR_STRING_NV ) ostr << "GL_PROGRAM_ERROR_STRING_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV
		else if ( en == GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV ) ostr << "GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_CALL_DEPTH_NV
		else if ( en == GL_MAX_PROGRAM_CALL_DEPTH_NV ) ostr << "GL_MAX_PROGRAM_CALL_DEPTH_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_IF_DEPTH_NV
		else if ( en == GL_MAX_PROGRAM_IF_DEPTH_NV ) ostr << "GL_MAX_PROGRAM_IF_DEPTH_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_LOOP_DEPTH_NV
		else if ( en == GL_MAX_PROGRAM_LOOP_DEPTH_NV ) ostr << "GL_MAX_PROGRAM_LOOP_DEPTH_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_LOOP_COUNT_NV
		else if ( en == GL_MAX_PROGRAM_LOOP_COUNT_NV ) ostr << "GL_MAX_PROGRAM_LOOP_COUNT_NV";
	#endif
	#ifdef GL_RENDERBUFFER_COVERAGE_SAMPLES_NV
		else if ( en == GL_RENDERBUFFER_COVERAGE_SAMPLES_NV ) ostr << "GL_RENDERBUFFER_COVERAGE_SAMPLES_NV";
	#endif
	#ifdef GL_RENDERBUFFER_COLOR_SAMPLES_NV
		else if ( en == GL_RENDERBUFFER_COLOR_SAMPLES_NV ) ostr << "GL_RENDERBUFFER_COLOR_SAMPLES_NV";
	#endif
	#ifdef GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV
		else if ( en == GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV ) ostr << "GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV";
	#endif
	#ifdef GL_MULTISAMPLE_COVERAGE_MODES_NV
		else if ( en == GL_MULTISAMPLE_COVERAGE_MODES_NV ) ostr << "GL_MULTISAMPLE_COVERAGE_MODES_NV";
	#endif
	#ifdef GL_GEOMETRY_PROGRAM_NV
		else if ( en == GL_GEOMETRY_PROGRAM_NV ) ostr << "GL_GEOMETRY_PROGRAM_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_OUTPUT_VERTICES_NV
		else if ( en == GL_MAX_PROGRAM_OUTPUT_VERTICES_NV ) ostr << "GL_MAX_PROGRAM_OUTPUT_VERTICES_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV
		else if ( en == GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV ) ostr << "GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV";
	#endif
	#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET_NV
		else if ( en == GL_MIN_PROGRAM_TEXEL_OFFSET_NV ) ostr << "GL_MIN_PROGRAM_TEXEL_OFFSET_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET_NV
		else if ( en == GL_MAX_PROGRAM_TEXEL_OFFSET_NV ) ostr << "GL_MAX_PROGRAM_TEXEL_OFFSET_NV";
	#endif
	#ifdef GL_PROGRAM_ATTRIB_COMPONENTS_NV
		else if ( en == GL_PROGRAM_ATTRIB_COMPONENTS_NV ) ostr << "GL_PROGRAM_ATTRIB_COMPONENTS_NV";
	#endif
	#ifdef GL_PROGRAM_RESULT_COMPONENTS_NV
		else if ( en == GL_PROGRAM_RESULT_COMPONENTS_NV ) ostr << "GL_PROGRAM_RESULT_COMPONENTS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV
		else if ( en == GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV ) ostr << "GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_RESULT_COMPONENTS_NV
		else if ( en == GL_MAX_PROGRAM_RESULT_COMPONENTS_NV ) ostr << "GL_MAX_PROGRAM_RESULT_COMPONENTS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV
		else if ( en == GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV ) ostr << "GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_GENERIC_RESULTS_NV
		else if ( en == GL_MAX_PROGRAM_GENERIC_RESULTS_NV ) ostr << "GL_MAX_PROGRAM_GENERIC_RESULTS_NV";
	#endif
	#ifdef GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV
		else if ( en == GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV ) ostr << "GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV";
	#endif
	#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV
		else if ( en == GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV ) ostr << "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV";
	#endif
	#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV
		else if ( en == GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV ) ostr << "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV";
	#endif
	#ifdef GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV
		else if ( en == GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV ) ostr << "GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV";
	#endif
	#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV
		else if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV ) ostr << "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV
		else if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV ) ostr << "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV";
	#endif
	#ifdef GL_INT64_NV
		else if ( en == GL_INT64_NV ) ostr << "GL_INT64_NV";
	#endif
	#ifdef GL_UNSIGNED_INT64_NV
		else if ( en == GL_UNSIGNED_INT64_NV ) ostr << "GL_UNSIGNED_INT64_NV";
	#endif
	#ifdef GL_INT8_NV
		else if ( en == GL_INT8_NV ) ostr << "GL_INT8_NV";
	#endif
	#ifdef GL_INT8_VEC2_NV
		else if ( en == GL_INT8_VEC2_NV ) ostr << "GL_INT8_VEC2_NV";
	#endif
	#ifdef GL_INT8_VEC3_NV
		else if ( en == GL_INT8_VEC3_NV ) ostr << "GL_INT8_VEC3_NV";
	#endif
	#ifdef GL_INT8_VEC4_NV
		else if ( en == GL_INT8_VEC4_NV ) ostr << "GL_INT8_VEC4_NV";
	#endif
	#ifdef GL_INT16_NV
		else if ( en == GL_INT16_NV ) ostr << "GL_INT16_NV";
	#endif
	#ifdef GL_INT16_VEC2_NV
		else if ( en == GL_INT16_VEC2_NV ) ostr << "GL_INT16_VEC2_NV";
	#endif
	#ifdef GL_INT16_VEC3_NV
		else if ( en == GL_INT16_VEC3_NV ) ostr << "GL_INT16_VEC3_NV";
	#endif
	#ifdef GL_INT16_VEC4_NV
		else if ( en == GL_INT16_VEC4_NV ) ostr << "GL_INT16_VEC4_NV";
	#endif
	#ifdef GL_INT64_VEC2_NV
		else if ( en == GL_INT64_VEC2_NV ) ostr << "GL_INT64_VEC2_NV";
	#endif
	#ifdef GL_INT64_VEC3_NV
		else if ( en == GL_INT64_VEC3_NV ) ostr << "GL_INT64_VEC3_NV";
	#endif
	#ifdef GL_INT64_VEC4_NV
		else if ( en == GL_INT64_VEC4_NV ) ostr << "GL_INT64_VEC4_NV";
	#endif
	#ifdef GL_UNSIGNED_INT8_NV
		else if ( en == GL_UNSIGNED_INT8_NV ) ostr << "GL_UNSIGNED_INT8_NV";
	#endif
	#ifdef GL_UNSIGNED_INT8_VEC2_NV
		else if ( en == GL_UNSIGNED_INT8_VEC2_NV ) ostr << "GL_UNSIGNED_INT8_VEC2_NV";
	#endif
	#ifdef GL_UNSIGNED_INT8_VEC3_NV
		else if ( en == GL_UNSIGNED_INT8_VEC3_NV ) ostr << "GL_UNSIGNED_INT8_VEC3_NV";
	#endif
	#ifdef GL_UNSIGNED_INT8_VEC4_NV
		else if ( en == GL_UNSIGNED_INT8_VEC4_NV ) ostr << "GL_UNSIGNED_INT8_VEC4_NV";
	#endif
	#ifdef GL_UNSIGNED_INT16_NV
		else if ( en == GL_UNSIGNED_INT16_NV ) ostr << "GL_UNSIGNED_INT16_NV";
	#endif
	#ifdef GL_UNSIGNED_INT16_VEC2_NV
		else if ( en == GL_UNSIGNED_INT16_VEC2_NV ) ostr << "GL_UNSIGNED_INT16_VEC2_NV";
	#endif
	#ifdef GL_UNSIGNED_INT16_VEC3_NV
		else if ( en == GL_UNSIGNED_INT16_VEC3_NV ) ostr << "GL_UNSIGNED_INT16_VEC3_NV";
	#endif
	#ifdef GL_UNSIGNED_INT16_VEC4_NV
		else if ( en == GL_UNSIGNED_INT16_VEC4_NV ) ostr << "GL_UNSIGNED_INT16_VEC4_NV";
	#endif
	#ifdef GL_UNSIGNED_INT64_VEC2_NV
		else if ( en == GL_UNSIGNED_INT64_VEC2_NV ) ostr << "GL_UNSIGNED_INT64_VEC2_NV";
	#endif
	#ifdef GL_UNSIGNED_INT64_VEC3_NV
		else if ( en == GL_UNSIGNED_INT64_VEC3_NV ) ostr << "GL_UNSIGNED_INT64_VEC3_NV";
	#endif
	#ifdef GL_UNSIGNED_INT64_VEC4_NV
		else if ( en == GL_UNSIGNED_INT64_VEC4_NV ) ostr << "GL_UNSIGNED_INT64_VEC4_NV";
	#endif
	#ifdef GL_FLOAT16_NV
		else if ( en == GL_FLOAT16_NV ) ostr << "GL_FLOAT16_NV";
	#endif
	#ifdef GL_FLOAT16_VEC2_NV
		else if ( en == GL_FLOAT16_VEC2_NV ) ostr << "GL_FLOAT16_VEC2_NV";
	#endif
	#ifdef GL_FLOAT16_VEC3_NV
		else if ( en == GL_FLOAT16_VEC3_NV ) ostr << "GL_FLOAT16_VEC3_NV";
	#endif
	#ifdef GL_FLOAT16_VEC4_NV
		else if ( en == GL_FLOAT16_VEC4_NV ) ostr << "GL_FLOAT16_VEC4_NV";
	#endif
	#ifdef GL_HALF_FLOAT_NV
		else if ( en == GL_HALF_FLOAT_NV ) ostr << "GL_HALF_FLOAT_NV";
	#endif
	#ifdef GL_MAX_SHININESS_NV
		else if ( en == GL_MAX_SHININESS_NV ) ostr << "GL_MAX_SHININESS_NV";
	#endif
	#ifdef GL_MAX_SPOT_EXPONENT_NV
		else if ( en == GL_MAX_SPOT_EXPONENT_NV ) ostr << "GL_MAX_SPOT_EXPONENT_NV";
	#endif
	#ifdef GL_COLOR_SAMPLES_NV
		else if ( en == GL_COLOR_SAMPLES_NV ) ostr << "GL_COLOR_SAMPLES_NV";
	#endif
	#ifdef GL_MULTISAMPLE_FILTER_HINT_NV
		else if ( en == GL_MULTISAMPLE_FILTER_HINT_NV ) ostr << "GL_MULTISAMPLE_FILTER_HINT_NV";
	#endif
	#ifdef GL_PIXEL_COUNTER_BITS_NV
		else if ( en == GL_PIXEL_COUNTER_BITS_NV ) ostr << "GL_PIXEL_COUNTER_BITS_NV";
	#endif
	#ifdef GL_CURRENT_OCCLUSION_QUERY_ID_NV
		else if ( en == GL_CURRENT_OCCLUSION_QUERY_ID_NV ) ostr << "GL_CURRENT_OCCLUSION_QUERY_ID_NV";
	#endif
	#ifdef GL_PIXEL_COUNT_NV
		else if ( en == GL_PIXEL_COUNT_NV ) ostr << "GL_PIXEL_COUNT_NV";
	#endif
	#ifdef GL_PIXEL_COUNT_AVAILABLE_NV
		else if ( en == GL_PIXEL_COUNT_AVAILABLE_NV ) ostr << "GL_PIXEL_COUNT_AVAILABLE_NV";
	#endif
	#ifdef GL_DEPTH_STENCIL_NV
		else if ( en == GL_DEPTH_STENCIL_NV ) ostr << "GL_DEPTH_STENCIL_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_24_8_NV
		else if ( en == GL_UNSIGNED_INT_24_8_NV ) ostr << "GL_UNSIGNED_INT_24_8_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV
		else if ( en == GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV ) ostr << "GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV
		else if ( en == GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV ) ostr << "GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV";
	#endif
	#ifdef GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_CLOSE_PATH_NV
		else if ( en == GL_CLOSE_PATH_NV ) ostr << "GL_CLOSE_PATH_NV";
	#endif
	#ifdef GL_BOLD_BIT_NV
		else if ( en == GL_BOLD_BIT_NV ) ostr << "GL_BOLD_BIT_NV";
	#endif
	#ifdef GL_GLYPH_WIDTH_BIT_NV
		else if ( en == GL_GLYPH_WIDTH_BIT_NV ) ostr << "GL_GLYPH_WIDTH_BIT_NV";
	#endif
	#ifdef GL_GLYPH_HEIGHT_BIT_NV
		else if ( en == GL_GLYPH_HEIGHT_BIT_NV ) ostr << "GL_GLYPH_HEIGHT_BIT_NV";
	#endif
	#ifdef GL_ITALIC_BIT_NV
		else if ( en == GL_ITALIC_BIT_NV ) ostr << "GL_ITALIC_BIT_NV";
	#endif
	#ifdef GL_MOVE_TO_NV
		else if ( en == GL_MOVE_TO_NV ) ostr << "GL_MOVE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_MOVE_TO_NV
		else if ( en == GL_RELATIVE_MOVE_TO_NV ) ostr << "GL_RELATIVE_MOVE_TO_NV";
	#endif
	#ifdef GL_LINE_TO_NV
		else if ( en == GL_LINE_TO_NV ) ostr << "GL_LINE_TO_NV";
	#endif
	#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
		else if ( en == GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV ) ostr << "GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV";
	#endif
	#ifdef GL_RELATIVE_LINE_TO_NV
		else if ( en == GL_RELATIVE_LINE_TO_NV ) ostr << "GL_RELATIVE_LINE_TO_NV";
	#endif
	#ifdef GL_HORIZONTAL_LINE_TO_NV
		else if ( en == GL_HORIZONTAL_LINE_TO_NV ) ostr << "GL_HORIZONTAL_LINE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
		else if ( en == GL_RELATIVE_HORIZONTAL_LINE_TO_NV ) ostr << "GL_RELATIVE_HORIZONTAL_LINE_TO_NV";
	#endif
	#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
		else if ( en == GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV ) ostr << "GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV";
	#endif
	#ifdef GL_VERTICAL_LINE_TO_NV
		else if ( en == GL_VERTICAL_LINE_TO_NV ) ostr << "GL_VERTICAL_LINE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
		else if ( en == GL_RELATIVE_VERTICAL_LINE_TO_NV ) ostr << "GL_RELATIVE_VERTICAL_LINE_TO_NV";
	#endif
	#ifdef GL_QUADRATIC_CURVE_TO_NV
		else if ( en == GL_QUADRATIC_CURVE_TO_NV ) ostr << "GL_QUADRATIC_CURVE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
		else if ( en == GL_RELATIVE_QUADRATIC_CURVE_TO_NV ) ostr << "GL_RELATIVE_QUADRATIC_CURVE_TO_NV";
	#endif
	#ifdef GL_CUBIC_CURVE_TO_NV
		else if ( en == GL_CUBIC_CURVE_TO_NV ) ostr << "GL_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
		else if ( en == GL_RELATIVE_CUBIC_CURVE_TO_NV ) ostr << "GL_RELATIVE_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
		else if ( en == GL_SMOOTH_QUADRATIC_CURVE_TO_NV ) ostr << "GL_SMOOTH_QUADRATIC_CURVE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
		else if ( en == GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV ) ostr << "GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV";
	#endif
	#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
		else if ( en == GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV ) ostr << "GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV";
	#endif
	#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
		else if ( en == GL_SMOOTH_CUBIC_CURVE_TO_NV ) ostr << "GL_SMOOTH_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
		else if ( en == GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV ) ostr << "GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_SMALL_CCW_ARC_TO_NV
		else if ( en == GL_SMALL_CCW_ARC_TO_NV ) ostr << "GL_SMALL_CCW_ARC_TO_NV";
	#endif
	#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
		else if ( en == GL_RELATIVE_SMALL_CCW_ARC_TO_NV ) ostr << "GL_RELATIVE_SMALL_CCW_ARC_TO_NV";
	#endif
	#ifdef GL_SMALL_CW_ARC_TO_NV
		else if ( en == GL_SMALL_CW_ARC_TO_NV ) ostr << "GL_SMALL_CW_ARC_TO_NV";
	#endif
	#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
		else if ( en == GL_RELATIVE_SMALL_CW_ARC_TO_NV ) ostr << "GL_RELATIVE_SMALL_CW_ARC_TO_NV";
	#endif
	#ifdef GL_LARGE_CCW_ARC_TO_NV
		else if ( en == GL_LARGE_CCW_ARC_TO_NV ) ostr << "GL_LARGE_CCW_ARC_TO_NV";
	#endif
	#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
		else if ( en == GL_RELATIVE_LARGE_CCW_ARC_TO_NV ) ostr << "GL_RELATIVE_LARGE_CCW_ARC_TO_NV";
	#endif
	#ifdef GL_LARGE_CW_ARC_TO_NV
		else if ( en == GL_LARGE_CW_ARC_TO_NV ) ostr << "GL_LARGE_CW_ARC_TO_NV";
	#endif
	#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
		else if ( en == GL_RELATIVE_LARGE_CW_ARC_TO_NV ) ostr << "GL_RELATIVE_LARGE_CW_ARC_TO_NV";
	#endif
	#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
		else if ( en == GL_GLYPH_VERTICAL_BEARING_X_BIT_NV ) ostr << "GL_GLYPH_VERTICAL_BEARING_X_BIT_NV";
	#endif
	#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
		else if ( en == GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV ) ostr << "GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV";
	#endif
	#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
		else if ( en == GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV ) ostr << "GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV";
	#endif
	#ifdef GL_RESTART_PATH_NV
		else if ( en == GL_RESTART_PATH_NV ) ostr << "GL_RESTART_PATH_NV";
	#endif
	#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
		else if ( en == GL_DUP_FIRST_CUBIC_CURVE_TO_NV ) ostr << "GL_DUP_FIRST_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
		else if ( en == GL_DUP_LAST_CUBIC_CURVE_TO_NV ) ostr << "GL_DUP_LAST_CUBIC_CURVE_TO_NV";
	#endif
	#ifdef GL_RECT_NV
		else if ( en == GL_RECT_NV ) ostr << "GL_RECT_NV";
	#endif
	#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
		else if ( en == GL_CIRCULAR_CCW_ARC_TO_NV ) ostr << "GL_CIRCULAR_CCW_ARC_TO_NV";
	#endif
	#ifdef GL_CIRCULAR_CW_ARC_TO_NV
		else if ( en == GL_CIRCULAR_CW_ARC_TO_NV ) ostr << "GL_CIRCULAR_CW_ARC_TO_NV";
	#endif
	#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
		else if ( en == GL_CIRCULAR_TANGENT_ARC_TO_NV ) ostr << "GL_CIRCULAR_TANGENT_ARC_TO_NV";
	#endif
	#ifdef GL_ARC_TO_NV
		else if ( en == GL_ARC_TO_NV ) ostr << "GL_ARC_TO_NV";
	#endif
	#ifdef GL_RELATIVE_ARC_TO_NV
		else if ( en == GL_RELATIVE_ARC_TO_NV ) ostr << "GL_RELATIVE_ARC_TO_NV";
	#endif
	#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
		else if ( en == GL_GLYPH_HAS_KERNING_BIT_NV ) ostr << "GL_GLYPH_HAS_KERNING_BIT_NV";
	#endif
	#ifdef GL_PRIMARY_COLOR
		else if ( en == GL_PRIMARY_COLOR ) ostr << "GL_PRIMARY_COLOR";
	#endif
	#ifdef GL_PATH_FORMAT_SVG_NV
		else if ( en == GL_PATH_FORMAT_SVG_NV ) ostr << "GL_PATH_FORMAT_SVG_NV";
	#endif
	#ifdef GL_PATH_FORMAT_PS_NV
		else if ( en == GL_PATH_FORMAT_PS_NV ) ostr << "GL_PATH_FORMAT_PS_NV";
	#endif
	#ifdef GL_STANDARD_FONT_NAME_NV
		else if ( en == GL_STANDARD_FONT_NAME_NV ) ostr << "GL_STANDARD_FONT_NAME_NV";
	#endif
	#ifdef GL_SYSTEM_FONT_NAME_NV
		else if ( en == GL_SYSTEM_FONT_NAME_NV ) ostr << "GL_SYSTEM_FONT_NAME_NV";
	#endif
	#ifdef GL_FILE_NAME_NV
		else if ( en == GL_FILE_NAME_NV ) ostr << "GL_FILE_NAME_NV";
	#endif
	#ifdef GL_PATH_STROKE_WIDTH_NV
		else if ( en == GL_PATH_STROKE_WIDTH_NV ) ostr << "GL_PATH_STROKE_WIDTH_NV";
	#endif
	#ifdef GL_PATH_END_CAPS_NV
		else if ( en == GL_PATH_END_CAPS_NV ) ostr << "GL_PATH_END_CAPS_NV";
	#endif
	#ifdef GL_PATH_INITIAL_END_CAP_NV
		else if ( en == GL_PATH_INITIAL_END_CAP_NV ) ostr << "GL_PATH_INITIAL_END_CAP_NV";
	#endif
	#ifdef GL_PATH_TERMINAL_END_CAP_NV
		else if ( en == GL_PATH_TERMINAL_END_CAP_NV ) ostr << "GL_PATH_TERMINAL_END_CAP_NV";
	#endif
	#ifdef GL_PATH_JOIN_STYLE_NV
		else if ( en == GL_PATH_JOIN_STYLE_NV ) ostr << "GL_PATH_JOIN_STYLE_NV";
	#endif
	#ifdef GL_PATH_MITER_LIMIT_NV
		else if ( en == GL_PATH_MITER_LIMIT_NV ) ostr << "GL_PATH_MITER_LIMIT_NV";
	#endif
	#ifdef GL_PATH_DASH_CAPS_NV
		else if ( en == GL_PATH_DASH_CAPS_NV ) ostr << "GL_PATH_DASH_CAPS_NV";
	#endif
	#ifdef GL_PATH_INITIAL_DASH_CAP_NV
		else if ( en == GL_PATH_INITIAL_DASH_CAP_NV ) ostr << "GL_PATH_INITIAL_DASH_CAP_NV";
	#endif
	#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
		else if ( en == GL_PATH_TERMINAL_DASH_CAP_NV ) ostr << "GL_PATH_TERMINAL_DASH_CAP_NV";
	#endif
	#ifdef GL_PATH_DASH_OFFSET_NV
		else if ( en == GL_PATH_DASH_OFFSET_NV ) ostr << "GL_PATH_DASH_OFFSET_NV";
	#endif
	#ifdef GL_PATH_CLIENT_LENGTH_NV
		else if ( en == GL_PATH_CLIENT_LENGTH_NV ) ostr << "GL_PATH_CLIENT_LENGTH_NV";
	#endif
	#ifdef GL_PATH_FILL_MODE_NV
		else if ( en == GL_PATH_FILL_MODE_NV ) ostr << "GL_PATH_FILL_MODE_NV";
	#endif
	#ifdef GL_PATH_FILL_MASK_NV
		else if ( en == GL_PATH_FILL_MASK_NV ) ostr << "GL_PATH_FILL_MASK_NV";
	#endif
	#ifdef GL_PATH_FILL_COVER_MODE_NV
		else if ( en == GL_PATH_FILL_COVER_MODE_NV ) ostr << "GL_PATH_FILL_COVER_MODE_NV";
	#endif
	#ifdef GL_PATH_STROKE_COVER_MODE_NV
		else if ( en == GL_PATH_STROKE_COVER_MODE_NV ) ostr << "GL_PATH_STROKE_COVER_MODE_NV";
	#endif
	#ifdef GL_PATH_STROKE_MASK_NV
		else if ( en == GL_PATH_STROKE_MASK_NV ) ostr << "GL_PATH_STROKE_MASK_NV";
	#endif
	#ifdef GL_COUNT_UP_NV
		else if ( en == GL_COUNT_UP_NV ) ostr << "GL_COUNT_UP_NV";
	#endif
	#ifdef GL_COUNT_DOWN_NV
		else if ( en == GL_COUNT_DOWN_NV ) ostr << "GL_COUNT_DOWN_NV";
	#endif
	#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
		else if ( en == GL_PATH_OBJECT_BOUNDING_BOX_NV ) ostr << "GL_PATH_OBJECT_BOUNDING_BOX_NV";
	#endif
	#ifdef GL_CONVEX_HULL_NV
		else if ( en == GL_CONVEX_HULL_NV ) ostr << "GL_CONVEX_HULL_NV";
	#endif
	#ifdef GL_BOUNDING_BOX_NV
		else if ( en == GL_BOUNDING_BOX_NV ) ostr << "GL_BOUNDING_BOX_NV";
	#endif
	#ifdef GL_TRANSLATE_X_NV
		else if ( en == GL_TRANSLATE_X_NV ) ostr << "GL_TRANSLATE_X_NV";
	#endif
	#ifdef GL_TRANSLATE_Y_NV
		else if ( en == GL_TRANSLATE_Y_NV ) ostr << "GL_TRANSLATE_Y_NV";
	#endif
	#ifdef GL_TRANSLATE_2D_NV
		else if ( en == GL_TRANSLATE_2D_NV ) ostr << "GL_TRANSLATE_2D_NV";
	#endif
	#ifdef GL_TRANSLATE_3D_NV
		else if ( en == GL_TRANSLATE_3D_NV ) ostr << "GL_TRANSLATE_3D_NV";
	#endif
	#ifdef GL_AFFINE_2D_NV
		else if ( en == GL_AFFINE_2D_NV ) ostr << "GL_AFFINE_2D_NV";
	#endif
	#ifdef GL_AFFINE_3D_NV
		else if ( en == GL_AFFINE_3D_NV ) ostr << "GL_AFFINE_3D_NV";
	#endif
	#ifdef GL_TRANSPOSE_AFFINE_2D_NV
		else if ( en == GL_TRANSPOSE_AFFINE_2D_NV ) ostr << "GL_TRANSPOSE_AFFINE_2D_NV";
	#endif
	#ifdef GL_TRANSPOSE_AFFINE_3D_NV
		else if ( en == GL_TRANSPOSE_AFFINE_3D_NV ) ostr << "GL_TRANSPOSE_AFFINE_3D_NV";
	#endif
	#ifdef GL_UTF8_NV
		else if ( en == GL_UTF8_NV ) ostr << "GL_UTF8_NV";
	#endif
	#ifdef GL_UTF16_NV
		else if ( en == GL_UTF16_NV ) ostr << "GL_UTF16_NV";
	#endif
	#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
		else if ( en == GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV ) ostr << "GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV";
	#endif
	#ifdef GL_PATH_COMMAND_COUNT_NV
		else if ( en == GL_PATH_COMMAND_COUNT_NV ) ostr << "GL_PATH_COMMAND_COUNT_NV";
	#endif
	#ifdef GL_PATH_COORD_COUNT_NV
		else if ( en == GL_PATH_COORD_COUNT_NV ) ostr << "GL_PATH_COORD_COUNT_NV";
	#endif
	#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
		else if ( en == GL_PATH_DASH_ARRAY_COUNT_NV ) ostr << "GL_PATH_DASH_ARRAY_COUNT_NV";
	#endif
	#ifdef GL_PATH_COMPUTED_LENGTH_NV
		else if ( en == GL_PATH_COMPUTED_LENGTH_NV ) ostr << "GL_PATH_COMPUTED_LENGTH_NV";
	#endif
	#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
		else if ( en == GL_PATH_FILL_BOUNDING_BOX_NV ) ostr << "GL_PATH_FILL_BOUNDING_BOX_NV";
	#endif
	#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
		else if ( en == GL_PATH_STROKE_BOUNDING_BOX_NV ) ostr << "GL_PATH_STROKE_BOUNDING_BOX_NV";
	#endif
	#ifdef GL_SQUARE_NV
		else if ( en == GL_SQUARE_NV ) ostr << "GL_SQUARE_NV";
	#endif
	#ifdef GL_ROUND_NV
		else if ( en == GL_ROUND_NV ) ostr << "GL_ROUND_NV";
	#endif
	#ifdef GL_TRIANGULAR_NV
		else if ( en == GL_TRIANGULAR_NV ) ostr << "GL_TRIANGULAR_NV";
	#endif
	#ifdef GL_BEVEL_NV
		else if ( en == GL_BEVEL_NV ) ostr << "GL_BEVEL_NV";
	#endif
	#ifdef GL_MITER_REVERT_NV
		else if ( en == GL_MITER_REVERT_NV ) ostr << "GL_MITER_REVERT_NV";
	#endif
	#ifdef GL_MITER_TRUNCATE_NV
		else if ( en == GL_MITER_TRUNCATE_NV ) ostr << "GL_MITER_TRUNCATE_NV";
	#endif
	#ifdef GL_SKIP_MISSING_GLYPH_NV
		else if ( en == GL_SKIP_MISSING_GLYPH_NV ) ostr << "GL_SKIP_MISSING_GLYPH_NV";
	#endif
	#ifdef GL_USE_MISSING_GLYPH_NV
		else if ( en == GL_USE_MISSING_GLYPH_NV ) ostr << "GL_USE_MISSING_GLYPH_NV";
	#endif
	#ifdef GL_PATH_ERROR_POSITION_NV
		else if ( en == GL_PATH_ERROR_POSITION_NV ) ostr << "GL_PATH_ERROR_POSITION_NV";
	#endif
	#ifdef GL_PATH_FOG_GEN_MODE_NV
		else if ( en == GL_PATH_FOG_GEN_MODE_NV ) ostr << "GL_PATH_FOG_GEN_MODE_NV";
	#endif
	#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
		else if ( en == GL_ACCUM_ADJACENT_PAIRS_NV ) ostr << "GL_ACCUM_ADJACENT_PAIRS_NV";
	#endif
	#ifdef GL_ADJACENT_PAIRS_NV
		else if ( en == GL_ADJACENT_PAIRS_NV ) ostr << "GL_ADJACENT_PAIRS_NV";
	#endif
	#ifdef GL_FIRST_TO_REST_NV
		else if ( en == GL_FIRST_TO_REST_NV ) ostr << "GL_FIRST_TO_REST_NV";
	#endif
	#ifdef GL_PATH_GEN_MODE_NV
		else if ( en == GL_PATH_GEN_MODE_NV ) ostr << "GL_PATH_GEN_MODE_NV";
	#endif
	#ifdef GL_PATH_GEN_COEFF_NV
		else if ( en == GL_PATH_GEN_COEFF_NV ) ostr << "GL_PATH_GEN_COEFF_NV";
	#endif
	#ifdef GL_PATH_GEN_COLOR_FORMAT_NV
		else if ( en == GL_PATH_GEN_COLOR_FORMAT_NV ) ostr << "GL_PATH_GEN_COLOR_FORMAT_NV";
	#endif
	#ifdef GL_PATH_GEN_COMPONENTS_NV
		else if ( en == GL_PATH_GEN_COMPONENTS_NV ) ostr << "GL_PATH_GEN_COMPONENTS_NV";
	#endif
	#ifdef GL_PATH_DASH_OFFSET_RESET_NV
		else if ( en == GL_PATH_DASH_OFFSET_RESET_NV ) ostr << "GL_PATH_DASH_OFFSET_RESET_NV";
	#endif
	#ifdef GL_MOVE_TO_RESETS_NV
		else if ( en == GL_MOVE_TO_RESETS_NV ) ostr << "GL_MOVE_TO_RESETS_NV";
	#endif
	#ifdef GL_MOVE_TO_CONTINUES_NV
		else if ( en == GL_MOVE_TO_CONTINUES_NV ) ostr << "GL_MOVE_TO_CONTINUES_NV";
	#endif
	#ifdef GL_PATH_STENCIL_FUNC_NV
		else if ( en == GL_PATH_STENCIL_FUNC_NV ) ostr << "GL_PATH_STENCIL_FUNC_NV";
	#endif
	#ifdef GL_PATH_STENCIL_REF_NV
		else if ( en == GL_PATH_STENCIL_REF_NV ) ostr << "GL_PATH_STENCIL_REF_NV";
	#endif
	#ifdef GL_PATH_STENCIL_VALUE_MASK_NV
		else if ( en == GL_PATH_STENCIL_VALUE_MASK_NV ) ostr << "GL_PATH_STENCIL_VALUE_MASK_NV";
	#endif
	#ifdef GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV
		else if ( en == GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV ) ostr << "GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV";
	#endif
	#ifdef GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV
		else if ( en == GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV ) ostr << "GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV";
	#endif
	#ifdef GL_PATH_COVER_DEPTH_FUNC_NV
		else if ( en == GL_PATH_COVER_DEPTH_FUNC_NV ) ostr << "GL_PATH_COVER_DEPTH_FUNC_NV";
	#endif
	#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
		else if ( en == GL_FONT_X_MIN_BOUNDS_BIT_NV ) ostr << "GL_FONT_X_MIN_BOUNDS_BIT_NV";
	#endif
	#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
		else if ( en == GL_FONT_Y_MIN_BOUNDS_BIT_NV ) ostr << "GL_FONT_Y_MIN_BOUNDS_BIT_NV";
	#endif
	#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
		else if ( en == GL_FONT_X_MAX_BOUNDS_BIT_NV ) ostr << "GL_FONT_X_MAX_BOUNDS_BIT_NV";
	#endif
	#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
		else if ( en == GL_FONT_Y_MAX_BOUNDS_BIT_NV ) ostr << "GL_FONT_Y_MAX_BOUNDS_BIT_NV";
	#endif
	#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
		else if ( en == GL_FONT_UNITS_PER_EM_BIT_NV ) ostr << "GL_FONT_UNITS_PER_EM_BIT_NV";
	#endif
	#ifdef GL_FONT_ASCENDER_BIT_NV
		else if ( en == GL_FONT_ASCENDER_BIT_NV ) ostr << "GL_FONT_ASCENDER_BIT_NV";
	#endif
	#ifdef GL_FONT_DESCENDER_BIT_NV
		else if ( en == GL_FONT_DESCENDER_BIT_NV ) ostr << "GL_FONT_DESCENDER_BIT_NV";
	#endif
	#ifdef GL_FONT_HEIGHT_BIT_NV
		else if ( en == GL_FONT_HEIGHT_BIT_NV ) ostr << "GL_FONT_HEIGHT_BIT_NV";
	#endif
	#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
		else if ( en == GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV ) ostr << "GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV";
	#endif
	#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
		else if ( en == GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV ) ostr << "GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV";
	#endif
	#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
		else if ( en == GL_FONT_UNDERLINE_POSITION_BIT_NV ) ostr << "GL_FONT_UNDERLINE_POSITION_BIT_NV";
	#endif
	#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
		else if ( en == GL_FONT_UNDERLINE_THICKNESS_BIT_NV ) ostr << "GL_FONT_UNDERLINE_THICKNESS_BIT_NV";
	#endif
	#ifdef GL_FONT_HAS_KERNING_BIT_NV
		else if ( en == GL_FONT_HAS_KERNING_BIT_NV ) ostr << "GL_FONT_HAS_KERNING_BIT_NV";
	#endif
	#ifdef GL_WRITE_PIXEL_DATA_RANGE_NV
		else if ( en == GL_WRITE_PIXEL_DATA_RANGE_NV ) ostr << "GL_WRITE_PIXEL_DATA_RANGE_NV";
	#endif
	#ifdef GL_READ_PIXEL_DATA_RANGE_NV
		else if ( en == GL_READ_PIXEL_DATA_RANGE_NV ) ostr << "GL_READ_PIXEL_DATA_RANGE_NV";
	#endif
	#ifdef GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV
		else if ( en == GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV ) ostr << "GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV";
	#endif
	#ifdef GL_READ_PIXEL_DATA_RANGE_LENGTH_NV
		else if ( en == GL_READ_PIXEL_DATA_RANGE_LENGTH_NV ) ostr << "GL_READ_PIXEL_DATA_RANGE_LENGTH_NV";
	#endif
	#ifdef GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV
		else if ( en == GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV ) ostr << "GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV";
	#endif
	#ifdef GL_READ_PIXEL_DATA_RANGE_POINTER_NV
		else if ( en == GL_READ_PIXEL_DATA_RANGE_POINTER_NV ) ostr << "GL_READ_PIXEL_DATA_RANGE_POINTER_NV";
	#endif
	#ifdef GL_POINT_SPRITE_NV
		else if ( en == GL_POINT_SPRITE_NV ) ostr << "GL_POINT_SPRITE_NV";
	#endif
	#ifdef GL_COORD_REPLACE_NV
		else if ( en == GL_COORD_REPLACE_NV ) ostr << "GL_COORD_REPLACE_NV";
	#endif
	#ifdef GL_POINT_SPRITE_R_MODE_NV
		else if ( en == GL_POINT_SPRITE_R_MODE_NV ) ostr << "GL_POINT_SPRITE_R_MODE_NV";
	#endif
	#ifdef GL_FRAME_NV
		else if ( en == GL_FRAME_NV ) ostr << "GL_FRAME_NV";
	#endif
	#ifdef GL_FIELDS_NV
		else if ( en == GL_FIELDS_NV ) ostr << "GL_FIELDS_NV";
	#endif
	#ifdef GL_CURRENT_TIME_NV
		else if ( en == GL_CURRENT_TIME_NV ) ostr << "GL_CURRENT_TIME_NV";
	#endif
	#ifdef GL_NUM_FILL_STREAMS_NV
		else if ( en == GL_NUM_FILL_STREAMS_NV ) ostr << "GL_NUM_FILL_STREAMS_NV";
	#endif
	#ifdef GL_PRESENT_TIME_NV
		else if ( en == GL_PRESENT_TIME_NV ) ostr << "GL_PRESENT_TIME_NV";
	#endif
	#ifdef GL_PRESENT_DURATION_NV
		else if ( en == GL_PRESENT_DURATION_NV ) ostr << "GL_PRESENT_DURATION_NV";
	#endif
	#ifdef GL_PRIMITIVE_RESTART_NV
		else if ( en == GL_PRIMITIVE_RESTART_NV ) ostr << "GL_PRIMITIVE_RESTART_NV";
	#endif
	#ifdef GL_PRIMITIVE_RESTART_INDEX_NV
		else if ( en == GL_PRIMITIVE_RESTART_INDEX_NV ) ostr << "GL_PRIMITIVE_RESTART_INDEX_NV";
	#endif
	#ifdef GL_REGISTER_COMBINERS_NV
		else if ( en == GL_REGISTER_COMBINERS_NV ) ostr << "GL_REGISTER_COMBINERS_NV";
	#endif
	#ifdef GL_VARIABLE_A_NV
		else if ( en == GL_VARIABLE_A_NV ) ostr << "GL_VARIABLE_A_NV";
	#endif
	#ifdef GL_VARIABLE_B_NV
		else if ( en == GL_VARIABLE_B_NV ) ostr << "GL_VARIABLE_B_NV";
	#endif
	#ifdef GL_VARIABLE_C_NV
		else if ( en == GL_VARIABLE_C_NV ) ostr << "GL_VARIABLE_C_NV";
	#endif
	#ifdef GL_VARIABLE_D_NV
		else if ( en == GL_VARIABLE_D_NV ) ostr << "GL_VARIABLE_D_NV";
	#endif
	#ifdef GL_VARIABLE_E_NV
		else if ( en == GL_VARIABLE_E_NV ) ostr << "GL_VARIABLE_E_NV";
	#endif
	#ifdef GL_VARIABLE_F_NV
		else if ( en == GL_VARIABLE_F_NV ) ostr << "GL_VARIABLE_F_NV";
	#endif
	#ifdef GL_VARIABLE_G_NV
		else if ( en == GL_VARIABLE_G_NV ) ostr << "GL_VARIABLE_G_NV";
	#endif
	#ifdef GL_CONSTANT_COLOR0_NV
		else if ( en == GL_CONSTANT_COLOR0_NV ) ostr << "GL_CONSTANT_COLOR0_NV";
	#endif
	#ifdef GL_CONSTANT_COLOR1_NV
		else if ( en == GL_CONSTANT_COLOR1_NV ) ostr << "GL_CONSTANT_COLOR1_NV";
	#endif
	#ifdef GL_PRIMARY_COLOR_NV
		else if ( en == GL_PRIMARY_COLOR_NV ) ostr << "GL_PRIMARY_COLOR_NV";
	#endif
	#ifdef GL_SECONDARY_COLOR_NV
		else if ( en == GL_SECONDARY_COLOR_NV ) ostr << "GL_SECONDARY_COLOR_NV";
	#endif
	#ifdef GL_SPARE0_NV
		else if ( en == GL_SPARE0_NV ) ostr << "GL_SPARE0_NV";
	#endif
	#ifdef GL_SPARE1_NV
		else if ( en == GL_SPARE1_NV ) ostr << "GL_SPARE1_NV";
	#endif
	#ifdef GL_DISCARD_NV
		else if ( en == GL_DISCARD_NV ) ostr << "GL_DISCARD_NV";
	#endif
	#ifdef GL_E_TIMES_F_NV
		else if ( en == GL_E_TIMES_F_NV ) ostr << "GL_E_TIMES_F_NV";
	#endif
	#ifdef GL_SPARE0_PLUS_SECONDARY_COLOR_NV
		else if ( en == GL_SPARE0_PLUS_SECONDARY_COLOR_NV ) ostr << "GL_SPARE0_PLUS_SECONDARY_COLOR_NV";
	#endif
	#ifdef GL_UNSIGNED_IDENTITY_NV
		else if ( en == GL_UNSIGNED_IDENTITY_NV ) ostr << "GL_UNSIGNED_IDENTITY_NV";
	#endif
	#ifdef GL_UNSIGNED_INVERT_NV
		else if ( en == GL_UNSIGNED_INVERT_NV ) ostr << "GL_UNSIGNED_INVERT_NV";
	#endif
	#ifdef GL_EXPAND_NORMAL_NV
		else if ( en == GL_EXPAND_NORMAL_NV ) ostr << "GL_EXPAND_NORMAL_NV";
	#endif
	#ifdef GL_EXPAND_NEGATE_NV
		else if ( en == GL_EXPAND_NEGATE_NV ) ostr << "GL_EXPAND_NEGATE_NV";
	#endif
	#ifdef GL_HALF_BIAS_NORMAL_NV
		else if ( en == GL_HALF_BIAS_NORMAL_NV ) ostr << "GL_HALF_BIAS_NORMAL_NV";
	#endif
	#ifdef GL_HALF_BIAS_NEGATE_NV
		else if ( en == GL_HALF_BIAS_NEGATE_NV ) ostr << "GL_HALF_BIAS_NEGATE_NV";
	#endif
	#ifdef GL_SIGNED_IDENTITY_NV
		else if ( en == GL_SIGNED_IDENTITY_NV ) ostr << "GL_SIGNED_IDENTITY_NV";
	#endif
	#ifdef GL_SIGNED_NEGATE_NV
		else if ( en == GL_SIGNED_NEGATE_NV ) ostr << "GL_SIGNED_NEGATE_NV";
	#endif
	#ifdef GL_SCALE_BY_TWO_NV
		else if ( en == GL_SCALE_BY_TWO_NV ) ostr << "GL_SCALE_BY_TWO_NV";
	#endif
	#ifdef GL_SCALE_BY_FOUR_NV
		else if ( en == GL_SCALE_BY_FOUR_NV ) ostr << "GL_SCALE_BY_FOUR_NV";
	#endif
	#ifdef GL_SCALE_BY_ONE_HALF_NV
		else if ( en == GL_SCALE_BY_ONE_HALF_NV ) ostr << "GL_SCALE_BY_ONE_HALF_NV";
	#endif
	#ifdef GL_BIAS_BY_NEGATIVE_ONE_HALF_NV
		else if ( en == GL_BIAS_BY_NEGATIVE_ONE_HALF_NV ) ostr << "GL_BIAS_BY_NEGATIVE_ONE_HALF_NV";
	#endif
	#ifdef GL_COMBINER_INPUT_NV
		else if ( en == GL_COMBINER_INPUT_NV ) ostr << "GL_COMBINER_INPUT_NV";
	#endif
	#ifdef GL_COMBINER_MAPPING_NV
		else if ( en == GL_COMBINER_MAPPING_NV ) ostr << "GL_COMBINER_MAPPING_NV";
	#endif
	#ifdef GL_COMBINER_COMPONENT_USAGE_NV
		else if ( en == GL_COMBINER_COMPONENT_USAGE_NV ) ostr << "GL_COMBINER_COMPONENT_USAGE_NV";
	#endif
	#ifdef GL_COMBINER_AB_DOT_PRODUCT_NV
		else if ( en == GL_COMBINER_AB_DOT_PRODUCT_NV ) ostr << "GL_COMBINER_AB_DOT_PRODUCT_NV";
	#endif
	#ifdef GL_COMBINER_CD_DOT_PRODUCT_NV
		else if ( en == GL_COMBINER_CD_DOT_PRODUCT_NV ) ostr << "GL_COMBINER_CD_DOT_PRODUCT_NV";
	#endif
	#ifdef GL_COMBINER_MUX_SUM_NV
		else if ( en == GL_COMBINER_MUX_SUM_NV ) ostr << "GL_COMBINER_MUX_SUM_NV";
	#endif
	#ifdef GL_COMBINER_SCALE_NV
		else if ( en == GL_COMBINER_SCALE_NV ) ostr << "GL_COMBINER_SCALE_NV";
	#endif
	#ifdef GL_COMBINER_BIAS_NV
		else if ( en == GL_COMBINER_BIAS_NV ) ostr << "GL_COMBINER_BIAS_NV";
	#endif
	#ifdef GL_COMBINER_AB_OUTPUT_NV
		else if ( en == GL_COMBINER_AB_OUTPUT_NV ) ostr << "GL_COMBINER_AB_OUTPUT_NV";
	#endif
	#ifdef GL_COMBINER_CD_OUTPUT_NV
		else if ( en == GL_COMBINER_CD_OUTPUT_NV ) ostr << "GL_COMBINER_CD_OUTPUT_NV";
	#endif
	#ifdef GL_COMBINER_SUM_OUTPUT_NV
		else if ( en == GL_COMBINER_SUM_OUTPUT_NV ) ostr << "GL_COMBINER_SUM_OUTPUT_NV";
	#endif
	#ifdef GL_MAX_GENERAL_COMBINERS_NV
		else if ( en == GL_MAX_GENERAL_COMBINERS_NV ) ostr << "GL_MAX_GENERAL_COMBINERS_NV";
	#endif
	#ifdef GL_NUM_GENERAL_COMBINERS_NV
		else if ( en == GL_NUM_GENERAL_COMBINERS_NV ) ostr << "GL_NUM_GENERAL_COMBINERS_NV";
	#endif
	#ifdef GL_COLOR_SUM_CLAMP_NV
		else if ( en == GL_COLOR_SUM_CLAMP_NV ) ostr << "GL_COLOR_SUM_CLAMP_NV";
	#endif
	#ifdef GL_COMBINER0_NV
		else if ( en == GL_COMBINER0_NV ) ostr << "GL_COMBINER0_NV";
	#endif
	#ifdef GL_COMBINER1_NV
		else if ( en == GL_COMBINER1_NV ) ostr << "GL_COMBINER1_NV";
	#endif
	#ifdef GL_COMBINER2_NV
		else if ( en == GL_COMBINER2_NV ) ostr << "GL_COMBINER2_NV";
	#endif
	#ifdef GL_COMBINER3_NV
		else if ( en == GL_COMBINER3_NV ) ostr << "GL_COMBINER3_NV";
	#endif
	#ifdef GL_COMBINER4_NV
		else if ( en == GL_COMBINER4_NV ) ostr << "GL_COMBINER4_NV";
	#endif
	#ifdef GL_COMBINER5_NV
		else if ( en == GL_COMBINER5_NV ) ostr << "GL_COMBINER5_NV";
	#endif
	#ifdef GL_COMBINER6_NV
		else if ( en == GL_COMBINER6_NV ) ostr << "GL_COMBINER6_NV";
	#endif
	#ifdef GL_COMBINER7_NV
		else if ( en == GL_COMBINER7_NV ) ostr << "GL_COMBINER7_NV";
	#endif
	#ifdef GL_PER_STAGE_CONSTANTS_NV
		else if ( en == GL_PER_STAGE_CONSTANTS_NV ) ostr << "GL_PER_STAGE_CONSTANTS_NV";
	#endif
	#ifdef GL_BUFFER_GPU_ADDRESS_NV
		else if ( en == GL_BUFFER_GPU_ADDRESS_NV ) ostr << "GL_BUFFER_GPU_ADDRESS_NV";
	#endif
	#ifdef GL_GPU_ADDRESS_NV
		else if ( en == GL_GPU_ADDRESS_NV ) ostr << "GL_GPU_ADDRESS_NV";
	#endif
	#ifdef GL_MAX_SHADER_BUFFER_ADDRESS_NV
		else if ( en == GL_MAX_SHADER_BUFFER_ADDRESS_NV ) ostr << "GL_MAX_SHADER_BUFFER_ADDRESS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_PATCH_ATTRIBS_NV
		else if ( en == GL_MAX_PROGRAM_PATCH_ATTRIBS_NV ) ostr << "GL_MAX_PROGRAM_PATCH_ATTRIBS_NV";
	#endif
	#ifdef GL_TESS_CONTROL_PROGRAM_NV
		else if ( en == GL_TESS_CONTROL_PROGRAM_NV ) ostr << "GL_TESS_CONTROL_PROGRAM_NV";
	#endif
	#ifdef GL_TESS_EVALUATION_PROGRAM_NV
		else if ( en == GL_TESS_EVALUATION_PROGRAM_NV ) ostr << "GL_TESS_EVALUATION_PROGRAM_NV";
	#endif
	#ifdef GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV
		else if ( en == GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV ) ostr << "GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV";
	#endif
	#ifdef GL_EMBOSS_LIGHT_NV
		else if ( en == GL_EMBOSS_LIGHT_NV ) ostr << "GL_EMBOSS_LIGHT_NV";
	#endif
	#ifdef GL_EMBOSS_CONSTANT_NV
		else if ( en == GL_EMBOSS_CONSTANT_NV ) ostr << "GL_EMBOSS_CONSTANT_NV";
	#endif
	#ifdef GL_EMBOSS_MAP_NV
		else if ( en == GL_EMBOSS_MAP_NV ) ostr << "GL_EMBOSS_MAP_NV";
	#endif
	#ifdef GL_NORMAL_MAP_NV
		else if ( en == GL_NORMAL_MAP_NV ) ostr << "GL_NORMAL_MAP_NV";
	#endif
	#ifdef GL_REFLECTION_MAP_NV
		else if ( en == GL_REFLECTION_MAP_NV ) ostr << "GL_REFLECTION_MAP_NV";
	#endif
	#ifdef GL_COMBINE4_NV
		else if ( en == GL_COMBINE4_NV ) ostr << "GL_COMBINE4_NV";
	#endif
	#ifdef GL_SOURCE3_RGB_NV
		else if ( en == GL_SOURCE3_RGB_NV ) ostr << "GL_SOURCE3_RGB_NV";
	#endif
	#ifdef GL_SOURCE3_ALPHA_NV
		else if ( en == GL_SOURCE3_ALPHA_NV ) ostr << "GL_SOURCE3_ALPHA_NV";
	#endif
	#ifdef GL_OPERAND3_RGB_NV
		else if ( en == GL_OPERAND3_RGB_NV ) ostr << "GL_OPERAND3_RGB_NV";
	#endif
	#ifdef GL_OPERAND3_ALPHA_NV
		else if ( en == GL_OPERAND3_ALPHA_NV ) ostr << "GL_OPERAND3_ALPHA_NV";
	#endif
	#ifdef GL_TEXTURE_UNSIGNED_REMAP_MODE_NV
		else if ( en == GL_TEXTURE_UNSIGNED_REMAP_MODE_NV ) ostr << "GL_TEXTURE_UNSIGNED_REMAP_MODE_NV";
	#endif
	#ifdef GL_TEXTURE_COVERAGE_SAMPLES_NV
		else if ( en == GL_TEXTURE_COVERAGE_SAMPLES_NV ) ostr << "GL_TEXTURE_COVERAGE_SAMPLES_NV";
	#endif
	#ifdef GL_TEXTURE_COLOR_SAMPLES_NV
		else if ( en == GL_TEXTURE_COLOR_SAMPLES_NV ) ostr << "GL_TEXTURE_COLOR_SAMPLES_NV";
	#endif
	#ifdef GL_TEXTURE_RECTANGLE_NV
		else if ( en == GL_TEXTURE_RECTANGLE_NV ) ostr << "GL_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_TEXTURE_BINDING_RECTANGLE_NV
		else if ( en == GL_TEXTURE_BINDING_RECTANGLE_NV ) ostr << "GL_TEXTURE_BINDING_RECTANGLE_NV";
	#endif
	#ifdef GL_PROXY_TEXTURE_RECTANGLE_NV
		else if ( en == GL_PROXY_TEXTURE_RECTANGLE_NV ) ostr << "GL_PROXY_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_NV
		else if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_NV ) ostr << "GL_MAX_RECTANGLE_TEXTURE_SIZE_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_RECTANGLE_NV
		else if ( en == GL_OFFSET_TEXTURE_RECTANGLE_NV ) ostr << "GL_OFFSET_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV
		else if ( en == GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV ) ostr << "GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV
		else if ( en == GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV ) ostr << "GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV
		else if ( en == GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV ) ostr << "GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_S8_S8_8_8_NV
		else if ( en == GL_UNSIGNED_INT_S8_S8_8_8_NV ) ostr << "GL_UNSIGNED_INT_S8_S8_8_8_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_8_8_S8_S8_REV_NV
		else if ( en == GL_UNSIGNED_INT_8_8_S8_S8_REV_NV ) ostr << "GL_UNSIGNED_INT_8_8_S8_S8_REV_NV";
	#endif
	#ifdef GL_DSDT_MAG_INTENSITY_NV
		else if ( en == GL_DSDT_MAG_INTENSITY_NV ) ostr << "GL_DSDT_MAG_INTENSITY_NV";
	#endif
	#ifdef GL_SHADER_CONSISTENT_NV
		else if ( en == GL_SHADER_CONSISTENT_NV ) ostr << "GL_SHADER_CONSISTENT_NV";
	#endif
	#ifdef GL_TEXTURE_SHADER_NV
		else if ( en == GL_TEXTURE_SHADER_NV ) ostr << "GL_TEXTURE_SHADER_NV";
	#endif
	#ifdef GL_SHADER_OPERATION_NV
		else if ( en == GL_SHADER_OPERATION_NV ) ostr << "GL_SHADER_OPERATION_NV";
	#endif
	#ifdef GL_CULL_MODES_NV
		else if ( en == GL_CULL_MODES_NV ) ostr << "GL_CULL_MODES_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_2D_MATRIX_NV
		else if ( en == GL_OFFSET_TEXTURE_2D_MATRIX_NV ) ostr << "GL_OFFSET_TEXTURE_2D_MATRIX_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_MATRIX_NV
		else if ( en == GL_OFFSET_TEXTURE_MATRIX_NV ) ostr << "GL_OFFSET_TEXTURE_MATRIX_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_2D_SCALE_NV
		else if ( en == GL_OFFSET_TEXTURE_2D_SCALE_NV ) ostr << "GL_OFFSET_TEXTURE_2D_SCALE_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_SCALE_NV
		else if ( en == GL_OFFSET_TEXTURE_SCALE_NV ) ostr << "GL_OFFSET_TEXTURE_SCALE_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_BIAS_NV
		else if ( en == GL_OFFSET_TEXTURE_BIAS_NV ) ostr << "GL_OFFSET_TEXTURE_BIAS_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_2D_BIAS_NV
		else if ( en == GL_OFFSET_TEXTURE_2D_BIAS_NV ) ostr << "GL_OFFSET_TEXTURE_2D_BIAS_NV";
	#endif
	#ifdef GL_PREVIOUS_TEXTURE_INPUT_NV
		else if ( en == GL_PREVIOUS_TEXTURE_INPUT_NV ) ostr << "GL_PREVIOUS_TEXTURE_INPUT_NV";
	#endif
	#ifdef GL_CONST_EYE_NV
		else if ( en == GL_CONST_EYE_NV ) ostr << "GL_CONST_EYE_NV";
	#endif
	#ifdef GL_PASS_THROUGH_NV
		else if ( en == GL_PASS_THROUGH_NV ) ostr << "GL_PASS_THROUGH_NV";
	#endif
	#ifdef GL_CULL_FRAGMENT_NV
		else if ( en == GL_CULL_FRAGMENT_NV ) ostr << "GL_CULL_FRAGMENT_NV";
	#endif
	#ifdef GL_OFFSET_TEXTURE_2D_NV
		else if ( en == GL_OFFSET_TEXTURE_2D_NV ) ostr << "GL_OFFSET_TEXTURE_2D_NV";
	#endif
	#ifdef GL_DEPENDENT_AR_TEXTURE_2D_NV
		else if ( en == GL_DEPENDENT_AR_TEXTURE_2D_NV ) ostr << "GL_DEPENDENT_AR_TEXTURE_2D_NV";
	#endif
	#ifdef GL_DEPENDENT_GB_TEXTURE_2D_NV
		else if ( en == GL_DEPENDENT_GB_TEXTURE_2D_NV ) ostr << "GL_DEPENDENT_GB_TEXTURE_2D_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_NV
		else if ( en == GL_DOT_PRODUCT_NV ) ostr << "GL_DOT_PRODUCT_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_DEPTH_REPLACE_NV
		else if ( en == GL_DOT_PRODUCT_DEPTH_REPLACE_NV ) ostr << "GL_DOT_PRODUCT_DEPTH_REPLACE_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_TEXTURE_2D_NV
		else if ( en == GL_DOT_PRODUCT_TEXTURE_2D_NV ) ostr << "GL_DOT_PRODUCT_TEXTURE_2D_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV
		else if ( en == GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV ) ostr << "GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV
		else if ( en == GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV ) ostr << "GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV
		else if ( en == GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV ) ostr << "GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV
		else if ( en == GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV ) ostr << "GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV";
	#endif
	#ifdef GL_HILO_NV
		else if ( en == GL_HILO_NV ) ostr << "GL_HILO_NV";
	#endif
	#ifdef GL_DSDT_NV
		else if ( en == GL_DSDT_NV ) ostr << "GL_DSDT_NV";
	#endif
	#ifdef GL_DSDT_MAG_NV
		else if ( en == GL_DSDT_MAG_NV ) ostr << "GL_DSDT_MAG_NV";
	#endif
	#ifdef GL_DSDT_MAG_VIB_NV
		else if ( en == GL_DSDT_MAG_VIB_NV ) ostr << "GL_DSDT_MAG_VIB_NV";
	#endif
	#ifdef GL_HILO16_NV
		else if ( en == GL_HILO16_NV ) ostr << "GL_HILO16_NV";
	#endif
	#ifdef GL_SIGNED_HILO_NV
		else if ( en == GL_SIGNED_HILO_NV ) ostr << "GL_SIGNED_HILO_NV";
	#endif
	#ifdef GL_SIGNED_HILO16_NV
		else if ( en == GL_SIGNED_HILO16_NV ) ostr << "GL_SIGNED_HILO16_NV";
	#endif
	#ifdef GL_SIGNED_RGBA_NV
		else if ( en == GL_SIGNED_RGBA_NV ) ostr << "GL_SIGNED_RGBA_NV";
	#endif
	#ifdef GL_SIGNED_RGBA8_NV
		else if ( en == GL_SIGNED_RGBA8_NV ) ostr << "GL_SIGNED_RGBA8_NV";
	#endif
	#ifdef GL_SIGNED_RGB_NV
		else if ( en == GL_SIGNED_RGB_NV ) ostr << "GL_SIGNED_RGB_NV";
	#endif
	#ifdef GL_SIGNED_RGB8_NV
		else if ( en == GL_SIGNED_RGB8_NV ) ostr << "GL_SIGNED_RGB8_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE_NV
		else if ( en == GL_SIGNED_LUMINANCE_NV ) ostr << "GL_SIGNED_LUMINANCE_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE8_NV
		else if ( en == GL_SIGNED_LUMINANCE8_NV ) ostr << "GL_SIGNED_LUMINANCE8_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE_ALPHA_NV
		else if ( en == GL_SIGNED_LUMINANCE_ALPHA_NV ) ostr << "GL_SIGNED_LUMINANCE_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE8_ALPHA8_NV
		else if ( en == GL_SIGNED_LUMINANCE8_ALPHA8_NV ) ostr << "GL_SIGNED_LUMINANCE8_ALPHA8_NV";
	#endif
	#ifdef GL_SIGNED_ALPHA_NV
		else if ( en == GL_SIGNED_ALPHA_NV ) ostr << "GL_SIGNED_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_ALPHA8_NV
		else if ( en == GL_SIGNED_ALPHA8_NV ) ostr << "GL_SIGNED_ALPHA8_NV";
	#endif
	#ifdef GL_SIGNED_INTENSITY_NV
		else if ( en == GL_SIGNED_INTENSITY_NV ) ostr << "GL_SIGNED_INTENSITY_NV";
	#endif
	#ifdef GL_SIGNED_INTENSITY8_NV
		else if ( en == GL_SIGNED_INTENSITY8_NV ) ostr << "GL_SIGNED_INTENSITY8_NV";
	#endif
	#ifdef GL_DSDT8_NV
		else if ( en == GL_DSDT8_NV ) ostr << "GL_DSDT8_NV";
	#endif
	#ifdef GL_DSDT8_MAG8_NV
		else if ( en == GL_DSDT8_MAG8_NV ) ostr << "GL_DSDT8_MAG8_NV";
	#endif
	#ifdef GL_DSDT8_MAG8_INTENSITY8_NV
		else if ( en == GL_DSDT8_MAG8_INTENSITY8_NV ) ostr << "GL_DSDT8_MAG8_INTENSITY8_NV";
	#endif
	#ifdef GL_SIGNED_RGB_UNSIGNED_ALPHA_NV
		else if ( en == GL_SIGNED_RGB_UNSIGNED_ALPHA_NV ) ostr << "GL_SIGNED_RGB_UNSIGNED_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV
		else if ( en == GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV ) ostr << "GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV";
	#endif
	#ifdef GL_HI_SCALE_NV
		else if ( en == GL_HI_SCALE_NV ) ostr << "GL_HI_SCALE_NV";
	#endif
	#ifdef GL_LO_SCALE_NV
		else if ( en == GL_LO_SCALE_NV ) ostr << "GL_LO_SCALE_NV";
	#endif
	#ifdef GL_DS_SCALE_NV
		else if ( en == GL_DS_SCALE_NV ) ostr << "GL_DS_SCALE_NV";
	#endif
	#ifdef GL_DT_SCALE_NV
		else if ( en == GL_DT_SCALE_NV ) ostr << "GL_DT_SCALE_NV";
	#endif
	#ifdef GL_MAGNITUDE_SCALE_NV
		else if ( en == GL_MAGNITUDE_SCALE_NV ) ostr << "GL_MAGNITUDE_SCALE_NV";
	#endif
	#ifdef GL_VIBRANCE_SCALE_NV
		else if ( en == GL_VIBRANCE_SCALE_NV ) ostr << "GL_VIBRANCE_SCALE_NV";
	#endif
	#ifdef GL_HI_BIAS_NV
		else if ( en == GL_HI_BIAS_NV ) ostr << "GL_HI_BIAS_NV";
	#endif
	#ifdef GL_LO_BIAS_NV
		else if ( en == GL_LO_BIAS_NV ) ostr << "GL_LO_BIAS_NV";
	#endif
	#ifdef GL_DS_BIAS_NV
		else if ( en == GL_DS_BIAS_NV ) ostr << "GL_DS_BIAS_NV";
	#endif
	#ifdef GL_DT_BIAS_NV
		else if ( en == GL_DT_BIAS_NV ) ostr << "GL_DT_BIAS_NV";
	#endif
	#ifdef GL_MAGNITUDE_BIAS_NV
		else if ( en == GL_MAGNITUDE_BIAS_NV ) ostr << "GL_MAGNITUDE_BIAS_NV";
	#endif
	#ifdef GL_VIBRANCE_BIAS_NV
		else if ( en == GL_VIBRANCE_BIAS_NV ) ostr << "GL_VIBRANCE_BIAS_NV";
	#endif
	#ifdef GL_TEXTURE_BORDER_VALUES_NV
		else if ( en == GL_TEXTURE_BORDER_VALUES_NV ) ostr << "GL_TEXTURE_BORDER_VALUES_NV";
	#endif
	#ifdef GL_TEXTURE_HI_SIZE_NV
		else if ( en == GL_TEXTURE_HI_SIZE_NV ) ostr << "GL_TEXTURE_HI_SIZE_NV";
	#endif
	#ifdef GL_TEXTURE_LO_SIZE_NV
		else if ( en == GL_TEXTURE_LO_SIZE_NV ) ostr << "GL_TEXTURE_LO_SIZE_NV";
	#endif
	#ifdef GL_TEXTURE_DS_SIZE_NV
		else if ( en == GL_TEXTURE_DS_SIZE_NV ) ostr << "GL_TEXTURE_DS_SIZE_NV";
	#endif
	#ifdef GL_TEXTURE_DT_SIZE_NV
		else if ( en == GL_TEXTURE_DT_SIZE_NV ) ostr << "GL_TEXTURE_DT_SIZE_NV";
	#endif
	#ifdef GL_TEXTURE_MAG_SIZE_NV
		else if ( en == GL_TEXTURE_MAG_SIZE_NV ) ostr << "GL_TEXTURE_MAG_SIZE_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_S8_S8_8_8_NV
		else if ( en == GL_UNSIGNED_INT_S8_S8_8_8_NV ) ostr << "GL_UNSIGNED_INT_S8_S8_8_8_NV";
	#endif
	#ifdef GL_UNSIGNED_INT_8_8_S8_S8_REV_NV
		else if ( en == GL_UNSIGNED_INT_8_8_S8_S8_REV_NV ) ostr << "GL_UNSIGNED_INT_8_8_S8_S8_REV_NV";
	#endif
	#ifdef GL_DSDT_MAG_INTENSITY_NV
		else if ( en == GL_DSDT_MAG_INTENSITY_NV ) ostr << "GL_DSDT_MAG_INTENSITY_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_TEXTURE_3D_NV
		else if ( en == GL_DOT_PRODUCT_TEXTURE_3D_NV ) ostr << "GL_DOT_PRODUCT_TEXTURE_3D_NV";
	#endif
	#ifdef GL_HILO_NV
		else if ( en == GL_HILO_NV ) ostr << "GL_HILO_NV";
	#endif
	#ifdef GL_DSDT_NV
		else if ( en == GL_DSDT_NV ) ostr << "GL_DSDT_NV";
	#endif
	#ifdef GL_DSDT_MAG_NV
		else if ( en == GL_DSDT_MAG_NV ) ostr << "GL_DSDT_MAG_NV";
	#endif
	#ifdef GL_DSDT_MAG_VIB_NV
		else if ( en == GL_DSDT_MAG_VIB_NV ) ostr << "GL_DSDT_MAG_VIB_NV";
	#endif
	#ifdef GL_HILO16_NV
		else if ( en == GL_HILO16_NV ) ostr << "GL_HILO16_NV";
	#endif
	#ifdef GL_SIGNED_HILO_NV
		else if ( en == GL_SIGNED_HILO_NV ) ostr << "GL_SIGNED_HILO_NV";
	#endif
	#ifdef GL_SIGNED_HILO16_NV
		else if ( en == GL_SIGNED_HILO16_NV ) ostr << "GL_SIGNED_HILO16_NV";
	#endif
	#ifdef GL_SIGNED_RGBA_NV
		else if ( en == GL_SIGNED_RGBA_NV ) ostr << "GL_SIGNED_RGBA_NV";
	#endif
	#ifdef GL_SIGNED_RGBA8_NV
		else if ( en == GL_SIGNED_RGBA8_NV ) ostr << "GL_SIGNED_RGBA8_NV";
	#endif
	#ifdef GL_SIGNED_RGB_NV
		else if ( en == GL_SIGNED_RGB_NV ) ostr << "GL_SIGNED_RGB_NV";
	#endif
	#ifdef GL_SIGNED_RGB8_NV
		else if ( en == GL_SIGNED_RGB8_NV ) ostr << "GL_SIGNED_RGB8_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE_NV
		else if ( en == GL_SIGNED_LUMINANCE_NV ) ostr << "GL_SIGNED_LUMINANCE_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE8_NV
		else if ( en == GL_SIGNED_LUMINANCE8_NV ) ostr << "GL_SIGNED_LUMINANCE8_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE_ALPHA_NV
		else if ( en == GL_SIGNED_LUMINANCE_ALPHA_NV ) ostr << "GL_SIGNED_LUMINANCE_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_LUMINANCE8_ALPHA8_NV
		else if ( en == GL_SIGNED_LUMINANCE8_ALPHA8_NV ) ostr << "GL_SIGNED_LUMINANCE8_ALPHA8_NV";
	#endif
	#ifdef GL_SIGNED_ALPHA_NV
		else if ( en == GL_SIGNED_ALPHA_NV ) ostr << "GL_SIGNED_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_ALPHA8_NV
		else if ( en == GL_SIGNED_ALPHA8_NV ) ostr << "GL_SIGNED_ALPHA8_NV";
	#endif
	#ifdef GL_SIGNED_INTENSITY_NV
		else if ( en == GL_SIGNED_INTENSITY_NV ) ostr << "GL_SIGNED_INTENSITY_NV";
	#endif
	#ifdef GL_SIGNED_INTENSITY8_NV
		else if ( en == GL_SIGNED_INTENSITY8_NV ) ostr << "GL_SIGNED_INTENSITY8_NV";
	#endif
	#ifdef GL_DSDT8_NV
		else if ( en == GL_DSDT8_NV ) ostr << "GL_DSDT8_NV";
	#endif
	#ifdef GL_DSDT8_MAG8_NV
		else if ( en == GL_DSDT8_MAG8_NV ) ostr << "GL_DSDT8_MAG8_NV";
	#endif
	#ifdef GL_DSDT8_MAG8_INTENSITY8_NV
		else if ( en == GL_DSDT8_MAG8_INTENSITY8_NV ) ostr << "GL_DSDT8_MAG8_INTENSITY8_NV";
	#endif
	#ifdef GL_SIGNED_RGB_UNSIGNED_ALPHA_NV
		else if ( en == GL_SIGNED_RGB_UNSIGNED_ALPHA_NV ) ostr << "GL_SIGNED_RGB_UNSIGNED_ALPHA_NV";
	#endif
	#ifdef GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV
		else if ( en == GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV ) ostr << "GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV";
	#endif
	#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV
		else if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV ) ostr << "GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV";
	#endif
	#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV
		else if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV ) ostr << "GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV";
	#endif
	#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV
		else if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV ) ostr << "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV
		else if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV ) ostr << "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV";
	#endif
	#ifdef GL_OFFSET_HILO_TEXTURE_2D_NV
		else if ( en == GL_OFFSET_HILO_TEXTURE_2D_NV ) ostr << "GL_OFFSET_HILO_TEXTURE_2D_NV";
	#endif
	#ifdef GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV
		else if ( en == GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV ) ostr << "GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV
		else if ( en == GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV ) ostr << "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV";
	#endif
	#ifdef GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV
		else if ( en == GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV ) ostr << "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV";
	#endif
	#ifdef GL_DEPENDENT_HILO_TEXTURE_2D_NV
		else if ( en == GL_DEPENDENT_HILO_TEXTURE_2D_NV ) ostr << "GL_DEPENDENT_HILO_TEXTURE_2D_NV";
	#endif
	#ifdef GL_DEPENDENT_RGB_TEXTURE_3D_NV
		else if ( en == GL_DEPENDENT_RGB_TEXTURE_3D_NV ) ostr << "GL_DEPENDENT_RGB_TEXTURE_3D_NV";
	#endif
	#ifdef GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV
		else if ( en == GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV ) ostr << "GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_PASS_THROUGH_NV
		else if ( en == GL_DOT_PRODUCT_PASS_THROUGH_NV ) ostr << "GL_DOT_PRODUCT_PASS_THROUGH_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_TEXTURE_1D_NV
		else if ( en == GL_DOT_PRODUCT_TEXTURE_1D_NV ) ostr << "GL_DOT_PRODUCT_TEXTURE_1D_NV";
	#endif
	#ifdef GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV
		else if ( en == GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV ) ostr << "GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV";
	#endif
	#ifdef GL_HILO8_NV
		else if ( en == GL_HILO8_NV ) ostr << "GL_HILO8_NV";
	#endif
	#ifdef GL_SIGNED_HILO8_NV
		else if ( en == GL_SIGNED_HILO8_NV ) ostr << "GL_SIGNED_HILO8_NV";
	#endif
	#ifdef GL_FORCE_BLUE_TO_ONE_NV
		else if ( en == GL_FORCE_BLUE_TO_ONE_NV ) ostr << "GL_FORCE_BLUE_TO_ONE_NV";
	#endif
	#ifdef GL_BACK_PRIMARY_COLOR_NV
		else if ( en == GL_BACK_PRIMARY_COLOR_NV ) ostr << "GL_BACK_PRIMARY_COLOR_NV";
	#endif
	#ifdef GL_BACK_SECONDARY_COLOR_NV
		else if ( en == GL_BACK_SECONDARY_COLOR_NV ) ostr << "GL_BACK_SECONDARY_COLOR_NV";
	#endif
	#ifdef GL_TEXTURE_COORD_NV
		else if ( en == GL_TEXTURE_COORD_NV ) ostr << "GL_TEXTURE_COORD_NV";
	#endif
	#ifdef GL_CLIP_DISTANCE_NV
		else if ( en == GL_CLIP_DISTANCE_NV ) ostr << "GL_CLIP_DISTANCE_NV";
	#endif
	#ifdef GL_VERTEX_ID_NV
		else if ( en == GL_VERTEX_ID_NV ) ostr << "GL_VERTEX_ID_NV";
	#endif
	#ifdef GL_PRIMITIVE_ID_NV
		else if ( en == GL_PRIMITIVE_ID_NV ) ostr << "GL_PRIMITIVE_ID_NV";
	#endif
	#ifdef GL_GENERIC_ATTRIB_NV
		else if ( en == GL_GENERIC_ATTRIB_NV ) ostr << "GL_GENERIC_ATTRIB_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_ATTRIBS_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_ATTRIBS_NV ) ostr << "GL_TRANSFORM_FEEDBACK_ATTRIBS_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV";
	#endif
	#ifdef GL_ACTIVE_VARYINGS_NV
		else if ( en == GL_ACTIVE_VARYINGS_NV ) ostr << "GL_ACTIVE_VARYINGS_NV";
	#endif
	#ifdef GL_ACTIVE_VARYING_MAX_LENGTH_NV
		else if ( en == GL_ACTIVE_VARYING_MAX_LENGTH_NV ) ostr << "GL_ACTIVE_VARYING_MAX_LENGTH_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS_NV ) ostr << "GL_TRANSFORM_FEEDBACK_VARYINGS_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_START_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_RECORD_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_RECORD_NV ) ostr << "GL_TRANSFORM_FEEDBACK_RECORD_NV";
	#endif
	#ifdef GL_PRIMITIVES_GENERATED_NV
		else if ( en == GL_PRIMITIVES_GENERATED_NV ) ostr << "GL_PRIMITIVES_GENERATED_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV ) ostr << "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV";
	#endif
	#ifdef GL_RASTERIZER_DISCARD_NV
		else if ( en == GL_RASTERIZER_DISCARD_NV ) ostr << "GL_RASTERIZER_DISCARD_NV";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV";
	#endif
	#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV
		else if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV ) ostr << "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV";
	#endif
	#ifdef GL_INTERLEAVED_ATTRIBS_NV
		else if ( en == GL_INTERLEAVED_ATTRIBS_NV ) ostr << "GL_INTERLEAVED_ATTRIBS_NV";
	#endif
	#ifdef GL_SEPARATE_ATTRIBS_NV
		else if ( en == GL_SEPARATE_ATTRIBS_NV ) ostr << "GL_SEPARATE_ATTRIBS_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_NV ) ostr << "GL_TRANSFORM_FEEDBACK_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV";
	#endif
	#ifdef GL_TRANSFORM_FEEDBACK_BINDING_NV
		else if ( en == GL_TRANSFORM_FEEDBACK_BINDING_NV ) ostr << "GL_TRANSFORM_FEEDBACK_BINDING_NV";
	#endif
	#ifdef GL_SURFACE_STATE_NV
		else if ( en == GL_SURFACE_STATE_NV ) ostr << "GL_SURFACE_STATE_NV";
	#endif
	#ifdef GL_SURFACE_REGISTERED_NV
		else if ( en == GL_SURFACE_REGISTERED_NV ) ostr << "GL_SURFACE_REGISTERED_NV";
	#endif
	#ifdef GL_SURFACE_MAPPED_NV
		else if ( en == GL_SURFACE_MAPPED_NV ) ostr << "GL_SURFACE_MAPPED_NV";
	#endif
	#ifdef GL_WRITE_DISCARD_NV
		else if ( en == GL_WRITE_DISCARD_NV ) ostr << "GL_WRITE_DISCARD_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_NV
		else if ( en == GL_VERTEX_ARRAY_RANGE_NV ) ostr << "GL_VERTEX_ARRAY_RANGE_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_LENGTH_NV
		else if ( en == GL_VERTEX_ARRAY_RANGE_LENGTH_NV ) ostr << "GL_VERTEX_ARRAY_RANGE_LENGTH_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_VALID_NV
		else if ( en == GL_VERTEX_ARRAY_RANGE_VALID_NV ) ostr << "GL_VERTEX_ARRAY_RANGE_VALID_NV";
	#endif
	#ifdef GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV
		else if ( en == GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV ) ostr << "GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_POINTER_NV
		else if ( en == GL_VERTEX_ARRAY_RANGE_POINTER_NV ) ostr << "GL_VERTEX_ARRAY_RANGE_POINTER_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV
		else if ( en == GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV ) ostr << "GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV";
	#endif
	#ifdef GL_INT64_NV
		else if ( en == GL_INT64_NV ) ostr << "GL_INT64_NV";
	#endif
	#ifdef GL_UNSIGNED_INT64_NV
		else if ( en == GL_UNSIGNED_INT64_NV ) ostr << "GL_UNSIGNED_INT64_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV";
	#endif
	#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
		else if ( en == GL_ELEMENT_ARRAY_UNIFIED_NV ) ostr << "GL_ELEMENT_ARRAY_UNIFIED_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_ADDRESS_NV
		else if ( en == GL_VERTEX_ARRAY_ADDRESS_NV ) ostr << "GL_VERTEX_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_NORMAL_ARRAY_ADDRESS_NV
		else if ( en == GL_NORMAL_ARRAY_ADDRESS_NV ) ostr << "GL_NORMAL_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_COLOR_ARRAY_ADDRESS_NV
		else if ( en == GL_COLOR_ARRAY_ADDRESS_NV ) ostr << "GL_COLOR_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_INDEX_ARRAY_ADDRESS_NV
		else if ( en == GL_INDEX_ARRAY_ADDRESS_NV ) ostr << "GL_INDEX_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_ADDRESS_NV
		else if ( en == GL_TEXTURE_COORD_ARRAY_ADDRESS_NV ) ostr << "GL_TEXTURE_COORD_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_ADDRESS_NV
		else if ( en == GL_EDGE_FLAG_ARRAY_ADDRESS_NV ) ostr << "GL_EDGE_FLAG_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV
		else if ( en == GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV ) ostr << "GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_ADDRESS_NV
		else if ( en == GL_FOG_COORD_ARRAY_ADDRESS_NV ) ostr << "GL_FOG_COORD_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_ELEMENT_ARRAY_ADDRESS_NV
		else if ( en == GL_ELEMENT_ARRAY_ADDRESS_NV ) ostr << "GL_ELEMENT_ARRAY_ADDRESS_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_VERTEX_ARRAY_LENGTH_NV
		else if ( en == GL_VERTEX_ARRAY_LENGTH_NV ) ostr << "GL_VERTEX_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_NORMAL_ARRAY_LENGTH_NV
		else if ( en == GL_NORMAL_ARRAY_LENGTH_NV ) ostr << "GL_NORMAL_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_COLOR_ARRAY_LENGTH_NV
		else if ( en == GL_COLOR_ARRAY_LENGTH_NV ) ostr << "GL_COLOR_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_INDEX_ARRAY_LENGTH_NV
		else if ( en == GL_INDEX_ARRAY_LENGTH_NV ) ostr << "GL_INDEX_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_TEXTURE_COORD_ARRAY_LENGTH_NV
		else if ( en == GL_TEXTURE_COORD_ARRAY_LENGTH_NV ) ostr << "GL_TEXTURE_COORD_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_EDGE_FLAG_ARRAY_LENGTH_NV
		else if ( en == GL_EDGE_FLAG_ARRAY_LENGTH_NV ) ostr << "GL_EDGE_FLAG_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_SECONDARY_COLOR_ARRAY_LENGTH_NV
		else if ( en == GL_SECONDARY_COLOR_ARRAY_LENGTH_NV ) ostr << "GL_SECONDARY_COLOR_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_FOG_COORD_ARRAY_LENGTH_NV
		else if ( en == GL_FOG_COORD_ARRAY_LENGTH_NV ) ostr << "GL_FOG_COORD_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_ELEMENT_ARRAY_LENGTH_NV
		else if ( en == GL_ELEMENT_ARRAY_LENGTH_NV ) ostr << "GL_ELEMENT_ARRAY_LENGTH_NV";
	#endif
	#ifdef GL_DRAW_INDIRECT_UNIFIED_NV
		else if ( en == GL_DRAW_INDIRECT_UNIFIED_NV ) ostr << "GL_DRAW_INDIRECT_UNIFIED_NV";
	#endif
	#ifdef GL_DRAW_INDIRECT_ADDRESS_NV
		else if ( en == GL_DRAW_INDIRECT_ADDRESS_NV ) ostr << "GL_DRAW_INDIRECT_ADDRESS_NV";
	#endif
	#ifdef GL_DRAW_INDIRECT_LENGTH_NV
		else if ( en == GL_DRAW_INDIRECT_LENGTH_NV ) ostr << "GL_DRAW_INDIRECT_LENGTH_NV";
	#endif
	#ifdef GL_VERTEX_PROGRAM_NV
		else if ( en == GL_VERTEX_PROGRAM_NV ) ostr << "GL_VERTEX_PROGRAM_NV";
	#endif
	#ifdef GL_VERTEX_STATE_PROGRAM_NV
		else if ( en == GL_VERTEX_STATE_PROGRAM_NV ) ostr << "GL_VERTEX_STATE_PROGRAM_NV";
	#endif
	#ifdef GL_ATTRIB_ARRAY_SIZE_NV
		else if ( en == GL_ATTRIB_ARRAY_SIZE_NV ) ostr << "GL_ATTRIB_ARRAY_SIZE_NV";
	#endif
	#ifdef GL_ATTRIB_ARRAY_STRIDE_NV
		else if ( en == GL_ATTRIB_ARRAY_STRIDE_NV ) ostr << "GL_ATTRIB_ARRAY_STRIDE_NV";
	#endif
	#ifdef GL_ATTRIB_ARRAY_TYPE_NV
		else if ( en == GL_ATTRIB_ARRAY_TYPE_NV ) ostr << "GL_ATTRIB_ARRAY_TYPE_NV";
	#endif
	#ifdef GL_CURRENT_ATTRIB_NV
		else if ( en == GL_CURRENT_ATTRIB_NV ) ostr << "GL_CURRENT_ATTRIB_NV";
	#endif
	#ifdef GL_PROGRAM_LENGTH_NV
		else if ( en == GL_PROGRAM_LENGTH_NV ) ostr << "GL_PROGRAM_LENGTH_NV";
	#endif
	#ifdef GL_PROGRAM_STRING_NV
		else if ( en == GL_PROGRAM_STRING_NV ) ostr << "GL_PROGRAM_STRING_NV";
	#endif
	#ifdef GL_MODELVIEW_PROJECTION_NV
		else if ( en == GL_MODELVIEW_PROJECTION_NV ) ostr << "GL_MODELVIEW_PROJECTION_NV";
	#endif
	#ifdef GL_IDENTITY_NV
		else if ( en == GL_IDENTITY_NV ) ostr << "GL_IDENTITY_NV";
	#endif
	#ifdef GL_INVERSE_NV
		else if ( en == GL_INVERSE_NV ) ostr << "GL_INVERSE_NV";
	#endif
	#ifdef GL_TRANSPOSE_NV
		else if ( en == GL_TRANSPOSE_NV ) ostr << "GL_TRANSPOSE_NV";
	#endif
	#ifdef GL_INVERSE_TRANSPOSE_NV
		else if ( en == GL_INVERSE_TRANSPOSE_NV ) ostr << "GL_INVERSE_TRANSPOSE_NV";
	#endif
	#ifdef GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV
		else if ( en == GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV ) ostr << "GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV";
	#endif
	#ifdef GL_MAX_TRACK_MATRICES_NV
		else if ( en == GL_MAX_TRACK_MATRICES_NV ) ostr << "GL_MAX_TRACK_MATRICES_NV";
	#endif
	#ifdef GL_MATRIX0_NV
		else if ( en == GL_MATRIX0_NV ) ostr << "GL_MATRIX0_NV";
	#endif
	#ifdef GL_MATRIX1_NV
		else if ( en == GL_MATRIX1_NV ) ostr << "GL_MATRIX1_NV";
	#endif
	#ifdef GL_MATRIX2_NV
		else if ( en == GL_MATRIX2_NV ) ostr << "GL_MATRIX2_NV";
	#endif
	#ifdef GL_MATRIX3_NV
		else if ( en == GL_MATRIX3_NV ) ostr << "GL_MATRIX3_NV";
	#endif
	#ifdef GL_MATRIX4_NV
		else if ( en == GL_MATRIX4_NV ) ostr << "GL_MATRIX4_NV";
	#endif
	#ifdef GL_MATRIX5_NV
		else if ( en == GL_MATRIX5_NV ) ostr << "GL_MATRIX5_NV";
	#endif
	#ifdef GL_MATRIX6_NV
		else if ( en == GL_MATRIX6_NV ) ostr << "GL_MATRIX6_NV";
	#endif
	#ifdef GL_MATRIX7_NV
		else if ( en == GL_MATRIX7_NV ) ostr << "GL_MATRIX7_NV";
	#endif
	#ifdef GL_CURRENT_MATRIX_STACK_DEPTH_NV
		else if ( en == GL_CURRENT_MATRIX_STACK_DEPTH_NV ) ostr << "GL_CURRENT_MATRIX_STACK_DEPTH_NV";
	#endif
	#ifdef GL_CURRENT_MATRIX_NV
		else if ( en == GL_CURRENT_MATRIX_NV ) ostr << "GL_CURRENT_MATRIX_NV";
	#endif
	#ifdef GL_VERTEX_PROGRAM_POINT_SIZE_NV
		else if ( en == GL_VERTEX_PROGRAM_POINT_SIZE_NV ) ostr << "GL_VERTEX_PROGRAM_POINT_SIZE_NV";
	#endif
	#ifdef GL_VERTEX_PROGRAM_TWO_SIDE_NV
		else if ( en == GL_VERTEX_PROGRAM_TWO_SIDE_NV ) ostr << "GL_VERTEX_PROGRAM_TWO_SIDE_NV";
	#endif
	#ifdef GL_PROGRAM_PARAMETER_NV
		else if ( en == GL_PROGRAM_PARAMETER_NV ) ostr << "GL_PROGRAM_PARAMETER_NV";
	#endif
	#ifdef GL_ATTRIB_ARRAY_POINTER_NV
		else if ( en == GL_ATTRIB_ARRAY_POINTER_NV ) ostr << "GL_ATTRIB_ARRAY_POINTER_NV";
	#endif
	#ifdef GL_PROGRAM_TARGET_NV
		else if ( en == GL_PROGRAM_TARGET_NV ) ostr << "GL_PROGRAM_TARGET_NV";
	#endif
	#ifdef GL_PROGRAM_RESIDENT_NV
		else if ( en == GL_PROGRAM_RESIDENT_NV ) ostr << "GL_PROGRAM_RESIDENT_NV";
	#endif
	#ifdef GL_TRACK_MATRIX_NV
		else if ( en == GL_TRACK_MATRIX_NV ) ostr << "GL_TRACK_MATRIX_NV";
	#endif
	#ifdef GL_TRACK_MATRIX_TRANSFORM_NV
		else if ( en == GL_TRACK_MATRIX_TRANSFORM_NV ) ostr << "GL_TRACK_MATRIX_TRANSFORM_NV";
	#endif
	#ifdef GL_VERTEX_PROGRAM_BINDING_NV
		else if ( en == GL_VERTEX_PROGRAM_BINDING_NV ) ostr << "GL_VERTEX_PROGRAM_BINDING_NV";
	#endif
	#ifdef GL_PROGRAM_ERROR_POSITION_NV
		else if ( en == GL_PROGRAM_ERROR_POSITION_NV ) ostr << "GL_PROGRAM_ERROR_POSITION_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY0_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY0_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY0_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY1_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY1_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY1_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY2_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY2_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY2_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY3_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY3_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY3_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY4_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY4_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY4_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY5_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY5_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY5_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY6_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY6_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY6_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY7_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY7_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY7_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY8_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY8_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY8_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY9_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY9_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY9_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY10_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY10_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY10_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY11_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY11_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY11_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY12_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY12_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY12_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY13_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY13_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY13_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY14_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY14_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY14_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY15_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY15_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY15_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB0_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB0_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB0_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB1_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB1_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB1_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB2_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB2_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB2_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB3_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB3_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB3_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB4_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB4_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB4_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB5_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB5_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB5_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB6_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB6_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB6_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB7_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB7_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB7_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB8_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB8_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB8_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB9_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB9_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB9_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB10_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB10_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB10_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB11_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB11_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB11_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB12_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB12_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB12_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB13_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB13_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB13_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB14_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB14_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB14_4_NV";
	#endif
	#ifdef GL_MAP1_VERTEX_ATTRIB15_4_NV
		else if ( en == GL_MAP1_VERTEX_ATTRIB15_4_NV ) ostr << "GL_MAP1_VERTEX_ATTRIB15_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB0_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB0_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB0_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB1_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB1_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB1_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB2_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB2_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB2_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB3_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB3_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB3_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB4_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB4_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB4_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB5_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB5_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB5_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB6_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB6_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB6_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB7_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB7_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB7_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB8_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB8_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB8_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB9_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB9_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB9_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB10_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB10_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB10_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB11_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB11_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB11_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB12_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB12_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB12_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB13_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB13_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB13_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB14_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB14_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB14_4_NV";
	#endif
	#ifdef GL_MAP2_VERTEX_ATTRIB15_4_NV
		else if ( en == GL_MAP2_VERTEX_ATTRIB15_4_NV ) ostr << "GL_MAP2_VERTEX_ATTRIB15_4_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV
		else if ( en == GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV ) ostr << "GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV";
	#endif
	#ifdef GL_MAX_PROGRAM_CALL_DEPTH_NV
		else if ( en == GL_MAX_PROGRAM_CALL_DEPTH_NV ) ostr << "GL_MAX_PROGRAM_CALL_DEPTH_NV";
	#endif
	#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV
		else if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV ) ostr << "GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV";
	#endif
	#ifdef GL_VIDEO_BUFFER_NV
		else if ( en == GL_VIDEO_BUFFER_NV ) ostr << "GL_VIDEO_BUFFER_NV";
	#endif
	#ifdef GL_VIDEO_BUFFER_BINDING_NV
		else if ( en == GL_VIDEO_BUFFER_BINDING_NV ) ostr << "GL_VIDEO_BUFFER_BINDING_NV";
	#endif
	#ifdef GL_FIELD_UPPER_NV
		else if ( en == GL_FIELD_UPPER_NV ) ostr << "GL_FIELD_UPPER_NV";
	#endif
	#ifdef GL_FIELD_LOWER_NV
		else if ( en == GL_FIELD_LOWER_NV ) ostr << "GL_FIELD_LOWER_NV";
	#endif
	#ifdef GL_NUM_VIDEO_CAPTURE_STREAMS_NV
		else if ( en == GL_NUM_VIDEO_CAPTURE_STREAMS_NV ) ostr << "GL_NUM_VIDEO_CAPTURE_STREAMS_NV";
	#endif
	#ifdef GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV
		else if ( en == GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV ) ostr << "GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV
		else if ( en == GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV ) ostr << "GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV";
	#endif
	#ifdef GL_LAST_VIDEO_CAPTURE_STATUS_NV
		else if ( en == GL_LAST_VIDEO_CAPTURE_STATUS_NV ) ostr << "GL_LAST_VIDEO_CAPTURE_STATUS_NV";
	#endif
	#ifdef GL_VIDEO_BUFFER_PITCH_NV
		else if ( en == GL_VIDEO_BUFFER_PITCH_NV ) ostr << "GL_VIDEO_BUFFER_PITCH_NV";
	#endif
	#ifdef GL_VIDEO_COLOR_CONVERSION_MATRIX_NV
		else if ( en == GL_VIDEO_COLOR_CONVERSION_MATRIX_NV ) ostr << "GL_VIDEO_COLOR_CONVERSION_MATRIX_NV";
	#endif
	#ifdef GL_VIDEO_COLOR_CONVERSION_MAX_NV
		else if ( en == GL_VIDEO_COLOR_CONVERSION_MAX_NV ) ostr << "GL_VIDEO_COLOR_CONVERSION_MAX_NV";
	#endif
	#ifdef GL_VIDEO_COLOR_CONVERSION_MIN_NV
		else if ( en == GL_VIDEO_COLOR_CONVERSION_MIN_NV ) ostr << "GL_VIDEO_COLOR_CONVERSION_MIN_NV";
	#endif
	#ifdef GL_VIDEO_COLOR_CONVERSION_OFFSET_NV
		else if ( en == GL_VIDEO_COLOR_CONVERSION_OFFSET_NV ) ostr << "GL_VIDEO_COLOR_CONVERSION_OFFSET_NV";
	#endif
	#ifdef GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV
		else if ( en == GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV ) ostr << "GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV";
	#endif
	#ifdef GL_PARTIAL_SUCCESS_NV
		else if ( en == GL_PARTIAL_SUCCESS_NV ) ostr << "GL_PARTIAL_SUCCESS_NV";
	#endif
	#ifdef GL_SUCCESS_NV
		else if ( en == GL_SUCCESS_NV ) ostr << "GL_SUCCESS_NV";
	#endif
	#ifdef GL_FAILURE_NV
		else if ( en == GL_FAILURE_NV ) ostr << "GL_FAILURE_NV";
	#endif
	#ifdef GL_YCBYCR8_422_NV
		else if ( en == GL_YCBYCR8_422_NV ) ostr << "GL_YCBYCR8_422_NV";
	#endif
	#ifdef GL_YCBAYCR8A_4224_NV
		else if ( en == GL_YCBAYCR8A_4224_NV ) ostr << "GL_YCBAYCR8A_4224_NV";
	#endif
	#ifdef GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV
		else if ( en == GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV ) ostr << "GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV";
	#endif
	#ifdef GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV
		else if ( en == GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV ) ostr << "GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV";
	#endif
	#ifdef GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV
		else if ( en == GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV ) ostr << "GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV";
	#endif
	#ifdef GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV
		else if ( en == GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV ) ostr << "GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV";
	#endif
	#ifdef GL_Z4Y12Z4CB12Z4CR12_444_NV
		else if ( en == GL_Z4Y12Z4CB12Z4CR12_444_NV ) ostr << "GL_Z4Y12Z4CB12Z4CR12_444_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_FRAME_WIDTH_NV
		else if ( en == GL_VIDEO_CAPTURE_FRAME_WIDTH_NV ) ostr << "GL_VIDEO_CAPTURE_FRAME_WIDTH_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV
		else if ( en == GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV ) ostr << "GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV
		else if ( en == GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV ) ostr << "GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV
		else if ( en == GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV ) ostr << "GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV";
	#endif
	#ifdef GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV
		else if ( en == GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV ) ostr << "GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV";
	#endif
	#ifdef GL_PALETTE4_RGB8_OES
		else if ( en == GL_PALETTE4_RGB8_OES ) ostr << "GL_PALETTE4_RGB8_OES";
	#endif
	#ifdef GL_PALETTE4_RGBA8_OES
		else if ( en == GL_PALETTE4_RGBA8_OES ) ostr << "GL_PALETTE4_RGBA8_OES";
	#endif
	#ifdef GL_PALETTE4_R5_G6_B5_OES
		else if ( en == GL_PALETTE4_R5_G6_B5_OES ) ostr << "GL_PALETTE4_R5_G6_B5_OES";
	#endif
	#ifdef GL_PALETTE4_RGBA4_OES
		else if ( en == GL_PALETTE4_RGBA4_OES ) ostr << "GL_PALETTE4_RGBA4_OES";
	#endif
	#ifdef GL_PALETTE4_RGB5_A1_OES
		else if ( en == GL_PALETTE4_RGB5_A1_OES ) ostr << "GL_PALETTE4_RGB5_A1_OES";
	#endif
	#ifdef GL_PALETTE8_RGB8_OES
		else if ( en == GL_PALETTE8_RGB8_OES ) ostr << "GL_PALETTE8_RGB8_OES";
	#endif
	#ifdef GL_PALETTE8_RGBA8_OES
		else if ( en == GL_PALETTE8_RGBA8_OES ) ostr << "GL_PALETTE8_RGBA8_OES";
	#endif
	#ifdef GL_PALETTE8_R5_G6_B5_OES
		else if ( en == GL_PALETTE8_R5_G6_B5_OES ) ostr << "GL_PALETTE8_R5_G6_B5_OES";
	#endif
	#ifdef GL_PALETTE8_RGBA4_OES
		else if ( en == GL_PALETTE8_RGBA4_OES ) ostr << "GL_PALETTE8_RGBA4_OES";
	#endif
	#ifdef GL_PALETTE8_RGB5_A1_OES
		else if ( en == GL_PALETTE8_RGB5_A1_OES ) ostr << "GL_PALETTE8_RGB5_A1_OES";
	#endif
	#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE_OES
		else if ( en == GL_IMPLEMENTATION_COLOR_READ_TYPE_OES ) ostr << "GL_IMPLEMENTATION_COLOR_READ_TYPE_OES";
	#endif
	#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES
		else if ( en == GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES ) ostr << "GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES";
	#endif
	#ifdef GL_INTERLACE_OML
		else if ( en == GL_INTERLACE_OML ) ostr << "GL_INTERLACE_OML";
	#endif
	#ifdef GL_INTERLACE_READ_OML
		else if ( en == GL_INTERLACE_READ_OML ) ostr << "GL_INTERLACE_READ_OML";
	#endif
	#ifdef GL_PACK_RESAMPLE_OML
		else if ( en == GL_PACK_RESAMPLE_OML ) ostr << "GL_PACK_RESAMPLE_OML";
	#endif
	#ifdef GL_UNPACK_RESAMPLE_OML
		else if ( en == GL_UNPACK_RESAMPLE_OML ) ostr << "GL_UNPACK_RESAMPLE_OML";
	#endif
	#ifdef GL_RESAMPLE_REPLICATE_OML
		else if ( en == GL_RESAMPLE_REPLICATE_OML ) ostr << "GL_RESAMPLE_REPLICATE_OML";
	#endif
	#ifdef GL_RESAMPLE_ZERO_FILL_OML
		else if ( en == GL_RESAMPLE_ZERO_FILL_OML ) ostr << "GL_RESAMPLE_ZERO_FILL_OML";
	#endif
	#ifdef GL_RESAMPLE_AVERAGE_OML
		else if ( en == GL_RESAMPLE_AVERAGE_OML ) ostr << "GL_RESAMPLE_AVERAGE_OML";
	#endif
	#ifdef GL_RESAMPLE_DECIMATE_OML
		else if ( en == GL_RESAMPLE_DECIMATE_OML ) ostr << "GL_RESAMPLE_DECIMATE_OML";
	#endif
	#ifdef GL_FORMAT_SUBSAMPLE_24_24_OML
		else if ( en == GL_FORMAT_SUBSAMPLE_24_24_OML ) ostr << "GL_FORMAT_SUBSAMPLE_24_24_OML";
	#endif
	#ifdef GL_FORMAT_SUBSAMPLE_244_244_OML
		else if ( en == GL_FORMAT_SUBSAMPLE_244_244_OML ) ostr << "GL_FORMAT_SUBSAMPLE_244_244_OML";
	#endif
	#ifdef GL_PREFER_DOUBLEBUFFER_HINT_PGI
		else if ( en == GL_PREFER_DOUBLEBUFFER_HINT_PGI ) ostr << "GL_PREFER_DOUBLEBUFFER_HINT_PGI";
	#endif
	#ifdef GL_CONSERVE_MEMORY_HINT_PGI
		else if ( en == GL_CONSERVE_MEMORY_HINT_PGI ) ostr << "GL_CONSERVE_MEMORY_HINT_PGI";
	#endif
	#ifdef GL_RECLAIM_MEMORY_HINT_PGI
		else if ( en == GL_RECLAIM_MEMORY_HINT_PGI ) ostr << "GL_RECLAIM_MEMORY_HINT_PGI";
	#endif
	#ifdef GL_NATIVE_GRAPHICS_HANDLE_PGI
		else if ( en == GL_NATIVE_GRAPHICS_HANDLE_PGI ) ostr << "GL_NATIVE_GRAPHICS_HANDLE_PGI";
	#endif
	#ifdef GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI
		else if ( en == GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI ) ostr << "GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI";
	#endif
	#ifdef GL_NATIVE_GRAPHICS_END_HINT_PGI
		else if ( en == GL_NATIVE_GRAPHICS_END_HINT_PGI ) ostr << "GL_NATIVE_GRAPHICS_END_HINT_PGI";
	#endif
	#ifdef GL_ALWAYS_FAST_HINT_PGI
		else if ( en == GL_ALWAYS_FAST_HINT_PGI ) ostr << "GL_ALWAYS_FAST_HINT_PGI";
	#endif
	#ifdef GL_ALWAYS_SOFT_HINT_PGI
		else if ( en == GL_ALWAYS_SOFT_HINT_PGI ) ostr << "GL_ALWAYS_SOFT_HINT_PGI";
	#endif
	#ifdef GL_ALLOW_DRAW_OBJ_HINT_PGI
		else if ( en == GL_ALLOW_DRAW_OBJ_HINT_PGI ) ostr << "GL_ALLOW_DRAW_OBJ_HINT_PGI";
	#endif
	#ifdef GL_ALLOW_DRAW_WIN_HINT_PGI
		else if ( en == GL_ALLOW_DRAW_WIN_HINT_PGI ) ostr << "GL_ALLOW_DRAW_WIN_HINT_PGI";
	#endif
	#ifdef GL_ALLOW_DRAW_FRG_HINT_PGI
		else if ( en == GL_ALLOW_DRAW_FRG_HINT_PGI ) ostr << "GL_ALLOW_DRAW_FRG_HINT_PGI";
	#endif
	#ifdef GL_ALLOW_DRAW_MEM_HINT_PGI
		else if ( en == GL_ALLOW_DRAW_MEM_HINT_PGI ) ostr << "GL_ALLOW_DRAW_MEM_HINT_PGI";
	#endif
	#ifdef GL_STRICT_DEPTHFUNC_HINT_PGI
		else if ( en == GL_STRICT_DEPTHFUNC_HINT_PGI ) ostr << "GL_STRICT_DEPTHFUNC_HINT_PGI";
	#endif
	#ifdef GL_STRICT_LIGHTING_HINT_PGI
		else if ( en == GL_STRICT_LIGHTING_HINT_PGI ) ostr << "GL_STRICT_LIGHTING_HINT_PGI";
	#endif
	#ifdef GL_STRICT_SCISSOR_HINT_PGI
		else if ( en == GL_STRICT_SCISSOR_HINT_PGI ) ostr << "GL_STRICT_SCISSOR_HINT_PGI";
	#endif
	#ifdef GL_FULL_STIPPLE_HINT_PGI
		else if ( en == GL_FULL_STIPPLE_HINT_PGI ) ostr << "GL_FULL_STIPPLE_HINT_PGI";
	#endif
	#ifdef GL_CLIP_NEAR_HINT_PGI
		else if ( en == GL_CLIP_NEAR_HINT_PGI ) ostr << "GL_CLIP_NEAR_HINT_PGI";
	#endif
	#ifdef GL_CLIP_FAR_HINT_PGI
		else if ( en == GL_CLIP_FAR_HINT_PGI ) ostr << "GL_CLIP_FAR_HINT_PGI";
	#endif
	#ifdef GL_WIDE_LINE_HINT_PGI
		else if ( en == GL_WIDE_LINE_HINT_PGI ) ostr << "GL_WIDE_LINE_HINT_PGI";
	#endif
	#ifdef GL_BACK_NORMALS_HINT_PGI
		else if ( en == GL_BACK_NORMALS_HINT_PGI ) ostr << "GL_BACK_NORMALS_HINT_PGI";
	#endif
	#ifdef GL_VERTEX23_BIT_PGI
		else if ( en == GL_VERTEX23_BIT_PGI ) ostr << "GL_VERTEX23_BIT_PGI";
	#endif
	#ifdef GL_VERTEX4_BIT_PGI
		else if ( en == GL_VERTEX4_BIT_PGI ) ostr << "GL_VERTEX4_BIT_PGI";
	#endif
	#ifdef GL_COLOR3_BIT_PGI
		else if ( en == GL_COLOR3_BIT_PGI ) ostr << "GL_COLOR3_BIT_PGI";
	#endif
	#ifdef GL_COLOR4_BIT_PGI
		else if ( en == GL_COLOR4_BIT_PGI ) ostr << "GL_COLOR4_BIT_PGI";
	#endif
	#ifdef GL_EDGEFLAG_BIT_PGI
		else if ( en == GL_EDGEFLAG_BIT_PGI ) ostr << "GL_EDGEFLAG_BIT_PGI";
	#endif
	#ifdef GL_INDEX_BIT_PGI
		else if ( en == GL_INDEX_BIT_PGI ) ostr << "GL_INDEX_BIT_PGI";
	#endif
	#ifdef GL_MAT_AMBIENT_BIT_PGI
		else if ( en == GL_MAT_AMBIENT_BIT_PGI ) ostr << "GL_MAT_AMBIENT_BIT_PGI";
	#endif
	#ifdef GL_VERTEX_DATA_HINT_PGI
		else if ( en == GL_VERTEX_DATA_HINT_PGI ) ostr << "GL_VERTEX_DATA_HINT_PGI";
	#endif
	#ifdef GL_VERTEX_CONSISTENT_HINT_PGI
		else if ( en == GL_VERTEX_CONSISTENT_HINT_PGI ) ostr << "GL_VERTEX_CONSISTENT_HINT_PGI";
	#endif
	#ifdef GL_MATERIAL_SIDE_HINT_PGI
		else if ( en == GL_MATERIAL_SIDE_HINT_PGI ) ostr << "GL_MATERIAL_SIDE_HINT_PGI";
	#endif
	#ifdef GL_MAX_VERTEX_HINT_PGI
		else if ( en == GL_MAX_VERTEX_HINT_PGI ) ostr << "GL_MAX_VERTEX_HINT_PGI";
	#endif
	#ifdef GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI
		else if ( en == GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI ) ostr << "GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI";
	#endif
	#ifdef GL_MAT_DIFFUSE_BIT_PGI
		else if ( en == GL_MAT_DIFFUSE_BIT_PGI ) ostr << "GL_MAT_DIFFUSE_BIT_PGI";
	#endif
	#ifdef GL_MAT_EMISSION_BIT_PGI
		else if ( en == GL_MAT_EMISSION_BIT_PGI ) ostr << "GL_MAT_EMISSION_BIT_PGI";
	#endif
	#ifdef GL_MAT_COLOR_INDEXES_BIT_PGI
		else if ( en == GL_MAT_COLOR_INDEXES_BIT_PGI ) ostr << "GL_MAT_COLOR_INDEXES_BIT_PGI";
	#endif
	#ifdef GL_MAT_SHININESS_BIT_PGI
		else if ( en == GL_MAT_SHININESS_BIT_PGI ) ostr << "GL_MAT_SHININESS_BIT_PGI";
	#endif
	#ifdef GL_MAT_SPECULAR_BIT_PGI
		else if ( en == GL_MAT_SPECULAR_BIT_PGI ) ostr << "GL_MAT_SPECULAR_BIT_PGI";
	#endif
	#ifdef GL_NORMAL_BIT_PGI
		else if ( en == GL_NORMAL_BIT_PGI ) ostr << "GL_NORMAL_BIT_PGI";
	#endif
	#ifdef GL_TEXCOORD1_BIT_PGI
		else if ( en == GL_TEXCOORD1_BIT_PGI ) ostr << "GL_TEXCOORD1_BIT_PGI";
	#endif
	#ifdef GL_TEXCOORD2_BIT_PGI
		else if ( en == GL_TEXCOORD2_BIT_PGI ) ostr << "GL_TEXCOORD2_BIT_PGI";
	#endif
	#ifdef GL_TEXCOORD3_BIT_PGI
		else if ( en == GL_TEXCOORD3_BIT_PGI ) ostr << "GL_TEXCOORD3_BIT_PGI";
	#endif
	#ifdef GL_TEXCOORD4_BIT_PGI
		else if ( en == GL_TEXCOORD4_BIT_PGI ) ostr << "GL_TEXCOORD4_BIT_PGI";
	#endif
	#ifdef GL_ERROR_REGAL
		else if ( en == GL_ERROR_REGAL ) ostr << "GL_ERROR_REGAL";
	#endif
	#ifdef GL_DEBUG_REGAL
		else if ( en == GL_DEBUG_REGAL ) ostr << "GL_DEBUG_REGAL";
	#endif
	#ifdef GL_LOG_REGAL
		else if ( en == GL_LOG_REGAL ) ostr << "GL_LOG_REGAL";
	#endif
	#ifdef GL_EMULATION_REGAL
		else if ( en == GL_EMULATION_REGAL ) ostr << "GL_EMULATION_REGAL";
	#endif
	#ifdef GL_DRIVER_REGAL
		else if ( en == GL_DRIVER_REGAL ) ostr << "GL_DRIVER_REGAL";
	#endif
	#ifdef GL_MISSING_REGAL
		else if ( en == GL_MISSING_REGAL ) ostr << "GL_MISSING_REGAL";
	#endif
	#ifdef GL_TRACE_REGAL
		else if ( en == GL_TRACE_REGAL ) ostr << "GL_TRACE_REGAL";
	#endif
	#ifdef GL_CACHE_REGAL
		else if ( en == GL_CACHE_REGAL ) ostr << "GL_CACHE_REGAL";
	#endif
	#ifdef GL_CODE_REGAL
		else if ( en == GL_CODE_REGAL ) ostr << "GL_CODE_REGAL";
	#endif
	#ifdef GL_STATISTICS_REGAL
		else if ( en == GL_STATISTICS_REGAL ) ostr << "GL_STATISTICS_REGAL";
	#endif
	#ifdef GL_LOG_ERROR_REGAL
		else if ( en == GL_LOG_ERROR_REGAL ) ostr << "GL_LOG_ERROR_REGAL";
	#endif
	#ifdef GL_LOG_WARNING_REGAL
		else if ( en == GL_LOG_WARNING_REGAL ) ostr << "GL_LOG_WARNING_REGAL";
	#endif
	#ifdef GL_LOG_INFO_REGAL
		else if ( en == GL_LOG_INFO_REGAL ) ostr << "GL_LOG_INFO_REGAL";
	#endif
	#ifdef GL_LOG_APP_REGAL
		else if ( en == GL_LOG_APP_REGAL ) ostr << "GL_LOG_APP_REGAL";
	#endif
	#ifdef GL_LOG_DRIVER_REGAL
		else if ( en == GL_LOG_DRIVER_REGAL ) ostr << "GL_LOG_DRIVER_REGAL";
	#endif
	#ifdef GL_LOG_INTERNAL_REGAL
		else if ( en == GL_LOG_INTERNAL_REGAL ) ostr << "GL_LOG_INTERNAL_REGAL";
	#endif
	#ifdef GL_LOG_DEBUG_REGAL
		else if ( en == GL_LOG_DEBUG_REGAL ) ostr << "GL_LOG_DEBUG_REGAL";
	#endif
	#ifdef GL_LOG_STATUS_REGAL
		else if ( en == GL_LOG_STATUS_REGAL ) ostr << "GL_LOG_STATUS_REGAL";
	#endif
	#ifdef GL_LOG_HTTP_REGAL
		else if ( en == GL_LOG_HTTP_REGAL ) ostr << "GL_LOG_HTTP_REGAL";
	#endif
	#ifdef GL_SCREEN_COORDINATES_REND
		else if ( en == GL_SCREEN_COORDINATES_REND ) ostr << "GL_SCREEN_COORDINATES_REND";
	#endif
	#ifdef GL_INVERTED_SCREEN_W_REND
		else if ( en == GL_INVERTED_SCREEN_W_REND ) ostr << "GL_INVERTED_SCREEN_W_REND";
	#endif
	#ifdef GL_RGB_S3TC
		else if ( en == GL_RGB_S3TC ) ostr << "GL_RGB_S3TC";
	#endif
	#ifdef GL_RGB4_S3TC
		else if ( en == GL_RGB4_S3TC ) ostr << "GL_RGB4_S3TC";
	#endif
	#ifdef GL_RGBA_S3TC
		else if ( en == GL_RGBA_S3TC ) ostr << "GL_RGBA_S3TC";
	#endif
	#ifdef GL_RGBA4_S3TC
		else if ( en == GL_RGBA4_S3TC ) ostr << "GL_RGBA4_S3TC";
	#endif
	#ifdef GL_RGBA_DXT5_S3TC
		else if ( en == GL_RGBA_DXT5_S3TC ) ostr << "GL_RGBA_DXT5_S3TC";
	#endif
	#ifdef GL_RGBA4_DXT5_S3TC
		else if ( en == GL_RGBA4_DXT5_S3TC ) ostr << "GL_RGBA4_DXT5_S3TC";
	#endif
	#ifdef GL_EXTENDED_RANGE_SGIS
		else if ( en == GL_EXTENDED_RANGE_SGIS ) ostr << "GL_EXTENDED_RANGE_SGIS";
	#endif
	#ifdef GL_MIN_RED_SGIS
		else if ( en == GL_MIN_RED_SGIS ) ostr << "GL_MIN_RED_SGIS";
	#endif
	#ifdef GL_MAX_RED_SGIS
		else if ( en == GL_MAX_RED_SGIS ) ostr << "GL_MAX_RED_SGIS";
	#endif
	#ifdef GL_MIN_GREEN_SGIS
		else if ( en == GL_MIN_GREEN_SGIS ) ostr << "GL_MIN_GREEN_SGIS";
	#endif
	#ifdef GL_MAX_GREEN_SGIS
		else if ( en == GL_MAX_GREEN_SGIS ) ostr << "GL_MAX_GREEN_SGIS";
	#endif
	#ifdef GL_MIN_BLUE_SGIS
		else if ( en == GL_MIN_BLUE_SGIS ) ostr << "GL_MIN_BLUE_SGIS";
	#endif
	#ifdef GL_MAX_BLUE_SGIS
		else if ( en == GL_MAX_BLUE_SGIS ) ostr << "GL_MAX_BLUE_SGIS";
	#endif
	#ifdef GL_MIN_ALPHA_SGIS
		else if ( en == GL_MIN_ALPHA_SGIS ) ostr << "GL_MIN_ALPHA_SGIS";
	#endif
	#ifdef GL_MAX_ALPHA_SGIS
		else if ( en == GL_MAX_ALPHA_SGIS ) ostr << "GL_MAX_ALPHA_SGIS";
	#endif
	#ifdef GL_GENERATE_MIPMAP_SGIS
		else if ( en == GL_GENERATE_MIPMAP_SGIS ) ostr << "GL_GENERATE_MIPMAP_SGIS";
	#endif
	#ifdef GL_GENERATE_MIPMAP_HINT_SGIS
		else if ( en == GL_GENERATE_MIPMAP_HINT_SGIS ) ostr << "GL_GENERATE_MIPMAP_HINT_SGIS";
	#endif
	#ifdef GL_MULTISAMPLE_SGIS
		else if ( en == GL_MULTISAMPLE_SGIS ) ostr << "GL_MULTISAMPLE_SGIS";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_MASK_SGIS
		else if ( en == GL_SAMPLE_ALPHA_TO_MASK_SGIS ) ostr << "GL_SAMPLE_ALPHA_TO_MASK_SGIS";
	#endif
	#ifdef GL_SAMPLE_ALPHA_TO_ONE_SGIS
		else if ( en == GL_SAMPLE_ALPHA_TO_ONE_SGIS ) ostr << "GL_SAMPLE_ALPHA_TO_ONE_SGIS";
	#endif
	#ifdef GL_SAMPLE_MASK_SGIS
		else if ( en == GL_SAMPLE_MASK_SGIS ) ostr << "GL_SAMPLE_MASK_SGIS";
	#endif
	#ifdef GL_1PASS_SGIS
		else if ( en == GL_1PASS_SGIS ) ostr << "GL_1PASS_SGIS";
	#endif
	#ifdef GL_2PASS_0_SGIS
		else if ( en == GL_2PASS_0_SGIS ) ostr << "GL_2PASS_0_SGIS";
	#endif
	#ifdef GL_2PASS_1_SGIS
		else if ( en == GL_2PASS_1_SGIS ) ostr << "GL_2PASS_1_SGIS";
	#endif
	#ifdef GL_4PASS_0_SGIS
		else if ( en == GL_4PASS_0_SGIS ) ostr << "GL_4PASS_0_SGIS";
	#endif
	#ifdef GL_4PASS_1_SGIS
		else if ( en == GL_4PASS_1_SGIS ) ostr << "GL_4PASS_1_SGIS";
	#endif
	#ifdef GL_4PASS_2_SGIS
		else if ( en == GL_4PASS_2_SGIS ) ostr << "GL_4PASS_2_SGIS";
	#endif
	#ifdef GL_4PASS_3_SGIS
		else if ( en == GL_4PASS_3_SGIS ) ostr << "GL_4PASS_3_SGIS";
	#endif
	#ifdef GL_SAMPLE_BUFFERS_SGIS
		else if ( en == GL_SAMPLE_BUFFERS_SGIS ) ostr << "GL_SAMPLE_BUFFERS_SGIS";
	#endif
	#ifdef GL_SAMPLES_SGIS
		else if ( en == GL_SAMPLES_SGIS ) ostr << "GL_SAMPLES_SGIS";
	#endif
	#ifdef GL_SAMPLE_MASK_VALUE_SGIS
		else if ( en == GL_SAMPLE_MASK_VALUE_SGIS ) ostr << "GL_SAMPLE_MASK_VALUE_SGIS";
	#endif
	#ifdef GL_SAMPLE_MASK_INVERT_SGIS
		else if ( en == GL_SAMPLE_MASK_INVERT_SGIS ) ostr << "GL_SAMPLE_MASK_INVERT_SGIS";
	#endif
	#ifdef GL_SAMPLE_PATTERN_SGIS
		else if ( en == GL_SAMPLE_PATTERN_SGIS ) ostr << "GL_SAMPLE_PATTERN_SGIS";
	#endif
	#ifdef GL_EYE_DISTANCE_TO_POINT_SGIS
		else if ( en == GL_EYE_DISTANCE_TO_POINT_SGIS ) ostr << "GL_EYE_DISTANCE_TO_POINT_SGIS";
	#endif
	#ifdef GL_OBJECT_DISTANCE_TO_POINT_SGIS
		else if ( en == GL_OBJECT_DISTANCE_TO_POINT_SGIS ) ostr << "GL_OBJECT_DISTANCE_TO_POINT_SGIS";
	#endif
	#ifdef GL_EYE_DISTANCE_TO_LINE_SGIS
		else if ( en == GL_EYE_DISTANCE_TO_LINE_SGIS ) ostr << "GL_EYE_DISTANCE_TO_LINE_SGIS";
	#endif
	#ifdef GL_OBJECT_DISTANCE_TO_LINE_SGIS
		else if ( en == GL_OBJECT_DISTANCE_TO_LINE_SGIS ) ostr << "GL_OBJECT_DISTANCE_TO_LINE_SGIS";
	#endif
	#ifdef GL_EYE_POINT_SGIS
		else if ( en == GL_EYE_POINT_SGIS ) ostr << "GL_EYE_POINT_SGIS";
	#endif
	#ifdef GL_OBJECT_POINT_SGIS
		else if ( en == GL_OBJECT_POINT_SGIS ) ostr << "GL_OBJECT_POINT_SGIS";
	#endif
	#ifdef GL_EYE_LINE_SGIS
		else if ( en == GL_EYE_LINE_SGIS ) ostr << "GL_EYE_LINE_SGIS";
	#endif
	#ifdef GL_OBJECT_LINE_SGIS
		else if ( en == GL_OBJECT_LINE_SGIS ) ostr << "GL_OBJECT_LINE_SGIS";
	#endif
	#ifdef GL_CLAMP_TO_BORDER_SGIS
		else if ( en == GL_CLAMP_TO_BORDER_SGIS ) ostr << "GL_CLAMP_TO_BORDER_SGIS";
	#endif
	#ifdef GL_CLAMP_TO_EDGE_SGIS
		else if ( en == GL_CLAMP_TO_EDGE_SGIS ) ostr << "GL_CLAMP_TO_EDGE_SGIS";
	#endif
	#ifdef GL_TEXTURE_MIN_LOD_SGIS
		else if ( en == GL_TEXTURE_MIN_LOD_SGIS ) ostr << "GL_TEXTURE_MIN_LOD_SGIS";
	#endif
	#ifdef GL_TEXTURE_MAX_LOD_SGIS
		else if ( en == GL_TEXTURE_MAX_LOD_SGIS ) ostr << "GL_TEXTURE_MAX_LOD_SGIS";
	#endif
	#ifdef GL_TEXTURE_BASE_LEVEL_SGIS
		else if ( en == GL_TEXTURE_BASE_LEVEL_SGIS ) ostr << "GL_TEXTURE_BASE_LEVEL_SGIS";
	#endif
	#ifdef GL_TEXTURE_MAX_LEVEL_SGIS
		else if ( en == GL_TEXTURE_MAX_LEVEL_SGIS ) ostr << "GL_TEXTURE_MAX_LEVEL_SGIS";
	#endif
	#ifdef GL_ASYNC_MARKER_SGIX
		else if ( en == GL_ASYNC_MARKER_SGIX ) ostr << "GL_ASYNC_MARKER_SGIX";
	#endif
	#ifdef GL_ASYNC_HISTOGRAM_SGIX
		else if ( en == GL_ASYNC_HISTOGRAM_SGIX ) ostr << "GL_ASYNC_HISTOGRAM_SGIX";
	#endif
	#ifdef GL_MAX_ASYNC_HISTOGRAM_SGIX
		else if ( en == GL_MAX_ASYNC_HISTOGRAM_SGIX ) ostr << "GL_MAX_ASYNC_HISTOGRAM_SGIX";
	#endif
	#ifdef GL_ASYNC_TEX_IMAGE_SGIX
		else if ( en == GL_ASYNC_TEX_IMAGE_SGIX ) ostr << "GL_ASYNC_TEX_IMAGE_SGIX";
	#endif
	#ifdef GL_ASYNC_DRAW_PIXELS_SGIX
		else if ( en == GL_ASYNC_DRAW_PIXELS_SGIX ) ostr << "GL_ASYNC_DRAW_PIXELS_SGIX";
	#endif
	#ifdef GL_ASYNC_READ_PIXELS_SGIX
		else if ( en == GL_ASYNC_READ_PIXELS_SGIX ) ostr << "GL_ASYNC_READ_PIXELS_SGIX";
	#endif
	#ifdef GL_MAX_ASYNC_TEX_IMAGE_SGIX
		else if ( en == GL_MAX_ASYNC_TEX_IMAGE_SGIX ) ostr << "GL_MAX_ASYNC_TEX_IMAGE_SGIX";
	#endif
	#ifdef GL_MAX_ASYNC_DRAW_PIXELS_SGIX
		else if ( en == GL_MAX_ASYNC_DRAW_PIXELS_SGIX ) ostr << "GL_MAX_ASYNC_DRAW_PIXELS_SGIX";
	#endif
	#ifdef GL_MAX_ASYNC_READ_PIXELS_SGIX
		else if ( en == GL_MAX_ASYNC_READ_PIXELS_SGIX ) ostr << "GL_MAX_ASYNC_READ_PIXELS_SGIX";
	#endif
	#ifdef GL_ALPHA_MIN_SGIX
		else if ( en == GL_ALPHA_MIN_SGIX ) ostr << "GL_ALPHA_MIN_SGIX";
	#endif
	#ifdef GL_ALPHA_MAX_SGIX
		else if ( en == GL_ALPHA_MAX_SGIX ) ostr << "GL_ALPHA_MAX_SGIX";
	#endif
	#ifdef GL_CONVOLUTION_HINT_SGIX
		else if ( en == GL_CONVOLUTION_HINT_SGIX ) ostr << "GL_CONVOLUTION_HINT_SGIX";
	#endif
	#ifdef GL_DEPTH_COMPONENT16_SGIX
		else if ( en == GL_DEPTH_COMPONENT16_SGIX ) ostr << "GL_DEPTH_COMPONENT16_SGIX";
	#endif
	#ifdef GL_DEPTH_COMPONENT24_SGIX
		else if ( en == GL_DEPTH_COMPONENT24_SGIX ) ostr << "GL_DEPTH_COMPONENT24_SGIX";
	#endif
	#ifdef GL_DEPTH_COMPONENT32_SGIX
		else if ( en == GL_DEPTH_COMPONENT32_SGIX ) ostr << "GL_DEPTH_COMPONENT32_SGIX";
	#endif
	#ifdef GL_FOG_OFFSET_SGIX
		else if ( en == GL_FOG_OFFSET_SGIX ) ostr << "GL_FOG_OFFSET_SGIX";
	#endif
	#ifdef GL_FOG_OFFSET_VALUE_SGIX
		else if ( en == GL_FOG_OFFSET_VALUE_SGIX ) ostr << "GL_FOG_OFFSET_VALUE_SGIX";
	#endif
	#ifdef GL_INTERLACE_SGIX
		else if ( en == GL_INTERLACE_SGIX ) ostr << "GL_INTERLACE_SGIX";
	#endif
	#ifdef GL_PACK_RESAMPLE_SGIX
		else if ( en == GL_PACK_RESAMPLE_SGIX ) ostr << "GL_PACK_RESAMPLE_SGIX";
	#endif
	#ifdef GL_UNPACK_RESAMPLE_SGIX
		else if ( en == GL_UNPACK_RESAMPLE_SGIX ) ostr << "GL_UNPACK_RESAMPLE_SGIX";
	#endif
	#ifdef GL_RESAMPLE_DECIMATE_SGIX
		else if ( en == GL_RESAMPLE_DECIMATE_SGIX ) ostr << "GL_RESAMPLE_DECIMATE_SGIX";
	#endif
	#ifdef GL_RESAMPLE_REPLICATE_SGIX
		else if ( en == GL_RESAMPLE_REPLICATE_SGIX ) ostr << "GL_RESAMPLE_REPLICATE_SGIX";
	#endif
	#ifdef GL_RESAMPLE_ZERO_FILL_SGIX
		else if ( en == GL_RESAMPLE_ZERO_FILL_SGIX ) ostr << "GL_RESAMPLE_ZERO_FILL_SGIX";
	#endif
	#ifdef GL_TEXTURE_COMPARE_SGIX
		else if ( en == GL_TEXTURE_COMPARE_SGIX ) ostr << "GL_TEXTURE_COMPARE_SGIX";
	#endif
	#ifdef GL_TEXTURE_COMPARE_OPERATOR_SGIX
		else if ( en == GL_TEXTURE_COMPARE_OPERATOR_SGIX ) ostr << "GL_TEXTURE_COMPARE_OPERATOR_SGIX";
	#endif
	#ifdef GL_TEXTURE_LEQUAL_R_SGIX
		else if ( en == GL_TEXTURE_LEQUAL_R_SGIX ) ostr << "GL_TEXTURE_LEQUAL_R_SGIX";
	#endif
	#ifdef GL_TEXTURE_GEQUAL_R_SGIX
		else if ( en == GL_TEXTURE_GEQUAL_R_SGIX ) ostr << "GL_TEXTURE_GEQUAL_R_SGIX";
	#endif
	#ifdef GL_SHADOW_AMBIENT_SGIX
		else if ( en == GL_SHADOW_AMBIENT_SGIX ) ostr << "GL_SHADOW_AMBIENT_SGIX";
	#endif
	#ifdef GL_TEXTURE_MAX_CLAMP_S_SGIX
		else if ( en == GL_TEXTURE_MAX_CLAMP_S_SGIX ) ostr << "GL_TEXTURE_MAX_CLAMP_S_SGIX";
	#endif
	#ifdef GL_TEXTURE_MAX_CLAMP_T_SGIX
		else if ( en == GL_TEXTURE_MAX_CLAMP_T_SGIX ) ostr << "GL_TEXTURE_MAX_CLAMP_T_SGIX";
	#endif
	#ifdef GL_TEXTURE_MAX_CLAMP_R_SGIX
		else if ( en == GL_TEXTURE_MAX_CLAMP_R_SGIX ) ostr << "GL_TEXTURE_MAX_CLAMP_R_SGIX";
	#endif
	#ifdef GL_TEXTURE_MULTI_BUFFER_HINT_SGIX
		else if ( en == GL_TEXTURE_MULTI_BUFFER_HINT_SGIX ) ostr << "GL_TEXTURE_MULTI_BUFFER_HINT_SGIX";
	#endif
	#ifdef GL_RGB_SIGNED_SGIX
		else if ( en == GL_RGB_SIGNED_SGIX ) ostr << "GL_RGB_SIGNED_SGIX";
	#endif
	#ifdef GL_RGBA_SIGNED_SGIX
		else if ( en == GL_RGBA_SIGNED_SGIX ) ostr << "GL_RGBA_SIGNED_SGIX";
	#endif
	#ifdef GL_ALPHA_SIGNED_SGIX
		else if ( en == GL_ALPHA_SIGNED_SGIX ) ostr << "GL_ALPHA_SIGNED_SGIX";
	#endif
	#ifdef GL_LUMINANCE_SIGNED_SGIX
		else if ( en == GL_LUMINANCE_SIGNED_SGIX ) ostr << "GL_LUMINANCE_SIGNED_SGIX";
	#endif
	#ifdef GL_INTENSITY_SIGNED_SGIX
		else if ( en == GL_INTENSITY_SIGNED_SGIX ) ostr << "GL_INTENSITY_SIGNED_SGIX";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_SIGNED_SGIX
		else if ( en == GL_LUMINANCE_ALPHA_SIGNED_SGIX ) ostr << "GL_LUMINANCE_ALPHA_SIGNED_SGIX";
	#endif
	#ifdef GL_RGB16_SIGNED_SGIX
		else if ( en == GL_RGB16_SIGNED_SGIX ) ostr << "GL_RGB16_SIGNED_SGIX";
	#endif
	#ifdef GL_RGBA16_SIGNED_SGIX
		else if ( en == GL_RGBA16_SIGNED_SGIX ) ostr << "GL_RGBA16_SIGNED_SGIX";
	#endif
	#ifdef GL_ALPHA16_SIGNED_SGIX
		else if ( en == GL_ALPHA16_SIGNED_SGIX ) ostr << "GL_ALPHA16_SIGNED_SGIX";
	#endif
	#ifdef GL_LUMINANCE16_SIGNED_SGIX
		else if ( en == GL_LUMINANCE16_SIGNED_SGIX ) ostr << "GL_LUMINANCE16_SIGNED_SGIX";
	#endif
	#ifdef GL_INTENSITY16_SIGNED_SGIX
		else if ( en == GL_INTENSITY16_SIGNED_SGIX ) ostr << "GL_INTENSITY16_SIGNED_SGIX";
	#endif
	#ifdef GL_LUMINANCE16_ALPHA16_SIGNED_SGIX
		else if ( en == GL_LUMINANCE16_ALPHA16_SIGNED_SGIX ) ostr << "GL_LUMINANCE16_ALPHA16_SIGNED_SGIX";
	#endif
	#ifdef GL_RGB_EXTENDED_RANGE_SGIX
		else if ( en == GL_RGB_EXTENDED_RANGE_SGIX ) ostr << "GL_RGB_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_RGBA_EXTENDED_RANGE_SGIX
		else if ( en == GL_RGBA_EXTENDED_RANGE_SGIX ) ostr << "GL_RGBA_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_ALPHA_EXTENDED_RANGE_SGIX
		else if ( en == GL_ALPHA_EXTENDED_RANGE_SGIX ) ostr << "GL_ALPHA_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_LUMINANCE_EXTENDED_RANGE_SGIX
		else if ( en == GL_LUMINANCE_EXTENDED_RANGE_SGIX ) ostr << "GL_LUMINANCE_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_INTENSITY_EXTENDED_RANGE_SGIX
		else if ( en == GL_INTENSITY_EXTENDED_RANGE_SGIX ) ostr << "GL_INTENSITY_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX
		else if ( en == GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX ) ostr << "GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_RGB16_EXTENDED_RANGE_SGIX
		else if ( en == GL_RGB16_EXTENDED_RANGE_SGIX ) ostr << "GL_RGB16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_RGBA16_EXTENDED_RANGE_SGIX
		else if ( en == GL_RGBA16_EXTENDED_RANGE_SGIX ) ostr << "GL_RGBA16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_ALPHA16_EXTENDED_RANGE_SGIX
		else if ( en == GL_ALPHA16_EXTENDED_RANGE_SGIX ) ostr << "GL_ALPHA16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_LUMINANCE16_EXTENDED_RANGE_SGIX
		else if ( en == GL_LUMINANCE16_EXTENDED_RANGE_SGIX ) ostr << "GL_LUMINANCE16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_INTENSITY16_EXTENDED_RANGE_SGIX
		else if ( en == GL_INTENSITY16_EXTENDED_RANGE_SGIX ) ostr << "GL_INTENSITY16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX
		else if ( en == GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX ) ostr << "GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX";
	#endif
	#ifdef GL_MIN_LUMINANCE_SGIS
		else if ( en == GL_MIN_LUMINANCE_SGIS ) ostr << "GL_MIN_LUMINANCE_SGIS";
	#endif
	#ifdef GL_MAX_LUMINANCE_SGIS
		else if ( en == GL_MAX_LUMINANCE_SGIS ) ostr << "GL_MAX_LUMINANCE_SGIS";
	#endif
	#ifdef GL_MIN_INTENSITY_SGIS
		else if ( en == GL_MIN_INTENSITY_SGIS ) ostr << "GL_MIN_INTENSITY_SGIS";
	#endif
	#ifdef GL_MAX_INTENSITY_SGIS
		else if ( en == GL_MAX_INTENSITY_SGIS ) ostr << "GL_MAX_INTENSITY_SGIS";
	#endif
	#ifdef GL_POST_TEXTURE_FILTER_BIAS_SGIX
		else if ( en == GL_POST_TEXTURE_FILTER_BIAS_SGIX ) ostr << "GL_POST_TEXTURE_FILTER_BIAS_SGIX";
	#endif
	#ifdef GL_POST_TEXTURE_FILTER_SCALE_SGIX
		else if ( en == GL_POST_TEXTURE_FILTER_SCALE_SGIX ) ostr << "GL_POST_TEXTURE_FILTER_SCALE_SGIX";
	#endif
	#ifdef GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX
		else if ( en == GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX ) ostr << "GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX";
	#endif
	#ifdef GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX
		else if ( en == GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX ) ostr << "GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX";
	#endif
	#ifdef GL_VERTEX_PRECLIP_SGIX
		else if ( en == GL_VERTEX_PRECLIP_SGIX ) ostr << "GL_VERTEX_PRECLIP_SGIX";
	#endif
	#ifdef GL_VERTEX_PRECLIP_HINT_SGIX
		else if ( en == GL_VERTEX_PRECLIP_HINT_SGIX ) ostr << "GL_VERTEX_PRECLIP_HINT_SGIX";
	#endif
	#ifdef GL_VERTEX_PRECLIP_SGIX
		else if ( en == GL_VERTEX_PRECLIP_SGIX ) ostr << "GL_VERTEX_PRECLIP_SGIX";
	#endif
	#ifdef GL_VERTEX_PRECLIP_HINT_SGIX
		else if ( en == GL_VERTEX_PRECLIP_HINT_SGIX ) ostr << "GL_VERTEX_PRECLIP_HINT_SGIX";
	#endif
	#ifdef GL_COLOR_MATRIX_SGI
		else if ( en == GL_COLOR_MATRIX_SGI ) ostr << "GL_COLOR_MATRIX_SGI";
	#endif
	#ifdef GL_COLOR_MATRIX_STACK_DEPTH_SGI
		else if ( en == GL_COLOR_MATRIX_STACK_DEPTH_SGI ) ostr << "GL_COLOR_MATRIX_STACK_DEPTH_SGI";
	#endif
	#ifdef GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI
		else if ( en == GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI ) ostr << "GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_RED_SCALE_SGI
		else if ( en == GL_POST_COLOR_MATRIX_RED_SCALE_SGI ) ostr << "GL_POST_COLOR_MATRIX_RED_SCALE_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI
		else if ( en == GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI ) ostr << "GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI
		else if ( en == GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI ) ostr << "GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI
		else if ( en == GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI ) ostr << "GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_RED_BIAS_SGI
		else if ( en == GL_POST_COLOR_MATRIX_RED_BIAS_SGI ) ostr << "GL_POST_COLOR_MATRIX_RED_BIAS_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI
		else if ( en == GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI ) ostr << "GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI
		else if ( en == GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI ) ostr << "GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI
		else if ( en == GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI ) ostr << "GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_SGI
		else if ( en == GL_COLOR_TABLE_SGI ) ostr << "GL_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_POST_CONVOLUTION_COLOR_TABLE_SGI
		else if ( en == GL_POST_CONVOLUTION_COLOR_TABLE_SGI ) ostr << "GL_POST_CONVOLUTION_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI
		else if ( en == GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI ) ostr << "GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_PROXY_COLOR_TABLE_SGI
		else if ( en == GL_PROXY_COLOR_TABLE_SGI ) ostr << "GL_PROXY_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI
		else if ( en == GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI ) ostr << "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI
		else if ( en == GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI ) ostr << "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_SCALE_SGI
		else if ( en == GL_COLOR_TABLE_SCALE_SGI ) ostr << "GL_COLOR_TABLE_SCALE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_BIAS_SGI
		else if ( en == GL_COLOR_TABLE_BIAS_SGI ) ostr << "GL_COLOR_TABLE_BIAS_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_FORMAT_SGI
		else if ( en == GL_COLOR_TABLE_FORMAT_SGI ) ostr << "GL_COLOR_TABLE_FORMAT_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_WIDTH_SGI
		else if ( en == GL_COLOR_TABLE_WIDTH_SGI ) ostr << "GL_COLOR_TABLE_WIDTH_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_RED_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_RED_SIZE_SGI ) ostr << "GL_COLOR_TABLE_RED_SIZE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_GREEN_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_GREEN_SIZE_SGI ) ostr << "GL_COLOR_TABLE_GREEN_SIZE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_BLUE_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_BLUE_SIZE_SGI ) ostr << "GL_COLOR_TABLE_BLUE_SIZE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_ALPHA_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_ALPHA_SIZE_SGI ) ostr << "GL_COLOR_TABLE_ALPHA_SIZE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE_SGI ) ostr << "GL_COLOR_TABLE_LUMINANCE_SIZE_SGI";
	#endif
	#ifdef GL_COLOR_TABLE_INTENSITY_SIZE_SGI
		else if ( en == GL_COLOR_TABLE_INTENSITY_SIZE_SGI ) ostr << "GL_COLOR_TABLE_INTENSITY_SIZE_SGI";
	#endif
	#ifdef GL_TEXTURE_COLOR_TABLE_SGI
		else if ( en == GL_TEXTURE_COLOR_TABLE_SGI ) ostr << "GL_TEXTURE_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_PROXY_TEXTURE_COLOR_TABLE_SGI
		else if ( en == GL_PROXY_TEXTURE_COLOR_TABLE_SGI ) ostr << "GL_PROXY_TEXTURE_COLOR_TABLE_SGI";
	#endif
	#ifdef GL_UNPACK_CONSTANT_DATA_SUNX
		else if ( en == GL_UNPACK_CONSTANT_DATA_SUNX ) ostr << "GL_UNPACK_CONSTANT_DATA_SUNX";
	#endif
	#ifdef GL_TEXTURE_CONSTANT_DATA_SUNX
		else if ( en == GL_TEXTURE_CONSTANT_DATA_SUNX ) ostr << "GL_TEXTURE_CONSTANT_DATA_SUNX";
	#endif
	#ifdef GL_WRAP_BORDER_SUN
		else if ( en == GL_WRAP_BORDER_SUN ) ostr << "GL_WRAP_BORDER_SUN";
	#endif
	#ifdef GL_GLOBAL_ALPHA_SUN
		else if ( en == GL_GLOBAL_ALPHA_SUN ) ostr << "GL_GLOBAL_ALPHA_SUN";
	#endif
	#ifdef GL_GLOBAL_ALPHA_FACTOR_SUN
		else if ( en == GL_GLOBAL_ALPHA_FACTOR_SUN ) ostr << "GL_GLOBAL_ALPHA_FACTOR_SUN";
	#endif
	#ifdef GL_QUAD_MESH_SUN
		else if ( en == GL_QUAD_MESH_SUN ) ostr << "GL_QUAD_MESH_SUN";
	#endif
	#ifdef GL_TRIANGLE_MESH_SUN
		else if ( en == GL_TRIANGLE_MESH_SUN ) ostr << "GL_TRIANGLE_MESH_SUN";
	#endif
	#ifdef GL_SLICE_ACCUM_SUN
		else if ( en == GL_SLICE_ACCUM_SUN ) ostr << "GL_SLICE_ACCUM_SUN";
	#endif
	#ifdef GL_RESTART_SUN
		else if ( en == GL_RESTART_SUN ) ostr << "GL_RESTART_SUN";
	#endif
	#ifdef GL_REPLACE_MIDDLE_SUN
		else if ( en == GL_REPLACE_MIDDLE_SUN ) ostr << "GL_REPLACE_MIDDLE_SUN";
	#endif
	#ifdef GL_REPLACE_OLDEST_SUN
		else if ( en == GL_REPLACE_OLDEST_SUN ) ostr << "GL_REPLACE_OLDEST_SUN";
	#endif
	#ifdef GL_TRIANGLE_LIST_SUN
		else if ( en == GL_TRIANGLE_LIST_SUN ) ostr << "GL_TRIANGLE_LIST_SUN";
	#endif
	#ifdef GL_REPLACEMENT_CODE_SUN
		else if ( en == GL_REPLACEMENT_CODE_SUN ) ostr << "GL_REPLACEMENT_CODE_SUN";
	#endif
	#ifdef GL_REPLACEMENT_CODE_ARRAY_SUN
		else if ( en == GL_REPLACEMENT_CODE_ARRAY_SUN ) ostr << "GL_REPLACEMENT_CODE_ARRAY_SUN";
	#endif
	#ifdef GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN
		else if ( en == GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN ) ostr << "GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN";
	#endif
	#ifdef GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN
		else if ( en == GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN ) ostr << "GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN";
	#endif
	#ifdef GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN
		else if ( en == GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN ) ostr << "GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN";
	#endif
	#ifdef GL_R1UI_V3F_SUN
		else if ( en == GL_R1UI_V3F_SUN ) ostr << "GL_R1UI_V3F_SUN";
	#endif
	#ifdef GL_R1UI_C4UB_V3F_SUN
		else if ( en == GL_R1UI_C4UB_V3F_SUN ) ostr << "GL_R1UI_C4UB_V3F_SUN";
	#endif
	#ifdef GL_R1UI_C3F_V3F_SUN
		else if ( en == GL_R1UI_C3F_V3F_SUN ) ostr << "GL_R1UI_C3F_V3F_SUN";
	#endif
	#ifdef GL_R1UI_N3F_V3F_SUN
		else if ( en == GL_R1UI_N3F_V3F_SUN ) ostr << "GL_R1UI_N3F_V3F_SUN";
	#endif
	#ifdef GL_R1UI_C4F_N3F_V3F_SUN
		else if ( en == GL_R1UI_C4F_N3F_V3F_SUN ) ostr << "GL_R1UI_C4F_N3F_V3F_SUN";
	#endif
	#ifdef GL_R1UI_T2F_V3F_SUN
		else if ( en == GL_R1UI_T2F_V3F_SUN ) ostr << "GL_R1UI_T2F_V3F_SUN";
	#endif
	#ifdef GL_R1UI_T2F_N3F_V3F_SUN
		else if ( en == GL_R1UI_T2F_N3F_V3F_SUN ) ostr << "GL_R1UI_T2F_N3F_V3F_SUN";
	#endif
	#ifdef GL_R1UI_T2F_C4F_N3F_V3F_SUN
		else if ( en == GL_R1UI_T2F_C4F_N3F_V3F_SUN ) ostr << "GL_R1UI_T2F_C4F_N3F_V3F_SUN";
	#endif
	#ifdef GL_PHONG_WIN
		else if ( en == GL_PHONG_WIN ) ostr << "GL_PHONG_WIN";
	#endif
	#ifdef GL_PHONG_HINT_WIN
		else if ( en == GL_PHONG_HINT_WIN ) ostr << "GL_PHONG_HINT_WIN";
	#endif
	#ifdef GL_FOG_SPECULAR_TEXTURE_WIN
		else if ( en == GL_FOG_SPECULAR_TEXTURE_WIN ) ostr << "GL_FOG_SPECULAR_TEXTURE_WIN";
	#endif
	
	else ostr << "UNKNOWN ENUM (" << en << ")";
}
} }