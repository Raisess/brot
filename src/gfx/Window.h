#pragma once

#include <iostream>
#include <functional>
#include "../common/types.h"
#include "SDLController.h"

namespace GFX {

class Window : public SDLController<SDL_Window*> {
public:
  Window(const std::string& title, const Common::Size& size);
  ~Window(void);

  const Common::Size get_size() const {
    return size;
  }

  void loop(std::function<void(void)> loop) const;

private:
  Common::Size size;
};

}
