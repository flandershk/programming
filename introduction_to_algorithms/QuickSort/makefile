CFLAGS=-g
OBJS=quicksort.o
quicksort: $(OBJS)
	g++ $(CFLAGS) -o $@ $(OBJS)
%.o: %.cpp
	g++ $(CFLAGS) -o $@ -c $<

.PHONY: clean
clean:
	rm -rf *.o quicksort
