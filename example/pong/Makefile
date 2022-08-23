CXX=clang++

SRC=main.cpp

OUT_DIR=../../test-build
OUT=$(OUT_DIR)/pong.o

LIB_DIR=/usr/local/bin/brot
GFX_LIB=$(LIB_DIR)/lib-gfx.so
SFX_LIB=$(LIB_DIR)/lib-sfx.so
INPUT_LIB=$(LIB_DIR)/lib-input.so
ENGINE_LIB=$(LIB_DIR)/lib-engine.so

build:
	$(CXX) $(GFX_LIB) $(SFX_LIB) $(INPUT_LIB) $(ENGINE_LIB) $(SRC) -o $(OUT)

run:
	$(OUT) --window-width=1600 --window-height=900

clean:
	rm -rf $(OUT)
