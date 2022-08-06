#include <assert.h>
#include "../util/Time.h"
#include "Animation.h"

Engine::Animation::Animation(const std::vector<std::shared_ptr<GFX::Image>>& sprites) : _sprites(sprites) {}

const int Engine::Animation::count_spites() const {
  return _sprites.size();
}

void Engine::Animation::animate(int timestep, const std::shared_ptr<GFX::TextureComponent>& texture_component) {
  if (_sprites.size() && !_paused) {
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

void Engine::Animation::resume() {
  _paused = false;
}

void Engine::Animation::pause() {
  _paused = true;
}

const bool Engine::Animation::is_paused() const {
  return _paused;
}
