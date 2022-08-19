#include "../../util/Logger.h"
#include "Scene.h"

Engine::Scene::Scene(const std::string& id) : _id(id) {
  Util::Logger::Debug("Create Scene: " + id);
}

void Engine::Scene::update(int delta_time) const {
  for (int i = _layers.size() - 1; i >= 0; i--) {
    _layers[i]->update(delta_time);
  }
}

void Engine::Scene::draw() const {
  for (int i = _layers.size() - 1; i >= 0; i--) {
    _layers[i]->draw();
  }
}

std::shared_ptr<Engine::Layer> Engine::Scene::push_layer() {
  _layers.push_back(std::make_shared<Engine::Layer>());
  return _layers[_layers.size() - 1];
}

void Engine::Scene::pop_layer() {
  _layers.pop_back();
}

size_t Engine::Scene::count_layer() const {
  return _layers.size();
}

std::shared_ptr<Engine::Layer> Engine::Scene::get_layer(int index) const {
  assert(index <= _layers.size());
  return _layers[index];
}

const std::string Engine::Scene::id() const {
  return _id;
}
