#pragma once

#include <memory>
#include <vector>
#include "../object/_Node.h"

namespace Engine {

class Layer {
public:
  std::vector<std::shared_ptr<Node>> nodes;

  void update(int delta_time) const;
  void draw() const;
  void hide();
  void unhide();
  void toggle_hide();
  void fill();
  void unfill();
  void toggle_fill();
  void rect();
  void unrect();
  void toggle_rect();

private:
  bool _hidden = false;
  bool _filled = false;
  bool _rected = false;
};

}
