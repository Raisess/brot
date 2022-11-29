# BROT

A lightweight game engine for lightweight 2D games.

## How to use

- Installing [`SDL2`](https://www.libsdl.org/download-2.0.php).

```shell
# for arch based systems
sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer
```

### Setup

Download, compile the source and install for include headers:

```shell
git clone https://github.com/Raisess/brot
cd brot
make all
make install
```

### Headers

The headers are all on `/usr/local/include/brot`, so the path will be like this:

```cpp
#include <brot/engine/core/Game.h>
#include <brot/engine/core/Scene.h>
#include <brot/engine/object/Entity.h>
```

### Code Example

Draws a small square in the center of screen.

```cpp
#include <brot/engine/core/Game.h>
#include <brot/engine/core/Scene.h>
#include <brot/engine/object/Entity.h>

using namespace Engine;

int main(int argc, char* arcv[]) {
  Game example("Example", argc, arcv);
  Scene main("main-scene");
  auto layer = main.push_layer();
  auto entity = Entity::Shared(example.ctx, "entity");
  layer->nodes.push_back(entity);

  entity->rect = true;
  entity->size = { 100, 100 };
  entity->position = example.ctx.window->get_size().xy() / 2;
  entity->offset = entity->size.xy().inverse() / 2;

  example.loop([&](int delta_time) {
    main.update(delta_time);
    main.draw();
  });

  return 0;
}
```

## Documentation

This project is under development.

- [Documentation](./docs)

### Compiling and running the Engine test program

NOTE: at this time I'm not providing the test assets, so you need to add your own to get this working...

```shell
make build_engine_test
make run_engine_test
```

## Notice

This project uses [Roboto](https://fonts.google.com/specimen/Roboto) font.
