#ifndef __INFI_EXTENSION_HPP__
#define __INFI_EXTENSION_HPP__

#include <set>
#include <unordered_map>

#include "base/types.hpp"
#include "base/error_log.hpp"

#include "engine/infi_engine_defs.hpp"
#include "engine/updatemngr/infi_update_mngr_module.hpp"
#include "components/infi_component_defs.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {

	struct infi_extension_t {

		// virtual functions
		virtual float64 Update( infi_controller_t&, float64 ) = 0;
		
		infi_extension_t() :
			_name( "New Extension" ),
			_lastrun(0.0),
			_nextrun(0.0),
			_good(0) { ; }
		
		infi_extension_t( const char* n ) :
			_name( n ),
			_lastrun(0.0),
			_nextrun(0.0),
			_good(0) { ; }
			
		virtual ~infi_extension_t();

		const char* getName() const;
		uint32 dependencyCount() const;
		uint32 signalCount() const;
		
		void initialDelay(float64);
		void loops();
		void needs(infi_extension_t*);
		void needs(infi_extension_t&);
		void needs(infi_extension_t*, uint32);
		void needs(infi_extension_t&, uint32);

		void run(infi_controller_t&);
		
	private:
		void __signal(infi_extension_t*, infi_controller_t&);

		struct __counter_item__ {
			infi_extension_t* _next;
			uint32 _need;
			uint32 _have;
		};

		const char* _name;
		float64 _lastrun;
		float64 _nextrun;

		std::set<infi_extension_t*> _dependencies;

		uint32 _good;
		std::vector<__counter_item__> _signals;
		std::unordered_map<infi_extension_t*, uint32> _signal_access;
		
	};

}

#endif//__INFI_EXTENSION_HPP__
