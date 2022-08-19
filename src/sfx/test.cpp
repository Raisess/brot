#include "../gfx/Window.h"

int main() {
  GFX::Window window("Brot Engine | SFX Test", { 800, 600 }, false);

  window.loop([&](int) -> void {});

  return 0;
}
