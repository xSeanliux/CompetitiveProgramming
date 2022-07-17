#include <iostream>
#define int long long int
using namespace std;

const int M = 65; //64 choose 32 = 1.8e18
int C[M][M], fact[11];

int pre(int L, int N) { //nCk <= L, n <= N
    if(N < M) {
        int ans = 0;
        int less = 0;
        for(int i = 0; i <= N; i++) {
            for(int j = 0; j <= i; j++) {
                if(C[i][j] <= L) {
                    ans++;
                    if(j > 9 && i >= 2 * j) {
                        less++;
                        cout << i << " " << j << endl;
                    }
                }
            }
        }
        cout << "NAIVE PRE(" << L << ", " << N << ") = " << ans << endl;
        cout << "LESS = " << less << endl;
        return ans;
    }
    //cout << "calculating pre(" << L << ", " << N << ")\n";
    if(L <= 0) return 0;
    //k = 0
    int ret = 2 * N + 1;
    if(L == 1 || N == 1) return ret;
    //k = 1
    ret += 2 * (min(L, N) - 1) - 1;
    //k > 1
    for(int k = 2; k < 32 && 2 * k <= N; k++) {
        int cur = C[2 * k][k], curk = 2 * k;
        if(cur <= L) ret -= 1; //because C[2 * k][k] will doublecount
        while(cur <= L && curk <= N) {
            //cout << curk << "C" << k << " = " << cur << endl;
            cur /= (curk - k + 1);
            curk++;
            ret += 2;
            if(cur <= L / curk) cur *= curk;
            else break;
        }
    }
    return ret;
}

inline void solve() {
    int L, R, N;
    cin >> L >> R >> N;
    if(N < M) {
            }
    cout << pre(R, N) - pre(L - 1, N) << endl;
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

