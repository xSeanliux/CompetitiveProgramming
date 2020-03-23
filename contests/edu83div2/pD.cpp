#include <iostream>
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 2e5 + 10;

int n, m, fact[maxN];

int expmod(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int r = expmod(b, e/2);
    r = r * r % MOD;
    if(e & 1) r = r * b % MOD;
    return r;
}

int inv(int x){
    return expmod(x, MOD - 2);
}

int choose(int a, int b){
    if(b > a) return 0;
    return (fact[a] * inv(fact[b]) % MOD) * inv(fact[a - b]) % MOD;
}

signed main(){
    fact[0] = 1;
    for(int i = 1; i < maxN; i++) fact[i] = i * fact[i - 1] % MOD;
    cin >> n >> m;
    if(n == 2){
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    for(int x = 1; x <= m; x++){
        ans = (ans + ((expmod(2, n - 3) % MOD) * ((choose(m - 1, n - 2) - choose(x - 1, n - 2) + MOD) % MOD) % MOD)) % MOD;
    }
    cout << ans << endl;
}
