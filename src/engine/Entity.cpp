#include <assert.h>
#include "../util/Logger.h"
#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx, const std::string& id, const Shared<GFX::Image>& sprite)
  : Node(id, Node::Type::ENTITY),
    _component(std::make_shared<GFX::TextureComponent>(*game_ctx.render_ctx)),
    _sprite(sprite) {
  Util::Logger::Debug("Create Entity: " + _id);
}

Engine::Entity::~Entity() {
  Util::Logger::Debug("Delete Entity: " + _id);
}

void Engine::Entity::update(int delta_time) {
  _component->set_angle(angle);
  _component->set_position(position);
  _component->set_size(size);
  _component->set_color(color);
  _component->set_fill(fill);
  _component->set_flip(flip);
  _component->set_rect(rect);

  if (_animations.size() && _animation_index != "") {
    if (_animation_index != _last_animation_index) {
      _animations[_last_animation_index].restart();
    }

    _animations[_animation_index].animate(delta_time, _component);
  } else if (_sprite != nullptr) {
    _component->bind(*_sprite);
  }
}

void Engine::Entity::draw() const {
  if (hide) return;

  _component->draw();
}

void Engine::Entity::create_animation(const std::string& id, const Animation& animation) {
  assert(animation.count_spites() > 0);
  _animations[id] = animation;
}

void Engine::Entity::create_animation(const std::string& id, const std::vector<Shared<GFX::Image>>& sprites) {
  _animations[id] = Animation();
  _animations[id].push_sprites(sprites);
}

void Engine::Entity::use_animation(const std::string& id) {
  _animation_index = id;
}
