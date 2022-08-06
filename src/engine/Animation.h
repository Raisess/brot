#pragma once

#include <memory>
#include <vector>
#include "../gfx/TextureComponent.h"
#include "../_Sharable.h"

#define SPRITE_DELAY 100

namespace Engine {

class Animation {
public:
  Animation() {}
  Animation(const std::vector<std::shared_ptr<GFX::Image>>& sprites);

  const int count_spites() const;
  void animate(int delta_time, const std::shared_ptr<GFX::TextureComponent>& texture_component);
  void restart();
  void resume();
  void pause();
  const bool is_paused() const;

private:
  std::vector<std::shared_ptr<GFX::Image>> _sprites;
  unsigned int _time_count = 0;
  size_t _sprite_count = 0;
  bool _paused = false;
};

}
