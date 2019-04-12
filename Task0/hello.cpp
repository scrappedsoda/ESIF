/*
 * =====================================================================================
 *
 *       Filename:  hello.cpp
 *
 *    Description:  Hello World
 *
 *        Version:  1.0
 *        Created:  04/10/2019 12:26:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Glinserer Andreas, 
 *   Organization:  -
 *
 * =====================================================================================
 */


#include "systemc.h"

SC_MODULE(hello_world) {
		SC_CTOR(hello_world) {

		}

		void sayHello() {
				// print hello world into the console
				cout << "Hello World" << endl;
		}
};

int sc_main(int argc, char* argv[]) {
		hello_world hello("HELLO");
		hello.sayHello();
		return 0;
}
