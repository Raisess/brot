#include "Layer.h"

void Engine::Layer::update() const {
  for (auto entity : entities) {
    entity->update();
  }
}

void Engine::Layer::draw() const {
  for (auto entity : entities) {
    entity->draw();
  }
}

void Engine::Layer::hide() {
  _hidden = true;
  for (auto entity : entities) {
    entity->hide();
  }
}

void Engine::Layer::unhide() {
  _hidden = false;
  for (auto entity : entities) {
    entity->unhide();
  }
}

void Engine::Layer::toggle_hide() {
  if (_hidden) {
    unhide();
  } else {
    hide();
  }
}
