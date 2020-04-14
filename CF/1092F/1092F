#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int N, u, v, x[maxN], sum[maxN], dist[maxN], ans = 0, cur = 0, totSum;
vector<int> adj[maxN];

void initSum(int p, int c){
    dist[c] = dist[p] + 1;
    sum[c] = x[c];
    for(int u : adj[c]){
        if(u == p) continue;
        initSum(c, u);
        sum[c] += sum[u];
    }
}

void dfs(int p, int c){
    ans = max(ans, cur);
    for(int u : adj[c]){
        if(u == p) continue;
        cur -= sum[u];
        cur += totSum - sum[u];
        dfs(c, u);
        cur += sum[u];
        cur -= totSum - sum[u];
    }
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x[i];
    }
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist[1] = -1;
    initSum(1, 1);
    for(int i = 1; i <= N; i++){
        cur += dist[i] * x[i];
        totSum += x[i];
    }
    dfs(1, 1);
    cout << ans << endl;
}
