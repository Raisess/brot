#pragma once

#include <unordered_map>
#include "../object/Entity.h"
#include "../object/SpriteAnimation.h"

namespace Engine {
namespace Manager {

class SpriteAnimationManager {
public:
  SpriteAnimationManager(Entity& entity, const std::unordered_map<std::string, SpriteAnimation>&);

  void play(int delta_time, const std::string& animation_id);

private:
  Entity& _entity;
  std::unordered_map<std::string, SpriteAnimation> _animations;
  std::string _last_animation_id;
};

}
}
