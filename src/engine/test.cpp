#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/ArgsParser.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Entity.h"
#include "Game.h"
#include "NodeContainer.h"
#include "Physics.h"
#include "Scene.h"
#include "UI.h"

#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
#define TEXTURE_PATH "../../assets/sprites/dino/"
#define TEXTURE_EXT ".png"
#define IDLE "idle"
#define RUNNING "running"
#define VELOCITY 5

using namespace Engine;

class Dino : public NodeContainer {
public:
  std::shared_ptr<Engine::UI> ui;
  std::shared_ptr<Engine::Entity> entity;

  Dino(const std::string& id, const GameContext& game_ctx, const std::shared_ptr<GFX::Image>& sprite, const std::shared_ptr<GFX::Font>& font)
    : NodeContainer(id) {
    ui = UI::Shared(game_ctx, id + "_ui", font);
    entity = Entity::Shared(game_ctx, id + "_entity", sprite);

    entity->size = { 100, 100 };
    entity->color = { 255, 0, 0 };
    ui->size = { 60, 50 };
    ui->offset = { 25, -30 };
    ui->text = id;
    nodes = { ui, entity };
  }
};

int main(int argc, char* argv[]) {
  Game game("Brot Engine | Engine Test", argc, argv);
  game.toggle_info();
  Scene scene("main_scene");
  std::shared_ptr<GFX::Font> game_font = GFX::Font::Shared(FONT_PATH);
  std::shared_ptr<Layer> ui_layer = scene.push_layer();
  std::shared_ptr<Layer> level_layer = scene.push_layer();

  std::shared_ptr<GFX::Image> dino_sprite = GFX::Image::Shared(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT));
  Animation dino_idle_animation = Animation({
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)),
  });
  Animation dino_running_animation = Animation({
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)),
    GFX::Image::Shared(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)),
  });

  std::shared_ptr<Dino> dino = std::make_shared<Dino>("dino_0", game.ctx, dino_sprite, game_font);
  dino->entity->create_animation(IDLE, dino_idle_animation);
  dino->entity->create_animation(RUNNING, dino_running_animation);
  level_layer->nodes.push_back(dino);

  std::shared_ptr<Dino> another_dino = std::make_shared<Dino>("dino_1", game.ctx, dino_sprite, game_font);
  another_dino->entity->create_animation(IDLE, dino_idle_animation);
  another_dino->entity->flip = true;
  another_dino->position = { 500, 100 };
  level_layer->nodes.push_back(another_dino);

  game.loop([&](int delta_time) -> void {
    dino->entity->use_animation(IDLE);
    another_dino->entity->use_animation(IDLE);

    Physics::Collision::IsColliding(*dino->entity, *another_dino->entity, []() -> void {
      Util::Logger::Log("colliding");
    });

    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      dino->entity->use_animation(RUNNING);
      dino->position.y -= VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::A, [&]() -> void {
      dino->entity->use_animation(RUNNING);
      dino->entity->flip = true;
      dino->position.x -= VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      dino->entity->use_animation(RUNNING);
      dino->position.y += VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::D, [&]() -> void {
      dino->entity->use_animation(RUNNING);
      dino->entity->flip = false;
      dino->position.x += VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::O, [&]() -> void {
      dino->entity->size = dino->entity->size - Common::Size({ 10, 10 });
    });
    Input::Keyboard::OnPressed(Input::Keyboard::P, [&]() -> void {
      dino->entity->size = dino->entity->size + Common::Size({ 10, 10 });
    });
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
    Input::Keyboard::OnPressed(Input::Keyboard::FOUR, [&]() -> void {
      if (dino->entity->is_paused_animation(IDLE)) {
        dino->entity->resume_animation(IDLE);
        dino->entity->resume_animation(RUNNING);
      } else {
        dino->entity->pause_animation(IDLE);
        dino->entity->pause_animation(RUNNING);
      }

      Util::Time::Delay(100);
    });

    scene.update(delta_time);
    scene.draw();
  });

  return 0;
}
