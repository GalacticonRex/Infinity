#include "depend/infi_gl.hpp"
#include "render/gl/infi_gl_enum.hpp"

namespace Infinity {
namespace Render {

const char* glenum( uint32 en ) {
	if ( en == GL_ZERO ) return "GL_ZERO";
	if ( en == GL_ONE ) return "GL_ONE";
#ifdef GL_LOGIC_OP
	if ( en == GL_LOGIC_OP ) return "GL_LOGIC_OP";
#endif
#ifdef GL_TEXTURE_COMPONENTS
	if ( en == GL_TEXTURE_COMPONENTS ) return "GL_TEXTURE_COMPONENTS";
#endif
#ifdef GL_POINTS
	if ( en == GL_POINTS ) return "GL_POINTS";
#endif
#ifdef GL_CURRENT_BIT
	if ( en == GL_CURRENT_BIT ) return "GL_CURRENT_BIT";
#endif
#ifdef GL_CLIENT_PIXEL_STORE_BIT
	if ( en == GL_CLIENT_PIXEL_STORE_BIT ) return "GL_CLIENT_PIXEL_STORE_BIT";
#endif
#ifdef GL_LINES
	if ( en == GL_LINES ) return "GL_LINES";
#endif
#ifdef GL_LINE_LOOP
	if ( en == GL_LINE_LOOP ) return "GL_LINE_LOOP";
#endif
#ifdef GL_CLIENT_VERTEX_ARRAY_BIT
	if ( en == GL_CLIENT_VERTEX_ARRAY_BIT ) return "GL_CLIENT_VERTEX_ARRAY_BIT";
#endif
#ifdef GL_LINE_STRIP
	if ( en == GL_LINE_STRIP ) return "GL_LINE_STRIP";
#endif
#ifdef GL_TRIANGLES
	if ( en == GL_TRIANGLES ) return "GL_TRIANGLES";
#endif
#ifdef GL_TRIANGLE_STRIP
	if ( en == GL_TRIANGLE_STRIP ) return "GL_TRIANGLE_STRIP";
#endif
#ifdef GL_TRIANGLE_FAN
	if ( en == GL_TRIANGLE_FAN ) return "GL_TRIANGLE_FAN";
#endif
#ifdef GL_QUADS
	if ( en == GL_QUADS ) return "GL_QUADS";
#endif
#ifdef GL_QUAD_STRIP
	if ( en == GL_QUAD_STRIP ) return "GL_QUAD_STRIP";
#endif
#ifdef GL_POLYGON_BIT
	if ( en == GL_POLYGON_BIT ) return "GL_POLYGON_BIT";
#endif
#ifdef GL_POLYGON
	if ( en == GL_POLYGON ) return "GL_POLYGON";
#endif
#ifdef GL_POLYGON_STIPPLE_BIT
	if ( en == GL_POLYGON_STIPPLE_BIT ) return "GL_POLYGON_STIPPLE_BIT";
#endif
#ifdef GL_PIXEL_MODE_BIT
	if ( en == GL_PIXEL_MODE_BIT ) return "GL_PIXEL_MODE_BIT";
#endif
#ifdef GL_LIGHTING_BIT
	if ( en == GL_LIGHTING_BIT ) return "GL_LIGHTING_BIT";
#endif
#ifdef GL_FOG_BIT
	if ( en == GL_FOG_BIT ) return "GL_FOG_BIT";
#endif
#ifdef GL_DEPTH_BUFFER_BIT
	if ( en == GL_DEPTH_BUFFER_BIT ) return "GL_DEPTH_BUFFER_BIT";
#endif
#ifdef GL_ACCUM
	if ( en == GL_ACCUM ) return "GL_ACCUM";
#endif
#ifdef GL_LOAD
	if ( en == GL_LOAD ) return "GL_LOAD";
#endif
#ifdef GL_RETURN
	if ( en == GL_RETURN ) return "GL_RETURN";
#endif
#ifdef GL_MULT
	if ( en == GL_MULT ) return "GL_MULT";
#endif
#ifdef GL_ADD
	if ( en == GL_ADD ) return "GL_ADD";
#endif
#ifdef GL_NEVER
	if ( en == GL_NEVER ) return "GL_NEVER";
#endif
#ifdef GL_ACCUM_BUFFER_BIT
	if ( en == GL_ACCUM_BUFFER_BIT ) return "GL_ACCUM_BUFFER_BIT";
#endif
#ifdef GL_LESS
	if ( en == GL_LESS ) return "GL_LESS";
#endif
#ifdef GL_EQUAL
	if ( en == GL_EQUAL ) return "GL_EQUAL";
#endif
#ifdef GL_LEQUAL
	if ( en == GL_LEQUAL ) return "GL_LEQUAL";
#endif
#ifdef GL_GREATER
	if ( en == GL_GREATER ) return "GL_GREATER";
#endif
#ifdef GL_NOTEQUAL
	if ( en == GL_NOTEQUAL ) return "GL_NOTEQUAL";
#endif
#ifdef GL_GEQUAL
	if ( en == GL_GEQUAL ) return "GL_GEQUAL";
#endif
#ifdef GL_ALWAYS
	if ( en == GL_ALWAYS ) return "GL_ALWAYS";
#endif
#ifdef GL_SRC_COLOR
	if ( en == GL_SRC_COLOR ) return "GL_SRC_COLOR";
#endif
#ifdef GL_ONE_MINUS_SRC_COLOR
	if ( en == GL_ONE_MINUS_SRC_COLOR ) return "GL_ONE_MINUS_SRC_COLOR";
#endif
#ifdef GL_SRC_ALPHA
	if ( en == GL_SRC_ALPHA ) return "GL_SRC_ALPHA";
#endif
#ifdef GL_ONE_MINUS_SRC_ALPHA
	if ( en == GL_ONE_MINUS_SRC_ALPHA ) return "GL_ONE_MINUS_SRC_ALPHA";
#endif
#ifdef GL_DST_ALPHA
	if ( en == GL_DST_ALPHA ) return "GL_DST_ALPHA";
#endif
#ifdef GL_ONE_MINUS_DST_ALPHA
	if ( en == GL_ONE_MINUS_DST_ALPHA ) return "GL_ONE_MINUS_DST_ALPHA";
#endif
#ifdef GL_DST_COLOR
	if ( en == GL_DST_COLOR ) return "GL_DST_COLOR";
#endif
#ifdef GL_ONE_MINUS_DST_COLOR
	if ( en == GL_ONE_MINUS_DST_COLOR ) return "GL_ONE_MINUS_DST_COLOR";
#endif
#ifdef GL_SRC_ALPHA_SATURATE
	if ( en == GL_SRC_ALPHA_SATURATE ) return "GL_SRC_ALPHA_SATURATE";
#endif
#ifdef GL_STENCIL_BUFFER_BIT
	if ( en == GL_STENCIL_BUFFER_BIT ) return "GL_STENCIL_BUFFER_BIT";
#endif
#ifdef GL_FRONT_LEFT
	if ( en == GL_FRONT_LEFT ) return "GL_FRONT_LEFT";
#endif
#ifdef GL_FRONT_RIGHT
	if ( en == GL_FRONT_RIGHT ) return "GL_FRONT_RIGHT";
#endif
#ifdef GL_BACK_LEFT
	if ( en == GL_BACK_LEFT ) return "GL_BACK_LEFT";
#endif
#ifdef GL_BACK_RIGHT
	if ( en == GL_BACK_RIGHT ) return "GL_BACK_RIGHT";
#endif
#ifdef GL_FRONT
	if ( en == GL_FRONT ) return "GL_FRONT";
#endif
#ifdef GL_BACK
	if ( en == GL_BACK ) return "GL_BACK";
#endif
#ifdef GL_LEFT
	if ( en == GL_LEFT ) return "GL_LEFT";
#endif
#ifdef GL_RIGHT
	if ( en == GL_RIGHT ) return "GL_RIGHT";
#endif
#ifdef GL_FRONT_AND_BACK
	if ( en == GL_FRONT_AND_BACK ) return "GL_FRONT_AND_BACK";
#endif
#ifdef GL_AUX0
	if ( en == GL_AUX0 ) return "GL_AUX0";
#endif
#ifdef GL_AUX1
	if ( en == GL_AUX1 ) return "GL_AUX1";
#endif
#ifdef GL_AUX2
	if ( en == GL_AUX2 ) return "GL_AUX2";
#endif
#ifdef GL_AUX3
	if ( en == GL_AUX3 ) return "GL_AUX3";
#endif
#ifdef GL_INVALID_ENUM
	if ( en == GL_INVALID_ENUM ) return "GL_INVALID_ENUM";
#endif
#ifdef GL_INVALID_VALUE
	if ( en == GL_INVALID_VALUE ) return "GL_INVALID_VALUE";
#endif
#ifdef GL_INVALID_OPERATION
	if ( en == GL_INVALID_OPERATION ) return "GL_INVALID_OPERATION";
#endif
#ifdef GL_STACK_OVERFLOW
	if ( en == GL_STACK_OVERFLOW ) return "GL_STACK_OVERFLOW";
#endif
#ifdef GL_STACK_UNDERFLOW
	if ( en == GL_STACK_UNDERFLOW ) return "GL_STACK_UNDERFLOW";
#endif
#ifdef GL_OUT_OF_MEMORY
	if ( en == GL_OUT_OF_MEMORY ) return "GL_OUT_OF_MEMORY";
#endif
#ifdef GL_2D
	if ( en == GL_2D ) return "GL_2D";
#endif
#ifdef GL_3D
	if ( en == GL_3D ) return "GL_3D";
#endif
#ifdef GL_3D_COLOR
	if ( en == GL_3D_COLOR ) return "GL_3D_COLOR";
#endif
#ifdef GL_3D_COLOR_TEXTURE
	if ( en == GL_3D_COLOR_TEXTURE ) return "GL_3D_COLOR_TEXTURE";
#endif
#ifdef GL_4D_COLOR_TEXTURE
	if ( en == GL_4D_COLOR_TEXTURE ) return "GL_4D_COLOR_TEXTURE";
#endif
#ifdef GL_PASS_THROUGH_TOKEN
	if ( en == GL_PASS_THROUGH_TOKEN ) return "GL_PASS_THROUGH_TOKEN";
#endif
#ifdef GL_POINT_TOKEN
	if ( en == GL_POINT_TOKEN ) return "GL_POINT_TOKEN";
#endif
#ifdef GL_LINE_TOKEN
	if ( en == GL_LINE_TOKEN ) return "GL_LINE_TOKEN";
#endif
#ifdef GL_POLYGON_TOKEN
	if ( en == GL_POLYGON_TOKEN ) return "GL_POLYGON_TOKEN";
#endif
#ifdef GL_BITMAP_TOKEN
	if ( en == GL_BITMAP_TOKEN ) return "GL_BITMAP_TOKEN";
#endif
#ifdef GL_DRAW_PIXEL_TOKEN
	if ( en == GL_DRAW_PIXEL_TOKEN ) return "GL_DRAW_PIXEL_TOKEN";
#endif
#ifdef GL_COPY_PIXEL_TOKEN
	if ( en == GL_COPY_PIXEL_TOKEN ) return "GL_COPY_PIXEL_TOKEN";
#endif
#ifdef GL_LINE_RESET_TOKEN
	if ( en == GL_LINE_RESET_TOKEN ) return "GL_LINE_RESET_TOKEN";
#endif
#ifdef GL_EXP
	if ( en == GL_EXP ) return "GL_EXP";
#endif
#ifdef GL_VIEWPORT_BIT
	if ( en == GL_VIEWPORT_BIT ) return "GL_VIEWPORT_BIT";
#endif
#ifdef GL_EXP2
	if ( en == GL_EXP2 ) return "GL_EXP2";
#endif
#ifdef GL_CW
	if ( en == GL_CW ) return "GL_CW";
#endif
#ifdef GL_CCW
	if ( en == GL_CCW ) return "GL_CCW";
#endif
#ifdef GL_COEFF
	if ( en == GL_COEFF ) return "GL_COEFF";
#endif
#ifdef GL_ORDER
	if ( en == GL_ORDER ) return "GL_ORDER";
#endif
#ifdef GL_DOMAIN
	if ( en == GL_DOMAIN ) return "GL_DOMAIN";
#endif
#ifdef GL_CURRENT_COLOR
	if ( en == GL_CURRENT_COLOR ) return "GL_CURRENT_COLOR";
#endif
#ifdef GL_CURRENT_INDEX
	if ( en == GL_CURRENT_INDEX ) return "GL_CURRENT_INDEX";
#endif
#ifdef GL_CURRENT_NORMAL
	if ( en == GL_CURRENT_NORMAL ) return "GL_CURRENT_NORMAL";
#endif
#ifdef GL_CURRENT_TEXTURE_COORDS
	if ( en == GL_CURRENT_TEXTURE_COORDS ) return "GL_CURRENT_TEXTURE_COORDS";
#endif
#ifdef GL_CURRENT_RASTER_COLOR
	if ( en == GL_CURRENT_RASTER_COLOR ) return "GL_CURRENT_RASTER_COLOR";
#endif
#ifdef GL_CURRENT_RASTER_INDEX
	if ( en == GL_CURRENT_RASTER_INDEX ) return "GL_CURRENT_RASTER_INDEX";
#endif
#ifdef GL_CURRENT_RASTER_TEXTURE_COORDS
	if ( en == GL_CURRENT_RASTER_TEXTURE_COORDS ) return "GL_CURRENT_RASTER_TEXTURE_COORDS";
#endif
#ifdef GL_CURRENT_RASTER_POSITION
	if ( en == GL_CURRENT_RASTER_POSITION ) return "GL_CURRENT_RASTER_POSITION";
#endif
#ifdef GL_CURRENT_RASTER_POSITION_VALID
	if ( en == GL_CURRENT_RASTER_POSITION_VALID ) return "GL_CURRENT_RASTER_POSITION_VALID";
#endif
#ifdef GL_CURRENT_RASTER_DISTANCE
	if ( en == GL_CURRENT_RASTER_DISTANCE ) return "GL_CURRENT_RASTER_DISTANCE";
#endif
#ifdef GL_POINT_SMOOTH
	if ( en == GL_POINT_SMOOTH ) return "GL_POINT_SMOOTH";
#endif
#ifdef GL_POINT_SIZE
	if ( en == GL_POINT_SIZE ) return "GL_POINT_SIZE";
#endif
#ifdef GL_POINT_SIZE_RANGE
	if ( en == GL_POINT_SIZE_RANGE ) return "GL_POINT_SIZE_RANGE";
#endif
#ifdef GL_POINT_SIZE_GRANULARITY
	if ( en == GL_POINT_SIZE_GRANULARITY ) return "GL_POINT_SIZE_GRANULARITY";
#endif
#ifdef GL_LINE_SMOOTH
	if ( en == GL_LINE_SMOOTH ) return "GL_LINE_SMOOTH";
#endif
#ifdef GL_LINE_WIDTH
	if ( en == GL_LINE_WIDTH ) return "GL_LINE_WIDTH";
#endif
#ifdef GL_LINE_WIDTH_RANGE
	if ( en == GL_LINE_WIDTH_RANGE ) return "GL_LINE_WIDTH_RANGE";
#endif
#ifdef GL_LINE_WIDTH_GRANULARITY
	if ( en == GL_LINE_WIDTH_GRANULARITY ) return "GL_LINE_WIDTH_GRANULARITY";
#endif
#ifdef GL_LINE_STIPPLE
	if ( en == GL_LINE_STIPPLE ) return "GL_LINE_STIPPLE";
#endif
#ifdef GL_LINE_STIPPLE_PATTERN
	if ( en == GL_LINE_STIPPLE_PATTERN ) return "GL_LINE_STIPPLE_PATTERN";
#endif
#ifdef GL_LINE_STIPPLE_REPEAT
	if ( en == GL_LINE_STIPPLE_REPEAT ) return "GL_LINE_STIPPLE_REPEAT";
#endif
#ifdef GL_LIST_MODE
	if ( en == GL_LIST_MODE ) return "GL_LIST_MODE";
#endif
#ifdef GL_MAX_LIST_NESTING
	if ( en == GL_MAX_LIST_NESTING ) return "GL_MAX_LIST_NESTING";
#endif
#ifdef GL_LIST_BASE
	if ( en == GL_LIST_BASE ) return "GL_LIST_BASE";
#endif
#ifdef GL_LIST_INDEX
	if ( en == GL_LIST_INDEX ) return "GL_LIST_INDEX";
#endif
#ifdef GL_POLYGON_MODE
	if ( en == GL_POLYGON_MODE ) return "GL_POLYGON_MODE";
#endif
#ifdef GL_POLYGON_SMOOTH
	if ( en == GL_POLYGON_SMOOTH ) return "GL_POLYGON_SMOOTH";
#endif
#ifdef GL_POLYGON_STIPPLE
	if ( en == GL_POLYGON_STIPPLE ) return "GL_POLYGON_STIPPLE";
#endif
#ifdef GL_EDGE_FLAG
	if ( en == GL_EDGE_FLAG ) return "GL_EDGE_FLAG";
#endif
#ifdef GL_CULL_FACE
	if ( en == GL_CULL_FACE ) return "GL_CULL_FACE";
#endif
#ifdef GL_CULL_FACE_MODE
	if ( en == GL_CULL_FACE_MODE ) return "GL_CULL_FACE_MODE";
#endif
#ifdef GL_FRONT_FACE
	if ( en == GL_FRONT_FACE ) return "GL_FRONT_FACE";
#endif
#ifdef GL_LIGHTING
	if ( en == GL_LIGHTING ) return "GL_LIGHTING";
#endif
#ifdef GL_LIGHT_MODEL_LOCAL_VIEWER
	if ( en == GL_LIGHT_MODEL_LOCAL_VIEWER ) return "GL_LIGHT_MODEL_LOCAL_VIEWER";
#endif
#ifdef GL_LIGHT_MODEL_TWO_SIDE
	if ( en == GL_LIGHT_MODEL_TWO_SIDE ) return "GL_LIGHT_MODEL_TWO_SIDE";
#endif
#ifdef GL_LIGHT_MODEL_AMBIENT
	if ( en == GL_LIGHT_MODEL_AMBIENT ) return "GL_LIGHT_MODEL_AMBIENT";
#endif
#ifdef GL_SHADE_MODEL
	if ( en == GL_SHADE_MODEL ) return "GL_SHADE_MODEL";
#endif
#ifdef GL_COLOR_MATERIAL_FACE
	if ( en == GL_COLOR_MATERIAL_FACE ) return "GL_COLOR_MATERIAL_FACE";
#endif
#ifdef GL_COLOR_MATERIAL_PARAMETER
	if ( en == GL_COLOR_MATERIAL_PARAMETER ) return "GL_COLOR_MATERIAL_PARAMETER";
#endif
#ifdef GL_COLOR_MATERIAL
	if ( en == GL_COLOR_MATERIAL ) return "GL_COLOR_MATERIAL";
#endif
#ifdef GL_FOG
	if ( en == GL_FOG ) return "GL_FOG";
#endif
#ifdef GL_FOG_INDEX
	if ( en == GL_FOG_INDEX ) return "GL_FOG_INDEX";
#endif
#ifdef GL_FOG_DENSITY
	if ( en == GL_FOG_DENSITY ) return "GL_FOG_DENSITY";
#endif
#ifdef GL_FOG_START
	if ( en == GL_FOG_START ) return "GL_FOG_START";
#endif
#ifdef GL_FOG_END
	if ( en == GL_FOG_END ) return "GL_FOG_END";
#endif
#ifdef GL_FOG_MODE
	if ( en == GL_FOG_MODE ) return "GL_FOG_MODE";
#endif
#ifdef GL_FOG_COLOR
	if ( en == GL_FOG_COLOR ) return "GL_FOG_COLOR";
#endif
#ifdef GL_DEPTH_RANGE
	if ( en == GL_DEPTH_RANGE ) return "GL_DEPTH_RANGE";
#endif
#ifdef GL_DEPTH_TEST
	if ( en == GL_DEPTH_TEST ) return "GL_DEPTH_TEST";
#endif
#ifdef GL_DEPTH_WRITEMASK
	if ( en == GL_DEPTH_WRITEMASK ) return "GL_DEPTH_WRITEMASK";
#endif
#ifdef GL_DEPTH_CLEAR_VALUE
	if ( en == GL_DEPTH_CLEAR_VALUE ) return "GL_DEPTH_CLEAR_VALUE";
#endif
#ifdef GL_DEPTH_FUNC
	if ( en == GL_DEPTH_FUNC ) return "GL_DEPTH_FUNC";
#endif
#ifdef GL_ACCUM_CLEAR_VALUE
	if ( en == GL_ACCUM_CLEAR_VALUE ) return "GL_ACCUM_CLEAR_VALUE";
#endif
#ifdef GL_STENCIL_TEST
	if ( en == GL_STENCIL_TEST ) return "GL_STENCIL_TEST";
#endif
#ifdef GL_STENCIL_CLEAR_VALUE
	if ( en == GL_STENCIL_CLEAR_VALUE ) return "GL_STENCIL_CLEAR_VALUE";
#endif
#ifdef GL_STENCIL_FUNC
	if ( en == GL_STENCIL_FUNC ) return "GL_STENCIL_FUNC";
#endif
#ifdef GL_STENCIL_VALUE_MASK
	if ( en == GL_STENCIL_VALUE_MASK ) return "GL_STENCIL_VALUE_MASK";
#endif
#ifdef GL_STENCIL_FAIL
	if ( en == GL_STENCIL_FAIL ) return "GL_STENCIL_FAIL";
#endif
#ifdef GL_STENCIL_PASS_DEPTH_FAIL
	if ( en == GL_STENCIL_PASS_DEPTH_FAIL ) return "GL_STENCIL_PASS_DEPTH_FAIL";
#endif
#ifdef GL_STENCIL_PASS_DEPTH_PASS
	if ( en == GL_STENCIL_PASS_DEPTH_PASS ) return "GL_STENCIL_PASS_DEPTH_PASS";
#endif
#ifdef GL_STENCIL_REF
	if ( en == GL_STENCIL_REF ) return "GL_STENCIL_REF";
#endif
#ifdef GL_STENCIL_WRITEMASK
	if ( en == GL_STENCIL_WRITEMASK ) return "GL_STENCIL_WRITEMASK";
#endif
#ifdef GL_MATRIX_MODE
	if ( en == GL_MATRIX_MODE ) return "GL_MATRIX_MODE";
#endif
#ifdef GL_NORMALIZE
	if ( en == GL_NORMALIZE ) return "GL_NORMALIZE";
#endif
#ifdef GL_VIEWPORT
	if ( en == GL_VIEWPORT ) return "GL_VIEWPORT";
#endif
#ifdef GL_MODELVIEW_STACK_DEPTH
	if ( en == GL_MODELVIEW_STACK_DEPTH ) return "GL_MODELVIEW_STACK_DEPTH";
#endif
#ifdef GL_PROJECTION_STACK_DEPTH
	if ( en == GL_PROJECTION_STACK_DEPTH ) return "GL_PROJECTION_STACK_DEPTH";
#endif
#ifdef GL_TEXTURE_STACK_DEPTH
	if ( en == GL_TEXTURE_STACK_DEPTH ) return "GL_TEXTURE_STACK_DEPTH";
#endif
#ifdef GL_MODELVIEW_MATRIX
	if ( en == GL_MODELVIEW_MATRIX ) return "GL_MODELVIEW_MATRIX";
#endif
#ifdef GL_PROJECTION_MATRIX
	if ( en == GL_PROJECTION_MATRIX ) return "GL_PROJECTION_MATRIX";
#endif
#ifdef GL_TEXTURE_MATRIX
	if ( en == GL_TEXTURE_MATRIX ) return "GL_TEXTURE_MATRIX";
#endif
#ifdef GL_ATTRIB_STACK_DEPTH
	if ( en == GL_ATTRIB_STACK_DEPTH ) return "GL_ATTRIB_STACK_DEPTH";
#endif
#ifdef GL_CLIENT_ATTRIB_STACK_DEPTH
	if ( en == GL_CLIENT_ATTRIB_STACK_DEPTH ) return "GL_CLIENT_ATTRIB_STACK_DEPTH";
#endif
#ifdef GL_ALPHA_TEST
	if ( en == GL_ALPHA_TEST ) return "GL_ALPHA_TEST";
#endif
#ifdef GL_ALPHA_TEST_FUNC
	if ( en == GL_ALPHA_TEST_FUNC ) return "GL_ALPHA_TEST_FUNC";
#endif
#ifdef GL_ALPHA_TEST_REF
	if ( en == GL_ALPHA_TEST_REF ) return "GL_ALPHA_TEST_REF";
#endif
#ifdef GL_DITHER
	if ( en == GL_DITHER ) return "GL_DITHER";
#endif
#ifdef GL_BLEND_DST
	if ( en == GL_BLEND_DST ) return "GL_BLEND_DST";
#endif
#ifdef GL_BLEND_SRC
	if ( en == GL_BLEND_SRC ) return "GL_BLEND_SRC";
#endif
#ifdef GL_BLEND
	if ( en == GL_BLEND ) return "GL_BLEND";
#endif
#ifdef GL_LOGIC_OP_MODE
	if ( en == GL_LOGIC_OP_MODE ) return "GL_LOGIC_OP_MODE";
#endif
#ifdef GL_INDEX_LOGIC_OP
	if ( en == GL_INDEX_LOGIC_OP ) return "GL_INDEX_LOGIC_OP";
#endif
#ifdef GL_COLOR_LOGIC_OP
	if ( en == GL_COLOR_LOGIC_OP ) return "GL_COLOR_LOGIC_OP";
#endif
#ifdef GL_AUX_BUFFERS
	if ( en == GL_AUX_BUFFERS ) return "GL_AUX_BUFFERS";
#endif
#ifdef GL_DRAW_BUFFER
	if ( en == GL_DRAW_BUFFER ) return "GL_DRAW_BUFFER";
#endif
#ifdef GL_READ_BUFFER
	if ( en == GL_READ_BUFFER ) return "GL_READ_BUFFER";
#endif
#ifdef GL_SCISSOR_BOX
	if ( en == GL_SCISSOR_BOX ) return "GL_SCISSOR_BOX";
#endif
#ifdef GL_SCISSOR_TEST
	if ( en == GL_SCISSOR_TEST ) return "GL_SCISSOR_TEST";
#endif
#ifdef GL_INDEX_CLEAR_VALUE
	if ( en == GL_INDEX_CLEAR_VALUE ) return "GL_INDEX_CLEAR_VALUE";
#endif
#ifdef GL_INDEX_WRITEMASK
	if ( en == GL_INDEX_WRITEMASK ) return "GL_INDEX_WRITEMASK";
#endif
#ifdef GL_COLOR_CLEAR_VALUE
	if ( en == GL_COLOR_CLEAR_VALUE ) return "GL_COLOR_CLEAR_VALUE";
#endif
#ifdef GL_COLOR_WRITEMASK
	if ( en == GL_COLOR_WRITEMASK ) return "GL_COLOR_WRITEMASK";
#endif
#ifdef GL_INDEX_MODE
	if ( en == GL_INDEX_MODE ) return "GL_INDEX_MODE";
#endif
#ifdef GL_RGBA_MODE
	if ( en == GL_RGBA_MODE ) return "GL_RGBA_MODE";
#endif
#ifdef GL_DOUBLEBUFFER
	if ( en == GL_DOUBLEBUFFER ) return "GL_DOUBLEBUFFER";
#endif
#ifdef GL_STEREO
	if ( en == GL_STEREO ) return "GL_STEREO";
#endif
#ifdef GL_RENDER_MODE
	if ( en == GL_RENDER_MODE ) return "GL_RENDER_MODE";
#endif
#ifdef GL_PERSPECTIVE_CORRECTION_HINT
	if ( en == GL_PERSPECTIVE_CORRECTION_HINT ) return "GL_PERSPECTIVE_CORRECTION_HINT";
#endif
#ifdef GL_POINT_SMOOTH_HINT
	if ( en == GL_POINT_SMOOTH_HINT ) return "GL_POINT_SMOOTH_HINT";
#endif
#ifdef GL_LINE_SMOOTH_HINT
	if ( en == GL_LINE_SMOOTH_HINT ) return "GL_LINE_SMOOTH_HINT";
#endif
#ifdef GL_POLYGON_SMOOTH_HINT
	if ( en == GL_POLYGON_SMOOTH_HINT ) return "GL_POLYGON_SMOOTH_HINT";
#endif
#ifdef GL_FOG_HINT
	if ( en == GL_FOG_HINT ) return "GL_FOG_HINT";
#endif
#ifdef GL_TEXTURE_GEN_S
	if ( en == GL_TEXTURE_GEN_S ) return "GL_TEXTURE_GEN_S";
#endif
#ifdef GL_TEXTURE_GEN_T
	if ( en == GL_TEXTURE_GEN_T ) return "GL_TEXTURE_GEN_T";
#endif
#ifdef GL_TEXTURE_GEN_R
	if ( en == GL_TEXTURE_GEN_R ) return "GL_TEXTURE_GEN_R";
#endif
#ifdef GL_TEXTURE_GEN_Q
	if ( en == GL_TEXTURE_GEN_Q ) return "GL_TEXTURE_GEN_Q";
#endif
#ifdef GL_PIXEL_MAP_I_TO_I
	if ( en == GL_PIXEL_MAP_I_TO_I ) return "GL_PIXEL_MAP_I_TO_I";
#endif
#ifdef GL_PIXEL_MAP_S_TO_S
	if ( en == GL_PIXEL_MAP_S_TO_S ) return "GL_PIXEL_MAP_S_TO_S";
#endif
#ifdef GL_PIXEL_MAP_I_TO_R
	if ( en == GL_PIXEL_MAP_I_TO_R ) return "GL_PIXEL_MAP_I_TO_R";
#endif
#ifdef GL_PIXEL_MAP_I_TO_G
	if ( en == GL_PIXEL_MAP_I_TO_G ) return "GL_PIXEL_MAP_I_TO_G";
#endif
#ifdef GL_PIXEL_MAP_I_TO_B
	if ( en == GL_PIXEL_MAP_I_TO_B ) return "GL_PIXEL_MAP_I_TO_B";
#endif
#ifdef GL_PIXEL_MAP_I_TO_A
	if ( en == GL_PIXEL_MAP_I_TO_A ) return "GL_PIXEL_MAP_I_TO_A";
#endif
#ifdef GL_PIXEL_MAP_R_TO_R
	if ( en == GL_PIXEL_MAP_R_TO_R ) return "GL_PIXEL_MAP_R_TO_R";
#endif
#ifdef GL_PIXEL_MAP_G_TO_G
	if ( en == GL_PIXEL_MAP_G_TO_G ) return "GL_PIXEL_MAP_G_TO_G";
#endif
#ifdef GL_PIXEL_MAP_B_TO_B
	if ( en == GL_PIXEL_MAP_B_TO_B ) return "GL_PIXEL_MAP_B_TO_B";
#endif
#ifdef GL_PIXEL_MAP_A_TO_A
	if ( en == GL_PIXEL_MAP_A_TO_A ) return "GL_PIXEL_MAP_A_TO_A";
#endif
#ifdef GL_PIXEL_MAP_I_TO_I_SIZE
	if ( en == GL_PIXEL_MAP_I_TO_I_SIZE ) return "GL_PIXEL_MAP_I_TO_I_SIZE";
#endif
#ifdef GL_PIXEL_MAP_S_TO_S_SIZE
	if ( en == GL_PIXEL_MAP_S_TO_S_SIZE ) return "GL_PIXEL_MAP_S_TO_S_SIZE";
#endif
#ifdef GL_PIXEL_MAP_I_TO_R_SIZE
	if ( en == GL_PIXEL_MAP_I_TO_R_SIZE ) return "GL_PIXEL_MAP_I_TO_R_SIZE";
#endif
#ifdef GL_PIXEL_MAP_I_TO_G_SIZE
	if ( en == GL_PIXEL_MAP_I_TO_G_SIZE ) return "GL_PIXEL_MAP_I_TO_G_SIZE";
#endif
#ifdef GL_PIXEL_MAP_I_TO_B_SIZE
	if ( en == GL_PIXEL_MAP_I_TO_B_SIZE ) return "GL_PIXEL_MAP_I_TO_B_SIZE";
#endif
#ifdef GL_PIXEL_MAP_I_TO_A_SIZE
	if ( en == GL_PIXEL_MAP_I_TO_A_SIZE ) return "GL_PIXEL_MAP_I_TO_A_SIZE";
#endif
#ifdef GL_PIXEL_MAP_R_TO_R_SIZE
	if ( en == GL_PIXEL_MAP_R_TO_R_SIZE ) return "GL_PIXEL_MAP_R_TO_R_SIZE";
#endif
#ifdef GL_PIXEL_MAP_G_TO_G_SIZE
	if ( en == GL_PIXEL_MAP_G_TO_G_SIZE ) return "GL_PIXEL_MAP_G_TO_G_SIZE";
#endif
#ifdef GL_PIXEL_MAP_B_TO_B_SIZE
	if ( en == GL_PIXEL_MAP_B_TO_B_SIZE ) return "GL_PIXEL_MAP_B_TO_B_SIZE";
#endif
#ifdef GL_PIXEL_MAP_A_TO_A_SIZE
	if ( en == GL_PIXEL_MAP_A_TO_A_SIZE ) return "GL_PIXEL_MAP_A_TO_A_SIZE";
#endif
#ifdef GL_UNPACK_SWAP_BYTES
	if ( en == GL_UNPACK_SWAP_BYTES ) return "GL_UNPACK_SWAP_BYTES";
#endif
#ifdef GL_UNPACK_LSB_FIRST
	if ( en == GL_UNPACK_LSB_FIRST ) return "GL_UNPACK_LSB_FIRST";
#endif
#ifdef GL_UNPACK_ROW_LENGTH
	if ( en == GL_UNPACK_ROW_LENGTH ) return "GL_UNPACK_ROW_LENGTH";
#endif
#ifdef GL_UNPACK_SKIP_ROWS
	if ( en == GL_UNPACK_SKIP_ROWS ) return "GL_UNPACK_SKIP_ROWS";
#endif
#ifdef GL_UNPACK_SKIP_PIXELS
	if ( en == GL_UNPACK_SKIP_PIXELS ) return "GL_UNPACK_SKIP_PIXELS";
#endif
#ifdef GL_UNPACK_ALIGNMENT
	if ( en == GL_UNPACK_ALIGNMENT ) return "GL_UNPACK_ALIGNMENT";
#endif
#ifdef GL_PACK_SWAP_BYTES
	if ( en == GL_PACK_SWAP_BYTES ) return "GL_PACK_SWAP_BYTES";
#endif
#ifdef GL_PACK_LSB_FIRST
	if ( en == GL_PACK_LSB_FIRST ) return "GL_PACK_LSB_FIRST";
#endif
#ifdef GL_PACK_ROW_LENGTH
	if ( en == GL_PACK_ROW_LENGTH ) return "GL_PACK_ROW_LENGTH";
#endif
#ifdef GL_PACK_SKIP_ROWS
	if ( en == GL_PACK_SKIP_ROWS ) return "GL_PACK_SKIP_ROWS";
#endif
#ifdef GL_PACK_SKIP_PIXELS
	if ( en == GL_PACK_SKIP_PIXELS ) return "GL_PACK_SKIP_PIXELS";
#endif
#ifdef GL_PACK_ALIGNMENT
	if ( en == GL_PACK_ALIGNMENT ) return "GL_PACK_ALIGNMENT";
#endif
#ifdef GL_MAP_COLOR
	if ( en == GL_MAP_COLOR ) return "GL_MAP_COLOR";
#endif
#ifdef GL_MAP_STENCIL
	if ( en == GL_MAP_STENCIL ) return "GL_MAP_STENCIL";
#endif
#ifdef GL_INDEX_SHIFT
	if ( en == GL_INDEX_SHIFT ) return "GL_INDEX_SHIFT";
#endif
#ifdef GL_INDEX_OFFSET
	if ( en == GL_INDEX_OFFSET ) return "GL_INDEX_OFFSET";
#endif
#ifdef GL_RED_SCALE
	if ( en == GL_RED_SCALE ) return "GL_RED_SCALE";
#endif
#ifdef GL_RED_BIAS
	if ( en == GL_RED_BIAS ) return "GL_RED_BIAS";
#endif
#ifdef GL_ZOOM_X
	if ( en == GL_ZOOM_X ) return "GL_ZOOM_X";
#endif
#ifdef GL_ZOOM_Y
	if ( en == GL_ZOOM_Y ) return "GL_ZOOM_Y";
#endif
#ifdef GL_GREEN_SCALE
	if ( en == GL_GREEN_SCALE ) return "GL_GREEN_SCALE";
#endif
#ifdef GL_GREEN_BIAS
	if ( en == GL_GREEN_BIAS ) return "GL_GREEN_BIAS";
#endif
#ifdef GL_BLUE_SCALE
	if ( en == GL_BLUE_SCALE ) return "GL_BLUE_SCALE";
#endif
#ifdef GL_BLUE_BIAS
	if ( en == GL_BLUE_BIAS ) return "GL_BLUE_BIAS";
#endif
#ifdef GL_ALPHA_SCALE
	if ( en == GL_ALPHA_SCALE ) return "GL_ALPHA_SCALE";
#endif
#ifdef GL_ALPHA_BIAS
	if ( en == GL_ALPHA_BIAS ) return "GL_ALPHA_BIAS";
#endif
#ifdef GL_DEPTH_SCALE
	if ( en == GL_DEPTH_SCALE ) return "GL_DEPTH_SCALE";
#endif
#ifdef GL_DEPTH_BIAS
	if ( en == GL_DEPTH_BIAS ) return "GL_DEPTH_BIAS";
#endif
#ifdef GL_MAX_EVAL_ORDER
	if ( en == GL_MAX_EVAL_ORDER ) return "GL_MAX_EVAL_ORDER";
#endif
#ifdef GL_MAX_LIGHTS
	if ( en == GL_MAX_LIGHTS ) return "GL_MAX_LIGHTS";
#endif
#ifdef GL_MAX_CLIP_PLANES
	if ( en == GL_MAX_CLIP_PLANES ) return "GL_MAX_CLIP_PLANES";
#endif
#ifdef GL_MAX_TEXTURE_SIZE
	if ( en == GL_MAX_TEXTURE_SIZE ) return "GL_MAX_TEXTURE_SIZE";
#endif
#ifdef GL_MAX_PIXEL_MAP_TABLE
	if ( en == GL_MAX_PIXEL_MAP_TABLE ) return "GL_MAX_PIXEL_MAP_TABLE";
#endif
#ifdef GL_MAX_ATTRIB_STACK_DEPTH
	if ( en == GL_MAX_ATTRIB_STACK_DEPTH ) return "GL_MAX_ATTRIB_STACK_DEPTH";
#endif
#ifdef GL_MAX_MODELVIEW_STACK_DEPTH
	if ( en == GL_MAX_MODELVIEW_STACK_DEPTH ) return "GL_MAX_MODELVIEW_STACK_DEPTH";
#endif
#ifdef GL_MAX_NAME_STACK_DEPTH
	if ( en == GL_MAX_NAME_STACK_DEPTH ) return "GL_MAX_NAME_STACK_DEPTH";
#endif
#ifdef GL_MAX_PROJECTION_STACK_DEPTH
	if ( en == GL_MAX_PROJECTION_STACK_DEPTH ) return "GL_MAX_PROJECTION_STACK_DEPTH";
#endif
#ifdef GL_MAX_TEXTURE_STACK_DEPTH
	if ( en == GL_MAX_TEXTURE_STACK_DEPTH ) return "GL_MAX_TEXTURE_STACK_DEPTH";
#endif
#ifdef GL_MAX_VIEWPORT_DIMS
	if ( en == GL_MAX_VIEWPORT_DIMS ) return "GL_MAX_VIEWPORT_DIMS";
#endif
#ifdef GL_MAX_CLIENT_ATTRIB_STACK_DEPTH
	if ( en == GL_MAX_CLIENT_ATTRIB_STACK_DEPTH ) return "GL_MAX_CLIENT_ATTRIB_STACK_DEPTH";
#endif
#ifdef GL_SUBPIXEL_BITS
	if ( en == GL_SUBPIXEL_BITS ) return "GL_SUBPIXEL_BITS";
#endif
#ifdef GL_INDEX_BITS
	if ( en == GL_INDEX_BITS ) return "GL_INDEX_BITS";
#endif
#ifdef GL_RED_BITS
	if ( en == GL_RED_BITS ) return "GL_RED_BITS";
#endif
#ifdef GL_GREEN_BITS
	if ( en == GL_GREEN_BITS ) return "GL_GREEN_BITS";
#endif
#ifdef GL_BLUE_BITS
	if ( en == GL_BLUE_BITS ) return "GL_BLUE_BITS";
#endif
#ifdef GL_ALPHA_BITS
	if ( en == GL_ALPHA_BITS ) return "GL_ALPHA_BITS";
#endif
#ifdef GL_DEPTH_BITS
	if ( en == GL_DEPTH_BITS ) return "GL_DEPTH_BITS";
#endif
#ifdef GL_STENCIL_BITS
	if ( en == GL_STENCIL_BITS ) return "GL_STENCIL_BITS";
#endif
#ifdef GL_ACCUM_RED_BITS
	if ( en == GL_ACCUM_RED_BITS ) return "GL_ACCUM_RED_BITS";
#endif
#ifdef GL_ACCUM_GREEN_BITS
	if ( en == GL_ACCUM_GREEN_BITS ) return "GL_ACCUM_GREEN_BITS";
#endif
#ifdef GL_ACCUM_BLUE_BITS
	if ( en == GL_ACCUM_BLUE_BITS ) return "GL_ACCUM_BLUE_BITS";
#endif
#ifdef GL_ACCUM_ALPHA_BITS
	if ( en == GL_ACCUM_ALPHA_BITS ) return "GL_ACCUM_ALPHA_BITS";
#endif
#ifdef GL_NAME_STACK_DEPTH
	if ( en == GL_NAME_STACK_DEPTH ) return "GL_NAME_STACK_DEPTH";
#endif
#ifdef GL_AUTO_NORMAL
	if ( en == GL_AUTO_NORMAL ) return "GL_AUTO_NORMAL";
#endif
#ifdef GL_MAP1_COLOR_4
	if ( en == GL_MAP1_COLOR_4 ) return "GL_MAP1_COLOR_4";
#endif
#ifdef GL_MAP1_INDEX
	if ( en == GL_MAP1_INDEX ) return "GL_MAP1_INDEX";
#endif
#ifdef GL_MAP1_NORMAL
	if ( en == GL_MAP1_NORMAL ) return "GL_MAP1_NORMAL";
#endif
#ifdef GL_MAP1_TEXTURE_COORD_1
	if ( en == GL_MAP1_TEXTURE_COORD_1 ) return "GL_MAP1_TEXTURE_COORD_1";
#endif
#ifdef GL_MAP1_TEXTURE_COORD_2
	if ( en == GL_MAP1_TEXTURE_COORD_2 ) return "GL_MAP1_TEXTURE_COORD_2";
#endif
#ifdef GL_MAP1_TEXTURE_COORD_3
	if ( en == GL_MAP1_TEXTURE_COORD_3 ) return "GL_MAP1_TEXTURE_COORD_3";
#endif
#ifdef GL_MAP1_TEXTURE_COORD_4
	if ( en == GL_MAP1_TEXTURE_COORD_4 ) return "GL_MAP1_TEXTURE_COORD_4";
#endif
#ifdef GL_MAP1_VERTEX_3
	if ( en == GL_MAP1_VERTEX_3 ) return "GL_MAP1_VERTEX_3";
#endif
#ifdef GL_MAP1_VERTEX_4
	if ( en == GL_MAP1_VERTEX_4 ) return "GL_MAP1_VERTEX_4";
#endif
#ifdef GL_MAP2_COLOR_4
	if ( en == GL_MAP2_COLOR_4 ) return "GL_MAP2_COLOR_4";
#endif
#ifdef GL_MAP2_INDEX
	if ( en == GL_MAP2_INDEX ) return "GL_MAP2_INDEX";
#endif
#ifdef GL_MAP2_NORMAL
	if ( en == GL_MAP2_NORMAL ) return "GL_MAP2_NORMAL";
#endif
#ifdef GL_MAP2_TEXTURE_COORD_1
	if ( en == GL_MAP2_TEXTURE_COORD_1 ) return "GL_MAP2_TEXTURE_COORD_1";
#endif
#ifdef GL_MAP2_TEXTURE_COORD_2
	if ( en == GL_MAP2_TEXTURE_COORD_2 ) return "GL_MAP2_TEXTURE_COORD_2";
#endif
#ifdef GL_MAP2_TEXTURE_COORD_3
	if ( en == GL_MAP2_TEXTURE_COORD_3 ) return "GL_MAP2_TEXTURE_COORD_3";
#endif
#ifdef GL_MAP2_TEXTURE_COORD_4
	if ( en == GL_MAP2_TEXTURE_COORD_4 ) return "GL_MAP2_TEXTURE_COORD_4";
#endif
#ifdef GL_MAP2_VERTEX_3
	if ( en == GL_MAP2_VERTEX_3 ) return "GL_MAP2_VERTEX_3";
#endif
#ifdef GL_MAP2_VERTEX_4
	if ( en == GL_MAP2_VERTEX_4 ) return "GL_MAP2_VERTEX_4";
#endif
#ifdef GL_MAP1_GRID_DOMAIN
	if ( en == GL_MAP1_GRID_DOMAIN ) return "GL_MAP1_GRID_DOMAIN";
#endif
#ifdef GL_MAP1_GRID_SEGMENTS
	if ( en == GL_MAP1_GRID_SEGMENTS ) return "GL_MAP1_GRID_SEGMENTS";
#endif
#ifdef GL_MAP2_GRID_DOMAIN
	if ( en == GL_MAP2_GRID_DOMAIN ) return "GL_MAP2_GRID_DOMAIN";
#endif
#ifdef GL_MAP2_GRID_SEGMENTS
	if ( en == GL_MAP2_GRID_SEGMENTS ) return "GL_MAP2_GRID_SEGMENTS";
#endif
#ifdef GL_TEXTURE_1D
	if ( en == GL_TEXTURE_1D ) return "GL_TEXTURE_1D";
#endif
#ifdef GL_TEXTURE_2D
	if ( en == GL_TEXTURE_2D ) return "GL_TEXTURE_2D";
#endif
#ifdef GL_FEEDBACK_BUFFER_POINTER
	if ( en == GL_FEEDBACK_BUFFER_POINTER ) return "GL_FEEDBACK_BUFFER_POINTER";
#endif
#ifdef GL_FEEDBACK_BUFFER_SIZE
	if ( en == GL_FEEDBACK_BUFFER_SIZE ) return "GL_FEEDBACK_BUFFER_SIZE";
#endif
#ifdef GL_FEEDBACK_BUFFER_TYPE
	if ( en == GL_FEEDBACK_BUFFER_TYPE ) return "GL_FEEDBACK_BUFFER_TYPE";
#endif
#ifdef GL_SELECTION_BUFFER_POINTER
	if ( en == GL_SELECTION_BUFFER_POINTER ) return "GL_SELECTION_BUFFER_POINTER";
#endif
#ifdef GL_SELECTION_BUFFER_SIZE
	if ( en == GL_SELECTION_BUFFER_SIZE ) return "GL_SELECTION_BUFFER_SIZE";
#endif
#ifdef GL_TEXTURE_WIDTH
	if ( en == GL_TEXTURE_WIDTH ) return "GL_TEXTURE_WIDTH";
#endif
#ifdef GL_TRANSFORM_BIT
	if ( en == GL_TRANSFORM_BIT ) return "GL_TRANSFORM_BIT";
#endif
#ifdef GL_TEXTURE_HEIGHT
	if ( en == GL_TEXTURE_HEIGHT ) return "GL_TEXTURE_HEIGHT";
#endif
#ifdef GL_TEXTURE_INTERNAL_FORMAT
	if ( en == GL_TEXTURE_INTERNAL_FORMAT ) return "GL_TEXTURE_INTERNAL_FORMAT";
#endif
#ifdef GL_TEXTURE_BORDER_COLOR
	if ( en == GL_TEXTURE_BORDER_COLOR ) return "GL_TEXTURE_BORDER_COLOR";
#endif
#ifdef GL_TEXTURE_BORDER
	if ( en == GL_TEXTURE_BORDER ) return "GL_TEXTURE_BORDER";
#endif
#ifdef GL_DONT_CARE
	if ( en == GL_DONT_CARE ) return "GL_DONT_CARE";
#endif
#ifdef GL_FASTEST
	if ( en == GL_FASTEST ) return "GL_FASTEST";
#endif
#ifdef GL_NICEST
	if ( en == GL_NICEST ) return "GL_NICEST";
#endif
#ifdef GL_AMBIENT
	if ( en == GL_AMBIENT ) return "GL_AMBIENT";
#endif
#ifdef GL_DIFFUSE
	if ( en == GL_DIFFUSE ) return "GL_DIFFUSE";
#endif
#ifdef GL_SPECULAR
	if ( en == GL_SPECULAR ) return "GL_SPECULAR";
#endif
#ifdef GL_POSITION
	if ( en == GL_POSITION ) return "GL_POSITION";
#endif
#ifdef GL_SPOT_DIRECTION
	if ( en == GL_SPOT_DIRECTION ) return "GL_SPOT_DIRECTION";
#endif
#ifdef GL_SPOT_EXPONENT
	if ( en == GL_SPOT_EXPONENT ) return "GL_SPOT_EXPONENT";
#endif
#ifdef GL_SPOT_CUTOFF
	if ( en == GL_SPOT_CUTOFF ) return "GL_SPOT_CUTOFF";
#endif
#ifdef GL_CONSTANT_ATTENUATION
	if ( en == GL_CONSTANT_ATTENUATION ) return "GL_CONSTANT_ATTENUATION";
#endif
#ifdef GL_LINEAR_ATTENUATION
	if ( en == GL_LINEAR_ATTENUATION ) return "GL_LINEAR_ATTENUATION";
#endif
#ifdef GL_QUADRATIC_ATTENUATION
	if ( en == GL_QUADRATIC_ATTENUATION ) return "GL_QUADRATIC_ATTENUATION";
#endif
#ifdef GL_COMPILE
	if ( en == GL_COMPILE ) return "GL_COMPILE";
#endif
#ifdef GL_COMPILE_AND_EXECUTE
	if ( en == GL_COMPILE_AND_EXECUTE ) return "GL_COMPILE_AND_EXECUTE";
#endif
#ifdef GL_BYTE
	if ( en == GL_BYTE ) return "GL_BYTE";
#endif
#ifdef GL_UNSIGNED_BYTE
	if ( en == GL_UNSIGNED_BYTE ) return "GL_UNSIGNED_BYTE";
#endif
#ifdef GL_SHORT
	if ( en == GL_SHORT ) return "GL_SHORT";
#endif
#ifdef GL_UNSIGNED_SHORT
	if ( en == GL_UNSIGNED_SHORT ) return "GL_UNSIGNED_SHORT";
#endif
#ifdef GL_INT
	if ( en == GL_INT ) return "GL_INT";
#endif
#ifdef GL_UNSIGNED_INT
	if ( en == GL_UNSIGNED_INT ) return "GL_UNSIGNED_INT";
#endif
#ifdef GL_FLOAT
	if ( en == GL_FLOAT ) return "GL_FLOAT";
#endif
#ifdef GL_2_BYTES
	if ( en == GL_2_BYTES ) return "GL_2_BYTES";
#endif
#ifdef GL_3_BYTES
	if ( en == GL_3_BYTES ) return "GL_3_BYTES";
#endif
#ifdef GL_4_BYTES
	if ( en == GL_4_BYTES ) return "GL_4_BYTES";
#endif
#ifdef GL_DOUBLE
	if ( en == GL_DOUBLE ) return "GL_DOUBLE";
#endif
#ifdef GL_CLEAR
	if ( en == GL_CLEAR ) return "GL_CLEAR";
#endif
#ifdef GL_AND
	if ( en == GL_AND ) return "GL_AND";
#endif
#ifdef GL_AND_REVERSE
	if ( en == GL_AND_REVERSE ) return "GL_AND_REVERSE";
#endif
#ifdef GL_COPY
	if ( en == GL_COPY ) return "GL_COPY";
#endif
#ifdef GL_AND_INVERTED
	if ( en == GL_AND_INVERTED ) return "GL_AND_INVERTED";
#endif
#ifdef GL_NOOP
	if ( en == GL_NOOP ) return "GL_NOOP";
#endif
#ifdef GL_XOR
	if ( en == GL_XOR ) return "GL_XOR";
#endif
#ifdef GL_OR
	if ( en == GL_OR ) return "GL_OR";
#endif
#ifdef GL_NOR
	if ( en == GL_NOR ) return "GL_NOR";
#endif
#ifdef GL_EQUIV
	if ( en == GL_EQUIV ) return "GL_EQUIV";
#endif
#ifdef GL_INVERT
	if ( en == GL_INVERT ) return "GL_INVERT";
#endif
#ifdef GL_OR_REVERSE
	if ( en == GL_OR_REVERSE ) return "GL_OR_REVERSE";
#endif
#ifdef GL_COPY_INVERTED
	if ( en == GL_COPY_INVERTED ) return "GL_COPY_INVERTED";
#endif
#ifdef GL_OR_INVERTED
	if ( en == GL_OR_INVERTED ) return "GL_OR_INVERTED";
#endif
#ifdef GL_NAND
	if ( en == GL_NAND ) return "GL_NAND";
#endif
#ifdef GL_SET
	if ( en == GL_SET ) return "GL_SET";
#endif
#ifdef GL_EMISSION
	if ( en == GL_EMISSION ) return "GL_EMISSION";
#endif
#ifdef GL_SHININESS
	if ( en == GL_SHININESS ) return "GL_SHININESS";
#endif
#ifdef GL_AMBIENT_AND_DIFFUSE
	if ( en == GL_AMBIENT_AND_DIFFUSE ) return "GL_AMBIENT_AND_DIFFUSE";
#endif
#ifdef GL_COLOR_INDEXES
	if ( en == GL_COLOR_INDEXES ) return "GL_COLOR_INDEXES";
#endif
#ifdef GL_MODELVIEW
	if ( en == GL_MODELVIEW ) return "GL_MODELVIEW";
#endif
#ifdef GL_PROJECTION
	if ( en == GL_PROJECTION ) return "GL_PROJECTION";
#endif
#ifdef GL_TEXTURE
	if ( en == GL_TEXTURE ) return "GL_TEXTURE";
#endif
#ifdef GL_COLOR
	if ( en == GL_COLOR ) return "GL_COLOR";
#endif
#ifdef GL_DEPTH
	if ( en == GL_DEPTH ) return "GL_DEPTH";
#endif
#ifdef GL_STENCIL
	if ( en == GL_STENCIL ) return "GL_STENCIL";
#endif
#ifdef GL_COLOR_INDEX
	if ( en == GL_COLOR_INDEX ) return "GL_COLOR_INDEX";
#endif
#ifdef GL_STENCIL_INDEX
	if ( en == GL_STENCIL_INDEX ) return "GL_STENCIL_INDEX";
#endif
#ifdef GL_DEPTH_COMPONENT
	if ( en == GL_DEPTH_COMPONENT ) return "GL_DEPTH_COMPONENT";
#endif
#ifdef GL_RED
	if ( en == GL_RED ) return "GL_RED";
#endif
#ifdef GL_GREEN
	if ( en == GL_GREEN ) return "GL_GREEN";
#endif
#ifdef GL_BLUE
	if ( en == GL_BLUE ) return "GL_BLUE";
#endif
#ifdef GL_ALPHA
	if ( en == GL_ALPHA ) return "GL_ALPHA";
#endif
#ifdef GL_RGB
	if ( en == GL_RGB ) return "GL_RGB";
#endif
#ifdef GL_RGBA
	if ( en == GL_RGBA ) return "GL_RGBA";
#endif
#ifdef GL_LUMINANCE
	if ( en == GL_LUMINANCE ) return "GL_LUMINANCE";
#endif
#ifdef GL_LUMINANCE_ALPHA
	if ( en == GL_LUMINANCE_ALPHA ) return "GL_LUMINANCE_ALPHA";
#endif
#ifdef GL_BITMAP
	if ( en == GL_BITMAP ) return "GL_BITMAP";
#endif
#ifdef GL_POINT
	if ( en == GL_POINT ) return "GL_POINT";
#endif
#ifdef GL_LINE
	if ( en == GL_LINE ) return "GL_LINE";
#endif
#ifdef GL_FILL
	if ( en == GL_FILL ) return "GL_FILL";
#endif
#ifdef GL_RENDER
	if ( en == GL_RENDER ) return "GL_RENDER";
#endif
#ifdef GL_FEEDBACK
	if ( en == GL_FEEDBACK ) return "GL_FEEDBACK";
#endif
#ifdef GL_SELECT
	if ( en == GL_SELECT ) return "GL_SELECT";
#endif
#ifdef GL_FLAT
	if ( en == GL_FLAT ) return "GL_FLAT";
#endif
#ifdef GL_SMOOTH
	if ( en == GL_SMOOTH ) return "GL_SMOOTH";
#endif
#ifdef GL_KEEP
	if ( en == GL_KEEP ) return "GL_KEEP";
#endif
#ifdef GL_REPLACE
	if ( en == GL_REPLACE ) return "GL_REPLACE";
#endif
#ifdef GL_INCR
	if ( en == GL_INCR ) return "GL_INCR";
#endif
#ifdef GL_DECR
	if ( en == GL_DECR ) return "GL_DECR";
#endif
#ifdef GL_VENDOR
	if ( en == GL_VENDOR ) return "GL_VENDOR";
#endif
#ifdef GL_RENDERER
	if ( en == GL_RENDERER ) return "GL_RENDERER";
#endif
#ifdef GL_VERSION
	if ( en == GL_VERSION ) return "GL_VERSION";
#endif
#ifdef GL_EXTENSIONS
	if ( en == GL_EXTENSIONS ) return "GL_EXTENSIONS";
#endif
#ifdef GL_S
	if ( en == GL_S ) return "GL_S";
#endif
#ifdef GL_ENABLE_BIT
	if ( en == GL_ENABLE_BIT ) return "GL_ENABLE_BIT";
#endif
#ifdef GL_T
	if ( en == GL_T ) return "GL_T";
#endif
#ifdef GL_R
	if ( en == GL_R ) return "GL_R";
#endif
#ifdef GL_Q
	if ( en == GL_Q ) return "GL_Q";
#endif
#ifdef GL_MODULATE
	if ( en == GL_MODULATE ) return "GL_MODULATE";
#endif
#ifdef GL_DECAL
	if ( en == GL_DECAL ) return "GL_DECAL";
#endif
#ifdef GL_TEXTURE_ENV_MODE
	if ( en == GL_TEXTURE_ENV_MODE ) return "GL_TEXTURE_ENV_MODE";
#endif
#ifdef GL_TEXTURE_ENV_COLOR
	if ( en == GL_TEXTURE_ENV_COLOR ) return "GL_TEXTURE_ENV_COLOR";
#endif
#ifdef GL_TEXTURE_ENV
	if ( en == GL_TEXTURE_ENV ) return "GL_TEXTURE_ENV";
#endif
#ifdef GL_EYE_LINEAR
	if ( en == GL_EYE_LINEAR ) return "GL_EYE_LINEAR";
#endif
#ifdef GL_OBJECT_LINEAR
	if ( en == GL_OBJECT_LINEAR ) return "GL_OBJECT_LINEAR";
#endif
#ifdef GL_SPHERE_MAP
	if ( en == GL_SPHERE_MAP ) return "GL_SPHERE_MAP";
#endif
#ifdef GL_TEXTURE_GEN_MODE
	if ( en == GL_TEXTURE_GEN_MODE ) return "GL_TEXTURE_GEN_MODE";
#endif
#ifdef GL_OBJECT_PLANE
	if ( en == GL_OBJECT_PLANE ) return "GL_OBJECT_PLANE";
#endif
#ifdef GL_EYE_PLANE
	if ( en == GL_EYE_PLANE ) return "GL_EYE_PLANE";
#endif
#ifdef GL_NEAREST
	if ( en == GL_NEAREST ) return "GL_NEAREST";
#endif
#ifdef GL_LINEAR
	if ( en == GL_LINEAR ) return "GL_LINEAR";
#endif
#ifdef GL_NEAREST_MIPMAP_NEAREST
	if ( en == GL_NEAREST_MIPMAP_NEAREST ) return "GL_NEAREST_MIPMAP_NEAREST";
#endif
#ifdef GL_LINEAR_MIPMAP_NEAREST
	if ( en == GL_LINEAR_MIPMAP_NEAREST ) return "GL_LINEAR_MIPMAP_NEAREST";
#endif
#ifdef GL_NEAREST_MIPMAP_LINEAR
	if ( en == GL_NEAREST_MIPMAP_LINEAR ) return "GL_NEAREST_MIPMAP_LINEAR";
#endif
#ifdef GL_LINEAR_MIPMAP_LINEAR
	if ( en == GL_LINEAR_MIPMAP_LINEAR ) return "GL_LINEAR_MIPMAP_LINEAR";
#endif
#ifdef GL_TEXTURE_MAG_FILTER
	if ( en == GL_TEXTURE_MAG_FILTER ) return "GL_TEXTURE_MAG_FILTER";
#endif
#ifdef GL_TEXTURE_MIN_FILTER
	if ( en == GL_TEXTURE_MIN_FILTER ) return "GL_TEXTURE_MIN_FILTER";
#endif
#ifdef GL_TEXTURE_WRAP_S
	if ( en == GL_TEXTURE_WRAP_S ) return "GL_TEXTURE_WRAP_S";
#endif
#ifdef GL_TEXTURE_WRAP_T
	if ( en == GL_TEXTURE_WRAP_T ) return "GL_TEXTURE_WRAP_T";
#endif
#ifdef GL_CLAMP
	if ( en == GL_CLAMP ) return "GL_CLAMP";
#endif
#ifdef GL_REPEAT
	if ( en == GL_REPEAT ) return "GL_REPEAT";
#endif
#ifdef GL_POLYGON_OFFSET_UNITS
	if ( en == GL_POLYGON_OFFSET_UNITS ) return "GL_POLYGON_OFFSET_UNITS";
#endif
#ifdef GL_POLYGON_OFFSET_POINT
	if ( en == GL_POLYGON_OFFSET_POINT ) return "GL_POLYGON_OFFSET_POINT";
#endif
#ifdef GL_POLYGON_OFFSET_LINE
	if ( en == GL_POLYGON_OFFSET_LINE ) return "GL_POLYGON_OFFSET_LINE";
#endif
#ifdef GL_R3_G3_B2
	if ( en == GL_R3_G3_B2 ) return "GL_R3_G3_B2";
#endif
#ifdef GL_V2F
	if ( en == GL_V2F ) return "GL_V2F";
#endif
#ifdef GL_V3F
	if ( en == GL_V3F ) return "GL_V3F";
#endif
#ifdef GL_C4UB_V2F
	if ( en == GL_C4UB_V2F ) return "GL_C4UB_V2F";
#endif
#ifdef GL_C4UB_V3F
	if ( en == GL_C4UB_V3F ) return "GL_C4UB_V3F";
#endif
#ifdef GL_C3F_V3F
	if ( en == GL_C3F_V3F ) return "GL_C3F_V3F";
#endif
#ifdef GL_N3F_V3F
	if ( en == GL_N3F_V3F ) return "GL_N3F_V3F";
#endif
#ifdef GL_C4F_N3F_V3F
	if ( en == GL_C4F_N3F_V3F ) return "GL_C4F_N3F_V3F";
#endif
#ifdef GL_T2F_V3F
	if ( en == GL_T2F_V3F ) return "GL_T2F_V3F";
#endif
#ifdef GL_T4F_V4F
	if ( en == GL_T4F_V4F ) return "GL_T4F_V4F";
#endif
#ifdef GL_T2F_C4UB_V3F
	if ( en == GL_T2F_C4UB_V3F ) return "GL_T2F_C4UB_V3F";
#endif
#ifdef GL_T2F_C3F_V3F
	if ( en == GL_T2F_C3F_V3F ) return "GL_T2F_C3F_V3F";
#endif
#ifdef GL_T2F_N3F_V3F
	if ( en == GL_T2F_N3F_V3F ) return "GL_T2F_N3F_V3F";
#endif
#ifdef GL_T2F_C4F_N3F_V3F
	if ( en == GL_T2F_C4F_N3F_V3F ) return "GL_T2F_C4F_N3F_V3F";
#endif
#ifdef GL_T4F_C4F_N3F_V4F
	if ( en == GL_T4F_C4F_N3F_V4F ) return "GL_T4F_C4F_N3F_V4F";
#endif
#ifdef GL_CLIP_PLANE0
	if ( en == GL_CLIP_PLANE0 ) return "GL_CLIP_PLANE0";
#endif
#ifdef GL_CLIP_PLANE1
	if ( en == GL_CLIP_PLANE1 ) return "GL_CLIP_PLANE1";
#endif
#ifdef GL_CLIP_PLANE2
	if ( en == GL_CLIP_PLANE2 ) return "GL_CLIP_PLANE2";
#endif
#ifdef GL_CLIP_PLANE3
	if ( en == GL_CLIP_PLANE3 ) return "GL_CLIP_PLANE3";
#endif
#ifdef GL_CLIP_PLANE4
	if ( en == GL_CLIP_PLANE4 ) return "GL_CLIP_PLANE4";
#endif
#ifdef GL_CLIP_PLANE5
	if ( en == GL_CLIP_PLANE5 ) return "GL_CLIP_PLANE5";
#endif
#ifdef GL_LIGHT0
	if ( en == GL_LIGHT0 ) return "GL_LIGHT0";
#endif
#ifdef GL_COLOR_BUFFER_BIT
	if ( en == GL_COLOR_BUFFER_BIT ) return "GL_COLOR_BUFFER_BIT";
#endif
#ifdef GL_LIGHT1
	if ( en == GL_LIGHT1 ) return "GL_LIGHT1";
#endif
#ifdef GL_LIGHT2
	if ( en == GL_LIGHT2 ) return "GL_LIGHT2";
#endif
#ifdef GL_LIGHT3
	if ( en == GL_LIGHT3 ) return "GL_LIGHT3";
#endif
#ifdef GL_LIGHT4
	if ( en == GL_LIGHT4 ) return "GL_LIGHT4";
#endif
#ifdef GL_LIGHT5
	if ( en == GL_LIGHT5 ) return "GL_LIGHT5";
#endif
#ifdef GL_LIGHT6
	if ( en == GL_LIGHT6 ) return "GL_LIGHT6";
#endif
#ifdef GL_LIGHT7
	if ( en == GL_LIGHT7 ) return "GL_LIGHT7";
#endif
#ifdef GL_HINT_BIT
	if ( en == GL_HINT_BIT ) return "GL_HINT_BIT";
#endif
#ifdef GL_POLYGON_OFFSET_FILL
	if ( en == GL_POLYGON_OFFSET_FILL ) return "GL_POLYGON_OFFSET_FILL";
#endif
#ifdef GL_POLYGON_OFFSET_FACTOR
	if ( en == GL_POLYGON_OFFSET_FACTOR ) return "GL_POLYGON_OFFSET_FACTOR";
#endif
#ifdef GL_ALPHA4
	if ( en == GL_ALPHA4 ) return "GL_ALPHA4";
#endif
#ifdef GL_ALPHA8
	if ( en == GL_ALPHA8 ) return "GL_ALPHA8";
#endif
#ifdef GL_ALPHA12
	if ( en == GL_ALPHA12 ) return "GL_ALPHA12";
#endif
#ifdef GL_ALPHA16
	if ( en == GL_ALPHA16 ) return "GL_ALPHA16";
#endif
#ifdef GL_LUMINANCE4
	if ( en == GL_LUMINANCE4 ) return "GL_LUMINANCE4";
#endif
#ifdef GL_LUMINANCE8
	if ( en == GL_LUMINANCE8 ) return "GL_LUMINANCE8";
#endif
#ifdef GL_LUMINANCE12
	if ( en == GL_LUMINANCE12 ) return "GL_LUMINANCE12";
#endif
#ifdef GL_LUMINANCE16
	if ( en == GL_LUMINANCE16 ) return "GL_LUMINANCE16";
#endif
#ifdef GL_LUMINANCE4_ALPHA4
	if ( en == GL_LUMINANCE4_ALPHA4 ) return "GL_LUMINANCE4_ALPHA4";
#endif
#ifdef GL_LUMINANCE6_ALPHA2
	if ( en == GL_LUMINANCE6_ALPHA2 ) return "GL_LUMINANCE6_ALPHA2";
#endif
#ifdef GL_LUMINANCE8_ALPHA8
	if ( en == GL_LUMINANCE8_ALPHA8 ) return "GL_LUMINANCE8_ALPHA8";
#endif
#ifdef GL_LUMINANCE12_ALPHA4
	if ( en == GL_LUMINANCE12_ALPHA4 ) return "GL_LUMINANCE12_ALPHA4";
#endif
#ifdef GL_LUMINANCE12_ALPHA12
	if ( en == GL_LUMINANCE12_ALPHA12 ) return "GL_LUMINANCE12_ALPHA12";
#endif
#ifdef GL_LUMINANCE16_ALPHA16
	if ( en == GL_LUMINANCE16_ALPHA16 ) return "GL_LUMINANCE16_ALPHA16";
#endif
#ifdef GL_INTENSITY
	if ( en == GL_INTENSITY ) return "GL_INTENSITY";
#endif
#ifdef GL_INTENSITY4
	if ( en == GL_INTENSITY4 ) return "GL_INTENSITY4";
#endif
#ifdef GL_INTENSITY8
	if ( en == GL_INTENSITY8 ) return "GL_INTENSITY8";
#endif
#ifdef GL_INTENSITY12
	if ( en == GL_INTENSITY12 ) return "GL_INTENSITY12";
#endif
#ifdef GL_INTENSITY16
	if ( en == GL_INTENSITY16 ) return "GL_INTENSITY16";
#endif
#ifdef GL_RGB4
	if ( en == GL_RGB4 ) return "GL_RGB4";
#endif
#ifdef GL_RGB5
	if ( en == GL_RGB5 ) return "GL_RGB5";
#endif
#ifdef GL_RGB8
	if ( en == GL_RGB8 ) return "GL_RGB8";
#endif
#ifdef GL_RGB10
	if ( en == GL_RGB10 ) return "GL_RGB10";
#endif
#ifdef GL_RGB12
	if ( en == GL_RGB12 ) return "GL_RGB12";
#endif
#ifdef GL_RGB16
	if ( en == GL_RGB16 ) return "GL_RGB16";
#endif
#ifdef GL_RGBA2
	if ( en == GL_RGBA2 ) return "GL_RGBA2";
#endif
#ifdef GL_RGBA4
	if ( en == GL_RGBA4 ) return "GL_RGBA4";
#endif
#ifdef GL_RGB5_A1
	if ( en == GL_RGB5_A1 ) return "GL_RGB5_A1";
#endif
#ifdef GL_RGBA8
	if ( en == GL_RGBA8 ) return "GL_RGBA8";
#endif
#ifdef GL_RGB10_A2
	if ( en == GL_RGB10_A2 ) return "GL_RGB10_A2";
#endif
#ifdef GL_RGBA12
	if ( en == GL_RGBA12 ) return "GL_RGBA12";
#endif
#ifdef GL_RGBA16
	if ( en == GL_RGBA16 ) return "GL_RGBA16";
#endif
#ifdef GL_TEXTURE_RED_SIZE
	if ( en == GL_TEXTURE_RED_SIZE ) return "GL_TEXTURE_RED_SIZE";
#endif
#ifdef GL_TEXTURE_GREEN_SIZE
	if ( en == GL_TEXTURE_GREEN_SIZE ) return "GL_TEXTURE_GREEN_SIZE";
#endif
#ifdef GL_TEXTURE_BLUE_SIZE
	if ( en == GL_TEXTURE_BLUE_SIZE ) return "GL_TEXTURE_BLUE_SIZE";
#endif
#ifdef GL_TEXTURE_ALPHA_SIZE
	if ( en == GL_TEXTURE_ALPHA_SIZE ) return "GL_TEXTURE_ALPHA_SIZE";
#endif
#ifdef GL_TEXTURE_LUMINANCE_SIZE
	if ( en == GL_TEXTURE_LUMINANCE_SIZE ) return "GL_TEXTURE_LUMINANCE_SIZE";
#endif
#ifdef GL_TEXTURE_INTENSITY_SIZE
	if ( en == GL_TEXTURE_INTENSITY_SIZE ) return "GL_TEXTURE_INTENSITY_SIZE";
#endif
#ifdef GL_PROXY_TEXTURE_1D
	if ( en == GL_PROXY_TEXTURE_1D ) return "GL_PROXY_TEXTURE_1D";
#endif
#ifdef GL_PROXY_TEXTURE_2D
	if ( en == GL_PROXY_TEXTURE_2D ) return "GL_PROXY_TEXTURE_2D";
#endif
#ifdef GL_TEXTURE_PRIORITY
	if ( en == GL_TEXTURE_PRIORITY ) return "GL_TEXTURE_PRIORITY";
#endif
#ifdef GL_TEXTURE_RESIDENT
	if ( en == GL_TEXTURE_RESIDENT ) return "GL_TEXTURE_RESIDENT";
#endif
#ifdef GL_TEXTURE_BINDING_1D
	if ( en == GL_TEXTURE_BINDING_1D ) return "GL_TEXTURE_BINDING_1D";
#endif
#ifdef GL_TEXTURE_BINDING_2D
	if ( en == GL_TEXTURE_BINDING_2D ) return "GL_TEXTURE_BINDING_2D";
#endif
#ifdef GL_VERTEX_ARRAY
	if ( en == GL_VERTEX_ARRAY ) return "GL_VERTEX_ARRAY";
#endif
#ifdef GL_NORMAL_ARRAY
	if ( en == GL_NORMAL_ARRAY ) return "GL_NORMAL_ARRAY";
#endif
#ifdef GL_COLOR_ARRAY
	if ( en == GL_COLOR_ARRAY ) return "GL_COLOR_ARRAY";
#endif
#ifdef GL_INDEX_ARRAY
	if ( en == GL_INDEX_ARRAY ) return "GL_INDEX_ARRAY";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY
	if ( en == GL_TEXTURE_COORD_ARRAY ) return "GL_TEXTURE_COORD_ARRAY";
#endif
#ifdef GL_EDGE_FLAG_ARRAY
	if ( en == GL_EDGE_FLAG_ARRAY ) return "GL_EDGE_FLAG_ARRAY";
#endif
#ifdef GL_VERTEX_ARRAY_SIZE
	if ( en == GL_VERTEX_ARRAY_SIZE ) return "GL_VERTEX_ARRAY_SIZE";
#endif
#ifdef GL_VERTEX_ARRAY_TYPE
	if ( en == GL_VERTEX_ARRAY_TYPE ) return "GL_VERTEX_ARRAY_TYPE";
#endif
#ifdef GL_VERTEX_ARRAY_STRIDE
	if ( en == GL_VERTEX_ARRAY_STRIDE ) return "GL_VERTEX_ARRAY_STRIDE";
#endif
#ifdef GL_NORMAL_ARRAY_TYPE
	if ( en == GL_NORMAL_ARRAY_TYPE ) return "GL_NORMAL_ARRAY_TYPE";
#endif
#ifdef GL_NORMAL_ARRAY_STRIDE
	if ( en == GL_NORMAL_ARRAY_STRIDE ) return "GL_NORMAL_ARRAY_STRIDE";
#endif
#ifdef GL_COLOR_ARRAY_SIZE
	if ( en == GL_COLOR_ARRAY_SIZE ) return "GL_COLOR_ARRAY_SIZE";
#endif
#ifdef GL_COLOR_ARRAY_TYPE
	if ( en == GL_COLOR_ARRAY_TYPE ) return "GL_COLOR_ARRAY_TYPE";
#endif
#ifdef GL_COLOR_ARRAY_STRIDE
	if ( en == GL_COLOR_ARRAY_STRIDE ) return "GL_COLOR_ARRAY_STRIDE";
#endif
#ifdef GL_INDEX_ARRAY_TYPE
	if ( en == GL_INDEX_ARRAY_TYPE ) return "GL_INDEX_ARRAY_TYPE";
#endif
#ifdef GL_INDEX_ARRAY_STRIDE
	if ( en == GL_INDEX_ARRAY_STRIDE ) return "GL_INDEX_ARRAY_STRIDE";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_SIZE
	if ( en == GL_TEXTURE_COORD_ARRAY_SIZE ) return "GL_TEXTURE_COORD_ARRAY_SIZE";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_TYPE
	if ( en == GL_TEXTURE_COORD_ARRAY_TYPE ) return "GL_TEXTURE_COORD_ARRAY_TYPE";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_STRIDE
	if ( en == GL_TEXTURE_COORD_ARRAY_STRIDE ) return "GL_TEXTURE_COORD_ARRAY_STRIDE";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_STRIDE
	if ( en == GL_EDGE_FLAG_ARRAY_STRIDE ) return "GL_EDGE_FLAG_ARRAY_STRIDE";
#endif
#ifdef GL_VERTEX_ARRAY_POINTER
	if ( en == GL_VERTEX_ARRAY_POINTER ) return "GL_VERTEX_ARRAY_POINTER";
#endif
#ifdef GL_NORMAL_ARRAY_POINTER
	if ( en == GL_NORMAL_ARRAY_POINTER ) return "GL_NORMAL_ARRAY_POINTER";
#endif
#ifdef GL_COLOR_ARRAY_POINTER
	if ( en == GL_COLOR_ARRAY_POINTER ) return "GL_COLOR_ARRAY_POINTER";
#endif
#ifdef GL_INDEX_ARRAY_POINTER
	if ( en == GL_INDEX_ARRAY_POINTER ) return "GL_INDEX_ARRAY_POINTER";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_POINTER
	if ( en == GL_TEXTURE_COORD_ARRAY_POINTER ) return "GL_TEXTURE_COORD_ARRAY_POINTER";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_POINTER
	if ( en == GL_EDGE_FLAG_ARRAY_POINTER ) return "GL_EDGE_FLAG_ARRAY_POINTER";
#endif
#ifdef GL_COLOR_INDEX1_EXT
	if ( en == GL_COLOR_INDEX1_EXT ) return "GL_COLOR_INDEX1_EXT";
#endif
#ifdef GL_COLOR_INDEX2_EXT
	if ( en == GL_COLOR_INDEX2_EXT ) return "GL_COLOR_INDEX2_EXT";
#endif
#ifdef GL_COLOR_INDEX4_EXT
	if ( en == GL_COLOR_INDEX4_EXT ) return "GL_COLOR_INDEX4_EXT";
#endif
#ifdef GL_COLOR_INDEX8_EXT
	if ( en == GL_COLOR_INDEX8_EXT ) return "GL_COLOR_INDEX8_EXT";
#endif
#ifdef GL_COLOR_INDEX12_EXT
	if ( en == GL_COLOR_INDEX12_EXT ) return "GL_COLOR_INDEX12_EXT";
#endif
#ifdef GL_COLOR_INDEX16_EXT
	if ( en == GL_COLOR_INDEX16_EXT ) return "GL_COLOR_INDEX16_EXT";
#endif
#ifdef GL_EVAL_BIT
	if ( en == GL_EVAL_BIT ) return "GL_EVAL_BIT";
#endif
#ifdef GL_LIST_BIT
	if ( en == GL_LIST_BIT ) return "GL_LIST_BIT";
#endif
#ifdef GL_TEXTURE_BIT
	if ( en == GL_TEXTURE_BIT ) return "GL_TEXTURE_BIT";
#endif
#ifdef GL_SCISSOR_BIT
	if ( en == GL_SCISSOR_BIT ) return "GL_SCISSOR_BIT";
#endif
#ifdef GL_ALL_ATTRIB_BITS
	if ( en == GL_ALL_ATTRIB_BITS ) return "GL_ALL_ATTRIB_BITS";
#endif
#ifdef GL_CLIENT_ALL_ATTRIB_BITS
	if ( en == GL_CLIENT_ALL_ATTRIB_BITS ) return "GL_CLIENT_ALL_ATTRIB_BITS";
#endif
#ifdef GL_SMOOTH_POINT_SIZE_RANGE
	if ( en == GL_SMOOTH_POINT_SIZE_RANGE ) return "GL_SMOOTH_POINT_SIZE_RANGE";
#endif
#ifdef GL_SMOOTH_POINT_SIZE_GRANULARITY
	if ( en == GL_SMOOTH_POINT_SIZE_GRANULARITY ) return "GL_SMOOTH_POINT_SIZE_GRANULARITY";
#endif
#ifdef GL_SMOOTH_LINE_WIDTH_RANGE
	if ( en == GL_SMOOTH_LINE_WIDTH_RANGE ) return "GL_SMOOTH_LINE_WIDTH_RANGE";
#endif
#ifdef GL_SMOOTH_LINE_WIDTH_GRANULARITY
	if ( en == GL_SMOOTH_LINE_WIDTH_GRANULARITY ) return "GL_SMOOTH_LINE_WIDTH_GRANULARITY";
#endif
#ifdef GL_UNSIGNED_BYTE_3_3_2
	if ( en == GL_UNSIGNED_BYTE_3_3_2 ) return "GL_UNSIGNED_BYTE_3_3_2";
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4
	if ( en == GL_UNSIGNED_SHORT_4_4_4_4 ) return "GL_UNSIGNED_SHORT_4_4_4_4";
#endif
#ifdef GL_UNSIGNED_SHORT_5_5_5_1
	if ( en == GL_UNSIGNED_SHORT_5_5_5_1 ) return "GL_UNSIGNED_SHORT_5_5_5_1";
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8
	if ( en == GL_UNSIGNED_INT_8_8_8_8 ) return "GL_UNSIGNED_INT_8_8_8_8";
#endif
#ifdef GL_UNSIGNED_INT_10_10_10_2
	if ( en == GL_UNSIGNED_INT_10_10_10_2 ) return "GL_UNSIGNED_INT_10_10_10_2";
#endif
#ifdef GL_RESCALE_NORMAL
	if ( en == GL_RESCALE_NORMAL ) return "GL_RESCALE_NORMAL";
#endif
#ifdef GL_TEXTURE_BINDING_3D
	if ( en == GL_TEXTURE_BINDING_3D ) return "GL_TEXTURE_BINDING_3D";
#endif
#ifdef GL_PACK_SKIP_IMAGES
	if ( en == GL_PACK_SKIP_IMAGES ) return "GL_PACK_SKIP_IMAGES";
#endif
#ifdef GL_PACK_IMAGE_HEIGHT
	if ( en == GL_PACK_IMAGE_HEIGHT ) return "GL_PACK_IMAGE_HEIGHT";
#endif
#ifdef GL_UNPACK_SKIP_IMAGES
	if ( en == GL_UNPACK_SKIP_IMAGES ) return "GL_UNPACK_SKIP_IMAGES";
#endif
#ifdef GL_UNPACK_IMAGE_HEIGHT
	if ( en == GL_UNPACK_IMAGE_HEIGHT ) return "GL_UNPACK_IMAGE_HEIGHT";
#endif
#ifdef GL_TEXTURE_3D
	if ( en == GL_TEXTURE_3D ) return "GL_TEXTURE_3D";
#endif
#ifdef GL_PROXY_TEXTURE_3D
	if ( en == GL_PROXY_TEXTURE_3D ) return "GL_PROXY_TEXTURE_3D";
#endif
#ifdef GL_TEXTURE_DEPTH
	if ( en == GL_TEXTURE_DEPTH ) return "GL_TEXTURE_DEPTH";
#endif
#ifdef GL_TEXTURE_WRAP_R
	if ( en == GL_TEXTURE_WRAP_R ) return "GL_TEXTURE_WRAP_R";
#endif
#ifdef GL_MAX_3D_TEXTURE_SIZE
	if ( en == GL_MAX_3D_TEXTURE_SIZE ) return "GL_MAX_3D_TEXTURE_SIZE";
#endif
#ifdef GL_BGR
	if ( en == GL_BGR ) return "GL_BGR";
#endif
#ifdef GL_BGRA
	if ( en == GL_BGRA ) return "GL_BGRA";
#endif
#ifdef GL_MAX_ELEMENTS_VERTICES
	if ( en == GL_MAX_ELEMENTS_VERTICES ) return "GL_MAX_ELEMENTS_VERTICES";
#endif
#ifdef GL_MAX_ELEMENTS_INDICES
	if ( en == GL_MAX_ELEMENTS_INDICES ) return "GL_MAX_ELEMENTS_INDICES";
#endif
#ifdef GL_CLAMP_TO_EDGE
	if ( en == GL_CLAMP_TO_EDGE ) return "GL_CLAMP_TO_EDGE";
#endif
#ifdef GL_TEXTURE_MIN_LOD
	if ( en == GL_TEXTURE_MIN_LOD ) return "GL_TEXTURE_MIN_LOD";
#endif
#ifdef GL_TEXTURE_MAX_LOD
	if ( en == GL_TEXTURE_MAX_LOD ) return "GL_TEXTURE_MAX_LOD";
#endif
#ifdef GL_TEXTURE_BASE_LEVEL
	if ( en == GL_TEXTURE_BASE_LEVEL ) return "GL_TEXTURE_BASE_LEVEL";
#endif
#ifdef GL_TEXTURE_MAX_LEVEL
	if ( en == GL_TEXTURE_MAX_LEVEL ) return "GL_TEXTURE_MAX_LEVEL";
#endif
#ifdef GL_LIGHT_MODEL_COLOR_CONTROL
	if ( en == GL_LIGHT_MODEL_COLOR_CONTROL ) return "GL_LIGHT_MODEL_COLOR_CONTROL";
#endif
#ifdef GL_SINGLE_COLOR
	if ( en == GL_SINGLE_COLOR ) return "GL_SINGLE_COLOR";
#endif
#ifdef GL_SEPARATE_SPECULAR_COLOR
	if ( en == GL_SEPARATE_SPECULAR_COLOR ) return "GL_SEPARATE_SPECULAR_COLOR";
#endif
#ifdef GL_UNSIGNED_BYTE_2_3_3_REV
	if ( en == GL_UNSIGNED_BYTE_2_3_3_REV ) return "GL_UNSIGNED_BYTE_2_3_3_REV";
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5
	if ( en == GL_UNSIGNED_SHORT_5_6_5 ) return "GL_UNSIGNED_SHORT_5_6_5";
#endif
#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
	if ( en == GL_UNSIGNED_SHORT_5_6_5_REV ) return "GL_UNSIGNED_SHORT_5_6_5_REV";
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4_REV
	if ( en == GL_UNSIGNED_SHORT_4_4_4_4_REV ) return "GL_UNSIGNED_SHORT_4_4_4_4_REV";
#endif
#ifdef GL_UNSIGNED_SHORT_1_5_5_5_REV
	if ( en == GL_UNSIGNED_SHORT_1_5_5_5_REV ) return "GL_UNSIGNED_SHORT_1_5_5_5_REV";
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8_REV
	if ( en == GL_UNSIGNED_INT_8_8_8_8_REV ) return "GL_UNSIGNED_INT_8_8_8_8_REV";
#endif
#ifdef GL_ALIASED_POINT_SIZE_RANGE
	if ( en == GL_ALIASED_POINT_SIZE_RANGE ) return "GL_ALIASED_POINT_SIZE_RANGE";
#endif
#ifdef GL_ALIASED_LINE_WIDTH_RANGE
	if ( en == GL_ALIASED_LINE_WIDTH_RANGE ) return "GL_ALIASED_LINE_WIDTH_RANGE";
#endif
#ifdef GL_MULTISAMPLE
	if ( en == GL_MULTISAMPLE ) return "GL_MULTISAMPLE";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE
	if ( en == GL_SAMPLE_ALPHA_TO_COVERAGE ) return "GL_SAMPLE_ALPHA_TO_COVERAGE";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE
	if ( en == GL_SAMPLE_ALPHA_TO_ONE ) return "GL_SAMPLE_ALPHA_TO_ONE";
#endif
#ifdef GL_SAMPLE_COVERAGE
	if ( en == GL_SAMPLE_COVERAGE ) return "GL_SAMPLE_COVERAGE";
#endif
#ifdef GL_SAMPLE_BUFFERS
	if ( en == GL_SAMPLE_BUFFERS ) return "GL_SAMPLE_BUFFERS";
#endif
#ifdef GL_SAMPLES
	if ( en == GL_SAMPLES ) return "GL_SAMPLES";
#endif
#ifdef GL_SAMPLE_COVERAGE_VALUE
	if ( en == GL_SAMPLE_COVERAGE_VALUE ) return "GL_SAMPLE_COVERAGE_VALUE";
#endif
#ifdef GL_SAMPLE_COVERAGE_INVERT
	if ( en == GL_SAMPLE_COVERAGE_INVERT ) return "GL_SAMPLE_COVERAGE_INVERT";
#endif
#ifdef GL_CLAMP_TO_BORDER
	if ( en == GL_CLAMP_TO_BORDER ) return "GL_CLAMP_TO_BORDER";
#endif
#ifdef GL_TEXTURE0
	if ( en == GL_TEXTURE0 ) return "GL_TEXTURE0";
#endif
#ifdef GL_TEXTURE1
	if ( en == GL_TEXTURE1 ) return "GL_TEXTURE1";
#endif
#ifdef GL_TEXTURE2
	if ( en == GL_TEXTURE2 ) return "GL_TEXTURE2";
#endif
#ifdef GL_TEXTURE3
	if ( en == GL_TEXTURE3 ) return "GL_TEXTURE3";
#endif
#ifdef GL_TEXTURE4
	if ( en == GL_TEXTURE4 ) return "GL_TEXTURE4";
#endif
#ifdef GL_TEXTURE5
	if ( en == GL_TEXTURE5 ) return "GL_TEXTURE5";
#endif
#ifdef GL_TEXTURE6
	if ( en == GL_TEXTURE6 ) return "GL_TEXTURE6";
#endif
#ifdef GL_TEXTURE7
	if ( en == GL_TEXTURE7 ) return "GL_TEXTURE7";
#endif
#ifdef GL_TEXTURE8
	if ( en == GL_TEXTURE8 ) return "GL_TEXTURE8";
#endif
#ifdef GL_TEXTURE9
	if ( en == GL_TEXTURE9 ) return "GL_TEXTURE9";
#endif
#ifdef GL_TEXTURE10
	if ( en == GL_TEXTURE10 ) return "GL_TEXTURE10";
#endif
#ifdef GL_TEXTURE11
	if ( en == GL_TEXTURE11 ) return "GL_TEXTURE11";
#endif
#ifdef GL_TEXTURE12
	if ( en == GL_TEXTURE12 ) return "GL_TEXTURE12";
#endif
#ifdef GL_TEXTURE13
	if ( en == GL_TEXTURE13 ) return "GL_TEXTURE13";
#endif
#ifdef GL_TEXTURE14
	if ( en == GL_TEXTURE14 ) return "GL_TEXTURE14";
#endif
#ifdef GL_TEXTURE15
	if ( en == GL_TEXTURE15 ) return "GL_TEXTURE15";
#endif
#ifdef GL_TEXTURE16
	if ( en == GL_TEXTURE16 ) return "GL_TEXTURE16";
#endif
#ifdef GL_TEXTURE17
	if ( en == GL_TEXTURE17 ) return "GL_TEXTURE17";
#endif
#ifdef GL_TEXTURE18
	if ( en == GL_TEXTURE18 ) return "GL_TEXTURE18";
#endif
#ifdef GL_TEXTURE19
	if ( en == GL_TEXTURE19 ) return "GL_TEXTURE19";
#endif
#ifdef GL_TEXTURE20
	if ( en == GL_TEXTURE20 ) return "GL_TEXTURE20";
#endif
#ifdef GL_TEXTURE21
	if ( en == GL_TEXTURE21 ) return "GL_TEXTURE21";
#endif
#ifdef GL_TEXTURE22
	if ( en == GL_TEXTURE22 ) return "GL_TEXTURE22";
#endif
#ifdef GL_TEXTURE23
	if ( en == GL_TEXTURE23 ) return "GL_TEXTURE23";
#endif
#ifdef GL_TEXTURE24
	if ( en == GL_TEXTURE24 ) return "GL_TEXTURE24";
#endif
#ifdef GL_TEXTURE25
	if ( en == GL_TEXTURE25 ) return "GL_TEXTURE25";
#endif
#ifdef GL_TEXTURE26
	if ( en == GL_TEXTURE26 ) return "GL_TEXTURE26";
#endif
#ifdef GL_TEXTURE27
	if ( en == GL_TEXTURE27 ) return "GL_TEXTURE27";
#endif
#ifdef GL_TEXTURE28
	if ( en == GL_TEXTURE28 ) return "GL_TEXTURE28";
#endif
#ifdef GL_TEXTURE29
	if ( en == GL_TEXTURE29 ) return "GL_TEXTURE29";
#endif
#ifdef GL_TEXTURE30
	if ( en == GL_TEXTURE30 ) return "GL_TEXTURE30";
#endif
#ifdef GL_TEXTURE31
	if ( en == GL_TEXTURE31 ) return "GL_TEXTURE31";
#endif
#ifdef GL_ACTIVE_TEXTURE
	if ( en == GL_ACTIVE_TEXTURE ) return "GL_ACTIVE_TEXTURE";
#endif
#ifdef GL_CLIENT_ACTIVE_TEXTURE
	if ( en == GL_CLIENT_ACTIVE_TEXTURE ) return "GL_CLIENT_ACTIVE_TEXTURE";
#endif
#ifdef GL_MAX_TEXTURE_UNITS
	if ( en == GL_MAX_TEXTURE_UNITS ) return "GL_MAX_TEXTURE_UNITS";
#endif
#ifdef GL_TRANSPOSE_MODELVIEW_MATRIX
	if ( en == GL_TRANSPOSE_MODELVIEW_MATRIX ) return "GL_TRANSPOSE_MODELVIEW_MATRIX";
#endif
#ifdef GL_TRANSPOSE_PROJECTION_MATRIX
	if ( en == GL_TRANSPOSE_PROJECTION_MATRIX ) return "GL_TRANSPOSE_PROJECTION_MATRIX";
#endif
#ifdef GL_TRANSPOSE_TEXTURE_MATRIX
	if ( en == GL_TRANSPOSE_TEXTURE_MATRIX ) return "GL_TRANSPOSE_TEXTURE_MATRIX";
#endif
#ifdef GL_TRANSPOSE_COLOR_MATRIX
	if ( en == GL_TRANSPOSE_COLOR_MATRIX ) return "GL_TRANSPOSE_COLOR_MATRIX";
#endif
#ifdef GL_SUBTRACT
	if ( en == GL_SUBTRACT ) return "GL_SUBTRACT";
#endif
#ifdef GL_COMPRESSED_ALPHA
	if ( en == GL_COMPRESSED_ALPHA ) return "GL_COMPRESSED_ALPHA";
#endif
#ifdef GL_COMPRESSED_LUMINANCE
	if ( en == GL_COMPRESSED_LUMINANCE ) return "GL_COMPRESSED_LUMINANCE";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_ALPHA
	if ( en == GL_COMPRESSED_LUMINANCE_ALPHA ) return "GL_COMPRESSED_LUMINANCE_ALPHA";
#endif
#ifdef GL_COMPRESSED_INTENSITY
	if ( en == GL_COMPRESSED_INTENSITY ) return "GL_COMPRESSED_INTENSITY";
#endif
#ifdef GL_COMPRESSED_RGB
	if ( en == GL_COMPRESSED_RGB ) return "GL_COMPRESSED_RGB";
#endif
#ifdef GL_COMPRESSED_RGBA
	if ( en == GL_COMPRESSED_RGBA ) return "GL_COMPRESSED_RGBA";
#endif
#ifdef GL_TEXTURE_COMPRESSION_HINT
	if ( en == GL_TEXTURE_COMPRESSION_HINT ) return "GL_TEXTURE_COMPRESSION_HINT";
#endif
#ifdef GL_NORMAL_MAP
	if ( en == GL_NORMAL_MAP ) return "GL_NORMAL_MAP";
#endif
#ifdef GL_REFLECTION_MAP
	if ( en == GL_REFLECTION_MAP ) return "GL_REFLECTION_MAP";
#endif
#ifdef GL_TEXTURE_CUBE_MAP
	if ( en == GL_TEXTURE_CUBE_MAP ) return "GL_TEXTURE_CUBE_MAP";
#endif
#ifdef GL_TEXTURE_BINDING_CUBE_MAP
	if ( en == GL_TEXTURE_BINDING_CUBE_MAP ) return "GL_TEXTURE_BINDING_CUBE_MAP";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_X";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP ) return "GL_PROXY_TEXTURE_CUBE_MAP";
#endif
#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE
	if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE ) return "GL_MAX_CUBE_MAP_TEXTURE_SIZE";
#endif
#ifdef GL_COMBINE
	if ( en == GL_COMBINE ) return "GL_COMBINE";
#endif
#ifdef GL_COMBINE_RGB
	if ( en == GL_COMBINE_RGB ) return "GL_COMBINE_RGB";
#endif
#ifdef GL_COMBINE_ALPHA
	if ( en == GL_COMBINE_ALPHA ) return "GL_COMBINE_ALPHA";
#endif
#ifdef GL_RGB_SCALE
	if ( en == GL_RGB_SCALE ) return "GL_RGB_SCALE";
#endif
#ifdef GL_ADD_SIGNED
	if ( en == GL_ADD_SIGNED ) return "GL_ADD_SIGNED";
#endif
#ifdef GL_INTERPOLATE
	if ( en == GL_INTERPOLATE ) return "GL_INTERPOLATE";
#endif
#ifdef GL_CONSTANT
	if ( en == GL_CONSTANT ) return "GL_CONSTANT";
#endif
#ifdef GL_PRIMARY_COLOR
	if ( en == GL_PRIMARY_COLOR ) return "GL_PRIMARY_COLOR";
#endif
#ifdef GL_PREVIOUS
	if ( en == GL_PREVIOUS ) return "GL_PREVIOUS";
#endif
#ifdef GL_SOURCE0_RGB
	if ( en == GL_SOURCE0_RGB ) return "GL_SOURCE0_RGB";
#endif
#ifdef GL_SOURCE1_RGB
	if ( en == GL_SOURCE1_RGB ) return "GL_SOURCE1_RGB";
#endif
#ifdef GL_SOURCE2_RGB
	if ( en == GL_SOURCE2_RGB ) return "GL_SOURCE2_RGB";
#endif
#ifdef GL_SOURCE0_ALPHA
	if ( en == GL_SOURCE0_ALPHA ) return "GL_SOURCE0_ALPHA";
#endif
#ifdef GL_SOURCE1_ALPHA
	if ( en == GL_SOURCE1_ALPHA ) return "GL_SOURCE1_ALPHA";
#endif
#ifdef GL_SOURCE2_ALPHA
	if ( en == GL_SOURCE2_ALPHA ) return "GL_SOURCE2_ALPHA";
#endif
#ifdef GL_OPERAND0_RGB
	if ( en == GL_OPERAND0_RGB ) return "GL_OPERAND0_RGB";
#endif
#ifdef GL_OPERAND1_RGB
	if ( en == GL_OPERAND1_RGB ) return "GL_OPERAND1_RGB";
#endif
#ifdef GL_OPERAND2_RGB
	if ( en == GL_OPERAND2_RGB ) return "GL_OPERAND2_RGB";
#endif
#ifdef GL_OPERAND0_ALPHA
	if ( en == GL_OPERAND0_ALPHA ) return "GL_OPERAND0_ALPHA";
#endif
#ifdef GL_OPERAND1_ALPHA
	if ( en == GL_OPERAND1_ALPHA ) return "GL_OPERAND1_ALPHA";
#endif
#ifdef GL_OPERAND2_ALPHA
	if ( en == GL_OPERAND2_ALPHA ) return "GL_OPERAND2_ALPHA";
#endif
#ifdef GL_TEXTURE_COMPRESSED_IMAGE_SIZE
	if ( en == GL_TEXTURE_COMPRESSED_IMAGE_SIZE ) return "GL_TEXTURE_COMPRESSED_IMAGE_SIZE";
#endif
#ifdef GL_TEXTURE_COMPRESSED
	if ( en == GL_TEXTURE_COMPRESSED ) return "GL_TEXTURE_COMPRESSED";
#endif
#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS
	if ( en == GL_NUM_COMPRESSED_TEXTURE_FORMATS ) return "GL_NUM_COMPRESSED_TEXTURE_FORMATS";
#endif
#ifdef GL_COMPRESSED_TEXTURE_FORMATS
	if ( en == GL_COMPRESSED_TEXTURE_FORMATS ) return "GL_COMPRESSED_TEXTURE_FORMATS";
#endif
#ifdef GL_DOT3_RGB
	if ( en == GL_DOT3_RGB ) return "GL_DOT3_RGB";
#endif
#ifdef GL_DOT3_RGBA
	if ( en == GL_DOT3_RGBA ) return "GL_DOT3_RGBA";
#endif
#ifdef GL_MULTISAMPLE_BIT
	if ( en == GL_MULTISAMPLE_BIT ) return "GL_MULTISAMPLE_BIT";
#endif
#ifdef GL_BLEND_DST_RGB
	if ( en == GL_BLEND_DST_RGB ) return "GL_BLEND_DST_RGB";
#endif
#ifdef GL_BLEND_SRC_RGB
	if ( en == GL_BLEND_SRC_RGB ) return "GL_BLEND_SRC_RGB";
#endif
#ifdef GL_BLEND_DST_ALPHA
	if ( en == GL_BLEND_DST_ALPHA ) return "GL_BLEND_DST_ALPHA";
#endif
#ifdef GL_BLEND_SRC_ALPHA
	if ( en == GL_BLEND_SRC_ALPHA ) return "GL_BLEND_SRC_ALPHA";
#endif
#ifdef GL_POINT_SIZE_MIN
	if ( en == GL_POINT_SIZE_MIN ) return "GL_POINT_SIZE_MIN";
#endif
#ifdef GL_POINT_SIZE_MAX
	if ( en == GL_POINT_SIZE_MAX ) return "GL_POINT_SIZE_MAX";
#endif
#ifdef GL_POINT_FADE_THRESHOLD_SIZE
	if ( en == GL_POINT_FADE_THRESHOLD_SIZE ) return "GL_POINT_FADE_THRESHOLD_SIZE";
#endif
#ifdef GL_POINT_DISTANCE_ATTENUATION
	if ( en == GL_POINT_DISTANCE_ATTENUATION ) return "GL_POINT_DISTANCE_ATTENUATION";
#endif
#ifdef GL_GENERATE_MIPMAP
	if ( en == GL_GENERATE_MIPMAP ) return "GL_GENERATE_MIPMAP";
#endif
#ifdef GL_GENERATE_MIPMAP_HINT
	if ( en == GL_GENERATE_MIPMAP_HINT ) return "GL_GENERATE_MIPMAP_HINT";
#endif
#ifdef GL_DEPTH_COMPONENT16
	if ( en == GL_DEPTH_COMPONENT16 ) return "GL_DEPTH_COMPONENT16";
#endif
#ifdef GL_DEPTH_COMPONENT24
	if ( en == GL_DEPTH_COMPONENT24 ) return "GL_DEPTH_COMPONENT24";
#endif
#ifdef GL_DEPTH_COMPONENT32
	if ( en == GL_DEPTH_COMPONENT32 ) return "GL_DEPTH_COMPONENT32";
#endif
#ifdef GL_MIRRORED_REPEAT
	if ( en == GL_MIRRORED_REPEAT ) return "GL_MIRRORED_REPEAT";
#endif
#ifdef GL_FOG_COORDINATE_SOURCE
	if ( en == GL_FOG_COORDINATE_SOURCE ) return "GL_FOG_COORDINATE_SOURCE";
#endif
#ifdef GL_FOG_COORDINATE
	if ( en == GL_FOG_COORDINATE ) return "GL_FOG_COORDINATE";
#endif
#ifdef GL_FRAGMENT_DEPTH
	if ( en == GL_FRAGMENT_DEPTH ) return "GL_FRAGMENT_DEPTH";
#endif
#ifdef GL_CURRENT_FOG_COORDINATE
	if ( en == GL_CURRENT_FOG_COORDINATE ) return "GL_CURRENT_FOG_COORDINATE";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_TYPE
	if ( en == GL_FOG_COORDINATE_ARRAY_TYPE ) return "GL_FOG_COORDINATE_ARRAY_TYPE";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_STRIDE
	if ( en == GL_FOG_COORDINATE_ARRAY_STRIDE ) return "GL_FOG_COORDINATE_ARRAY_STRIDE";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_POINTER
	if ( en == GL_FOG_COORDINATE_ARRAY_POINTER ) return "GL_FOG_COORDINATE_ARRAY_POINTER";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY
	if ( en == GL_FOG_COORDINATE_ARRAY ) return "GL_FOG_COORDINATE_ARRAY";
#endif
#ifdef GL_COLOR_SUM
	if ( en == GL_COLOR_SUM ) return "GL_COLOR_SUM";
#endif
#ifdef GL_CURRENT_SECONDARY_COLOR
	if ( en == GL_CURRENT_SECONDARY_COLOR ) return "GL_CURRENT_SECONDARY_COLOR";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_SIZE
	if ( en == GL_SECONDARY_COLOR_ARRAY_SIZE ) return "GL_SECONDARY_COLOR_ARRAY_SIZE";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_TYPE
	if ( en == GL_SECONDARY_COLOR_ARRAY_TYPE ) return "GL_SECONDARY_COLOR_ARRAY_TYPE";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_STRIDE
	if ( en == GL_SECONDARY_COLOR_ARRAY_STRIDE ) return "GL_SECONDARY_COLOR_ARRAY_STRIDE";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_POINTER
	if ( en == GL_SECONDARY_COLOR_ARRAY_POINTER ) return "GL_SECONDARY_COLOR_ARRAY_POINTER";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY
	if ( en == GL_SECONDARY_COLOR_ARRAY ) return "GL_SECONDARY_COLOR_ARRAY";
#endif
#ifdef GL_MAX_TEXTURE_LOD_BIAS
	if ( en == GL_MAX_TEXTURE_LOD_BIAS ) return "GL_MAX_TEXTURE_LOD_BIAS";
#endif
#ifdef GL_TEXTURE_FILTER_CONTROL
	if ( en == GL_TEXTURE_FILTER_CONTROL ) return "GL_TEXTURE_FILTER_CONTROL";
#endif
#ifdef GL_TEXTURE_LOD_BIAS
	if ( en == GL_TEXTURE_LOD_BIAS ) return "GL_TEXTURE_LOD_BIAS";
#endif
#ifdef GL_INCR_WRAP
	if ( en == GL_INCR_WRAP ) return "GL_INCR_WRAP";
#endif
#ifdef GL_DECR_WRAP
	if ( en == GL_DECR_WRAP ) return "GL_DECR_WRAP";
#endif
#ifdef GL_TEXTURE_DEPTH_SIZE
	if ( en == GL_TEXTURE_DEPTH_SIZE ) return "GL_TEXTURE_DEPTH_SIZE";
#endif
#ifdef GL_DEPTH_TEXTURE_MODE
	if ( en == GL_DEPTH_TEXTURE_MODE ) return "GL_DEPTH_TEXTURE_MODE";
#endif
#ifdef GL_TEXTURE_COMPARE_MODE
	if ( en == GL_TEXTURE_COMPARE_MODE ) return "GL_TEXTURE_COMPARE_MODE";
#endif
#ifdef GL_TEXTURE_COMPARE_FUNC
	if ( en == GL_TEXTURE_COMPARE_FUNC ) return "GL_TEXTURE_COMPARE_FUNC";
#endif
#ifdef GL_COMPARE_R_TO_TEXTURE
	if ( en == GL_COMPARE_R_TO_TEXTURE ) return "GL_COMPARE_R_TO_TEXTURE";
#endif
#ifdef GL_FOG_COORD_SRC
	if ( en == GL_FOG_COORD_SRC ) return "GL_FOG_COORD_SRC";
#endif
#ifdef GL_FOG_COORD
	if ( en == GL_FOG_COORD ) return "GL_FOG_COORD";
#endif
#ifdef GL_FOG_COORD_ARRAY
	if ( en == GL_FOG_COORD_ARRAY ) return "GL_FOG_COORD_ARRAY";
#endif
#ifdef GL_SRC0_RGB
	if ( en == GL_SRC0_RGB ) return "GL_SRC0_RGB";
#endif
#ifdef GL_FOG_COORD_ARRAY_POINTER
	if ( en == GL_FOG_COORD_ARRAY_POINTER ) return "GL_FOG_COORD_ARRAY_POINTER";
#endif
#ifdef GL_FOG_COORD_ARRAY_TYPE
	if ( en == GL_FOG_COORD_ARRAY_TYPE ) return "GL_FOG_COORD_ARRAY_TYPE";
#endif
#ifdef GL_SRC1_ALPHA
	if ( en == GL_SRC1_ALPHA ) return "GL_SRC1_ALPHA";
#endif
#ifdef GL_CURRENT_FOG_COORD
	if ( en == GL_CURRENT_FOG_COORD ) return "GL_CURRENT_FOG_COORD";
#endif
#ifdef GL_FOG_COORD_ARRAY_STRIDE
	if ( en == GL_FOG_COORD_ARRAY_STRIDE ) return "GL_FOG_COORD_ARRAY_STRIDE";
#endif
#ifdef GL_SRC0_ALPHA
	if ( en == GL_SRC0_ALPHA ) return "GL_SRC0_ALPHA";
#endif
#ifdef GL_SRC1_RGB
	if ( en == GL_SRC1_RGB ) return "GL_SRC1_RGB";
#endif
#ifdef GL_FOG_COORD_ARRAY_BUFFER_BINDING
	if ( en == GL_FOG_COORD_ARRAY_BUFFER_BINDING ) return "GL_FOG_COORD_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_SRC2_ALPHA
	if ( en == GL_SRC2_ALPHA ) return "GL_SRC2_ALPHA";
#endif
#ifdef GL_SRC2_RGB
	if ( en == GL_SRC2_RGB ) return "GL_SRC2_RGB";
#endif
#ifdef GL_BUFFER_SIZE
	if ( en == GL_BUFFER_SIZE ) return "GL_BUFFER_SIZE";
#endif
#ifdef GL_BUFFER_USAGE
	if ( en == GL_BUFFER_USAGE ) return "GL_BUFFER_USAGE";
#endif
#ifdef GL_QUERY_COUNTER_BITS
	if ( en == GL_QUERY_COUNTER_BITS ) return "GL_QUERY_COUNTER_BITS";
#endif
#ifdef GL_CURRENT_QUERY
	if ( en == GL_CURRENT_QUERY ) return "GL_CURRENT_QUERY";
#endif
#ifdef GL_QUERY_RESULT
	if ( en == GL_QUERY_RESULT ) return "GL_QUERY_RESULT";
#endif
#ifdef GL_QUERY_RESULT_AVAILABLE
	if ( en == GL_QUERY_RESULT_AVAILABLE ) return "GL_QUERY_RESULT_AVAILABLE";
#endif
#ifdef GL_ARRAY_BUFFER
	if ( en == GL_ARRAY_BUFFER ) return "GL_ARRAY_BUFFER";
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER
	if ( en == GL_ELEMENT_ARRAY_BUFFER ) return "GL_ELEMENT_ARRAY_BUFFER";
#endif
#ifdef GL_ARRAY_BUFFER_BINDING
	if ( en == GL_ARRAY_BUFFER_BINDING ) return "GL_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING
	if ( en == GL_ELEMENT_ARRAY_BUFFER_BINDING ) return "GL_ELEMENT_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_VERTEX_ARRAY_BUFFER_BINDING
	if ( en == GL_VERTEX_ARRAY_BUFFER_BINDING ) return "GL_VERTEX_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_NORMAL_ARRAY_BUFFER_BINDING
	if ( en == GL_NORMAL_ARRAY_BUFFER_BINDING ) return "GL_NORMAL_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_COLOR_ARRAY_BUFFER_BINDING
	if ( en == GL_COLOR_ARRAY_BUFFER_BINDING ) return "GL_COLOR_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_INDEX_ARRAY_BUFFER_BINDING
	if ( en == GL_INDEX_ARRAY_BUFFER_BINDING ) return "GL_INDEX_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING
	if ( en == GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING ) return "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_BUFFER_BINDING
	if ( en == GL_EDGE_FLAG_ARRAY_BUFFER_BINDING ) return "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING
	if ( en == GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING ) return "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING
	if ( en == GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING ) return "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_WEIGHT_ARRAY_BUFFER_BINDING
	if ( en == GL_WEIGHT_ARRAY_BUFFER_BINDING ) return "GL_WEIGHT_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING
	if ( en == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING ) return "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING";
#endif
#ifdef GL_READ_ONLY
	if ( en == GL_READ_ONLY ) return "GL_READ_ONLY";
#endif
#ifdef GL_WRITE_ONLY
	if ( en == GL_WRITE_ONLY ) return "GL_WRITE_ONLY";
#endif
#ifdef GL_READ_WRITE
	if ( en == GL_READ_WRITE ) return "GL_READ_WRITE";
#endif
#ifdef GL_BUFFER_ACCESS
	if ( en == GL_BUFFER_ACCESS ) return "GL_BUFFER_ACCESS";
#endif
#ifdef GL_BUFFER_MAPPED
	if ( en == GL_BUFFER_MAPPED ) return "GL_BUFFER_MAPPED";
#endif
#ifdef GL_BUFFER_MAP_POINTER
	if ( en == GL_BUFFER_MAP_POINTER ) return "GL_BUFFER_MAP_POINTER";
#endif
#ifdef GL_STREAM_DRAW
	if ( en == GL_STREAM_DRAW ) return "GL_STREAM_DRAW";
#endif
#ifdef GL_STREAM_READ
	if ( en == GL_STREAM_READ ) return "GL_STREAM_READ";
#endif
#ifdef GL_STREAM_COPY
	if ( en == GL_STREAM_COPY ) return "GL_STREAM_COPY";
#endif
#ifdef GL_STATIC_DRAW
	if ( en == GL_STATIC_DRAW ) return "GL_STATIC_DRAW";
#endif
#ifdef GL_STATIC_READ
	if ( en == GL_STATIC_READ ) return "GL_STATIC_READ";
#endif
#ifdef GL_STATIC_COPY
	if ( en == GL_STATIC_COPY ) return "GL_STATIC_COPY";
#endif
#ifdef GL_DYNAMIC_DRAW
	if ( en == GL_DYNAMIC_DRAW ) return "GL_DYNAMIC_DRAW";
#endif
#ifdef GL_DYNAMIC_READ
	if ( en == GL_DYNAMIC_READ ) return "GL_DYNAMIC_READ";
#endif
#ifdef GL_DYNAMIC_COPY
	if ( en == GL_DYNAMIC_COPY ) return "GL_DYNAMIC_COPY";
#endif
#ifdef GL_SAMPLES_PASSED
	if ( en == GL_SAMPLES_PASSED ) return "GL_SAMPLES_PASSED";
#endif
#ifdef GL_BLEND_EQUATION_RGB
	if ( en == GL_BLEND_EQUATION_RGB ) return "GL_BLEND_EQUATION_RGB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_ENABLED
	if ( en == GL_VERTEX_ATTRIB_ARRAY_ENABLED ) return "GL_VERTEX_ATTRIB_ARRAY_ENABLED";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_SIZE
	if ( en == GL_VERTEX_ATTRIB_ARRAY_SIZE ) return "GL_VERTEX_ATTRIB_ARRAY_SIZE";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_STRIDE
	if ( en == GL_VERTEX_ATTRIB_ARRAY_STRIDE ) return "GL_VERTEX_ATTRIB_ARRAY_STRIDE";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_TYPE
	if ( en == GL_VERTEX_ATTRIB_ARRAY_TYPE ) return "GL_VERTEX_ATTRIB_ARRAY_TYPE";
#endif
#ifdef GL_CURRENT_VERTEX_ATTRIB
	if ( en == GL_CURRENT_VERTEX_ATTRIB ) return "GL_CURRENT_VERTEX_ATTRIB";
#endif
#ifdef GL_VERTEX_PROGRAM_POINT_SIZE
	if ( en == GL_VERTEX_PROGRAM_POINT_SIZE ) return "GL_VERTEX_PROGRAM_POINT_SIZE";
#endif
#ifdef GL_VERTEX_PROGRAM_TWO_SIDE
	if ( en == GL_VERTEX_PROGRAM_TWO_SIDE ) return "GL_VERTEX_PROGRAM_TWO_SIDE";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_POINTER
	if ( en == GL_VERTEX_ATTRIB_ARRAY_POINTER ) return "GL_VERTEX_ATTRIB_ARRAY_POINTER";
#endif
#ifdef GL_STENCIL_BACK_FUNC
	if ( en == GL_STENCIL_BACK_FUNC ) return "GL_STENCIL_BACK_FUNC";
#endif
#ifdef GL_STENCIL_BACK_FAIL
	if ( en == GL_STENCIL_BACK_FAIL ) return "GL_STENCIL_BACK_FAIL";
#endif
#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL
	if ( en == GL_STENCIL_BACK_PASS_DEPTH_FAIL ) return "GL_STENCIL_BACK_PASS_DEPTH_FAIL";
#endif
#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS
	if ( en == GL_STENCIL_BACK_PASS_DEPTH_PASS ) return "GL_STENCIL_BACK_PASS_DEPTH_PASS";
#endif
#ifdef GL_MAX_DRAW_BUFFERS
	if ( en == GL_MAX_DRAW_BUFFERS ) return "GL_MAX_DRAW_BUFFERS";
#endif
#ifdef GL_DRAW_BUFFER0
	if ( en == GL_DRAW_BUFFER0 ) return "GL_DRAW_BUFFER0";
#endif
#ifdef GL_DRAW_BUFFER1
	if ( en == GL_DRAW_BUFFER1 ) return "GL_DRAW_BUFFER1";
#endif
#ifdef GL_DRAW_BUFFER2
	if ( en == GL_DRAW_BUFFER2 ) return "GL_DRAW_BUFFER2";
#endif
#ifdef GL_DRAW_BUFFER3
	if ( en == GL_DRAW_BUFFER3 ) return "GL_DRAW_BUFFER3";
#endif
#ifdef GL_DRAW_BUFFER4
	if ( en == GL_DRAW_BUFFER4 ) return "GL_DRAW_BUFFER4";
#endif
#ifdef GL_DRAW_BUFFER5
	if ( en == GL_DRAW_BUFFER5 ) return "GL_DRAW_BUFFER5";
#endif
#ifdef GL_DRAW_BUFFER6
	if ( en == GL_DRAW_BUFFER6 ) return "GL_DRAW_BUFFER6";
#endif
#ifdef GL_DRAW_BUFFER7
	if ( en == GL_DRAW_BUFFER7 ) return "GL_DRAW_BUFFER7";
#endif
#ifdef GL_DRAW_BUFFER8
	if ( en == GL_DRAW_BUFFER8 ) return "GL_DRAW_BUFFER8";
#endif
#ifdef GL_DRAW_BUFFER9
	if ( en == GL_DRAW_BUFFER9 ) return "GL_DRAW_BUFFER9";
#endif
#ifdef GL_DRAW_BUFFER10
	if ( en == GL_DRAW_BUFFER10 ) return "GL_DRAW_BUFFER10";
#endif
#ifdef GL_DRAW_BUFFER11
	if ( en == GL_DRAW_BUFFER11 ) return "GL_DRAW_BUFFER11";
#endif
#ifdef GL_DRAW_BUFFER12
	if ( en == GL_DRAW_BUFFER12 ) return "GL_DRAW_BUFFER12";
#endif
#ifdef GL_DRAW_BUFFER13
	if ( en == GL_DRAW_BUFFER13 ) return "GL_DRAW_BUFFER13";
#endif
#ifdef GL_DRAW_BUFFER14
	if ( en == GL_DRAW_BUFFER14 ) return "GL_DRAW_BUFFER14";
#endif
#ifdef GL_DRAW_BUFFER15
	if ( en == GL_DRAW_BUFFER15 ) return "GL_DRAW_BUFFER15";
#endif
#ifdef GL_BLEND_EQUATION_ALPHA
	if ( en == GL_BLEND_EQUATION_ALPHA ) return "GL_BLEND_EQUATION_ALPHA";
#endif
#ifdef GL_POINT_SPRITE
	if ( en == GL_POINT_SPRITE ) return "GL_POINT_SPRITE";
#endif
#ifdef GL_COORD_REPLACE
	if ( en == GL_COORD_REPLACE ) return "GL_COORD_REPLACE";
#endif
#ifdef GL_MAX_VERTEX_ATTRIBS
	if ( en == GL_MAX_VERTEX_ATTRIBS ) return "GL_MAX_VERTEX_ATTRIBS";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_NORMALIZED
	if ( en == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED ) return "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED";
#endif
#ifdef GL_MAX_TEXTURE_COORDS
	if ( en == GL_MAX_TEXTURE_COORDS ) return "GL_MAX_TEXTURE_COORDS";
#endif
#ifdef GL_MAX_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_TEXTURE_IMAGE_UNITS ) return "GL_MAX_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_FRAGMENT_SHADER
	if ( en == GL_FRAGMENT_SHADER ) return "GL_FRAGMENT_SHADER";
#endif
#ifdef GL_VERTEX_SHADER
	if ( en == GL_VERTEX_SHADER ) return "GL_VERTEX_SHADER";
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS
	if ( en == GL_MAX_FRAGMENT_UNIFORM_COMPONENTS ) return "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS
	if ( en == GL_MAX_VERTEX_UNIFORM_COMPONENTS ) return "GL_MAX_VERTEX_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_VARYING_FLOATS
	if ( en == GL_MAX_VARYING_FLOATS ) return "GL_MAX_VARYING_FLOATS";
#endif
#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS ) return "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS ) return "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_SHADER_TYPE
	if ( en == GL_SHADER_TYPE ) return "GL_SHADER_TYPE";
#endif
#ifdef GL_FLOAT_VEC2
	if ( en == GL_FLOAT_VEC2 ) return "GL_FLOAT_VEC2";
#endif
#ifdef GL_FLOAT_VEC3
	if ( en == GL_FLOAT_VEC3 ) return "GL_FLOAT_VEC3";
#endif
#ifdef GL_FLOAT_VEC4
	if ( en == GL_FLOAT_VEC4 ) return "GL_FLOAT_VEC4";
#endif
#ifdef GL_INT_VEC2
	if ( en == GL_INT_VEC2 ) return "GL_INT_VEC2";
#endif
#ifdef GL_INT_VEC3
	if ( en == GL_INT_VEC3 ) return "GL_INT_VEC3";
#endif
#ifdef GL_INT_VEC4
	if ( en == GL_INT_VEC4 ) return "GL_INT_VEC4";
#endif
#ifdef GL_BOOL
	if ( en == GL_BOOL ) return "GL_BOOL";
#endif
#ifdef GL_BOOL_VEC2
	if ( en == GL_BOOL_VEC2 ) return "GL_BOOL_VEC2";
#endif
#ifdef GL_BOOL_VEC3
	if ( en == GL_BOOL_VEC3 ) return "GL_BOOL_VEC3";
#endif
#ifdef GL_BOOL_VEC4
	if ( en == GL_BOOL_VEC4 ) return "GL_BOOL_VEC4";
#endif
#ifdef GL_FLOAT_MAT2
	if ( en == GL_FLOAT_MAT2 ) return "GL_FLOAT_MAT2";
#endif
#ifdef GL_FLOAT_MAT3
	if ( en == GL_FLOAT_MAT3 ) return "GL_FLOAT_MAT3";
#endif
#ifdef GL_FLOAT_MAT4
	if ( en == GL_FLOAT_MAT4 ) return "GL_FLOAT_MAT4";
#endif
#ifdef GL_SAMPLER_1D
	if ( en == GL_SAMPLER_1D ) return "GL_SAMPLER_1D";
#endif
#ifdef GL_SAMPLER_2D
	if ( en == GL_SAMPLER_2D ) return "GL_SAMPLER_2D";
#endif
#ifdef GL_SAMPLER_3D
	if ( en == GL_SAMPLER_3D ) return "GL_SAMPLER_3D";
#endif
#ifdef GL_SAMPLER_CUBE
	if ( en == GL_SAMPLER_CUBE ) return "GL_SAMPLER_CUBE";
#endif
#ifdef GL_SAMPLER_1D_SHADOW
	if ( en == GL_SAMPLER_1D_SHADOW ) return "GL_SAMPLER_1D_SHADOW";
#endif
#ifdef GL_SAMPLER_2D_SHADOW
	if ( en == GL_SAMPLER_2D_SHADOW ) return "GL_SAMPLER_2D_SHADOW";
#endif
#ifdef GL_DELETE_STATUS
	if ( en == GL_DELETE_STATUS ) return "GL_DELETE_STATUS";
#endif
#ifdef GL_COMPILE_STATUS
	if ( en == GL_COMPILE_STATUS ) return "GL_COMPILE_STATUS";
#endif
#ifdef GL_LINK_STATUS
	if ( en == GL_LINK_STATUS ) return "GL_LINK_STATUS";
#endif
#ifdef GL_VALIDATE_STATUS
	if ( en == GL_VALIDATE_STATUS ) return "GL_VALIDATE_STATUS";
#endif
#ifdef GL_INFO_LOG_LENGTH
	if ( en == GL_INFO_LOG_LENGTH ) return "GL_INFO_LOG_LENGTH";
#endif
#ifdef GL_ATTACHED_SHADERS
	if ( en == GL_ATTACHED_SHADERS ) return "GL_ATTACHED_SHADERS";
#endif
#ifdef GL_ACTIVE_UNIFORMS
	if ( en == GL_ACTIVE_UNIFORMS ) return "GL_ACTIVE_UNIFORMS";
#endif
#ifdef GL_ACTIVE_UNIFORM_MAX_LENGTH
	if ( en == GL_ACTIVE_UNIFORM_MAX_LENGTH ) return "GL_ACTIVE_UNIFORM_MAX_LENGTH";
#endif
#ifdef GL_SHADER_SOURCE_LENGTH
	if ( en == GL_SHADER_SOURCE_LENGTH ) return "GL_SHADER_SOURCE_LENGTH";
#endif
#ifdef GL_ACTIVE_ATTRIBUTES
	if ( en == GL_ACTIVE_ATTRIBUTES ) return "GL_ACTIVE_ATTRIBUTES";
#endif
#ifdef GL_ACTIVE_ATTRIBUTE_MAX_LENGTH
	if ( en == GL_ACTIVE_ATTRIBUTE_MAX_LENGTH ) return "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH";
#endif
#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT
	if ( en == GL_FRAGMENT_SHADER_DERIVATIVE_HINT ) return "GL_FRAGMENT_SHADER_DERIVATIVE_HINT";
#endif
#ifdef GL_SHADING_LANGUAGE_VERSION
	if ( en == GL_SHADING_LANGUAGE_VERSION ) return "GL_SHADING_LANGUAGE_VERSION";
#endif
#ifdef GL_CURRENT_PROGRAM
	if ( en == GL_CURRENT_PROGRAM ) return "GL_CURRENT_PROGRAM";
#endif
#ifdef GL_POINT_SPRITE_COORD_ORIGIN
	if ( en == GL_POINT_SPRITE_COORD_ORIGIN ) return "GL_POINT_SPRITE_COORD_ORIGIN";
#endif
#ifdef GL_LOWER_LEFT
	if ( en == GL_LOWER_LEFT ) return "GL_LOWER_LEFT";
#endif
#ifdef GL_UPPER_LEFT
	if ( en == GL_UPPER_LEFT ) return "GL_UPPER_LEFT";
#endif
#ifdef GL_STENCIL_BACK_REF
	if ( en == GL_STENCIL_BACK_REF ) return "GL_STENCIL_BACK_REF";
#endif
#ifdef GL_STENCIL_BACK_VALUE_MASK
	if ( en == GL_STENCIL_BACK_VALUE_MASK ) return "GL_STENCIL_BACK_VALUE_MASK";
#endif
#ifdef GL_STENCIL_BACK_WRITEMASK
	if ( en == GL_STENCIL_BACK_WRITEMASK ) return "GL_STENCIL_BACK_WRITEMASK";
#endif
#ifdef GL_CURRENT_RASTER_SECONDARY_COLOR
	if ( en == GL_CURRENT_RASTER_SECONDARY_COLOR ) return "GL_CURRENT_RASTER_SECONDARY_COLOR";
#endif
#ifdef GL_PIXEL_PACK_BUFFER
	if ( en == GL_PIXEL_PACK_BUFFER ) return "GL_PIXEL_PACK_BUFFER";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER
	if ( en == GL_PIXEL_UNPACK_BUFFER ) return "GL_PIXEL_UNPACK_BUFFER";
#endif
#ifdef GL_PIXEL_PACK_BUFFER_BINDING
	if ( en == GL_PIXEL_PACK_BUFFER_BINDING ) return "GL_PIXEL_PACK_BUFFER_BINDING";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING
	if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING ) return "GL_PIXEL_UNPACK_BUFFER_BINDING";
#endif
#ifdef GL_FLOAT_MAT2x3
	if ( en == GL_FLOAT_MAT2x3 ) return "GL_FLOAT_MAT2x3";
#endif
#ifdef GL_FLOAT_MAT2x4
	if ( en == GL_FLOAT_MAT2x4 ) return "GL_FLOAT_MAT2x4";
#endif
#ifdef GL_FLOAT_MAT3x2
	if ( en == GL_FLOAT_MAT3x2 ) return "GL_FLOAT_MAT3x2";
#endif
#ifdef GL_FLOAT_MAT3x4
	if ( en == GL_FLOAT_MAT3x4 ) return "GL_FLOAT_MAT3x4";
#endif
#ifdef GL_FLOAT_MAT4x2
	if ( en == GL_FLOAT_MAT4x2 ) return "GL_FLOAT_MAT4x2";
#endif
#ifdef GL_FLOAT_MAT4x3
	if ( en == GL_FLOAT_MAT4x3 ) return "GL_FLOAT_MAT4x3";
#endif
#ifdef GL_SRGB
	if ( en == GL_SRGB ) return "GL_SRGB";
#endif
#ifdef GL_SRGB8
	if ( en == GL_SRGB8 ) return "GL_SRGB8";
#endif
#ifdef GL_SRGB_ALPHA
	if ( en == GL_SRGB_ALPHA ) return "GL_SRGB_ALPHA";
#endif
#ifdef GL_SRGB8_ALPHA8
	if ( en == GL_SRGB8_ALPHA8 ) return "GL_SRGB8_ALPHA8";
#endif
#ifdef GL_SLUMINANCE_ALPHA
	if ( en == GL_SLUMINANCE_ALPHA ) return "GL_SLUMINANCE_ALPHA";
#endif
#ifdef GL_SLUMINANCE8_ALPHA8
	if ( en == GL_SLUMINANCE8_ALPHA8 ) return "GL_SLUMINANCE8_ALPHA8";
#endif
#ifdef GL_SLUMINANCE
	if ( en == GL_SLUMINANCE ) return "GL_SLUMINANCE";
#endif
#ifdef GL_SLUMINANCE8
	if ( en == GL_SLUMINANCE8 ) return "GL_SLUMINANCE8";
#endif
#ifdef GL_COMPRESSED_SRGB
	if ( en == GL_COMPRESSED_SRGB ) return "GL_COMPRESSED_SRGB";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA
	if ( en == GL_COMPRESSED_SRGB_ALPHA ) return "GL_COMPRESSED_SRGB_ALPHA";
#endif
#ifdef GL_COMPRESSED_SLUMINANCE
	if ( en == GL_COMPRESSED_SLUMINANCE ) return "GL_COMPRESSED_SLUMINANCE";
#endif
#ifdef GL_COMPRESSED_SLUMINANCE_ALPHA
	if ( en == GL_COMPRESSED_SLUMINANCE_ALPHA ) return "GL_COMPRESSED_SLUMINANCE_ALPHA";
#endif
#ifdef GL_MAX_CLIP_DISTANCES
	if ( en == GL_MAX_CLIP_DISTANCES ) return "GL_MAX_CLIP_DISTANCES";
#endif
#ifdef GL_CLIP_DISTANCE5
	if ( en == GL_CLIP_DISTANCE5 ) return "GL_CLIP_DISTANCE5";
#endif
#ifdef GL_CLIP_DISTANCE1
	if ( en == GL_CLIP_DISTANCE1 ) return "GL_CLIP_DISTANCE1";
#endif
#ifdef GL_CLIP_DISTANCE3
	if ( en == GL_CLIP_DISTANCE3 ) return "GL_CLIP_DISTANCE3";
#endif
#ifdef GL_COMPARE_REF_TO_TEXTURE
	if ( en == GL_COMPARE_REF_TO_TEXTURE ) return "GL_COMPARE_REF_TO_TEXTURE";
#endif
#ifdef GL_CLIP_DISTANCE0
	if ( en == GL_CLIP_DISTANCE0 ) return "GL_CLIP_DISTANCE0";
#endif
#ifdef GL_CLIP_DISTANCE4
	if ( en == GL_CLIP_DISTANCE4 ) return "GL_CLIP_DISTANCE4";
#endif
#ifdef GL_CLIP_DISTANCE2
	if ( en == GL_CLIP_DISTANCE2 ) return "GL_CLIP_DISTANCE2";
#endif
#ifdef GL_MAX_VARYING_COMPONENTS
	if ( en == GL_MAX_VARYING_COMPONENTS ) return "GL_MAX_VARYING_COMPONENTS";
#endif
#ifdef GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT
	if ( en == GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT ) return "GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT";
#endif
#ifdef GL_MAJOR_VERSION
	if ( en == GL_MAJOR_VERSION ) return "GL_MAJOR_VERSION";
#endif
#ifdef GL_MINOR_VERSION
	if ( en == GL_MINOR_VERSION ) return "GL_MINOR_VERSION";
#endif
#ifdef GL_NUM_EXTENSIONS
	if ( en == GL_NUM_EXTENSIONS ) return "GL_NUM_EXTENSIONS";
#endif
#ifdef GL_CONTEXT_FLAGS
	if ( en == GL_CONTEXT_FLAGS ) return "GL_CONTEXT_FLAGS";
#endif
#ifdef GL_DEPTH_BUFFER
	if ( en == GL_DEPTH_BUFFER ) return "GL_DEPTH_BUFFER";
#endif
#ifdef GL_STENCIL_BUFFER
	if ( en == GL_STENCIL_BUFFER ) return "GL_STENCIL_BUFFER";
#endif
#ifdef GL_RGBA32F
	if ( en == GL_RGBA32F ) return "GL_RGBA32F";
#endif
#ifdef GL_RGB32F
	if ( en == GL_RGB32F ) return "GL_RGB32F";
#endif
#ifdef GL_RGBA16F
	if ( en == GL_RGBA16F ) return "GL_RGBA16F";
#endif
#ifdef GL_RGB16F
	if ( en == GL_RGB16F ) return "GL_RGB16F";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER
	if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER ) return "GL_VERTEX_ATTRIB_ARRAY_INTEGER";
#endif
#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS
	if ( en == GL_MAX_ARRAY_TEXTURE_LAYERS ) return "GL_MAX_ARRAY_TEXTURE_LAYERS";
#endif
#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET
	if ( en == GL_MIN_PROGRAM_TEXEL_OFFSET ) return "GL_MIN_PROGRAM_TEXEL_OFFSET";
#endif
#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET
	if ( en == GL_MAX_PROGRAM_TEXEL_OFFSET ) return "GL_MAX_PROGRAM_TEXEL_OFFSET";
#endif
#ifdef GL_CLAMP_VERTEX_COLOR
	if ( en == GL_CLAMP_VERTEX_COLOR ) return "GL_CLAMP_VERTEX_COLOR";
#endif
#ifdef GL_CLAMP_FRAGMENT_COLOR
	if ( en == GL_CLAMP_FRAGMENT_COLOR ) return "GL_CLAMP_FRAGMENT_COLOR";
#endif
#ifdef GL_CLAMP_READ_COLOR
	if ( en == GL_CLAMP_READ_COLOR ) return "GL_CLAMP_READ_COLOR";
#endif
#ifdef GL_FIXED_ONLY
	if ( en == GL_FIXED_ONLY ) return "GL_FIXED_ONLY";
#endif
#ifdef GL_TEXTURE_RED_TYPE
	if ( en == GL_TEXTURE_RED_TYPE ) return "GL_TEXTURE_RED_TYPE";
#endif
#ifdef GL_TEXTURE_GREEN_TYPE
	if ( en == GL_TEXTURE_GREEN_TYPE ) return "GL_TEXTURE_GREEN_TYPE";
#endif
#ifdef GL_TEXTURE_BLUE_TYPE
	if ( en == GL_TEXTURE_BLUE_TYPE ) return "GL_TEXTURE_BLUE_TYPE";
#endif
#ifdef GL_TEXTURE_ALPHA_TYPE
	if ( en == GL_TEXTURE_ALPHA_TYPE ) return "GL_TEXTURE_ALPHA_TYPE";
#endif
#ifdef GL_TEXTURE_LUMINANCE_TYPE
	if ( en == GL_TEXTURE_LUMINANCE_TYPE ) return "GL_TEXTURE_LUMINANCE_TYPE";
#endif
#ifdef GL_TEXTURE_INTENSITY_TYPE
	if ( en == GL_TEXTURE_INTENSITY_TYPE ) return "GL_TEXTURE_INTENSITY_TYPE";
#endif
#ifdef GL_TEXTURE_DEPTH_TYPE
	if ( en == GL_TEXTURE_DEPTH_TYPE ) return "GL_TEXTURE_DEPTH_TYPE";
#endif
#ifdef GL_TEXTURE_1D_ARRAY
	if ( en == GL_TEXTURE_1D_ARRAY ) return "GL_TEXTURE_1D_ARRAY";
#endif
#ifdef GL_PROXY_TEXTURE_1D_ARRAY
	if ( en == GL_PROXY_TEXTURE_1D_ARRAY ) return "GL_PROXY_TEXTURE_1D_ARRAY";
#endif
#ifdef GL_TEXTURE_2D_ARRAY
	if ( en == GL_TEXTURE_2D_ARRAY ) return "GL_TEXTURE_2D_ARRAY";
#endif
#ifdef GL_PROXY_TEXTURE_2D_ARRAY
	if ( en == GL_PROXY_TEXTURE_2D_ARRAY ) return "GL_PROXY_TEXTURE_2D_ARRAY";
#endif
#ifdef GL_TEXTURE_BINDING_1D_ARRAY
	if ( en == GL_TEXTURE_BINDING_1D_ARRAY ) return "GL_TEXTURE_BINDING_1D_ARRAY";
#endif
#ifdef GL_TEXTURE_BINDING_2D_ARRAY
	if ( en == GL_TEXTURE_BINDING_2D_ARRAY ) return "GL_TEXTURE_BINDING_2D_ARRAY";
#endif
#ifdef GL_R11F_G11F_B10F
	if ( en == GL_R11F_G11F_B10F ) return "GL_R11F_G11F_B10F";
#endif
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV ) return "GL_UNSIGNED_INT_10F_11F_11F_REV";
#endif
#ifdef GL_RGB9_E5
	if ( en == GL_RGB9_E5 ) return "GL_RGB9_E5";
#endif
#ifdef GL_UNSIGNED_INT_5_9_9_9_REV
	if ( en == GL_UNSIGNED_INT_5_9_9_9_REV ) return "GL_UNSIGNED_INT_5_9_9_9_REV";
#endif
#ifdef GL_TEXTURE_SHARED_SIZE
	if ( en == GL_TEXTURE_SHARED_SIZE ) return "GL_TEXTURE_SHARED_SIZE";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH
	if ( en == GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH ) return "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE ) return "GL_TRANSFORM_FEEDBACK_BUFFER_MODE";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS
	if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS ) return "GL_TRANSFORM_FEEDBACK_VARYINGS";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START ) return "GL_TRANSFORM_FEEDBACK_BUFFER_START";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE ) return "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE";
#endif
#ifdef GL_PRIMITIVES_GENERATED
	if ( en == GL_PRIMITIVES_GENERATED ) return "GL_PRIMITIVES_GENERATED";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN
	if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN ) return "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN";
#endif
#ifdef GL_RASTERIZER_DISCARD
	if ( en == GL_RASTERIZER_DISCARD ) return "GL_RASTERIZER_DISCARD";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS ) return "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS";
#endif
#ifdef GL_INTERLEAVED_ATTRIBS
	if ( en == GL_INTERLEAVED_ATTRIBS ) return "GL_INTERLEAVED_ATTRIBS";
#endif
#ifdef GL_SEPARATE_ATTRIBS
	if ( en == GL_SEPARATE_ATTRIBS ) return "GL_SEPARATE_ATTRIBS";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER ) return "GL_TRANSFORM_FEEDBACK_BUFFER";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING ) return "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING";
#endif
#ifdef GL_RGBA32UI
	if ( en == GL_RGBA32UI ) return "GL_RGBA32UI";
#endif
#ifdef GL_RGB32UI
	if ( en == GL_RGB32UI ) return "GL_RGB32UI";
#endif
#ifdef GL_RGBA16UI
	if ( en == GL_RGBA16UI ) return "GL_RGBA16UI";
#endif
#ifdef GL_RGB16UI
	if ( en == GL_RGB16UI ) return "GL_RGB16UI";
#endif
#ifdef GL_RGBA8UI
	if ( en == GL_RGBA8UI ) return "GL_RGBA8UI";
#endif
#ifdef GL_RGB8UI
	if ( en == GL_RGB8UI ) return "GL_RGB8UI";
#endif
#ifdef GL_RGBA32I
	if ( en == GL_RGBA32I ) return "GL_RGBA32I";
#endif
#ifdef GL_RGB32I
	if ( en == GL_RGB32I ) return "GL_RGB32I";
#endif
#ifdef GL_RGBA16I
	if ( en == GL_RGBA16I ) return "GL_RGBA16I";
#endif
#ifdef GL_RGB16I
	if ( en == GL_RGB16I ) return "GL_RGB16I";
#endif
#ifdef GL_RGBA8I
	if ( en == GL_RGBA8I ) return "GL_RGBA8I";
#endif
#ifdef GL_RGB8I
	if ( en == GL_RGB8I ) return "GL_RGB8I";
#endif
#ifdef GL_RED_INTEGER
	if ( en == GL_RED_INTEGER ) return "GL_RED_INTEGER";
#endif
#ifdef GL_GREEN_INTEGER
	if ( en == GL_GREEN_INTEGER ) return "GL_GREEN_INTEGER";
#endif
#ifdef GL_BLUE_INTEGER
	if ( en == GL_BLUE_INTEGER ) return "GL_BLUE_INTEGER";
#endif
#ifdef GL_ALPHA_INTEGER
	if ( en == GL_ALPHA_INTEGER ) return "GL_ALPHA_INTEGER";
#endif
#ifdef GL_RGB_INTEGER
	if ( en == GL_RGB_INTEGER ) return "GL_RGB_INTEGER";
#endif
#ifdef GL_RGBA_INTEGER
	if ( en == GL_RGBA_INTEGER ) return "GL_RGBA_INTEGER";
#endif
#ifdef GL_BGR_INTEGER
	if ( en == GL_BGR_INTEGER ) return "GL_BGR_INTEGER";
#endif
#ifdef GL_BGRA_INTEGER
	if ( en == GL_BGRA_INTEGER ) return "GL_BGRA_INTEGER";
#endif
#ifdef GL_SAMPLER_1D_ARRAY
	if ( en == GL_SAMPLER_1D_ARRAY ) return "GL_SAMPLER_1D_ARRAY";
#endif
#ifdef GL_SAMPLER_2D_ARRAY
	if ( en == GL_SAMPLER_2D_ARRAY ) return "GL_SAMPLER_2D_ARRAY";
#endif
#ifdef GL_SAMPLER_1D_ARRAY_SHADOW
	if ( en == GL_SAMPLER_1D_ARRAY_SHADOW ) return "GL_SAMPLER_1D_ARRAY_SHADOW";
#endif
#ifdef GL_SAMPLER_2D_ARRAY_SHADOW
	if ( en == GL_SAMPLER_2D_ARRAY_SHADOW ) return "GL_SAMPLER_2D_ARRAY_SHADOW";
#endif
#ifdef GL_SAMPLER_CUBE_SHADOW
	if ( en == GL_SAMPLER_CUBE_SHADOW ) return "GL_SAMPLER_CUBE_SHADOW";
#endif
#ifdef GL_UNSIGNED_INT_VEC2
	if ( en == GL_UNSIGNED_INT_VEC2 ) return "GL_UNSIGNED_INT_VEC2";
#endif
#ifdef GL_UNSIGNED_INT_VEC3
	if ( en == GL_UNSIGNED_INT_VEC3 ) return "GL_UNSIGNED_INT_VEC3";
#endif
#ifdef GL_UNSIGNED_INT_VEC4
	if ( en == GL_UNSIGNED_INT_VEC4 ) return "GL_UNSIGNED_INT_VEC4";
#endif
#ifdef GL_INT_SAMPLER_1D
	if ( en == GL_INT_SAMPLER_1D ) return "GL_INT_SAMPLER_1D";
#endif
#ifdef GL_INT_SAMPLER_2D
	if ( en == GL_INT_SAMPLER_2D ) return "GL_INT_SAMPLER_2D";
#endif
#ifdef GL_INT_SAMPLER_3D
	if ( en == GL_INT_SAMPLER_3D ) return "GL_INT_SAMPLER_3D";
#endif
#ifdef GL_INT_SAMPLER_CUBE
	if ( en == GL_INT_SAMPLER_CUBE ) return "GL_INT_SAMPLER_CUBE";
#endif
#ifdef GL_INT_SAMPLER_1D_ARRAY
	if ( en == GL_INT_SAMPLER_1D_ARRAY ) return "GL_INT_SAMPLER_1D_ARRAY";
#endif
#ifdef GL_INT_SAMPLER_2D_ARRAY
	if ( en == GL_INT_SAMPLER_2D_ARRAY ) return "GL_INT_SAMPLER_2D_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D
	if ( en == GL_UNSIGNED_INT_SAMPLER_1D ) return "GL_UNSIGNED_INT_SAMPLER_1D";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D ) return "GL_UNSIGNED_INT_SAMPLER_2D";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_3D
	if ( en == GL_UNSIGNED_INT_SAMPLER_3D ) return "GL_UNSIGNED_INT_SAMPLER_3D";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE
	if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE ) return "GL_UNSIGNED_INT_SAMPLER_CUBE";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY
	if ( en == GL_UNSIGNED_INT_SAMPLER_1D_ARRAY ) return "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_ARRAY ) return "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY";
#endif
#ifdef GL_QUERY_WAIT
	if ( en == GL_QUERY_WAIT ) return "GL_QUERY_WAIT";
#endif
#ifdef GL_QUERY_NO_WAIT
	if ( en == GL_QUERY_NO_WAIT ) return "GL_QUERY_NO_WAIT";
#endif
#ifdef GL_QUERY_BY_REGION_WAIT
	if ( en == GL_QUERY_BY_REGION_WAIT ) return "GL_QUERY_BY_REGION_WAIT";
#endif
#ifdef GL_QUERY_BY_REGION_NO_WAIT
	if ( en == GL_QUERY_BY_REGION_NO_WAIT ) return "GL_QUERY_BY_REGION_NO_WAIT";
#endif
#ifdef GL_TEXTURE_RECTANGLE
	if ( en == GL_TEXTURE_RECTANGLE ) return "GL_TEXTURE_RECTANGLE";
#endif
#ifdef GL_TEXTURE_BINDING_RECTANGLE
	if ( en == GL_TEXTURE_BINDING_RECTANGLE ) return "GL_TEXTURE_BINDING_RECTANGLE";
#endif
#ifdef GL_PROXY_TEXTURE_RECTANGLE
	if ( en == GL_PROXY_TEXTURE_RECTANGLE ) return "GL_PROXY_TEXTURE_RECTANGLE";
#endif
#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE
	if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE ) return "GL_MAX_RECTANGLE_TEXTURE_SIZE";
#endif
#ifdef GL_SAMPLER_2D_RECT
	if ( en == GL_SAMPLER_2D_RECT ) return "GL_SAMPLER_2D_RECT";
#endif
#ifdef GL_SAMPLER_2D_RECT_SHADOW
	if ( en == GL_SAMPLER_2D_RECT_SHADOW ) return "GL_SAMPLER_2D_RECT_SHADOW";
#endif
#ifdef GL_TEXTURE_BUFFER
	if ( en == GL_TEXTURE_BUFFER ) return "GL_TEXTURE_BUFFER";
#endif
#ifdef GL_MAX_TEXTURE_BUFFER_SIZE
	if ( en == GL_MAX_TEXTURE_BUFFER_SIZE ) return "GL_MAX_TEXTURE_BUFFER_SIZE";
#endif
#ifdef GL_TEXTURE_BINDING_BUFFER
	if ( en == GL_TEXTURE_BINDING_BUFFER ) return "GL_TEXTURE_BINDING_BUFFER";
#endif
#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING
	if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING ) return "GL_TEXTURE_BUFFER_DATA_STORE_BINDING";
#endif
#ifdef GL_TEXTURE_BUFFER_FORMAT
	if ( en == GL_TEXTURE_BUFFER_FORMAT ) return "GL_TEXTURE_BUFFER_FORMAT";
#endif
#ifdef GL_SAMPLER_BUFFER
	if ( en == GL_SAMPLER_BUFFER ) return "GL_SAMPLER_BUFFER";
#endif
#ifdef GL_INT_SAMPLER_2D_RECT
	if ( en == GL_INT_SAMPLER_2D_RECT ) return "GL_INT_SAMPLER_2D_RECT";
#endif
#ifdef GL_INT_SAMPLER_BUFFER
	if ( en == GL_INT_SAMPLER_BUFFER ) return "GL_INT_SAMPLER_BUFFER";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_RECT ) return "GL_UNSIGNED_INT_SAMPLER_2D_RECT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER
	if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER ) return "GL_UNSIGNED_INT_SAMPLER_BUFFER";
#endif
#ifdef GL_RED_SNORM
	if ( en == GL_RED_SNORM ) return "GL_RED_SNORM";
#endif
#ifdef GL_RG_SNORM
	if ( en == GL_RG_SNORM ) return "GL_RG_SNORM";
#endif
#ifdef GL_RGB_SNORM
	if ( en == GL_RGB_SNORM ) return "GL_RGB_SNORM";
#endif
#ifdef GL_RGBA_SNORM
	if ( en == GL_RGBA_SNORM ) return "GL_RGBA_SNORM";
#endif
#ifdef GL_R8_SNORM
	if ( en == GL_R8_SNORM ) return "GL_R8_SNORM";
#endif
#ifdef GL_RG8_SNORM
	if ( en == GL_RG8_SNORM ) return "GL_RG8_SNORM";
#endif
#ifdef GL_RGB8_SNORM
	if ( en == GL_RGB8_SNORM ) return "GL_RGB8_SNORM";
#endif
#ifdef GL_RGBA8_SNORM
	if ( en == GL_RGBA8_SNORM ) return "GL_RGBA8_SNORM";
#endif
#ifdef GL_R16_SNORM
	if ( en == GL_R16_SNORM ) return "GL_R16_SNORM";
#endif
#ifdef GL_RG16_SNORM
	if ( en == GL_RG16_SNORM ) return "GL_RG16_SNORM";
#endif
#ifdef GL_RGB16_SNORM
	if ( en == GL_RGB16_SNORM ) return "GL_RGB16_SNORM";
#endif
#ifdef GL_RGBA16_SNORM
	if ( en == GL_RGBA16_SNORM ) return "GL_RGBA16_SNORM";
#endif
#ifdef GL_SIGNED_NORMALIZED
	if ( en == GL_SIGNED_NORMALIZED ) return "GL_SIGNED_NORMALIZED";
#endif
#ifdef GL_PRIMITIVE_RESTART
	if ( en == GL_PRIMITIVE_RESTART ) return "GL_PRIMITIVE_RESTART";
#endif
#ifdef GL_PRIMITIVE_RESTART_INDEX
	if ( en == GL_PRIMITIVE_RESTART_INDEX ) return "GL_PRIMITIVE_RESTART_INDEX";
#endif
#ifdef GL_BUFFER_ACCESS_FLAGS
	if ( en == GL_BUFFER_ACCESS_FLAGS ) return "GL_BUFFER_ACCESS_FLAGS";
#endif
#ifdef GL_BUFFER_MAP_LENGTH
	if ( en == GL_BUFFER_MAP_LENGTH ) return "GL_BUFFER_MAP_LENGTH";
#endif
#ifdef GL_BUFFER_MAP_OFFSET
	if ( en == GL_BUFFER_MAP_OFFSET ) return "GL_BUFFER_MAP_OFFSET";
#endif
#ifdef GL_CONTEXT_CORE_PROFILE_BIT
	if ( en == GL_CONTEXT_CORE_PROFILE_BIT ) return "GL_CONTEXT_CORE_PROFILE_BIT";
#endif
#ifdef GL_CONTEXT_COMPATIBILITY_PROFILE_BIT
	if ( en == GL_CONTEXT_COMPATIBILITY_PROFILE_BIT ) return "GL_CONTEXT_COMPATIBILITY_PROFILE_BIT";
#endif
#ifdef GL_LINES_ADJACENCY
	if ( en == GL_LINES_ADJACENCY ) return "GL_LINES_ADJACENCY";
#endif
#ifdef GL_LINE_STRIP_ADJACENCY
	if ( en == GL_LINE_STRIP_ADJACENCY ) return "GL_LINE_STRIP_ADJACENCY";
#endif
#ifdef GL_TRIANGLES_ADJACENCY
	if ( en == GL_TRIANGLES_ADJACENCY ) return "GL_TRIANGLES_ADJACENCY";
#endif
#ifdef GL_TRIANGLE_STRIP_ADJACENCY
	if ( en == GL_TRIANGLE_STRIP_ADJACENCY ) return "GL_TRIANGLE_STRIP_ADJACENCY";
#endif
#ifdef GL_PROGRAM_POINT_SIZE
	if ( en == GL_PROGRAM_POINT_SIZE ) return "GL_PROGRAM_POINT_SIZE";
#endif
#ifdef GL_GEOMETRY_VERTICES_OUT
	if ( en == GL_GEOMETRY_VERTICES_OUT ) return "GL_GEOMETRY_VERTICES_OUT";
#endif
#ifdef GL_GEOMETRY_INPUT_TYPE
	if ( en == GL_GEOMETRY_INPUT_TYPE ) return "GL_GEOMETRY_INPUT_TYPE";
#endif
#ifdef GL_GEOMETRY_OUTPUT_TYPE
	if ( en == GL_GEOMETRY_OUTPUT_TYPE ) return "GL_GEOMETRY_OUTPUT_TYPE";
#endif
#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS ) return "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED ) return "GL_FRAMEBUFFER_ATTACHMENT_LAYERED";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS ) return "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS";
#endif
#ifdef GL_GEOMETRY_SHADER
	if ( en == GL_GEOMETRY_SHADER ) return "GL_GEOMETRY_SHADER";
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS
	if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS ) return "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES
	if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES ) return "GL_MAX_GEOMETRY_OUTPUT_VERTICES";
#endif
#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS
	if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS ) return "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS";
#endif
#ifdef GL_MAX_VERTEX_OUTPUT_COMPONENTS
	if ( en == GL_MAX_VERTEX_OUTPUT_COMPONENTS ) return "GL_MAX_VERTEX_OUTPUT_COMPONENTS";
#endif
#ifdef GL_MAX_GEOMETRY_INPUT_COMPONENTS
	if ( en == GL_MAX_GEOMETRY_INPUT_COMPONENTS ) return "GL_MAX_GEOMETRY_INPUT_COMPONENTS";
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_COMPONENTS
	if ( en == GL_MAX_GEOMETRY_OUTPUT_COMPONENTS ) return "GL_MAX_GEOMETRY_OUTPUT_COMPONENTS";
#endif
#ifdef GL_MAX_FRAGMENT_INPUT_COMPONENTS
	if ( en == GL_MAX_FRAGMENT_INPUT_COMPONENTS ) return "GL_MAX_FRAGMENT_INPUT_COMPONENTS";
#endif
#ifdef GL_CONTEXT_PROFILE_MASK
	if ( en == GL_CONTEXT_PROFILE_MASK ) return "GL_CONTEXT_PROFILE_MASK";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR
	if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR ) return "GL_VERTEX_ATTRIB_ARRAY_DIVISOR";
#endif
#ifdef GL_RGB10_A2UI
	if ( en == GL_RGB10_A2UI ) return "GL_RGB10_A2UI";
#endif
#ifdef GL_SAMPLE_SHADING
	if ( en == GL_SAMPLE_SHADING ) return "GL_SAMPLE_SHADING";
#endif
#ifdef GL_MIN_SAMPLE_SHADING_VALUE
	if ( en == GL_MIN_SAMPLE_SHADING_VALUE ) return "GL_MIN_SAMPLE_SHADING_VALUE";
#endif
#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET
	if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET ) return "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET";
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET
	if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET ) return "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET";
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS
	if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS ) return "GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_ARRAY
	if ( en == GL_TEXTURE_CUBE_MAP_ARRAY ) return "GL_TEXTURE_CUBE_MAP_ARRAY";
#endif
#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY
	if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARRAY ) return "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARRAY
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARRAY ) return "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY";
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY
	if ( en == GL_SAMPLER_CUBE_MAP_ARRAY ) return "GL_SAMPLER_CUBE_MAP_ARRAY";
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW
	if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW ) return "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW";
#endif
#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY
	if ( en == GL_INT_SAMPLER_CUBE_MAP_ARRAY ) return "GL_INT_SAMPLER_CUBE_MAP_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY
	if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY ) return "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY";
#endif
#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM
	if ( en == GL_COMPRESSED_RGBA_BPTC_UNORM ) return "GL_COMPRESSED_RGBA_BPTC_UNORM";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM
	if ( en == GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM ) return "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM";
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT
	if ( en == GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT ) return "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT";
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT
	if ( en == GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT ) return "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT";
#endif
#ifdef GL_NUM_SHADING_LANGUAGE_VERSIONS
	if ( en == GL_NUM_SHADING_LANGUAGE_VERSIONS ) return "GL_NUM_SHADING_LANGUAGE_VERSIONS";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_LONG
	if ( en == GL_VERTEX_ATTRIB_ARRAY_LONG ) return "GL_VERTEX_ATTRIB_ARRAY_LONG";
#endif
#ifdef GL_MAX_VERTEX_ATTRIB_STRIDE
	if ( en == GL_MAX_VERTEX_ATTRIB_STRIDE ) return "GL_MAX_VERTEX_ATTRIB_STRIDE";
#endif
#ifdef GL_MULTISAMPLE_3DFX
	if ( en == GL_MULTISAMPLE_3DFX ) return "GL_MULTISAMPLE_3DFX";
#endif
#ifdef GL_SAMPLE_BUFFERS_3DFX
	if ( en == GL_SAMPLE_BUFFERS_3DFX ) return "GL_SAMPLE_BUFFERS_3DFX";
#endif
#ifdef GL_SAMPLES_3DFX
	if ( en == GL_SAMPLES_3DFX ) return "GL_SAMPLES_3DFX";
#endif
#ifdef GL_MULTISAMPLE_BIT_3DFX
	if ( en == GL_MULTISAMPLE_BIT_3DFX ) return "GL_MULTISAMPLE_BIT_3DFX";
#endif
#ifdef GL_COMPRESSED_RGB_FXT1_3DFX
	if ( en == GL_COMPRESSED_RGB_FXT1_3DFX ) return "GL_COMPRESSED_RGB_FXT1_3DFX";
#endif
#ifdef GL_COMPRESSED_RGBA_FXT1_3DFX
	if ( en == GL_COMPRESSED_RGBA_FXT1_3DFX ) return "GL_COMPRESSED_RGBA_FXT1_3DFX";
#endif
#ifdef GL_FACTOR_MIN_AMD
	if ( en == GL_FACTOR_MIN_AMD ) return "GL_FACTOR_MIN_AMD";
#endif
#ifdef GL_FACTOR_MAX_AMD
	if ( en == GL_FACTOR_MAX_AMD ) return "GL_FACTOR_MAX_AMD";
#endif
#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH_AMD
	if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH_AMD ) return "GL_MAX_DEBUG_MESSAGE_LENGTH_AMD";
#endif
#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES_AMD
	if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES_AMD ) return "GL_MAX_DEBUG_LOGGED_MESSAGES_AMD";
#endif
#ifdef GL_DEBUG_LOGGED_MESSAGES_AMD
	if ( en == GL_DEBUG_LOGGED_MESSAGES_AMD ) return "GL_DEBUG_LOGGED_MESSAGES_AMD";
#endif
#ifdef GL_DEBUG_SEVERITY_HIGH_AMD
	if ( en == GL_DEBUG_SEVERITY_HIGH_AMD ) return "GL_DEBUG_SEVERITY_HIGH_AMD";
#endif
#ifdef GL_DEBUG_SEVERITY_MEDIUM_AMD
	if ( en == GL_DEBUG_SEVERITY_MEDIUM_AMD ) return "GL_DEBUG_SEVERITY_MEDIUM_AMD";
#endif
#ifdef GL_DEBUG_SEVERITY_LOW_AMD
	if ( en == GL_DEBUG_SEVERITY_LOW_AMD ) return "GL_DEBUG_SEVERITY_LOW_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_API_ERROR_AMD
	if ( en == GL_DEBUG_CATEGORY_API_ERROR_AMD ) return "GL_DEBUG_CATEGORY_API_ERROR_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD
	if ( en == GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD ) return "GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_DEPRECATION_AMD
	if ( en == GL_DEBUG_CATEGORY_DEPRECATION_AMD ) return "GL_DEBUG_CATEGORY_DEPRECATION_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD
	if ( en == GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD ) return "GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_PERFORMANCE_AMD
	if ( en == GL_DEBUG_CATEGORY_PERFORMANCE_AMD ) return "GL_DEBUG_CATEGORY_PERFORMANCE_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD
	if ( en == GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD ) return "GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_APPLICATION_AMD
	if ( en == GL_DEBUG_CATEGORY_APPLICATION_AMD ) return "GL_DEBUG_CATEGORY_APPLICATION_AMD";
#endif
#ifdef GL_DEBUG_CATEGORY_OTHER_AMD
	if ( en == GL_DEBUG_CATEGORY_OTHER_AMD ) return "GL_DEBUG_CATEGORY_OTHER_AMD";
#endif
#ifdef GL_DEPTH_CLAMP_NEAR_AMD
	if ( en == GL_DEPTH_CLAMP_NEAR_AMD ) return "GL_DEPTH_CLAMP_NEAR_AMD";
#endif
#ifdef GL_DEPTH_CLAMP_FAR_AMD
	if ( en == GL_DEPTH_CLAMP_FAR_AMD ) return "GL_DEPTH_CLAMP_FAR_AMD";
#endif
#ifdef GL_RED
	if ( en == GL_RED ) return "GL_RED";
#endif
#ifdef GL_GREEN
	if ( en == GL_GREEN ) return "GL_GREEN";
#endif
#ifdef GL_BLUE
	if ( en == GL_BLUE ) return "GL_BLUE";
#endif
#ifdef GL_ALPHA
	if ( en == GL_ALPHA ) return "GL_ALPHA";
#endif
#ifdef GL_RG8UI
	if ( en == GL_RG8UI ) return "GL_RG8UI";
#endif
#ifdef GL_RG16UI
	if ( en == GL_RG16UI ) return "GL_RG16UI";
#endif
#ifdef GL_RGBA8UI
	if ( en == GL_RGBA8UI ) return "GL_RGBA8UI";
#endif
#ifdef GL_VERTEX_ELEMENT_SWIZZLE_AMD
	if ( en == GL_VERTEX_ELEMENT_SWIZZLE_AMD ) return "GL_VERTEX_ELEMENT_SWIZZLE_AMD";
#endif
#ifdef GL_VERTEX_ID_SWIZZLE_AMD
	if ( en == GL_VERTEX_ID_SWIZZLE_AMD ) return "GL_VERTEX_ID_SWIZZLE_AMD";
#endif
#ifdef GL_DATA_BUFFER_AMD
	if ( en == GL_DATA_BUFFER_AMD ) return "GL_DATA_BUFFER_AMD";
#endif
#ifdef GL_PERFORMANCE_MONITOR_AMD
	if ( en == GL_PERFORMANCE_MONITOR_AMD ) return "GL_PERFORMANCE_MONITOR_AMD";
#endif
#ifdef GL_QUERY_OBJECT_AMD
	if ( en == GL_QUERY_OBJECT_AMD ) return "GL_QUERY_OBJECT_AMD";
#endif
#ifdef GL_VERTEX_ARRAY_OBJECT_AMD
	if ( en == GL_VERTEX_ARRAY_OBJECT_AMD ) return "GL_VERTEX_ARRAY_OBJECT_AMD";
#endif
#ifdef GL_SAMPLER_OBJECT_AMD
	if ( en == GL_SAMPLER_OBJECT_AMD ) return "GL_SAMPLER_OBJECT_AMD";
#endif
#ifdef GL_COUNTER_TYPE_AMD
	if ( en == GL_COUNTER_TYPE_AMD ) return "GL_COUNTER_TYPE_AMD";
#endif
#ifdef GL_COUNTER_RANGE_AMD
	if ( en == GL_COUNTER_RANGE_AMD ) return "GL_COUNTER_RANGE_AMD";
#endif
#ifdef GL_UNSIGNED_INT64_AMD
	if ( en == GL_UNSIGNED_INT64_AMD ) return "GL_UNSIGNED_INT64_AMD";
#endif
#ifdef GL_PERCENTAGE_AMD
	if ( en == GL_PERCENTAGE_AMD ) return "GL_PERCENTAGE_AMD";
#endif
#ifdef GL_PERFMON_RESULT_AVAILABLE_AMD
	if ( en == GL_PERFMON_RESULT_AVAILABLE_AMD ) return "GL_PERFMON_RESULT_AVAILABLE_AMD";
#endif
#ifdef GL_PERFMON_RESULT_SIZE_AMD
	if ( en == GL_PERFMON_RESULT_SIZE_AMD ) return "GL_PERFMON_RESULT_SIZE_AMD";
#endif
#ifdef GL_PERFMON_RESULT_AMD
	if ( en == GL_PERFMON_RESULT_AMD ) return "GL_PERFMON_RESULT_AMD";
#endif
#ifdef GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD
	if ( en == GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD ) return "GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD";
#endif
#ifdef GL_QUERY_BUFFER_AMD
	if ( en == GL_QUERY_BUFFER_AMD ) return "GL_QUERY_BUFFER_AMD";
#endif
#ifdef GL_QUERY_BUFFER_BINDING_AMD
	if ( en == GL_QUERY_BUFFER_BINDING_AMD ) return "GL_QUERY_BUFFER_BINDING_AMD";
#endif
#ifdef GL_QUERY_RESULT_NO_WAIT_AMD
	if ( en == GL_QUERY_RESULT_NO_WAIT_AMD ) return "GL_QUERY_RESULT_NO_WAIT_AMD";
#endif
#ifdef GL_SUBSAMPLE_DISTANCE_AMD
	if ( en == GL_SUBSAMPLE_DISTANCE_AMD ) return "GL_SUBSAMPLE_DISTANCE_AMD";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB ) return "GL_TEXTURE_CUBE_MAP_SEAMLESS_ARB";
#endif
#ifdef GL_TEXTURE_STORAGE_SPARSE_BIT_AMD
	if ( en == GL_TEXTURE_STORAGE_SPARSE_BIT_AMD ) return "GL_TEXTURE_STORAGE_SPARSE_BIT_AMD";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_X_AMD
	if ( en == GL_VIRTUAL_PAGE_SIZE_X_AMD ) return "GL_VIRTUAL_PAGE_SIZE_X_AMD";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_Y_AMD
	if ( en == GL_VIRTUAL_PAGE_SIZE_Y_AMD ) return "GL_VIRTUAL_PAGE_SIZE_Y_AMD";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_Z_AMD
	if ( en == GL_VIRTUAL_PAGE_SIZE_Z_AMD ) return "GL_VIRTUAL_PAGE_SIZE_Z_AMD";
#endif
#ifdef GL_MAX_SPARSE_TEXTURE_SIZE_AMD
	if ( en == GL_MAX_SPARSE_TEXTURE_SIZE_AMD ) return "GL_MAX_SPARSE_TEXTURE_SIZE_AMD";
#endif
#ifdef GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD
	if ( en == GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD ) return "GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD";
#endif
#ifdef GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS
	if ( en == GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS ) return "GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS";
#endif
#ifdef GL_MIN_SPARSE_LEVEL_AMD
	if ( en == GL_MIN_SPARSE_LEVEL_AMD ) return "GL_MIN_SPARSE_LEVEL_AMD";
#endif
#ifdef GL_MIN_LOD_WARNING_AMD
	if ( en == GL_MIN_LOD_WARNING_AMD ) return "GL_MIN_LOD_WARNING_AMD";
#endif
#ifdef GL_SET_AMD
	if ( en == GL_SET_AMD ) return "GL_SET_AMD";
#endif
#ifdef GL_REPLACE_VALUE_AMD
	if ( en == GL_REPLACE_VALUE_AMD ) return "GL_REPLACE_VALUE_AMD";
#endif
#ifdef GL_STENCIL_OP_VALUE_AMD
	if ( en == GL_STENCIL_OP_VALUE_AMD ) return "GL_STENCIL_OP_VALUE_AMD";
#endif
#ifdef GL_STENCIL_BACK_OP_VALUE_AMD
	if ( en == GL_STENCIL_BACK_OP_VALUE_AMD ) return "GL_STENCIL_BACK_OP_VALUE_AMD";
#endif
#ifdef GL_SAMPLER_BUFFER_AMD
	if ( en == GL_SAMPLER_BUFFER_AMD ) return "GL_SAMPLER_BUFFER_AMD";
#endif
#ifdef GL_INT_SAMPLER_BUFFER_AMD
	if ( en == GL_INT_SAMPLER_BUFFER_AMD ) return "GL_INT_SAMPLER_BUFFER_AMD";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD
	if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD ) return "GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD";
#endif
#ifdef GL_TESSELLATION_MODE_AMD
	if ( en == GL_TESSELLATION_MODE_AMD ) return "GL_TESSELLATION_MODE_AMD";
#endif
#ifdef GL_TESSELLATION_FACTOR_AMD
	if ( en == GL_TESSELLATION_FACTOR_AMD ) return "GL_TESSELLATION_FACTOR_AMD";
#endif
#ifdef GL_DISCRETE_AMD
	if ( en == GL_DISCRETE_AMD ) return "GL_DISCRETE_AMD";
#endif
#ifdef GL_CONTINUOUS_AMD
	if ( en == GL_CONTINUOUS_AMD ) return "GL_CONTINUOUS_AMD";
#endif
#ifdef GL_DRAW_FRAMEBUFFER_BINDING_ANGLE
	if ( en == GL_DRAW_FRAMEBUFFER_BINDING_ANGLE ) return "GL_DRAW_FRAMEBUFFER_BINDING_ANGLE";
#endif
#ifdef GL_READ_FRAMEBUFFER_ANGLE
	if ( en == GL_READ_FRAMEBUFFER_ANGLE ) return "GL_READ_FRAMEBUFFER_ANGLE";
#endif
#ifdef GL_DRAW_FRAMEBUFFER_ANGLE
	if ( en == GL_DRAW_FRAMEBUFFER_ANGLE ) return "GL_DRAW_FRAMEBUFFER_ANGLE";
#endif
#ifdef GL_READ_FRAMEBUFFER_BINDING_ANGLE
	if ( en == GL_READ_FRAMEBUFFER_BINDING_ANGLE ) return "GL_READ_FRAMEBUFFER_BINDING_ANGLE";
#endif
#ifdef GL_RENDERBUFFER_SAMPLES_ANGLE
	if ( en == GL_RENDERBUFFER_SAMPLES_ANGLE ) return "GL_RENDERBUFFER_SAMPLES_ANGLE";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE ) return "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_ANGLE";
#endif
#ifdef GL_MAX_SAMPLES_ANGLE
	if ( en == GL_MAX_SAMPLES_ANGLE ) return "GL_MAX_SAMPLES_ANGLE";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE
	if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE ) return "GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ANGLE";
#endif
#ifdef GL_PACK_REVERSE_ROW_ORDER_ANGLE
	if ( en == GL_PACK_REVERSE_ROW_ORDER_ANGLE ) return "GL_PACK_REVERSE_ROW_ORDER_ANGLE";
#endif
#ifdef GL_PROGRAM_BINARY_ANGLE
	if ( en == GL_PROGRAM_BINARY_ANGLE ) return "GL_PROGRAM_BINARY_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGB_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT1_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT3_ANGLE";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE ) return "GL_COMPRESSED_RGBA_S3TC_DXT5_ANGLE";
#endif
#ifdef GL_TEXTURE_USAGE_ANGLE
	if ( en == GL_TEXTURE_USAGE_ANGLE ) return "GL_TEXTURE_USAGE_ANGLE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_ANGLE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_ANGLE ) return "GL_FRAMEBUFFER_ATTACHMENT_ANGLE";
#endif
#ifdef GL_QUERY_COUNTER_BITS_ANGLE
	if ( en == GL_QUERY_COUNTER_BITS_ANGLE ) return "GL_QUERY_COUNTER_BITS_ANGLE";
#endif
#ifdef GL_CURRENT_QUERY_ANGLE
	if ( en == GL_CURRENT_QUERY_ANGLE ) return "GL_CURRENT_QUERY_ANGLE";
#endif
#ifdef GL_QUERY_RESULT_ANGLE
	if ( en == GL_QUERY_RESULT_ANGLE ) return "GL_QUERY_RESULT_ANGLE";
#endif
#ifdef GL_QUERY_RESULT_AVAILABLE_ANGLE
	if ( en == GL_QUERY_RESULT_AVAILABLE_ANGLE ) return "GL_QUERY_RESULT_AVAILABLE_ANGLE";
#endif
#ifdef GL_TIME_ELAPSED_ANGLE
	if ( en == GL_TIME_ELAPSED_ANGLE ) return "GL_TIME_ELAPSED_ANGLE";
#endif
#ifdef GL_TIMESTAMP_ANGLE
	if ( en == GL_TIMESTAMP_ANGLE ) return "GL_TIMESTAMP_ANGLE";
#endif
#ifdef GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE
	if ( en == GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE ) return "GL_TRANSLATED_SHADER_SOURCE_LENGTH_ANGLE";
#endif
#ifdef GL_AUX_DEPTH_STENCIL_APPLE
	if ( en == GL_AUX_DEPTH_STENCIL_APPLE ) return "GL_AUX_DEPTH_STENCIL_APPLE";
#endif
#ifdef GL_UNPACK_CLIENT_STORAGE_APPLE
	if ( en == GL_UNPACK_CLIENT_STORAGE_APPLE ) return "GL_UNPACK_CLIENT_STORAGE_APPLE";
#endif
#ifdef GL_ELEMENT_ARRAY_APPLE
	if ( en == GL_ELEMENT_ARRAY_APPLE ) return "GL_ELEMENT_ARRAY_APPLE";
#endif
#ifdef GL_ELEMENT_ARRAY_TYPE_APPLE
	if ( en == GL_ELEMENT_ARRAY_TYPE_APPLE ) return "GL_ELEMENT_ARRAY_TYPE_APPLE";
#endif
#ifdef GL_ELEMENT_ARRAY_POINTER_APPLE
	if ( en == GL_ELEMENT_ARRAY_POINTER_APPLE ) return "GL_ELEMENT_ARRAY_POINTER_APPLE";
#endif
#ifdef GL_DRAW_PIXELS_APPLE
	if ( en == GL_DRAW_PIXELS_APPLE ) return "GL_DRAW_PIXELS_APPLE";
#endif
#ifdef GL_FENCE_APPLE
	if ( en == GL_FENCE_APPLE ) return "GL_FENCE_APPLE";
#endif
#ifdef GL_HALF_APPLE
	if ( en == GL_HALF_APPLE ) return "GL_HALF_APPLE";
#endif
#ifdef GL_RGBA_FLOAT32_APPLE
	if ( en == GL_RGBA_FLOAT32_APPLE ) return "GL_RGBA_FLOAT32_APPLE";
#endif
#ifdef GL_RGB_FLOAT32_APPLE
	if ( en == GL_RGB_FLOAT32_APPLE ) return "GL_RGB_FLOAT32_APPLE";
#endif
#ifdef GL_ALPHA_FLOAT32_APPLE
	if ( en == GL_ALPHA_FLOAT32_APPLE ) return "GL_ALPHA_FLOAT32_APPLE";
#endif
#ifdef GL_INTENSITY_FLOAT32_APPLE
	if ( en == GL_INTENSITY_FLOAT32_APPLE ) return "GL_INTENSITY_FLOAT32_APPLE";
#endif
#ifdef GL_LUMINANCE_FLOAT32_APPLE
	if ( en == GL_LUMINANCE_FLOAT32_APPLE ) return "GL_LUMINANCE_FLOAT32_APPLE";
#endif
#ifdef GL_LUMINANCE_ALPHA_FLOAT32_APPLE
	if ( en == GL_LUMINANCE_ALPHA_FLOAT32_APPLE ) return "GL_LUMINANCE_ALPHA_FLOAT32_APPLE";
#endif
#ifdef GL_RGBA_FLOAT16_APPLE
	if ( en == GL_RGBA_FLOAT16_APPLE ) return "GL_RGBA_FLOAT16_APPLE";
#endif
#ifdef GL_RGB_FLOAT16_APPLE
	if ( en == GL_RGB_FLOAT16_APPLE ) return "GL_RGB_FLOAT16_APPLE";
#endif
#ifdef GL_ALPHA_FLOAT16_APPLE
	if ( en == GL_ALPHA_FLOAT16_APPLE ) return "GL_ALPHA_FLOAT16_APPLE";
#endif
#ifdef GL_INTENSITY_FLOAT16_APPLE
	if ( en == GL_INTENSITY_FLOAT16_APPLE ) return "GL_INTENSITY_FLOAT16_APPLE";
#endif
#ifdef GL_LUMINANCE_FLOAT16_APPLE
	if ( en == GL_LUMINANCE_FLOAT16_APPLE ) return "GL_LUMINANCE_FLOAT16_APPLE";
#endif
#ifdef GL_LUMINANCE_ALPHA_FLOAT16_APPLE
	if ( en == GL_LUMINANCE_ALPHA_FLOAT16_APPLE ) return "GL_LUMINANCE_ALPHA_FLOAT16_APPLE";
#endif
#ifdef GL_COLOR_FLOAT_APPLE
	if ( en == GL_COLOR_FLOAT_APPLE ) return "GL_COLOR_FLOAT_APPLE";
#endif
#ifdef GL_BUFFER_SERIALIZED_MODIFY_APPLE
	if ( en == GL_BUFFER_SERIALIZED_MODIFY_APPLE ) return "GL_BUFFER_SERIALIZED_MODIFY_APPLE";
#endif
#ifdef GL_BUFFER_FLUSHING_UNMAP_APPLE
	if ( en == GL_BUFFER_FLUSHING_UNMAP_APPLE ) return "GL_BUFFER_FLUSHING_UNMAP_APPLE";
#endif
#ifdef GL_BUFFER_OBJECT_APPLE
	if ( en == GL_BUFFER_OBJECT_APPLE ) return "GL_BUFFER_OBJECT_APPLE";
#endif
#ifdef GL_RELEASED_APPLE
	if ( en == GL_RELEASED_APPLE ) return "GL_RELEASED_APPLE";
#endif
#ifdef GL_VOLATILE_APPLE
	if ( en == GL_VOLATILE_APPLE ) return "GL_VOLATILE_APPLE";
#endif
#ifdef GL_RETAINED_APPLE
	if ( en == GL_RETAINED_APPLE ) return "GL_RETAINED_APPLE";
#endif
#ifdef GL_UNDEFINED_APPLE
	if ( en == GL_UNDEFINED_APPLE ) return "GL_UNDEFINED_APPLE";
#endif
#ifdef GL_PURGEABLE_APPLE
	if ( en == GL_PURGEABLE_APPLE ) return "GL_PURGEABLE_APPLE";
#endif
#ifdef GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE
	if ( en == GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE ) return "GL_MIN_PBUFFER_VIEWPORT_DIMS_APPLE";
#endif
#ifdef GL_UNSIGNED_SHORT_8_8_APPLE
	if ( en == GL_UNSIGNED_SHORT_8_8_APPLE ) return "GL_UNSIGNED_SHORT_8_8_APPLE";
#endif
#ifdef GL_UNSIGNED_SHORT_8_8_REV_APPLE
	if ( en == GL_UNSIGNED_SHORT_8_8_REV_APPLE ) return "GL_UNSIGNED_SHORT_8_8_REV_APPLE";
#endif
#ifdef GL_RGB_422_APPLE
	if ( en == GL_RGB_422_APPLE ) return "GL_RGB_422_APPLE";
#endif
#ifdef GL_PACK_ROW_BYTES_APPLE
	if ( en == GL_PACK_ROW_BYTES_APPLE ) return "GL_PACK_ROW_BYTES_APPLE";
#endif
#ifdef GL_UNPACK_ROW_BYTES_APPLE
	if ( en == GL_UNPACK_ROW_BYTES_APPLE ) return "GL_UNPACK_ROW_BYTES_APPLE";
#endif
#ifdef GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE
	if ( en == GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE ) return "GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE";
#endif
#ifdef GL_TEXTURE_RANGE_LENGTH_APPLE
	if ( en == GL_TEXTURE_RANGE_LENGTH_APPLE ) return "GL_TEXTURE_RANGE_LENGTH_APPLE";
#endif
#ifdef GL_TEXTURE_RANGE_POINTER_APPLE
	if ( en == GL_TEXTURE_RANGE_POINTER_APPLE ) return "GL_TEXTURE_RANGE_POINTER_APPLE";
#endif
#ifdef GL_TEXTURE_STORAGE_HINT_APPLE
	if ( en == GL_TEXTURE_STORAGE_HINT_APPLE ) return "GL_TEXTURE_STORAGE_HINT_APPLE";
#endif
#ifdef GL_STORAGE_PRIVATE_APPLE
	if ( en == GL_STORAGE_PRIVATE_APPLE ) return "GL_STORAGE_PRIVATE_APPLE";
#endif
#ifdef GL_STORAGE_CACHED_APPLE
	if ( en == GL_STORAGE_CACHED_APPLE ) return "GL_STORAGE_CACHED_APPLE";
#endif
#ifdef GL_STORAGE_SHARED_APPLE
	if ( en == GL_STORAGE_SHARED_APPLE ) return "GL_STORAGE_SHARED_APPLE";
#endif
#ifdef GL_TRANSFORM_HINT_APPLE
	if ( en == GL_TRANSFORM_HINT_APPLE ) return "GL_TRANSFORM_HINT_APPLE";
#endif
#ifdef GL_VERTEX_ARRAY_BINDING_APPLE
	if ( en == GL_VERTEX_ARRAY_BINDING_APPLE ) return "GL_VERTEX_ARRAY_BINDING_APPLE";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_APPLE
	if ( en == GL_VERTEX_ARRAY_RANGE_APPLE ) return "GL_VERTEX_ARRAY_RANGE_APPLE";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE
	if ( en == GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE ) return "GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE";
#endif
#ifdef GL_VERTEX_ARRAY_STORAGE_HINT_APPLE
	if ( en == GL_VERTEX_ARRAY_STORAGE_HINT_APPLE ) return "GL_VERTEX_ARRAY_STORAGE_HINT_APPLE";
#endif
#ifdef GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE
	if ( en == GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE ) return "GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_POINTER_APPLE
	if ( en == GL_VERTEX_ARRAY_RANGE_POINTER_APPLE ) return "GL_VERTEX_ARRAY_RANGE_POINTER_APPLE";
#endif
#ifdef GL_STORAGE_CLIENT_APPLE
	if ( en == GL_STORAGE_CLIENT_APPLE ) return "GL_STORAGE_CLIENT_APPLE";
#endif
#ifdef GL_STORAGE_CACHED_APPLE
	if ( en == GL_STORAGE_CACHED_APPLE ) return "GL_STORAGE_CACHED_APPLE";
#endif
#ifdef GL_STORAGE_SHARED_APPLE
	if ( en == GL_STORAGE_SHARED_APPLE ) return "GL_STORAGE_SHARED_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP1_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP1_APPLE ) return "GL_VERTEX_ATTRIB_MAP1_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP2_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP2_APPLE ) return "GL_VERTEX_ATTRIB_MAP2_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE ) return "GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE ) return "GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE ) return "GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE ) return "GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE ) return "GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE ) return "GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE ) return "GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE";
#endif
#ifdef GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE
	if ( en == GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE ) return "GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE";
#endif
#ifdef GL_YCBCR_422_APPLE
	if ( en == GL_YCBCR_422_APPLE ) return "GL_YCBCR_422_APPLE";
#endif
#ifdef GL_FIXED
	if ( en == GL_FIXED ) return "GL_FIXED";
#endif
#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE
	if ( en == GL_IMPLEMENTATION_COLOR_READ_TYPE ) return "GL_IMPLEMENTATION_COLOR_READ_TYPE";
#endif
#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT
	if ( en == GL_IMPLEMENTATION_COLOR_READ_FORMAT ) return "GL_IMPLEMENTATION_COLOR_READ_FORMAT";
#endif
#ifdef GL_RGB565
	if ( en == GL_RGB565 ) return "GL_RGB565";
#endif
#ifdef GL_LOW_FLOAT
	if ( en == GL_LOW_FLOAT ) return "GL_LOW_FLOAT";
#endif
#ifdef GL_MEDIUM_FLOAT
	if ( en == GL_MEDIUM_FLOAT ) return "GL_MEDIUM_FLOAT";
#endif
#ifdef GL_HIGH_FLOAT
	if ( en == GL_HIGH_FLOAT ) return "GL_HIGH_FLOAT";
#endif
#ifdef GL_LOW_INT
	if ( en == GL_LOW_INT ) return "GL_LOW_INT";
#endif
#ifdef GL_MEDIUM_INT
	if ( en == GL_MEDIUM_INT ) return "GL_MEDIUM_INT";
#endif
#ifdef GL_HIGH_INT
	if ( en == GL_HIGH_INT ) return "GL_HIGH_INT";
#endif
#ifdef GL_SHADER_BINARY_FORMATS
	if ( en == GL_SHADER_BINARY_FORMATS ) return "GL_SHADER_BINARY_FORMATS";
#endif
#ifdef GL_NUM_SHADER_BINARY_FORMATS
	if ( en == GL_NUM_SHADER_BINARY_FORMATS ) return "GL_NUM_SHADER_BINARY_FORMATS";
#endif
#ifdef GL_SHADER_COMPILER
	if ( en == GL_SHADER_COMPILER ) return "GL_SHADER_COMPILER";
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_VECTORS
	if ( en == GL_MAX_VERTEX_UNIFORM_VECTORS ) return "GL_MAX_VERTEX_UNIFORM_VECTORS";
#endif
#ifdef GL_MAX_VARYING_VECTORS
	if ( en == GL_MAX_VARYING_VECTORS ) return "GL_MAX_VARYING_VECTORS";
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_VECTORS
	if ( en == GL_MAX_FRAGMENT_UNIFORM_VECTORS ) return "GL_MAX_FRAGMENT_UNIFORM_VECTORS";
#endif
#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	if ( en == GL_TEXTURE_IMMUTABLE_LEVELS ) return "GL_TEXTURE_IMMUTABLE_LEVELS";
#endif
#ifdef GL_PRIMITIVE_RESTART_FIXED_INDEX
	if ( en == GL_PRIMITIVE_RESTART_FIXED_INDEX ) return "GL_PRIMITIVE_RESTART_FIXED_INDEX";
#endif
#ifdef GL_ANY_SAMPLES_PASSED_CONSERVATIVE
	if ( en == GL_ANY_SAMPLES_PASSED_CONSERVATIVE ) return "GL_ANY_SAMPLES_PASSED_CONSERVATIVE";
#endif
#ifdef GL_MAX_ELEMENT_INDEX
	if ( en == GL_MAX_ELEMENT_INDEX ) return "GL_MAX_ELEMENT_INDEX";
#endif
#ifdef GL_COMPRESSED_R11_EAC
	if ( en == GL_COMPRESSED_R11_EAC ) return "GL_COMPRESSED_R11_EAC";
#endif
#ifdef GL_COMPRESSED_SIGNED_R11_EAC
	if ( en == GL_COMPRESSED_SIGNED_R11_EAC ) return "GL_COMPRESSED_SIGNED_R11_EAC";
#endif
#ifdef GL_COMPRESSED_RG11_EAC
	if ( en == GL_COMPRESSED_RG11_EAC ) return "GL_COMPRESSED_RG11_EAC";
#endif
#ifdef GL_COMPRESSED_SIGNED_RG11_EAC
	if ( en == GL_COMPRESSED_SIGNED_RG11_EAC ) return "GL_COMPRESSED_SIGNED_RG11_EAC";
#endif
#ifdef GL_COMPRESSED_RGB8_ETC2
	if ( en == GL_COMPRESSED_RGB8_ETC2 ) return "GL_COMPRESSED_RGB8_ETC2";
#endif
#ifdef GL_COMPRESSED_SRGB8_ETC2
	if ( en == GL_COMPRESSED_SRGB8_ETC2 ) return "GL_COMPRESSED_SRGB8_ETC2";
#endif
#ifdef GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2
	if ( en == GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 ) return "GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2";
#endif
#ifdef GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2
	if ( en == GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 ) return "GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2";
#endif
#ifdef GL_COMPRESSED_RGBA8_ETC2_EAC
	if ( en == GL_COMPRESSED_RGBA8_ETC2_EAC ) return "GL_COMPRESSED_RGBA8_ETC2_EAC";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC ) return "GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC";
#endif
#ifdef GL_UNSIGNED_INT64_ARB
	if ( en == GL_UNSIGNED_INT64_ARB ) return "GL_UNSIGNED_INT64_ARB";
#endif
#ifdef GL_SRC1_COLOR
	if ( en == GL_SRC1_COLOR ) return "GL_SRC1_COLOR";
#endif
#ifdef GL_ONE_MINUS_SRC1_COLOR
	if ( en == GL_ONE_MINUS_SRC1_COLOR ) return "GL_ONE_MINUS_SRC1_COLOR";
#endif
#ifdef GL_ONE_MINUS_SRC1_ALPHA
	if ( en == GL_ONE_MINUS_SRC1_ALPHA ) return "GL_ONE_MINUS_SRC1_ALPHA";
#endif
#ifdef GL_MAX_DUAL_SOURCE_DRAW_BUFFERS
	if ( en == GL_MAX_DUAL_SOURCE_DRAW_BUFFERS ) return "GL_MAX_DUAL_SOURCE_DRAW_BUFFERS";
#endif
#ifdef GL_MAP_READ_BIT
	if ( en == GL_MAP_READ_BIT ) return "GL_MAP_READ_BIT";
#endif
#ifdef GL_MAP_WRITE_BIT
	if ( en == GL_MAP_WRITE_BIT ) return "GL_MAP_WRITE_BIT";
#endif
#ifdef GL_MAP_PERSISTENT_BIT
	if ( en == GL_MAP_PERSISTENT_BIT ) return "GL_MAP_PERSISTENT_BIT";
#endif
#ifdef GL_MAP_COHERENT_BIT
	if ( en == GL_MAP_COHERENT_BIT ) return "GL_MAP_COHERENT_BIT";
#endif
#ifdef GL_DYNAMIC_STORAGE_BIT
	if ( en == GL_DYNAMIC_STORAGE_BIT ) return "GL_DYNAMIC_STORAGE_BIT";
#endif
#ifdef GL_CLIENT_STORAGE_BIT
	if ( en == GL_CLIENT_STORAGE_BIT ) return "GL_CLIENT_STORAGE_BIT";
#endif
#ifdef GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT
	if ( en == GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT ) return "GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT";
#endif
#ifdef GL_BUFFER_IMMUTABLE_STORAGE
	if ( en == GL_BUFFER_IMMUTABLE_STORAGE ) return "GL_BUFFER_IMMUTABLE_STORAGE";
#endif
#ifdef GL_BUFFER_STORAGE_FLAGS
	if ( en == GL_BUFFER_STORAGE_FLAGS ) return "GL_BUFFER_STORAGE_FLAGS";
#endif
#ifdef GL_SYNC_CL_EVENT_ARB
	if ( en == GL_SYNC_CL_EVENT_ARB ) return "GL_SYNC_CL_EVENT_ARB";
#endif
#ifdef GL_SYNC_CL_EVENT_COMPLETE_ARB
	if ( en == GL_SYNC_CL_EVENT_COMPLETE_ARB ) return "GL_SYNC_CL_EVENT_COMPLETE_ARB";
#endif
#ifdef GL_CLEAR_TEXTURE
	if ( en == GL_CLEAR_TEXTURE ) return "GL_CLEAR_TEXTURE";
#endif
#ifdef GL_RGBA_FLOAT_MODE_ARB
	if ( en == GL_RGBA_FLOAT_MODE_ARB ) return "GL_RGBA_FLOAT_MODE_ARB";
#endif
#ifdef GL_CLAMP_VERTEX_COLOR_ARB
	if ( en == GL_CLAMP_VERTEX_COLOR_ARB ) return "GL_CLAMP_VERTEX_COLOR_ARB";
#endif
#ifdef GL_CLAMP_FRAGMENT_COLOR_ARB
	if ( en == GL_CLAMP_FRAGMENT_COLOR_ARB ) return "GL_CLAMP_FRAGMENT_COLOR_ARB";
#endif
#ifdef GL_CLAMP_READ_COLOR_ARB
	if ( en == GL_CLAMP_READ_COLOR_ARB ) return "GL_CLAMP_READ_COLOR_ARB";
#endif
#ifdef GL_FIXED_ONLY_ARB
	if ( en == GL_FIXED_ONLY_ARB ) return "GL_FIXED_ONLY_ARB";
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	if ( en == GL_UNPACK_COMPRESSED_BLOCK_WIDTH ) return "GL_UNPACK_COMPRESSED_BLOCK_WIDTH";
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	if ( en == GL_UNPACK_COMPRESSED_BLOCK_HEIGHT ) return "GL_UNPACK_COMPRESSED_BLOCK_HEIGHT";
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	if ( en == GL_UNPACK_COMPRESSED_BLOCK_DEPTH ) return "GL_UNPACK_COMPRESSED_BLOCK_DEPTH";
#endif
#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	if ( en == GL_UNPACK_COMPRESSED_BLOCK_SIZE ) return "GL_UNPACK_COMPRESSED_BLOCK_SIZE";
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	if ( en == GL_PACK_COMPRESSED_BLOCK_WIDTH ) return "GL_PACK_COMPRESSED_BLOCK_WIDTH";
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	if ( en == GL_PACK_COMPRESSED_BLOCK_HEIGHT ) return "GL_PACK_COMPRESSED_BLOCK_HEIGHT";
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	if ( en == GL_PACK_COMPRESSED_BLOCK_DEPTH ) return "GL_PACK_COMPRESSED_BLOCK_DEPTH";
#endif
#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	if ( en == GL_PACK_COMPRESSED_BLOCK_SIZE ) return "GL_PACK_COMPRESSED_BLOCK_SIZE";
#endif
#ifdef GL_COMPUTE_SHADER_BIT
	if ( en == GL_COMPUTE_SHADER_BIT ) return "GL_COMPUTE_SHADER_BIT";
#endif
#ifdef GL_MAX_COMPUTE_SHARED_MEMORY_SIZE
	if ( en == GL_MAX_COMPUTE_SHARED_MEMORY_SIZE ) return "GL_MAX_COMPUTE_SHARED_MEMORY_SIZE";
#endif
#ifdef GL_MAX_COMPUTE_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMPUTE_UNIFORM_COMPONENTS ) return "GL_MAX_COMPUTE_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_COMPUTE_ATOMIC_COUNTERS
	if ( en == GL_MAX_COMPUTE_ATOMIC_COUNTERS ) return "GL_MAX_COMPUTE_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS";
#endif
#ifdef GL_COMPUTE_WORK_GROUP_SIZE
	if ( en == GL_COMPUTE_WORK_GROUP_SIZE ) return "GL_COMPUTE_WORK_GROUP_SIZE";
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS
	if ( en == GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS ) return "GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER";
#endif
#ifdef GL_DISPATCH_INDIRECT_BUFFER
	if ( en == GL_DISPATCH_INDIRECT_BUFFER ) return "GL_DISPATCH_INDIRECT_BUFFER";
#endif
#ifdef GL_DISPATCH_INDIRECT_BUFFER_BINDING
	if ( en == GL_DISPATCH_INDIRECT_BUFFER_BINDING ) return "GL_DISPATCH_INDIRECT_BUFFER_BINDING";
#endif
#ifdef GL_COMPUTE_SHADER
	if ( en == GL_COMPUTE_SHADER ) return "GL_COMPUTE_SHADER";
#endif
#ifdef GL_MAX_COMPUTE_UNIFORM_BLOCKS
	if ( en == GL_MAX_COMPUTE_UNIFORM_BLOCKS ) return "GL_MAX_COMPUTE_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS ) return "GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_MAX_COMPUTE_IMAGE_UNIFORMS
	if ( en == GL_MAX_COMPUTE_IMAGE_UNIFORMS ) return "GL_MAX_COMPUTE_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_COUNT
	if ( en == GL_MAX_COMPUTE_WORK_GROUP_COUNT ) return "GL_MAX_COMPUTE_WORK_GROUP_COUNT";
#endif
#ifdef GL_MAX_COMPUTE_WORK_GROUP_SIZE
	if ( en == GL_MAX_COMPUTE_WORK_GROUP_SIZE ) return "GL_MAX_COMPUTE_WORK_GROUP_SIZE";
#endif
#ifdef GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB
	if ( en == GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB ) return "GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB";
#endif
#ifdef GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB
	if ( en == GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB ) return "GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB";
#endif
#ifdef GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB
	if ( en == GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB ) return "GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB";
#endif
#ifdef GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB
	if ( en == GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB ) return "GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB";
#endif
#ifdef GL_COPY_READ_BUFFER
	if ( en == GL_COPY_READ_BUFFER ) return "GL_COPY_READ_BUFFER";
#endif
#ifdef GL_COPY_WRITE_BUFFER
	if ( en == GL_COPY_WRITE_BUFFER ) return "GL_COPY_WRITE_BUFFER";
#endif
#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB
	if ( en == GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB ) return "GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB";
#endif
#ifdef GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB
	if ( en == GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB ) return "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB";
#endif
#ifdef GL_DEBUG_CALLBACK_FUNCTION_ARB
	if ( en == GL_DEBUG_CALLBACK_FUNCTION_ARB ) return "GL_DEBUG_CALLBACK_FUNCTION_ARB";
#endif
#ifdef GL_DEBUG_CALLBACK_USER_PARAM_ARB
	if ( en == GL_DEBUG_CALLBACK_USER_PARAM_ARB ) return "GL_DEBUG_CALLBACK_USER_PARAM_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_API_ARB
	if ( en == GL_DEBUG_SOURCE_API_ARB ) return "GL_DEBUG_SOURCE_API_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB
	if ( en == GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB ) return "GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER_ARB
	if ( en == GL_DEBUG_SOURCE_SHADER_COMPILER_ARB ) return "GL_DEBUG_SOURCE_SHADER_COMPILER_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_THIRD_PARTY_ARB
	if ( en == GL_DEBUG_SOURCE_THIRD_PARTY_ARB ) return "GL_DEBUG_SOURCE_THIRD_PARTY_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_APPLICATION_ARB
	if ( en == GL_DEBUG_SOURCE_APPLICATION_ARB ) return "GL_DEBUG_SOURCE_APPLICATION_ARB";
#endif
#ifdef GL_DEBUG_SOURCE_OTHER_ARB
	if ( en == GL_DEBUG_SOURCE_OTHER_ARB ) return "GL_DEBUG_SOURCE_OTHER_ARB";
#endif
#ifdef GL_DEBUG_TYPE_ERROR_ARB
	if ( en == GL_DEBUG_TYPE_ERROR_ARB ) return "GL_DEBUG_TYPE_ERROR_ARB";
#endif
#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB
	if ( en == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB ) return "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB";
#endif
#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB
	if ( en == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB ) return "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB";
#endif
#ifdef GL_DEBUG_TYPE_PORTABILITY_ARB
	if ( en == GL_DEBUG_TYPE_PORTABILITY_ARB ) return "GL_DEBUG_TYPE_PORTABILITY_ARB";
#endif
#ifdef GL_DEBUG_TYPE_PERFORMANCE_ARB
	if ( en == GL_DEBUG_TYPE_PERFORMANCE_ARB ) return "GL_DEBUG_TYPE_PERFORMANCE_ARB";
#endif
#ifdef GL_DEBUG_TYPE_OTHER_ARB
	if ( en == GL_DEBUG_TYPE_OTHER_ARB ) return "GL_DEBUG_TYPE_OTHER_ARB";
#endif
#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH_ARB
	if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH_ARB ) return "GL_MAX_DEBUG_MESSAGE_LENGTH_ARB";
#endif
#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES_ARB
	if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES_ARB ) return "GL_MAX_DEBUG_LOGGED_MESSAGES_ARB";
#endif
#ifdef GL_DEBUG_LOGGED_MESSAGES_ARB
	if ( en == GL_DEBUG_LOGGED_MESSAGES_ARB ) return "GL_DEBUG_LOGGED_MESSAGES_ARB";
#endif
#ifdef GL_DEBUG_SEVERITY_HIGH_ARB
	if ( en == GL_DEBUG_SEVERITY_HIGH_ARB ) return "GL_DEBUG_SEVERITY_HIGH_ARB";
#endif
#ifdef GL_DEBUG_SEVERITY_MEDIUM_ARB
	if ( en == GL_DEBUG_SEVERITY_MEDIUM_ARB ) return "GL_DEBUG_SEVERITY_MEDIUM_ARB";
#endif
#ifdef GL_DEBUG_SEVERITY_LOW_ARB
	if ( en == GL_DEBUG_SEVERITY_LOW_ARB ) return "GL_DEBUG_SEVERITY_LOW_ARB";
#endif
#ifdef GL_DEPTH_COMPONENT32F
	if ( en == GL_DEPTH_COMPONENT32F ) return "GL_DEPTH_COMPONENT32F";
#endif
#ifdef GL_DEPTH32F_STENCIL8
	if ( en == GL_DEPTH32F_STENCIL8 ) return "GL_DEPTH32F_STENCIL8";
#endif
#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV
	if ( en == GL_FLOAT_32_UNSIGNED_INT_24_8_REV ) return "GL_FLOAT_32_UNSIGNED_INT_24_8_REV";
#endif
#ifdef GL_DEPTH_CLAMP
	if ( en == GL_DEPTH_CLAMP ) return "GL_DEPTH_CLAMP";
#endif
#ifdef GL_DEPTH_COMPONENT16_ARB
	if ( en == GL_DEPTH_COMPONENT16_ARB ) return "GL_DEPTH_COMPONENT16_ARB";
#endif
#ifdef GL_DEPTH_COMPONENT24_ARB
	if ( en == GL_DEPTH_COMPONENT24_ARB ) return "GL_DEPTH_COMPONENT24_ARB";
#endif
#ifdef GL_DEPTH_COMPONENT32_ARB
	if ( en == GL_DEPTH_COMPONENT32_ARB ) return "GL_DEPTH_COMPONENT32_ARB";
#endif
#ifdef GL_TEXTURE_DEPTH_SIZE_ARB
	if ( en == GL_TEXTURE_DEPTH_SIZE_ARB ) return "GL_TEXTURE_DEPTH_SIZE_ARB";
#endif
#ifdef GL_DEPTH_TEXTURE_MODE_ARB
	if ( en == GL_DEPTH_TEXTURE_MODE_ARB ) return "GL_DEPTH_TEXTURE_MODE_ARB";
#endif
#ifdef GL_MAX_DRAW_BUFFERS_ARB
	if ( en == GL_MAX_DRAW_BUFFERS_ARB ) return "GL_MAX_DRAW_BUFFERS_ARB";
#endif
#ifdef GL_DRAW_BUFFER0_ARB
	if ( en == GL_DRAW_BUFFER0_ARB ) return "GL_DRAW_BUFFER0_ARB";
#endif
#ifdef GL_DRAW_BUFFER1_ARB
	if ( en == GL_DRAW_BUFFER1_ARB ) return "GL_DRAW_BUFFER1_ARB";
#endif
#ifdef GL_DRAW_BUFFER2_ARB
	if ( en == GL_DRAW_BUFFER2_ARB ) return "GL_DRAW_BUFFER2_ARB";
#endif
#ifdef GL_DRAW_BUFFER3_ARB
	if ( en == GL_DRAW_BUFFER3_ARB ) return "GL_DRAW_BUFFER3_ARB";
#endif
#ifdef GL_DRAW_BUFFER4_ARB
	if ( en == GL_DRAW_BUFFER4_ARB ) return "GL_DRAW_BUFFER4_ARB";
#endif
#ifdef GL_DRAW_BUFFER5_ARB
	if ( en == GL_DRAW_BUFFER5_ARB ) return "GL_DRAW_BUFFER5_ARB";
#endif
#ifdef GL_DRAW_BUFFER6_ARB
	if ( en == GL_DRAW_BUFFER6_ARB ) return "GL_DRAW_BUFFER6_ARB";
#endif
#ifdef GL_DRAW_BUFFER7_ARB
	if ( en == GL_DRAW_BUFFER7_ARB ) return "GL_DRAW_BUFFER7_ARB";
#endif
#ifdef GL_DRAW_BUFFER8_ARB
	if ( en == GL_DRAW_BUFFER8_ARB ) return "GL_DRAW_BUFFER8_ARB";
#endif
#ifdef GL_DRAW_BUFFER9_ARB
	if ( en == GL_DRAW_BUFFER9_ARB ) return "GL_DRAW_BUFFER9_ARB";
#endif
#ifdef GL_DRAW_BUFFER10_ARB
	if ( en == GL_DRAW_BUFFER10_ARB ) return "GL_DRAW_BUFFER10_ARB";
#endif
#ifdef GL_DRAW_BUFFER11_ARB
	if ( en == GL_DRAW_BUFFER11_ARB ) return "GL_DRAW_BUFFER11_ARB";
#endif
#ifdef GL_DRAW_BUFFER12_ARB
	if ( en == GL_DRAW_BUFFER12_ARB ) return "GL_DRAW_BUFFER12_ARB";
#endif
#ifdef GL_DRAW_BUFFER13_ARB
	if ( en == GL_DRAW_BUFFER13_ARB ) return "GL_DRAW_BUFFER13_ARB";
#endif
#ifdef GL_DRAW_BUFFER14_ARB
	if ( en == GL_DRAW_BUFFER14_ARB ) return "GL_DRAW_BUFFER14_ARB";
#endif
#ifdef GL_DRAW_BUFFER15_ARB
	if ( en == GL_DRAW_BUFFER15_ARB ) return "GL_DRAW_BUFFER15_ARB";
#endif
#ifdef GL_DRAW_INDIRECT_BUFFER
	if ( en == GL_DRAW_INDIRECT_BUFFER ) return "GL_DRAW_INDIRECT_BUFFER";
#endif
#ifdef GL_DRAW_INDIRECT_BUFFER_BINDING
	if ( en == GL_DRAW_INDIRECT_BUFFER_BINDING ) return "GL_DRAW_INDIRECT_BUFFER_BINDING";
#endif
#ifdef GL_LOCATION_COMPONENT
	if ( en == GL_LOCATION_COMPONENT ) return "GL_LOCATION_COMPONENT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_INDEX
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_INDEX ) return "GL_TRANSFORM_FEEDBACK_BUFFER_INDEX";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE ) return "GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE";
#endif
#ifdef GL_MAX_UNIFORM_LOCATIONS
	if ( en == GL_MAX_UNIFORM_LOCATIONS ) return "GL_MAX_UNIFORM_LOCATIONS";
#endif
#ifdef GL_FRAGMENT_PROGRAM_ARB
	if ( en == GL_FRAGMENT_PROGRAM_ARB ) return "GL_FRAGMENT_PROGRAM_ARB";
#endif
#ifdef GL_PROGRAM_ALU_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_ALU_INSTRUCTIONS_ARB ) return "GL_PROGRAM_ALU_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_TEX_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_TEX_INSTRUCTIONS_ARB ) return "GL_PROGRAM_TEX_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_TEX_INDIRECTIONS_ARB
	if ( en == GL_PROGRAM_TEX_INDIRECTIONS_ARB ) return "GL_PROGRAM_TEX_INDIRECTIONS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB ) return "GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB ) return "GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB
	if ( en == GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB ) return "GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB
	if ( en == GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB ) return "GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB ) return "GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB";
#endif
#ifdef GL_MAX_TEXTURE_COORDS_ARB
	if ( en == GL_MAX_TEXTURE_COORDS_ARB ) return "GL_MAX_TEXTURE_COORDS_ARB";
#endif
#ifdef GL_MAX_TEXTURE_IMAGE_UNITS_ARB
	if ( en == GL_MAX_TEXTURE_IMAGE_UNITS_ARB ) return "GL_MAX_TEXTURE_IMAGE_UNITS_ARB";
#endif
#ifdef GL_FRAGMENT_SHADER_ARB
	if ( en == GL_FRAGMENT_SHADER_ARB ) return "GL_FRAGMENT_SHADER_ARB";
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB
	if ( en == GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB ) return "GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB";
#endif
#ifdef GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB
	if ( en == GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB ) return "GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_WIDTH
	if ( en == GL_FRAMEBUFFER_DEFAULT_WIDTH ) return "GL_FRAMEBUFFER_DEFAULT_WIDTH";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_HEIGHT
	if ( en == GL_FRAMEBUFFER_DEFAULT_HEIGHT ) return "GL_FRAMEBUFFER_DEFAULT_HEIGHT";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_LAYERS
	if ( en == GL_FRAMEBUFFER_DEFAULT_LAYERS ) return "GL_FRAMEBUFFER_DEFAULT_LAYERS";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_SAMPLES
	if ( en == GL_FRAMEBUFFER_DEFAULT_SAMPLES ) return "GL_FRAMEBUFFER_DEFAULT_SAMPLES";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS
	if ( en == GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS ) return "GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS";
#endif
#ifdef GL_MAX_FRAMEBUFFER_WIDTH
	if ( en == GL_MAX_FRAMEBUFFER_WIDTH ) return "GL_MAX_FRAMEBUFFER_WIDTH";
#endif
#ifdef GL_MAX_FRAMEBUFFER_HEIGHT
	if ( en == GL_MAX_FRAMEBUFFER_HEIGHT ) return "GL_MAX_FRAMEBUFFER_HEIGHT";
#endif
#ifdef GL_MAX_FRAMEBUFFER_LAYERS
	if ( en == GL_MAX_FRAMEBUFFER_LAYERS ) return "GL_MAX_FRAMEBUFFER_LAYERS";
#endif
#ifdef GL_MAX_FRAMEBUFFER_SAMPLES
	if ( en == GL_MAX_FRAMEBUFFER_SAMPLES ) return "GL_MAX_FRAMEBUFFER_SAMPLES";
#endif
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION
	if ( en == GL_INVALID_FRAMEBUFFER_OPERATION ) return "GL_INVALID_FRAMEBUFFER_OPERATION";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING ) return "GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE ) return "GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE ) return "GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_DEFAULT
	if ( en == GL_FRAMEBUFFER_DEFAULT ) return "GL_FRAMEBUFFER_DEFAULT";
#endif
#ifdef GL_FRAMEBUFFER_UNDEFINED
	if ( en == GL_FRAMEBUFFER_UNDEFINED ) return "GL_FRAMEBUFFER_UNDEFINED";
#endif
#ifdef GL_DEPTH_STENCIL_ATTACHMENT
	if ( en == GL_DEPTH_STENCIL_ATTACHMENT ) return "GL_DEPTH_STENCIL_ATTACHMENT";
#endif
#ifdef GL_INDEX
	if ( en == GL_INDEX ) return "GL_INDEX";
#endif
#ifdef GL_MAX_RENDERBUFFER_SIZE
	if ( en == GL_MAX_RENDERBUFFER_SIZE ) return "GL_MAX_RENDERBUFFER_SIZE";
#endif
#ifdef GL_DEPTH_STENCIL
	if ( en == GL_DEPTH_STENCIL ) return "GL_DEPTH_STENCIL";
#endif
#ifdef GL_UNSIGNED_INT_24_8
	if ( en == GL_UNSIGNED_INT_24_8 ) return "GL_UNSIGNED_INT_24_8";
#endif
#ifdef GL_DEPTH24_STENCIL8
	if ( en == GL_DEPTH24_STENCIL8 ) return "GL_DEPTH24_STENCIL8";
#endif
#ifdef GL_TEXTURE_STENCIL_SIZE
	if ( en == GL_TEXTURE_STENCIL_SIZE ) return "GL_TEXTURE_STENCIL_SIZE";
#endif
#ifdef GL_UNSIGNED_NORMALIZED
	if ( en == GL_UNSIGNED_NORMALIZED ) return "GL_UNSIGNED_NORMALIZED";
#endif
#ifdef GL_SRGB
	if ( en == GL_SRGB ) return "GL_SRGB";
#endif
#ifdef GL_DRAW_FRAMEBUFFER_BINDING
	if ( en == GL_DRAW_FRAMEBUFFER_BINDING ) return "GL_DRAW_FRAMEBUFFER_BINDING";
#endif
#ifdef GL_FRAMEBUFFER_BINDING
	if ( en == GL_FRAMEBUFFER_BINDING ) return "GL_FRAMEBUFFER_BINDING";
#endif
#ifdef GL_RENDERBUFFER_BINDING
	if ( en == GL_RENDERBUFFER_BINDING ) return "GL_RENDERBUFFER_BINDING";
#endif
#ifdef GL_READ_FRAMEBUFFER
	if ( en == GL_READ_FRAMEBUFFER ) return "GL_READ_FRAMEBUFFER";
#endif
#ifdef GL_DRAW_FRAMEBUFFER
	if ( en == GL_DRAW_FRAMEBUFFER ) return "GL_DRAW_FRAMEBUFFER";
#endif
#ifdef GL_READ_FRAMEBUFFER_BINDING
	if ( en == GL_READ_FRAMEBUFFER_BINDING ) return "GL_READ_FRAMEBUFFER_BINDING";
#endif
#ifdef GL_RENDERBUFFER_SAMPLES
	if ( en == GL_RENDERBUFFER_SAMPLES ) return "GL_RENDERBUFFER_SAMPLES";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE ) return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME ) return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER";
#endif
#ifdef GL_FRAMEBUFFER_COMPLETE
	if ( en == GL_FRAMEBUFFER_COMPLETE ) return "GL_FRAMEBUFFER_COMPLETE";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT ) return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT ) return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER ) return "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER ) return "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER";
#endif
#ifdef GL_FRAMEBUFFER_UNSUPPORTED
	if ( en == GL_FRAMEBUFFER_UNSUPPORTED ) return "GL_FRAMEBUFFER_UNSUPPORTED";
#endif
#ifdef GL_MAX_COLOR_ATTACHMENTS
	if ( en == GL_MAX_COLOR_ATTACHMENTS ) return "GL_MAX_COLOR_ATTACHMENTS";
#endif
#ifdef GL_COLOR_ATTACHMENT0
	if ( en == GL_COLOR_ATTACHMENT0 ) return "GL_COLOR_ATTACHMENT0";
#endif
#ifdef GL_COLOR_ATTACHMENT1
	if ( en == GL_COLOR_ATTACHMENT1 ) return "GL_COLOR_ATTACHMENT1";
#endif
#ifdef GL_COLOR_ATTACHMENT2
	if ( en == GL_COLOR_ATTACHMENT2 ) return "GL_COLOR_ATTACHMENT2";
#endif
#ifdef GL_COLOR_ATTACHMENT3
	if ( en == GL_COLOR_ATTACHMENT3 ) return "GL_COLOR_ATTACHMENT3";
#endif
#ifdef GL_COLOR_ATTACHMENT4
	if ( en == GL_COLOR_ATTACHMENT4 ) return "GL_COLOR_ATTACHMENT4";
#endif
#ifdef GL_COLOR_ATTACHMENT5
	if ( en == GL_COLOR_ATTACHMENT5 ) return "GL_COLOR_ATTACHMENT5";
#endif
#ifdef GL_COLOR_ATTACHMENT6
	if ( en == GL_COLOR_ATTACHMENT6 ) return "GL_COLOR_ATTACHMENT6";
#endif
#ifdef GL_COLOR_ATTACHMENT7
	if ( en == GL_COLOR_ATTACHMENT7 ) return "GL_COLOR_ATTACHMENT7";
#endif
#ifdef GL_COLOR_ATTACHMENT8
	if ( en == GL_COLOR_ATTACHMENT8 ) return "GL_COLOR_ATTACHMENT8";
#endif
#ifdef GL_COLOR_ATTACHMENT9
	if ( en == GL_COLOR_ATTACHMENT9 ) return "GL_COLOR_ATTACHMENT9";
#endif
#ifdef GL_COLOR_ATTACHMENT10
	if ( en == GL_COLOR_ATTACHMENT10 ) return "GL_COLOR_ATTACHMENT10";
#endif
#ifdef GL_COLOR_ATTACHMENT11
	if ( en == GL_COLOR_ATTACHMENT11 ) return "GL_COLOR_ATTACHMENT11";
#endif
#ifdef GL_COLOR_ATTACHMENT12
	if ( en == GL_COLOR_ATTACHMENT12 ) return "GL_COLOR_ATTACHMENT12";
#endif
#ifdef GL_COLOR_ATTACHMENT13
	if ( en == GL_COLOR_ATTACHMENT13 ) return "GL_COLOR_ATTACHMENT13";
#endif
#ifdef GL_COLOR_ATTACHMENT14
	if ( en == GL_COLOR_ATTACHMENT14 ) return "GL_COLOR_ATTACHMENT14";
#endif
#ifdef GL_COLOR_ATTACHMENT15
	if ( en == GL_COLOR_ATTACHMENT15 ) return "GL_COLOR_ATTACHMENT15";
#endif
#ifdef GL_DEPTH_ATTACHMENT
	if ( en == GL_DEPTH_ATTACHMENT ) return "GL_DEPTH_ATTACHMENT";
#endif
#ifdef GL_STENCIL_ATTACHMENT
	if ( en == GL_STENCIL_ATTACHMENT ) return "GL_STENCIL_ATTACHMENT";
#endif
#ifdef GL_FRAMEBUFFER
	if ( en == GL_FRAMEBUFFER ) return "GL_FRAMEBUFFER";
#endif
#ifdef GL_RENDERBUFFER
	if ( en == GL_RENDERBUFFER ) return "GL_RENDERBUFFER";
#endif
#ifdef GL_RENDERBUFFER_WIDTH
	if ( en == GL_RENDERBUFFER_WIDTH ) return "GL_RENDERBUFFER_WIDTH";
#endif
#ifdef GL_RENDERBUFFER_HEIGHT
	if ( en == GL_RENDERBUFFER_HEIGHT ) return "GL_RENDERBUFFER_HEIGHT";
#endif
#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT
	if ( en == GL_RENDERBUFFER_INTERNAL_FORMAT ) return "GL_RENDERBUFFER_INTERNAL_FORMAT";
#endif
#ifdef GL_STENCIL_INDEX1
	if ( en == GL_STENCIL_INDEX1 ) return "GL_STENCIL_INDEX1";
#endif
#ifdef GL_STENCIL_INDEX4
	if ( en == GL_STENCIL_INDEX4 ) return "GL_STENCIL_INDEX4";
#endif
#ifdef GL_STENCIL_INDEX8
	if ( en == GL_STENCIL_INDEX8 ) return "GL_STENCIL_INDEX8";
#endif
#ifdef GL_STENCIL_INDEX16
	if ( en == GL_STENCIL_INDEX16 ) return "GL_STENCIL_INDEX16";
#endif
#ifdef GL_RENDERBUFFER_RED_SIZE
	if ( en == GL_RENDERBUFFER_RED_SIZE ) return "GL_RENDERBUFFER_RED_SIZE";
#endif
#ifdef GL_RENDERBUFFER_GREEN_SIZE
	if ( en == GL_RENDERBUFFER_GREEN_SIZE ) return "GL_RENDERBUFFER_GREEN_SIZE";
#endif
#ifdef GL_RENDERBUFFER_BLUE_SIZE
	if ( en == GL_RENDERBUFFER_BLUE_SIZE ) return "GL_RENDERBUFFER_BLUE_SIZE";
#endif
#ifdef GL_RENDERBUFFER_ALPHA_SIZE
	if ( en == GL_RENDERBUFFER_ALPHA_SIZE ) return "GL_RENDERBUFFER_ALPHA_SIZE";
#endif
#ifdef GL_RENDERBUFFER_DEPTH_SIZE
	if ( en == GL_RENDERBUFFER_DEPTH_SIZE ) return "GL_RENDERBUFFER_DEPTH_SIZE";
#endif
#ifdef GL_RENDERBUFFER_STENCIL_SIZE
	if ( en == GL_RENDERBUFFER_STENCIL_SIZE ) return "GL_RENDERBUFFER_STENCIL_SIZE";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE ) return "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE";
#endif
#ifdef GL_MAX_SAMPLES
	if ( en == GL_MAX_SAMPLES ) return "GL_MAX_SAMPLES";
#endif
#ifdef GL_FRAMEBUFFER_SRGB
	if ( en == GL_FRAMEBUFFER_SRGB ) return "GL_FRAMEBUFFER_SRGB";
#endif
#ifdef GL_LINES_ADJACENCY_ARB
	if ( en == GL_LINES_ADJACENCY_ARB ) return "GL_LINES_ADJACENCY_ARB";
#endif
#ifdef GL_LINE_STRIP_ADJACENCY_ARB
	if ( en == GL_LINE_STRIP_ADJACENCY_ARB ) return "GL_LINE_STRIP_ADJACENCY_ARB";
#endif
#ifdef GL_TRIANGLES_ADJACENCY_ARB
	if ( en == GL_TRIANGLES_ADJACENCY_ARB ) return "GL_TRIANGLES_ADJACENCY_ARB";
#endif
#ifdef GL_TRIANGLE_STRIP_ADJACENCY_ARB
	if ( en == GL_TRIANGLE_STRIP_ADJACENCY_ARB ) return "GL_TRIANGLE_STRIP_ADJACENCY_ARB";
#endif
#ifdef GL_PROGRAM_POINT_SIZE_ARB
	if ( en == GL_PROGRAM_POINT_SIZE_ARB ) return "GL_PROGRAM_POINT_SIZE_ARB";
#endif
#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB
	if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB ) return "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB ) return "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB ) return "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB ) return "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB";
#endif
#ifdef GL_GEOMETRY_SHADER_ARB
	if ( en == GL_GEOMETRY_SHADER_ARB ) return "GL_GEOMETRY_SHADER_ARB";
#endif
#ifdef GL_GEOMETRY_VERTICES_OUT_ARB
	if ( en == GL_GEOMETRY_VERTICES_OUT_ARB ) return "GL_GEOMETRY_VERTICES_OUT_ARB";
#endif
#ifdef GL_GEOMETRY_INPUT_TYPE_ARB
	if ( en == GL_GEOMETRY_INPUT_TYPE_ARB ) return "GL_GEOMETRY_INPUT_TYPE_ARB";
#endif
#ifdef GL_GEOMETRY_OUTPUT_TYPE_ARB
	if ( en == GL_GEOMETRY_OUTPUT_TYPE_ARB ) return "GL_GEOMETRY_OUTPUT_TYPE_ARB";
#endif
#ifdef GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB
	if ( en == GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB ) return "GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB";
#endif
#ifdef GL_MAX_VERTEX_VARYING_COMPONENTS_ARB
	if ( en == GL_MAX_VERTEX_VARYING_COMPONENTS_ARB ) return "GL_MAX_VERTEX_VARYING_COMPONENTS_ARB";
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB
	if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB ) return "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB";
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB
	if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB ) return "GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB";
#endif
#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB
	if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB ) return "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB";
#endif
#ifdef GL_PROGRAM_BINARY_RETRIEVABLE_HINT
	if ( en == GL_PROGRAM_BINARY_RETRIEVABLE_HINT ) return "GL_PROGRAM_BINARY_RETRIEVABLE_HINT";
#endif
#ifdef GL_PROGRAM_BINARY_LENGTH
	if ( en == GL_PROGRAM_BINARY_LENGTH ) return "GL_PROGRAM_BINARY_LENGTH";
#endif
#ifdef GL_NUM_PROGRAM_BINARY_FORMATS
	if ( en == GL_NUM_PROGRAM_BINARY_FORMATS ) return "GL_NUM_PROGRAM_BINARY_FORMATS";
#endif
#ifdef GL_PROGRAM_BINARY_FORMATS
	if ( en == GL_PROGRAM_BINARY_FORMATS ) return "GL_PROGRAM_BINARY_FORMATS";
#endif
#ifdef GL_GEOMETRY_SHADER_INVOCATIONS
	if ( en == GL_GEOMETRY_SHADER_INVOCATIONS ) return "GL_GEOMETRY_SHADER_INVOCATIONS";
#endif
#ifdef GL_MAX_GEOMETRY_SHADER_INVOCATIONS
	if ( en == GL_MAX_GEOMETRY_SHADER_INVOCATIONS ) return "GL_MAX_GEOMETRY_SHADER_INVOCATIONS";
#endif
#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET
	if ( en == GL_MIN_FRAGMENT_INTERPOLATION_OFFSET ) return "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET";
#endif
#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET
	if ( en == GL_MAX_FRAGMENT_INTERPOLATION_OFFSET ) return "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET";
#endif
#ifdef GL_FRAGMENT_INTERPOLATION_OFFSET_BITS
	if ( en == GL_FRAGMENT_INTERPOLATION_OFFSET_BITS ) return "GL_FRAGMENT_INTERPOLATION_OFFSET_BITS";
#endif
#ifdef GL_MAX_VERTEX_STREAMS
	if ( en == GL_MAX_VERTEX_STREAMS ) return "GL_MAX_VERTEX_STREAMS";
#endif
#ifdef GL_DOUBLE_MAT2
	if ( en == GL_DOUBLE_MAT2 ) return "GL_DOUBLE_MAT2";
#endif
#ifdef GL_DOUBLE_MAT3
	if ( en == GL_DOUBLE_MAT3 ) return "GL_DOUBLE_MAT3";
#endif
#ifdef GL_DOUBLE_MAT4
	if ( en == GL_DOUBLE_MAT4 ) return "GL_DOUBLE_MAT4";
#endif
#ifdef GL_DOUBLE_MAT2x3
	if ( en == GL_DOUBLE_MAT2x3 ) return "GL_DOUBLE_MAT2x3";
#endif
#ifdef GL_DOUBLE_MAT2x4
	if ( en == GL_DOUBLE_MAT2x4 ) return "GL_DOUBLE_MAT2x4";
#endif
#ifdef GL_DOUBLE_MAT3x2
	if ( en == GL_DOUBLE_MAT3x2 ) return "GL_DOUBLE_MAT3x2";
#endif
#ifdef GL_DOUBLE_MAT3x4
	if ( en == GL_DOUBLE_MAT3x4 ) return "GL_DOUBLE_MAT3x4";
#endif
#ifdef GL_DOUBLE_MAT4x2
	if ( en == GL_DOUBLE_MAT4x2 ) return "GL_DOUBLE_MAT4x2";
#endif
#ifdef GL_DOUBLE_MAT4x3
	if ( en == GL_DOUBLE_MAT4x3 ) return "GL_DOUBLE_MAT4x3";
#endif
#ifdef GL_DOUBLE_VEC2
	if ( en == GL_DOUBLE_VEC2 ) return "GL_DOUBLE_VEC2";
#endif
#ifdef GL_DOUBLE_VEC3
	if ( en == GL_DOUBLE_VEC3 ) return "GL_DOUBLE_VEC3";
#endif
#ifdef GL_DOUBLE_VEC4
	if ( en == GL_DOUBLE_VEC4 ) return "GL_DOUBLE_VEC4";
#endif
#ifdef GL_HALF_FLOAT_ARB
	if ( en == GL_HALF_FLOAT_ARB ) return "GL_HALF_FLOAT_ARB";
#endif
#ifdef GL_HALF_FLOAT
	if ( en == GL_HALF_FLOAT ) return "GL_HALF_FLOAT";
#endif
#ifdef GL_CONSTANT_COLOR
	if ( en == GL_CONSTANT_COLOR ) return "GL_CONSTANT_COLOR";
#endif
#ifdef GL_ONE_MINUS_CONSTANT_COLOR
	if ( en == GL_ONE_MINUS_CONSTANT_COLOR ) return "GL_ONE_MINUS_CONSTANT_COLOR";
#endif
#ifdef GL_CONSTANT_ALPHA
	if ( en == GL_CONSTANT_ALPHA ) return "GL_CONSTANT_ALPHA";
#endif
#ifdef GL_ONE_MINUS_CONSTANT_ALPHA
	if ( en == GL_ONE_MINUS_CONSTANT_ALPHA ) return "GL_ONE_MINUS_CONSTANT_ALPHA";
#endif
#ifdef GL_BLEND_COLOR
	if ( en == GL_BLEND_COLOR ) return "GL_BLEND_COLOR";
#endif
#ifdef GL_FUNC_ADD
	if ( en == GL_FUNC_ADD ) return "GL_FUNC_ADD";
#endif
#ifdef GL_MIN
	if ( en == GL_MIN ) return "GL_MIN";
#endif
#ifdef GL_MAX
	if ( en == GL_MAX ) return "GL_MAX";
#endif
#ifdef GL_BLEND_EQUATION
	if ( en == GL_BLEND_EQUATION ) return "GL_BLEND_EQUATION";
#endif
#ifdef GL_FUNC_SUBTRACT
	if ( en == GL_FUNC_SUBTRACT ) return "GL_FUNC_SUBTRACT";
#endif
#ifdef GL_FUNC_REVERSE_SUBTRACT
	if ( en == GL_FUNC_REVERSE_SUBTRACT ) return "GL_FUNC_REVERSE_SUBTRACT";
#endif
#ifdef GL_CONVOLUTION_1D
	if ( en == GL_CONVOLUTION_1D ) return "GL_CONVOLUTION_1D";
#endif
#ifdef GL_CONVOLUTION_2D
	if ( en == GL_CONVOLUTION_2D ) return "GL_CONVOLUTION_2D";
#endif
#ifdef GL_SEPARABLE_2D
	if ( en == GL_SEPARABLE_2D ) return "GL_SEPARABLE_2D";
#endif
#ifdef GL_CONVOLUTION_BORDER_MODE
	if ( en == GL_CONVOLUTION_BORDER_MODE ) return "GL_CONVOLUTION_BORDER_MODE";
#endif
#ifdef GL_CONVOLUTION_FILTER_SCALE
	if ( en == GL_CONVOLUTION_FILTER_SCALE ) return "GL_CONVOLUTION_FILTER_SCALE";
#endif
#ifdef GL_CONVOLUTION_FILTER_BIAS
	if ( en == GL_CONVOLUTION_FILTER_BIAS ) return "GL_CONVOLUTION_FILTER_BIAS";
#endif
#ifdef GL_REDUCE
	if ( en == GL_REDUCE ) return "GL_REDUCE";
#endif
#ifdef GL_CONVOLUTION_FORMAT
	if ( en == GL_CONVOLUTION_FORMAT ) return "GL_CONVOLUTION_FORMAT";
#endif
#ifdef GL_CONVOLUTION_WIDTH
	if ( en == GL_CONVOLUTION_WIDTH ) return "GL_CONVOLUTION_WIDTH";
#endif
#ifdef GL_CONVOLUTION_HEIGHT
	if ( en == GL_CONVOLUTION_HEIGHT ) return "GL_CONVOLUTION_HEIGHT";
#endif
#ifdef GL_MAX_CONVOLUTION_WIDTH
	if ( en == GL_MAX_CONVOLUTION_WIDTH ) return "GL_MAX_CONVOLUTION_WIDTH";
#endif
#ifdef GL_MAX_CONVOLUTION_HEIGHT
	if ( en == GL_MAX_CONVOLUTION_HEIGHT ) return "GL_MAX_CONVOLUTION_HEIGHT";
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE
	if ( en == GL_POST_CONVOLUTION_RED_SCALE ) return "GL_POST_CONVOLUTION_RED_SCALE";
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE
	if ( en == GL_POST_CONVOLUTION_GREEN_SCALE ) return "GL_POST_CONVOLUTION_GREEN_SCALE";
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE
	if ( en == GL_POST_CONVOLUTION_BLUE_SCALE ) return "GL_POST_CONVOLUTION_BLUE_SCALE";
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE
	if ( en == GL_POST_CONVOLUTION_ALPHA_SCALE ) return "GL_POST_CONVOLUTION_ALPHA_SCALE";
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS
	if ( en == GL_POST_CONVOLUTION_RED_BIAS ) return "GL_POST_CONVOLUTION_RED_BIAS";
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS
	if ( en == GL_POST_CONVOLUTION_GREEN_BIAS ) return "GL_POST_CONVOLUTION_GREEN_BIAS";
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS
	if ( en == GL_POST_CONVOLUTION_BLUE_BIAS ) return "GL_POST_CONVOLUTION_BLUE_BIAS";
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS
	if ( en == GL_POST_CONVOLUTION_ALPHA_BIAS ) return "GL_POST_CONVOLUTION_ALPHA_BIAS";
#endif
#ifdef GL_HISTOGRAM
	if ( en == GL_HISTOGRAM ) return "GL_HISTOGRAM";
#endif
#ifdef GL_PROXY_HISTOGRAM
	if ( en == GL_PROXY_HISTOGRAM ) return "GL_PROXY_HISTOGRAM";
#endif
#ifdef GL_HISTOGRAM_WIDTH
	if ( en == GL_HISTOGRAM_WIDTH ) return "GL_HISTOGRAM_WIDTH";
#endif
#ifdef GL_HISTOGRAM_FORMAT
	if ( en == GL_HISTOGRAM_FORMAT ) return "GL_HISTOGRAM_FORMAT";
#endif
#ifdef GL_HISTOGRAM_RED_SIZE
	if ( en == GL_HISTOGRAM_RED_SIZE ) return "GL_HISTOGRAM_RED_SIZE";
#endif
#ifdef GL_HISTOGRAM_GREEN_SIZE
	if ( en == GL_HISTOGRAM_GREEN_SIZE ) return "GL_HISTOGRAM_GREEN_SIZE";
#endif
#ifdef GL_HISTOGRAM_BLUE_SIZE
	if ( en == GL_HISTOGRAM_BLUE_SIZE ) return "GL_HISTOGRAM_BLUE_SIZE";
#endif
#ifdef GL_HISTOGRAM_ALPHA_SIZE
	if ( en == GL_HISTOGRAM_ALPHA_SIZE ) return "GL_HISTOGRAM_ALPHA_SIZE";
#endif
#ifdef GL_HISTOGRAM_LUMINANCE_SIZE
	if ( en == GL_HISTOGRAM_LUMINANCE_SIZE ) return "GL_HISTOGRAM_LUMINANCE_SIZE";
#endif
#ifdef GL_HISTOGRAM_SINK
	if ( en == GL_HISTOGRAM_SINK ) return "GL_HISTOGRAM_SINK";
#endif
#ifdef GL_MINMAX
	if ( en == GL_MINMAX ) return "GL_MINMAX";
#endif
#ifdef GL_MINMAX_FORMAT
	if ( en == GL_MINMAX_FORMAT ) return "GL_MINMAX_FORMAT";
#endif
#ifdef GL_MINMAX_SINK
	if ( en == GL_MINMAX_SINK ) return "GL_MINMAX_SINK";
#endif
#ifdef GL_TABLE_TOO_LARGE
	if ( en == GL_TABLE_TOO_LARGE ) return "GL_TABLE_TOO_LARGE";
#endif
#ifdef GL_COLOR_MATRIX
	if ( en == GL_COLOR_MATRIX ) return "GL_COLOR_MATRIX";
#endif
#ifdef GL_COLOR_MATRIX_STACK_DEPTH
	if ( en == GL_COLOR_MATRIX_STACK_DEPTH ) return "GL_COLOR_MATRIX_STACK_DEPTH";
#endif
#ifdef GL_MAX_COLOR_MATRIX_STACK_DEPTH
	if ( en == GL_MAX_COLOR_MATRIX_STACK_DEPTH ) return "GL_MAX_COLOR_MATRIX_STACK_DEPTH";
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE
	if ( en == GL_POST_COLOR_MATRIX_RED_SCALE ) return "GL_POST_COLOR_MATRIX_RED_SCALE";
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE
	if ( en == GL_POST_COLOR_MATRIX_GREEN_SCALE ) return "GL_POST_COLOR_MATRIX_GREEN_SCALE";
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE
	if ( en == GL_POST_COLOR_MATRIX_BLUE_SCALE ) return "GL_POST_COLOR_MATRIX_BLUE_SCALE";
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE
	if ( en == GL_POST_COLOR_MATRIX_ALPHA_SCALE ) return "GL_POST_COLOR_MATRIX_ALPHA_SCALE";
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS
	if ( en == GL_POST_COLOR_MATRIX_RED_BIAS ) return "GL_POST_COLOR_MATRIX_RED_BIAS";
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS
	if ( en == GL_POST_COLOR_MATRIX_GREEN_BIAS ) return "GL_POST_COLOR_MATRIX_GREEN_BIAS";
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS
	if ( en == GL_POST_COLOR_MATRIX_BLUE_BIAS ) return "GL_POST_COLOR_MATRIX_BLUE_BIAS";
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS
	if ( en == GL_POST_COLOR_MATRIX_ALPHA_BIAS ) return "GL_POST_COLOR_MATRIX_ALPHA_BIAS";
#endif
#ifdef GL_COLOR_TABLE
	if ( en == GL_COLOR_TABLE ) return "GL_COLOR_TABLE";
#endif
#ifdef GL_POST_CONVOLUTION_COLOR_TABLE
	if ( en == GL_POST_CONVOLUTION_COLOR_TABLE ) return "GL_POST_CONVOLUTION_COLOR_TABLE";
#endif
#ifdef GL_POST_COLOR_MATRIX_COLOR_TABLE
	if ( en == GL_POST_COLOR_MATRIX_COLOR_TABLE ) return "GL_POST_COLOR_MATRIX_COLOR_TABLE";
#endif
#ifdef GL_PROXY_COLOR_TABLE
	if ( en == GL_PROXY_COLOR_TABLE ) return "GL_PROXY_COLOR_TABLE";
#endif
#ifdef GL_PROXY_POST_CONVOLUTION_COLOR_TABLE
	if ( en == GL_PROXY_POST_CONVOLUTION_COLOR_TABLE ) return "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE";
#endif
#ifdef GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE
	if ( en == GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE ) return "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE";
#endif
#ifdef GL_COLOR_TABLE_SCALE
	if ( en == GL_COLOR_TABLE_SCALE ) return "GL_COLOR_TABLE_SCALE";
#endif
#ifdef GL_COLOR_TABLE_BIAS
	if ( en == GL_COLOR_TABLE_BIAS ) return "GL_COLOR_TABLE_BIAS";
#endif
#ifdef GL_COLOR_TABLE_FORMAT
	if ( en == GL_COLOR_TABLE_FORMAT ) return "GL_COLOR_TABLE_FORMAT";
#endif
#ifdef GL_COLOR_TABLE_WIDTH
	if ( en == GL_COLOR_TABLE_WIDTH ) return "GL_COLOR_TABLE_WIDTH";
#endif
#ifdef GL_COLOR_TABLE_RED_SIZE
	if ( en == GL_COLOR_TABLE_RED_SIZE ) return "GL_COLOR_TABLE_RED_SIZE";
#endif
#ifdef GL_COLOR_TABLE_GREEN_SIZE
	if ( en == GL_COLOR_TABLE_GREEN_SIZE ) return "GL_COLOR_TABLE_GREEN_SIZE";
#endif
#ifdef GL_COLOR_TABLE_BLUE_SIZE
	if ( en == GL_COLOR_TABLE_BLUE_SIZE ) return "GL_COLOR_TABLE_BLUE_SIZE";
#endif
#ifdef GL_COLOR_TABLE_ALPHA_SIZE
	if ( en == GL_COLOR_TABLE_ALPHA_SIZE ) return "GL_COLOR_TABLE_ALPHA_SIZE";
#endif
#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE
	if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE ) return "GL_COLOR_TABLE_LUMINANCE_SIZE";
#endif
#ifdef GL_COLOR_TABLE_INTENSITY_SIZE
	if ( en == GL_COLOR_TABLE_INTENSITY_SIZE ) return "GL_COLOR_TABLE_INTENSITY_SIZE";
#endif
#ifdef GL_IGNORE_BORDER
	if ( en == GL_IGNORE_BORDER ) return "GL_IGNORE_BORDER";
#endif
#ifdef GL_CONSTANT_BORDER
	if ( en == GL_CONSTANT_BORDER ) return "GL_CONSTANT_BORDER";
#endif
#ifdef GL_WRAP_BORDER
	if ( en == GL_WRAP_BORDER ) return "GL_WRAP_BORDER";
#endif
#ifdef GL_REPLICATE_BORDER
	if ( en == GL_REPLICATE_BORDER ) return "GL_REPLICATE_BORDER";
#endif
#ifdef GL_CONVOLUTION_BORDER_COLOR
	if ( en == GL_CONVOLUTION_BORDER_COLOR ) return "GL_CONVOLUTION_BORDER_COLOR";
#endif
#ifdef GL_PARAMETER_BUFFER_ARB
	if ( en == GL_PARAMETER_BUFFER_ARB ) return "GL_PARAMETER_BUFFER_ARB";
#endif
#ifdef GL_PARAMETER_BUFFER_BINDING_ARB
	if ( en == GL_PARAMETER_BUFFER_BINDING_ARB ) return "GL_PARAMETER_BUFFER_BINDING_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB";
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
	if ( en == GL_NUM_SAMPLE_COUNTS ) return "GL_NUM_SAMPLE_COUNTS";
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
	if ( en == GL_INTERNALFORMAT_SUPPORTED ) return "GL_INTERNALFORMAT_SUPPORTED";
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
	if ( en == GL_INTERNALFORMAT_PREFERRED ) return "GL_INTERNALFORMAT_PREFERRED";
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
	if ( en == GL_INTERNALFORMAT_RED_SIZE ) return "GL_INTERNALFORMAT_RED_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
	if ( en == GL_INTERNALFORMAT_GREEN_SIZE ) return "GL_INTERNALFORMAT_GREEN_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
	if ( en == GL_INTERNALFORMAT_BLUE_SIZE ) return "GL_INTERNALFORMAT_BLUE_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
	if ( en == GL_INTERNALFORMAT_ALPHA_SIZE ) return "GL_INTERNALFORMAT_ALPHA_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
	if ( en == GL_INTERNALFORMAT_DEPTH_SIZE ) return "GL_INTERNALFORMAT_DEPTH_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
	if ( en == GL_INTERNALFORMAT_STENCIL_SIZE ) return "GL_INTERNALFORMAT_STENCIL_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
	if ( en == GL_INTERNALFORMAT_SHARED_SIZE ) return "GL_INTERNALFORMAT_SHARED_SIZE";
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
	if ( en == GL_INTERNALFORMAT_RED_TYPE ) return "GL_INTERNALFORMAT_RED_TYPE";
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
	if ( en == GL_INTERNALFORMAT_GREEN_TYPE ) return "GL_INTERNALFORMAT_GREEN_TYPE";
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
	if ( en == GL_INTERNALFORMAT_BLUE_TYPE ) return "GL_INTERNALFORMAT_BLUE_TYPE";
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
	if ( en == GL_INTERNALFORMAT_ALPHA_TYPE ) return "GL_INTERNALFORMAT_ALPHA_TYPE";
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
	if ( en == GL_INTERNALFORMAT_DEPTH_TYPE ) return "GL_INTERNALFORMAT_DEPTH_TYPE";
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
	if ( en == GL_INTERNALFORMAT_STENCIL_TYPE ) return "GL_INTERNALFORMAT_STENCIL_TYPE";
#endif
#ifdef GL_MAX_WIDTH
	if ( en == GL_MAX_WIDTH ) return "GL_MAX_WIDTH";
#endif
#ifdef GL_MAX_HEIGHT
	if ( en == GL_MAX_HEIGHT ) return "GL_MAX_HEIGHT";
#endif
#ifdef GL_MAX_DEPTH
	if ( en == GL_MAX_DEPTH ) return "GL_MAX_DEPTH";
#endif
#ifdef GL_MAX_LAYERS
	if ( en == GL_MAX_LAYERS ) return "GL_MAX_LAYERS";
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
	if ( en == GL_MAX_COMBINED_DIMENSIONS ) return "GL_MAX_COMBINED_DIMENSIONS";
#endif
#ifdef GL_COLOR_COMPONENTS
	if ( en == GL_COLOR_COMPONENTS ) return "GL_COLOR_COMPONENTS";
#endif
#ifdef GL_DEPTH_COMPONENTS
	if ( en == GL_DEPTH_COMPONENTS ) return "GL_DEPTH_COMPONENTS";
#endif
#ifdef GL_STENCIL_COMPONENTS
	if ( en == GL_STENCIL_COMPONENTS ) return "GL_STENCIL_COMPONENTS";
#endif
#ifdef GL_COLOR_RENDERABLE
	if ( en == GL_COLOR_RENDERABLE ) return "GL_COLOR_RENDERABLE";
#endif
#ifdef GL_DEPTH_RENDERABLE
	if ( en == GL_DEPTH_RENDERABLE ) return "GL_DEPTH_RENDERABLE";
#endif
#ifdef GL_STENCIL_RENDERABLE
	if ( en == GL_STENCIL_RENDERABLE ) return "GL_STENCIL_RENDERABLE";
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
	if ( en == GL_FRAMEBUFFER_RENDERABLE ) return "GL_FRAMEBUFFER_RENDERABLE";
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
	if ( en == GL_FRAMEBUFFER_RENDERABLE_LAYERED ) return "GL_FRAMEBUFFER_RENDERABLE_LAYERED";
#endif
#ifdef GL_FRAMEBUFFER_BLEND
	if ( en == GL_FRAMEBUFFER_BLEND ) return "GL_FRAMEBUFFER_BLEND";
#endif
#ifdef GL_READ_PIXELS
	if ( en == GL_READ_PIXELS ) return "GL_READ_PIXELS";
#endif
#ifdef GL_READ_PIXELS_FORMAT
	if ( en == GL_READ_PIXELS_FORMAT ) return "GL_READ_PIXELS_FORMAT";
#endif
#ifdef GL_READ_PIXELS_TYPE
	if ( en == GL_READ_PIXELS_TYPE ) return "GL_READ_PIXELS_TYPE";
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
	if ( en == GL_TEXTURE_IMAGE_FORMAT ) return "GL_TEXTURE_IMAGE_FORMAT";
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
	if ( en == GL_TEXTURE_IMAGE_TYPE ) return "GL_TEXTURE_IMAGE_TYPE";
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
	if ( en == GL_GET_TEXTURE_IMAGE_FORMAT ) return "GL_GET_TEXTURE_IMAGE_FORMAT";
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
	if ( en == GL_GET_TEXTURE_IMAGE_TYPE ) return "GL_GET_TEXTURE_IMAGE_TYPE";
#endif
#ifdef GL_MIPMAP
	if ( en == GL_MIPMAP ) return "GL_MIPMAP";
#endif
#ifdef GL_MANUAL_GENERATE_MIPMAP
	if ( en == GL_MANUAL_GENERATE_MIPMAP ) return "GL_MANUAL_GENERATE_MIPMAP";
#endif
#ifdef GL_AUTO_GENERATE_MIPMAP
	if ( en == GL_AUTO_GENERATE_MIPMAP ) return "GL_AUTO_GENERATE_MIPMAP";
#endif
#ifdef GL_COLOR_ENCODING
	if ( en == GL_COLOR_ENCODING ) return "GL_COLOR_ENCODING";
#endif
#ifdef GL_SRGB_READ
	if ( en == GL_SRGB_READ ) return "GL_SRGB_READ";
#endif
#ifdef GL_SRGB_WRITE
	if ( en == GL_SRGB_WRITE ) return "GL_SRGB_WRITE";
#endif
#ifdef GL_SRGB_DECODE_ARB
	if ( en == GL_SRGB_DECODE_ARB ) return "GL_SRGB_DECODE_ARB";
#endif
#ifdef GL_FILTER
	if ( en == GL_FILTER ) return "GL_FILTER";
#endif
#ifdef GL_VERTEX_TEXTURE
	if ( en == GL_VERTEX_TEXTURE ) return "GL_VERTEX_TEXTURE";
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
	if ( en == GL_TESS_CONTROL_TEXTURE ) return "GL_TESS_CONTROL_TEXTURE";
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
	if ( en == GL_TESS_EVALUATION_TEXTURE ) return "GL_TESS_EVALUATION_TEXTURE";
#endif
#ifdef GL_GEOMETRY_TEXTURE
	if ( en == GL_GEOMETRY_TEXTURE ) return "GL_GEOMETRY_TEXTURE";
#endif
#ifdef GL_FRAGMENT_TEXTURE
	if ( en == GL_FRAGMENT_TEXTURE ) return "GL_FRAGMENT_TEXTURE";
#endif
#ifdef GL_COMPUTE_TEXTURE
	if ( en == GL_COMPUTE_TEXTURE ) return "GL_COMPUTE_TEXTURE";
#endif
#ifdef GL_TEXTURE_SHADOW
	if ( en == GL_TEXTURE_SHADOW ) return "GL_TEXTURE_SHADOW";
#endif
#ifdef GL_TEXTURE_GATHER
	if ( en == GL_TEXTURE_GATHER ) return "GL_TEXTURE_GATHER";
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
	if ( en == GL_TEXTURE_GATHER_SHADOW ) return "GL_TEXTURE_GATHER_SHADOW";
#endif
#ifdef GL_SHADER_IMAGE_LOAD
	if ( en == GL_SHADER_IMAGE_LOAD ) return "GL_SHADER_IMAGE_LOAD";
#endif
#ifdef GL_SHADER_IMAGE_STORE
	if ( en == GL_SHADER_IMAGE_STORE ) return "GL_SHADER_IMAGE_STORE";
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
	if ( en == GL_SHADER_IMAGE_ATOMIC ) return "GL_SHADER_IMAGE_ATOMIC";
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
	if ( en == GL_IMAGE_TEXEL_SIZE ) return "GL_IMAGE_TEXEL_SIZE";
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
	if ( en == GL_IMAGE_COMPATIBILITY_CLASS ) return "GL_IMAGE_COMPATIBILITY_CLASS";
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
	if ( en == GL_IMAGE_PIXEL_FORMAT ) return "GL_IMAGE_PIXEL_FORMAT";
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
	if ( en == GL_IMAGE_PIXEL_TYPE ) return "GL_IMAGE_PIXEL_TYPE";
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
	if ( en == GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST ) return "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST";
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
	if ( en == GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST ) return "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST";
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
	if ( en == GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE ) return "GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE";
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
	if ( en == GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE ) return "GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE";
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
	if ( en == GL_TEXTURE_COMPRESSED_BLOCK_WIDTH ) return "GL_TEXTURE_COMPRESSED_BLOCK_WIDTH";
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
	if ( en == GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT ) return "GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT";
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
	if ( en == GL_TEXTURE_COMPRESSED_BLOCK_SIZE ) return "GL_TEXTURE_COMPRESSED_BLOCK_SIZE";
#endif
#ifdef GL_CLEAR_BUFFER
	if ( en == GL_CLEAR_BUFFER ) return "GL_CLEAR_BUFFER";
#endif
#ifdef GL_TEXTURE_VIEW
	if ( en == GL_TEXTURE_VIEW ) return "GL_TEXTURE_VIEW";
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
	if ( en == GL_VIEW_COMPATIBILITY_CLASS ) return "GL_VIEW_COMPATIBILITY_CLASS";
#endif
#ifdef GL_FULL_SUPPORT
	if ( en == GL_FULL_SUPPORT ) return "GL_FULL_SUPPORT";
#endif
#ifdef GL_CAVEAT_SUPPORT
	if ( en == GL_CAVEAT_SUPPORT ) return "GL_CAVEAT_SUPPORT";
#endif
#ifdef GL_IMAGE_CLASS_4_X_32
	if ( en == GL_IMAGE_CLASS_4_X_32 ) return "GL_IMAGE_CLASS_4_X_32";
#endif
#ifdef GL_IMAGE_CLASS_2_X_32
	if ( en == GL_IMAGE_CLASS_2_X_32 ) return "GL_IMAGE_CLASS_2_X_32";
#endif
#ifdef GL_IMAGE_CLASS_1_X_32
	if ( en == GL_IMAGE_CLASS_1_X_32 ) return "GL_IMAGE_CLASS_1_X_32";
#endif
#ifdef GL_IMAGE_CLASS_4_X_16
	if ( en == GL_IMAGE_CLASS_4_X_16 ) return "GL_IMAGE_CLASS_4_X_16";
#endif
#ifdef GL_IMAGE_CLASS_2_X_16
	if ( en == GL_IMAGE_CLASS_2_X_16 ) return "GL_IMAGE_CLASS_2_X_16";
#endif
#ifdef GL_IMAGE_CLASS_1_X_16
	if ( en == GL_IMAGE_CLASS_1_X_16 ) return "GL_IMAGE_CLASS_1_X_16";
#endif
#ifdef GL_IMAGE_CLASS_4_X_8
	if ( en == GL_IMAGE_CLASS_4_X_8 ) return "GL_IMAGE_CLASS_4_X_8";
#endif
#ifdef GL_IMAGE_CLASS_2_X_8
	if ( en == GL_IMAGE_CLASS_2_X_8 ) return "GL_IMAGE_CLASS_2_X_8";
#endif
#ifdef GL_IMAGE_CLASS_1_X_8
	if ( en == GL_IMAGE_CLASS_1_X_8 ) return "GL_IMAGE_CLASS_1_X_8";
#endif
#ifdef GL_IMAGE_CLASS_11_11_10
	if ( en == GL_IMAGE_CLASS_11_11_10 ) return "GL_IMAGE_CLASS_11_11_10";
#endif
#ifdef GL_IMAGE_CLASS_10_10_10_2
	if ( en == GL_IMAGE_CLASS_10_10_10_2 ) return "GL_IMAGE_CLASS_10_10_10_2";
#endif
#ifdef GL_VIEW_CLASS_128_BITS
	if ( en == GL_VIEW_CLASS_128_BITS ) return "GL_VIEW_CLASS_128_BITS";
#endif
#ifdef GL_VIEW_CLASS_96_BITS
	if ( en == GL_VIEW_CLASS_96_BITS ) return "GL_VIEW_CLASS_96_BITS";
#endif
#ifdef GL_VIEW_CLASS_64_BITS
	if ( en == GL_VIEW_CLASS_64_BITS ) return "GL_VIEW_CLASS_64_BITS";
#endif
#ifdef GL_VIEW_CLASS_48_BITS
	if ( en == GL_VIEW_CLASS_48_BITS ) return "GL_VIEW_CLASS_48_BITS";
#endif
#ifdef GL_VIEW_CLASS_32_BITS
	if ( en == GL_VIEW_CLASS_32_BITS ) return "GL_VIEW_CLASS_32_BITS";
#endif
#ifdef GL_VIEW_CLASS_24_BITS
	if ( en == GL_VIEW_CLASS_24_BITS ) return "GL_VIEW_CLASS_24_BITS";
#endif
#ifdef GL_VIEW_CLASS_16_BITS
	if ( en == GL_VIEW_CLASS_16_BITS ) return "GL_VIEW_CLASS_16_BITS";
#endif
#ifdef GL_VIEW_CLASS_8_BITS
	if ( en == GL_VIEW_CLASS_8_BITS ) return "GL_VIEW_CLASS_8_BITS";
#endif
#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGB
	if ( en == GL_VIEW_CLASS_S3TC_DXT1_RGB ) return "GL_VIEW_CLASS_S3TC_DXT1_RGB";
#endif
#ifdef GL_VIEW_CLASS_S3TC_DXT1_RGBA
	if ( en == GL_VIEW_CLASS_S3TC_DXT1_RGBA ) return "GL_VIEW_CLASS_S3TC_DXT1_RGBA";
#endif
#ifdef GL_VIEW_CLASS_S3TC_DXT3_RGBA
	if ( en == GL_VIEW_CLASS_S3TC_DXT3_RGBA ) return "GL_VIEW_CLASS_S3TC_DXT3_RGBA";
#endif
#ifdef GL_VIEW_CLASS_S3TC_DXT5_RGBA
	if ( en == GL_VIEW_CLASS_S3TC_DXT5_RGBA ) return "GL_VIEW_CLASS_S3TC_DXT5_RGBA";
#endif
#ifdef GL_VIEW_CLASS_RGTC1_RED
	if ( en == GL_VIEW_CLASS_RGTC1_RED ) return "GL_VIEW_CLASS_RGTC1_RED";
#endif
#ifdef GL_VIEW_CLASS_RGTC2_RG
	if ( en == GL_VIEW_CLASS_RGTC2_RG ) return "GL_VIEW_CLASS_RGTC2_RG";
#endif
#ifdef GL_VIEW_CLASS_BPTC_UNORM
	if ( en == GL_VIEW_CLASS_BPTC_UNORM ) return "GL_VIEW_CLASS_BPTC_UNORM";
#endif
#ifdef GL_VIEW_CLASS_BPTC_FLOAT
	if ( en == GL_VIEW_CLASS_BPTC_FLOAT ) return "GL_VIEW_CLASS_BPTC_FLOAT";
#endif
#ifdef GL_MIN_MAP_BUFFER_ALIGNMENT
	if ( en == GL_MIN_MAP_BUFFER_ALIGNMENT ) return "GL_MIN_MAP_BUFFER_ALIGNMENT";
#endif
#ifdef GL_MAP_READ_BIT
	if ( en == GL_MAP_READ_BIT ) return "GL_MAP_READ_BIT";
#endif
#ifdef GL_MAP_WRITE_BIT
	if ( en == GL_MAP_WRITE_BIT ) return "GL_MAP_WRITE_BIT";
#endif
#ifdef GL_MAP_INVALIDATE_RANGE_BIT
	if ( en == GL_MAP_INVALIDATE_RANGE_BIT ) return "GL_MAP_INVALIDATE_RANGE_BIT";
#endif
#ifdef GL_MAP_INVALIDATE_BUFFER_BIT
	if ( en == GL_MAP_INVALIDATE_BUFFER_BIT ) return "GL_MAP_INVALIDATE_BUFFER_BIT";
#endif
#ifdef GL_MAP_FLUSH_EXPLICIT_BIT
	if ( en == GL_MAP_FLUSH_EXPLICIT_BIT ) return "GL_MAP_FLUSH_EXPLICIT_BIT";
#endif
#ifdef GL_MAP_UNSYNCHRONIZED_BIT
	if ( en == GL_MAP_UNSYNCHRONIZED_BIT ) return "GL_MAP_UNSYNCHRONIZED_BIT";
#endif
#ifdef GL_MATRIX_PALETTE_ARB
	if ( en == GL_MATRIX_PALETTE_ARB ) return "GL_MATRIX_PALETTE_ARB";
#endif
#ifdef GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB
	if ( en == GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB ) return "GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB";
#endif
#ifdef GL_MAX_PALETTE_MATRICES_ARB
	if ( en == GL_MAX_PALETTE_MATRICES_ARB ) return "GL_MAX_PALETTE_MATRICES_ARB";
#endif
#ifdef GL_CURRENT_PALETTE_MATRIX_ARB
	if ( en == GL_CURRENT_PALETTE_MATRIX_ARB ) return "GL_CURRENT_PALETTE_MATRIX_ARB";
#endif
#ifdef GL_MATRIX_INDEX_ARRAY_ARB
	if ( en == GL_MATRIX_INDEX_ARRAY_ARB ) return "GL_MATRIX_INDEX_ARRAY_ARB";
#endif
#ifdef GL_CURRENT_MATRIX_INDEX_ARB
	if ( en == GL_CURRENT_MATRIX_INDEX_ARB ) return "GL_CURRENT_MATRIX_INDEX_ARB";
#endif
#ifdef GL_MATRIX_INDEX_ARRAY_SIZE_ARB
	if ( en == GL_MATRIX_INDEX_ARRAY_SIZE_ARB ) return "GL_MATRIX_INDEX_ARRAY_SIZE_ARB";
#endif
#ifdef GL_MATRIX_INDEX_ARRAY_TYPE_ARB
	if ( en == GL_MATRIX_INDEX_ARRAY_TYPE_ARB ) return "GL_MATRIX_INDEX_ARRAY_TYPE_ARB";
#endif
#ifdef GL_MATRIX_INDEX_ARRAY_STRIDE_ARB
	if ( en == GL_MATRIX_INDEX_ARRAY_STRIDE_ARB ) return "GL_MATRIX_INDEX_ARRAY_STRIDE_ARB";
#endif
#ifdef GL_MATRIX_INDEX_ARRAY_POINTER_ARB
	if ( en == GL_MATRIX_INDEX_ARRAY_POINTER_ARB ) return "GL_MATRIX_INDEX_ARRAY_POINTER_ARB";
#endif
#ifdef GL_MULTISAMPLE_ARB
	if ( en == GL_MULTISAMPLE_ARB ) return "GL_MULTISAMPLE_ARB";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_COVERAGE_ARB
	if ( en == GL_SAMPLE_ALPHA_TO_COVERAGE_ARB ) return "GL_SAMPLE_ALPHA_TO_COVERAGE_ARB";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE_ARB
	if ( en == GL_SAMPLE_ALPHA_TO_ONE_ARB ) return "GL_SAMPLE_ALPHA_TO_ONE_ARB";
#endif
#ifdef GL_SAMPLE_COVERAGE_ARB
	if ( en == GL_SAMPLE_COVERAGE_ARB ) return "GL_SAMPLE_COVERAGE_ARB";
#endif
#ifdef GL_SAMPLE_BUFFERS_ARB
	if ( en == GL_SAMPLE_BUFFERS_ARB ) return "GL_SAMPLE_BUFFERS_ARB";
#endif
#ifdef GL_SAMPLES_ARB
	if ( en == GL_SAMPLES_ARB ) return "GL_SAMPLES_ARB";
#endif
#ifdef GL_SAMPLE_COVERAGE_VALUE_ARB
	if ( en == GL_SAMPLE_COVERAGE_VALUE_ARB ) return "GL_SAMPLE_COVERAGE_VALUE_ARB";
#endif
#ifdef GL_SAMPLE_COVERAGE_INVERT_ARB
	if ( en == GL_SAMPLE_COVERAGE_INVERT_ARB ) return "GL_SAMPLE_COVERAGE_INVERT_ARB";
#endif
#ifdef GL_MULTISAMPLE_BIT_ARB
	if ( en == GL_MULTISAMPLE_BIT_ARB ) return "GL_MULTISAMPLE_BIT_ARB";
#endif
#ifdef GL_TEXTURE0_ARB
	if ( en == GL_TEXTURE0_ARB ) return "GL_TEXTURE0_ARB";
#endif
#ifdef GL_TEXTURE1_ARB
	if ( en == GL_TEXTURE1_ARB ) return "GL_TEXTURE1_ARB";
#endif
#ifdef GL_TEXTURE2_ARB
	if ( en == GL_TEXTURE2_ARB ) return "GL_TEXTURE2_ARB";
#endif
#ifdef GL_TEXTURE3_ARB
	if ( en == GL_TEXTURE3_ARB ) return "GL_TEXTURE3_ARB";
#endif
#ifdef GL_TEXTURE4_ARB
	if ( en == GL_TEXTURE4_ARB ) return "GL_TEXTURE4_ARB";
#endif
#ifdef GL_TEXTURE5_ARB
	if ( en == GL_TEXTURE5_ARB ) return "GL_TEXTURE5_ARB";
#endif
#ifdef GL_TEXTURE6_ARB
	if ( en == GL_TEXTURE6_ARB ) return "GL_TEXTURE6_ARB";
#endif
#ifdef GL_TEXTURE7_ARB
	if ( en == GL_TEXTURE7_ARB ) return "GL_TEXTURE7_ARB";
#endif
#ifdef GL_TEXTURE8_ARB
	if ( en == GL_TEXTURE8_ARB ) return "GL_TEXTURE8_ARB";
#endif
#ifdef GL_TEXTURE9_ARB
	if ( en == GL_TEXTURE9_ARB ) return "GL_TEXTURE9_ARB";
#endif
#ifdef GL_TEXTURE10_ARB
	if ( en == GL_TEXTURE10_ARB ) return "GL_TEXTURE10_ARB";
#endif
#ifdef GL_TEXTURE11_ARB
	if ( en == GL_TEXTURE11_ARB ) return "GL_TEXTURE11_ARB";
#endif
#ifdef GL_TEXTURE12_ARB
	if ( en == GL_TEXTURE12_ARB ) return "GL_TEXTURE12_ARB";
#endif
#ifdef GL_TEXTURE13_ARB
	if ( en == GL_TEXTURE13_ARB ) return "GL_TEXTURE13_ARB";
#endif
#ifdef GL_TEXTURE14_ARB
	if ( en == GL_TEXTURE14_ARB ) return "GL_TEXTURE14_ARB";
#endif
#ifdef GL_TEXTURE15_ARB
	if ( en == GL_TEXTURE15_ARB ) return "GL_TEXTURE15_ARB";
#endif
#ifdef GL_TEXTURE16_ARB
	if ( en == GL_TEXTURE16_ARB ) return "GL_TEXTURE16_ARB";
#endif
#ifdef GL_TEXTURE17_ARB
	if ( en == GL_TEXTURE17_ARB ) return "GL_TEXTURE17_ARB";
#endif
#ifdef GL_TEXTURE18_ARB
	if ( en == GL_TEXTURE18_ARB ) return "GL_TEXTURE18_ARB";
#endif
#ifdef GL_TEXTURE19_ARB
	if ( en == GL_TEXTURE19_ARB ) return "GL_TEXTURE19_ARB";
#endif
#ifdef GL_TEXTURE20_ARB
	if ( en == GL_TEXTURE20_ARB ) return "GL_TEXTURE20_ARB";
#endif
#ifdef GL_TEXTURE21_ARB
	if ( en == GL_TEXTURE21_ARB ) return "GL_TEXTURE21_ARB";
#endif
#ifdef GL_TEXTURE22_ARB
	if ( en == GL_TEXTURE22_ARB ) return "GL_TEXTURE22_ARB";
#endif
#ifdef GL_TEXTURE23_ARB
	if ( en == GL_TEXTURE23_ARB ) return "GL_TEXTURE23_ARB";
#endif
#ifdef GL_TEXTURE24_ARB
	if ( en == GL_TEXTURE24_ARB ) return "GL_TEXTURE24_ARB";
#endif
#ifdef GL_TEXTURE25_ARB
	if ( en == GL_TEXTURE25_ARB ) return "GL_TEXTURE25_ARB";
#endif
#ifdef GL_TEXTURE26_ARB
	if ( en == GL_TEXTURE26_ARB ) return "GL_TEXTURE26_ARB";
#endif
#ifdef GL_TEXTURE27_ARB
	if ( en == GL_TEXTURE27_ARB ) return "GL_TEXTURE27_ARB";
#endif
#ifdef GL_TEXTURE28_ARB
	if ( en == GL_TEXTURE28_ARB ) return "GL_TEXTURE28_ARB";
#endif
#ifdef GL_TEXTURE29_ARB
	if ( en == GL_TEXTURE29_ARB ) return "GL_TEXTURE29_ARB";
#endif
#ifdef GL_TEXTURE30_ARB
	if ( en == GL_TEXTURE30_ARB ) return "GL_TEXTURE30_ARB";
#endif
#ifdef GL_TEXTURE31_ARB
	if ( en == GL_TEXTURE31_ARB ) return "GL_TEXTURE31_ARB";
#endif
#ifdef GL_ACTIVE_TEXTURE_ARB
	if ( en == GL_ACTIVE_TEXTURE_ARB ) return "GL_ACTIVE_TEXTURE_ARB";
#endif
#ifdef GL_CLIENT_ACTIVE_TEXTURE_ARB
	if ( en == GL_CLIENT_ACTIVE_TEXTURE_ARB ) return "GL_CLIENT_ACTIVE_TEXTURE_ARB";
#endif
#ifdef GL_MAX_TEXTURE_UNITS_ARB
	if ( en == GL_MAX_TEXTURE_UNITS_ARB ) return "GL_MAX_TEXTURE_UNITS_ARB";
#endif
#ifdef GL_QUERY_COUNTER_BITS_ARB
	if ( en == GL_QUERY_COUNTER_BITS_ARB ) return "GL_QUERY_COUNTER_BITS_ARB";
#endif
#ifdef GL_CURRENT_QUERY_ARB
	if ( en == GL_CURRENT_QUERY_ARB ) return "GL_CURRENT_QUERY_ARB";
#endif
#ifdef GL_QUERY_RESULT_ARB
	if ( en == GL_QUERY_RESULT_ARB ) return "GL_QUERY_RESULT_ARB";
#endif
#ifdef GL_QUERY_RESULT_AVAILABLE_ARB
	if ( en == GL_QUERY_RESULT_AVAILABLE_ARB ) return "GL_QUERY_RESULT_AVAILABLE_ARB";
#endif
#ifdef GL_SAMPLES_PASSED_ARB
	if ( en == GL_SAMPLES_PASSED_ARB ) return "GL_SAMPLES_PASSED_ARB";
#endif
#ifdef GL_ANY_SAMPLES_PASSED
	if ( en == GL_ANY_SAMPLES_PASSED ) return "GL_ANY_SAMPLES_PASSED";
#endif
#ifdef GL_PIXEL_PACK_BUFFER_ARB
	if ( en == GL_PIXEL_PACK_BUFFER_ARB ) return "GL_PIXEL_PACK_BUFFER_ARB";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_ARB
	if ( en == GL_PIXEL_UNPACK_BUFFER_ARB ) return "GL_PIXEL_UNPACK_BUFFER_ARB";
#endif
#ifdef GL_PIXEL_PACK_BUFFER_BINDING_ARB
	if ( en == GL_PIXEL_PACK_BUFFER_BINDING_ARB ) return "GL_PIXEL_PACK_BUFFER_BINDING_ARB";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING_ARB
	if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING_ARB ) return "GL_PIXEL_UNPACK_BUFFER_BINDING_ARB";
#endif
#ifdef GL_POINT_SIZE_MIN_ARB
	if ( en == GL_POINT_SIZE_MIN_ARB ) return "GL_POINT_SIZE_MIN_ARB";
#endif
#ifdef GL_POINT_SIZE_MAX_ARB
	if ( en == GL_POINT_SIZE_MAX_ARB ) return "GL_POINT_SIZE_MAX_ARB";
#endif
#ifdef GL_POINT_FADE_THRESHOLD_SIZE_ARB
	if ( en == GL_POINT_FADE_THRESHOLD_SIZE_ARB ) return "GL_POINT_FADE_THRESHOLD_SIZE_ARB";
#endif
#ifdef GL_POINT_DISTANCE_ATTENUATION_ARB
	if ( en == GL_POINT_DISTANCE_ATTENUATION_ARB ) return "GL_POINT_DISTANCE_ATTENUATION_ARB";
#endif
#ifdef GL_POINT_SPRITE_ARB
	if ( en == GL_POINT_SPRITE_ARB ) return "GL_POINT_SPRITE_ARB";
#endif
#ifdef GL_COORD_REPLACE_ARB
	if ( en == GL_COORD_REPLACE_ARB ) return "GL_COORD_REPLACE_ARB";
#endif
#ifdef GL_UNIFORM
	if ( en == GL_UNIFORM ) return "GL_UNIFORM";
#endif
#ifdef GL_UNIFORM_BLOCK
	if ( en == GL_UNIFORM_BLOCK ) return "GL_UNIFORM_BLOCK";
#endif
#ifdef GL_PROGRAM_INPUT
	if ( en == GL_PROGRAM_INPUT ) return "GL_PROGRAM_INPUT";
#endif
#ifdef GL_PROGRAM_OUTPUT
	if ( en == GL_PROGRAM_OUTPUT ) return "GL_PROGRAM_OUTPUT";
#endif
#ifdef GL_BUFFER_VARIABLE
	if ( en == GL_BUFFER_VARIABLE ) return "GL_BUFFER_VARIABLE";
#endif
#ifdef GL_SHADER_STORAGE_BLOCK
	if ( en == GL_SHADER_STORAGE_BLOCK ) return "GL_SHADER_STORAGE_BLOCK";
#endif
#ifdef GL_IS_PER_PATCH
	if ( en == GL_IS_PER_PATCH ) return "GL_IS_PER_PATCH";
#endif
#ifdef GL_VERTEX_SUBROUTINE
	if ( en == GL_VERTEX_SUBROUTINE ) return "GL_VERTEX_SUBROUTINE";
#endif
#ifdef GL_TESS_CONTROL_SUBROUTINE
	if ( en == GL_TESS_CONTROL_SUBROUTINE ) return "GL_TESS_CONTROL_SUBROUTINE";
#endif
#ifdef GL_TESS_EVALUATION_SUBROUTINE
	if ( en == GL_TESS_EVALUATION_SUBROUTINE ) return "GL_TESS_EVALUATION_SUBROUTINE";
#endif
#ifdef GL_GEOMETRY_SUBROUTINE
	if ( en == GL_GEOMETRY_SUBROUTINE ) return "GL_GEOMETRY_SUBROUTINE";
#endif
#ifdef GL_FRAGMENT_SUBROUTINE
	if ( en == GL_FRAGMENT_SUBROUTINE ) return "GL_FRAGMENT_SUBROUTINE";
#endif
#ifdef GL_COMPUTE_SUBROUTINE
	if ( en == GL_COMPUTE_SUBROUTINE ) return "GL_COMPUTE_SUBROUTINE";
#endif
#ifdef GL_VERTEX_SUBROUTINE_UNIFORM
	if ( en == GL_VERTEX_SUBROUTINE_UNIFORM ) return "GL_VERTEX_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_TESS_CONTROL_SUBROUTINE_UNIFORM
	if ( en == GL_TESS_CONTROL_SUBROUTINE_UNIFORM ) return "GL_TESS_CONTROL_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_TESS_EVALUATION_SUBROUTINE_UNIFORM
	if ( en == GL_TESS_EVALUATION_SUBROUTINE_UNIFORM ) return "GL_TESS_EVALUATION_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_GEOMETRY_SUBROUTINE_UNIFORM
	if ( en == GL_GEOMETRY_SUBROUTINE_UNIFORM ) return "GL_GEOMETRY_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_FRAGMENT_SUBROUTINE_UNIFORM
	if ( en == GL_FRAGMENT_SUBROUTINE_UNIFORM ) return "GL_FRAGMENT_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_COMPUTE_SUBROUTINE_UNIFORM
	if ( en == GL_COMPUTE_SUBROUTINE_UNIFORM ) return "GL_COMPUTE_SUBROUTINE_UNIFORM";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYING
	if ( en == GL_TRANSFORM_FEEDBACK_VARYING ) return "GL_TRANSFORM_FEEDBACK_VARYING";
#endif
#ifdef GL_ACTIVE_RESOURCES
	if ( en == GL_ACTIVE_RESOURCES ) return "GL_ACTIVE_RESOURCES";
#endif
#ifdef GL_MAX_NAME_LENGTH
	if ( en == GL_MAX_NAME_LENGTH ) return "GL_MAX_NAME_LENGTH";
#endif
#ifdef GL_MAX_NUM_ACTIVE_VARIABLES
	if ( en == GL_MAX_NUM_ACTIVE_VARIABLES ) return "GL_MAX_NUM_ACTIVE_VARIABLES";
#endif
#ifdef GL_MAX_NUM_COMPATIBLE_SUBROUTINES
	if ( en == GL_MAX_NUM_COMPATIBLE_SUBROUTINES ) return "GL_MAX_NUM_COMPATIBLE_SUBROUTINES";
#endif
#ifdef GL_NAME_LENGTH
	if ( en == GL_NAME_LENGTH ) return "GL_NAME_LENGTH";
#endif
#ifdef GL_TYPE
	if ( en == GL_TYPE ) return "GL_TYPE";
#endif
#ifdef GL_ARRAY_SIZE
	if ( en == GL_ARRAY_SIZE ) return "GL_ARRAY_SIZE";
#endif
#ifdef GL_OFFSET
	if ( en == GL_OFFSET ) return "GL_OFFSET";
#endif
#ifdef GL_BLOCK_INDEX
	if ( en == GL_BLOCK_INDEX ) return "GL_BLOCK_INDEX";
#endif
#ifdef GL_ARRAY_STRIDE
	if ( en == GL_ARRAY_STRIDE ) return "GL_ARRAY_STRIDE";
#endif
#ifdef GL_MATRIX_STRIDE
	if ( en == GL_MATRIX_STRIDE ) return "GL_MATRIX_STRIDE";
#endif
#ifdef GL_IS_ROW_MAJOR
	if ( en == GL_IS_ROW_MAJOR ) return "GL_IS_ROW_MAJOR";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_INDEX
	if ( en == GL_ATOMIC_COUNTER_BUFFER_INDEX ) return "GL_ATOMIC_COUNTER_BUFFER_INDEX";
#endif
#ifdef GL_BUFFER_BINDING
	if ( en == GL_BUFFER_BINDING ) return "GL_BUFFER_BINDING";
#endif
#ifdef GL_BUFFER_DATA_SIZE
	if ( en == GL_BUFFER_DATA_SIZE ) return "GL_BUFFER_DATA_SIZE";
#endif
#ifdef GL_NUM_ACTIVE_VARIABLES
	if ( en == GL_NUM_ACTIVE_VARIABLES ) return "GL_NUM_ACTIVE_VARIABLES";
#endif
#ifdef GL_ACTIVE_VARIABLES
	if ( en == GL_ACTIVE_VARIABLES ) return "GL_ACTIVE_VARIABLES";
#endif
#ifdef GL_REFERENCED_BY_VERTEX_SHADER
	if ( en == GL_REFERENCED_BY_VERTEX_SHADER ) return "GL_REFERENCED_BY_VERTEX_SHADER";
#endif
#ifdef GL_REFERENCED_BY_TESS_CONTROL_SHADER
	if ( en == GL_REFERENCED_BY_TESS_CONTROL_SHADER ) return "GL_REFERENCED_BY_TESS_CONTROL_SHADER";
#endif
#ifdef GL_REFERENCED_BY_TESS_EVALUATION_SHADER
	if ( en == GL_REFERENCED_BY_TESS_EVALUATION_SHADER ) return "GL_REFERENCED_BY_TESS_EVALUATION_SHADER";
#endif
#ifdef GL_REFERENCED_BY_GEOMETRY_SHADER
	if ( en == GL_REFERENCED_BY_GEOMETRY_SHADER ) return "GL_REFERENCED_BY_GEOMETRY_SHADER";
#endif
#ifdef GL_REFERENCED_BY_FRAGMENT_SHADER
	if ( en == GL_REFERENCED_BY_FRAGMENT_SHADER ) return "GL_REFERENCED_BY_FRAGMENT_SHADER";
#endif
#ifdef GL_REFERENCED_BY_COMPUTE_SHADER
	if ( en == GL_REFERENCED_BY_COMPUTE_SHADER ) return "GL_REFERENCED_BY_COMPUTE_SHADER";
#endif
#ifdef GL_TOP_LEVEL_ARRAY_SIZE
	if ( en == GL_TOP_LEVEL_ARRAY_SIZE ) return "GL_TOP_LEVEL_ARRAY_SIZE";
#endif
#ifdef GL_TOP_LEVEL_ARRAY_STRIDE
	if ( en == GL_TOP_LEVEL_ARRAY_STRIDE ) return "GL_TOP_LEVEL_ARRAY_STRIDE";
#endif
#ifdef GL_LOCATION
	if ( en == GL_LOCATION ) return "GL_LOCATION";
#endif
#ifdef GL_LOCATION_INDEX
	if ( en == GL_LOCATION_INDEX ) return "GL_LOCATION_INDEX";
#endif
#ifdef GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION
	if ( en == GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION ) return "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION";
#endif
#ifdef GL_FIRST_VERTEX_CONVENTION
	if ( en == GL_FIRST_VERTEX_CONVENTION ) return "GL_FIRST_VERTEX_CONVENTION";
#endif
#ifdef GL_LAST_VERTEX_CONVENTION
	if ( en == GL_LAST_VERTEX_CONVENTION ) return "GL_LAST_VERTEX_CONVENTION";
#endif
#ifdef GL_PROVOKING_VERTEX
	if ( en == GL_PROVOKING_VERTEX ) return "GL_PROVOKING_VERTEX";
#endif
#ifdef GL_QUERY_BUFFER_BARRIER_BIT
	if ( en == GL_QUERY_BUFFER_BARRIER_BIT ) return "GL_QUERY_BUFFER_BARRIER_BIT";
#endif
#ifdef GL_QUERY_BUFFER
	if ( en == GL_QUERY_BUFFER ) return "GL_QUERY_BUFFER";
#endif
#ifdef GL_QUERY_BUFFER_BINDING
	if ( en == GL_QUERY_BUFFER_BINDING ) return "GL_QUERY_BUFFER_BINDING";
#endif
#ifdef GL_QUERY_RESULT_NO_WAIT
	if ( en == GL_QUERY_RESULT_NO_WAIT ) return "GL_QUERY_RESULT_NO_WAIT";
#endif
#ifdef GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB
	if ( en == GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB ) return "GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB";
#endif
#ifdef GL_LOSE_CONTEXT_ON_RESET_ARB
	if ( en == GL_LOSE_CONTEXT_ON_RESET_ARB ) return "GL_LOSE_CONTEXT_ON_RESET_ARB";
#endif
#ifdef GL_GUILTY_CONTEXT_RESET_ARB
	if ( en == GL_GUILTY_CONTEXT_RESET_ARB ) return "GL_GUILTY_CONTEXT_RESET_ARB";
#endif
#ifdef GL_INNOCENT_CONTEXT_RESET_ARB
	if ( en == GL_INNOCENT_CONTEXT_RESET_ARB ) return "GL_INNOCENT_CONTEXT_RESET_ARB";
#endif
#ifdef GL_UNKNOWN_CONTEXT_RESET_ARB
	if ( en == GL_UNKNOWN_CONTEXT_RESET_ARB ) return "GL_UNKNOWN_CONTEXT_RESET_ARB";
#endif
#ifdef GL_RESET_NOTIFICATION_STRATEGY_ARB
	if ( en == GL_RESET_NOTIFICATION_STRATEGY_ARB ) return "GL_RESET_NOTIFICATION_STRATEGY_ARB";
#endif
#ifdef GL_NO_RESET_NOTIFICATION_ARB
	if ( en == GL_NO_RESET_NOTIFICATION_ARB ) return "GL_NO_RESET_NOTIFICATION_ARB";
#endif
#ifdef GL_SAMPLE_SHADING_ARB
	if ( en == GL_SAMPLE_SHADING_ARB ) return "GL_SAMPLE_SHADING_ARB";
#endif
#ifdef GL_MIN_SAMPLE_SHADING_VALUE_ARB
	if ( en == GL_MIN_SAMPLE_SHADING_VALUE_ARB ) return "GL_MIN_SAMPLE_SHADING_VALUE_ARB";
#endif
#ifdef GL_SAMPLER_BINDING
	if ( en == GL_SAMPLER_BINDING ) return "GL_SAMPLER_BINDING";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS ) return "GL_TEXTURE_CUBE_MAP_SEAMLESS";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_SEAMLESS
	if ( en == GL_TEXTURE_CUBE_MAP_SEAMLESS ) return "GL_TEXTURE_CUBE_MAP_SEAMLESS";
#endif
#ifdef GL_VERTEX_SHADER_BIT
	if ( en == GL_VERTEX_SHADER_BIT ) return "GL_VERTEX_SHADER_BIT";
#endif
#ifdef GL_FRAGMENT_SHADER_BIT
	if ( en == GL_FRAGMENT_SHADER_BIT ) return "GL_FRAGMENT_SHADER_BIT";
#endif
#ifdef GL_GEOMETRY_SHADER_BIT
	if ( en == GL_GEOMETRY_SHADER_BIT ) return "GL_GEOMETRY_SHADER_BIT";
#endif
#ifdef GL_TESS_CONTROL_SHADER_BIT
	if ( en == GL_TESS_CONTROL_SHADER_BIT ) return "GL_TESS_CONTROL_SHADER_BIT";
#endif
#ifdef GL_TESS_EVALUATION_SHADER_BIT
	if ( en == GL_TESS_EVALUATION_SHADER_BIT ) return "GL_TESS_EVALUATION_SHADER_BIT";
#endif
#ifdef GL_PROGRAM_SEPARABLE
	if ( en == GL_PROGRAM_SEPARABLE ) return "GL_PROGRAM_SEPARABLE";
#endif
#ifdef GL_ACTIVE_PROGRAM
	if ( en == GL_ACTIVE_PROGRAM ) return "GL_ACTIVE_PROGRAM";
#endif
#ifdef GL_PROGRAM_PIPELINE_BINDING
	if ( en == GL_PROGRAM_PIPELINE_BINDING ) return "GL_PROGRAM_PIPELINE_BINDING";
#endif
#ifdef GL_ALL_SHADER_BITS
	if ( en == GL_ALL_SHADER_BITS ) return "GL_ALL_SHADER_BITS";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER
	if ( en == GL_ATOMIC_COUNTER_BUFFER ) return "GL_ATOMIC_COUNTER_BUFFER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_BINDING
	if ( en == GL_ATOMIC_COUNTER_BUFFER_BINDING ) return "GL_ATOMIC_COUNTER_BUFFER_BINDING";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_START
	if ( en == GL_ATOMIC_COUNTER_BUFFER_START ) return "GL_ATOMIC_COUNTER_BUFFER_START";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_SIZE
	if ( en == GL_ATOMIC_COUNTER_BUFFER_SIZE ) return "GL_ATOMIC_COUNTER_BUFFER_SIZE";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE
	if ( en == GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE ) return "GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS
	if ( en == GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS ) return "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES
	if ( en == GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES ) return "GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER";
#endif
#ifdef GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER
	if ( en == GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER ) return "GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER";
#endif
#ifdef GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS ) return "GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_MAX_VERTEX_ATOMIC_COUNTERS
	if ( en == GL_MAX_VERTEX_ATOMIC_COUNTERS ) return "GL_MAX_VERTEX_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS
	if ( en == GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS ) return "GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS
	if ( en == GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS ) return "GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_GEOMETRY_ATOMIC_COUNTERS
	if ( en == GL_MAX_GEOMETRY_ATOMIC_COUNTERS ) return "GL_MAX_GEOMETRY_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_FRAGMENT_ATOMIC_COUNTERS
	if ( en == GL_MAX_FRAGMENT_ATOMIC_COUNTERS ) return "GL_MAX_FRAGMENT_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_COMBINED_ATOMIC_COUNTERS
	if ( en == GL_MAX_COMBINED_ATOMIC_COUNTERS ) return "GL_MAX_COMBINED_ATOMIC_COUNTERS";
#endif
#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE
	if ( en == GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE ) return "GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE";
#endif
#ifdef GL_ACTIVE_ATOMIC_COUNTER_BUFFERS
	if ( en == GL_ACTIVE_ATOMIC_COUNTER_BUFFERS ) return "GL_ACTIVE_ATOMIC_COUNTER_BUFFERS";
#endif
#ifdef GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX
	if ( en == GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX ) return "GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX";
#endif
#ifdef GL_UNSIGNED_INT_ATOMIC_COUNTER
	if ( en == GL_UNSIGNED_INT_ATOMIC_COUNTER ) return "GL_UNSIGNED_INT_ATOMIC_COUNTER";
#endif
#ifdef GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS
	if ( en == GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS ) return "GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT
	if ( en == GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT ) return "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT";
#endif
#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT
	if ( en == GL_ELEMENT_ARRAY_BARRIER_BIT ) return "GL_ELEMENT_ARRAY_BARRIER_BIT";
#endif
#ifdef GL_UNIFORM_BARRIER_BIT
	if ( en == GL_UNIFORM_BARRIER_BIT ) return "GL_UNIFORM_BARRIER_BIT";
#endif
#ifdef GL_TEXTURE_FETCH_BARRIER_BIT
	if ( en == GL_TEXTURE_FETCH_BARRIER_BIT ) return "GL_TEXTURE_FETCH_BARRIER_BIT";
#endif
#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT
	if ( en == GL_SHADER_IMAGE_ACCESS_BARRIER_BIT ) return "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT";
#endif
#ifdef GL_COMMAND_BARRIER_BIT
	if ( en == GL_COMMAND_BARRIER_BIT ) return "GL_COMMAND_BARRIER_BIT";
#endif
#ifdef GL_PIXEL_BUFFER_BARRIER_BIT
	if ( en == GL_PIXEL_BUFFER_BARRIER_BIT ) return "GL_PIXEL_BUFFER_BARRIER_BIT";
#endif
#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT
	if ( en == GL_TEXTURE_UPDATE_BARRIER_BIT ) return "GL_TEXTURE_UPDATE_BARRIER_BIT";
#endif
#ifdef GL_BUFFER_UPDATE_BARRIER_BIT
	if ( en == GL_BUFFER_UPDATE_BARRIER_BIT ) return "GL_BUFFER_UPDATE_BARRIER_BIT";
#endif
#ifdef GL_FRAMEBUFFER_BARRIER_BIT
	if ( en == GL_FRAMEBUFFER_BARRIER_BIT ) return "GL_FRAMEBUFFER_BARRIER_BIT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT
	if ( en == GL_TRANSFORM_FEEDBACK_BARRIER_BIT ) return "GL_TRANSFORM_FEEDBACK_BARRIER_BIT";
#endif
#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT
	if ( en == GL_ATOMIC_COUNTER_BARRIER_BIT ) return "GL_ATOMIC_COUNTER_BARRIER_BIT";
#endif
#ifdef GL_MAX_IMAGE_UNITS
	if ( en == GL_MAX_IMAGE_UNITS ) return "GL_MAX_IMAGE_UNITS";
#endif
#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS
	if ( en == GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS ) return "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS";
#endif
#ifdef GL_IMAGE_BINDING_NAME
	if ( en == GL_IMAGE_BINDING_NAME ) return "GL_IMAGE_BINDING_NAME";
#endif
#ifdef GL_IMAGE_BINDING_LEVEL
	if ( en == GL_IMAGE_BINDING_LEVEL ) return "GL_IMAGE_BINDING_LEVEL";
#endif
#ifdef GL_IMAGE_BINDING_LAYERED
	if ( en == GL_IMAGE_BINDING_LAYERED ) return "GL_IMAGE_BINDING_LAYERED";
#endif
#ifdef GL_IMAGE_BINDING_LAYER
	if ( en == GL_IMAGE_BINDING_LAYER ) return "GL_IMAGE_BINDING_LAYER";
#endif
#ifdef GL_IMAGE_BINDING_ACCESS
	if ( en == GL_IMAGE_BINDING_ACCESS ) return "GL_IMAGE_BINDING_ACCESS";
#endif
#ifdef GL_IMAGE_1D
	if ( en == GL_IMAGE_1D ) return "GL_IMAGE_1D";
#endif
#ifdef GL_IMAGE_2D
	if ( en == GL_IMAGE_2D ) return "GL_IMAGE_2D";
#endif
#ifdef GL_IMAGE_3D
	if ( en == GL_IMAGE_3D ) return "GL_IMAGE_3D";
#endif
#ifdef GL_IMAGE_2D_RECT
	if ( en == GL_IMAGE_2D_RECT ) return "GL_IMAGE_2D_RECT";
#endif
#ifdef GL_IMAGE_CUBE
	if ( en == GL_IMAGE_CUBE ) return "GL_IMAGE_CUBE";
#endif
#ifdef GL_IMAGE_BUFFER
	if ( en == GL_IMAGE_BUFFER ) return "GL_IMAGE_BUFFER";
#endif
#ifdef GL_IMAGE_1D_ARRAY
	if ( en == GL_IMAGE_1D_ARRAY ) return "GL_IMAGE_1D_ARRAY";
#endif
#ifdef GL_IMAGE_2D_ARRAY
	if ( en == GL_IMAGE_2D_ARRAY ) return "GL_IMAGE_2D_ARRAY";
#endif
#ifdef GL_IMAGE_CUBE_MAP_ARRAY
	if ( en == GL_IMAGE_CUBE_MAP_ARRAY ) return "GL_IMAGE_CUBE_MAP_ARRAY";
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE
	if ( en == GL_IMAGE_2D_MULTISAMPLE ) return "GL_IMAGE_2D_MULTISAMPLE";
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY
	if ( en == GL_IMAGE_2D_MULTISAMPLE_ARRAY ) return "GL_IMAGE_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_INT_IMAGE_1D
	if ( en == GL_INT_IMAGE_1D ) return "GL_INT_IMAGE_1D";
#endif
#ifdef GL_INT_IMAGE_2D
	if ( en == GL_INT_IMAGE_2D ) return "GL_INT_IMAGE_2D";
#endif
#ifdef GL_INT_IMAGE_3D
	if ( en == GL_INT_IMAGE_3D ) return "GL_INT_IMAGE_3D";
#endif
#ifdef GL_INT_IMAGE_2D_RECT
	if ( en == GL_INT_IMAGE_2D_RECT ) return "GL_INT_IMAGE_2D_RECT";
#endif
#ifdef GL_INT_IMAGE_CUBE
	if ( en == GL_INT_IMAGE_CUBE ) return "GL_INT_IMAGE_CUBE";
#endif
#ifdef GL_INT_IMAGE_BUFFER
	if ( en == GL_INT_IMAGE_BUFFER ) return "GL_INT_IMAGE_BUFFER";
#endif
#ifdef GL_INT_IMAGE_1D_ARRAY
	if ( en == GL_INT_IMAGE_1D_ARRAY ) return "GL_INT_IMAGE_1D_ARRAY";
#endif
#ifdef GL_INT_IMAGE_2D_ARRAY
	if ( en == GL_INT_IMAGE_2D_ARRAY ) return "GL_INT_IMAGE_2D_ARRAY";
#endif
#ifdef GL_INT_IMAGE_CUBE_MAP_ARRAY
	if ( en == GL_INT_IMAGE_CUBE_MAP_ARRAY ) return "GL_INT_IMAGE_CUBE_MAP_ARRAY";
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE
	if ( en == GL_INT_IMAGE_2D_MULTISAMPLE ) return "GL_INT_IMAGE_2D_MULTISAMPLE";
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY ) return "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D
	if ( en == GL_UNSIGNED_INT_IMAGE_1D ) return "GL_UNSIGNED_INT_IMAGE_1D";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D
	if ( en == GL_UNSIGNED_INT_IMAGE_2D ) return "GL_UNSIGNED_INT_IMAGE_2D";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_3D
	if ( en == GL_UNSIGNED_INT_IMAGE_3D ) return "GL_UNSIGNED_INT_IMAGE_3D";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_RECT ) return "GL_UNSIGNED_INT_IMAGE_2D_RECT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE
	if ( en == GL_UNSIGNED_INT_IMAGE_CUBE ) return "GL_UNSIGNED_INT_IMAGE_CUBE";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER
	if ( en == GL_UNSIGNED_INT_IMAGE_BUFFER ) return "GL_UNSIGNED_INT_IMAGE_BUFFER";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY
	if ( en == GL_UNSIGNED_INT_IMAGE_1D_ARRAY ) return "GL_UNSIGNED_INT_IMAGE_1D_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_ARRAY ) return "GL_UNSIGNED_INT_IMAGE_2D_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY
	if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY ) return "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE ) return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY ) return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_MAX_IMAGE_SAMPLES
	if ( en == GL_MAX_IMAGE_SAMPLES ) return "GL_MAX_IMAGE_SAMPLES";
#endif
#ifdef GL_IMAGE_BINDING_FORMAT
	if ( en == GL_IMAGE_BINDING_FORMAT ) return "GL_IMAGE_BINDING_FORMAT";
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
	if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_TYPE ) return "GL_IMAGE_FORMAT_COMPATIBILITY_TYPE";
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE
	if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE ) return "GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE";
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS
	if ( en == GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS ) return "GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS";
#endif
#ifdef GL_MAX_VERTEX_IMAGE_UNIFORMS
	if ( en == GL_MAX_VERTEX_IMAGE_UNIFORMS ) return "GL_MAX_VERTEX_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS
	if ( en == GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS ) return "GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS
	if ( en == GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS ) return "GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_GEOMETRY_IMAGE_UNIFORMS
	if ( en == GL_MAX_GEOMETRY_IMAGE_UNIFORMS ) return "GL_MAX_GEOMETRY_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_FRAGMENT_IMAGE_UNIFORMS
	if ( en == GL_MAX_FRAGMENT_IMAGE_UNIFORMS ) return "GL_MAX_FRAGMENT_IMAGE_UNIFORMS";
#endif
#ifdef GL_MAX_COMBINED_IMAGE_UNIFORMS
	if ( en == GL_MAX_COMBINED_IMAGE_UNIFORMS ) return "GL_MAX_COMBINED_IMAGE_UNIFORMS";
#endif
#ifdef GL_ALL_BARRIER_BITS
	if ( en == GL_ALL_BARRIER_BITS ) return "GL_ALL_BARRIER_BITS";
#endif
#ifdef GL_PROGRAM_OBJECT_ARB
	if ( en == GL_PROGRAM_OBJECT_ARB ) return "GL_PROGRAM_OBJECT_ARB";
#endif
#ifdef GL_SHADER_OBJECT_ARB
	if ( en == GL_SHADER_OBJECT_ARB ) return "GL_SHADER_OBJECT_ARB";
#endif
#ifdef INFI_GL_OBJECT_TYPE_ARB
	if ( en == INFI_GL_OBJECT_TYPE_ARB ) return "INFI_GL_OBJECT_TYPE_ARB";
#endif
#ifdef GL_OBJECT_SUBTYPE_ARB
	if ( en == GL_OBJECT_SUBTYPE_ARB ) return "GL_OBJECT_SUBTYPE_ARB";
#endif
#ifdef GL_FLOAT_VEC2_ARB
	if ( en == GL_FLOAT_VEC2_ARB ) return "GL_FLOAT_VEC2_ARB";
#endif
#ifdef GL_FLOAT_VEC3_ARB
	if ( en == GL_FLOAT_VEC3_ARB ) return "GL_FLOAT_VEC3_ARB";
#endif
#ifdef GL_FLOAT_VEC4_ARB
	if ( en == GL_FLOAT_VEC4_ARB ) return "GL_FLOAT_VEC4_ARB";
#endif
#ifdef GL_INT_VEC2_ARB
	if ( en == GL_INT_VEC2_ARB ) return "GL_INT_VEC2_ARB";
#endif
#ifdef GL_INT_VEC3_ARB
	if ( en == GL_INT_VEC3_ARB ) return "GL_INT_VEC3_ARB";
#endif
#ifdef GL_INT_VEC4_ARB
	if ( en == GL_INT_VEC4_ARB ) return "GL_INT_VEC4_ARB";
#endif
#ifdef GL_BOOL_ARB
	if ( en == GL_BOOL_ARB ) return "GL_BOOL_ARB";
#endif
#ifdef GL_BOOL_VEC2_ARB
	if ( en == GL_BOOL_VEC2_ARB ) return "GL_BOOL_VEC2_ARB";
#endif
#ifdef GL_BOOL_VEC3_ARB
	if ( en == GL_BOOL_VEC3_ARB ) return "GL_BOOL_VEC3_ARB";
#endif
#ifdef GL_BOOL_VEC4_ARB
	if ( en == GL_BOOL_VEC4_ARB ) return "GL_BOOL_VEC4_ARB";
#endif
#ifdef GL_FLOAT_MAT2_ARB
	if ( en == GL_FLOAT_MAT2_ARB ) return "GL_FLOAT_MAT2_ARB";
#endif
#ifdef GL_FLOAT_MAT3_ARB
	if ( en == GL_FLOAT_MAT3_ARB ) return "GL_FLOAT_MAT3_ARB";
#endif
#ifdef GL_FLOAT_MAT4_ARB
	if ( en == GL_FLOAT_MAT4_ARB ) return "GL_FLOAT_MAT4_ARB";
#endif
#ifdef GL_SAMPLER_1D_ARB
	if ( en == GL_SAMPLER_1D_ARB ) return "GL_SAMPLER_1D_ARB";
#endif
#ifdef GL_SAMPLER_2D_ARB
	if ( en == GL_SAMPLER_2D_ARB ) return "GL_SAMPLER_2D_ARB";
#endif
#ifdef GL_SAMPLER_3D_ARB
	if ( en == GL_SAMPLER_3D_ARB ) return "GL_SAMPLER_3D_ARB";
#endif
#ifdef GL_SAMPLER_CUBE_ARB
	if ( en == GL_SAMPLER_CUBE_ARB ) return "GL_SAMPLER_CUBE_ARB";
#endif
#ifdef GL_SAMPLER_1D_SHADOW_ARB
	if ( en == GL_SAMPLER_1D_SHADOW_ARB ) return "GL_SAMPLER_1D_SHADOW_ARB";
#endif
#ifdef GL_SAMPLER_2D_SHADOW_ARB
	if ( en == GL_SAMPLER_2D_SHADOW_ARB ) return "GL_SAMPLER_2D_SHADOW_ARB";
#endif
#ifdef GL_SAMPLER_2D_RECT_ARB
	if ( en == GL_SAMPLER_2D_RECT_ARB ) return "GL_SAMPLER_2D_RECT_ARB";
#endif
#ifdef GL_SAMPLER_2D_RECT_SHADOW_ARB
	if ( en == GL_SAMPLER_2D_RECT_SHADOW_ARB ) return "GL_SAMPLER_2D_RECT_SHADOW_ARB";
#endif
#ifdef GL_OBJECT_DELETE_STATUS_ARB
	if ( en == GL_OBJECT_DELETE_STATUS_ARB ) return "GL_OBJECT_DELETE_STATUS_ARB";
#endif
#ifdef GL_OBJECT_COMPILE_STATUS_ARB
	if ( en == GL_OBJECT_COMPILE_STATUS_ARB ) return "GL_OBJECT_COMPILE_STATUS_ARB";
#endif
#ifdef GL_OBJECT_LINK_STATUS_ARB
	if ( en == GL_OBJECT_LINK_STATUS_ARB ) return "GL_OBJECT_LINK_STATUS_ARB";
#endif
#ifdef GL_OBJECT_VALIDATE_STATUS_ARB
	if ( en == GL_OBJECT_VALIDATE_STATUS_ARB ) return "GL_OBJECT_VALIDATE_STATUS_ARB";
#endif
#ifdef GL_OBJECT_INFO_LOG_LENGTH_ARB
	if ( en == GL_OBJECT_INFO_LOG_LENGTH_ARB ) return "GL_OBJECT_INFO_LOG_LENGTH_ARB";
#endif
#ifdef GL_OBJECT_ATTACHED_OBJECTS_ARB
	if ( en == GL_OBJECT_ATTACHED_OBJECTS_ARB ) return "GL_OBJECT_ATTACHED_OBJECTS_ARB";
#endif
#ifdef GL_OBJECT_ACTIVE_UNIFORMS_ARB
	if ( en == GL_OBJECT_ACTIVE_UNIFORMS_ARB ) return "GL_OBJECT_ACTIVE_UNIFORMS_ARB";
#endif
#ifdef GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB
	if ( en == GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB ) return "GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB";
#endif
#ifdef GL_OBJECT_SHADER_SOURCE_LENGTH_ARB
	if ( en == GL_OBJECT_SHADER_SOURCE_LENGTH_ARB ) return "GL_OBJECT_SHADER_SOURCE_LENGTH_ARB";
#endif
#ifdef GL_SHADER_STORAGE_BARRIER_BIT
	if ( en == GL_SHADER_STORAGE_BARRIER_BIT ) return "GL_SHADER_STORAGE_BARRIER_BIT";
#endif
#ifdef GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES
	if ( en == GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES ) return "GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES";
#endif
#ifdef GL_SHADER_STORAGE_BUFFER
	if ( en == GL_SHADER_STORAGE_BUFFER ) return "GL_SHADER_STORAGE_BUFFER";
#endif
#ifdef GL_SHADER_STORAGE_BUFFER_BINDING
	if ( en == GL_SHADER_STORAGE_BUFFER_BINDING ) return "GL_SHADER_STORAGE_BUFFER_BINDING";
#endif
#ifdef GL_SHADER_STORAGE_BUFFER_START
	if ( en == GL_SHADER_STORAGE_BUFFER_START ) return "GL_SHADER_STORAGE_BUFFER_START";
#endif
#ifdef GL_SHADER_STORAGE_BUFFER_SIZE
	if ( en == GL_SHADER_STORAGE_BUFFER_SIZE ) return "GL_SHADER_STORAGE_BUFFER_SIZE";
#endif
#ifdef GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS ) return "GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS ) return "GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS ) return "GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS ) return "GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS ) return "GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS ) return "GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS
	if ( en == GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS ) return "GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS";
#endif
#ifdef GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS
	if ( en == GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS ) return "GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS";
#endif
#ifdef GL_MAX_SHADER_STORAGE_BLOCK_SIZE
	if ( en == GL_MAX_SHADER_STORAGE_BLOCK_SIZE ) return "GL_MAX_SHADER_STORAGE_BLOCK_SIZE";
#endif
#ifdef GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT
	if ( en == GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT ) return "GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT";
#endif
#ifdef GL_ACTIVE_SUBROUTINES
	if ( en == GL_ACTIVE_SUBROUTINES ) return "GL_ACTIVE_SUBROUTINES";
#endif
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORMS
	if ( en == GL_ACTIVE_SUBROUTINE_UNIFORMS ) return "GL_ACTIVE_SUBROUTINE_UNIFORMS";
#endif
#ifdef GL_MAX_SUBROUTINES
	if ( en == GL_MAX_SUBROUTINES ) return "GL_MAX_SUBROUTINES";
#endif
#ifdef GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS
	if ( en == GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS ) return "GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS";
#endif
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS
	if ( en == GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS ) return "GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS";
#endif
#ifdef GL_ACTIVE_SUBROUTINE_MAX_LENGTH
	if ( en == GL_ACTIVE_SUBROUTINE_MAX_LENGTH ) return "GL_ACTIVE_SUBROUTINE_MAX_LENGTH";
#endif
#ifdef GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH
	if ( en == GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH ) return "GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH";
#endif
#ifdef GL_NUM_COMPATIBLE_SUBROUTINES
	if ( en == GL_NUM_COMPATIBLE_SUBROUTINES ) return "GL_NUM_COMPATIBLE_SUBROUTINES";
#endif
#ifdef GL_COMPATIBLE_SUBROUTINES
	if ( en == GL_COMPATIBLE_SUBROUTINES ) return "GL_COMPATIBLE_SUBROUTINES";
#endif
#ifdef GL_SHADING_LANGUAGE_VERSION_ARB
	if ( en == GL_SHADING_LANGUAGE_VERSION_ARB ) return "GL_SHADING_LANGUAGE_VERSION_ARB";
#endif
#ifdef GL_SHADER_INCLUDE_ARB
	if ( en == GL_SHADER_INCLUDE_ARB ) return "GL_SHADER_INCLUDE_ARB";
#endif
#ifdef GL_NAMED_STRING_LENGTH_ARB
	if ( en == GL_NAMED_STRING_LENGTH_ARB ) return "GL_NAMED_STRING_LENGTH_ARB";
#endif
#ifdef GL_NAMED_STRING_TYPE_ARB
	if ( en == GL_NAMED_STRING_TYPE_ARB ) return "GL_NAMED_STRING_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_COMPARE_MODE_ARB
	if ( en == GL_TEXTURE_COMPARE_MODE_ARB ) return "GL_TEXTURE_COMPARE_MODE_ARB";
#endif
#ifdef GL_TEXTURE_COMPARE_FUNC_ARB
	if ( en == GL_TEXTURE_COMPARE_FUNC_ARB ) return "GL_TEXTURE_COMPARE_FUNC_ARB";
#endif
#ifdef GL_COMPARE_R_TO_TEXTURE_ARB
	if ( en == GL_COMPARE_R_TO_TEXTURE_ARB ) return "GL_COMPARE_R_TO_TEXTURE_ARB";
#endif
#ifdef GL_TEXTURE_COMPARE_FAIL_VALUE_ARB
	if ( en == GL_TEXTURE_COMPARE_FAIL_VALUE_ARB ) return "GL_TEXTURE_COMPARE_FAIL_VALUE_ARB";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_X_ARB
	if ( en == GL_VIRTUAL_PAGE_SIZE_X_ARB ) return "GL_VIRTUAL_PAGE_SIZE_X_ARB";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_Y_ARB
	if ( en == GL_VIRTUAL_PAGE_SIZE_Y_ARB ) return "GL_VIRTUAL_PAGE_SIZE_Y_ARB";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_Z_ARB
	if ( en == GL_VIRTUAL_PAGE_SIZE_Z_ARB ) return "GL_VIRTUAL_PAGE_SIZE_Z_ARB";
#endif
#ifdef GL_MAX_SPARSE_TEXTURE_SIZE_ARB
	if ( en == GL_MAX_SPARSE_TEXTURE_SIZE_ARB ) return "GL_MAX_SPARSE_TEXTURE_SIZE_ARB";
#endif
#ifdef GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB
	if ( en == GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB ) return "GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB";
#endif
#ifdef GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB
	if ( en == GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB ) return "GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB";
#endif
#ifdef GL_TEXTURE_SPARSE_ARB
	if ( en == GL_TEXTURE_SPARSE_ARB ) return "GL_TEXTURE_SPARSE_ARB";
#endif
#ifdef GL_VIRTUAL_PAGE_SIZE_INDEX_ARB
	if ( en == GL_VIRTUAL_PAGE_SIZE_INDEX_ARB ) return "GL_VIRTUAL_PAGE_SIZE_INDEX_ARB";
#endif
#ifdef GL_NUM_VIRTUAL_PAGE_SIZES_ARB
	if ( en == GL_NUM_VIRTUAL_PAGE_SIZES_ARB ) return "GL_NUM_VIRTUAL_PAGE_SIZES_ARB";
#endif
#ifdef GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB
	if ( en == GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB ) return "GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB";
#endif
#ifdef GL_NUM_SPARSE_LEVELS_ARB
	if ( en == GL_NUM_SPARSE_LEVELS_ARB ) return "GL_NUM_SPARSE_LEVELS_ARB";
#endif
#ifdef GL_DEPTH_STENCIL_TEXTURE_MODE
	if ( en == GL_DEPTH_STENCIL_TEXTURE_MODE ) return "GL_DEPTH_STENCIL_TEXTURE_MODE";
#endif
#ifdef GL_SYNC_FLUSH_COMMANDS_BIT
	if ( en == GL_SYNC_FLUSH_COMMANDS_BIT ) return "GL_SYNC_FLUSH_COMMANDS_BIT";
#endif
#ifdef GL_MAX_SERVER_WAIT_TIMEOUT
	if ( en == GL_MAX_SERVER_WAIT_TIMEOUT ) return "GL_MAX_SERVER_WAIT_TIMEOUT";
#endif
#ifdef INFI_GL_OBJECT_TYPE
	if ( en == INFI_GL_OBJECT_TYPE ) return "INFI_GL_OBJECT_TYPE";
#endif
#ifdef GL_SYNC_CONDITION
	if ( en == GL_SYNC_CONDITION ) return "GL_SYNC_CONDITION";
#endif
#ifdef GL_SYNC_STATUS
	if ( en == GL_SYNC_STATUS ) return "GL_SYNC_STATUS";
#endif
#ifdef GL_SYNC_FLAGS
	if ( en == GL_SYNC_FLAGS ) return "GL_SYNC_FLAGS";
#endif
#ifdef GL_SYNC_FENCE
	if ( en == GL_SYNC_FENCE ) return "GL_SYNC_FENCE";
#endif
#ifdef GL_SYNC_GPU_COMMANDS_COMPLETE
	if ( en == GL_SYNC_GPU_COMMANDS_COMPLETE ) return "GL_SYNC_GPU_COMMANDS_COMPLETE";
#endif
#ifdef GL_UNSIGNALED
	if ( en == GL_UNSIGNALED ) return "GL_UNSIGNALED";
#endif
#ifdef GL_SIGNALED
	if ( en == GL_SIGNALED ) return "GL_SIGNALED";
#endif
#ifdef GL_ALREADY_SIGNALED
	if ( en == GL_ALREADY_SIGNALED ) return "GL_ALREADY_SIGNALED";
#endif
#ifdef GL_TIMEOUT_EXPIRED
	if ( en == GL_TIMEOUT_EXPIRED ) return "GL_TIMEOUT_EXPIRED";
#endif
#ifdef GL_CONDITION_SATISFIED
	if ( en == GL_CONDITION_SATISFIED ) return "GL_CONDITION_SATISFIED";
#endif
#ifdef GL_WAIT_FAILED
	if ( en == GL_WAIT_FAILED ) return "GL_WAIT_FAILED";
#endif
#ifdef GL_TIMEOUT_IGNORED
	if ( en == GL_TIMEOUT_IGNORED ) return "GL_TIMEOUT_IGNORED";
#endif
#ifdef GL_PATCHES
	if ( en == GL_PATCHES ) return "GL_PATCHES";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER";
#endif
#ifdef GL_MAX_TESS_CONTROL_INPUT_COMPONENTS
	if ( en == GL_MAX_TESS_CONTROL_INPUT_COMPONENTS ) return "GL_MAX_TESS_CONTROL_INPUT_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS
	if ( en == GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS ) return "GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS";
#endif
#ifdef GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS";
#endif
#ifdef GL_PATCH_VERTICES
	if ( en == GL_PATCH_VERTICES ) return "GL_PATCH_VERTICES";
#endif
#ifdef GL_PATCH_DEFAULT_INNER_LEVEL
	if ( en == GL_PATCH_DEFAULT_INNER_LEVEL ) return "GL_PATCH_DEFAULT_INNER_LEVEL";
#endif
#ifdef GL_PATCH_DEFAULT_OUTER_LEVEL
	if ( en == GL_PATCH_DEFAULT_OUTER_LEVEL ) return "GL_PATCH_DEFAULT_OUTER_LEVEL";
#endif
#ifdef GL_TESS_CONTROL_OUTPUT_VERTICES
	if ( en == GL_TESS_CONTROL_OUTPUT_VERTICES ) return "GL_TESS_CONTROL_OUTPUT_VERTICES";
#endif
#ifdef GL_TESS_GEN_MODE
	if ( en == GL_TESS_GEN_MODE ) return "GL_TESS_GEN_MODE";
#endif
#ifdef GL_TESS_GEN_SPACING
	if ( en == GL_TESS_GEN_SPACING ) return "GL_TESS_GEN_SPACING";
#endif
#ifdef GL_TESS_GEN_VERTEX_ORDER
	if ( en == GL_TESS_GEN_VERTEX_ORDER ) return "GL_TESS_GEN_VERTEX_ORDER";
#endif
#ifdef GL_TESS_GEN_POINT_MODE
	if ( en == GL_TESS_GEN_POINT_MODE ) return "GL_TESS_GEN_POINT_MODE";
#endif
#ifdef GL_ISOLINES
	if ( en == GL_ISOLINES ) return "GL_ISOLINES";
#endif
#ifdef GL_FRACTIONAL_ODD
	if ( en == GL_FRACTIONAL_ODD ) return "GL_FRACTIONAL_ODD";
#endif
#ifdef GL_FRACTIONAL_EVEN
	if ( en == GL_FRACTIONAL_EVEN ) return "GL_FRACTIONAL_EVEN";
#endif
#ifdef GL_MAX_PATCH_VERTICES
	if ( en == GL_MAX_PATCH_VERTICES ) return "GL_MAX_PATCH_VERTICES";
#endif
#ifdef GL_MAX_TESS_GEN_LEVEL
	if ( en == GL_MAX_TESS_GEN_LEVEL ) return "GL_MAX_TESS_GEN_LEVEL";
#endif
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS
	if ( en == GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS ) return "GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS
	if ( en == GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS ) return "GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS ) return "GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS
	if ( en == GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS ) return "GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS";
#endif
#ifdef GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS
	if ( en == GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS ) return "GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_PATCH_COMPONENTS
	if ( en == GL_MAX_TESS_PATCH_COMPONENTS ) return "GL_MAX_TESS_PATCH_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS
	if ( en == GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS ) return "GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS
	if ( en == GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS ) return "GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS";
#endif
#ifdef GL_TESS_EVALUATION_SHADER
	if ( en == GL_TESS_EVALUATION_SHADER ) return "GL_TESS_EVALUATION_SHADER";
#endif
#ifdef GL_TESS_CONTROL_SHADER
	if ( en == GL_TESS_CONTROL_SHADER ) return "GL_TESS_CONTROL_SHADER";
#endif
#ifdef GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS
	if ( en == GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS ) return "GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS
	if ( en == GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS ) return "GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS";
#endif
#ifdef GL_CLAMP_TO_BORDER_ARB
	if ( en == GL_CLAMP_TO_BORDER_ARB ) return "GL_CLAMP_TO_BORDER_ARB";
#endif
#ifdef GL_TEXTURE_BUFFER_ARB
	if ( en == GL_TEXTURE_BUFFER_ARB ) return "GL_TEXTURE_BUFFER_ARB";
#endif
#ifdef GL_MAX_TEXTURE_BUFFER_SIZE_ARB
	if ( en == GL_MAX_TEXTURE_BUFFER_SIZE_ARB ) return "GL_MAX_TEXTURE_BUFFER_SIZE_ARB";
#endif
#ifdef GL_TEXTURE_BINDING_BUFFER_ARB
	if ( en == GL_TEXTURE_BINDING_BUFFER_ARB ) return "GL_TEXTURE_BINDING_BUFFER_ARB";
#endif
#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB
	if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB ) return "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB";
#endif
#ifdef GL_TEXTURE_BUFFER_FORMAT_ARB
	if ( en == GL_TEXTURE_BUFFER_FORMAT_ARB ) return "GL_TEXTURE_BUFFER_FORMAT_ARB";
#endif
#ifdef GL_TEXTURE_BUFFER_OFFSET
	if ( en == GL_TEXTURE_BUFFER_OFFSET ) return "GL_TEXTURE_BUFFER_OFFSET";
#endif
#ifdef GL_TEXTURE_BUFFER_SIZE
	if ( en == GL_TEXTURE_BUFFER_SIZE ) return "GL_TEXTURE_BUFFER_SIZE";
#endif
#ifdef GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT
	if ( en == GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT ) return "GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT";
#endif
#ifdef GL_COMPRESSED_ALPHA_ARB
	if ( en == GL_COMPRESSED_ALPHA_ARB ) return "GL_COMPRESSED_ALPHA_ARB";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_ARB
	if ( en == GL_COMPRESSED_LUMINANCE_ARB ) return "GL_COMPRESSED_LUMINANCE_ARB";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_ARB
	if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_ARB ) return "GL_COMPRESSED_LUMINANCE_ALPHA_ARB";
#endif
#ifdef GL_COMPRESSED_INTENSITY_ARB
	if ( en == GL_COMPRESSED_INTENSITY_ARB ) return "GL_COMPRESSED_INTENSITY_ARB";
#endif
#ifdef GL_COMPRESSED_RGB_ARB
	if ( en == GL_COMPRESSED_RGB_ARB ) return "GL_COMPRESSED_RGB_ARB";
#endif
#ifdef GL_COMPRESSED_RGBA_ARB
	if ( en == GL_COMPRESSED_RGBA_ARB ) return "GL_COMPRESSED_RGBA_ARB";
#endif
#ifdef GL_TEXTURE_COMPRESSION_HINT_ARB
	if ( en == GL_TEXTURE_COMPRESSION_HINT_ARB ) return "GL_TEXTURE_COMPRESSION_HINT_ARB";
#endif
#ifdef GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB
	if ( en == GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB ) return "GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB";
#endif
#ifdef GL_TEXTURE_COMPRESSED_ARB
	if ( en == GL_TEXTURE_COMPRESSED_ARB ) return "GL_TEXTURE_COMPRESSED_ARB";
#endif
#ifdef GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB
	if ( en == GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB ) return "GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB";
#endif
#ifdef GL_COMPRESSED_TEXTURE_FORMATS_ARB
	if ( en == GL_COMPRESSED_TEXTURE_FORMATS_ARB ) return "GL_COMPRESSED_TEXTURE_FORMATS_ARB";
#endif
#ifdef GL_COMPRESSED_RGBA_BPTC_UNORM_ARB
	if ( en == GL_COMPRESSED_RGBA_BPTC_UNORM_ARB ) return "GL_COMPRESSED_RGBA_BPTC_UNORM_ARB";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB
	if ( en == GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB ) return "GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB";
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB
	if ( en == GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB ) return "GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB";
#endif
#ifdef GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB
	if ( en == GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB ) return "GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB";
#endif
#ifdef GL_COMPRESSED_RED_RGTC1
	if ( en == GL_COMPRESSED_RED_RGTC1 ) return "GL_COMPRESSED_RED_RGTC1";
#endif
#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1
	if ( en == GL_COMPRESSED_SIGNED_RED_RGTC1 ) return "GL_COMPRESSED_SIGNED_RED_RGTC1";
#endif
#ifdef GL_COMPRESSED_RG_RGTC2
	if ( en == GL_COMPRESSED_RG_RGTC2 ) return "GL_COMPRESSED_RG_RGTC2";
#endif
#ifdef GL_COMPRESSED_SIGNED_RG_RGTC2
	if ( en == GL_COMPRESSED_SIGNED_RG_RGTC2 ) return "GL_COMPRESSED_SIGNED_RG_RGTC2";
#endif
#ifdef GL_NORMAL_MAP_ARB
	if ( en == GL_NORMAL_MAP_ARB ) return "GL_NORMAL_MAP_ARB";
#endif
#ifdef GL_REFLECTION_MAP_ARB
	if ( en == GL_REFLECTION_MAP_ARB ) return "GL_REFLECTION_MAP_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_ARB ) return "GL_TEXTURE_CUBE_MAP_ARB";
#endif
#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARB
	if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARB ) return "GL_TEXTURE_BINDING_CUBE_MAP_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARB
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARB ) return "GL_PROXY_TEXTURE_CUBE_MAP_ARB";
#endif
#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB
	if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB ) return "GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_ARRAY_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_ARRAY_ARB ) return "GL_TEXTURE_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB
	if ( en == GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB ) return "GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB ) return "GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_ARB
	if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_ARB ) return "GL_SAMPLER_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB
	if ( en == GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB ) return "GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB";
#endif
#ifdef GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB
	if ( en == GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB ) return "GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB
	if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB ) return "GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB";
#endif
#ifdef GL_SUBTRACT_ARB
	if ( en == GL_SUBTRACT_ARB ) return "GL_SUBTRACT_ARB";
#endif
#ifdef GL_COMBINE_ARB
	if ( en == GL_COMBINE_ARB ) return "GL_COMBINE_ARB";
#endif
#ifdef GL_COMBINE_RGB_ARB
	if ( en == GL_COMBINE_RGB_ARB ) return "GL_COMBINE_RGB_ARB";
#endif
#ifdef GL_COMBINE_ALPHA_ARB
	if ( en == GL_COMBINE_ALPHA_ARB ) return "GL_COMBINE_ALPHA_ARB";
#endif
#ifdef GL_RGB_SCALE_ARB
	if ( en == GL_RGB_SCALE_ARB ) return "GL_RGB_SCALE_ARB";
#endif
#ifdef GL_ADD_SIGNED_ARB
	if ( en == GL_ADD_SIGNED_ARB ) return "GL_ADD_SIGNED_ARB";
#endif
#ifdef GL_INTERPOLATE_ARB
	if ( en == GL_INTERPOLATE_ARB ) return "GL_INTERPOLATE_ARB";
#endif
#ifdef GL_CONSTANT_ARB
	if ( en == GL_CONSTANT_ARB ) return "GL_CONSTANT_ARB";
#endif
#ifdef GL_PRIMARY_COLOR_ARB
	if ( en == GL_PRIMARY_COLOR_ARB ) return "GL_PRIMARY_COLOR_ARB";
#endif
#ifdef GL_PREVIOUS_ARB
	if ( en == GL_PREVIOUS_ARB ) return "GL_PREVIOUS_ARB";
#endif
#ifdef GL_SOURCE0_RGB_ARB
	if ( en == GL_SOURCE0_RGB_ARB ) return "GL_SOURCE0_RGB_ARB";
#endif
#ifdef GL_SOURCE1_RGB_ARB
	if ( en == GL_SOURCE1_RGB_ARB ) return "GL_SOURCE1_RGB_ARB";
#endif
#ifdef GL_SOURCE2_RGB_ARB
	if ( en == GL_SOURCE2_RGB_ARB ) return "GL_SOURCE2_RGB_ARB";
#endif
#ifdef GL_SOURCE0_ALPHA_ARB
	if ( en == GL_SOURCE0_ALPHA_ARB ) return "GL_SOURCE0_ALPHA_ARB";
#endif
#ifdef GL_SOURCE1_ALPHA_ARB
	if ( en == GL_SOURCE1_ALPHA_ARB ) return "GL_SOURCE1_ALPHA_ARB";
#endif
#ifdef GL_SOURCE2_ALPHA_ARB
	if ( en == GL_SOURCE2_ALPHA_ARB ) return "GL_SOURCE2_ALPHA_ARB";
#endif
#ifdef GL_OPERAND0_RGB_ARB
	if ( en == GL_OPERAND0_RGB_ARB ) return "GL_OPERAND0_RGB_ARB";
#endif
#ifdef GL_OPERAND1_RGB_ARB
	if ( en == GL_OPERAND1_RGB_ARB ) return "GL_OPERAND1_RGB_ARB";
#endif
#ifdef GL_OPERAND2_RGB_ARB
	if ( en == GL_OPERAND2_RGB_ARB ) return "GL_OPERAND2_RGB_ARB";
#endif
#ifdef GL_OPERAND0_ALPHA_ARB
	if ( en == GL_OPERAND0_ALPHA_ARB ) return "GL_OPERAND0_ALPHA_ARB";
#endif
#ifdef GL_OPERAND1_ALPHA_ARB
	if ( en == GL_OPERAND1_ALPHA_ARB ) return "GL_OPERAND1_ALPHA_ARB";
#endif
#ifdef GL_OPERAND2_ALPHA_ARB
	if ( en == GL_OPERAND2_ALPHA_ARB ) return "GL_OPERAND2_ALPHA_ARB";
#endif
#ifdef GL_DOT3_RGB_ARB
	if ( en == GL_DOT3_RGB_ARB ) return "GL_DOT3_RGB_ARB";
#endif
#ifdef GL_DOT3_RGBA_ARB
	if ( en == GL_DOT3_RGBA_ARB ) return "GL_DOT3_RGBA_ARB";
#endif
#ifdef GL_RGBA32F_ARB
	if ( en == GL_RGBA32F_ARB ) return "GL_RGBA32F_ARB";
#endif
#ifdef GL_RGB32F_ARB
	if ( en == GL_RGB32F_ARB ) return "GL_RGB32F_ARB";
#endif
#ifdef GL_ALPHA32F_ARB
	if ( en == GL_ALPHA32F_ARB ) return "GL_ALPHA32F_ARB";
#endif
#ifdef GL_INTENSITY32F_ARB
	if ( en == GL_INTENSITY32F_ARB ) return "GL_INTENSITY32F_ARB";
#endif
#ifdef GL_LUMINANCE32F_ARB
	if ( en == GL_LUMINANCE32F_ARB ) return "GL_LUMINANCE32F_ARB";
#endif
#ifdef GL_LUMINANCE_ALPHA32F_ARB
	if ( en == GL_LUMINANCE_ALPHA32F_ARB ) return "GL_LUMINANCE_ALPHA32F_ARB";
#endif
#ifdef GL_RGBA16F_ARB
	if ( en == GL_RGBA16F_ARB ) return "GL_RGBA16F_ARB";
#endif
#ifdef GL_RGB16F_ARB
	if ( en == GL_RGB16F_ARB ) return "GL_RGB16F_ARB";
#endif
#ifdef GL_ALPHA16F_ARB
	if ( en == GL_ALPHA16F_ARB ) return "GL_ALPHA16F_ARB";
#endif
#ifdef GL_INTENSITY16F_ARB
	if ( en == GL_INTENSITY16F_ARB ) return "GL_INTENSITY16F_ARB";
#endif
#ifdef GL_LUMINANCE16F_ARB
	if ( en == GL_LUMINANCE16F_ARB ) return "GL_LUMINANCE16F_ARB";
#endif
#ifdef GL_LUMINANCE_ALPHA16F_ARB
	if ( en == GL_LUMINANCE_ALPHA16F_ARB ) return "GL_LUMINANCE_ALPHA16F_ARB";
#endif
#ifdef GL_TEXTURE_RED_TYPE_ARB
	if ( en == GL_TEXTURE_RED_TYPE_ARB ) return "GL_TEXTURE_RED_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_GREEN_TYPE_ARB
	if ( en == GL_TEXTURE_GREEN_TYPE_ARB ) return "GL_TEXTURE_GREEN_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_BLUE_TYPE_ARB
	if ( en == GL_TEXTURE_BLUE_TYPE_ARB ) return "GL_TEXTURE_BLUE_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_ALPHA_TYPE_ARB
	if ( en == GL_TEXTURE_ALPHA_TYPE_ARB ) return "GL_TEXTURE_ALPHA_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_LUMINANCE_TYPE_ARB
	if ( en == GL_TEXTURE_LUMINANCE_TYPE_ARB ) return "GL_TEXTURE_LUMINANCE_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_INTENSITY_TYPE_ARB
	if ( en == GL_TEXTURE_INTENSITY_TYPE_ARB ) return "GL_TEXTURE_INTENSITY_TYPE_ARB";
#endif
#ifdef GL_TEXTURE_DEPTH_TYPE_ARB
	if ( en == GL_TEXTURE_DEPTH_TYPE_ARB ) return "GL_TEXTURE_DEPTH_TYPE_ARB";
#endif
#ifdef GL_UNSIGNED_NORMALIZED_ARB
	if ( en == GL_UNSIGNED_NORMALIZED_ARB ) return "GL_UNSIGNED_NORMALIZED_ARB";
#endif
#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB
	if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB ) return "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB";
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB
	if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB ) return "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB";
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB
	if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB ) return "GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB";
#endif
#ifdef GL_MIRROR_CLAMP_TO_EDGE
	if ( en == GL_MIRROR_CLAMP_TO_EDGE ) return "GL_MIRROR_CLAMP_TO_EDGE";
#endif
#ifdef GL_MIRRORED_REPEAT_ARB
	if ( en == GL_MIRRORED_REPEAT_ARB ) return "GL_MIRRORED_REPEAT_ARB";
#endif
#ifdef GL_SAMPLE_POSITION
	if ( en == GL_SAMPLE_POSITION ) return "GL_SAMPLE_POSITION";
#endif
#ifdef GL_SAMPLE_MASK
	if ( en == GL_SAMPLE_MASK ) return "GL_SAMPLE_MASK";
#endif
#ifdef GL_SAMPLE_MASK_VALUE
	if ( en == GL_SAMPLE_MASK_VALUE ) return "GL_SAMPLE_MASK_VALUE";
#endif
#ifdef GL_MAX_SAMPLE_MASK_WORDS
	if ( en == GL_MAX_SAMPLE_MASK_WORDS ) return "GL_MAX_SAMPLE_MASK_WORDS";
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE
	if ( en == GL_TEXTURE_2D_MULTISAMPLE ) return "GL_TEXTURE_2D_MULTISAMPLE";
#endif
#ifdef GL_PROXY_TEXTURE_2D_MULTISAMPLE
	if ( en == GL_PROXY_TEXTURE_2D_MULTISAMPLE ) return "GL_PROXY_TEXTURE_2D_MULTISAMPLE";
#endif
#ifdef GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	if ( en == GL_TEXTURE_2D_MULTISAMPLE_ARRAY ) return "GL_TEXTURE_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY
	if ( en == GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY ) return "GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE
	if ( en == GL_TEXTURE_BINDING_2D_MULTISAMPLE ) return "GL_TEXTURE_BINDING_2D_MULTISAMPLE";
#endif
#ifdef GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY
	if ( en == GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY ) return "GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_TEXTURE_SAMPLES
	if ( en == GL_TEXTURE_SAMPLES ) return "GL_TEXTURE_SAMPLES";
#endif
#ifdef GL_TEXTURE_FIXED_SAMPLE_LOCATIONS
	if ( en == GL_TEXTURE_FIXED_SAMPLE_LOCATIONS ) return "GL_TEXTURE_FIXED_SAMPLE_LOCATIONS";
#endif
#ifdef GL_SAMPLER_2D_MULTISAMPLE
	if ( en == GL_SAMPLER_2D_MULTISAMPLE ) return "GL_SAMPLER_2D_MULTISAMPLE";
#endif
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE
	if ( en == GL_INT_SAMPLER_2D_MULTISAMPLE ) return "GL_INT_SAMPLER_2D_MULTISAMPLE";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE ) return "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE";
#endif
#ifdef GL_SAMPLER_2D_MULTISAMPLE_ARRAY
	if ( en == GL_SAMPLER_2D_MULTISAMPLE_ARRAY ) return "GL_SAMPLER_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	if ( en == GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY ) return "GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY ) return "GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY";
#endif
#ifdef GL_MAX_COLOR_TEXTURE_SAMPLES
	if ( en == GL_MAX_COLOR_TEXTURE_SAMPLES ) return "GL_MAX_COLOR_TEXTURE_SAMPLES";
#endif
#ifdef GL_MAX_DEPTH_TEXTURE_SAMPLES
	if ( en == GL_MAX_DEPTH_TEXTURE_SAMPLES ) return "GL_MAX_DEPTH_TEXTURE_SAMPLES";
#endif
#ifdef GL_MAX_INTEGER_SAMPLES
	if ( en == GL_MAX_INTEGER_SAMPLES ) return "GL_MAX_INTEGER_SAMPLES";
#endif
#ifdef GL_TEXTURE_RECTANGLE_ARB
	if ( en == GL_TEXTURE_RECTANGLE_ARB ) return "GL_TEXTURE_RECTANGLE_ARB";
#endif
#ifdef GL_TEXTURE_BINDING_RECTANGLE_ARB
	if ( en == GL_TEXTURE_BINDING_RECTANGLE_ARB ) return "GL_TEXTURE_BINDING_RECTANGLE_ARB";
#endif
#ifdef GL_PROXY_TEXTURE_RECTANGLE_ARB
	if ( en == GL_PROXY_TEXTURE_RECTANGLE_ARB ) return "GL_PROXY_TEXTURE_RECTANGLE_ARB";
#endif
#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB
	if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB ) return "GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB";
#endif
#ifdef GL_SAMPLER_2D_RECT_ARB
	if ( en == GL_SAMPLER_2D_RECT_ARB ) return "GL_SAMPLER_2D_RECT_ARB";
#endif
#ifdef GL_SAMPLER_2D_RECT_SHADOW_ARB
	if ( en == GL_SAMPLER_2D_RECT_SHADOW_ARB ) return "GL_SAMPLER_2D_RECT_SHADOW_ARB";
#endif
#ifdef GL_COMPRESSED_RED
	if ( en == GL_COMPRESSED_RED ) return "GL_COMPRESSED_RED";
#endif
#ifdef GL_COMPRESSED_RG
	if ( en == GL_COMPRESSED_RG ) return "GL_COMPRESSED_RG";
#endif
#ifdef GL_RG
	if ( en == GL_RG ) return "GL_RG";
#endif
#ifdef GL_RG_INTEGER
	if ( en == GL_RG_INTEGER ) return "GL_RG_INTEGER";
#endif
#ifdef GL_R8
	if ( en == GL_R8 ) return "GL_R8";
#endif
#ifdef GL_R16
	if ( en == GL_R16 ) return "GL_R16";
#endif
#ifdef GL_RG8
	if ( en == GL_RG8 ) return "GL_RG8";
#endif
#ifdef GL_RG16
	if ( en == GL_RG16 ) return "GL_RG16";
#endif
#ifdef GL_R16F
	if ( en == GL_R16F ) return "GL_R16F";
#endif
#ifdef GL_R32F
	if ( en == GL_R32F ) return "GL_R32F";
#endif
#ifdef GL_RG16F
	if ( en == GL_RG16F ) return "GL_RG16F";
#endif
#ifdef GL_RG32F
	if ( en == GL_RG32F ) return "GL_RG32F";
#endif
#ifdef GL_R8I
	if ( en == GL_R8I ) return "GL_R8I";
#endif
#ifdef GL_R8UI
	if ( en == GL_R8UI ) return "GL_R8UI";
#endif
#ifdef GL_R16I
	if ( en == GL_R16I ) return "GL_R16I";
#endif
#ifdef GL_R16UI
	if ( en == GL_R16UI ) return "GL_R16UI";
#endif
#ifdef GL_R32I
	if ( en == GL_R32I ) return "GL_R32I";
#endif
#ifdef GL_R32UI
	if ( en == GL_R32UI ) return "GL_R32UI";
#endif
#ifdef GL_RG8I
	if ( en == GL_RG8I ) return "GL_RG8I";
#endif
#ifdef GL_RG8UI
	if ( en == GL_RG8UI ) return "GL_RG8UI";
#endif
#ifdef GL_RG16I
	if ( en == GL_RG16I ) return "GL_RG16I";
#endif
#ifdef GL_RG16UI
	if ( en == GL_RG16UI ) return "GL_RG16UI";
#endif
#ifdef GL_RG32I
	if ( en == GL_RG32I ) return "GL_RG32I";
#endif
#ifdef GL_RG32UI
	if ( en == GL_RG32UI ) return "GL_RG32UI";
#endif
#ifdef GL_RGB10_A2UI
	if ( en == GL_RGB10_A2UI ) return "GL_RGB10_A2UI";
#endif
#ifdef GL_STENCIL_INDEX
	if ( en == GL_STENCIL_INDEX ) return "GL_STENCIL_INDEX";
#endif
#ifdef GL_STENCIL_INDEX8
	if ( en == GL_STENCIL_INDEX8 ) return "GL_STENCIL_INDEX8";
#endif
#ifdef GL_TEXTURE_IMMUTABLE_FORMAT
	if ( en == GL_TEXTURE_IMMUTABLE_FORMAT ) return "GL_TEXTURE_IMMUTABLE_FORMAT";
#endif
#ifdef GL_TEXTURE_SWIZZLE_R
	if ( en == GL_TEXTURE_SWIZZLE_R ) return "GL_TEXTURE_SWIZZLE_R";
#endif
#ifdef GL_TEXTURE_SWIZZLE_G
	if ( en == GL_TEXTURE_SWIZZLE_G ) return "GL_TEXTURE_SWIZZLE_G";
#endif
#ifdef GL_TEXTURE_SWIZZLE_B
	if ( en == GL_TEXTURE_SWIZZLE_B ) return "GL_TEXTURE_SWIZZLE_B";
#endif
#ifdef GL_TEXTURE_SWIZZLE_A
	if ( en == GL_TEXTURE_SWIZZLE_A ) return "GL_TEXTURE_SWIZZLE_A";
#endif
#ifdef GL_TEXTURE_SWIZZLE_RGBA
	if ( en == GL_TEXTURE_SWIZZLE_RGBA ) return "GL_TEXTURE_SWIZZLE_RGBA";
#endif
#ifdef GL_TEXTURE_VIEW_MIN_LEVEL
	if ( en == GL_TEXTURE_VIEW_MIN_LEVEL ) return "GL_TEXTURE_VIEW_MIN_LEVEL";
#endif
#ifdef GL_TEXTURE_VIEW_NUM_LEVELS
	if ( en == GL_TEXTURE_VIEW_NUM_LEVELS ) return "GL_TEXTURE_VIEW_NUM_LEVELS";
#endif
#ifdef GL_TEXTURE_VIEW_MIN_LAYER
	if ( en == GL_TEXTURE_VIEW_MIN_LAYER ) return "GL_TEXTURE_VIEW_MIN_LAYER";
#endif
#ifdef GL_TEXTURE_VIEW_NUM_LAYERS
	if ( en == GL_TEXTURE_VIEW_NUM_LAYERS ) return "GL_TEXTURE_VIEW_NUM_LAYERS";
#endif
#ifdef GL_TEXTURE_IMMUTABLE_LEVELS
	if ( en == GL_TEXTURE_IMMUTABLE_LEVELS ) return "GL_TEXTURE_IMMUTABLE_LEVELS";
#endif
#ifdef GL_TIME_ELAPSED
	if ( en == GL_TIME_ELAPSED ) return "GL_TIME_ELAPSED";
#endif
#ifdef GL_TIMESTAMP
	if ( en == GL_TIMESTAMP ) return "GL_TIMESTAMP";
#endif
#ifdef GL_TRANSFORM_FEEDBACK
	if ( en == GL_TRANSFORM_FEEDBACK ) return "GL_TRANSFORM_FEEDBACK";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED ) return "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE ) return "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BINDING
	if ( en == GL_TRANSFORM_FEEDBACK_BINDING ) return "GL_TRANSFORM_FEEDBACK_BINDING";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_BUFFERS
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_BUFFERS ) return "GL_MAX_TRANSFORM_FEEDBACK_BUFFERS";
#endif
#ifdef GL_MAX_VERTEX_STREAMS
	if ( en == GL_MAX_VERTEX_STREAMS ) return "GL_MAX_VERTEX_STREAMS";
#endif
#ifdef GL_TRANSPOSE_MODELVIEW_MATRIX_ARB
	if ( en == GL_TRANSPOSE_MODELVIEW_MATRIX_ARB ) return "GL_TRANSPOSE_MODELVIEW_MATRIX_ARB";
#endif
#ifdef GL_TRANSPOSE_PROJECTION_MATRIX_ARB
	if ( en == GL_TRANSPOSE_PROJECTION_MATRIX_ARB ) return "GL_TRANSPOSE_PROJECTION_MATRIX_ARB";
#endif
#ifdef GL_TRANSPOSE_TEXTURE_MATRIX_ARB
	if ( en == GL_TRANSPOSE_TEXTURE_MATRIX_ARB ) return "GL_TRANSPOSE_TEXTURE_MATRIX_ARB";
#endif
#ifdef GL_TRANSPOSE_COLOR_MATRIX_ARB
	if ( en == GL_TRANSPOSE_COLOR_MATRIX_ARB ) return "GL_TRANSPOSE_COLOR_MATRIX_ARB";
#endif
#ifdef GL_UNIFORM_BUFFER
	if ( en == GL_UNIFORM_BUFFER ) return "GL_UNIFORM_BUFFER";
#endif
#ifdef GL_UNIFORM_BUFFER_BINDING
	if ( en == GL_UNIFORM_BUFFER_BINDING ) return "GL_UNIFORM_BUFFER_BINDING";
#endif
#ifdef GL_UNIFORM_BUFFER_START
	if ( en == GL_UNIFORM_BUFFER_START ) return "GL_UNIFORM_BUFFER_START";
#endif
#ifdef GL_UNIFORM_BUFFER_SIZE
	if ( en == GL_UNIFORM_BUFFER_SIZE ) return "GL_UNIFORM_BUFFER_SIZE";
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_BLOCKS
	if ( en == GL_MAX_VERTEX_UNIFORM_BLOCKS ) return "GL_MAX_VERTEX_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_BLOCKS
	if ( en == GL_MAX_GEOMETRY_UNIFORM_BLOCKS ) return "GL_MAX_GEOMETRY_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_FRAGMENT_UNIFORM_BLOCKS
	if ( en == GL_MAX_FRAGMENT_UNIFORM_BLOCKS ) return "GL_MAX_FRAGMENT_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_COMBINED_UNIFORM_BLOCKS
	if ( en == GL_MAX_COMBINED_UNIFORM_BLOCKS ) return "GL_MAX_COMBINED_UNIFORM_BLOCKS";
#endif
#ifdef GL_MAX_UNIFORM_BUFFER_BINDINGS
	if ( en == GL_MAX_UNIFORM_BUFFER_BINDINGS ) return "GL_MAX_UNIFORM_BUFFER_BINDINGS";
#endif
#ifdef GL_MAX_UNIFORM_BLOCK_SIZE
	if ( en == GL_MAX_UNIFORM_BLOCK_SIZE ) return "GL_MAX_UNIFORM_BLOCK_SIZE";
#endif
#ifdef GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS";
#endif
#ifdef GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS
	if ( en == GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS ) return "GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS";
#endif
#ifdef GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT
	if ( en == GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT ) return "GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT";
#endif
#ifdef GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH
	if ( en == GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH ) return "GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH";
#endif
#ifdef GL_ACTIVE_UNIFORM_BLOCKS
	if ( en == GL_ACTIVE_UNIFORM_BLOCKS ) return "GL_ACTIVE_UNIFORM_BLOCKS";
#endif
#ifdef GL_UNIFORM_TYPE
	if ( en == GL_UNIFORM_TYPE ) return "GL_UNIFORM_TYPE";
#endif
#ifdef GL_UNIFORM_SIZE
	if ( en == GL_UNIFORM_SIZE ) return "GL_UNIFORM_SIZE";
#endif
#ifdef GL_UNIFORM_NAME_LENGTH
	if ( en == GL_UNIFORM_NAME_LENGTH ) return "GL_UNIFORM_NAME_LENGTH";
#endif
#ifdef GL_UNIFORM_BLOCK_INDEX
	if ( en == GL_UNIFORM_BLOCK_INDEX ) return "GL_UNIFORM_BLOCK_INDEX";
#endif
#ifdef GL_UNIFORM_OFFSET
	if ( en == GL_UNIFORM_OFFSET ) return "GL_UNIFORM_OFFSET";
#endif
#ifdef GL_UNIFORM_ARRAY_STRIDE
	if ( en == GL_UNIFORM_ARRAY_STRIDE ) return "GL_UNIFORM_ARRAY_STRIDE";
#endif
#ifdef GL_UNIFORM_MATRIX_STRIDE
	if ( en == GL_UNIFORM_MATRIX_STRIDE ) return "GL_UNIFORM_MATRIX_STRIDE";
#endif
#ifdef GL_UNIFORM_IS_ROW_MAJOR
	if ( en == GL_UNIFORM_IS_ROW_MAJOR ) return "GL_UNIFORM_IS_ROW_MAJOR";
#endif
#ifdef GL_UNIFORM_BLOCK_BINDING
	if ( en == GL_UNIFORM_BLOCK_BINDING ) return "GL_UNIFORM_BLOCK_BINDING";
#endif
#ifdef GL_UNIFORM_BLOCK_DATA_SIZE
	if ( en == GL_UNIFORM_BLOCK_DATA_SIZE ) return "GL_UNIFORM_BLOCK_DATA_SIZE";
#endif
#ifdef GL_UNIFORM_BLOCK_NAME_LENGTH
	if ( en == GL_UNIFORM_BLOCK_NAME_LENGTH ) return "GL_UNIFORM_BLOCK_NAME_LENGTH";
#endif
#ifdef GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS
	if ( en == GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS ) return "GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS";
#endif
#ifdef GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES
	if ( en == GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES ) return "GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER";
#endif
#ifdef GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER
	if ( en == GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER ) return "GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER";
#endif
#ifdef GL_INVALID_INDEX
	if ( en == GL_INVALID_INDEX ) return "GL_INVALID_INDEX";
#endif
#ifdef GL_BGRA
	if ( en == GL_BGRA ) return "GL_BGRA";
#endif
#ifdef GL_VERTEX_ARRAY_BINDING
	if ( en == GL_VERTEX_ARRAY_BINDING ) return "GL_VERTEX_ARRAY_BINDING";
#endif
#ifdef GL_VERTEX_ATTRIB_BINDING
	if ( en == GL_VERTEX_ATTRIB_BINDING ) return "GL_VERTEX_ATTRIB_BINDING";
#endif
#ifdef GL_VERTEX_ATTRIB_RELATIVE_OFFSET
	if ( en == GL_VERTEX_ATTRIB_RELATIVE_OFFSET ) return "GL_VERTEX_ATTRIB_RELATIVE_OFFSET";
#endif
#ifdef GL_VERTEX_BINDING_DIVISOR
	if ( en == GL_VERTEX_BINDING_DIVISOR ) return "GL_VERTEX_BINDING_DIVISOR";
#endif
#ifdef GL_VERTEX_BINDING_OFFSET
	if ( en == GL_VERTEX_BINDING_OFFSET ) return "GL_VERTEX_BINDING_OFFSET";
#endif
#ifdef GL_VERTEX_BINDING_STRIDE
	if ( en == GL_VERTEX_BINDING_STRIDE ) return "GL_VERTEX_BINDING_STRIDE";
#endif
#ifdef GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET
	if ( en == GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET ) return "GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET";
#endif
#ifdef GL_MAX_VERTEX_ATTRIB_BINDINGS
	if ( en == GL_MAX_VERTEX_ATTRIB_BINDINGS ) return "GL_MAX_VERTEX_ATTRIB_BINDINGS";
#endif
#ifdef GL_MODELVIEW0_ARB
	if ( en == GL_MODELVIEW0_ARB ) return "GL_MODELVIEW0_ARB";
#endif
#ifdef GL_MODELVIEW1_ARB
	if ( en == GL_MODELVIEW1_ARB ) return "GL_MODELVIEW1_ARB";
#endif
#ifdef GL_MAX_VERTEX_UNITS_ARB
	if ( en == GL_MAX_VERTEX_UNITS_ARB ) return "GL_MAX_VERTEX_UNITS_ARB";
#endif
#ifdef GL_ACTIVE_VERTEX_UNITS_ARB
	if ( en == GL_ACTIVE_VERTEX_UNITS_ARB ) return "GL_ACTIVE_VERTEX_UNITS_ARB";
#endif
#ifdef GL_WEIGHT_SUM_UNITY_ARB
	if ( en == GL_WEIGHT_SUM_UNITY_ARB ) return "GL_WEIGHT_SUM_UNITY_ARB";
#endif
#ifdef GL_VERTEX_BLEND_ARB
	if ( en == GL_VERTEX_BLEND_ARB ) return "GL_VERTEX_BLEND_ARB";
#endif
#ifdef GL_CURRENT_WEIGHT_ARB
	if ( en == GL_CURRENT_WEIGHT_ARB ) return "GL_CURRENT_WEIGHT_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_TYPE_ARB
	if ( en == GL_WEIGHT_ARRAY_TYPE_ARB ) return "GL_WEIGHT_ARRAY_TYPE_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_STRIDE_ARB
	if ( en == GL_WEIGHT_ARRAY_STRIDE_ARB ) return "GL_WEIGHT_ARRAY_STRIDE_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_SIZE_ARB
	if ( en == GL_WEIGHT_ARRAY_SIZE_ARB ) return "GL_WEIGHT_ARRAY_SIZE_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_POINTER_ARB
	if ( en == GL_WEIGHT_ARRAY_POINTER_ARB ) return "GL_WEIGHT_ARRAY_POINTER_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_ARB
	if ( en == GL_WEIGHT_ARRAY_ARB ) return "GL_WEIGHT_ARRAY_ARB";
#endif
#ifdef GL_MODELVIEW2_ARB
	if ( en == GL_MODELVIEW2_ARB ) return "GL_MODELVIEW2_ARB";
#endif
#ifdef GL_MODELVIEW3_ARB
	if ( en == GL_MODELVIEW3_ARB ) return "GL_MODELVIEW3_ARB";
#endif
#ifdef GL_MODELVIEW4_ARB
	if ( en == GL_MODELVIEW4_ARB ) return "GL_MODELVIEW4_ARB";
#endif
#ifdef GL_MODELVIEW5_ARB
	if ( en == GL_MODELVIEW5_ARB ) return "GL_MODELVIEW5_ARB";
#endif
#ifdef GL_MODELVIEW6_ARB
	if ( en == GL_MODELVIEW6_ARB ) return "GL_MODELVIEW6_ARB";
#endif
#ifdef GL_MODELVIEW7_ARB
	if ( en == GL_MODELVIEW7_ARB ) return "GL_MODELVIEW7_ARB";
#endif
#ifdef GL_MODELVIEW8_ARB
	if ( en == GL_MODELVIEW8_ARB ) return "GL_MODELVIEW8_ARB";
#endif
#ifdef GL_MODELVIEW9_ARB
	if ( en == GL_MODELVIEW9_ARB ) return "GL_MODELVIEW9_ARB";
#endif
#ifdef GL_MODELVIEW10_ARB
	if ( en == GL_MODELVIEW10_ARB ) return "GL_MODELVIEW10_ARB";
#endif
#ifdef GL_MODELVIEW11_ARB
	if ( en == GL_MODELVIEW11_ARB ) return "GL_MODELVIEW11_ARB";
#endif
#ifdef GL_MODELVIEW12_ARB
	if ( en == GL_MODELVIEW12_ARB ) return "GL_MODELVIEW12_ARB";
#endif
#ifdef GL_MODELVIEW13_ARB
	if ( en == GL_MODELVIEW13_ARB ) return "GL_MODELVIEW13_ARB";
#endif
#ifdef GL_MODELVIEW14_ARB
	if ( en == GL_MODELVIEW14_ARB ) return "GL_MODELVIEW14_ARB";
#endif
#ifdef GL_MODELVIEW15_ARB
	if ( en == GL_MODELVIEW15_ARB ) return "GL_MODELVIEW15_ARB";
#endif
#ifdef GL_MODELVIEW16_ARB
	if ( en == GL_MODELVIEW16_ARB ) return "GL_MODELVIEW16_ARB";
#endif
#ifdef GL_MODELVIEW17_ARB
	if ( en == GL_MODELVIEW17_ARB ) return "GL_MODELVIEW17_ARB";
#endif
#ifdef GL_MODELVIEW18_ARB
	if ( en == GL_MODELVIEW18_ARB ) return "GL_MODELVIEW18_ARB";
#endif
#ifdef GL_MODELVIEW19_ARB
	if ( en == GL_MODELVIEW19_ARB ) return "GL_MODELVIEW19_ARB";
#endif
#ifdef GL_MODELVIEW20_ARB
	if ( en == GL_MODELVIEW20_ARB ) return "GL_MODELVIEW20_ARB";
#endif
#ifdef GL_MODELVIEW21_ARB
	if ( en == GL_MODELVIEW21_ARB ) return "GL_MODELVIEW21_ARB";
#endif
#ifdef GL_MODELVIEW22_ARB
	if ( en == GL_MODELVIEW22_ARB ) return "GL_MODELVIEW22_ARB";
#endif
#ifdef GL_MODELVIEW23_ARB
	if ( en == GL_MODELVIEW23_ARB ) return "GL_MODELVIEW23_ARB";
#endif
#ifdef GL_MODELVIEW24_ARB
	if ( en == GL_MODELVIEW24_ARB ) return "GL_MODELVIEW24_ARB";
#endif
#ifdef GL_MODELVIEW25_ARB
	if ( en == GL_MODELVIEW25_ARB ) return "GL_MODELVIEW25_ARB";
#endif
#ifdef GL_MODELVIEW26_ARB
	if ( en == GL_MODELVIEW26_ARB ) return "GL_MODELVIEW26_ARB";
#endif
#ifdef GL_MODELVIEW27_ARB
	if ( en == GL_MODELVIEW27_ARB ) return "GL_MODELVIEW27_ARB";
#endif
#ifdef GL_MODELVIEW28_ARB
	if ( en == GL_MODELVIEW28_ARB ) return "GL_MODELVIEW28_ARB";
#endif
#ifdef GL_MODELVIEW29_ARB
	if ( en == GL_MODELVIEW29_ARB ) return "GL_MODELVIEW29_ARB";
#endif
#ifdef GL_MODELVIEW30_ARB
	if ( en == GL_MODELVIEW30_ARB ) return "GL_MODELVIEW30_ARB";
#endif
#ifdef GL_MODELVIEW31_ARB
	if ( en == GL_MODELVIEW31_ARB ) return "GL_MODELVIEW31_ARB";
#endif
#ifdef GL_BUFFER_SIZE_ARB
	if ( en == GL_BUFFER_SIZE_ARB ) return "GL_BUFFER_SIZE_ARB";
#endif
#ifdef GL_BUFFER_USAGE_ARB
	if ( en == GL_BUFFER_USAGE_ARB ) return "GL_BUFFER_USAGE_ARB";
#endif
#ifdef GL_ARRAY_BUFFER_ARB
	if ( en == GL_ARRAY_BUFFER_ARB ) return "GL_ARRAY_BUFFER_ARB";
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER_ARB
	if ( en == GL_ELEMENT_ARRAY_BUFFER_ARB ) return "GL_ELEMENT_ARRAY_BUFFER_ARB";
#endif
#ifdef GL_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_ARRAY_BUFFER_BINDING_ARB ) return "GL_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB ) return "GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_VERTEX_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_VERTEX_ARRAY_BUFFER_BINDING_ARB ) return "GL_VERTEX_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_NORMAL_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_NORMAL_ARRAY_BUFFER_BINDING_ARB ) return "GL_NORMAL_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_COLOR_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_COLOR_ARRAY_BUFFER_BINDING_ARB ) return "GL_COLOR_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_INDEX_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_INDEX_ARRAY_BUFFER_BINDING_ARB ) return "GL_INDEX_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB ) return "GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB ) return "GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB ) return "GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB ) return "GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB ) return "GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB";
#endif
#ifdef GL_READ_ONLY_ARB
	if ( en == GL_READ_ONLY_ARB ) return "GL_READ_ONLY_ARB";
#endif
#ifdef GL_WRITE_ONLY_ARB
	if ( en == GL_WRITE_ONLY_ARB ) return "GL_WRITE_ONLY_ARB";
#endif
#ifdef GL_READ_WRITE_ARB
	if ( en == GL_READ_WRITE_ARB ) return "GL_READ_WRITE_ARB";
#endif
#ifdef GL_BUFFER_ACCESS_ARB
	if ( en == GL_BUFFER_ACCESS_ARB ) return "GL_BUFFER_ACCESS_ARB";
#endif
#ifdef GL_BUFFER_MAPPED_ARB
	if ( en == GL_BUFFER_MAPPED_ARB ) return "GL_BUFFER_MAPPED_ARB";
#endif
#ifdef GL_BUFFER_MAP_POINTER_ARB
	if ( en == GL_BUFFER_MAP_POINTER_ARB ) return "GL_BUFFER_MAP_POINTER_ARB";
#endif
#ifdef GL_STREAM_DRAW_ARB
	if ( en == GL_STREAM_DRAW_ARB ) return "GL_STREAM_DRAW_ARB";
#endif
#ifdef GL_STREAM_READ_ARB
	if ( en == GL_STREAM_READ_ARB ) return "GL_STREAM_READ_ARB";
#endif
#ifdef GL_STREAM_COPY_ARB
	if ( en == GL_STREAM_COPY_ARB ) return "GL_STREAM_COPY_ARB";
#endif
#ifdef GL_STATIC_DRAW_ARB
	if ( en == GL_STATIC_DRAW_ARB ) return "GL_STATIC_DRAW_ARB";
#endif
#ifdef GL_STATIC_READ_ARB
	if ( en == GL_STATIC_READ_ARB ) return "GL_STATIC_READ_ARB";
#endif
#ifdef GL_STATIC_COPY_ARB
	if ( en == GL_STATIC_COPY_ARB ) return "GL_STATIC_COPY_ARB";
#endif
#ifdef GL_DYNAMIC_DRAW_ARB
	if ( en == GL_DYNAMIC_DRAW_ARB ) return "GL_DYNAMIC_DRAW_ARB";
#endif
#ifdef GL_DYNAMIC_READ_ARB
	if ( en == GL_DYNAMIC_READ_ARB ) return "GL_DYNAMIC_READ_ARB";
#endif
#ifdef GL_DYNAMIC_COPY_ARB
	if ( en == GL_DYNAMIC_COPY_ARB ) return "GL_DYNAMIC_COPY_ARB";
#endif
#ifdef GL_COLOR_SUM_ARB
	if ( en == GL_COLOR_SUM_ARB ) return "GL_COLOR_SUM_ARB";
#endif
#ifdef GL_VERTEX_PROGRAM_ARB
	if ( en == GL_VERTEX_PROGRAM_ARB ) return "GL_VERTEX_PROGRAM_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB";
#endif
#ifdef GL_CURRENT_VERTEX_ATTRIB_ARB
	if ( en == GL_CURRENT_VERTEX_ATTRIB_ARB ) return "GL_CURRENT_VERTEX_ATTRIB_ARB";
#endif
#ifdef GL_PROGRAM_LENGTH_ARB
	if ( en == GL_PROGRAM_LENGTH_ARB ) return "GL_PROGRAM_LENGTH_ARB";
#endif
#ifdef GL_PROGRAM_STRING_ARB
	if ( en == GL_PROGRAM_STRING_ARB ) return "GL_PROGRAM_STRING_ARB";
#endif
#ifdef GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB
	if ( en == GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB ) return "GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB";
#endif
#ifdef GL_MAX_PROGRAM_MATRICES_ARB
	if ( en == GL_MAX_PROGRAM_MATRICES_ARB ) return "GL_MAX_PROGRAM_MATRICES_ARB";
#endif
#ifdef GL_CURRENT_MATRIX_STACK_DEPTH_ARB
	if ( en == GL_CURRENT_MATRIX_STACK_DEPTH_ARB ) return "GL_CURRENT_MATRIX_STACK_DEPTH_ARB";
#endif
#ifdef GL_CURRENT_MATRIX_ARB
	if ( en == GL_CURRENT_MATRIX_ARB ) return "GL_CURRENT_MATRIX_ARB";
#endif
#ifdef GL_VERTEX_PROGRAM_POINT_SIZE_ARB
	if ( en == GL_VERTEX_PROGRAM_POINT_SIZE_ARB ) return "GL_VERTEX_PROGRAM_POINT_SIZE_ARB";
#endif
#ifdef GL_VERTEX_PROGRAM_TWO_SIDE_ARB
	if ( en == GL_VERTEX_PROGRAM_TWO_SIDE_ARB ) return "GL_VERTEX_PROGRAM_TWO_SIDE_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB";
#endif
#ifdef GL_PROGRAM_ERROR_POSITION_ARB
	if ( en == GL_PROGRAM_ERROR_POSITION_ARB ) return "GL_PROGRAM_ERROR_POSITION_ARB";
#endif
#ifdef GL_PROGRAM_BINDING_ARB
	if ( en == GL_PROGRAM_BINDING_ARB ) return "GL_PROGRAM_BINDING_ARB";
#endif
#ifdef GL_MAX_VERTEX_ATTRIBS_ARB
	if ( en == GL_MAX_VERTEX_ATTRIBS_ARB ) return "GL_MAX_VERTEX_ATTRIBS_ARB";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB
	if ( en == GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB ) return "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB";
#endif
#ifdef GL_PROGRAM_ERROR_STRING_ARB
	if ( en == GL_PROGRAM_ERROR_STRING_ARB ) return "GL_PROGRAM_ERROR_STRING_ARB";
#endif
#ifdef GL_PROGRAM_FORMAT_ASCII_ARB
	if ( en == GL_PROGRAM_FORMAT_ASCII_ARB ) return "GL_PROGRAM_FORMAT_ASCII_ARB";
#endif
#ifdef GL_PROGRAM_FORMAT_ARB
	if ( en == GL_PROGRAM_FORMAT_ARB ) return "GL_PROGRAM_FORMAT_ARB";
#endif
#ifdef GL_PROGRAM_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_INSTRUCTIONS_ARB ) return "GL_PROGRAM_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB
	if ( en == GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB ) return "GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB ) return "GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB";
#endif
#ifdef GL_PROGRAM_TEMPORARIES_ARB
	if ( en == GL_PROGRAM_TEMPORARIES_ARB ) return "GL_PROGRAM_TEMPORARIES_ARB";
#endif
#ifdef GL_MAX_PROGRAM_TEMPORARIES_ARB
	if ( en == GL_MAX_PROGRAM_TEMPORARIES_ARB ) return "GL_MAX_PROGRAM_TEMPORARIES_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_TEMPORARIES_ARB
	if ( en == GL_PROGRAM_NATIVE_TEMPORARIES_ARB ) return "GL_PROGRAM_NATIVE_TEMPORARIES_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB ) return "GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB";
#endif
#ifdef GL_PROGRAM_PARAMETERS_ARB
	if ( en == GL_PROGRAM_PARAMETERS_ARB ) return "GL_PROGRAM_PARAMETERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_PARAMETERS_ARB
	if ( en == GL_MAX_PROGRAM_PARAMETERS_ARB ) return "GL_MAX_PROGRAM_PARAMETERS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_PARAMETERS_ARB
	if ( en == GL_PROGRAM_NATIVE_PARAMETERS_ARB ) return "GL_PROGRAM_NATIVE_PARAMETERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB ) return "GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB";
#endif
#ifdef GL_PROGRAM_ATTRIBS_ARB
	if ( en == GL_PROGRAM_ATTRIBS_ARB ) return "GL_PROGRAM_ATTRIBS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_ATTRIBS_ARB
	if ( en == GL_MAX_PROGRAM_ATTRIBS_ARB ) return "GL_MAX_PROGRAM_ATTRIBS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_ATTRIBS_ARB
	if ( en == GL_PROGRAM_NATIVE_ATTRIBS_ARB ) return "GL_PROGRAM_NATIVE_ATTRIBS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB ) return "GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB";
#endif
#ifdef GL_PROGRAM_ADDRESS_REGISTERS_ARB
	if ( en == GL_PROGRAM_ADDRESS_REGISTERS_ARB ) return "GL_PROGRAM_ADDRESS_REGISTERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB
	if ( en == GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB ) return "GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB";
#endif
#ifdef GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB
	if ( en == GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB ) return "GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB
	if ( en == GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB ) return "GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB
	if ( en == GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB ) return "GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB";
#endif
#ifdef GL_MAX_PROGRAM_ENV_PARAMETERS_ARB
	if ( en == GL_MAX_PROGRAM_ENV_PARAMETERS_ARB ) return "GL_MAX_PROGRAM_ENV_PARAMETERS_ARB";
#endif
#ifdef GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB
	if ( en == GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB ) return "GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB";
#endif
#ifdef GL_TRANSPOSE_CURRENT_MATRIX_ARB
	if ( en == GL_TRANSPOSE_CURRENT_MATRIX_ARB ) return "GL_TRANSPOSE_CURRENT_MATRIX_ARB";
#endif
#ifdef GL_MATRIX0_ARB
	if ( en == GL_MATRIX0_ARB ) return "GL_MATRIX0_ARB";
#endif
#ifdef GL_MATRIX1_ARB
	if ( en == GL_MATRIX1_ARB ) return "GL_MATRIX1_ARB";
#endif
#ifdef GL_MATRIX2_ARB
	if ( en == GL_MATRIX2_ARB ) return "GL_MATRIX2_ARB";
#endif
#ifdef GL_MATRIX3_ARB
	if ( en == GL_MATRIX3_ARB ) return "GL_MATRIX3_ARB";
#endif
#ifdef GL_MATRIX4_ARB
	if ( en == GL_MATRIX4_ARB ) return "GL_MATRIX4_ARB";
#endif
#ifdef GL_MATRIX5_ARB
	if ( en == GL_MATRIX5_ARB ) return "GL_MATRIX5_ARB";
#endif
#ifdef GL_MATRIX6_ARB
	if ( en == GL_MATRIX6_ARB ) return "GL_MATRIX6_ARB";
#endif
#ifdef GL_MATRIX7_ARB
	if ( en == GL_MATRIX7_ARB ) return "GL_MATRIX7_ARB";
#endif
#ifdef GL_MATRIX8_ARB
	if ( en == GL_MATRIX8_ARB ) return "GL_MATRIX8_ARB";
#endif
#ifdef GL_MATRIX9_ARB
	if ( en == GL_MATRIX9_ARB ) return "GL_MATRIX9_ARB";
#endif
#ifdef GL_MATRIX10_ARB
	if ( en == GL_MATRIX10_ARB ) return "GL_MATRIX10_ARB";
#endif
#ifdef GL_MATRIX11_ARB
	if ( en == GL_MATRIX11_ARB ) return "GL_MATRIX11_ARB";
#endif
#ifdef GL_MATRIX12_ARB
	if ( en == GL_MATRIX12_ARB ) return "GL_MATRIX12_ARB";
#endif
#ifdef GL_MATRIX13_ARB
	if ( en == GL_MATRIX13_ARB ) return "GL_MATRIX13_ARB";
#endif
#ifdef GL_MATRIX14_ARB
	if ( en == GL_MATRIX14_ARB ) return "GL_MATRIX14_ARB";
#endif
#ifdef GL_MATRIX15_ARB
	if ( en == GL_MATRIX15_ARB ) return "GL_MATRIX15_ARB";
#endif
#ifdef GL_MATRIX16_ARB
	if ( en == GL_MATRIX16_ARB ) return "GL_MATRIX16_ARB";
#endif
#ifdef GL_MATRIX17_ARB
	if ( en == GL_MATRIX17_ARB ) return "GL_MATRIX17_ARB";
#endif
#ifdef GL_MATRIX18_ARB
	if ( en == GL_MATRIX18_ARB ) return "GL_MATRIX18_ARB";
#endif
#ifdef GL_MATRIX19_ARB
	if ( en == GL_MATRIX19_ARB ) return "GL_MATRIX19_ARB";
#endif
#ifdef GL_MATRIX20_ARB
	if ( en == GL_MATRIX20_ARB ) return "GL_MATRIX20_ARB";
#endif
#ifdef GL_MATRIX21_ARB
	if ( en == GL_MATRIX21_ARB ) return "GL_MATRIX21_ARB";
#endif
#ifdef GL_MATRIX22_ARB
	if ( en == GL_MATRIX22_ARB ) return "GL_MATRIX22_ARB";
#endif
#ifdef GL_MATRIX23_ARB
	if ( en == GL_MATRIX23_ARB ) return "GL_MATRIX23_ARB";
#endif
#ifdef GL_MATRIX24_ARB
	if ( en == GL_MATRIX24_ARB ) return "GL_MATRIX24_ARB";
#endif
#ifdef GL_MATRIX25_ARB
	if ( en == GL_MATRIX25_ARB ) return "GL_MATRIX25_ARB";
#endif
#ifdef GL_MATRIX26_ARB
	if ( en == GL_MATRIX26_ARB ) return "GL_MATRIX26_ARB";
#endif
#ifdef GL_MATRIX27_ARB
	if ( en == GL_MATRIX27_ARB ) return "GL_MATRIX27_ARB";
#endif
#ifdef GL_MATRIX28_ARB
	if ( en == GL_MATRIX28_ARB ) return "GL_MATRIX28_ARB";
#endif
#ifdef GL_MATRIX29_ARB
	if ( en == GL_MATRIX29_ARB ) return "GL_MATRIX29_ARB";
#endif
#ifdef GL_MATRIX30_ARB
	if ( en == GL_MATRIX30_ARB ) return "GL_MATRIX30_ARB";
#endif
#ifdef GL_MATRIX31_ARB
	if ( en == GL_MATRIX31_ARB ) return "GL_MATRIX31_ARB";
#endif
#ifdef GL_VERTEX_SHADER_ARB
	if ( en == GL_VERTEX_SHADER_ARB ) return "GL_VERTEX_SHADER_ARB";
#endif
#ifdef GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB
	if ( en == GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB ) return "GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB";
#endif
#ifdef GL_MAX_VARYING_FLOATS_ARB
	if ( en == GL_MAX_VARYING_FLOATS_ARB ) return "GL_MAX_VARYING_FLOATS_ARB";
#endif
#ifdef GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB
	if ( en == GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB ) return "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB";
#endif
#ifdef GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB
	if ( en == GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB ) return "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB";
#endif
#ifdef GL_OBJECT_ACTIVE_ATTRIBUTES_ARB
	if ( en == GL_OBJECT_ACTIVE_ATTRIBUTES_ARB ) return "GL_OBJECT_ACTIVE_ATTRIBUTES_ARB";
#endif
#ifdef GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB
	if ( en == GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB ) return "GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB";
#endif
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV
	if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV ) return "GL_UNSIGNED_INT_10F_11F_11F_REV";
#endif
#ifdef GL_UNSIGNED_INT_2_10_10_10_REV
	if ( en == GL_UNSIGNED_INT_2_10_10_10_REV ) return "GL_UNSIGNED_INT_2_10_10_10_REV";
#endif
#ifdef GL_INT_2_10_10_10_REV
	if ( en == GL_INT_2_10_10_10_REV ) return "GL_INT_2_10_10_10_REV";
#endif
#ifdef GL_DEPTH_RANGE
	if ( en == GL_DEPTH_RANGE ) return "GL_DEPTH_RANGE";
#endif
#ifdef GL_VIEWPORT
	if ( en == GL_VIEWPORT ) return "GL_VIEWPORT";
#endif
#ifdef GL_SCISSOR_BOX
	if ( en == GL_SCISSOR_BOX ) return "GL_SCISSOR_BOX";
#endif
#ifdef GL_SCISSOR_TEST
	if ( en == GL_SCISSOR_TEST ) return "GL_SCISSOR_TEST";
#endif
#ifdef GL_MAX_VIEWPORTS
	if ( en == GL_MAX_VIEWPORTS ) return "GL_MAX_VIEWPORTS";
#endif
#ifdef GL_VIEWPORT_SUBPIXEL_BITS
	if ( en == GL_VIEWPORT_SUBPIXEL_BITS ) return "GL_VIEWPORT_SUBPIXEL_BITS";
#endif
#ifdef GL_VIEWPORT_BOUNDS_RANGE
	if ( en == GL_VIEWPORT_BOUNDS_RANGE ) return "GL_VIEWPORT_BOUNDS_RANGE";
#endif
#ifdef GL_LAYER_PROVOKING_VERTEX
	if ( en == GL_LAYER_PROVOKING_VERTEX ) return "GL_LAYER_PROVOKING_VERTEX";
#endif
#ifdef GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	if ( en == GL_VIEWPORT_INDEX_PROVOKING_VERTEX ) return "GL_VIEWPORT_INDEX_PROVOKING_VERTEX";
#endif
#ifdef GL_UNDEFINED_VERTEX
	if ( en == GL_UNDEFINED_VERTEX ) return "GL_UNDEFINED_VERTEX";
#endif
#ifdef GL_FIRST_VERTEX_CONVENTION
	if ( en == GL_FIRST_VERTEX_CONVENTION ) return "GL_FIRST_VERTEX_CONVENTION";
#endif
#ifdef GL_LAST_VERTEX_CONVENTION
	if ( en == GL_LAST_VERTEX_CONVENTION ) return "GL_LAST_VERTEX_CONVENTION";
#endif
#ifdef GL_PROVOKING_VERTEX
	if ( en == GL_PROVOKING_VERTEX ) return "GL_PROVOKING_VERTEX";
#endif
#ifdef GL_TEXTURE_POINT_MODE_ATIX
	if ( en == GL_TEXTURE_POINT_MODE_ATIX ) return "GL_TEXTURE_POINT_MODE_ATIX";
#endif
#ifdef GL_TEXTURE_POINT_ONE_COORD_ATIX
	if ( en == GL_TEXTURE_POINT_ONE_COORD_ATIX ) return "GL_TEXTURE_POINT_ONE_COORD_ATIX";
#endif
#ifdef GL_TEXTURE_POINT_SPRITE_ATIX
	if ( en == GL_TEXTURE_POINT_SPRITE_ATIX ) return "GL_TEXTURE_POINT_SPRITE_ATIX";
#endif
#ifdef GL_POINT_SPRITE_CULL_MODE_ATIX
	if ( en == GL_POINT_SPRITE_CULL_MODE_ATIX ) return "GL_POINT_SPRITE_CULL_MODE_ATIX";
#endif
#ifdef GL_POINT_SPRITE_CULL_CENTER_ATIX
	if ( en == GL_POINT_SPRITE_CULL_CENTER_ATIX ) return "GL_POINT_SPRITE_CULL_CENTER_ATIX";
#endif
#ifdef GL_POINT_SPRITE_CULL_CLIP_ATIX
	if ( en == GL_POINT_SPRITE_CULL_CLIP_ATIX ) return "GL_POINT_SPRITE_CULL_CLIP_ATIX";
#endif
#ifdef GL_MODULATE_ADD_ATIX
	if ( en == GL_MODULATE_ADD_ATIX ) return "GL_MODULATE_ADD_ATIX";
#endif
#ifdef GL_MODULATE_SIGNED_ADD_ATIX
	if ( en == GL_MODULATE_SIGNED_ADD_ATIX ) return "GL_MODULATE_SIGNED_ADD_ATIX";
#endif
#ifdef GL_MODULATE_SUBTRACT_ATIX
	if ( en == GL_MODULATE_SUBTRACT_ATIX ) return "GL_MODULATE_SUBTRACT_ATIX";
#endif
#ifdef GL_SECONDARY_COLOR_ATIX
	if ( en == GL_SECONDARY_COLOR_ATIX ) return "GL_SECONDARY_COLOR_ATIX";
#endif
#ifdef GL_TEXTURE_OUTPUT_RGB_ATIX
	if ( en == GL_TEXTURE_OUTPUT_RGB_ATIX ) return "GL_TEXTURE_OUTPUT_RGB_ATIX";
#endif
#ifdef GL_TEXTURE_OUTPUT_ALPHA_ATIX
	if ( en == GL_TEXTURE_OUTPUT_ALPHA_ATIX ) return "GL_TEXTURE_OUTPUT_ALPHA_ATIX";
#endif
#ifdef GL_OUTPUT_POINT_SIZE_ATIX
	if ( en == GL_OUTPUT_POINT_SIZE_ATIX ) return "GL_OUTPUT_POINT_SIZE_ATIX";
#endif
#ifdef GL_MAX_DRAW_BUFFERS_ATI
	if ( en == GL_MAX_DRAW_BUFFERS_ATI ) return "GL_MAX_DRAW_BUFFERS_ATI";
#endif
#ifdef GL_DRAW_BUFFER0_ATI
	if ( en == GL_DRAW_BUFFER0_ATI ) return "GL_DRAW_BUFFER0_ATI";
#endif
#ifdef GL_DRAW_BUFFER1_ATI
	if ( en == GL_DRAW_BUFFER1_ATI ) return "GL_DRAW_BUFFER1_ATI";
#endif
#ifdef GL_DRAW_BUFFER2_ATI
	if ( en == GL_DRAW_BUFFER2_ATI ) return "GL_DRAW_BUFFER2_ATI";
#endif
#ifdef GL_DRAW_BUFFER3_ATI
	if ( en == GL_DRAW_BUFFER3_ATI ) return "GL_DRAW_BUFFER3_ATI";
#endif
#ifdef GL_DRAW_BUFFER4_ATI
	if ( en == GL_DRAW_BUFFER4_ATI ) return "GL_DRAW_BUFFER4_ATI";
#endif
#ifdef GL_DRAW_BUFFER5_ATI
	if ( en == GL_DRAW_BUFFER5_ATI ) return "GL_DRAW_BUFFER5_ATI";
#endif
#ifdef GL_DRAW_BUFFER6_ATI
	if ( en == GL_DRAW_BUFFER6_ATI ) return "GL_DRAW_BUFFER6_ATI";
#endif
#ifdef GL_DRAW_BUFFER7_ATI
	if ( en == GL_DRAW_BUFFER7_ATI ) return "GL_DRAW_BUFFER7_ATI";
#endif
#ifdef GL_DRAW_BUFFER8_ATI
	if ( en == GL_DRAW_BUFFER8_ATI ) return "GL_DRAW_BUFFER8_ATI";
#endif
#ifdef GL_DRAW_BUFFER9_ATI
	if ( en == GL_DRAW_BUFFER9_ATI ) return "GL_DRAW_BUFFER9_ATI";
#endif
#ifdef GL_DRAW_BUFFER10_ATI
	if ( en == GL_DRAW_BUFFER10_ATI ) return "GL_DRAW_BUFFER10_ATI";
#endif
#ifdef GL_DRAW_BUFFER11_ATI
	if ( en == GL_DRAW_BUFFER11_ATI ) return "GL_DRAW_BUFFER11_ATI";
#endif
#ifdef GL_DRAW_BUFFER12_ATI
	if ( en == GL_DRAW_BUFFER12_ATI ) return "GL_DRAW_BUFFER12_ATI";
#endif
#ifdef GL_DRAW_BUFFER13_ATI
	if ( en == GL_DRAW_BUFFER13_ATI ) return "GL_DRAW_BUFFER13_ATI";
#endif
#ifdef GL_DRAW_BUFFER14_ATI
	if ( en == GL_DRAW_BUFFER14_ATI ) return "GL_DRAW_BUFFER14_ATI";
#endif
#ifdef GL_DRAW_BUFFER15_ATI
	if ( en == GL_DRAW_BUFFER15_ATI ) return "GL_DRAW_BUFFER15_ATI";
#endif
#ifdef GL_ELEMENT_ARRAY_ATI
	if ( en == GL_ELEMENT_ARRAY_ATI ) return "GL_ELEMENT_ARRAY_ATI";
#endif
#ifdef GL_ELEMENT_ARRAY_TYPE_ATI
	if ( en == GL_ELEMENT_ARRAY_TYPE_ATI ) return "GL_ELEMENT_ARRAY_TYPE_ATI";
#endif
#ifdef GL_ELEMENT_ARRAY_POINTER_ATI
	if ( en == GL_ELEMENT_ARRAY_POINTER_ATI ) return "GL_ELEMENT_ARRAY_POINTER_ATI";
#endif
#ifdef GL_BUMP_ROT_MATRIX_ATI
	if ( en == GL_BUMP_ROT_MATRIX_ATI ) return "GL_BUMP_ROT_MATRIX_ATI";
#endif
#ifdef GL_BUMP_ROT_MATRIX_SIZE_ATI
	if ( en == GL_BUMP_ROT_MATRIX_SIZE_ATI ) return "GL_BUMP_ROT_MATRIX_SIZE_ATI";
#endif
#ifdef GL_BUMP_NUM_TEX_UNITS_ATI
	if ( en == GL_BUMP_NUM_TEX_UNITS_ATI ) return "GL_BUMP_NUM_TEX_UNITS_ATI";
#endif
#ifdef GL_BUMP_TEX_UNITS_ATI
	if ( en == GL_BUMP_TEX_UNITS_ATI ) return "GL_BUMP_TEX_UNITS_ATI";
#endif
#ifdef GL_DUDV_ATI
	if ( en == GL_DUDV_ATI ) return "GL_DUDV_ATI";
#endif
#ifdef GL_DU8DV8_ATI
	if ( en == GL_DU8DV8_ATI ) return "GL_DU8DV8_ATI";
#endif
#ifdef GL_BUMP_ENVMAP_ATI
	if ( en == GL_BUMP_ENVMAP_ATI ) return "GL_BUMP_ENVMAP_ATI";
#endif
#ifdef GL_BUMP_TARGET_ATI
	if ( en == GL_BUMP_TARGET_ATI ) return "GL_BUMP_TARGET_ATI";
#endif
#ifdef GL_RED_BIT_ATI
	if ( en == GL_RED_BIT_ATI ) return "GL_RED_BIT_ATI";
#endif
#ifdef GL_2X_BIT_ATI
	if ( en == GL_2X_BIT_ATI ) return "GL_2X_BIT_ATI";
#endif
#ifdef GL_4X_BIT_ATI
	if ( en == GL_4X_BIT_ATI ) return "GL_4X_BIT_ATI";
#endif
#ifdef GL_GREEN_BIT_ATI
	if ( en == GL_GREEN_BIT_ATI ) return "GL_GREEN_BIT_ATI";
#endif
#ifdef GL_COMP_BIT_ATI
	if ( en == GL_COMP_BIT_ATI ) return "GL_COMP_BIT_ATI";
#endif
#ifdef GL_BLUE_BIT_ATI
	if ( en == GL_BLUE_BIT_ATI ) return "GL_BLUE_BIT_ATI";
#endif
#ifdef GL_8X_BIT_ATI
	if ( en == GL_8X_BIT_ATI ) return "GL_8X_BIT_ATI";
#endif
#ifdef GL_NEGATE_BIT_ATI
	if ( en == GL_NEGATE_BIT_ATI ) return "GL_NEGATE_BIT_ATI";
#endif
#ifdef GL_BIAS_BIT_ATI
	if ( en == GL_BIAS_BIT_ATI ) return "GL_BIAS_BIT_ATI";
#endif
#ifdef GL_HALF_BIT_ATI
	if ( en == GL_HALF_BIT_ATI ) return "GL_HALF_BIT_ATI";
#endif
#ifdef GL_QUARTER_BIT_ATI
	if ( en == GL_QUARTER_BIT_ATI ) return "GL_QUARTER_BIT_ATI";
#endif
#ifdef GL_EIGHTH_BIT_ATI
	if ( en == GL_EIGHTH_BIT_ATI ) return "GL_EIGHTH_BIT_ATI";
#endif
#ifdef GL_SATURATE_BIT_ATI
	if ( en == GL_SATURATE_BIT_ATI ) return "GL_SATURATE_BIT_ATI";
#endif
#ifdef GL_FRAGMENT_SHADER_ATI
	if ( en == GL_FRAGMENT_SHADER_ATI ) return "GL_FRAGMENT_SHADER_ATI";
#endif
#ifdef GL_REG_0_ATI
	if ( en == GL_REG_0_ATI ) return "GL_REG_0_ATI";
#endif
#ifdef GL_REG_1_ATI
	if ( en == GL_REG_1_ATI ) return "GL_REG_1_ATI";
#endif
#ifdef GL_REG_2_ATI
	if ( en == GL_REG_2_ATI ) return "GL_REG_2_ATI";
#endif
#ifdef GL_REG_3_ATI
	if ( en == GL_REG_3_ATI ) return "GL_REG_3_ATI";
#endif
#ifdef GL_REG_4_ATI
	if ( en == GL_REG_4_ATI ) return "GL_REG_4_ATI";
#endif
#ifdef GL_REG_5_ATI
	if ( en == GL_REG_5_ATI ) return "GL_REG_5_ATI";
#endif
#ifdef GL_CON_0_ATI
	if ( en == GL_CON_0_ATI ) return "GL_CON_0_ATI";
#endif
#ifdef GL_CON_1_ATI
	if ( en == GL_CON_1_ATI ) return "GL_CON_1_ATI";
#endif
#ifdef GL_CON_2_ATI
	if ( en == GL_CON_2_ATI ) return "GL_CON_2_ATI";
#endif
#ifdef GL_CON_3_ATI
	if ( en == GL_CON_3_ATI ) return "GL_CON_3_ATI";
#endif
#ifdef GL_CON_4_ATI
	if ( en == GL_CON_4_ATI ) return "GL_CON_4_ATI";
#endif
#ifdef GL_CON_5_ATI
	if ( en == GL_CON_5_ATI ) return "GL_CON_5_ATI";
#endif
#ifdef GL_CON_6_ATI
	if ( en == GL_CON_6_ATI ) return "GL_CON_6_ATI";
#endif
#ifdef GL_CON_7_ATI
	if ( en == GL_CON_7_ATI ) return "GL_CON_7_ATI";
#endif
#ifdef GL_MOV_ATI
	if ( en == GL_MOV_ATI ) return "GL_MOV_ATI";
#endif
#ifdef GL_ADD_ATI
	if ( en == GL_ADD_ATI ) return "GL_ADD_ATI";
#endif
#ifdef GL_MUL_ATI
	if ( en == GL_MUL_ATI ) return "GL_MUL_ATI";
#endif
#ifdef GL_SUB_ATI
	if ( en == GL_SUB_ATI ) return "GL_SUB_ATI";
#endif
#ifdef GL_DOT3_ATI
	if ( en == GL_DOT3_ATI ) return "GL_DOT3_ATI";
#endif
#ifdef GL_DOT4_ATI
	if ( en == GL_DOT4_ATI ) return "GL_DOT4_ATI";
#endif
#ifdef GL_MAD_ATI
	if ( en == GL_MAD_ATI ) return "GL_MAD_ATI";
#endif
#ifdef GL_LERP_ATI
	if ( en == GL_LERP_ATI ) return "GL_LERP_ATI";
#endif
#ifdef GL_CND_ATI
	if ( en == GL_CND_ATI ) return "GL_CND_ATI";
#endif
#ifdef GL_CND0_ATI
	if ( en == GL_CND0_ATI ) return "GL_CND0_ATI";
#endif
#ifdef GL_DOT2_ADD_ATI
	if ( en == GL_DOT2_ADD_ATI ) return "GL_DOT2_ADD_ATI";
#endif
#ifdef GL_SECONDARY_INTERPOLATOR_ATI
	if ( en == GL_SECONDARY_INTERPOLATOR_ATI ) return "GL_SECONDARY_INTERPOLATOR_ATI";
#endif
#ifdef GL_NUM_FRAGMENT_REGISTERS_ATI
	if ( en == GL_NUM_FRAGMENT_REGISTERS_ATI ) return "GL_NUM_FRAGMENT_REGISTERS_ATI";
#endif
#ifdef GL_NUM_FRAGMENT_CONSTANTS_ATI
	if ( en == GL_NUM_FRAGMENT_CONSTANTS_ATI ) return "GL_NUM_FRAGMENT_CONSTANTS_ATI";
#endif
#ifdef GL_NUM_PASSES_ATI
	if ( en == GL_NUM_PASSES_ATI ) return "GL_NUM_PASSES_ATI";
#endif
#ifdef GL_NUM_INSTRUCTIONS_PER_PASS_ATI
	if ( en == GL_NUM_INSTRUCTIONS_PER_PASS_ATI ) return "GL_NUM_INSTRUCTIONS_PER_PASS_ATI";
#endif
#ifdef GL_NUM_INSTRUCTIONS_TOTAL_ATI
	if ( en == GL_NUM_INSTRUCTIONS_TOTAL_ATI ) return "GL_NUM_INSTRUCTIONS_TOTAL_ATI";
#endif
#ifdef GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI
	if ( en == GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI ) return "GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI";
#endif
#ifdef GL_NUM_LOOPBACK_COMPONENTS_ATI
	if ( en == GL_NUM_LOOPBACK_COMPONENTS_ATI ) return "GL_NUM_LOOPBACK_COMPONENTS_ATI";
#endif
#ifdef GL_COLOR_ALPHA_PAIRING_ATI
	if ( en == GL_COLOR_ALPHA_PAIRING_ATI ) return "GL_COLOR_ALPHA_PAIRING_ATI";
#endif
#ifdef GL_SWIZZLE_STR_ATI
	if ( en == GL_SWIZZLE_STR_ATI ) return "GL_SWIZZLE_STR_ATI";
#endif
#ifdef GL_SWIZZLE_STQ_ATI
	if ( en == GL_SWIZZLE_STQ_ATI ) return "GL_SWIZZLE_STQ_ATI";
#endif
#ifdef GL_SWIZZLE_STR_DR_ATI
	if ( en == GL_SWIZZLE_STR_DR_ATI ) return "GL_SWIZZLE_STR_DR_ATI";
#endif
#ifdef GL_SWIZZLE_STQ_DQ_ATI
	if ( en == GL_SWIZZLE_STQ_DQ_ATI ) return "GL_SWIZZLE_STQ_DQ_ATI";
#endif
#ifdef GL_SWIZZLE_STRQ_ATI
	if ( en == GL_SWIZZLE_STRQ_ATI ) return "GL_SWIZZLE_STRQ_ATI";
#endif
#ifdef GL_SWIZZLE_STRQ_DQ_ATI
	if ( en == GL_SWIZZLE_STRQ_DQ_ATI ) return "GL_SWIZZLE_STRQ_DQ_ATI";
#endif
#ifdef GL_VBO_FREE_MEMORY_ATI
	if ( en == GL_VBO_FREE_MEMORY_ATI ) return "GL_VBO_FREE_MEMORY_ATI";
#endif
#ifdef GL_TEXTURE_FREE_MEMORY_ATI
	if ( en == GL_TEXTURE_FREE_MEMORY_ATI ) return "GL_TEXTURE_FREE_MEMORY_ATI";
#endif
#ifdef GL_RENDERBUFFER_FREE_MEMORY_ATI
	if ( en == GL_RENDERBUFFER_FREE_MEMORY_ATI ) return "GL_RENDERBUFFER_FREE_MEMORY_ATI";
#endif
#ifdef GL_PN_TRIANGLES_ATI
	if ( en == GL_PN_TRIANGLES_ATI ) return "GL_PN_TRIANGLES_ATI";
#endif
#ifdef GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI
	if ( en == GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI ) return "GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI";
#endif
#ifdef GL_PN_TRIANGLES_POINT_MODE_ATI
	if ( en == GL_PN_TRIANGLES_POINT_MODE_ATI ) return "GL_PN_TRIANGLES_POINT_MODE_ATI";
#endif
#ifdef GL_PN_TRIANGLES_NORMAL_MODE_ATI
	if ( en == GL_PN_TRIANGLES_NORMAL_MODE_ATI ) return "GL_PN_TRIANGLES_NORMAL_MODE_ATI";
#endif
#ifdef GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI
	if ( en == GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI ) return "GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI";
#endif
#ifdef GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI
	if ( en == GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI ) return "GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI";
#endif
#ifdef GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI
	if ( en == GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI ) return "GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI";
#endif
#ifdef GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI
	if ( en == GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI ) return "GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI";
#endif
#ifdef GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI
	if ( en == GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI ) return "GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI";
#endif
#ifdef GL_STENCIL_BACK_FUNC_ATI
	if ( en == GL_STENCIL_BACK_FUNC_ATI ) return "GL_STENCIL_BACK_FUNC_ATI";
#endif
#ifdef GL_STENCIL_BACK_FAIL_ATI
	if ( en == GL_STENCIL_BACK_FAIL_ATI ) return "GL_STENCIL_BACK_FAIL_ATI";
#endif
#ifdef GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI
	if ( en == GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI ) return "GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI";
#endif
#ifdef GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI
	if ( en == GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI ) return "GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI";
#endif
#ifdef GL_TEXT_FRAGMENT_SHADER_ATI
	if ( en == GL_TEXT_FRAGMENT_SHADER_ATI ) return "GL_TEXT_FRAGMENT_SHADER_ATI";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI
	if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI ) return "GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI";
#endif
#ifdef GL_MODULATE_ADD_ATI
	if ( en == GL_MODULATE_ADD_ATI ) return "GL_MODULATE_ADD_ATI";
#endif
#ifdef GL_MODULATE_SIGNED_ADD_ATI
	if ( en == GL_MODULATE_SIGNED_ADD_ATI ) return "GL_MODULATE_SIGNED_ADD_ATI";
#endif
#ifdef GL_MODULATE_SUBTRACT_ATI
	if ( en == GL_MODULATE_SUBTRACT_ATI ) return "GL_MODULATE_SUBTRACT_ATI";
#endif
#ifdef GL_RGBA_FLOAT32_ATI
	if ( en == GL_RGBA_FLOAT32_ATI ) return "GL_RGBA_FLOAT32_ATI";
#endif
#ifdef GL_RGB_FLOAT32_ATI
	if ( en == GL_RGB_FLOAT32_ATI ) return "GL_RGB_FLOAT32_ATI";
#endif
#ifdef GL_ALPHA_FLOAT32_ATI
	if ( en == GL_ALPHA_FLOAT32_ATI ) return "GL_ALPHA_FLOAT32_ATI";
#endif
#ifdef GL_INTENSITY_FLOAT32_ATI
	if ( en == GL_INTENSITY_FLOAT32_ATI ) return "GL_INTENSITY_FLOAT32_ATI";
#endif
#ifdef GL_LUMINANCE_FLOAT32_ATI
	if ( en == GL_LUMINANCE_FLOAT32_ATI ) return "GL_LUMINANCE_FLOAT32_ATI";
#endif
#ifdef GL_LUMINANCE_ALPHA_FLOAT32_ATI
	if ( en == GL_LUMINANCE_ALPHA_FLOAT32_ATI ) return "GL_LUMINANCE_ALPHA_FLOAT32_ATI";
#endif
#ifdef GL_RGBA_FLOAT16_ATI
	if ( en == GL_RGBA_FLOAT16_ATI ) return "GL_RGBA_FLOAT16_ATI";
#endif
#ifdef GL_RGB_FLOAT16_ATI
	if ( en == GL_RGB_FLOAT16_ATI ) return "GL_RGB_FLOAT16_ATI";
#endif
#ifdef GL_ALPHA_FLOAT16_ATI
	if ( en == GL_ALPHA_FLOAT16_ATI ) return "GL_ALPHA_FLOAT16_ATI";
#endif
#ifdef GL_INTENSITY_FLOAT16_ATI
	if ( en == GL_INTENSITY_FLOAT16_ATI ) return "GL_INTENSITY_FLOAT16_ATI";
#endif
#ifdef GL_LUMINANCE_FLOAT16_ATI
	if ( en == GL_LUMINANCE_FLOAT16_ATI ) return "GL_LUMINANCE_FLOAT16_ATI";
#endif
#ifdef GL_LUMINANCE_ALPHA_FLOAT16_ATI
	if ( en == GL_LUMINANCE_ALPHA_FLOAT16_ATI ) return "GL_LUMINANCE_ALPHA_FLOAT16_ATI";
#endif
#ifdef GL_MIRROR_CLAMP_ATI
	if ( en == GL_MIRROR_CLAMP_ATI ) return "GL_MIRROR_CLAMP_ATI";
#endif
#ifdef GL_MIRROR_CLAMP_TO_EDGE_ATI
	if ( en == GL_MIRROR_CLAMP_TO_EDGE_ATI ) return "GL_MIRROR_CLAMP_TO_EDGE_ATI";
#endif
#ifdef GL_STATIC_ATI
	if ( en == GL_STATIC_ATI ) return "GL_STATIC_ATI";
#endif
#ifdef GL_DYNAMIC_ATI
	if ( en == GL_DYNAMIC_ATI ) return "GL_DYNAMIC_ATI";
#endif
#ifdef GL_PRESERVE_ATI
	if ( en == GL_PRESERVE_ATI ) return "GL_PRESERVE_ATI";
#endif
#ifdef GL_DISCARD_ATI
	if ( en == GL_DISCARD_ATI ) return "GL_DISCARD_ATI";
#endif
#ifdef GL_OBJECT_BUFFER_SIZE_ATI
	if ( en == GL_OBJECT_BUFFER_SIZE_ATI ) return "GL_OBJECT_BUFFER_SIZE_ATI";
#endif
#ifdef GL_OBJECT_BUFFER_USAGE_ATI
	if ( en == GL_OBJECT_BUFFER_USAGE_ATI ) return "GL_OBJECT_BUFFER_USAGE_ATI";
#endif
#ifdef GL_ARRAY_OBJECT_BUFFER_ATI
	if ( en == GL_ARRAY_OBJECT_BUFFER_ATI ) return "GL_ARRAY_OBJECT_BUFFER_ATI";
#endif
#ifdef GL_ARRAY_OBJECT_OFFSET_ATI
	if ( en == GL_ARRAY_OBJECT_OFFSET_ATI ) return "GL_ARRAY_OBJECT_OFFSET_ATI";
#endif
#ifdef GL_MAX_VERTEX_STREAMS_ATI
	if ( en == GL_MAX_VERTEX_STREAMS_ATI ) return "GL_MAX_VERTEX_STREAMS_ATI";
#endif
#ifdef GL_VERTEX_SOURCE_ATI
	if ( en == GL_VERTEX_SOURCE_ATI ) return "GL_VERTEX_SOURCE_ATI";
#endif
#ifdef GL_VERTEX_STREAM0_ATI
	if ( en == GL_VERTEX_STREAM0_ATI ) return "GL_VERTEX_STREAM0_ATI";
#endif
#ifdef GL_VERTEX_STREAM1_ATI
	if ( en == GL_VERTEX_STREAM1_ATI ) return "GL_VERTEX_STREAM1_ATI";
#endif
#ifdef GL_VERTEX_STREAM2_ATI
	if ( en == GL_VERTEX_STREAM2_ATI ) return "GL_VERTEX_STREAM2_ATI";
#endif
#ifdef GL_VERTEX_STREAM3_ATI
	if ( en == GL_VERTEX_STREAM3_ATI ) return "GL_VERTEX_STREAM3_ATI";
#endif
#ifdef GL_VERTEX_STREAM4_ATI
	if ( en == GL_VERTEX_STREAM4_ATI ) return "GL_VERTEX_STREAM4_ATI";
#endif
#ifdef GL_VERTEX_STREAM5_ATI
	if ( en == GL_VERTEX_STREAM5_ATI ) return "GL_VERTEX_STREAM5_ATI";
#endif
#ifdef GL_VERTEX_STREAM6_ATI
	if ( en == GL_VERTEX_STREAM6_ATI ) return "GL_VERTEX_STREAM6_ATI";
#endif
#ifdef GL_VERTEX_STREAM7_ATI
	if ( en == GL_VERTEX_STREAM7_ATI ) return "GL_VERTEX_STREAM7_ATI";
#endif
#ifdef GL_422_EXT
	if ( en == GL_422_EXT ) return "GL_422_EXT";
#endif
#ifdef GL_422_REV_EXT
	if ( en == GL_422_REV_EXT ) return "GL_422_REV_EXT";
#endif
#ifdef GL_422_AVERAGE_EXT
	if ( en == GL_422_AVERAGE_EXT ) return "GL_422_AVERAGE_EXT";
#endif
#ifdef GL_422_REV_AVERAGE_EXT
	if ( en == GL_422_REV_AVERAGE_EXT ) return "GL_422_REV_AVERAGE_EXT";
#endif
#ifdef GL_CG_VERTEX_SHADER_EXT
	if ( en == GL_CG_VERTEX_SHADER_EXT ) return "GL_CG_VERTEX_SHADER_EXT";
#endif
#ifdef GL_CG_FRAGMENT_SHADER_EXT
	if ( en == GL_CG_FRAGMENT_SHADER_EXT ) return "GL_CG_FRAGMENT_SHADER_EXT";
#endif
#ifdef GL_ABGR_EXT
	if ( en == GL_ABGR_EXT ) return "GL_ABGR_EXT";
#endif
#ifdef GL_BGR_EXT
	if ( en == GL_BGR_EXT ) return "GL_BGR_EXT";
#endif
#ifdef GL_BGRA_EXT
	if ( en == GL_BGRA_EXT ) return "GL_BGRA_EXT";
#endif
#ifdef GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT
	if ( en == GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT ) return "GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT";
#endif
#ifdef GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT
	if ( en == GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT ) return "GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT
	if ( en == GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT ) return "GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT";
#endif
#ifdef GL_MAX_BINDABLE_UNIFORM_SIZE_EXT
	if ( en == GL_MAX_BINDABLE_UNIFORM_SIZE_EXT ) return "GL_MAX_BINDABLE_UNIFORM_SIZE_EXT";
#endif
#ifdef GL_UNIFORM_BUFFER_EXT
	if ( en == GL_UNIFORM_BUFFER_EXT ) return "GL_UNIFORM_BUFFER_EXT";
#endif
#ifdef GL_UNIFORM_BUFFER_BINDING_EXT
	if ( en == GL_UNIFORM_BUFFER_BINDING_EXT ) return "GL_UNIFORM_BUFFER_BINDING_EXT";
#endif
#ifdef GL_CONSTANT_COLOR_EXT
	if ( en == GL_CONSTANT_COLOR_EXT ) return "GL_CONSTANT_COLOR_EXT";
#endif
#ifdef GL_ONE_MINUS_CONSTANT_COLOR_EXT
	if ( en == GL_ONE_MINUS_CONSTANT_COLOR_EXT ) return "GL_ONE_MINUS_CONSTANT_COLOR_EXT";
#endif
#ifdef GL_CONSTANT_ALPHA_EXT
	if ( en == GL_CONSTANT_ALPHA_EXT ) return "GL_CONSTANT_ALPHA_EXT";
#endif
#ifdef GL_ONE_MINUS_CONSTANT_ALPHA_EXT
	if ( en == GL_ONE_MINUS_CONSTANT_ALPHA_EXT ) return "GL_ONE_MINUS_CONSTANT_ALPHA_EXT";
#endif
#ifdef GL_BLEND_COLOR_EXT
	if ( en == GL_BLEND_COLOR_EXT ) return "GL_BLEND_COLOR_EXT";
#endif
#ifdef GL_BLEND_EQUATION_RGB_EXT
	if ( en == GL_BLEND_EQUATION_RGB_EXT ) return "GL_BLEND_EQUATION_RGB_EXT";
#endif
#ifdef GL_BLEND_EQUATION_ALPHA_EXT
	if ( en == GL_BLEND_EQUATION_ALPHA_EXT ) return "GL_BLEND_EQUATION_ALPHA_EXT";
#endif
#ifdef GL_BLEND_DST_RGB_EXT
	if ( en == GL_BLEND_DST_RGB_EXT ) return "GL_BLEND_DST_RGB_EXT";
#endif
#ifdef GL_BLEND_SRC_RGB_EXT
	if ( en == GL_BLEND_SRC_RGB_EXT ) return "GL_BLEND_SRC_RGB_EXT";
#endif
#ifdef GL_BLEND_DST_ALPHA_EXT
	if ( en == GL_BLEND_DST_ALPHA_EXT ) return "GL_BLEND_DST_ALPHA_EXT";
#endif
#ifdef GL_BLEND_SRC_ALPHA_EXT
	if ( en == GL_BLEND_SRC_ALPHA_EXT ) return "GL_BLEND_SRC_ALPHA_EXT";
#endif
#ifdef GL_FUNC_ADD_EXT
	if ( en == GL_FUNC_ADD_EXT ) return "GL_FUNC_ADD_EXT";
#endif
#ifdef GL_MIN_EXT
	if ( en == GL_MIN_EXT ) return "GL_MIN_EXT";
#endif
#ifdef GL_MAX_EXT
	if ( en == GL_MAX_EXT ) return "GL_MAX_EXT";
#endif
#ifdef GL_BLEND_EQUATION_EXT
	if ( en == GL_BLEND_EQUATION_EXT ) return "GL_BLEND_EQUATION_EXT";
#endif
#ifdef GL_FUNC_SUBTRACT_EXT
	if ( en == GL_FUNC_SUBTRACT_EXT ) return "GL_FUNC_SUBTRACT_EXT";
#endif
#ifdef GL_FUNC_REVERSE_SUBTRACT_EXT
	if ( en == GL_FUNC_REVERSE_SUBTRACT_EXT ) return "GL_FUNC_REVERSE_SUBTRACT_EXT";
#endif
#ifdef GL_CLIP_VOLUME_CLIPPING_HINT_EXT
	if ( en == GL_CLIP_VOLUME_CLIPPING_HINT_EXT ) return "GL_CLIP_VOLUME_CLIPPING_HINT_EXT";
#endif
#ifdef GL_CMYK_EXT
	if ( en == GL_CMYK_EXT ) return "GL_CMYK_EXT";
#endif
#ifdef GL_CMYKA_EXT
	if ( en == GL_CMYKA_EXT ) return "GL_CMYKA_EXT";
#endif
#ifdef GL_PACK_CMYK_HINT_EXT
	if ( en == GL_PACK_CMYK_HINT_EXT ) return "GL_PACK_CMYK_HINT_EXT";
#endif
#ifdef GL_UNPACK_CMYK_HINT_EXT
	if ( en == GL_UNPACK_CMYK_HINT_EXT ) return "GL_UNPACK_CMYK_HINT_EXT";
#endif
#ifdef GL_ARRAY_ELEMENT_LOCK_FIRST_EXT
	if ( en == GL_ARRAY_ELEMENT_LOCK_FIRST_EXT ) return "GL_ARRAY_ELEMENT_LOCK_FIRST_EXT";
#endif
#ifdef GL_ARRAY_ELEMENT_LOCK_COUNT_EXT
	if ( en == GL_ARRAY_ELEMENT_LOCK_COUNT_EXT ) return "GL_ARRAY_ELEMENT_LOCK_COUNT_EXT";
#endif
#ifdef GL_CONVOLUTION_1D_EXT
	if ( en == GL_CONVOLUTION_1D_EXT ) return "GL_CONVOLUTION_1D_EXT";
#endif
#ifdef GL_CONVOLUTION_2D_EXT
	if ( en == GL_CONVOLUTION_2D_EXT ) return "GL_CONVOLUTION_2D_EXT";
#endif
#ifdef GL_SEPARABLE_2D_EXT
	if ( en == GL_SEPARABLE_2D_EXT ) return "GL_SEPARABLE_2D_EXT";
#endif
#ifdef GL_CONVOLUTION_BORDER_MODE_EXT
	if ( en == GL_CONVOLUTION_BORDER_MODE_EXT ) return "GL_CONVOLUTION_BORDER_MODE_EXT";
#endif
#ifdef GL_CONVOLUTION_FILTER_SCALE_EXT
	if ( en == GL_CONVOLUTION_FILTER_SCALE_EXT ) return "GL_CONVOLUTION_FILTER_SCALE_EXT";
#endif
#ifdef GL_CONVOLUTION_FILTER_BIAS_EXT
	if ( en == GL_CONVOLUTION_FILTER_BIAS_EXT ) return "GL_CONVOLUTION_FILTER_BIAS_EXT";
#endif
#ifdef GL_REDUCE_EXT
	if ( en == GL_REDUCE_EXT ) return "GL_REDUCE_EXT";
#endif
#ifdef GL_CONVOLUTION_FORMAT_EXT
	if ( en == GL_CONVOLUTION_FORMAT_EXT ) return "GL_CONVOLUTION_FORMAT_EXT";
#endif
#ifdef GL_CONVOLUTION_WIDTH_EXT
	if ( en == GL_CONVOLUTION_WIDTH_EXT ) return "GL_CONVOLUTION_WIDTH_EXT";
#endif
#ifdef GL_CONVOLUTION_HEIGHT_EXT
	if ( en == GL_CONVOLUTION_HEIGHT_EXT ) return "GL_CONVOLUTION_HEIGHT_EXT";
#endif
#ifdef GL_MAX_CONVOLUTION_WIDTH_EXT
	if ( en == GL_MAX_CONVOLUTION_WIDTH_EXT ) return "GL_MAX_CONVOLUTION_WIDTH_EXT";
#endif
#ifdef GL_MAX_CONVOLUTION_HEIGHT_EXT
	if ( en == GL_MAX_CONVOLUTION_HEIGHT_EXT ) return "GL_MAX_CONVOLUTION_HEIGHT_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_RED_SCALE_EXT
	if ( en == GL_POST_CONVOLUTION_RED_SCALE_EXT ) return "GL_POST_CONVOLUTION_RED_SCALE_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_SCALE_EXT
	if ( en == GL_POST_CONVOLUTION_GREEN_SCALE_EXT ) return "GL_POST_CONVOLUTION_GREEN_SCALE_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_SCALE_EXT
	if ( en == GL_POST_CONVOLUTION_BLUE_SCALE_EXT ) return "GL_POST_CONVOLUTION_BLUE_SCALE_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_SCALE_EXT
	if ( en == GL_POST_CONVOLUTION_ALPHA_SCALE_EXT ) return "GL_POST_CONVOLUTION_ALPHA_SCALE_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_RED_BIAS_EXT
	if ( en == GL_POST_CONVOLUTION_RED_BIAS_EXT ) return "GL_POST_CONVOLUTION_RED_BIAS_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_GREEN_BIAS_EXT
	if ( en == GL_POST_CONVOLUTION_GREEN_BIAS_EXT ) return "GL_POST_CONVOLUTION_GREEN_BIAS_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_BLUE_BIAS_EXT
	if ( en == GL_POST_CONVOLUTION_BLUE_BIAS_EXT ) return "GL_POST_CONVOLUTION_BLUE_BIAS_EXT";
#endif
#ifdef GL_POST_CONVOLUTION_ALPHA_BIAS_EXT
	if ( en == GL_POST_CONVOLUTION_ALPHA_BIAS_EXT ) return "GL_POST_CONVOLUTION_ALPHA_BIAS_EXT";
#endif
#ifdef GL_TANGENT_ARRAY_EXT
	if ( en == GL_TANGENT_ARRAY_EXT ) return "GL_TANGENT_ARRAY_EXT";
#endif
#ifdef GL_BINORMAL_ARRAY_EXT
	if ( en == GL_BINORMAL_ARRAY_EXT ) return "GL_BINORMAL_ARRAY_EXT";
#endif
#ifdef GL_CURRENT_TANGENT_EXT
	if ( en == GL_CURRENT_TANGENT_EXT ) return "GL_CURRENT_TANGENT_EXT";
#endif
#ifdef GL_CURRENT_BINORMAL_EXT
	if ( en == GL_CURRENT_BINORMAL_EXT ) return "GL_CURRENT_BINORMAL_EXT";
#endif
#ifdef GL_TANGENT_ARRAY_TYPE_EXT
	if ( en == GL_TANGENT_ARRAY_TYPE_EXT ) return "GL_TANGENT_ARRAY_TYPE_EXT";
#endif
#ifdef GL_TANGENT_ARRAY_STRIDE_EXT
	if ( en == GL_TANGENT_ARRAY_STRIDE_EXT ) return "GL_TANGENT_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_BINORMAL_ARRAY_TYPE_EXT
	if ( en == GL_BINORMAL_ARRAY_TYPE_EXT ) return "GL_BINORMAL_ARRAY_TYPE_EXT";
#endif
#ifdef GL_BINORMAL_ARRAY_STRIDE_EXT
	if ( en == GL_BINORMAL_ARRAY_STRIDE_EXT ) return "GL_BINORMAL_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_TANGENT_ARRAY_POINTER_EXT
	if ( en == GL_TANGENT_ARRAY_POINTER_EXT ) return "GL_TANGENT_ARRAY_POINTER_EXT";
#endif
#ifdef GL_BINORMAL_ARRAY_POINTER_EXT
	if ( en == GL_BINORMAL_ARRAY_POINTER_EXT ) return "GL_BINORMAL_ARRAY_POINTER_EXT";
#endif
#ifdef GL_MAP1_TANGENT_EXT
	if ( en == GL_MAP1_TANGENT_EXT ) return "GL_MAP1_TANGENT_EXT";
#endif
#ifdef GL_MAP2_TANGENT_EXT
	if ( en == GL_MAP2_TANGENT_EXT ) return "GL_MAP2_TANGENT_EXT";
#endif
#ifdef GL_MAP1_BINORMAL_EXT
	if ( en == GL_MAP1_BINORMAL_EXT ) return "GL_MAP1_BINORMAL_EXT";
#endif
#ifdef GL_MAP2_BINORMAL_EXT
	if ( en == GL_MAP2_BINORMAL_EXT ) return "GL_MAP2_BINORMAL_EXT";
#endif
#ifdef GL_CULL_VERTEX_EXT
	if ( en == GL_CULL_VERTEX_EXT ) return "GL_CULL_VERTEX_EXT";
#endif
#ifdef GL_CULL_VERTEX_EYE_POSITION_EXT
	if ( en == GL_CULL_VERTEX_EYE_POSITION_EXT ) return "GL_CULL_VERTEX_EYE_POSITION_EXT";
#endif
#ifdef GL_CULL_VERTEX_OBJECT_POSITION_EXT
	if ( en == GL_CULL_VERTEX_OBJECT_POSITION_EXT ) return "GL_CULL_VERTEX_OBJECT_POSITION_EXT";
#endif
#ifdef GL_DEPTH_BOUNDS_TEST_EXT
	if ( en == GL_DEPTH_BOUNDS_TEST_EXT ) return "GL_DEPTH_BOUNDS_TEST_EXT";
#endif
#ifdef GL_DEPTH_BOUNDS_EXT
	if ( en == GL_DEPTH_BOUNDS_EXT ) return "GL_DEPTH_BOUNDS_EXT";
#endif
#ifdef GL_PROGRAM_MATRIX_EXT
	if ( en == GL_PROGRAM_MATRIX_EXT ) return "GL_PROGRAM_MATRIX_EXT";
#endif
#ifdef GL_TRANSPOSE_PROGRAM_MATRIX_EXT
	if ( en == GL_TRANSPOSE_PROGRAM_MATRIX_EXT ) return "GL_TRANSPOSE_PROGRAM_MATRIX_EXT";
#endif
#ifdef GL_PROGRAM_MATRIX_STACK_DEPTH_EXT
	if ( en == GL_PROGRAM_MATRIX_STACK_DEPTH_EXT ) return "GL_PROGRAM_MATRIX_STACK_DEPTH_EXT";
#endif
#ifdef GL_MAX_ELEMENTS_VERTICES_EXT
	if ( en == GL_MAX_ELEMENTS_VERTICES_EXT ) return "GL_MAX_ELEMENTS_VERTICES_EXT";
#endif
#ifdef GL_MAX_ELEMENTS_INDICES_EXT
	if ( en == GL_MAX_ELEMENTS_INDICES_EXT ) return "GL_MAX_ELEMENTS_INDICES_EXT";
#endif
#ifdef GL_FOG_COORDINATE_SOURCE_EXT
	if ( en == GL_FOG_COORDINATE_SOURCE_EXT ) return "GL_FOG_COORDINATE_SOURCE_EXT";
#endif
#ifdef GL_FOG_COORDINATE_EXT
	if ( en == GL_FOG_COORDINATE_EXT ) return "GL_FOG_COORDINATE_EXT";
#endif
#ifdef GL_FRAGMENT_DEPTH_EXT
	if ( en == GL_FRAGMENT_DEPTH_EXT ) return "GL_FRAGMENT_DEPTH_EXT";
#endif
#ifdef GL_CURRENT_FOG_COORDINATE_EXT
	if ( en == GL_CURRENT_FOG_COORDINATE_EXT ) return "GL_CURRENT_FOG_COORDINATE_EXT";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_TYPE_EXT
	if ( en == GL_FOG_COORDINATE_ARRAY_TYPE_EXT ) return "GL_FOG_COORDINATE_ARRAY_TYPE_EXT";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_STRIDE_EXT
	if ( en == GL_FOG_COORDINATE_ARRAY_STRIDE_EXT ) return "GL_FOG_COORDINATE_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_POINTER_EXT
	if ( en == GL_FOG_COORDINATE_ARRAY_POINTER_EXT ) return "GL_FOG_COORDINATE_ARRAY_POINTER_EXT";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_EXT
	if ( en == GL_FOG_COORDINATE_ARRAY_EXT ) return "GL_FOG_COORDINATE_ARRAY_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHTING_EXT
	if ( en == GL_FRAGMENT_LIGHTING_EXT ) return "GL_FRAGMENT_LIGHTING_EXT";
#endif
#ifdef GL_FRAGMENT_COLOR_MATERIAL_EXT
	if ( en == GL_FRAGMENT_COLOR_MATERIAL_EXT ) return "GL_FRAGMENT_COLOR_MATERIAL_EXT";
#endif
#ifdef GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT
	if ( en == GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT ) return "GL_FRAGMENT_COLOR_MATERIAL_FACE_EXT";
#endif
#ifdef GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT
	if ( en == GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT ) return "GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_EXT";
#endif
#ifdef GL_MAX_FRAGMENT_LIGHTS_EXT
	if ( en == GL_MAX_FRAGMENT_LIGHTS_EXT ) return "GL_MAX_FRAGMENT_LIGHTS_EXT";
#endif
#ifdef GL_MAX_ACTIVE_LIGHTS_EXT
	if ( en == GL_MAX_ACTIVE_LIGHTS_EXT ) return "GL_MAX_ACTIVE_LIGHTS_EXT";
#endif
#ifdef GL_CURRENT_RASTER_NORMAL_EXT
	if ( en == GL_CURRENT_RASTER_NORMAL_EXT ) return "GL_CURRENT_RASTER_NORMAL_EXT";
#endif
#ifdef GL_LIGHT_ENV_MODE_EXT
	if ( en == GL_LIGHT_ENV_MODE_EXT ) return "GL_LIGHT_ENV_MODE_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT
	if ( en == GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT ) return "GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT
	if ( en == GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT ) return "GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT
	if ( en == GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT ) return "GL_FRAGMENT_LIGHT_MODEL_AMBIENT_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT
	if ( en == GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT ) return "GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT0_EXT
	if ( en == GL_FRAGMENT_LIGHT0_EXT ) return "GL_FRAGMENT_LIGHT0_EXT";
#endif
#ifdef GL_FRAGMENT_LIGHT7_EXT
	if ( en == GL_FRAGMENT_LIGHT7_EXT ) return "GL_FRAGMENT_LIGHT7_EXT";
#endif
#ifdef GL_DRAW_FRAMEBUFFER_BINDING_EXT
	if ( en == GL_DRAW_FRAMEBUFFER_BINDING_EXT ) return "GL_DRAW_FRAMEBUFFER_BINDING_EXT";
#endif
#ifdef GL_READ_FRAMEBUFFER_EXT
	if ( en == GL_READ_FRAMEBUFFER_EXT ) return "GL_READ_FRAMEBUFFER_EXT";
#endif
#ifdef GL_DRAW_FRAMEBUFFER_EXT
	if ( en == GL_DRAW_FRAMEBUFFER_EXT ) return "GL_DRAW_FRAMEBUFFER_EXT";
#endif
#ifdef GL_READ_FRAMEBUFFER_BINDING_EXT
	if ( en == GL_READ_FRAMEBUFFER_BINDING_EXT ) return "GL_READ_FRAMEBUFFER_BINDING_EXT";
#endif
#ifdef GL_RENDERBUFFER_SAMPLES_EXT
	if ( en == GL_RENDERBUFFER_SAMPLES_EXT ) return "GL_RENDERBUFFER_SAMPLES_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT";
#endif
#ifdef GL_MAX_SAMPLES_EXT
	if ( en == GL_MAX_SAMPLES_EXT ) return "GL_MAX_SAMPLES_EXT";
#endif
#ifdef GL_SCALED_RESOLVE_FASTEST_EXT
	if ( en == GL_SCALED_RESOLVE_FASTEST_EXT ) return "GL_SCALED_RESOLVE_FASTEST_EXT";
#endif
#ifdef GL_SCALED_RESOLVE_NICEST_EXT
	if ( en == GL_SCALED_RESOLVE_NICEST_EXT ) return "GL_SCALED_RESOLVE_NICEST_EXT";
#endif
#ifdef GL_INVALID_FRAMEBUFFER_OPERATION_EXT
	if ( en == GL_INVALID_FRAMEBUFFER_OPERATION_EXT ) return "GL_INVALID_FRAMEBUFFER_OPERATION_EXT";
#endif
#ifdef GL_MAX_RENDERBUFFER_SIZE_EXT
	if ( en == GL_MAX_RENDERBUFFER_SIZE_EXT ) return "GL_MAX_RENDERBUFFER_SIZE_EXT";
#endif
#ifdef GL_FRAMEBUFFER_BINDING_EXT
	if ( en == GL_FRAMEBUFFER_BINDING_EXT ) return "GL_FRAMEBUFFER_BINDING_EXT";
#endif
#ifdef GL_RENDERBUFFER_BINDING_EXT
	if ( en == GL_RENDERBUFFER_BINDING_EXT ) return "GL_RENDERBUFFER_BINDING_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT";
#endif
#ifdef GL_FRAMEBUFFER_COMPLETE_EXT
	if ( en == GL_FRAMEBUFFER_COMPLETE_EXT ) return "GL_FRAMEBUFFER_COMPLETE_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT";
#endif
#ifdef GL_FRAMEBUFFER_UNSUPPORTED_EXT
	if ( en == GL_FRAMEBUFFER_UNSUPPORTED_EXT ) return "GL_FRAMEBUFFER_UNSUPPORTED_EXT";
#endif
#ifdef GL_MAX_COLOR_ATTACHMENTS_EXT
	if ( en == GL_MAX_COLOR_ATTACHMENTS_EXT ) return "GL_MAX_COLOR_ATTACHMENTS_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT0_EXT
	if ( en == GL_COLOR_ATTACHMENT0_EXT ) return "GL_COLOR_ATTACHMENT0_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT1_EXT
	if ( en == GL_COLOR_ATTACHMENT1_EXT ) return "GL_COLOR_ATTACHMENT1_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT2_EXT
	if ( en == GL_COLOR_ATTACHMENT2_EXT ) return "GL_COLOR_ATTACHMENT2_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT3_EXT
	if ( en == GL_COLOR_ATTACHMENT3_EXT ) return "GL_COLOR_ATTACHMENT3_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT4_EXT
	if ( en == GL_COLOR_ATTACHMENT4_EXT ) return "GL_COLOR_ATTACHMENT4_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT5_EXT
	if ( en == GL_COLOR_ATTACHMENT5_EXT ) return "GL_COLOR_ATTACHMENT5_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT6_EXT
	if ( en == GL_COLOR_ATTACHMENT6_EXT ) return "GL_COLOR_ATTACHMENT6_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT7_EXT
	if ( en == GL_COLOR_ATTACHMENT7_EXT ) return "GL_COLOR_ATTACHMENT7_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT8_EXT
	if ( en == GL_COLOR_ATTACHMENT8_EXT ) return "GL_COLOR_ATTACHMENT8_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT9_EXT
	if ( en == GL_COLOR_ATTACHMENT9_EXT ) return "GL_COLOR_ATTACHMENT9_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT10_EXT
	if ( en == GL_COLOR_ATTACHMENT10_EXT ) return "GL_COLOR_ATTACHMENT10_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT11_EXT
	if ( en == GL_COLOR_ATTACHMENT11_EXT ) return "GL_COLOR_ATTACHMENT11_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT12_EXT
	if ( en == GL_COLOR_ATTACHMENT12_EXT ) return "GL_COLOR_ATTACHMENT12_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT13_EXT
	if ( en == GL_COLOR_ATTACHMENT13_EXT ) return "GL_COLOR_ATTACHMENT13_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT14_EXT
	if ( en == GL_COLOR_ATTACHMENT14_EXT ) return "GL_COLOR_ATTACHMENT14_EXT";
#endif
#ifdef GL_COLOR_ATTACHMENT15_EXT
	if ( en == GL_COLOR_ATTACHMENT15_EXT ) return "GL_COLOR_ATTACHMENT15_EXT";
#endif
#ifdef GL_DEPTH_ATTACHMENT_EXT
	if ( en == GL_DEPTH_ATTACHMENT_EXT ) return "GL_DEPTH_ATTACHMENT_EXT";
#endif
#ifdef GL_STENCIL_ATTACHMENT_EXT
	if ( en == GL_STENCIL_ATTACHMENT_EXT ) return "GL_STENCIL_ATTACHMENT_EXT";
#endif
#ifdef GL_FRAMEBUFFER_EXT
	if ( en == GL_FRAMEBUFFER_EXT ) return "GL_FRAMEBUFFER_EXT";
#endif
#ifdef GL_RENDERBUFFER_EXT
	if ( en == GL_RENDERBUFFER_EXT ) return "GL_RENDERBUFFER_EXT";
#endif
#ifdef GL_RENDERBUFFER_WIDTH_EXT
	if ( en == GL_RENDERBUFFER_WIDTH_EXT ) return "GL_RENDERBUFFER_WIDTH_EXT";
#endif
#ifdef GL_RENDERBUFFER_HEIGHT_EXT
	if ( en == GL_RENDERBUFFER_HEIGHT_EXT ) return "GL_RENDERBUFFER_HEIGHT_EXT";
#endif
#ifdef GL_RENDERBUFFER_INTERNAL_FORMAT_EXT
	if ( en == GL_RENDERBUFFER_INTERNAL_FORMAT_EXT ) return "GL_RENDERBUFFER_INTERNAL_FORMAT_EXT";
#endif
#ifdef GL_STENCIL_INDEX1_EXT
	if ( en == GL_STENCIL_INDEX1_EXT ) return "GL_STENCIL_INDEX1_EXT";
#endif
#ifdef GL_STENCIL_INDEX4_EXT
	if ( en == GL_STENCIL_INDEX4_EXT ) return "GL_STENCIL_INDEX4_EXT";
#endif
#ifdef GL_STENCIL_INDEX8_EXT
	if ( en == GL_STENCIL_INDEX8_EXT ) return "GL_STENCIL_INDEX8_EXT";
#endif
#ifdef GL_STENCIL_INDEX16_EXT
	if ( en == GL_STENCIL_INDEX16_EXT ) return "GL_STENCIL_INDEX16_EXT";
#endif
#ifdef GL_RENDERBUFFER_RED_SIZE_EXT
	if ( en == GL_RENDERBUFFER_RED_SIZE_EXT ) return "GL_RENDERBUFFER_RED_SIZE_EXT";
#endif
#ifdef GL_RENDERBUFFER_GREEN_SIZE_EXT
	if ( en == GL_RENDERBUFFER_GREEN_SIZE_EXT ) return "GL_RENDERBUFFER_GREEN_SIZE_EXT";
#endif
#ifdef GL_RENDERBUFFER_BLUE_SIZE_EXT
	if ( en == GL_RENDERBUFFER_BLUE_SIZE_EXT ) return "GL_RENDERBUFFER_BLUE_SIZE_EXT";
#endif
#ifdef GL_RENDERBUFFER_ALPHA_SIZE_EXT
	if ( en == GL_RENDERBUFFER_ALPHA_SIZE_EXT ) return "GL_RENDERBUFFER_ALPHA_SIZE_EXT";
#endif
#ifdef GL_RENDERBUFFER_DEPTH_SIZE_EXT
	if ( en == GL_RENDERBUFFER_DEPTH_SIZE_EXT ) return "GL_RENDERBUFFER_DEPTH_SIZE_EXT";
#endif
#ifdef GL_RENDERBUFFER_STENCIL_SIZE_EXT
	if ( en == GL_RENDERBUFFER_STENCIL_SIZE_EXT ) return "GL_RENDERBUFFER_STENCIL_SIZE_EXT";
#endif
#ifdef GL_FRAMEBUFFER_SRGB_EXT
	if ( en == GL_FRAMEBUFFER_SRGB_EXT ) return "GL_FRAMEBUFFER_SRGB_EXT";
#endif
#ifdef GL_FRAMEBUFFER_SRGB_CAPABLE_EXT
	if ( en == GL_FRAMEBUFFER_SRGB_CAPABLE_EXT ) return "GL_FRAMEBUFFER_SRGB_CAPABLE_EXT";
#endif
#ifdef GL_LINES_ADJACENCY_EXT
	if ( en == GL_LINES_ADJACENCY_EXT ) return "GL_LINES_ADJACENCY_EXT";
#endif
#ifdef GL_LINE_STRIP_ADJACENCY_EXT
	if ( en == GL_LINE_STRIP_ADJACENCY_EXT ) return "GL_LINE_STRIP_ADJACENCY_EXT";
#endif
#ifdef GL_TRIANGLES_ADJACENCY_EXT
	if ( en == GL_TRIANGLES_ADJACENCY_EXT ) return "GL_TRIANGLES_ADJACENCY_EXT";
#endif
#ifdef GL_TRIANGLE_STRIP_ADJACENCY_EXT
	if ( en == GL_TRIANGLE_STRIP_ADJACENCY_EXT ) return "GL_TRIANGLE_STRIP_ADJACENCY_EXT";
#endif
#ifdef GL_PROGRAM_POINT_SIZE_EXT
	if ( en == GL_PROGRAM_POINT_SIZE_EXT ) return "GL_PROGRAM_POINT_SIZE_EXT";
#endif
#ifdef GL_MAX_VARYING_COMPONENTS_EXT
	if ( en == GL_MAX_VARYING_COMPONENTS_EXT ) return "GL_MAX_VARYING_COMPONENTS_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT
	if ( en == GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT ) return "GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT";
#endif
#ifdef GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT
	if ( en == GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT ) return "GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT";
#endif
#ifdef GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT
	if ( en == GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT ) return "GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT";
#endif
#ifdef GL_GEOMETRY_SHADER_EXT
	if ( en == GL_GEOMETRY_SHADER_EXT ) return "GL_GEOMETRY_SHADER_EXT";
#endif
#ifdef GL_GEOMETRY_VERTICES_OUT_EXT
	if ( en == GL_GEOMETRY_VERTICES_OUT_EXT ) return "GL_GEOMETRY_VERTICES_OUT_EXT";
#endif
#ifdef GL_GEOMETRY_INPUT_TYPE_EXT
	if ( en == GL_GEOMETRY_INPUT_TYPE_EXT ) return "GL_GEOMETRY_INPUT_TYPE_EXT";
#endif
#ifdef GL_GEOMETRY_OUTPUT_TYPE_EXT
	if ( en == GL_GEOMETRY_OUTPUT_TYPE_EXT ) return "GL_GEOMETRY_OUTPUT_TYPE_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT
	if ( en == GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT ) return "GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT";
#endif
#ifdef GL_MAX_VERTEX_VARYING_COMPONENTS_EXT
	if ( en == GL_MAX_VERTEX_VARYING_COMPONENTS_EXT ) return "GL_MAX_VERTEX_VARYING_COMPONENTS_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT
	if ( en == GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT ) return "GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT
	if ( en == GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT ) return "GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT";
#endif
#ifdef GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT
	if ( en == GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT ) return "GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT
	if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT ) return "GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT";
#endif
#ifdef GL_SAMPLER_1D_ARRAY_EXT
	if ( en == GL_SAMPLER_1D_ARRAY_EXT ) return "GL_SAMPLER_1D_ARRAY_EXT";
#endif
#ifdef GL_SAMPLER_2D_ARRAY_EXT
	if ( en == GL_SAMPLER_2D_ARRAY_EXT ) return "GL_SAMPLER_2D_ARRAY_EXT";
#endif
#ifdef GL_SAMPLER_BUFFER_EXT
	if ( en == GL_SAMPLER_BUFFER_EXT ) return "GL_SAMPLER_BUFFER_EXT";
#endif
#ifdef GL_SAMPLER_1D_ARRAY_SHADOW_EXT
	if ( en == GL_SAMPLER_1D_ARRAY_SHADOW_EXT ) return "GL_SAMPLER_1D_ARRAY_SHADOW_EXT";
#endif
#ifdef GL_SAMPLER_2D_ARRAY_SHADOW_EXT
	if ( en == GL_SAMPLER_2D_ARRAY_SHADOW_EXT ) return "GL_SAMPLER_2D_ARRAY_SHADOW_EXT";
#endif
#ifdef GL_SAMPLER_CUBE_SHADOW_EXT
	if ( en == GL_SAMPLER_CUBE_SHADOW_EXT ) return "GL_SAMPLER_CUBE_SHADOW_EXT";
#endif
#ifdef GL_UNSIGNED_INT_VEC2_EXT
	if ( en == GL_UNSIGNED_INT_VEC2_EXT ) return "GL_UNSIGNED_INT_VEC2_EXT";
#endif
#ifdef GL_UNSIGNED_INT_VEC3_EXT
	if ( en == GL_UNSIGNED_INT_VEC3_EXT ) return "GL_UNSIGNED_INT_VEC3_EXT";
#endif
#ifdef GL_UNSIGNED_INT_VEC4_EXT
	if ( en == GL_UNSIGNED_INT_VEC4_EXT ) return "GL_UNSIGNED_INT_VEC4_EXT";
#endif
#ifdef GL_INT_SAMPLER_1D_EXT
	if ( en == GL_INT_SAMPLER_1D_EXT ) return "GL_INT_SAMPLER_1D_EXT";
#endif
#ifdef GL_INT_SAMPLER_2D_EXT
	if ( en == GL_INT_SAMPLER_2D_EXT ) return "GL_INT_SAMPLER_2D_EXT";
#endif
#ifdef GL_INT_SAMPLER_3D_EXT
	if ( en == GL_INT_SAMPLER_3D_EXT ) return "GL_INT_SAMPLER_3D_EXT";
#endif
#ifdef GL_INT_SAMPLER_CUBE_EXT
	if ( en == GL_INT_SAMPLER_CUBE_EXT ) return "GL_INT_SAMPLER_CUBE_EXT";
#endif
#ifdef GL_INT_SAMPLER_2D_RECT_EXT
	if ( en == GL_INT_SAMPLER_2D_RECT_EXT ) return "GL_INT_SAMPLER_2D_RECT_EXT";
#endif
#ifdef GL_INT_SAMPLER_1D_ARRAY_EXT
	if ( en == GL_INT_SAMPLER_1D_ARRAY_EXT ) return "GL_INT_SAMPLER_1D_ARRAY_EXT";
#endif
#ifdef GL_INT_SAMPLER_2D_ARRAY_EXT
	if ( en == GL_INT_SAMPLER_2D_ARRAY_EXT ) return "GL_INT_SAMPLER_2D_ARRAY_EXT";
#endif
#ifdef GL_INT_SAMPLER_BUFFER_EXT
	if ( en == GL_INT_SAMPLER_BUFFER_EXT ) return "GL_INT_SAMPLER_BUFFER_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_1D_EXT ) return "GL_UNSIGNED_INT_SAMPLER_1D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_EXT ) return "GL_UNSIGNED_INT_SAMPLER_2D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_3D_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_3D_EXT ) return "GL_UNSIGNED_INT_SAMPLER_3D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_CUBE_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_CUBE_EXT ) return "GL_UNSIGNED_INT_SAMPLER_CUBE_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT ) return "GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT ) return "GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT ) return "GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT
	if ( en == GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT ) return "GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT";
#endif
#ifdef GL_HISTOGRAM_EXT
	if ( en == GL_HISTOGRAM_EXT ) return "GL_HISTOGRAM_EXT";
#endif
#ifdef GL_PROXY_HISTOGRAM_EXT
	if ( en == GL_PROXY_HISTOGRAM_EXT ) return "GL_PROXY_HISTOGRAM_EXT";
#endif
#ifdef GL_HISTOGRAM_WIDTH_EXT
	if ( en == GL_HISTOGRAM_WIDTH_EXT ) return "GL_HISTOGRAM_WIDTH_EXT";
#endif
#ifdef GL_HISTOGRAM_FORMAT_EXT
	if ( en == GL_HISTOGRAM_FORMAT_EXT ) return "GL_HISTOGRAM_FORMAT_EXT";
#endif
#ifdef GL_HISTOGRAM_RED_SIZE_EXT
	if ( en == GL_HISTOGRAM_RED_SIZE_EXT ) return "GL_HISTOGRAM_RED_SIZE_EXT";
#endif
#ifdef GL_HISTOGRAM_GREEN_SIZE_EXT
	if ( en == GL_HISTOGRAM_GREEN_SIZE_EXT ) return "GL_HISTOGRAM_GREEN_SIZE_EXT";
#endif
#ifdef GL_HISTOGRAM_BLUE_SIZE_EXT
	if ( en == GL_HISTOGRAM_BLUE_SIZE_EXT ) return "GL_HISTOGRAM_BLUE_SIZE_EXT";
#endif
#ifdef GL_HISTOGRAM_ALPHA_SIZE_EXT
	if ( en == GL_HISTOGRAM_ALPHA_SIZE_EXT ) return "GL_HISTOGRAM_ALPHA_SIZE_EXT";
#endif
#ifdef GL_HISTOGRAM_LUMINANCE_SIZE_EXT
	if ( en == GL_HISTOGRAM_LUMINANCE_SIZE_EXT ) return "GL_HISTOGRAM_LUMINANCE_SIZE_EXT";
#endif
#ifdef GL_HISTOGRAM_SINK_EXT
	if ( en == GL_HISTOGRAM_SINK_EXT ) return "GL_HISTOGRAM_SINK_EXT";
#endif
#ifdef GL_MINMAX_EXT
	if ( en == GL_MINMAX_EXT ) return "GL_MINMAX_EXT";
#endif
#ifdef GL_MINMAX_FORMAT_EXT
	if ( en == GL_MINMAX_FORMAT_EXT ) return "GL_MINMAX_FORMAT_EXT";
#endif
#ifdef GL_MINMAX_SINK_EXT
	if ( en == GL_MINMAX_SINK_EXT ) return "GL_MINMAX_SINK_EXT";
#endif
#ifdef GL_FRAGMENT_MATERIAL_EXT
	if ( en == GL_FRAGMENT_MATERIAL_EXT ) return "GL_FRAGMENT_MATERIAL_EXT";
#endif
#ifdef GL_FRAGMENT_NORMAL_EXT
	if ( en == GL_FRAGMENT_NORMAL_EXT ) return "GL_FRAGMENT_NORMAL_EXT";
#endif
#ifdef GL_FRAGMENT_COLOR_EXT
	if ( en == GL_FRAGMENT_COLOR_EXT ) return "GL_FRAGMENT_COLOR_EXT";
#endif
#ifdef GL_ATTENUATION_EXT
	if ( en == GL_ATTENUATION_EXT ) return "GL_ATTENUATION_EXT";
#endif
#ifdef GL_SHADOW_ATTENUATION_EXT
	if ( en == GL_SHADOW_ATTENUATION_EXT ) return "GL_SHADOW_ATTENUATION_EXT";
#endif
#ifdef GL_TEXTURE_APPLICATION_MODE_EXT
	if ( en == GL_TEXTURE_APPLICATION_MODE_EXT ) return "GL_TEXTURE_APPLICATION_MODE_EXT";
#endif
#ifdef GL_TEXTURE_LIGHT_EXT
	if ( en == GL_TEXTURE_LIGHT_EXT ) return "GL_TEXTURE_LIGHT_EXT";
#endif
#ifdef GL_TEXTURE_MATERIAL_FACE_EXT
	if ( en == GL_TEXTURE_MATERIAL_FACE_EXT ) return "GL_TEXTURE_MATERIAL_FACE_EXT";
#endif
#ifdef GL_TEXTURE_MATERIAL_PARAMETER_EXT
	if ( en == GL_TEXTURE_MATERIAL_PARAMETER_EXT ) return "GL_TEXTURE_MATERIAL_PARAMETER_EXT";
#endif
#ifdef GL_MULTISAMPLE_EXT
	if ( en == GL_MULTISAMPLE_EXT ) return "GL_MULTISAMPLE_EXT";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_MASK_EXT
	if ( en == GL_SAMPLE_ALPHA_TO_MASK_EXT ) return "GL_SAMPLE_ALPHA_TO_MASK_EXT";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE_EXT
	if ( en == GL_SAMPLE_ALPHA_TO_ONE_EXT ) return "GL_SAMPLE_ALPHA_TO_ONE_EXT";
#endif
#ifdef GL_SAMPLE_MASK_EXT
	if ( en == GL_SAMPLE_MASK_EXT ) return "GL_SAMPLE_MASK_EXT";
#endif
#ifdef GL_1PASS_EXT
	if ( en == GL_1PASS_EXT ) return "GL_1PASS_EXT";
#endif
#ifdef GL_2PASS_0_EXT
	if ( en == GL_2PASS_0_EXT ) return "GL_2PASS_0_EXT";
#endif
#ifdef GL_2PASS_1_EXT
	if ( en == GL_2PASS_1_EXT ) return "GL_2PASS_1_EXT";
#endif
#ifdef GL_4PASS_0_EXT
	if ( en == GL_4PASS_0_EXT ) return "GL_4PASS_0_EXT";
#endif
#ifdef GL_4PASS_1_EXT
	if ( en == GL_4PASS_1_EXT ) return "GL_4PASS_1_EXT";
#endif
#ifdef GL_4PASS_2_EXT
	if ( en == GL_4PASS_2_EXT ) return "GL_4PASS_2_EXT";
#endif
#ifdef GL_4PASS_3_EXT
	if ( en == GL_4PASS_3_EXT ) return "GL_4PASS_3_EXT";
#endif
#ifdef GL_SAMPLE_BUFFERS_EXT
	if ( en == GL_SAMPLE_BUFFERS_EXT ) return "GL_SAMPLE_BUFFERS_EXT";
#endif
#ifdef GL_SAMPLES_EXT
	if ( en == GL_SAMPLES_EXT ) return "GL_SAMPLES_EXT";
#endif
#ifdef GL_SAMPLE_MASK_VALUE_EXT
	if ( en == GL_SAMPLE_MASK_VALUE_EXT ) return "GL_SAMPLE_MASK_VALUE_EXT";
#endif
#ifdef GL_SAMPLE_MASK_INVERT_EXT
	if ( en == GL_SAMPLE_MASK_INVERT_EXT ) return "GL_SAMPLE_MASK_INVERT_EXT";
#endif
#ifdef GL_SAMPLE_PATTERN_EXT
	if ( en == GL_SAMPLE_PATTERN_EXT ) return "GL_SAMPLE_PATTERN_EXT";
#endif
#ifdef GL_MULTISAMPLE_BIT_EXT
	if ( en == GL_MULTISAMPLE_BIT_EXT ) return "GL_MULTISAMPLE_BIT_EXT";
#endif
#ifdef GL_DEPTH_STENCIL_EXT
	if ( en == GL_DEPTH_STENCIL_EXT ) return "GL_DEPTH_STENCIL_EXT";
#endif
#ifdef GL_UNSIGNED_INT_24_8_EXT
	if ( en == GL_UNSIGNED_INT_24_8_EXT ) return "GL_UNSIGNED_INT_24_8_EXT";
#endif
#ifdef GL_DEPTH24_STENCIL8_EXT
	if ( en == GL_DEPTH24_STENCIL8_EXT ) return "GL_DEPTH24_STENCIL8_EXT";
#endif
#ifdef GL_TEXTURE_STENCIL_SIZE_EXT
	if ( en == GL_TEXTURE_STENCIL_SIZE_EXT ) return "GL_TEXTURE_STENCIL_SIZE_EXT";
#endif
#ifdef GL_R11F_G11F_B10F_EXT
	if ( en == GL_R11F_G11F_B10F_EXT ) return "GL_R11F_G11F_B10F_EXT";
#endif
#ifdef GL_UNSIGNED_INT_10F_11F_11F_REV_EXT
	if ( en == GL_UNSIGNED_INT_10F_11F_11F_REV_EXT ) return "GL_UNSIGNED_INT_10F_11F_11F_REV_EXT";
#endif
#ifdef GL_RGBA_SIGNED_COMPONENTS_EXT
	if ( en == GL_RGBA_SIGNED_COMPONENTS_EXT ) return "GL_RGBA_SIGNED_COMPONENTS_EXT";
#endif
#ifdef GL_UNSIGNED_BYTE_3_3_2_EXT
	if ( en == GL_UNSIGNED_BYTE_3_3_2_EXT ) return "GL_UNSIGNED_BYTE_3_3_2_EXT";
#endif
#ifdef GL_UNSIGNED_SHORT_4_4_4_4_EXT
	if ( en == GL_UNSIGNED_SHORT_4_4_4_4_EXT ) return "GL_UNSIGNED_SHORT_4_4_4_4_EXT";
#endif
#ifdef GL_UNSIGNED_SHORT_5_5_5_1_EXT
	if ( en == GL_UNSIGNED_SHORT_5_5_5_1_EXT ) return "GL_UNSIGNED_SHORT_5_5_5_1_EXT";
#endif
#ifdef GL_UNSIGNED_INT_8_8_8_8_EXT
	if ( en == GL_UNSIGNED_INT_8_8_8_8_EXT ) return "GL_UNSIGNED_INT_8_8_8_8_EXT";
#endif
#ifdef GL_UNSIGNED_INT_10_10_10_2_EXT
	if ( en == GL_UNSIGNED_INT_10_10_10_2_EXT ) return "GL_UNSIGNED_INT_10_10_10_2_EXT";
#endif
#ifdef GL_TEXTURE_1D
	if ( en == GL_TEXTURE_1D ) return "GL_TEXTURE_1D";
#endif
#ifdef GL_TEXTURE_2D
	if ( en == GL_TEXTURE_2D ) return "GL_TEXTURE_2D";
#endif
#ifdef GL_PROXY_TEXTURE_1D
	if ( en == GL_PROXY_TEXTURE_1D ) return "GL_PROXY_TEXTURE_1D";
#endif
#ifdef GL_PROXY_TEXTURE_2D
	if ( en == GL_PROXY_TEXTURE_2D ) return "GL_PROXY_TEXTURE_2D";
#endif
#ifdef GL_COLOR_TABLE_FORMAT_EXT
	if ( en == GL_COLOR_TABLE_FORMAT_EXT ) return "GL_COLOR_TABLE_FORMAT_EXT";
#endif
#ifdef GL_COLOR_TABLE_WIDTH_EXT
	if ( en == GL_COLOR_TABLE_WIDTH_EXT ) return "GL_COLOR_TABLE_WIDTH_EXT";
#endif
#ifdef GL_COLOR_TABLE_RED_SIZE_EXT
	if ( en == GL_COLOR_TABLE_RED_SIZE_EXT ) return "GL_COLOR_TABLE_RED_SIZE_EXT";
#endif
#ifdef GL_COLOR_TABLE_GREEN_SIZE_EXT
	if ( en == GL_COLOR_TABLE_GREEN_SIZE_EXT ) return "GL_COLOR_TABLE_GREEN_SIZE_EXT";
#endif
#ifdef GL_COLOR_TABLE_BLUE_SIZE_EXT
	if ( en == GL_COLOR_TABLE_BLUE_SIZE_EXT ) return "GL_COLOR_TABLE_BLUE_SIZE_EXT";
#endif
#ifdef GL_COLOR_TABLE_ALPHA_SIZE_EXT
	if ( en == GL_COLOR_TABLE_ALPHA_SIZE_EXT ) return "GL_COLOR_TABLE_ALPHA_SIZE_EXT";
#endif
#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE_EXT
	if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE_EXT ) return "GL_COLOR_TABLE_LUMINANCE_SIZE_EXT";
#endif
#ifdef GL_COLOR_TABLE_INTENSITY_SIZE_EXT
	if ( en == GL_COLOR_TABLE_INTENSITY_SIZE_EXT ) return "GL_COLOR_TABLE_INTENSITY_SIZE_EXT";
#endif
#ifdef GL_COLOR_INDEX1_EXT
	if ( en == GL_COLOR_INDEX1_EXT ) return "GL_COLOR_INDEX1_EXT";
#endif
#ifdef GL_COLOR_INDEX2_EXT
	if ( en == GL_COLOR_INDEX2_EXT ) return "GL_COLOR_INDEX2_EXT";
#endif
#ifdef GL_COLOR_INDEX4_EXT
	if ( en == GL_COLOR_INDEX4_EXT ) return "GL_COLOR_INDEX4_EXT";
#endif
#ifdef GL_COLOR_INDEX8_EXT
	if ( en == GL_COLOR_INDEX8_EXT ) return "GL_COLOR_INDEX8_EXT";
#endif
#ifdef GL_COLOR_INDEX12_EXT
	if ( en == GL_COLOR_INDEX12_EXT ) return "GL_COLOR_INDEX12_EXT";
#endif
#ifdef GL_COLOR_INDEX16_EXT
	if ( en == GL_COLOR_INDEX16_EXT ) return "GL_COLOR_INDEX16_EXT";
#endif
#ifdef GL_TEXTURE_INDEX_SIZE_EXT
	if ( en == GL_TEXTURE_INDEX_SIZE_EXT ) return "GL_TEXTURE_INDEX_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_ARB
	if ( en == GL_TEXTURE_CUBE_MAP_ARB ) return "GL_TEXTURE_CUBE_MAP_ARB";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP_ARB
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP_ARB ) return "GL_PROXY_TEXTURE_CUBE_MAP_ARB";
#endif
#ifdef GL_PIXEL_PACK_BUFFER_EXT
	if ( en == GL_PIXEL_PACK_BUFFER_EXT ) return "GL_PIXEL_PACK_BUFFER_EXT";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_EXT
	if ( en == GL_PIXEL_UNPACK_BUFFER_EXT ) return "GL_PIXEL_UNPACK_BUFFER_EXT";
#endif
#ifdef GL_PIXEL_PACK_BUFFER_BINDING_EXT
	if ( en == GL_PIXEL_PACK_BUFFER_BINDING_EXT ) return "GL_PIXEL_PACK_BUFFER_BINDING_EXT";
#endif
#ifdef GL_PIXEL_UNPACK_BUFFER_BINDING_EXT
	if ( en == GL_PIXEL_UNPACK_BUFFER_BINDING_EXT ) return "GL_PIXEL_UNPACK_BUFFER_BINDING_EXT";
#endif
#ifdef GL_PIXEL_TRANSFORM_2D_EXT
	if ( en == GL_PIXEL_TRANSFORM_2D_EXT ) return "GL_PIXEL_TRANSFORM_2D_EXT";
#endif
#ifdef GL_PIXEL_MAG_FILTER_EXT
	if ( en == GL_PIXEL_MAG_FILTER_EXT ) return "GL_PIXEL_MAG_FILTER_EXT";
#endif
#ifdef GL_PIXEL_MIN_FILTER_EXT
	if ( en == GL_PIXEL_MIN_FILTER_EXT ) return "GL_PIXEL_MIN_FILTER_EXT";
#endif
#ifdef GL_PIXEL_CUBIC_WEIGHT_EXT
	if ( en == GL_PIXEL_CUBIC_WEIGHT_EXT ) return "GL_PIXEL_CUBIC_WEIGHT_EXT";
#endif
#ifdef GL_CUBIC_EXT
	if ( en == GL_CUBIC_EXT ) return "GL_CUBIC_EXT";
#endif
#ifdef GL_AVERAGE_EXT
	if ( en == GL_AVERAGE_EXT ) return "GL_AVERAGE_EXT";
#endif
#ifdef GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT
	if ( en == GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT ) return "GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT";
#endif
#ifdef GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT
	if ( en == GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT ) return "GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT";
#endif
#ifdef GL_PIXEL_TRANSFORM_2D_MATRIX_EXT
	if ( en == GL_PIXEL_TRANSFORM_2D_MATRIX_EXT ) return "GL_PIXEL_TRANSFORM_2D_MATRIX_EXT";
#endif
#ifdef GL_POINT_SIZE_MIN_EXT
	if ( en == GL_POINT_SIZE_MIN_EXT ) return "GL_POINT_SIZE_MIN_EXT";
#endif
#ifdef GL_POINT_SIZE_MAX_EXT
	if ( en == GL_POINT_SIZE_MAX_EXT ) return "GL_POINT_SIZE_MAX_EXT";
#endif
#ifdef GL_POINT_FADE_THRESHOLD_SIZE_EXT
	if ( en == GL_POINT_FADE_THRESHOLD_SIZE_EXT ) return "GL_POINT_FADE_THRESHOLD_SIZE_EXT";
#endif
#ifdef GL_DISTANCE_ATTENUATION_EXT
	if ( en == GL_DISTANCE_ATTENUATION_EXT ) return "GL_DISTANCE_ATTENUATION_EXT";
#endif
#ifdef GL_POLYGON_OFFSET_EXT
	if ( en == GL_POLYGON_OFFSET_EXT ) return "GL_POLYGON_OFFSET_EXT";
#endif
#ifdef GL_POLYGON_OFFSET_FACTOR_EXT
	if ( en == GL_POLYGON_OFFSET_FACTOR_EXT ) return "GL_POLYGON_OFFSET_FACTOR_EXT";
#endif
#ifdef GL_POLYGON_OFFSET_BIAS_EXT
	if ( en == GL_POLYGON_OFFSET_BIAS_EXT ) return "GL_POLYGON_OFFSET_BIAS_EXT";
#endif
#ifdef GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT
	if ( en == GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT ) return "GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT";
#endif
#ifdef GL_FIRST_VERTEX_CONVENTION_EXT
	if ( en == GL_FIRST_VERTEX_CONVENTION_EXT ) return "GL_FIRST_VERTEX_CONVENTION_EXT";
#endif
#ifdef GL_LAST_VERTEX_CONVENTION_EXT
	if ( en == GL_LAST_VERTEX_CONVENTION_EXT ) return "GL_LAST_VERTEX_CONVENTION_EXT";
#endif
#ifdef GL_PROVOKING_VERTEX_EXT
	if ( en == GL_PROVOKING_VERTEX_EXT ) return "GL_PROVOKING_VERTEX_EXT";
#endif
#ifdef GL_RESCALE_NORMAL_EXT
	if ( en == GL_RESCALE_NORMAL_EXT ) return "GL_RESCALE_NORMAL_EXT";
#endif
#ifdef GL_COLOR_SUM_EXT
	if ( en == GL_COLOR_SUM_EXT ) return "GL_COLOR_SUM_EXT";
#endif
#ifdef GL_CURRENT_SECONDARY_COLOR_EXT
	if ( en == GL_CURRENT_SECONDARY_COLOR_EXT ) return "GL_CURRENT_SECONDARY_COLOR_EXT";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_SIZE_EXT
	if ( en == GL_SECONDARY_COLOR_ARRAY_SIZE_EXT ) return "GL_SECONDARY_COLOR_ARRAY_SIZE_EXT";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_TYPE_EXT
	if ( en == GL_SECONDARY_COLOR_ARRAY_TYPE_EXT ) return "GL_SECONDARY_COLOR_ARRAY_TYPE_EXT";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT
	if ( en == GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT ) return "GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_POINTER_EXT
	if ( en == GL_SECONDARY_COLOR_ARRAY_POINTER_EXT ) return "GL_SECONDARY_COLOR_ARRAY_POINTER_EXT";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_EXT
	if ( en == GL_SECONDARY_COLOR_ARRAY_EXT ) return "GL_SECONDARY_COLOR_ARRAY_EXT";
#endif
#ifdef GL_ACTIVE_PROGRAM_EXT
	if ( en == GL_ACTIVE_PROGRAM_EXT ) return "GL_ACTIVE_PROGRAM_EXT";
#endif
#ifdef GL_LIGHT_MODEL_COLOR_CONTROL_EXT
	if ( en == GL_LIGHT_MODEL_COLOR_CONTROL_EXT ) return "GL_LIGHT_MODEL_COLOR_CONTROL_EXT";
#endif
#ifdef GL_SINGLE_COLOR_EXT
	if ( en == GL_SINGLE_COLOR_EXT ) return "GL_SINGLE_COLOR_EXT";
#endif
#ifdef GL_SEPARATE_SPECULAR_COLOR_EXT
	if ( en == GL_SEPARATE_SPECULAR_COLOR_EXT ) return "GL_SEPARATE_SPECULAR_COLOR_EXT";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT
	if ( en == GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT ) return "GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT";
#endif
#ifdef GL_ELEMENT_ARRAY_BARRIER_BIT_EXT
	if ( en == GL_ELEMENT_ARRAY_BARRIER_BIT_EXT ) return "GL_ELEMENT_ARRAY_BARRIER_BIT_EXT";
#endif
#ifdef GL_UNIFORM_BARRIER_BIT_EXT
	if ( en == GL_UNIFORM_BARRIER_BIT_EXT ) return "GL_UNIFORM_BARRIER_BIT_EXT";
#endif
#ifdef GL_TEXTURE_FETCH_BARRIER_BIT_EXT
	if ( en == GL_TEXTURE_FETCH_BARRIER_BIT_EXT ) return "GL_TEXTURE_FETCH_BARRIER_BIT_EXT";
#endif
#ifdef GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT
	if ( en == GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT ) return "GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT";
#endif
#ifdef GL_COMMAND_BARRIER_BIT_EXT
	if ( en == GL_COMMAND_BARRIER_BIT_EXT ) return "GL_COMMAND_BARRIER_BIT_EXT";
#endif
#ifdef GL_PIXEL_BUFFER_BARRIER_BIT_EXT
	if ( en == GL_PIXEL_BUFFER_BARRIER_BIT_EXT ) return "GL_PIXEL_BUFFER_BARRIER_BIT_EXT";
#endif
#ifdef GL_TEXTURE_UPDATE_BARRIER_BIT_EXT
	if ( en == GL_TEXTURE_UPDATE_BARRIER_BIT_EXT ) return "GL_TEXTURE_UPDATE_BARRIER_BIT_EXT";
#endif
#ifdef GL_BUFFER_UPDATE_BARRIER_BIT_EXT
	if ( en == GL_BUFFER_UPDATE_BARRIER_BIT_EXT ) return "GL_BUFFER_UPDATE_BARRIER_BIT_EXT";
#endif
#ifdef GL_FRAMEBUFFER_BARRIER_BIT_EXT
	if ( en == GL_FRAMEBUFFER_BARRIER_BIT_EXT ) return "GL_FRAMEBUFFER_BARRIER_BIT_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT ) return "GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT";
#endif
#ifdef GL_ATOMIC_COUNTER_BARRIER_BIT_EXT
	if ( en == GL_ATOMIC_COUNTER_BARRIER_BIT_EXT ) return "GL_ATOMIC_COUNTER_BARRIER_BIT_EXT";
#endif
#ifdef GL_MAX_IMAGE_UNITS_EXT
	if ( en == GL_MAX_IMAGE_UNITS_EXT ) return "GL_MAX_IMAGE_UNITS_EXT";
#endif
#ifdef GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT
	if ( en == GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT ) return "GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT";
#endif
#ifdef GL_IMAGE_BINDING_NAME_EXT
	if ( en == GL_IMAGE_BINDING_NAME_EXT ) return "GL_IMAGE_BINDING_NAME_EXT";
#endif
#ifdef GL_IMAGE_BINDING_LEVEL_EXT
	if ( en == GL_IMAGE_BINDING_LEVEL_EXT ) return "GL_IMAGE_BINDING_LEVEL_EXT";
#endif
#ifdef GL_IMAGE_BINDING_LAYERED_EXT
	if ( en == GL_IMAGE_BINDING_LAYERED_EXT ) return "GL_IMAGE_BINDING_LAYERED_EXT";
#endif
#ifdef GL_IMAGE_BINDING_LAYER_EXT
	if ( en == GL_IMAGE_BINDING_LAYER_EXT ) return "GL_IMAGE_BINDING_LAYER_EXT";
#endif
#ifdef GL_IMAGE_BINDING_ACCESS_EXT
	if ( en == GL_IMAGE_BINDING_ACCESS_EXT ) return "GL_IMAGE_BINDING_ACCESS_EXT";
#endif
#ifdef GL_IMAGE_1D_EXT
	if ( en == GL_IMAGE_1D_EXT ) return "GL_IMAGE_1D_EXT";
#endif
#ifdef GL_IMAGE_2D_EXT
	if ( en == GL_IMAGE_2D_EXT ) return "GL_IMAGE_2D_EXT";
#endif
#ifdef GL_IMAGE_3D_EXT
	if ( en == GL_IMAGE_3D_EXT ) return "GL_IMAGE_3D_EXT";
#endif
#ifdef GL_IMAGE_2D_RECT_EXT
	if ( en == GL_IMAGE_2D_RECT_EXT ) return "GL_IMAGE_2D_RECT_EXT";
#endif
#ifdef GL_IMAGE_CUBE_EXT
	if ( en == GL_IMAGE_CUBE_EXT ) return "GL_IMAGE_CUBE_EXT";
#endif
#ifdef GL_IMAGE_BUFFER_EXT
	if ( en == GL_IMAGE_BUFFER_EXT ) return "GL_IMAGE_BUFFER_EXT";
#endif
#ifdef GL_IMAGE_1D_ARRAY_EXT
	if ( en == GL_IMAGE_1D_ARRAY_EXT ) return "GL_IMAGE_1D_ARRAY_EXT";
#endif
#ifdef GL_IMAGE_2D_ARRAY_EXT
	if ( en == GL_IMAGE_2D_ARRAY_EXT ) return "GL_IMAGE_2D_ARRAY_EXT";
#endif
#ifdef GL_IMAGE_CUBE_MAP_ARRAY_EXT
	if ( en == GL_IMAGE_CUBE_MAP_ARRAY_EXT ) return "GL_IMAGE_CUBE_MAP_ARRAY_EXT";
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE_EXT
	if ( en == GL_IMAGE_2D_MULTISAMPLE_EXT ) return "GL_IMAGE_2D_MULTISAMPLE_EXT";
#endif
#ifdef GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
	if ( en == GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) return "GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
#endif
#ifdef GL_INT_IMAGE_1D_EXT
	if ( en == GL_INT_IMAGE_1D_EXT ) return "GL_INT_IMAGE_1D_EXT";
#endif
#ifdef GL_INT_IMAGE_2D_EXT
	if ( en == GL_INT_IMAGE_2D_EXT ) return "GL_INT_IMAGE_2D_EXT";
#endif
#ifdef GL_INT_IMAGE_3D_EXT
	if ( en == GL_INT_IMAGE_3D_EXT ) return "GL_INT_IMAGE_3D_EXT";
#endif
#ifdef GL_INT_IMAGE_2D_RECT_EXT
	if ( en == GL_INT_IMAGE_2D_RECT_EXT ) return "GL_INT_IMAGE_2D_RECT_EXT";
#endif
#ifdef GL_INT_IMAGE_CUBE_EXT
	if ( en == GL_INT_IMAGE_CUBE_EXT ) return "GL_INT_IMAGE_CUBE_EXT";
#endif
#ifdef GL_INT_IMAGE_BUFFER_EXT
	if ( en == GL_INT_IMAGE_BUFFER_EXT ) return "GL_INT_IMAGE_BUFFER_EXT";
#endif
#ifdef GL_INT_IMAGE_1D_ARRAY_EXT
	if ( en == GL_INT_IMAGE_1D_ARRAY_EXT ) return "GL_INT_IMAGE_1D_ARRAY_EXT";
#endif
#ifdef GL_INT_IMAGE_2D_ARRAY_EXT
	if ( en == GL_INT_IMAGE_2D_ARRAY_EXT ) return "GL_INT_IMAGE_2D_ARRAY_EXT";
#endif
#ifdef GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT
	if ( en == GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT ) return "GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT";
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_EXT
	if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_EXT ) return "GL_INT_IMAGE_2D_MULTISAMPLE_EXT";
#endif
#ifdef GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
	if ( en == GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) return "GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_1D_EXT ) return "GL_UNSIGNED_INT_IMAGE_1D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_EXT ) return "GL_UNSIGNED_INT_IMAGE_2D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_3D_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_3D_EXT ) return "GL_UNSIGNED_INT_IMAGE_3D_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT ) return "GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_EXT ) return "GL_UNSIGNED_INT_IMAGE_CUBE_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_BUFFER_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_BUFFER_EXT ) return "GL_UNSIGNED_INT_IMAGE_BUFFER_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT ) return "GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT ) return "GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT ) return "GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT ) return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT";
#endif
#ifdef GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT
	if ( en == GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT ) return "GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT";
#endif
#ifdef GL_MAX_IMAGE_SAMPLES_EXT
	if ( en == GL_MAX_IMAGE_SAMPLES_EXT ) return "GL_MAX_IMAGE_SAMPLES_EXT";
#endif
#ifdef GL_IMAGE_BINDING_FORMAT_EXT
	if ( en == GL_IMAGE_BINDING_FORMAT_EXT ) return "GL_IMAGE_BINDING_FORMAT_EXT";
#endif
#ifdef GL_ALL_BARRIER_BITS_EXT
	if ( en == GL_ALL_BARRIER_BITS_EXT ) return "GL_ALL_BARRIER_BITS_EXT";
#endif
#ifdef GL_SHARED_TEXTURE_PALETTE_EXT
	if ( en == GL_SHARED_TEXTURE_PALETTE_EXT ) return "GL_SHARED_TEXTURE_PALETTE_EXT";
#endif
#ifdef GL_STENCIL_TAG_BITS_EXT
	if ( en == GL_STENCIL_TAG_BITS_EXT ) return "GL_STENCIL_TAG_BITS_EXT";
#endif
#ifdef GL_STENCIL_CLEAR_TAG_VALUE_EXT
	if ( en == GL_STENCIL_CLEAR_TAG_VALUE_EXT ) return "GL_STENCIL_CLEAR_TAG_VALUE_EXT";
#endif
#ifdef GL_STENCIL_TEST_TWO_SIDE_EXT
	if ( en == GL_STENCIL_TEST_TWO_SIDE_EXT ) return "GL_STENCIL_TEST_TWO_SIDE_EXT";
#endif
#ifdef GL_ACTIVE_STENCIL_FACE_EXT
	if ( en == GL_ACTIVE_STENCIL_FACE_EXT ) return "GL_ACTIVE_STENCIL_FACE_EXT";
#endif
#ifdef GL_INCR_WRAP_EXT
	if ( en == GL_INCR_WRAP_EXT ) return "GL_INCR_WRAP_EXT";
#endif
#ifdef GL_DECR_WRAP_EXT
	if ( en == GL_DECR_WRAP_EXT ) return "GL_DECR_WRAP_EXT";
#endif
#ifdef GL_ALPHA4_EXT
	if ( en == GL_ALPHA4_EXT ) return "GL_ALPHA4_EXT";
#endif
#ifdef GL_ALPHA8_EXT
	if ( en == GL_ALPHA8_EXT ) return "GL_ALPHA8_EXT";
#endif
#ifdef GL_ALPHA12_EXT
	if ( en == GL_ALPHA12_EXT ) return "GL_ALPHA12_EXT";
#endif
#ifdef GL_ALPHA16_EXT
	if ( en == GL_ALPHA16_EXT ) return "GL_ALPHA16_EXT";
#endif
#ifdef GL_LUMINANCE4_EXT
	if ( en == GL_LUMINANCE4_EXT ) return "GL_LUMINANCE4_EXT";
#endif
#ifdef GL_LUMINANCE8_EXT
	if ( en == GL_LUMINANCE8_EXT ) return "GL_LUMINANCE8_EXT";
#endif
#ifdef GL_LUMINANCE12_EXT
	if ( en == GL_LUMINANCE12_EXT ) return "GL_LUMINANCE12_EXT";
#endif
#ifdef GL_LUMINANCE16_EXT
	if ( en == GL_LUMINANCE16_EXT ) return "GL_LUMINANCE16_EXT";
#endif
#ifdef GL_LUMINANCE4_ALPHA4_EXT
	if ( en == GL_LUMINANCE4_ALPHA4_EXT ) return "GL_LUMINANCE4_ALPHA4_EXT";
#endif
#ifdef GL_LUMINANCE6_ALPHA2_EXT
	if ( en == GL_LUMINANCE6_ALPHA2_EXT ) return "GL_LUMINANCE6_ALPHA2_EXT";
#endif
#ifdef GL_LUMINANCE8_ALPHA8_EXT
	if ( en == GL_LUMINANCE8_ALPHA8_EXT ) return "GL_LUMINANCE8_ALPHA8_EXT";
#endif
#ifdef GL_LUMINANCE12_ALPHA4_EXT
	if ( en == GL_LUMINANCE12_ALPHA4_EXT ) return "GL_LUMINANCE12_ALPHA4_EXT";
#endif
#ifdef GL_LUMINANCE12_ALPHA12_EXT
	if ( en == GL_LUMINANCE12_ALPHA12_EXT ) return "GL_LUMINANCE12_ALPHA12_EXT";
#endif
#ifdef GL_LUMINANCE16_ALPHA16_EXT
	if ( en == GL_LUMINANCE16_ALPHA16_EXT ) return "GL_LUMINANCE16_ALPHA16_EXT";
#endif
#ifdef GL_INTENSITY_EXT
	if ( en == GL_INTENSITY_EXT ) return "GL_INTENSITY_EXT";
#endif
#ifdef GL_INTENSITY4_EXT
	if ( en == GL_INTENSITY4_EXT ) return "GL_INTENSITY4_EXT";
#endif
#ifdef GL_INTENSITY8_EXT
	if ( en == GL_INTENSITY8_EXT ) return "GL_INTENSITY8_EXT";
#endif
#ifdef GL_INTENSITY12_EXT
	if ( en == GL_INTENSITY12_EXT ) return "GL_INTENSITY12_EXT";
#endif
#ifdef GL_INTENSITY16_EXT
	if ( en == GL_INTENSITY16_EXT ) return "GL_INTENSITY16_EXT";
#endif
#ifdef GL_RGB2_EXT
	if ( en == GL_RGB2_EXT ) return "GL_RGB2_EXT";
#endif
#ifdef GL_RGB4_EXT
	if ( en == GL_RGB4_EXT ) return "GL_RGB4_EXT";
#endif
#ifdef GL_RGB5_EXT
	if ( en == GL_RGB5_EXT ) return "GL_RGB5_EXT";
#endif
#ifdef GL_RGB8_EXT
	if ( en == GL_RGB8_EXT ) return "GL_RGB8_EXT";
#endif
#ifdef GL_RGB10_EXT
	if ( en == GL_RGB10_EXT ) return "GL_RGB10_EXT";
#endif
#ifdef GL_RGB12_EXT
	if ( en == GL_RGB12_EXT ) return "GL_RGB12_EXT";
#endif
#ifdef GL_RGB16_EXT
	if ( en == GL_RGB16_EXT ) return "GL_RGB16_EXT";
#endif
#ifdef GL_RGBA2_EXT
	if ( en == GL_RGBA2_EXT ) return "GL_RGBA2_EXT";
#endif
#ifdef GL_RGBA4_EXT
	if ( en == GL_RGBA4_EXT ) return "GL_RGBA4_EXT";
#endif
#ifdef GL_RGB5_A1_EXT
	if ( en == GL_RGB5_A1_EXT ) return "GL_RGB5_A1_EXT";
#endif
#ifdef GL_RGBA8_EXT
	if ( en == GL_RGBA8_EXT ) return "GL_RGBA8_EXT";
#endif
#ifdef GL_RGB10_A2_EXT
	if ( en == GL_RGB10_A2_EXT ) return "GL_RGB10_A2_EXT";
#endif
#ifdef GL_RGBA12_EXT
	if ( en == GL_RGBA12_EXT ) return "GL_RGBA12_EXT";
#endif
#ifdef GL_RGBA16_EXT
	if ( en == GL_RGBA16_EXT ) return "GL_RGBA16_EXT";
#endif
#ifdef GL_TEXTURE_RED_SIZE_EXT
	if ( en == GL_TEXTURE_RED_SIZE_EXT ) return "GL_TEXTURE_RED_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_GREEN_SIZE_EXT
	if ( en == GL_TEXTURE_GREEN_SIZE_EXT ) return "GL_TEXTURE_GREEN_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_BLUE_SIZE_EXT
	if ( en == GL_TEXTURE_BLUE_SIZE_EXT ) return "GL_TEXTURE_BLUE_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_ALPHA_SIZE_EXT
	if ( en == GL_TEXTURE_ALPHA_SIZE_EXT ) return "GL_TEXTURE_ALPHA_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_LUMINANCE_SIZE_EXT
	if ( en == GL_TEXTURE_LUMINANCE_SIZE_EXT ) return "GL_TEXTURE_LUMINANCE_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_INTENSITY_SIZE_EXT
	if ( en == GL_TEXTURE_INTENSITY_SIZE_EXT ) return "GL_TEXTURE_INTENSITY_SIZE_EXT";
#endif
#ifdef GL_REPLACE_EXT
	if ( en == GL_REPLACE_EXT ) return "GL_REPLACE_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_1D_EXT
	if ( en == GL_PROXY_TEXTURE_1D_EXT ) return "GL_PROXY_TEXTURE_1D_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_2D_EXT
	if ( en == GL_PROXY_TEXTURE_2D_EXT ) return "GL_PROXY_TEXTURE_2D_EXT";
#endif
#ifdef GL_PACK_SKIP_IMAGES_EXT
	if ( en == GL_PACK_SKIP_IMAGES_EXT ) return "GL_PACK_SKIP_IMAGES_EXT";
#endif
#ifdef GL_PACK_IMAGE_HEIGHT_EXT
	if ( en == GL_PACK_IMAGE_HEIGHT_EXT ) return "GL_PACK_IMAGE_HEIGHT_EXT";
#endif
#ifdef GL_UNPACK_SKIP_IMAGES_EXT
	if ( en == GL_UNPACK_SKIP_IMAGES_EXT ) return "GL_UNPACK_SKIP_IMAGES_EXT";
#endif
#ifdef GL_UNPACK_IMAGE_HEIGHT_EXT
	if ( en == GL_UNPACK_IMAGE_HEIGHT_EXT ) return "GL_UNPACK_IMAGE_HEIGHT_EXT";
#endif
#ifdef GL_TEXTURE_3D_EXT
	if ( en == GL_TEXTURE_3D_EXT ) return "GL_TEXTURE_3D_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_3D_EXT
	if ( en == GL_PROXY_TEXTURE_3D_EXT ) return "GL_PROXY_TEXTURE_3D_EXT";
#endif
#ifdef GL_TEXTURE_DEPTH_EXT
	if ( en == GL_TEXTURE_DEPTH_EXT ) return "GL_TEXTURE_DEPTH_EXT";
#endif
#ifdef GL_TEXTURE_WRAP_R_EXT
	if ( en == GL_TEXTURE_WRAP_R_EXT ) return "GL_TEXTURE_WRAP_R_EXT";
#endif
#ifdef GL_MAX_3D_TEXTURE_SIZE_EXT
	if ( en == GL_MAX_3D_TEXTURE_SIZE_EXT ) return "GL_MAX_3D_TEXTURE_SIZE_EXT";
#endif
#ifdef GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT
	if ( en == GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT ) return "GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT";
#endif
#ifdef GL_MAX_ARRAY_TEXTURE_LAYERS_EXT
	if ( en == GL_MAX_ARRAY_TEXTURE_LAYERS_EXT ) return "GL_MAX_ARRAY_TEXTURE_LAYERS_EXT";
#endif
#ifdef GL_TEXTURE_1D_ARRAY_EXT
	if ( en == GL_TEXTURE_1D_ARRAY_EXT ) return "GL_TEXTURE_1D_ARRAY_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_1D_ARRAY_EXT
	if ( en == GL_PROXY_TEXTURE_1D_ARRAY_EXT ) return "GL_PROXY_TEXTURE_1D_ARRAY_EXT";
#endif
#ifdef GL_TEXTURE_2D_ARRAY_EXT
	if ( en == GL_TEXTURE_2D_ARRAY_EXT ) return "GL_TEXTURE_2D_ARRAY_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_2D_ARRAY_EXT
	if ( en == GL_PROXY_TEXTURE_2D_ARRAY_EXT ) return "GL_PROXY_TEXTURE_2D_ARRAY_EXT";
#endif
#ifdef GL_TEXTURE_BINDING_1D_ARRAY_EXT
	if ( en == GL_TEXTURE_BINDING_1D_ARRAY_EXT ) return "GL_TEXTURE_BINDING_1D_ARRAY_EXT";
#endif
#ifdef GL_TEXTURE_BINDING_2D_ARRAY_EXT
	if ( en == GL_TEXTURE_BINDING_2D_ARRAY_EXT ) return "GL_TEXTURE_BINDING_2D_ARRAY_EXT";
#endif
#ifdef GL_TEXTURE_BUFFER_EXT
	if ( en == GL_TEXTURE_BUFFER_EXT ) return "GL_TEXTURE_BUFFER_EXT";
#endif
#ifdef GL_MAX_TEXTURE_BUFFER_SIZE_EXT
	if ( en == GL_MAX_TEXTURE_BUFFER_SIZE_EXT ) return "GL_MAX_TEXTURE_BUFFER_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_BINDING_BUFFER_EXT
	if ( en == GL_TEXTURE_BINDING_BUFFER_EXT ) return "GL_TEXTURE_BINDING_BUFFER_EXT";
#endif
#ifdef GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT
	if ( en == GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT ) return "GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT";
#endif
#ifdef GL_TEXTURE_BUFFER_FORMAT_EXT
	if ( en == GL_TEXTURE_BUFFER_FORMAT_EXT ) return "GL_TEXTURE_BUFFER_FORMAT_EXT";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_LATC1_EXT
	if ( en == GL_COMPRESSED_LUMINANCE_LATC1_EXT ) return "GL_COMPRESSED_LUMINANCE_LATC1_EXT";
#endif
#ifdef GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT
	if ( en == GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT ) return "GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT";
#endif
#ifdef GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT
	if ( en == GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT ) return "GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT";
#endif
#ifdef GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT
	if ( en == GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT ) return "GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT";
#endif
#ifdef GL_COMPRESSED_RED_RGTC1_EXT
	if ( en == GL_COMPRESSED_RED_RGTC1_EXT ) return "GL_COMPRESSED_RED_RGTC1_EXT";
#endif
#ifdef GL_COMPRESSED_SIGNED_RED_RGTC1_EXT
	if ( en == GL_COMPRESSED_SIGNED_RED_RGTC1_EXT ) return "GL_COMPRESSED_SIGNED_RED_RGTC1_EXT";
#endif
#ifdef GL_COMPRESSED_RED_GREEN_RGTC2_EXT
	if ( en == GL_COMPRESSED_RED_GREEN_RGTC2_EXT ) return "GL_COMPRESSED_RED_GREEN_RGTC2_EXT";
#endif
#ifdef GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT
	if ( en == GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT ) return "GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT";
#endif
#ifdef GL_COMPRESSED_RGB_S3TC_DXT1_EXT
	if ( en == GL_COMPRESSED_RGB_S3TC_DXT1_EXT ) return "GL_COMPRESSED_RGB_S3TC_DXT1_EXT";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT1_EXT
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT ) return "GL_COMPRESSED_RGBA_S3TC_DXT1_EXT";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT3_EXT
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT3_EXT ) return "GL_COMPRESSED_RGBA_S3TC_DXT3_EXT";
#endif
#ifdef GL_COMPRESSED_RGBA_S3TC_DXT5_EXT
	if ( en == GL_COMPRESSED_RGBA_S3TC_DXT5_EXT ) return "GL_COMPRESSED_RGBA_S3TC_DXT5_EXT";
#endif
#ifdef GL_NORMAL_MAP_EXT
	if ( en == GL_NORMAL_MAP_EXT ) return "GL_NORMAL_MAP_EXT";
#endif
#ifdef GL_REFLECTION_MAP_EXT
	if ( en == GL_REFLECTION_MAP_EXT ) return "GL_REFLECTION_MAP_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_EXT ) return "GL_TEXTURE_CUBE_MAP_EXT";
#endif
#ifdef GL_TEXTURE_BINDING_CUBE_MAP_EXT
	if ( en == GL_TEXTURE_BINDING_CUBE_MAP_EXT ) return "GL_TEXTURE_BINDING_CUBE_MAP_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT ) return "GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT";
#endif
#ifdef GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT
	if ( en == GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT ) return "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_CUBE_MAP_EXT
	if ( en == GL_PROXY_TEXTURE_CUBE_MAP_EXT ) return "GL_PROXY_TEXTURE_CUBE_MAP_EXT";
#endif
#ifdef GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT
	if ( en == GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT ) return "GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT";
#endif
#ifdef GL_CLAMP_TO_EDGE_EXT
	if ( en == GL_CLAMP_TO_EDGE_EXT ) return "GL_CLAMP_TO_EDGE_EXT";
#endif
#ifdef GL_COMBINE_EXT
	if ( en == GL_COMBINE_EXT ) return "GL_COMBINE_EXT";
#endif
#ifdef GL_COMBINE_RGB_EXT
	if ( en == GL_COMBINE_RGB_EXT ) return "GL_COMBINE_RGB_EXT";
#endif
#ifdef GL_COMBINE_ALPHA_EXT
	if ( en == GL_COMBINE_ALPHA_EXT ) return "GL_COMBINE_ALPHA_EXT";
#endif
#ifdef GL_RGB_SCALE_EXT
	if ( en == GL_RGB_SCALE_EXT ) return "GL_RGB_SCALE_EXT";
#endif
#ifdef GL_ADD_SIGNED_EXT
	if ( en == GL_ADD_SIGNED_EXT ) return "GL_ADD_SIGNED_EXT";
#endif
#ifdef GL_INTERPOLATE_EXT
	if ( en == GL_INTERPOLATE_EXT ) return "GL_INTERPOLATE_EXT";
#endif
#ifdef GL_CONSTANT_EXT
	if ( en == GL_CONSTANT_EXT ) return "GL_CONSTANT_EXT";
#endif
#ifdef GL_PRIMARY_COLOR_EXT
	if ( en == GL_PRIMARY_COLOR_EXT ) return "GL_PRIMARY_COLOR_EXT";
#endif
#ifdef GL_PREVIOUS_EXT
	if ( en == GL_PREVIOUS_EXT ) return "GL_PREVIOUS_EXT";
#endif
#ifdef GL_SOURCE0_RGB_EXT
	if ( en == GL_SOURCE0_RGB_EXT ) return "GL_SOURCE0_RGB_EXT";
#endif
#ifdef GL_SOURCE1_RGB_EXT
	if ( en == GL_SOURCE1_RGB_EXT ) return "GL_SOURCE1_RGB_EXT";
#endif
#ifdef GL_SOURCE2_RGB_EXT
	if ( en == GL_SOURCE2_RGB_EXT ) return "GL_SOURCE2_RGB_EXT";
#endif
#ifdef GL_SOURCE0_ALPHA_EXT
	if ( en == GL_SOURCE0_ALPHA_EXT ) return "GL_SOURCE0_ALPHA_EXT";
#endif
#ifdef GL_SOURCE1_ALPHA_EXT
	if ( en == GL_SOURCE1_ALPHA_EXT ) return "GL_SOURCE1_ALPHA_EXT";
#endif
#ifdef GL_SOURCE2_ALPHA_EXT
	if ( en == GL_SOURCE2_ALPHA_EXT ) return "GL_SOURCE2_ALPHA_EXT";
#endif
#ifdef GL_OPERAND0_RGB_EXT
	if ( en == GL_OPERAND0_RGB_EXT ) return "GL_OPERAND0_RGB_EXT";
#endif
#ifdef GL_OPERAND1_RGB_EXT
	if ( en == GL_OPERAND1_RGB_EXT ) return "GL_OPERAND1_RGB_EXT";
#endif
#ifdef GL_OPERAND2_RGB_EXT
	if ( en == GL_OPERAND2_RGB_EXT ) return "GL_OPERAND2_RGB_EXT";
#endif
#ifdef GL_OPERAND0_ALPHA_EXT
	if ( en == GL_OPERAND0_ALPHA_EXT ) return "GL_OPERAND0_ALPHA_EXT";
#endif
#ifdef GL_OPERAND1_ALPHA_EXT
	if ( en == GL_OPERAND1_ALPHA_EXT ) return "GL_OPERAND1_ALPHA_EXT";
#endif
#ifdef GL_OPERAND2_ALPHA_EXT
	if ( en == GL_OPERAND2_ALPHA_EXT ) return "GL_OPERAND2_ALPHA_EXT";
#endif
#ifdef GL_DOT3_RGB_EXT
	if ( en == GL_DOT3_RGB_EXT ) return "GL_DOT3_RGB_EXT";
#endif
#ifdef GL_DOT3_RGBA_EXT
	if ( en == GL_DOT3_RGBA_EXT ) return "GL_DOT3_RGBA_EXT";
#endif
#ifdef GL_TEXTURE_MAX_ANISOTROPY_EXT
	if ( en == GL_TEXTURE_MAX_ANISOTROPY_EXT ) return "GL_TEXTURE_MAX_ANISOTROPY_EXT";
#endif
#ifdef GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT
	if ( en == GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT ) return "GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT";
#endif
#ifdef GL_RGBA32UI_EXT
	if ( en == GL_RGBA32UI_EXT ) return "GL_RGBA32UI_EXT";
#endif
#ifdef GL_RGB32UI_EXT
	if ( en == GL_RGB32UI_EXT ) return "GL_RGB32UI_EXT";
#endif
#ifdef GL_ALPHA32UI_EXT
	if ( en == GL_ALPHA32UI_EXT ) return "GL_ALPHA32UI_EXT";
#endif
#ifdef GL_INTENSITY32UI_EXT
	if ( en == GL_INTENSITY32UI_EXT ) return "GL_INTENSITY32UI_EXT";
#endif
#ifdef GL_LUMINANCE32UI_EXT
	if ( en == GL_LUMINANCE32UI_EXT ) return "GL_LUMINANCE32UI_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA32UI_EXT
	if ( en == GL_LUMINANCE_ALPHA32UI_EXT ) return "GL_LUMINANCE_ALPHA32UI_EXT";
#endif
#ifdef GL_RGBA16UI_EXT
	if ( en == GL_RGBA16UI_EXT ) return "GL_RGBA16UI_EXT";
#endif
#ifdef GL_RGB16UI_EXT
	if ( en == GL_RGB16UI_EXT ) return "GL_RGB16UI_EXT";
#endif
#ifdef GL_ALPHA16UI_EXT
	if ( en == GL_ALPHA16UI_EXT ) return "GL_ALPHA16UI_EXT";
#endif
#ifdef GL_INTENSITY16UI_EXT
	if ( en == GL_INTENSITY16UI_EXT ) return "GL_INTENSITY16UI_EXT";
#endif
#ifdef GL_LUMINANCE16UI_EXT
	if ( en == GL_LUMINANCE16UI_EXT ) return "GL_LUMINANCE16UI_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA16UI_EXT
	if ( en == GL_LUMINANCE_ALPHA16UI_EXT ) return "GL_LUMINANCE_ALPHA16UI_EXT";
#endif
#ifdef GL_RGBA8UI_EXT
	if ( en == GL_RGBA8UI_EXT ) return "GL_RGBA8UI_EXT";
#endif
#ifdef GL_RGB8UI_EXT
	if ( en == GL_RGB8UI_EXT ) return "GL_RGB8UI_EXT";
#endif
#ifdef GL_ALPHA8UI_EXT
	if ( en == GL_ALPHA8UI_EXT ) return "GL_ALPHA8UI_EXT";
#endif
#ifdef GL_INTENSITY8UI_EXT
	if ( en == GL_INTENSITY8UI_EXT ) return "GL_INTENSITY8UI_EXT";
#endif
#ifdef GL_LUMINANCE8UI_EXT
	if ( en == GL_LUMINANCE8UI_EXT ) return "GL_LUMINANCE8UI_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA8UI_EXT
	if ( en == GL_LUMINANCE_ALPHA8UI_EXT ) return "GL_LUMINANCE_ALPHA8UI_EXT";
#endif
#ifdef GL_RGBA32I_EXT
	if ( en == GL_RGBA32I_EXT ) return "GL_RGBA32I_EXT";
#endif
#ifdef GL_RGB32I_EXT
	if ( en == GL_RGB32I_EXT ) return "GL_RGB32I_EXT";
#endif
#ifdef GL_ALPHA32I_EXT
	if ( en == GL_ALPHA32I_EXT ) return "GL_ALPHA32I_EXT";
#endif
#ifdef GL_INTENSITY32I_EXT
	if ( en == GL_INTENSITY32I_EXT ) return "GL_INTENSITY32I_EXT";
#endif
#ifdef GL_LUMINANCE32I_EXT
	if ( en == GL_LUMINANCE32I_EXT ) return "GL_LUMINANCE32I_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA32I_EXT
	if ( en == GL_LUMINANCE_ALPHA32I_EXT ) return "GL_LUMINANCE_ALPHA32I_EXT";
#endif
#ifdef GL_RGBA16I_EXT
	if ( en == GL_RGBA16I_EXT ) return "GL_RGBA16I_EXT";
#endif
#ifdef GL_RGB16I_EXT
	if ( en == GL_RGB16I_EXT ) return "GL_RGB16I_EXT";
#endif
#ifdef GL_ALPHA16I_EXT
	if ( en == GL_ALPHA16I_EXT ) return "GL_ALPHA16I_EXT";
#endif
#ifdef GL_INTENSITY16I_EXT
	if ( en == GL_INTENSITY16I_EXT ) return "GL_INTENSITY16I_EXT";
#endif
#ifdef GL_LUMINANCE16I_EXT
	if ( en == GL_LUMINANCE16I_EXT ) return "GL_LUMINANCE16I_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA16I_EXT
	if ( en == GL_LUMINANCE_ALPHA16I_EXT ) return "GL_LUMINANCE_ALPHA16I_EXT";
#endif
#ifdef GL_RGBA8I_EXT
	if ( en == GL_RGBA8I_EXT ) return "GL_RGBA8I_EXT";
#endif
#ifdef GL_RGB8I_EXT
	if ( en == GL_RGB8I_EXT ) return "GL_RGB8I_EXT";
#endif
#ifdef GL_ALPHA8I_EXT
	if ( en == GL_ALPHA8I_EXT ) return "GL_ALPHA8I_EXT";
#endif
#ifdef GL_INTENSITY8I_EXT
	if ( en == GL_INTENSITY8I_EXT ) return "GL_INTENSITY8I_EXT";
#endif
#ifdef GL_LUMINANCE8I_EXT
	if ( en == GL_LUMINANCE8I_EXT ) return "GL_LUMINANCE8I_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA8I_EXT
	if ( en == GL_LUMINANCE_ALPHA8I_EXT ) return "GL_LUMINANCE_ALPHA8I_EXT";
#endif
#ifdef GL_RED_INTEGER_EXT
	if ( en == GL_RED_INTEGER_EXT ) return "GL_RED_INTEGER_EXT";
#endif
#ifdef GL_GREEN_INTEGER_EXT
	if ( en == GL_GREEN_INTEGER_EXT ) return "GL_GREEN_INTEGER_EXT";
#endif
#ifdef GL_BLUE_INTEGER_EXT
	if ( en == GL_BLUE_INTEGER_EXT ) return "GL_BLUE_INTEGER_EXT";
#endif
#ifdef GL_ALPHA_INTEGER_EXT
	if ( en == GL_ALPHA_INTEGER_EXT ) return "GL_ALPHA_INTEGER_EXT";
#endif
#ifdef GL_RGB_INTEGER_EXT
	if ( en == GL_RGB_INTEGER_EXT ) return "GL_RGB_INTEGER_EXT";
#endif
#ifdef GL_RGBA_INTEGER_EXT
	if ( en == GL_RGBA_INTEGER_EXT ) return "GL_RGBA_INTEGER_EXT";
#endif
#ifdef GL_BGR_INTEGER_EXT
	if ( en == GL_BGR_INTEGER_EXT ) return "GL_BGR_INTEGER_EXT";
#endif
#ifdef GL_BGRA_INTEGER_EXT
	if ( en == GL_BGRA_INTEGER_EXT ) return "GL_BGRA_INTEGER_EXT";
#endif
#ifdef GL_LUMINANCE_INTEGER_EXT
	if ( en == GL_LUMINANCE_INTEGER_EXT ) return "GL_LUMINANCE_INTEGER_EXT";
#endif
#ifdef GL_LUMINANCE_ALPHA_INTEGER_EXT
	if ( en == GL_LUMINANCE_ALPHA_INTEGER_EXT ) return "GL_LUMINANCE_ALPHA_INTEGER_EXT";
#endif
#ifdef GL_RGBA_INTEGER_MODE_EXT
	if ( en == GL_RGBA_INTEGER_MODE_EXT ) return "GL_RGBA_INTEGER_MODE_EXT";
#endif
#ifdef GL_MAX_TEXTURE_LOD_BIAS_EXT
	if ( en == GL_MAX_TEXTURE_LOD_BIAS_EXT ) return "GL_MAX_TEXTURE_LOD_BIAS_EXT";
#endif
#ifdef GL_TEXTURE_FILTER_CONTROL_EXT
	if ( en == GL_TEXTURE_FILTER_CONTROL_EXT ) return "GL_TEXTURE_FILTER_CONTROL_EXT";
#endif
#ifdef GL_TEXTURE_LOD_BIAS_EXT
	if ( en == GL_TEXTURE_LOD_BIAS_EXT ) return "GL_TEXTURE_LOD_BIAS_EXT";
#endif
#ifdef GL_MIRROR_CLAMP_EXT
	if ( en == GL_MIRROR_CLAMP_EXT ) return "GL_MIRROR_CLAMP_EXT";
#endif
#ifdef GL_MIRROR_CLAMP_TO_EDGE_EXT
	if ( en == GL_MIRROR_CLAMP_TO_EDGE_EXT ) return "GL_MIRROR_CLAMP_TO_EDGE_EXT";
#endif
#ifdef GL_MIRROR_CLAMP_TO_BORDER_EXT
	if ( en == GL_MIRROR_CLAMP_TO_BORDER_EXT ) return "GL_MIRROR_CLAMP_TO_BORDER_EXT";
#endif
#ifdef GL_TEXTURE_PRIORITY_EXT
	if ( en == GL_TEXTURE_PRIORITY_EXT ) return "GL_TEXTURE_PRIORITY_EXT";
#endif
#ifdef GL_TEXTURE_RESIDENT_EXT
	if ( en == GL_TEXTURE_RESIDENT_EXT ) return "GL_TEXTURE_RESIDENT_EXT";
#endif
#ifdef GL_TEXTURE_1D_BINDING_EXT
	if ( en == GL_TEXTURE_1D_BINDING_EXT ) return "GL_TEXTURE_1D_BINDING_EXT";
#endif
#ifdef GL_TEXTURE_2D_BINDING_EXT
	if ( en == GL_TEXTURE_2D_BINDING_EXT ) return "GL_TEXTURE_2D_BINDING_EXT";
#endif
#ifdef GL_TEXTURE_3D_BINDING_EXT
	if ( en == GL_TEXTURE_3D_BINDING_EXT ) return "GL_TEXTURE_3D_BINDING_EXT";
#endif
#ifdef GL_PERTURB_EXT
	if ( en == GL_PERTURB_EXT ) return "GL_PERTURB_EXT";
#endif
#ifdef GL_TEXTURE_NORMAL_EXT
	if ( en == GL_TEXTURE_NORMAL_EXT ) return "GL_TEXTURE_NORMAL_EXT";
#endif
#ifdef GL_TEXTURE_RECTANGLE_EXT
	if ( en == GL_TEXTURE_RECTANGLE_EXT ) return "GL_TEXTURE_RECTANGLE_EXT";
#endif
#ifdef GL_TEXTURE_BINDING_RECTANGLE_EXT
	if ( en == GL_TEXTURE_BINDING_RECTANGLE_EXT ) return "GL_TEXTURE_BINDING_RECTANGLE_EXT";
#endif
#ifdef GL_PROXY_TEXTURE_RECTANGLE_EXT
	if ( en == GL_PROXY_TEXTURE_RECTANGLE_EXT ) return "GL_PROXY_TEXTURE_RECTANGLE_EXT";
#endif
#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT
	if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT ) return "GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT";
#endif
#ifdef GL_SRGB_EXT
	if ( en == GL_SRGB_EXT ) return "GL_SRGB_EXT";
#endif
#ifdef GL_SRGB8_EXT
	if ( en == GL_SRGB8_EXT ) return "GL_SRGB8_EXT";
#endif
#ifdef GL_SRGB_ALPHA_EXT
	if ( en == GL_SRGB_ALPHA_EXT ) return "GL_SRGB_ALPHA_EXT";
#endif
#ifdef GL_SRGB8_ALPHA8_EXT
	if ( en == GL_SRGB8_ALPHA8_EXT ) return "GL_SRGB8_ALPHA8_EXT";
#endif
#ifdef GL_SLUMINANCE_ALPHA_EXT
	if ( en == GL_SLUMINANCE_ALPHA_EXT ) return "GL_SLUMINANCE_ALPHA_EXT";
#endif
#ifdef GL_SLUMINANCE8_ALPHA8_EXT
	if ( en == GL_SLUMINANCE8_ALPHA8_EXT ) return "GL_SLUMINANCE8_ALPHA8_EXT";
#endif
#ifdef GL_SLUMINANCE_EXT
	if ( en == GL_SLUMINANCE_EXT ) return "GL_SLUMINANCE_EXT";
#endif
#ifdef GL_SLUMINANCE8_EXT
	if ( en == GL_SLUMINANCE8_EXT ) return "GL_SLUMINANCE8_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_EXT
	if ( en == GL_COMPRESSED_SRGB_EXT ) return "GL_COMPRESSED_SRGB_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_EXT
	if ( en == GL_COMPRESSED_SRGB_ALPHA_EXT ) return "GL_COMPRESSED_SRGB_ALPHA_EXT";
#endif
#ifdef GL_COMPRESSED_SLUMINANCE_EXT
	if ( en == GL_COMPRESSED_SLUMINANCE_EXT ) return "GL_COMPRESSED_SLUMINANCE_EXT";
#endif
#ifdef GL_COMPRESSED_SLUMINANCE_ALPHA_EXT
	if ( en == GL_COMPRESSED_SLUMINANCE_ALPHA_EXT ) return "GL_COMPRESSED_SLUMINANCE_ALPHA_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_S3TC_DXT1_EXT
	if ( en == GL_COMPRESSED_SRGB_S3TC_DXT1_EXT ) return "GL_COMPRESSED_SRGB_S3TC_DXT1_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT
	if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT ) return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT
	if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT ) return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT";
#endif
#ifdef GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT
	if ( en == GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT ) return "GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT";
#endif
#ifdef GL_TEXTURE_SRGB_DECODE_EXT
	if ( en == GL_TEXTURE_SRGB_DECODE_EXT ) return "GL_TEXTURE_SRGB_DECODE_EXT";
#endif
#ifdef GL_DECODE_EXT
	if ( en == GL_DECODE_EXT ) return "GL_DECODE_EXT";
#endif
#ifdef GL_SKIP_DECODE_EXT
	if ( en == GL_SKIP_DECODE_EXT ) return "GL_SKIP_DECODE_EXT";
#endif
#ifdef GL_RGB9_E5_EXT
	if ( en == GL_RGB9_E5_EXT ) return "GL_RGB9_E5_EXT";
#endif
#ifdef GL_UNSIGNED_INT_5_9_9_9_REV_EXT
	if ( en == GL_UNSIGNED_INT_5_9_9_9_REV_EXT ) return "GL_UNSIGNED_INT_5_9_9_9_REV_EXT";
#endif
#ifdef GL_TEXTURE_SHARED_SIZE_EXT
	if ( en == GL_TEXTURE_SHARED_SIZE_EXT ) return "GL_TEXTURE_SHARED_SIZE_EXT";
#endif
#ifdef GL_RED_SNORM
	if ( en == GL_RED_SNORM ) return "GL_RED_SNORM";
#endif
#ifdef GL_RG_SNORM
	if ( en == GL_RG_SNORM ) return "GL_RG_SNORM";
#endif
#ifdef GL_RGB_SNORM
	if ( en == GL_RGB_SNORM ) return "GL_RGB_SNORM";
#endif
#ifdef GL_RGBA_SNORM
	if ( en == GL_RGBA_SNORM ) return "GL_RGBA_SNORM";
#endif
#ifdef GL_R8_SNORM
	if ( en == GL_R8_SNORM ) return "GL_R8_SNORM";
#endif
#ifdef GL_RG8_SNORM
	if ( en == GL_RG8_SNORM ) return "GL_RG8_SNORM";
#endif
#ifdef GL_RGB8_SNORM
	if ( en == GL_RGB8_SNORM ) return "GL_RGB8_SNORM";
#endif
#ifdef GL_RGBA8_SNORM
	if ( en == GL_RGBA8_SNORM ) return "GL_RGBA8_SNORM";
#endif
#ifdef GL_R16_SNORM
	if ( en == GL_R16_SNORM ) return "GL_R16_SNORM";
#endif
#ifdef GL_RG16_SNORM
	if ( en == GL_RG16_SNORM ) return "GL_RG16_SNORM";
#endif
#ifdef GL_RGB16_SNORM
	if ( en == GL_RGB16_SNORM ) return "GL_RGB16_SNORM";
#endif
#ifdef GL_RGBA16_SNORM
	if ( en == GL_RGBA16_SNORM ) return "GL_RGBA16_SNORM";
#endif
#ifdef GL_SIGNED_NORMALIZED
	if ( en == GL_SIGNED_NORMALIZED ) return "GL_SIGNED_NORMALIZED";
#endif
#ifdef GL_ALPHA_SNORM
	if ( en == GL_ALPHA_SNORM ) return "GL_ALPHA_SNORM";
#endif
#ifdef GL_LUMINANCE_SNORM
	if ( en == GL_LUMINANCE_SNORM ) return "GL_LUMINANCE_SNORM";
#endif
#ifdef GL_LUMINANCE_ALPHA_SNORM
	if ( en == GL_LUMINANCE_ALPHA_SNORM ) return "GL_LUMINANCE_ALPHA_SNORM";
#endif
#ifdef GL_INTENSITY_SNORM
	if ( en == GL_INTENSITY_SNORM ) return "GL_INTENSITY_SNORM";
#endif
#ifdef GL_ALPHA8_SNORM
	if ( en == GL_ALPHA8_SNORM ) return "GL_ALPHA8_SNORM";
#endif
#ifdef GL_LUMINANCE8_SNORM
	if ( en == GL_LUMINANCE8_SNORM ) return "GL_LUMINANCE8_SNORM";
#endif
#ifdef GL_LUMINANCE8_ALPHA8_SNORM
	if ( en == GL_LUMINANCE8_ALPHA8_SNORM ) return "GL_LUMINANCE8_ALPHA8_SNORM";
#endif
#ifdef GL_INTENSITY8_SNORM
	if ( en == GL_INTENSITY8_SNORM ) return "GL_INTENSITY8_SNORM";
#endif
#ifdef GL_ALPHA16_SNORM
	if ( en == GL_ALPHA16_SNORM ) return "GL_ALPHA16_SNORM";
#endif
#ifdef GL_LUMINANCE16_SNORM
	if ( en == GL_LUMINANCE16_SNORM ) return "GL_LUMINANCE16_SNORM";
#endif
#ifdef GL_LUMINANCE16_ALPHA16_SNORM
	if ( en == GL_LUMINANCE16_ALPHA16_SNORM ) return "GL_LUMINANCE16_ALPHA16_SNORM";
#endif
#ifdef GL_INTENSITY16_SNORM
	if ( en == GL_INTENSITY16_SNORM ) return "GL_INTENSITY16_SNORM";
#endif
#ifdef GL_TEXTURE_SWIZZLE_R_EXT
	if ( en == GL_TEXTURE_SWIZZLE_R_EXT ) return "GL_TEXTURE_SWIZZLE_R_EXT";
#endif
#ifdef GL_TEXTURE_SWIZZLE_G_EXT
	if ( en == GL_TEXTURE_SWIZZLE_G_EXT ) return "GL_TEXTURE_SWIZZLE_G_EXT";
#endif
#ifdef GL_TEXTURE_SWIZZLE_B_EXT
	if ( en == GL_TEXTURE_SWIZZLE_B_EXT ) return "GL_TEXTURE_SWIZZLE_B_EXT";
#endif
#ifdef GL_TEXTURE_SWIZZLE_A_EXT
	if ( en == GL_TEXTURE_SWIZZLE_A_EXT ) return "GL_TEXTURE_SWIZZLE_A_EXT";
#endif
#ifdef GL_TEXTURE_SWIZZLE_RGBA_EXT
	if ( en == GL_TEXTURE_SWIZZLE_RGBA_EXT ) return "GL_TEXTURE_SWIZZLE_RGBA_EXT";
#endif
#ifdef GL_TIME_ELAPSED_EXT
	if ( en == GL_TIME_ELAPSED_EXT ) return "GL_TIME_ELAPSED_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT ) return "GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT ) return "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS_EXT ) return "GL_TRANSFORM_FEEDBACK_VARYINGS_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT ) return "GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT ) return "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT";
#endif
#ifdef GL_PRIMITIVES_GENERATED_EXT
	if ( en == GL_PRIMITIVES_GENERATED_EXT ) return "GL_PRIMITIVES_GENERATED_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT ) return "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT";
#endif
#ifdef GL_RASTERIZER_DISCARD_EXT
	if ( en == GL_RASTERIZER_DISCARD_EXT ) return "GL_RASTERIZER_DISCARD_EXT";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT ) return "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT";
#endif
#ifdef GL_INTERLEAVED_ATTRIBS_EXT
	if ( en == GL_INTERLEAVED_ATTRIBS_EXT ) return "GL_INTERLEAVED_ATTRIBS_EXT";
#endif
#ifdef GL_SEPARATE_ATTRIBS_EXT
	if ( en == GL_SEPARATE_ATTRIBS_EXT ) return "GL_SEPARATE_ATTRIBS_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_EXT ) return "GL_TRANSFORM_FEEDBACK_BUFFER_EXT";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT ) return "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT";
#endif
#ifdef GL_DOUBLE_EXT
	if ( en == GL_DOUBLE_EXT ) return "GL_DOUBLE_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_EXT
	if ( en == GL_VERTEX_ARRAY_EXT ) return "GL_VERTEX_ARRAY_EXT";
#endif
#ifdef GL_NORMAL_ARRAY_EXT
	if ( en == GL_NORMAL_ARRAY_EXT ) return "GL_NORMAL_ARRAY_EXT";
#endif
#ifdef GL_COLOR_ARRAY_EXT
	if ( en == GL_COLOR_ARRAY_EXT ) return "GL_COLOR_ARRAY_EXT";
#endif
#ifdef GL_INDEX_ARRAY_EXT
	if ( en == GL_INDEX_ARRAY_EXT ) return "GL_INDEX_ARRAY_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_EXT ) return "GL_TEXTURE_COORD_ARRAY_EXT";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_EXT
	if ( en == GL_EDGE_FLAG_ARRAY_EXT ) return "GL_EDGE_FLAG_ARRAY_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_SIZE_EXT
	if ( en == GL_VERTEX_ARRAY_SIZE_EXT ) return "GL_VERTEX_ARRAY_SIZE_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_TYPE_EXT
	if ( en == GL_VERTEX_ARRAY_TYPE_EXT ) return "GL_VERTEX_ARRAY_TYPE_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_STRIDE_EXT
	if ( en == GL_VERTEX_ARRAY_STRIDE_EXT ) return "GL_VERTEX_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_COUNT_EXT
	if ( en == GL_VERTEX_ARRAY_COUNT_EXT ) return "GL_VERTEX_ARRAY_COUNT_EXT";
#endif
#ifdef GL_NORMAL_ARRAY_TYPE_EXT
	if ( en == GL_NORMAL_ARRAY_TYPE_EXT ) return "GL_NORMAL_ARRAY_TYPE_EXT";
#endif
#ifdef GL_NORMAL_ARRAY_STRIDE_EXT
	if ( en == GL_NORMAL_ARRAY_STRIDE_EXT ) return "GL_NORMAL_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_NORMAL_ARRAY_COUNT_EXT
	if ( en == GL_NORMAL_ARRAY_COUNT_EXT ) return "GL_NORMAL_ARRAY_COUNT_EXT";
#endif
#ifdef GL_COLOR_ARRAY_SIZE_EXT
	if ( en == GL_COLOR_ARRAY_SIZE_EXT ) return "GL_COLOR_ARRAY_SIZE_EXT";
#endif
#ifdef GL_COLOR_ARRAY_TYPE_EXT
	if ( en == GL_COLOR_ARRAY_TYPE_EXT ) return "GL_COLOR_ARRAY_TYPE_EXT";
#endif
#ifdef GL_COLOR_ARRAY_STRIDE_EXT
	if ( en == GL_COLOR_ARRAY_STRIDE_EXT ) return "GL_COLOR_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_COLOR_ARRAY_COUNT_EXT
	if ( en == GL_COLOR_ARRAY_COUNT_EXT ) return "GL_COLOR_ARRAY_COUNT_EXT";
#endif
#ifdef GL_INDEX_ARRAY_TYPE_EXT
	if ( en == GL_INDEX_ARRAY_TYPE_EXT ) return "GL_INDEX_ARRAY_TYPE_EXT";
#endif
#ifdef GL_INDEX_ARRAY_STRIDE_EXT
	if ( en == GL_INDEX_ARRAY_STRIDE_EXT ) return "GL_INDEX_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_INDEX_ARRAY_COUNT_EXT
	if ( en == GL_INDEX_ARRAY_COUNT_EXT ) return "GL_INDEX_ARRAY_COUNT_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_SIZE_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_SIZE_EXT ) return "GL_TEXTURE_COORD_ARRAY_SIZE_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_TYPE_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_TYPE_EXT ) return "GL_TEXTURE_COORD_ARRAY_TYPE_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_STRIDE_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_STRIDE_EXT ) return "GL_TEXTURE_COORD_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_COUNT_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_COUNT_EXT ) return "GL_TEXTURE_COORD_ARRAY_COUNT_EXT";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_STRIDE_EXT
	if ( en == GL_EDGE_FLAG_ARRAY_STRIDE_EXT ) return "GL_EDGE_FLAG_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_COUNT_EXT
	if ( en == GL_EDGE_FLAG_ARRAY_COUNT_EXT ) return "GL_EDGE_FLAG_ARRAY_COUNT_EXT";
#endif
#ifdef GL_VERTEX_ARRAY_POINTER_EXT
	if ( en == GL_VERTEX_ARRAY_POINTER_EXT ) return "GL_VERTEX_ARRAY_POINTER_EXT";
#endif
#ifdef GL_NORMAL_ARRAY_POINTER_EXT
	if ( en == GL_NORMAL_ARRAY_POINTER_EXT ) return "GL_NORMAL_ARRAY_POINTER_EXT";
#endif
#ifdef GL_COLOR_ARRAY_POINTER_EXT
	if ( en == GL_COLOR_ARRAY_POINTER_EXT ) return "GL_COLOR_ARRAY_POINTER_EXT";
#endif
#ifdef GL_INDEX_ARRAY_POINTER_EXT
	if ( en == GL_INDEX_ARRAY_POINTER_EXT ) return "GL_INDEX_ARRAY_POINTER_EXT";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_POINTER_EXT
	if ( en == GL_TEXTURE_COORD_ARRAY_POINTER_EXT ) return "GL_TEXTURE_COORD_ARRAY_POINTER_EXT";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_POINTER_EXT
	if ( en == GL_EDGE_FLAG_ARRAY_POINTER_EXT ) return "GL_EDGE_FLAG_ARRAY_POINTER_EXT";
#endif
#ifdef GL_BGRA
	if ( en == GL_BGRA ) return "GL_BGRA";
#endif
#ifdef GL_DOUBLE_MAT2_EXT
	if ( en == GL_DOUBLE_MAT2_EXT ) return "GL_DOUBLE_MAT2_EXT";
#endif
#ifdef GL_DOUBLE_MAT3_EXT
	if ( en == GL_DOUBLE_MAT3_EXT ) return "GL_DOUBLE_MAT3_EXT";
#endif
#ifdef GL_DOUBLE_MAT4_EXT
	if ( en == GL_DOUBLE_MAT4_EXT ) return "GL_DOUBLE_MAT4_EXT";
#endif
#ifdef GL_DOUBLE_MAT2x3_EXT
	if ( en == GL_DOUBLE_MAT2x3_EXT ) return "GL_DOUBLE_MAT2x3_EXT";
#endif
#ifdef GL_DOUBLE_MAT2x4_EXT
	if ( en == GL_DOUBLE_MAT2x4_EXT ) return "GL_DOUBLE_MAT2x4_EXT";
#endif
#ifdef GL_DOUBLE_MAT3x2_EXT
	if ( en == GL_DOUBLE_MAT3x2_EXT ) return "GL_DOUBLE_MAT3x2_EXT";
#endif
#ifdef GL_DOUBLE_MAT3x4_EXT
	if ( en == GL_DOUBLE_MAT3x4_EXT ) return "GL_DOUBLE_MAT3x4_EXT";
#endif
#ifdef GL_DOUBLE_MAT4x2_EXT
	if ( en == GL_DOUBLE_MAT4x2_EXT ) return "GL_DOUBLE_MAT4x2_EXT";
#endif
#ifdef GL_DOUBLE_MAT4x3_EXT
	if ( en == GL_DOUBLE_MAT4x3_EXT ) return "GL_DOUBLE_MAT4x3_EXT";
#endif
#ifdef GL_DOUBLE_VEC2_EXT
	if ( en == GL_DOUBLE_VEC2_EXT ) return "GL_DOUBLE_VEC2_EXT";
#endif
#ifdef GL_DOUBLE_VEC3_EXT
	if ( en == GL_DOUBLE_VEC3_EXT ) return "GL_DOUBLE_VEC3_EXT";
#endif
#ifdef GL_DOUBLE_VEC4_EXT
	if ( en == GL_DOUBLE_VEC4_EXT ) return "GL_DOUBLE_VEC4_EXT";
#endif
#ifdef GL_VERTEX_SHADER_EXT
	if ( en == GL_VERTEX_SHADER_EXT ) return "GL_VERTEX_SHADER_EXT";
#endif
#ifdef GL_VERTEX_SHADER_BINDING_EXT
	if ( en == GL_VERTEX_SHADER_BINDING_EXT ) return "GL_VERTEX_SHADER_BINDING_EXT";
#endif
#ifdef GL_OP_INDEX_EXT
	if ( en == GL_OP_INDEX_EXT ) return "GL_OP_INDEX_EXT";
#endif
#ifdef GL_OP_NEGATE_EXT
	if ( en == GL_OP_NEGATE_EXT ) return "GL_OP_NEGATE_EXT";
#endif
#ifdef GL_OP_DOT3_EXT
	if ( en == GL_OP_DOT3_EXT ) return "GL_OP_DOT3_EXT";
#endif
#ifdef GL_OP_DOT4_EXT
	if ( en == GL_OP_DOT4_EXT ) return "GL_OP_DOT4_EXT";
#endif
#ifdef GL_OP_MUL_EXT
	if ( en == GL_OP_MUL_EXT ) return "GL_OP_MUL_EXT";
#endif
#ifdef GL_OP_ADD_EXT
	if ( en == GL_OP_ADD_EXT ) return "GL_OP_ADD_EXT";
#endif
#ifdef GL_OP_MADD_EXT
	if ( en == GL_OP_MADD_EXT ) return "GL_OP_MADD_EXT";
#endif
#ifdef GL_OP_FRAC_EXT
	if ( en == GL_OP_FRAC_EXT ) return "GL_OP_FRAC_EXT";
#endif
#ifdef GL_OP_MAX_EXT
	if ( en == GL_OP_MAX_EXT ) return "GL_OP_MAX_EXT";
#endif
#ifdef GL_OP_MIN_EXT
	if ( en == GL_OP_MIN_EXT ) return "GL_OP_MIN_EXT";
#endif
#ifdef GL_OP_SET_GE_EXT
	if ( en == GL_OP_SET_GE_EXT ) return "GL_OP_SET_GE_EXT";
#endif
#ifdef GL_OP_SET_LT_EXT
	if ( en == GL_OP_SET_LT_EXT ) return "GL_OP_SET_LT_EXT";
#endif
#ifdef GL_OP_CLAMP_EXT
	if ( en == GL_OP_CLAMP_EXT ) return "GL_OP_CLAMP_EXT";
#endif
#ifdef GL_OP_FLOOR_EXT
	if ( en == GL_OP_FLOOR_EXT ) return "GL_OP_FLOOR_EXT";
#endif
#ifdef GL_OP_ROUND_EXT
	if ( en == GL_OP_ROUND_EXT ) return "GL_OP_ROUND_EXT";
#endif
#ifdef GL_OP_EXP_BASE_2_EXT
	if ( en == GL_OP_EXP_BASE_2_EXT ) return "GL_OP_EXP_BASE_2_EXT";
#endif
#ifdef GL_OP_LOG_BASE_2_EXT
	if ( en == GL_OP_LOG_BASE_2_EXT ) return "GL_OP_LOG_BASE_2_EXT";
#endif
#ifdef GL_OP_POWER_EXT
	if ( en == GL_OP_POWER_EXT ) return "GL_OP_POWER_EXT";
#endif
#ifdef GL_OP_RECIP_EXT
	if ( en == GL_OP_RECIP_EXT ) return "GL_OP_RECIP_EXT";
#endif
#ifdef GL_OP_RECIP_SQRT_EXT
	if ( en == GL_OP_RECIP_SQRT_EXT ) return "GL_OP_RECIP_SQRT_EXT";
#endif
#ifdef GL_OP_SUB_EXT
	if ( en == GL_OP_SUB_EXT ) return "GL_OP_SUB_EXT";
#endif
#ifdef GL_OP_CROSS_PRODUCT_EXT
	if ( en == GL_OP_CROSS_PRODUCT_EXT ) return "GL_OP_CROSS_PRODUCT_EXT";
#endif
#ifdef GL_OP_MULTIPLY_MATRIX_EXT
	if ( en == GL_OP_MULTIPLY_MATRIX_EXT ) return "GL_OP_MULTIPLY_MATRIX_EXT";
#endif
#ifdef GL_OP_MOV_EXT
	if ( en == GL_OP_MOV_EXT ) return "GL_OP_MOV_EXT";
#endif
#ifdef GL_OUTPUT_VERTEX_EXT
	if ( en == GL_OUTPUT_VERTEX_EXT ) return "GL_OUTPUT_VERTEX_EXT";
#endif
#ifdef GL_OUTPUT_COLOR0_EXT
	if ( en == GL_OUTPUT_COLOR0_EXT ) return "GL_OUTPUT_COLOR0_EXT";
#endif
#ifdef GL_OUTPUT_COLOR1_EXT
	if ( en == GL_OUTPUT_COLOR1_EXT ) return "GL_OUTPUT_COLOR1_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD0_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD0_EXT ) return "GL_OUTPUT_TEXTURE_COORD0_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD1_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD1_EXT ) return "GL_OUTPUT_TEXTURE_COORD1_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD2_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD2_EXT ) return "GL_OUTPUT_TEXTURE_COORD2_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD3_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD3_EXT ) return "GL_OUTPUT_TEXTURE_COORD3_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD4_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD4_EXT ) return "GL_OUTPUT_TEXTURE_COORD4_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD5_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD5_EXT ) return "GL_OUTPUT_TEXTURE_COORD5_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD6_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD6_EXT ) return "GL_OUTPUT_TEXTURE_COORD6_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD7_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD7_EXT ) return "GL_OUTPUT_TEXTURE_COORD7_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD8_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD8_EXT ) return "GL_OUTPUT_TEXTURE_COORD8_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD9_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD9_EXT ) return "GL_OUTPUT_TEXTURE_COORD9_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD10_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD10_EXT ) return "GL_OUTPUT_TEXTURE_COORD10_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD11_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD11_EXT ) return "GL_OUTPUT_TEXTURE_COORD11_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD12_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD12_EXT ) return "GL_OUTPUT_TEXTURE_COORD12_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD13_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD13_EXT ) return "GL_OUTPUT_TEXTURE_COORD13_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD14_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD14_EXT ) return "GL_OUTPUT_TEXTURE_COORD14_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD15_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD15_EXT ) return "GL_OUTPUT_TEXTURE_COORD15_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD16_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD16_EXT ) return "GL_OUTPUT_TEXTURE_COORD16_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD17_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD17_EXT ) return "GL_OUTPUT_TEXTURE_COORD17_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD18_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD18_EXT ) return "GL_OUTPUT_TEXTURE_COORD18_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD19_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD19_EXT ) return "GL_OUTPUT_TEXTURE_COORD19_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD20_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD20_EXT ) return "GL_OUTPUT_TEXTURE_COORD20_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD21_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD21_EXT ) return "GL_OUTPUT_TEXTURE_COORD21_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD22_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD22_EXT ) return "GL_OUTPUT_TEXTURE_COORD22_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD23_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD23_EXT ) return "GL_OUTPUT_TEXTURE_COORD23_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD24_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD24_EXT ) return "GL_OUTPUT_TEXTURE_COORD24_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD25_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD25_EXT ) return "GL_OUTPUT_TEXTURE_COORD25_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD26_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD26_EXT ) return "GL_OUTPUT_TEXTURE_COORD26_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD27_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD27_EXT ) return "GL_OUTPUT_TEXTURE_COORD27_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD28_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD28_EXT ) return "GL_OUTPUT_TEXTURE_COORD28_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD29_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD29_EXT ) return "GL_OUTPUT_TEXTURE_COORD29_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD30_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD30_EXT ) return "GL_OUTPUT_TEXTURE_COORD30_EXT";
#endif
#ifdef GL_OUTPUT_TEXTURE_COORD31_EXT
	if ( en == GL_OUTPUT_TEXTURE_COORD31_EXT ) return "GL_OUTPUT_TEXTURE_COORD31_EXT";
#endif
#ifdef GL_OUTPUT_FOG_EXT
	if ( en == GL_OUTPUT_FOG_EXT ) return "GL_OUTPUT_FOG_EXT";
#endif
#ifdef GL_SCALAR_EXT
	if ( en == GL_SCALAR_EXT ) return "GL_SCALAR_EXT";
#endif
#ifdef GL_VECTOR_EXT
	if ( en == GL_VECTOR_EXT ) return "GL_VECTOR_EXT";
#endif
#ifdef GL_MATRIX_EXT
	if ( en == GL_MATRIX_EXT ) return "GL_MATRIX_EXT";
#endif
#ifdef GL_VARIANT_EXT
	if ( en == GL_VARIANT_EXT ) return "GL_VARIANT_EXT";
#endif
#ifdef GL_INVARIANT_EXT
	if ( en == GL_INVARIANT_EXT ) return "GL_INVARIANT_EXT";
#endif
#ifdef GL_LOCAL_CONSTANT_EXT
	if ( en == GL_LOCAL_CONSTANT_EXT ) return "GL_LOCAL_CONSTANT_EXT";
#endif
#ifdef GL_LOCAL_EXT
	if ( en == GL_LOCAL_EXT ) return "GL_LOCAL_EXT";
#endif
#ifdef GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT
	if ( en == GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT ) return "GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT";
#endif
#ifdef GL_MAX_VERTEX_SHADER_VARIANTS_EXT
	if ( en == GL_MAX_VERTEX_SHADER_VARIANTS_EXT ) return "GL_MAX_VERTEX_SHADER_VARIANTS_EXT";
#endif
#ifdef GL_MAX_VERTEX_SHADER_INVARIANTS_EXT
	if ( en == GL_MAX_VERTEX_SHADER_INVARIANTS_EXT ) return "GL_MAX_VERTEX_SHADER_INVARIANTS_EXT";
#endif
#ifdef GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
	if ( en == GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) return "GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
#endif
#ifdef GL_MAX_VERTEX_SHADER_LOCALS_EXT
	if ( en == GL_MAX_VERTEX_SHADER_LOCALS_EXT ) return "GL_MAX_VERTEX_SHADER_LOCALS_EXT";
#endif
#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT
	if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT ) return "GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT";
#endif
#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT
	if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT ) return "GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT";
#endif
#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT
	if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT ) return "GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT";
#endif
#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
	if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) return "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
#endif
#ifdef GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT
	if ( en == GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT ) return "GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_INSTRUCTIONS_EXT
	if ( en == GL_VERTEX_SHADER_INSTRUCTIONS_EXT ) return "GL_VERTEX_SHADER_INSTRUCTIONS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_VARIANTS_EXT
	if ( en == GL_VERTEX_SHADER_VARIANTS_EXT ) return "GL_VERTEX_SHADER_VARIANTS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_INVARIANTS_EXT
	if ( en == GL_VERTEX_SHADER_INVARIANTS_EXT ) return "GL_VERTEX_SHADER_INVARIANTS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT
	if ( en == GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT ) return "GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_LOCALS_EXT
	if ( en == GL_VERTEX_SHADER_LOCALS_EXT ) return "GL_VERTEX_SHADER_LOCALS_EXT";
#endif
#ifdef GL_VERTEX_SHADER_OPTIMIZED_EXT
	if ( en == GL_VERTEX_SHADER_OPTIMIZED_EXT ) return "GL_VERTEX_SHADER_OPTIMIZED_EXT";
#endif
#ifdef GL_X_EXT
	if ( en == GL_X_EXT ) return "GL_X_EXT";
#endif
#ifdef GL_Y_EXT
	if ( en == GL_Y_EXT ) return "GL_Y_EXT";
#endif
#ifdef GL_Z_EXT
	if ( en == GL_Z_EXT ) return "GL_Z_EXT";
#endif
#ifdef GL_W_EXT
	if ( en == GL_W_EXT ) return "GL_W_EXT";
#endif
#ifdef GL_NEGATIVE_X_EXT
	if ( en == GL_NEGATIVE_X_EXT ) return "GL_NEGATIVE_X_EXT";
#endif
#ifdef GL_NEGATIVE_Y_EXT
	if ( en == GL_NEGATIVE_Y_EXT ) return "GL_NEGATIVE_Y_EXT";
#endif
#ifdef GL_NEGATIVE_Z_EXT
	if ( en == GL_NEGATIVE_Z_EXT ) return "GL_NEGATIVE_Z_EXT";
#endif
#ifdef GL_NEGATIVE_W_EXT
	if ( en == GL_NEGATIVE_W_EXT ) return "GL_NEGATIVE_W_EXT";
#endif
#ifdef GL_ZERO_EXT
	if ( en == GL_ZERO_EXT ) return "GL_ZERO_EXT";
#endif
#ifdef GL_ONE_EXT
	if ( en == GL_ONE_EXT ) return "GL_ONE_EXT";
#endif
#ifdef GL_NEGATIVE_ONE_EXT
	if ( en == GL_NEGATIVE_ONE_EXT ) return "GL_NEGATIVE_ONE_EXT";
#endif
#ifdef GL_NORMALIZED_RANGE_EXT
	if ( en == GL_NORMALIZED_RANGE_EXT ) return "GL_NORMALIZED_RANGE_EXT";
#endif
#ifdef GL_FULL_RANGE_EXT
	if ( en == GL_FULL_RANGE_EXT ) return "GL_FULL_RANGE_EXT";
#endif
#ifdef GL_CURRENT_VERTEX_EXT
	if ( en == GL_CURRENT_VERTEX_EXT ) return "GL_CURRENT_VERTEX_EXT";
#endif
#ifdef GL_MVP_MATRIX_EXT
	if ( en == GL_MVP_MATRIX_EXT ) return "GL_MVP_MATRIX_EXT";
#endif
#ifdef GL_VARIANT_VALUE_EXT
	if ( en == GL_VARIANT_VALUE_EXT ) return "GL_VARIANT_VALUE_EXT";
#endif
#ifdef GL_VARIANT_DATATYPE_EXT
	if ( en == GL_VARIANT_DATATYPE_EXT ) return "GL_VARIANT_DATATYPE_EXT";
#endif
#ifdef GL_VARIANT_ARRAY_STRIDE_EXT
	if ( en == GL_VARIANT_ARRAY_STRIDE_EXT ) return "GL_VARIANT_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_VARIANT_ARRAY_TYPE_EXT
	if ( en == GL_VARIANT_ARRAY_TYPE_EXT ) return "GL_VARIANT_ARRAY_TYPE_EXT";
#endif
#ifdef GL_VARIANT_ARRAY_EXT
	if ( en == GL_VARIANT_ARRAY_EXT ) return "GL_VARIANT_ARRAY_EXT";
#endif
#ifdef GL_VARIANT_ARRAY_POINTER_EXT
	if ( en == GL_VARIANT_ARRAY_POINTER_EXT ) return "GL_VARIANT_ARRAY_POINTER_EXT";
#endif
#ifdef GL_INVARIANT_VALUE_EXT
	if ( en == GL_INVARIANT_VALUE_EXT ) return "GL_INVARIANT_VALUE_EXT";
#endif
#ifdef GL_INVARIANT_DATATYPE_EXT
	if ( en == GL_INVARIANT_DATATYPE_EXT ) return "GL_INVARIANT_DATATYPE_EXT";
#endif
#ifdef GL_LOCAL_CONSTANT_VALUE_EXT
	if ( en == GL_LOCAL_CONSTANT_VALUE_EXT ) return "GL_LOCAL_CONSTANT_VALUE_EXT";
#endif
#ifdef GL_LOCAL_CONSTANT_DATATYPE_EXT
	if ( en == GL_LOCAL_CONSTANT_DATATYPE_EXT ) return "GL_LOCAL_CONSTANT_DATATYPE_EXT";
#endif
#ifdef GL_MODELVIEW0_STACK_DEPTH_EXT
	if ( en == GL_MODELVIEW0_STACK_DEPTH_EXT ) return "GL_MODELVIEW0_STACK_DEPTH_EXT";
#endif
#ifdef GL_MODELVIEW0_MATRIX_EXT
	if ( en == GL_MODELVIEW0_MATRIX_EXT ) return "GL_MODELVIEW0_MATRIX_EXT";
#endif
#ifdef GL_MODELVIEW0_EXT
	if ( en == GL_MODELVIEW0_EXT ) return "GL_MODELVIEW0_EXT";
#endif
#ifdef GL_MODELVIEW1_STACK_DEPTH_EXT
	if ( en == GL_MODELVIEW1_STACK_DEPTH_EXT ) return "GL_MODELVIEW1_STACK_DEPTH_EXT";
#endif
#ifdef GL_MODELVIEW1_MATRIX_EXT
	if ( en == GL_MODELVIEW1_MATRIX_EXT ) return "GL_MODELVIEW1_MATRIX_EXT";
#endif
#ifdef GL_VERTEX_WEIGHTING_EXT
	if ( en == GL_VERTEX_WEIGHTING_EXT ) return "GL_VERTEX_WEIGHTING_EXT";
#endif
#ifdef GL_MODELVIEW1_EXT
	if ( en == GL_MODELVIEW1_EXT ) return "GL_MODELVIEW1_EXT";
#endif
#ifdef GL_CURRENT_VERTEX_WEIGHT_EXT
	if ( en == GL_CURRENT_VERTEX_WEIGHT_EXT ) return "GL_CURRENT_VERTEX_WEIGHT_EXT";
#endif
#ifdef GL_VERTEX_WEIGHT_ARRAY_EXT
	if ( en == GL_VERTEX_WEIGHT_ARRAY_EXT ) return "GL_VERTEX_WEIGHT_ARRAY_EXT";
#endif
#ifdef GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT
	if ( en == GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT ) return "GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT";
#endif
#ifdef GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT
	if ( en == GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT ) return "GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT";
#endif
#ifdef GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT
	if ( en == GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT ) return "GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT";
#endif
#ifdef GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT
	if ( en == GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT ) return "GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT";
#endif
#ifdef GL_SYNC_X11_FENCE_EXT
	if ( en == GL_SYNC_X11_FENCE_EXT ) return "GL_SYNC_X11_FENCE_EXT";
#endif
#ifdef GL_CULL_VERTEX_IBM
	if ( en == GL_CULL_VERTEX_IBM ) return "GL_CULL_VERTEX_IBM";
#endif
#ifdef GL_RASTER_POSITION_UNCLIPPED_IBM
	if ( en == GL_RASTER_POSITION_UNCLIPPED_IBM ) return "GL_RASTER_POSITION_UNCLIPPED_IBM";
#endif
#ifdef GL_ALL_STATIC_DATA_IBM
	if ( en == GL_ALL_STATIC_DATA_IBM ) return "GL_ALL_STATIC_DATA_IBM";
#endif
#ifdef GL_STATIC_VERTEX_ARRAY_IBM
	if ( en == GL_STATIC_VERTEX_ARRAY_IBM ) return "GL_STATIC_VERTEX_ARRAY_IBM";
#endif
#ifdef GL_MIRRORED_REPEAT_IBM
	if ( en == GL_MIRRORED_REPEAT_IBM ) return "GL_MIRRORED_REPEAT_IBM";
#endif
#ifdef GL_VERTEX_ARRAY_LIST_IBM
	if ( en == GL_VERTEX_ARRAY_LIST_IBM ) return "GL_VERTEX_ARRAY_LIST_IBM";
#endif
#ifdef GL_NORMAL_ARRAY_LIST_IBM
	if ( en == GL_NORMAL_ARRAY_LIST_IBM ) return "GL_NORMAL_ARRAY_LIST_IBM";
#endif
#ifdef GL_COLOR_ARRAY_LIST_IBM
	if ( en == GL_COLOR_ARRAY_LIST_IBM ) return "GL_COLOR_ARRAY_LIST_IBM";
#endif
#ifdef GL_INDEX_ARRAY_LIST_IBM
	if ( en == GL_INDEX_ARRAY_LIST_IBM ) return "GL_INDEX_ARRAY_LIST_IBM";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_LIST_IBM
	if ( en == GL_TEXTURE_COORD_ARRAY_LIST_IBM ) return "GL_TEXTURE_COORD_ARRAY_LIST_IBM";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_LIST_IBM
	if ( en == GL_EDGE_FLAG_ARRAY_LIST_IBM ) return "GL_EDGE_FLAG_ARRAY_LIST_IBM";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_LIST_IBM
	if ( en == GL_FOG_COORDINATE_ARRAY_LIST_IBM ) return "GL_FOG_COORDINATE_ARRAY_LIST_IBM";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_LIST_IBM
	if ( en == GL_SECONDARY_COLOR_ARRAY_LIST_IBM ) return "GL_SECONDARY_COLOR_ARRAY_LIST_IBM";
#endif
#ifdef GL_VERTEX_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_VERTEX_ARRAY_LIST_STRIDE_IBM ) return "GL_VERTEX_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_NORMAL_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_NORMAL_ARRAY_LIST_STRIDE_IBM ) return "GL_NORMAL_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_COLOR_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_COLOR_ARRAY_LIST_STRIDE_IBM ) return "GL_COLOR_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_INDEX_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_INDEX_ARRAY_LIST_STRIDE_IBM ) return "GL_INDEX_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM ) return "GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM ) return "GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM ) return "GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM
	if ( en == GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM ) return "GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM";
#endif
#ifdef GL_RED_MIN_CLAMP_INGR
	if ( en == GL_RED_MIN_CLAMP_INGR ) return "GL_RED_MIN_CLAMP_INGR";
#endif
#ifdef GL_GREEN_MIN_CLAMP_INGR
	if ( en == GL_GREEN_MIN_CLAMP_INGR ) return "GL_GREEN_MIN_CLAMP_INGR";
#endif
#ifdef GL_BLUE_MIN_CLAMP_INGR
	if ( en == GL_BLUE_MIN_CLAMP_INGR ) return "GL_BLUE_MIN_CLAMP_INGR";
#endif
#ifdef GL_ALPHA_MIN_CLAMP_INGR
	if ( en == GL_ALPHA_MIN_CLAMP_INGR ) return "GL_ALPHA_MIN_CLAMP_INGR";
#endif
#ifdef GL_RED_MAX_CLAMP_INGR
	if ( en == GL_RED_MAX_CLAMP_INGR ) return "GL_RED_MAX_CLAMP_INGR";
#endif
#ifdef GL_GREEN_MAX_CLAMP_INGR
	if ( en == GL_GREEN_MAX_CLAMP_INGR ) return "GL_GREEN_MAX_CLAMP_INGR";
#endif
#ifdef GL_BLUE_MAX_CLAMP_INGR
	if ( en == GL_BLUE_MAX_CLAMP_INGR ) return "GL_BLUE_MAX_CLAMP_INGR";
#endif
#ifdef GL_ALPHA_MAX_CLAMP_INGR
	if ( en == GL_ALPHA_MAX_CLAMP_INGR ) return "GL_ALPHA_MAX_CLAMP_INGR";
#endif
#ifdef GL_INTERLACE_READ_INGR
	if ( en == GL_INTERLACE_READ_INGR ) return "GL_INTERLACE_READ_INGR";
#endif
#ifdef GL_LAYOUT_LINEAR_CPU_CACHED_INTEL
	if ( en == GL_LAYOUT_LINEAR_CPU_CACHED_INTEL ) return "GL_LAYOUT_LINEAR_CPU_CACHED_INTEL";
#endif
#ifdef GL_TEXTURE_MEMORY_LAYOUT_INTEL
	if ( en == GL_TEXTURE_MEMORY_LAYOUT_INTEL ) return "GL_TEXTURE_MEMORY_LAYOUT_INTEL";
#endif
#ifdef GL_PARALLEL_ARRAYS_INTEL
	if ( en == GL_PARALLEL_ARRAYS_INTEL ) return "GL_PARALLEL_ARRAYS_INTEL";
#endif
#ifdef GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL
	if ( en == GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL ) return "GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL";
#endif
#ifdef GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL
	if ( en == GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL ) return "GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL";
#endif
#ifdef GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL
	if ( en == GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL ) return "GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL
	if ( en == GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL ) return "GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL";
#endif
#ifdef GL_CONTEXT_FLAG_DEBUG_BIT
	if ( en == GL_CONTEXT_FLAG_DEBUG_BIT ) return "GL_CONTEXT_FLAG_DEBUG_BIT";
#endif
#ifdef GL_STACK_OVERFLOW
	if ( en == GL_STACK_OVERFLOW ) return "GL_STACK_OVERFLOW";
#endif
#ifdef GL_STACK_UNDERFLOW
	if ( en == GL_STACK_UNDERFLOW ) return "GL_STACK_UNDERFLOW";
#endif
#ifdef GL_DEBUG_OUTPUT_SYNCHRONOUS
	if ( en == GL_DEBUG_OUTPUT_SYNCHRONOUS ) return "GL_DEBUG_OUTPUT_SYNCHRONOUS";
#endif
#ifdef GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH
	if ( en == GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH ) return "GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH";
#endif
#ifdef GL_DEBUG_CALLBACK_FUNCTION
	if ( en == GL_DEBUG_CALLBACK_FUNCTION ) return "GL_DEBUG_CALLBACK_FUNCTION";
#endif
#ifdef GL_DEBUG_CALLBACK_USER_PARAM
	if ( en == GL_DEBUG_CALLBACK_USER_PARAM ) return "GL_DEBUG_CALLBACK_USER_PARAM";
#endif
#ifdef GL_DEBUG_SOURCE_API
	if ( en == GL_DEBUG_SOURCE_API ) return "GL_DEBUG_SOURCE_API";
#endif
#ifdef GL_DEBUG_SOURCE_WINDOW_SYSTEM
	if ( en == GL_DEBUG_SOURCE_WINDOW_SYSTEM ) return "GL_DEBUG_SOURCE_WINDOW_SYSTEM";
#endif
#ifdef GL_DEBUG_SOURCE_SHADER_COMPILER
	if ( en == GL_DEBUG_SOURCE_SHADER_COMPILER ) return "GL_DEBUG_SOURCE_SHADER_COMPILER";
#endif
#ifdef GL_DEBUG_SOURCE_THIRD_PARTY
	if ( en == GL_DEBUG_SOURCE_THIRD_PARTY ) return "GL_DEBUG_SOURCE_THIRD_PARTY";
#endif
#ifdef GL_DEBUG_SOURCE_APPLICATION
	if ( en == GL_DEBUG_SOURCE_APPLICATION ) return "GL_DEBUG_SOURCE_APPLICATION";
#endif
#ifdef GL_DEBUG_SOURCE_OTHER
	if ( en == GL_DEBUG_SOURCE_OTHER ) return "GL_DEBUG_SOURCE_OTHER";
#endif
#ifdef GL_DEBUG_TYPE_ERROR
	if ( en == GL_DEBUG_TYPE_ERROR ) return "GL_DEBUG_TYPE_ERROR";
#endif
#ifdef GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR
	if ( en == GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR ) return "GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR";
#endif
#ifdef GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR
	if ( en == GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR ) return "GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR";
#endif
#ifdef GL_DEBUG_TYPE_PORTABILITY
	if ( en == GL_DEBUG_TYPE_PORTABILITY ) return "GL_DEBUG_TYPE_PORTABILITY";
#endif
#ifdef GL_DEBUG_TYPE_PERFORMANCE
	if ( en == GL_DEBUG_TYPE_PERFORMANCE ) return "GL_DEBUG_TYPE_PERFORMANCE";
#endif
#ifdef GL_DEBUG_TYPE_OTHER
	if ( en == GL_DEBUG_TYPE_OTHER ) return "GL_DEBUG_TYPE_OTHER";
#endif
#ifdef GL_DEBUG_TYPE_MARKER
	if ( en == GL_DEBUG_TYPE_MARKER ) return "GL_DEBUG_TYPE_MARKER";
#endif
#ifdef GL_DEBUG_TYPE_PUSH_GROUP
	if ( en == GL_DEBUG_TYPE_PUSH_GROUP ) return "GL_DEBUG_TYPE_PUSH_GROUP";
#endif
#ifdef GL_DEBUG_TYPE_POP_GROUP
	if ( en == GL_DEBUG_TYPE_POP_GROUP ) return "GL_DEBUG_TYPE_POP_GROUP";
#endif
#ifdef GL_DEBUG_SEVERITY_NOTIFICATION
	if ( en == GL_DEBUG_SEVERITY_NOTIFICATION ) return "GL_DEBUG_SEVERITY_NOTIFICATION";
#endif
#ifdef GL_MAX_DEBUG_GROUP_STACK_DEPTH
	if ( en == GL_MAX_DEBUG_GROUP_STACK_DEPTH ) return "GL_MAX_DEBUG_GROUP_STACK_DEPTH";
#endif
#ifdef GL_DEBUG_GROUP_STACK_DEPTH
	if ( en == GL_DEBUG_GROUP_STACK_DEPTH ) return "GL_DEBUG_GROUP_STACK_DEPTH";
#endif
#ifdef GL_BUFFER
	if ( en == GL_BUFFER ) return "GL_BUFFER";
#endif
#ifdef GL_SHADER
	if ( en == GL_SHADER ) return "GL_SHADER";
#endif
#ifdef GL_PROGRAM
	if ( en == GL_PROGRAM ) return "GL_PROGRAM";
#endif
#ifdef GL_QUERY
	if ( en == GL_QUERY ) return "GL_QUERY";
#endif
#ifdef GL_PROGRAM_PIPELINE
	if ( en == GL_PROGRAM_PIPELINE ) return "GL_PROGRAM_PIPELINE";
#endif
#ifdef GL_SAMPLER
	if ( en == GL_SAMPLER ) return "GL_SAMPLER";
#endif
#ifdef GL_DISPLAY_LIST
	if ( en == GL_DISPLAY_LIST ) return "GL_DISPLAY_LIST";
#endif
#ifdef GL_MAX_LABEL_LENGTH
	if ( en == GL_MAX_LABEL_LENGTH ) return "GL_MAX_LABEL_LENGTH";
#endif
#ifdef GL_MAX_DEBUG_MESSAGE_LENGTH
	if ( en == GL_MAX_DEBUG_MESSAGE_LENGTH ) return "GL_MAX_DEBUG_MESSAGE_LENGTH";
#endif
#ifdef GL_MAX_DEBUG_LOGGED_MESSAGES
	if ( en == GL_MAX_DEBUG_LOGGED_MESSAGES ) return "GL_MAX_DEBUG_LOGGED_MESSAGES";
#endif
#ifdef GL_DEBUG_LOGGED_MESSAGES
	if ( en == GL_DEBUG_LOGGED_MESSAGES ) return "GL_DEBUG_LOGGED_MESSAGES";
#endif
#ifdef GL_DEBUG_SEVERITY_HIGH
	if ( en == GL_DEBUG_SEVERITY_HIGH ) return "GL_DEBUG_SEVERITY_HIGH";
#endif
#ifdef GL_DEBUG_SEVERITY_MEDIUM
	if ( en == GL_DEBUG_SEVERITY_MEDIUM ) return "GL_DEBUG_SEVERITY_MEDIUM";
#endif
#ifdef GL_DEBUG_SEVERITY_LOW
	if ( en == GL_DEBUG_SEVERITY_LOW ) return "GL_DEBUG_SEVERITY_LOW";
#endif
#ifdef GL_DEBUG_OUTPUT
	if ( en == GL_DEBUG_OUTPUT ) return "GL_DEBUG_OUTPUT";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_4x4_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_4x4_KHR ) return "GL_COMPRESSED_RGBA_ASTC_4x4_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_5x4_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_5x4_KHR ) return "GL_COMPRESSED_RGBA_ASTC_5x4_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_5x5_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_5x5_KHR ) return "GL_COMPRESSED_RGBA_ASTC_5x5_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_6x5_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_6x5_KHR ) return "GL_COMPRESSED_RGBA_ASTC_6x5_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_6x6_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_6x6_KHR ) return "GL_COMPRESSED_RGBA_ASTC_6x6_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_8x5_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_8x5_KHR ) return "GL_COMPRESSED_RGBA_ASTC_8x5_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_8x6_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_8x6_KHR ) return "GL_COMPRESSED_RGBA_ASTC_8x6_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_8x8_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_8x8_KHR ) return "GL_COMPRESSED_RGBA_ASTC_8x8_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_10x5_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_10x5_KHR ) return "GL_COMPRESSED_RGBA_ASTC_10x5_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_10x6_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_10x6_KHR ) return "GL_COMPRESSED_RGBA_ASTC_10x6_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_10x8_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_10x8_KHR ) return "GL_COMPRESSED_RGBA_ASTC_10x8_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_10x10_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_10x10_KHR ) return "GL_COMPRESSED_RGBA_ASTC_10x10_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_12x10_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_12x10_KHR ) return "GL_COMPRESSED_RGBA_ASTC_12x10_KHR";
#endif
#ifdef GL_COMPRESSED_RGBA_ASTC_12x12_KHR
	if ( en == GL_COMPRESSED_RGBA_ASTC_12x12_KHR ) return "GL_COMPRESSED_RGBA_ASTC_12x12_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR";
#endif
#ifdef GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR
	if ( en == GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR ) return "GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR";
#endif
#ifdef GL_KTX_FRONT_REGION
	if ( en == GL_KTX_FRONT_REGION ) return "GL_KTX_FRONT_REGION";
#endif
#ifdef GL_KTX_BACK_REGION
	if ( en == GL_KTX_BACK_REGION ) return "GL_KTX_BACK_REGION";
#endif
#ifdef GL_KTX_Z_REGION
	if ( en == GL_KTX_Z_REGION ) return "GL_KTX_Z_REGION";
#endif
#ifdef GL_KTX_STENCIL_REGION
	if ( en == GL_KTX_STENCIL_REGION ) return "GL_KTX_STENCIL_REGION";
#endif
#ifdef GL_TEXTURE_1D_STACK_MESAX
	if ( en == GL_TEXTURE_1D_STACK_MESAX ) return "GL_TEXTURE_1D_STACK_MESAX";
#endif
#ifdef GL_TEXTURE_2D_STACK_MESAX
	if ( en == GL_TEXTURE_2D_STACK_MESAX ) return "GL_TEXTURE_2D_STACK_MESAX";
#endif
#ifdef GL_PROXY_TEXTURE_1D_STACK_MESAX
	if ( en == GL_PROXY_TEXTURE_1D_STACK_MESAX ) return "GL_PROXY_TEXTURE_1D_STACK_MESAX";
#endif
#ifdef GL_PROXY_TEXTURE_2D_STACK_MESAX
	if ( en == GL_PROXY_TEXTURE_2D_STACK_MESAX ) return "GL_PROXY_TEXTURE_2D_STACK_MESAX";
#endif
#ifdef GL_TEXTURE_1D_STACK_BINDING_MESAX
	if ( en == GL_TEXTURE_1D_STACK_BINDING_MESAX ) return "GL_TEXTURE_1D_STACK_BINDING_MESAX";
#endif
#ifdef GL_TEXTURE_2D_STACK_BINDING_MESAX
	if ( en == GL_TEXTURE_2D_STACK_BINDING_MESAX ) return "GL_TEXTURE_2D_STACK_BINDING_MESAX";
#endif
#ifdef GL_PACK_INVERT_MESA
	if ( en == GL_PACK_INVERT_MESA ) return "GL_PACK_INVERT_MESA";
#endif
#ifdef GL_UNSIGNED_SHORT_8_8_MESA
	if ( en == GL_UNSIGNED_SHORT_8_8_MESA ) return "GL_UNSIGNED_SHORT_8_8_MESA";
#endif
#ifdef GL_UNSIGNED_SHORT_8_8_REV_MESA
	if ( en == GL_UNSIGNED_SHORT_8_8_REV_MESA ) return "GL_UNSIGNED_SHORT_8_8_REV_MESA";
#endif
#ifdef GL_YCBCR_MESA
	if ( en == GL_YCBCR_MESA ) return "GL_YCBCR_MESA";
#endif
#ifdef GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX
	if ( en == GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX ) return "GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX";
#endif
#ifdef GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX
	if ( en == GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX ) return "GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX";
#endif
#ifdef GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX
	if ( en == GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX ) return "GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX";
#endif
#ifdef GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX
	if ( en == GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX ) return "GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX";
#endif
#ifdef GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX
	if ( en == GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX ) return "GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX";
#endif
#ifdef GL_BLEND_PREMULTIPLIED_SRC_NV
	if ( en == GL_BLEND_PREMULTIPLIED_SRC_NV ) return "GL_BLEND_PREMULTIPLIED_SRC_NV";
#endif
#ifdef GL_BLEND_OVERLAP_NV
	if ( en == GL_BLEND_OVERLAP_NV ) return "GL_BLEND_OVERLAP_NV";
#endif
#ifdef GL_UNCORRELATED_NV
	if ( en == GL_UNCORRELATED_NV ) return "GL_UNCORRELATED_NV";
#endif
#ifdef GL_DISJOINT_NV
	if ( en == GL_DISJOINT_NV ) return "GL_DISJOINT_NV";
#endif
#ifdef GL_CONJOINT_NV
	if ( en == GL_CONJOINT_NV ) return "GL_CONJOINT_NV";
#endif
#ifdef GL_BLEND_ADVANCED_COHERENT_NV
	if ( en == GL_BLEND_ADVANCED_COHERENT_NV ) return "GL_BLEND_ADVANCED_COHERENT_NV";
#endif
#ifdef GL_SRC_NV
	if ( en == GL_SRC_NV ) return "GL_SRC_NV";
#endif
#ifdef GL_DST_NV
	if ( en == GL_DST_NV ) return "GL_DST_NV";
#endif
#ifdef GL_SRC_OVER_NV
	if ( en == GL_SRC_OVER_NV ) return "GL_SRC_OVER_NV";
#endif
#ifdef GL_DST_OVER_NV
	if ( en == GL_DST_OVER_NV ) return "GL_DST_OVER_NV";
#endif
#ifdef GL_SRC_IN_NV
	if ( en == GL_SRC_IN_NV ) return "GL_SRC_IN_NV";
#endif
#ifdef GL_DST_IN_NV
	if ( en == GL_DST_IN_NV ) return "GL_DST_IN_NV";
#endif
#ifdef GL_SRC_OUT_NV
	if ( en == GL_SRC_OUT_NV ) return "GL_SRC_OUT_NV";
#endif
#ifdef GL_DST_OUT_NV
	if ( en == GL_DST_OUT_NV ) return "GL_DST_OUT_NV";
#endif
#ifdef GL_SRC_ATOP_NV
	if ( en == GL_SRC_ATOP_NV ) return "GL_SRC_ATOP_NV";
#endif
#ifdef GL_DST_ATOP_NV
	if ( en == GL_DST_ATOP_NV ) return "GL_DST_ATOP_NV";
#endif
#ifdef GL_PLUS_NV
	if ( en == GL_PLUS_NV ) return "GL_PLUS_NV";
#endif
#ifdef GL_PLUS_DARKER_NV
	if ( en == GL_PLUS_DARKER_NV ) return "GL_PLUS_DARKER_NV";
#endif
#ifdef GL_MULTIPLY_NV
	if ( en == GL_MULTIPLY_NV ) return "GL_MULTIPLY_NV";
#endif
#ifdef GL_SCREEN_NV
	if ( en == GL_SCREEN_NV ) return "GL_SCREEN_NV";
#endif
#ifdef GL_OVERLAY_NV
	if ( en == GL_OVERLAY_NV ) return "GL_OVERLAY_NV";
#endif
#ifdef GL_DARKEN_NV
	if ( en == GL_DARKEN_NV ) return "GL_DARKEN_NV";
#endif
#ifdef GL_LIGHTEN_NV
	if ( en == GL_LIGHTEN_NV ) return "GL_LIGHTEN_NV";
#endif
#ifdef GL_COLORDODGE_NV
	if ( en == GL_COLORDODGE_NV ) return "GL_COLORDODGE_NV";
#endif
#ifdef GL_COLORBURN_NV
	if ( en == GL_COLORBURN_NV ) return "GL_COLORBURN_NV";
#endif
#ifdef GL_HARDLIGHT_NV
	if ( en == GL_HARDLIGHT_NV ) return "GL_HARDLIGHT_NV";
#endif
#ifdef GL_SOFTLIGHT_NV
	if ( en == GL_SOFTLIGHT_NV ) return "GL_SOFTLIGHT_NV";
#endif
#ifdef GL_DIFFERENCE_NV
	if ( en == GL_DIFFERENCE_NV ) return "GL_DIFFERENCE_NV";
#endif
#ifdef GL_MINUS_NV
	if ( en == GL_MINUS_NV ) return "GL_MINUS_NV";
#endif
#ifdef GL_EXCLUSION_NV
	if ( en == GL_EXCLUSION_NV ) return "GL_EXCLUSION_NV";
#endif
#ifdef GL_CONTRAST_NV
	if ( en == GL_CONTRAST_NV ) return "GL_CONTRAST_NV";
#endif
#ifdef GL_INVERT_RGB_NV
	if ( en == GL_INVERT_RGB_NV ) return "GL_INVERT_RGB_NV";
#endif
#ifdef GL_LINEARDODGE_NV
	if ( en == GL_LINEARDODGE_NV ) return "GL_LINEARDODGE_NV";
#endif
#ifdef GL_LINEARBURN_NV
	if ( en == GL_LINEARBURN_NV ) return "GL_LINEARBURN_NV";
#endif
#ifdef GL_VIVIDLIGHT_NV
	if ( en == GL_VIVIDLIGHT_NV ) return "GL_VIVIDLIGHT_NV";
#endif
#ifdef GL_LINEARLIGHT_NV
	if ( en == GL_LINEARLIGHT_NV ) return "GL_LINEARLIGHT_NV";
#endif
#ifdef GL_PINLIGHT_NV
	if ( en == GL_PINLIGHT_NV ) return "GL_PINLIGHT_NV";
#endif
#ifdef GL_HARDMIX_NV
	if ( en == GL_HARDMIX_NV ) return "GL_HARDMIX_NV";
#endif
#ifdef GL_HSL_HUE_NV
	if ( en == GL_HSL_HUE_NV ) return "GL_HSL_HUE_NV";
#endif
#ifdef GL_HSL_SATURATION_NV
	if ( en == GL_HSL_SATURATION_NV ) return "GL_HSL_SATURATION_NV";
#endif
#ifdef GL_HSL_COLOR_NV
	if ( en == GL_HSL_COLOR_NV ) return "GL_HSL_COLOR_NV";
#endif
#ifdef GL_HSL_LUMINOSITY_NV
	if ( en == GL_HSL_LUMINOSITY_NV ) return "GL_HSL_LUMINOSITY_NV";
#endif
#ifdef GL_PLUS_CLAMPED_NV
	if ( en == GL_PLUS_CLAMPED_NV ) return "GL_PLUS_CLAMPED_NV";
#endif
#ifdef GL_PLUS_CLAMPED_ALPHA_NV
	if ( en == GL_PLUS_CLAMPED_ALPHA_NV ) return "GL_PLUS_CLAMPED_ALPHA_NV";
#endif
#ifdef GL_MINUS_CLAMPED_NV
	if ( en == GL_MINUS_CLAMPED_NV ) return "GL_MINUS_CLAMPED_NV";
#endif
#ifdef GL_INVERT_OVG_NV
	if ( en == GL_INVERT_OVG_NV ) return "GL_INVERT_OVG_NV";
#endif
#ifdef GL_COMPUTE_PROGRAM_NV
	if ( en == GL_COMPUTE_PROGRAM_NV ) return "GL_COMPUTE_PROGRAM_NV";
#endif
#ifdef GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_QUERY_WAIT_NV
	if ( en == GL_QUERY_WAIT_NV ) return "GL_QUERY_WAIT_NV";
#endif
#ifdef GL_QUERY_NO_WAIT_NV
	if ( en == GL_QUERY_NO_WAIT_NV ) return "GL_QUERY_NO_WAIT_NV";
#endif
#ifdef GL_QUERY_BY_REGION_WAIT_NV
	if ( en == GL_QUERY_BY_REGION_WAIT_NV ) return "GL_QUERY_BY_REGION_WAIT_NV";
#endif
#ifdef GL_QUERY_BY_REGION_NO_WAIT_NV
	if ( en == GL_QUERY_BY_REGION_NO_WAIT_NV ) return "GL_QUERY_BY_REGION_NO_WAIT_NV";
#endif
#ifdef GL_DEPTH_STENCIL_TO_RGBA_NV
	if ( en == GL_DEPTH_STENCIL_TO_RGBA_NV ) return "GL_DEPTH_STENCIL_TO_RGBA_NV";
#endif
#ifdef GL_DEPTH_STENCIL_TO_BGRA_NV
	if ( en == GL_DEPTH_STENCIL_TO_BGRA_NV ) return "GL_DEPTH_STENCIL_TO_BGRA_NV";
#endif
#ifdef GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV
	if ( en == GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV ) return "GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV";
#endif
#ifdef GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV
	if ( en == GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV ) return "GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV";
#endif
#ifdef GL_DEPTH_COMPONENT32F_NV
	if ( en == GL_DEPTH_COMPONENT32F_NV ) return "GL_DEPTH_COMPONENT32F_NV";
#endif
#ifdef GL_DEPTH32F_STENCIL8_NV
	if ( en == GL_DEPTH32F_STENCIL8_NV ) return "GL_DEPTH32F_STENCIL8_NV";
#endif
#ifdef GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV
	if ( en == GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV ) return "GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV";
#endif
#ifdef GL_DEPTH_BUFFER_FLOAT_MODE_NV
	if ( en == GL_DEPTH_BUFFER_FLOAT_MODE_NV ) return "GL_DEPTH_BUFFER_FLOAT_MODE_NV";
#endif
#ifdef GL_DEPTH_CLAMP_NV
	if ( en == GL_DEPTH_CLAMP_NV ) return "GL_DEPTH_CLAMP_NV";
#endif
#ifdef GL_SAMPLE_COUNT_BITS_NV
	if ( en == GL_SAMPLE_COUNT_BITS_NV ) return "GL_SAMPLE_COUNT_BITS_NV";
#endif
#ifdef GL_CURRENT_SAMPLE_COUNT_QUERY_NV
	if ( en == GL_CURRENT_SAMPLE_COUNT_QUERY_NV ) return "GL_CURRENT_SAMPLE_COUNT_QUERY_NV";
#endif
#ifdef GL_QUERY_RESULT_NV
	if ( en == GL_QUERY_RESULT_NV ) return "GL_QUERY_RESULT_NV";
#endif
#ifdef GL_QUERY_RESULT_AVAILABLE_NV
	if ( en == GL_QUERY_RESULT_AVAILABLE_NV ) return "GL_QUERY_RESULT_AVAILABLE_NV";
#endif
#ifdef GL_SAMPLE_COUNT_NV
	if ( en == GL_SAMPLE_COUNT_NV ) return "GL_SAMPLE_COUNT_NV";
#endif
#ifdef GL_EVAL_2D_NV
	if ( en == GL_EVAL_2D_NV ) return "GL_EVAL_2D_NV";
#endif
#ifdef GL_EVAL_TRIANGULAR_2D_NV
	if ( en == GL_EVAL_TRIANGULAR_2D_NV ) return "GL_EVAL_TRIANGULAR_2D_NV";
#endif
#ifdef GL_MAP_TESSELLATION_NV
	if ( en == GL_MAP_TESSELLATION_NV ) return "GL_MAP_TESSELLATION_NV";
#endif
#ifdef GL_MAP_ATTRIB_U_ORDER_NV
	if ( en == GL_MAP_ATTRIB_U_ORDER_NV ) return "GL_MAP_ATTRIB_U_ORDER_NV";
#endif
#ifdef GL_MAP_ATTRIB_V_ORDER_NV
	if ( en == GL_MAP_ATTRIB_V_ORDER_NV ) return "GL_MAP_ATTRIB_V_ORDER_NV";
#endif
#ifdef GL_EVAL_FRACTIONAL_TESSELLATION_NV
	if ( en == GL_EVAL_FRACTIONAL_TESSELLATION_NV ) return "GL_EVAL_FRACTIONAL_TESSELLATION_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB0_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB0_NV ) return "GL_EVAL_VERTEX_ATTRIB0_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB1_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB1_NV ) return "GL_EVAL_VERTEX_ATTRIB1_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB2_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB2_NV ) return "GL_EVAL_VERTEX_ATTRIB2_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB3_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB3_NV ) return "GL_EVAL_VERTEX_ATTRIB3_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB4_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB4_NV ) return "GL_EVAL_VERTEX_ATTRIB4_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB5_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB5_NV ) return "GL_EVAL_VERTEX_ATTRIB5_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB6_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB6_NV ) return "GL_EVAL_VERTEX_ATTRIB6_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB7_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB7_NV ) return "GL_EVAL_VERTEX_ATTRIB7_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB8_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB8_NV ) return "GL_EVAL_VERTEX_ATTRIB8_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB9_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB9_NV ) return "GL_EVAL_VERTEX_ATTRIB9_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB10_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB10_NV ) return "GL_EVAL_VERTEX_ATTRIB10_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB11_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB11_NV ) return "GL_EVAL_VERTEX_ATTRIB11_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB12_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB12_NV ) return "GL_EVAL_VERTEX_ATTRIB12_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB13_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB13_NV ) return "GL_EVAL_VERTEX_ATTRIB13_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB14_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB14_NV ) return "GL_EVAL_VERTEX_ATTRIB14_NV";
#endif
#ifdef GL_EVAL_VERTEX_ATTRIB15_NV
	if ( en == GL_EVAL_VERTEX_ATTRIB15_NV ) return "GL_EVAL_VERTEX_ATTRIB15_NV";
#endif
#ifdef GL_MAX_MAP_TESSELLATION_NV
	if ( en == GL_MAX_MAP_TESSELLATION_NV ) return "GL_MAX_MAP_TESSELLATION_NV";
#endif
#ifdef GL_MAX_RATIONAL_EVAL_ORDER_NV
	if ( en == GL_MAX_RATIONAL_EVAL_ORDER_NV ) return "GL_MAX_RATIONAL_EVAL_ORDER_NV";
#endif
#ifdef GL_SAMPLE_POSITION_NV
	if ( en == GL_SAMPLE_POSITION_NV ) return "GL_SAMPLE_POSITION_NV";
#endif
#ifdef GL_SAMPLE_MASK_NV
	if ( en == GL_SAMPLE_MASK_NV ) return "GL_SAMPLE_MASK_NV";
#endif
#ifdef GL_SAMPLE_MASK_VALUE_NV
	if ( en == GL_SAMPLE_MASK_VALUE_NV ) return "GL_SAMPLE_MASK_VALUE_NV";
#endif
#ifdef GL_TEXTURE_BINDING_RENDERBUFFER_NV
	if ( en == GL_TEXTURE_BINDING_RENDERBUFFER_NV ) return "GL_TEXTURE_BINDING_RENDERBUFFER_NV";
#endif
#ifdef GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV
	if ( en == GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV ) return "GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV";
#endif
#ifdef GL_TEXTURE_RENDERBUFFER_NV
	if ( en == GL_TEXTURE_RENDERBUFFER_NV ) return "GL_TEXTURE_RENDERBUFFER_NV";
#endif
#ifdef GL_SAMPLER_RENDERBUFFER_NV
	if ( en == GL_SAMPLER_RENDERBUFFER_NV ) return "GL_SAMPLER_RENDERBUFFER_NV";
#endif
#ifdef GL_INT_SAMPLER_RENDERBUFFER_NV
	if ( en == GL_INT_SAMPLER_RENDERBUFFER_NV ) return "GL_INT_SAMPLER_RENDERBUFFER_NV";
#endif
#ifdef GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV
	if ( en == GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV ) return "GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV";
#endif
#ifdef GL_MAX_SAMPLE_MASK_WORDS_NV
	if ( en == GL_MAX_SAMPLE_MASK_WORDS_NV ) return "GL_MAX_SAMPLE_MASK_WORDS_NV";
#endif
#ifdef GL_ALL_COMPLETED_NV
	if ( en == GL_ALL_COMPLETED_NV ) return "GL_ALL_COMPLETED_NV";
#endif
#ifdef GL_FENCE_STATUS_NV
	if ( en == GL_FENCE_STATUS_NV ) return "GL_FENCE_STATUS_NV";
#endif
#ifdef GL_FENCE_CONDITION_NV
	if ( en == GL_FENCE_CONDITION_NV ) return "GL_FENCE_CONDITION_NV";
#endif
#ifdef GL_FLOAT_R_NV
	if ( en == GL_FLOAT_R_NV ) return "GL_FLOAT_R_NV";
#endif
#ifdef GL_FLOAT_RG_NV
	if ( en == GL_FLOAT_RG_NV ) return "GL_FLOAT_RG_NV";
#endif
#ifdef GL_FLOAT_RGB_NV
	if ( en == GL_FLOAT_RGB_NV ) return "GL_FLOAT_RGB_NV";
#endif
#ifdef GL_FLOAT_RGBA_NV
	if ( en == GL_FLOAT_RGBA_NV ) return "GL_FLOAT_RGBA_NV";
#endif
#ifdef GL_FLOAT_R16_NV
	if ( en == GL_FLOAT_R16_NV ) return "GL_FLOAT_R16_NV";
#endif
#ifdef GL_FLOAT_R32_NV
	if ( en == GL_FLOAT_R32_NV ) return "GL_FLOAT_R32_NV";
#endif
#ifdef GL_FLOAT_RG16_NV
	if ( en == GL_FLOAT_RG16_NV ) return "GL_FLOAT_RG16_NV";
#endif
#ifdef GL_FLOAT_RG32_NV
	if ( en == GL_FLOAT_RG32_NV ) return "GL_FLOAT_RG32_NV";
#endif
#ifdef GL_FLOAT_RGB16_NV
	if ( en == GL_FLOAT_RGB16_NV ) return "GL_FLOAT_RGB16_NV";
#endif
#ifdef GL_FLOAT_RGB32_NV
	if ( en == GL_FLOAT_RGB32_NV ) return "GL_FLOAT_RGB32_NV";
#endif
#ifdef GL_FLOAT_RGBA16_NV
	if ( en == GL_FLOAT_RGBA16_NV ) return "GL_FLOAT_RGBA16_NV";
#endif
#ifdef GL_FLOAT_RGBA32_NV
	if ( en == GL_FLOAT_RGBA32_NV ) return "GL_FLOAT_RGBA32_NV";
#endif
#ifdef GL_TEXTURE_FLOAT_COMPONENTS_NV
	if ( en == GL_TEXTURE_FLOAT_COMPONENTS_NV ) return "GL_TEXTURE_FLOAT_COMPONENTS_NV";
#endif
#ifdef GL_FLOAT_CLEAR_COLOR_VALUE_NV
	if ( en == GL_FLOAT_CLEAR_COLOR_VALUE_NV ) return "GL_FLOAT_CLEAR_COLOR_VALUE_NV";
#endif
#ifdef GL_FLOAT_RGBA_MODE_NV
	if ( en == GL_FLOAT_RGBA_MODE_NV ) return "GL_FLOAT_RGBA_MODE_NV";
#endif
#ifdef GL_FOG_DISTANCE_MODE_NV
	if ( en == GL_FOG_DISTANCE_MODE_NV ) return "GL_FOG_DISTANCE_MODE_NV";
#endif
#ifdef GL_EYE_RADIAL_NV
	if ( en == GL_EYE_RADIAL_NV ) return "GL_EYE_RADIAL_NV";
#endif
#ifdef GL_EYE_PLANE_ABSOLUTE_NV
	if ( en == GL_EYE_PLANE_ABSOLUTE_NV ) return "GL_EYE_PLANE_ABSOLUTE_NV";
#endif
#ifdef GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV
	if ( en == GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV ) return "GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV";
#endif
#ifdef GL_FRAGMENT_PROGRAM_NV
	if ( en == GL_FRAGMENT_PROGRAM_NV ) return "GL_FRAGMENT_PROGRAM_NV";
#endif
#ifdef GL_MAX_TEXTURE_COORDS_NV
	if ( en == GL_MAX_TEXTURE_COORDS_NV ) return "GL_MAX_TEXTURE_COORDS_NV";
#endif
#ifdef GL_MAX_TEXTURE_IMAGE_UNITS_NV
	if ( en == GL_MAX_TEXTURE_IMAGE_UNITS_NV ) return "GL_MAX_TEXTURE_IMAGE_UNITS_NV";
#endif
#ifdef GL_FRAGMENT_PROGRAM_BINDING_NV
	if ( en == GL_FRAGMENT_PROGRAM_BINDING_NV ) return "GL_FRAGMENT_PROGRAM_BINDING_NV";
#endif
#ifdef GL_PROGRAM_ERROR_STRING_NV
	if ( en == GL_PROGRAM_ERROR_STRING_NV ) return "GL_PROGRAM_ERROR_STRING_NV";
#endif
#ifdef GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV
	if ( en == GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV ) return "GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV";
#endif
#ifdef GL_MAX_PROGRAM_CALL_DEPTH_NV
	if ( en == GL_MAX_PROGRAM_CALL_DEPTH_NV ) return "GL_MAX_PROGRAM_CALL_DEPTH_NV";
#endif
#ifdef GL_MAX_PROGRAM_IF_DEPTH_NV
	if ( en == GL_MAX_PROGRAM_IF_DEPTH_NV ) return "GL_MAX_PROGRAM_IF_DEPTH_NV";
#endif
#ifdef GL_MAX_PROGRAM_LOOP_DEPTH_NV
	if ( en == GL_MAX_PROGRAM_LOOP_DEPTH_NV ) return "GL_MAX_PROGRAM_LOOP_DEPTH_NV";
#endif
#ifdef GL_MAX_PROGRAM_LOOP_COUNT_NV
	if ( en == GL_MAX_PROGRAM_LOOP_COUNT_NV ) return "GL_MAX_PROGRAM_LOOP_COUNT_NV";
#endif
#ifdef GL_RENDERBUFFER_COVERAGE_SAMPLES_NV
	if ( en == GL_RENDERBUFFER_COVERAGE_SAMPLES_NV ) return "GL_RENDERBUFFER_COVERAGE_SAMPLES_NV";
#endif
#ifdef GL_RENDERBUFFER_COLOR_SAMPLES_NV
	if ( en == GL_RENDERBUFFER_COLOR_SAMPLES_NV ) return "GL_RENDERBUFFER_COLOR_SAMPLES_NV";
#endif
#ifdef GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV
	if ( en == GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV ) return "GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV";
#endif
#ifdef GL_MULTISAMPLE_COVERAGE_MODES_NV
	if ( en == GL_MULTISAMPLE_COVERAGE_MODES_NV ) return "GL_MULTISAMPLE_COVERAGE_MODES_NV";
#endif
#ifdef GL_GEOMETRY_PROGRAM_NV
	if ( en == GL_GEOMETRY_PROGRAM_NV ) return "GL_GEOMETRY_PROGRAM_NV";
#endif
#ifdef GL_MAX_PROGRAM_OUTPUT_VERTICES_NV
	if ( en == GL_MAX_PROGRAM_OUTPUT_VERTICES_NV ) return "GL_MAX_PROGRAM_OUTPUT_VERTICES_NV";
#endif
#ifdef GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV
	if ( en == GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV ) return "GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV";
#endif
#ifdef GL_MIN_PROGRAM_TEXEL_OFFSET_NV
	if ( en == GL_MIN_PROGRAM_TEXEL_OFFSET_NV ) return "GL_MIN_PROGRAM_TEXEL_OFFSET_NV";
#endif
#ifdef GL_MAX_PROGRAM_TEXEL_OFFSET_NV
	if ( en == GL_MAX_PROGRAM_TEXEL_OFFSET_NV ) return "GL_MAX_PROGRAM_TEXEL_OFFSET_NV";
#endif
#ifdef GL_PROGRAM_ATTRIB_COMPONENTS_NV
	if ( en == GL_PROGRAM_ATTRIB_COMPONENTS_NV ) return "GL_PROGRAM_ATTRIB_COMPONENTS_NV";
#endif
#ifdef GL_PROGRAM_RESULT_COMPONENTS_NV
	if ( en == GL_PROGRAM_RESULT_COMPONENTS_NV ) return "GL_PROGRAM_RESULT_COMPONENTS_NV";
#endif
#ifdef GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV
	if ( en == GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV ) return "GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV";
#endif
#ifdef GL_MAX_PROGRAM_RESULT_COMPONENTS_NV
	if ( en == GL_MAX_PROGRAM_RESULT_COMPONENTS_NV ) return "GL_MAX_PROGRAM_RESULT_COMPONENTS_NV";
#endif
#ifdef GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV
	if ( en == GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV ) return "GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV";
#endif
#ifdef GL_MAX_PROGRAM_GENERIC_RESULTS_NV
	if ( en == GL_MAX_PROGRAM_GENERIC_RESULTS_NV ) return "GL_MAX_PROGRAM_GENERIC_RESULTS_NV";
#endif
#ifdef GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV
	if ( en == GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV ) return "GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV";
#endif
#ifdef GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV
	if ( en == GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV ) return "GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV";
#endif
#ifdef GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV
	if ( en == GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV ) return "GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV";
#endif
#ifdef GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV
	if ( en == GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV ) return "GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV";
#endif
#ifdef GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV
	if ( en == GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV ) return "GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV";
#endif
#ifdef GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV
	if ( en == GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV ) return "GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV";
#endif
#ifdef GL_INT64_NV
	if ( en == GL_INT64_NV ) return "GL_INT64_NV";
#endif
#ifdef GL_UNSIGNED_INT64_NV
	if ( en == GL_UNSIGNED_INT64_NV ) return "GL_UNSIGNED_INT64_NV";
#endif
#ifdef GL_INT8_NV
	if ( en == GL_INT8_NV ) return "GL_INT8_NV";
#endif
#ifdef GL_INT8_VEC2_NV
	if ( en == GL_INT8_VEC2_NV ) return "GL_INT8_VEC2_NV";
#endif
#ifdef GL_INT8_VEC3_NV
	if ( en == GL_INT8_VEC3_NV ) return "GL_INT8_VEC3_NV";
#endif
#ifdef GL_INT8_VEC4_NV
	if ( en == GL_INT8_VEC4_NV ) return "GL_INT8_VEC4_NV";
#endif
#ifdef GL_INT16_NV
	if ( en == GL_INT16_NV ) return "GL_INT16_NV";
#endif
#ifdef GL_INT16_VEC2_NV
	if ( en == GL_INT16_VEC2_NV ) return "GL_INT16_VEC2_NV";
#endif
#ifdef GL_INT16_VEC3_NV
	if ( en == GL_INT16_VEC3_NV ) return "GL_INT16_VEC3_NV";
#endif
#ifdef GL_INT16_VEC4_NV
	if ( en == GL_INT16_VEC4_NV ) return "GL_INT16_VEC4_NV";
#endif
#ifdef GL_INT64_VEC2_NV
	if ( en == GL_INT64_VEC2_NV ) return "GL_INT64_VEC2_NV";
#endif
#ifdef GL_INT64_VEC3_NV
	if ( en == GL_INT64_VEC3_NV ) return "GL_INT64_VEC3_NV";
#endif
#ifdef GL_INT64_VEC4_NV
	if ( en == GL_INT64_VEC4_NV ) return "GL_INT64_VEC4_NV";
#endif
#ifdef GL_UNSIGNED_INT8_NV
	if ( en == GL_UNSIGNED_INT8_NV ) return "GL_UNSIGNED_INT8_NV";
#endif
#ifdef GL_UNSIGNED_INT8_VEC2_NV
	if ( en == GL_UNSIGNED_INT8_VEC2_NV ) return "GL_UNSIGNED_INT8_VEC2_NV";
#endif
#ifdef GL_UNSIGNED_INT8_VEC3_NV
	if ( en == GL_UNSIGNED_INT8_VEC3_NV ) return "GL_UNSIGNED_INT8_VEC3_NV";
#endif
#ifdef GL_UNSIGNED_INT8_VEC4_NV
	if ( en == GL_UNSIGNED_INT8_VEC4_NV ) return "GL_UNSIGNED_INT8_VEC4_NV";
#endif
#ifdef GL_UNSIGNED_INT16_NV
	if ( en == GL_UNSIGNED_INT16_NV ) return "GL_UNSIGNED_INT16_NV";
#endif
#ifdef GL_UNSIGNED_INT16_VEC2_NV
	if ( en == GL_UNSIGNED_INT16_VEC2_NV ) return "GL_UNSIGNED_INT16_VEC2_NV";
#endif
#ifdef GL_UNSIGNED_INT16_VEC3_NV
	if ( en == GL_UNSIGNED_INT16_VEC3_NV ) return "GL_UNSIGNED_INT16_VEC3_NV";
#endif
#ifdef GL_UNSIGNED_INT16_VEC4_NV
	if ( en == GL_UNSIGNED_INT16_VEC4_NV ) return "GL_UNSIGNED_INT16_VEC4_NV";
#endif
#ifdef GL_UNSIGNED_INT64_VEC2_NV
	if ( en == GL_UNSIGNED_INT64_VEC2_NV ) return "GL_UNSIGNED_INT64_VEC2_NV";
#endif
#ifdef GL_UNSIGNED_INT64_VEC3_NV
	if ( en == GL_UNSIGNED_INT64_VEC3_NV ) return "GL_UNSIGNED_INT64_VEC3_NV";
#endif
#ifdef GL_UNSIGNED_INT64_VEC4_NV
	if ( en == GL_UNSIGNED_INT64_VEC4_NV ) return "GL_UNSIGNED_INT64_VEC4_NV";
#endif
#ifdef GL_FLOAT16_NV
	if ( en == GL_FLOAT16_NV ) return "GL_FLOAT16_NV";
#endif
#ifdef GL_FLOAT16_VEC2_NV
	if ( en == GL_FLOAT16_VEC2_NV ) return "GL_FLOAT16_VEC2_NV";
#endif
#ifdef GL_FLOAT16_VEC3_NV
	if ( en == GL_FLOAT16_VEC3_NV ) return "GL_FLOAT16_VEC3_NV";
#endif
#ifdef GL_FLOAT16_VEC4_NV
	if ( en == GL_FLOAT16_VEC4_NV ) return "GL_FLOAT16_VEC4_NV";
#endif
#ifdef GL_HALF_FLOAT_NV
	if ( en == GL_HALF_FLOAT_NV ) return "GL_HALF_FLOAT_NV";
#endif
#ifdef GL_MAX_SHININESS_NV
	if ( en == GL_MAX_SHININESS_NV ) return "GL_MAX_SHININESS_NV";
#endif
#ifdef GL_MAX_SPOT_EXPONENT_NV
	if ( en == GL_MAX_SPOT_EXPONENT_NV ) return "GL_MAX_SPOT_EXPONENT_NV";
#endif
#ifdef GL_COLOR_SAMPLES_NV
	if ( en == GL_COLOR_SAMPLES_NV ) return "GL_COLOR_SAMPLES_NV";
#endif
#ifdef GL_MULTISAMPLE_FILTER_HINT_NV
	if ( en == GL_MULTISAMPLE_FILTER_HINT_NV ) return "GL_MULTISAMPLE_FILTER_HINT_NV";
#endif
#ifdef GL_PIXEL_COUNTER_BITS_NV
	if ( en == GL_PIXEL_COUNTER_BITS_NV ) return "GL_PIXEL_COUNTER_BITS_NV";
#endif
#ifdef GL_CURRENT_OCCLUSION_QUERY_ID_NV
	if ( en == GL_CURRENT_OCCLUSION_QUERY_ID_NV ) return "GL_CURRENT_OCCLUSION_QUERY_ID_NV";
#endif
#ifdef GL_PIXEL_COUNT_NV
	if ( en == GL_PIXEL_COUNT_NV ) return "GL_PIXEL_COUNT_NV";
#endif
#ifdef GL_PIXEL_COUNT_AVAILABLE_NV
	if ( en == GL_PIXEL_COUNT_AVAILABLE_NV ) return "GL_PIXEL_COUNT_AVAILABLE_NV";
#endif
#ifdef GL_DEPTH_STENCIL_NV
	if ( en == GL_DEPTH_STENCIL_NV ) return "GL_DEPTH_STENCIL_NV";
#endif
#ifdef GL_UNSIGNED_INT_24_8_NV
	if ( en == GL_UNSIGNED_INT_24_8_NV ) return "GL_UNSIGNED_INT_24_8_NV";
#endif
#ifdef GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV
	if ( en == GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV ) return "GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV";
#endif
#ifdef GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV
	if ( en == GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV ) return "GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV";
#endif
#ifdef GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_CLOSE_PATH_NV
	if ( en == GL_CLOSE_PATH_NV ) return "GL_CLOSE_PATH_NV";
#endif
#ifdef GL_BOLD_BIT_NV
	if ( en == GL_BOLD_BIT_NV ) return "GL_BOLD_BIT_NV";
#endif
#ifdef GL_GLYPH_WIDTH_BIT_NV
	if ( en == GL_GLYPH_WIDTH_BIT_NV ) return "GL_GLYPH_WIDTH_BIT_NV";
#endif
#ifdef GL_GLYPH_HEIGHT_BIT_NV
	if ( en == GL_GLYPH_HEIGHT_BIT_NV ) return "GL_GLYPH_HEIGHT_BIT_NV";
#endif
#ifdef GL_ITALIC_BIT_NV
	if ( en == GL_ITALIC_BIT_NV ) return "GL_ITALIC_BIT_NV";
#endif
#ifdef GL_MOVE_TO_NV
	if ( en == GL_MOVE_TO_NV ) return "GL_MOVE_TO_NV";
#endif
#ifdef GL_RELATIVE_MOVE_TO_NV
	if ( en == GL_RELATIVE_MOVE_TO_NV ) return "GL_RELATIVE_MOVE_TO_NV";
#endif
#ifdef GL_LINE_TO_NV
	if ( en == GL_LINE_TO_NV ) return "GL_LINE_TO_NV";
#endif
#ifdef GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV
	if ( en == GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV ) return "GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV";
#endif
#ifdef GL_RELATIVE_LINE_TO_NV
	if ( en == GL_RELATIVE_LINE_TO_NV ) return "GL_RELATIVE_LINE_TO_NV";
#endif
#ifdef GL_HORIZONTAL_LINE_TO_NV
	if ( en == GL_HORIZONTAL_LINE_TO_NV ) return "GL_HORIZONTAL_LINE_TO_NV";
#endif
#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	if ( en == GL_RELATIVE_HORIZONTAL_LINE_TO_NV ) return "GL_RELATIVE_HORIZONTAL_LINE_TO_NV";
#endif
#ifdef GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV
	if ( en == GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV ) return "GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV";
#endif
#ifdef GL_VERTICAL_LINE_TO_NV
	if ( en == GL_VERTICAL_LINE_TO_NV ) return "GL_VERTICAL_LINE_TO_NV";
#endif
#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	if ( en == GL_RELATIVE_VERTICAL_LINE_TO_NV ) return "GL_RELATIVE_VERTICAL_LINE_TO_NV";
#endif
#ifdef GL_QUADRATIC_CURVE_TO_NV
	if ( en == GL_QUADRATIC_CURVE_TO_NV ) return "GL_QUADRATIC_CURVE_TO_NV";
#endif
#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	if ( en == GL_RELATIVE_QUADRATIC_CURVE_TO_NV ) return "GL_RELATIVE_QUADRATIC_CURVE_TO_NV";
#endif
#ifdef GL_CUBIC_CURVE_TO_NV
	if ( en == GL_CUBIC_CURVE_TO_NV ) return "GL_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	if ( en == GL_RELATIVE_CUBIC_CURVE_TO_NV ) return "GL_RELATIVE_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	if ( en == GL_SMOOTH_QUADRATIC_CURVE_TO_NV ) return "GL_SMOOTH_QUADRATIC_CURVE_TO_NV";
#endif
#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	if ( en == GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV ) return "GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV";
#endif
#ifdef GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV
	if ( en == GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV ) return "GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV";
#endif
#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	if ( en == GL_SMOOTH_CUBIC_CURVE_TO_NV ) return "GL_SMOOTH_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	if ( en == GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV ) return "GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_SMALL_CCW_ARC_TO_NV
	if ( en == GL_SMALL_CCW_ARC_TO_NV ) return "GL_SMALL_CCW_ARC_TO_NV";
#endif
#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	if ( en == GL_RELATIVE_SMALL_CCW_ARC_TO_NV ) return "GL_RELATIVE_SMALL_CCW_ARC_TO_NV";
#endif
#ifdef GL_SMALL_CW_ARC_TO_NV
	if ( en == GL_SMALL_CW_ARC_TO_NV ) return "GL_SMALL_CW_ARC_TO_NV";
#endif
#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	if ( en == GL_RELATIVE_SMALL_CW_ARC_TO_NV ) return "GL_RELATIVE_SMALL_CW_ARC_TO_NV";
#endif
#ifdef GL_LARGE_CCW_ARC_TO_NV
	if ( en == GL_LARGE_CCW_ARC_TO_NV ) return "GL_LARGE_CCW_ARC_TO_NV";
#endif
#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	if ( en == GL_RELATIVE_LARGE_CCW_ARC_TO_NV ) return "GL_RELATIVE_LARGE_CCW_ARC_TO_NV";
#endif
#ifdef GL_LARGE_CW_ARC_TO_NV
	if ( en == GL_LARGE_CW_ARC_TO_NV ) return "GL_LARGE_CW_ARC_TO_NV";
#endif
#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	if ( en == GL_RELATIVE_LARGE_CW_ARC_TO_NV ) return "GL_RELATIVE_LARGE_CW_ARC_TO_NV";
#endif
#ifdef GL_GLYPH_VERTICAL_BEARING_X_BIT_NV
	if ( en == GL_GLYPH_VERTICAL_BEARING_X_BIT_NV ) return "GL_GLYPH_VERTICAL_BEARING_X_BIT_NV";
#endif
#ifdef GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV
	if ( en == GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV ) return "GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV";
#endif
#ifdef GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV
	if ( en == GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV ) return "GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV";
#endif
#ifdef GL_RESTART_PATH_NV
	if ( en == GL_RESTART_PATH_NV ) return "GL_RESTART_PATH_NV";
#endif
#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	if ( en == GL_DUP_FIRST_CUBIC_CURVE_TO_NV ) return "GL_DUP_FIRST_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	if ( en == GL_DUP_LAST_CUBIC_CURVE_TO_NV ) return "GL_DUP_LAST_CUBIC_CURVE_TO_NV";
#endif
#ifdef GL_RECT_NV
	if ( en == GL_RECT_NV ) return "GL_RECT_NV";
#endif
#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
	if ( en == GL_CIRCULAR_CCW_ARC_TO_NV ) return "GL_CIRCULAR_CCW_ARC_TO_NV";
#endif
#ifdef GL_CIRCULAR_CW_ARC_TO_NV
	if ( en == GL_CIRCULAR_CW_ARC_TO_NV ) return "GL_CIRCULAR_CW_ARC_TO_NV";
#endif
#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	if ( en == GL_CIRCULAR_TANGENT_ARC_TO_NV ) return "GL_CIRCULAR_TANGENT_ARC_TO_NV";
#endif
#ifdef GL_ARC_TO_NV
	if ( en == GL_ARC_TO_NV ) return "GL_ARC_TO_NV";
#endif
#ifdef GL_RELATIVE_ARC_TO_NV
	if ( en == GL_RELATIVE_ARC_TO_NV ) return "GL_RELATIVE_ARC_TO_NV";
#endif
#ifdef GL_GLYPH_HAS_KERNING_BIT_NV
	if ( en == GL_GLYPH_HAS_KERNING_BIT_NV ) return "GL_GLYPH_HAS_KERNING_BIT_NV";
#endif
#ifdef GL_PRIMARY_COLOR
	if ( en == GL_PRIMARY_COLOR ) return "GL_PRIMARY_COLOR";
#endif
#ifdef GL_PATH_FORMAT_SVG_NV
	if ( en == GL_PATH_FORMAT_SVG_NV ) return "GL_PATH_FORMAT_SVG_NV";
#endif
#ifdef GL_PATH_FORMAT_PS_NV
	if ( en == GL_PATH_FORMAT_PS_NV ) return "GL_PATH_FORMAT_PS_NV";
#endif
#ifdef GL_STANDARD_FONT_NAME_NV
	if ( en == GL_STANDARD_FONT_NAME_NV ) return "GL_STANDARD_FONT_NAME_NV";
#endif
#ifdef GL_SYSTEM_FONT_NAME_NV
	if ( en == GL_SYSTEM_FONT_NAME_NV ) return "GL_SYSTEM_FONT_NAME_NV";
#endif
#ifdef GL_FILE_NAME_NV
	if ( en == GL_FILE_NAME_NV ) return "GL_FILE_NAME_NV";
#endif
#ifdef GL_PATH_STROKE_WIDTH_NV
	if ( en == GL_PATH_STROKE_WIDTH_NV ) return "GL_PATH_STROKE_WIDTH_NV";
#endif
#ifdef GL_PATH_END_CAPS_NV
	if ( en == GL_PATH_END_CAPS_NV ) return "GL_PATH_END_CAPS_NV";
#endif
#ifdef GL_PATH_INITIAL_END_CAP_NV
	if ( en == GL_PATH_INITIAL_END_CAP_NV ) return "GL_PATH_INITIAL_END_CAP_NV";
#endif
#ifdef GL_PATH_TERMINAL_END_CAP_NV
	if ( en == GL_PATH_TERMINAL_END_CAP_NV ) return "GL_PATH_TERMINAL_END_CAP_NV";
#endif
#ifdef GL_PATH_JOIN_STYLE_NV
	if ( en == GL_PATH_JOIN_STYLE_NV ) return "GL_PATH_JOIN_STYLE_NV";
#endif
#ifdef GL_PATH_MITER_LIMIT_NV
	if ( en == GL_PATH_MITER_LIMIT_NV ) return "GL_PATH_MITER_LIMIT_NV";
#endif
#ifdef GL_PATH_DASH_CAPS_NV
	if ( en == GL_PATH_DASH_CAPS_NV ) return "GL_PATH_DASH_CAPS_NV";
#endif
#ifdef GL_PATH_INITIAL_DASH_CAP_NV
	if ( en == GL_PATH_INITIAL_DASH_CAP_NV ) return "GL_PATH_INITIAL_DASH_CAP_NV";
#endif
#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	if ( en == GL_PATH_TERMINAL_DASH_CAP_NV ) return "GL_PATH_TERMINAL_DASH_CAP_NV";
#endif
#ifdef GL_PATH_DASH_OFFSET_NV
	if ( en == GL_PATH_DASH_OFFSET_NV ) return "GL_PATH_DASH_OFFSET_NV";
#endif
#ifdef GL_PATH_CLIENT_LENGTH_NV
	if ( en == GL_PATH_CLIENT_LENGTH_NV ) return "GL_PATH_CLIENT_LENGTH_NV";
#endif
#ifdef GL_PATH_FILL_MODE_NV
	if ( en == GL_PATH_FILL_MODE_NV ) return "GL_PATH_FILL_MODE_NV";
#endif
#ifdef GL_PATH_FILL_MASK_NV
	if ( en == GL_PATH_FILL_MASK_NV ) return "GL_PATH_FILL_MASK_NV";
#endif
#ifdef GL_PATH_FILL_COVER_MODE_NV
	if ( en == GL_PATH_FILL_COVER_MODE_NV ) return "GL_PATH_FILL_COVER_MODE_NV";
#endif
#ifdef GL_PATH_STROKE_COVER_MODE_NV
	if ( en == GL_PATH_STROKE_COVER_MODE_NV ) return "GL_PATH_STROKE_COVER_MODE_NV";
#endif
#ifdef GL_PATH_STROKE_MASK_NV
	if ( en == GL_PATH_STROKE_MASK_NV ) return "GL_PATH_STROKE_MASK_NV";
#endif
#ifdef GL_COUNT_UP_NV
	if ( en == GL_COUNT_UP_NV ) return "GL_COUNT_UP_NV";
#endif
#ifdef GL_COUNT_DOWN_NV
	if ( en == GL_COUNT_DOWN_NV ) return "GL_COUNT_DOWN_NV";
#endif
#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	if ( en == GL_PATH_OBJECT_BOUNDING_BOX_NV ) return "GL_PATH_OBJECT_BOUNDING_BOX_NV";
#endif
#ifdef GL_CONVEX_HULL_NV
	if ( en == GL_CONVEX_HULL_NV ) return "GL_CONVEX_HULL_NV";
#endif
#ifdef GL_BOUNDING_BOX_NV
	if ( en == GL_BOUNDING_BOX_NV ) return "GL_BOUNDING_BOX_NV";
#endif
#ifdef GL_TRANSLATE_X_NV
	if ( en == GL_TRANSLATE_X_NV ) return "GL_TRANSLATE_X_NV";
#endif
#ifdef GL_TRANSLATE_Y_NV
	if ( en == GL_TRANSLATE_Y_NV ) return "GL_TRANSLATE_Y_NV";
#endif
#ifdef GL_TRANSLATE_2D_NV
	if ( en == GL_TRANSLATE_2D_NV ) return "GL_TRANSLATE_2D_NV";
#endif
#ifdef GL_TRANSLATE_3D_NV
	if ( en == GL_TRANSLATE_3D_NV ) return "GL_TRANSLATE_3D_NV";
#endif
#ifdef GL_AFFINE_2D_NV
	if ( en == GL_AFFINE_2D_NV ) return "GL_AFFINE_2D_NV";
#endif
#ifdef GL_AFFINE_3D_NV
	if ( en == GL_AFFINE_3D_NV ) return "GL_AFFINE_3D_NV";
#endif
#ifdef GL_TRANSPOSE_AFFINE_2D_NV
	if ( en == GL_TRANSPOSE_AFFINE_2D_NV ) return "GL_TRANSPOSE_AFFINE_2D_NV";
#endif
#ifdef GL_TRANSPOSE_AFFINE_3D_NV
	if ( en == GL_TRANSPOSE_AFFINE_3D_NV ) return "GL_TRANSPOSE_AFFINE_3D_NV";
#endif
#ifdef GL_UTF8_NV
	if ( en == GL_UTF8_NV ) return "GL_UTF8_NV";
#endif
#ifdef GL_UTF16_NV
	if ( en == GL_UTF16_NV ) return "GL_UTF16_NV";
#endif
#ifdef GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV
	if ( en == GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV ) return "GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV";
#endif
#ifdef GL_PATH_COMMAND_COUNT_NV
	if ( en == GL_PATH_COMMAND_COUNT_NV ) return "GL_PATH_COMMAND_COUNT_NV";
#endif
#ifdef GL_PATH_COORD_COUNT_NV
	if ( en == GL_PATH_COORD_COUNT_NV ) return "GL_PATH_COORD_COUNT_NV";
#endif
#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	if ( en == GL_PATH_DASH_ARRAY_COUNT_NV ) return "GL_PATH_DASH_ARRAY_COUNT_NV";
#endif
#ifdef GL_PATH_COMPUTED_LENGTH_NV
	if ( en == GL_PATH_COMPUTED_LENGTH_NV ) return "GL_PATH_COMPUTED_LENGTH_NV";
#endif
#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	if ( en == GL_PATH_FILL_BOUNDING_BOX_NV ) return "GL_PATH_FILL_BOUNDING_BOX_NV";
#endif
#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	if ( en == GL_PATH_STROKE_BOUNDING_BOX_NV ) return "GL_PATH_STROKE_BOUNDING_BOX_NV";
#endif
#ifdef GL_SQUARE_NV
	if ( en == GL_SQUARE_NV ) return "GL_SQUARE_NV";
#endif
#ifdef GL_ROUND_NV
	if ( en == GL_ROUND_NV ) return "GL_ROUND_NV";
#endif
#ifdef GL_TRIANGULAR_NV
	if ( en == GL_TRIANGULAR_NV ) return "GL_TRIANGULAR_NV";
#endif
#ifdef GL_BEVEL_NV
	if ( en == GL_BEVEL_NV ) return "GL_BEVEL_NV";
#endif
#ifdef GL_MITER_REVERT_NV
	if ( en == GL_MITER_REVERT_NV ) return "GL_MITER_REVERT_NV";
#endif
#ifdef GL_MITER_TRUNCATE_NV
	if ( en == GL_MITER_TRUNCATE_NV ) return "GL_MITER_TRUNCATE_NV";
#endif
#ifdef GL_SKIP_MISSING_GLYPH_NV
	if ( en == GL_SKIP_MISSING_GLYPH_NV ) return "GL_SKIP_MISSING_GLYPH_NV";
#endif
#ifdef GL_USE_MISSING_GLYPH_NV
	if ( en == GL_USE_MISSING_GLYPH_NV ) return "GL_USE_MISSING_GLYPH_NV";
#endif
#ifdef GL_PATH_ERROR_POSITION_NV
	if ( en == GL_PATH_ERROR_POSITION_NV ) return "GL_PATH_ERROR_POSITION_NV";
#endif
#ifdef GL_PATH_FOG_GEN_MODE_NV
	if ( en == GL_PATH_FOG_GEN_MODE_NV ) return "GL_PATH_FOG_GEN_MODE_NV";
#endif
#ifdef GL_ACCUM_ADJACENT_PAIRS_NV
	if ( en == GL_ACCUM_ADJACENT_PAIRS_NV ) return "GL_ACCUM_ADJACENT_PAIRS_NV";
#endif
#ifdef GL_ADJACENT_PAIRS_NV
	if ( en == GL_ADJACENT_PAIRS_NV ) return "GL_ADJACENT_PAIRS_NV";
#endif
#ifdef GL_FIRST_TO_REST_NV
	if ( en == GL_FIRST_TO_REST_NV ) return "GL_FIRST_TO_REST_NV";
#endif
#ifdef GL_PATH_GEN_MODE_NV
	if ( en == GL_PATH_GEN_MODE_NV ) return "GL_PATH_GEN_MODE_NV";
#endif
#ifdef GL_PATH_GEN_COEFF_NV
	if ( en == GL_PATH_GEN_COEFF_NV ) return "GL_PATH_GEN_COEFF_NV";
#endif
#ifdef GL_PATH_GEN_COLOR_FORMAT_NV
	if ( en == GL_PATH_GEN_COLOR_FORMAT_NV ) return "GL_PATH_GEN_COLOR_FORMAT_NV";
#endif
#ifdef GL_PATH_GEN_COMPONENTS_NV
	if ( en == GL_PATH_GEN_COMPONENTS_NV ) return "GL_PATH_GEN_COMPONENTS_NV";
#endif
#ifdef GL_PATH_DASH_OFFSET_RESET_NV
	if ( en == GL_PATH_DASH_OFFSET_RESET_NV ) return "GL_PATH_DASH_OFFSET_RESET_NV";
#endif
#ifdef GL_MOVE_TO_RESETS_NV
	if ( en == GL_MOVE_TO_RESETS_NV ) return "GL_MOVE_TO_RESETS_NV";
#endif
#ifdef GL_MOVE_TO_CONTINUES_NV
	if ( en == GL_MOVE_TO_CONTINUES_NV ) return "GL_MOVE_TO_CONTINUES_NV";
#endif
#ifdef GL_PATH_STENCIL_FUNC_NV
	if ( en == GL_PATH_STENCIL_FUNC_NV ) return "GL_PATH_STENCIL_FUNC_NV";
#endif
#ifdef GL_PATH_STENCIL_REF_NV
	if ( en == GL_PATH_STENCIL_REF_NV ) return "GL_PATH_STENCIL_REF_NV";
#endif
#ifdef GL_PATH_STENCIL_VALUE_MASK_NV
	if ( en == GL_PATH_STENCIL_VALUE_MASK_NV ) return "GL_PATH_STENCIL_VALUE_MASK_NV";
#endif
#ifdef GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV
	if ( en == GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV ) return "GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV";
#endif
#ifdef GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV
	if ( en == GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV ) return "GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV";
#endif
#ifdef GL_PATH_COVER_DEPTH_FUNC_NV
	if ( en == GL_PATH_COVER_DEPTH_FUNC_NV ) return "GL_PATH_COVER_DEPTH_FUNC_NV";
#endif
#ifdef GL_FONT_X_MIN_BOUNDS_BIT_NV
	if ( en == GL_FONT_X_MIN_BOUNDS_BIT_NV ) return "GL_FONT_X_MIN_BOUNDS_BIT_NV";
#endif
#ifdef GL_FONT_Y_MIN_BOUNDS_BIT_NV
	if ( en == GL_FONT_Y_MIN_BOUNDS_BIT_NV ) return "GL_FONT_Y_MIN_BOUNDS_BIT_NV";
#endif
#ifdef GL_FONT_X_MAX_BOUNDS_BIT_NV
	if ( en == GL_FONT_X_MAX_BOUNDS_BIT_NV ) return "GL_FONT_X_MAX_BOUNDS_BIT_NV";
#endif
#ifdef GL_FONT_Y_MAX_BOUNDS_BIT_NV
	if ( en == GL_FONT_Y_MAX_BOUNDS_BIT_NV ) return "GL_FONT_Y_MAX_BOUNDS_BIT_NV";
#endif
#ifdef GL_FONT_UNITS_PER_EM_BIT_NV
	if ( en == GL_FONT_UNITS_PER_EM_BIT_NV ) return "GL_FONT_UNITS_PER_EM_BIT_NV";
#endif
#ifdef GL_FONT_ASCENDER_BIT_NV
	if ( en == GL_FONT_ASCENDER_BIT_NV ) return "GL_FONT_ASCENDER_BIT_NV";
#endif
#ifdef GL_FONT_DESCENDER_BIT_NV
	if ( en == GL_FONT_DESCENDER_BIT_NV ) return "GL_FONT_DESCENDER_BIT_NV";
#endif
#ifdef GL_FONT_HEIGHT_BIT_NV
	if ( en == GL_FONT_HEIGHT_BIT_NV ) return "GL_FONT_HEIGHT_BIT_NV";
#endif
#ifdef GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV
	if ( en == GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV ) return "GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV";
#endif
#ifdef GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV
	if ( en == GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV ) return "GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV";
#endif
#ifdef GL_FONT_UNDERLINE_POSITION_BIT_NV
	if ( en == GL_FONT_UNDERLINE_POSITION_BIT_NV ) return "GL_FONT_UNDERLINE_POSITION_BIT_NV";
#endif
#ifdef GL_FONT_UNDERLINE_THICKNESS_BIT_NV
	if ( en == GL_FONT_UNDERLINE_THICKNESS_BIT_NV ) return "GL_FONT_UNDERLINE_THICKNESS_BIT_NV";
#endif
#ifdef GL_FONT_HAS_KERNING_BIT_NV
	if ( en == GL_FONT_HAS_KERNING_BIT_NV ) return "GL_FONT_HAS_KERNING_BIT_NV";
#endif
#ifdef GL_WRITE_PIXEL_DATA_RANGE_NV
	if ( en == GL_WRITE_PIXEL_DATA_RANGE_NV ) return "GL_WRITE_PIXEL_DATA_RANGE_NV";
#endif
#ifdef GL_READ_PIXEL_DATA_RANGE_NV
	if ( en == GL_READ_PIXEL_DATA_RANGE_NV ) return "GL_READ_PIXEL_DATA_RANGE_NV";
#endif
#ifdef GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV
	if ( en == GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV ) return "GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV";
#endif
#ifdef GL_READ_PIXEL_DATA_RANGE_LENGTH_NV
	if ( en == GL_READ_PIXEL_DATA_RANGE_LENGTH_NV ) return "GL_READ_PIXEL_DATA_RANGE_LENGTH_NV";
#endif
#ifdef GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV
	if ( en == GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV ) return "GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV";
#endif
#ifdef GL_READ_PIXEL_DATA_RANGE_POINTER_NV
	if ( en == GL_READ_PIXEL_DATA_RANGE_POINTER_NV ) return "GL_READ_PIXEL_DATA_RANGE_POINTER_NV";
#endif
#ifdef GL_POINT_SPRITE_NV
	if ( en == GL_POINT_SPRITE_NV ) return "GL_POINT_SPRITE_NV";
#endif
#ifdef GL_COORD_REPLACE_NV
	if ( en == GL_COORD_REPLACE_NV ) return "GL_COORD_REPLACE_NV";
#endif
#ifdef GL_POINT_SPRITE_R_MODE_NV
	if ( en == GL_POINT_SPRITE_R_MODE_NV ) return "GL_POINT_SPRITE_R_MODE_NV";
#endif
#ifdef GL_FRAME_NV
	if ( en == GL_FRAME_NV ) return "GL_FRAME_NV";
#endif
#ifdef GL_FIELDS_NV
	if ( en == GL_FIELDS_NV ) return "GL_FIELDS_NV";
#endif
#ifdef GL_CURRENT_TIME_NV
	if ( en == GL_CURRENT_TIME_NV ) return "GL_CURRENT_TIME_NV";
#endif
#ifdef GL_NUM_FILL_STREAMS_NV
	if ( en == GL_NUM_FILL_STREAMS_NV ) return "GL_NUM_FILL_STREAMS_NV";
#endif
#ifdef GL_PRESENT_TIME_NV
	if ( en == GL_PRESENT_TIME_NV ) return "GL_PRESENT_TIME_NV";
#endif
#ifdef GL_PRESENT_DURATION_NV
	if ( en == GL_PRESENT_DURATION_NV ) return "GL_PRESENT_DURATION_NV";
#endif
#ifdef GL_PRIMITIVE_RESTART_NV
	if ( en == GL_PRIMITIVE_RESTART_NV ) return "GL_PRIMITIVE_RESTART_NV";
#endif
#ifdef GL_PRIMITIVE_RESTART_INDEX_NV
	if ( en == GL_PRIMITIVE_RESTART_INDEX_NV ) return "GL_PRIMITIVE_RESTART_INDEX_NV";
#endif
#ifdef GL_REGISTER_COMBINERS_NV
	if ( en == GL_REGISTER_COMBINERS_NV ) return "GL_REGISTER_COMBINERS_NV";
#endif
#ifdef GL_VARIABLE_A_NV
	if ( en == GL_VARIABLE_A_NV ) return "GL_VARIABLE_A_NV";
#endif
#ifdef GL_VARIABLE_B_NV
	if ( en == GL_VARIABLE_B_NV ) return "GL_VARIABLE_B_NV";
#endif
#ifdef GL_VARIABLE_C_NV
	if ( en == GL_VARIABLE_C_NV ) return "GL_VARIABLE_C_NV";
#endif
#ifdef GL_VARIABLE_D_NV
	if ( en == GL_VARIABLE_D_NV ) return "GL_VARIABLE_D_NV";
#endif
#ifdef GL_VARIABLE_E_NV
	if ( en == GL_VARIABLE_E_NV ) return "GL_VARIABLE_E_NV";
#endif
#ifdef GL_VARIABLE_F_NV
	if ( en == GL_VARIABLE_F_NV ) return "GL_VARIABLE_F_NV";
#endif
#ifdef GL_VARIABLE_G_NV
	if ( en == GL_VARIABLE_G_NV ) return "GL_VARIABLE_G_NV";
#endif
#ifdef GL_CONSTANT_COLOR0_NV
	if ( en == GL_CONSTANT_COLOR0_NV ) return "GL_CONSTANT_COLOR0_NV";
#endif
#ifdef GL_CONSTANT_COLOR1_NV
	if ( en == GL_CONSTANT_COLOR1_NV ) return "GL_CONSTANT_COLOR1_NV";
#endif
#ifdef GL_PRIMARY_COLOR_NV
	if ( en == GL_PRIMARY_COLOR_NV ) return "GL_PRIMARY_COLOR_NV";
#endif
#ifdef GL_SECONDARY_COLOR_NV
	if ( en == GL_SECONDARY_COLOR_NV ) return "GL_SECONDARY_COLOR_NV";
#endif
#ifdef GL_SPARE0_NV
	if ( en == GL_SPARE0_NV ) return "GL_SPARE0_NV";
#endif
#ifdef GL_SPARE1_NV
	if ( en == GL_SPARE1_NV ) return "GL_SPARE1_NV";
#endif
#ifdef GL_DISCARD_NV
	if ( en == GL_DISCARD_NV ) return "GL_DISCARD_NV";
#endif
#ifdef GL_E_TIMES_F_NV
	if ( en == GL_E_TIMES_F_NV ) return "GL_E_TIMES_F_NV";
#endif
#ifdef GL_SPARE0_PLUS_SECONDARY_COLOR_NV
	if ( en == GL_SPARE0_PLUS_SECONDARY_COLOR_NV ) return "GL_SPARE0_PLUS_SECONDARY_COLOR_NV";
#endif
#ifdef GL_UNSIGNED_IDENTITY_NV
	if ( en == GL_UNSIGNED_IDENTITY_NV ) return "GL_UNSIGNED_IDENTITY_NV";
#endif
#ifdef GL_UNSIGNED_INVERT_NV
	if ( en == GL_UNSIGNED_INVERT_NV ) return "GL_UNSIGNED_INVERT_NV";
#endif
#ifdef GL_EXPAND_NORMAL_NV
	if ( en == GL_EXPAND_NORMAL_NV ) return "GL_EXPAND_NORMAL_NV";
#endif
#ifdef GL_EXPAND_NEGATE_NV
	if ( en == GL_EXPAND_NEGATE_NV ) return "GL_EXPAND_NEGATE_NV";
#endif
#ifdef GL_HALF_BIAS_NORMAL_NV
	if ( en == GL_HALF_BIAS_NORMAL_NV ) return "GL_HALF_BIAS_NORMAL_NV";
#endif
#ifdef GL_HALF_BIAS_NEGATE_NV
	if ( en == GL_HALF_BIAS_NEGATE_NV ) return "GL_HALF_BIAS_NEGATE_NV";
#endif
#ifdef GL_SIGNED_IDENTITY_NV
	if ( en == GL_SIGNED_IDENTITY_NV ) return "GL_SIGNED_IDENTITY_NV";
#endif
#ifdef GL_SIGNED_NEGATE_NV
	if ( en == GL_SIGNED_NEGATE_NV ) return "GL_SIGNED_NEGATE_NV";
#endif
#ifdef GL_SCALE_BY_TWO_NV
	if ( en == GL_SCALE_BY_TWO_NV ) return "GL_SCALE_BY_TWO_NV";
#endif
#ifdef GL_SCALE_BY_FOUR_NV
	if ( en == GL_SCALE_BY_FOUR_NV ) return "GL_SCALE_BY_FOUR_NV";
#endif
#ifdef GL_SCALE_BY_ONE_HALF_NV
	if ( en == GL_SCALE_BY_ONE_HALF_NV ) return "GL_SCALE_BY_ONE_HALF_NV";
#endif
#ifdef GL_BIAS_BY_NEGATIVE_ONE_HALF_NV
	if ( en == GL_BIAS_BY_NEGATIVE_ONE_HALF_NV ) return "GL_BIAS_BY_NEGATIVE_ONE_HALF_NV";
#endif
#ifdef GL_COMBINER_INPUT_NV
	if ( en == GL_COMBINER_INPUT_NV ) return "GL_COMBINER_INPUT_NV";
#endif
#ifdef GL_COMBINER_MAPPING_NV
	if ( en == GL_COMBINER_MAPPING_NV ) return "GL_COMBINER_MAPPING_NV";
#endif
#ifdef GL_COMBINER_COMPONENT_USAGE_NV
	if ( en == GL_COMBINER_COMPONENT_USAGE_NV ) return "GL_COMBINER_COMPONENT_USAGE_NV";
#endif
#ifdef GL_COMBINER_AB_DOT_PRODUCT_NV
	if ( en == GL_COMBINER_AB_DOT_PRODUCT_NV ) return "GL_COMBINER_AB_DOT_PRODUCT_NV";
#endif
#ifdef GL_COMBINER_CD_DOT_PRODUCT_NV
	if ( en == GL_COMBINER_CD_DOT_PRODUCT_NV ) return "GL_COMBINER_CD_DOT_PRODUCT_NV";
#endif
#ifdef GL_COMBINER_MUX_SUM_NV
	if ( en == GL_COMBINER_MUX_SUM_NV ) return "GL_COMBINER_MUX_SUM_NV";
#endif
#ifdef GL_COMBINER_SCALE_NV
	if ( en == GL_COMBINER_SCALE_NV ) return "GL_COMBINER_SCALE_NV";
#endif
#ifdef GL_COMBINER_BIAS_NV
	if ( en == GL_COMBINER_BIAS_NV ) return "GL_COMBINER_BIAS_NV";
#endif
#ifdef GL_COMBINER_AB_OUTPUT_NV
	if ( en == GL_COMBINER_AB_OUTPUT_NV ) return "GL_COMBINER_AB_OUTPUT_NV";
#endif
#ifdef GL_COMBINER_CD_OUTPUT_NV
	if ( en == GL_COMBINER_CD_OUTPUT_NV ) return "GL_COMBINER_CD_OUTPUT_NV";
#endif
#ifdef GL_COMBINER_SUM_OUTPUT_NV
	if ( en == GL_COMBINER_SUM_OUTPUT_NV ) return "GL_COMBINER_SUM_OUTPUT_NV";
#endif
#ifdef GL_MAX_GENERAL_COMBINERS_NV
	if ( en == GL_MAX_GENERAL_COMBINERS_NV ) return "GL_MAX_GENERAL_COMBINERS_NV";
#endif
#ifdef GL_NUM_GENERAL_COMBINERS_NV
	if ( en == GL_NUM_GENERAL_COMBINERS_NV ) return "GL_NUM_GENERAL_COMBINERS_NV";
#endif
#ifdef GL_COLOR_SUM_CLAMP_NV
	if ( en == GL_COLOR_SUM_CLAMP_NV ) return "GL_COLOR_SUM_CLAMP_NV";
#endif
#ifdef GL_COMBINER0_NV
	if ( en == GL_COMBINER0_NV ) return "GL_COMBINER0_NV";
#endif
#ifdef GL_COMBINER1_NV
	if ( en == GL_COMBINER1_NV ) return "GL_COMBINER1_NV";
#endif
#ifdef GL_COMBINER2_NV
	if ( en == GL_COMBINER2_NV ) return "GL_COMBINER2_NV";
#endif
#ifdef GL_COMBINER3_NV
	if ( en == GL_COMBINER3_NV ) return "GL_COMBINER3_NV";
#endif
#ifdef GL_COMBINER4_NV
	if ( en == GL_COMBINER4_NV ) return "GL_COMBINER4_NV";
#endif
#ifdef GL_COMBINER5_NV
	if ( en == GL_COMBINER5_NV ) return "GL_COMBINER5_NV";
#endif
#ifdef GL_COMBINER6_NV
	if ( en == GL_COMBINER6_NV ) return "GL_COMBINER6_NV";
#endif
#ifdef GL_COMBINER7_NV
	if ( en == GL_COMBINER7_NV ) return "GL_COMBINER7_NV";
#endif
#ifdef GL_PER_STAGE_CONSTANTS_NV
	if ( en == GL_PER_STAGE_CONSTANTS_NV ) return "GL_PER_STAGE_CONSTANTS_NV";
#endif
#ifdef GL_BUFFER_GPU_ADDRESS_NV
	if ( en == GL_BUFFER_GPU_ADDRESS_NV ) return "GL_BUFFER_GPU_ADDRESS_NV";
#endif
#ifdef GL_GPU_ADDRESS_NV
	if ( en == GL_GPU_ADDRESS_NV ) return "GL_GPU_ADDRESS_NV";
#endif
#ifdef GL_MAX_SHADER_BUFFER_ADDRESS_NV
	if ( en == GL_MAX_SHADER_BUFFER_ADDRESS_NV ) return "GL_MAX_SHADER_BUFFER_ADDRESS_NV";
#endif
#ifdef GL_MAX_PROGRAM_PATCH_ATTRIBS_NV
	if ( en == GL_MAX_PROGRAM_PATCH_ATTRIBS_NV ) return "GL_MAX_PROGRAM_PATCH_ATTRIBS_NV";
#endif
#ifdef GL_TESS_CONTROL_PROGRAM_NV
	if ( en == GL_TESS_CONTROL_PROGRAM_NV ) return "GL_TESS_CONTROL_PROGRAM_NV";
#endif
#ifdef GL_TESS_EVALUATION_PROGRAM_NV
	if ( en == GL_TESS_EVALUATION_PROGRAM_NV ) return "GL_TESS_EVALUATION_PROGRAM_NV";
#endif
#ifdef GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV
	if ( en == GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV ) return "GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV";
#endif
#ifdef GL_EMBOSS_LIGHT_NV
	if ( en == GL_EMBOSS_LIGHT_NV ) return "GL_EMBOSS_LIGHT_NV";
#endif
#ifdef GL_EMBOSS_CONSTANT_NV
	if ( en == GL_EMBOSS_CONSTANT_NV ) return "GL_EMBOSS_CONSTANT_NV";
#endif
#ifdef GL_EMBOSS_MAP_NV
	if ( en == GL_EMBOSS_MAP_NV ) return "GL_EMBOSS_MAP_NV";
#endif
#ifdef GL_NORMAL_MAP_NV
	if ( en == GL_NORMAL_MAP_NV ) return "GL_NORMAL_MAP_NV";
#endif
#ifdef GL_REFLECTION_MAP_NV
	if ( en == GL_REFLECTION_MAP_NV ) return "GL_REFLECTION_MAP_NV";
#endif
#ifdef GL_COMBINE4_NV
	if ( en == GL_COMBINE4_NV ) return "GL_COMBINE4_NV";
#endif
#ifdef GL_SOURCE3_RGB_NV
	if ( en == GL_SOURCE3_RGB_NV ) return "GL_SOURCE3_RGB_NV";
#endif
#ifdef GL_SOURCE3_ALPHA_NV
	if ( en == GL_SOURCE3_ALPHA_NV ) return "GL_SOURCE3_ALPHA_NV";
#endif
#ifdef GL_OPERAND3_RGB_NV
	if ( en == GL_OPERAND3_RGB_NV ) return "GL_OPERAND3_RGB_NV";
#endif
#ifdef GL_OPERAND3_ALPHA_NV
	if ( en == GL_OPERAND3_ALPHA_NV ) return "GL_OPERAND3_ALPHA_NV";
#endif
#ifdef GL_TEXTURE_UNSIGNED_REMAP_MODE_NV
	if ( en == GL_TEXTURE_UNSIGNED_REMAP_MODE_NV ) return "GL_TEXTURE_UNSIGNED_REMAP_MODE_NV";
#endif
#ifdef GL_TEXTURE_COVERAGE_SAMPLES_NV
	if ( en == GL_TEXTURE_COVERAGE_SAMPLES_NV ) return "GL_TEXTURE_COVERAGE_SAMPLES_NV";
#endif
#ifdef GL_TEXTURE_COLOR_SAMPLES_NV
	if ( en == GL_TEXTURE_COLOR_SAMPLES_NV ) return "GL_TEXTURE_COLOR_SAMPLES_NV";
#endif
#ifdef GL_TEXTURE_RECTANGLE_NV
	if ( en == GL_TEXTURE_RECTANGLE_NV ) return "GL_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_TEXTURE_BINDING_RECTANGLE_NV
	if ( en == GL_TEXTURE_BINDING_RECTANGLE_NV ) return "GL_TEXTURE_BINDING_RECTANGLE_NV";
#endif
#ifdef GL_PROXY_TEXTURE_RECTANGLE_NV
	if ( en == GL_PROXY_TEXTURE_RECTANGLE_NV ) return "GL_PROXY_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_MAX_RECTANGLE_TEXTURE_SIZE_NV
	if ( en == GL_MAX_RECTANGLE_TEXTURE_SIZE_NV ) return "GL_MAX_RECTANGLE_TEXTURE_SIZE_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_RECTANGLE_NV
	if ( en == GL_OFFSET_TEXTURE_RECTANGLE_NV ) return "GL_OFFSET_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV
	if ( en == GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV ) return "GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV";
#endif
#ifdef GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV
	if ( en == GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV ) return "GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV
	if ( en == GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV ) return "GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV";
#endif
#ifdef GL_UNSIGNED_INT_S8_S8_8_8_NV
	if ( en == GL_UNSIGNED_INT_S8_S8_8_8_NV ) return "GL_UNSIGNED_INT_S8_S8_8_8_NV";
#endif
#ifdef GL_UNSIGNED_INT_8_8_S8_S8_REV_NV
	if ( en == GL_UNSIGNED_INT_8_8_S8_S8_REV_NV ) return "GL_UNSIGNED_INT_8_8_S8_S8_REV_NV";
#endif
#ifdef GL_DSDT_MAG_INTENSITY_NV
	if ( en == GL_DSDT_MAG_INTENSITY_NV ) return "GL_DSDT_MAG_INTENSITY_NV";
#endif
#ifdef GL_SHADER_CONSISTENT_NV
	if ( en == GL_SHADER_CONSISTENT_NV ) return "GL_SHADER_CONSISTENT_NV";
#endif
#ifdef GL_TEXTURE_SHADER_NV
	if ( en == GL_TEXTURE_SHADER_NV ) return "GL_TEXTURE_SHADER_NV";
#endif
#ifdef GL_SHADER_OPERATION_NV
	if ( en == GL_SHADER_OPERATION_NV ) return "GL_SHADER_OPERATION_NV";
#endif
#ifdef GL_CULL_MODES_NV
	if ( en == GL_CULL_MODES_NV ) return "GL_CULL_MODES_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_2D_MATRIX_NV
	if ( en == GL_OFFSET_TEXTURE_2D_MATRIX_NV ) return "GL_OFFSET_TEXTURE_2D_MATRIX_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_MATRIX_NV
	if ( en == GL_OFFSET_TEXTURE_MATRIX_NV ) return "GL_OFFSET_TEXTURE_MATRIX_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_2D_SCALE_NV
	if ( en == GL_OFFSET_TEXTURE_2D_SCALE_NV ) return "GL_OFFSET_TEXTURE_2D_SCALE_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_SCALE_NV
	if ( en == GL_OFFSET_TEXTURE_SCALE_NV ) return "GL_OFFSET_TEXTURE_SCALE_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_BIAS_NV
	if ( en == GL_OFFSET_TEXTURE_BIAS_NV ) return "GL_OFFSET_TEXTURE_BIAS_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_2D_BIAS_NV
	if ( en == GL_OFFSET_TEXTURE_2D_BIAS_NV ) return "GL_OFFSET_TEXTURE_2D_BIAS_NV";
#endif
#ifdef GL_PREVIOUS_TEXTURE_INPUT_NV
	if ( en == GL_PREVIOUS_TEXTURE_INPUT_NV ) return "GL_PREVIOUS_TEXTURE_INPUT_NV";
#endif
#ifdef GL_CONST_EYE_NV
	if ( en == GL_CONST_EYE_NV ) return "GL_CONST_EYE_NV";
#endif
#ifdef GL_PASS_THROUGH_NV
	if ( en == GL_PASS_THROUGH_NV ) return "GL_PASS_THROUGH_NV";
#endif
#ifdef GL_CULL_FRAGMENT_NV
	if ( en == GL_CULL_FRAGMENT_NV ) return "GL_CULL_FRAGMENT_NV";
#endif
#ifdef GL_OFFSET_TEXTURE_2D_NV
	if ( en == GL_OFFSET_TEXTURE_2D_NV ) return "GL_OFFSET_TEXTURE_2D_NV";
#endif
#ifdef GL_DEPENDENT_AR_TEXTURE_2D_NV
	if ( en == GL_DEPENDENT_AR_TEXTURE_2D_NV ) return "GL_DEPENDENT_AR_TEXTURE_2D_NV";
#endif
#ifdef GL_DEPENDENT_GB_TEXTURE_2D_NV
	if ( en == GL_DEPENDENT_GB_TEXTURE_2D_NV ) return "GL_DEPENDENT_GB_TEXTURE_2D_NV";
#endif
#ifdef GL_DOT_PRODUCT_NV
	if ( en == GL_DOT_PRODUCT_NV ) return "GL_DOT_PRODUCT_NV";
#endif
#ifdef GL_DOT_PRODUCT_DEPTH_REPLACE_NV
	if ( en == GL_DOT_PRODUCT_DEPTH_REPLACE_NV ) return "GL_DOT_PRODUCT_DEPTH_REPLACE_NV";
#endif
#ifdef GL_DOT_PRODUCT_TEXTURE_2D_NV
	if ( en == GL_DOT_PRODUCT_TEXTURE_2D_NV ) return "GL_DOT_PRODUCT_TEXTURE_2D_NV";
#endif
#ifdef GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV
	if ( en == GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV ) return "GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV";
#endif
#ifdef GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV
	if ( en == GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV ) return "GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV";
#endif
#ifdef GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV
	if ( en == GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV ) return "GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV";
#endif
#ifdef GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV
	if ( en == GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV ) return "GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV";
#endif
#ifdef GL_HILO_NV
	if ( en == GL_HILO_NV ) return "GL_HILO_NV";
#endif
#ifdef GL_DSDT_NV
	if ( en == GL_DSDT_NV ) return "GL_DSDT_NV";
#endif
#ifdef GL_DSDT_MAG_NV
	if ( en == GL_DSDT_MAG_NV ) return "GL_DSDT_MAG_NV";
#endif
#ifdef GL_DSDT_MAG_VIB_NV
	if ( en == GL_DSDT_MAG_VIB_NV ) return "GL_DSDT_MAG_VIB_NV";
#endif
#ifdef GL_HILO16_NV
	if ( en == GL_HILO16_NV ) return "GL_HILO16_NV";
#endif
#ifdef GL_SIGNED_HILO_NV
	if ( en == GL_SIGNED_HILO_NV ) return "GL_SIGNED_HILO_NV";
#endif
#ifdef GL_SIGNED_HILO16_NV
	if ( en == GL_SIGNED_HILO16_NV ) return "GL_SIGNED_HILO16_NV";
#endif
#ifdef GL_SIGNED_RGBA_NV
	if ( en == GL_SIGNED_RGBA_NV ) return "GL_SIGNED_RGBA_NV";
#endif
#ifdef GL_SIGNED_RGBA8_NV
	if ( en == GL_SIGNED_RGBA8_NV ) return "GL_SIGNED_RGBA8_NV";
#endif
#ifdef GL_SIGNED_RGB_NV
	if ( en == GL_SIGNED_RGB_NV ) return "GL_SIGNED_RGB_NV";
#endif
#ifdef GL_SIGNED_RGB8_NV
	if ( en == GL_SIGNED_RGB8_NV ) return "GL_SIGNED_RGB8_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE_NV
	if ( en == GL_SIGNED_LUMINANCE_NV ) return "GL_SIGNED_LUMINANCE_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE8_NV
	if ( en == GL_SIGNED_LUMINANCE8_NV ) return "GL_SIGNED_LUMINANCE8_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE_ALPHA_NV
	if ( en == GL_SIGNED_LUMINANCE_ALPHA_NV ) return "GL_SIGNED_LUMINANCE_ALPHA_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE8_ALPHA8_NV
	if ( en == GL_SIGNED_LUMINANCE8_ALPHA8_NV ) return "GL_SIGNED_LUMINANCE8_ALPHA8_NV";
#endif
#ifdef GL_SIGNED_ALPHA_NV
	if ( en == GL_SIGNED_ALPHA_NV ) return "GL_SIGNED_ALPHA_NV";
#endif
#ifdef GL_SIGNED_ALPHA8_NV
	if ( en == GL_SIGNED_ALPHA8_NV ) return "GL_SIGNED_ALPHA8_NV";
#endif
#ifdef GL_SIGNED_INTENSITY_NV
	if ( en == GL_SIGNED_INTENSITY_NV ) return "GL_SIGNED_INTENSITY_NV";
#endif
#ifdef GL_SIGNED_INTENSITY8_NV
	if ( en == GL_SIGNED_INTENSITY8_NV ) return "GL_SIGNED_INTENSITY8_NV";
#endif
#ifdef GL_DSDT8_NV
	if ( en == GL_DSDT8_NV ) return "GL_DSDT8_NV";
#endif
#ifdef GL_DSDT8_MAG8_NV
	if ( en == GL_DSDT8_MAG8_NV ) return "GL_DSDT8_MAG8_NV";
#endif
#ifdef GL_DSDT8_MAG8_INTENSITY8_NV
	if ( en == GL_DSDT8_MAG8_INTENSITY8_NV ) return "GL_DSDT8_MAG8_INTENSITY8_NV";
#endif
#ifdef GL_SIGNED_RGB_UNSIGNED_ALPHA_NV
	if ( en == GL_SIGNED_RGB_UNSIGNED_ALPHA_NV ) return "GL_SIGNED_RGB_UNSIGNED_ALPHA_NV";
#endif
#ifdef GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV
	if ( en == GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV ) return "GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV";
#endif
#ifdef GL_HI_SCALE_NV
	if ( en == GL_HI_SCALE_NV ) return "GL_HI_SCALE_NV";
#endif
#ifdef GL_LO_SCALE_NV
	if ( en == GL_LO_SCALE_NV ) return "GL_LO_SCALE_NV";
#endif
#ifdef GL_DS_SCALE_NV
	if ( en == GL_DS_SCALE_NV ) return "GL_DS_SCALE_NV";
#endif
#ifdef GL_DT_SCALE_NV
	if ( en == GL_DT_SCALE_NV ) return "GL_DT_SCALE_NV";
#endif
#ifdef GL_MAGNITUDE_SCALE_NV
	if ( en == GL_MAGNITUDE_SCALE_NV ) return "GL_MAGNITUDE_SCALE_NV";
#endif
#ifdef GL_VIBRANCE_SCALE_NV
	if ( en == GL_VIBRANCE_SCALE_NV ) return "GL_VIBRANCE_SCALE_NV";
#endif
#ifdef GL_HI_BIAS_NV
	if ( en == GL_HI_BIAS_NV ) return "GL_HI_BIAS_NV";
#endif
#ifdef GL_LO_BIAS_NV
	if ( en == GL_LO_BIAS_NV ) return "GL_LO_BIAS_NV";
#endif
#ifdef GL_DS_BIAS_NV
	if ( en == GL_DS_BIAS_NV ) return "GL_DS_BIAS_NV";
#endif
#ifdef GL_DT_BIAS_NV
	if ( en == GL_DT_BIAS_NV ) return "GL_DT_BIAS_NV";
#endif
#ifdef GL_MAGNITUDE_BIAS_NV
	if ( en == GL_MAGNITUDE_BIAS_NV ) return "GL_MAGNITUDE_BIAS_NV";
#endif
#ifdef GL_VIBRANCE_BIAS_NV
	if ( en == GL_VIBRANCE_BIAS_NV ) return "GL_VIBRANCE_BIAS_NV";
#endif
#ifdef GL_TEXTURE_BORDER_VALUES_NV
	if ( en == GL_TEXTURE_BORDER_VALUES_NV ) return "GL_TEXTURE_BORDER_VALUES_NV";
#endif
#ifdef GL_TEXTURE_HI_SIZE_NV
	if ( en == GL_TEXTURE_HI_SIZE_NV ) return "GL_TEXTURE_HI_SIZE_NV";
#endif
#ifdef GL_TEXTURE_LO_SIZE_NV
	if ( en == GL_TEXTURE_LO_SIZE_NV ) return "GL_TEXTURE_LO_SIZE_NV";
#endif
#ifdef GL_TEXTURE_DS_SIZE_NV
	if ( en == GL_TEXTURE_DS_SIZE_NV ) return "GL_TEXTURE_DS_SIZE_NV";
#endif
#ifdef GL_TEXTURE_DT_SIZE_NV
	if ( en == GL_TEXTURE_DT_SIZE_NV ) return "GL_TEXTURE_DT_SIZE_NV";
#endif
#ifdef GL_TEXTURE_MAG_SIZE_NV
	if ( en == GL_TEXTURE_MAG_SIZE_NV ) return "GL_TEXTURE_MAG_SIZE_NV";
#endif
#ifdef GL_UNSIGNED_INT_S8_S8_8_8_NV
	if ( en == GL_UNSIGNED_INT_S8_S8_8_8_NV ) return "GL_UNSIGNED_INT_S8_S8_8_8_NV";
#endif
#ifdef GL_UNSIGNED_INT_8_8_S8_S8_REV_NV
	if ( en == GL_UNSIGNED_INT_8_8_S8_S8_REV_NV ) return "GL_UNSIGNED_INT_8_8_S8_S8_REV_NV";
#endif
#ifdef GL_DSDT_MAG_INTENSITY_NV
	if ( en == GL_DSDT_MAG_INTENSITY_NV ) return "GL_DSDT_MAG_INTENSITY_NV";
#endif
#ifdef GL_DOT_PRODUCT_TEXTURE_3D_NV
	if ( en == GL_DOT_PRODUCT_TEXTURE_3D_NV ) return "GL_DOT_PRODUCT_TEXTURE_3D_NV";
#endif
#ifdef GL_HILO_NV
	if ( en == GL_HILO_NV ) return "GL_HILO_NV";
#endif
#ifdef GL_DSDT_NV
	if ( en == GL_DSDT_NV ) return "GL_DSDT_NV";
#endif
#ifdef GL_DSDT_MAG_NV
	if ( en == GL_DSDT_MAG_NV ) return "GL_DSDT_MAG_NV";
#endif
#ifdef GL_DSDT_MAG_VIB_NV
	if ( en == GL_DSDT_MAG_VIB_NV ) return "GL_DSDT_MAG_VIB_NV";
#endif
#ifdef GL_HILO16_NV
	if ( en == GL_HILO16_NV ) return "GL_HILO16_NV";
#endif
#ifdef GL_SIGNED_HILO_NV
	if ( en == GL_SIGNED_HILO_NV ) return "GL_SIGNED_HILO_NV";
#endif
#ifdef GL_SIGNED_HILO16_NV
	if ( en == GL_SIGNED_HILO16_NV ) return "GL_SIGNED_HILO16_NV";
#endif
#ifdef GL_SIGNED_RGBA_NV
	if ( en == GL_SIGNED_RGBA_NV ) return "GL_SIGNED_RGBA_NV";
#endif
#ifdef GL_SIGNED_RGBA8_NV
	if ( en == GL_SIGNED_RGBA8_NV ) return "GL_SIGNED_RGBA8_NV";
#endif
#ifdef GL_SIGNED_RGB_NV
	if ( en == GL_SIGNED_RGB_NV ) return "GL_SIGNED_RGB_NV";
#endif
#ifdef GL_SIGNED_RGB8_NV
	if ( en == GL_SIGNED_RGB8_NV ) return "GL_SIGNED_RGB8_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE_NV
	if ( en == GL_SIGNED_LUMINANCE_NV ) return "GL_SIGNED_LUMINANCE_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE8_NV
	if ( en == GL_SIGNED_LUMINANCE8_NV ) return "GL_SIGNED_LUMINANCE8_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE_ALPHA_NV
	if ( en == GL_SIGNED_LUMINANCE_ALPHA_NV ) return "GL_SIGNED_LUMINANCE_ALPHA_NV";
#endif
#ifdef GL_SIGNED_LUMINANCE8_ALPHA8_NV
	if ( en == GL_SIGNED_LUMINANCE8_ALPHA8_NV ) return "GL_SIGNED_LUMINANCE8_ALPHA8_NV";
#endif
#ifdef GL_SIGNED_ALPHA_NV
	if ( en == GL_SIGNED_ALPHA_NV ) return "GL_SIGNED_ALPHA_NV";
#endif
#ifdef GL_SIGNED_ALPHA8_NV
	if ( en == GL_SIGNED_ALPHA8_NV ) return "GL_SIGNED_ALPHA8_NV";
#endif
#ifdef GL_SIGNED_INTENSITY_NV
	if ( en == GL_SIGNED_INTENSITY_NV ) return "GL_SIGNED_INTENSITY_NV";
#endif
#ifdef GL_SIGNED_INTENSITY8_NV
	if ( en == GL_SIGNED_INTENSITY8_NV ) return "GL_SIGNED_INTENSITY8_NV";
#endif
#ifdef GL_DSDT8_NV
	if ( en == GL_DSDT8_NV ) return "GL_DSDT8_NV";
#endif
#ifdef GL_DSDT8_MAG8_NV
	if ( en == GL_DSDT8_MAG8_NV ) return "GL_DSDT8_MAG8_NV";
#endif
#ifdef GL_DSDT8_MAG8_INTENSITY8_NV
	if ( en == GL_DSDT8_MAG8_INTENSITY8_NV ) return "GL_DSDT8_MAG8_INTENSITY8_NV";
#endif
#ifdef GL_SIGNED_RGB_UNSIGNED_ALPHA_NV
	if ( en == GL_SIGNED_RGB_UNSIGNED_ALPHA_NV ) return "GL_SIGNED_RGB_UNSIGNED_ALPHA_NV";
#endif
#ifdef GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV
	if ( en == GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV ) return "GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV";
#endif
#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV
	if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV ) return "GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV";
#endif
#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV
	if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV ) return "GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV";
#endif
#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV
	if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV ) return "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV
	if ( en == GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV ) return "GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV";
#endif
#ifdef GL_OFFSET_HILO_TEXTURE_2D_NV
	if ( en == GL_OFFSET_HILO_TEXTURE_2D_NV ) return "GL_OFFSET_HILO_TEXTURE_2D_NV";
#endif
#ifdef GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV
	if ( en == GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV ) return "GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV
	if ( en == GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV ) return "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV";
#endif
#ifdef GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV
	if ( en == GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV ) return "GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV";
#endif
#ifdef GL_DEPENDENT_HILO_TEXTURE_2D_NV
	if ( en == GL_DEPENDENT_HILO_TEXTURE_2D_NV ) return "GL_DEPENDENT_HILO_TEXTURE_2D_NV";
#endif
#ifdef GL_DEPENDENT_RGB_TEXTURE_3D_NV
	if ( en == GL_DEPENDENT_RGB_TEXTURE_3D_NV ) return "GL_DEPENDENT_RGB_TEXTURE_3D_NV";
#endif
#ifdef GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV
	if ( en == GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV ) return "GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV";
#endif
#ifdef GL_DOT_PRODUCT_PASS_THROUGH_NV
	if ( en == GL_DOT_PRODUCT_PASS_THROUGH_NV ) return "GL_DOT_PRODUCT_PASS_THROUGH_NV";
#endif
#ifdef GL_DOT_PRODUCT_TEXTURE_1D_NV
	if ( en == GL_DOT_PRODUCT_TEXTURE_1D_NV ) return "GL_DOT_PRODUCT_TEXTURE_1D_NV";
#endif
#ifdef GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV
	if ( en == GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV ) return "GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV";
#endif
#ifdef GL_HILO8_NV
	if ( en == GL_HILO8_NV ) return "GL_HILO8_NV";
#endif
#ifdef GL_SIGNED_HILO8_NV
	if ( en == GL_SIGNED_HILO8_NV ) return "GL_SIGNED_HILO8_NV";
#endif
#ifdef GL_FORCE_BLUE_TO_ONE_NV
	if ( en == GL_FORCE_BLUE_TO_ONE_NV ) return "GL_FORCE_BLUE_TO_ONE_NV";
#endif
#ifdef GL_BACK_PRIMARY_COLOR_NV
	if ( en == GL_BACK_PRIMARY_COLOR_NV ) return "GL_BACK_PRIMARY_COLOR_NV";
#endif
#ifdef GL_BACK_SECONDARY_COLOR_NV
	if ( en == GL_BACK_SECONDARY_COLOR_NV ) return "GL_BACK_SECONDARY_COLOR_NV";
#endif
#ifdef GL_TEXTURE_COORD_NV
	if ( en == GL_TEXTURE_COORD_NV ) return "GL_TEXTURE_COORD_NV";
#endif
#ifdef GL_CLIP_DISTANCE_NV
	if ( en == GL_CLIP_DISTANCE_NV ) return "GL_CLIP_DISTANCE_NV";
#endif
#ifdef GL_VERTEX_ID_NV
	if ( en == GL_VERTEX_ID_NV ) return "GL_VERTEX_ID_NV";
#endif
#ifdef GL_PRIMITIVE_ID_NV
	if ( en == GL_PRIMITIVE_ID_NV ) return "GL_PRIMITIVE_ID_NV";
#endif
#ifdef GL_GENERIC_ATTRIB_NV
	if ( en == GL_GENERIC_ATTRIB_NV ) return "GL_GENERIC_ATTRIB_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_ATTRIBS_NV
	if ( en == GL_TRANSFORM_FEEDBACK_ATTRIBS_NV ) return "GL_TRANSFORM_FEEDBACK_ATTRIBS_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV";
#endif
#ifdef GL_ACTIVE_VARYINGS_NV
	if ( en == GL_ACTIVE_VARYINGS_NV ) return "GL_ACTIVE_VARYINGS_NV";
#endif
#ifdef GL_ACTIVE_VARYING_MAX_LENGTH_NV
	if ( en == GL_ACTIVE_VARYING_MAX_LENGTH_NV ) return "GL_ACTIVE_VARYING_MAX_LENGTH_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_VARYINGS_NV
	if ( en == GL_TRANSFORM_FEEDBACK_VARYINGS_NV ) return "GL_TRANSFORM_FEEDBACK_VARYINGS_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_START_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_START_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_START_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_RECORD_NV
	if ( en == GL_TRANSFORM_FEEDBACK_RECORD_NV ) return "GL_TRANSFORM_FEEDBACK_RECORD_NV";
#endif
#ifdef GL_PRIMITIVES_GENERATED_NV
	if ( en == GL_PRIMITIVES_GENERATED_NV ) return "GL_PRIMITIVES_GENERATED_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV
	if ( en == GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV ) return "GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV";
#endif
#ifdef GL_RASTERIZER_DISCARD_NV
	if ( en == GL_RASTERIZER_DISCARD_NV ) return "GL_RASTERIZER_DISCARD_NV";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV ) return "GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV";
#endif
#ifdef GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV
	if ( en == GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV ) return "GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV";
#endif
#ifdef GL_INTERLEAVED_ATTRIBS_NV
	if ( en == GL_INTERLEAVED_ATTRIBS_NV ) return "GL_INTERLEAVED_ATTRIBS_NV";
#endif
#ifdef GL_SEPARATE_ATTRIBS_NV
	if ( en == GL_SEPARATE_ATTRIBS_NV ) return "GL_SEPARATE_ATTRIBS_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_NV
	if ( en == GL_TRANSFORM_FEEDBACK_NV ) return "GL_TRANSFORM_FEEDBACK_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV ) return "GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV";
#endif
#ifdef GL_TRANSFORM_FEEDBACK_BINDING_NV
	if ( en == GL_TRANSFORM_FEEDBACK_BINDING_NV ) return "GL_TRANSFORM_FEEDBACK_BINDING_NV";
#endif
#ifdef GL_SURFACE_STATE_NV
	if ( en == GL_SURFACE_STATE_NV ) return "GL_SURFACE_STATE_NV";
#endif
#ifdef GL_SURFACE_REGISTERED_NV
	if ( en == GL_SURFACE_REGISTERED_NV ) return "GL_SURFACE_REGISTERED_NV";
#endif
#ifdef GL_SURFACE_MAPPED_NV
	if ( en == GL_SURFACE_MAPPED_NV ) return "GL_SURFACE_MAPPED_NV";
#endif
#ifdef GL_WRITE_DISCARD_NV
	if ( en == GL_WRITE_DISCARD_NV ) return "GL_WRITE_DISCARD_NV";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_NV
	if ( en == GL_VERTEX_ARRAY_RANGE_NV ) return "GL_VERTEX_ARRAY_RANGE_NV";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_LENGTH_NV
	if ( en == GL_VERTEX_ARRAY_RANGE_LENGTH_NV ) return "GL_VERTEX_ARRAY_RANGE_LENGTH_NV";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_VALID_NV
	if ( en == GL_VERTEX_ARRAY_RANGE_VALID_NV ) return "GL_VERTEX_ARRAY_RANGE_VALID_NV";
#endif
#ifdef GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV
	if ( en == GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV ) return "GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_POINTER_NV
	if ( en == GL_VERTEX_ARRAY_RANGE_POINTER_NV ) return "GL_VERTEX_ARRAY_RANGE_POINTER_NV";
#endif
#ifdef GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV
	if ( en == GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV ) return "GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV";
#endif
#ifdef GL_INT64_NV
	if ( en == GL_INT64_NV ) return "GL_INT64_NV";
#endif
#ifdef GL_UNSIGNED_INT64_NV
	if ( en == GL_UNSIGNED_INT64_NV ) return "GL_UNSIGNED_INT64_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV ) return "GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV";
#endif
#ifdef GL_ELEMENT_ARRAY_UNIFIED_NV
	if ( en == GL_ELEMENT_ARRAY_UNIFIED_NV ) return "GL_ELEMENT_ARRAY_UNIFIED_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV ) return "GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_VERTEX_ARRAY_ADDRESS_NV
	if ( en == GL_VERTEX_ARRAY_ADDRESS_NV ) return "GL_VERTEX_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_NORMAL_ARRAY_ADDRESS_NV
	if ( en == GL_NORMAL_ARRAY_ADDRESS_NV ) return "GL_NORMAL_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_COLOR_ARRAY_ADDRESS_NV
	if ( en == GL_COLOR_ARRAY_ADDRESS_NV ) return "GL_COLOR_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_INDEX_ARRAY_ADDRESS_NV
	if ( en == GL_INDEX_ARRAY_ADDRESS_NV ) return "GL_INDEX_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_ADDRESS_NV
	if ( en == GL_TEXTURE_COORD_ARRAY_ADDRESS_NV ) return "GL_TEXTURE_COORD_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_ADDRESS_NV
	if ( en == GL_EDGE_FLAG_ARRAY_ADDRESS_NV ) return "GL_EDGE_FLAG_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV
	if ( en == GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV ) return "GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_FOG_COORD_ARRAY_ADDRESS_NV
	if ( en == GL_FOG_COORD_ARRAY_ADDRESS_NV ) return "GL_FOG_COORD_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_ELEMENT_ARRAY_ADDRESS_NV
	if ( en == GL_ELEMENT_ARRAY_ADDRESS_NV ) return "GL_ELEMENT_ARRAY_ADDRESS_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV ) return "GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV";
#endif
#ifdef GL_VERTEX_ARRAY_LENGTH_NV
	if ( en == GL_VERTEX_ARRAY_LENGTH_NV ) return "GL_VERTEX_ARRAY_LENGTH_NV";
#endif
#ifdef GL_NORMAL_ARRAY_LENGTH_NV
	if ( en == GL_NORMAL_ARRAY_LENGTH_NV ) return "GL_NORMAL_ARRAY_LENGTH_NV";
#endif
#ifdef GL_COLOR_ARRAY_LENGTH_NV
	if ( en == GL_COLOR_ARRAY_LENGTH_NV ) return "GL_COLOR_ARRAY_LENGTH_NV";
#endif
#ifdef GL_INDEX_ARRAY_LENGTH_NV
	if ( en == GL_INDEX_ARRAY_LENGTH_NV ) return "GL_INDEX_ARRAY_LENGTH_NV";
#endif
#ifdef GL_TEXTURE_COORD_ARRAY_LENGTH_NV
	if ( en == GL_TEXTURE_COORD_ARRAY_LENGTH_NV ) return "GL_TEXTURE_COORD_ARRAY_LENGTH_NV";
#endif
#ifdef GL_EDGE_FLAG_ARRAY_LENGTH_NV
	if ( en == GL_EDGE_FLAG_ARRAY_LENGTH_NV ) return "GL_EDGE_FLAG_ARRAY_LENGTH_NV";
#endif
#ifdef GL_SECONDARY_COLOR_ARRAY_LENGTH_NV
	if ( en == GL_SECONDARY_COLOR_ARRAY_LENGTH_NV ) return "GL_SECONDARY_COLOR_ARRAY_LENGTH_NV";
#endif
#ifdef GL_FOG_COORD_ARRAY_LENGTH_NV
	if ( en == GL_FOG_COORD_ARRAY_LENGTH_NV ) return "GL_FOG_COORD_ARRAY_LENGTH_NV";
#endif
#ifdef GL_ELEMENT_ARRAY_LENGTH_NV
	if ( en == GL_ELEMENT_ARRAY_LENGTH_NV ) return "GL_ELEMENT_ARRAY_LENGTH_NV";
#endif
#ifdef GL_DRAW_INDIRECT_UNIFIED_NV
	if ( en == GL_DRAW_INDIRECT_UNIFIED_NV ) return "GL_DRAW_INDIRECT_UNIFIED_NV";
#endif
#ifdef GL_DRAW_INDIRECT_ADDRESS_NV
	if ( en == GL_DRAW_INDIRECT_ADDRESS_NV ) return "GL_DRAW_INDIRECT_ADDRESS_NV";
#endif
#ifdef GL_DRAW_INDIRECT_LENGTH_NV
	if ( en == GL_DRAW_INDIRECT_LENGTH_NV ) return "GL_DRAW_INDIRECT_LENGTH_NV";
#endif
#ifdef GL_VERTEX_PROGRAM_NV
	if ( en == GL_VERTEX_PROGRAM_NV ) return "GL_VERTEX_PROGRAM_NV";
#endif
#ifdef GL_VERTEX_STATE_PROGRAM_NV
	if ( en == GL_VERTEX_STATE_PROGRAM_NV ) return "GL_VERTEX_STATE_PROGRAM_NV";
#endif
#ifdef GL_ATTRIB_ARRAY_SIZE_NV
	if ( en == GL_ATTRIB_ARRAY_SIZE_NV ) return "GL_ATTRIB_ARRAY_SIZE_NV";
#endif
#ifdef GL_ATTRIB_ARRAY_STRIDE_NV
	if ( en == GL_ATTRIB_ARRAY_STRIDE_NV ) return "GL_ATTRIB_ARRAY_STRIDE_NV";
#endif
#ifdef GL_ATTRIB_ARRAY_TYPE_NV
	if ( en == GL_ATTRIB_ARRAY_TYPE_NV ) return "GL_ATTRIB_ARRAY_TYPE_NV";
#endif
#ifdef GL_CURRENT_ATTRIB_NV
	if ( en == GL_CURRENT_ATTRIB_NV ) return "GL_CURRENT_ATTRIB_NV";
#endif
#ifdef GL_PROGRAM_LENGTH_NV
	if ( en == GL_PROGRAM_LENGTH_NV ) return "GL_PROGRAM_LENGTH_NV";
#endif
#ifdef GL_PROGRAM_STRING_NV
	if ( en == GL_PROGRAM_STRING_NV ) return "GL_PROGRAM_STRING_NV";
#endif
#ifdef GL_MODELVIEW_PROJECTION_NV
	if ( en == GL_MODELVIEW_PROJECTION_NV ) return "GL_MODELVIEW_PROJECTION_NV";
#endif
#ifdef GL_IDENTITY_NV
	if ( en == GL_IDENTITY_NV ) return "GL_IDENTITY_NV";
#endif
#ifdef GL_INVERSE_NV
	if ( en == GL_INVERSE_NV ) return "GL_INVERSE_NV";
#endif
#ifdef GL_TRANSPOSE_NV
	if ( en == GL_TRANSPOSE_NV ) return "GL_TRANSPOSE_NV";
#endif
#ifdef GL_INVERSE_TRANSPOSE_NV
	if ( en == GL_INVERSE_TRANSPOSE_NV ) return "GL_INVERSE_TRANSPOSE_NV";
#endif
#ifdef GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV
	if ( en == GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV ) return "GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV";
#endif
#ifdef GL_MAX_TRACK_MATRICES_NV
	if ( en == GL_MAX_TRACK_MATRICES_NV ) return "GL_MAX_TRACK_MATRICES_NV";
#endif
#ifdef GL_MATRIX0_NV
	if ( en == GL_MATRIX0_NV ) return "GL_MATRIX0_NV";
#endif
#ifdef GL_MATRIX1_NV
	if ( en == GL_MATRIX1_NV ) return "GL_MATRIX1_NV";
#endif
#ifdef GL_MATRIX2_NV
	if ( en == GL_MATRIX2_NV ) return "GL_MATRIX2_NV";
#endif
#ifdef GL_MATRIX3_NV
	if ( en == GL_MATRIX3_NV ) return "GL_MATRIX3_NV";
#endif
#ifdef GL_MATRIX4_NV
	if ( en == GL_MATRIX4_NV ) return "GL_MATRIX4_NV";
#endif
#ifdef GL_MATRIX5_NV
	if ( en == GL_MATRIX5_NV ) return "GL_MATRIX5_NV";
#endif
#ifdef GL_MATRIX6_NV
	if ( en == GL_MATRIX6_NV ) return "GL_MATRIX6_NV";
#endif
#ifdef GL_MATRIX7_NV
	if ( en == GL_MATRIX7_NV ) return "GL_MATRIX7_NV";
#endif
#ifdef GL_CURRENT_MATRIX_STACK_DEPTH_NV
	if ( en == GL_CURRENT_MATRIX_STACK_DEPTH_NV ) return "GL_CURRENT_MATRIX_STACK_DEPTH_NV";
#endif
#ifdef GL_CURRENT_MATRIX_NV
	if ( en == GL_CURRENT_MATRIX_NV ) return "GL_CURRENT_MATRIX_NV";
#endif
#ifdef GL_VERTEX_PROGRAM_POINT_SIZE_NV
	if ( en == GL_VERTEX_PROGRAM_POINT_SIZE_NV ) return "GL_VERTEX_PROGRAM_POINT_SIZE_NV";
#endif
#ifdef GL_VERTEX_PROGRAM_TWO_SIDE_NV
	if ( en == GL_VERTEX_PROGRAM_TWO_SIDE_NV ) return "GL_VERTEX_PROGRAM_TWO_SIDE_NV";
#endif
#ifdef GL_PROGRAM_PARAMETER_NV
	if ( en == GL_PROGRAM_PARAMETER_NV ) return "GL_PROGRAM_PARAMETER_NV";
#endif
#ifdef GL_ATTRIB_ARRAY_POINTER_NV
	if ( en == GL_ATTRIB_ARRAY_POINTER_NV ) return "GL_ATTRIB_ARRAY_POINTER_NV";
#endif
#ifdef GL_PROGRAM_TARGET_NV
	if ( en == GL_PROGRAM_TARGET_NV ) return "GL_PROGRAM_TARGET_NV";
#endif
#ifdef GL_PROGRAM_RESIDENT_NV
	if ( en == GL_PROGRAM_RESIDENT_NV ) return "GL_PROGRAM_RESIDENT_NV";
#endif
#ifdef GL_TRACK_MATRIX_NV
	if ( en == GL_TRACK_MATRIX_NV ) return "GL_TRACK_MATRIX_NV";
#endif
#ifdef GL_TRACK_MATRIX_TRANSFORM_NV
	if ( en == GL_TRACK_MATRIX_TRANSFORM_NV ) return "GL_TRACK_MATRIX_TRANSFORM_NV";
#endif
#ifdef GL_VERTEX_PROGRAM_BINDING_NV
	if ( en == GL_VERTEX_PROGRAM_BINDING_NV ) return "GL_VERTEX_PROGRAM_BINDING_NV";
#endif
#ifdef GL_PROGRAM_ERROR_POSITION_NV
	if ( en == GL_PROGRAM_ERROR_POSITION_NV ) return "GL_PROGRAM_ERROR_POSITION_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY0_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY0_NV ) return "GL_VERTEX_ATTRIB_ARRAY0_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY1_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY1_NV ) return "GL_VERTEX_ATTRIB_ARRAY1_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY2_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY2_NV ) return "GL_VERTEX_ATTRIB_ARRAY2_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY3_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY3_NV ) return "GL_VERTEX_ATTRIB_ARRAY3_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY4_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY4_NV ) return "GL_VERTEX_ATTRIB_ARRAY4_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY5_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY5_NV ) return "GL_VERTEX_ATTRIB_ARRAY5_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY6_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY6_NV ) return "GL_VERTEX_ATTRIB_ARRAY6_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY7_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY7_NV ) return "GL_VERTEX_ATTRIB_ARRAY7_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY8_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY8_NV ) return "GL_VERTEX_ATTRIB_ARRAY8_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY9_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY9_NV ) return "GL_VERTEX_ATTRIB_ARRAY9_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY10_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY10_NV ) return "GL_VERTEX_ATTRIB_ARRAY10_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY11_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY11_NV ) return "GL_VERTEX_ATTRIB_ARRAY11_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY12_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY12_NV ) return "GL_VERTEX_ATTRIB_ARRAY12_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY13_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY13_NV ) return "GL_VERTEX_ATTRIB_ARRAY13_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY14_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY14_NV ) return "GL_VERTEX_ATTRIB_ARRAY14_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY15_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY15_NV ) return "GL_VERTEX_ATTRIB_ARRAY15_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB0_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB0_4_NV ) return "GL_MAP1_VERTEX_ATTRIB0_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB1_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB1_4_NV ) return "GL_MAP1_VERTEX_ATTRIB1_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB2_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB2_4_NV ) return "GL_MAP1_VERTEX_ATTRIB2_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB3_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB3_4_NV ) return "GL_MAP1_VERTEX_ATTRIB3_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB4_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB4_4_NV ) return "GL_MAP1_VERTEX_ATTRIB4_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB5_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB5_4_NV ) return "GL_MAP1_VERTEX_ATTRIB5_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB6_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB6_4_NV ) return "GL_MAP1_VERTEX_ATTRIB6_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB7_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB7_4_NV ) return "GL_MAP1_VERTEX_ATTRIB7_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB8_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB8_4_NV ) return "GL_MAP1_VERTEX_ATTRIB8_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB9_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB9_4_NV ) return "GL_MAP1_VERTEX_ATTRIB9_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB10_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB10_4_NV ) return "GL_MAP1_VERTEX_ATTRIB10_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB11_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB11_4_NV ) return "GL_MAP1_VERTEX_ATTRIB11_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB12_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB12_4_NV ) return "GL_MAP1_VERTEX_ATTRIB12_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB13_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB13_4_NV ) return "GL_MAP1_VERTEX_ATTRIB13_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB14_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB14_4_NV ) return "GL_MAP1_VERTEX_ATTRIB14_4_NV";
#endif
#ifdef GL_MAP1_VERTEX_ATTRIB15_4_NV
	if ( en == GL_MAP1_VERTEX_ATTRIB15_4_NV ) return "GL_MAP1_VERTEX_ATTRIB15_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB0_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB0_4_NV ) return "GL_MAP2_VERTEX_ATTRIB0_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB1_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB1_4_NV ) return "GL_MAP2_VERTEX_ATTRIB1_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB2_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB2_4_NV ) return "GL_MAP2_VERTEX_ATTRIB2_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB3_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB3_4_NV ) return "GL_MAP2_VERTEX_ATTRIB3_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB4_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB4_4_NV ) return "GL_MAP2_VERTEX_ATTRIB4_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB5_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB5_4_NV ) return "GL_MAP2_VERTEX_ATTRIB5_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB6_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB6_4_NV ) return "GL_MAP2_VERTEX_ATTRIB6_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB7_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB7_4_NV ) return "GL_MAP2_VERTEX_ATTRIB7_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB8_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB8_4_NV ) return "GL_MAP2_VERTEX_ATTRIB8_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB9_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB9_4_NV ) return "GL_MAP2_VERTEX_ATTRIB9_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB10_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB10_4_NV ) return "GL_MAP2_VERTEX_ATTRIB10_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB11_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB11_4_NV ) return "GL_MAP2_VERTEX_ATTRIB11_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB12_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB12_4_NV ) return "GL_MAP2_VERTEX_ATTRIB12_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB13_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB13_4_NV ) return "GL_MAP2_VERTEX_ATTRIB13_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB14_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB14_4_NV ) return "GL_MAP2_VERTEX_ATTRIB14_4_NV";
#endif
#ifdef GL_MAP2_VERTEX_ATTRIB15_4_NV
	if ( en == GL_MAP2_VERTEX_ATTRIB15_4_NV ) return "GL_MAP2_VERTEX_ATTRIB15_4_NV";
#endif
#ifdef GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV
	if ( en == GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV ) return "GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV";
#endif
#ifdef GL_MAX_PROGRAM_CALL_DEPTH_NV
	if ( en == GL_MAX_PROGRAM_CALL_DEPTH_NV ) return "GL_MAX_PROGRAM_CALL_DEPTH_NV";
#endif
#ifdef GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV
	if ( en == GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV ) return "GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV";
#endif
#ifdef GL_VIDEO_BUFFER_NV
	if ( en == GL_VIDEO_BUFFER_NV ) return "GL_VIDEO_BUFFER_NV";
#endif
#ifdef GL_VIDEO_BUFFER_BINDING_NV
	if ( en == GL_VIDEO_BUFFER_BINDING_NV ) return "GL_VIDEO_BUFFER_BINDING_NV";
#endif
#ifdef GL_FIELD_UPPER_NV
	if ( en == GL_FIELD_UPPER_NV ) return "GL_FIELD_UPPER_NV";
#endif
#ifdef GL_FIELD_LOWER_NV
	if ( en == GL_FIELD_LOWER_NV ) return "GL_FIELD_LOWER_NV";
#endif
#ifdef GL_NUM_VIDEO_CAPTURE_STREAMS_NV
	if ( en == GL_NUM_VIDEO_CAPTURE_STREAMS_NV ) return "GL_NUM_VIDEO_CAPTURE_STREAMS_NV";
#endif
#ifdef GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV
	if ( en == GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV ) return "GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV
	if ( en == GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV ) return "GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV";
#endif
#ifdef GL_LAST_VIDEO_CAPTURE_STATUS_NV
	if ( en == GL_LAST_VIDEO_CAPTURE_STATUS_NV ) return "GL_LAST_VIDEO_CAPTURE_STATUS_NV";
#endif
#ifdef GL_VIDEO_BUFFER_PITCH_NV
	if ( en == GL_VIDEO_BUFFER_PITCH_NV ) return "GL_VIDEO_BUFFER_PITCH_NV";
#endif
#ifdef GL_VIDEO_COLOR_CONVERSION_MATRIX_NV
	if ( en == GL_VIDEO_COLOR_CONVERSION_MATRIX_NV ) return "GL_VIDEO_COLOR_CONVERSION_MATRIX_NV";
#endif
#ifdef GL_VIDEO_COLOR_CONVERSION_MAX_NV
	if ( en == GL_VIDEO_COLOR_CONVERSION_MAX_NV ) return "GL_VIDEO_COLOR_CONVERSION_MAX_NV";
#endif
#ifdef GL_VIDEO_COLOR_CONVERSION_MIN_NV
	if ( en == GL_VIDEO_COLOR_CONVERSION_MIN_NV ) return "GL_VIDEO_COLOR_CONVERSION_MIN_NV";
#endif
#ifdef GL_VIDEO_COLOR_CONVERSION_OFFSET_NV
	if ( en == GL_VIDEO_COLOR_CONVERSION_OFFSET_NV ) return "GL_VIDEO_COLOR_CONVERSION_OFFSET_NV";
#endif
#ifdef GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV
	if ( en == GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV ) return "GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV";
#endif
#ifdef GL_PARTIAL_SUCCESS_NV
	if ( en == GL_PARTIAL_SUCCESS_NV ) return "GL_PARTIAL_SUCCESS_NV";
#endif
#ifdef GL_SUCCESS_NV
	if ( en == GL_SUCCESS_NV ) return "GL_SUCCESS_NV";
#endif
#ifdef GL_FAILURE_NV
	if ( en == GL_FAILURE_NV ) return "GL_FAILURE_NV";
#endif
#ifdef GL_YCBYCR8_422_NV
	if ( en == GL_YCBYCR8_422_NV ) return "GL_YCBYCR8_422_NV";
#endif
#ifdef GL_YCBAYCR8A_4224_NV
	if ( en == GL_YCBAYCR8A_4224_NV ) return "GL_YCBAYCR8A_4224_NV";
#endif
#ifdef GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV
	if ( en == GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV ) return "GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV";
#endif
#ifdef GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV
	if ( en == GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV ) return "GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV";
#endif
#ifdef GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV
	if ( en == GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV ) return "GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV";
#endif
#ifdef GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV
	if ( en == GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV ) return "GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV";
#endif
#ifdef GL_Z4Y12Z4CB12Z4CR12_444_NV
	if ( en == GL_Z4Y12Z4CB12Z4CR12_444_NV ) return "GL_Z4Y12Z4CB12Z4CR12_444_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_FRAME_WIDTH_NV
	if ( en == GL_VIDEO_CAPTURE_FRAME_WIDTH_NV ) return "GL_VIDEO_CAPTURE_FRAME_WIDTH_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV
	if ( en == GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV ) return "GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV
	if ( en == GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV ) return "GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV
	if ( en == GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV ) return "GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV";
#endif
#ifdef GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV
	if ( en == GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV ) return "GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV";
#endif
#ifdef GL_PALETTE4_RGB8_OES
	if ( en == GL_PALETTE4_RGB8_OES ) return "GL_PALETTE4_RGB8_OES";
#endif
#ifdef GL_PALETTE4_RGBA8_OES
	if ( en == GL_PALETTE4_RGBA8_OES ) return "GL_PALETTE4_RGBA8_OES";
#endif
#ifdef GL_PALETTE4_R5_G6_B5_OES
	if ( en == GL_PALETTE4_R5_G6_B5_OES ) return "GL_PALETTE4_R5_G6_B5_OES";
#endif
#ifdef GL_PALETTE4_RGBA4_OES
	if ( en == GL_PALETTE4_RGBA4_OES ) return "GL_PALETTE4_RGBA4_OES";
#endif
#ifdef GL_PALETTE4_RGB5_A1_OES
	if ( en == GL_PALETTE4_RGB5_A1_OES ) return "GL_PALETTE4_RGB5_A1_OES";
#endif
#ifdef GL_PALETTE8_RGB8_OES
	if ( en == GL_PALETTE8_RGB8_OES ) return "GL_PALETTE8_RGB8_OES";
#endif
#ifdef GL_PALETTE8_RGBA8_OES
	if ( en == GL_PALETTE8_RGBA8_OES ) return "GL_PALETTE8_RGBA8_OES";
#endif
#ifdef GL_PALETTE8_R5_G6_B5_OES
	if ( en == GL_PALETTE8_R5_G6_B5_OES ) return "GL_PALETTE8_R5_G6_B5_OES";
#endif
#ifdef GL_PALETTE8_RGBA4_OES
	if ( en == GL_PALETTE8_RGBA4_OES ) return "GL_PALETTE8_RGBA4_OES";
#endif
#ifdef GL_PALETTE8_RGB5_A1_OES
	if ( en == GL_PALETTE8_RGB5_A1_OES ) return "GL_PALETTE8_RGB5_A1_OES";
#endif
#ifdef GL_IMPLEMENTATION_COLOR_READ_TYPE_OES
	if ( en == GL_IMPLEMENTATION_COLOR_READ_TYPE_OES ) return "GL_IMPLEMENTATION_COLOR_READ_TYPE_OES";
#endif
#ifdef GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES
	if ( en == GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES ) return "GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES";
#endif
#ifdef GL_INTERLACE_OML
	if ( en == GL_INTERLACE_OML ) return "GL_INTERLACE_OML";
#endif
#ifdef GL_INTERLACE_READ_OML
	if ( en == GL_INTERLACE_READ_OML ) return "GL_INTERLACE_READ_OML";
#endif
#ifdef GL_PACK_RESAMPLE_OML
	if ( en == GL_PACK_RESAMPLE_OML ) return "GL_PACK_RESAMPLE_OML";
#endif
#ifdef GL_UNPACK_RESAMPLE_OML
	if ( en == GL_UNPACK_RESAMPLE_OML ) return "GL_UNPACK_RESAMPLE_OML";
#endif
#ifdef GL_RESAMPLE_REPLICATE_OML
	if ( en == GL_RESAMPLE_REPLICATE_OML ) return "GL_RESAMPLE_REPLICATE_OML";
#endif
#ifdef GL_RESAMPLE_ZERO_FILL_OML
	if ( en == GL_RESAMPLE_ZERO_FILL_OML ) return "GL_RESAMPLE_ZERO_FILL_OML";
#endif
#ifdef GL_RESAMPLE_AVERAGE_OML
	if ( en == GL_RESAMPLE_AVERAGE_OML ) return "GL_RESAMPLE_AVERAGE_OML";
#endif
#ifdef GL_RESAMPLE_DECIMATE_OML
	if ( en == GL_RESAMPLE_DECIMATE_OML ) return "GL_RESAMPLE_DECIMATE_OML";
#endif
#ifdef GL_FORMAT_SUBSAMPLE_24_24_OML
	if ( en == GL_FORMAT_SUBSAMPLE_24_24_OML ) return "GL_FORMAT_SUBSAMPLE_24_24_OML";
#endif
#ifdef GL_FORMAT_SUBSAMPLE_244_244_OML
	if ( en == GL_FORMAT_SUBSAMPLE_244_244_OML ) return "GL_FORMAT_SUBSAMPLE_244_244_OML";
#endif
#ifdef GL_PREFER_DOUBLEBUFFER_HINT_PGI
	if ( en == GL_PREFER_DOUBLEBUFFER_HINT_PGI ) return "GL_PREFER_DOUBLEBUFFER_HINT_PGI";
#endif
#ifdef GL_CONSERVE_MEMORY_HINT_PGI
	if ( en == GL_CONSERVE_MEMORY_HINT_PGI ) return "GL_CONSERVE_MEMORY_HINT_PGI";
#endif
#ifdef GL_RECLAIM_MEMORY_HINT_PGI
	if ( en == GL_RECLAIM_MEMORY_HINT_PGI ) return "GL_RECLAIM_MEMORY_HINT_PGI";
#endif
#ifdef GL_NATIVE_GRAPHICS_HANDLE_PGI
	if ( en == GL_NATIVE_GRAPHICS_HANDLE_PGI ) return "GL_NATIVE_GRAPHICS_HANDLE_PGI";
#endif
#ifdef GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI
	if ( en == GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI ) return "GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI";
#endif
#ifdef GL_NATIVE_GRAPHICS_END_HINT_PGI
	if ( en == GL_NATIVE_GRAPHICS_END_HINT_PGI ) return "GL_NATIVE_GRAPHICS_END_HINT_PGI";
#endif
#ifdef GL_ALWAYS_FAST_HINT_PGI
	if ( en == GL_ALWAYS_FAST_HINT_PGI ) return "GL_ALWAYS_FAST_HINT_PGI";
#endif
#ifdef GL_ALWAYS_SOFT_HINT_PGI
	if ( en == GL_ALWAYS_SOFT_HINT_PGI ) return "GL_ALWAYS_SOFT_HINT_PGI";
#endif
#ifdef GL_ALLOW_DRAW_OBJ_HINT_PGI
	if ( en == GL_ALLOW_DRAW_OBJ_HINT_PGI ) return "GL_ALLOW_DRAW_OBJ_HINT_PGI";
#endif
#ifdef GL_ALLOW_DRAW_WIN_HINT_PGI
	if ( en == GL_ALLOW_DRAW_WIN_HINT_PGI ) return "GL_ALLOW_DRAW_WIN_HINT_PGI";
#endif
#ifdef GL_ALLOW_DRAW_FRG_HINT_PGI
	if ( en == GL_ALLOW_DRAW_FRG_HINT_PGI ) return "GL_ALLOW_DRAW_FRG_HINT_PGI";
#endif
#ifdef GL_ALLOW_DRAW_MEM_HINT_PGI
	if ( en == GL_ALLOW_DRAW_MEM_HINT_PGI ) return "GL_ALLOW_DRAW_MEM_HINT_PGI";
#endif
#ifdef GL_STRICT_DEPTHFUNC_HINT_PGI
	if ( en == GL_STRICT_DEPTHFUNC_HINT_PGI ) return "GL_STRICT_DEPTHFUNC_HINT_PGI";
#endif
#ifdef GL_STRICT_LIGHTING_HINT_PGI
	if ( en == GL_STRICT_LIGHTING_HINT_PGI ) return "GL_STRICT_LIGHTING_HINT_PGI";
#endif
#ifdef GL_STRICT_SCISSOR_HINT_PGI
	if ( en == GL_STRICT_SCISSOR_HINT_PGI ) return "GL_STRICT_SCISSOR_HINT_PGI";
#endif
#ifdef GL_FULL_STIPPLE_HINT_PGI
	if ( en == GL_FULL_STIPPLE_HINT_PGI ) return "GL_FULL_STIPPLE_HINT_PGI";
#endif
#ifdef GL_CLIP_NEAR_HINT_PGI
	if ( en == GL_CLIP_NEAR_HINT_PGI ) return "GL_CLIP_NEAR_HINT_PGI";
#endif
#ifdef GL_CLIP_FAR_HINT_PGI
	if ( en == GL_CLIP_FAR_HINT_PGI ) return "GL_CLIP_FAR_HINT_PGI";
#endif
#ifdef GL_WIDE_LINE_HINT_PGI
	if ( en == GL_WIDE_LINE_HINT_PGI ) return "GL_WIDE_LINE_HINT_PGI";
#endif
#ifdef GL_BACK_NORMALS_HINT_PGI
	if ( en == GL_BACK_NORMALS_HINT_PGI ) return "GL_BACK_NORMALS_HINT_PGI";
#endif
#ifdef GL_VERTEX23_BIT_PGI
	if ( en == GL_VERTEX23_BIT_PGI ) return "GL_VERTEX23_BIT_PGI";
#endif
#ifdef GL_VERTEX4_BIT_PGI
	if ( en == GL_VERTEX4_BIT_PGI ) return "GL_VERTEX4_BIT_PGI";
#endif
#ifdef GL_COLOR3_BIT_PGI
	if ( en == GL_COLOR3_BIT_PGI ) return "GL_COLOR3_BIT_PGI";
#endif
#ifdef GL_COLOR4_BIT_PGI
	if ( en == GL_COLOR4_BIT_PGI ) return "GL_COLOR4_BIT_PGI";
#endif
#ifdef GL_EDGEFLAG_BIT_PGI
	if ( en == GL_EDGEFLAG_BIT_PGI ) return "GL_EDGEFLAG_BIT_PGI";
#endif
#ifdef GL_INDEX_BIT_PGI
	if ( en == GL_INDEX_BIT_PGI ) return "GL_INDEX_BIT_PGI";
#endif
#ifdef GL_MAT_AMBIENT_BIT_PGI
	if ( en == GL_MAT_AMBIENT_BIT_PGI ) return "GL_MAT_AMBIENT_BIT_PGI";
#endif
#ifdef GL_VERTEX_DATA_HINT_PGI
	if ( en == GL_VERTEX_DATA_HINT_PGI ) return "GL_VERTEX_DATA_HINT_PGI";
#endif
#ifdef GL_VERTEX_CONSISTENT_HINT_PGI
	if ( en == GL_VERTEX_CONSISTENT_HINT_PGI ) return "GL_VERTEX_CONSISTENT_HINT_PGI";
#endif
#ifdef GL_MATERIAL_SIDE_HINT_PGI
	if ( en == GL_MATERIAL_SIDE_HINT_PGI ) return "GL_MATERIAL_SIDE_HINT_PGI";
#endif
#ifdef GL_MAX_VERTEX_HINT_PGI
	if ( en == GL_MAX_VERTEX_HINT_PGI ) return "GL_MAX_VERTEX_HINT_PGI";
#endif
#ifdef GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI
	if ( en == GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI ) return "GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI";
#endif
#ifdef GL_MAT_DIFFUSE_BIT_PGI
	if ( en == GL_MAT_DIFFUSE_BIT_PGI ) return "GL_MAT_DIFFUSE_BIT_PGI";
#endif
#ifdef GL_MAT_EMISSION_BIT_PGI
	if ( en == GL_MAT_EMISSION_BIT_PGI ) return "GL_MAT_EMISSION_BIT_PGI";
#endif
#ifdef GL_MAT_COLOR_INDEXES_BIT_PGI
	if ( en == GL_MAT_COLOR_INDEXES_BIT_PGI ) return "GL_MAT_COLOR_INDEXES_BIT_PGI";
#endif
#ifdef GL_MAT_SHININESS_BIT_PGI
	if ( en == GL_MAT_SHININESS_BIT_PGI ) return "GL_MAT_SHININESS_BIT_PGI";
#endif
#ifdef GL_MAT_SPECULAR_BIT_PGI
	if ( en == GL_MAT_SPECULAR_BIT_PGI ) return "GL_MAT_SPECULAR_BIT_PGI";
#endif
#ifdef GL_NORMAL_BIT_PGI
	if ( en == GL_NORMAL_BIT_PGI ) return "GL_NORMAL_BIT_PGI";
#endif
#ifdef GL_TEXCOORD1_BIT_PGI
	if ( en == GL_TEXCOORD1_BIT_PGI ) return "GL_TEXCOORD1_BIT_PGI";
#endif
#ifdef GL_TEXCOORD2_BIT_PGI
	if ( en == GL_TEXCOORD2_BIT_PGI ) return "GL_TEXCOORD2_BIT_PGI";
#endif
#ifdef GL_TEXCOORD3_BIT_PGI
	if ( en == GL_TEXCOORD3_BIT_PGI ) return "GL_TEXCOORD3_BIT_PGI";
#endif
#ifdef GL_TEXCOORD4_BIT_PGI
	if ( en == GL_TEXCOORD4_BIT_PGI ) return "GL_TEXCOORD4_BIT_PGI";
#endif
#ifdef GL_ERROR_REGAL
	if ( en == GL_ERROR_REGAL ) return "GL_ERROR_REGAL";
#endif
#ifdef GL_DEBUG_REGAL
	if ( en == GL_DEBUG_REGAL ) return "GL_DEBUG_REGAL";
#endif
#ifdef GL_LOG_REGAL
	if ( en == GL_LOG_REGAL ) return "GL_LOG_REGAL";
#endif
#ifdef GL_EMULATION_REGAL
	if ( en == GL_EMULATION_REGAL ) return "GL_EMULATION_REGAL";
#endif
#ifdef GL_DRIVER_REGAL
	if ( en == GL_DRIVER_REGAL ) return "GL_DRIVER_REGAL";
#endif
#ifdef GL_MISSING_REGAL
	if ( en == GL_MISSING_REGAL ) return "GL_MISSING_REGAL";
#endif
#ifdef GL_TRACE_REGAL
	if ( en == GL_TRACE_REGAL ) return "GL_TRACE_REGAL";
#endif
#ifdef GL_CACHE_REGAL
	if ( en == GL_CACHE_REGAL ) return "GL_CACHE_REGAL";
#endif
#ifdef GL_CODE_REGAL
	if ( en == GL_CODE_REGAL ) return "GL_CODE_REGAL";
#endif
#ifdef GL_STATISTICS_REGAL
	if ( en == GL_STATISTICS_REGAL ) return "GL_STATISTICS_REGAL";
#endif
#ifdef GL_LOG_ERROR_REGAL
	if ( en == GL_LOG_ERROR_REGAL ) return "GL_LOG_ERROR_REGAL";
#endif
#ifdef GL_LOG_WARNING_REGAL
	if ( en == GL_LOG_WARNING_REGAL ) return "GL_LOG_WARNING_REGAL";
#endif
#ifdef GL_LOG_INFO_REGAL
	if ( en == GL_LOG_INFO_REGAL ) return "GL_LOG_INFO_REGAL";
#endif
#ifdef GL_LOG_APP_REGAL
	if ( en == GL_LOG_APP_REGAL ) return "GL_LOG_APP_REGAL";
#endif
#ifdef GL_LOG_DRIVER_REGAL
	if ( en == GL_LOG_DRIVER_REGAL ) return "GL_LOG_DRIVER_REGAL";
#endif
#ifdef GL_LOG_INTERNAL_REGAL
	if ( en == GL_LOG_INTERNAL_REGAL ) return "GL_LOG_INTERNAL_REGAL";
#endif
#ifdef GL_LOG_DEBUG_REGAL
	if ( en == GL_LOG_DEBUG_REGAL ) return "GL_LOG_DEBUG_REGAL";
#endif
#ifdef GL_LOG_STATUS_REGAL
	if ( en == GL_LOG_STATUS_REGAL ) return "GL_LOG_STATUS_REGAL";
#endif
#ifdef GL_LOG_HTTP_REGAL
	if ( en == GL_LOG_HTTP_REGAL ) return "GL_LOG_HTTP_REGAL";
#endif
#ifdef GL_SCREEN_COORDINATES_REND
	if ( en == GL_SCREEN_COORDINATES_REND ) return "GL_SCREEN_COORDINATES_REND";
#endif
#ifdef GL_INVERTED_SCREEN_W_REND
	if ( en == GL_INVERTED_SCREEN_W_REND ) return "GL_INVERTED_SCREEN_W_REND";
#endif
#ifdef GL_RGB_S3TC
	if ( en == GL_RGB_S3TC ) return "GL_RGB_S3TC";
#endif
#ifdef GL_RGB4_S3TC
	if ( en == GL_RGB4_S3TC ) return "GL_RGB4_S3TC";
#endif
#ifdef GL_RGBA_S3TC
	if ( en == GL_RGBA_S3TC ) return "GL_RGBA_S3TC";
#endif
#ifdef GL_RGBA4_S3TC
	if ( en == GL_RGBA4_S3TC ) return "GL_RGBA4_S3TC";
#endif
#ifdef GL_RGBA_DXT5_S3TC
	if ( en == GL_RGBA_DXT5_S3TC ) return "GL_RGBA_DXT5_S3TC";
#endif
#ifdef GL_RGBA4_DXT5_S3TC
	if ( en == GL_RGBA4_DXT5_S3TC ) return "GL_RGBA4_DXT5_S3TC";
#endif
#ifdef GL_EXTENDED_RANGE_SGIS
	if ( en == GL_EXTENDED_RANGE_SGIS ) return "GL_EXTENDED_RANGE_SGIS";
#endif
#ifdef GL_MIN_RED_SGIS
	if ( en == GL_MIN_RED_SGIS ) return "GL_MIN_RED_SGIS";
#endif
#ifdef GL_MAX_RED_SGIS
	if ( en == GL_MAX_RED_SGIS ) return "GL_MAX_RED_SGIS";
#endif
#ifdef GL_MIN_GREEN_SGIS
	if ( en == GL_MIN_GREEN_SGIS ) return "GL_MIN_GREEN_SGIS";
#endif
#ifdef GL_MAX_GREEN_SGIS
	if ( en == GL_MAX_GREEN_SGIS ) return "GL_MAX_GREEN_SGIS";
#endif
#ifdef GL_MIN_BLUE_SGIS
	if ( en == GL_MIN_BLUE_SGIS ) return "GL_MIN_BLUE_SGIS";
#endif
#ifdef GL_MAX_BLUE_SGIS
	if ( en == GL_MAX_BLUE_SGIS ) return "GL_MAX_BLUE_SGIS";
#endif
#ifdef GL_MIN_ALPHA_SGIS
	if ( en == GL_MIN_ALPHA_SGIS ) return "GL_MIN_ALPHA_SGIS";
#endif
#ifdef GL_MAX_ALPHA_SGIS
	if ( en == GL_MAX_ALPHA_SGIS ) return "GL_MAX_ALPHA_SGIS";
#endif
#ifdef GL_GENERATE_MIPMAP_SGIS
	if ( en == GL_GENERATE_MIPMAP_SGIS ) return "GL_GENERATE_MIPMAP_SGIS";
#endif
#ifdef GL_GENERATE_MIPMAP_HINT_SGIS
	if ( en == GL_GENERATE_MIPMAP_HINT_SGIS ) return "GL_GENERATE_MIPMAP_HINT_SGIS";
#endif
#ifdef GL_MULTISAMPLE_SGIS
	if ( en == GL_MULTISAMPLE_SGIS ) return "GL_MULTISAMPLE_SGIS";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_MASK_SGIS
	if ( en == GL_SAMPLE_ALPHA_TO_MASK_SGIS ) return "GL_SAMPLE_ALPHA_TO_MASK_SGIS";
#endif
#ifdef GL_SAMPLE_ALPHA_TO_ONE_SGIS
	if ( en == GL_SAMPLE_ALPHA_TO_ONE_SGIS ) return "GL_SAMPLE_ALPHA_TO_ONE_SGIS";
#endif
#ifdef GL_SAMPLE_MASK_SGIS
	if ( en == GL_SAMPLE_MASK_SGIS ) return "GL_SAMPLE_MASK_SGIS";
#endif
#ifdef GL_1PASS_SGIS
	if ( en == GL_1PASS_SGIS ) return "GL_1PASS_SGIS";
#endif
#ifdef GL_2PASS_0_SGIS
	if ( en == GL_2PASS_0_SGIS ) return "GL_2PASS_0_SGIS";
#endif
#ifdef GL_2PASS_1_SGIS
	if ( en == GL_2PASS_1_SGIS ) return "GL_2PASS_1_SGIS";
#endif
#ifdef GL_4PASS_0_SGIS
	if ( en == GL_4PASS_0_SGIS ) return "GL_4PASS_0_SGIS";
#endif
#ifdef GL_4PASS_1_SGIS
	if ( en == GL_4PASS_1_SGIS ) return "GL_4PASS_1_SGIS";
#endif
#ifdef GL_4PASS_2_SGIS
	if ( en == GL_4PASS_2_SGIS ) return "GL_4PASS_2_SGIS";
#endif
#ifdef GL_4PASS_3_SGIS
	if ( en == GL_4PASS_3_SGIS ) return "GL_4PASS_3_SGIS";
#endif
#ifdef GL_SAMPLE_BUFFERS_SGIS
	if ( en == GL_SAMPLE_BUFFERS_SGIS ) return "GL_SAMPLE_BUFFERS_SGIS";
#endif
#ifdef GL_SAMPLES_SGIS
	if ( en == GL_SAMPLES_SGIS ) return "GL_SAMPLES_SGIS";
#endif
#ifdef GL_SAMPLE_MASK_VALUE_SGIS
	if ( en == GL_SAMPLE_MASK_VALUE_SGIS ) return "GL_SAMPLE_MASK_VALUE_SGIS";
#endif
#ifdef GL_SAMPLE_MASK_INVERT_SGIS
	if ( en == GL_SAMPLE_MASK_INVERT_SGIS ) return "GL_SAMPLE_MASK_INVERT_SGIS";
#endif
#ifdef GL_SAMPLE_PATTERN_SGIS
	if ( en == GL_SAMPLE_PATTERN_SGIS ) return "GL_SAMPLE_PATTERN_SGIS";
#endif
#ifdef GL_EYE_DISTANCE_TO_POINT_SGIS
	if ( en == GL_EYE_DISTANCE_TO_POINT_SGIS ) return "GL_EYE_DISTANCE_TO_POINT_SGIS";
#endif
#ifdef GL_OBJECT_DISTANCE_TO_POINT_SGIS
	if ( en == GL_OBJECT_DISTANCE_TO_POINT_SGIS ) return "GL_OBJECT_DISTANCE_TO_POINT_SGIS";
#endif
#ifdef GL_EYE_DISTANCE_TO_LINE_SGIS
	if ( en == GL_EYE_DISTANCE_TO_LINE_SGIS ) return "GL_EYE_DISTANCE_TO_LINE_SGIS";
#endif
#ifdef GL_OBJECT_DISTANCE_TO_LINE_SGIS
	if ( en == GL_OBJECT_DISTANCE_TO_LINE_SGIS ) return "GL_OBJECT_DISTANCE_TO_LINE_SGIS";
#endif
#ifdef GL_EYE_POINT_SGIS
	if ( en == GL_EYE_POINT_SGIS ) return "GL_EYE_POINT_SGIS";
#endif
#ifdef GL_OBJECT_POINT_SGIS
	if ( en == GL_OBJECT_POINT_SGIS ) return "GL_OBJECT_POINT_SGIS";
#endif
#ifdef GL_EYE_LINE_SGIS
	if ( en == GL_EYE_LINE_SGIS ) return "GL_EYE_LINE_SGIS";
#endif
#ifdef GL_OBJECT_LINE_SGIS
	if ( en == GL_OBJECT_LINE_SGIS ) return "GL_OBJECT_LINE_SGIS";
#endif
#ifdef GL_CLAMP_TO_BORDER_SGIS
	if ( en == GL_CLAMP_TO_BORDER_SGIS ) return "GL_CLAMP_TO_BORDER_SGIS";
#endif
#ifdef GL_CLAMP_TO_EDGE_SGIS
	if ( en == GL_CLAMP_TO_EDGE_SGIS ) return "GL_CLAMP_TO_EDGE_SGIS";
#endif
#ifdef GL_TEXTURE_MIN_LOD_SGIS
	if ( en == GL_TEXTURE_MIN_LOD_SGIS ) return "GL_TEXTURE_MIN_LOD_SGIS";
#endif
#ifdef GL_TEXTURE_MAX_LOD_SGIS
	if ( en == GL_TEXTURE_MAX_LOD_SGIS ) return "GL_TEXTURE_MAX_LOD_SGIS";
#endif
#ifdef GL_TEXTURE_BASE_LEVEL_SGIS
	if ( en == GL_TEXTURE_BASE_LEVEL_SGIS ) return "GL_TEXTURE_BASE_LEVEL_SGIS";
#endif
#ifdef GL_TEXTURE_MAX_LEVEL_SGIS
	if ( en == GL_TEXTURE_MAX_LEVEL_SGIS ) return "GL_TEXTURE_MAX_LEVEL_SGIS";
#endif
#ifdef GL_ASYNC_MARKER_SGIX
	if ( en == GL_ASYNC_MARKER_SGIX ) return "GL_ASYNC_MARKER_SGIX";
#endif
#ifdef GL_ASYNC_HISTOGRAM_SGIX
	if ( en == GL_ASYNC_HISTOGRAM_SGIX ) return "GL_ASYNC_HISTOGRAM_SGIX";
#endif
#ifdef GL_MAX_ASYNC_HISTOGRAM_SGIX
	if ( en == GL_MAX_ASYNC_HISTOGRAM_SGIX ) return "GL_MAX_ASYNC_HISTOGRAM_SGIX";
#endif
#ifdef GL_ASYNC_TEX_IMAGE_SGIX
	if ( en == GL_ASYNC_TEX_IMAGE_SGIX ) return "GL_ASYNC_TEX_IMAGE_SGIX";
#endif
#ifdef GL_ASYNC_DRAW_PIXELS_SGIX
	if ( en == GL_ASYNC_DRAW_PIXELS_SGIX ) return "GL_ASYNC_DRAW_PIXELS_SGIX";
#endif
#ifdef GL_ASYNC_READ_PIXELS_SGIX
	if ( en == GL_ASYNC_READ_PIXELS_SGIX ) return "GL_ASYNC_READ_PIXELS_SGIX";
#endif
#ifdef GL_MAX_ASYNC_TEX_IMAGE_SGIX
	if ( en == GL_MAX_ASYNC_TEX_IMAGE_SGIX ) return "GL_MAX_ASYNC_TEX_IMAGE_SGIX";
#endif
#ifdef GL_MAX_ASYNC_DRAW_PIXELS_SGIX
	if ( en == GL_MAX_ASYNC_DRAW_PIXELS_SGIX ) return "GL_MAX_ASYNC_DRAW_PIXELS_SGIX";
#endif
#ifdef GL_MAX_ASYNC_READ_PIXELS_SGIX
	if ( en == GL_MAX_ASYNC_READ_PIXELS_SGIX ) return "GL_MAX_ASYNC_READ_PIXELS_SGIX";
#endif
#ifdef GL_ALPHA_MIN_SGIX
	if ( en == GL_ALPHA_MIN_SGIX ) return "GL_ALPHA_MIN_SGIX";
#endif
#ifdef GL_ALPHA_MAX_SGIX
	if ( en == GL_ALPHA_MAX_SGIX ) return "GL_ALPHA_MAX_SGIX";
#endif
#ifdef GL_CONVOLUTION_HINT_SGIX
	if ( en == GL_CONVOLUTION_HINT_SGIX ) return "GL_CONVOLUTION_HINT_SGIX";
#endif
#ifdef GL_DEPTH_COMPONENT16_SGIX
	if ( en == GL_DEPTH_COMPONENT16_SGIX ) return "GL_DEPTH_COMPONENT16_SGIX";
#endif
#ifdef GL_DEPTH_COMPONENT24_SGIX
	if ( en == GL_DEPTH_COMPONENT24_SGIX ) return "GL_DEPTH_COMPONENT24_SGIX";
#endif
#ifdef GL_DEPTH_COMPONENT32_SGIX
	if ( en == GL_DEPTH_COMPONENT32_SGIX ) return "GL_DEPTH_COMPONENT32_SGIX";
#endif
#ifdef GL_FOG_OFFSET_SGIX
	if ( en == GL_FOG_OFFSET_SGIX ) return "GL_FOG_OFFSET_SGIX";
#endif
#ifdef GL_FOG_OFFSET_VALUE_SGIX
	if ( en == GL_FOG_OFFSET_VALUE_SGIX ) return "GL_FOG_OFFSET_VALUE_SGIX";
#endif
#ifdef GL_INTERLACE_SGIX
	if ( en == GL_INTERLACE_SGIX ) return "GL_INTERLACE_SGIX";
#endif
#ifdef GL_PACK_RESAMPLE_SGIX
	if ( en == GL_PACK_RESAMPLE_SGIX ) return "GL_PACK_RESAMPLE_SGIX";
#endif
#ifdef GL_UNPACK_RESAMPLE_SGIX
	if ( en == GL_UNPACK_RESAMPLE_SGIX ) return "GL_UNPACK_RESAMPLE_SGIX";
#endif
#ifdef GL_RESAMPLE_DECIMATE_SGIX
	if ( en == GL_RESAMPLE_DECIMATE_SGIX ) return "GL_RESAMPLE_DECIMATE_SGIX";
#endif
#ifdef GL_RESAMPLE_REPLICATE_SGIX
	if ( en == GL_RESAMPLE_REPLICATE_SGIX ) return "GL_RESAMPLE_REPLICATE_SGIX";
#endif
#ifdef GL_RESAMPLE_ZERO_FILL_SGIX
	if ( en == GL_RESAMPLE_ZERO_FILL_SGIX ) return "GL_RESAMPLE_ZERO_FILL_SGIX";
#endif
#ifdef GL_TEXTURE_COMPARE_SGIX
	if ( en == GL_TEXTURE_COMPARE_SGIX ) return "GL_TEXTURE_COMPARE_SGIX";
#endif
#ifdef GL_TEXTURE_COMPARE_OPERATOR_SGIX
	if ( en == GL_TEXTURE_COMPARE_OPERATOR_SGIX ) return "GL_TEXTURE_COMPARE_OPERATOR_SGIX";
#endif
#ifdef GL_TEXTURE_LEQUAL_R_SGIX
	if ( en == GL_TEXTURE_LEQUAL_R_SGIX ) return "GL_TEXTURE_LEQUAL_R_SGIX";
#endif
#ifdef GL_TEXTURE_GEQUAL_R_SGIX
	if ( en == GL_TEXTURE_GEQUAL_R_SGIX ) return "GL_TEXTURE_GEQUAL_R_SGIX";
#endif
#ifdef GL_SHADOW_AMBIENT_SGIX
	if ( en == GL_SHADOW_AMBIENT_SGIX ) return "GL_SHADOW_AMBIENT_SGIX";
#endif
#ifdef GL_TEXTURE_MAX_CLAMP_S_SGIX
	if ( en == GL_TEXTURE_MAX_CLAMP_S_SGIX ) return "GL_TEXTURE_MAX_CLAMP_S_SGIX";
#endif
#ifdef GL_TEXTURE_MAX_CLAMP_T_SGIX
	if ( en == GL_TEXTURE_MAX_CLAMP_T_SGIX ) return "GL_TEXTURE_MAX_CLAMP_T_SGIX";
#endif
#ifdef GL_TEXTURE_MAX_CLAMP_R_SGIX
	if ( en == GL_TEXTURE_MAX_CLAMP_R_SGIX ) return "GL_TEXTURE_MAX_CLAMP_R_SGIX";
#endif
#ifdef GL_TEXTURE_MULTI_BUFFER_HINT_SGIX
	if ( en == GL_TEXTURE_MULTI_BUFFER_HINT_SGIX ) return "GL_TEXTURE_MULTI_BUFFER_HINT_SGIX";
#endif
#ifdef GL_RGB_SIGNED_SGIX
	if ( en == GL_RGB_SIGNED_SGIX ) return "GL_RGB_SIGNED_SGIX";
#endif
#ifdef GL_RGBA_SIGNED_SGIX
	if ( en == GL_RGBA_SIGNED_SGIX ) return "GL_RGBA_SIGNED_SGIX";
#endif
#ifdef GL_ALPHA_SIGNED_SGIX
	if ( en == GL_ALPHA_SIGNED_SGIX ) return "GL_ALPHA_SIGNED_SGIX";
#endif
#ifdef GL_LUMINANCE_SIGNED_SGIX
	if ( en == GL_LUMINANCE_SIGNED_SGIX ) return "GL_LUMINANCE_SIGNED_SGIX";
#endif
#ifdef GL_INTENSITY_SIGNED_SGIX
	if ( en == GL_INTENSITY_SIGNED_SGIX ) return "GL_INTENSITY_SIGNED_SGIX";
#endif
#ifdef GL_LUMINANCE_ALPHA_SIGNED_SGIX
	if ( en == GL_LUMINANCE_ALPHA_SIGNED_SGIX ) return "GL_LUMINANCE_ALPHA_SIGNED_SGIX";
#endif
#ifdef GL_RGB16_SIGNED_SGIX
	if ( en == GL_RGB16_SIGNED_SGIX ) return "GL_RGB16_SIGNED_SGIX";
#endif
#ifdef GL_RGBA16_SIGNED_SGIX
	if ( en == GL_RGBA16_SIGNED_SGIX ) return "GL_RGBA16_SIGNED_SGIX";
#endif
#ifdef GL_ALPHA16_SIGNED_SGIX
	if ( en == GL_ALPHA16_SIGNED_SGIX ) return "GL_ALPHA16_SIGNED_SGIX";
#endif
#ifdef GL_LUMINANCE16_SIGNED_SGIX
	if ( en == GL_LUMINANCE16_SIGNED_SGIX ) return "GL_LUMINANCE16_SIGNED_SGIX";
#endif
#ifdef GL_INTENSITY16_SIGNED_SGIX
	if ( en == GL_INTENSITY16_SIGNED_SGIX ) return "GL_INTENSITY16_SIGNED_SGIX";
#endif
#ifdef GL_LUMINANCE16_ALPHA16_SIGNED_SGIX
	if ( en == GL_LUMINANCE16_ALPHA16_SIGNED_SGIX ) return "GL_LUMINANCE16_ALPHA16_SIGNED_SGIX";
#endif
#ifdef GL_RGB_EXTENDED_RANGE_SGIX
	if ( en == GL_RGB_EXTENDED_RANGE_SGIX ) return "GL_RGB_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_RGBA_EXTENDED_RANGE_SGIX
	if ( en == GL_RGBA_EXTENDED_RANGE_SGIX ) return "GL_RGBA_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_ALPHA_EXTENDED_RANGE_SGIX
	if ( en == GL_ALPHA_EXTENDED_RANGE_SGIX ) return "GL_ALPHA_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_LUMINANCE_EXTENDED_RANGE_SGIX
	if ( en == GL_LUMINANCE_EXTENDED_RANGE_SGIX ) return "GL_LUMINANCE_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_INTENSITY_EXTENDED_RANGE_SGIX
	if ( en == GL_INTENSITY_EXTENDED_RANGE_SGIX ) return "GL_INTENSITY_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX
	if ( en == GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX ) return "GL_LUMINANCE_ALPHA_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_RGB16_EXTENDED_RANGE_SGIX
	if ( en == GL_RGB16_EXTENDED_RANGE_SGIX ) return "GL_RGB16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_RGBA16_EXTENDED_RANGE_SGIX
	if ( en == GL_RGBA16_EXTENDED_RANGE_SGIX ) return "GL_RGBA16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_ALPHA16_EXTENDED_RANGE_SGIX
	if ( en == GL_ALPHA16_EXTENDED_RANGE_SGIX ) return "GL_ALPHA16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_LUMINANCE16_EXTENDED_RANGE_SGIX
	if ( en == GL_LUMINANCE16_EXTENDED_RANGE_SGIX ) return "GL_LUMINANCE16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_INTENSITY16_EXTENDED_RANGE_SGIX
	if ( en == GL_INTENSITY16_EXTENDED_RANGE_SGIX ) return "GL_INTENSITY16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX
	if ( en == GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX ) return "GL_LUMINANCE16_ALPHA16_EXTENDED_RANGE_SGIX";
#endif
#ifdef GL_MIN_LUMINANCE_SGIS
	if ( en == GL_MIN_LUMINANCE_SGIS ) return "GL_MIN_LUMINANCE_SGIS";
#endif
#ifdef GL_MAX_LUMINANCE_SGIS
	if ( en == GL_MAX_LUMINANCE_SGIS ) return "GL_MAX_LUMINANCE_SGIS";
#endif
#ifdef GL_MIN_INTENSITY_SGIS
	if ( en == GL_MIN_INTENSITY_SGIS ) return "GL_MIN_INTENSITY_SGIS";
#endif
#ifdef GL_MAX_INTENSITY_SGIS
	if ( en == GL_MAX_INTENSITY_SGIS ) return "GL_MAX_INTENSITY_SGIS";
#endif
#ifdef GL_POST_TEXTURE_FILTER_BIAS_SGIX
	if ( en == GL_POST_TEXTURE_FILTER_BIAS_SGIX ) return "GL_POST_TEXTURE_FILTER_BIAS_SGIX";
#endif
#ifdef GL_POST_TEXTURE_FILTER_SCALE_SGIX
	if ( en == GL_POST_TEXTURE_FILTER_SCALE_SGIX ) return "GL_POST_TEXTURE_FILTER_SCALE_SGIX";
#endif
#ifdef GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX
	if ( en == GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX ) return "GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX";
#endif
#ifdef GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX
	if ( en == GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX ) return "GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX";
#endif
#ifdef GL_VERTEX_PRECLIP_SGIX
	if ( en == GL_VERTEX_PRECLIP_SGIX ) return "GL_VERTEX_PRECLIP_SGIX";
#endif
#ifdef GL_VERTEX_PRECLIP_HINT_SGIX
	if ( en == GL_VERTEX_PRECLIP_HINT_SGIX ) return "GL_VERTEX_PRECLIP_HINT_SGIX";
#endif
#ifdef GL_VERTEX_PRECLIP_SGIX
	if ( en == GL_VERTEX_PRECLIP_SGIX ) return "GL_VERTEX_PRECLIP_SGIX";
#endif
#ifdef GL_VERTEX_PRECLIP_HINT_SGIX
	if ( en == GL_VERTEX_PRECLIP_HINT_SGIX ) return "GL_VERTEX_PRECLIP_HINT_SGIX";
#endif
#ifdef GL_COLOR_MATRIX_SGI
	if ( en == GL_COLOR_MATRIX_SGI ) return "GL_COLOR_MATRIX_SGI";
#endif
#ifdef GL_COLOR_MATRIX_STACK_DEPTH_SGI
	if ( en == GL_COLOR_MATRIX_STACK_DEPTH_SGI ) return "GL_COLOR_MATRIX_STACK_DEPTH_SGI";
#endif
#ifdef GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI
	if ( en == GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI ) return "GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_SCALE_SGI
	if ( en == GL_POST_COLOR_MATRIX_RED_SCALE_SGI ) return "GL_POST_COLOR_MATRIX_RED_SCALE_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI
	if ( en == GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI ) return "GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI
	if ( en == GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI ) return "GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI
	if ( en == GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI ) return "GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_RED_BIAS_SGI
	if ( en == GL_POST_COLOR_MATRIX_RED_BIAS_SGI ) return "GL_POST_COLOR_MATRIX_RED_BIAS_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI
	if ( en == GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI ) return "GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI
	if ( en == GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI ) return "GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI
	if ( en == GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI ) return "GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI";
#endif
#ifdef GL_COLOR_TABLE_SGI
	if ( en == GL_COLOR_TABLE_SGI ) return "GL_COLOR_TABLE_SGI";
#endif
#ifdef GL_POST_CONVOLUTION_COLOR_TABLE_SGI
	if ( en == GL_POST_CONVOLUTION_COLOR_TABLE_SGI ) return "GL_POST_CONVOLUTION_COLOR_TABLE_SGI";
#endif
#ifdef GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI
	if ( en == GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI ) return "GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI";
#endif
#ifdef GL_PROXY_COLOR_TABLE_SGI
	if ( en == GL_PROXY_COLOR_TABLE_SGI ) return "GL_PROXY_COLOR_TABLE_SGI";
#endif
#ifdef GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI
	if ( en == GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI ) return "GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI";
#endif
#ifdef GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI
	if ( en == GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI ) return "GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI";
#endif
#ifdef GL_COLOR_TABLE_SCALE_SGI
	if ( en == GL_COLOR_TABLE_SCALE_SGI ) return "GL_COLOR_TABLE_SCALE_SGI";
#endif
#ifdef GL_COLOR_TABLE_BIAS_SGI
	if ( en == GL_COLOR_TABLE_BIAS_SGI ) return "GL_COLOR_TABLE_BIAS_SGI";
#endif
#ifdef GL_COLOR_TABLE_FORMAT_SGI
	if ( en == GL_COLOR_TABLE_FORMAT_SGI ) return "GL_COLOR_TABLE_FORMAT_SGI";
#endif
#ifdef GL_COLOR_TABLE_WIDTH_SGI
	if ( en == GL_COLOR_TABLE_WIDTH_SGI ) return "GL_COLOR_TABLE_WIDTH_SGI";
#endif
#ifdef GL_COLOR_TABLE_RED_SIZE_SGI
	if ( en == GL_COLOR_TABLE_RED_SIZE_SGI ) return "GL_COLOR_TABLE_RED_SIZE_SGI";
#endif
#ifdef GL_COLOR_TABLE_GREEN_SIZE_SGI
	if ( en == GL_COLOR_TABLE_GREEN_SIZE_SGI ) return "GL_COLOR_TABLE_GREEN_SIZE_SGI";
#endif
#ifdef GL_COLOR_TABLE_BLUE_SIZE_SGI
	if ( en == GL_COLOR_TABLE_BLUE_SIZE_SGI ) return "GL_COLOR_TABLE_BLUE_SIZE_SGI";
#endif
#ifdef GL_COLOR_TABLE_ALPHA_SIZE_SGI
	if ( en == GL_COLOR_TABLE_ALPHA_SIZE_SGI ) return "GL_COLOR_TABLE_ALPHA_SIZE_SGI";
#endif
#ifdef GL_COLOR_TABLE_LUMINANCE_SIZE_SGI
	if ( en == GL_COLOR_TABLE_LUMINANCE_SIZE_SGI ) return "GL_COLOR_TABLE_LUMINANCE_SIZE_SGI";
#endif
#ifdef GL_COLOR_TABLE_INTENSITY_SIZE_SGI
	if ( en == GL_COLOR_TABLE_INTENSITY_SIZE_SGI ) return "GL_COLOR_TABLE_INTENSITY_SIZE_SGI";
#endif
#ifdef GL_TEXTURE_COLOR_TABLE_SGI
	if ( en == GL_TEXTURE_COLOR_TABLE_SGI ) return "GL_TEXTURE_COLOR_TABLE_SGI";
#endif
#ifdef GL_PROXY_TEXTURE_COLOR_TABLE_SGI
	if ( en == GL_PROXY_TEXTURE_COLOR_TABLE_SGI ) return "GL_PROXY_TEXTURE_COLOR_TABLE_SGI";
#endif
#ifdef GL_UNPACK_CONSTANT_DATA_SUNX
	if ( en == GL_UNPACK_CONSTANT_DATA_SUNX ) return "GL_UNPACK_CONSTANT_DATA_SUNX";
#endif
#ifdef GL_TEXTURE_CONSTANT_DATA_SUNX
	if ( en == GL_TEXTURE_CONSTANT_DATA_SUNX ) return "GL_TEXTURE_CONSTANT_DATA_SUNX";
#endif
#ifdef GL_WRAP_BORDER_SUN
	if ( en == GL_WRAP_BORDER_SUN ) return "GL_WRAP_BORDER_SUN";
#endif
#ifdef GL_GLOBAL_ALPHA_SUN
	if ( en == GL_GLOBAL_ALPHA_SUN ) return "GL_GLOBAL_ALPHA_SUN";
#endif
#ifdef GL_GLOBAL_ALPHA_FACTOR_SUN
	if ( en == GL_GLOBAL_ALPHA_FACTOR_SUN ) return "GL_GLOBAL_ALPHA_FACTOR_SUN";
#endif
#ifdef GL_QUAD_MESH_SUN
	if ( en == GL_QUAD_MESH_SUN ) return "GL_QUAD_MESH_SUN";
#endif
#ifdef GL_TRIANGLE_MESH_SUN
	if ( en == GL_TRIANGLE_MESH_SUN ) return "GL_TRIANGLE_MESH_SUN";
#endif
#ifdef GL_SLICE_ACCUM_SUN
	if ( en == GL_SLICE_ACCUM_SUN ) return "GL_SLICE_ACCUM_SUN";
#endif
#ifdef GL_RESTART_SUN
	if ( en == GL_RESTART_SUN ) return "GL_RESTART_SUN";
#endif
#ifdef GL_REPLACE_MIDDLE_SUN
	if ( en == GL_REPLACE_MIDDLE_SUN ) return "GL_REPLACE_MIDDLE_SUN";
#endif
#ifdef GL_REPLACE_OLDEST_SUN
	if ( en == GL_REPLACE_OLDEST_SUN ) return "GL_REPLACE_OLDEST_SUN";
#endif
#ifdef GL_TRIANGLE_LIST_SUN
	if ( en == GL_TRIANGLE_LIST_SUN ) return "GL_TRIANGLE_LIST_SUN";
#endif
#ifdef GL_REPLACEMENT_CODE_SUN
	if ( en == GL_REPLACEMENT_CODE_SUN ) return "GL_REPLACEMENT_CODE_SUN";
#endif
#ifdef GL_REPLACEMENT_CODE_ARRAY_SUN
	if ( en == GL_REPLACEMENT_CODE_ARRAY_SUN ) return "GL_REPLACEMENT_CODE_ARRAY_SUN";
#endif
#ifdef GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN
	if ( en == GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN ) return "GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN";
#endif
#ifdef GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN
	if ( en == GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN ) return "GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN";
#endif
#ifdef GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN
	if ( en == GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN ) return "GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN";
#endif
#ifdef GL_R1UI_V3F_SUN
	if ( en == GL_R1UI_V3F_SUN ) return "GL_R1UI_V3F_SUN";
#endif
#ifdef GL_R1UI_C4UB_V3F_SUN
	if ( en == GL_R1UI_C4UB_V3F_SUN ) return "GL_R1UI_C4UB_V3F_SUN";
#endif
#ifdef GL_R1UI_C3F_V3F_SUN
	if ( en == GL_R1UI_C3F_V3F_SUN ) return "GL_R1UI_C3F_V3F_SUN";
#endif
#ifdef GL_R1UI_N3F_V3F_SUN
	if ( en == GL_R1UI_N3F_V3F_SUN ) return "GL_R1UI_N3F_V3F_SUN";
#endif
#ifdef GL_R1UI_C4F_N3F_V3F_SUN
	if ( en == GL_R1UI_C4F_N3F_V3F_SUN ) return "GL_R1UI_C4F_N3F_V3F_SUN";
#endif
#ifdef GL_R1UI_T2F_V3F_SUN
	if ( en == GL_R1UI_T2F_V3F_SUN ) return "GL_R1UI_T2F_V3F_SUN";
#endif
#ifdef GL_R1UI_T2F_N3F_V3F_SUN
	if ( en == GL_R1UI_T2F_N3F_V3F_SUN ) return "GL_R1UI_T2F_N3F_V3F_SUN";
#endif
#ifdef GL_R1UI_T2F_C4F_N3F_V3F_SUN
	if ( en == GL_R1UI_T2F_C4F_N3F_V3F_SUN ) return "GL_R1UI_T2F_C4F_N3F_V3F_SUN";
#endif
#ifdef GL_PHONG_WIN
	if ( en == GL_PHONG_WIN ) return "GL_PHONG_WIN";
#endif
#ifdef GL_PHONG_HINT_WIN
	if ( en == GL_PHONG_HINT_WIN ) return "GL_PHONG_HINT_WIN";
#endif
#ifdef GL_FOG_SPECULAR_TEXTURE_WIN
	if ( en == GL_FOG_SPECULAR_TEXTURE_WIN ) return "GL_FOG_SPECULAR_TEXTURE_WIN";
#endif
	else return "UNKNOWN ENUM";
}

void InfiGLPrint( std::ostream& ostr, uint32 en ) {
	ostr << glenum(en);
}

} }
