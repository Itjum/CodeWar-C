CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99
LDLIBS = -lm -lpthread

BIN = sieve
OBJS = sieve.o main.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDLIBS) -o $@ $^
clean:
	rm -f $(BIN) $(OBJS)

.PHONY: clean all
