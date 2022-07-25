#include "../util/Logger.h"
#include "Text.h"

GFX::Font::Font(const std::string& path, unsigned int point_size) {
  Util::Logger::Debug("Create Font: " + path);

  sdl_value = TTF_OpenFont(path.c_str(), point_size);
  if (sdl_value == nullptr) {
    Util::Logger::Error("Error loading font at: " + path);
    exit(1);
  }
}

GFX::Font::~Font() {
  TTF_CloseFont(sdl_value);
  Util::Logger::Debug("Delete Font");
}

GFX::Text::Text(const Renderer& renderer, const Font& font, const std::string& text, const Common::Color& color) {
  SDL_Surface* surface = TTF_RenderText_Solid(font.get(), text.c_str(), {
    (Uint8) color.red,
    (Uint8) color.green,
    (Uint8) color.blue,
    (Uint8) color.alpha,
  });
  sdl_value = SDL_CreateTextureFromSurface(renderer.get(), surface);
  SDL_FreeSurface(surface);
}

GFX::Text::~Text() {
  SDL_DestroyTexture(sdl_value);
}

void GFX::Text::Init() {
  TTF_Init();
}

void GFX::Text::Close() {
  TTF_Quit();
}
