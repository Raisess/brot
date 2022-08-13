#pragma once

#include <memory>
#include "../gfx/Text.h"
#include "../gfx/TextComponent.h"
#include "../_Sharable.h"
#include "Game.h"
#include "_Node.h"

namespace Engine {

class UI
  : public Node,
    public Sharable<UI, const GameContext&, const std::string&, const std::shared_ptr<GFX::Font>&> {
public:
  std::string text;

  UI(const GameContext& game_ctx, const std::string& id, const std::shared_ptr<GFX::Font>& font);
  ~UI();

  void update(int delta_time) final override;
  void draw() final override;

private:
  std::unique_ptr<GFX::TextComponent> _component;
  std::shared_ptr<GFX::Font> _font;
  unsigned int _time_count = 0;
};

}
