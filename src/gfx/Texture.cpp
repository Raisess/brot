#include "../util/Logger.h"
#include "Texture.h"

GFX::Image::Image(const std::string& path) {
  Util::Logger::debug("Create Image: " + path);
  sdl_value = IMG_Load(path.c_str());
  if (sdl_value == nullptr) {
    Util::Logger::error("Error loading image at: " + path);
    exit(1);
  }
}

GFX::Image::~Image() {
  SDL_FreeSurface(sdl_value);
  Util::Logger::debug("Delete Image");
}

GFX::Texture::Texture(const Renderer& renderer, const Image& image) {
  sdl_value = SDL_CreateTextureFromSurface(renderer.get(), image.get());
}

GFX::Texture::~Texture() {
  SDL_DestroyTexture(sdl_value);
}
