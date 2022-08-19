#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "../../gfx/Texture.h"
#include "Entity.h"

namespace Engine {

class SpriteAnimation {
public:
  SpriteAnimation() {}
  SpriteAnimation(const std::vector<std::shared_ptr<GFX::Image>>& sprites);

  void play(int delta_time, Entity& entity);
  void restart();
  bool finished();

private:
  std::vector<std::shared_ptr<GFX::Image>> _sprites;
  unsigned int _time_count = 0;
  unsigned int _last_index = 0;
  unsigned int _index = 0;
};

}
