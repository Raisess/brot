#include "../common/Vec2.h"
#include "Physics.h"

bool Engine::Physics::Collision::IsColliding(const Entity& entity_a, const Entity& entity_b) {
  return Collision::CheckCollison(entity_a, entity_b);
}

void Engine::Physics::Collision::IsColliding(const Entity& entity_a, const Entity& entity_b, const CollisionCallback& callback) {
  if (Collision::CheckCollison(entity_a, entity_b)) {
    return callback(entity_a, entity_b);
  }
}

void Engine::Physics::Collision::IsColliding(const Entity& entity_a, const Entity& entity_b, const CollisionCallbackNoParam& callback) {
  if (Collision::CheckCollison(entity_a, entity_b)) {
    return callback();
  }
}

bool Engine::Physics::Collision::Overlapping(const Vec2& point_a, const Vec2& point_b) {
  return point_a[1] >= point_b[0] && point_a[0] <= point_b[1];
}

bool Engine::Physics::Collision::CheckCollison(const Entity& entity_a, const Entity& entity_b) {
  Vec2 x_point_a = { entity_a.position.x, entity_a.position.x + entity_a.size.width };
  Vec2 x_point_b = { entity_b.position.x, entity_b.position.x + entity_b.size.width };
  Vec2 y_point_a = { entity_a.position.y, entity_a.position.y + entity_a.size.height };
  Vec2 y_point_b = { entity_b.position.y, entity_b.position.y + entity_b.size.height };

  return Overlapping(x_point_a, x_point_b) && Overlapping(y_point_a, y_point_b);
}
