#include <iostream>
#define int long long int
using namespace std;

inline void solve() {
    int x, y, n, a;
    cin >> n >> x >> y;
    x &= 1;
    y &= 1;
    for(int i = 0; i < n; i++) {
        cin >> a;
        x ^= (a & 1);
    }
    cout << (x == y ? "Alice" : "Bob") << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
