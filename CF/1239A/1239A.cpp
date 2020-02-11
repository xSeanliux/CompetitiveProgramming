#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, MOD = 1e9 + 7;

int n, m, dp[maxN];

inline int getdp(int x){
    return (x < 0) ? 0 : dp[x];
}

signed main(){
    cin >> n >> m;
    dp[0] = 0;
    dp[1] = 1;
    int cs = 0;
    if(n < m) swap(n, m);
    for(int i = 2; i < n; i++){
        dp[i] = cs + 1;
        cs = (dp[i - 1] + cs) % MOD;
    }
    int ans = 2;
    if(m > 1){
        ans = (ans + 2 * (2 * getdp(m - 1) + getdp(m - 2) - 1))%MOD;
    }
    if(n > 1){
        ans = (ans + 2 * (2 * getdp(n - 1) + getdp(n - 2) - 1))%MOD;
    }
    cout << ans << endl;
}
