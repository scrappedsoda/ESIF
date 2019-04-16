#include "tb.h"
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

void tb::source() {
		sc_uint<8> tmp_r, tmp_g, tmp_b;

		// after the negative edge wait another edge
		wait();
		// wait 3 ms to get the in the middle of the low part
		wait(3, SC_NS);

		for (int i = 0; i < 10; i++) {
				tmp_r = i+50;
				tmp_g = i*10;
				tmp_b = i*20;

				img_r.write(tmp_r);
				img_g.write(tmp_g);
				img_b.write(tmp_b);
#ifdef DEBUG
				cout << "At time " << sc_time_stamp() << " Source:\t";
				cout << "r: " << tmp_r << "\tg: " << tmp_g << "\tb: " << tmp_b << endl;
#endif
				// same wait procedure as above
				wait();
				wait(3, SC_NS);


		}
		
		// here starts the image part
		BmpImg img;
		img.read("test2.bmp");
		int width  = img.get_width();
		int heigth = img.get_height();

#ifdef DEBUG
		cout << "Image" << endl;
		cout << "width: " << width << "\theigth: " << heigth << endl;
#endif

		for (int i = width-1; i >= 0; i--) {
				for (int j = heigth-1; j >= 0; j--) {
						tmp_r = img.red_at(i,j);
						tmp_g = img.green_at(i,j);
						tmp_b = img.blue_at(i,j);
						img_r.write(tmp_r);
						img_g.write(tmp_g);
						img_b.write(tmp_b);
#ifdef DEBUG
						cout << "j: " << j << "\ti: " << i << "\t\t";
						cout << tmp_r << " " << tmp_g << " " << tmp_b << endl;
#endif
						wait();
						wait(3, SC_NS);
				}
		}
}

void tb::sink(void) { 
		sc_uint<8> tout_r, tout_g, tout_b;
		int sink_width = 500;
		int sink_height = 588;
		BmpImg img(sink_width, sink_height);
  
		wait();
		for (int i = 0; i < 10; i++) {
				tout_r = greyscale_r.read();
				tout_g = greyscale_g.read();
				tout_b = greyscale_b.read();
#ifdef DEBUG
				cout << "At time " << sc_time_stamp() << " Sink:\t";
				cout << "r: " << tout_r << "\tg: " << tout_g << "\tb: " << tout_b << endl;
#endif
				wait();
		}
		
		// The image part
		for (int i = sink_width-1; i >= 0; i--) {
				for (int j = sink_height-1; j >= 0; j--) {

						tout_r = greyscale_r.read();
						tout_g = greyscale_g.read();
						tout_b = greyscale_b.read();
						
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
