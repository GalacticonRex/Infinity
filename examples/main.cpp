#include "infinity.hpp"

void run(const Infinity::Library& lib) {
	// Initialize Controller
	Infinity::Controller control(lib);

	// Create window that closes when you press the <escape> key
	Infinity::Window& mainWindow = control.createWindow("Window", {1024,780}, 60);
	mainWindow.close.when( mainWindow.input.escape );

	core::transform3_t transform;

	Infinity::Shader shad;
	Infinity::Vertices vertices;
	Infinity::Draw drawCall;

	{
		Infinity::AcquireRenderer renderer(control.renderer);
		vertices.create(renderer);
		{
			Infinity::Vertices::Define<core::vec2, core::vec2>
				vertDef(renderer, vertices, Infinity::Triangles(2));
			
			vertDef[0] = {{0.0f, 0.0f}, {0.0f, 0.0f}};
			vertDef[1] = {{0.0f, 1.0f}, {0.0f, 1.0f}};
			vertDef[2] = {{1.0f, 0.0f}, {1.0f, 0.0f}};
			vertDef[3] = {{1.0f, 1.0f}, {1.0f, 1.0f}};

			vertDef.indices[0] = {0,2,3};
			vertDef.indices[1] = {3,1,0};
		}

		shad = Infinity::Assets2D::Shader(
			renderer,
			{Infinity::Assets2D::Position, Infinity::Assets2D::UV}
			);

		shad[Infinity::Assets2D::Transform] = transform;

		drawCall.bind(vertices, shad);
	}


	mainWindow.renderWith([&](Infinity::Renderer& R){
		drawCall(R);
	});

	// Run the game!
	control.run();
}

int main(int argc, char** argv) {
	Infinity::Run(run);
	return 0;
}