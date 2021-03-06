#pragma once

#include "../util/Logger.h"
#include "Component.h"

namespace GFX {

class TextComponent : public Component {
public:
  TextComponent(const Renderer& renderer) : Component(renderer) {
    Util::Logger::debug("Create TextComponent");
  }
  ~TextComponent() {
    Util::Logger::debug("Delete TextComponent");
  }

  void bind(const Font& font, const std::string& str) {
    text = std::make_unique<Text>(renderer, font, str, _color);
  }
};

}
