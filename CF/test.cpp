#include <iostream>
#include <vector>
#include <map>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e6, maxC = 1e6 + 326, maxB = 13, INF = 1e12;

int cnt = 0;
vector<int> primes;
bool isPrime[maxC];

inline void sieve(){
    fill(isPrime, isPrime + maxC, true);
    isPrime[1] = false;
    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(i * p >= maxC) break;
            isPrime[i * p] = false;
            if(!(i % p)) break;
        }
    }
}

void dfs(int now = 0, int cp = 1){
    if(now == 11){
        cnt++;
        return;
    }
    if(primes[now] <= INF / cp) dfs(now + 1, cp * primes[now]);
    dfs(now + 1, cp);
}

signed main(){
    sieve();
    dfs();
    cout << cnt << endl;
}
