#pragma once

#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "../common/Color.h"
#include "../_Sharable.h"
#include "Renderer.h"
#include "../SDLController.h"

#define FONT_POINT_SIZE 25

namespace GFX {

class Font
  : public SDLController<TTF_Font*>,
    public Sharable<Font, const std::string&> {
public:
  Font(const std::string& path, unsigned int point_size = FONT_POINT_SIZE);
  ~Font();
};

class Text : public SDLController<SDL_Texture*> {
public:
  Text(const Renderer& renderer, const Font& font, const std::string& text, const Common::Color& color);
  ~Text();

  static void Init();
  static void Close();
};

}
