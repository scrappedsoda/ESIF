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
		
		// The image part
		for (int i = sink_width-1; i >= 0; i--) {
				for (int j = sink_height-1; j >= 0; j--) {
						auto datain = in->d_read();

						tout_r = std::get<0>(datain);
						tout_g = std::get<1>(datain);
						tout_b = std::get<2>(datain);
						
#ifdef DEBUG
						cout << "j: " << j << "\ti: " << i << "\t\t";
						cout << tout_r << " " << tout_g << " " << tout_b << endl;
#endif

						img.set_pixel(i, j, tout_r, tout_g, tout_b);
						wait();

				}
		}

		wait();
		img.write("test_out.bmp");
		sc_stop(); 

}
