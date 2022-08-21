#pragma once

#include <iostream>
#include <SDL2/SDL_mixer.h>
#include "../_Sharable.h"
#include "../SDLController.h"

namespace SFX {

class Sound :
  public SDLController<Mix_Chunk*>,
  public Sharable<Sound, const std::string&> {
public:
  static constexpr unsigned int MaxVolume = 128;

  Sound(const std::string& path, unsigned int duration);
  ~Sound();

  const unsigned int get_duration() const {
    return _duration;
  }

  const unsigned int get_volume() const {
    return _volume;
  }

  void set_volume(unsigned int volume);

private:
  unsigned int _duration = 0;
  unsigned int _volume = 100;
};

}
