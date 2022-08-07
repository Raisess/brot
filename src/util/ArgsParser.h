#pragma once

#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>
#include "Logger.h"

namespace Util {

using Arguments = std::unordered_map<std::string, std::string>;
using Tuple = std::array<std::string, 2>;
using PlainArguments = std::vector<std::string>;

class ArgsParser {
public:
  static Arguments Parse(int argc, char* argv[]) {
    PlainArguments args = ArgsParser::ToStringVector(argc, argv);
    Arguments map = std::unordered_map<std::string, std::string>();

    if (!args.size()) {
      return map;
    }

    for (auto arg : args) {
      if (arg.substr(0, 2) == "--") {
        Tuple tuple = ArgsParser::ParseDoubleHifen(arg);
        map[tuple[0]] = tuple[1];
      } else {
        Logger::Error("Invalid argument: " + arg);
        exit(1);
      }
    }

    return map;
  }

private:
  static Tuple ParseDoubleHifen(const std::string& arg) {
    size_t key_size = 0;

    for (size_t i = 2; i < arg.size(); i++) {
      if (arg.substr(i, 1) == "=") {
        break;
      }

      key_size++;
    }

    std::string key = arg.substr(2, key_size);
    std::string value = arg.substr(key_size + 3, arg.size() - (key_size + 3));

    return { key, value };
  }

  static PlainArguments ToStringVector(int argc, char* argv[]) {
    if (argc == 1) {
      return {};
    }

    PlainArguments vec;

    for (int i = 1; i < argc; i++) {
      vec.push_back(std::string(argv[i]));
    }

    return vec;
  }
};

}
