# By default, $(CC) = cc (and cc is an alias for gcc)

CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

# -lXXXX => va me linker libXXXX.so dans les dossiers standards
LDLIBS = -lm -lpthread

BIN = my_strstr


OBJS = main.o my_strstr.o

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(LDLIBS) -o $@ $^

# This rule is implicit:
# %.o: %.c:
# 	$(CC) $(CFLAGS) -o $@ $^
clean:
	rm -f $(BIN) $(OBJS)

.PHONY: clean all
