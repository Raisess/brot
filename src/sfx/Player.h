#pragma once

#include "Sound.h"

namespace SFX {

class Player {
public:
  enum Channel {
    AUTO = -1,
    MONO = 1,
    STEREO,
  };

  Player(Channel channel = Channel::STEREO);
  ~Player();

  void play(int delta_time, const Sound& sound, Channel channel = Channel::AUTO);
  void restart();

private:
  unsigned int _elapsed_time = 0;
  bool _playing = false;
};

}
