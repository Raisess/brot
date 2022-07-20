#pragma once

#include "Component.h"

namespace GFX {

class TextComponent : public Component {
public:
  TextComponent(const Renderer& renderer) : Component(renderer) {}

  void bind(const Font& font, const std::string& str) {
    text = std::make_unique<Text>(renderer, font, str, _color);
  }
};

}
