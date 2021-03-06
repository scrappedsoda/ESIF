/*
 * =====================================================================================
 *
 *       Filename:  grey-scale.h
 *
 *    Description:  header for grey scale image processor
 *
 *        Version:  1.0
 *        Created:  04/14/2019 02:07:00 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:
 *   Organization:
 *
 * =====================================================================================
 */

#include "systemc.h"

struct grey_scale : sc_module {
    sc_in<bool> clk;
    sc_in<sc_uint<8>> in_r, in_g, in_b;
    sc_out<sc_uint<8>> out_r, out_g, out_b;

	void greyifer(void);

    SC_CTOR(grey_scale) { 
			SC_METHOD(greyifer);
			sensitive << clk.pos();// << in_r << in_g << in_b;
			//	wenn ich de method nur auf clk.pos sensitive mache hab ich eine periode
			//	delay dabei
//			sensitive << clk.pos(); 

	}
};
