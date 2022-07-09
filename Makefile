CC=g++
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC_DIR=./src
COMMON_PATH=$(SRC_DIR)/common
UTIL_PATH=$(SRC_DIR)/util
GFX_PATH=$(SRC_DIR)/gfx

UTIL_SRC=$(UTIL_PATH)/Time.cpp

COMMON_SRC=$(COMMON_PATH)/Vec2.cpp \
					 $(COMMON_PATH)/Size.cpp

GFX_SRC=$(UTIL_SRC) \
				$(COMMON_SRC) \
				$(GFX_PATH)/Window.cpp \
				$(GFX_PATH)/Renderer.cpp \
				$(GFX_PATH)/Texture.cpp \
				$(GFX_PATH)/Text.cpp \
				$(GFX_PATH)/Component.cpp \
				$(GFX_PATH)/test.cpp

OUT_DIR=./build
GFX_OUT=$(OUT_DIR)/gfx.o
OUT=$(OUT_DIR)/out.o

build_gfx:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(GFX_SRC) -o $(GFX_OUT)

run_gfx:
	$(GFX_OUT)

clean:
	rm -rf $(OUT_DIR)
