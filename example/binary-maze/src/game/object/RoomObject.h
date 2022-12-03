#pragma once

#include <brot/engine/core/Game.h>
#include <brot/engine/object/Entity.h>

class RoomObject : public Engine::Entity {
public:
  RoomObject(const Engine::GameContext&);
  ~RoomObject();
};

class RoomDoorObject : public Engine::Entity {
public:
  enum class Side {
    LEFT = 0,
    RIGHT = 1,
    BOTTOM = 2,
  };

  RoomDoorObject(
    const Engine::GameContext&,
    const RoomObject&,
    const RoomDoorObject::Side&
  );
  ~RoomDoorObject();
};
