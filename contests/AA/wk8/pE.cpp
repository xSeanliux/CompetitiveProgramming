#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 326, INF = 1e15;
struct Ans{
	int len;
	string s;
	Ans(int l, string s): len(l), s(s){}
	Ans(){}
	const bool operator<(const Ans &a) const {
		return (len == a.len) ? s < a.s : len < a.len;
	}
} dis[maxN];

struct Edge{
	int v, w;
	char c;
	Edge(int v, int w, char c): v(v), w(w), c(c){}
};

int N, M, u, v, w;
char c;
bool vis[maxN];
vector<Edge> adj[maxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main(){
	cin >> N >> M;	
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w >> c;
		adj[u].emplace_back(v, w, c);
		adj[v].emplace_back(u, w, c);
	}
	for(int i = 2; i <= N; i++) dis[i] = Ans(INF, "");
	dis[1] = Ans(0, "");
	pq.push({0, 1});
	while(pq.size()){
		auto x = pq.top(); pq.pop();
		int u = x.S;
		//cout << "have: " << u << endl;
		if(vis[u]) continue;
		vis[u] = true;
		for(auto e : adj[u]){
			if(vis[e.v]) continue;
			//cout << "Looking at " << e.v << ", new string: " << dis[u].s + e.c << endl;
			if(Ans(dis[u].len, dis[u].s + e.c) < dis[e.v]){
				dis[e.v] = Ans(dis[u].len, dis[u].s + e.c);
				//cout << "updating " << e.v << endl;
				pq.push({dis[e.v].len, e.v});
			}
		}
	}
	for(int i = 2; i <= N; i++) cout << dis[i].s[dis[i].s.length() - 1];
}
