/*
 * =====================================================================================
 *
 *       Filename:  full-adder.cpp
 *
 *    Description:  Full-Adder implementation
 *
 *        Version:  1.0
 *        Created:  04/11/2019 11:02:02 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Glinserer Andreas (AGL), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "full-adder.h"


void full_adder::carry_or(void) {
		full_adder::out_cout = full_adder::c1 | full_adder::c2;
//		full_adder::out_cout.write(full_adder::c1.read() | full_adder::c2.read());
}
