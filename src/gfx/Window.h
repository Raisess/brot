#pragma once

#include <iostream>
#include <functional>
#include "../common/Size.h"
#include "SDLController.h"

using CallbackLoop = std::function<void(int)>;

namespace GFX {

class Window : public SDLController<SDL_Window*> {
public:
  std::string title;

  Window(const std::string& title, const Common::Size& size, bool fullscreen);
  ~Window(void);

  void quit() const;
  void loop(const CallbackLoop& callback);

  const Common::Size get_size() const {
    return _size;
  }

  const int get_fps() const {
    return _fps;
  }

  const bool is_fullscreen() const {
    return _fullscreen;
  }

private:
  static unsigned int MinimunDeltaTime;
  unsigned int _fps = 0;
  Common::Size _size;
  bool _fullscreen;
};

}
