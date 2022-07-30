#pragma once

#include <iostream>
#include <memory>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"
#include "Renderer.h"
#include "SDLController.h"

using namespace Common;

namespace GFX {

class Component : public SDLController<SDL_Rect> {
public:
  Component(const Renderer& renderer);

  virtual void draw() = 0;

  const Size get_size() const;
  void set_size(const Size& new_size);
  const Vec2 get_position() const;
  void set_position(const Vec2& new_position);
  const Color get_color() const;
  void set_color(const Color& new_color);
  const int get_angle() const;
  void set_angle(int value);
  const bool get_fill() const;
  void set_fill(bool fill);
  const bool get_flip() const;
  void set_flip(bool flip);
  const bool get_rect() const;
  void set_rect(bool rect);

protected:
  const Renderer& renderer;
  bool _fill = false;
  bool _flip = false;
  bool _rect = false;
  int _angle = 0;
  Vec2 _position;
  Size _size;
  Color _color;

  void draw_rect();
};

}
