
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
#include "channel_if.h"

SC_MODULE(img_reader) 
{
		sc_in<bool> in_clk;
		sc_port<channel_write_if> out;

		
		void reader(void);		// creates the values

		SC_CTOR(img_reader)
		{
				SC_CTHREAD(reader, in_clk.neg());
//				sensitive << in_clk.neg();
		}

};
