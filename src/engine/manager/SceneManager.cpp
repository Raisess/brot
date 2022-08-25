#include "../../util/Logger.h"
#include "SceneManager.h"

bool Engine::SceneManager::Instantiated = false;
Engine::SceneManager Engine::SceneManager::Create(std::vector<std::string>&& scenes) {
  if (!SceneManager::Instantiated) {
    SceneManager::Instantiated = true;
    return SceneManager(std::move(scenes));
  }

  Util::Logger::Error("Can't create multiple instaces of a SceneManager");
  exit(1);
}

Engine::SceneManager::SceneManager(std::vector<std::string>&& scenes) {
  for (auto scene : scenes) {
    _scene_collection[scene] = std::make_shared<Scene>(scene);
  }
}

Engine::SceneManager::~SceneManager() {}

std::shared_ptr<Engine::Scene> Engine::SceneManager::get(const std::string& scene_id) {
  return _scene_collection[scene_id];
}

std::shared_ptr<Engine::Scene> Engine::SceneManager::load(
  const std::string& scene_id,
  unsigned int layer_idx,
  std::vector<std::shared_ptr<Node>> nodes
) {
  auto scene = _scene_collection[scene_id];
  auto layer = scene->get_layer(layer_idx);
  layer->nodes = std::move(nodes);
  return scene;
}

void Engine::SceneManager::use(const std::string& scene_id, unsigned int delta_time, std::function<void(void)> callback) {
  callback();
  auto scene = _scene_collection[scene_id];
  scene->update(delta_time);
  scene->draw();
}

void Engine::SceneManager::use(const std::string& scene_id, unsigned int delta_time) {
  auto scene = _scene_collection[scene_id];
  scene->update(delta_time);
  scene->draw();
}
