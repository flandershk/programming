CFLAGS=-g
EXEC=shm sem_pv sem_pv2 mmap-read mmap-write pipe dup2 popen socket_client socket_server
.PHONY: all

all:$(EXEC)

shm: shm.c
	gcc $(CFLAGS) $< -o $@

sem_pv: sem_pv.c
	gcc $(CFLAGS) $< -o $@

sem_pv2: sem_pv2.c
	gcc $(CFLAGS) $< -o $@

mmap-read: mmap-read.c
	gcc $(CFLAGS) $< -o $@

mmap-write: mmap-write.c
	gcc $(CFLAGS) $< -o $@

pipe: pipe.c
	gcc $(CFLAGS) $< -o $@

dup2: dup2.c
	gcc $(CFLAGS) $< -o $@

popen: popen.c
	gcc $(CFLAGS) $< -o $@

socket_client: socket_client.c
	gcc $(CFLAGS) $< -o $@

socket_server: socket_server.c
	gcc $(CFLAGS) $< -o $@


.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
