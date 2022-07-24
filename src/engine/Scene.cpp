#include "../util/Logger.h"
#include "Scene.h"

Engine::Scene::Scene(const std::string& id) : _id(id) {
  Util::Logger::debug("Create Scene: " + id);
}

void Engine::Scene::update() const {
  for (auto layer : _layers) {
    layer->update();
  }
}

void Engine::Scene::draw() const {
  for (auto layer : _layers) {
    layer->draw();
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
