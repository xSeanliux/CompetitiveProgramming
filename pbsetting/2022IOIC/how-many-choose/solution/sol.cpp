#include <iostream>
#define int long long int
using namespace std;

const int M = 65; //64 choose 32 = 1.8e18
int C[M][M], fact[11];

int pre(int L, int N) { //nCk <= L, n <= N
    //cout << "calculating pre(" << L << ", " << N << ")\n";
    if(L <= 0) return 0;
    //k = 0
    int ret = 2 * N + 1;
    if(L == 1 || N == 1) return ret;
    //k = 1
    ret += 2 * (min(L, N) - 1) - 1;
    //k > 1
    for(int k = 2; k < 32 && 2 * k <= N; k++) {
        //cout << "k = " << k << endl;
        if(k <= 9) { //binary search
            int l = 2 * k, r = N + 1, m;
            auto can = [=](int n, int k, int L) -> bool { //is nCk <= L? makes sure n <= N.
                int cur = 1;
                for(int i = 0; i < k; i++) {
                    if(cur <= L * fact[k] / (n - i)) 
                        cur *= (n - i);
                    else return false;
                }
                //cout << n << "C" << k << " = " << cur  / fact[k] << " <= " << L << endl;
                return true;
            };
            if(l >= r || !can(l, k, L)) return ret;
            //binary search
            
            while(r - l > 1) {
                m = (l + r) / 2;
                if(can(m, k, L)) l = m;
                else r = m;
                //cout << "l = " << l << ", r = " << r << endl;
            }
            //cout << "max is " << l << " for k = " << k << endl;
            ret += 2 * (l - 2 * k) + 1;
            //cout << "adding " << 2 * (l - 2 * k) + 1 << endl;
        } else {
            //cout << "k large = " << k << endl;
            int cur = C[2 * k][k], curk = 2 * k;
            if(cur <= L) ret -= 1; //because C[2 * k][k] will doublecount
            while(cur <= L && curk <= N) {
                cout << curk << "C" << k << " = " << cur << endl;
                ret += 2;
                curk++;
                if(cur * curk <= L * (curk - k + 1)) {

                    cur *= curk;
                    cur /= (curk - k);
                }
                else break;
            }
        }
    }
    cout << "PRE(" << L << ", " << N << ") = " << ret << endl;
    return ret;
}

inline void solve() {
    int L, R, N;
    cin >> L >> R >> N;
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
