#pragma once

#include <brot/engine/core/Game.h>
#include <brot/engine/core/Scene.h>

class Game {
public:
  Game(int argc, char* argv[]);
  ~Game();

  void run();

private:
  Engine::Game game;
};
