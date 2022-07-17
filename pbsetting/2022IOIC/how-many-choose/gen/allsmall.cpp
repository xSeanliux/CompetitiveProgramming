#include "testlib.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define ll long long int
using namespace std;

ll C[45][45];
vector<ll> Cs;

inline void getC() {
    C[0][0] = 1;
    Cs.push_back(1);
    for(int i = 1; i < 45; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 2; j < i; j++){
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            Cs.push_back(C[i][j]);
        }
    }
    sort(Cs.begin(), Cs.end());
    int sz = unique(Cs.begin(), Cs.end()) - Cs.begin();
    vector<ll> nc = vector<ll>();
    for(int i = 0LL; i < sz; i++) nc.push_back(Cs[i]);
    Cs = nc; 
    nc = vector<ll>();
}

int main(int argc, char* argv[]) {
    assert(argc > 1);
    registerGen(argc, argv, 1);
    int T = atoi(argv[1]);

    getC();

    cout << T << endl;
    for(int i = 0; i < T; i++) {
        ll l = max(1LL, rnd.any(Cs) + rnd.next(-1, 1));
        ll r = max(1LL, rnd.any(Cs) + rnd.next(-1, 1));
        ll n = rnd.next(5LL, 44LL);
        if(l > r) swap(l, r);
        cout << l << " " << r << " " << n << endl;
    }
}
