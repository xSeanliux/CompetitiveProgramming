#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int maxN = (1 << 20) + 10, maxK = 19, M = 998244353;

int a[maxN], fact[maxN], cnts[maxK + 10], Log2[maxN], pos[maxN];

inline int lb(int n) {
    return n & -n;
}

struct BIT {
    int bit[maxN];
    BIT() {
        fill(bit, bit + maxN, 0);
    }
    void add(int p) {
        for(; p < maxN; p += lb(p)) bit[p]++;
    }
    int pre(int p) {
        int r = 0;
        if(p <= 0) return 0;
        for(; p; p -= lb(p)) r += bit[p];
        return r;
    }
    int sum(int l, int r) {
        return pre(r) - pre(l - 1);
    }
} bit;

inline void solve() {
    int k;
    cin >> k;
    int N = 1LL << k;
    bit = BIT();
    fill(cnts, cnts + maxK, 0);
    fill(pos, pos + maxN, -1);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        if(a[i] == -1) continue;
        pos[a[i]] = i; 
        bit.add(i);
    }
    int ans = 1;
    
    for(int t = k - 1; t >= 0; t--) {
        // doing numbers ( 2^t, 2^(t + 1) ]
        int blockSz = 1 << (k - t);
        int freeNumbers = 1 << t;
        // cout << "t = " << t << ", blockSz = " << blockSz << endl;
        // cout << "numbers in (" << (1 << t) << ", " << (1 << (t + 1)) << "]" << endl;

        for(int i = 1; i <= N; i += blockSz) {
            int hasCount = 0;
            // cout << "doing i = " << i << " to " << i + blockSz - 1 << endl;
            int filledCount = blockSz - bit.sum(i, i + blockSz - 1);
            for(int j = i; j < i + blockSz; j++) {
                hasCount += (a[j] > (1 << t)) && (a[j] <= (1 << (t + 1)));
            }
            // cout << "hasCount = " << hasCount << endl;
            if(hasCount > 1) {
                cout << 0 << endl;
                return;
            } else if(!hasCount) {
                ans = ans * filledCount % M;
                // cout << " ans *= " << filledCount << endl;
                bit.add(i);
            } else {
                freeNumbers--;
            }
        }
        // cout << "permutation: " << freeNumbers << "!" << endl;
        ans = ans * fact[freeNumbers] % M;
    }
    cout << ans << endl;
}

signed main() {
    fact[0] = 1;
    for(int i = 1; i < maxN; i++) fact[i] = i * fact[i - 1] % M;
    for(int i = 0; i < maxK; i++) Log2[1LL << i] = i;
    solve();
}

