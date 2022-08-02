#include <assert.h>
#include "../util/Time.h"
#include "Animation.h"

Engine::Animation::Animation(const std::vector<std::shared_ptr<GFX::Image>>& sprites) {
  _sprites = sprites;
}

const int Engine::Animation::count_spites() const {
  return _sprites.size();
}

void Engine::Animation::push_sprite(const std::shared_ptr<GFX::Image>& sprite) {
  _sprites.push_back(sprite);
}

void Engine::Animation::push_sprites(const std::vector<std::shared_ptr<GFX::Image>>& sprites) {
  assert(count_spites() == 0);
  _sprites = sprites;
}

void Engine::Animation::animate(int timestep, const std::shared_ptr<GFX::TextureComponent>& texture_component) {
  if (_sprites.size()) {
    texture_component->bind(*_sprites[_sprite_count]);

    if (Util::Time::Wait(SPRITE_DELAY, timestep, _time_count)) {
      _sprite_count++;
      _time_count = 0;
    }
    if (_sprite_count == _sprites.size()) {
      _sprite_count = 0;
    }
  }
}

void Engine::Animation::restart() {
  _sprite_count = 0;
  _time_count = 0;
}
