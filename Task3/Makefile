PROJECT = grey-scale
TB		= tb
OBJS    =    \
	tb.cpp.o \
	grey-scale.cpp.o \
	main.cpp.o

export SYSTEMC_HOME ?=/home/ldis/ESIF/systemc-2.3.3
CXX = g++
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lm -lstdc++ -std=c++14
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 $(CXXFLAGS)

all: main run

# dependencies
tb.cpp.o : tb.h
grey_scale.cpp.o : grey-scale.h

%.cpp.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJS)

run:
	./main

simulate:
	gtkwave main.vcd &

clean:
	rm -rf $(OBJS) main main.vcd
