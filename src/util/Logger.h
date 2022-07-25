#pragma once

#include <iostream>

#define DEBUG_LOG 1

namespace Util {

class Logger {
public:
  static void Log(const std::string& message) {
    Logger::_log("LOG", message);
  }

  static void Error(const std::string& message) {
    Logger::_log("ERROR", message);
  }

  static void Debug(const std::string& message) {
    if (DEBUG_LOG) {
      Logger::_log("DEBUG", message);
    }
  }

private:
  static void _log(const std::string& type, const std::string& message) {
    std::cout << "> " << type << ": " << message << std::endl;
  }
};

}
