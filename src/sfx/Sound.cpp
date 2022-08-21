#include "../util/Logger.h"
#include "Sound.h"

SFX::Sound::Sound(const std::string& path, unsigned int duration)
  : _duration(duration), _volume(MaxVolume) {
  Util::Logger::Debug("Create Sound: " + path);
  sdl_value = Mix_LoadWAV(path.c_str());

  if (sdl_value == nullptr) {
    Util::Logger::Error("Error loading sound: " + path);
    exit(1);
  }
}

SFX::Sound::~Sound() {
  Mix_FreeChunk(sdl_value);
  Util::Logger::Debug("Delete Sound");
}

void SFX::Sound::set_volume(unsigned int volume) {
  _volume = std::min((int) volume, (int) MaxVolume);
  sdl_value->volume = _volume;
}
