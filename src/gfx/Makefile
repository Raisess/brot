CXX=clang++
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC=./Window.cpp \
		./Renderer.cpp \
		./Texture.cpp \
		./Text.cpp \
		./_Component.cpp

OUT_DIR=../../build
OUT=$(OUT_DIR)/test-gfx.o
LIB_OUT=$(OUT_DIR)/lib-gfx.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(OUT_DIR)
	$(CXX) $(LIB_OUT) $(SRC) ./test.cpp -o $(OUT)

run_test:
	$(OUT)

clean:
	rm -f $(OUT)
	rm -f $(LIB_OUT)
