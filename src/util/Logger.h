#pragma once

#include <iostream>

#define DEBUG_LOG 1

namespace Util {

class Logger {
public:
  static void error(const std::string& message) {
    Logger::log("ERROR", message);
  }

  static void debug(const std::string& message) {
    if (DEBUG_LOG) {
      Logger::log("DEBUG", message);
    }
  }

private:
  static void log(const std::string& type, const std::string& message) {
    std::cout << "> " << type << ": " << message << std::endl;
  }
};

}
