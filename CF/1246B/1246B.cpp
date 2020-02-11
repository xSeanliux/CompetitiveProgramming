#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, MOD = 1e9 + 7;
bool isPrime[maxN];
vector<int> primes, arr;
map<int, int> mp;
int hv[maxN], n, k, frq[maxN], ans = 0;

int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = exp(b, e/2);
    res = res * res;
    if(e % 2) res = res * b;
    return res;
}

inline void getPrime(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j : primes){
            if(i * j >= maxN) break;
            isPrime[i * j] = false;
            if(!(i % j)) break;
        }
    }
}

inline int getHash(int x){
    int pow, res = 0;
    for(int p : primes){
        if(p * p > x) break;
        if(!(x % p)){
            pow = 0;
            while(!(x % p)){
                x /= p;
                pow++;
            }
            pow %= 2;
            res = (hv[p]*pow + res) % MOD;
        }
    }
    if(x > 1) res = (hv[x] + res) % MOD;
    return res;
}


signed main(){
    ericxiao;
    cin >> n >> k;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(k == 2){ //hash
        getPrime();
        int k = 1;
        for(int p : primes){
            hv[p] = k;
            k = 2 * k % MOD;
        }
        int hsh;
        for(int u : arr){
            hsh = getHash(u);
            ans += mp[hsh];
            mp[hsh]++;
        }
        cout << ans << endl;
    } else {
        for(int i = 0; i < n; i++) frq[arr[i]]++;
        int t;
        for(int j = 1;; j++){
            //cout << k * log10(j) << endl;
            if(k * log10(j) - 0.1 > 10){
                cout << ans << endl;
                return 0;
            }
            t = exp(j, k);
            for(int i = 1; i*i <= t; i++){
                if(!(t % i) && t / i <= (int)(1e5)){
                    //cout << "t = " << t << ", i = " << i << endl;
                    if(i == t/i) ans += frq[i] * (frq[i] - 1) / 2;
                    else ans += frq[i] * frq[t / i];
                    //cout << "ans = " << ans << endl;
                }
            }
        }
    }
}
