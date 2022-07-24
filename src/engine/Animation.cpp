#include "../util/Time.h"
#include "Animation.h"

void Engine::Animation::push_sprite(std::shared_ptr<GFX::Image> sprite) {
  _sprites.push_back(sprite);
}

void Engine::Animation::animate(std::shared_ptr<GFX::TextureComponent> texture_component) {
  if (_sprites.size()) {
    if (WAIT_DELAY) {
      Util::Time::delay(SPRITE_DELAY);
    }

    texture_component->bind(*_sprites[_sprite_count]);

    _sprite_count += 1;
    if (_sprite_count == _sprites.size()) {
      _sprite_count = 0;
    }
  }
}

void Engine::Animation::restart() {
  _sprite_count = 0;
}
