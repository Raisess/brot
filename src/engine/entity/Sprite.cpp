#include "../../util/Time.h"
#include "Sprite.h"

Engine::Sprite::Sprite(const std::string& img_path, unsigned int delay)
  : _image(std::make_shared<GFX::Image>(img_path)), _delay(delay) {}

std::shared_ptr<GFX::Image> Engine::Sprite::image() const {
  Util::Time::delay(_delay);
  return _image;
}
