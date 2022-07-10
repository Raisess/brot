#pragma once

#include <functional>
#include <SDL2/SDL_mouse.h>
#include "../common/Vec2.h"

namespace Input {

class Mouse {

using Callback = std::function<void(Common::Vec2)>;

public:
  enum Click {
    LEFT = SDL_BUTTON_LMASK,
    RIGHT = SDL_BUTTON_RMASK,
  };

  static void OnLeftClick(Callback callback);
  static void OnRightClick(Callback callback);

private:
};

}
