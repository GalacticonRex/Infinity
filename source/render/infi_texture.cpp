#include "render/objects/basic/infi_texture.hpp"
#include "engine/infi_controller.hpp"
#include "render/infi_sync_renderer.hpp"
#include "render/gl/infi_gl_context_controller.hpp"
#include "render/infi_sync_renderer.hpp"

namespace Infinity {
namespace Render {

	infi_typed_allocator_t<infi_texture_t::__jpeg_loader__, 64> infi_texture_t::_jpeg_loader;

	bool infi_texture_t::__upload_data__::compatible(const Render::infi_gl_t&) const {
		return true;
	}
	void infi_texture_t::__upload_data__::run(const Render::infi_gl_t& gl, Render::infi_gl_context_controller_t& ctx, __upload_item__& u) const {
		gl.TexImage(0, u.internal_format, u.dimensions.x, u.dimensions.y, u.format, u.type, u.data);
	}

	bool infi_texture_t::__upload_subdata__::compatible(const infi_gl_t& gl) const {
		return true;
	}
	void infi_texture_t::__upload_subdata__::run(const infi_gl_t& gl, infi_gl_context_controller_t& ctx, __upload_subitem__& u) const {
		if ( u.format == 0 ) {
			Error::send<Error::Fatality::Method> (
				Error::Type::Init,
				"Texture has not yet been initialized for subdata upload"
			);
		}
		gl.TexSubImage(0, u.offset.x, u.offset.y, u.dimensions.x, u.dimensions.y, u.format, u.type, u.data);
	}

	void infi_texture_t::__upload_data(infi_renderer_t& r, uint32 type, void* data) {
		__upload_item__ u;
		u.internal_format = _format.size_type;
		u.format = _format.base_type;
		u.type = type;
		u.dimensions = _dimensions;
		u.data = (uint8*)data;

		_upload_data.push(r.state(), u);
		r(_upload_data);
	}
	void infi_texture_t::__upload_subdata(infi_renderer_t& r, const core::vec2i& off, const core::vec2ui& dim, uint32 type, void* data) {
		__upload_subitem__ u;
		u.format = _format.base_type;
		u.type = type;
		u.offset = off;
		u.dimensions = dim;
		u.data = (uint8*)data;

		_upload_subdata.push(r.state(), u);
		r(_upload_subdata);
	}

	bool infi_texture_t::__set_attrib_int__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_texture_t::__set_attrib_int__::run(const infi_gl_t& gl, infi_gl_context_controller_t&, __attrib_item__<int32>& attr) const {
		gl.TexParameteri(attr.param, attr.data);
	}
	bool infi_texture_t::__set_attrib_intv__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_texture_t::__set_attrib_intv__::run(const infi_gl_t& gl, infi_gl_context_controller_t&, __attrib_item__<int32*>& attr) const {
		gl.TexParameteri(attr.param, attr.data);
	}
	bool infi_texture_t::__set_attrib_float__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_texture_t::__set_attrib_float__::run(const infi_gl_t& gl, infi_gl_context_controller_t&, __attrib_item__<float32>& attr) const {
		gl.TexParameterf(attr.param, attr.data);
	}
	bool infi_texture_t::__set_attrib_floatv__::compatible(const infi_gl_t&) const {
		return true;
	}
	void infi_texture_t::__set_attrib_floatv__::run(const infi_gl_t& gl, infi_gl_context_controller_t&, __attrib_item__<float32*>& attr) const {
		gl.TexParameterf(attr.param, attr.data);
	}

