SRC=main.cpp

OUT_DIR=../../build
OUT=$(OUT_DIR)/pong.o

GFX_LIB=$(OUT_DIR)/lib-gfx.so
INPUT_LIB=$(OUT_DIR)/lib-input.so
ENGINE_LIB=$(OUT_DIR)/lib-engine.so

build:
	$(CXX) $(GFX_LIB) $(INPUT_LIB) $(ENGINE_LIB) $(SRC) -o $(OUT)

run:
	$(OUT) --fps-limit=240

clean:
	rm -rf $(OUT)
