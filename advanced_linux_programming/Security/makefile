CFLAGS=-g
EXEC=simpleid stat-perm setuid-test temp_file
.PHONY: all

all:$(EXEC)

simpleid: simpleid.c
	gcc $(CFLAGS) $< -o $@

stat-perm: stat-perm.c
	gcc $(CFLAGS) $< -o $@

setuid-test: setuid-test.c
	gcc $(CFLAGS) $< -o $@

pam: pam.c
	gcc $(CFLAGS) $< -o $@ -lpam -lpam_misc

temp_file: temp_file.c
	gcc $(CFLAGS) $< -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a
