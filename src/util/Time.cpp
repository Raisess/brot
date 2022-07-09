#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Time.h"

void Util::Time::delay(unsigned int ms) {
#ifdef _WIN32
  Sleep(ms);
#else
  sleep(ms / 1000);
#endif
}
