#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 326;

int N, u, v, dp[maxN][2];
vector<int> adj[maxN];

void dfs(int p = 1, int u = 1){
	int d = 0;
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
		dp[u][0] += max(dp[v][0], dp[v][1]);
		dp[u][1] += max(dp[v][0], dp[v][1]);
		if(dp[v][1] >= dp[v][0])
			d = max(d, dp[v][0] - dp[v][1] + 1);
	}
	dp[u][1] += d;
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << max(dp[1][0], dp[1][1]) << endl;
}
