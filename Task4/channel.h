/*
 * =====================================================================================
 *
 *       Filename:  channel.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2019 11:11:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "channel_if.h"


class channel : public sc_module, public channel_write_if, public channel_read_if
{
		private:
			sc_uint<8> data[3];

		public:
			channel(sc_module_name nm) : sc_module(nm)
			{
				
			}

			void d_write(char datar, char datag, char datab) 
			{
				data[0] = datar;
				data[1] = datag;
				data[2] = datab;
			}

			std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>> d_read() 
			{
				return std::make_tuple(data[0], data[1], data[2]);
			}

};
