#pragma once

#include <iostream>
#include <map>
#include <vector>
#include "Logger.h"

namespace Util {

using Arguments = std::map<std::string, std::string>;

class ArgsParser {
public:
  static Arguments Parse(int argc, char* argv[]) {
    auto args = ArgsParser::ToStringVector(argc, argv);
    auto map = std::map<std::string, std::string>();

    if (!args.size()) {
      return map;
    }

    for (auto arg : args) {
      if (arg.substr(0, 2) == "--") {
        std::string key;
        std::string value;
        int side = 0;

        for (int i = 2; i < arg.size(); i++) {
          std::string charc = arg.substr(i, 1);

          if (charc == "=") {
            side = 1;
            continue;
          }

          if (side == 0) {
            key += charc;
          } else {
            value += charc;
          }
        }

        map[key] = value;
      } else {
        Logger::Error("Invalid argument: " + arg);
        exit(1);
      }
    }

    return map;
  }

private:
  static std::vector<std::string> ToStringVector(int argc, char* argv[]) {
    if (argc == 1) {
      return {};
    }

    std::vector<std::string> vec;

    for (int i = 1; i < argc; i++) {
      vec.push_back(std::string(argv[i]));
    }

    return vec;
  }
};

}
