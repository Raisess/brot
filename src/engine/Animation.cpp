#include "Animation.h"

void Engine::Animation::push_sprite(std::shared_ptr<GFX::Image> sprite) {
  _sprites.push_back(sprite);
}

void Engine::Animation::animate(int timestep, std::shared_ptr<GFX::TextureComponent> texture_component) {
  if (_sprites.size()) {
    texture_component->bind(*_sprites[_sprite_count]);
    _time_count += timestep;

    if (_time_count >= SPRITE_DELAY) {
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
