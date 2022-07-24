#include "Layer.h"

void Engine::Layer::update(int delta_time) const {
  for (auto entity : entities) {
    entity->update(delta_time);
  }

  for (auto ui : uis) {
    ui->update();
  }
}

void Engine::Layer::draw() const {
  for (auto entity : entities) {
    entity->draw();
  }

  for (auto ui : uis) {
    ui->draw();
  }
}

void Engine::Layer::hide() {
  _hidden = true;
  for (auto entity : entities) {
    entity->hide = true;
  }
}

void Engine::Layer::unhide() {
  _hidden = false;
  for (auto entity : entities) {
    entity->hide = false;
  }
}

void Engine::Layer::toggle_hide() {
  if (_hidden) {
    unhide();
  } else {
    hide();
  }
}

void Engine::Layer::fill() {
  _filled = true;
  for (auto entity : entities) {
    entity->fill = true;
  }
}

void Engine::Layer::unfill() {
  _filled = false;
  for (auto entity : entities) {
    entity->fill = false;
  }
}

void Engine::Layer::toggle_fill() {
  if (_filled) {
    unfill();
  } else {
    fill();
  }
}
