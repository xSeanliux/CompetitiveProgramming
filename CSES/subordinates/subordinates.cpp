#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 326;

int N, p, sz[maxN];
vector<int> adj[maxN];

int dfs(int u = 1){
	sz[u] = 1;
	for(int v : adj[u]) sz[u] += dfs(v);
	return sz[u];
}

int main(){
	cin >> N;
	for(int i = 2; i <= N; i++){
		cin >> p;
		adj[p].push_back(i);
	}
	dfs();
	for(int i = 1; i <= N; i++) cout << sz[i] - 1 << endl;
}
