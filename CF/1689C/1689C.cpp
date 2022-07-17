#include <iostream>
#include <vector>
#include <functional>
using namespace std;

inline void solve() {
    int N;
    cin >> N;
    vector<vector<int>> adj = vector<vector<int>>(N, vector<int>());
    vector<int> dp = vector<int>(N), sz = vector<int>(N);
    
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int, int)> dfs = [&](int p, int u) {
        sz[u] = 1;
        for(int v : adj[u]) if(v != p) {
            dfs(u, v);
            sz[u] += sz[v]; 
        }
        if(u == p) {
            if(adj[u].size() == 1) {
                dp[u] = sz[u] - 2;
            } else {
                int a = adj[u][0], b = adj[u][1];
                dp[u] = max(dp[a] + sz[b] - 1, dp[b] + sz[a] - 1);
            }
        } else {
            if(adj[u].size() <= 2) dp[u] = max(0, sz[u] - 2);
            else {
                int a = -1, b = -1;
                for(int v : adj[u]) if(v != p) {
                    if(a != -1) b = v;
                    else a = v;
                }
                dp[u] = max(dp[a] + sz[b] - 1, dp[b] + sz[a] - 1);
            }
        }
    };
    dfs(0, 0);
    cout << dp[0] << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();

}
