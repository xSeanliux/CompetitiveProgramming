#include <iostream>
#include <vector>
#include <map>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e6;

inline int vp(int x, int p){ //calculates v_p(x!)
    int res = 0, t = p;
    while(x >= t){
        res += x/t;
        t *= p;
    }
    return res;
}

bool isPrime[maxN];
vector<int> primes, v;
map<int, int> mp;

inline void getPrime(){
    fill(isPrime, isPrime + maxN, true);
    isPrime[1] = false;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < maxN; j++){
            isPrime[i * primes[j]] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int k, a;

signed main(){
    ericxiao;
    getPrime();
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a;
        for(int p : primes){
            if(p > a) break;
            mp[p] += vp(a, p);
        }
    }
    int n = 1;
    //pp = *mp.rbegin();
    for(auto pp : mp){
        cout << pp.F << ", " << pp.S << endl;
        //pp.F: prime; pp.S: minima vp
        int l = 1, r = 1e9, m = (l + r) / 2;
        while(l + 1 < r){
            if(vp(m, pp.F) >= pp.S) r = m;
            else l = m;
            m = (l + r) / 2;
        }
        cout << "vp(" << r << "!, " << pp.F << ") = " << vp(r, pp.F) << endl;
        n = max(n, r);
    }
    cout << n << endl;
}
