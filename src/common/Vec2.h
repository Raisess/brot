#pragma once

#include <iostream>

namespace Common {

class Vec2 {
public:
  int x;
  int y;

  Vec2(int x, int y);

  std::string to_print_string();
  Vec2 operator+(Vec2 vec);
  Vec2 operator+(int value);
  Vec2 operator*(Vec2 vec);
  Vec2 operator*(int value);
};

}
