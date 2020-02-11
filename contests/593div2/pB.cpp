#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int n, m;

int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = exp(b, e/2);
    res=  res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

signed main(){
    cin >> n >> m;
    n %= MOD;
    cout << exp((exp(2, m) - 1 + MOD) % MOD, n);
}
