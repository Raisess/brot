#include "Mouse.h"

void Input::Mouse::OnLeftClick(Callback callback) {
  Common::Vec2 pos(0, 0);
  unsigned int buttons = SDL_GetMouseState(&pos.x, &pos.y);

  if ((buttons & LEFT) != 0) {
    callback(pos);
  }
}

void Input::Mouse::OnRightClick(Callback callback) {
  Common::Vec2 pos(0, 0);
  unsigned int buttons = SDL_GetMouseState(&pos.x, &pos.y);

  if ((buttons & RIGHT) != 0) {
    callback(pos);
  }
}
