CXX=g++
CXXFLAGS=-g
OBJS=chain_of_responsibility.o
APP=chain_of_responsibility

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
