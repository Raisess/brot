#include "../../util/Logger.h"
#include "SpriteManager.h"

bool Engine::SpriteManager::Instancied = false;
Engine::SpriteManager Engine::SpriteManager::Create(const std::string& base_path) {
  if (!SpriteManager::Instancied) {
    SpriteManager::Instancied = true;
    return SpriteManager(base_path);
  }

  Util::Logger::Error("Can't create multiple instaces of a SpriteManager");
  exit(1);
}

Engine::SpriteManager::SpriteManager(const std::string& base_path) : base_path(base_path) {}

Engine::SpriteManager::~SpriteManager() {
  free();
}

void Engine::SpriteManager::load(const std::vector<std::string>& paths) {
  for (auto path : paths) {
    this->_sprite_collection.push_back(Sprite::Shared(base_path + path));
  }
}

void Engine::SpriteManager::free() {
  for (auto sprite : this->_sprite_collection) {
    sprite.reset();
    delete sprite.get();
  }
}

std::shared_ptr<Engine::Sprite> Engine::SpriteManager::get(const std::string& path) {
  for (auto sprite : this->_sprite_collection) {
    if (sprite->path == base_path + path) return sprite;
  }

  return nullptr;
}
