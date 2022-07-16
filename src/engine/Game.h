#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include "../gfx/Renderer.h"
#include "../gfx/Window.h"

#define GWINDOW_W 800
#define GWINDOW_H 600

namespace Engine {

class GameContext {
public:
  std::unique_ptr<GFX::Window> window_ctx;
  std::shared_ptr<GFX::Renderer> render_ctx;

  GameContext(const std::string& window_title);
};

class Game {

using Loop = std::function<void(void)>;

public:
  GameContext ctx;

  Game(const std::string& title);

  void loop(const Loop& callback) const;
};

}
