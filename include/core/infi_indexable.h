#ifndef __INFI_INDEXABLE_H__
#define __INFI_INDEXABLE_H__

#include <iostream>
#include <initializer_list>
#include "main/infi_types.h"
#include "main/infi_error.h"

namespace INFI {
namespace core {
	
	template<typename T>
	struct indexable_t {
		
		virtual T* source() = 0;
		virtual const T* source() const = 0;
		
		virtual uint32 size() const = 0;
		
		virtual T& operator[] ( uint32 ) = 0;
		virtual const T& operator[] ( uint32 ) const = 0;
		
	};
	
	template<typename T>
	struct mu_indexable_t : indexable_t<T> {
		
		virtual void resize( uint32 ) = 0;
		virtual void concat( const indexable_t<T>& ) = 0;
		
	};
	
	template<typename T>
	std::ostream& operator<< ( std::ostream& ostr, const indexable_t<T>& block ) {
		ostr << "{ ";
		for ( uint32 i=0;i<block.size();++i ) {
			ostr << block[i] << " ";
		}
		ostr << "}";
		return ostr;
	}
	
} }

#endif//__INFI_INDEXABLE_H__