#ifndef __INFI_TEXTURE_HPP__
#define __INFI_TEXTURE_HPP__

#include "core/vector.hpp"
#include "render/gl/infi_gl_defs.hpp"
#include "render/infi_render_defs.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/infi_renderer.hpp"
#include "render/infi_sync_renderer.hpp"
#include "threads/infi_typed_allocator.hpp"
#include "threads/infi_threadable.hpp"
#include "components/infi_async.hpp"
#include "io/infi_base_loader.hpp"
#include "jpeg/jpeglib.h"
#include "png/png.h"

namespace Infinity {
namespace Render {

	struct infi_texture_t {
	static const uint32& padding;

	struct texture_format {
		uint32 size_type;
		uint32 base_type;
	};

	static texture_format RGB(uint32);
	static texture_format RGB(uint32,uint32,uint32);
	static texture_format RGBA(uint32);
	static texture_format RGBA(uint32,uint32,uint32,uint32);
	static texture_format Depth();
	static texture_format DepthStencil();

	template<typename T> struct Format { static uint32 Type(); };

	private:
		static uint32 _padding;

		struct __upload_item__ {
			uint32 internal_format;
			uint32 format;
			uint32 type;
			core::vec2i dimensions;
			uint8* data;
		};
		struct __upload_subitem__ {
			uint32 format;
			uint32 type;
			core::vec2i offset;
			core::vec2i dimensions;
			uint8* data;
		};

		struct __upload_data__ : public infi_gl_typed_function_t<__upload_item__> {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __upload_item__&) const;
		};
		struct __upload_subdata__ : public infi_gl_typed_function_t<__upload_subitem__> {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __upload_subitem__&) const;
		};

		void __upload_data(infi_renderer_t&, uint32, void*);
		void __upload_subdata(infi_renderer_t&, const core::vec2i&, const core::vec2ui&, uint32, void*);

		template<typename T>
		struct __attrib_item__ {
			uint32 param;
			T data;
		};
		
