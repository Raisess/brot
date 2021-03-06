#include "Animation.h"

void Engine::Animation::push_sprite(std::shared_ptr<Sprite> sprite) {
  _sprites.push_back(sprite);
}

void Engine::Animation::animate(std::shared_ptr<GFX::TextureComponent> texture_component) {
  if (_sprites.size()) {
    texture_component->bind(*_sprites[_sprite_count]->image());

    _sprite_count += 1;
    if (_sprite_count == _sprites.size()) {
      _sprite_count = 0;
    }
  }
}

void Engine::Animation::restart() {
  _sprite_count = 0;
}
