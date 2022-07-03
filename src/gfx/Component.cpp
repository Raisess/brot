#include "../common/Logger.h"
#include "Component.h"

GFX::Component::Component(const Common::Size& size, const Common::Pos& position)
  : size(size), position(position) {
}

void GFX::Component::draw(const Renderer& renderer, bool fill) {
  sdl_value.w = (int) size.width;
  sdl_value.h = (int) size.height;
  sdl_value.x = position.x;
  sdl_value.y = position.y;

  SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer.get(), &sdl_value);

  if (fill) {
    SDL_RenderFillRect(renderer.get(), &sdl_value);
  }

  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
  SDL_RenderPresent(renderer.get());
}
