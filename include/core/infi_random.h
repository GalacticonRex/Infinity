#ifndef __INFI_RANDOM_H__
#define __INFI_RANDOM_H__

#include "core/infi_vector.h"

#ifdef __WIN32__
	#include <windows.h>
	#include <Wincrypt.h>
#endif

namespace INFI {
namespace core {

struct INFI_EXPORT random_t {
	
	random_t();
	~random_t();
	
	uint32  decimal32() const;
	uint64  decimal64() const;
	uint32	integer32() const;
	
	float32 weighted32( float32 mean, float32 var ) const;
	float64 weighted64( float64 mean, float64 var ) const;
	
	float32 operator() () const;
	float32 range( float32=0.f,float32=1.f ) const;
	int32	intrange( int32, int32 ) const;
	
	// random values between 0 and 1
	void	vector( vec2& ) const;
	void	vector( vec3& ) const;
	void	vector( vec4& ) const;
	
	// control upper limit ( 0 is lower limit )
	void	vector( vec2&, const vec2& ) const;
	void	vector( vec3&, const vec3& ) const;
	void	vector( vec4&, const vec4& ) const;
	
	// control upper and lower limits 
	void	vector( vec2&, const vec2&, const vec2& ) const;
	void	vector( vec3&, const vec3&, const vec3& ) const;
	void	vector( vec4&, const vec4&, const vec4& ) const;
	
	#ifdef __WIN32__
		HCRYPTPROV prov;
	#endif
} static Random;

} }

#endif//__INFI_RANDOM_H__
