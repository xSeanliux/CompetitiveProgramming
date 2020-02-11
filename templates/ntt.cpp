#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int MOD = 5 * (1 <<25) + 1, root = 3;
int n, m, l;
vector<int> f1, f2;

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

int modinv(int x){
    return modexp(x, MOD - 2);
}

void ntt(vector<int> &f, bool inv){
    if(f.size() == 1) return;
    vector<int> e, o;
    for(int i = 0; i < f.size(); i++) (i % 2 ? o : e).push_back(f[i]);
    ntt(e, inv);
    ntt(o, inv);
    int omega_n, omega;
    if(inv) omega_n = modinv(modexp(root, (MOD - 1) / f.size()));
    else omega_n = modexp(root, (MOD - 1) / f.size());
    omega = 1;
    for(int i = 0; i < f.size()/2; i++){
        f[i] = (e[i] + omega * o[i] % MOD) % MOD;
        f[i + f.size() / 2] = (e[i] + MOD - omega * o[i] % MOD) % MOD;
        omega = omega * omega_n % MOD;
    }
    if(inv){
        int IR = invmod(f.size());
        for(int &x : f) x = x * I % MOD;
    }
}

inline vector<int> mult(vector<int> a, vector<int> b){
    if(a.size() < b.size()) swap(a, b);
    int l;
    for(l = 1; l < a.size(); l <<= 1){}
    l <<= 1;
    while(a.size() < l) a.emplace_back(0);
    while(b.size() < l) b.emplace_back(0);
    ntt(a, false);
    int om = modexp(root, (MOD - 1) / a.size()), o = om;

    for(int u : a){
        o = o * om % MOD;
    }

    ntt(b, false);
    for(int i = 0; i < a.size(); i++){
        a[i] = a[i] * b[i] % MOD;
    }
    invntt(a);
    return a;
}

signed main(){
    cin >> n >> m;
    f1.resize(n);
    f2.resize(m);
    for(int i = 0; i < n; i++) cin >> f1[i];
    for(int i = 0; i < m; i++) cin >> f2[i];
    vector<int> res = mult(f1, f2);
    for(int u : res){
        cout << u << " ";
    }
}
