#ifndef __INFI_MEMBLOCK_H__
#define __INFI_MEMBLOCK_H__

namespace INFI {
namespace core {
	
	template<typename T,uint32 BUFFER>
	struct memblock_t {
	private:
		
		static uint32 DATA_ALLOC = 1;
		static uint32 DATA_REFER = 2;
		static uint32 DATA_USER  = 3;
		
		T* data;
		
		static T* create_data( uint32 sz ) {
			uint32* ndata = (uint32*) operator new[]( sz * sizeof(T) + DATA_REFER + BUFFER );
			T* ret = (T*)( ndata + DATA_REFER + BUFFER );
			new (ret) T[sz];
			return ret;
		}
		static void destroy_data( T* d ) {
			
		}
		
		// fork this object for modification
		void modify_clear() {
			if ( refcount() == 1 )
				return;
			
			
		}
		void modify_retain() {
			if ( refcount() == 1 )
				return;
			
			
		}
		
		void increment() {
			++ ( *(((uint32*)data)-DATA_REFER) );
		}
		void decrement() {
			if ( -- ( *(((uint32*)data)-DATA_REFER) ) )
				destroy_data( data );
		}
		
	public:
		memblock_t() : data( create_data( 0 ) ) { ; }
		memblock_t( const memblock_t& copy ) :
			data( copy.data ) { increment(); }
		~memblock_t() { decrement(); }
		
		// how big is the allocation space?
		uint32 alloc() const {
			return *(((uint32*)data)-DATA_ALLOC);
		}
		
		// how many objects refer to this data?
		uint32 refcount() const {
			return *(((uint32*)data)-DATA_REFER);
		}
		
		const uint32& userdata( uint32 offset ) const {
			return *(((uint32*)data)-(DATA_USER+offset))
		}
		uint32& userdata( uint32 offset ) {
			return *(((uint32*)data)-(DATA_USER+offset))
		}
		
		// resize the data
		// may call modify()
		void require( uint32 );
	};
	
} }

#endif//__INFI_MEMBLOCK_H__