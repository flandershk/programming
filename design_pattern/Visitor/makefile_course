CXX=g++
CXXFLAGS=-g
OBJS=course_element.o course_visitor.o course_main.o
APP=course_visitor

$(APP): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf *.o $(APP) $(OBJS)
