CXX=clang++
FLAGS=-lSDL2 -lSDL2_mixer

SRC=./Sound.cpp \
		./Player.cpp

OUT_DIR=../../build
OUT=$(OUT_DIR)/test-sfx.o
LIB_OUT=$(OUT_DIR)/lib-sfx.so

GFX_LIB=$(OUT_DIR)/lib-gfx.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(OUT_DIR)
	$(CXX) $(FLAGS) $(GFX_LIB) $(LIB_OUT) ./test.cpp -o $(OUT)

run_test:
	$(OUT)

clean:
	rm -f $(OUT)
	rm -f $(LIB_OUT)
