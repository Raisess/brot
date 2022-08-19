#include <iostream>
#include <memory>
#include "../../src/common/Size.h"
#include "../../src/gfx/Text.h"
#include "../../src/input/Keyboard.h"
#include "../../src/util/ArgsParser.h"
#include "../../src/util/Number.h"
#include "../../src/engine/core/Game.h"
#include "../../src/engine/core/Layer.h"
#include "../../src/engine/core/Scene.h"
#include "../../src/engine/object/Entity.h"
#include "../../src/engine/object/Physics.h"
#include "../../src/engine/object/UI.h"

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

  Player(const GameContext& game_ctx, const Size& window_size)
    : Entity(game_ctx, "player", nullptr),
      _initial_pos(0) {
    fill = true;
    size = { 30, 150 };
    _initial_pos = (window_size.height / 2) - (size.height / 2);
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

  Ball(const GameContext& game_ctx, const Size& window_size)
    : Entity(game_ctx, "ball", nullptr),
      _initial_pos({
        ((window_size.width / 2) - (size.width / 2)),
        ((window_size.height / 2) - (size.height / 2)),
      }) {
    fill = true;
    size = { 30, 30 };
    reset();
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

  Player::Num tick(const Size& limit) {
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
    if (position.x <= 0) {
      return Player::Num::TWO; // increase point to player 2
    } else if (position.x >= (limit.width - size.width)) {
      return Player::Num::ONE; // increase point to player 1
    }

    return Player::Num::NONE;
  }

private:
  unsigned int _vel = BALL_VEL;
  unsigned int _vside;
  unsigned int _hside;
  Vec2 _initial_pos;
};

int main(int argc, char* argv[]) {
  Game game("pong", argc, argv);
  game.toggle_info();
  Scene scene("main");

  const auto window_size = game.ctx.window_ctx->get_size();
  auto ui_layer = scene.push_layer();
  auto level_layer = scene.push_layer();

  auto player_one_points = std::make_shared<PointUI>(game.ctx, game.ctx.engine_font);
  player_one_points->position.x = POINT_OFFSET;
  ui_layer->nodes.push_back(player_one_points);
  auto player_two_points = std::make_shared<PointUI>(game.ctx, game.ctx.engine_font);
  player_two_points->position.x = (window_size.width - player_two_points->size.width) - POINT_OFFSET;
  ui_layer->nodes.push_back(player_two_points);

  auto player_one = std::make_shared<Player>(game.ctx, window_size);
  player_one->position.x = PLAYER_OFFSET;
  level_layer->nodes.push_back(player_one);
  auto player_two = std::make_shared<Player>(game.ctx, window_size);
  player_two->position.x = (window_size.width - player_two->size.width) - PLAYER_OFFSET;
  level_layer->nodes.push_back(player_two);
  auto ball = std::make_shared<Ball>(game.ctx, window_size);
  level_layer->nodes.push_back(ball);

  game.loop([&](int dt) -> void {
    Input::Keyboard::OnPressed(Input::Keyboard::ESC, [&]() -> void {
      return game.end();
    });
    Input::Keyboard::OnPressed(Input::Keyboard::W, [&]() -> void {
      player_one->position.y = std::max(player_one->position.y - PLAYER_VEL, 0);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::S, [&]() -> void {
      player_one->position.y = std::min(player_one->position.y + PLAYER_VEL, window_size.height - player_one->size.height);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::UP, [&]() -> void {
      player_two->position.y = std::max(player_two->position.y - PLAYER_VEL, 0);
    });
    Input::Keyboard::OnPressed(Input::Keyboard::DOWN, [&]() -> void {
      player_two->position.y = std::min(player_two->position.y + PLAYER_VEL, window_size.height - player_two->size.height);
    });

    Physics::Collision::IsColliding(*player_one, *ball, [&]() -> void {
      ball->to_right();
    });
    Physics::Collision::IsColliding(*player_two, *ball, [&]() -> void {
      ball->to_left();
    });

    const Player::Num to_increase_point = ball->tick(window_size);
    switch (to_increase_point) {
      case Player::Num::ONE:
        player_one->points++;
        player_one_points->text = std::to_string(player_one->points);
        break;
      case Player::Num::TWO:
        player_two->points++;
        player_two_points->text = std::to_string(player_two->points);
        break;
      case Player::Num::NONE:
        break;
    }

    if (to_increase_point != Player::Num::NONE) {
      player_one->reset();
      player_two->reset();
      ball->reset();
    }

    scene.update(dt);
    scene.draw();
  });

  return 0;
}
