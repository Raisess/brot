#pragma once

#include <iostream>
#include <memory>
#include "../../gfx/Texture.h"

#define SPRITE_DELAY 50

namespace Engine {

class Sprite {
public:
  Sprite(const std::string& img_path);

  std::shared_ptr<GFX::Image> image() const;
  const std::string path() const;

private:
  std::shared_ptr<GFX::Image> _image;
  std::string _path;
};

}
