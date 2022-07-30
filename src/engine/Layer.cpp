#include "Layer.h"

void Engine::Layer::update(int delta_time) const {
  for (auto node : nodes) {
    node->update(delta_time);
  }
}

void Engine::Layer::draw() const {
  for (auto node : nodes) {
    node->draw();
  }
}

void Engine::Layer::hide() {
  _hidden = true;
  for (auto node : nodes) {
    node->hide = true;
  }
}

void Engine::Layer::unhide() {
  _hidden = false;
  for (auto node : nodes) {
    node->hide = false;
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
  for (auto node : nodes) {
    node->fill = true;
  }
}

void Engine::Layer::unfill() {
  _filled = false;
  for (auto node : nodes) {
    node->fill = false;
  }
}

void Engine::Layer::toggle_fill() {
  if (_filled) {
    unfill();
  } else {
    fill();
  }
}

void Engine::Layer::rect() {
  _rected = true;
  for (auto node : nodes) {
    node->rect = true;
  }
}

void Engine::Layer::unrect() {
  _rected = false;
  for (auto node : nodes) {
    node->rect = false;
  }
}

void Engine::Layer::toggle_rect() {
  if (_rected) {
    unrect();
  } else {
    rect();
  }
}
