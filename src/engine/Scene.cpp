#include "Scene.h"

Engine::Scene::Scene(const std::string& scene_id)
  : _scene_id(scene_id) {}

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

void Engine::Scene::push_layer() {
  _layers.push_back(new Layer());
}

void Engine::Scene::pop_layer() {
  _layers.pop_back();
}

size_t Engine::Scene::count_layer() const {
  return _layers.size();
}

Engine::Layer* Engine::Scene::get_layer(int index) const {
  assert(index <= _layers.size());
  return _layers[index];
}

std::string Engine::Scene::scene_id() const {
  return _scene_id;
}
