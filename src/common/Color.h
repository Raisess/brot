#pragma once

namespace Common {

class Color {
public:
  int red;
  int green;
  int blue;
  int alpha;

  Color(int red = 255, int green = 255, int blue = 255, int alpha = 255)
    : red(red), green(green), blue(blue), alpha(alpha) {}
};

}
