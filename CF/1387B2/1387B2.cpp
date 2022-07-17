#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <numeric>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326;
vector<int> adj[maxN], ord;

int N, u, v, sz[maxN], to[maxN];
long long int ans;
stack<pii> stk;

int dfs(int p = 1, int u = 1){
	sz[u] = 1;
	for(int v : adj[u]) if(v != p) sz[u] += dfs(u, v);
	return sz[u];
}

int find(int p = 1, int u = 1){
	for(int v : adj[u]) if(v != p && sz[v] * 2 > N) return find(u, v);
	return u;
}

void getSts(int p, int u, int d = 0){
	d++;
	ans += d * 2;
	ord.push_back(u);
	for(int v : adj[u]) if(v != p){
		getSts(u, v, d);
	}
}

int main(){
	cin >> N;
	iota(to, to + N + 1, 0);
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int c = find();
	//cout << "cen = " << c << endl;
	for(int v : adj[c]){
		getSts(c, v);
	}
	if(ord.size() & 1) ord.push_back(c);
	//for(int x : ord) cout << x << " ";
	//cout << endl;
	for(int i = 0; i < ord.size() / 2; i++){
		assert((i + ord.size() / 2) < ord.size());
		swap(to[ord[i]], to[ord[i + ord.size() / 2]]);
	}
	if(to[c] == c){
		for(int i = 1; i <= N; i++) if(i != c) {
			swap(to[c], to[i]);
			break;
		}
	}
	cout << ans << endl;
	for(int i = 1; i <= N; i++) cout << to[i] << " \n"[i == N];
}


