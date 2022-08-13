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
    renderer.clear();
    renderer.draw();
  });

  return 0;
}
```

## Component

The `component` class is resposible for generating any of the rendered rectagles on the screen.

### Constructor

```cpp
GFX::Component component(GFX::Renderer);
```

### Methods

```cpp
virtual void draw() = 0;

const Size get_size() const;
void set_size(const Size& new_size);
const Vec2 get_position() const;
void set_position(const Vec2& new_position);
const Color get_color() const;
void set_color(const Color& new_color);
const int get_angle() const;
void set_angle(int value);
const bool get_fill() const;
void set_fill(bool fill);
const bool get_flip() const;
void set_flip(bool flip);
const bool get_rect() const;
void set_rect(bool rect);
```

## Images and Textures

### Image Constructor

```cpp
GFX::Image texture(std::string path);
```

### Texture Constructor

```cpp
GFX::Texture texture(GFX::Renderer, GFX::Image);
```

### TextureComponent

- Extends public `Component` class.

```cpp
GFX::TextureComponent texture_component(GFX::Renderer);
texture_component.bind(GFX::Image);
```

### Example

```cpp
GFX::Image image("some-image-path");
GFX::TextureComponent texture_component(renderer);
texture_component.bind(image);
```

## Fonts and Texts

### Font Constructor

```cpp
GFX::Font font(std::string path);
```

### Text Constructor

```cpp
GFX::Text text(GFX::Renderer, GFX::Font, std::string text, Common::Color);
```

### TextComponent

- Extends public `Component` class.

```cpp
GFX::TextComponent text_component(GFX::Renderer);
text_component.bind(GFX::Font, std::string str);
```

### Example

```cpp
GFX::Font font("some-font-path");
GFX::TextComponent text_component(renderer);
text_component.bind(font, "some-text");
```

## Program example

```cpp
#include "TextureComponent.h"
#include "Renderer.h"
#include "Window.h"

#define FONT_PATH "some-font-path"
#define IMAGE_PATH "some-image-path"

int main() {
  GFX::Window window("Example", { 800, 600 });
  GFX::Renderer renderer(window);
  GFX::TextComponent text_component(renderer);
  text_component.bind(GFX::Font(FONT_PATH), "some text to show");
  GFX::TextureComponent texture_component(renderer);
  texture_component.set_size({ 100, 100 });
  texture_component.set_position({ 200, 200 });
  texture_component.bind(GFX::Image(IMAGE_PATH));

  window.loop([&]() -> void {
    renderer.clear();
    text_component.draw();
    texture_component.draw();
    renderer.draw();
  });

  return 0;
}
```
