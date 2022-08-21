#pragma once

#include <SDL2/SDL.h>

template<typename T>
class SDLController {
public:
  T get() const {
    return sdl_value;
  }

protected:
  T sdl_value;
};
