#include "grey-scale.h"

#define DEBUG
// Using the greyscaling factor which multiplies
// R by 0.3, G by 0.59, B by 0.11
// and instead of these i multiply by
// R by 19, G by 38, B by 6 and divide all by
// 64 which equals a bitshift of 6 bits


// since the highest multiplication is with a 38
// and 38 is representable with 6 bits i need a 14
// bit vector to save the values but i am not sure
// if this is right so i use a 16 bit just to be sure
void grey_scale::greyifer(void) {
    sc_uint<8> coeffs[] = {19, 38, 7};
    sc_uint<16> sig_rm, sig_gm, sig_bm;
    sc_uint<18> tmp = 0;
    std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>> rgb;

    bool data_valid = in->d_read(rgb);
    if (data_valid) {		
        sig_rm = std::get<0>(rgb) * coeffs[0];
        sig_gm = std::get<1>(rgb) * coeffs[1];
        sig_bm = std::get<2>(rgb) * coeffs[2];

        // here i divide by 64 by shifting 7 bits
        // and add them together
        // shifting happens by only selecting the chosen ones
        tmp += sig_rm; //.range(13, 6);
        tmp += sig_gm; //.range(13, 6);
        tmp += sig_bm; //.range(13, 6);

        out->d_write(tmp.range(13,6), tmp.range(13,6), tmp.range(13,6));

        //		grey_scale::out_r.write( tmp);
        //		grey_scale::out_g.write( tmp);
        //		grey_scale::out_b.write( tmp);
    }
}
