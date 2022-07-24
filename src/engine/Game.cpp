#include "../common/Size.h"
#include "../util/Logger.h"
#include "Game.h"

Engine::GameContext::GameContext(const std::string& window_title)
  : window_ctx(std::make_unique<GFX::Window>(window_title, Common::Size(GWINDOW_W, GWINDOW_H))),
    render_ctx(std::make_shared<GFX::Renderer>(*window_ctx)) {}

Engine::Game::Game(const std::string& title) : ctx(GameContext(title)) {
  Util::Logger::debug("Create Game: " + title);
}

Engine::Game::~Game() {
  Util::Logger::debug("Delete Game");
}

void Engine::Game::loop(const Loop& callback) const {
  ctx.window_ctx->loop([&]() -> void {
    ctx.render_ctx->clear();
    callback();
    ctx.render_ctx->draw();
  });
}

void Engine::Game::end() const {
  ctx.window_ctx->quit();
}
