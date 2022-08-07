#include "Keyboard.h"

void Input::Keyboard::OnPressed(const Key& key, const Callback& callback) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  if (state[key]) {
    return callback();
  }
}

void Input::Keyboard::OnPressed(const std::vector<Key>& keys, const Callback& callback) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  bool exec = true;
  for (auto key : keys) {
    if (!state[key]) {
      exec = false;
    }
  }

  if (exec) {
    return callback();
  }
}
