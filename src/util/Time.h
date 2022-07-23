#pragma once

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
  static void delay(unsigned int ms) {
    SLEEP(ms);
  }
};

}
