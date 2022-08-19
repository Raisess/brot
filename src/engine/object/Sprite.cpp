#include "Sprite.h"

Engine::Sprite::Sprite(const std::string& path, int timesteps)
  : path(path), timesteps(timesteps), _image(std::make_unique<GFX::Image>(path)) {}

std::shared_ptr<Engine::Sprite> Engine::Sprite::Create(const std::string& path, int timesteps) {
  return std::make_shared<Engine::Sprite>(path, timesteps);
}
