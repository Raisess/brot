#include <iostream>
#include <memory>
#include "../input/Keyboard.h"
#include "../util/Time.h"
#include "Entity.h"
#include "Game.h"
#include "NodeContainer.h"
#include "Scene.h"
#include "UI.h"

#define FONT_PATH "./assets/fonts/font.ttf"
#define TEXTURE_PATH "../tmp/dino-char/sprites/sprite_"
#define TEXTURE_EXT ".png"
#define IDLE "idle"
#define RUNNING "running"
#define VELOCITY 5

int main() {
  Engine::Game game("Brot Engine | Engine Test");
  Engine::Scene scene("main_scene");
  std::shared_ptr<Engine::Layer> level_layer = scene.push_layer();
  std::shared_ptr<Engine::Layer> ui_layer = scene.push_layer();

  std::shared_ptr<GFX::Font> game_font = std::make_shared<GFX::Font>(FONT_PATH);

  std::shared_ptr<Engine::UI> fps_ui = std::make_shared<Engine::UI>(game.ctx, "fps_ui", game_font);
  fps_ui->size = { 100, 40 };
  ui_layer->nodes.push_back(fps_ui);

  std::shared_ptr<Engine::Entity> dino_entity = std::make_shared<Engine::Entity>(game.ctx, "dino_entity");
  dino_entity->size = { 100, 100 };
  dino_entity->color = { 255, 0, 0 };
  std::shared_ptr<Engine::UI> dino_ui = std::make_shared<Engine::UI>(game.ctx, "dino_ui", game_font);
  dino_ui->offset = { 25, -30 };
  dino_ui->size = { 50, 50 };
  dino_ui->text = "Dino";
  std::shared_ptr<Engine::NodeContainer> dino = std::make_shared<Engine::NodeContainer>("dino");
  dino->nodes.push_back(dino_entity);
  dino->nodes.push_back(dino_ui);
  level_layer->nodes.push_back(dino);

  dino_entity->create_animation(IDLE, {
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)),
  });

  dino_entity->create_animation(RUNNING, {
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)),
    std::make_shared<GFX::Image>(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)),
  });

  game.loop([&](int delta_time) -> void {
    fps_ui->text = "FPS: " + std::to_string(game.ctx.window_ctx->get_fps());
    dino_entity->use_animation(IDLE);

    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      dino_entity->use_animation(RUNNING);
      dino->position.y -= VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::A, [&]() -> void {
      dino_entity->use_animation(RUNNING);
      dino_entity->flip = true;
      dino->position.x -= VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      dino_entity->use_animation(RUNNING);
      dino->position.y += VELOCITY;
    });
    Input::Keyboard::OnPressed(Input::Keyboard::D, [&]() -> void {
      dino_entity->use_animation(RUNNING);
      dino_entity->flip = false;
      dino->position.x += VELOCITY;
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

    scene.update(delta_time);
    scene.draw();
  });

  return 0;
}
