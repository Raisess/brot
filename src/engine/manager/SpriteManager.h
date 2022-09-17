#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include "../object/Sprite.h"

namespace Engine {

class SpriteManager {
public:
  const std::string base_path;

  static SpriteManager Create(const std::string& base_path = "");
  ~SpriteManager();

  void load(const std::vector<std::string>& paths);
  void free();
  std::shared_ptr<Sprite> get(const std::string& path);

private:
  static bool Instancied;
  std::vector<std::shared_ptr<Sprite>> _sprite_collection;

  SpriteManager(const std::string& base_path);
};

}
