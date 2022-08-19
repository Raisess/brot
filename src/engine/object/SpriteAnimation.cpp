#include <cassert>
#include "../../util/Time.h"
#include "SpriteAnimation.h"

Engine::SpriteAnimation::SpriteAnimation(const std::vector<SpriteStruct>& sprites)
  : _sprites(sprites) {
  assert(sprites.size() > 0);
}

void Engine::SpriteAnimation::play(int delta_time, Entity& entity) {
  if (_last_index == 0 || _index != _last_index) {
    entity.set_sprite(_sprites[_index].sprite);
  }

  if (Util::Time::Wait(_sprites[_index].timesteps, delta_time, _time_count)) {
    _time_count = 0;
    _last_index = _index;
    _index++;
  }
  if (_index == _sprites.size()) restart();
}

void Engine::SpriteAnimation::restart() {
  _time_count = 0;
  _last_index = 0;
  _index = 0;
}

bool Engine::SpriteAnimation::finished() {
  return _index == _sprites.size();
}
