#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326, INF = 1e9;

vector<pii> adj[maxN];
vector<int> npp;

int N, M, K, u, v, w, minDist[maxN], Q, s[maxN], t[maxN], ord[maxN], ans[maxN], isIn[maxN];

void Dijkstra(){
	bool vis[maxN];
	priority_queue<pii, vector<pii>, greater<pii>> pq = priority_queue<pii, vector<pii>, greater<pii>>();
	fill(minDist, minDist + maxN, INF);
	fill(vis, vis + maxN, false);
	for(int s : npp){
		minDist[s] = 0;
		pq.push({0, s});
	}
	while(pq.size()){
		auto [d, u] = pq.top(); pq.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto [v, w] : adj[u]) if(!vis[v]){
			if(minDist[v] > minDist[u] + w){
				minDist[v] = minDist[u] + w;
				pq.push({minDist[v], v});
			}
		}
	}
}

struct Query{
	int l, r;
	vector<int> ques;
	Query(){}
	Query(int l, int r, vector<int> q): l(l), r(r), ques(q){}
};

struct DSU{
	int dsu[maxN];
	DSU(){}
	DSU(int N){	
		iota(dsu, dsu + N + 1, 0);
	}
	void Flat(int x){
		if(x == dsu[x]) return;
		Flat(dsu[x]);
		dsu[x] = dsu[dsu[x]];
	}
	void Merge(int a, int b){
		Flat(a);
		Flat(b);
		dsu[dsu[a]] = dsu[b];
	}
} dsu;

int main(){
	ericxiao
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	cin >> K;
	npp.resize(K);
	for(int i = 0; i < K; i++) cin >> npp[i];
	Dijkstra();
	cin >> Q;
	for(int i = 0; i < Q; i++){
		cin >> s[i] >> t[i];
	}

	queue<Query> que = queue<Query>();
	vector<int> vec = vector<int>();
	for(int i = 0; i < Q; i++) vec.push_back(i);
	que.emplace(0, N, vec);
	dsu = DSU(N);
	iota(ord, ord + N + 1, 0);
	sort(ord + 1, ord + N + 1, [](int a, int b){
		return minDist[a] > minDist[b];
	});

	int cur = 1;
	while(que.size()){
		Query q = que.front(); que.pop();
		//cout << "l = " << q.l << ", r = " << q.r << ", ques = "; for(int x : q.ques) cout << x << " "; cout << endl;
		if(q.r - q.l == 1){
			for(int id : q.ques){
				ans[id] = minDist[ord[q.r]];
			}
			continue;
		}
		int m = (q.l + q.r) / 2;
		vector<int> lef = vector<int>(), rig = vector<int>();
		if(m < cur - 1){
			cur = 1;
			//cout << "resetting" << endl;
			fill(isIn, isIn + N + 1, 0);
			dsu = DSU(N);
		}
		//cout << "m = " << m << endl;
		for(; cur <= m; cur++){
			//cout << "cur = " << cur << endl;
			for(auto [v, w] : adj[ord[cur]]) if(isIn[v]) dsu.Merge(v, ord[cur]);
			isIn[ord[cur]] = true;
		}
		for(int id : q.ques){
			dsu.Flat(s[id]);
			dsu.Flat(t[id]);
			if(dsu.dsu[s[id]] == dsu.dsu[t[id]]) lef.push_back(id);
			else rig.push_back(id);
		}
		if(lef.size()) que.emplace(q.l, m, lef);
		if(rig.size()) que.emplace(m, q.r, rig);
	}
	for(int i = 0; i < Q; i++) cout << min(ans[i], min(minDist[s[i]], minDist[t[i]])) << " ";
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
  */
