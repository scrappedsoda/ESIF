/*
 * =====================================================================================
 *
 *       Filename:  main file
 *
 *    Description:  top level to design which instantiates the DUT and the TB
 *
 *        Version:  1.0
 *        Created:  04/10/2019 06:37:55 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "nbit-adder.h"
#include "tb.h"

const int width = 6;
SC_MODULE( SYSTEM) {
		// fulladder and testbench instances
		tb<width>	*tb0;
		nbit_adder<width>	*add0;

		// signals which connect them
		sc_signal <sc_uint<width> > sig_a, sig_b;
	    sc_signal <bool> sig_cin;
		sc_signal <sc_uint<width> > sig_s;
		sc_signal <bool> sig_c;
		sc_clock sig_clk;

		// Constructor
		SC_CTOR (SYSTEM) 
				: sig_clk("clk_sig", 10, SC_NS)		// copy constructor
		{
				tb0 = new tb<width>("tb0");
				tb0 -> in_clk(sig_clk);
				tb0 -> in_a(sig_a);
				tb0 -> in_b(sig_b);
				tb0 -> in_cin(sig_cin);
				tb0 -> out_s(sig_s);
				tb0 -> out_c(sig_c);

				  
				add0 = new nbit_adder<width>("add0");
				add0 -> in_clk(sig_clk);
				add0 -> in_a(sig_a);
				add0 -> in_b(sig_b);
				add0 -> in_cin(sig_cin);
				add0 -> out_s(sig_s);
				add0 -> out_c(sig_c);
				
		}

		// Destructor to free the mem
		~SYSTEM() {
			delete tb0;
			delete add0;
		}
};

SYSTEM *top = NULL;

// the main functio where the magic happens
int sc_main(int argc, char* argv[]) {
		// instantiate the top level and start the simulation
		top = new SYSTEM("top");

		// put everything into a vcd file
		sc_trace_file *wf = sc_create_vcd_trace_file("main");
		// variables to be traced
		sc_trace(wf, top->sig_a, "sig_a");
		sc_trace(wf, top->sig_b, "sig_b");
		sc_trace(wf, top->sig_cin, "sig_cin");
		sc_trace(wf, top->sig_s, "sig_s");
		sc_trace(wf, top->sig_c, "sig_c");
		sc_trace(wf, top->sig_clk, "sig_clk");

		sc_start();
		return 0;
}


