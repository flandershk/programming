CXX = g++
CFLAGS = -Wall -g -pedantic
SOURCES = heapsort.cpp
OBJS = $(SOURCES:.cpp=.o)
APPS = $(SOURCES:.cpp=)

.PHONY: all clean

all: heapsort

heapsort: %: %.o
	$(CXX) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(APPS)
