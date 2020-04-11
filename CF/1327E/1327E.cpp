#include <iostream>
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 2e5 + 10;

int N, ans;

inline int add(int a, int b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

int modexp(int b, int e){
    if(e < 0) return 0;
    int r = 1, c = b;
    for(int i = 0; i < 30; i++){
        if((e >> i) & 1) r = r * c % MOD;
        c = c * c % MOD;
    }
    return r;
}

signed main(){
    cin >> N;
    for(int l = 1; l < N; l++){
        cout <<  (2 * 90 * modexp(10, N - l - 1) + 810 * modexp(10, N - l - 2) % MOD * (N - l - 1) ) % MOD << " ";
    }
    cout << 10;
}
