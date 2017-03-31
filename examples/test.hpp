#ifndef INFINITY_TEST
#define INFINITY_TEST

#include "infinity.hpp"

struct Player : Infinity::Game2D::Object {
private:
	Infinity::Rate<float32, keyInput<float32>> _move;
	Infinity::Sprite _sprite;
public:
	Player(Infinity::Scene& game, const std::string& fname, float32 speed) :
		_move(game.controller.clock, keyInput<float32>(game.controller, Infinity::Key::LeftArrow, speed)),
		_sprite() {}

	void Update(Infinity::Controller& control, float64 dt) {
		if ( control.input.leftArrow ) {

		}
	}
};

struct MainScene : Infinity::SceneInitializer {
	void operator()(Infinity::Scene& scene) {
		scene.alloc(Player(scene0, core::vec2(), "filename.jpg"));
		scene.alloc(Infinity::Sprite(scene0, {100,100}, "filename.jpg"));
	}
};

void run() {
	Infinity::Library lib;
	Infinity::Controller control;

	Infinity::Window& mainWindow = control.createWindow("Window", {640,480}, 60);
	mainWindow.close.when( mainWindow.input.escape );

	Infinity::Game2D game(control);
	Infinity::Scene& scene0 = game.createScene(MainScene());
	game.loadScene(scene0, mainWindow);

	control.run();
}

#endif//INFINITY_TEST