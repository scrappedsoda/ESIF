/*
 * =====================================================================================
 *
 *       Filename:  tb.h
 *
 *    Description:  testbench header
 *
 *        Version:  1.0
 *        Created:  04/10/2019 07:46:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "systemc.h"

SC_MODULE(tb) 
{
		sc_in<bool> in_clk;
		sc_out<bool> in_a, in_b, in_cin;
		sc_in<bool> out_s, out_c;

		void source(void);		// creates the values
		void sink(void);		// reads the values

		SC_CTOR(tb)
		{
				SC_CTHREAD(source, in_clk.pos() );
				SC_CTHREAD(sink, in_clk.pos() );
		}
};

