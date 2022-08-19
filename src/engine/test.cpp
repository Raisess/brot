#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/ArgsParser.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "core/Game.h"
#include "core/Scene.h"
#include "object/Entity.h"
#include "object/NodeContainer.h"
#include "object/Physics.h"
#include "object/Sprite.h"
#include "object/SpriteAnimation.h"
#include "object/UI.h"
#include "manager/SpriteAnimationManager.h"

#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
#define TEXTURE_PATH "../../assets/sprites/dino/"
#define TEXTURE_EXT ".png"
#define IDLE "idle"
#define RUNNING "running"
#define VELOCITY 10

using namespace Engine;

class Dino : public NodeContainer {
public:
  std::shared_ptr<Engine::UI> ui;
  std::shared_ptr<Engine::Entity> entity;

  Dino(const std::string& id, const GameContext& game_ctx, const std::shared_ptr<Sprite>& sprite, const std::shared_ptr<GFX::Font>& font)
    : NodeContainer(id) {
    ui = UI::Shared(game_ctx, id + "_ui", font);
    entity = Entity::Shared(game_ctx, id + "_entity", sprite);

    entity->size = { 100, 100 };
    entity->color = { 255, 0, 0 };
    ui->size = { 60, 50 };
    ui->offset = { 20, -30 };
    ui->text = id;
    nodes = { ui, entity };
  }
};

int main(int argc, char* argv[]) {
  Game game("Brot Engine | Engine Test", argc, argv);
  game.toggle_info();
  Scene scene("main_scene");
  std::shared_ptr<Layer> level_layer = scene.push_layer();
  std::shared_ptr<GFX::Font> game_font = GFX::Font::Shared(FONT_PATH);

  std::shared_ptr<Sprite> dino_sprite = Sprite::Create(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT));
  SpriteAnimation dino_idle_animation = SpriteAnimation({
    Sprite::Create(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)),
  });
  SpriteAnimation dino_running_animation = SpriteAnimation({
    Sprite::Create(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)),
    Sprite::Create(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)),
  });

  std::shared_ptr<Dino> dino = std::make_shared<Dino>("dino_0", game.ctx, dino_sprite, game_font);
  Manager::SpriteAnimationManager dino_animation(*dino->entity, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });
  level_layer->nodes.push_back(dino);

  std::shared_ptr<Dino> another_dino = std::make_shared<Dino>("dino_1", game.ctx, dino_sprite, game_font);
  Manager::SpriteAnimationManager another_dino_animation(*another_dino->entity, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });
  another_dino->entity->flip = true;
  another_dino->position = { 500, 100 };
  level_layer->nodes.push_back(another_dino);

  game.loop([&](int delta_time) -> void {
    Physics::Collision::IsColliding(*dino->entity, *another_dino->entity, []() -> void {
      Util::Logger::Log("colliding");
    });

    another_dino_animation.play(delta_time, IDLE);

    if (Input::Keyboard::OnPressed(Input::Keyboard::W)) {
      dino_animation.play(delta_time, RUNNING);
      dino->position.y -= VELOCITY;
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::A)) {
      dino_animation.play(delta_time, RUNNING);
      dino->entity->flip = true;
      dino->position.x -= VELOCITY;
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::S)) {
      dino_animation.play(delta_time, RUNNING);
      dino->position.y += VELOCITY;
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::D)) {
      dino_animation.play(delta_time, RUNNING);
      dino->entity->flip = false;
      dino->position.x += VELOCITY;
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::O)) {
      dino->entity->size = dino->entity->size - Common::Size({ 10, 10 });
    } else if (Input::Keyboard::OnPressed(Input::Keyboard::P)) {
      dino->entity->size = dino->entity->size + Common::Size({ 10, 10 });
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
