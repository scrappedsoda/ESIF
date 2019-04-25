
/*
 * =====================================================================================
 *
 *       Filename:  img_writer.h
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
#include "channel_if.h"

SC_MODULE(img_writer) 
{
		sc_in<bool> in_clk;
		sc_port<channel_read_if> in;

		void writer(void);		// reads the values from the channel

		SC_CTOR(img_writer)
		{
				SC_THREAD(writer);
				sensitive << in_clk.pos();

//				SC_CTHREAD(source, in_clk.neg() );
//				SC_CTHREAD(sink, in_clk.pos() );
		}

};
