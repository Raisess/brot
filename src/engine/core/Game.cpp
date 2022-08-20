#include "../../common/Size.h"
#include "../../input/Keyboard.h"
#include "../../util/Logger.h"
#include "../../util/Time.h"
#include "Game.h"

#define INTRO_LOGO_WIDTH 500
#define INTRO_LOGO_HEIGHT 100
#define INTRO_DELAY 1500
#define INTRO_FONT_PATH "../../assets/fonts/Roboto/Roboto-Regular.ttf"

Engine::GameContext::GameContext(const std::string& window_title, int argc, char* argv[]) {
  Util::Arguments args = Util::ArgsParser::Parse(argc, argv);
  window_ctx = std::make_unique<GFX::Window>(
    window_title,
    Common::Size({
      Util::ArgsParser::ToInteger(args, "window-width"),
      Util::ArgsParser::ToInteger(args, "window-height"),
    }),
    Util::ArgsParser::ToBoolean(args, "window-fullscreen")
  );
  render_ctx = std::make_shared<GFX::Renderer>(*window_ctx);
  engine_font = std::make_shared<GFX::Font>(INTRO_FONT_PATH);
}

int Engine::GameInfo::Offset = 10;
Engine::GameInfo::GameInfo(const GameContext& game_ctx) : game_ctx(game_ctx) {
  _fps = std::make_unique<GFX::TextComponent>(*game_ctx.render_ctx);
  _fps->set_color({ 255, 0, 0 });
  _fps->set_position({ Offset, 0 });
  _fps->set_size({ 70, 40 });
  _delta_time = std::make_unique<GFX::TextComponent>(*game_ctx.render_ctx);
  _delta_time->set_color({ 255, 0, 0 });
  _delta_time->set_size({ 120, 40 });
  _delta_time->set_position({ Offset, 40 });
}

void Engine::GameInfo::update(const struct Info& info) {
  _info = info;
}

void Engine::GameInfo::draw() {
  _fps->bind(*game_ctx.engine_font, "FPS: " + std::to_string(_info.fps));
  _delta_time->bind(*game_ctx.engine_font, "DELTA_TIME: " + std::to_string(_info.delta_time));
  _fps->draw();
  _delta_time->draw();
}

Engine::Game::Game(const std::string& title, int argc, char* argv[])
  : ctx(GameContext(title, argc, argv)),
    info(GameInfo(ctx)),
    _logo(std::make_unique<GFX::TextComponent>(*ctx.render_ctx)) {
  Util::Logger::Debug("Create Game: " + title);

  const Common::Size window_size = ctx.window_ctx->get_size();
  _logo->set_size({ INTRO_LOGO_WIDTH, INTRO_LOGO_HEIGHT });
  _logo->set_position({
    (window_size.width / 2) - (INTRO_LOGO_WIDTH / 2),
    (window_size.height / 2) - (INTRO_LOGO_HEIGHT / 2),
  });
  _logo->bind(*ctx.engine_font, "Brot Engine");
}

Engine::Game::~Game() {
  Util::Logger::Debug("Delete Game");
}

void Engine::Game::toggle_info() {
  _info = !_info;
}

void Engine::Game::loop(const CallbackLoop& callback) {
  ctx.window_ctx->loop([&](int delta_time) -> void {
    ctx.render_ctx->clear();

    if (_started) {
      info.update({ delta_time, ctx.window_ctx->get_fps() });
      callback(delta_time);
      if (_info) {
        info.draw();
      }
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
