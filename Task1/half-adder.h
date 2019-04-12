#define DEBUG_SYSTEMC // #undef this to disable assertions.

#include "systemc.h"

struct half_adder: sc_module {
		sc_in<bool> in_clk;
		sc_in<sc_uint<1>> in_a, in_b;
		sc_out<sc_uint<1>> out_s, out_c;
		SC_CTOR(half_adder)
		{
				SC_METHOD(addIt)
			 	sensitive << in_clk << in_a << in_b;
		}

		void addIt();
};


