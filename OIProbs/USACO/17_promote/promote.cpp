#include <iostream>
#include <vector>
#include <fstream>

#define cin infile
#define cout outfile
using namespace std;

const int maxN = 1e5 + 326;


ifstream infile;
ofstream outfile;

int sts[maxN], wei[maxN], maxChild[maxN], ans[maxN], N, u, v, treap[maxN * 5], val[maxN * 5], sz[maxN * 5], pri[maxN * 5], l[maxN * 5], r[maxN * 5], roots[maxN], arr[maxN];
int cnt = 1;
vector<int> adj[maxN];

inline int Rand(){
	static int seed = 32603;
	return seed = (seed * 3 + 1) % 0xdefaced;
}

inline int Sz(int x){
	return x ? sz[x] : 0;
}

inline int newNode(int x){
	val[cnt] = x;
	sz[cnt] = 1;	
	pri[cnt] = Rand();
	l[cnt] = r[cnt] = 0;
	return cnt++;
}

inline void pull(int x){
	sz[x] = Sz(l[x]) + Sz(r[x]) + 1;
}

void Split(int o, int &a, int &b, int k){
	if(!o){
		a = b = 0;
		return;
	}
	if(val[o] <= k){
		a = o;
		Split(r[o], r[a], b, k);
		pull(a);
	} else {
		b = o;
		Split(l[o], a, l[b], k);
		pull(b);
	}
	pull(o);
}

int Merge(int a, int b){
	if(!a || !b) return !a ? b : a;
	if(pri[a] < pri[b]){
		r[a] = Merge(r[a], b);
		pull(a);
		return a;
	}
	l[b] = Merge(a, l[b]);
	pull(b);
	return b;
}

void Insert(int &root, int v){
	int a, b;
	Split(root, a, b, v);
	root = Merge(a, Merge(newNode(v), b));
}

inline int Rank(int root, int v){
	int res = 0;
	while(root){
		if(val[root] <= v){
			res += Sz(l[root]) + 1;
			root = r[root]; 
		} else {
			root = l[root];	
		}
	}
	return res;
}

void add(int root, int &tgt){
	if(!root) return;
	Insert(tgt, val[root]);
	add(l[root], tgt);
	add(r[root], tgt);
}

void disp(int root){
	if(!root) return;
	disp(l[root]);
	cout << val[root] << " ";
	disp(r[root]);
}

void dfs(int p = 1, int u = 1){
	sts[u] = 1;	
	maxChild[u] = -1;
	for(int v : adj[u]) if(v != p){
		dfs(u, v);
		sts[u] += sts[v];
		if(maxChild[u] == -1 || sts[maxChild[u]] < sts[v]) maxChild[u] = v;
	}
	if(~maxChild[u]) swap(roots[maxChild[u]], roots[u]);
	for(int v : adj[u]) if(v != p && v != maxChild[u]){
		add(roots[v], roots[u]);
	}
	ans[u] = Sz(roots[u]) - Rank(roots[u], arr[u]);
	Insert(roots[u], arr[u]);
	/*
	cout << "for " << u << endl;
	disp(roots[u]);
	cout << endl;
	cout << "Sz = " << Sz(roots[u]) << endl;
	*/
}


int main(){
	infile.open("promote.in");
	outfile.open("promote.out");
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> arr[i];
	for(int i = 2; i <= N; i++){
		cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	dfs();
	for(int i = 1; i <= N; i++) cout << ans[i] << '\n';
}
