#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx) 
  : gfx_component(std::make_unique<GFX::Component>(*game_ctx.render_ctx)) {}

void Engine::Entity::update() {
  gfx_component->set_angle(angle);
  gfx_component->set_position(position);
  gfx_component->set_size(size);
  gfx_component->set_color(color);

  if (fill) {
    gfx_component->fill();
  } else {
    gfx_component->unfill();
  }

  if (flip) {
    gfx_component->flip();
  } else {
    gfx_component->unflip();
  }

  if (spritesheet_index != _last_spritesheet_index) {
    _sprite_count = 0;
  }

  if (spritesheets[spritesheet_index].size()) {
    gfx_component->bind_texture(*spritesheets[spritesheet_index][_sprite_count]->image());

    _sprite_count += 1;
    if (_sprite_count == spritesheets[spritesheet_index].size()) {
      _sprite_count = 0;
    }
  }

  _last_spritesheet_index = spritesheet_index;
}

void Engine::Entity::draw() const {
  if (hide) return;

  gfx_component->draw();
}
