#include "../util/Logger.h"
#include "Text.h"
#include "Renderer.h"

GFX::Renderer::Renderer(const Window& window) {
  Util::Logger::Debug("Create Renderer");

  sdl_value = SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
  if (sdl_value == nullptr) {
    Util::Logger::Error("Error creating renderer: " + std::string(SDL_GetError()));
    exit(1);
  }

  const auto window_size = window.get_size();
  SDL_RenderSetLogicalSize(sdl_value, window_size.width, window_size.height);

  const int blend_mode_code = SDL_SetRenderDrawBlendMode(sdl_value, SDL_BLENDMODE_BLEND);
  if (blend_mode_code < 0) {
    Util::Logger::Error("Error enabling bled mode: " + std::string(SDL_GetError()));
  }

  clear();
  Text::Init();
}

GFX::Renderer::~Renderer() {
  Text::Close();
  SDL_DestroyRenderer(sdl_value);
  Util::Logger::Debug("Delete Renderer");
}

void GFX::Renderer::draw() const {
  SDL_SetRenderDrawColor(sdl_value, 0, 0, 0, 255);
  SDL_RenderDrawRect(sdl_value, nullptr);
  SDL_RenderPresent(sdl_value);
}

void GFX::Renderer::clear() const {
  SDL_RenderClear(sdl_value);
}
