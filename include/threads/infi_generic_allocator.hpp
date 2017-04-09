#ifndef __INFI_GENERIC_ALLOCATOR_HPP__
#define __INFI_GENERIC_ALLOCATOR_HPP__

#include "base/types.hpp"
#include "base/error_log.hpp"

namespace Infinity {

	template<uint32 _Size = 1024, uint32 _Block=64>
	struct infi_generic_allocator_t {
	private:
		uint32 _in_use[_Size/_Block];
		uint32 _end_point[_Size/_Block];
		uint8  _data[_Size];

	public:
		infi_generic_allocator_t() {
			for ( uint32 i=0;i<_Size/_Block;i++ ) {
				_in_use[i] = 0;
				_end_point[i] = 0;
			}
		}

		template<typename _T>
		_T& alloc() {
			static_assert(sizeof(_T) <= _Block, "Cannot allocate object that is larger than allocator block size!");

			return alloc(_T());
		}
		template<typename _T>
		_T& alloc(const _T& copy) {
			static_assert(sizeof(_T) <= _Block, "Cannot allocate object that is larger than allocator block size!");

			uint32 index = 0;
			for (;_Block - _end_point[index] < sizeof(_T);++index)
				if (index >= _Size/_Block)
					Error::send<Error::Fatality::Thread>(
						Error::Type::Overflow,
						"Generic allocator overflowed!"
					);

			_T* new_object = (_T*)&_data[index*_Block+_end_point[index]];
			new (new_object) _T(copy);
			_end_point[index] += sizeof(_T);
			++ _in_use[index];

			return *new_object;
		}
		template<typename _T>
		void dealloc(_T* obj) {
			if ( obj == nullptr )
				return;
			
			if ( (uint8*)obj < _data || (uint8*)obj >= _data + _Size )
				Error::send<Error::Fatality::Thread>(
					Error::Type::Value,
					"Element not a member of this allocator!"
				);

			uint32 index = ((uint8*)obj - _data) / _Block;
			-- _in_use[index];
			if ( _in_use[index] == 0 ) {
				_end_point[index] = 0;
			}

			obj -> ~_T();
		}

	};

}

#endif//__INFI_TYPED_ALLOCATOR_HPP__