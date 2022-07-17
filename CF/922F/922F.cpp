#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define int long long int
using namespace std;

const int maxN = 3e5 + 10;

bool isPrime[maxN], isIn[maxN];
vector<int> primes;

inline void sieve() {
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i * 2; j < maxN; j += i) isPrime[j] = false;
        }
    }
}

int har(int N) {
    int x = 0;
    for(int i = 1; i <= N; i++) {
        x += (N / (N / i) - i + 1) * (N / i); 
        i = N / (N / i);
    }
    x -= N;
    return x;
}


signed main() {
    sieve();
    int N, K;
    cin >> N >> K;
    //cout << "ok\n";
    
    if(K > har(N)) {
        cout << "No" << '\n';
        return 0;
    }
    //cout << "har = " << har[N] << endl;
    int l = 0, r = N, m;
    while(r - l > 1) {
        m = (l + r) / 2;
        if(har(m) >= K) r = m;
        else l = m;
    }
    int lim = r;
    //cout << "lim = " << lim << endl;
    //cout << "har[" << lim << "] = " << har[lim] << endl;
    fill(isIn + 1, isIn + 1 + lim, true);
    int sz = lim;
    int pairs = har(lim);
    for(int p : primes) {
        if(p > lim) break;
        //cout << "checking p = " << p << endl;
        if(pairs - (lim / p) >= K) {
            //cout << "removing " << p << endl;
            isIn[p] = false;
            pairs -= (lim / p);
            sz--;
            //cout << "k = " << K << endl;
        }
    }
    if(pairs != K) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    cout << sz << endl;
    for(int i = 1; i <= N; i++) {
        if(isIn[i]) cout << i << " "; 
    }
    cout << "\n";
}


