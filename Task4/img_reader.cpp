#include "img_reader.h"
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

void img_reader::reader() {
		sc_uint<8> tmp_r, tmp_g, tmp_b;

		BmpImg img;
		img.read("test2.bmp");

		int width  = img.get_width();
		int height = img.get_height();

#ifdef DEBUG
		cout << "Image" << endl;
		cout << "width: " << width << "\theight: " << height << endl;
#endif

		for (int i = width-1; i >= 0; i--) {
				for (int j = height-1; j >= 0; j--) {
						tmp_r = img.red_at(i,j);
						tmp_g = img.green_at(i,j);
						tmp_b = img.blue_at(i,j);
						out->d_write(tmp_r, tmp_g, tmp_b);

//#ifdef DEBUG
//						cout << "j: " << j << "\ti: " << i << "\t\t";
//						cout << tmp_r << " " << tmp_g << " " << tmp_b << endl;
//#endif
						wait();
				}
		}
}
