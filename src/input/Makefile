CXX=clang++
FLAGS=-lSDL2

SRC=./Keyboard.cpp \
		./Mouse.cpp

OUT_DIR=../../build
OUT=$(OUT_DIR)/test-input.o
LIB_OUT=$(OUT_DIR)/lib-input.so

GFX_LIB=$(OUT_DIR)/lib-gfx.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(OUT_DIR)
	$(CXX) $(GFX_LIB) $(LIB_OUT) ./test.cpp -o $(OUT)

run_test:
	$(OUT)

clean:
	rm -f $(OUT)
	rm -f $(LIB_OUT)
