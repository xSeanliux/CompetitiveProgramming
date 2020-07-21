#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <bitset>
#define int long long int
using namespace std;

const int maxN = 2e5 + 226, INF = 1e18;

vector<int> adj[maxN], weights, dA, dB, dC;
queue<int> que;
int T, N, M, u, v, w, a, b, c;
bitset<maxN> visited;

inline void bfs(int s, vector<int> &minDist){
	minDist.resize(N + 1);
	visited.reset();
	fill(minDist.begin(), minDist.end(), INF);
	minDist[s] = 0;
	visited[s] = true;
	que.push(s);
	while(que.size()){
		int t = que.front();
		que.pop();
		for(int x : adj[t]){
			if(visited[x]) continue;
			visited[x] = true;
			minDist[x] = minDist[t] + 1;
			que.push(x);
		}
	}
}

inline void solve(){
	cin >> N >> M >> a >> b >> c;
	for(int i = 1; i <= N; i++) vector<int>().swap(adj[i]);
	weights.resize(M + 1);
	weights[0] = 0;
	for(int i = 1; i <= M; i++) cin >> weights[i];
	for(int i = 1; i <= M; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(weights.begin(), weights.end());
	for(int i = 1; i <= M; i++) weights[i] += weights[i - 1];
	//for(int i = 1; i <= M; i++){
	//	cout << "weights[" << i << "] = " << weights[i] << endl;
	//}
	bfs(a, dA);
	bfs(b, dB);
	bfs(c, dC);
	int ans = INF;
	for(int i = 1; i <= N; i++){
		if(dA[i] + dB[i] + dC[i] > M) continue;
		//cout << "i = " << i << ", dB[i] = " << dB[i] << ", oth = " << dA[i] + dB[i] + dC[i] << endl;
		ans = min(ans, weights[dB[i]] + weights[dA[i] + dB[i] + dC[i]]);
	}
	cout << ans << endl;
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
