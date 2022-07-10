#include "Vec2.h"

namespace Common {

Vec2::Vec2(int x, int y) : x(x), y(y) {}

std::string Vec2::to_print_string() {
  return "x: " + std::to_string(x) + ", y: " + std::to_string(y);
}

Vec2 Vec2::operator+(Vec2 vec) {
  return Vec2(x + vec.x, y + vec.y);
}

Vec2 Vec2::operator+(int value) {
  return Vec2(x + value, y + value);
}

Vec2 Vec2::operator*(Vec2 vec) {
  return Vec2(x * vec.x, y * vec.y);
}

Vec2 Vec2::operator*(int value) {
  return Vec2(x * value, y * value);
}

}
