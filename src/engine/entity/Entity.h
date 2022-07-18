#pragma once

#include <array>
#include <memory>
#include <vector>
#include "../../common/Color.h"
#include "../../common/Size.h"
#include "../../common/Vec2.h"
#include "../../gfx/Component.h"
#include "../Game.h"
#include "Sprite.h"

namespace Engine {

class Entity {
public:
  // TODO: handle more than 3 spritesheets
  std::array<std::vector<std::shared_ptr<Sprite>>, 3> spritesheets;
  size_t spritesheet_index = 0;
  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  int angle = 0;
  bool fill = false;
  bool flip = false;

  Entity(const GameContext& game_ctx);

  void update();
  void draw() const;
  void hide();
  void unhide();

private:
  std::unique_ptr<GFX::Component> gfx_component;
  size_t _last_spritesheet_index = 0;
  size_t _sprite_count = 0;
  bool _hidden = false;
};

}
