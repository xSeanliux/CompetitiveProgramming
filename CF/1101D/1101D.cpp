#include <iostream>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

vector<int> wei, primes, adj[maxN], currentAdj[maxN], cans[maxN];
vector<bool> visited, isPrime;
vector<set<int> > has;
int n, a, b, ans = 0;

inline void getPrime(){
    isPrime.resize(maxN);
    fill(isPrime.begin(), isPrime.end(), true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j : primes){
            if(j * i >= maxN) break;
            isPrime[j * i] = false;
            if(!(i % j)) break;
        }
    }
}

pii getFar(int p, int x, int pr){
    visited[x] = true;
    int maxFar = 0, id = x;
    pii res;
    for(int u : adj[x]){
        if(u == p || (wei[u] % pr)) continue;
        res = getFar(x, u, pr);
        if(res.F > maxFar){
            maxFar = res.F;
            id = res.S;
        }
    }
    return {1 + maxFar, id};
}

signed main(){
    ericxiao;
    getPrime();
    cin >> n;
    visited.resize(n);
    has.resize(n);
    wei.resize(n);
    int _w;
    for(int i = 0; i < n; i++){
        cin >> wei[i];
        _w = wei[i];
        for(int p : primes){
            if(p * p > _w) break;
            if(!(_w % p)){
                cans[p].push_back(i);
            }
        }
        if(_w > 1) cans[_w].push_back(i);
    }
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        has[a].insert(b);
        has[b].insert(a);
    }
    pii res;
    //cout << "primes size = " << primes.size() << endl;
    for(int p : primes){
        //cout << "Checking prime " << p << endl;
        for(int u : cans[p]){
            //cout << "u = " << u << endl;
            visited[u] = false;
        }
        for(int u : cans[p]){
            if(!visited[u]){
                res = getFar(u, u, p);
                res = getFar(res.S, res.S, p);
                ans = max(res.F, ans);
                //cout << "Ans = " << res.F << endl;
            }
        }
    }
    cout << ans << endl;
}
