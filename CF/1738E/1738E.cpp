#include <bits/stdc++.h>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 10, MOD = 998244353;
int pow2[maxN], fact[maxN], invfact[maxN];

inline int mpow(int b, int e) {
    int r = 1;
    while(e) {
        if(e & 1) r = r * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return r;
}

inline int inv(int x) {
    return mpow(x, MOD - 2);
}

inline int choose(int n, int k) {
    if(n < k) return 0;
    return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD;
}

inline int choose2(int a, int b) {
    if(a > b) swap(a, b);
    int res = 0;
    for(int i = 0; i <= a; i++) res = (res + choose(a, i) * choose(b, i) % MOD) % MOD;
    return res;
}

inline void solve() {
    int N;
    cin >> N;
    vector<int> arr = vector<int>(N);
    vector<int> pre = vector<int>(N);
    vector<int> suf = vector<int>(N);
    for(int i = 0; i < N; i++) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), pre.begin()); //wow lol
    for(int i = 0; i < N; i++) suf[i] = pre[N - 1] - pre[i] + arr[i];

    vector<pii> pairs = vector<pii>();

    int rp = N - 1, lp = 0, midsize = 0;
    while(lp <= rp) {
        //cout << "lp = " << lp << ", rp = " << rp << endl;
        if(pre[lp] < suf[rp]) lp++;
        else if(pre[lp] > suf[rp]) rp--;
        else {
            int a = 0, b = 0, v = pre[lp];
            while(lp <= rp && pre[lp] == v) {
                lp++;
                a++;
            }
            while(lp <= rp && v == suf[rp]) {
                rp--;
                b++;
            }
            if(lp > rp) {
                midsize = a + b;
                break;
            }
            
            pairs.emplace_back(a, b);
        }
    }
    //cout << "midsize = " << midsize << endl;
    int ans = (midsize ? pow2[midsize - 1] : 1);
    //cout << "init ans = " << ans << endl;
    for(auto [a, b] : pairs) {
        //cout << "a = " << a << ", b = " << b << endl;
        ans = (choose2(a, b) * ans) % MOD;
    }
    cout << ans << endl;
}

signed main() {
    pow2[0] = 1;
    for(int i = 1; i < maxN; i++) pow2[i] = (2 * pow2[i - 1]) % MOD;
    fact[0] = 1;
    for(int i = 1; i < maxN; i++) fact[i] = (i * fact[i - 1]) % MOD; 
    for(int i = 0; i < maxN; i++) invfact[i] = inv(fact[i]); 
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
