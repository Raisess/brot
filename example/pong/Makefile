CXX=clang++

SRC=main.cpp

OUT_DIR=../../test-build
OUT=$(OUT_DIR)/pong.o

LIB_DIR=/usr/local/lib/brot
LIB=$(LIB_DIR)/lib-gfx.so \
		$(LIB_DIR)/lib-sfx.so \
		$(LIB_DIR)/lib-input.so \
		$(LIB_DIR)/lib-engine.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) $(LIB) $(SRC) -o $(OUT)

run:
	$(OUT) --window-width=1600 --window-height=900

clean:
	rm -rf $(OUT)
