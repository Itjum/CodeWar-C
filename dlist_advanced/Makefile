CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address

TEST_OBJS = main.o
OBJ = dlist_print.o dlist_init.o dlist_push_back.o dlist_push_front.o dlist_remove_at.o dlist_clear.o dlist_shift.o dlist_insert_at.o dlist_add_sort.o dlist_remove_eq.o dlist_copy.o dlist_sort.o dlist_concat.o dlist_merge.o dlist_levenshtein.o dlist_get.o dlist_size.o

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
