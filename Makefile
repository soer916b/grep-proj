CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src
BIN = bin

grep: $(SRC)/grep.c
	$(CC) $(CFLAGS) $(SRC)/grep.c -o $(BIN)/grep

clean:
	rm -f $(BIN)/grep