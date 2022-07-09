#pragma once

#include <iostream>
#include <SDL2/SDL_image.h>
#include "Renderer.h"
#include "SDLController.h"

namespace GFX {

class Image : public SDLController<SDL_Surface*> {
public:
  Image(const std::string& path);
  ~Image();
};

class Texture : public SDLController<SDL_Texture*> {
public:
  Texture(const Renderer& renderer, const Image& image);
  ~Texture();
};

}
