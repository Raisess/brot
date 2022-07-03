#pragma once

namespace Common {

typedef struct {
  int width;
  int height;
} Size;

typedef struct {
  int x;
  int y;
} Position;

typedef struct Color {
  int red = 255;
  int green = 255;
  int blue = 255;
  int alpha = 255;
} Color;

}
