#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "../gfx/TextureComponent.h"

#define SPRITE_DELAY 50

namespace Engine {

class Animation {
public:
  void push_sprite(std::shared_ptr<GFX::Image> sprite);
  void animate(std::shared_ptr<GFX::TextureComponent> texture_component);
  void restart();

private:
  std::vector<std::shared_ptr<GFX::Image>> _sprites;
  size_t _sprite_count = 0;
};

}
