#include "../util/Logger.h"
#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx, const std::string& id) 
  : _id(id), _component(std::make_shared<GFX::TextureComponent>(*game_ctx.render_ctx)) {
  Util::Logger::Debug("Create Entity: " + id);
}

Engine::Entity::~Entity() {
  Util::Logger::Debug("Delete Entity");
}

void Engine::Entity::update(int delta_time) {
  _component->set_angle(angle);
  _component->set_position(position);
  _component->set_size(size);
  _component->set_color(color);

  if (fill) {
    _component->fill();
  } else {
    _component->unfill();
  }

  if (flip) {
    _component->flip();
  } else {
    _component->unflip();
  }

  if (rect) {
    _component->rect();
  } else {
    _component->unrect();
  }

  if (_animations.size()) {
    if (_animation_index != _last_animation_index) {
      _animations[_last_animation_index].restart();
    }

    _animations[_animation_index].animate(delta_time, _component);
  }
}

void Engine::Entity::draw() const {
  if (hide) return;

  _component->draw();
}

void Engine::Entity::create_animation(const std::string& id, const std::vector<std::shared_ptr<GFX::Image>>& sprites) {
  _animations[id] = Animation();

  for (auto sprite : sprites) {
    _animations[id].push_sprite(sprite);
  }
}

void Engine::Entity::use_animation(const std::string& id) {
  _animation_index = id;
}

const std::string Engine::Entity::id() const {
  return _id;
}
