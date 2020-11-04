#include <iostream>
#include <vector>
using namespace std;

const int maxN = 3e5 + 326;
int T, N, col[maxN], u, v, dep[maxN], md[maxN][2], minZ, minO;
vector<int> adj[maxN];

void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	md[u][col[u]] = dep[u];
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
		md[u][0] = min(md[u][0] 
	}
}



void solve(){
	cin >> N;
	ans = 0;
	minZ = minO = maxN;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int hasz = 0, haso = 0;
	for(int i = 1; i <= N; i++){
		cin >> col[i];
		(col[i] ? hasz : haso) += 1;
	}
	if(hasz < 2 || haso < 2){
		cout << -1 << endl;
	} else {
		
	}
	for(int i = 1; i <= N; i++){
		vector<int>().swap(adj[i]);
		md[i][0] = md[i][1] = 0;
		dep[i] = 0;
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
