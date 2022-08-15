#pragma once

#include <iostream>

#define MAX_COLOR 255
#define NORMALIZE_COLOR(v) std::min(std::max(v, 0), MAX_COLOR)

namespace Common {

class Color {
public:
  int red;
  int green;
  int blue;
  int alpha;

  Color(int red = 255, int green = 255, int blue = 255, int alpha = 255)
    : red(NORMALIZE_COLOR(red)), green(NORMALIZE_COLOR(green)), blue(NORMALIZE_COLOR(blue)), alpha(NORMALIZE_COLOR(alpha)) {}
};

}
