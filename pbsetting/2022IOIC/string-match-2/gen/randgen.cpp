#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 2);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int Q = atoi(argv[2]);
    string s = rnd.next("[a-z]{" + to_string(N) + "}");
    cout << N << " " << Q << endl;
    cout << s << endl;
    for(int i = 0; i < Q; i++) {
    	int l = rnd.next(1, N);
    	int r = rnd.next(l, N);
    	cout << l << " " << r << endl;
    }
}
