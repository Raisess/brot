#include "UI.h"

Engine::UI::UI(const GameContext& game_ctx, std::shared_ptr<GFX::Font> font)
  : _component(std::make_unique<GFX::TextComponent>(*game_ctx.render_ctx)), _font(font) {}

void Engine::UI::update() const {
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
