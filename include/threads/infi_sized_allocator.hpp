#ifndef __INFI_SIZED_ALLOCATOR_HPP__
#define __INFI_SIZED_ALLOCATOR_HPP__

#include "base/types.hpp"
#include "base/error_log.hpp"

namespace Infinity {

	template<uint32 _Size, uint32 _Count = 1024>
	struct infi_sized_allocator_t {
	private:
		uint32 _flags[((_Size*_Count)>>8)+1];
		uint8  _data[_Size*_Count];
	public:
		
	};

}

#endif//__INFI_TYPED_ALLOCATOR_HPP__