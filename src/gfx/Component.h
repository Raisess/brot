#pragma once

#include <SDL2/SDL.h>
#include "../common/types.h"
#include "Renderer.h"

namespace GFX {

class Component {
public:
  Component(const Common::Size& size, const Common::Pos& position);

  SDL_Rect get() const {
    return rect;
  }

  Common::Size get_size() const {
    return size;
  }

  void set_size(const Common::Size& new_size) {
    size = new_size;
  }

  Common::Pos get_pos() const {
    return position;
  }

  void set_pos(const Common::Pos new_position) {
    position = new_position;
  }

  void draw(const Renderer& renderer, bool fill);

private:
  SDL_Rect rect;
  Common::Size size;
  Common::Pos position;
};

}
