#include "Vec2.h"

namespace Common {

Vec2::Vec2(int x, int y) : x(x), y(y) {}

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
