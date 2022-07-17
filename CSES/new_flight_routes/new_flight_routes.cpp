#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int N, M, u[maxN], v[maxN], indeg[maxN], outdeg[maxN], has[maxN];

struct Kosaraju{
	vector<int> adj[maxN], rev[maxN], ord;	
	bool vis[maxN];
	int belong[maxN], cnt = 0;
	void dfs(int now){
		vis[now] = true;	
		for(int v : adj[now]) if(!vis[v]) dfs(v);
		ord.push_back(now);
	}
	void dfs2(int now, int val){
		vis[now] = true;
		belong[now] = val;
		for(auto v : rev[now]) if(!vis[v]) dfs2(v, val);
	}
	void addEdge(int u, int v){
		adj[u].push_back(v);
		rev[v].push_back(u);
	}
	void run(){
		vector<int>().swap(ord);
		fill(vis, vis + N + 1, 0);
		for(int i = 1; i <= N; i++) if(!vis[i]) dfs(i);
		//cout << "ord: "; for(int x : ord) cout << x << " "; cout << endl;
		reverse(ord.begin(), ord.end());
		fill(vis, vis + N + 1, 0);
		for(int x : ord){
			if(!vis[x]){
				dfs2(x, cnt);
				cnt++;
			}
		}
	}
} scc;

vector<pii> ans;
queue<int> a, b, c;

int main(){
	cin >> N >> M;	
	for(int i = 0; i < M; i++){
		cin >> u[i] >> v[i];
		scc.addEdge(u[i], v[i]);
	}
	scc.run();
	for(int i = 0; i < M; i++){
		if(scc.belong[u[i]] != scc.belong[v[i]]){
			indeg[scc.belong[v[i]]]++;
			outdeg[scc.belong[u[i]]]++;
		}
	}
	for(int i = 1; i <= N; i++){
		if(has[scc.belong[i]]) continue;
		has[scc.belong[i]] = true;
		if(indeg[scc.belong[i]] == 0 && outdeg[scc.belong[i]] == 0) c.push(i);
		else if(indeg[scc.belong[i]] == 0) a.push(i);
		else if(outdeg[scc.belong[i]] == 0) b.push(i);
	}
	while(a.size() && b.size()
	cout << max(a, b) << endl;
}
