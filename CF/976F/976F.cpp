#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e3 + 326;

struct Flow{
	int cap[maxN][maxN], cost[maxN][maxN], N, dist[maxN], from[maxN];
	bool vis[maxN]; 
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	Flow(){}
	Flow(int N): N(N){}
	inline void setEdge(int u, int v, int f, int c){ //
		cap[u][v] = f;
		cost[u][v] = c;
		cost[v][u] = -c;
	}
	inline bool getDist(int s, int t){
		fill(vis, vis + N + 1, false);			
		fill(dist, dist + N + 1, maxN);
		dist[s] = 0;
		pq.push({0, s});
		pq = priority_queue<pii, vector<pii>, greater<pii>>();
		while(pq.size() && !vis[t]){
			auto [d, cur] = pq.top();
			pq.pop();
			if(vis[cur]) continue;
			vis[cur] = true;
			for(int i = 0; i <= N; i++) if(!vis[cur] && cap[cur][i] > 0 && dist[i] > d + cost[cur][i]){
				dist[i] = d + cost[cur][i];	
				from[i] = cur;
				pq.push({dist[i], i});	
			}
		}
		return vis[t];
	}
	inline pii run(int s, int t){

	}
} flow;

int main(){

}
