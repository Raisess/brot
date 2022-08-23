#include <brot/gfx/Window.h>
#include <brot/util/Logger.h>
#include <brot/sfx/Player.h>
#include <brot/sfx/Sound.h>

#define SOUND_PATH "../../assets/sounds/footstep.wav"

int main() {
  GFX::Window window("Brot Engine | SFX Test", { 800, 600 }, false);
  SFX::Player player;
  SFX::Sound sound(SOUND_PATH, 5000);

  Util::Logger::Log("DURATION", std::to_string(sound.get_duration()));
  Util::Logger::Log("VOLUME", std::to_string(sound.get_volume()));

  window.loop([&](int delta_time) -> void {
    player.play(delta_time, sound);
  });

  return 0;
}
