#include "../util/Logger.h"
#include "../util/Time.h"
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

unsigned int GFX::Window::MinimumDeltaTime = 1000 / FPS_LIMIT;

void GFX::Window::loop(std::function<void(void)> loop) {
  SDL_Event event;
  int last_time = SDL_GetTicks64();

  while (true) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
          Util::Logger::debug("Quiting...");
          return;
        break;
      }
    }

    int now = SDL_GetTicks64();

    if (last_time < now) {
      int delta_time = now - last_time;

      if (delta_time < MinimumDeltaTime) {
        delta_time = MinimumDeltaTime;
      }

      last_time = now;
      fps = 1000 / delta_time;

      loop();
    } else {
      Util::Time::delay(1);
    }
  }
}

const Common::Size GFX::Window::get_size() const {
  return size;
}

const unsigned int GFX::Window::get_fps() const {
  return fps;
}
