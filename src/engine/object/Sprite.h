#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "../../gfx/Texture.h"

namespace Engine {

class Sprite {
#define SPRITE_DELAY 200
public:
  const std::string path;
  const int timesteps;

  Sprite(const std::string& path, int timesteps);
  static std::shared_ptr<Sprite> Create(const std::string& path, int timesteps = SPRITE_DELAY);

  const GFX::Image& image() const {
    return *_image;
  }

private:
  std::unique_ptr<GFX::Image> _image;
};

}
