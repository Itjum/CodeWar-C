CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address

OBJ = sieve.o

all: sieve.o

check: sieve
	./sieve

sieve: $(OBJ)
	$(CC) -o $@ $^ -fsanitize=address

clean:
	rm -f $(OBJ) sieve

.PHONY: clean
