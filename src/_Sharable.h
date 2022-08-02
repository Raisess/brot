#pragma once

#include <memory>

template<typename T, typename... K>
class Sharable {
public:
  static std::shared_ptr<T> Share(K&& ...args) {
    return std::make_shared<T>(args...);
  }
};
