#pragma once

#include <iostream>
#include <functional>
#include <SDL2/SDL.h>
#include "../common/Logger.h"
#include "../common/types.h"

namespace GFX {

class Window {
public:
  Window(const std::string& title, const Common::Size& size);
  ~Window(void);

  SDL_Window* get() const {
    return window;
  }

  void loop(std::function<void(void)> game_loop) const;

private:
  SDL_Window* window;
};

}
