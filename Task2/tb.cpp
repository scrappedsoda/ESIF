/*
 * =====================================================================================
 *
 *       Filename:  tb-fa.cpp
 *
 *    Description:  the testbench
 *
 *        Version:  1.0
 *        Created:  04/10/2019 07:49:37 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


//#include "tb.h"

// here are the stimulus generated
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
		sc_uint<1> tmp_c=0;
		// send stimulus to the ha
		for (int i = 0; i < 8; i++)
		{
				tmp_a = i;
				tmp_b = i/2;
				in_a.write(tmp_a);
				in_b.write(tmp_b);
				in_cin.write(tmp_c);
				wait();
		}
}

// check (here write) the signals which come from the DUT
template <int size>
void tb<size>::sink(void) {
		sc_uint<size> tmp_s;
		sc_uint<1> tmp_c;
		// Read output from the DUT
		wait();
		  
		for( int i = 0; i < 8; i++)
		{
				tmp_s = out_s.read();
				tmp_c = out_c.read();
				wait();
				cout << i << ":\t s:" << tmp_s.to_int() << ",\t c:" << tmp_c.to_int() << endl;
		}

		// End simulation
		sc_stop();		// stops the simulation and calls the modules destructor
		
}
