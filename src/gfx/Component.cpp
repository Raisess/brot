#include "../common/Logger.h"
#include "Component.h"

GFX::Component::Component(const Renderer& renderer)
  : renderer(renderer), size({ 0, 0 }), position({ 0, 0 }) {}

void GFX::Component::draw(const bool& fill) {
  sdl_value.rect.w = (int) size.width;
  sdl_value.rect.h = (int) size.height;
  sdl_value.rect.x = position.x;
  sdl_value.rect.y = position.y;

  SDL_SetRenderDrawColor(renderer.get(), color.red, color.green, color.blue, color.alpha);

  if (fill) {
    SDL_RenderFillRect(renderer.get(), &sdl_value.rect);
  } else {
    SDL_RenderDrawRect(renderer.get(), &sdl_value.rect);
  }
}
