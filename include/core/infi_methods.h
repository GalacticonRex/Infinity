#ifndef __INFI_MISC_FUNCTION_H__
#define __INFI_MISC_FUNCTION_H__

#include "core/infi_vector.h"
#include "core/infi_matrix.h"

namespace INFI {
namespace core {

// Create basic matrices
INFI_FUNCTION( mat3, TranslationMatrix, ( vec2 ) );
INFI_FUNCTION( mat4, TranslationMatrix, ( vec3 ) );
INFI_FUNCTION( mat3, ScalingMatrix, ( vec2 ) );
INFI_FUNCTION( mat4, ScalingMatrix, ( vec3 ) );

INFI_FUNCTION( mat3, OrthoMat3, ( vec2, vec2 ) );
INFI_FUNCTION( mat4, OrthoMat4, ( vec2, vec2 ) );
INFI_FUNCTION( mat4, Perspective, ( float32,float32,float32,float32 ) );

// Core STD Functions
INFI_FUNCTION( float32, rad2deg, (float32) );
INFI_FUNCTION( float32, deg2rad, (float32) );

INFI_FUNCTION( float32, Clamp, (float32,float32=0.,float32=1.) );

INFI_FUNCTION( int32, MakePow2, (int32) );
INFI_FUNCTION( vec2i, MakePow2, (vec2i) );
INFI_FUNCTION( vec3i, MakePow2, (vec3i) );
INFI_FUNCTION( vec4i, MakePow2, (vec4i) );

INFI_FUNCTION( uint32, MakePow2, (uint32) );
INFI_FUNCTION( vec2ui, MakePow2, (vec2ui) );
INFI_FUNCTION( vec3ui, MakePow2, (vec3ui) );
INFI_FUNCTION( vec4ui, MakePow2, (vec4ui) );

} }

#endif