#include <iostream>
#include <vector>
#include <queue>
#define int long long int
using namespace std;

const int maxN = 326, INF = 1e15;

struct Flow{
	int cap[maxN][maxN], N, dep[maxN], from[maxN], deg[maxN];
	queue<int> que;
	Flow(){}
	Flow(int N): N(N){
		for(int i = 0; i <= N; i++){
			for(int j = 0; j <= N; j++) cap[i][j] = cap[j][i] = 0;
			deg[i] = 0;
		}
	}
	void addEdge(int u, int v, int c){
		deg[u]++;
		deg[v]++;
		cap[u][v] += c;
	}
	bool BFS(int s, int t){
		fill(dep, dep + N + 1, INF);
		dep[s] = 0;
		que = queue<int>();
		que.push(s);
		while(que.size()){
			int x = que.front();
			que.pop();
			for(int i = 0; i <= N; i++){
				if(cap[x][i] > 0 && dep[i] == INF){
					from[i] = x;
					dep[i] = dep[x] + 1;
					que.push(i);
				}
			}
		}
		return dep[t] != INF;
	}
	int DFS(int s, int t){
		int c = t, bottleneck = INF;	
		while(s != c){
			bottleneck = min(bottleneck, cap[from[c]][c]);
			c = from[c];
		}
		c = t;
		while(s != c){
			cap[from[c]][c] -= bottleneck;
			cap[c][from[c]] += bottleneck;
			c = from[c];
		}
		return bottleneck;
	}
	inline int run(int s, int t){
		int r = 0;
		while(BFS(s, t)){
			r += DFS(s, t);
			//get the path
		}
		return r;
	}
} flow;

int N, M, u, v, x;

signed main(){
	cin >> N;	
	flow = Flow(2 * N + 1);
	for(int i = 1; i <= N; i++){
		cin >> x;
		flow.addEdge(2 * i - 1, 2 * i, x);
	}
	cin >> M;
	while(M--){
		cin >> u >> v;
		flow.addEdge(2 * u, 2 * v - 1, INF);
	}
	for(int i = 1; i <= N; i++){
		if(flow.deg[2 * i - 1] == 1){
			flow.addEdge(0, 2 * i - 1, INF);
		}
		if(flow.deg[2 * i] == 1) flow.addEdge(2 * i, 2 * N + 1, INF);
	}
	cout << flow.run(0, 2 * N + 1);
}
