#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int MOD = 998244353;

int f(int x){
    string r = "", s = to_string(x);
    int res = 0;
    for(int i = 0; i < s.length(); i++){
        int k = s[i] - '0';
        res = (res*10 % MOD + k) % MOD;
        res = (res*10 % MOD + k) % MOD;
    }
    return res;
}

int N, x, ans = 0;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        ans = ( ans + f(x) * N % MOD ) % MOD;
    }
    cout << ans << endl;
}
