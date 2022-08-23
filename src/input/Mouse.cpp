#include "Mouse.h"

void Input::Mouse::IsClick(const Button& button, const Callback& callback) {
  Common::Vec2 pos(0, 0);
  unsigned int buttons = SDL_GetMouseState(&pos.x, &pos.y);

  if ((buttons & button) != 0) {
    return callback(pos);
  }
}
