CFLAGS=-g
EXEC=random_number cdrom-eject
.PHONY: all

all:$(EXEC)

random_number: random_number.c
	gcc $(CFLAGS) $< -o $@

cdrom-eject: cdrom-eject.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
