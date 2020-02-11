#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

int T, a, m;

vector<int> primes;
bool isPrime[maxN];

inline void init(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxN) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}

inline int phi(int x){
    int res = 1, cp;
    for(int p : primes){
        if(p * p > x) break;
        if(!(x % p)){
            cp = 1;
            while(!(x % p)){
                x /= p;
                cp *= p;
            }
            res *= (cp - cp / p);
        }
    }
    if(x > 1) res *= (x - 1);
    return res;
}

signed main(){
    init();
    cin >> T;
    while(T--){
        cin >> a >> m;
        int g = gcd(a, m);
        m /= g;
        cout << phi(m) << '\n';
    }
}
