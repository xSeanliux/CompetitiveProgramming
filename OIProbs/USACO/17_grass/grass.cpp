#pragma GCC_optimize("O3")
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <fstream>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 326, INF = 2e9;

ifstream infile;
ofstream outfile;

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	bool operator<(const Edge &e) const {
		return w < e.w;
	}
} edges[maxN];

struct DSU{
	int arr[maxN], sz[maxN];
	DSU(){}
	inline void init(){
		iota(arr, arr + maxN, 0);
	}
	void Flat(int x){
		if(arr[x] == x) return;
		Flat(arr[x]);
		arr[x] = arr[arr[x]];
	}
	bool Merge(int a, int b){
		Flat(a);
		Flat(b);
		if(arr[a] == arr[b]) return false;
		if(sz[a] == sz[b]){
			arr[arr[a]] = arr[b];
			sz[arr[b]]++;
		} else {
			if(sz[a] > sz[b]) swap(a, b);	
			arr[arr[a]] = arr[b];
		}
		return true;
	}
} dsu;

int N, K, M, Q, u, v, w, c, pa[maxN], col[maxN], pw[maxN], ans[maxN];
set<pii> mincols[maxN];  
map<int, multiset<int> > colweis[maxN];
multiset<int> ansst;
vector<pii> adj[maxN];

void getPa(int p = 0, int u = 0){
	pa[u] = p;
	for(auto pp = adj[u].begin(); pp != adj[u].end(); pp++){
		int v = pp->F, w = pp->S;
		if(v != p){
			getPa(u, v);
			pw[v] = w;
			colweis[u][col[v]].insert(w);
		}
	}
	for(auto p = colweis[u].begin(); p != colweis[u].end(); p++){
		int c = p->F;
		multiset<int> ms = p->S;
		mincols[u].insert({*ms.begin(), c});
	}
	ans[u] = INF;
	//cout << "Looking at node " << u << endl;
	for(auto p = mincols[u].begin(); p != mincols[u].end(); p++){
		int mv = p->F, c = p->S;
		if(c != col[u]){
			//cout << "Ans is " << mv << endl;
			ans[u] = mv;
			break;
		}
	}
	ansst.insert(ans[u]);
}

/*
inline void disp(){
	cout << "ANSST: " << endl;
	for(int x : ansst){
		cout << x << " ";
	}
	cout << endl;
	for(int i = 0; i < N; i++){
		cout << "ans[" << i << "] = " << ans[i] << endl;
		cout << "Colour:" << col[i] << endl;
		for(auto [c, ms] : colweis[i]){
			cout << "Has child of colour " << c << endl;
			for(int x : ms){
				cout << x << " ";
			}
			cout << endl;
		}
		for(auto [mv, col] : mincols[i]){
			cout << "col " << col << ": " << mv << endl;
		}
		cout << endl;
	}

}
*/

int main(){
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	ericxiao;
	Read(N);
	Read(M);
	Read(K);
	Read(Q);
	for(int i = 0; i < M; i++){
		Read(u);
		Read(v);
		Read(w);
		u--, v--;
		edges[i] = Edge(u, v, w);	
	}
	for(int i = 0; i < N; i++) Read(col[i]);
	dsu.init();
	sort(edges, edges + M);
	for(int i = 0; i < M; i++){
		if(dsu.Merge(edges[i].u, edges[i].v)){
			adj[edges[i].u].emplace_back(edges[i].v, edges[i].w);
			adj[edges[i].v].emplace_back(edges[i].u, edges[i].w);
		}
	}
	getPa();
	
	while(Q--){
		Read(u);
		Read(c);
		u--;
		//cout << "Changing node " << u << " to colour " << c << endl;
		if(u != pa[u]){
			//mincols[node]         -> <Min. Value, Colour>
			//Colweis[node][colour] -> Set of weights
			mincols[pa[u]].erase({*colweis[pa[u]][col[u]].begin(), col[u]});
			if(colweis[pa[u]].count(c)) mincols[pa[u]].erase({*colweis[pa[u]][     c].begin(),      c});
			colweis[pa[u]][col[u]].erase(colweis[pa[u]][col[u]].find(pw[u]));
			if(!colweis[pa[u]][col[u]].size()) colweis[pa[u]].erase(colweis[pa[u]].find(col[u]));
			colweis[pa[u]][     c].insert(pw[u]);
			if(colweis[pa[u]][col[u]].size()) mincols[pa[u]].insert({*colweis[pa[u]][col[u]].begin(), col[u]});
			mincols[pa[u]].insert({*colweis[pa[u]][     c].begin(),      c});

			ansst.erase(ansst.find(ans[pa[u]]));
			ans[pa[u]] = INF;
			for(auto p = mincols[pa[u]].begin(); p != mincols[pa[u]].end(); p++){
				int mv = p->F, c = p->S;
				if(c != col[pa[u]]){
					ans[pa[u]] = mv;
					break;
				}
			}
			ansst.insert(ans[pa[u]]);
		}
		col[u] = c;
		ansst.erase(ansst.find(ans[u]));
		ans[u] = INF;
		int cnt = 0;
		for(auto p = mincols[u].begin(); p != mincols[u].end(); p++){
			int mv = p->F, c = p->S;
			if(c != col[u]){
				ans[u] = mv;
				break;
			}
		}
		ansst.insert(ans[u]);
		printf("%d\n", *ansst.begin());
	}
}



