#include "core/infi_random.h"
#include "main/infi_error.h"

namespace INFI {
namespace core {

#ifdef __WIN32__
	random_t::random_t() {
		if ( !CryptAcquireContextW( &prov, 0, 0, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT ) )
			InfiSendError( INFI_SYSTEM_ERROR, "Random.Ctor()", "Could not generate randomization context --> WIN32"  );
	}
	random_t::~random_t() {
		CryptReleaseContext( prov, 0 );
	}
	uint32 random_t::decimal32() const { 
		return float32(float64(this->integer32()) / float64((uint32)-1));
	}
	uint64 random_t::decimal64() const {
		return float64(this->integer32()) / float64((uint32)-1);
	}
	uint32 random_t::integer32() const {
		uint32 buffer;
		CryptGenRandom( prov, sizeof( uint32 ), (uint8*) &buffer );
		return buffer;
	}
#else
	random_t() { srand( time(NULL) ); }
	~random_t() { }
	float32 random_t::decimal32() () const { return float32(rand()) / float32(RAND_MAX); }
	float64 random_t::decimal64() const { return float64(rand()) / float64(RAND_MAX); }
	uint32 random_t::integer32() () const { return rand(); }
#endif

float32 random_t::weighted32( float32 mean, float32 var ) const {
	return 0.f;
}
float64 random_t::weighted64( float64 mean, float64 var ) const {
	return 0.0;
}

float32 random_t::operator() () const{ return this->decimal32(); }
float32 random_t::range( float32 low,float32 up ) const { return this->decimal32() * (up-low) + low; }
int32 random_t::intrange( int32 low, int32 up ) const { return this->integer32() % (up-low) + low; }

void random_t::vector( vec2& v ) const {
	v.x *= this->decimal32();
	v.y *= this->decimal32();
}
void random_t::vector( vec3& v ) const {
	v.x *= this->decimal32();
	v.y *= this->decimal32();
	v.z *= this->decimal32();
}
void random_t::vector( vec4& v ) const {
	v.x *= this->decimal32();
	v.y *= this->decimal32();
	v.z *= this->decimal32();
	v.w *= this->decimal32();
}

const random_t& Randomom() {
	static const random_t __main__;
	return __main__;
}

} }
