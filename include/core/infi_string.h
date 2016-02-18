#ifndef __INFI_STRING_2_H__
#define __INFI_STRING_2_H__

#include <iostream>
#include "main/infi_export.h"
#include "main/infi_types.h"
#include "core/infi_array.h"

namespace INFI {
namespace core {

struct INFI_EXPORT string_t {
	
	string_t();
	string_t( const char* );
	string_t( const char*, const char* );
	string_t( char*, uint32, uint32 );
	string_t( const string_t& );
	
	explicit string_t( char );
	explicit string_t( char, uint32 );
	
	string_t& operator= ( const char* );
	string_t& operator= ( const string_t& );
	
	~string_t();
	
	void clear();
	
	char operator[] ( uint32 ) const;
	const char* from( uint32 ) const;
	string_t localize() const;
	char* duplicate() const;
	
	const char* source();
	
	uint32 last() const;
	uint32 size() const;
	
	uint32 allocated() const;
	uint32 associated() const;
	bool is_substr() const;
	
	bool operator< ( const string_t& ) const;
	bool operator> ( const string_t& ) const;
	bool operator<= ( const string_t& ) const;
	bool operator>= ( const string_t& ) const;
	bool operator== ( const string_t& ) const;
	
	bool operator> ( const char* ) const;
	bool operator< ( const char* ) const;
	bool operator<= ( const char* ) const;
	bool operator>= ( const char* ) const;
	bool operator== ( const char* ) const;
	
	bool operator> ( char ) const;
	bool operator< ( char ) const;
	bool operator>= ( char ) const;
	bool operator<= ( char ) const;
	bool operator== ( char ) const;
	
	string_t& operator+=( char );
	string_t& operator+=( const char* );
	string_t& operator+=( const string_t& );
	
	string_t substr( uint32, uint32 ) const;
	string_t front( uint32 ) const;
	string_t back( uint32 ) const;
	
	string_t fromfront( char ) const;
	string_t fromback( char ) const;
	
	string_t tofront( char ) const;
	string_t toback( char ) const;
	
	void split( char, array_t<string_t>& ) const;
	void split( const array_t<char>&, array_t<string_t>& ) const;
	//void split( const string_t&, array_t<string_t>& );
	
	explicit operator int32 () const;
	
	uint32 start, end;
	char* data;
};

INFI_FUNCTION( std::ostream&, operator<<, ( std::ostream&, const string_t& ) );

} }

#endif//__INFI_STRING_H__