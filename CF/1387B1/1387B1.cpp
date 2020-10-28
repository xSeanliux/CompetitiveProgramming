#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 1e5 + 326;
int N, u, v, deg[maxN], pa[maxN], ans[maxN];
bool isLeaf[maxN];
vector<int> adj[maxN], chi[maxN];
queue<int> que;

void dfs(int p = 1, int u = 1){
	pa[u] = p;
	cout << "pa of " << u << " is " << p << endl;
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
	}
}

int main(){
	cin >> N;
	fill(isLeaf, isLeaf + N + 1, true);
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	dfs();
	for(int i = 2; i <= N; i++) if(deg[i] == 1) que.push(i);
	while(que.size()){
		int t = que.front();
		//cout << "t = " << t << " pa = " << pa[t] << endl;
		que.pop();
		if(t == 1) break;
		if(isLeaf[t]){
			isLeaf[pa[t]] = false;	
			chi[pa[t]].push_back(t);
		}
		deg[pa[t]]--;
		if(deg[pa[t]] == 1){
			que.push(pa[t]);
		}
	}
	if(isLeaf[1]){
		chi[adj[1][0]].push_back(1);
	}
	for(int i = 1; i <= N; i++){
		if(!isLeaf[i]){
			cout << "i = " << i << endl;
			cout << "chi: ";
			for(int x : chi[i]) cout << x << " ";
			cout << endl;
			ans[chi[i][0]] = i;	
			ans[i        ] = chi[i][0];
			for(int j = 2; j < chi[i].size(); j++) ans[chi[i][j]] = chi[i][j - 1];
			if(chi[i].size() > 1) ans[chi[i][1]] = ans[chi[i]
		}
	}
	int sum = 2 * N;
	for(int i = 1; i <= N; i++){
		if(!isLeaf[i]){
			cout << "i = " << i << endl;
			sum -= 2;
		}
	}
	cout << sum << endl;
	for(int i = 1; i <= N; i++) cout << ans[i] << " \n"[i == N];
}
