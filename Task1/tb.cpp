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
				tmp_a = i%2;
				tmp_b = (i/2)%2;
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
		}

		// End simulation
		sc_stop();		// stops the simulation and calls the modules destructor
}
