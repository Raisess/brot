#pragma once

#include <map>
#include <memory>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"
#include "../gfx/TextureComponent.h"
#include "entity/Animation.h"
#include "Game.h"

namespace Engine {

class Entity {
public:
  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  int angle = 0;
  bool hide = false;
  bool fill = false;
  bool flip = false;
  bool rect = false;

  Entity(const GameContext& game_ctx, const std::string& id);
  ~Entity();

  void update();
  void draw() const;
  void create_animation(const std::string& id, const std::vector<std::shared_ptr<Sprite>>& sprites);
  void use_animation(const std::string& id);
  const std::string id() const;

private:
  std::shared_ptr<GFX::TextureComponent> texture_component;
  std::map<std::string, Animation> _animations;
  std::string _id;
  std::string _animation_index;
  std::string _last_animation_index;
};

}
