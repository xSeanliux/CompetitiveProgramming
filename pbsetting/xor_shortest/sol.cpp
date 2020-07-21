#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 226, maxC = (1 << 10), INF = 1e18;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

int N, M, a, b, x, y, s, t;

struct Dijkstra{
	priority_queue<pii, vector<pii>, greater<pii> > pq;	
	vector<pii> adj[maxN * maxN + maxC];	
	int minDist[maxN * maxN + maxC];
	bool visited[maxN * maxN + maxC];
	void addEdge(int u, int v, int w){
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	void run(int s){
		fill(minDist, minDist + maxN * maxN + maxC, INF);
		fill(visited, visited + maxN * maxN + maxC, 0);
		minDist[s] = 0;
		pq.push({0, s});
		while(!visited[t * maxN] && pq.size()){
			auto [dist, u] = pq.top();
			pq.pop();
			if(visited[u]){
				continue;	
			}
			visited[u] = true;
			for(auto [v, wei] : adj[u]){
				if(visited[v]) continue;	
				if(minDist[v] > dist + wei){
					minDist[v] = dist + wei;
					pq.push({minDist[v], v});
				}
			}
		}
	}
} sssp;


signed main(){
	ericxiao;
	Read(N); Read(M); Read(s); Read(t);
	for(int i = 0; i < M; i++){
		Read(a); Read(b); Read(x); Read(y);
		for(int v = 0; v < maxC; v++){
			sssp.addEdge(maxN * a + v, maxN * b + (v ^ x), y);
		}
	}
	sssp.run(maxN * s);
	cout << (sssp.minDist[maxN * t] == INF ? -1 : sssp.minDist[maxN * t]) << endl;
}
