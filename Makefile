SRC_DIR=./src
GFX_PATH=$(SRC_DIR)/gfx
SFX_PATH=$(SRC_DIR)/sfx
INPUT_PATH=$(SRC_DIR)/input
ENGINE_PATH=$(SRC_DIR)/engine

OUT_DIR=./build

clean:
	rm -rf $(OUT_DIR)

all: build_gfx build_input build_engine

build_engine:
	make -C $(ENGINE_PATH)

build_engine_test:
	make -C $(ENGINE_PATH) build_test

run_engine_test:
	make -C $(ENGINE_PATH) run_test

build_input:
	make -C $(INPUT_PATH)

build_input_test:
	make -C $(INPUT_PATH) build_test

run_input_test:
	make -C $(INPUT_PATH) run_test

build_gfx:
	make -C $(GFX_PATH)

build_gfx_test:
	make -C $(GFX_PATH) build_test

run_gfx_test:
	make -C $(GFX_PATH) run_test
