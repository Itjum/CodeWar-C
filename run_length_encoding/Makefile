CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

OBJ = main.o rle.o

check: testsuit
	./testsuit

testsuit: $(OBJ)
	$(CC) -o $@ $^ -fsanitize=address

clean:
	rm -f testsuit $(OBJ)

.PHONY: clean all
