#include "../util/Logger.h"
#include "Renderer.h"

GFX::Renderer::Renderer(const Window& window) {
  sdl_value = SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (sdl_value == nullptr) {
    Util::Logger::error("Error creating renderer " + std::string(SDL_GetError()));
    exit(1);
  }

  clear();
}

GFX::Renderer::~Renderer() {
  SDL_DestroyRenderer(sdl_value);
}

void GFX::Renderer::draw() const {
  SDL_SetRenderDrawColor(sdl_value, 0, 0, 0, 255);
  SDL_RenderDrawRect(sdl_value, nullptr);
  SDL_RenderPresent(sdl_value);
}

void GFX::Renderer::clear() const {
  SDL_RenderClear(sdl_value);
}
