#include "../../util/Time.h"
#include "Sprite.h"

Engine::Sprite::Sprite(const std::string& img_path)
  : _image(std::make_shared<GFX::Image>(img_path)), _path(img_path) {}

std::shared_ptr<GFX::Image> Engine::Sprite::image() const {
  Util::Time::delay(SPRITE_DELAY);
  return _image;
}

const std::string Engine::Sprite::path() const {
  return _path;
}
