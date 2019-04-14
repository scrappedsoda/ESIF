#include "tb.h"

// use cerr for assert debug messages
#define ASSERT(expr, message)                                                  \
    do {                                                                       \
        if (!(expr)) {                                                         \
            cerr << message << endl;                                           \
        }                                                                      \
    } while (0)
// use assert
//#define ASSERT(expr, message) do {assert(expr);}while(0)

void tb::source(void) {}

void tb::sink(void) { sc_stop(); }