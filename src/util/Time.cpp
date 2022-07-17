#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP(ms) usleep(ms * 1000)
#endif

#include "Time.h"

void Util::Time::delay(unsigned int ms) {
  SLEEP(ms);
}
