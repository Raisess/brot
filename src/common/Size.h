#pragma once

#include <assert.h>
#include <iostream>

namespace Common {

class Size {
public:
  int width;
  int height;

  Size(int width, int height) : width(width), height(height) {
    assert(width >= 0);
    assert(height >= 0);
  }

  std::string to_print_string() const {
    return " { width: " + std::to_string(width) + ", height: " + std::to_string(height) + " } ";
  }

  Size operator+(const Size& size) const {
    return Size(width + size.width, height + size.height);
  }

  Size operator-(const Size& size) const {
    return Size(width - size.width, height - size.height);
  }
};

}
