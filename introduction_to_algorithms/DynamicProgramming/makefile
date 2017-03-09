CXX = g++
CFLAGS = -Wall -g -pedantic
SOURCES = lmis.c
OBJS = $(SOURCES:.c=.o)
APPS = $(SOURCES:.c=)

.PHONY: all clean

all: lmis

lmis: %: %.o
	$(CXX) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJS) $(APPS)
