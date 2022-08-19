#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "../../gfx/Texture.h"
#include "../../_Sharable.h"

namespace Engine {

class Sprite : public Sharable<Sprite, const std::string&>{
public:
  const std::string path;

  Sprite(const std::string& path);

  const GFX::Image& image() const {
    return *_image;
  }

private:
  std::unique_ptr<GFX::Image> _image;
};

}