	void infi_texture_t::__jpeg_loader__::__init(j_decompress_ptr cinfo) {
		__stream__* src = (__stream__*)(cinfo->src);
		src->stream->seekg(0, src->stream->beg);
	}
	boolean infi_texture_t::__jpeg_loader__::__fill(j_decompress_ptr cinfo) {
		__stream__* src = (__stream__*)(cinfo->src);

		src->stream->read(src->buffer,4096);

		src->pub.next_input_byte = (const JOCTET*)src->buffer;
		if (src->stream->gcount() <= 0) {
			src->buffer[0] = (JOCTET) 0xFF;
    		src->buffer[1] = (JOCTET) JPEG_EOI;
    		src->pub.bytes_in_buffer = 2;
		} else {
			src->pub.bytes_in_buffer = src->stream->gcount();
		}

		return TRUE;
	}
	void infi_texture_t::__jpeg_loader__::__skip(j_decompress_ptr cinfo, long num_bytes) {
		__stream__* src = (__stream__*)(cinfo->src);

		if (num_bytes > 0) {
			while (num_bytes > (long) src->pub.bytes_in_buffer) {
				num_bytes -= (long) src->pub.bytes_in_buffer;
				(void) (*src->pub.fill_input_buffer) (cinfo);
			}
			src->pub.next_input_byte += (std::size_t) num_bytes;
			src->pub.bytes_in_buffer -= (std::size_t) num_bytes;
		}
	}
	void infi_texture_t::__jpeg_loader__::__term(j_decompress_ptr cinfo) {
		
	}
	void infi_texture_t::__jpeg_loader__::__make_stream(j_decompress_ptr cinfo, std::istream* in) {
		__stream__ * src;

		if (cinfo->src == nullptr)
		{   
			cinfo->src = (struct jpeg_source_mgr *)(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(__stream__));
			src = reinterpret_cast<__stream__*> (cinfo->src);
		}

		src = reinterpret_cast<__stream__*> (cinfo->src);
		
		src->pub.init_source = __init;
		src->pub.fill_input_buffer = __fill;
		src->pub.skip_input_data = __skip;
		src->pub.term_source = __term;

		src->pub.resync_to_restart = jpeg_resync_to_restart;
		src->stream = in;
		src->pub.bytes_in_buffer = 0;
		src->pub.next_input_byte = nullptr;
	}

	void infi_texture_t::__jpeg_loader__::Load(infi_controller_t& ctrl, std::ifstream& input) {
		struct jpeg_decompress_struct cinfo;
		struct jpeg_error_mgr jerr;
		
		JSAMPARRAY buffer;
		int32 row_stride;
		
		cinfo.err = jpeg_std_error(&jerr);
		
		jpeg_create_decompress(&cinfo);
		__make_stream(&cinfo, &input);
		
		(void) jpeg_read_header(&cinfo, TRUE);
		(void) jpeg_start_decompress(&cinfo);
		
		row_stride = ( cinfo.output_width * cinfo.output_components );
		uint32 irwst = row_stride;
		if ( row_stride % 4 )
			row_stride += 4 - row_stride % 4;

		buffer = (*cinfo.mem->alloc_sarray)
		((j_common_ptr) &cinfo, JPOOL_IMAGE, row_stride, 1);
		
		core::vec2i dim = core::vec2i( cinfo.output_width, cinfo.output_height );
		uint32 buflen = row_stride * cinfo.output_height;
		char* mainbuf = new char[buflen];

		uint32 scanlines = 1;
		uint32 index = 0;
		
		while (cinfo.output_scanline < cinfo.output_height) {
			(void) jpeg_read_scanlines(&cinfo, buffer, scanlines);
			uint32 offset = row_stride * ( dim.y - index - 1 );
			memcpy( mainbuf + offset,
					buffer[0],
					irwst );
			index += scanlines;
		}
		
		(void) jpeg_finish_decompress(&cinfo);
		jpeg_destroy_decompress(&cinfo);

		__upload_item__ u;
		u.internal_format = GL_RGB8;
		u.format = GL_RGB;
		u.type = GL_UNSIGNED_BYTE;
		u.dimensions = dim;
		u.data = (uint8*)mainbuf;

		_texture._dimensions = dim;
		_texture._format = {GL_RGB8, GL_RGB};

		Render::infi_synchronized_renderer_t::Acquire renderer(ctrl.renderer);
		renderer -> pushTexture(_texture._handle);
		_texture._upload_data.push(renderer -> state(), u);
		renderer -> command(_texture._upload_data);
		renderer -> popTexture();
	}
	infi_texture_t::__jpeg_loader__::__jpeg_loader__(const std::string& fname, infi_texture_t& t) :
		infi_base_loader_t(fname), _texture(t) { ; }

	bool infi_texture_t::__png_loader__::__validate(std::istream& source) {
		//Allocate a buffer of 8 bytes, where we can put the file signature.
		png_byte pngsig[8];
		int is_png = 0;

		//Read the 8 bytes from the stream into the sig buffer.
		source.read((char*)pngsig, 8);

		//Check if the read worked...
		if (!source.good()) return false;

		//Let LibPNG check the sig. If this function returns 0, everything is OK.
		is_png = png_sig_cmp(pngsig, 0, 8);
		return (is_png == 0);
	}
	void infi_texture_t::__png_loader__::__read(png_structp pngPtr, png_bytep data, png_size_t length) {
		png_voidp a = png_get_io_ptr(pngPtr);
		((std::istream*)a)->read((char*)data, length);
	}

