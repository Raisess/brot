#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx) 
  : texture_component(std::make_unique<GFX::TextureComponent>(*game_ctx.render_ctx)) {}

void Engine::Entity::update() {
  texture_component->set_angle(angle);
  texture_component->set_position(position);
  texture_component->set_size(size);
  texture_component->set_color(color);

  if (fill) {
    texture_component->fill();
  } else {
    texture_component->unfill();
  }

  if (flip) {
    texture_component->flip();
  } else {
    texture_component->unflip();
  }

  if (rect) {
    texture_component->rect();
  } else {
    texture_component->unrect();
  }

  if (spritesheet_index != _last_spritesheet_index) {
    _sprite_count = 0;
  }

  if (spritesheets[spritesheet_index].size()) {
    texture_component->bind(*spritesheets[spritesheet_index][_sprite_count]->image());

    _sprite_count += 1;
    if (_sprite_count == spritesheets[spritesheet_index].size()) {
      _sprite_count = 0;
    }
  }

  _last_spritesheet_index = spritesheet_index;
}

void Engine::Entity::draw() const {
  if (hide) return;

  texture_component->draw();
}
