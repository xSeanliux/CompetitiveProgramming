#include <vector>
#include <cstdio>
#define max(a,b) (a)>(b)?(a):(b)
using namespace std;

const int maxN = 2e3 + 326;
int N, K, dp[maxN][maxN][2], u, v, w[maxN], sz[maxN];

vector<int> adj[maxN];

int dfs(int p = 1, int u = 1){
	sz[u] = 1;
	dp[u][0][0] = dp[u][0][1] = w[u];
	int newdp[sz[u]][2];
	for(int k = 0; k < adj[u].size(); k++){
		int v = adj[u][k];
		if(v != p){
			sz[u] += dfs(u, v);	
			for(int i = 0; i <= 2 * sz[u] - 2; i++) newdp[i][0] = newdp[i][1] = 0;
			for(int i = 0; i <= 2 * sz[u] - 2; i++){
				for(int j = 0; j <= 2 * sz[v] - 2; j++){
					if(i + j + 2 <= K){
						newdp[i + j + 2][0] = max(newdp[i + j + 2][0], dp[u][i][0] + dp[v][j][0]);
						newdp[i + j + 2][1] = max(newdp[i + j + 2][1], dp[u][i][1] + dp[v][j][0]);
					}
					if(i + j + 1 <= K){
						newdp[i + j + 1][1] = max(newdp[i + j + 1][1], dp[u][i][0] + dp[v][j][1]);
					}
				}
			}
			for(int i = 0; i <= 2 * sz[u] - 2; i++){
				dp[u][i][0] = max(dp[u][i][0], newdp[i][0]);
				dp[u][i][1] = max(dp[u][i][1], newdp[i][1]);
			}
		}
	}
	return sz[u];
}

int main(){
	scanf("%d%d", &N, &K);
	K = min(K, 2 * N - 2);
	for(int i = 1; i <= N; i++) scanf("%d", w + i);
	for(int i = 0; i < N - 1; i++){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int ans = 0;
	for(int i = 0; i <= K; i++) ans = max(ans, max(dp[1][i][0], dp[1][i][1]));
	printf("%d\n", ans);
}
