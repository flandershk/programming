CFLAGS=-g
EXEC=print-pid system fork fork-exec sigusr1 zombie sigchld fork-ctl signal
.PHONY: all

all:$(EXEC)

print-pid: print-pid.c
	gcc $(CFLAGS) $< -o $@

system: system.c
	gcc $(CFLAGS) $< -o $@

fork: fork.c
	gcc $(CFLAGS) $< -o $@

fork-exec: fork-exec.c
	gcc $(CFLAGS) $< -o $@

sigusr1: sigusr1.c
	gcc $(CFLAGS) $< -o $@

zombie: zombie.c
	gcc $(CFLAGS) $< -o $@

sigchld: sigchld.c
	gcc $(CFLAGS) $< -o $@

signal: signal.c
	gcc $(CFLAGS) $< -o $@

fork-ctl: fork-ctl.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
