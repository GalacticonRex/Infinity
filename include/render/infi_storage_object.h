#ifndef __INFI_STORAGE_OBJECT_T__
#define __INFI_STORAGE_OBJECT_T__

#include "main/infi_types.h"
#include "core/infi_datablock.h"

namespace INFI {
namespace render {
	
	struct infi_storage_t {
		infi_storage_t();
		infi_storage_t(const infi_storage_t&);
		virtual ~infi_storage_t() { ; }
		
		uint32 getHandle() const;
		
		virtual void setData( const core::indexable_t<uint8>& ) = 0;
		virtual void setData( uint32, const core::indexable_t<uint8>& ) = 0;
		virtual void getData( core::data_t<uint8>& ) = 0;
		
		protected:
			uint32 handle;
			
			uint32* references() const { return refcount; }
			void increment() const;
			void decrement(); // call this in derived destructor
			void assign( infi_storage_t& ) const;
			bool fork_data();
			
			virtual uint32 store_create_data() = 0;
			virtual uint32 store_copy_data() = 0;
			virtual void store_destroy_data() = 0;
			
		private:
			uint32* refcount;
	};
	
} }

#endif//__INFI_STORAGE_OBJECT_T__