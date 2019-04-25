#include "img_writer.h"
#include "libbmp.h"

// use cerr for assert debug messages
#define ASSERT(expr, message)                                                  \
    do {                                                                       \
        if (!(expr)) {                                                         \
            cerr << message << endl;                                           \
        }                                                                      \
    } while (0)
// use assert
//#define ASSERT(expr, message) do {assert(expr);}while(0)

// comment this define to suppress output
#define DEBUG


void img_writer::writer(void) { 
		sc_uint<8> tout_r, tout_g, tout_b;

		int sink_width = 500;
		int sink_height = 588;
		BmpImg img(sink_width, sink_height);
  
		wait();
		
		std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>> rgb;
		bool data_valid;

		// wait until the first pixel arrived
		while (!(data_valid = in->d_read(rgb))) {
			wait();
		}
		// The image part
		for (int i = sink_width-1; i >= 0; i--) {
				for (int j = sink_height-1; j >= 0; j--) {
						

						tout_r = std::get<0>(rgb);
						tout_g = std::get<1>(rgb);
						tout_b = std::get<2>(rgb);
						
//#ifdef DEBUG
//						cout << "j: " << j << "\ti: " << i << "\t\t";
//						cout << tout_r << " " << tout_g << " " << tout_b << endl;
//#endif

						img.set_pixel(i, j, tout_r, tout_g, tout_b);
						wait();
						data_valid = in->d_read(rgb);
				}
		}

		wait();
		img.write("test_out.bmp");
		sc_stop(); 

}
