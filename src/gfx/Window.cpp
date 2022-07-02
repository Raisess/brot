#include "../common/Logger.h"
#include "Window.h"

GFX::Window::Window(const std::string& title, const Common::Size& size) {
  SDL_Init(SDL_INIT_VIDEO);

  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.width, size.height, 0);
  if (window == nullptr) {
    Common::Logger::error("Error creating the window " + std::string(SDL_GetError()));
  }
}

GFX::Window::~Window(void) {
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void GFX::Window::loop(std::function<void(void)> game_loop) const {
  SDL_Event event;

  while (true) {
    SDL_PollEvent(&event);
    switch (event.type) {
      case SDL_QUIT:
        Common::Logger::debug("Quiting...");
        return;
      break;
    }

    game_loop();
  }
}
