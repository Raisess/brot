#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx) 
  : gfx_component(std::make_unique<GFX::Component>(*game_ctx.render_ctx)) {}

void Engine::Entity::update() const {
  gfx_component->set_angle(angle);
  gfx_component->set_position(position);
  gfx_component->set_size(size);
  gfx_component->set_color(color);

  for (auto sprite : sprites) {
    gfx_component->bind_texture(*sprite->image());
  }
}

void Engine::Entity::draw() const {
  if (_hidden) return;

  if (fill) {
    gfx_component->fill();
  } else {
    gfx_component->unfill();
  }

  gfx_component->draw();
}

void Engine::Entity::hide() {
  _hidden = true;
}

void Engine::Entity::unhide() {
  _hidden = false;
}
