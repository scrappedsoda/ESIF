/*
 * =====================================================================================
 *
 *       Filename:  main file
 *
 *    Description:  top level to design which instantiates the DUT and the TB
 *
 *        Version:  1.0
 *        Created:  04/14/2019 02:07:00 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#define DEBUG 0

#include "systemc.h"

#include "grey-scale.h"
#include "img_writer.h"
#include "img_reader.h"
#include "channel.h"

SC_MODULE(SYSTEM) {
	img_reader *imr0;
	img_writer *imw0;
    grey_scale *grey_scale0;

	channel *cha0;
	channel *cha1;

    sc_clock sig_clk;

    SC_CTOR(SYSTEM) : sig_clk("clk_sig", 10, SC_NS) {
		cha0 = new channel("m_channel0");
		cha1 = new channel("m_channel1");

		imr0 = new img_reader("imr0");
		imr0->in_clk (sig_clk);
		imr0->out (*cha0);

        grey_scale0 = new grey_scale("grey_scale0");
        grey_scale0->clk(sig_clk);
		grey_scale0->in(*cha0);
		grey_scale0->out(*cha1);

		imw0 = new img_writer("img_writer0");
		imw0->in_clk(sig_clk);
		imw0->in(*cha1);
    }

    // Destructor to free the mem
    ~SYSTEM() {
        delete imr0;
        delete imw0;
        delete grey_scale0;
    }
};

SYSTEM *top = NULL;

// the main functio where the magic happens
int sc_main(int argc, char *argv[]) {
    // instantiate the top level and start the simulation
    top = new SYSTEM("top");


    // put everything into a vcd file
    sc_trace_file *wf = sc_create_vcd_trace_file("main");
    // variables to be traced
    // sc_trace(wf, top->grey_scale0->in, "greyscale_in");
//    sc_trace(
//    sc_trace(wf, top->sig_in_g, "sig_in_g");
//    sc_trace(wf, top->sig_in_b, "sig_in_b");
//    sc_trace(wf, top->sig_out_r, "sig_out_r");
//    sc_trace(wf, top->sig_out_g, "sig_out_g");
//    sc_trace(wf, top->sig_out_b, "sig_out_b");
    sc_trace(wf, top->sig_clk, "sig_clk");

    sc_start();
    return 0;
}
