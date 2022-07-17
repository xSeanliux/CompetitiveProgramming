#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 4e3 + 326, maxL = 15, INF = 2e9;
int N, M, Q, dep[maxN], anc[maxN][maxL], tag[maxN][7], ans[100000 + 326];
int u, v, a[maxN], b[maxN], c[maxN];
int dist[maxN];
vector<int> adj[maxN];
vector<pii> que[maxN];

inline void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	anc[u][0] = p;
	for(int i = 1; i < maxL; i++){
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
	}
}

inline int kthAnc(int x, int k){
	for(int i = 0; i < maxL; i++){
		if((k >> i) & 1) x = anc[x][i];
	}
	return x;
}

inline int LCA(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	a = kthAnc(a, dep[a] - dep[b]);
	if(a == b) return a;
	for(int i = maxL - 1; i >= 0; i--){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

void getTag(int p, int u){
	for(int v : adj[u]) if(v != p){
		getTag(u, v);
		for(int i = 0; i < 7; i++){
			if(tag[v][i] == maxN || dep[tag[v][i]] >= dep[u]) continue;
			tag[u][i] = (tag[u][i] == maxN || dep[tag[u][i]] > dep[tag[v][i]] ? tag[v][i] : tag[u][i] );
		}
	}
}

void getDist(int p, int u){
	if(u == p) dist[u] = 0;
	else {
		dist[u] = INF;
		for(int i = 0; i < 7; i++){
			if(tag[u][i] != maxN){
				dist[u] = min(dist[u], i + dist[tag[u][i]]);
			}
		}
	}
	for(int v : adj[u]) if(v != p){
		getDist(u, v);
	}
}

int main(){
	ericxiao
	cin >> N >> M >> Q;
	if(N > maxN) return 0;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 0; i < M; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	int A, B;
	for(int i = 0; i < Q; i++){
		cin >> A >> B;
		que[A].emplace_back(B, i);
	}
	for(int r = 1; r <= N; r++){
		//cout << "root = " << r << endl;
		dfs(r, r);
		//cout << "done setting vars" << endl;
		for(int i = 1; i <= N; i++) for(int j = 0; j < 7; j++) tag[i][j] = maxN;
		for(int i = 0; i < M; i++){
			if(dep[a[i]] < dep[b[i]]) swap(a[i], b[i]);
			int lca = LCA(a[i], b[i]);
			if(lca == b[i]){
				tag[a[i]][c[i]] = min(tag[a[i]][c[i]], lca);
			} else {
				tag[b[i]][c[i]] = min(tag[b[i]][c[i]], lca);
				tag[a[i]][c[i]] = min(tag[a[i]][c[i]], lca);
			}
		}
		//cout << "done tagging" << endl;
		getTag(r, r);
		//cout << "done setting tags" << endl;
		getDist(r, r);
		//cout << "done setting dists" << endl;
		for(auto [tgt, id] : que[r]){
			ans[id] = (dist[tgt] == INF ? -1 : dist[tgt]);
		}
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}
