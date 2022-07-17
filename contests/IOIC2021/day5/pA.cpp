#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

const int maxN = 3260;
const int INF = 1e9;

struct Dinic{
	struct Edge{
		int to, cap, rev;
		Edge(){}
		Edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev){}
	};
	vector<Edge> G[maxN];
	void add_edge(int from, int to, int cap){
		G[from].push_back(Edge(to, cap, (int)(G[to].size())));
		G[to].push_back(Edge(from, 0, (int)(G[from].size()) - 1));
	}
	int n, s, t;
	void init(int _n){
		n = _n;
		for(int i = 0; i <= n; i++){
			G[i].clear();
		}
	}
	int level[maxN], iter[maxN];
	void bfs(){
		//cout << "starting with " << s << endl;
		fill(level, level + n + 1, -1);
		level[s] = 0;
		queue<int> que = queue<int>(); que.push(s);
		while(!que.empty()){
			int tmp = que.front(); que.pop();
			for (Edge e : G[tmp]){
				if(e.cap > 0 && level[e.to] == -1){
					level[e.to] = level[tmp] + 1;
					que.push(e.to);
				}
			}
		}
	}
	int dfs(int now, int flow){
		//cout << "now at " << now << ", flow = " << flow << endl;
		if(now == t) return flow;
		for(int &i = iter[now]; i < (int)G[now].size(); ++i){
			//cout << "i = " << i << endl;
			Edge &e = G[now][i];
			if(e.cap > 0 && level[e.to] == level[now] + 1){
				int ret = dfs(e.to, min(flow, e.cap));
				if(ret > 0){
					e.cap -= ret;
					G[e.to][e.rev].cap += ret;
					return ret;
				}
			}
		}
		return 0;
	}
	int flow(int _s, int _t){
		s = _s;
		t = _t;
		int ret = 0;
		while(true){
			bfs();
			if(level[t] == -1) break;
			fill(iter, iter + n + 1, 0);
			int tmp;
			while((tmp = dfs(s, INF)) > 0){
				//cout << "Flow += " << tmp << endl;
				ret += tmp;
			}
		}
		return ret;
	}
} flow;
int N, M, Q, u, v, w;

struct Edge{
	int u, v, w;
	Edge(int u = 0, int v = 0, int w = 0): u(u), v(v), w(w){}
	const bool operator<(const Edge &e) const { return w < e.w; }
};

vector<Edge> edges;

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);
	}
	sort(edges.begin(), edges.end());
	cin >> Q;
	while(Q--){
		cin >> u >> v >> w;
		int a = 0;
		//cout << "SMALL\n";
		flow.init(N);
		for(int i = 0; i < M; i++){
			if(edges[i].w >= w) break;
			//cout << "adding: " << edges[i].u << " " << edges[i].v << endl;
			flow.add_edge(edges[i].u, edges[i].v, 1);
			flow.add_edge(edges[i].v, edges[i].u, 1);
		}
		a = flow.flow(u, v);
		flow.init(N);
		//cout << "BIG" << endl;
		for(int i = M - 1; i >= 0; i--){
			if(edges[i].w <= w) break;
			//cout << "adding: " << edges[i].u << " " << edges[i].v << endl;
			flow.add_edge(edges[i].u, edges[i].v, 1);
			flow.add_edge(edges[i].v, edges[i].u, 1);
		}
		a += flow.flow(u, v);
		cout << a << endl;
	}
}
