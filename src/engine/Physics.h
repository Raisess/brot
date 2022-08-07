#pragma once

#include "Entity.h"

namespace Engine {

class Physics {
public:

  class Collision {
  public:
    static bool Overlapping(const Vec2& point_a, const Vec2& point_b);
    static bool IsColliding(const Entity& entity_a, const Entity& entity_b);
  };

  class Gravity {

  };
};

}
