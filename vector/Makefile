CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

TEST_OBJS = main.o
OBJ = vector_init.o vector_destroy.o vector_resize.o vector_append.o vector_print.o vector_reset.o vector_insert.o vector_remove.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJS)
	$(CC) -o $@ $^ -fsanitize=address

libvector.a: $(OBJ)
	ar csr libvector.a $(OBJ)

library: libvector.a

clean:
	rm -f testsuit libvector.a $(TEST_OBJS) $(OBJ)

.PHONY: clean all
