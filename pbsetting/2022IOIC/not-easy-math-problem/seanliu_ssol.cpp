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
    void run(int M) {
        fill(vis, vis + N, 0);
        fill(dist, dist + N, INF);
        dist[1] = 1;
        pq.push({1, 1});
        while(pq.size()) {
            auto [d, u] = pq.top(); pq.pop();
            if(vis[u]) continue;
            if(dist[(u * 10) % M] > dist[u]) {
                dist[(u * 10) % M] = dist[u];
                pq.push({dist[u], (u * 10) % M});
            }
            if(dist[(u + 1) % M] > dist[u] + 1) {
                dist[(u + 1) % M] = dist[u] + 1;
                pq.push({dist[u] + 1, (u + 1) % M});
            }
        }
    } 
} sssp;

inline void solve() {
    int N, M;
    cin >> N >> M;
    sssp.reset(N);
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

