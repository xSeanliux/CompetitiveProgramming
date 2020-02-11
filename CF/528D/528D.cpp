#include <iostream>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int long long int
using namespace std;

const int MOD = 998244353, root = 3, maxN = (1LL << 21);

int n, m, k, rev[maxN];
string s, t;
vector<int> occ[4], tocc[4], match[4];
int __lg(int x) { return 31-__builtin_clz(x); }
inline int getId(char c){ //ACGT
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
}

int modpow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modpow(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

int modinv(int x){
    return modpow(x, MOD - 2);
}

inline void bitInversePermutation(vector<int> &f){
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
    f.swap(res);
}

inline void ntt(vector<int> &f, bool inv){
    bitInversePermutation(f);
    int omega, tw, s, t;
    for(int stp = 2; stp <= f.size(); stp *= 2){
        omega = modpow(root, (MOD - 1) / stp);
        if(inv) omega = modinv(omega);
        for(int i = 0; i < f.size(); i += stp){
            tw = 1;
            for(int j = i; j < i + stp/2; j++){
                s = f[j], t = f[j + stp/2] * tw % MOD;
                f[j] = (s + t < MOD ? s + t : s + t - MOD);
                f[j + stp/2] = (s - t < 0 ? s - t + MOD : s - t);
                tw = tw * omega % MOD;
            }
        }
    }
    if(inv){
        int iN = modinv(f.size());
        for(int &x : f) x = x * iN % MOD;
    }
}

inline void mult(vector<int> &a, vector<int> &b){
    //if(a.size() < b.size()) swap(a, b);
    int l = 1<<__lg(a.size()+b.size())+1;
    a.resize(l);
    b.resize(l);
    ntt(a, 0);
    ntt(b, 0);
    for(int i = 0; i < l; i++){
        a[i] = a[i] * b[i] % MOD;
    }
    ntt(a, 1);
}

signed main(){
    ericxiao;
    cin >> n >> m >> k >> s >> t;
    for(int i = 0; i < 4; i++){
        occ[i].resize(n + 1);
        tocc[i].resize(m + 1);
    }
    int l, r, idd;
    for(int i = 0; i < n; i++){
        idd = getId(s[i]);
        l = max(i - k, 0LL);
        r = min(i + k + 1, n);
        occ[idd][l]++;
        occ[idd][r]--;
    }
    for(int k = 0; k < 4; k++){
        for(int i = 1; i < n; i++){
            occ[k][i] += occ[k][i - 1];
        }
        for(int i = 0; i < n; i++){
            occ[k][i] = occ[k][i] > 0;
            //cout << occ[k][i];
        }
        //cout << endl;
    }
    for(int i = 0; i < m; i++){
        idd = getId(t[i]);
        tocc[idd][i]++;
    }
    int maxsz = 0;
    for(int k = 0; k < 4; ++k){
        reverse(tocc[k].begin(), tocc[k].end());
        mult(tocc[k], occ[k]);
    }
    int ans = 0;
    for(int i = 0; i < tocc[0].size(); ++i){
        ans += (tocc[0][i] + tocc[1][i] + tocc[2][i] + tocc[3][i] == m);
    }
    cout << ans << endl;
}
