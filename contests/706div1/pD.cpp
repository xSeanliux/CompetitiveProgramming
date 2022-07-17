#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 426, MOD = 998244353;
int N, M, u, v, ans[maxN][maxN], wei[maxN], lv[maxN][maxN], inv[maxN];
pii dp[maxN];
bool vis[maxN];

vector<int> adj[maxN];

inline int modexp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

inline int getInv(int x){
	return modexp(x, MOD - 2);
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int solve(int a, int b){
	//cout << "a = " << a << ", b = " << b << endl;
	int prod = 1, zc = 0;
	for(int i = 1; i <= N; i++){
		
		//cout << "i = " << i << ", lA = " << lA[i] << ", lB = " << lB[i] << endl;
		if(i == a || i == b) wei[i] = 1;
		else {
			wei[i] = 0;
			for(auto v : adj[i]) if(lv[a][v] + 1 == lv[a][i] && lv[b][v] + 1 == lv[b][i]) wei[i]++;
		}
		/*
		if(a == 5 && b == 6)
			cout << "wei[" << i << "] = " << wei[i] << endl;
			*/
		if(wei[i]) prod = prod * wei[i] % MOD;
		else zc++;
	}
	queue<int> que = queue<int>();
	for(int i = 1; i <= N; i++) dp[i] = {0, 0};
	dp[b] = {1, 0};
	fill(vis, vis + N + 1, 0);	
	vis[b] = true;
	que.push(b);
	while(que.size()){
		int u = que.front(); que.pop();
		if(u == a) break;
		if(wei[u])
			dp[u].F = dp[u].F * inv[wei[u]] % MOD;
		else dp[u].S++;
		//cout << "dp[" << u << "] = " << dp[u].F << ", " << dp[u].S << endl;
		for(int v : adj[u]){
			if(lv[b][v] == lv[b][u] + 1){	
				if(dp[v].S > dp[u].S) continue;
				else if(dp[v].S < dp[u].S) dp[v] = dp[u];
				else dp[v].F = add(dp[v].F, dp[u].F);
				if(!vis[v]){
					que.push(v);
					vis[v] = true;
				}
			}
		}
	}
	if(zc == dp[a].S) return prod * dp[a].F % MOD;
	else return 0;
}

signed main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) lv[i][j] = (i != j) * maxN;
	for(int i = 1; i <= N; i++) inv[i] = getInv(i);
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		lv[u][v] = lv[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) lv[i][j] = min(lv[i][j], lv[i][k] + lv[k][j]);
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j++){
			ans[i][j] = ans[j][i] = solve(i, j);
		}
	}
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cout << ans[i][j] << " \n"[j == N];
}

