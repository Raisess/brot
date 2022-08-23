#include <iostream>
#include <memory>
#include "../../src/common/Size.h"
#include "../../src/gfx/Text.h"
#include "../../src/input/Keyboard.h"
#include "../../src/util/Number.h"
#include "../../src/engine/core/Game.h"
#include "../../src/engine/core/Layer.h"
#include "../../src/engine/core/Scene.h"
#include "../../src/engine/object/Entity.h"
#include "../../src/engine/object/Physics.h"
#include "../../src/engine/object/UI.h"

#define FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"
#define POINT_OFFSET 50
#define PLAYER_OFFSET 10
#define PLAYER_VEL 15
#define BALL_VEL 10

using namespace Common;
using namespace Engine;

class PointUI : public UI {
public:
  PointUI(const GameContext& game_ctx, const std::shared_ptr<GFX::Font>& font)
    : UI(game_ctx, "points_ui", font) {
    size = { 70, 80 };
    position.y = POINT_OFFSET;
    text = "0";
  }
};

class Player : public Entity {
public:
  enum Num {
    NONE = 0,
    ONE,
    TWO,
  };

  unsigned int points = 0;

  Player(const GameContext& game_ctx)
    : Entity(game_ctx, "player"),
      _initial_pos(0) {
    fill = true;
    size = { 30, 150 };
    _initial_pos = (game_ctx.window->get_size().height / 2) - (size.height / 2);
    position.y = _initial_pos;
  }

  void reset() {
    position.y = _initial_pos;
  }

private:
  unsigned int _initial_pos;
};

class Ball : public Entity {
public:
  enum Side {
    LEFT = 0,
    RIGHT,
    UP,
    DOWN,
  };

  Ball(const GameContext& game_ctx)
    : Entity(game_ctx, "ball"),
      _initial_pos({
        ((game_ctx.window->get_size().width / 2) - (size.width / 2)),
        ((game_ctx.window->get_size().height / 2) - (size.height / 2)),
      }) {
    fill = true;
    size = { 30, 30 };
    reset();
  }

  void tick(const Common::Size& limit) {
    if (_hside == Side::RIGHT) {
      position.x += _vel;
    } else {
      position.x -= _vel;
    }
    if (_vside == Side::DOWN) {
      position.y += _vel;
    } else {
      position.y -= _vel;
    }

    // limits collision checks
    if (position.y <= 0) {
      _vside = Side::DOWN;
    } else if (position.y >= (limit.height - size.height)) {
      _vside = Side::UP;
    }
  }

  void to_left() {
    _hside = Side::LEFT;
  }

  void to_right() {
    _hside = Side::RIGHT;
  }

  void reset() {
    _hside = Util::Number::Random(Side::LEFT, Side::RIGHT);
    _vside = Util::Number::Random(Side::UP, Side::DOWN);
    _vel = BALL_VEL;
    position = _initial_pos;
  }

private:
  unsigned int _vel = BALL_VEL;
  unsigned int _vside;
  unsigned int _hside;
  Vec2 _initial_pos;
};

class Pong {
public:
  std::shared_ptr<Player> player_one;
  std::shared_ptr<PointUI> player_one_ui;
  std::shared_ptr<Player> player_two;
  std::shared_ptr<PointUI> player_two_ui;
  std::shared_ptr<Ball> ball;

  Pong(const GameContext& game_ctx, const std::shared_ptr<GFX::Font>& game_font)
    : player_one(std::make_shared<Player>(game_ctx)),
      player_one_ui(std::make_shared<PointUI>(game_ctx, game_font)),
      player_two(std::make_shared<Player>(game_ctx)),
      player_two_ui(std::make_shared<PointUI>(game_ctx, game_font)),
      ball(std::make_shared<Ball>(game_ctx)) {}

  void tick(const Size& limit) {
    ball->tick(limit);

    Physics::Collision::IsColliding(*player_one, *ball, [&]() -> void {
      ball->to_right();
    });
    Physics::Collision::IsColliding(*player_two, *ball, [&]() -> void {
      ball->to_left();
    });

    if (ball->position.x <= 0) {
      player_two->points++;
      player_two_ui->text = std::to_string(player_two->points);
      player_one->reset();
      player_two->reset();
      ball->reset();
    } else if (ball->position.x >= (limit.width - ball->size.width)) {
      player_one->points++;
      player_one_ui->text = std::to_string(player_one->points);
      player_one->reset();
      player_two->reset();
      ball->reset();
    }
  }
};

int main(int argc, char* argv[]) {
  Game game("pong", argc, argv);
  game.toggle_info();
  Scene scene("main");

  const auto window_size = game.ctx.window->get_size();
  auto ui_layer = scene.push_layer();
  auto level_layer = scene.push_layer();

  Pong pong(game.ctx, std::make_shared<GFX::Font>(FONT_PATH));
  pong.player_one->position.x = PLAYER_OFFSET;
  pong.player_one_ui->position.x = POINT_OFFSET;
  pong.player_two->position.x = (window_size.width - pong.player_two->size.width) - PLAYER_OFFSET;
  pong.player_two_ui->position.x = (window_size.width - pong.player_two_ui->size.width) - POINT_OFFSET;

  level_layer->nodes.push_back(pong.player_one);
  level_layer->nodes.push_back(pong.player_two);
  level_layer->nodes.push_back(pong.ball);
  ui_layer->nodes.push_back(pong.player_one_ui);
  ui_layer->nodes.push_back(pong.player_two_ui);

  game.loop([&](int dt) -> void {
    Input::Keyboard::IsPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::IsPressed(Input::Keyboard::W, [&]() -> void {
      pong.player_one->position.y = std::max(pong.player_one->position.y - PLAYER_VEL, 0);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::S, [&]() -> void {
      pong.player_one->position.y = std::min(pong.player_one->position.y + PLAYER_VEL, window_size.height - pong.player_one->size.height);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::UP, [&]() -> void {
      pong.player_two->position.y = std::max(pong.player_two->position.y - PLAYER_VEL, 0);
    });
    Input::Keyboard::IsPressed(Input::Keyboard::DOWN, [&]() -> void {
      pong.player_two->position.y = std::min(pong.player_two->position.y + PLAYER_VEL, window_size.height - pong.player_two->size.height);
    });

    pong.tick(window_size);
    scene.update(dt);
    scene.draw();
  });

  return 0;
}
