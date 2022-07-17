#pragma once

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
  std::vector<std::shared_ptr<Sprite>> sprites;
  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  int angle = 0;
  bool fill = false;

  Entity(const GameContext& game_ctx);

  void update() const;
  void draw() const;
  void hide();
  void unhide();

private:
  std::unique_ptr<GFX::Component> gfx_component;
  bool _hidden = false;
};

}
