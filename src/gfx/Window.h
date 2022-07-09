#pragma once

#include <iostream>
#include <functional>
#include "../common/Size.h"
#include "SDLController.h"

#define FPS_LIMIT 60

namespace GFX {

class Window : public SDLController<SDL_Window*> {
public:
  Window(const std::string& title, const Common::Size& size);
  ~Window(void);

  void loop(std::function<void(void)> loop);
  const Common::Size get_size() const;
  const unsigned int get_fps() const;

private:
  static unsigned int MinimumDeltaTime;
  unsigned int fps = 0;
  Common::Size size;
};

}
