#include "../common/Vec2.h"
#include "../gfx/Window.h"
#include "../util/Logger.h"
#include "Keyboard.h"
#include "Mouse.h"

int main() {
  GFX::Window window("Brot Engine | Input Test", { 800, 600 });

  window.loop([&](int) -> void {
    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      window.quit();
    });

    Input::Keyboard::OnPressed(Input::Keyboard::RETURN, [&]() -> void {
      Util::Logger::Debug("pressed RETURN");
    });

    Input::Keyboard::OnPressed({ Input::Keyboard::LCTRL, Input::Keyboard::ONE }, [&]() -> void {
      Util::Logger::Debug("pressed LCTRL + ONE");
    });

    Input::Mouse::OnClick(Input::Mouse::LEFT, [&](Common::Vec2 pos) -> void {
      Util::Logger::Debug("pressed LEFT_CLICK at " + pos.to_print_string());
    });
  });

  return 0;
}
