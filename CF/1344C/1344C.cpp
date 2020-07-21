#include <iostream>
#include <queue>
#include <numeric>
#include <vector>
using namespace std;

const int maxN = 2e5 + 226;
queue<int> que;
int N, M, a, b, min1[maxN], min2[maxN], indeg[maxN];

vector<int> adj[maxN], rev[maxN];

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	for(int i = 1; i <= N; i++){
		for(int x : adj[i]) indeg[x]++;	
	}
	for(int i = 1; i <= N; i++) if(!indeg[i]) que.push(i);
	int cnt = 0;
	while(que.size()){
		int t = que.front();
		que.pop();
		cnt++;
		for(int u : adj[t]){
			indeg[u]--;
			if(!indeg[u]) que.push(u);
		}
	}
	if(cnt < N){
		cout << -1 << endl;
		return 0;
	}
	iota(min1, min1 + N + 1, 0);
	iota(min2, min2 + N + 1, 0);
	for(int i = 1; i <= N; i++){
		for(int x : adj[i]) indeg[x]++;
	}
	for(int i = 1; i <= N; i++) if(!indeg[i]) que.push(i);
	while(que.size()){
		int t = que.front();	
		que.pop();
		for(int u : adj[t]){
			min1[u] = min(min1[u], min1[t]);
			indeg[u]--;
			if(!indeg[u]) que.push(u);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int x : rev[i]) indeg[x]++;
	}
	for(int i = 1; i <= N; i++) if(!indeg[i]) que.push(i);
	while(que.size()){
		int t = que.front();	
		que.pop();
		for(int u : rev[t]){
			min2[u] = min(min2[u], min2[t]);
			indeg[u]--;
			if(!indeg[u]) que.push(u);
		}
	}
	int ans = 0;
	for(int i = 1; i <= N; i++){
		if(min1[i] == i && min2[i] == i) ans++;
	}
	cout << ans << endl;
	for(int i = 1; i <= N; i++){
		cout << ((min1[i] == i && min2[i] == i) ? 'A' : 'E');
	}
}
