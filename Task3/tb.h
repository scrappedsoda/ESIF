
/*
 * =====================================================================================
 *
 *       Filename:  tb.h
 *
 *    Description:  testbench header for grey_scale
 *
 *        Version:  1.0
 *        Created:  04/14/2019 02:44:00 PM
 *       Revision:  none
 *       Compiler:  g++
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
		sc_out<sc_uint<8>> img_r, img_g, img_b;
		sc_in<sc_uint<8>> greyscale_r, greyscale_g, greyscale_b;
		
		void source(void);		// creates the values
		void sink(void);		// reads the values

		SC_CTOR(tb)
		{
				// changed to thread because these are easier to handle (at least for me)
				// the big advantage is the possibility to use sc_wait with times
				//
				// source triggers at neg edge to simulate something like data has to be 
				// there before the edge (setup_time)
				SC_THREAD(source);
				sensitive << in_clk.neg();
				SC_THREAD(sink);
				sensitive << in_clk.pos();

//				SC_CTHREAD(source, in_clk.neg() );
//				SC_CTHREAD(sink, in_clk.pos() );
		}

};
