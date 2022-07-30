#include "_Component.h"

GFX::Component::Component(const Renderer& renderer)
  : renderer(renderer), _size({ 0, 0 }), _position({ 0, 0 }) {}

void GFX::Component::draw_rect() {
  sdl_value.w = _size.width;
  sdl_value.h = _size.height;
  sdl_value.x = _position.x;
  sdl_value.y = _position.y;

  if (_rect || _fill) {
    SDL_SetRenderDrawColor(renderer.get(), _color.red, _color.green, _color.blue, _color.alpha);

    if (_fill) {
      SDL_RenderFillRect(renderer.get(), &sdl_value);
    } else {
      SDL_RenderDrawRect(renderer.get(), &sdl_value);
    }
  }
}

const Size GFX::Component::get_size() const {
  return _size;
}

void GFX::Component::set_size(const Size& size) {
  _size = size;
}

const Vec2 GFX::Component::get_position() const {
  return _position;
}

void GFX::Component::set_position(const Vec2& position) {
  _position = position;
}

const Color GFX::Component::get_color() const {
  return _color;
}

void GFX::Component::set_color(const Color& color) {
  _color = color;
}

const int GFX::Component::get_angle() const {
  return _angle;
}

void GFX::Component::set_angle(int angle) {
  _angle = angle;
}

const bool GFX::Component::get_fill() const {
  return _fill;
}

void GFX::Component::set_fill(bool fill) {
  _fill = fill;
}

const bool GFX::Component::get_flip() const {
  return _flip;
}

void GFX::Component::set_flip(bool flip) {
  _flip = flip;
}

const bool GFX::Component::get_rect() const {
  return _rect;
}

void GFX::Component::set_rect(bool rect){
  _rect = rect;
}
