#pragma once

#include <assert.h>
#include <iostream>
#include <memory>
#include <vector>
#include "Layer.h"

namespace Engine {

class Scene {
public:
  Scene(const std::string& scene_id);

  void update() const;
  void draw() const;
  void push_layer();
  void pop_layer();
  size_t count_layer() const;
  Layer* get_layer(int index) const;
  std::string scene_id() const;

private:
  std::string _scene_id;
  std::vector<Layer*> _layers;
};

}
