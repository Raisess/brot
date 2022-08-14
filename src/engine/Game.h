#pragma once

#include <iostream>
#include <functional>
#include <memory>
#include "../gfx/Renderer.h"
#include "../gfx/TextComponent.h"
#include "../gfx/Window.h"
#include "../util/ArgsParser.h"

namespace Engine {

class GameContext {
public:
  std::unique_ptr<GFX::Window> window_ctx;
  std::shared_ptr<GFX::Renderer> render_ctx;
  std::shared_ptr<GFX::Font> engine_font;

  GameContext(const std::string& window_title, int argc, char* argv[]);
};

class GameInfo {
public:
  struct Info {
    int delta_time;
    int fps;
  };

  GameInfo(const GameContext& game_ctx);

  void update(const struct Info& info);
  void draw();

private:
  static int Offset;

  const GameContext& game_ctx;
  struct Info _info;
  std::unique_ptr<GFX::TextComponent> _fps;
  std::unique_ptr<GFX::TextComponent> _delta_time;
};

class Game {
public:
  GameContext ctx;
  GameInfo info;

  Game(const std::string& title, int argc, char* argv[]);
  ~Game();

  void loop(const CallbackLoop& callback);
  void toggle_info();
  void end() const;

private:
  std::unique_ptr<GFX::TextComponent> _logo;
  bool _started = false;
  bool _info = false;
};

}
