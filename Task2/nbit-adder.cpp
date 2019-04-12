/*
 * =====================================================================================
 *
 *       Filename:  nbit-adder.cpp
 *
 *    Description:  nbit-adder implementation
 *
 *        Version:  1.0
 *        Created:  04/11/2019 07:01:08 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Glinserer Andreas (AGL), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "nbit-adder.h"


template <int size>
void nbit_adder<size>::split(void) {
		sc_uint<size> tmp_bus_a = nbit_adder<size>::in_a.read();
		sc_uint<size> tmp_bus_b = nbit_adder<size>::in_b.read();
		
		for (int i = 0; i < size; i++) {
				tmp_a[i] = tmp_bus_a[i];
				tmp_b[i] = tmp_bus_b[i];
		}
}

template <int size>
void nbit_adder<size>::merge(void) {
		sc_uint<size> tmp_bus_s; 
		for (int i = 0; i < size; i++) {
				tmp_bus_s[i] = nbit_adder<size>::tmp_s[i].read();
		}
		nbit_adder<size>::out_s.write(tmp_bus_s);
		nbit_adder<size>::out_c.write(nbit_adder<size>::tmp_c[size-1]);
}
