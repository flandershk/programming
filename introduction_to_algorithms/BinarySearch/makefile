CXX = g++
CFLAGS = -Wall -g -pedantic
SOURCES = binary_search.cpp
OBJS = $(SOURCES:.cpp=.o)
APPS = $(SOURCES:.cpp=)

.PHONY: all clean

all: binary_search

binary_search: %: %.o
	$(CXX) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(APPS)
