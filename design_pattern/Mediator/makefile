CXX=g++
CXXFLAGS=-g
OBJS=mediator.o colleage.o main.o
APP=mediator

$(APP): $(OBJS)
	$(CXX) $(OBJS) -o $@

include $(OBJS:.o=.d)

%.d: %.cpp
	rm -f $@; $(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[:]*,\1.o $@ :,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$;

.PHONY:clean

clean:
	rm -rf *.o $(APP) $(OBJS) $(OBJS:.o=.d)
