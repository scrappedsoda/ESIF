PROJECT = grey-scale
OBJS    =    \
	img_reader.cpp.o \
	img_writer.cpp.o \
	grey-scale.cpp.o \
	main.cpp.o \
	libbmp.cpp.o \
	channel.cpp.o

export SYSTEMC_HOME ?=/home/ldis/ESIF/systemc-2.3.3
CXX = g++
CXXFLAGS = -I. -I$(SYSTEMC_HOME)/include -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -lsystemc -lm -lstdc++ -std=c++14
LDFLAGS = -L. -L$(SYSTEMC_HOME)/lib-linux64 $(CXXFLAGS)

all: main run

# dependencies
img_reader.cpp.o : img_reader.h channel_if.h
img_writer.cpp.o : img_writer.h channel_if.h
grey_scale.cpp.o : grey-scale.h channel_if.h
channel.cpp.o : channel.h
main.cpp.o: channel.h img_reader.h img_writer.h grey-scale.h

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
