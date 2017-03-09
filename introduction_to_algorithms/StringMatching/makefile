CXX = g++
CFLAGS = -Wall -g -pedantic
SOURCES = kmp.cpp
OBJS = $(SOURCES:.cpp=.o)
APPS = $(SOURCES:.cpp=)

.PHONY: all clean

all: kmp

kmp: %: %.o
	$(CXX) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(APPS)
