#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, INF = 1e18;

map<int, int> adj[maxN];

int n, m, u, v, w, ans = 0;

struct Edge{
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w): u(u), v(v), w(w){}
    bool operator <(Edge e) const {
        return w > e.w;
    }
};

signed main(){
    ericxiao;
    cin >> n >> m;
    priority_queue<Edge> pq;
    Edge ed;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u][v] += w;
    }
    deque<pii> newadj[maxN];
    for(int i = 1; i <= n; i++){
        for(auto p : adj[i]){
            if(adj[p.F].count(i)) && adj[p.F][i] < adj[i][p.F]){
                newadj[maxN].push_back(adj[p.F][i]);
            }
        }
    }
}
