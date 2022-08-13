#include "../common/Size.h"
#include "../util/Logger.h"
#include "../util/Time.h"
#include "Game.h"

#define INTRO_LOGO_WIDTH 500
#define INTRO_LOGO_HEIGHT 100
#define INTRO_DELAY 1500
#define INTRO_FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"

Engine::GameContext::GameContext(const std::string& window_title, const Common::Size& window_size)
  : window_ctx(std::make_unique<GFX::Window>(window_title, window_size)),
    render_ctx(std::make_shared<GFX::Renderer>(*window_ctx)) {}

Engine::Game::Game(const std::string& title, Util::Arguments args)
  : ctx(GameContext(title, {
      Util::ArgsParser::ToInteger(args, "window_width"),
      Util::ArgsParser::ToInteger(args, "window_height"),
    })),
    _logo(std::make_unique<GFX::TextComponent>(*ctx.render_ctx)) {
  Util::Logger::Debug("Create Game: " + title);

  Common::Size window_size = ctx.window_ctx->get_size();
  _logo->set_size({ INTRO_LOGO_WIDTH, INTRO_LOGO_HEIGHT });
  _logo->set_position({
    (window_size.width / 2) - (INTRO_LOGO_WIDTH / 2),
    (window_size.height / 2) - (INTRO_LOGO_HEIGHT / 2),
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
