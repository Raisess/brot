#include "SpriteAnimationManager.h"

namespace Engine {

Manager::AnimationManager::AnimationManager(Entity& entity, const std::unordered_map<std::string, SpriteAnimation>& animations)
  : _entity(entity), _animations(animations) {}

void Manager::AnimationManager::play(int delta_time, const std::string& animation_id) {
  if (animation_id != _last_animation_id) {
    _last_animation_id = animation_id;
    _animations[_last_animation_id].restart();
  }

  _animations[animation_id].play(delta_time, _entity);
}

}
