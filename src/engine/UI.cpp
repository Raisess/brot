#include "../util/Logger.h"
#include "UI.h"

Engine::UI::UI(const GameContext& game_ctx, const std::string& id, std::shared_ptr<GFX::Font> font)
  : Node(id),
    _component(std::make_unique<GFX::TextComponent>(*game_ctx.render_ctx)),
    _font(font) {
  Util::Logger::Debug("Create UI: " + _id);
}

Engine::UI::~UI() {
  Util::Logger::Debug("Delete UI: " + _id);
}

void Engine::UI::update(int) {
  _component->set_angle(angle);
  _component->set_position(position);
  _component->set_size(size);
  _component->set_color(color);
  _component->bind(*_font, text);
}

void Engine::UI::draw() const {
  if (hide) return;

  _component->draw();
}
