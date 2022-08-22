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
    public Sharable<Entity, const GameContext&, const std::string&> {
public:
  Entity(const GameContext& game_ctx, const std::string& id);
  ~Entity();

  virtual void on_update(int delta_time) {};
  virtual void on_draw() {};

  void update(int delta_time) final override;
  void draw() final override;
  void set_sprite(const Sprite& sprite);

private:
  std::unique_ptr<GFX::TextureComponent> _component;
};

}
