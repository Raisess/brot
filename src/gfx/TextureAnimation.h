#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>
#include "TextureComponent.h"

namespace GFX {

class TextureAnimation {
public:
  using Collection = std::unordered_map<std::string, TextureAnimation>;

  TextureAnimation() {}
  TextureAnimation(const std::vector<std::shared_ptr<GFX::Image>>& images);

  void play(int delta_time, TextureComponent& texture_component);
  void restart();

private:
  std::vector<std::shared_ptr<Image>> _images;
  unsigned int _time_count = 0;
  unsigned int _index = 0;
  bool _paused = false;
};

}
