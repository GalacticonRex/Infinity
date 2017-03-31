#include "infinity.hpp"

void run() {
	// Initialize Library and Controller
	Infinity::Library lib;
	Infinity::Controller control(lib);

	// Create window that closes when you press the <escape> key
	Infinity::Window& mainWindow = control.createWindow("Window", {1024,780}, 60);
	mainWindow.close.when( mainWindow.input.escape );

	Infinity::Vertices vertices(ctrl.renderer);
	Infinity::Vertices::Define vertDef(vertices);
	vertDef[0] = {0.0f, 0.0f, 0.0f, 0.0f};
	vertDef[1] = {0.0f, 1.0f, 0.0f, 1.0f};
	vertDef[2] = {1.0f, 0.0f, 1.0f, 0.0f};
	vertDef[3] = {1.0f, 1.0f, 1.0f, 1.0f};

	// Run the game!
	control.run();
}

int main(int argc, char** argv) {
	run();
	return 0;
}