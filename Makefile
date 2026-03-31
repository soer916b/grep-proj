CC ?= cc
CFLAGS = -Wall -Wextra -std=c11

SRC_DIR = src
BIN_DIR = bin
TARGET = $(BIN_DIR)/grep

all: $(TARGET)

$(TARGET): $(SRC_DIR)/grep.c | $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -f $(TARGET)
	rmdir $(BIN_DIR) 2>/dev/null || true
	