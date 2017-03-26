#ifndef __INFI_RENDERABLE_H__
#define __INFI_RENDERABLE_H__

#include <vector>
#include <string>

#include "base/types.hpp"
#include "base/structure.hpp"
#include "components/infi_component_defs.hpp"
#include "render/infi_render_defs.hpp"

namespace Infinity {

	struct infi_renderable_t {
	public:
		infi_renderable_t( const std::string& );
		virtual ~infi_renderable_t();

		// virtual functions
		virtual void OnBind( Render::infi_renderer_t& ) { ; }
		virtual void Render( Render::infi_renderer_t&, float64 dt ) = 0;

		const std::string& getName() const;

		infi_window_t& parent();
		const infi_window_t& parent() const;
		void parent( infi_window_t& );

		uint32 depth() const;
		void depth( uint32 );

		bool isActive() const;
		bool isVisible() const;

		void active( bool = true );
		void visible( bool = true );

		struct compare {
			bool operator() (infi_renderable_t* const& a, infi_renderable_t* const& b) {
				return (a -> _zpos < b -> _zpos);
			}
		};

	private:
		std::string _name;
		infi_window_t* _parent;

		uint32 _zpos;
		uint32 _flags;

		friend struct infi_window_t;
	};

}

#endif//__INFI_RENDERABLE_H__