	void infi_texture_t::__png_loader__::Load(infi_controller_t& ctrl, std::ifstream& input) {
		//so First, we validate our stream with the validate function I just mentioned
		if (!__validate(input)) {
			Error::send<Error::Fatality::Method>(
				Error::Type::CannotReadFile,
				"Data is not valid PNG-data!"
			);
		}

		//Here we create the png read struct. The 3 nullptr's at the end can be used
		//for your own custom error handling functions, but we'll just use the default.
		//if the function fails, nullptr is returned. Always check the return values!
		png_structp pngPtr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
		if (!pngPtr) {
			Error::send<Error::Fatality::Method>(
				Error::Type::CannotReadFile,
				"Couldn't initialize PNG reader!"
			);
		}

		//Here we create the png info struct.
		//Note that this time, if this function fails, we have to clean up the read struct!
		png_infop infoPtr = png_create_info_struct(pngPtr);
		if (!infoPtr) {
			png_destroy_read_struct(&pngPtr, (png_infopp)0, (png_infopp)0);
			Error::send<Error::Fatality::Method>(
				Error::Type::CannotReadFile,
				"Couldn't initialize PNG information!"
			);
		}

		//Here I've defined 2 pointers up front, so I can use them in error handling.
		//I will explain these 2 later. Just making sure these get deleted on error.
		png_bytep* rowPtrs = nullptr;
		char* data = nullptr;

		if (setjmp(png_jmpbuf(pngPtr))) {
			//An error occured, so clean up what we have allocated so far...
			png_destroy_read_struct(&pngPtr, &infoPtr, (png_infopp)0);
			if (rowPtrs != nullptr) delete [] rowPtrs;
			if (data != nullptr) delete [] data;

			Error::send<Error::Fatality::Method>(
				Error::Type::Failed,
				"An error occured while reading the PNG file!"
			);
		}

		png_set_read_fn(pngPtr,(png_voidp)&input, __read);

		png_set_sig_bytes(pngPtr, 8);

		png_read_info(pngPtr, infoPtr);

		png_uint_32 imgWidth =  png_get_image_width(pngPtr, infoPtr);
		png_uint_32 imgHeight = png_get_image_height(pngPtr, infoPtr);

		//bits per CHANNEL! note: not per pixel!
		png_uint_32 bitdepth   = png_get_bit_depth(pngPtr, infoPtr);
		//Number of channels
		png_uint_32 channels   = png_get_channels(pngPtr, infoPtr);
		//Color type. (RGB, RGBA, Luminance, luminance alpha... palette... etc)
		png_uint_32 color_type = png_get_color_type(pngPtr, infoPtr);

		switch (color_type) {
			case PNG_COLOR_TYPE_PALETTE:
				png_set_palette_to_rgb(pngPtr);
				//Don't forget to update the channel info (thanks Tom!)
				//It's used later to know how big a buffer we need for the image
				channels = 3;           
				break;
			case PNG_COLOR_TYPE_GRAY:
				if (bitdepth < 8)
					png_set_expand_gray_1_2_4_to_8(pngPtr);
				//And the bitdepth info
				bitdepth = 8;
				break;
		}

		/*if the image has a transperancy set.. convert it to a full Alpha channel..*/
		if (png_get_valid(pngPtr, infoPtr, PNG_INFO_tRNS)) {
			png_set_tRNS_to_alpha(pngPtr);
			channels ++ ;
		}

		//We don't support 16 bit precision.. so if the image Has 16 bits per channel
		//precision... round it down to 8.
		if (bitdepth == 16)
			png_set_strip_16(pngPtr);

		//As Nicholas suggested, we should let png update the information structs with the transformations we requested:
		png_read_update_info(pngPtr, infoPtr);

		//Here's one of the pointers we've defined in the error handler section:
		//Array of row pointers. One for every row.
		rowPtrs = new png_bytep[imgHeight];

		//Alocate a buffer with enough space.
		//(Don't use the stack, these blocks get big easilly)
		//This pointer was also defined in the error handling section, so we can clean it up on error.
		data = new char[imgWidth * imgHeight * bitdepth * channels / 8];
		//This is the length in bytes, of one row.
		const unsigned int stride = imgWidth * bitdepth * channels / 8;

		//A little for-loop here to set all the row pointers to the starting
		//Adresses for every row in the buffer

		for (uint32 i = 0; i < imgHeight; i++) {
			//Set the pointer to the data pointer + i times the row stride.
			//Notice that the row order is reversed with q.
			//This is how at least OpenGL expects it,
			//and how many other image loaders present the data.
			png_uint_32 q = (imgHeight- i - 1) * stride;
			rowPtrs[i] = (png_bytep)data + q;
		}

		//And here it is! The actuall reading of the image!
		//Read the imagedata and write it to the adresses pointed to
		//by rowptrs (in other words: our image databuffer)
		png_read_image(pngPtr, rowPtrs);

		//Delete the row pointers array....
		delete[] (png_bytep)rowPtrs;
		//And don't forget to clean up the read and info structs !
		png_destroy_read_struct(&pngPtr, &infoPtr,(png_infopp)0);

		__upload_item__ u;
		u.internal_format = GL_RGBA8;
		u.format = GL_RGBA;
		u.type = GL_UNSIGNED_BYTE;
		u.dimensions = core::vec2ui(imgWidth, imgHeight);
		u.data = (uint8*)data;

		_texture._dimensions = core::vec2ui(imgWidth, imgHeight);
		_texture._format = {GL_RGBA8, GL_RGBA};

		Render::infi_synchronized_renderer_t::Acquire renderer(ctrl.renderer);
		renderer -> pushTexture(_texture._handle);
		_texture._upload_data.push(renderer -> state(), u);
		renderer -> command(_texture._upload_data);
		renderer -> popTexture();
	}

