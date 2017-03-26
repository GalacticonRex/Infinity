#ifndef __INFI_BUFFER_OBJECT_HPP__
#define __INFI_BUFFER_OBJECT_HPP__

#include "render/gl/infi_gl_defs.hpp"
#include "render/infi_render_defs.hpp"
#include "render/gl/infi_gl_command.hpp"

namespace Infinity {
namespace Render {

	struct infi_buffer_object_t {
	private:
		struct __upload_item__ {
			infi_buffer_object_t* buffer;
			uint32 bind_point;
			uint32 start;
			uint32 size;
			uint8* data;
		};
		struct __upload_data__ : public infi_gl_typed_function_t<__upload_item__> {
		private:
			void __realloc_buffer(const infi_gl_t&,
								  infi_gl_context_controller_t&,
								  infi_buffer_object_t*,
								  uint32,
								  uint32,
								  uint32);
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __upload_item__&) const;
		} _upload;

		void __upload(infi_renderer_t&, uint32, uint32, uint8*);

		uint32 _handle;

		bool _generated;
		uint32 _usage;
		uint32 _size;
		uint8* _mapping;

	public:

		enum class Modification {
			Stream,
			Static,
			Dynamic
		};
		enum class Usage {
			Draw,
			Read,
			Copy
		};

		struct DEFINE_EXPORT Bind {
		private:
			infi_buffer_object_t& _buffer;
			infi_renderer_t& _renderer;
			BufferBindPoint _bind;
		public:
			Bind(infi_renderer_t&, infi_buffer_object_t&, BufferBindPoint);
			~Bind();

			template<typename _T, uint32 _N>
			void upload(_T* data) {
				_buffer.__upload(_renderer, 0, sizeof(_T)*_N, (uint8*)data);
			}
			template<typename _T, uint32 _N>
			void upload(uint32 offset, _T* data) {
				_buffer.__upload(_renderer, offset, sizeof(_T)*_N, (uint8*)data);
			}
			void download(uint8*&);

			uint8& operator[](uint32);
		};

		infi_buffer_object_t();
		infi_buffer_object_t(infi_renderer_t&, BufferBindPoint);

		void create(infi_synchronized_renderer_t&, BufferBindPoint);

		void usage(Modification, Usage);
		
		uint32 handle() const;
		uint32 byteSize() const;
	};

} }

#endif//__INFI_BUFFER_OBJECT_HPP__