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
    string s = rnd.next("[a-z]{" + to_string((N / 2) / 2) + "}");
    
    cout << N << " " << Q << endl;
    for(int i = 0; i < N - 2 * (int)s.length(); i++) cout << rnd.next("[a-z]{1}");
    cout << s << s << endl;
    
    
    for(int i = 0; i < Q; i++) {
    	int l = rnd.next(N - 2 * s.length(), N - s.length());
    	int r = rnd.next(l, N - (int)s.length());
    	cout << l << " " << r << endl;
    }
}
