#include "Renderer.h"
#include "Window.h"

int main() {
  GFX::Window window("Brot Engine", { 840, 600 });
  GFX::Renderer renderer(window);

  window.loop([&]() -> void {
    renderer.clear();
  });

  return 0;
}
