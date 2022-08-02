#pragma once

#include <assert.h>

namespace Common {

class Size {
public:
  int width;
  int height;

  Size(int width, int height) : width(width), height(height) {
    assert(width >= 0);
    assert(height >= 0);
  }

  Size operator+(const Size& size) {
    return Size(width + size.width, height + size.height);
  }

  Size operator-(const Size& size) {
    return Size(width - size.width, height - size.height);
  }
};

}
