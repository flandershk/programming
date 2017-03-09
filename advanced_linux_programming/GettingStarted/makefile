OBJS=main.o reciprocal.o
INCLUCES=-I../include
CFLAGS=-g

.PHONY: all clean

all: reciprocal test_sizeof test_vtable

reciprocal: $(OBJS)
	g++ $(CFLAGS) -o reciprocal $(OBJS)

test_sizeof: test_sizeof.cpp
	g++ $(CFLAGS) $< -o $@

test_vtable: test_vtable.cpp
	g++ $(CFLAGS) $< -o $@

main.o: main.c
	gcc $(CFLAGS) $(INCLUCES) -c $<

reciprocal.o: reciprocal.cpp
	g++ $(CFLAGS) $(INCLUCES) -c $<

clean:
	rm -f *.o reciprocal test_sizeof
