#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 3e5 + 10, root = 3;
int n, k, q, w, fact[maxN];
map<int,int> white;
vector<int> red, que, ans;

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

inline void getFact(){
    fact[0] = 1;
    for(int i = 1; i < maxN; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
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
    for(int stp = 2; stp <= f.size(); stp <<= 1){
        omega = modexp(root, (MOD - 1) / stp);
        if(inv) omega = modinv(omega);
        for(int i = 0; i < f.size(); i += stp){
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
    for(l = 1; l < a.size() + b.size(); l <<= 1){}
    a.resize(l);
    b.resize(l);
    a = ntt(a, false);
    b = ntt(b, false);
    for(int i = 0; i < a.size(); ++i){
        a[i] = a[i] * b[i] % MOD;
    }
    a = ntt(a, true);
    return a;
}

inline vector<int> getPoly(int a, int n){ //(1 + ax)^n
    vector<int> pol;
    int currentChoose = 1, tw = 1;
    for(int i = 0; i <= n; ++i){
        if(i) currentChoose = (currentChoose * modinv(i) % MOD) * (n - i + 1) % MOD;
        pol.push_back(currentChoose * tw % MOD);
        tw = tw * a % MOD;
    }
    return pol;
}

signed main(){
    vector<int> r = mult({1, 1}, {1, 1});
    for(int u : r) cout << u << " ";
    cout << endl;
    ericxiao;
    cin >> n >> k;
    red.resize(k);
    for(int i = 0; i < n; i++){
        cin >> w;
        white[w]++;
    }
    for(int i = 0; i < k; i++) cin >> red[i];
    cin >> q;
    que.resize(q);
    ans.resize(q);
    for(int i = 0; i < q; i++){
        cin >> que[i];
        que[i] /= 2;
    }
    int s = 0, t = 0; //(1 + 2x)^s, (1 + x)^{2t}

    vector<int> res;
    for(int r : red){
        s = t = 0;
        for(auto w : white){
            if(w.F >= r) break;
            if(w.S == 1) s++;
            else t++;
        }
        //cout << "S = " << s << ", T = " << t << endl;
        res = mult(getPoly(2, s), getPoly(1, 2 * t));
        for(int i = 0; i < q; ++i){
            if(que[i] - r - 1 < res.size() && que[i] - r - 1 >= 0)
                ans[i] = (res[que[i] - r - 1] + ans[i]) % MOD;
        }
    }
    for(int u : ans) cout << u << '\n';
}

