# GFX Documentation

## Window

### Constructor

```cpp
// window(title, size{ width, height })
GFX::Window window(std::string, { int, int });
```

### Methods

- The window loop

```cpp
// loop([](void) -> void {});
window.loop(std::function<void(void)>);
```

### Example

```cpp
#include "gfx/Window.h"

int main() {
  GFX::Window window("Title", { 800, 600 });

  window.loop([&]() -> void {});

  return 0;
}
```

## Renderer

## Component

## Texture

## Implementation e.g.
