#include "../common/Logger.h"
#include "Texture.h"

GFX::Texture::Texture(const Renderer& renderer, const std::string& img_path) {
  sdl_value = IMG_LoadTexture(renderer.get(), img_path.c_str());

  if (sdl_value == nullptr) {
    Common::Logger::error("Error loading image at: " + img_path);
  }
}

GFX::Texture::~Texture() {
  SDL_DestroyTexture(sdl_value);
}