	infi_texture_t::__png_loader__::__png_loader__(const std::string& fname, infi_texture_t& t) :
		infi_base_loader_t(fname), _texture(t) { ; }

	template<>
	infi_threadable_t::function_return<infi_threadable_t::Parallel>::type
	infi_texture_t::JPEG<infi_threadable_t::Parallel>
	(infi_controller_t& ctrl, const std::string& fname) {
		__jpeg_loader__ ld(fname, *this);
		return infi_async_t(ctrl, ld);
	}
		
	template<>
	infi_threadable_t::function_return<infi_threadable_t::Serial>::type
	infi_texture_t::JPEG<infi_threadable_t::Serial>
	(infi_controller_t& ctrl, const std::string& fname) {
		__jpeg_loader__ ld(fname, *this);
		ld(ctrl);
	}

	template<> 
	infi_threadable_t::function_return<infi_threadable_t::Parallel>::type
	infi_texture_t::PNG<infi_threadable_t::Parallel>
	(infi_controller_t& ctrl, const std::string& fname) {
		__png_loader__ ld(fname, *this);
		return infi_async_t(ctrl, ld);
	}

	template<> 
	infi_threadable_t::function_return<infi_threadable_t::Serial>::type
	infi_texture_t::PNG<infi_threadable_t::Serial>
	(infi_controller_t& ctrl, const std::string& fname) {
		__png_loader__ ld(fname, *this);
		ld(ctrl);
	}
	
	infi_texture_t::Bind::Bind(infi_renderer_t& r, infi_texture_t& t, uint32 a) :
		_renderer(r), _texture(t), _active(a) {
		if ( _texture._handle == 0 ) {
			Error::send<Error::Fatality::Method>(
				Error::Type::Init,
				"cannot bind uninitialized texture!"
			);
		}
		_renderer.pushTexture(_texture._handle, _active);
	}
	infi_texture_t::Bind::~Bind() {
		_renderer.popTexture(_active);
	}

	void infi_texture_t::Bind::attribute(uint32 p, int32 at) {
		_texture._set_attrib_int.push(_renderer.state(), {p,at});
		_renderer(_texture._set_attrib_int);
	}
	void infi_texture_t::Bind::attribute(uint32 p, int32* at) {
		_texture._set_attrib_intv.push(_renderer.state(), {p,at});
		_renderer(_texture._set_attrib_intv);
	}
	void infi_texture_t::Bind::attribute(uint32 p, float32 at) {
		_texture._set_attrib_float.push(_renderer.state(), {p,at});
		_renderer(_texture._set_attrib_float);
	}
	void infi_texture_t::Bind::attribute(uint32 p, float32* at) {
		_texture._set_attrib_floatv.push(_renderer.state(), {p,at});
		_renderer(_texture._set_attrib_floatv);
	}

