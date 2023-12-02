BUILD_DIR = build

all: ninja run

ninja:
	meson setup $(BUILD_DIR)
	ninja -C $(BUILD_DIR)

run: ninja
	./$(BUILD_DIR)/exe

clean:
	meson setup --wipe $(BUILD_DIR)

.PHONY: all run clean

