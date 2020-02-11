#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5, maxVal = 1e6, MOD = 998244353;
int N, cnt[maxVal + 10], W[maxVal], inv[maxVal], x;

inline void initW(){
    inv[1] = 1;
    for(int i = 2; i <= maxVal; i++){
        inv[i] = (MOD - MOD/i) * inv[(MOD % i)] % MOD;
    }
    W[1] = 1;
    for(int i = 2; i <= maxVal; i++) W[i] = inv[i];
    for(int i = 1; i <= maxVal; i++) {
        for(int j = 2 * i; j <= maxVal; j += i) W[j] = (W[j] + MOD - W[i]) % MOD;
    }
}

signed main(){
    ericxiao;
    cin >> N;
    int su = 0;
    for(int i = 0; i < N; i++){
        cin >> x;
        su = (su + x) % MOD;
        cnt[x]++;
    }
    initW();
    /*
    for(int i = 1; i <= 10; i++){
        cout << inv[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= 10; i++){
        cout << W[i] << " ";
    }

    cout << endl;
    */
    int ans = 0, tw;
    for(int d = 1; d <= maxVal; d++){
        tw = 0;
        for(int j = d; j <= maxVal; j += d){
            tw = (tw + cnt[j] * j) % MOD;
        }
        ans = (ans + ((tw * tw % MOD) * W[d]) % MOD) % MOD;
    }
    ans = (ans - su + MOD) % MOD;
    ans = ( ans * inv[2] ) % MOD;
    cout << ans << endl;
}
