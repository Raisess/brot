#pragma once

#include "../SDLController.h"
#include "Window.h"

namespace GFX {

class Renderer : public SDLController<SDL_Renderer*> {
public:
  Renderer(const Window& window);
  ~Renderer();

  void draw() const;
  void clear() const;
};

}
