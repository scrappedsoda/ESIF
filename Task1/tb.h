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

typedef struct {
	unsigned int a, 
		b, 
		expectedSumBit,
		expectedCarryBit;
} TestPattern_t;

SC_MODULE(tb) 
{
		sc_in<bool> in_clk;
		sc_out<sc_uint<1>> in_a, in_b;
		sc_in<sc_uint<1>> out_s, out_c;

		void source(void);		// creates the values
		void sink(void);		// reads the values

		TestPattern_t getPattern(int i);

		SC_CTOR(tb)
		{
				SC_CTHREAD(source, in_clk.pos() );
				SC_CTHREAD(sink, in_clk.pos() );
		}
};

