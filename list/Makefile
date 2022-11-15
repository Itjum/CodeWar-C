CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

TEST_OBJS = main.o
OBJ = list.o list_print.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJS)
	$(CC) -o $@ $^ -fsanitize=address

liblist.a: $(OBJ)
	ar csr liblist.a $(OBJ)

library: liblist.a

clean:
	rm -f testsuit liblist.a $(TEST_OBJS) $(OBJ)

.PHONY: clean all
