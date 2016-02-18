#include <cstdlib>
#include <cstring>

#include "core/infi_string.h"
#include "main/infi_error.h"

namespace INFI {
namespace core {
	
	#define STRING_OFFSET_CONSTANT (sizeof(uint32) << 2)
	
	#define STRING_ATTRIB_DATA 	1
	#define STRING_ATTRIB_SIZE 	2
	#define STRING_ATTRIB_ALLOC 3
	#define STRING_ATTRIB_REF 	4
	
	// get the amount of space 
	static uint32 get_allocation_size_from( char* str, uint32 );
	
	// set string attribs
	static uint32& string_alloc( char* str );
	static uint32& string_size( char* str );
	static const uint32& string_ref( char* str );
	static void string_increment( char* str );
	static void string_decrement( char* str );
	
	// get the first character of a string
	static char* string_start( const string_t& );
	
	// allocate a new string data big enough to fit <sz>
	static char* string_allocate( char* str, uint32 sz );
	
	// initializes the string data
	static char* string_initialize( string_t&, char*, uint32=1, uint32=0 );
	
	// assigns a new string (and increments)
	static char* string_assign( string_t&, char*, uint32=1, uint32=0 );
	
	// copy the contents of <src> to the location pointed to by <str>
	// <offset> determines the start point in the <src>
	// <stroffset> determines the start point in the <str>
	// <len> determines the number of bytes to be copied
	static char* string_copy( char* str, string_t& src, uint32 offset, uint32 len );
	
	// creates a duplicate of <str>, but with string attributes
	static char* string_dup( const char* str, uint32 len );
	
	// reallocates a string so that it can fit within the requested space
	static void string_realloc( string_t&, uint32 len );
	
	
	
	
	
	std::ostream& operator<<( std::ostream& ostr, const string_t& str ) {
		const char* c = str.from(0);
		const char* c2 = str.from(str.size());
		if ( *c2 == '\0' )
			ostr << c;
		else
			for ( ;c<c2;++c )
				ostr << *c;
		return ostr;
	}
	
	uint32 string_t::last() const {
		uint32 sz = this->size();
		return (sz==0) ? 0 : sz - 1;
	}
	uint32 string_t::size() const {
		return ( this->is_substr() ) ?
							( end - start ) : 
							string_size( data );
	}
	uint32 string_t::allocated() const {
		return string_alloc( data );
	}
	uint32 string_t::associated() const {
		return string_ref( data );
	}
	bool string_t::is_substr() const {
		return start <= end;
	}
	
	string_t::string_t()
		: data( string_allocate(NULL,0) ) {
		string_size( data ) = 0;
	}
	string_t::string_t( const char* str ) {
		string_initialize( *this, string_dup( str, strlen( str ) ) );
	}
	string_t::string_t( const char* s1, const char* s2 ) {
		InfiPushFunction( "string_t.ctor" );
		if ( s1 > s2 )
			InfiSendError( INFI_INDEX_ERROR,
						   "initial string does not terminate at final string" );
		string_initialize( *this, string_dup( s1, s2 - s1 ) );
		InfiPopFunction();
	}
	string_t::string_t( char* str, uint32 a, uint32 b ) {
		string_initialize( *this, str, a, b );
	}
	string_t::string_t( const string_t& str ) {
		string_initialize( *this, str.data, str.start, str.end );
	}
	string_t::string_t( char c ) {
		string_initialize( *this, string_dup( &c, 1 ) );
	}
	string_t::string_t( char c, uint32 len ) {
		string_initialize( *this, string_allocate( NULL, len ) );
		string_size( data ) = len;
		
		for ( uint32 i=0;i<len;data[i] = c,++i );
		data[len] = '\0';
	}
	
	string_t& string_t::operator= ( const char* str ) {
		string_assign( *this, string_dup( str, strlen(str) ) );
		return *this;
	}
	string_t& string_t::operator= ( const string_t& str ) {
		string_assign( *this, str.data, str.start, str.end );
		return *this;
	}
	
