CFLAGS=-g
EXEC=thread-create thread-create2 primes detached critical-section tsd cleanup cxx-exit job-queue2 job-queue3 spin-condvar condvar thread-pid
.PHONY: all

all:$(EXEC)

thread-create: thread-create.c
	gcc $(CFLAGS) $< -o $@ -lpthread

thread-create2: thread-create2.c
	gcc $(CFLAGS) $< -o $@ -lpthread

primes: primes.c
	gcc $(CFLAGS) $< -o $@ -lpthread
	
detached: detached.c
	gcc $(CFLAGS) $< -o $@ -lpthread
	
critical-section: critical-section.c
	gcc $(CFLAGS) $< -o $@ -lpthread

tsd: tsd.c
	gcc $(CFLAGS) $< -o $@ -lpthread

cleanup: cleanup.c
	gcc $(CFLAGS) $< -o $@ -lpthread

cxx-exit: cxx-exit.cpp
	g++ $(CFLAGS) $< -o $@ -lpthread

job-queue2: job-queue2.c
	gcc $(CFLAGS) $< -o $@ -lpthread

job-queue3: job-queue3.c
	gcc $(CFLAGS) $< -o $@ -lpthread

spin-condvar: spin-condvar.c
	gcc $(CFLAGS) $< -o $@ -lpthread

condvar: condvar.c
	gcc $(CFLAGS) $< -o $@ -lpthread

thread-pid: thread-pid.c
	gcc $(CFLAGS) $< -o $@ -lpthread

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a *.log
