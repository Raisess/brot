#pragma once

#include <cassert>
#include <random>

namespace Util {

class Number {
public:
  static int Random(int start, int end) {
    assert(end > start);
    std::random_device random_device;
    std::default_random_engine engine(random_device());
    std::uniform_int_distribution<int> dist(start, end);
    return dist(engine);
  }
};

}
