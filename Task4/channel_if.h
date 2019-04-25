/*
 * =====================================================================================
 *
 *       Filename:  fifo_if.h
 *
 *    Description:  Channel-Interface for a hierachial channel
 *
 *        Version:  1.0
 *        Created:  04/25/2019 10:17:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  
 *   Organization:  
 *
 * =====================================================================================
 */


#pragma once
#include "systemc.h"

class channel_write_if: virtual public sc_interface
{
		public:
				virtual void d_write(char datar, char datag, char datab) = 0;
};

class channel_read_if: virtual public sc_interface
{
		public:
				virtual std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>> d_read();
};

