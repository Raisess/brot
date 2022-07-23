#pragma once

#include <memory>
#include <vector>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"
#include "../gfx/TextureComponent.h"
#include "entity/Animation.h"
#include "Game.h"

namespace Engine {

class Entity {
public:
  std::vector<Animation> animations;
  size_t animation_index = 0;
  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  int angle = 0;
  bool hide = false;
  bool fill = false;
  bool flip = false;
  bool rect = false;

  Entity(const GameContext& game_ctx);

  void update();
  void draw() const;

private:
  std::shared_ptr<GFX::TextureComponent> texture_component;
  size_t _last_animation_index = 0;
};

}
