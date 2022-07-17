#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 3e5 + 326;
int N, M, ans[maxN], u[maxN], v[maxN], cnt = 1;
bool vis[maxN];

vector<pii> adj[maxN];

void dfs(int u = 1){
	vis[u] = true;
	int chi = 0;
	for(auto [v, id] : adj[u]) if(!vis[v]) {
		ans[id] = cnt++;
		chi++;
		dfs(v);
	}
	for(auto [v, id] : adj[u]) if(!ans[id]){
		ans[id] = cnt++;
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u[i] >> v[i];
		adj[u[i]].emplace_back(v[i], i);
		adj[v[i]].emplace_back(u[i], i);
	}
	dfs();
	for(int i = 0; i < M; i++) cout << u[i] << " " << v[i] << " " << ans[i] << endl;
}
