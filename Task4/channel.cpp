#include "channel.h"

void channel::d_write(char datar, char datag, char datab) {
    data_valid = true;
    data[0] = datar;
    data[1] = datag;
    data[2] = datab;
}

bool channel::d_read(std::tuple<sc_uint<8>, sc_uint<8>, sc_uint<8>> &rgb) {
    if (data_valid) {
        rgb = std::make_tuple(data[0], data[1], data[2]);
        return true;
    }
    return false;
}