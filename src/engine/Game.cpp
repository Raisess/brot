#include "../common/Size.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Game.h"

#define GAME_WINDOW_WIDTH 1280
#define GAME_WINDOW_HEIGHT 720
#define INTRO_FONT_PATH "./assets/fonts/font.ttf"
#define INTRO_LOGO_WIDTH 500
#define INTRO_LOGO_HEIGHT 100
#define INTRO_DELAY 1500

Engine::GameContext::GameContext(const std::string& window_title)
  : window_ctx(std::make_unique<GFX::Window>(window_title, Common::Size(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT))),
    render_ctx(std::make_shared<GFX::Renderer>(*window_ctx)) {}

Engine::Game::Game(const std::string& title)
  : ctx(GameContext(title)),
    _logo(std::make_unique<GFX::TextComponent>(*ctx.render_ctx)) {
  Util::Logger::Debug("Create Game: " + title);
  _logo->set_size({ INTRO_LOGO_WIDTH, INTRO_LOGO_HEIGHT });
  _logo->set_position({
    (GAME_WINDOW_WIDTH / 2) - (INTRO_LOGO_WIDTH / 2),
    (GAME_WINDOW_HEIGHT / 2) - (INTRO_LOGO_HEIGHT / 2),
  });
  _logo->bind(GFX::Font(INTRO_FONT_PATH), "Brot Engine");
}

Engine::Game::~Game() {
  Util::Logger::Debug("Delete Game");
}

void Engine::Game::loop(const CallbackLoop& callback) {
  ctx.window_ctx->loop([&](int delta_time) -> void {
    ctx.render_ctx->clear();

    if (_started) {
      callback(delta_time);
      ctx.render_ctx->draw();
    } else {
      _logo->draw();
      ctx.render_ctx->draw();
      Util::Time::Delay(INTRO_DELAY);
      delete _logo.release();
      _started = true;
    }
  });
}

void Engine::Game::end() const {
  ctx.window_ctx->quit();
}
