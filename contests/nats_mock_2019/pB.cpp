#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

struct Edge{
	int u, v, w;
	Edge(int u, int v, int w): u(u), v(v), w(w){};
	bool operator<(const Edge e) const {
		return w > e.w;
	}
};

vector<Edge> edges;
int n, m, u, v, w, dsu[maxN];

void flat(int x){
	if(dsu[x] == x) return;
	flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
	flat(a);
	flat(b);
	if(dsu[a] == dsu[b]) return false;
	dsu[dsu[a]] = dsu[b];
	return true;
}

signed main(){
	cin >> n >> m;
	iota(dsu, dsu + n, 0);
	for(int i = 0; i < m; i++){
		cin >> u >> v >> w;
		edges.emplace_back(u, v, w);		
	}
	sort(edges.begin(), edges.end());
	int ans = 0;
	for(Edge e : edges){
		if(!Merge(e.u, e.v)) ans += e.w;
	}
	cout << ans << endl;
}
