CC=g++
FLAGS=-lSDL2 -lSDL2_image

COMMON_PATH=$(SRC_DIR)/common
UTIL_PATH=$(SRC_DIR)/util
GFX_PATH=$(SRC_DIR)/gfx

SRC_DIR=./src
SRC=$(SRC_DIR)/main.cpp

COMMON_SRC=$(COMMON_PATH)/Vec2.cpp \
					 $(COMMON_PATH)/Size.cpp

GFX_SRC=$(COMMON_SRC) \
				$(GFX_PATH)/Window.cpp \
				$(GFX_PATH)/Renderer.cpp \
				$(GFX_PATH)/Texture.cpp \
				$(GFX_PATH)/Component.cpp \
				$(GFX_PATH)/main.cpp

OUT_DIR=./build
GFX_OUT=$(OUT_DIR)/gfx.o
OUT=$(OUT_DIR)/out.o

build:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(SRC) -o $(OUT)

build_gfx:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(GFX_SRC) -o $(GFX_OUT)

run:
	$(OUT)

run_gfx:
	$(GFX_OUT)

clean:
	rm -rf $(OUT_DIR)
