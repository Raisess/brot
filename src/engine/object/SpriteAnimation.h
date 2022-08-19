#pragma once

#include "Sprite.h"
#include "Entity.h"

namespace Engine {

class SpriteAnimation {
public:
  SpriteAnimation() {}
  SpriteAnimation(const std::vector<std::shared_ptr<Sprite>>& sprites);

  void play(int delta_time, Entity& entity);
  void restart();
  bool finished();

private:
  std::vector<std::shared_ptr<Sprite>> _sprites;
  unsigned int _time_count = 0;
  unsigned int _last_index = 0;
  unsigned int _index = 0;
};

}
