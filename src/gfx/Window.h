#pragma once

#include <iostream>
#include <functional>
#include "../common/Size.h"
#include "SDLController.h"

#define FPS_LIMIT 30

namespace GFX {

class Window : public SDLController<SDL_Window*> {

using Loop = std::function<void(void)>;

public:
  Window(const std::string& title, const Common::Size& size);
  ~Window(void);

  void quit() const;
  void loop(const Loop& loop);
  const Common::Size get_size() const;
  const unsigned int get_fps() const;

private:
  static unsigned int MinimumDeltaTime;
  unsigned int _fps = 0;
  Common::Size _size;
};

}
