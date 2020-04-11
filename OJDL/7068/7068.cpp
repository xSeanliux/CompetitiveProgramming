#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e5 + 10, INF = 1e9;

int N, Q, u, v, fat[maxN], pos[maxN], m, tag[maxN * 4], lm[maxN], rm[maxN], ord[maxN];
bool has[maxN];
pii seg[maxN * 4];
vector<int> adj[maxN];
queue<int> que;

void dfs(int p = 1, int u = 1){
	fat[u] = p;
	for(int v : adj[u]){
		if(v == p) continue;
		dfs(u, v);
	}
}

inline void push(int id, int l, int r){
	seg[id].F += tag[id];
	if(l + 1 < r){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	tag[id] = 0;
}

inline void pull(int id){
	if(seg[2 * id + 1].F < seg[2 * id + 2].F){
		seg[id] = seg[2 * id + 1];
	} else if(seg[2 * id + 1].F > seg[2 * id + 2].F){
		seg[id] = seg[2 * id + 2];
	} else {
		seg[id] = {seg[2 * id + 1].F, seg[2 * id + 1].S + seg[2 * id + 2].S};
	}
}

void build(int id = 0, int l = 1, int r = N + 1){
	tag[id] = 0;
	if(l + 1 == r){
		seg[id] = {adj[ord[l]].size(), 1};	
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

pii query(int id, int ql, int qr, int l = 1, int r = N + 1){
	push(id, l, r);
	if(l >= qr || ql >= r) return {maxN, 0};
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	pii pl = query(2 * id + 1, ql, qr, l, m);
	pii pr = query(2 * id + 2, ql, qr, m, r);
	if(pl.F < pr.F) return pl;
	if(pl.F > pr.F) return pr;
	return {pl.F, pl.S + pr.S};


void modify(int id, int ql, int qr, int l, int r, int v){
	push(id, l, r);
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		tag[id] += v;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	modify(2 * id + 1, ql, qr, l, m, v);
	modify(2 * id + 2, ql, qr, m, r, v);
	pull(id);
}

inline void disp(){
	for(int i = 1; i <= N; i++){
		cout << query(0, i, i + 1).F << " ";
	}
	cout << endl;
}

int main(){
	ericxiao;
	cin >> N >> Q;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	que.push(1);
	while(que.size()){
		int t = que.front();
		que.pop();
		pos[t] = ++m;
		ord[m] = t;
		//cout << ord[m] << " ";
		//cout << "pos[" << t << "] = " << pos[t] << endl;
		for(int u : adj[t]){
			if(u == fat[t]) continue;
			que.push(u);
		}
	}
	build();
	//cout << endl;
	fill(lm, lm + 1 + N, maxN);
	fill(rm, rm + 1 + N, -maxN);
	for(int i = 2; i <= N; i++){
		lm[fat[i]] = min(lm[fat[i]], pos[i]);
		rm[fat[i]] = max(rm[fat[i]], pos[i]);
	}
	while(Q--){
		cin >> u;
		if(!has[u]){
			if(u != 1){
				modify(0, pos[fat[u]], pos[fat[u]] + 1, 1, N + 1, -1);
			}
			if(lm[u] != maxN) modify(0, lm[u], rm[u] + 1, 1, N + 1, -1);
			modify(0, pos[u], pos[u] + 1, 1, N + 1, INF);
		} else {
			if(u != 1){
				modify(0, pos[fat[u]], pos[fat[u]] + 1, 1, N + 1, 1);
			}
			if(lm[u] != maxN) modify(0, lm[u], rm[u] + 1, 1, N + 1, 1);
			modify(0, pos[u], pos[u] + 1, 1, N + 1, -INF);
		}
		has[u] ^= 1;
		//disp();
		pii res = query(0, 1, N + 1);
		cout << (res.F == 0 ? res.S : 0) << endl;
	}
}

