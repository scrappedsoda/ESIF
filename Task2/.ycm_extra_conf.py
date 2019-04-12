def Settings(**kwargs):
    return {
        'flags':['-x','c++','-Wall', '-I.', '-I/home/ldis/ESIF/systemc-2.3.3/include', '-L.', '-L/home/ldis/ESIF/systemc-2.3.3/lib-linux64', '-Wl,-rpath=/home/ldis/ESIF/systemc-2.3.3/lib-linux64', '-lm', '-lsystemc'],
    }
