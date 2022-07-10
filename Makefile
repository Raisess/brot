CC=g++
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC_DIR=./src
COMMON_PATH=$(SRC_DIR)/common
UTIL_PATH=$(SRC_DIR)/util
GFX_PATH=$(SRC_DIR)/gfx
SFX_PATH=$(SRC_DIR)/sfx
INPUT_PATH=$(SRC_DIR)/input

UTIL_SRC=$(UTIL_PATH)/Time.cpp

COMMON_SRC=$(COMMON_PATH)/Vec2.cpp \
					 $(COMMON_PATH)/Size.cpp

GFX_SRC=$(GFX_PATH)/Window.cpp \
				$(GFX_PATH)/Renderer.cpp \
				$(GFX_PATH)/Texture.cpp \
				$(GFX_PATH)/Text.cpp \
				$(GFX_PATH)/Component.cpp

SFX_SRC=

INPUT_SRC=$(INPUT_PATH)/Keyboard.cpp \
					$(INPUT_PATH)/Mouse.cpp

OUT_DIR=./build
GFX_OUT=$(OUT_DIR)/gfx.o
SFX_OUT=$(OUT_DIR)/sfx.o
INPUT_OUT=$(OUT_DIR)/input.o
OUT=$(OUT_DIR)/out.o

build_gfx:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(COMMON_SRC) $(UTIL_SRC) $(GFX_SRC) $(GFX_PATH)/test.cpp -o $(GFX_OUT)

run_gfx:
	$(GFX_OUT)

build_sfx:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(COMMON_SRC) $(UTIL_SRC) $(SFX_SRC) $(GFX_PATH)/Window.cpp $(SFX_PATH)/test.cpp -o $(SFX_OUT)

run_sfx:
	$(SFX_OUT)

build_input:
	mkdir -p $(OUT_DIR)
	$(CC) $(FLAGS) $(COMMON_SRC) $(UTIL_SRC) $(INPUT_SRC) $(GFX_PATH)/Window.cpp $(INPUT_PATH)/test.cpp -o $(INPUT_OUT)

run_input:
	$(INPUT_OUT)

clean:
	rm -rf $(OUT_DIR)
