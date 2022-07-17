#include "testlib.h"
#include <string.h>

const long long int MAXT = 1e5, MAXR = 1e12;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    
    int T = inf.readInt(1, MAXT);
    inf.readEoln();

    for(int i = 0; i < T; i++) {
        int l = inf.readLong(1, MAXR);
        inf.readSpace();
        int r = inf.readLong(l, MAXR);
        inf.readSpace();
        int n = inf.readLong(1, MAXR);
        inf.readEoln();
    }

    inf.readEof();
}
