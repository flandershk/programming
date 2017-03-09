CXX=g++
CXXFLAGS=-g
OBJS=abstract_factory.o
APP=abstract_factory

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
