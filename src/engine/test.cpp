#include <iostream>
#include "../input/Keyboard.h"
#include "../util/Time.h"
#include "../_Sharable.h"
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

using namespace Engine;

int main() {
  Game game("Brot Engine | Engine Test");
  Scene scene("main_scene");
  Shared<Layer> level_layer = scene.push_layer();
  Shared<Layer> ui_layer = scene.push_layer();

  Shared<GFX::Font> game_font = GFX::Font::Share(FONT_PATH);

  Shared<UI> fps_ui = UI::Share(game.ctx, "fps_ui", game_font);
  fps_ui->size = { 100, 40 };
  ui_layer->nodes.push_back(fps_ui);

  Shared<UI> dino_ui = UI::Share(game.ctx, "dino_ui", game_font);
  dino_ui->offset = { 25, -30 };
  dino_ui->size = { 50, 50 };
  dino_ui->text = "Dino";
  Shared<Entity> dino_entity = Entity::Share(game.ctx, "dino_entity");
  dino_entity->size = { 100, 100 };
  dino_entity->color = { 255, 0, 0 };
  dino_entity->create_animation(IDLE, {
    GFX::Image::Share(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)),
  });
  dino_entity->create_animation(RUNNING, {
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_5" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_6" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_7" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_8" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_9" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_10" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_11" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_12" + std::string(TEXTURE_EXT)),
    GFX::Image::Share(std::string(TEXTURE_PATH) + "running_13" + std::string(TEXTURE_EXT)),
  });
  Shared<NodeContainer> dino = NodeContainer::Share("dino");
  dino->nodes.push_back(dino_entity);
  dino->nodes.push_back(dino_ui);
  level_layer->nodes.push_back(dino);

  Shared<Entity> another_dino_entity = Entity::Share(game.ctx, "another_dino_entity");
  another_dino_entity->size = { 100, 100 };
  another_dino_entity->color = { 255, 0, 0 };
  another_dino_entity->position = { 500, 100 };
  level_layer->nodes.push_back(another_dino_entity);

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
