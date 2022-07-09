#pragma once

namespace Common {

class Vec2 {
public:
  int x;
  int y;

  Vec2(int x, int y);

  Vec2 operator+(Vec2 vec);
  Vec2 operator+(int value);
  Vec2 operator*(Vec2 vec);
  Vec2 operator*(int value);
};

}
