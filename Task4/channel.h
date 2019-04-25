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
			bool data_valid;

		public:
			channel(sc_module_name nm) : sc_module(nm), data_valid(false){

			}
			
			void d_write(char datar, char datag, char datab);
			
			bool d_read(std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>>& rgb);

};
