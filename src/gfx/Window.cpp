#include "../util/Logger.h"
#include "../util/Time.h"
#include "Window.h"

#define DEFAULT_WINDOW_WIDTH 1280
#define DEFAULT_WINDOW_HEIGHT 720

GFX::Window::Window(const std::string& title, const Common::Size& size, bool fullscreen)
  : title(title), _size(size), _fullscreen(fullscreen) {
  _size.width = size.width ? size.width : DEFAULT_WINDOW_WIDTH;
  _size.height = size.height ? size.height : DEFAULT_WINDOW_HEIGHT;

  Util::Logger::Debug("Create Window: " + title + " | width: " + std::to_string(_size.width) + ", height: " + std::to_string(_size.height));

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    Util::Logger::Error("Error initializing video: " + std::string(SDL_GetError()));
    exit(1);
  }

  sdl_value = SDL_CreateWindow(
    title.c_str(),
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    _size.width, _size.height,
    SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | (_fullscreen ? SDL_WINDOW_FULLSCREEN : 0)
  );
  if (sdl_value == nullptr) {
    Util::Logger::Error("Error creating window: " + std::string(SDL_GetError()));
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

unsigned int GFX::Window::MinimunDeltaTime = 1000 / 60;
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

      if (delta_time < MinimunDeltaTime) {
        delta_time = MinimunDeltaTime;
      }

      callback(delta_time);

      last_time = now;
      _fps = 1000 / delta_time;
    } else {
      Util::Time::Delay(1);
    }
  }
}
