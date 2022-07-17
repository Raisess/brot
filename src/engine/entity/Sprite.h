#pragma once

#include <iostream>
#include <memory>
#include "../../gfx/Texture.h"

namespace Engine {

class Sprite {
public:
  Sprite(const std::string& img_path, unsigned int delay = 0);

  std::shared_ptr<GFX::Image> image() const;

private:
  std::shared_ptr<GFX::Image> _image;
  unsigned int _delay;
};

}
