#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <fstream>
#define pii pair<int,int>
#define F first
#define S second
#define cin infile
#define cout outfile
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326, maxL = 16;
vector<pii> adj[maxN];
vector<int> add[maxN], rem[maxN];
map<int, int> has[maxN];

int N, M, u, v, w, sz[maxN], maxChild[maxN], anc[maxN][maxL], dep[maxN], pid[maxN], ans[maxN];

ifstream infile;
ofstream outfile;

void dfs(int p = 1, int u = 1){
	sz[u] = 1;
	dep[u] = dep[p] + 1;
	anc[u][0] = p;
	for(int i = 1; i < maxL; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	maxChild[u] = -1;
	for(auto e : adj[u]) if(e.F != p){
		dfs(u, e.F);
		sz[u] += sz[e.F];
		pid[e.F] = e.S;
		if(maxChild[u] == -1 || sz[maxChild[u]] < sz[e.F]) maxChild[u] = e.F;
	}
}

inline int LCA(int u, int v){
	if(dep[u] < dep[v]) swap(u, v);
	int k = dep[u] - dep[v];
	for(int i = 0; i < maxL; i++){
		if((k >> i) & 1){
			u = anc[u][i];
		}
	}
	if(u == v) return u;
	for(int i = maxL - 1; i >= 0; i--){
		if(anc[u][i] != anc[v][i]){
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}

void dfs2(int p = 1, int u = 1){
	for(auto e : adj[u]){
		if(e.F != p){
			dfs2(u, e.F);
		}
	}
	if(maxChild[u] != -1) swap(has[u], has[maxChild[u]]);
	for(int x : add[u]){
		has[u][x]++;
	}
	for(auto e : adj[u]) if(e.F != p && e.F != maxChild[u]){
		for(auto pa : has[e.F]){
			has[u][pa.F] += pa.S;
		}
		has[e.F].clear();
	}
	for(int x : rem[u]){
		has[u][x]--;
		if(has[u][x] == 0) has[u].erase(x);
	}
	if(u == 1) return;
	if(has[u].size()) ans[pid[u]] = has[u].begin()->F;
	else ans[pid[u]] = -1;
}

int main(){
	infile.open("disrupt.in");
	outfile.open("disrupt.out");
	cin >> N >> M;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	dfs();
	while(M--){
		cin >> u >> v >> w;
		if(dep[u] < dep[v]) swap(u, v);
		int lca = LCA(u, v);
		if(lca == v){
			rem[v].push_back(w);
			add[u].push_back(w);
		} else {
			add[u].push_back(w);	
			add[v].push_back(w);	
			rem[lca].push_back(w);
			rem[lca].push_back(w);
		}
	}
	dfs2();
	for(int i = 0; i < N - 1; i++) cout << ans[i] << '\n';
}


