#include "../common/Logger.h"
#include "Component.h"

GFX::Component::Component() : size({ 0, 0 }), position({ 0, 0 }) {}

void GFX::Component::draw(const Renderer& renderer, const bool& fill) {
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

  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
  SDL_RenderPresent(renderer.get());
}
