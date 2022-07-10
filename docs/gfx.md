# GFX Documentation

- Table of contents

1. [Window](#window)
2. [Renderer](#renderer)
3. [Component](#component)
4. [Images and Textures](#images-and-textures)
5. [Fonts and Texts](#fonts-and-texts)

## Window

The `window` class is resposible for generating the window of the program.

### Constructor

```cpp
GFX::Window window(std::string title, Vec2 size);
```

### Methods

- Loop:

```cpp
void loop(std::function<void(void)> callback);
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

The `renderer` class is resposible for generating the screen rendering context.

### Constructor

```cpp
GFX::Renderer renderer(GFX::Window);
```

### Methods

- Draw:

```cpp
void draw() const;
```

### Example

This example results in a black blank window.

```cpp
#include "gfx/Window.h"
#include "gfx/Renderer.h"

int main() {
  GFX::Window window("Title", { 800, 600 });
  GFX::Renderer renderer(window);

  window.loop([&]() -> void {
    renderer.draw();
  });

  return 0;
}
```

## Component

The `component` class is resposible for generating any of the rendered rectagles on the screen.

### Constructor

### Methods

### Example

## Images and Textures

### Image Constructor

### Texture Constructor

### Example

## Fonts and Texts

### Font Constructor

### Text Constructor

### Example

## Program example

```cpp
```
