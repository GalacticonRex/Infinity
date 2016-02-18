#ifndef __INFI_RAW_BUFFER_H__
#define __INFI_RAW_BUFFER_H__

#include "core/infi_indexable.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct raw_data_t : indexable_t<T> {
		T* 		rawdata;
		uint32 	count;
		
		raw_data_t() :
			rawdata( NULL ),
			count( 0 ) { }
		raw_data_t( uint32 c, T* raw ) :
			rawdata( raw ),
			count( c ) { }
		
		T* source() {
			return rawdata;
		}
		const T* source() const {
			return rawdata;
		}
		
		uint32 size() const {
			return count;
		}
		
		T& operator[] ( uint32 i ) {
			if ( i >= count )
				InfiSendError( INFI_INDEX_ERROR, 
							   "cannot index location %d out of %d", i, count );
			return rawdata[i];
		}
		const T& operator[] ( uint32 i ) const {
			if ( i >= count )
				InfiSendError( INFI_INDEX_ERROR, 
							   "cannot index location %d out of %d", i, count );
			return rawdata[i];
		}
	};
	
} }

#endif//__INFI_RAW_BUFFER_H__