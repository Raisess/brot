#pragma once

#include <memory>
#include "../common/types.h"
#include "Renderer.h"
#include "SDLController.h"
#include "Texture.h"

namespace GFX {

class Component : public SDLController<SDL_Rect> {
public:
  Component(const Renderer& renderer);

  void attach_texture(const std::string& texture);
  void draw(const bool& fill);

  const Common::Size get_size() const {
    return size;
  }

  void set_size(const Common::Size& new_size) {
    size = new_size;
  }

  const Common::Position get_position() const {
    return position;
  }

  void set_position(const Common::Position& new_position) {
    position = new_position;
  }

  const Common::Color get_color() const {
    return color;
  }

  void set_color(const Common::Color& new_color) {
    color = new_color;
  }

private:
  const Renderer renderer;
  std::unique_ptr<Texture> texture;
  Common::Size size;
  Common::Position position;
  Common::Color color;
};

}
