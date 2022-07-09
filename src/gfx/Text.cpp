#include "Text.h"

GFX::Text::Text(const Renderer& renderer, const std::string& font_path, const std::string& text, const Common::Color& color) {
  TTF_Init();
  font = TTF_OpenFont(font_path.c_str(), FONT_POINT_SIZE);
  SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), {
    (Uint8) color.red,
    (Uint8) color.green,
    (Uint8) color.blue,
    (Uint8) color.alpha,
  });
  sdl_value = SDL_CreateTextureFromSurface(renderer.get(), surface);
  SDL_FreeSurface(surface);
}

GFX::Text::~Text() {
  TTF_CloseFont(font);
  SDL_DestroyTexture(sdl_value);
  TTF_Quit();
}
