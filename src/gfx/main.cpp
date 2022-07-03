#include "Component.h"
#include "Renderer.h"
#include "Window.h"

int main() {
  GFX::Window window("Brot Engine", { 840, 600 });
  GFX::Renderer renderer(window);
  GFX::Component component({ 100, 100 }, { 0, 0 });

  window.loop([&]() -> void {
    component.draw(renderer, true);
    renderer.clear();
  });

  return 0;
}
