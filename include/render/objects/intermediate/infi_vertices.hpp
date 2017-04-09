#ifndef __INFI_VERTICES_HPP__
#define __INFI_VERTICES_HPP__

#include <algorithm>
#include "render/infi_renderer.hpp"
#include "render/objects/basic/infi_buffer_object.hpp"
#include "render/objects/basic/infi_vertex_array.hpp"
#include "render/objects/basic/infi_vertex_format.hpp"

namespace Infinity {
namespace Render {

	struct infi_vertices_t {
	private:
		infi_vertex_format_t _format;
		infi_vertex_array_t _vertex_array;
		infi_buffer_object_t _geometry;
		infi_buffer_object_t _indices;

		template<typename _T>
		static void __upload_single(const _T& item, uint8*& data) {
			*((_T*) data) = item;
			data += sizeof(_T);
		}

		template<uint32 _I, typename _T, typename... _Args>
		static void __upload_vertex(const _T& v, uint8*& data) {
			std::tuple_element<_I, std::tuple<_Args...>>& item = std::get<_I>(v);
			*((std::tuple_element<_I, std::tuple<_Args...>>*) data) = item;
			data += sizeof(std::tuple_element<_I, std::tuple<_Args...>>);

			__upload_vertex<_I-1>(v, data);
		}

		template<uint32 _I, typename _T, typename _K, typename _Args...>
		static void __upload_vertex_base(const _T& v, uint8*& data) {
			__upload_single(std::get<sizeof...(_Args)-_I>(v), data);
			__upload_vertex_base<_I+1, _T, _Args...>(v, data);
		}

	public:
		template<typename... _Args>
		struct Define {
		typedef std::tuple<_Args...> Vertex;

		private:
			infi_renderer_t& _renderer;
			infi_vertices_t& _vertices;
			std::vector<Vertex> _data;

		public:
			Define(infi_renderer_t& R, infi_vertices_t& vert) :
				_renderer(R), _vertices(vert) { ; }
			Define(infi_renderer_t& R, infi_vertices_t& vert, uint32 count) :
				_renderer(R), _vertices(vert), _data(count) { ; }
			~Define() {
				_vertices._format = infi_vertex_format_t::Create<_Args...>();

				_vertices._geometry.create(_renderer, infi_gl_t::ARRAY_BUFFER);

				infi_buffer_object_t::Bind buffer(_renderer, _vertices._geometry, infi_gl_t::ARRAY_BUFFER);
				uint8* data = new uint8[sizeof(Vertex) * _data.size()];
				
				uint8* ptr = data;
				for ( uint32 i=0;i<_data.size();i++ )
					__upload_vertex_base<sizeof...(_Args), std::tuple<_Args...>, _Args...>(_data[i], ptr);

				buffer.raw_upload(8, data).then([=](){delete[] data;});
			}
			
			Define& operator+= (const Vertex& data) {
				_data.push_back(data);
				return *this;
			}
			Vertex& operator[] (uint32 i) {
				if ( i >= _data.size() )
					Error::send<Error::Fatality::Method>(
						Error::Type::Index,
						"Invalid index %d, only %d vertices have been defined",
						i, _data.size()
					);
				return _data[i];
			}

		};

		struct DEFINE_EXPORT Bind {
		private:
			infi_vertices_t& _vertices;
		public:
			Bind(infi_vertices_t&);
			~Bind();
		};

		infi_vertices_t(infi_renderer_t&);
	};

	template<typename... _Args>
	void infi_vertices_t::__upload_vertex<0, _Args...>(const std::tuple<_Args...>& verts, uint8*& data) {
		std::tuple_element<0, std::tuple<_Args...>>& item = std::get<0>(verts);
		*((std::tuple_element<0, std::tuple<_Args...>>*) data) = item;
		data += sizeof(std::tuple_element<0, Vertex>);
	}

} }

#endif//__INFI_VERTICES_HPP__