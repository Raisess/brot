CXX=clang++ --std=c++14

LIB_DIR=/usr/local/lib/brot
LIB=$(LIB_DIR)/lib-gfx.so \
		$(LIB_DIR)/lib-sfx.so \
		$(LIB_DIR)/lib-input.so \
		$(LIB_DIR)/lib-engine.so

SRC_DIR=./src
SRC=$(SRC_DIR)/main.cpp \
		$(SRC_DIR)/game/Game.cpp \
		$(SRC_DIR)/game/object/PlayerObject.cpp \
		$(SRC_DIR)/game/object/RoomObject.cpp

OUT_DIR=../../test-build
OUT=$(OUT_DIR)/binary-maze.o

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(LIB) $(SRC) -o $(OUT)

run:
	$(OUT)

clean:
	rm -rf $(OUT_DIR)
