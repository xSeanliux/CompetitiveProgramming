#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = (1 << 20) + 226;
vector<pii> pis;
vector<pii> adj[maxN];
vector<int> ans;
int n, deg[maxN], _a, _b, rep, lv;
bool has[maxN];

struct DSU{
	int sz, dsu[maxN];
	DSU(){}
	DSU(int s){
		sz = s;
		iota(dsu, dsu + s, 0);
	}
	void Find(int x){
		if(x == dsu[x]) return;
		Find(dsu[x]);
		dsu[x] = dsu[dsu[x]];
	}
	void Merge(int a, int b){
		Find(dsu[a]);
		Find(dsu[b]);
		dsu[dsu[a]] = dsu[b];
	}
} dsu;

void dfs(int pa, int now){
	for(auto [v, id] : adj[now]){
		if(v == pa) continue;
		if((pis[id].F & ((1 << lv) - 1)) == v){
			ans.push_back(2 * id + 1);
			ans.push_back(2 * id + 2);
		} else {
			ans.push_back(2 * id + 2);
			ans.push_back(2 * id + 1);
		}
		dfs(now, v);
	}
}

int main(){
	cin >> n;
	pis.resize(n);
	for(int i = 0; i < n; i++) cin >> pis[i].F >> pis[i].S;
	for(lv = 20; lv >= 0; lv--){
		bool can = true;
		for(int i = 0; i < (1 << lv); i++){
			adj[i].clear();
		}
		dsu = DSU((1 << lv));
		fill(has, has + (1 << lv), false);
		int ind = 0;
		for(auto [a, b] : pis){
			_a = a & ((1 << lv) - 1);
			_b = b & ((1 << lv) - 1);
			has[_a] = has[_b] = true;
			adj[_a].emplace_back(_b, ind);
			adj[_b].emplace_back(_a, ind);
			dsu.Merge(_a, _b);
			rep = _a;
			ind++;
		}
		dsu.Find(rep);
		for(int i = 0; i < (1 << lv); i++){
			if(has[i]){
				dsu.Find(i);
				if(dsu.dsu[i] != dsu.dsu[rep]){
					can = false;
					break;
				}
				if(adj[i].size() & 1){
					can = false;
					break;
				}
			}
		}
		if(can){ //get euler cycle
			cout << lv << endl;
			dfs(rep, rep);
			for(int x : ans) cout << x << " ";
			cout << endl;
			return 0;
		}
	}
}



