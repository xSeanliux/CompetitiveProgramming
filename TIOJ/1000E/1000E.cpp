#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 3e5 + 10;

bool visited[maxN], isBridge[maxN];
int N, M, a, b;
int dep[maxN], low[maxN], dsu[maxN];
vector<pii> adj[maxN], edges;
vector<int> tradj[maxN];

inline void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

inline void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(a > b) swap(a, b);
	dsu[dsu[b]] = dsu[a];
}

void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	low[u] = dep[p] + 1;
	visited[u] = true;
	for(auto [v, id] : adj[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u], dep[v]);	
		} else {
			dfs(u, v);
			if(low[v] > dep[u]){
				isBridge[id] = true;
			} else {
				Merge(u, v);	
				//cout << "Merging " << u << " and " << v << endl;
			}
			low[u] = min(low[u], low[v]);
		}
	}
}

pii getFar(int p, int u){
	pii res = {0, u}, _r;
	for(int v : tradj[u]){
		//cout << "Looking at " << v << endl;
		if(v == p) continue;
		_r = getFar(u, v);
		_r.F++;
		res = max(res, _r);
	}
	return res;
}

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) dsu[i] = i;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		edges.emplace_back(a, b);
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}
	dfs();
	for(int i = 1; i <= N; i++) Flat(i);
	for(int i = 0; i < M; i++){
		if(isBridge[i]){
			tradj[dsu[edges[i].F]].push_back(dsu[edges[i].S]);
			tradj[dsu[edges[i].S]].push_back(dsu[edges[i].F]);
		}
	}
	pii res = getFar(1, 1);
	//cout << "Far from 1: " << res.F << ", " << res.S << endl;
	res = getFar(res.S, res.S);
	cout << res.F << endl;
}
