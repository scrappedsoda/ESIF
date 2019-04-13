PROJECT = half-adder
TB		= tb
OBJS    = $(PROJECT).o


export SYSTEMC_HOME ?=/home/ldis/ESIF/systemc-2.3.3

prog:
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o main main.cpp $(TB).cpp $(PROJECT).cpp -lsystemc -lm -lstdc++

run:
	./$(PROJECT)
hello:
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o hello hello.cpp -lsystemc -lm
	./hello
