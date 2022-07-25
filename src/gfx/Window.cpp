#include "../util/Logger.h"
#include "../util/Time.h"
#include "Window.h"

GFX::Window::Window(const std::string& title, const Common::Size& size) : title(title), _size(size) {
  Util::Logger::Debug("Create Window: " + title + " | width: " + std::to_string(size.width) + ", height: " + std::to_string(size.height));

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Util::Logger::Error("Error initializing video " + std::string(SDL_GetError()));
    exit(1);
  }

  sdl_value = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.width, size.height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
  if (sdl_value == nullptr) {
    Util::Logger::Error("Error creating window " + std::string(SDL_GetError()));
    exit(1);
  }
}

GFX::Window::~Window(void) {
  SDL_DestroyWindow(sdl_value);
  SDL_Quit();
  Util::Logger::Debug("Delete Window");
}

void GFX::Window::quit() const {
  SDL_Event quit_event = { SDL_QUIT };
  SDL_PushEvent(&quit_event);
}

unsigned int GFX::Window::MinimumDeltaTime = 1000 / FPS_LIMIT;

void GFX::Window::loop(const CallbackLoop& callback) {
  SDL_Event event;
  int last_time = SDL_GetTicks64();

  while (true) {
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_QUIT:
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

      callback(delta_time);

      last_time = now;
      _fps = 1000 / delta_time;
    } else {
      Util::Time::Delay(1);
    }
  }
}

const Common::Size GFX::Window::get_size() const {
  return _size;
}

const unsigned int GFX::Window::get_fps() const {
  return _fps;
}
