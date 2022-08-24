#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include "Layer.h"

namespace Engine {

class Scene {
public:
  Scene(const std::string& id);

  void update(int delta_time) const;
  void draw() const;
  std::shared_ptr<Layer> push_layer();
  std::shared_ptr<Layer> get_layer(int index);
  size_t count_layer() const;
  void pop_layer();
  const std::string id() const;

private:
  std::string _id;
  std::vector<std::shared_ptr<Layer>> _layers;
};

}
