CXX = g++
CFLAGS = -Wall -g -pedantic
SOURCES = insertition_sort.cpp
OBJS = $(SOURCES:.cpp=.o)
APPS = $(SOURCES:.cpp=)

.PHONY: all clean

all: insertition_sort

heapsort: %: %.o
	$(CXX) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(APPS)
