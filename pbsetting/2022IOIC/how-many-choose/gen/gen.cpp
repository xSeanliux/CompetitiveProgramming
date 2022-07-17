#include "testlib.h"
#include <cassert>
#include <iostream>
#include <string>
#define ll long long int
using namespace std;

int main(int argc, char* argv[]) {
    assert(argc > 3);
    registerGen(argc, argv, 1);
    ll T = atoll(argv[1]);
    ll MAXR = atoll(argv[2]);
    ll MAXN = atoll(argv[3]);
    cout << T << endl;
    for(int i = 0; i < T; i++) {
        ll l = rnd.next(1LL, MAXR);
        ll r = rnd.next(l, MAXR);
        ll n = rnd.next(1LL, MAXN);
        cout << l << " " << r << " " << n << endl;
    }
}
