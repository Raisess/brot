#pragma once

#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "../common/Color.h"
#include "Renderer.h"
#include "SDLController.h"

#define FONT_POINT_SIZE 25

namespace GFX {

class Text : public SDLController<SDL_Texture*> {
public:
  Text(const Renderer& renderer, const std::string& font_path, const std::string& text, const Common::Color& color);
  ~Text();

  static void Init();
  static void Close();

private:
  TTF_Font* font;
};

}
