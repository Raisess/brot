#include "Keyboard.h"

void Input::Keyboard::OnPressed(Key key, Callback callback) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  if (state[key]) {
    callback();
  }
}

void Input::Keyboard::OnPressed(const std::vector<Key>& keys, Callback callback) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  bool exec = true;
  for (auto key : keys) {
    if (!state[key]) {
      exec = false;
    }
  }

  if (exec) {
    callback();
  }
}