		struct __set_attrib_int__ : public infi_gl_typed_function_t< __attrib_item__<int32> > {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __attrib_item__<int32>&) const;
		};
		struct __set_attrib_intv__ : public infi_gl_typed_function_t< __attrib_item__<int32*> > {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __attrib_item__<int32*>&) const;
		};
		struct __set_attrib_float__ : public infi_gl_typed_function_t< __attrib_item__<float32> > {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __attrib_item__<float32>&) const;
		};
		struct __set_attrib_floatv__ : public infi_gl_typed_function_t< __attrib_item__<float32*> > {
		public:
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, __attrib_item__<float32*>&) const;
		};

		struct __jpeg_loader__ : public IO::infi_base_loader_t {
		private:
			struct __stream__ {
				jpeg_source_mgr pub;
				std::istream* stream;
				int8 buffer[4096];
			};
			
			static void __init(j_decompress_ptr);
			static boolean __fill(j_decompress_ptr);
			static void __skip(j_decompress_ptr, long);
			static void __term(j_decompress_ptr);
			static void __make_stream(j_decompress_ptr, std::istream*);

			infi_texture_t& _texture;

		protected:
			void Load(infi_controller_t&, std::ifstream&);

		public:
			__jpeg_loader__(const std::string&, infi_texture_t&);
		};

		struct __png_loader__ : public IO::infi_base_loader_t {
		private:
			static bool __validate(std::istream&);
			static void __read(png_structp pngPtr, png_bytep data, png_size_t length);

			infi_texture_t& _texture;

		protected:
			void Load(infi_controller_t&, std::ifstream&);

		public:
			__png_loader__(const std::string&, infi_texture_t&);
		};

		uint32 _handle;
		texture_format _format;

		core::vec2i _dimensions;

		__upload_data__ _upload_data;
		__upload_subdata__ _upload_subdata;
		__set_attrib_int__ _set_attrib_int;
		__set_attrib_intv__ _set_attrib_intv;
		__set_attrib_float__ _set_attrib_float;
		__set_attrib_floatv__ _set_attrib_floatv;

		static infi_typed_allocator_t<__jpeg_loader__, 64> _jpeg_loader;

	public:
		template<typename _Upload>
		struct DEFINE_EXPORT Upload {
		private:
			infi_renderer_t& _renderer;
			infi_texture_t& _texture;
			uint32 _active;
		public:
			Upload(infi_renderer_t& r, infi_texture_t& t, uint32 a = 0) :
				_renderer(r), _texture(t), _active(a) {
				_renderer.pushTexture(_texture._handle, _active);
			}
			~Upload() {
				_renderer.popTexture(_active);
			}

			void copyFormat(const infi_texture_t& t, const _Upload* data = NULL) {
				_texture._dimensions = t._dimensions;
				_texture._format = t._format;
				_texture.__upload_data(_renderer, infi_texture_t::Format<_Upload>::Type(), (void*)data);
			}
			void operator()(texture_format format, const core::vec2ui& dim, const _Upload* data) {
				_texture._format = format;
				_texture._dimensions = dim;
				_texture.__upload_data(_renderer, infi_texture_t::Format<_Upload>::Type(), (void*)data);	
			}
			void operator()(const core::vec2ui& dim, const _Upload* data) {
				_texture.__upload_subdata(_renderer, core::vec2i(), dim, infi_texture_t::Format<_Upload>::Type(), (void*)data);
			}
			void operator()(const core::vec2ui& off, const core::vec2ui& dim, const _Upload* data) {
				_texture.__upload_subdata(_renderer, off, dim, infi_texture_t::Format<_Upload>::Type(), (void*)data);
			}
		};

		struct DEFINE_EXPORT Bind {
		private:
			infi_renderer_t& _renderer;
			infi_texture_t& _texture;
			uint32 _active;
		public:
			Bind(infi_renderer_t&, infi_texture_t&, uint32=0);
			~Bind();

			void attribute(uint32, int32);
			void attribute(uint32, int32*);
			void attribute(uint32, float32);
			void attribute(uint32, float32*);
		};

		infi_texture_t();
		infi_texture_t(infi_renderer_t&);
		~infi_texture_t();

		void create(infi_synchronized_renderer_t&);

		template<infi_threadable_t::Operation _Eval=infi_threadable_t::Parallel>
		typename infi_threadable_t::function_return<_Eval>::type
			JPEG(infi_controller_t&, const std::string&);

		template<infi_threadable_t::Operation _Eval=infi_threadable_t::Parallel>
		typename infi_threadable_t::function_return<_Eval>::type
			PNG(infi_controller_t&, const std::string&);

		uint32 handle() const;
		const core::vec2i& dimensions() const;
	};

	template<> infi_threadable_t::function_return<infi_threadable_t::Parallel>::type
	DEFINE_EXPORT infi_texture_t::JPEG<infi_threadable_t::Parallel>(infi_controller_t&, const std::string&);

	template<> infi_threadable_t::function_return<infi_threadable_t::Serial>::type
	DEFINE_EXPORT infi_texture_t::JPEG<infi_threadable_t::Serial>(infi_controller_t&, const std::string&);

	template<> infi_threadable_t::function_return<infi_threadable_t::Parallel>::type
	DEFINE_EXPORT infi_texture_t::PNG<infi_threadable_t::Parallel>(infi_controller_t&, const std::string&);

	template<> infi_threadable_t::function_return<infi_threadable_t::Serial>::type
	DEFINE_EXPORT infi_texture_t::PNG<infi_threadable_t::Serial>(infi_controller_t&, const std::string&);

	template<> struct DEFINE_EXPORT infi_texture_t::Format<int8> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<uint8> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<int16> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<uint16> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<int32> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<uint32> { static uint32 Type(); };
	template<> struct DEFINE_EXPORT infi_texture_t::Format<float32> { static uint32 Type(); };

} }

#endif//__INFI_TEXTURE_HPP__