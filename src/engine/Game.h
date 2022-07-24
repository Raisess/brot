#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include "../gfx/Renderer.h"
#include "../gfx/Window.h"

#define GWINDOW_W 800
#define GWINDOW_H 600
#define LOGO_W 500
#define LOGO_H 100
#define INTRO_DELAY 3000

namespace Engine {

class GameContext {
public:
  std::unique_ptr<GFX::Window> window_ctx;
  std::shared_ptr<GFX::Renderer> render_ctx;

  GameContext(const std::string& window_title);
};

class Game {

public:
  GameContext ctx;

  Game(const std::string& title);
  ~Game();

  void loop(const CallbackLoop& callback) const;
  void end() const;
};

}
