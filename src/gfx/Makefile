CXX=clang++
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC=./Window.cpp \
		./Renderer.cpp \
		./_Component.cpp \
		./Text.cpp \
		./Texture.cpp

OUT_DIR=../../build
LIB_OUT=$(OUT_DIR)/lib-gfx.so
TEST_OUT_DIR=../../test-build
TEST_OUT=$(OUT_DIR)/test-gfx.o

LIB_DIR=/usr/local/bin/brot
GFX_LIB=$(LIB_DIR)/lib-gfx.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(TEST_OUT_DIR)
	$(CXX) $(FLAGS) $(GFX_LIB) ./test.cpp -o $(TEST_OUT)

run_test:
	$(TEST_OUT)

clean:
	rm -f $(TEST_OUT)
	rm -f $(LIB_OUT)
