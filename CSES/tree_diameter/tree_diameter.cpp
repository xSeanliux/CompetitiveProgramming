#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
int N, u, v, d1[maxN], d2[maxN];
vector<int> adj[maxN];





pii getFar(int p = 1, int u = 1){
	pii res = {0, u};
	for(int v : adj[u]) if(v != p){
		auto r = getFar(u, v);
		r.F++;
		res = max(res, r);
	}
	return res;
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto [d, x] = getFar();
	d = getFar(x, x).F;
	auto [d, y] = getFar(x, x);

}
