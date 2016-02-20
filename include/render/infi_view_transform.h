#ifndef __INFI_VIEWPORT_H__
#define __INFI_VIEWPORT_H__

#include "core/infi_matrix.h"
#include "core/infi_quaternion.h"
#include "core/infi_rect.h"
#include "render/infi_render.h"

namespace INFI {
namespace render {

struct infi_view_transform_t {
	virtual ~infi_view_transform_t() { ; }
	virtual operator core::mat4() const = 0;
};

struct infi_view_matrix_t : infi_view_transform_t {
	infi_view_matrix_t();
	core::mat4 transform_matrix;
};

struct infi_orthogonal_t : infi_view_matrix_t {
	core::vec2 offset;
	core::vec2 dimensions;
	operator core::mat4() const;
};
struct infi_projection_t : infi_view_matrix_t {
	float32 closeview;
	float32 farview;
	float32 fov;
	operator core::mat4() const;
};

struct infi_camera_t : infi_projection_t {
	core::vec3 position;
	core::quaternion_t rotation;
	
	core::vec3 forward();
	core::vec3 up();
	core::vec3 right();
	
	void look_at( const core::vec3& to );
	
	operator core::mat4() const;
};

INFI_FUNCTION( infi_orthogonal_t*, InfiCreateOrthogonal, ( float32, float32 ) );
INFI_FUNCTION( infi_orthogonal_t*, InfiCreateOrthogonal, ( const core::vec2& ) );
INFI_FUNCTION( infi_orthogonal_t*, InfiCreateOrthogonal, ( float32, float32, float32, float32 ) );
INFI_FUNCTION( infi_orthogonal_t*, InfiCreateOrthogonal, ( const core::vec2&, const core::vec2& ) );
INFI_FUNCTION( infi_orthogonal_t*, InfiCreateOrthogonal, ( const core::rectf& ) );

INFI_FUNCTION( infi_projection_t*, InfiCreateProjection, ( float32 = 1.22173048 ) );

INFI_FUNCTION( infi_camera_t*, InfiCreateCamera, ( const core::vec3&, const core::quaternion_t&, float32 = 1.22173048 ) );

INFI_FUNCTION( const core::mat4&, InfiGetCamera, () );
INFI_FUNCTION( infi_view_transform_t*, InfiCurrentCamera, () );
INFI_FUNCTION( void, InfiPushCamera, () );
INFI_FUNCTION( void, InfiPushCamera, ( infi_view_transform_t* ) );
INFI_FUNCTION( void, InfiPopCamera, () );

} }

#endif//__INFI_VIEWPORT_H__