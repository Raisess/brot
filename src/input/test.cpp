#include "../common/Vec2.h"
#include "../gfx/Window.h"
#include "../util/Logger.h"
#include "Keyboard.h"
#include "Mouse.h"

int main() {
  GFX::Window window("Brot Engine | Input Test", { 800, 600 }, false);

  window.loop([&](int) -> void {
    Input::Keyboard::IsPressed(Input::Keyboard::ESC, [&]() -> void {
      window.quit();
    });

    Input::Keyboard::IsPressed(Input::Keyboard::RETURN, [&]() -> void {
      Util::Logger::Debug("pressed RETURN");
    });

    Input::Keyboard::IsPressed({ Input::Keyboard::LCTRL, Input::Keyboard::ONE }, [&]() -> void {
      Util::Logger::Debug("pressed LCTRL + ONE");
    });

    Input::Mouse::IsClick(Input::Mouse::LEFT, [&](Common::Vec2 pos) -> void {
      Util::Logger::Debug("pressed LEFT_CLICK at " + pos.to_print_string());
    });
  });

  return 0;
}
