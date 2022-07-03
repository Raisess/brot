#include "../common/Logger.h"
#include "Component.h"
#include "Renderer.h"
#include "Window.h"

#define VEL 5

int main() {
  GFX::Window window("Brot Engine", { 840, 600 });
  GFX::Renderer renderer(window);

  GFX::Component component;
  component.set_size({ 100, 100 });
  component.set_position({ 0, 0 });
  component.set_color({ 255, 0, 0 });

  bool up = false;
  int i = 0;
  window.loop([&]() -> void {
    renderer.clear();
    component.draw(renderer, true);

    if (up) {
      if (component.get_position().y <= -VEL) {
        up = false;
      }
      component.set_position({ i - VEL, i - VEL });
      i -= VEL;
    } else {
      if (component.get_position().y >= (window.get_size().height - component.get_size().height - VEL)) {
        up = true;
      }
      component.set_position({ i + VEL, i + VEL });
      i += VEL;
    }
  });

  return 0;
}
