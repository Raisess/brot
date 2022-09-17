#include <iostream>
#include <memory>
#include <brot/input/Keyboard.h>
#include <brot/sfx/Sound.h>
#include <brot/util/Logger.h>
#include <brot/util/Time.h>
#include <brot/engine/core/Game.h>
#include <brot/engine/manager/SceneManager.h>
#include <brot/engine/manager/SpriteManager.h>
#include <brot/engine/object/Camera.h>
#include <brot/engine/object/Entity.h>
#include <brot/engine/object/Physics.h>
#include <brot/engine/object/Sprite.h>
#include <brot/engine/object/SpriteAnimation.h>
#include <brot/engine/object/SpriteAnimationPlayer.h>
#include <brot/engine/object/UI.h>

#define MAIN_SCENE "main_scene"
#define TEXTURE_BASE_PATH "../../assets/sprites/dino/"
#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
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

  SceneManager scene_manager = SceneManager::Create({ MAIN_SCENE });
  SpriteManager sprite_manager = SpriteManager::Create(TEXTURE_BASE_PATH);

  sprite_manager.load({
    "idle_1.png",
    "idle_2.png",
    "idle_3.png",
    "idle_4.png",
    "running_5.png",
    "running_6.png",
    "running_7.png",
    "running_8.png",
    "running_9.png",
    "running_10.png",
    "running_11.png",
    "running_12.png",
    "running_13.png",
  });

  std::shared_ptr<GFX::Font> game_font = GFX::Font::Shared(FONT_PATH);
  SpriteAnimation dino_idle_animation({
    { sprite_manager.get("idle_1.png"), 200 },
    { sprite_manager.get("idle_2.png"), 200 },
    { sprite_manager.get("idle_3.png"), 200 },
    { sprite_manager.get("idle_4.png"), 200 },
  });
  SpriteAnimation dino_running_animation({
    { sprite_manager.get("running_5.png"), 200 },
    { sprite_manager.get("running_6.png"), 200 },
    { sprite_manager.get("running_7.png"), 200 },
    { sprite_manager.get("running_8.png"), 200 },
    { sprite_manager.get("running_9.png"), 200 },
    { sprite_manager.get("running_10.png"), 200 },
    { sprite_manager.get("running_11.png"), 200 },
    { sprite_manager.get("running_12.png"), 200 },
    { sprite_manager.get("running_13.png"), 200 },
  });

  std::shared_ptr<Dino> dino = std::make_shared<Dino>(
    "dino_0",
    game.ctx,
    *sprite_manager.get("idle_1.png"),
    game_font
  );
  dino->position = { 100, 0 };
  SpriteAnimationPlayer dino_animation(*dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });

  std::shared_ptr<Dino> another_dino = std::make_shared<Dino>(
    "dino_1",
    game.ctx,
    *sprite_manager.get("idle_1.png"),
    game_font
  );
  another_dino->flip = true;
  another_dino->position = { 500, 100 };
  SpriteAnimationPlayer another_dino_animation(*another_dino, { { IDLE, dino_idle_animation }, { RUNNING, dino_running_animation } });

  SFX::Sound footstep_sound(SOUND_PATH, 200);
  footstep_sound.set_volume(50);

  std::shared_ptr<Scene> scene = scene_manager.load(MAIN_SCENE, 0, { dino, another_dino });
  std::shared_ptr<Layer> level_layer = scene->get_layer(0);

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

    scene_manager.use(MAIN_SCENE, delta_time);
  });

  return 0;
}
