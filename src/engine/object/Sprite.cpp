#include "Sprite.h"

Engine::Sprite::Sprite(const std::string& path)
  : path(path), _image(std::make_unique<GFX::Image>(path)) {}
