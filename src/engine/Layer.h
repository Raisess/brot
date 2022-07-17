#pragma once

#include <memory>
#include <vector>
#include "./entity/Entity.h"

namespace Engine {

class Layer {
public:
  std::vector<Entity*> entities;

  void update() const;
  void draw() const;
  void hide();
  void unhide();
  void toggle_hide();

private:
  bool _hidden = false;
};

}
