#pragma once

#include <functional>
#include <vector>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_keyboard.h>

namespace Input {

class Keyboard {

using Callback = std::function<void(void)>;

public:
  enum Key {
    ONE = SDL_SCANCODE_1,
    TWO = SDL_SCANCODE_2,
    THREE = SDL_SCANCODE_3,
    FOUR = SDL_SCANCODE_4,
    FIVE = SDL_SCANCODE_5,
    SIX = SDL_SCANCODE_6,
    SEVEN = SDL_SCANCODE_7,
    EIGHT = SDL_SCANCODE_8,
    NINE = SDL_SCANCODE_9,
    ZERO = SDL_SCANCODE_0,

    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,

    UP = SDL_SCANCODE_UP,
    DOWN = SDL_SCANCODE_DOWN,
    RIGHT = SDL_SCANCODE_RIGHT,
    LEFT = SDL_SCANCODE_LEFT,

    LCTRL = SDL_SCANCODE_LCTRL,
    RCTRL = SDL_SCANCODE_RCTRL,
    RETURN = SDL_SCANCODE_RETURN,
    BACKSPACE = SDL_SCANCODE_BACKSPACE,
    SPACE = SDL_SCANCODE_SPACE,
    ESC = SDL_SCANCODE_ESCAPE,
  };

  static void OnPressed(Key key, Callback callback);
  static void OnPressed(const std::vector<Key>& keys, Callback callback);
};

}
