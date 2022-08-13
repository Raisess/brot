#include <assert.h>
#include "../util/Logger.h"
#include "./Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx, const std::string& id, const std::shared_ptr<GFX::Image>& sprite)
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
  _component->set_position(position + offset);
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

void Engine::Entity::draw() {
  if (hide) return;

  _component->draw();
}

void Engine::Entity::create_animation(const std::string& id, const Animation& animation) {
  assert(animation.count_spites() > 0);
  _animations[id] = animation;
}

void Engine::Entity::create_animation(const std::string& id, const std::vector<std::shared_ptr<GFX::Image>>& sprites) {
  _animations[id] = Animation(sprites);
}

void Engine::Entity::use_animation(const std::string& id) {
  _animation_index = id;
}

void Engine::Entity::resume_animation(const std::string& id) {
  _animations[id].resume();
}

void Engine::Entity::pause_animation(const std::string& id) {
  _animations[id].pause();
}

const bool Engine::Entity::is_paused_animation(const std::string& id) {
  return _animations[id].is_paused();
}
