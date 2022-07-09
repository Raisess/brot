#pragma once

#include <assert.h>

namespace Common {

class Color {
public:
  int red;
  int green;
  int blue;
  int alpha;

  Color(int red = 255, int green = 255, int blue = 255, int alpha = 255)
    : red(red), green(green), blue(blue), alpha(alpha) {
    assert(red >= 0 && red <= 255);
    assert(blue >= 0 && blue <= 255);
    assert(green >= 0 && green <= 255);
    assert(alpha >= 0 && alpha <= 255);
  }
};

}
