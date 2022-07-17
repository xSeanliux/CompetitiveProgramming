#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 326, INF = 1e9;

struct Flow{
	int N, cap[maxN][maxN], dep[maxN], from[maxN];
	vector<int> adj[maxN];
	queue<int> que;
	Flow(){}
	Flow(int N): N(N){
		for(int i = 0; i < N; i++){
			vector<int>().swap(adj[i]);
			for(int j = 0; j < N; j++) cap[i][j] = cap[j][i] = 0;
		}
	}
	inline void addEdge(int u, int v, int c){
		cap[u][v] += c;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool BFS(int s, int t){
		que = queue<int>();
		fill(dep, dep + N, INF);
		dep[s] = 0;
		que.push(s);
		while(que.size()){	
			int x = que.front();
			que.pop();
			for(int v : adj[x]){
				if(cap[x][v] > 0 && dep[v] == INF){
					dep[v] = dep[x] + 1;
					from[v] = x;
					que.push(v);
				}
			}
		}
		return dep[t] != INF;
	}
	inline int upd(int s, int t){
		int c = t, b = INF;
		while(c != s){
			b = min(b, cap[from[c]][c]);
			c = from[c];
		}
		c = t;
		while(c != s){
			cap[from[c]][c] -= b;
			cap[c][from[c]] += b;	
			c = from[c];
		}
		return b;
	}
	inline int run(int s, int t){
		int r = 0;
		while(BFS(s, t)) r += upd(s, t);
		return r;
	}
} flow;


int N, M;
string a, b;

inline int getId(string &s){
	if(s == "XXL") return M + 1;
	if(s == "XL") return M + 2;
	if(s == "L") return M + 3;
	if(s == "M") return M + 4;
	if(s == "S") return M + 5;
	if(s == "XS") return M + 6;
	return -1;
}

inline void solve(){
	flow = Flow(M + 8);
	for(int i = M + 1; i <= M + 6; i++) flow.addEdge(i, M + 7, N / 6);
	for(int i = 1; i <= M; i++){
		cin >> a >> b;
		flow.addEdge(0, i, 1);
		flow.addEdge(i, getId(a), 1);
		flow.addEdge(i, getId(b), 1);
	}
	cout << (flow.run(0, M + 7) == M ? "YES" : "NO") << endl;
}

int main(){
	while(cin >> N >> M){
		solve();
	}
}
