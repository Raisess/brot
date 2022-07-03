#pragma once

#include "../common/types.h"
#include "Renderer.h"
#include "SDLController.h"

namespace GFX {

class Component : public SDLController<SDL_Rect> {
public:
  Component();

  const Common::Size get_size() const {
    return size;
  }

  void set_size(const Common::Size& new_size) {
    size = new_size;
  }

  const Common::Pos get_pos() const {
    return position;
  }

  void set_pos(const Common::Pos new_position) {
    position = new_position;
  }

  void draw(const Renderer& renderer, bool fill);

private:
  Common::Size size;
  Common::Pos position;
};

}
