#include "Component.h"

GFX::Component::Component(const Renderer& renderer)
  : renderer(renderer), size({ 0, 0 }), position({ 0, 0 }) {}

void GFX::Component::attach_texture(const std::string& img_path) {
  texture = std::make_unique<Texture>(renderer, img_path);
}

void GFX::Component::draw(const bool& fill) {
  sdl_value.w = (int) size.width;
  sdl_value.h = (int) size.height;
  sdl_value.x = position.x;
  sdl_value.y = position.y;

  SDL_SetRenderDrawColor(renderer.get(), color.red, color.green, color.blue, color.alpha);

  if (fill) {
    SDL_RenderFillRect(renderer.get(), &sdl_value);
  } else {
    SDL_RenderDrawRect(renderer.get(), &sdl_value);
  }

  if (texture != nullptr) {
    SDL_RenderCopy(renderer.get(), texture->get(), nullptr, &sdl_value);
  } else {
    SDL_RenderCopy(renderer.get(), nullptr, nullptr, &sdl_value);
  }
}