	string_t::~string_t() {
		string_decrement( data );
	}
	
	void string_t::clear() {
		start = 0;
		end = 0;
	}
	
	char string_t::operator[] ( uint32 i ) const {
		InfiPushFunction( "string_t.[]" );
		if ( i >= size() )
			InfiSendError( INFI_INDEX_ERROR, 
						   "Indexing element %d out of %d", i, size() );
		InfiPopFunction();
		return string_start(*this)[i];
	}
	const char* string_t::from( uint32 offset ) const {
		InfiPushFunction( "string_t.from" );
		if ( offset > size() )
			InfiSendError( INFI_INDEX_ERROR, 
						   "Accessing string from location %d out of %d", offset, size() );
		InfiPopFunction();
		return string_start(*this) + offset;
	}
	const char* string_t::source() {
		if ( is_substr() )
			string_assign( *this,
				string_copy( 
					string_allocate( data, size() ), 
					*this, 0, size() 
				) 
			);
		return data;
	}
	string_t string_t::localize() const {
		return string_t( this->from(0),
						 this->from(size()) );
	}
	char* string_t::duplicate() const {
		uint32 sz = size();
		
		char* ndata = new char[sz+1];
		memcpy( ndata, string_start(*this), sz );
		ndata[sz] = '\0';
		
		return ndata;
	}
	
	#define STROTHER str
	#define STRLEN len

	#define COMPARE_EQ(A,B) \
			if ( A != B ) \
				return false;
			
	#define COMPARE_LT(A,B) \
			if ( A != B ) \
				return (A<B);

	#define COMPARE_GT(A,B) \
			if ( A != B ) \
				return (A>B);
			
	#define GET_MIN_LEN(strsz) \
			uint32 STRLEN = ( this->size() < strsz ) ? this->size() : strsz;
		
	#define GET_EQ_LEN(strsz) \
			if ( this->size() != strsz )\
				return false; \
			uint32 STRLEN = this->size();
		
	#define COMPARE_STR( func ) \
			for ( uint32 i=0;i<STRLEN;i++ ) \
				func((*this)[i],STROTHER[i])
				
	#define COMPARE_FAIL( func ) \
			return ( func );
		
	#define COMPARE( op, other, A, B, C ) \
		bool string_t::operator op ( other STROTHER ) const { \
			A COMPARE_STR(B) COMPARE_FAIL(C) \
		}
		
	#define COMPAREC( op, fail ) \
		bool string_t::operator op ( char STROTHER ) const { \
			if ( this->size() fail ) return false; \
			return ( (*this)[0] op STROTHER ); \
		}

	COMPARE( <, const string_t&,
			 GET_MIN_LEN(STROTHER.size()), 
			 COMPARE_LT, 
			 this->size() == STRLEN && this->size() != STROTHER.size() );
	COMPARE( <=, const string_t&,
			 GET_MIN_LEN(STROTHER.size()),
			 COMPARE_LT,
			 this->size() == STROTHER.size() );
	COMPARE( >, const string_t&,
			 GET_MIN_LEN(STROTHER.size()),
			 COMPARE_GT,
			 STROTHER.size() == STRLEN && this->size() != STROTHER.size());
	COMPARE( >=, const string_t&,
			 GET_MIN_LEN(STROTHER.size()),
			 COMPARE_GT,
			 this->size() == STROTHER.size() );
	COMPARE( ==, const string_t&,
			 GET_EQ_LEN(STROTHER.size()),
			 COMPARE_EQ,
			 true );

