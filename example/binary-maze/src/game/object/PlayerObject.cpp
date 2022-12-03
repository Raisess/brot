#include <brot/input/Keyboard.h>
#include "PlayerObject.h"

uint8_t PlayerObject::Velocity = 10;

PlayerObject::PlayerObject(const Engine::GameContext& game_ctx)
  : Engine::Entity(game_ctx, "PlayerObject") {
  this->fill = true;
  this->rect = true;
  this->size = { 50, 50 };
  //this->color = { 0, 0, 0 };

  this->position = (game_ctx.window->get_size() / 2).xy() - (this->size / 2).xy();
}

PlayerObject::~PlayerObject() {}

void PlayerObject::on_update(int) {
  Input::Keyboard::IsPressed(Input::Keyboard::W, [this]() {
    this->position.y -= PlayerObject::Velocity;
  });
  Input::Keyboard::IsPressed(Input::Keyboard::A, [this]() {
    this->position.x -= PlayerObject::Velocity;
  });
  Input::Keyboard::IsPressed(Input::Keyboard::S, [this]() {
    this->position.y += PlayerObject::Velocity;
  });
  Input::Keyboard::IsPressed(Input::Keyboard::D, [this]() {
    this->position.x += PlayerObject::Velocity;
  });
}
