#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 326, maxLog = 19;
set<int> pos[maxN], sing[maxN];

int N, M, com, v, x, y, l, r, dep[maxN], jump[maxN], pa[maxN], Q, arr[maxN], anc[maxLog][maxN];
vector<int> adj[maxN];

void getAnc(int p = 1, int u = 1){
	pa[u] = p;
	//anc[0][u] = p;
	dep[u] = dep[p] + 1;
	//for(int i = 1; i < maxLog; i++) anc[i][u] = anc[i - 1][anc[i - 1][u]];
	if(u == p){
		jump[u] = p;
	} else {
		if(dep[jump[jump[p]]] - dep[jump[p]] == dep[jump[p]] - dep[p]) jump[u] = jump[jump[p]]; 
		else jump[u] = p;
	}
	for(int v : adj[u]) if(v != p) getAnc(u, v);
}

int lca(int a, int b){
	if(dep[a] > dep[b]) swap(a, b);
	while(dep[b] > dep[a]){
		if(dep[jump[b]] < dep[a]) b = pa[b];
		else b = jump[b];
	}
	if(a == b) return a;
	while(pa[a] != pa[b]){
		if(jump[a] == jump[b]){
			a = pa[a];
			b = pa[b];
		} else {
			a = jump[a];
			b = jump[b];
		}
	}
	return pa[a];
}

int main(){
	ericxiao
	cin >> N >> M >> Q;
	for(int i = 0; i < N - 1; i++){
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	getAnc();
	for(int i = 1; i <= M; i++){
		cin >> arr[i];
		sing[arr[i]].insert(i);
	}
	for(int i = 1; i < M; i++){
		pos[lca(arr[i], arr[i + 1])].insert(i);
		//cout << arr[i] << " " << arr[i + 1] << ": " << lca(arr[i], arr[i + 1]) << endl;
	}
	while(Q--){
		cin >> com;
		if(com == 1){
			cin >> x >> v;
			sing[arr[x]].erase(x);
			if(x + 1 <= M){
				pos[lca(arr[x], arr[x + 1])].erase(x);
			}
			if(x - 1 >= 1){
				pos[lca(arr[x - 1], arr[x])].erase(x - 1);	
			}
			arr[x] = v;
			sing[arr[x]].insert(x);
			if(x + 1 <= M){
				pos[lca(arr[x], arr[x + 1])].insert(x);
			}
			if(x - 1 >= 1){
				pos[lca(arr[x - 1], arr[x])].insert(x - 1);	
			}
		} else {
			cin >> l >> r >> v;
			auto it = sing[v].lower_bound(l);
			if(it != sing[v].end() && *it <= r){
				assert(*it >= l && *it <= r);
				assert(arr[*it] == v);
				cout << *it << " " << *it << endl;
			} else {
				auto it2 = pos[v].lower_bound(l);
				//if(it2 != pos[v].end()) cout << "found: " << *it2 << endl;
				if(it2 != pos[v].end() && *it2 + 1 <= r){
					assert(*it2 >= l && *it2 + 1 <= r);
					assert(lca(arr[*it2], arr[*it2 + 1]) == v);
					cout << *it2 << " " << *it2 + 1 << endl;
				} else {
					cout << "-1 -1" << endl;
				}
			}
		}
	}

}
