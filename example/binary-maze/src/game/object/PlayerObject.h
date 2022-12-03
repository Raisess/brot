#pragma once

#include <cstdint>
#include <brot/engine/core/Game.h>
#include <brot/engine/object/Entity.h>

class PlayerObject : public Engine::Entity {
public:
  PlayerObject(const Engine::GameContext&);
  ~PlayerObject();

  void on_update(int) final override;

private:
  static uint8_t Velocity;
};
