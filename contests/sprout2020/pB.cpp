#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 226, INF = 1e18;
vector<pii> adj[maxN];

int N, u, v, w, wei[maxN], ans = INF, stwd[maxN], sts[maxN], totsz = 0;

void dfs1(int p = 1, int u = 1){
	stwd[u] = 0;	
	sts[u] = wei[u];
	for(auto e : adj[u]){
		if(p == e.F) continue;
		dfs1(u, e.F);
		sts[u] += sts[e.F];
		stwd[u] += stwd[e.F] + sts[e.F] * e.S;
	}
}

void dfs2(int p = 1, int u = 1){
	ans = min(ans, stwd[u]);
	//cout << "U = " << u << ", ans = " << stwd[u] << endl;
	for(auto e : adj[u]){
		if(p == e.F) continue;	
		int ustwd = stwd[u], usts = sts[u], vstwd = stwd[e.F], vsts = sts[e.F];
		sts[u] = totsz - vsts;
		sts[e.F] = totsz;
		stwd[u] = ustwd - vstwd - vsts * e.S; 
		stwd[e.F] = vstwd + stwd[u] + sts[u] * e.S;
		dfs2(u, e.F);
		sts[u] = usts;
		sts[e.F] = vsts;
		stwd[u] = ustwd;
		stwd[e.F] = vstwd;
	}
}

signed main(){
	ericxiao;
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> wei[i];
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	dfs1();
	totsz = sts[1];
	for(int i = 1; i <= N; i++){
		//cout << "stwd[" << i << "] = " << stwd[i] << endl;
	}
	dfs2();
	cout << ans << endl;
}
