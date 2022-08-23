#include <iostream>
#include <memory>
#include <brot/input/Keyboard.h>
#include <brot/sfx/Sound.h>
#include <brot/util/ArgsParser.h>
#include <brot/util/Logger.h>
#include <brot/util/Time.h>
#include <brot/engine/core/Game.h>
#include <brot/engine/core/Scene.h>
#include <brot/engine/manager/SpriteAnimationManager.h>
#include <brot/engine/object/Camera.h>
#include <brot/engine/object/Entity.h>
#include <brot/engine/object/Physics.h>
#include <brot/engine/object/Sprite.h>
#include <brot/engine/object/SpriteAnimation.h>
#include <brot/engine/object/UI.h>

#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
#define TEXTURE_PATH "../../assets/sprites/dino/"
#define TEXTURE_EXT ".png"
#define SOUND_PATH "../../assets/sounds/footstep.wav"
#define IDLE "idle"
#define RUNNING "running"
#define VELOCITY 10

using namespace Engine;

class Dino : public Entity {
public:
  Dino(const std::string& id, const GameContext& game_ctx, const Sprite& sprite, const std::shared_ptr<GFX::Font>& font)
    : Entity(game_ctx, id), _ui(game_ctx, id + "_ui", font) {
    set_sprite(sprite);
    size = { 100, 100 };
    color = { 255, 0, 0 };
    _ui.size = { 60, 50 };
    _ui.text = id;
  }

  void on_update(int delta_time) final override {
    _ui.position = position;
    _ui.offset = Common::Vec2(20, -30) + offset;
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
  SpriteAnimation dino_idle_animation({
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_2" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_3" + std::string(TEXTURE_EXT)), 200 },
    { Sprite::Shared(std::string(TEXTURE_PATH) + "idle_4" + std::string(TEXTURE_EXT)), 200 },
  });
  SpriteAnimation dino_running_animation({
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

  Sprite dino_sprite(std::string(TEXTURE_PATH) + "idle_1" + std::string(TEXTURE_EXT));
  std::shared_ptr<Dino> dino = std::make_shared<Dino>("dino_0", game.ctx, dino_sprite, game_font);
  dino->position = { 100, 0 };
  Manager::SpriteAnimationManager dino_animation(*dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });

  std::shared_ptr<Dino> another_dino = std::make_shared<Dino>("dino_1", game.ctx, dino_sprite, game_font);
  another_dino->flip = true;
  another_dino->position = { 500, 100 };
  Manager::SpriteAnimationManager another_dino_animation(*another_dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });

  level_layer->nodes.push_back(dino);
  level_layer->nodes.push_back(another_dino);

  SFX::Sound footstep_sound(SOUND_PATH, 200);
  footstep_sound.set_volume(50);

  game.loop([&](int delta_time) -> void {
    Camera::Move(
      *level_layer,
      dino->position,
      Common::Vec2((game.ctx.window->get_size() / 2).xy() - dino->size.xy()).inverse()
    );

    Physics::Collision::IsColliding(*dino, *another_dino, []() -> void {
      Util::Logger::Log("colliding");
    });

    another_dino_animation.play(delta_time, IDLE);

    if (Input::Keyboard::IsPressed(Input::Keyboard::UP)) {
      Camera::Zoom(*level_layer, 10);
    } else if (Input::Keyboard::IsPressed(Input::Keyboard::DOWN)) {
      Camera::Zoom(*level_layer, -10);
    }

    if (Input::Keyboard::IsPressed(Input::Keyboard::W)) {
      dino->position.y = dino->position.y -= VELOCITY;
      dino_animation.play(delta_time, RUNNING);
      game.ctx.sound->play(delta_time, footstep_sound);
    } else if (Input::Keyboard::IsPressed(Input::Keyboard::A)) {
      dino->flip = true;
      dino->position.x = dino->position.x -= VELOCITY;
      dino_animation.play(delta_time, RUNNING);
      game.ctx.sound->play(delta_time, footstep_sound);
    } else if (Input::Keyboard::IsPressed(Input::Keyboard::S)) {
      dino->position.y = dino->position.y += VELOCITY;
      dino_animation.play(delta_time, RUNNING);
      game.ctx.sound->play(delta_time, footstep_sound);
    } else if (Input::Keyboard::IsPressed(Input::Keyboard::D)) {
      dino->flip = false;
      dino->position.x = dino->position.x += VELOCITY;
      dino_animation.play(delta_time, RUNNING);
      game.ctx.sound->play(delta_time, footstep_sound);
    } else {
      dino_animation.play(delta_time, IDLE);
    }

    Input::Keyboard::IsPressed(Input::Keyboard::ONE, [&]() -> void {
      level_layer->toggle_fill();
      Util::Time::Delay(100);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::TWO, [&]() -> void {
      level_layer->toggle_rect();
      Util::Time::Delay(100);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::THREE, [&]() -> void {
      level_layer->toggle_hide();
      Util::Time::Delay(100);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });

    scene.update(delta_time);
    scene.draw();
  });

  return 0;
}
