#ifndef __INFI_TYPED_ALLOCATOR_HPP__
#define __INFI_TYPED_ALLOCATOR_HPP__

#include <thread>
#include <mutex>
#include <vector>
#include <stack>

#include "base/types.hpp"
#include "base/error_log.hpp"

namespace Infinity {

	template<typename T, uint32 _Size = 1024>
	struct infi_typed_allocator_t {
	private:
		std::mutex _lock;
		std::thread::id _held;

		uint32 _allocd;
		std::stack<uint32> _available;
		std::vector<bool> _in_use;
		uint8 _data[_Size * sizeof(T)];

	public:
		struct pointer {
		private:
			infi_typed_allocator_t& _alloc;
			T& _value;
		public:
			pointer(infi_typed_allocator_t& a) :
				_alloc(a),
				_value(a.alloc()) { ; }
			pointer(infi_typed_allocator_t& a, const T& t) :
				_alloc(a),
				_value(a.alloc(t)) { ; }

			pointer(const pointer& copy) :
				_alloc(copy._alloc),
				_value(_alloc.alloc(copy.value)) { ; }
			~pointer() {
				_alloc.dealloc(_value);
			}

			T& get() { return _value; }
			const T& get() const { return _value; }

			T& operator* () { return this -> value(); }
		};

		infi_typed_allocator_t() :
			_allocd(0), _in_use(_Size, false) { ; }
		~infi_typed_allocator_t() {
			for ( uint32 i=0;i<_in_use.size();i++ ) {
				if ( _in_use[i] ) {
					((T*)_data)[i].~T();
				}
			}
		}

		T& alloc(const T& t) {
			std::thread::id id = std::this_thread::get_id();
			std::unique_lock<std::mutex> lk(_lock, std::defer_lock);

			if ( _held != id ) {
				lk.lock();
				_held = id;
			}

			if ( _available.empty() ) {
				if ( _allocd >= _Size ) {
					Error::send<Error::Fatality::Fatal>(
						Error::Type::Overflow,
						"Overflowed typed allocator!"
					);
				}
				new (_data + _allocd * sizeof(T)) T(t);
				_in_use[_allocd] = true;
				return ((T*)_data)[_allocd ++];
			} else {
				uint32 i = _available.top();
				_available.pop();
				new (_data + i * sizeof(T)) T(t);
				_in_use[i] = true;
				return ((T*)_data)[i];
			}
		}
		T& alloc() {
			return alloc(T());
		}
		void dealloc(uint32 i) {
			std::thread::id id = std::this_thread::get_id();
			std::unique_lock<std::mutex> lk(_lock, std::defer_lock);

			if ( _held != id ) {
				lk.lock();
				_held = id;
			}

			if ( !_in_use[i] ) {
				Error::send<Error::Fatality::Fatal>(
					Error::Type::Value,
					"Cannot deallocate item from typed allocator. Object is not currently in use!"
				);
			}
			((T*)_data)[i].~T();
			_available.push(i);
			_in_use[i] = false;
		}
		void dealloc(T* id) {
			if ( (uint8*)id < _data || (uint8*)id >= _data + _Size * sizeof(T) ) {
				Error::send<Error::Fatality::Fatal>(
					Error::Type::Value,
					"Cannot deallocate item from typed allocator. Pointer mismatch!"
				);
			}
			dealloc((uint32)(id - (T*)_data));
		}
		void dealloc(T& id) {
			dealloc(&id);
		}
	};

	template<typename T, uint32 _Size>
	using infi_alloc_ptr_t = typename infi_typed_allocator_t<T, _Size>::pointer;

}

#endif//__INFI_TYPED_ALLOCATOR_HPP__