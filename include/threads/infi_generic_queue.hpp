#ifndef __INFI_GENERIC_QUEUE_HPP__
#define __INFI_GENERIC_QUEUE_HPP__

#include <mutex>

#include "base/structure.hpp"
#include "base/types.hpp"
#include "base/error_log.hpp"

namespace Infinity {

	template<uint32 _BlockSize, uint32 _BlockCount>
	struct infi_generic_queue_t : does_not_copy {
	private:

		struct __element__ : does_not_copy {
		private:
			std::mutex _lock;

			uint32 _front;
			uint32 _allocated;
			uint32 _termin;

			uint8 _data[_BlockSize];

			__element__* _next;

		public:
			__element__() : _front(0),
							_allocated(0),
							_termin(_BlockSize),
							_next(NULL) {
				////__WriteError__("front&:     " << &_front);
				////__WriteError__("allocated&: " << &_allocated);
				////__WriteError__("termin&:    " << &_termin);
			}

			void reset() {
				_front = 0;
				_allocated = 0;
				_termin = _BlockSize;
			}

			// returns the address of the element that
			// the object was pushed to
			template<typename T>
			__element__* insert(const T& item, __element__* usenext) {
				////__WriteError__("pre-front     " << _front);
				////__WriteError__("pre-allocated " << _allocated);
				////__WriteError__("pre-termin    " << _termin);

				bool space_exists = (_allocated + sizeof(T) <= _BlockSize);
				bool space_at_front = (_front >= sizeof(T));
				bool space_at_end = (_BlockSize - (_front+_allocated) >= sizeof(T));

				////__WriteError__("space exists: " << space_exists);
				////__WriteError__("space at front: " << space_at_front);
				////__WriteError__("space at end: " << space_at_end);

				// there is not enough space to allocate the new item
				if ( !space_exists || (!space_at_end && !space_at_front) ) {
					//__WriteError__("could not find space!");
					if ( usenext == NULL ) {
						//Error::define_scope __scope__("infi_generic_queue_t.push");
						Error::send<Error::Fatality::Method>(
							Error::Type::Overflow,
							"Cannot allocate any more objects to this generic queue"
						);
					}
					////__WriteError__("====================================");
					usenext -> insert(item, NULL);
					return usenext;
				}
				// there is enough space for allocation!
				else {
					////__WriteError__("space was found!");
					if ( space_at_front && !space_at_end ) {
						//__WriteError__("loop back to the beginning");
						std::lock_guard<std::mutex> lk(_lock);
						_termin = _front + _allocated;
					}
					void* location = (void*)(std::size_t)(_data + ((_front + _allocated) % _termin));
					////__WriteError__("allocating now at " << location << "...");
					new ( location ) T(item);

					std::lock_guard<std::mutex> lk(_lock);
					_allocated += sizeof(T);
					////__WriteError__("allocation was a success!");

					////__WriteError__("pst-front     " << _front);
					////__WriteError__("pst-allocated " << _allocated);
					////__WriteError__("pst-termin    " << _termin);

					return this;
				}
			}

			// view the object at the front of the element
			template<typename T>
			T& view() {
				////__WriteError__("me: " << this);
				void* location = (_data+_front);
				////__WriteError__("viewing at " << location);
				return *((T*)location);
			}

			// remove the front element. returns true if
			// the element still has objects, false if
			// the element is empty after popping
			template<typename T>
			bool remove() {
				////__WriteError__("pre-front     " << _front);
				////__WriteError__("pre-allocated " << _allocated);
				////__WriteError__("pre-termin    " << _termin);

				void* location = (void*)(_data+_front);
				
				////__WriteError__("deallocating now at " << location);
				((T*)location) -> ~T();
				
				{
					std::lock_guard<std::mutex> lk(_lock);
					_front += sizeof(T);
					if ( _front >= _termin ) {
						_front -= _termin;
						_termin = _BlockSize;
					}
					_allocated -= sizeof(T);
				}

				////__WriteError__("pst-front     " << _front);
				////__WriteError__("pst-allocated " << _allocated);
				////__WriteError__("pst-termin    " << _termin);

				return ( _allocated == 0 );
			}
		};

		template<typename T>
		void __push(const T& data) {
			////__WriteError__("front: " << _front);
			uint32 back1, back2;
			{
				std::lock_guard<std::mutex> lk(_lock);
				back1 = (_front + _in_use) % _BlockCount;
				back2 = (_front + _in_use + 1) % _BlockCount;
				////__WriteError__("indices to use: " << back1 << ", " << back2);
			}

			// not enough room in current back
			if ( _base[back1].insert(data, &_base[back2] ) != &_base[back1] ) {
				std::lock_guard<std::mutex> lk(_lock);
				if ( _in_use + 1 > _BlockCount ) {
					//Error::define_scope __scope__("infi_generic_queue_t.push");
					Error::send<Error::Fatality::Fatal>(
						Error::Type::Overflow,
						"No more space in generic_queue, object cannot be allocated!"
					);
				}
				_in_use ++ ;
			}
		}

		template<typename T>
		T& __view() {
			////__WriteError__("view! " << _front);
			return _base[_front].template view<T>();
		}

		template<typename T>
		void __pop() {
			////__WriteError__("front: " << _front);
			if ( _base[_front].template remove<T>() && _in_use > 1 ) {
				std::lock_guard<std::mutex> lk(_lock);
				_front = ( _front + 1 ) % _BlockCount;
				_in_use -- ;
			}
		}

		std::mutex _lock;

		uint32 _front;
		uint32 _in_use;

		__element__ _base[_BlockCount];

	public:

		infi_generic_queue_t() :
			_front(0),
			_in_use(0) { ; }

		template<typename T>
		struct push {
			push(infi_generic_queue_t& q, const T& data) {
				q.template __push<T>(data);
			}
		};

		template<typename T>
		struct pop {
			pop(infi_generic_queue_t& q) {
				q.template __pop<T>();
			}
		};

		template<typename T>
		struct get {
		private:
			T& _data;
		public:
			get(infi_generic_queue_t& q) :
				_data(q.template __view<T>()) { ; }
			operator T&() { return _data; }
		};
	};

	typedef infi_generic_queue_t<65536, 8> infi_default_queue_t;

}

#endif//__INFI_GENERIC_QUEUE_HPP__