/*
 * =====================================================================================
 *
 *       Filename:  tb.cpp
 *
 *    Description:  the testbench
 *
 *        Version:  1.0
 *        Created:  04/10/2019 07:49:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include "tb.h"

TestPattern_t tb::getPattern(int i) {
	TestPattern_t pattern;
	pattern.a = i%2;
	pattern.b = (i/2)%2;
	unsigned int expectedSum = (i%2) + ((i/2)%2);
	pattern.expectedSumBit= (expectedSum) & 0x01;
	pattern.expectedCarryBit = (expectedSum >> 1) & 0x01;
	return pattern;
}

// here are the stimulus generated
void tb::source(void) {
		// Reset
		/* 
		 * inp.write(0);
		 * rst.write(1);
		 * wait();
		 * rst.write(0)
		 * wait();
		 * creates one full reset */

		sc_uint<1> tmp_a=0; 
		sc_uint<1> tmp_b=0;
		// send stimulus to the ha
		for (int i = 0; i < 4; i++)
		{
			TestPattern_t pattern = getPattern(i);
			tmp_a = pattern.a;
			tmp_b = pattern.b;
			in_a.write(tmp_a);
			in_b.write(tmp_b);
			wait();
		}
}

// check (here write) the signals which come from the DUT
void tb::sink(void) {
		sc_uint<1> tmp_s, tmp_c;
		// Read output from the DUT
		wait();
		for( int i = 0; i < 4; i++)
		{
				tmp_s = out_s.read();
				tmp_c = out_c.read();
				wait();
				cout << i << ":\t s:" << tmp_s.to_int() << ",\t c:" << tmp_c.to_int() << endl;

				// assert correct values for out_s and out_c
				TestPattern_t pattern = getPattern(i);
				if (pattern.expectedSumBit != tmp_s.to_uint()) {
					cerr << "sum bit error expected: " 
						<< pattern.expectedSumBit << " actual: " << tmp_s.to_uint() << endl;
				}
				if (pattern.expectedCarryBit != tmp_c.to_uint()) {
					cerr << "carry bit error expected: " 
						<< pattern.expectedCarryBit << " actual: " << tmp_c.to_uint() << endl;
				}
		}
		// End simulation
		sc_stop();		// stops the simulation and calls the modules destructor
}
