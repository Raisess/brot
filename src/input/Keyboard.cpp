#include "Keyboard.h"

void Input::Keyboard::IsPressed(const Key& key, const Callback& callback) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  if (state[key]) {
    return callback();
  }
}

bool Input::Keyboard::IsPressed(const Key& key) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);
  return state[key] ? true : false;
}

void Input::Keyboard::IsPressed(const std::vector<Key>& keys, const Callback& callback) {
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

bool Input::Keyboard::IsPressed(const std::vector<Key>& keys) {
  const unsigned char* state = SDL_GetKeyboardState(nullptr);

  bool exec = true;
  for (auto key : keys) {
    if (!state[key]) {
      exec = false;
    }
  }

  return exec;
}
