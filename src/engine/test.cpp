#include "../input/Keyboard.h"
#include "entity/Entity.h"
#include "Game.h"

#define VELOCITY 5

int main() {
  Engine::Game game("Brot Engine | Engine Test");
  Engine::Entity entity(game.ctx);

  entity.fill = true;
  entity.size = { 100, 100 };

  game.loop([&]() -> void {
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      entity.position.y = entity.position.y - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      entity.position.y = entity.position.y + VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::A, [&]() -> void {
      entity.position.x = entity.position.x - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::D, [&]() -> void {
      entity.position.x = entity.position.x + VELOCITY;
    });

    entity.update();
    entity.draw();
  });

  return 0;
}
