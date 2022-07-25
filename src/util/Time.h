#pragma once

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP(ms) usleep(ms * 1000)
#endif

namespace Util {

class Time {
public:
  static void Delay(unsigned int ms) {
    SLEEP(ms);
  }

  static bool Wait(unsigned int time, unsigned int timestep, unsigned int& count) {
    if (count >= time) {
      return true;
    }

    count += timestep;
    return count >= time;
  }
};

}
