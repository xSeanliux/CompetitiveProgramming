#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5, maxL = 20;
int jump[maxL][maxN][2][2]; //fwjump, bwjump, LCP, least number

//verified with TIOJ

int main() {
    ericxiao
    vector<int> sa, rk, lcp;
    int N, Q, l, r;
    string S;
    cin >> N >> Q;
    cin >> S;

    N++;

    sa = rk = lcp = vector<int>(N);
    iota(sa.begin() + 1, sa.end(), 0);

    sort(sa.begin() + 1, sa.end(), [&](int i, int j) {
       return S[i] < S[j];      
    });

    sa[0] = N - 1;

    for(int i = 1; i < N; i++) {
        int a = sa[i], b = sa[i - 1];
        rk[a] = (i > 1 && S[a] == S[b]) ? rk[b] : i;
    }

    for(int l = 1; l < N; l *= 2) {
        vector<int> _sa(sa), _rk(rk), pos(N);
        iota(pos.begin(), pos.end(), 0);
        for(int t : _sa) {
            int T = (t - l);
            if(T >= 0)
                sa[pos[rk[T]]++] = T;
        }
        for(int i = 1; i < N; i++) {
            int a = sa[i], b = sa[i - 1];
            rk[a] = (_rk[a] == _rk[b] && _rk[a + l] == _rk[b + l]) ? rk[b] : i; //why doesn't rk[a + l]
        }
    }
 
    int k = 0;
    for(int i = 0; i < N - 1; i++) {
        int j = sa[rk[i] - 1];
        while(j + k < N && i + k < N && S[i + k] == S[j + k]) k++;
        lcp[rk[i] - 1] = k;
        if(k) k--;
    }

    lcp[N - 1] = 0;
 
    /*
    for(int i = 1; i < N; i++) {
        cout << sa[i] << ": " << S.substr(sa[i], N) << " " << lcp[i] << endl;
    }
    */

    for(int i = 0; i < N; i++) {
        jump[0][i][0][0] = jump[0][i][1][0] = lcp[i];
        jump[0][i][0][1] = jump[0][i][1][1] = sa[i];
    }

    for(int i = 1; i < maxL; i++) {
        for(int j = 0; j < N; j++) {
            if(j + (1 << i) <= N){
                jump[i][j][0][0] = min(jump[i - 1][j][0][0], jump[i - 1][j + (1 << (i - 1))][0][0]);
                jump[i][j][0][1] = min(jump[i - 1][j][0][1], jump[i - 1][j + (1 << (i - 1))][0][1]);
            } else {
                jump[i][j][0][0] = -1; jump[i][j][0][1] = N;
            }
            if(j - (1 << i) + 1 >= 0) {
                jump[i][j][1][0] = min(jump[i - 1][j][1][0], jump[i - 1][j - (1 << (i - 1))][1][0]);
                jump[i][j][1][1] = min(jump[i - 1][j][1][1], jump[i - 1][j - (1 << (i - 1))][1][1]);
            } else {
                jump[i][j][1][0] = -1; jump[i][j][1][1] = N;
            }
        }
    }

    while(Q--) {
        cin >> l >> r;
        --l; --r;

        int len = r - l + 1;
        int ans = l;

        //fw
        //cout << "fw" << endl;
        int cur = rk[l];
        for(int i = maxL - 1; i >= 0; i--) {
            if(jump[i][cur][0][0] >= len) {
                //cout << "jumping " << (1 << i) << endl;
                ans = min(ans, jump[i][cur][0][1]);
                cur += (1 << i);
            }
        }
        if(jump[0][cur - 1][0][0] >= len) ans = min(ans, jump[0][cur][0][1]);

        cur = rk[l] - 1;
        //cout << "bw" << endl;
        for(int i = maxL - 1; i >= 0; i--) {
            if(jump[i][cur][1][0] >= len) {
                ans = min(ans, jump[i][cur][1][1]);
                //cout << "jumping " << (1 << i) << endl;
                cur -= (1 << i);
            }
            if(cur < 0) break;
        }
        cout << ans + 1 << '\n';
    }
}
