PROJECT = full-adder
PROJECTN = nbit-adder
USES	= half-adder
TB		= tb
OBJS    = $(PROJECT).o


export SYSTEMC_HOME =/home/ldis/ESIF/systemc-2.3.3

all: prog run

progfa: 
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o main-fa main-fa.cpp $(TB).cpp $(PROJECT).cpp $(USES).cpp -lsystemc -lm -lstdc++

prog:
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o main main.cpp $(PROJECT).cpp  $(USES).cpp -lsystemc -lm -lstdc++

runfa:
	./main-fa

run:
	./main

simulatefa:
	gtkwave main-fa.vcd &
simulate:
	gtkwave main.vcd &
