#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
vector<int> adj[maxN];
deque<int> ord;

int N, M, u, v, x, deg[maxN], pa[maxN], root, minVal[maxN][2], maxDist[maxN][2];
bool is[maxN], cand[maxN];

void getPa(int p = root, int u = root){
	for(int v : adj[u]) if(v != p){
		pa[v] = u;
		getPa(u, v);
	}
}

pii getFar(int p, int u){
	pii res = {0, u};
	for(int v : adj[u]) if(v != p && cand[v]){
		pii x = getFar(u, v);
		x.F++;
		if(x.F > res.F){
			res = x;
		} else if(x.F == res.F){
			res.S = min(res.S, x.S);
		}
	}
	return res;
}

int main(){
	cin >> N >> M;
	fill(cand, cand + N + 1, true);
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	
	for(int i = 0; i < M; i++){
		cin >> x;
		is[x] = true;
	}
	for(int i = 1; i <= N; i++) if(is[i]) root = i;
	getPa();
	queue<int> que;
	int ans = N;
	for(int i = 1; i <= N; i++){
		if(adj[i].size() == 1) que.push(i);
	}
	while(que.size()){
		int f = que.front();
		que.pop();
		if(is[f]) continue;
		ans--;
		cand[f] = false;
		if(f == root) continue;
		deg[pa[f]]--;
		if(deg[pa[f]] == 1){
			que.push(pa[f]);
		}
	}
	auto [d,   a] = getFar(root, root);
	auto [dia, b] = getFar(a, a);
	cout << min(a, b) << endl;
	cout << 2 * (ans - 1) - dia << endl;
}
