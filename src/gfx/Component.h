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

  void set_pos(const Common::Pos& new_position) {
    position = new_position;
  }

  const Common::Color get_color() const {
    return color;
  }

  void set_color(const Common::Color& new_color) {
    color = new_color;
  }

  void draw(const Renderer& renderer, const bool& fill);

private:
  Common::Size size;
  Common::Pos position;
  Common::Color color;
};

}
