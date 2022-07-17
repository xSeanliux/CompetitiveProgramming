#include <iostream>
#include <queue>
#include <vector>
#include <fstream> 
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define cout outfile
#define cin infile
using namespace std;

const int maxN = 1e5 + 326;

int N, M, u, v, ans;
struct Kosaraju{
	vector<int> adj[maxN], ord, rev[maxN];
	int belong[maxN], cnt, sz[maxN];
	bool vis[maxN];
	void addEdge(int u, int v){
		adj[u].push_back(v);	
		rev[v].push_back(u);	
	}
	void dfs(int now){
		vis[now] = 1;
		for(int v : adj[now]) if(!vis[v]) dfs(v);
		ord.push_back(now);
	}
	void rdfs(int now){
		vis[now] = 1;
		belong[now] = cnt;
		sz[cnt]++;
		for(int v : rev[now]) if(!vis[v]) rdfs(v);
	}
	void run(){
		fill(vis, vis + maxN, 0);
		for(int i = 1; i <= N; i++) if(!vis[i]) dfs(i);
		reverse(ord.begin(), ord.end());
		cnt = 1;
		fill(vis, vis + maxN, 0);
		for(int x : ord){
			if(!vis[x]){
				rdfs(x);
				cnt++;
			}
		}
	}
} scc;

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("grass.in");
	outfile.open("grass.out");
}



struct DP{
	vector<vector<int>> adj, rev;
	int w[maxN], dp[maxN][2], deg[maxN], N;
	bool vis[maxN];
	queue<int> que;
	DP(int N = 0): N(N){
		adj.resize(N + 1);
		rev.resize(N + 1);
	}
	inline void addEdge(int u, int v){
		adj[u].push_back(v);	
		rev[v].push_back(u);
	}
	void topo(int r, vector<vector<int>> &adj, int b){
		que = queue<int>();
		for(int i = 1; i <= N; i++) for(int x : adj[i]) deg[x]++;
		for(int i = 1; i <= N; i++) if(!deg[i]) que.push(i);
		while(que.size()){
			int u = que.front(); que.pop();
			for(int v : adj[u]){
				deg[v]--;	
				if(vis[u]){
					vis[v] = true;
					dp[v][b] = max(dp[v][b], dp[u][b] + w[v]);
				}
				if(!deg[v]) que.push(v);
			}
		}
	}
	inline void run(int r){
		for(int i = 1; i <= N; i++) dp[i][0] = dp[i][1] = 0;
		dp[r][0] = dp[r][1] = w[r];

		fill(vis, vis + N + 1, 0);
		fill(deg, deg + N + 1, 0);	
		vis[r] = true;
		topo(r, adj, 0);

		fill(vis, vis + N + 1, 0);
		fill(deg, deg + N + 1, 0);	
		vis[r] = true;
		topo(r, rev, 1);

		for(int i = 1; i <= N; i++){
			if(!dp[i][0]) dp[i][0] = -maxN;
			if(!dp[i][1]) dp[i][1] = -maxN;
		}
	}
} dp;


int main(){
	ericxiao
	IO();
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		scc.addEdge(u, v);
	}
	scc.run();
	dp = DP(scc.cnt);
	for(int i = 1; i <= N; i++) {
		dp.w[scc.belong[i]] = scc.sz[scc.belong[i]];
		for(int v : scc.adj[i]) if(scc.belong[i] != scc.belong[v]) dp.addEdge(scc.belong[i], scc.belong[v]);
	}
	dp.run(scc.belong[1]);
	ans = dp.dp[scc.belong[1]][0];
	for(int i = 1; i <= N; i++){
		for(int v : scc.adj[i]){
			ans = max(ans, dp.dp[scc.belong[i]][1] + dp.dp[scc.belong[v]][0] - dp.dp[scc.belong[1]][0]);
		}
	}
	cout << ans << endl;

}