	infi_texture_t::infi_texture_t() :
		infi_resource_t(0) { ; }
	infi_texture_t::infi_texture_t(infi_renderer_t& r) :
		infi_resource_t(r.createTexture()) { ; }
	infi_texture_t::~infi_texture_t() {

	}

	void infi_texture_t::create(infi_renderer_t& r) {
		_handle = r.createTexture();
	}

	bool infi_texture_t::ready() const {
		return (_dimensions != core::vec2i());
	}
	
	const core::vec2i& infi_texture_t::dimensions() const {
		return _dimensions;
	}

	infi_texture_t::texture_format infi_texture_t::RGB(uint32 rgb) {
		return RGB(rgb, rgb, rgb);
	}
	infi_texture_t::texture_format infi_texture_t::RGB(uint32 r, uint32 g, uint32 b) {
		switch(r) {
			case 3:
				if ( g == 3 && b == 2 )
					return {GL_R3_G3_B2, GL_RGB};
				break;
			case 4:
				if ( g == 4 && b == 4 )
					return {GL_RGB4, GL_RGB};
				break;
			case 5:
				if ( g == 5 && b == 5 )
					return {GL_RGB5, GL_RGB};
				break;
			case 8:
				if ( g == 8 && b == 8 )
					return {GL_RGB8, GL_RGB};
				break;
			case 9:
				if ( g == 9 && b == 9 )
					return {GL_RGB9_E5, GL_RGB};
				break;
			case 10:
				if ( g == 10 && b == 10 )
					return {GL_RGB10, GL_RGB};
				break;
			case 12:
				if ( g == 10 && b == 10 )
					return {GL_RGB12, GL_RGB};
				break;
		}
		Error::send<Error::Fatality::Warning>(
			Error::Type::Value,
			"Cannot get texture format with R=%d, G=%d, B=%d",
			r, g, b
		);
		return {0,0};
	}
	infi_texture_t::texture_format infi_texture_t::RGBA(uint32 rgba) {
		return RGBA(rgba, rgba, rgba, rgba);
	}
	infi_texture_t::texture_format infi_texture_t::RGBA(uint32 r, uint32 g, uint32 b, uint32 a) {
		switch(r) {
			case 2:
				if ( g==2 && b==2 && a==2 )
					return {GL_RGBA2, GL_RGB};
				break;
			case 4:
				if ( g==4 && b==4 && a==4 )
					return {GL_RGBA4, GL_RGB};
				break;
			case 5:
				if ( g==5 && b==5 && a==1 )
					return {GL_RGB5_A1, GL_RGBA};
				break;
			case 8:
				if ( g==8 && b==8 && a==8 )
					return {GL_RGBA8, GL_RGBA};
				break;
			case 10:
				if ( g==10 && b==10 && a==2 )
					return {GL_RGB10_A2, GL_RGBA};
				break;
			case 12:
				if ( g==12 && b==12 && a==12 )
					return {GL_RGBA12, GL_RGBA};
				break;
			case 16:
				if ( g==16 && b==16 && a==16 )
					return {GL_RGBA16, GL_RGBA};
				break;
		}
		Error::send<Error::Fatality::Warning>(
			Error::Type::Value,
			"Cannot get texture format with R=%d, G=%d, B=%d, A=%d",
			r, g, b, a
		);
		return {0,0};
	}
	infi_texture_t::texture_format infi_texture_t::Depth() {
		return {GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT};
	}
	infi_texture_t::texture_format infi_texture_t::DepthStencil() {
		return {GL_DEPTH_STENCIL, GL_DEPTH_STENCIL};
	}

	uint32 infi_texture_t::Format<int8>::Type() {
		return GL_BYTE;
	}
	uint32 infi_texture_t::Format<uint8>::Type() {
		return GL_UNSIGNED_BYTE;
	}
	uint32 infi_texture_t::Format<int16>::Type() {
		return GL_SHORT;
	}
	uint32 infi_texture_t::Format<uint16>::Type() {
		return GL_UNSIGNED_SHORT;
	}
	uint32 infi_texture_t::Format<int32>::Type() {
		return GL_INT;
	}
	uint32 infi_texture_t::Format<uint32>::Type() {
		return GL_UNSIGNED_INT;
	}
	uint32 infi_texture_t::Format<float32>::Type() {
		return GL_FLOAT;
	}

} }