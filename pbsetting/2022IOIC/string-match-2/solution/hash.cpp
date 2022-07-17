#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int M = 0xdefaced, B = 101, maxN = 1e6 + 326;
int hsh[maxN], pow[maxN];

inline int getHash(int l, int r) {
    if(!l) return hsh[r];
    return (hsh[r] - hsh[l - 1] * pow[r - l + 1] % M + M) % M;
}

signed main() {
    int N, Q, l, r;
    string S;

    cin >> N >> Q >> S;
    hsh[0] = S[0];
    pow[0] = 1;
    for(int i = 1; i < N; i++) {
        hsh[i] = (hsh[i - 1] * B + S[i]) % M;
        pow[i] = pow[i - 1] * B % M;
    }

    while(Q--) {
        cin >> l >> r;
        l--;
        int _len = r - l, tgt = getHash(l, r - 1);
        for(int i = 0; i + _len <= N; i++) {
            if(tgt == getHash(i, i + _len - 1)) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }

}

