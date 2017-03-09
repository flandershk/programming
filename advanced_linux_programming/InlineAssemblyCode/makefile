CFLAGS=-g
EXEC=bit_pos_loop bit_pos_asm
.PHONY: all

all:$(EXEC)

bit_pos_loop: bit_pos_loop.c
	gcc $(CFLAGS) $< -o $@

bit_pos_asm: bit_pos_asm.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
