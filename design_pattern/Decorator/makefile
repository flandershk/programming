CXX=g++
CXXFLAGS=-g
OBJS=decorator.o
APP=decorator

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
