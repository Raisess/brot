#include <SDL2/SDL_mixer.h>
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Player.h"

SFX::Player::Player(Channel channel) {
  if (Mix_OpenAudio(44100, AUDIO_S16SYS, channel, 512) < 0) {
    Util::Logger::Error("Error opening audio");
    exit(1);
  }
}

SFX::Player::~Player() {}

void SFX::Player::play(int delta_time, const Sound& sound, Channel channel) {
  if (sound.get_duration() == 0) return;

  if (Util::Time::Wait(sound.get_duration(), delta_time, _elapsed_time)) {
    restart();
  } else {
    if (!_playing) {
      _playing = true;
      Mix_PlayChannel(channel, sound.get(), 0);
    }
  }
}

void SFX::Player::restart() {
  _elapsed_time = 0;
  _playing = false;
}
