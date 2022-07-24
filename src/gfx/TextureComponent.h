#pragma once

#include "../util/Logger.h"
#include "Component.h"

namespace GFX {

class TextureComponent : public Component {
public:
  TextureComponent(const Renderer& renderer) : Component(renderer) {
    Util::Logger::debug("Create TextureComponent");
  }
  ~TextureComponent() {
    Util::Logger::debug("Delete TextureComponent");
  }

  void bind(const Image& image) {
    texture = std::make_unique<Texture>(renderer, image);
  }
};

}
