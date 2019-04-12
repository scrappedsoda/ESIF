
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
		}
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
		// send stimulus to the ha
		for (int i = 0; i < 8; i++)
		{
				tmp_a = i;
				tmp_b = i/2;
				in_a.write(tmp_a);
				in_b.write(tmp_b);
				in_cin.write(tmp_c);
				cout << i << ":\t a:" << tmp_a.to_int() << ",\t b:" << tmp_b.to_int() << endl;
				wait();
		}
		tmp_a = 32;
		tmp_b = 32;
		in_a.write(tmp_a);
		in_b.write(tmp_b);
		wait();

}

// check (here write) the signals which come from the DUT
template <int size>
void tb<size>::sink(void) {
		sc_uint<size> tmp_s;
		bool tmp_c;
		// Read output from the DUT
		//wait();
		  
		for( int i = 0; i < 12; i++)
		{
				tmp_s = out_s.read();
				tmp_c = out_c.read();
				cout << i << ":\t s:" << tmp_s.to_int() << ",\t c:" << tmp_c << endl;
				wait();
		}

		// End simulation
		sc_stop();		// stops the simulation and calls the modules destructor
		
}

