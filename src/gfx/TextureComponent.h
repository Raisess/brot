#pragma once

#include "Component.h"

namespace GFX {

class TextureComponent : public Component {
public:
  TextureComponent(const Renderer& renderer) : Component(renderer) {}

  void bind(const Image& image) {
    texture = std::make_unique<Texture>(renderer, image);
  }
};

}
