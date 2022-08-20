#pragma once

#include <iostream>
#include "Vec2.h"

#define MAX_SIZE 1000 * 1000
#define NORMALIZE_SIZE(px) std::min(std::max(px, 0), MAX_SIZE)

namespace Common {

class Size {
public:
  int width;
  int height;

  Size(int width, int height) : width(NORMALIZE_SIZE(width)), height(NORMALIZE_SIZE(height)) {}

  Vec2 xy() const {
    return Vec2(width, height);
  }

  Size inverse() const {
    return Size(-width, -height);
  }

  std::string to_print_string() const {
    return " { width: " + std::to_string(width) + ", height: " + std::to_string(height) + " } ";
  }

  Size operator+(const Size& size) const {
    return Size(width + size.width, height + size.height);
  }

  Size operator+(int value) const {
    return Size(width + value, height + value);
  }

  Size operator-(const Size& size) const {
    return Size(width - size.width, height - size.height);
  }

  Size operator-(int value) const {
    return Size(width - value, height - value);
  }

  Size operator*(const Size& size) const {
    return Size(width * size.width, height * size.height);
  }

  Size operator*(int value) const {
    return Size(width * value, height * value);
  }

  Size operator/(const Size& size) const {
    return Size(width / size.width, height / size.height);
  }

  Size operator/(int value) const {
    return Size(width / value, height / value);
  }
};

}
