#include <ctime>
#include <iostream>
#include <memory>
#include "../../src/common/Size.h"
#include "../../src/engine/Entity.h"
#include "../../src/engine/Game.h"
#include "../../src/engine/Layer.h"
#include "../../src/engine/Physics.h"
#include "../../src/engine/Scene.h"
#include "../../src/engine/UI.h"
#include "../../src/gfx/Text.h"
#include "../../src/input/Keyboard.h"
#include "../../src/util/ArgsParser.h"

#define POINT_OFFSET 50
#define PLAYER_OFFSET 10
#define PLAYER_VEL 10
#define BALL_VEL 10

using namespace Common;
using namespace Engine;

class PointUI : public UI {
public:
  PointUI(const GameContext& game_ctx, const std::shared_ptr<GFX::Font>& font)
    : UI(game_ctx, "points_ui", font) {
    size = { 70, 80 };
    position.y = POINT_OFFSET;
  }
};

class Player : public Entity {
public:
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
  Ball(const GameContext& game_ctx, const Size& window_size)
    : Entity(game_ctx, "ball", nullptr),
      _initial_pos({
        ((window_size.width / 2) - (size.width / 2)),
        ((window_size.height / 2) - (size.height / 2)),
      }) {
    fill = true;
    size = { 30, 30 };
    position = _initial_pos;

    srand(time(nullptr));
    _hside = rand() % 2;
    _vside = rand() % 2;
  }

  void to_left() {
    _hside = 0;
  }

  void to_right() {
    _hside = 1;
  }

  void reset() {
    _hside = 0;
    _vside = 0;
    _vel = BALL_VEL;
    position = _initial_pos;
  }

  int tick(const Size& limit) {
    if (_hside) {
      position.x += _vel;
    } else {
      position.x -= _vel;
    }
    if (_vside) {
      position.y += _vel;
    } else {
      position.y -= _vel;
    }

    // limits collision checks
    if (position.y <= 0) {
      _vside = 1;
    } else if (position.y >= (limit.height - size.height)) {
      _vside = 0;
    }
    if (position.x <= 0) {
      return 2; // increase point to player 2
    } else if (position.x >= (limit.width - size.width)) {
      return 1; // increase point to player 1
    }

    return 0;
  }

  void increase_vel() {
    _vel = std::min(_vel + 2, (unsigned int) 30);
  }

private:
  unsigned int _vside = 0; // 0: up, 1: down
  unsigned int _hside = 0; // 0: left, 1: right
  unsigned int _vel = BALL_VEL;
  Vec2 _initial_pos;
};

int main(int argc, char* argv[]) {
  Game game("pong", argc, argv);
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
      ball->increase_vel();
    });
    Physics::Collision::IsColliding(*player_two, *ball, [&]() -> void {
      ball->to_left();
      ball->increase_vel();
    });

    const int to_increase_point = ball->tick(window_size);
    if (to_increase_point) {
      player_one->reset();
      player_two->reset();
      ball->reset();
    }
    if (to_increase_point == 1) {
      player_one->points++;
    } else if (to_increase_point == 2) {
      player_two->points++;
    }

    player_one_points->text = std::to_string(player_one->points);
    player_two_points->text = std::to_string(player_two->points);
    scene.update(dt);
    scene.draw();
  });

  return 0;
}
