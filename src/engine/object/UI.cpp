#include "../../util/Logger.h"
#include "UI.h"

Engine::UI::UI(const GameContext& game_ctx, const std::string& id, const std::shared_ptr<GFX::Font>& font)
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
  _component->set_position(position + offset);
  _component->set_size(size);
  _component->set_color(color);
  _component->set_fill(fill);
  _component->set_flip(flip);
  _component->set_rect(rect);
  _component->bind(*_font, text);
}

void Engine::UI::draw() {
  if (hide) return;
  _component->draw();
}
