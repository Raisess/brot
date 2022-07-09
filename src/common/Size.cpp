#include <assert.h>
#include "Size.h"

Common::Size::Size(int width, int height) : width(width), height(height) {
  assert(width >= 0);
  assert(height >= 0);
}
