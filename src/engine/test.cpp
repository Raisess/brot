#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/ArgsParser.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "core/Game.h"
#include "core/Scene.h"
#include "manager/SpriteAnimationManager.h"
#include "object/Entity.h"
#include "object/Physics.h"
#include "object/Sprite.h"
#include "object/SpriteAnimation.h"
#include "object/UI.h"

#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
#define TEXTURE_PATH "../../assets/sprites/dino/"
#define TEXTURE_EXT ".png"
#define IDLE "idle"
#define RUNNING "running"
#define VELOCITY 10

using namespace Engine;

class Dino : public Entity {
public:
  Dino(const std::string& id, const GameContext& game_ctx, const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<GFX::Font>& font)
    : Entity(game_ctx, id, sprite), _ui(game_ctx, id + "_ui", font) {
    size = { 100, 100 };
    color = { 255, 0, 0 };
    _ui.size = { 60, 50 };
    _ui.offset = { 20, -30 };
    _ui.text = id;
  }

  void on_update(int delta_time) final override {
    _ui.position = position;
    _ui.update(delta_time);
  }

  void on_draw() final override {
    _ui.draw();
  }

private:
  Engine::UI _ui;
};

int main(int argc, char* argv[]) {
  Game game("Brot Engine | Engine Test", argc, argv);
  game.toggle_info();
  Scene scene("main_scene");
  std::shared_ptr<Layer> level_layer = scene.push_layer();
  std::shared_ptr<GFX::Font> game_font = GFX::Font::Shared(FONT_PATH);

  std::shared_ptr<Sprite> dino_sprite = Sprite::Shared(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT));
  SpriteAnimation dino_idle_animation = SpriteAnimation({
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)), 200 },
  });
  SpriteAnimation dino_running_animation = SpriteAnimation({
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)), 200 },
  });

  std::shared_ptr<Dino> dino = std::make_shared<Dino>("dino_0", game.ctx, dino_sprite, game_font);
  dino->position = { 100, 0 };
  Manager::SpriteAnimationManager dino_animation(*dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });
  level_layer->nodes.push_back(dino);

  std::shared_ptr<Dino> another_dino = std::make_shared<Dino>("dino_1", game.ctx, dino_sprite, game_font);
  another_dino->flip = true;
  another_dino->position = { 500, 100 };
  Manager::SpriteAnimationManager another_dino_animation(*another_dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });
  level_layer->nodes.push_back(another_dino);

  game.loop([&](int delta_time) -> void {
    Physics::Collision::IsColliding(*dino, *another_dino, []() -> void {
      Util::Logger::Log("colliding");
    });

    another_dino_animation.play(delta_time, IDLE);

    if (Input::Keyboard::OnPressed(Input::Keyboard::W)) {
      dino->position.y = dino->position.y -= VELOCITY;
      dino_animation.play(delta_time, RUNNING);
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::A)) {
      dino->flip = true;
      dino->position.x = dino->position.x -= VELOCITY;
      dino_animation.play(delta_time, RUNNING);
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::S)) {
      dino->position.y = dino->position.y += VELOCITY;
      dino_animation.play(delta_time, RUNNING);
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::D)) {
      dino->flip = false;
      dino->position.x = dino->position.x += VELOCITY;
      dino_animation.play(delta_time, RUNNING);
    } else {
      dino_animation.play(delta_time, IDLE);
    }

    Input::Keyboard::OnPressed(Input::Keyboard::ONE, [&]() -> void {
      level_layer->toggle_fill();
      Util::Time::Delay(100);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::TWO, [&]() -> void {
      level_layer->toggle_rect();
      Util::Time::Delay(100);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::THREE, [&]() -> void {
      level_layer->toggle_hide();
      Util::Time::Delay(100);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });

    scene.update(delta_time);
    scene.draw();
  });

  return 0;
}
