#pragma once

#include <memory>

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T, typename... K>
class Sharable {
public:
  static Shared<T> Share(K&& ...args) {
    return std::make_shared<T>(args...);
  }
};
