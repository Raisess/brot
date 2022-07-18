#include "Component.h"

GFX::Component::Component(const Renderer& renderer)
  : renderer(renderer), _size({ 0, 0 }), _position({ 0, 0 }) {}

void GFX::Component::draw() {
  sdl_value.w = _size.width;
  sdl_value.h = _size.height;
  sdl_value.x = _position.x;
  sdl_value.y = _position.y;

  SDL_SetRenderDrawColor(renderer.get(), _color.red, _color.green, _color.blue, _color.alpha);

  if (_fill) {
    SDL_RenderFillRect(renderer.get(), &sdl_value);
  } else {
    SDL_RenderDrawRect(renderer.get(), &sdl_value);
  }

  if (texture != nullptr) {
    SDL_RenderCopyEx(renderer.get(), texture->get(), nullptr, &sdl_value, _angle, nullptr, _flip ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
  } else if (text != nullptr) {
    SDL_RenderCopyEx(renderer.get(), text->get(), nullptr, &sdl_value, _angle, nullptr, SDL_FLIP_NONE);
  } else {
    SDL_RenderCopy(renderer.get(), nullptr, nullptr, &sdl_value);
  }
}

void GFX::Component::bind_texture(const Image& image) {
  texture = std::make_unique<Texture>(renderer, image);
}

void GFX::Component::bind_text(const Font& font, const std::string& str) {
  text = std::make_unique<Text>(renderer, font, str, _color);
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

void GFX::Component::fill() {
  _fill = true;
}

void GFX::Component::unfill() {
  _fill = false;
}

void GFX::Component::flip() {
  _flip = true;
}

void GFX::Component::unflip() {
  _flip = false;
}
