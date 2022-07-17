#include <iostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5, maxL = 17;

int main() {
    ericxiao
    vector<int> sa, rk;
    int N, Q, l, r;
    string S;
    getline(cin, S);
    N = S.length() + 1;
    sa = rk = vector<int>(N);
    sa[0] = N - 1;
    iota(sa.begin() + 1, sa.end(), 0);

    sort(sa.begin() + 1, sa.end(), [&](int i, int j) {
       return S[i] < S[j];      
    });


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

    for(int i = 1; i < N; i++) cout << sa[i] << endl;
}

