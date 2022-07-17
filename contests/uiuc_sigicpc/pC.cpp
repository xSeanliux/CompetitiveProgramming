#include <iostream>
#include <set>
#define int long long int
using namespace std;

const int INF = 2e18, L = 38;
set<int> st;

int pow3[L + 200];

void F(int sum, int tgt, int curmax) {
}

inline void solve() {
    int N;
    int ans = 0;
    cin >> N;
    for(int i = L; i >= 0; i--) {
        if((pow3[i] - 1) / 2 + ans < N) ans += pow3[i];
    }
    cout << ans << endl;
}

signed main() {
    pow3[0] = 1;
    for(int i = 1; i <= L; i++) {
        pow3[i] = pow3[i - 1] * 3;
    }
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
