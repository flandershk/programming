CFLAGS = -g
SOURCES = $(shell find . -maxdepth 1 -name "*.cpp")
OBJS = $(SOURCES:.cpp=.o)
EXEC = $(SOURCES:.cpp=)

.PHONY: all clean

all: $(EXEC)

$(EXEC): %: %.o
	g++ $(CFLAGS) $^ -o $@

%.o: %.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(EXEC)
