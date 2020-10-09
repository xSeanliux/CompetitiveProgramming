#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 326;
vector<pii> adj[maxN], in[maxN];
vector<int> deg[12];

int N, M, K, u, v, w, can[12][12][12][12], self[12][12], cur[12], ans, frq[maxN];

void dfs(int lay = 1){
	if(lay == K + 1){
		ans++;
		return;
	}
	for(int i = 1; i <= lay; i++){
		bool f = self[lay][i];
		for(int j = 1; j < lay && f; j++){
			if(!can[j][cur[j]][lay][i]){
				f = false;
				break;
			}
		}
		if(f){
			cur[lay] = i;
			dfs(lay + 1);
		}
	}
}

signed main(){
	ericxiao;
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(w, v);
	}
	for(int i = 1; i <= N; i++){
		sort(adj[i].begin(), adj[i].end());
		int cnt = 1;
		for(auto [w, v] : adj[i]){
			in[v].emplace_back(cnt++, i);
		}
		deg[adj[i].size()].emplace_back(i);
	}
	for(int a = 1; a <= K; a++)
		for(int b = 1; b <= a; b++){
			self[a][b] = true;
			for(int x : deg[a]){
				if(frq[adj[x][b - 1].S]){
					self[a][b] = false;
				}
				frq[adj[x][b - 1].S]++;
			}
			if(!self[a][b]){
				for(int x : deg[a]){
					frq[adj[x][b - 1].S]--;
				}
				continue;
			}
			for(int c = a + 1; c <= K; c++)
				for(int d = 1; d <= c; d++){
					can[a][b][c][d] = true;
					for(int x : deg[c]){
						if(frq[adj[x][d - 1].S]){
							can[a][b][c][d] = false;
						}
						frq[adj[x][d - 1].S]++;
					}
					for(int x : deg[c]){
						frq[adj[x][d - 1].S]--;
					}
				}
			for(int x : deg[a]){
				frq[adj[x][b - 1].S]--;
			}
		}


	dfs();
	cout << ans << endl;
}
