//#pragma gcc target("avx2")
//#pragma gcc("Ofast")
#include <bits/stdc++.h>
#define int long long int 
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

const int maxN = 1e3, INF = 1e15;
int dist[maxN][maxN], w[maxN];
bool vis[maxN];
pii dp[maxN];

inline int ceil(int a, int b) {
    return a <= 0 ? 0LL : (a + b - 1) / b;
}

void solve() {
    int N, M, p, u, v, c;
    cin >> N >> M >> p;
    fill(vis, vis + N, false);
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        dist[i][j] = INF;
    }
    for(int i = 0; i < N; i++) {
        cin >> w[i];
        dist[i][i] = 0;
        dp[i] = {INF, -INF};
    }
    for(int i = 0; i < M; i++) {
        cin >> u >> v >> c;
        --u, --v;
        dist[u][v] = min(dist[u][v], c);
    }
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        //cout << dist[i][j] << " \n"[j == N - 1];
    }
    if(dist[0][N - 1] == INF) {
        cout << "-1\n";
        return;
    }
    dp[0] = {0, p};
    priority_queue<pii, vector<pii>, greater<pii>> pq = priority_queue<pii, vector<pii>, greater<pii>>();
    pq.push({0, 0}); //(min number of performances, idx)
    while(pq.size()) {
        auto p = pq.top(); pq.pop();
        int u = p.S, perf = dp[u].F;
        int money = dp[u].S;
        for(int v = 0; v < N; v++) {
            if(w[v] >= w[u] && dist[u][v] < INF) {
                //extra performances: ceil(dist[u][v] - money, w[u])
                int ext = max(0LL, ceil(dist[u][v] - money, w[u]));
                int new_money = money + ext * w[u] - dist[u][v];
                if(ext + perf < dp[v].F || (ext + perf == dp[v].F && new_money > dp[v].S)) {
                    dp[v] = {ext + perf, new_money};
                    pq.push({dp[v].F, v});
                }
            }
        }
    }
    int ans = dp[N - 1].F;
    for(int i = 0; i < N; i++) {
        if(dp[i].F < INF && dist[i][N - 1] != INF)
            ans = min(ans, dp[i].F + max(0LL, ceil(dist[i][N - 1] - dp[i].S, w[i]))); 
    }
    cout << ans << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}

