#include <iostream>
#include <map>
#include <vector>
#include <utility>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 20;
vector<int> childs[maxN];
vector<pii> adj[maxN];
vector<map<int, int>> subs[maxN];
int N, M, Q, val[maxN], u, v, w, sts[maxN], mc[maxN], root;
bool isCentroid[maxN];

inline int mexp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1){
			r = r * b % M;	
		}
		b = b * b % M;
	}
	return r;
}

void getSts(int p, int u){
	sts[u] = 1;
	mc[u] = -1;
	for(auto [v, w] : adj[u]){
		if(v != p && !isCentroid[v]){
			getSts(u, v, r);
			if(mc[u] == -1 || sts[mc[u]] < sts[v]) mc[u] = v;
			sts[u] += sts[v];
		}
	}
}

int getCentroid(int u, int l){
	int mx = l - sts[u];
	if(mc[u] != -1) mx = max(mx, sts[mc[u]]);
	if(mx <= l / 2) return u;
	return getCentroid(mc[u], l);
}

int buildTree(int u){
	getSts(u, u);	
	int cen = getCentroid(u, u);
	isCentroid[cen] = true;
	for(auto [v, w] : adj[cen]){
		if(isCentroid[v]) continue;
		childs[cen].push_back(buildTree(v));
	}
	return cen;
}


int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	root = getCentroid();
}



