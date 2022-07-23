#pragma once

#include <assert.h>
#include <iostream>
#include <vector>
#include "Layer.h"

namespace Engine {

class Scene {
public:
  Scene(const std::string& id);

  void update() const;
  void draw() const;
  void push_layer();
  void pop_layer();
  size_t count_layer() const;
  Layer* get_layer(int index) const;
  std::string id() const;

private:
  std::string _id;
  std::vector<Layer*> _layers;
};

}
