#pragma once

#include <functional>
#include "../../common/Vec2.h"
#include "_Node.h"

namespace Engine {

class Physics {

using CollisionCallback = std::function<void(const Node&, const Node&)>;
using CollisionCallbackNoParam = std::function<void(void)>;

public:
  class Collision {
  public:
    static bool IsColliding(const Node&, const Node&);
    static void IsColliding(const Node&, const Node&, const CollisionCallback&);
    static void IsColliding(const Node&, const Node&, const CollisionCallbackNoParam&);
    static bool Overlapping(const Common::Vec2&, const Common::Vec2&);

  private:
    static bool CheckCollison(const Node& entity_a, const Node& entity_b);
  };

  class Gravity {};
};

}
