#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/Time.h"
#include "entity/Sprite.h"
#include "Entity.h"
#include "Game.h"
#include "Scene.h"

#define TEXTURE_PATH "../tmp/dino-char/sprites/sprite_"
#define TEXTURE_EXT ".png"
#define IDLE 0
#define RUNNING 1
#define VELOCITY 20

int main() {
  Engine::Game game("Brot Engine | Engine Test");
  Engine::Scene scene("main_scene");
  std::shared_ptr<Engine::Entity> entity = std::make_shared<Engine::Entity>(game.ctx);

  entity->size = { 100, 100 };
  entity->animations.push_back(Engine::Animation());
  entity->animations[IDLE].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)));
  entity->animations[IDLE].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)));
  entity->animations[IDLE].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)));
  entity->animations[IDLE].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)));

  entity->animations.push_back(Engine::Animation());
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)));
  entity->animations[RUNNING].push_sprite(std::make_shared<Engine::Sprite>(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)));

  scene.push_layer();
  std::shared_ptr<Engine::Layer> level_layer = scene.get_layer(0);
  level_layer->entities.push_back(entity);

  game.loop([&]() -> void {
    entity->animation_index = IDLE;

    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      entity->animation_index = RUNNING;
      entity->position.y = entity->position.y - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::A, [&]() -> void {
      entity->flip = true;
      entity->animation_index = RUNNING;
      entity->position.x = entity->position.x - VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      entity->animation_index = RUNNING;
      entity->position.y = entity->position.y + VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::D, [&]() -> void {
      entity->flip = false;
      entity->animation_index = RUNNING;
      entity->position.x = entity->position.x + VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::ONE, [&]() -> void {
      level_layer->toggle_fill();
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
