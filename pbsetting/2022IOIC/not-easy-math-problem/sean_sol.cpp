#undef _GLIBCXX_DEBUG                // disable run-time bound checking, etc
#pragma GCC optimize("Ofast,inline,unroll-loops") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation
#pragma GCC target("movbe")                                      // byte swap
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD

#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define all(x) x.begin(),x.end()
using namespace std;

const int INF = 1e9, maxN = 1e6 + 326;

struct Dijkstra {
    int N;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<pii> adj[maxN];
    int dist[maxN];
    bool vis[maxN];
    Dijkstra() {}
    inline void addEdge(int u, int v, int w) {
        adj[u].emplace_back(v, w);
    }
    void reset(int _N) {
        N = _N + 1;
        pq = priority_queue<pii, vector<pii>, greater<pii>>();
        for(int i = 0; i < N; i++) adj[i] = vector<pii>();
    }
    void run(int s) {
        fill(vis, vis + N, 0);
        fill(dist, dist + N, INF);
        dist[s] = 0;
        pq.push({0, s});
        while(pq.size()) {
            auto [d, u] = pq.top(); pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto [v, w] : adj[u]) {
                if(!vis[v]) {
                    if(dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
    } 
} sssp;

inline void solve() {
    int N, M;
    cin >> N >> M;
    sssp.reset(N);
    for(int i = 0; i < N; i++) for(int d = 0; d < 10; d++) {
        sssp.addEdge(i, (i * 10 + d) % N, d);
    }
    for(int d = 1; d < 10; d++) sssp.addEdge(N, d, d);
    sssp.run(N);
    cout << sssp.dist[M] << '\n';
}
int main() {
    ericxiao;
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
