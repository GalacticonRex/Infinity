#ifndef __INFI_QUATERNION_H__
#define __INFI_QUATERNION_H__

#include "core/infi_vector.h"

namespace INFI {
namespace core {

	struct INFI_EXPORT quaternion_t {
		float32 i,j,k,w;
		
		quaternion_t();
		quaternion_t(float32,float32,float32,float32);
		
		quaternion_t operator+ () const;
		quaternion_t operator- () const;
		
		const vec4& asVector() const;
		quaternion_t inverse() const;
	};

	INFI_FUNCTION( const quaternion_t&, asQuaternion, (const vec4&) );

	INFI_FUNCTION( float32, Dot, (const quaternion_t&,const quaternion_t&) );
	INFI_FUNCTION( quaternion_t, Blend, (const quaternion_t&,const quaternion_t&,float32=.5) );
	INFI_FUNCTION( quaternion_t, Concatenate, (const quaternion_t&,const quaternion_t&) );
	INFI_FUNCTION( quaternion_t, Integrate, (const quaternion_t&,vec3,float32=1.) );
	INFI_FUNCTION( quaternion_t, Integrate, (const quaternion_t&,const quaternion_t&,float32=1.) );
	INFI_FUNCTION( quaternion_t, Product, (const quaternion_t&,const quaternion_t&) );

	INFI_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const quaternion_t& ) );

} }

#endif//__INFI_QUATERNION_H__
