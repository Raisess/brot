#include "../common/Logger.h"
#include "Renderer.h"

GFX::Renderer::Renderer(const Window& window) {
  renderer = SDL_CreateRenderer(window.get(), -1, 0);
  if (renderer == nullptr) {
    Common::Logger::error("Error creating the renderer " + std::string(SDL_GetError()));
  }
}

GFX::Renderer::~Renderer() {
  Common::Logger::debug("Destroying renderer...");
  SDL_DestroyRenderer(renderer);
  Common::Logger::debug("Renderer destroyed.");
}

void GFX::Renderer::clear() const {
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, nullptr, nullptr, nullptr);
  SDL_RenderPresent(renderer);
}
