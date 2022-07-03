#include "../common/Logger.h"
#include "Component.h"

GFX::Component::Component(const Common::Size& size, const Common::Pos& position)
  : size(size), position(position) {
}

void GFX::Component::draw(const Renderer& renderer, bool fill) {
  rect.w = (int) size.width;
  rect.h = (int) size.height;
  rect.x = position.x;
  rect.y = position.y;

  SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
  SDL_RenderDrawRect(renderer.get(), &rect);

  if (fill) {
    SDL_RenderFillRect(renderer.get(), &rect);
  }

  SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 255);
  SDL_RenderPresent(renderer.get());
}
