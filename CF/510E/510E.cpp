#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

const int maxN = 2e4 + 226;
bool isPrime[maxN], vis[maxN];
int match[maxN], val[maxN];
vector<int> adj[maxN], bip[maxN];

struct Dinic{
	static const int MXN = 10000;
	struct Edge{ int v, f, re; };
	int n, s, t, level[MXN];
	vector<Edge> E[MXN];
	void init (int _n, int _s, int _t){
		n = _n; s = _s; t = _t;
		for(int i = 0; i < n; i++) E[i].clear();
	}
#define SZ(x) ((int)x.size())
#define PB push_back
	void add_edge(int u, int v, int f){
		E[u].PB({v, f, SZ(E[v])});
		E[v].PB({u, 0, SZ(E[u]) - 1});
	}
	bool BFS(){
		for(int i = 0; i < n; i++) level[i] = -1;	
		queue<int> que;
		que.push(s);
		level[s] = 0;
		while(!que.empty()){
			int u = que.front(); que.pop();
			for(auto it : E[u]){
				if(it.f > 0 && level[it.v] == -1){
					level[it.v] = level[u] + 1;	
					que.push(it.v);
				}
			}
		}
		return level[t] != -1;
	}
	int DFS(int u, int nf){
		if(u == t) return nf;	
		int res = 0;
		for(auto &it : E[u]){
			if(it.f > 0 && level[it.v] == level[u] + 1){
				int tf = DFS(it.v, min(nf, it.f));	
				res += tf;
				nf -= tf;
				it.f -= tf;
				E[it.v][it.re].f += tf;
				if(!nf) return res;
			}
		}
		if(!res) level[u] = -1;
		return res;
	}
	int flow(int res = 0){
		while(BFS()){
			res += DFS(s, 2147283647);
		}
		return res;
	}
} flow;

int N, M, K, t, x;

bool visited[maxN], side[maxN];
vector<int> ans[maxN];
int cnt;

void dfs(int x){
	visited[x] = true;
	ans[cnt].push_back(x);
	for(int u : adj[x]){
		if(!visited[u]) dfs(u);
	}
}

void getSide(int x, bool cs = 0){
	visited[x] = true;
	side[x] = cs;
	for(int v : bip[x]){
		if(visited[v]) continue;
		getSide(v, cs ^ 1);
	}
}

int main(){
	fill(isPrime, isPrime + maxN, true);
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]){
			for(int j = i * i; j < maxN; j += i) isPrime[j] = false;
		}
	}
	cin >> N;
	flow.init(N + 2, 0, N + 1);
	for(int i = 1; i <= N; i++) cin >> val[i];
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(isPrime[val[i] + val[j]]){
				bip[i].push_back(j);
				bip[j].push_back(i);
			}
		}
	}
	fill(visited, visited + N + 1, 0);
	for(int i = 1; i <= N; i++){
		if(!visited[i]) getSide(i);
	}
	for(int i = 1; i <= N; i++){
		if(!side[i]){
			flow.add_edge(0, i, 2);
			for(int j = 1; j <= N; j++){
				if(isPrime[val[i] + val[j]]){
					flow.add_edge(i, j, 1);	
					//cout << "Adding: " << i << " - " << j << endl;
				}
			}
		} else {
			flow.add_edge(i, N + 1, 2);
		}
	}
	if(flow.flow() != N){
		cout << "Impossible\n";
		return 0;
	}
	for(int i = 1; i <= N; i++){
		if(side[i]) continue;
		for(auto e : flow.E[i]){
			if(!e.f){
				adj[i].push_back(e.v);
				adj[e.v].push_back(i);
			}
		}
	}
	fill(visited, visited + N + 1, 0);
	for(int i = 1; i <= N; i++){
		if(visited[i]) continue;
		dfs(i);
		cnt++;
	}
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++){
		cout << ans[i].size();
		for(int x : ans[i]) cout << " " << x;
		cout << endl;
	}
}
