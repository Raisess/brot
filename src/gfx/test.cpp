#include <iostream>
#include "Component.h"
#include "Renderer.h"
#include "Window.h"

#define BG_TEXTURE_PATH "../tmp/test-bg-img.png"
#define TEXTURE_PATH "../tmp/test-img.png"
#define FONT_PATH "../tmp/test-font.ttf"
#define VELOCITY 5

int main() {
  GFX::Window window("Brot Engine | GFX Test", { 800, 600 });
  GFX::Renderer renderer(window);
  GFX::Image test_bg_image(BG_TEXTURE_PATH);
  GFX::Image test_image(TEXTURE_PATH);
  GFX::Font test_font(FONT_PATH);

  GFX::Component bg(renderer);
  bg.set_size(window.get_size());
  bg.attach_texture(test_bg_image);

  GFX::Component red_component(renderer);
  red_component.set_size({ 100, 100 });
  red_component.set_position({ 0, 0 });
  red_component.set_color({ 255, 0, 0 });
  red_component.fill();
  red_component.attach_texture(test_image);

  GFX::Component green_component(renderer);
  green_component.set_size({ 100, 100 });
  green_component.set_position({ 500, 300 });
  green_component.set_color({ 0, 255, 0 });

  GFX::Component blue_component(renderer);
  blue_component.set_size({ 100, 100 });
  blue_component.set_position({ 700, 50 });
  blue_component.set_color({ 0, 0, 255 });
  blue_component.attach_texture(test_image);

  GFX::Component text_component(renderer);
  text_component.set_size({ 100, 50 });

  bool up = false;
  int i = 0;
  window.loop([&]() -> void {
    text_component.attach_text(test_font, "FPS: " + std::to_string(window.get_fps()));
    renderer.clear();
    bg.draw();

    if (up) {
      if (red_component.get_position().y <= 0) {
        up = false;
      }
      red_component.set_position({ i - VELOCITY, i - VELOCITY });
      i -= VELOCITY;
    } else {
      if (red_component.get_position().y >= (window.get_size().height - red_component.get_size().height - VELOCITY)) {
        up = true;
      }
      red_component.set_position({ i + VELOCITY, i + VELOCITY });
      i += VELOCITY;
    }

    if (up) {
      green_component.fill();
      green_component.draw();
    } else {
      green_component.unfill();
      green_component.draw();
    }

    red_component.draw();
    blue_component.draw();
    text_component.draw();
    renderer.draw();
  });

  return 0;
}
