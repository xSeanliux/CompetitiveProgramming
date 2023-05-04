//#pragma gcc target("avx2")
//#pragma gcc("Ofast")
#include <bits/stdc++.h>
#define int long long int 
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

inline int ceil(int a, int b) {
    return a <= 0 ? 0LL : (a + b - 1) / b;
}

void solve() {
    int Q, a, b, n, t;
    int l = 1, r = 2e18;
    cin >> Q;
    while(Q--) {
        cin >> t >> a >> b;
        if(t == 1) {
            cin >> n;

            int nr = (a - b) * (n - 1) + a;
            int nl = (a - b) * (n - 2) + a + 1;
            if(n == 1) nl = 1;
            //cout << "for " << t << " " << a << " " << b << " " << n << ": " << nl << ", " << nr << endl;
            if(nr < l || r < nl) {
                cout << "0 ";
            } else {
                l = max(l, nl);
                r = min(r, nr);
                cout << "1 ";
            }
        } else {
            int t1 = max(0LL, ceil(r - a, a - b)) + 1;
            int t2 = max(0LL, ceil(l - a, a - b)) + 1;
            if(t1 != t2) cout << "-1 ";
            else cout << t1 << " ";
        }
    }
    cout << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}

