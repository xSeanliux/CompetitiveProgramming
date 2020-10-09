#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <numeric>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 326;
int N, M, K, P, u, v, t, a, b, can[maxN], haskey[maxN];
vector<pii> doors[maxN], adj[maxN];
set<int> keys[maxN], pot[maxN];
queue<int> que;

int main(){
	ericxiao;
	cin >> N >> M >> K >> P;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> t;
		adj[u].emplace_back(v, t);
		adj[v].emplace_back(u, t);
	}
	for(int i = 0; i < P; i++){
		cin >> a >> b;
		keys[a].insert(b);
	}
	que.push(1);
	can[1] = true;
	while(que.size()){
		int f = que.front();
		que.pop();
		for(int k : keys[f]){
			haskey[k] = true;
			for(int x : pot[k]) if(!can[x]){
				que.push(x);
				can[x] = true;
			}
			pot[k] = set<int>();
		}
		for(auto [u, v] : adj[f]){
			if(can[u]) continue;
			if(haskey[v]){
				can[u] = true;
				que.push(u);
			} else {
				pot[v].insert(u);
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) cnt += can[i];
	cout << cnt << endl;
	for(int i = 1; i <= N; i++){
		if(can[i]) cout << i << " ";
	}
	
}

