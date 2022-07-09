#include "Component.h"
#include "Renderer.h"
#include "Window.h"

#define TEXTURE_PATH "../test-img.png"
#define VELOCITY 5

int main() {
  GFX::Window window("Brot Engine", { 800, 600 });
  GFX::Renderer renderer(window);

  GFX::Component red_component(renderer);
  red_component.set_size({ 100, 100 });
  red_component.set_position({ 0, 0 });
  red_component.set_color({ 255, 0, 0 });
  red_component.attach_texture(TEXTURE_PATH);

  GFX::Component green_component(renderer);
  green_component.set_size({ 100, 100 });
  green_component.set_position({ 500, 300 });
  green_component.set_color({ 0, 255, 0 });

  GFX::Component blue_component(renderer);
  blue_component.set_size({ 100, 100 });
  blue_component.set_position({ 700, 50 });
  blue_component.set_color({ 0, 0, 255 });
  blue_component.attach_texture(TEXTURE_PATH);

  bool up = false;
  int i = 0;
  window.loop([&]() -> void {
    renderer.clear();

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

    red_component.draw(true);

    if (up) {
      green_component.draw(true);
    } else {
      green_component.draw(false);
    }

    blue_component.draw(false);
    renderer.draw();
  });

  return 0;
}
