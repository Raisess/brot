#pragma once

#include <memory>
#include "../gfx/TextureComponent.h"
#include "../_Sharable.h"
#include "Game.h"
#include "_Node.h"

namespace Engine {

class Entity
  : public Node,
    public Sharable<Entity, const GameContext&, const std::string&, const std::shared_ptr<GFX::Image>&> {
public:
  Entity(const GameContext& game_ctx, const std::string& id, const std::shared_ptr<GFX::Image>& sprite);
  ~Entity();

  void update(int delta_time) final override;
  void draw() final override;
  void set_sprite(const std::shared_ptr<GFX::Image>& sprite);

private:
  std::shared_ptr<GFX::TextureComponent> _component;
  std::shared_ptr<GFX::Image> _sprite;
  std::string _animation_index;
  std::string _last_animation_index;
};

}
