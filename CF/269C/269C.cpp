#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 10;
struct Edge{
	int u, w, id;
	Edge(int u, int w, int id): u(u), w(w), id(id){}
};


queue<int> que;

pii edges[maxN];
vector<Edge> adj[maxN];
bool ori[maxN], vis[maxN];

int N, M, u, v, w, needIn[maxN], deg[maxN];

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		edges[i] = {u, v};
		adj[u].emplace_back(v, w, i);
		adj[v].emplace_back(u, w, i);
		deg[u] += w;
		deg[v] += w;
	}
	for(int i = 1; i < N; i++){
		needIn[i] = deg[i] / 2;
	}
	que.push(1);	
	while(que.size()){
		int f = que.front();
		vis[f] = true;
		que.pop();
		for(auto [v, w, id] : adj[f]){
			if(vis[v]) continue;
			needIn[v] -= w;
			ori[id] = (edges[id].F != f); 
			if(!needIn[v]){
				que.push(v);
			}
		}
	}
	for(int i = 0; i < M; i++) cout << ori[i] << endl;
}
