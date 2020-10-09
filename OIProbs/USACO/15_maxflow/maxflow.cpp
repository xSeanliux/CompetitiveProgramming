#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int maxN = 5e4 + 10, maxL = 15;

vector<int> adj[maxN];
int N, K, u, v, anc[maxN][maxL], pa[maxN], dep[maxN], val[maxN];

ifstream infile;
ofstream outfile;

void getAnc(int p = 1, int u = 1){
	pa[u] = anc[u][0] = p;
	dep[u] = dep[p] + 1;
	for(int i = 1; i < maxL; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int v : adj[u]) if(v != p) getAnc(u, v);
}

int kthAnc(int x, int k){
	for(int i = 0; i < maxL; i++){
		if((k >> i) & 1) x = anc[x][i];
	}
	return x;
}

int LCA(int a, int b){
	if(dep[a] > dep[b]) swap(a, b);
	b = kthAnc(b, dep[b] - dep[a]);
	if(a == b) return a;
	for(int i = maxL - 1; i >= 0; i--){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

void dfs(int p = 1, int u = 1){
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
		val[u] += val[v];
	}
}

int main(){
	infile.open("maxflow.in");
	outfile.open("maxflow.out");
	infile >> N >> K;	
	for(int i = 0; i < N - 1; i++){
		infile >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	getAnc();
	while(K--){
		infile >> u >> v;
		if(dep[u] > dep[v]) swap(u, v);
		int lca = LCA(u, v);
		if(lca == u || lca == v){
			val[v]++;
			if(pa[lca] != lca) val[pa[lca]] -= 1;
		} else {
			val[v]++;
			val[u]++;
			val[lca]--;
			if(pa[lca] != lca) val[pa[lca]] -= 1;

		}
	}
	dfs();
	int mxAt = 0;
	for(int i = 1; i <= N; i++){
		if(!mxAt || val[mxAt] < val[i]) mxAt = i;
	}
	outfile << val[mxAt] << endl;
	infile.close();
	outfile.close();
}

