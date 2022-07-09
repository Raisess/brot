#include "../util/Logger.h"
#include "Window.h"

GFX::Window::Window(const std::string& title, const Common::Size& size) : size(size) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Util::Logger::error("Error initializing video " + std::string(SDL_GetError()));
    exit(1);
  }

  sdl_value = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.width, size.height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  if (sdl_value == nullptr) {
    Util::Logger::error("Error creating window " + std::string(SDL_GetError()));
    exit(1);
  }
}

GFX::Window::~Window(void) {
  SDL_DestroyWindow(sdl_value);
  SDL_Quit();
}

void GFX::Window::loop(std::function<void(void)> loop) const {
  SDL_Event event;

  while (true) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          Util::Logger::debug("Quiting...");
          return;
        break;
      }
    }

    loop();
    SDL_Delay(50);
  }
}
