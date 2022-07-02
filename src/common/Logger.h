#pragma once

#include <iostream>

namespace Common {

#define DEBUG_LOG 1

class Logger {
public:
  static void error(const std::string& message, unsigned int code = 1) {
    std::cout << "> ERROR: " <<  message << std::endl;
    exit(code);
  }

  static void debug(const std::string& message) {
    if (DEBUG_LOG) {
      std::cout << "> DEGUB: " << message << std::endl;
    }
  }
};

}
