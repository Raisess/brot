#pragma once

#include <memory>
#include "../../gfx/TextureComponent.h"
#include "../../_Sharable.h"
#include "../core/Game.h"
#include "_Node.h"
#include "Sprite.h"

namespace Engine {

class Entity
  : public Node,
    public Sharable<Entity, const GameContext&, const std::string&, const std::shared_ptr<Sprite>&> {
public:
  Entity(const GameContext& game_ctx, const std::string& id, const std::shared_ptr<Sprite>& sprite);
  ~Entity();

  void update(int delta_time) final override;
  void draw() final override;
  void set_sprite(const std::shared_ptr<Sprite>& sprite);

private:
  std::unique_ptr<GFX::TextureComponent> _component;
  std::shared_ptr<Sprite> _sprite;
  std::string _animation_index;
  std::string _last_animation_index;
};

}
