CXX=g++
CXXFLAGS=-g
OBJS=subject.o observer.o main.o
APP=observer
LDFLAGS=-lpthread

$(APP): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
