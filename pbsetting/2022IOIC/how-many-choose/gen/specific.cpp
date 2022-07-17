#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
#define ll long long int
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 4);
    registerGen(argc, argv, 1);
    ll T = atoll(argv[1]);
    ll L = atoll(argv[2]);
    ll R = atoll(argv[3]);
    ll N = atoll(argv[4]);

    cout << "T = " T << endl;
    for(int i = 0; i < T; i++) {
        cout << L << " " << R << " " << N << endl;
    }
}
