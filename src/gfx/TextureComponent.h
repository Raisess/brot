#pragma once

#include "../util/Logger.h"
#include "_Component.h"
#include "Texture.h"

namespace GFX {

class TextureComponent : public Component {
public:
  TextureComponent(const Renderer& renderer) : Component(renderer) {
    Util::Logger::Debug("Create TextureComponent");
  }
  ~TextureComponent() {
    Util::Logger::Debug("Delete TextureComponent");
  }

  void bind(const Image& image) {
    texture = std::make_unique<Texture>(renderer, image);
  }

  void draw() final override {
    draw_rect();

    if (texture != nullptr) {
      SDL_RenderCopyEx(renderer.get(), texture->get(), nullptr, &sdl_value, _angle, nullptr, _flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    } else {
      SDL_RenderCopy(renderer.get(), nullptr, nullptr, &sdl_value);
    }
  }

private:
  std::unique_ptr<Texture> texture = nullptr;
};

}
