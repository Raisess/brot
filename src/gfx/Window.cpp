#include "../common/Logger.h"
#include "Window.h"

GFX::Window::Window(const std::string& title, const Common::Size& size) : size(size) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Common::Logger::error("Error initializing the video " + std::string(SDL_GetError()));
  }

  sdl_value = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.width, size.height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  if (sdl_value == nullptr) {
    Common::Logger::error("Error creating the window " + std::string(SDL_GetError()));
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
          Common::Logger::debug("Quiting...");
          return;
        break;
      }
    }

    loop();
    SDL_Delay(50);
  }
}
