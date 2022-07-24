#include "../common/Size.h"
#include "../gfx/TextComponent.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Game.h"

#define FONT_PATH "../tmp/test-font.ttf"

Engine::GameContext::GameContext(const std::string& window_title)
  : window_ctx(std::make_unique<GFX::Window>(window_title, Common::Size(GWINDOW_W, GWINDOW_H))),
    render_ctx(std::make_shared<GFX::Renderer>(*window_ctx)) {}

Engine::Game::Game(const std::string& title) : ctx(GameContext(title)) {
  Util::Logger::debug("Create Game: " + title);
}

Engine::Game::~Game() {
  Util::Logger::debug("Delete Game");
}

void Engine::Game::loop(const CallbackLoop& callback) const {
  GFX::TextComponent intro_text(*ctx.render_ctx);
  intro_text.set_size({ LOGO_W, LOGO_H });
  intro_text.set_position({ (GWINDOW_W / 2) - (LOGO_W / 2), (GWINDOW_H / 2) - (LOGO_H / 2) });
  intro_text.bind(GFX::Font(FONT_PATH), "BROT Engine");

  unsigned int intro_count = 0;
  ctx.window_ctx->loop([&](int delta_time) -> void {
    ctx.render_ctx->clear();

    if (Util::Time::wait(INTRO_DELAY, delta_time, intro_count)) {
      callback(delta_time);
    } else {
      intro_text.draw();
    }

    ctx.render_ctx->draw();
  });
}

void Engine::Game::end() const {
  ctx.window_ctx->quit();
}
