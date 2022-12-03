#include <cstdint>
#include <iostream>
#include "RoomObject.h"

#define SIDE_TO_STR(side) std::to_string(static_cast<uint8_t>(side))

#define DOOR_OFFSET Common::Vec2({ 30, 0 })
#define LEFT_DOOR_COLOR { 0, 255, 0 }
#define RIGHT_DOOR_COLOR LEFT_DOOR_COLOR
#define BOTTOM_DOOR_COLOR { 0, 0, 255 }

RoomObject::RoomObject(const Engine::GameContext& game_ctx)
  : Engine::Entity(game_ctx, "RoomObject") {
  this->fill = true;
  this->rect = true;
  this->size = { 700, 500 };
  this->color = { 255, 0, 0 };

  this->position = (game_ctx.window->get_size() / 2).xy() - (this->size / 2).xy();
}

RoomObject::~RoomObject() {}

RoomDoorObject::RoomDoorObject(
  const Engine::GameContext& game_ctx,
  const RoomObject& room,
  const RoomDoorObject::Side& side
) : Engine::Entity(game_ctx, "RoomDoorObject_" + SIDE_TO_STR(side)) {
  this->fill = true;
  this->rect = true;
  this->size = { 100, 20 };

  switch (side) {
    case RoomDoorObject::Side::LEFT:
      this->color = LEFT_DOOR_COLOR;
      this->position = room.position + DOOR_OFFSET;
      break;
    case RoomDoorObject::Side::RIGHT:
      this->color = RIGHT_DOOR_COLOR;
      this->position = Common::Vec2(
        (room.position.x + room.size.width) - this->size.width, room.position.y
      ) + DOOR_OFFSET.inverse();
      break;
    case RoomDoorObject::Side::BOTTOM:
      this->color = BOTTOM_DOOR_COLOR;
      this->position = Common::Vec2(
        (room.position.x + (room.size.width / 2)) - (this->size.width / 2),
        (room.position.y + room.size.height) - this->size.height
      );
      break;
  }
}

RoomDoorObject::~RoomDoorObject() {}
