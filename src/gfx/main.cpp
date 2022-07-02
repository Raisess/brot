#include "Window.h"

int main() {
  GFX::Window window("Brot engine", { 100, 100 });

  window.loop([&]() -> void {});

  return 0;
}
