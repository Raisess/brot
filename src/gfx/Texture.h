#pragma once

#include <SDL2/SDL_image.h>
#include "Renderer.h"
#include "SDLController.h"

namespace GFX {

class Texture : public SDLController<SDL_Texture*> {
public:
  Texture(const Renderer& renderer, const std::string& img_path);
  ~Texture();
};

}
