#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
#define ll long long int
using namespace std;

const int MOD = 1e9, maxN = 1e5 + 326;
vector<pii> points;
map<pii, int> mp;
vector<int> adj[maxN];
set<pii> edges;

ll ans[maxN], up[maxN], sz[maxN], cnt[maxN];

ll add(ll a, ll b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

ll sub(ll a, ll b){
	return (a >= b ? a - b : a - b + MOD);
}

void dfs(int p = 1, int u = 1){
	ans[u] = up[u] = 0;
	sz[u] = cnt[u];
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
		ans[u] = add(ans[u], up[u] * sz[v] % MOD);
		ans[u] = add(ans[u], add(up[v], sz[v]) * sub(sz[u], cnt[u]) % MOD);
		sz[u] = add(sz[u], sz[v]);
		up[u] = add(up[u], add(up[v], sz[v]));
		ans[u] = add(ans[u], ans[v]);
		//from the last
	}
	//cout << "before updating up: " << ans[u] << endl;
	ans[u] = add(ans[u], up[u] * cnt[u] % MOD);
	//cout << "for " << u << ": ans = " << ans[u] << ", up = " << up[u] << ", sz = " << sz[u] << endl;
}

inline int run(int N){
	sort(points.begin(), points.end());
	mp = map<pii, int>();
	edges = set<pii>();
	fill(cnt, cnt + N + 1, 0);
	int c = 1;
	for(int i = 0; i < N; i++){
		auto [x, y] = points[i];
		if(mp.count({x, y - 1})) mp[{x, y}] = mp[{x, y - 1}];
		else mp[{x, y}] = c++;
		cnt[mp[{x, y}]]++;
		//cout << "mp[" << x << ", " << y << "] = " << mp[{x, y}] << endl;
	}
	fill(adj, adj + c + 1, vector<int>());
	for(auto [x, y] : points){
		if(mp.count({x - 1, y}) && !edges.count({mp[{x - 1, y}], mp[{x, y}]})){
			edges.insert({mp[{x - 1, y}], mp[{x, y}]});
			edges.insert({mp[{x, y}], mp[{x - 1, y}]});
		}
	}
	for(auto [u, v] : edges) adj[u].push_back(v);	
	dfs();
	return ans[1];
}


int DistanceSum(int N, int *X, int *Y){
	for(int i = 0; i < N; i++) points.emplace_back(X[i], Y[i]);
	ll ans = run(N);
	//cout << "Vertical: " << ans << endl;
	for(auto &p : points) swap(p.F, p.S);
	ans = add(ans, run(N));
	return ans;
}
