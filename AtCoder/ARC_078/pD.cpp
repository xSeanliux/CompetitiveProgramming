#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int maxN = 1e5 + 326;

deque<int> path;

vector<int> adj[maxN];
bool vis[maxN];

int N, u, v, sz[maxN];
bool found = false;

void findPath(int p = 1, int u = 1){
	if(found) return;
	path.push_back(u);
	if(u == N){
		found = true;
		return;
	}
	for(int v : adj[u]) if(v != p){
		findPath(u, v);
		if(found) return;
	}
	path.pop_back();
}

int getSz(int u){
	if(vis[u]) return 0;
	vis[u] = true;
	int r = 1;
	for(int v : adj[u]){
		r += getSz(v);
	}
	return r;
}

int main(){
 	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	findPath();
	for(int x : path){
		vis[x] = true;
	}
	for(int x : path){
		for(int v : adj[x]){
			sz[x] += getSz(v);
		}
	}
	int A = 0, B = 0;
	A = sz[path.front()] + 1, B = sz[path.back()] + 1;
	path.pop_front();
	path.pop_back();
	while(path.size()){
		A += sz[path.front()] + 1;
		path.pop_front();
		if(path.size()){
			B += sz[path.back()] + 1;
			path.pop_back();
		}
	}
	if(A > B){
		cout << "Fennec" << endl;
	} else {
		cout << "Snuke" << endl;
	}
}
