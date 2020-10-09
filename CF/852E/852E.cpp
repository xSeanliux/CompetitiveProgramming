#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326, MOD = 1e9 + 7;

vector<int> adj[maxN];

int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline int inv(int x){
	return exp(x, MOD - 2);
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a >= b ? a - b : a - b + MOD);
}

int N, u, v, dp[maxN][2], ans;

void getAns(int p = 1, int u = 1){
	int a = 1, b = 1, c = 1, d = 1;
	for(int v : adj[u]) if(v != p){
		getAns(u, v);		
		a = a * dp[v][1] % MOD;
		b = b * dp[v][0] % MOD;
	}
	dp[u][0] = dp[u][1] = add(a, b);
}

void dfs(int p = 1, int u = 1){
	ans = add(ans, dp[u][0]);
	for(int v : adj[u]) if(v != p){
			
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	getAns();
	dfs();
}
