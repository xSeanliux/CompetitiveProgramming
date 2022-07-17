#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5 + 326;
vector<int> adj[maxN];

int N, u, v, sz[maxN], dep[maxN];
bool rem[maxN];

int getSz(int p, int u){
	dep[u]++;
	sz[u] = 1;
	for(int x : adj[u]) if(!rem[x] && x != p) sz[u] += getSz(u, x);
	return sz[u];
}

int find(int p, int u, int S){
	for(int x : adj[u]) if(!rem[x] && x != p){
		if(sz[x] * 2 > S) return find(u, x, S);
	}
	return u;
}

void centroid(int n = 1){
	n = find(n, n, getSz(n, n));
	rem[n] = 1;
	for(int x : adj[n]) if(!rem[x]) centroid(x);
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	centroid();	
	for(int i = 1; i <= N; i++) cout << (char)(dep[i] + 'A') << " \n"[i == N];
}
