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

#include "grey-scale.h"
#include "systemc.h"
#include "tb.h"


SC_MODULE(SYSTEM) {
    tb *tb0;
    grey_scale *grey_scale0;

    sc_signal<sc_uint<8>> sig_in_r, sig_in_g, sig_in_b, sig_out_r, sig_out_g,
        sig_out_b;

    sc_clock sig_clk;

    SC_CTOR(SYSTEM) : sig_clk("clk_sig", 10, SC_NS) {
        tb0 = new tb("tb0");
        tb0->in_clk(sig_clk);
        tb0->img_r(sig_in_r);
        tb0->img_g(sig_in_g);
        tb0->img_b(sig_in_b);
        tb0->greyscale_r(sig_out_r);
        tb0->greyscale_g(sig_out_g);
        tb0->greyscale_b(sig_out_b);

        grey_scale0 = new grey_scale("grey_scale0");
        grey_scale0->in_r(sig_in_r);
        grey_scale0->in_g(sig_in_g);
        grey_scale0->in_b(sig_in_b);
        grey_scale0->out_r(sig_out_r);
        grey_scale0->out_g(sig_out_g);
        grey_scale0->out_b(sig_out_b);
        grey_scale0->clk(sig_clk);
    }

    // Destructor to free the mem
    ~SYSTEM() {
        delete tb0;
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
    sc_trace(wf, top->sig_in_r, "sig_in_r");
    sc_trace(wf, top->sig_in_g, "sig_in_g");
    sc_trace(wf, top->sig_in_b, "sig_in_b");
    sc_trace(wf, top->sig_out_r, "sig_out_r");
    sc_trace(wf, top->sig_out_g, "sig_out_g");
    sc_trace(wf, top->sig_out_b, "sig_out_b");
    sc_trace(wf, top->sig_clk, "sig_clk");

    sc_start();
    return 0;
}
