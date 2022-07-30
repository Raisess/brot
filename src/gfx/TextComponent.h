#pragma once

#include "../util/Logger.h"
#include "_Component.h"
#include "Text.h"

namespace GFX {

class TextComponent : public Component {
public:
  TextComponent(const Renderer& renderer) : Component(renderer) {
    Util::Logger::Debug("Create TextComponent");
  }
  ~TextComponent() {
    Util::Logger::Debug("Delete TextComponent");
  }

  void bind(const Font& font, const std::string& str) {
    text = std::make_unique<Text>(renderer, font, str, _color);
  }

  void draw() final override {
    draw_rect();

    if (text != nullptr || !_rect) {
      SDL_RenderCopyEx(renderer.get(), text->get(), nullptr, &sdl_value, _angle, nullptr, _flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    } else {
      SDL_RenderCopy(renderer.get(), nullptr, nullptr, &sdl_value);
    }
  }

private:
  std::unique_ptr<Text> text;
};

}
