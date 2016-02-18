#ifndef __INFI_MULTI_CONTEXT_H__
#define __INFI_MULTI_CONTEXT_H__

#include "core/infi_map.h"
#include "core/infi_queue.h"

namespace INFI {
namespace render {
	
	template<typename ContextType,			// how is a unique context represented
			 typename HandleType,			// what is bound to the context
			 typename ObjectType,			// how is a single object represented
			 ContextType (*CurrentContext)(),// what is the current handle?
			 void (*DestroyHandle)( ContextType, HandleType ) = NULL>
	struct infi_multi_context_t {
		
		// object bound to a unique context
		struct local_handle {
			HandleType 	handle;	 // what object is associated with this context?
			uint32		index;
		};
		core::map_t<uint32,ObjectType> 	objects;
			
		private:
			
			// object wrapper (with update index)
			struct local_object {
				uint32 object_index;
				uint32 update_index;
			};
			
			core::map_t<ContextType,
						local_handle>		contexts;
			uint32							current;
			uint32 							objcount;
			core::queue_t<local_object>		changelog;
		
		protected:
			
			local_handle& get_handle() {
				InfiPushFunction( "ContextHandle.get" );
				ContextType cur = CurrentContext();
				
				typename core::map_t<ContextType,local_handle>::iterator
					iter = contexts.find( cur );
					
				// create a new handle
				if ( iter == contexts.end() ) {
					// generate the new handle
					local_handle temp;
					temp.handle = CreateNewHandle( cur );
					temp.index = current;
					
					// update that handle to the current values
					typename core::map_t<uint32,ObjectType>::iterator
						iter = objects.begin();	
					for ( ;iter!=objects.end();++iter ) {
						SyncObject( temp, iter->first, iter->second );
					}
					
					InfiPopFunction();
					return 	contexts.insert(
								std::pair<ContextType,local_handle>( cur, temp ) 
							).first->second;
				}
				
				// sync handle
				else {
					
					local_handle& temp = iter->second;
					
					if ( current <= temp.index ) {
						for ( uint32 i=0;i<changelog.size();++i ) {
							local_object& id = changelog[i];
							if ( id.update_index <= temp.index )
								continue;
							
							uint32 obj = id.object_index;
							SyncObject( temp, obj, objects[obj] );
						}
						temp.index = current;
					}
					InfiPopFunction();
					return temp;
				}
			}
			
			virtual HandleType CreateNewHandle( ContextType ) = 0;
			virtual void SyncObject( const local_handle&, uint32, const ObjectType& ) = 0;
			
		public:
		
			infi_multi_context_t() :
				current( 0 ),
				objcount( 0 ) { ; }
				
			infi_multi_context_t( const infi_multi_context_t& copy ) :
				objects( copy.objects ),
				contexts(),
				current( 0 ),
				objcount( copy.objcount ),
				changelog() { ; }
				
			virtual ~infi_multi_context_t() {
				typename core::map_t<ContextType,local_handle>::iterator
					iter = contexts.begin();
				for( ;iter!=contexts.end();++iter ) {
					std::cerr << "DESTROYING HANDLE " << iter->second.handle << std::endl;
					DestroyHandle( iter->first, iter->second.handle );
				}
			}
			
			HandleType handle() {
				return this->get_handle().handle;
			}
			
			bool exists( uint32 index ) {
				return ( objects.find( index ) != objects.end() );
			}
			void add( uint32 index, const ObjectType& obj ) {
				++ current;
				typename core::map_t<uint32,ObjectType>::iterator
					iter = objects.find( index );
				if ( iter != objects.end() ) {
					for ( uint32 i=0;i<changelog.size();++i ) {
						local_object temp;
						changelog.pop( temp );
						if ( temp.object_index != index )
							changelog.push( temp );
					}
				}
				objects[index] = obj;
				local_object li = { index, current };
				changelog.push( li );
			}
			ObjectType& get( uint32 index ) {
				InfiPushFunction( "MultiContext.get" );
				if ( !this->exists(index) )
					InfiSendError( INFI_INDEX_ERROR,
								   "no object bound at %d", index );
				return objects.find( index )->second;
				InfiPopFunction();
			}
	};
	
} }

#endif//__INFI_MULTI_CONTEXT_H__