#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 526;
int dist[maxN][maxN], ans[maxN][maxN], N, M, u, v;
int F[maxN * 2], C[maxN * 2];

int main(){
	ericxiao;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) dist[i][j] = maxN;
	for(int i = 1; i <= N; i++) dist[i][i] = 0;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		dist[u][v] = dist[v][u] = 1;
	}
	for(int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	for(int a = 1; a <= N; a++){
		for(int v = 1; v <= N; v++){
			fill(F, F + maxN * 2, 0);
			fill(C, C + maxN * 2, 0);
			for(int b = 1; b <= N; b++){
				F[dist[a][b] - 1 - dist[v][b] + 500] += dist[a][b] - 1 - dist[v][b];
				C[dist[a][b] - 1 - dist[v][b] + 500]++;
			}
			for(int i = maxN * 2 - 2; i >= 0; i--){
				F[i] += F[i + 1];
				C[i] += C[i + 1];
			}
			for(int u = 1; u <= N; u++){
				ans[u][v] += F[dist[a][u] + 500] + ( - C[dist[a][u] + 500]) * dist[a][u];
				ans[v][u] += F[dist[a][u] + 500] + ( - C[dist[a][u] + 500]) * dist[a][u];
			}
		}
	}
	int mx = 0, mxcnt = 0;
	for(int u = 1; u <= N; u++){
		for(int v = u; v <= N; v++){
			if(mx < ans[u][v]){
				//cout << "u = " << u << ", v = " << v << endl;
				mxcnt = 1;
				mx = ans[u][v];
			} else if(mx == ans[u][v]){
				mxcnt++;
			}
		}
	}
	cout << mxcnt << " " << mx / 2 << endl;
}
