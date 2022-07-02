#pragma once

#include <SDL2/SDL.h>
#include "Window.h"

namespace GFX {

class Renderer {
public:
  Renderer(const Window& window);
  ~Renderer();

  SDL_Renderer* get() const {
    return renderer;
  }

  void clear() const;

private:
  SDL_Renderer* renderer;
};

}
