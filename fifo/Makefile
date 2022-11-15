CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

TEST_OBJS = main.o
OBJ = fifo_init.o fifo_push.o fifo_size.o fifo_head.o fifo_pop.o fifo_clear.o fifo_destroy.o fifo_print.o

all: library

check: testsuit
	./testsuit

testsuit: $(OBJ) $(TEST_OBJS)
	$(CC) -o $@ $^ -fsanitize=address

libfifo.a: $(OBJ)
	ar csr libfifo.a $(OBJ)

library: libfifo.a

clean:
	rm -f testsuit libfifo.a $(TEST_OBJS) $(OBJ)

.PHONY: clean all
