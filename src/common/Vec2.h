#pragma once

#include <iostream>

namespace Common {

class Vec2 {
public:
  int x;
  int y;

  Vec2(int x, int y) : x(x), y(y) {}

  std::string to_print_string() {
    return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
  }

  Vec2 operator+(Vec2 vec) {
    return Vec2(x + vec.x, y + vec.y);
  }

  Vec2 operator+(int value) {
    return Vec2(x + value, y + value);
  }

  Vec2 operator*(Vec2 vec) {
    return Vec2(x * vec.x, y * vec.y);
  }

  Vec2 operator*(int value) {
    return Vec2(x * value, y * value);
  }
};

}
