#include "../gfx/Window.h"

int main() {
  GFX::Window window("Brot Engine | SFX Test", { 800, 600 });

  window.loop([&]() -> void {});

  return 0;
}
