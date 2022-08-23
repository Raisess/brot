CXX=clang++
FLAGS=-lSDL2

SRC=./Keyboard.cpp \
		./Mouse.cpp

OUT_DIR=../../build
LIB_OUT=$(OUT_DIR)/lib-input.so
TEST_OUT_DIR=../../test-build
TEST_OUT=$(OUT_DIR)/test-input.o

LIB_DIR=/usr/local/bin/brot
GFX_LIB=$(LIB_DIR)/lib-gfx.so
INPUT_LIB=$(LIB_DIR)/lib-input.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(TEST_OUT_DIR)
	$(CXX) $(GFX_LIB) $(INPUT_LIB) ./test.cpp -o $(TEST_OUT)

run_test:
	$(TEST_OUT)

clean:
	rm -f $(TEST_OUT)
	rm -f $(LIB_OUT)
