#pragma once

#include <map>
#include <memory>
#include "../gfx/TextureComponent.h"
#include "Animation.h"
#include "Game.h"
#include "_Node.h"

namespace Engine {

class Entity : public Node {
public:
  Entity(const GameContext& game_ctx, const std::string& id);
  ~Entity();

  void update(int delta_time) final override;
  void draw() const final override;
  void create_animation(const std::string& id, const std::vector<std::shared_ptr<GFX::Image>>& sprites);
  void use_animation(const std::string& id);

private:
  std::shared_ptr<GFX::TextureComponent> _component;
  std::map<std::string, Animation> _animations;
  std::string _animation_index;
  std::string _last_animation_index;
};

}
