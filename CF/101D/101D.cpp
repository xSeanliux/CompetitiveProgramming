#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iomanip>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e5 + 226;

vector<pii> adj[maxN];

int N, u, v, w, dp[maxN], lensum[maxN], sts[maxN];

void dfs(int p, int u){
    vector<int> lens;
    sts[u] = 1;
    for(pii e : adj[u]){
        if(e.F == p) continue;
        dfs(u, e.F);
        lensum[u] += e.S + lensum[e.F];
        sts[u] += sts[e.F];
        dp[u] += dp[e.F] + sts[e.F] * e.S;
        lens.push_back(lensum[e.F] + e.S);
    }
    sort(adj[u].begin(), adj[u].end(), [=](pii a, pii b){
        return ( lensum[a.F] + a.S ) * sts[b.F] < ( lensum[b.F] + b.S ) * sts[a.F];
    });
    int running_tot = 0;
    dp[u] = 0;
    for(pii e : adj[u]){
        if(e.F == p) continue;
        dp[u] += (2 * running_tot + e.S) * sts[e.F] + dp[e.F];
        running_tot += e.S + lensum[e.F];
    }
}

signed main(){
    cout << fixed << setprecision(10);
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 1);
    cout << dp[1] * 1.0 / (N - 1);
}
