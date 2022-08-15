CXX=clang++
FLAGS=-lSDL2 -lSDL2_image -lSDL2_ttf

SRC=./Game.cpp \
		./Scene.cpp \
		./Layer.cpp \
		./NodeContainer.cpp \
		./UI.cpp \
		./Entity.cpp \
		./Animation.cpp \
		./Physics.cpp

OUT_DIR=../../build
OUT=$(OUT_DIR)/test-engine.o
LIB_OUT=$(OUT_DIR)/lib-engine.so

GFX_LIB=$(OUT_DIR)/lib-gfx.so
INPUT_LIB=$(OUT_DIR)/lib-input.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(FLAGS) $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(OUT_DIR)
	$(CXX) $(GFX_LIB) $(INPUT_LIB) $(LIB_OUT) ./test.cpp -o $(OUT)

run_test:
	$(OUT) --window-width=1600 --window-height=900

clean:
	rm -f $(OUT)
	rm -f $(LIB_OUT)
