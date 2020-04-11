#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define F first
#define S second
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


const int maxN = 2e5 + 10, maxLog = 20;
set<pii> st;
vector<int> adj[maxN];
int N, Q, u, v, ord[maxN], pos[maxN], m, lm[maxN], rm[maxN], mx[maxN * 4], tag[maxN * 4], cnt[maxN * 4], edgecnt;
int dep[maxN], anc[maxLog][maxN];

inline void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	anc[0][u] = p;
	for(int i = 1; i < maxLog; i++){
		anc[i][u] = anc[i - 1][anc[i - 1][u]];	
	}
	ord[m++] = u;
	pos[u] = m - 1;
	lm[u] = m - 1;
	for(int v : adj[u]){
		if(v == p) continue;
		dfs(u, v);	
	}
	rm[u] = m;	
}

int get(int a, int b){
	for(int i = 0; i < maxLog; i++){
		if(((dep[b] - dep[a] - 1) >> i) & 1) b = anc[i][b]; 
	}
	return b;
}

inline void pull(int id){
	if(mx[2 * id + 1] < mx[2 * id + 2]){
		mx[id] = mx[2 * id + 2];
		cnt[id] = cnt[2 * id + 2];
	} else if(mx[2 * id + 1] > mx[2 * id + 2]){
		mx[id] = mx[2 * id + 1];
		cnt[id] = cnt[2 * id + 1];
	} else {
		mx[id] = mx[2 * id + 1];
		cnt[id] = cnt[2 * id + 1] + cnt[2 * id + 2];
	}
}

inline void push(int id, int l, int r){
	mx[id] += tag[id];
	if(l + 1 < r){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = N){
	tag[id] = 0;
	if(l + 1 == r){
		mx[id] = 0;
		cnt[id] = 1;
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int ql, int qr, int l, int r, int v){
	push(id, l, r);
	if(ql >= r || l >= qr) return;	
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

pii query(int id, int ql, int qr, int l, int r){
	push(id, l, r);	
	if(ql >= r || l >= qr){
		return {-1, 0};
	}
	if(ql <= l && r <= qr){
		return {mx[id], cnt[id]};
	}
	int m = (l + r) / 2;
	pii pl = query(2 * id + 1, ql, qr, l, m);
	pii pr = query(2 * id + 2, ql, qr, m, r);
	if(pl.F == pr.F) return {pl.F, pl.S + pr.S};
	else if(pl.F < pr.F){
		return pr;
	} else return pl;
}

inline bool isAnc(int a, int b){ //a is anc of b
	return lm[a] <= lm[b] && rm[b] <= rm[a];
}

void disp(){
	for(int i = 0; i < N; i++){
		cout << query(0, i, i + 1, 0, N).F << " ";
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
	build();
	/*
	for(int i = 1; i <= N; i++){
		cout << ord[i] << " " << endl;
	}
	
	for(int i = 1; i <= N; i++){
		cout << "l" << i << " = " << lm[i] << endl;
		cout << "r" << i << " = " << rm[i] << endl;
	}
	*/
	while(Q--){
		cin >> u >> v;
		if(u > v) swap(u, v);
		if(!st.count({u, v})){
			st.insert({u, v});
			if(isAnc(u, v)){
				u = get(u, v);
				modify(0, 0, N, 0, N, 1);	
				modify(0, lm[u], rm[u], 0, N, -1);
				modify(0, lm[v], rm[v], 0, N, 1);
			} else if(isAnc(v, u)){
				v = get(v, u);
				modify(0, 0, N, 0, N, 1);
				modify(0, lm[v], rm[v], 0, N, -1);
				modify(0, lm[u], rm[u], 0, N, 1);
			} else {
				modify(0, lm[v], rm[v], 0, N, 1);
				modify(0, lm[u], rm[u], 0, N, 1);
			}
		} else {
			st.erase({u, v});
			if(isAnc(u, v)){
				u = get(u, v);
				modify(0, 0, N, 0, N, -1);	
				modify(0, lm[u], rm[u], 0, N, 1);
				modify(0, lm[v], rm[v], 0, N, -1);
			} else if(isAnc(v, u)){
				v = get(v, u);
				modify(0, 0, N, 0, N, -1);
				modify(0, lm[v], rm[v], 0, N, 1);
				modify(0, lm[u], rm[u], 0, N, -1);
			} else {
				modify(0, lm[v], rm[v], 0, N, -1);
				modify(0, lm[u], rm[u], 0, N, -1);
			}
		}
		//disp();
		pii res = query(0, 0, N, 0, N); 
		if(res.F == st.size()) cout << res.S << endl;
		else cout << 0 << endl;
	}
}
