#pragma once

#include <assert.h>
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
  void pop_layer();
  size_t count_layer() const;
  std::shared_ptr<Layer> get_layer(int index) const;
  const std::string id() const;

private:
  std::string _id;
  std::vector<std::shared_ptr<Layer>> _layers;
};

}