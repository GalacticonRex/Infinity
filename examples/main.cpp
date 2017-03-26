#include "infinity.hpp"

struct DrawBox : public Infinity::Renderable {
private:
	Infinity::Controller& _control;
	Infinity::Program _program;
	Infinity::Buffer _buffer;

	Infinity::Texture _abigail;
	Infinity::Texture _texture;
	Infinity::Texture _fbo_target;

	Infinity::Framebuffer _fbo;

	Infinity::Blender _blend;

	Infinity::Vertices _vertices;

	core::transform3_t _transform;

	float32 _rotation;

public:
	DrawBox(Infinity::Controller& ctrl) :
		Infinity::Renderable("DrawBox"),
		_control(ctrl),
		_rotation(0.0f) {

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

		_program.vertex =	"#version 150\r\n"
							"uniform mat4 uMVP;"
							"in vec2 vPosition;"
							"in vec2 vUV;"
							"out vec2 fUV;"
							"void main() {"
							"	gl_Position = uMVP * vec4(vPosition, 0, 1);"
							"	fUV = vUV;"
							"}";

		_program.fragment =	"#version 150\r\n"
							"uniform vec4 uColor;"
							"uniform sampler2D uImage;"
							"in vec2 fUV;"
							"out vec4 oColor;"
							"void main() {"
							"	oColor = uColor * texture2D(uImage, fUV);"
							"}";

		Infinity::AcquireRenderer renderer(ctrl.renderer);
		_program.link(renderer.source())
			.then( ctrl, [this](Infinity::Controller& ctrl) {
				std::cerr << "moo" << std::endl;
				Infinity::AcquireRenderer R(ctrl.renderer);
				Infinity::Vertices::Modify modVert(R, _vertices);
				modVert.vertices(_buffer);
				modVert.attributes(_program.format);
				std::cerr << "moo" << std::endl;
			} );
	}

	void OnBind( Infinity::Renderer& R ) {
		Infinity::Program::Bind program(R, _program);
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

		buffer.upload<float32, 24>( data );

		program.uniform("uColor", core::vec4{1,1,1,1});
		program.uniformi("uImage", (int32)0);
	}
	void Render( Infinity::Renderer& R, float64 dt ) {
		if ( _control.input.mouse.left ) {
			_rotation += 0.1f;
		}
		if ( _control.input.mouse.right ) {

			
			_rotation -= 0.1f;
		}

		core::vec2i dim = _abigail.dimensions() * 2;
		core::vec2i hlf = dim / 2;
		core::vec2i pos = _control.input.mouse.position();
		
		_transform.position(core::vec3(pos.x, pos.y, 0));
		_transform.pivotPoint(core::vec3(hlf.x, hlf.y, 0));
		_transform.rotation(core::toQuaternion(core::axisangle_t(_rotation,{0,0,1})));
		_transform.scale(core::scale3_t(dim.x, dim.y));

		{
			Infinity::Vertices::Bind vertices(R, _vertices);
		}

		Infinity::Blender::Bind blend(R, _blend);
		Infinity::Program::Bind program(R, _program);
		{
			core::vec2ui d = _texture.dimensions();
			Infinity::Texture::Bind texture(R, _texture);
			program.uniform("uMVP", core::ortho4( parent() ) * core::scale4(core::vec3(d.x, d.y, 1)) );
			program.draw( _buffer );
		}
		{
			Infinity::Texture::Bind texture(R, _abigail);
			program.uniform("uMVP", core::ortho4( parent() ) * (core::mat4)_transform );
			program.draw( _buffer );
		}
	}
};

void run() {
	// Initialize Library and Controller
	Infinity::Library lib;
	Infinity::Controller control(lib);

	// Create window that closes when you press the <escape> key
	Infinity::Window& mainWindow = control.createWindow("Window", {1600,900}, 60);
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