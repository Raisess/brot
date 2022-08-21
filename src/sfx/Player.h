#pragma once

#include "Sound.h"

namespace SFX {

class Player {
public:
  Player();
  ~Player();

  void play(int delta_time, const Sound& sound);
  void restart();

private:
  unsigned int _elapsed_time = 0;
  bool _playing = false;
};

}
