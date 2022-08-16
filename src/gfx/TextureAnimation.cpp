#include <cassert>
#include "../util/Time.h"
#include "TextureAnimation.h"

#define SPRITE_DELAY 200

GFX::TextureAnimation::TextureAnimation(const std::vector<std::shared_ptr<GFX::Image>>& images) : _images(images) {
  assert(images.size() > 0);
}

void GFX::TextureAnimation::play(int timestep, GFX::TextureComponent& texture_component) {
  if (_images.size() && !_paused) {
    texture_component.bind(*_images[_index]);

    if (Util::Time::Wait(SPRITE_DELAY, timestep, _time_count)) {
      _index++;
      _time_count = 0;
    }
    if (_index == _images.size()) restart();
  }
}

void GFX::TextureAnimation::restart() {
  _index = 0;
  _time_count = 0;
}
