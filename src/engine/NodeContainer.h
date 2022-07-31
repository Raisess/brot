#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "../_Sharable.h"
#include "_Node.h"

namespace Engine {

class NodeContainer
  : public Node,
    public Sharable<NodeContainer, const std::string&> {
public:
  std::vector<Shared<Node>> nodes;

  NodeContainer(const std::string& id);
  ~NodeContainer();

  void update(int delta_time) final override;
  void draw() const final override;
};

}
