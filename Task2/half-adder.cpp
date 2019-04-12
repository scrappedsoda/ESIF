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
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "half-adder.h"

void half_adder::addIt(void)
{
		half_adder::out_s = half_adder::in_a ^ half_adder::in_b;
		half_adder::out_c = half_adder::in_a & half_adder::in_b;
}

