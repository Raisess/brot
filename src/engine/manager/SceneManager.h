#pragma once

#include <functional>
#include <unordered_map>
#include <vector>
#include "../core/Scene.h"
#include "../object/_Node.h"

namespace Engine {

class SceneManager {
public:
  static SceneManager Create(std::vector<std::string>&&);
  ~SceneManager();

  std::shared_ptr<Scene> get(const std::string& scene_id);
  std::shared_ptr<Scene> load(const std::string& scene_id, unsigned int layer_idx, std::vector<std::shared_ptr<Node>>);
  void use(const std::string& scene_id, unsigned int delta_time, std::function<void(void)>);
  void use(const std::string& scene_id, unsigned int delta_time);

private:
  static bool Instantiated;
  std::unordered_map<std::string, std::shared_ptr<Scene>> _scene_collection;

  SceneManager(std::vector<std::string>&&);
};

}
