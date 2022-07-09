#pragma once

#include <iostream>
#include <memory>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"
#include "Renderer.h"
#include "SDLController.h"
#include "Text.h"
#include "Texture.h"

using namespace Common;

namespace GFX {

class Component : public SDLController<SDL_Rect> {
public:
  Component(const Renderer& renderer);

  void attach_texture(const std::string& img_path);
  void attach_text(const std::string& font_path, const std::string& text);
  void draw(const bool& fill);
  const Size get_size() const;
  void set_size(const Size& new_size);
  const Vec2 get_position() const;
  void set_position(const Vec2& new_position);
  const Color get_color() const;
  void set_color(const Color& new_color);

private:
  const Renderer renderer;
  std::unique_ptr<Texture> texture;
  std::unique_ptr<Text> text;
  Size size;
  Vec2 position;
  Color color;
};

}
