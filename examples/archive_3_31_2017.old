#include "infinity.hpp"

struct DrawBox : public Infinity::Renderable {
private:
	Infinity::Controller& _control;
	Infinity::Program _program;
	Infinity::Program _blur;
	Infinity::Buffer _buffer;
	Infinity::Texture _abigail;
	Infinity::Texture _texture;
	Infinity::Texture _fbo_target;
	Infinity::Framebuffer _fbo;
	Infinity::Blender _blend;
	Infinity::VertexArray _vertices;

	core::transform3_t _transform;

	template<typename _T>
	using quadratic = core::linear<_T, core::linear<_T>>;

	template<typename _T>
	using cubic = core::linear<_T, quadratic<_T>>;

	Infinity::Trigger<void> _trigger_a;
	Infinity::Trigger<void> _trigger_d;

	Infinity::Clock _clock;
	Infinity::Rate<float32, cubic<float64>, Infinity::Clock> _rotation;

	Infinity::Rate<float32, core::sinusoid<float64>, Infinity::EventClock> _blur_amount;

public:
	DrawBox(Infinity::Controller& ctrl) :
		Infinity::Renderable("DrawBox"),
		_control(ctrl),
		_trigger_a([&](bool signal) {
			_clock.addScale( (signal) ? -1.0 : 1.0 );
		}),
		_trigger_d([&](bool signal) {
			_clock.addScale( (signal) ? 1.0 : -1.0 );
		}),
		_clock(0.0),
		_rotation(_clock, cubic<float64>(quadratic<float64>(core::linear<float64>(1.0, 0.0), 0.0), 0.0)),
		_blur_amount(ctrl.clock, core::sinusoid<float64>(1.0, 0.5, 0.5, 0.0)) {

		_trigger_a.when(ctrl.input.a);
		_trigger_d.when(ctrl.input.d);

		_blur.create(ctrl.renderer);
		_program.create(ctrl.renderer);
		_buffer.create(ctrl.renderer, Infinity::OpenGL::ARRAY_BUFFER);
		
		_texture.create(ctrl.renderer);
		_abigail.create(ctrl.renderer);
		_fbo_target.create(ctrl.renderer);
		
		_fbo.create(ctrl.renderer);
		_vertices.create(ctrl.renderer);

		_blend.function(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		_abigail.PNG(ctrl, "..\\..\\resources\\stardew_valley\\abigail.png");
		_texture.JPEG(ctrl, "..\\..\\resources\\flowers\\hibiscus.jpg")
			.then([this](Infinity::Controller& ctrl) {
				Infinity::AcquireRenderer renderer(ctrl.renderer);
				{
					Infinity::Texture::Upload<int8> texture(renderer, _fbo_target);
					texture.copyFormat(_texture);
				}
				{
					Infinity::Framebuffer::Bind fbo(renderer, _fbo);
					fbo.texture(_fbo_target);
					fbo.clear({0,1,0,1});
				}
			});

		_program.vertex =
			"#version 150\r\n"
			"uniform mat4 uMVP;"
			"in vec2 vPosition;"
			"in vec2 vUV;"
			"out vec2 fUV;"
			"void main() {"
			"	gl_Position = uMVP * vec4(vPosition, 0, 1);"
			"	fUV = vUV;"
			"}";

		_program.fragment =	
			"#version 150\r\n"
			"uniform vec4 uColor;"
			"uniform sampler2D uImage;"
			"in vec2 fUV;"
			"out vec4 oColor;"
			"void main() {"
			"	oColor = uColor * texture2D(uImage, fUV);"
			"}";

		_blur.vertex =
			"#version 150\r\n"
			"uniform mat4 uMVP;"
			"in vec2 vPosition;"
			"in vec2 vUV;"
			"out vec2 fUV;"
			"void main() {"
			"	gl_Position = uMVP * vec4(vPosition, 0, 1);"
			"	fUV = vUV;"
			"}";

		_blur.fragment =
			"#version 150\r\n"
			"uniform float uWidth;"
			"uniform vec4 uColor;"
			"uniform sampler2D uImage;"
			"uniform float uBlurAmount;"
			"uniform float uBlurKernel[9];"
			"in vec2 fUV;"
			"out vec4 oColor;"
			"void main() {"
			"	vec4 unblurred = texture2D(uImage, fUV);"
			"	vec4 blursamp = "
			"		uBlurKernel[0] * texture2D(uImage, fUV + vec2(-4/uWidth,0)) + "
			"		uBlurKernel[1] * texture2D(uImage, fUV + vec2(-3/uWidth,0)) + "
			"		uBlurKernel[2] * texture2D(uImage, fUV + vec2(-2/uWidth,0)) + "
			"		uBlurKernel[3] * texture2D(uImage, fUV + vec2(-1/uWidth,0)) + "
			"		uBlurKernel[4] * unblurred + "
			"		uBlurKernel[5] * texture2D(uImage, fUV + vec2( 1/uWidth,0)) + "
			"		uBlurKernel[6] * texture2D(uImage, fUV + vec2( 2/uWidth,0)) + "
			"		uBlurKernel[7] * texture2D(uImage, fUV + vec2( 3/uWidth,0)) + "
			"		uBlurKernel[8] * texture2D(uImage, fUV + vec2( 4/uWidth,0));"
			"	oColor = uColor * (unblurred * (1-uBlurAmount) + blursamp * uBlurAmount);"
			"}";

		Infinity::AcquireRenderer renderer(ctrl.renderer);
		_blur.link(renderer);
		_program.link(renderer)

			.then( ctrl, [this](Infinity::Controller& ctrl) {

				Infinity::AcquireRenderer R(ctrl.renderer);
				Infinity::VertexArray::Modify modVert(R, _vertices);
				modVert.vertices(_buffer);
				modVert.attributes(_program.format);

			});
	}

	void OnBind( Infinity::Renderer& R ) {
		Infinity::Buffer::Bind buffer(R, _buffer, Infinity::OpenGL::ARRAY_BUFFER);

		{
			Infinity::Texture::Bind texture(R, _texture);
			texture.attribute(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.attribute(GL_TEXTURE_WRAP_T, GL_REPEAT);

			texture.attribute(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.attribute(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		{
			Infinity::Texture::Bind texture(R, _fbo_target);
			texture.attribute(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.attribute(GL_TEXTURE_WRAP_T, GL_REPEAT);

			texture.attribute(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			texture.attribute(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		{
			Infinity::Texture::Bind texture(R, _abigail);
			texture.attribute(GL_TEXTURE_WRAP_S, GL_REPEAT);
			texture.attribute(GL_TEXTURE_WRAP_T, GL_REPEAT);

			texture.attribute(GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			texture.attribute(GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		}

		float32* data = new float32[24] {
			0.0f, 0.0f, 0.0f, 0.0f, 
			1.0f, 1.0f, 1.0f, 1.0f, 
			0.0f, 1.0f, 0.0f, 1.0f, 
			1.0f, 1.0f, 1.0f, 1.0f, 
			0.0f, 0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};
		float32* blurk = new float[9] {
			0.1f, 0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.1f
		};

		buffer.upload<float32, 24>( data ).then(_control, [this](Infinity::Controller& ctrl) {delete[] data;});

		{
			Infinity::Program::Bind program(R, _program);
			program.uniform("uColor", core::vec4{1,1,1,1});
			program.uniformi("uImage", (int32)0);
		}
		{
			Infinity::Program::Bind program(R, _blur);
			program.uniform("uColor", core::vec4{1,1,1,1});
			program.uniformv("uBlurKernel[0]", 9, blurk);
			program.uniformi("uImage", (int32)0);
		}
	}
	void Render( Infinity::Renderer& R, float64 dt ) {
		if ( !_fbo.ready() || !_program.ready() || !_vertices.ready() )
			return;

		core::vec2i dim = _abigail.dimensions();
		core::vec2i hlf = dim / 2;
		core::vec2i pos = _control.input.mouse.position();
		
		_transform.position(core::vec3(pos.x, pos.y, 0));
		_transform.pivotPoint(core::vec3(hlf.x, hlf.y, 0));
		_transform.rotation(core::toQuaternion(core::axisangle_t(_rotation,{0,0,1})));
		_transform.scale(core::scale3_t(dim.x, dim.y));

		Infinity::Blender::Bind blend(R, _blend);
		Infinity::VertexArray::Bind vertices(R, _vertices);
		{
			Infinity::Framebuffer::Bind framebuffer(R, _fbo);
			{
				Infinity::Program::Bind program(R, _blur);
				Infinity::Texture::Bind texture(R, _texture);
				core::vec2ui d = parent().dimensions();
				program.uniform("uMVP", core::ortho4( parent() ) * core::scale4(core::vec3(d.x, d.y, 1)) );
				program.uniform("uBlurAmount", (float32)_blur_amount );
				program.uniform("uWidth", (float32)_texture.dimensions().x/2.0f );
				R.drawArrays(Infinity::OpenGL::TRIANGLES, _vertices.vertexCount());
			}
			{
				Infinity::Program::Bind program(R, _program);
				Infinity::Texture::Bind texture(R, _abigail);
				program.uniform("uMVP", core::ortho4( parent() ) * (core::mat4)_transform );
				R.drawArrays(Infinity::OpenGL::TRIANGLES, _vertices.vertexCount());
			}
		}
		{
			Infinity::Program::Bind program(R, _program);
			Infinity::Texture::Bind texture(R, _fbo_target);
			core::vec2ui d = _fbo_target.dimensions();
			program.uniform("uMVP", core::ortho4( parent() ) * core::scale4(core::vec3(d.x, d.y, 1)) );
			R.drawArrays(Infinity::OpenGL::TRIANGLES, _vertices.vertexCount());
		}
	}
};

void run() {
	// Initialize Library and Controller
	Infinity::Library lib;
	Infinity::Controller control(lib);

	// Create window that closes when you press the <escape> key
	Infinity::Window& mainWindow = control.createWindow("Window", {1024,780}, 60);
	mainWindow.close.when( mainWindow.input.escape );

	// Box Renderer
	DrawBox box(control);

	// Set rendering for box
	mainWindow.renderWith( box );

	// Run the game!
	control.run();
}

int main(int argc, char** argv) {
	run();
	return 0;
}