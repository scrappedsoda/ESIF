PROJECT = half-adder
TB		= tb
OBJS    =    \
	tb.cpp.o \
	half-adder.cpp.o \
	main.cpp.o

export SYSTEMC_HOME ?=/home/ldis/ESIF/systemc-2.3.3
CXX = g++
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lm -lstdc++ -std=c++14
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 $(CXXFLAGS)

all: main run

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
