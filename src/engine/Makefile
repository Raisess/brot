CXX=clang++

SRC=./core/Game.cpp \
		./core/Scene.cpp \
		./core/Layer.cpp \
		./object/UI.cpp \
		./object/Entity.cpp \
		./object/Sprite.cpp \
		./object/SpriteAnimation.cpp \
		./object/SpriteAnimationPlayer.cpp \
		./object/Physics.cpp \
		./object/Camera.cpp \
		./manager/SceneManager.cpp \
		./manager/SpriteManager.cpp

OUT_DIR=../../build
LIB_OUT=$(OUT_DIR)/lib-engine.so
TEST_OUT_DIR=../../test-build
TEST_OUT=$(TEST_OUT_DIR)/test-engine.o

LIB_DIR=/usr/local/lib/brot
GFX_LIB=$(LIB_DIR)/lib-gfx.so
SFX_LIB=$(LIB_DIR)/lib-sfx.so
INPUT_LIB=$(LIB_DIR)/lib-input.so
ENGINE_LIB=$(LIB_DIR)/lib-engine.so

build:
	mkdir -p $(OUT_DIR)
	$(CXX) -fPIC -shared $(SRC) -o $(LIB_OUT)

build_test:
	mkdir -p $(TEST_OUT_DIR)
	$(CXX) $(GFX_LIB) $(SFX_LIB) $(INPUT_LIB) $(ENGINE_LIB) ./test.cpp -o $(TEST_OUT)

run_test:
	$(TEST_OUT) --window-width=1600 --window-height=900

clean:
	rm -f $(TEST_OUT)
	rm -f $(LIB_OUT)
