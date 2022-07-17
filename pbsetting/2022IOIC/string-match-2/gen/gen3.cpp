#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int Q = N * (N + 1) / 2;

    cout << N << " " << Q << endl;
    for(int i = 0; i < N; i++) {
        cout << ((i < N / 2) ? 'a' : 'b'); 
    }
    cout << endl;
    
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            cout << i << " " << j << endl;
        }
    } 
}
