#ifndef __INFI_RESERVED_ARRAY_H__
#define __INFI_RESERVED_ARRAY_H__

#include "core/infi_stack.h"
#include "core/infi_bitfield.h"
#include "main/infi_error.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct reserved_array_t {
		array_t<T> data;
		stack_t<uint32> available;
		bitfield_t reserved; // if set, index is currently in use
		
		reserved_array_t() { ; }
		reserved_array_t( uint32 isize ) {
			data.resize( isize + 1 );
		}
		
		uint32 size() const {
			return data.size();
		}
		bool exists( uint32 x ) const {
			return reserved.get(x);
		}
		T& operator[] ( uint32 x ) {
			if ( x >= data.size() ) {
				data.resize( x + 1 );
				data[x] = T();
			} else if ( !reserved[x] ) {
				data[x] = T();
				reserved.set(x);
			}
			return data[x];
		}
		const T& operator[] (uint32 x) const {
			InfiPushFunction( "reserved_array_t.[]" );
			if ( x >= data.size() || !reserved[x] )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot index location %d", x );
			InfiPopFunction();
			return data[x];
		}
		
		uint32 add( const T& x ) {
			uint32 ret = (uint32)-1;
			if ( available.size() == 0 ) {
				ret = data.size();
				data.add( x );
			} else {
				do {
					uint32 top = available[0];
					available.pop();
					if ( !reserved[top] ) {
						ret = top;
						data[top] = x;
						break;
					}
				} while ( available.size() > 0 );
				if ( available.size() == 0 ) {
					ret = data.size();
					data.add( x );
				}
			}
			reserved.set( ret );
			return ret;
		}
		T remove( uint32 x ) {
			InfiPushFunction( "reserved_array_t.remove" );
			if ( x >= data.size() )
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot index location %d", x );
			if ( reserved[x] ) {
				reserved.unset( x );
				available.push( x );
				return data[x];
			} else
				InfiSendError( INFI_INDEX_ERROR,
							   "Cannot index location %d", x );
			InfiPopFunction();
			return T();
		}
		void clear() {
			data.resize(0);
			reserved.clear();
			available.clear();
		}
	};
	
	template<typename T>
	std::ostream& operator<< ( std::ostream& ostr, const reserved_array_t<T>& arr ) {
		ostr << "{ ";
		for ( uint32 i=0;i<arr.data.size();i++ ) {
			if ( arr.exists( i ) ) {
				ostr << arr.data[i];
			} else {
				ostr << '.';
			}
			if ( arr.reserved[i] ) {
				ostr << '_';
			} else {
				ostr << ' ';
			}
		}
		ostr << "}";
		return ostr;
	}
	
} };

#endif//__INFI_RESERVED_ARRAY_H__