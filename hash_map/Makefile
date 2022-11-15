CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

TEST_OBJS = main.o
OBJ = hash.o hash_map.o dump.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJS)
	$(CC) -o $@ $^ -fsanitize=address

libhash.a: $(OBJ)
	ar csr libhash.a $(OBJ)

library: libhash.a

clean:
	rm -f testsuit libhash.a $(TEST_OBJS) $(OBJ)

.PHONY: clean all