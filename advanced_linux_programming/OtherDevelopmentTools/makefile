CC = gcc
CFLAGS = -pg -g -Wall -pedantic
SOURCES = malloc_use.c
SOURCESC = calculator.c stack.c number.c
DEFS = -DMTRACE
OBJS = $(SOURCES:.c=.o)
OBJSC = $(SOURCESC:.c=.o)

.PHONY: all clean

all: calculator malloc_use

calculator: $(OBJSC)
	$(CC) $(CFLAGS) $^ -o $@

malloc_use: $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(DEFS) $< -c -o $@

clean:
	rm -rf *.o $(OBJS) $(OBJ2) malloc_use calculator
