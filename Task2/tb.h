
/*
 * =====================================================================================
 *
 *       Filename:  tb.h
 *
 *    Description:  testbench header for the nbit-adder
 *
 *        Version:  1.0
 *        Created:  04/10/2019 07:46:51 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "systemc.h"
#include <cstdlib>
#include <ctime>

#define RUNS (100)

// use cerr for assert debug messages
#define ASSERT(expr, message)  \
  do {                         \
    if (!(expr)) {             \
      cerr << message << endl; \
    }                          \
  } while (0)
// use assert
//#define ASSERT(expr, message) do {assert(expr);}while(0)

typedef struct {
  unsigned int a, b, expectedSum;
  bool expectedCarry;
} TestPattern_t;

template <int size=4>
SC_MODULE(tb) 
{
		sc_in<bool> in_clk;
		sc_out<sc_uint<size>> 	in_a, in_b; 
		sc_out<bool> 		in_cin;
		sc_in<sc_uint<size>> 	out_s;
		sc_in<bool> 	out_c;

		void source(void);		// creates the values
		void sink(void);		// reads the values

		SC_CTOR(tb)
		{
				SC_CTHREAD(source, in_clk.pos() );
				SC_CTHREAD(sink, in_clk.pos() );
				generatePatterns();
		}

		private:
			TestPattern_t patterns[RUNS];
			void generatePatterns(void);
			TestPattern_t generatePattern(void);
};

template <int size>
void tb<size>::source(void) {
		// Reset
		/* 
		 * inp.write(0);
		 * rst.write(1);
		 * wait();
		 * rst.write(0)
		 * wait();
		 * creates one full reset */

		  
		sc_uint<size> tmp_a=0; 
		sc_uint<size> tmp_b=0;
		bool tmp_c=0;
		// send stimulus to the n-bit adder
		for (int i = 0; i < RUNS; i++)
		{
			TestPattern_t pattern = patterns[i];
			tmp_a = pattern.a;
			tmp_b = pattern.b;
			in_a.write(tmp_a);
			in_b.write(tmp_b);
			in_cin.write(tmp_c);
			cout << i << ":\t a:" << tmp_a.to_int() << ",\t b:" << tmp_b.to_int() << endl;
			wait();
		}
}

// check (here write) the signals which come from the DUT
template <int size>
void tb<size>::sink(void) {
		sc_uint<size> tmp_s;
		bool tmp_c;
		// Read output from the DUT
		wait();
		  
		for( int i = 0; i < RUNS; i++)
		{
			TestPattern_t pattern = patterns[i];
			tmp_s = out_s.read();
			tmp_c = out_c.read();
			ASSERT(pattern.expectedSum == tmp_s.to_uint(), 
				"sum error expected " << pattern.expectedSum << " actual: " << tmp_s.to_uint());
			ASSERT(pattern.expectedCarry == tmp_c, 
				"carry error expected " << pattern.expectedCarry << " actual: " << tmp_c);
			cout << i << ":\t s:" << tmp_s.to_int() << ",\t c:" << tmp_c << endl;
			wait();
		}

		// End simulation
		sc_stop();		// stops the simulation and calls the modules destructor
		
}

template <int size>
TestPattern_t tb<size>::generatePattern(void) {
  TestPattern_t pattern;
  const unsigned int max_number = (1 << size) - 1;
  pattern.a = rand() % max_number + 1;
  pattern.b = rand() % max_number + 1;
  pattern.expectedSum = (pattern.a + pattern.b) & max_number;
  pattern.expectedCarry = (pattern.a + pattern.b) > max_number ? true : false;
  return pattern;
}


template <int size>
void tb<size>::generatePatterns(void) {
	srand(time(NULL));
	for(int i = 0; i < RUNS; i++) {
		patterns[i] = generatePattern();
	}
}
