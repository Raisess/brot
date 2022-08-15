#include "../gfx/Window.h"

int main() {
  GFX::Window window("Brot Engine | SFX Test", { 800, 600 });

  window.loop([&](int) -> void {});

  return 0;
}
