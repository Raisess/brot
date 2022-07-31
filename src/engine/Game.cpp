#include "../common/Size.h"
#include "../gfx/TextComponent.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Game.h"

#define GWINDOW_W 1280
#define GWINDOW_H 720
#define FONT_PATH "./assets/fonts/font.ttf"
#define LOGO_W 500
#define LOGO_H 100
#define INTRO_DELAY 1500

Engine::GameContext::GameContext(const std::string& window_title)
  : window_ctx(std::make_unique<GFX::Window>(window_title, Common::Size(GWINDOW_W, GWINDOW_H))),
    render_ctx(std::make_shared<GFX::Renderer>(*window_ctx)) {}

Engine::Game::Game(const std::string& title) : ctx(GameContext(title)) {
  Util::Logger::Debug("Create Game: " + title);
}

Engine::Game::~Game() {
  Util::Logger::Debug("Delete Game");
}

void Engine::Game::loop(const CallbackLoop& callback) const {
  Util::Logger::Debug("Intro");
  GFX::TextComponent logo(*ctx.render_ctx);
  logo.set_size({ LOGO_W, LOGO_H });
  logo.set_position({ (GWINDOW_W / 2) - (LOGO_W / 2), (GWINDOW_H / 2) - (LOGO_H / 2) });
  logo.bind(GFX::Font(FONT_PATH), "Brot Engine");

  unsigned int intro_count = 0;
  ctx.window_ctx->loop([&](int delta_time) -> void {
    ctx.render_ctx->clear();

    if (Util::Time::Wait(INTRO_DELAY, delta_time, intro_count)) {
      callback(delta_time);
    } else {
      logo.draw();
    }

    ctx.render_ctx->draw();
  });
}

void Engine::Game::end() const {
  ctx.window_ctx->quit();
}
