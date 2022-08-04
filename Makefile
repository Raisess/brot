CXX=g++
#CXX=clang -std=c++11
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

# PATHS
SRC_DIR=./src
GFX_PATH=$(SRC_DIR)/gfx
SFX_PATH=$(SRC_DIR)/sfx
INPUT_PATH=$(SRC_DIR)/input
ENGINE_PATH=$(SRC_DIR)/engine

# SOURCES
GFX_SRC=$(GFX_PATH)/Window.cpp \
				$(GFX_PATH)/Renderer.cpp \
				$(GFX_PATH)/Texture.cpp \
				$(GFX_PATH)/Text.cpp \
				$(GFX_PATH)/_Component.cpp

SFX_SRC=

INPUT_SRC=$(INPUT_PATH)/Keyboard.cpp \
					$(INPUT_PATH)/Mouse.cpp

ENGINE_SRC=$(ENGINE_PATH)/Game.cpp \
					 $(ENGINE_PATH)/NodeContainer.cpp \
					 $(ENGINE_PATH)/UI.cpp \
					 $(ENGINE_PATH)/Animation.cpp \
					 $(ENGINE_PATH)/Entity.cpp \
					 $(ENGINE_PATH)/Layer.cpp \
					 $(ENGINE_PATH)/Scene.cpp

# OUTPUT
OUT_DIR=./build
OUT=$(OUT_DIR)/out.o

# TEST ONLY
GFX_OUT=$(OUT_DIR)/gfx.o
SFX_OUT=$(OUT_DIR)/sfx.o
INPUT_OUT=$(OUT_DIR)/input.o
ENGINE_OUT=$(OUT_DIR)/engine.o

# SCRIPTS
SETUP_ENGINE_CFG=./setup_engine_cfg.sh

clean:
	rm -rf $(OUT_DIR)

build_gfx:
	mkdir -p $(OUT_DIR)
	$(CXX) $(FLAGS) $(GFX_SRC) $(GFX_PATH)/test.cpp -o $(GFX_OUT)

run_gfx:
	$(GFX_OUT)

build_sfx:
	mkdir -p $(OUT_DIR)
	$(CXX) $(FLAGS) $(SFX_SRC) $(GFX_PATH)/Window.cpp $(SFX_PATH)/test.cpp -o $(SFX_OUT)

run_sfx:
	$(SFX_OUT)

build_input:
	mkdir -p $(OUT_DIR)
	$(CXX) $(FLAGS) $(INPUT_SRC) $(GFX_PATH)/Window.cpp $(INPUT_PATH)/test.cpp -o $(INPUT_OUT)

run_input:
	$(INPUT_OUT)

build_engine:
	mkdir -p $(OUT_DIR)
	$(CXX) $(FLAGS) $(GFX_SRC) $(SFX_SRC) $(INPUT_SRC) $(ENGINE_SRC) $(ENGINE_PATH)/test.cpp -o $(ENGINE_OUT)

run_engine:
	$(ENGINE_OUT)
