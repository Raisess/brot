#pragma once

#include <functional>
#include "Entity.h"

namespace Engine {

class Physics {

using CollisionCallback = std::function<void(const Entity&, const Entity&)>;
using CollisionCallbackNoParam = std::function<void(void)>;

public:
  class Collision {
  public:
    static bool IsColliding(const Entity& entity_a, const Entity& entity_b);
    static void IsColliding(const Entity& entity_a, const Entity& entity_b, const CollisionCallback& callback);
    static void IsColliding(const Entity& entity_a, const Entity& entity_b, const CollisionCallbackNoParam& callback);
    static bool Overlapping(const Vec2& point_a, const Vec2& point_b);

  private:
    static bool CheckCollison(const Entity& entity_a, const Entity& entity_b);
  };

  class Gravity {};
};

}
