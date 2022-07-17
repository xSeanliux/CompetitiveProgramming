#include <iostream>
#define int long long int
using namespace std;

const int M = 65; //64 choose 32 = 1.8e18
int C[M][M], fact[11];

inline void solve() {
    int L, R, N;
    cin >> L >> R >> N;
    int ans = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= i; j++) {
            if(L <= C[i][j] && C[i][j] <= R) ans++;
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    int T;
    for(int i = 0; i < M; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    fact[0] = 1;
    for(int i = 1; i < 11; i++) fact[i] = fact[i - 1] * i;

    cin >> T;
    while(T--) {
        solve();
    }
}

