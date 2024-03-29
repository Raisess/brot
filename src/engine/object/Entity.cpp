#include "../../util/Logger.h"
#include "Entity.h"

Engine::Entity::Entity(const Engine::GameContext& game_ctx, const std::string& id)
  : Node(id),
    _component(std::make_unique<GFX::TextureComponent>(*game_ctx.renderer)) {
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
  on_update(delta_time);
}

void Engine::Entity::set_sprite(const Sprite& sprite) {
  _component->bind(sprite.image());
}

void Engine::Entity::draw() {
  if (hide) return;
  _component->draw();
  on_draw();
}
