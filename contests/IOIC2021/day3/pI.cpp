#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define endl '\n'
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326, INF = 1e17;
int N, M, K, u, v, w;

vector<pii> adj[maxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

bool vis[maxN];
int dist[maxN];
signed main(){
	ericxiao
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(v + N, w);
		adj[u + N].emplace_back(v + N, w);
	}
	for(int i = 0; i < K; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(v + N, w);
		adj[u + N].emplace_back(v + N, w);
		adj[u + N].emplace_back(v, 0);
	}
	fill(dist, dist + maxN, INF);
	dist[1] = 0;
	pq.push({0, 1});
	while(pq.size()){
		auto [d, u] = pq.top();
		pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto [v, w] : adj[u]) if(!vis[v]){
			if(dist[v] > d + w){
				dist[v] = d + w;
				pq.push({dist[v], v});
			}
		}
	}
	for(int i = 2; i <= N; i++) cout << (min(dist[i], dist[i + N]) == INF ? -1 : min(dist[i], dist[i + N])) << " \n"[i == N];
}
