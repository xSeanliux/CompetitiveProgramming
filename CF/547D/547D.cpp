#include <iostream>
#include <vector>
#include <utility>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
set<pii> adj[maxN * 2];

int N, x, y, ans[maxN * 2];
bool vis[maxN * 2];

void dfs(int x, bool f = true){
	if(!adj[x].size()) return;
	auto pi = *adj[x].begin();
	ans[pi.S] = f;
	adj[pi.F].erase({x, pi.S});
	adj[x].erase(pi);
	dfs(pi.F, f ^ 1);
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		adj[x].insert({y + maxN, i});
		adj[y + maxN].insert({x, i});
	}
	for(int i = 1; i < 2 * maxN; i++){
		if(adj[i].size() & 1){
			adj[0].insert({i, maxN * 2 - 1});
			adj[i].insert({0, maxN * 2 - 1});
		}
	}
	for(int i = 0; i < maxN * 2; i++){
		if(adj[i].size()){
			dfs(i);
		}
	}
	for(int i = 0; i < N; i++) cout << (ans[i] ? 'r' : 'b');
}
