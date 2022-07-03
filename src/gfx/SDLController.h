# pragma once

#include <SDL2/SDL.h>

namespace GFX {

template<typename T>
class SDLController {
public:
  T get() const {
    return sdl_value;
  }

protected:
  T sdl_value;
};

}
