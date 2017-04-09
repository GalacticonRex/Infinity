#ifndef __INFI_VERTEX_FORMAT_HPP__
#define __INFI_VERTEX_FORMAT_HPP__

#include <vector>

#include "base/types.hpp"
#include "render/infi_render_defs.hpp"
#include "render/gl/infi_gl_command.hpp"
#include "render/gl/infi_gl_context.hpp"

namespace Infinity {
namespace Render {

	struct infi_vertex_format_t {

	struct attribute {
		uint32 bind_point;
		ShaderAttribType type;
		uint32 count;
	};
	struct formatted_attrib {
		uint32 bind_point; // index of this attribute
		AttribType type; // type of attribute (i.e. vec4 = float)
		uint32 count; // number of elements (i.e. vec4 = 4)
		uint32 size; // size in bytes of this attribute
	};

	private:
		struct __bind_format__ : public infi_gl_typed_function_t<infi_vertex_format_t*> {
			bool compatible(const infi_gl_t&) const;
			void run(const infi_gl_t&, infi_gl_context_controller_t&, infi_vertex_format_t*&) const;
		};

		std::vector<formatted_attrib> _attributes;
		uint32 _size;
		__bind_format__ _bind;

		template<typename T>
		bool __matches(uint32 i) const {
			static_assert(true, "Invalid types!");
			return false;
		}
		
		template<typename _T, typename... _Args>
		bool __matchesv(uint32 i) const {
			if ( i >= _attributes.size() )
				Error::send<Error::Fatality::Method>(
					Error::Type::Index,
					"Invalid number of type arguments!"
				);
			return __matches<_T>(i) && __matches_base<_Args...>(i+1);
		}

		template<typename... _Args>
		bool __matches_base(uint32 i) const {
			return __matchesv<_Args...>(i);
		}

		template<typename _T>
		void __fill_data() {
			formatted_attrib attr;
			attr.bind_point = _attributes.size();
			if ( !infi_gl_t::getComponents<_T>(attr.type, attr.count) ) {
				Error::send<Error::Fatality::Method>(
					Error::Type::Type,
					"Invalid type %s in creation of vertex format!",
					typeid(_T).name()
				);
			}
			attr.size = attr.count * infi_gl_t::sizeOf(attr.type);
			_attributes.push_back(attr);
		}

		template<typename _T, typename... _Args>
		void __fill_data_args() {
			__fill_data<_T>();
			__fill_data_base<_Args...>();
		}
		template<typename... _Args>
		void __fill_data_base() {
			__fill_data_args<_Args...>();
		}

	public:
		struct DEFINE_EXPORT Bind {
		private:
			infi_renderer_t& _renderer;
			infi_vertex_format_t& _vf;
		public:
			Bind(infi_renderer_t&, infi_vertex_format_t&);
			~Bind();
		};

		template<typename... _Args>
		static infi_vertex_format_t Create() {
			infi_vertex_format_t output;
			output._attributes.resize(sizeof...(_Args));
			output.__fill_data_base<_Args...>();
			return output;
		}

		infi_vertex_format_t();
		infi_vertex_format_t(std::initializer_list<attribute>);
		infi_vertex_format_t(const std::vector<attribute>&);

		const formatted_attrib& operator[](uint32) const;
		uint32 attributeCount() const;
		uint32 byteSize() const;

		template<typename... _Args>
		bool matches() const {
			return __matches_base<_Args...>(0);
		}

		operator infi_vertex_array_bindings_t() const;
		void fillArrayBindings(infi_vertex_array_bindings_t&) const;
	};

	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches_base<>(uint32 i) const;
	template<> void DEFINE_EXPORT infi_vertex_format_t::__fill_data_base<>();

	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<float32>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec2>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec3>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec4>(uint32 i) const;

	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<int32>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec2i>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec3i>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec4i>(uint32 i) const;

	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<uint32>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec2ui>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec3ui>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::vec4ui>(uint32 i) const;

	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::mat2>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::mat3>(uint32 i) const;
	template<> bool DEFINE_EXPORT infi_vertex_format_t::__matches<core::mat4>(uint32 i) const;

} }

#endif//__INFI_VERTEX_FORMAT_HPP__/
