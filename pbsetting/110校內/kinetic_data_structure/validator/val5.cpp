#include "testlib.h"

const int MAXN = 1e5, MAXC = 1e9;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int N = inf.readInt(1, MAXN, "N");
    inf.readSpace();
    int Q = inf.readInt(1, MAXN, "Q");
	inf.readEoln();

    for(int i = 0; i < N; i++){
    	inf.readInt(0, MAXC);
    	if(i < N - 1) inf.readSpace();
    	else inf.readEoln();
    }
    for(int i = 0; i < N; i++){
    	inf.readInt(0, MAXC);
    	if(i < N - 1) inf.readSpace();
    	else inf.readEoln();
    }

    bool used3 = false;
    int c, l, r, x;
    for(int i = 0; i < Q; i++){
    	c = inf.readInt(1, 3);

    	ensuref(c == 2 || c == 3, "only operations of types 1 and 3");

    	inf.readSpace();
    	l = inf.readInt(1, N);
		inf.readSpace();
		r = inf.readInt(l, N);
    	if(c <= 2){
    		inf.readSpace();
    		x = inf.readInt(0, MAXC);
    	} else used3 = true;
    	inf.readEoln();
    }
    ensuref(used3, "must have at least one query");
    
    inf.readEof();
}
