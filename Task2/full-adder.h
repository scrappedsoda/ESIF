/*
 * =====================================================================================
 *
 *       Filename:  full-adder.h
 *
 *    Description:  header for full adder
 *
 *        Version:  1.0
 *        Created:  04/11/2019 11:00:41 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Glinserer Andreas (AGL), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "half-adder.h"

struct full_adder: sc_module {
		sc_in<bool> in_a, in_b, in_cin;
		sc_out<bool> out_s, out_cout;

		sc_signal<bool> s1,c1,c2;

		half_adder *ha0;
		half_adder *ha1;
		SC_CTOR(full_adder)
		{
				ha0 = new half_adder("ha0");
				ha0 -> in_a(in_a);
				ha0 -> in_b(in_b);
				ha0 -> out_s(s1);
				ha0 -> out_c(c1);

				ha1 = new half_adder("ha1");
				ha1 -> in_a(s1);
				ha1 -> in_b(in_cin);
				ha1 -> out_s(out_s);
				ha1 -> out_c(c2);


				SC_METHOD(carry_or)
			 	sensitive << c1 << c2;
		}

		~ full_adder() {
				delete ha0;
				delete ha1;
		}

		void carry_or(void);
};
