#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 3);
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int rep = atoi(argv[2]);
    int N = n * rep;
    int Q = atoi(argv[3]);

    cout << N << " " << Q << endl;
    string s = rnd.next("[a-z]{" + to_string(n) + "}");
    for(int i = 0; i < rep; i++) {
        s[0] = rnd.next("[a-z]{1}")[0];
        cout << s;
    }
    cout << endl;

    for(int i = 0; i < Q; i++) {
    	int l = rnd.next(1, N);
    	int r = rnd.next(l, N);
    	cout << l << " " << r << endl;
    }
}
