CXX=g++
CXXFLAGS=-g
OBJS=strategy.o
APP=strategy

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
