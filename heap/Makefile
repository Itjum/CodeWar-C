CC = gcc
CFLAGS = -Wall -g -Wextra -Werror -pedantic -std=c99 -fsanitize=address

#TEST_LDLIBS = -lcriterion
OBJ = create.o add.o pop.o del.o print.o
TEST_OBJ = main.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJ)
	$(CC) -o $@ $^ -fsanitize=address

libheap.a: $(OBJ)
	ar csr libheap.a $(OBJ)

library: libheap.a

clean:
	rm -f testsuit libheap.a $(OBJ) $(TEST_OBJ)

.PHONY: clean all
