#pragma once

#include <iostream>
#include "../common/Color.h"
#include "../common/Size.h"
#include "../common/Vec2.h"

namespace Engine {

class Node {
public:
  enum Type {
    ENTITY = 0,
    UI,
    CONTAINER,
  };

  Common::Color color = {};
  Common::Size size = { 0, 0 };
  Common::Vec2 position = { 0, 0 };
  Common::Vec2 offset = { 0, 0 };
  int angle = 0;
  bool hide = false;
  bool fill = false;
  bool flip = false;
  bool rect = false;

  Node(const std::string& id, const Type& type) : _id(id), _type(type) {}

  virtual void update(int delta_time) = 0;
  virtual void draw() = 0;

  const std::string id() const {
    return _id;
  }

  const Type type() const {
    return _type;
  }

protected:
  std::string _id;
  Type _type;
};

}
