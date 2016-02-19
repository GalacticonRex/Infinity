#ifndef __INFI_BITFIELD_H__
#define __INFI_BITFIELD_H__

#include "core/infi_datablock.h"
#include "core/infi_array.h"
#include "core/infi_methods.h"

namespace INFI {
namespace core {

struct bitfield_t {

	private:
		void __realloc( uint32 x ) {
			x =  x / 8 + ( x % 8 != 0 );
			if ( x > _alloc ) {
				while ( _alloc < x )
					_alloc = (_alloc==0) ? 1 : _alloc << 1;
				uint8* tmp = new uint8[_alloc];
				memset( tmp, 0, _alloc );
				for ( uint32 i=0;i<_sz/8+(_sz%8!=0);i++ )
					tmp[i] = _data[i];
				delete[] _data;
				_data = tmp;
			}
		}
		
		uint32 	_sz, // number of sections of bitsize (in bits) in use
				_alloc; // size of _data[] in chars
		uint8*	_data; // allocated space
	
	public:
	
		bitfield_t() : _sz( 0 ), _alloc( 0 ), _data( NULL ) { }
		bitfield_t( uint32 sz )
			: _sz( sz ), _alloc( MakePow2( sz / 8 + ( sz % 8 != 0 ) ) ),
			  _data( new uint8[_alloc] ) { }
		bitfield_t( const bitfield_t& copy )
			: _sz( copy._sz ), _alloc( copy._alloc ),
			  _data( new uint8[_alloc] ) {
			for ( uint32 i=0;i<_alloc;i++ )
				_data[i] = copy._data[i];
		}	
		
		
		template<typename Type>
		explicit bitfield_t( const array_t<Type>& copy )
			: _sz( copy.size() * sizeof(Type) * 8 ), _alloc( MakePow2( _sz + 1 ) ),
			  _data( new uint8[_alloc] ) {
			for ( uint32 i=0;i<copy.size()*sizeof(Type);i++ )
				_data[i] = copy.template get<uint8>( i );
		}
		template<typename Type>
		explicit bitfield_t( const data_t<Type>& copy )
			: _sz( copy.size() * sizeof(Type) * 8 ), _alloc( MakePow2( _sz + 1 ) ),
			  _data( new uint8[_alloc] ) {
			for ( uint32 i=0;i<copy.size()*sizeof(Type);i++ )
				_data[i] = copy.template get<uint8>( i );
		}
		
		~bitfield_t() {
			delete[] _data;
		}
		
		bitfield_t& operator= ( const bitfield_t& copy ) {
			resize( copy._sz );
			for ( uint32 i=0;i<_alloc;i++ )
				_data[i] = copy._data[i];
			return *this;
		}
		
		bool get( uint32 x ) { 
			if ( x >= _sz )
				return false;
			else
				return ( _data[x/8] & ( 0x1 << ( x % 8 ) ) );
		}
		bool get( uint32 x ) const { 
			if ( x >= _sz )
				return false;
			else
				return ( _data[x/8] & ( 0x1 << ( x % 8 ) ) );
		}
		bool operator[] ( uint32 x ) { return get( x ); }
		bool operator[] ( uint32 x ) const { return get( x ); }
		
		void set( uint32 x ) {
			if ( x >= _sz ) {
				__realloc( x + 1 );
				_sz = x + 1;
			} _data[x/8] |= ( 1 << ( x % 8 ) );
		}
		void unset( uint32 x ) {
			if ( x >= _sz )
				return;
			_data[x/8] &= ~( 1 << ( x % 8 ) );
		}
		
		void flood( uint32 first, uint32 second=0 ) {
			if ( first < second ) {
				
			} else {
				//first % 8
			}
		}
		
		void append( bool val ) {
			__realloc( _sz + 1 );
			( val ) ? set( _sz ) : unset( _sz );
			_sz ++ ;
		}
		void resize( uint32 sz ) {
			__realloc( sz );
			_sz = sz;
		}
		void clear() { memset( _data, 0, _alloc ); }
		uint32 size() const { return _sz; }
		bool none_set() const {
			uint32 byteuse = _sz / 8 + ( _sz % 8 != 0 );
			for ( uint32 i=0;i<byteuse;i++ )
				if ( _data[i] != 0 )
					return false;
			return true;
		}
		
		bitfield_t operator+ ( const bitfield_t& other ) {
			bool this_is_bigger;
			uint32 largeish = (this_is_bigger=(this->_alloc>other._alloc))
							? this->_alloc : other._alloc;
			uint32 smallish = std::min( this->_alloc, other._alloc );
			bitfield_t ret(largeish*8);
			
			uint32 i;
			for ( i=0;i<smallish;++i )
				ret._data[i] = this->_data[i] | other._data[i];
			for ( ;i<largeish;++i )
				ret._data[i] = (this_is_bigger) ? this->_data[i] :
												  other._data[i];
			return ret;
		}
		bitfield_t operator- ( const bitfield_t& other ) {
			bool this_is_bigger;
			uint32 largeish = (this_is_bigger=(this->_alloc>other._alloc))
							? this->_alloc : other._alloc;
			uint32 smallish = std::min( this->_alloc, other._alloc );
			bitfield_t ret(largeish*8);
			
			uint32 i;
			for ( i=0;i<smallish;++i )
				ret._data[i] = this->_data[i] ^ other._data[i];
			for ( ;i<largeish;++i )
				ret._data[i] = (this_is_bigger) ? this->_data[i] :
												  other._data[i];
			return ret;
		}
};

inline std::ostream& operator << ( std::ostream& ostr, const bitfield_t& bits ) {
	ostr << "{ ";
	if ( bits.size() > 0 ) {
		uint32 i = 0;
		for ( ;i<bits.size()-1;i++ ) {
			if ( bits[i] )  ostr << "1.";
			else			ostr << "0.";
		} 
		if ( bits[i] )  ostr << "1";
		else			ostr << "0";
	} else
		ostr << "empty";
	ostr << " }";
	return ostr;
}

} }

#endif