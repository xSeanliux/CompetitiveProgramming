#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 10000;

struct Flow{
	int cap[500][500], N;
	bool vis[500];
	queue<int> que;
	int from[500], minDist[500];
	Flow(){}
	Flow(int N): N(N){
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cap[i][j] = 0;
	}
	inline void addEdge(int u, int v, int c){
		cap[u][v] += c;
	}
	inline bool BFS(int s, int t){
		fill(from, from + N, -1);
		fill(minDist, minDist + N, maxN);
		fill(vis, vis + N, false);
		minDist[s] = 0;
		que = queue<int>();
		que.push(s);
		vis[s] = true;
		while(que.size()){
			int u = que.front();
			que.pop();
			for(int i = 0; i < N; i++){
				if(!vis[i] && cap[u][i] > 0){
					minDist[i] = minDist[u] + 1;
					vis[i] = true;
					from[i] = u;
					que.push(i);
				}
			}
		}
		return from[t] != -1;
	}
	inline int upd(int s, int t){
		int minF = maxN;	
		for(int c = t; c != s; c = from[c]){
			minF = min(minF, cap[from[c]][c]);
		}
		for(int c = t; c != s; c = from[c]){
			cap[from[c]][c] -= minF;
			cap[c][from[c]] += minF;
		}
		return minF;
	}
	inline int run(int s, int t){
		int r = 0;
		while(BFS(s, t)){
			r += upd(s, t);
		}
		return r;
	}
} flow;

int N, M;
string s;

int main(){
	cin >> N >> M;
	flow = Flow(N + M + 20);
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < M; j++){
			if(s[j] == 'o'){
				flow.addEdge(i, j + N, 1);
				flow.addEdge(j + N, i, 1);
			}
			if(s[j] == 'S'){
				flow.addEdge(N + M, i, maxN);
				flow.addEdge(N + M, j + N, maxN);
			}
			if(s[j] == 'T'){
				flow.addEdge(i, N + M + 1, maxN);
				flow.addEdge(j + N, N + M + 1, maxN);
			}
		}
	}
	//source: N + M
	//sink: N + M + 1
	int res = flow.run(N + M, N + M + 1);
	cout << (res >= maxN ? -1 : res) << endl;
}
