#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxN = 1e5 + 10, maxLog = 20;

int N, M, a, b, K, overlp[maxN], addTag[maxN], minTag[maxN], dep[maxN], anc[maxN][maxLog], peid[maxN], pre[maxN];
bool ans[maxN];


struct Edge{
	int to, id;
	Edge(){}
	Edge(int T, int I): to(T), id(I){}
};

vector<Edge> adj[maxN];

void dfs(int p = 1, int u = 1){
	dep[u] = dep[p] + 1;
	anc[u][0] = p;
	for(int i = 1; i < maxLog; i++){
		anc[u][i] = anc[anc[u][i - 1]][i - 1];
	}
	for(auto e : adj[u]){
		if(e.to == p) continue;
		peid[e.to] = e.id;
		dfs(u, e.to);
	}
}

int LCA(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	int k = dep[a] - dep[b];
	for(int i = 0; i < maxLog; i++){
		if((k >> i) & 1){
			a = anc[a][i];
		}
	}
	if(a == b) return a;
	for(int i = 0; i < maxLog; i++){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

void addPath(int a, int b){
	if(dep[a] < dep[b]) swap(a, b);
	int lca = LCA(a, b); 
	if(lca == b){
		int _a = a, k = dep[a] - dep[b] - 1;
		for(int i = 0; i < maxLog; i++){
			if((k >> i) & 1) _a = anc[_a][i];
		}
		addTag[_a]++;
		minTag[a]++;
	} else {
		int _a = a, _b = b, k;
		k = dep[a] - dep[lca] - 1;
		for(int i = 0; i < maxLog; i++){
			if((k >> i) & 1) _a = anc[_a][i];
		}
		k = dep[b] - dep[lca] - 1;
		for(int i = 0; i < maxLog; i++){
			if((k >> i) & 1) _b = anc[_b][i];
		}
		addTag[_a]++;
		addTag[_b]++;
		minTag[a]++;
		minTag[b]++;
	}
}

void getAns(int p = 1, int u = 1){
	pre[u] = pre[p] + addTag[u];
	if(pre[u] >= K) ans[peid[u]] = true;
	pre[u] -= minTag[u];
	for(auto e : adj[u]){
		if(e.to == p) continue;
		getAns(u, e.to);	
	}
	
}

int main(){
	cin >> N >> M >> K;
	for(int i = 0; i < N - 1; i++){
		cin >> a >> b;
		adj[a].emplace_back(b, i);
		adj[b].emplace_back(a, i);
	}
	dfs();
	getAns();
	for(int i = 0; i < M; i++){
		int k, x, cl;
		vector<int> ques;
		set<int> ads;
		for(int i = 0; i < k; i++){
			cin >> x;
			ques.push_back(x);
		}
		cl = x;
		for(int i = 1; i < k; i++){
			cl = LCA(cl, ques[i]);
		}
	}
	int cnt = 0;
	for(int i = 0; i < N - 1; i++){
		cnt += ans[i];	
	}
	cout << cnt << endl;
	for(int i = 0; i < N - 1; i++){
		if(ans[i]) cout << i + 1 << " ";
	}
}
