CFLAGS=-g
EXEC=getopt_long arglist print_env temp_file basic_io basic_io2 readfile app app2 tifftest app3 test_friend
.PHONY: all

all:$(EXEC)

tifftest: tifftest.c
	gcc $(CFLAGS) $< -o $@ -ltiff

getopt_long: getopt_long.c
	gcc $(CFLAGS) $< -o $@

arglist: arglist.c
	gcc $(CFLAGS) $< -o $@

print_env: print_env.c
	gcc $(CFLAGS) $< -o $@

temp_file: temp_file.c
	gcc $(CFLAGS) $< -o $@

basic_io: basic_io.c
	gcc $(CFLAGS) $< -o $@

basic_io2: basic_io2.c
	gcc $(CFLAGS) $< -o $@

readfile: readfile.c
	gcc $(CFLAGS) $< -o $@

app: app.o libtest.a
	gcc $(CFLAGS) -static -o $@ app.o -L. -ltest 

app2: app.o libtest.so
	gcc $(CFLAGS) -o $@ app.o -L. -ltest -Wl,-rpath,.

app3: app.o libtest.so
	gcc $(CFLAGS) -o $@ app.o -L. -ltest -Wl,-rpath,.

test_friend: test_friend.cpp
	g++ $(CFLAGS) $< -o $@

libtest.so: test.o
	gcc $(CFLAGS) -shared $^ -o $@

libtest.a: test.o
	ar cr $@ $?

test.o: test.c
	gcc $(CFLAGS) $< -c -o $@

app.o: app.c
	gcc $(CFLAGS) $< -c -o $@

.PHONY: clean

clean: 
	rm -f *.o $(EXEC) *.a *.so
