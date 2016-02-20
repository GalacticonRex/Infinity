#include "core/infi_convert.h"
#include "core/infi_stack.h"
#include "core/infi_methods.h"
#include "render/infi_canvas.h"
#include "render/infi_view_transform.h"

namespace INFI {
namespace render {

namespace {
	using namespace core;
}

static core::stack_t<infi_view_transform_t*> viewstack;
static core::mat4 buffer;

const core::mat4& InfiGetCamera() {
	infi_view_transform_t* vi = InfiCurrentCamera();
	buffer = (vi) ? *vi : mat4::identity();
	return buffer;
}
infi_view_transform_t* InfiCurrentCamera() {
	return (viewstack.empty()) ? NULL : *viewstack;
}
void InfiPushCamera() {
	InfiPushFunction( "InfiPushCamera" );
	infi_canvas_t* cv = NULL;
	if ( InfiCanvasIsTexture() ) {
		viewstack.push( InfiCurrentTextureCanvas() );
	} else if ( ( cv = InfiCurrentCanvas() ) == NULL ) {
		viewstack.push( InfiRenderWindow() );
	} else {
		viewstack.push( cv );
	}
	InfiPopFunction();
}
void InfiPushCamera( infi_view_transform_t* v ) {
	InfiPushFunction( "InfiPushCamera" );
	viewstack.push( v );
	InfiPopFunction();
}
void InfiPopCamera() {
	InfiPushFunction( "InfiPopCamera" );
	viewstack.pop();
	InfiPopFunction();
}

infi_view_matrix_t::infi_view_matrix_t() 
	: transform_matrix( mat4::identity() ) { ; }
	
void infi_camera_t::look_at( const vec3& to ) {
	//vec3 dif = to - position;
	//vec3 crx = Cross( dif,  );
}

infi_orthogonal_t::operator core::mat4() const {
	mat4 proj = OrthoMat4( offset, dimensions );
	return proj * transform_matrix;
}

infi_projection_t::operator core::mat4() const {
	mat4 proj = Perspective( fov, InfiGetRatio(), closeview, farview );
	return proj * transform_matrix;
}

infi_camera_t::operator core::mat4() const {
	mat4 proj = Perspective( fov, InfiGetRatio(), closeview, farview );
	mat4 move = ExpandMat4( toMatrix( rotation ) ) * TranslationMatrix( -position );
	return proj * transform_matrix * move;
}

infi_orthogonal_t* InfiCreateOrthogonal( float32 x, float32 y, float32 w, float32 h ) {
	infi_orthogonal_t* ret = new infi_orthogonal_t;
	ret->offset = vec2(x,y);
	ret->dimensions = vec2(w,h);
	return ret;
}
infi_orthogonal_t* InfiCreateOrthogonal( float32 w, float32 h ) {
	return InfiCreateOrthogonal( 0, 0, w, h );
}
infi_orthogonal_t* InfiCreateOrthogonal( const vec2& dim ) {
	return InfiCreateOrthogonal( 0, 0, dim.x, dim.y );
}
infi_orthogonal_t* InfiCreateOrthogonal( const vec2& start, const vec2& finish ) {
	return InfiCreateOrthogonal( start.x, start.y, finish.x - start.x, finish.y - start.y );
}
infi_orthogonal_t* InfiCreateOrthogonal( const rectf& r ) {
	return InfiCreateOrthogonal( r.x, r.y, r.w, r.h );
}

infi_projection_t* InfiCreateProjection( float32 f ) {
	infi_projection_t* ret = new infi_projection_t;
	ret->closeview = 0.1;
	ret->farview = 1000;
	ret->fov = f;
	return ret;
}

infi_camera_t* InfiCreateCamera( const vec3& pos, const quaternion_t& rot, float32 f ) {
	infi_camera_t* ret = new infi_camera_t;
	ret->position = pos;
	ret->rotation = rot;
	ret->closeview = 0.1;
	ret->farview = 1000;
	ret->fov = f;
	return ret;
}

} }