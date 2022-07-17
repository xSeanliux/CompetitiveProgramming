#include <iostream>
#include <vector>
using namespace std;

const int maxN = 500;

vector<int> g[maxN], r[maxN];
vector<int> ord, sccs[maxN];

int head = 0, belong[maxN], N, M, u, v;

bool vis[maxN];

void rDfs(int x){
	vis[x] = true;
	for(int u : r[x]){
		if(!vis[u]) rDfs(u);
	}
	ord.push_back(x);
}

void dfs(int x, int s){
	sccs[s].push_back(x);
	belong[x] = s;
	for(int u : g[x]){
		if(belong[u] == -1) dfs(u, s);
	}
}

void Kosaraju(){
	fill(belong, belong + maxN, -1);
	for(int i = 1; i <= N; i++) if(!vis[i]) rDfs(i);
	for(int i = N - 1; i >= 0; i--){
		int x = ord[i];
		if(belong[x] == -1){
			dfs(x, head);	
			head++;
		}
	}
}
int main(){
	cin >> N >> M;	
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		g[u].push_back(v);
		r[v].push_back(u);
	}
	Kosaraju();
	int ans = 0;
	for(int i = 1; i <= N; i++) cout << belong[i] << endl;
	for(int i = 0; i < head; i++){
		ans += (sccs[i].size() == 1);
	}
	cout << ans << endl;
}
