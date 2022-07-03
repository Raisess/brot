# BROT

In development...

## How to use

- Installing [`SDL2`](https://www.libsdl.org/download-2.0.php).

```shell
# for arch based systems
sudo pacman -S sdl2 sdl2_image

# for ubuntu based systems
sudo apt install sdl2 sdl2_image libsdl2-dev
```

### Setup

```shell
git clone https://github.com/Raisess/brot
cd brot
```

### Compiling and running the GFX module

```shell
make build_gfx
make run_gfx
```

## GFX Module

The graphical module is for all implementations of window, rendering, textures and screen components, 
so it's a low level module and will not be highly used by the engine.
