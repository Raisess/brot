#pragma once

#include <iostream>

namespace Common {

class Vec2 {
public:
  int x;
  int y;

  Vec2(int x, int y) : x(x), y(y) {}

  std::string to_print_string() const {
    return "{ x: " + std::to_string(x) + ", y: " + std::to_string(y) + " }";
  }

  int operator[](int index) const {
    return index == 0 ? x : y;
  }

  Vec2 operator+(const Vec2& vec) const {
    return Vec2(x + vec.x, y + vec.y);
  }

  Vec2 operator+(int value) const {
    return Vec2(x + value, y + value);
  }

  Vec2 operator*(const Vec2& vec) const {
    return Vec2(x * vec.x, y * vec.y);
  }

  Vec2 operator*(int value) const {
    return Vec2(x * value, y * value);
  }
};

}
