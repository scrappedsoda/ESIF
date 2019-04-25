/*
 * =====================================================================================
 *
 *       Filename:  nbit-adder.h
 *
 *    Description:  nbit-header file
 *
 *        Version:  1.0
 *        Created:  04/11/2019 06:20:32 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Glinserer Andreas (AGL), 
 *   Organization:  
 *
 * =====================================================================================
 */

// Important -> parameterized things need their methods defined in the header instead of
// a separate .cpp file. This has to do with compiler issues. Source:
// https://www.doulos.com/knowhow/systemc/faq/#q2
#include "full-adder.h"
#include <string>

template <int size=4>
SC_MODULE (nbit_adder) {
		// The input and output signals
		sc_in<sc_uint<size> > in_a;
		sc_in<sc_uint<size> > in_b;
		sc_in<bool> in_cin;
		sc_in<bool> in_clk;

		sc_out<sc_uint<size> > out_s;
		sc_out<bool> out_c;

		// intermediate signals or signals i need to convert from vector to single signal
		sc_signal<bool> tmp_a[size];
		sc_signal<bool> tmp_b[size];
		sc_signal<bool> tmp_c[size];
		sc_signal<bool> tmp_s[size];

		
		// the array of full adders declaration
		full_adder *faddas[size];		// faddas = full adders (addas)

		// the methods which join and separate the busses
		void split(void);
		void merge(void);
	
		// constructor
		SC_CTOR(nbit_adder) {
			// initialising this whole thing with the full adders
			std::string name;
			for (int i = 0; i < size; i++) {
					name = "fa" + std::to_string(i);
					faddas[i] = new full_adder(name.c_str());
			}
			// the first full adder has to be done by hand
			faddas[0] -> in_a(tmp_a[0]);
			faddas[0] -> in_b(tmp_b[0]);
			faddas[0] -> in_cin(in_cin);
			faddas[0] -> out_s(tmp_s[0]);
			faddas[0] -> out_cout(tmp_c[0]);

			// the other full adders are done via for loop
			for (int i = 1; i < size; i++) {
					faddas[i] -> in_a(tmp_a[i]);
					faddas[i] -> in_b(tmp_b[i]);
					faddas[i] -> in_cin(tmp_c[i-1]);
					faddas[i] -> out_s(tmp_s[i]);
					faddas[i] -> out_cout(tmp_c[i]);
			}

			// The methods to split the input vectors
			SC_METHOD(split);
			sensitive << in_clk;
//			sensitive << in_a << in_b << in_cin;
			// The method which merges the output vectors
			SC_METHOD(merge);
			for (int i = 0; i < size; i++) {
					sensitive << tmp_s[i] << tmp_c[i];
			}
			//sensitive << in_a << in_b << in_cin;
			//sensitive << tmp_s << tmp_c;

		}

		// destructor
		~nbit_adder() {
				for (int i = 0; i < size; i++) {
						delete faddas[i];
				}
		}
};

template <int size>
void nbit_adder<size>::split(void) {
		sc_uint<size> tmp_bus_a = nbit_adder<size>::in_a.read();
		sc_uint<size> tmp_bus_b = nbit_adder<size>::in_b.read();
		
		for (int i = 0; i < size; i++) {
				nbit_adder<size>::tmp_a[i] = tmp_bus_a[i];
				nbit_adder<size>::tmp_b[i] = tmp_bus_b[i];
		}
}

template <int size>
void nbit_adder<size>::merge(void) {
		sc_uint<size> tmp_bus_s; 
		for (int i = 0; i < size; i++) {
				tmp_bus_s[i] = nbit_adder<size>::tmp_s[i];
		}
		nbit_adder<size>::out_s.write(tmp_bus_s);
		nbit_adder<size>::out_c.write(nbit_adder<size>::tmp_c[size-1]);
}
