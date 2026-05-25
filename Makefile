CC=gcc
CFLAGS=-Wall -Wextra -g -fsanitize=address -Iinclude
SRC=src/main.c src/logger.c src/parser.c src/dispatcher.c src/handlers.c tests/parser_tests.c
HDR = include/logger.h include/parser.h include/dispatcher.h include/handlers.h
TARGET=message_switch

all: $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)