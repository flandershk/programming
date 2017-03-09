CFLAGS=-g
EXEC=clock-speed get-pid print-arg-list print-environment get-exe-path open-and-spin print-uptime
.PHONY: all

all:$(EXEC)

clock-speed: clock-speed.c
	gcc $(CFLAGS) $< -o $@

get-pid: get-pid.c
	gcc $(CFLAGS) $< -o $@

print-arg-list: print-arg-list.c
	gcc $(CFLAGS) $< -o $@

print-environment: print-environment.c
	gcc $(CFLAGS) $< -o $@

get-exe-path: get-exe-path.c
	gcc $(CFLAGS) $< -o $@

open-and-spin: open-and-spin.c
	gcc $(CFLAGS) $< -o $@

print-uptime: print-uptime.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
