#include "../util/Logger.h"
#include "NodeContainer.h"

Engine::NodeContainer::NodeContainer(const std::string& id)
  : Node(id, Node::Type::CONTAINER) {
  Util::Logger::Debug("Create container: " + _id);
}

Engine::NodeContainer::~NodeContainer() {
  Util::Logger::Debug("Delete container: " + _id);
}

void Engine::NodeContainer::update(int delta_time) {
  for (auto node : nodes) {
    node->flip = flip;
    node->fill = fill;
    node->rect = rect;
    node->angle = angle;
    node->position = position + node->offset;
    node->update(delta_time);
  }
}

void Engine::NodeContainer::draw() const {
  if (hide) return;

  for (auto node : nodes) {
    node->draw();
  }
}
