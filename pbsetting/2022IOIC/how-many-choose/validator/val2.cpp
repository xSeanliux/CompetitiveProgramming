#include "testlib.h"
#include <string.h>

const int MAXN = 1e5;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, MAXN, "N");
    inf.readSpace();
    int Q = inf.readInt(1, MAXN, "Q");
    inf.readEoln();
    ensuref(N <= (int)1e6 / Q, "NQ <= 1e6 has to be satisfied");

    std::string s = inf.readString("[a-z]+");
    ensuref(s.length() == N, "s has to have length N");
    inf.readEoln();

    for(int i = 0; i < Q; i++) {
    	int l = inf.readInt(1, N, "l");
	    inf.readSpace();
	    int r = inf.readInt(l, N, "r");
	    inf.readEoln();
	    if(i < Q - 1) inf.readEoln();
	    else inf.readEof();
    }
}
