#pragma once

#include <iostream>
#include <functional>
#include "../common/Size.h"
#include "SDLController.h"

#define DEFAULT_FPS_LIMIT 60

using CallbackLoop = std::function<void(int)>;

namespace GFX {

class Window : public SDLController<SDL_Window*> {
public:
  std::string title;

  Window(const std::string& title, const Common::Size& size, int fps_limit = DEFAULT_FPS_LIMIT);
  ~Window(void);

  void quit() const;
  void loop(const CallbackLoop& callback);
  const Common::Size get_size() const;
  const unsigned int get_fps() const;

private:
  unsigned int _minimum_delta_time;
  unsigned int _fps_limit;
  unsigned int _fps = 0;
  Common::Size _size;
};

}
