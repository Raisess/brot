#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx) 
  : texture_component(std::make_shared<GFX::TextureComponent>(*game_ctx.render_ctx)) {}

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

  if (_animations.size()) {
    if (_animation_index != _last_animation_index) {
      _animations[_last_animation_index].restart();
    }

    _animations[_animation_index].animate(texture_component);
  }
}

void Engine::Entity::draw() const {
  if (hide) return;

  texture_component->draw();
}

void Engine::Entity::create_animation(const std::string& id, const std::vector<std::shared_ptr<Sprite>>& sprites) {
  _animations[id] = Animation();

  for (auto sprite : sprites) {
    _animations[id].push_sprite(sprite);
  }
}

void Engine::Entity::use_animation(const std::string& id) {
  _animation_index = id;
}
