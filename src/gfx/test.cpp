#include <iostream>
#include "Renderer.h"
#include "TextComponent.h"
#include "TextureComponent.h"
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

  GFX::TextureComponent bg(renderer);
  bg.set_size(window.get_size());
  bg.bind(test_bg_image);

  GFX::TextureComponent red_component(renderer);
  red_component.set_size({ 100, 100 });
  red_component.set_position({ 0, 0 });
  red_component.set_color({ 255, 0, 0 });
  red_component.set_fill(true);
  red_component.bind(test_image);

  GFX::TextureComponent green_component(renderer);
  green_component.set_size({ 100, 100 });
  green_component.set_position({ 500, 300 });
  green_component.set_color({ 0, 255, 0 });
  green_component.set_rect(true);

  GFX::TextureComponent blue_component(renderer);
  blue_component.set_size({ 100, 100 });
  blue_component.set_position({ 700, 50 });
  blue_component.set_color({ 0, 0, 255 });
  blue_component.bind(test_image);

  GFX::TextComponent fps_text_component(renderer);
  fps_text_component.set_size({ 100, 50 });

  bool up = false;
  int i = 0;
  window.loop([&](int) -> void {
    fps_text_component.bind(test_font, "FPS: " + std::to_string(window.get_fps()));
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
      green_component.set_fill(true);
    } else {
      green_component.set_fill(false);
    }

    blue_component.set_angle(i);
    blue_component.draw();
    red_component.draw();
    green_component.draw();
    fps_text_component.draw();
    renderer.draw();
  });

  return 0;
}