	COMPARE( <, const char*,
			 GET_MIN_LEN(strlen(STROTHER)),
			 COMPARE_LT,
			 this->size() == STRLEN && this->size() != strlen(STROTHER) );
	COMPARE( <=, const char*,
			 GET_MIN_LEN(strlen(STROTHER)),
			 COMPARE_LT,
			 this->size() == strlen(STROTHER) );
	COMPARE( >, const char*,
			 GET_MIN_LEN(strlen(STROTHER)),
			 COMPARE_GT,
			 strlen(STROTHER) == STRLEN && this->size() != strlen(STROTHER) );
	COMPARE( >=, const char*,
			 GET_MIN_LEN(strlen(STROTHER)),
			 COMPARE_GT,
			 this->size() == strlen(STROTHER) );
	COMPARE( ==, const char*,
			 GET_EQ_LEN(strlen(STROTHER)),
			 COMPARE_EQ,
			 true );

	COMPAREC( <, == 0 );
	COMPAREC( >, == 0 );
	COMPAREC( ==, != 1 );

	bool string_t::operator<= ( char str ) const {
		return ( (*this) < str || (*this) == str );
	}
	bool string_t::operator>= ( char str ) const {
		return ( (*this) > str || (*this) == str );
	}
	
	
	string_t& string_t::operator+=( char c ) {
		uint32 sz = size();
		string_realloc( *this, sz + 1 );
		
		data[sz] = c;
		++ string_size( data );
		data[sz+1] = '\0';
		
		return *this;
	}
	string_t& string_t::operator+=( const char* str ) {
		uint32 len = strlen(str);
		uint32 sz = size();
		string_realloc( *this, sz + len );
		
		memcpy( data + sz, str, len );
		string_size( data ) += len;
		
		data[sz+len] = '\0';
		
		return *this;
	}
	string_t& string_t::operator+=( const string_t& str ) {
		uint32 len = str.size();
		uint32 sz = size();
		string_realloc( *this, sz + len );
		
		memcpy( data + sz, string_start(str), len );
		string_size( data ) += len;
		
		data[sz+len] = '\0';
		
		return *this;
	}
	
