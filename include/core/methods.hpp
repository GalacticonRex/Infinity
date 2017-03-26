#ifndef __MISC_FUNCTIONS_H__
#define __MISC_FUNCTIONS_H__

#include "core/vector.hpp"
#include "core/matrix.hpp"

namespace core {

// Core STD Functions
DEFINE_EXPORTED_FUNCTION( float32, rad2deg, (float32) );
DEFINE_EXPORTED_FUNCTION( float32, deg2rad, (float32) );

DEFINE_EXPORTED_FUNCTION( float32, Clamp, (float32,float32=0.,float32=1.) );

DEFINE_EXPORTED_FUNCTION( int32, MakePow2, (int32) );
DEFINE_EXPORTED_FUNCTION( vec2i, MakePow2, (vec2i) );
DEFINE_EXPORTED_FUNCTION( vec3i, MakePow2, (vec3i) );
DEFINE_EXPORTED_FUNCTION( vec4i, MakePow2, (vec4i) );

DEFINE_EXPORTED_FUNCTION( uint32, MakePow2, (uint32) );
DEFINE_EXPORTED_FUNCTION( vec2ui, MakePow2, (vec2ui) );
DEFINE_EXPORTED_FUNCTION( vec3ui, MakePow2, (vec3ui) );
DEFINE_EXPORTED_FUNCTION( vec4ui, MakePow2, (vec4ui) );

}

#endif//__MISC_FUNCTIONS_H__
