#pragma once

#include <memory>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"
#include "../gfx/Text.h"
#include "../gfx/TextComponent.h"
#include "Game.h"

namespace Engine {

class UI {
public:
  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  int angle = 0;
  bool hide = false;
  bool fill = false;
  bool flip = false;
  bool rect = false;
  std::string text;

  UI(const GameContext& game_ctx, std::shared_ptr<GFX::Font> font);

  void update() const;
  void draw() const;

private:
  std::unique_ptr<GFX::TextComponent> _component;
  std::shared_ptr<GFX::Font> _font;
};

}
