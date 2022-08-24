#include "../../common/Vec2.h"
#include "Physics.h"

bool Engine::Physics::Collision::IsColliding(const Node& node_a, const Node& node_b) {
  return Collision::CheckCollison(node_a, node_b);
}

void Engine::Physics::Collision::IsColliding(const Node& node_a, const Node& node_b, const CollisionCallback& callback) {
  if (Collision::CheckCollison(node_a, node_b)) {
    return callback(node_a, node_b);
  }
}

void Engine::Physics::Collision::IsColliding(const Node& node_a, const Node& node_b, const CollisionCallbackNoParam& callback) {
  if (Collision::CheckCollison(node_a, node_b)) {
    return callback();
  }
}

bool Engine::Physics::Collision::Overlapping(const Common::Vec2& point_a, const Common::Vec2& point_b) {
  return point_a[1] >= point_b[0] && point_a[0] <= point_b[1];
}

bool Engine::Physics::Collision::CheckCollison(const Node& node_a, const Node& node_b) {
  Common::Vec2 x_point_a = { node_a.position.x, node_a.position.x + node_a.size.width };
  Common::Vec2 x_point_b = { node_b.position.x, node_b.position.x + node_b.size.width };
  Common::Vec2 y_point_a = { node_a.position.y, node_a.position.y + node_a.size.height };
  Common::Vec2 y_point_b = { node_b.position.y, node_b.position.y + node_b.size.height };

  return Overlapping(x_point_a, x_point_b) && Overlapping(y_point_a, y_point_b);
}
