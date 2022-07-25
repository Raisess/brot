#pragma once

#include <memory>
#include "../gfx/Text.h"
#include "../gfx/TextComponent.h"
#include "Game.h"
#include "_Node.h"

namespace Engine {

class UI : public Node {
public:
  std::string text;

  UI(const GameContext& game_ctx, const std::string& id, std::shared_ptr<GFX::Font> font);

  void update(int delta_time) final override;
  void draw() const final override;

private:
  std::unique_ptr<GFX::TextComponent> _component;
  std::shared_ptr<GFX::Font> _font;
  unsigned int _time_count = 0;
};

}
