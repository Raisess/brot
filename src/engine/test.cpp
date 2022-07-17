#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/Time.h"
#include "entity/Entity.h"
#include "entity/Sprite.h"
#include "Game.h"
#include "Scene.h"

#define TEXTURE_PATH "../tmp/dino-char/sprites/sprite_"
#define TEXTURE_EXT ".png"
#define VELOCITY 20

int main() {
  Engine::Game game("Brot Engine | Engine Test");
  Engine::Scene scene("main_scene");
  Engine::Entity entity(game.ctx);

  entity.fill = true;
  entity.size = { 100, 100 };
  entity.sprites.push_back(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "1" + std::string(TEXTURE_EXT)));
  entity.sprites.push_back(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "2" + std::string(TEXTURE_EXT)));
  entity.sprites.push_back(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "3" + std::string(TEXTURE_EXT)));
  entity.sprites.push_back(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "4" + std::string(TEXTURE_EXT)));

  scene.push_layer();
  Engine::Layer* level_layer = scene.get_layer(0);
  level_layer->entities.push_back(&entity);

  game.loop([&]() -> void {
    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      entity.position.y = entity.position.y - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::A, [&]() -> void {
      entity.position.x = entity.position.x - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      entity.position.y = entity.position.y + VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::D, [&]() -> void {
      entity.position.x = entity.position.x + VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::ONE, [&]() -> void {
      entity.fill = !entity.fill;
      Util::Time::delay(100);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::TWO, [&]() -> void {
      level_layer->toggle_hide();
      Util::Time::delay(100);
    });

    scene.update();
    scene.draw();
  });

  return 0;
}
