#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int Q = atoi(argv[2]);

    cout << N << " " << Q << endl;
    for(int i = 0; i < N; i++) {
        cout << ((i == N - 1) ? 'a' : 'b'); 
    }
    cout << endl;
    
    for(int i = 0; i < Q; i++) {
    	cout << (N / 2) + (i % 3) + 1 << " " << N << endl;
    } 
}
