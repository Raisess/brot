#pragma once

#include <vector>
#include "Entity.h"

namespace Engine {

class Layer {
public:
  std::vector<std::shared_ptr<Entity>> entities;

  void update() const;
  void draw() const;
  void hide();
  void unhide();
  void toggle_hide();
  void fill();
  void unfill();
  void toggle_fill();

private:
  bool _hidden = false;
  bool _filled = false;
};

}
