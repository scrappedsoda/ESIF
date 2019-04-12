/*
 * =====================================================================================
 *
 *       Filename:  half-adder.cpp
 *
 *    Description:  half-adder 
 *
 *        Version:  1.0
 *        Created:  04/10/2019 07:46:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "half-adder.h"

void half_adder::addIt(void)
{
		half_adder::out_s.write(half_adder::in_a.read() xor half_adder::in_b.read());
		half_adder::out_c.write(half_adder::in_a.read() and half_adder::in_b.read());
}

