#include <memory>
#include <brot/input/Keyboard.h>
#include "object/PlayerObject.h"
#include "object/RoomObject.h"
#include "Game.h"

Game::Game(int argc, char* argv[])
  : game("binary-maze", argc, argv) {
  game.toggle_info();
}

Game::~Game() {}

void Game::run() {
  Engine::Scene scene("main");

  auto player = std::make_shared<PlayerObject>(this->game.ctx);
  auto room = std::make_shared<RoomObject>(this->game.ctx);
  auto left_door = std::make_shared<RoomDoorObject>(
    this->game.ctx,
    *room,
    RoomDoorObject::Side::LEFT
  );
  auto right_door = std::make_shared<RoomDoorObject>(
    this->game.ctx,
    *room,
    RoomDoorObject::Side::RIGHT
  );
  auto bottom_door = std::make_shared<RoomDoorObject>(
    this->game.ctx,
    *room,
    RoomDoorObject::Side::BOTTOM
  );

  auto main_layer = scene.push_layer();
  main_layer->nodes.push_back(player);
  main_layer->nodes.push_back(left_door);
  main_layer->nodes.push_back(right_door);
  main_layer->nodes.push_back(bottom_door);
  main_layer->nodes.push_back(room);

  auto gui_layer = scene.push_layer();

  this->game.loop([&](int dt) {
    Input::Keyboard::IsPressed(Input::Keyboard::ESC, [&]() {
      this->game.end();
    });

    // TODO: add binary tree core
    // TODO: add door events

    scene.update(dt);
    scene.draw();
  });
}
