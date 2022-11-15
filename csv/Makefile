CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -fsanitize=address -g

OBJ = csv.o

all: csv

csv: $(OBJ)
	$(CC) -o $@ $^ -fsanitize=address

clean:
	rm -f csv $(OBJ)

.PHONY: clean all
