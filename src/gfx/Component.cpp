#include "Component.h"

GFX::Component::Component(const Renderer& renderer)
  : renderer(renderer), size({ 0, 0 }), position({ 0, 0 }) {}

void GFX::Component::attach_texture(const std::string& img_path) {
  texture = std::make_unique<Texture>(renderer, img_path);
}

void GFX::Component::attach_text(const std::string& font_path, const std::string& _text) {
  text = std::make_unique<Text>(renderer, font_path, _text, color);
}

void GFX::Component::draw(const bool& fill) {
  sdl_value.w = size.width;
  sdl_value.h = size.height;
  sdl_value.x = position.x;
  sdl_value.y = position.y;

  SDL_SetRenderDrawColor(renderer.get(), color.red, color.green, color.blue, color.alpha);

  if (fill) {
    SDL_RenderFillRect(renderer.get(), &sdl_value);
  } else {
    SDL_RenderDrawRect(renderer.get(), &sdl_value);
  }

  if (texture != nullptr) {
    SDL_RenderCopy(renderer.get(), texture->get(), nullptr, &sdl_value);
  } else if (text != nullptr) {
    SDL_RenderCopy(renderer.get(), text->get(), nullptr, &sdl_value);
  } else {
    SDL_RenderCopy(renderer.get(), nullptr, nullptr, &sdl_value);
  }
}

const Size GFX::Component::get_size() const {
  return size;
}

void GFX::Component::set_size(const Size& new_size) {
  size = new_size;
}

const Vec2 GFX::Component::get_position() const {
  return position;
}

void GFX::Component::set_position(const Vec2& new_position) {
  position = new_position;
}

const Color GFX::Component::get_color() const {
  return color;
}

void GFX::Component::set_color(const Color& new_color) {
  color = new_color;
}
