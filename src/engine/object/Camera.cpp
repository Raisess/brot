#include "../../util/Logger.h"
#include "Camera.h"

void Engine::Camera::Move(Layer& reference, const Common::Vec2& position, const Common::Vec2& offset) {
  for (auto node : reference.nodes) {
    node->offset = (position + offset).inverse();
  }
}

void Engine::Camera::Zoom(Layer& reference, int value) {
  for (auto node : reference.nodes) {
    node->size = node->size + value;
  }
}
