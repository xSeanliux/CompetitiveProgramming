#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 326;
vector<int> adj[maxN];
vector<pii> cur;

int N, u, v, fibs[maxN], sz[maxN], pa[maxN];

int getSz(int p, int u){
	sz[u] = 1;
	pa[u] = p;
	for(int v : adj[u]) if(v != p) sz[u] += getSz(u, v);
	cur.emplace_back(u, sz[u]);
	return sz[u];
}

inline void del(vector<int> &v, int id){
	v.erase(find(v.begin(), v.end(), id));
}

bool fibTree(int r, int id){
	if(id <= 3) return true;
	vector<pii>().swap(cur);
	getSz(r, r);
	vector<pii> _cur = cur;
	vector<pii>().swap(cur);
	for(auto [v, s] : _cur){
		if(s == fibs[id - 1]){
			del(adj[v], pa[v]);
			del(adj[pa[v]], v);
			return fibTree(v, id - 1) && fibTree(r, id - 2);
		} else if(s == fibs[id - 2]){
			del(adj[v], pa[v]);
			del(adj[pa[v]], v);
			return fibTree(v, id - 2) && fibTree(r, id - 1);
		}
	}
	return false;
}

int main(){
	cin >> N;
	if(N == 1){
		cout << "Yes\n";
		return 0;
	}
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fibs[0] = fibs[1] = 1;
	int id;
	for(int i = 2; ; i++){
		fibs[i] = fibs[i - 1] + fibs[i - 2];
		if(fibs[i] == N){
			id = i;
			break;
		} else if(fibs[i] > N){
			cout << "No\n";
			return 0;
		}
	}
	cout << (fibTree(1, id) ? "Yes" : "No") << endl;
}
