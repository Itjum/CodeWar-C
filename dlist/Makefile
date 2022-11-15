CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

TEST_OBJS = main.o
OBJ = dlist_print.o dlist_init.o dlist_push_front.o dlist_push_back.o dlist_size.o dlist_get.o dlist_insert_at.o dlist_find.o dlist_remove_at.o dlist_concat.o dlist_map_square.o dlist_split_at.o dlist_reverse.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJS)
	$(CC) -o $@ $^ -fsanitize=address

libdlist.a: $(OBJ)
	ar csr libdlist.a $(OBJ)

library: libdlist.a

clean:
	rm -f testsuit libdlist.a $(TEST_OBJS) $(OBJ)

.PHONY: clean all
