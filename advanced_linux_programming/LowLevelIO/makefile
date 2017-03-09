CC = gcc
CFLAGS = -g -Wall -pedantic
SOURCES = create_file.c timestamp.c hexdump.c lseek_huge.c read_file.c write_arg.c listdir.c
OBJS = $(SOURCES:.c=.o)
EXEC = $(SOURCES:.c=)

.PHONY: all clean

all: $(EXEC)

$(EXEC): %: %.o
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(EXEC)
