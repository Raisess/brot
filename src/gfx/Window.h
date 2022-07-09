#pragma once

#include <iostream>
#include <functional>
#include "../common/Size.h"
#include "SDLController.h"

namespace GFX {

class Window : public SDLController<SDL_Window*> {
public:
  Window(const std::string& title, const Common::Size& size);
  ~Window(void);

  void loop(std::function<void(void)> loop) const;
  const Common::Size get_size() const;

private:
  Common::Size size;
};

}
