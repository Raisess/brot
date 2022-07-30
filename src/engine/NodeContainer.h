#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "_Node.h"

namespace Engine {

class NodeContainer : public Node {
public:
  std::vector<std::shared_ptr<Node>> nodes;

  NodeContainer(const std::string& id);
  ~NodeContainer();

  void update(int delta_time) final override;
  void draw() const final override;
};

}
