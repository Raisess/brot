#pragma once

#include <functional>
#include <SDL2/SDL_mouse.h>
#include "../common/Vec2.h"

namespace Input {

class Mouse {

using Callback = std::function<void(const Common::Vec2&)>;

public:
  enum Button {
    LEFT = SDL_BUTTON_LMASK,
    RIGHT = SDL_BUTTON_RMASK,
  };

  static void OnClick(const Button& button, const Callback& callback);
};

}
