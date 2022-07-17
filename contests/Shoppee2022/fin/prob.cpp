#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 1LL << 20, root = 3;

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    b %= MOD;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

inline int modinv(int x){
    return modexp(x, MOD - 2);
}

inline vector<int> bitInversePermutation(vector<int> f){
    int n = f.size();
    vector<int> res = vector<int>(n);
    int ind = 0;
    for(int i = 0; i < n; i++){
        ind = 0;
        for(int j = 0; (1LL << j) < n; j++){
            ind <<= 1;
            if(i & (1<<j)) ind++;
        }
        res[ind] = f[i];
    }
    return res;
}

vector<int> ntt(vector<int> f, bool inv){
    f = bitInversePermutation(f);
    int omega, twi, u, v;
    for(int stp = 2; stp <= (int)f.size(); stp <<= 1){
        omega = modexp(root, (MOD - 1) / stp);
        if(inv) omega = modinv(omega);
        for(int i = 0; i < (int)f.size(); i += stp){
            twi = 1;
            for(int j = 0; j < stp/2; j++){
                u = f[i + j];
                v = twi * f[i + j + stp/2] % MOD;
                f[i + j] = (u + v) % MOD;
                f[i + j + stp/2] = (u - v + MOD) % MOD;
                twi = twi * omega % MOD;
            }
        }
    }
    if(inv){
        int iN = modinv(f.size());
        for(int &u : f) u = u * iN % MOD;
    }
    return f;
}

inline vector<int> mult(vector<int> a, vector<int> b){
    int l;
    for(l = 1; l < (int)a.size() + (int)b.size(); l <<= 1){}
    a.resize(l);
    b.resize(l);
    a = ntt(a, false);
    b = ntt(b, false);
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = a[i] * b[i] % MOD;
    }
    a = ntt(a, true);
    return a;
}

vector<int> polyexp(vector<int> b, int e) {
    int N = b.size();
    vector<int> r = vector<int>(N);
    r[0] = 1;
    for(int i = 0; i < 32; i++) {
        if((e >> i) & 1) {
            r = mult(r, b);
            if((int)r.size() > N) r.resize(N);
        }
        b = mult(b, b);
        if((int)b.size() > N) b.resize(N);
    }
    return r;
}

signed main() {
    int n, m;

    cin >> n >> m;
    vector<int> sq = vector<int>(n);

    for(int i = 0; i <= n + 1; i++) sq[i] = i * i % MOD;
    vector<int> res = polyexp(sq, 2);
    cout << res[n] << endl;
}



