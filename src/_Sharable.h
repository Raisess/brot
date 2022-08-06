#pragma once

#include <memory>

template<typename T, typename ...Args>
class Sharable {
public:
  static std::shared_ptr<T> Shared(Args&& ...args) {
    return std::make_shared<T>(args...);
  }
};
