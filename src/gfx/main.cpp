#include "../common/Logger.h"
#include "Component.h"
#include "Renderer.h"
#include "Window.h"

#define VEL 5

int main() {
  GFX::Window window("Brot Engine", { 840, 600 });
  GFX::Renderer renderer(window);

  GFX::Component red_component(renderer);
  red_component.set_size({ 100, 100 });
  red_component.set_position({ 0, 0 });
  red_component.set_color({ 255, 0, 0 });

  GFX::Component blue_component(renderer);
  blue_component.set_size({ 100, 100 });
  blue_component.set_position({ window.get_size().width - blue_component.get_size().width - 50, 50 });
  blue_component.set_color({ 0, 0, 255 });

  bool up = false;
  int i = 0;
  window.loop([&]() -> void {
    renderer.clear();

    if (up) {
      if (red_component.get_position().y <= -VEL) {
        up = false;
      }
      red_component.set_position({ i - VEL, i - VEL });
      i -= VEL;
    } else {
      if (red_component.get_position().y >= (window.get_size().height - red_component.get_size().height - VEL)) {
        up = true;
      }
      red_component.set_position({ i + VEL, i + VEL });
      i += VEL;
    }

    red_component.draw(true);
    blue_component.draw(false);
    renderer.draw();
  });

  return 0;
}