	string_t string_t::substr( uint32 a, uint32 b ) const {
		InfiPushFunction( "string_t.substr" );
		if ( a > b )
			InfiSendError( INFI_INDEX_ERROR,
						   "Initial index %d is greater than final index %d", a, b );
		
		uint32 sz = size();
		if ( a > b || a > sz || b > sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Indexes out of range (%d, %d)", a, b );
		
		if ( is_substr() ) {
			a += start;
			b += start;
		}
		
		InfiPopFunction();
		return string_t( data, a, b );
	}
	string_t string_t::front( uint32 a ) const {
		InfiPushFunction( "string_t.front" );
		uint32 sz = size();
		if ( a > sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Index %d out of range of %d", a, sz );
		if ( is_substr() )
			a += start;
		InfiPopFunction();
		return string_t( data, 0, a );
	}
	string_t string_t::back( uint32 a ) const {
		InfiPushFunction( "string_t.back" );
		uint32 sz = size();
		if ( a > sz )
			InfiSendError( INFI_INDEX_ERROR,
						   "Index %d out of range of %d", a, sz );
		if ( is_substr() )
			a += start;
		InfiPopFunction();
		return string_t( data, sz - a, sz );
	}

	string_t string_t::fromfront( char c ) const {
		uint32 init = (is_substr()) ? start : 0;
		uint32 termin = init+size();
		for ( uint32 i=init;i<termin;++i ) {
			if ( data[i] == c )
				return string_t( data, init, init+i );
		}
		return string_t( *this );
	}
	string_t string_t::fromback( char c ) const {
		uint32 init = (is_substr()) ? start : 0;
		uint32 termin = init+size();
		for ( uint32 i=termin;i>init;--i ) {
			if ( data[i-1] == c )
				return string_t( data, i, termin );
		}
		return string_t( *this );
	}

	string_t string_t::tofront( char c ) const {
		uint32 init = (is_substr()) ? start : 0;
		uint32 termin = init+size();
		for ( uint32 i=init;i<termin;++i ) {
			if ( data[i] == c )
				return string_t( data, i+1, termin );
		}
		return string_t( *this );
	}
	string_t string_t::toback( char c ) const {
		uint32 init = (is_substr()) ? start : 0;
		uint32 termin = init+size();
		for ( uint32 i=termin;i>init;--i ) {
			if ( data[i-1] == c )
				return string_t( data, init, i+1 );
		}
		return string_t( *this );
	}

	void string_t::split( char c, array_t<string_t>& output ) const {
		uint32 len = this->size();
		uint32 last = 0;
		for ( uint32 i=0;i<len;++i )
			if ( c == data[i] ) {
				output.add( string_t( data, last, i ) );
				last = ++ i;
			}
		if ( last != len )
			output.add( string_t( data, last, len ) );
	}
	void string_t::split( const array_t<char>& cs, array_t<string_t>& output ) const {
		uint32 len = this->size();
		uint32 last = 0;
		for ( uint32 i=0;i<len;++i )
			for ( uint32 j=0;j<cs.size();++j )
				if ( cs[j] == data[i] ) {
					if ( last != i )
						output.add( string_t( data, last, i ) );
					last = i + 1;
					break;
				}
		if ( last != len )
			output.add( string_t( data, last, len ) );
	}

	string_t::operator int32 () const {
		char* buffer = this->duplicate();
		int32 ret = std::atoi( buffer );
		delete[] buffer;
		return ret;
	}
	
	
	static uint32 get_allocation_size_from( char* str, uint32 sz ) {
		return sz + (32 - (sz%32));
	}
	
	static uint32& string_alloc( char* str ) {
		return *(((uint32*)str)-STRING_ATTRIB_ALLOC);
	}
	static uint32& string_size( char* str ) {
		return *(((uint32*)str)-STRING_ATTRIB_SIZE);
	}
	static const uint32& string_ref( char* str ) {
		return *(((uint32*)str)-STRING_ATTRIB_REF);
	}
	static void string_increment( char* str ) {
		++ *(((uint32*)str)-STRING_ATTRIB_REF);
	}
	static void string_decrement( char* str ) {
		if ( -- *(((uint32*)str)-STRING_ATTRIB_REF) == 0 )
			delete[] (str - STRING_OFFSET_CONSTANT);
	}
	
	static char* string_start( const string_t& str ) {
		return (str.is_substr()) ? str.data + str.start : str.data;
	}
	
	static char* string_allocate( char* str, uint32 sz ) {
		uint32 alloc = get_allocation_size_from( str, sz + 1 );
		char* ndata = new char[alloc+STRING_OFFSET_CONSTANT];
		char* temp = ndata + STRING_OFFSET_CONSTANT;
		
		*(((uint32*)temp)-STRING_ATTRIB_DATA) = 1234;
		*(((uint32*)temp)-STRING_ATTRIB_REF) = 0;
		string_alloc( temp ) = alloc;
		
		return temp;
	}
	
	static char* string_initialize( string_t& str, char* src, uint32 a, uint32 b ) {
		string_increment( src );
		str.data = src;
		str.start = a;
		str.end = b;
		return src;
	}
	static char* string_assign( string_t& str, char* src, uint32 a, uint32 b ) {
		string_increment( src );
		string_decrement( str.data );
		str.data = src;
		str.start = a;
		str.end = b;
		return src;
	}
	
	static char* string_copy( char* str, string_t& src, uint32 offset, uint32 len ) {
		memcpy( str + offset, string_start(src), len );
		string_size( str ) = offset + len;
		return str;
	}
	
	static char* string_dup( const char* str, uint32 len ) {
		char* temp = string_allocate(NULL,len);
		memcpy( temp, str, len );
		temp[len] = '\0';
		string_size( temp ) = len;
		return temp;
	}
	
	static void string_realloc( string_t& str, uint32 len ) {
		if ( !str.is_substr() && len < string_alloc( str.data ) )
			return;
		
		uint32 sz = str.size();
		char* temp = string_allocate( str.data, len );
		string_size( temp ) = sz;
		memcpy( temp, string_start( str ), sz );
		
		string_assign( str, temp );
	}
	
} }